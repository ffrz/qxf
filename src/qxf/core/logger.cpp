#include "logger.h"
#include "logwriter.h"
#include "logmessage.h"

#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QTimer>

namespace qxf {
namespace core {

Logger* Logger::_self = 0;

struct Logger::_Data
{
    QMutex mutex;
    QTimer* timer;
    QList<LogWriter*> writers;
    QQueue<LogMessage> messages;

    _Data(){}
    ~_Data()
    {
        qDeleteAll(writers);
    }
};

Logger::Logger(QObject* parent)
    : QThread(parent)
    , _d(new _Data)
{
    _self = this;
}

Logger::~Logger()
{
    quit();
    wait();
    delete _d;
    _self = 0;
}

void Logger::run()
{
    _d->timer = new QTimer;
    _d->timer->setInterval(1000);
    _d->timer->setTimerType(Qt::VeryCoarseTimer);
    connect(_d->timer, SIGNAL(timeout()), SLOT(writeMessages()), Qt::DirectConnection);

    _d->timer->start();

    exec();

    delete _d->timer;
    writeMessages();
}

void Logger::writeMessages()
{
    _d->mutex.lock();
    QList<LogWriter*> writers = _d->writers;
    QQueue<LogMessage> messages = _d->messages;
    _d->messages.clear();
    _d->mutex.unlock();

    if (messages.isEmpty())
        return;

    while (!messages.isEmpty()) {
        const LogMessage message = messages.dequeue();
        for (LogWriter* writer: writers) {
            writer->write(message);
        }
    }

    for (LogWriter* writer: writers) {
        writer->flush();
    }
}

void Logger::log(LogLevel level, const QString& message)
{
    QMutexLocker l(&_d->mutex);
    LogMessage msg;
    msg.data = message;
    msg.threadId = currentThreadId();
    msg.threadName = currentThread()->objectName();
    msg.timestamp = QDateTime::currentDateTime();
    msg.level = level;
    _d->messages.enqueue(msg);
}

void Logger::addWriter(LogWriter* writer)
{
    QMutexLocker l(&_d->mutex);
    _d->writers.append(writer);
}

void Logger::removeWriter(LogWriter* writer)
{
    QMutexLocker l(&_d->mutex);
    _d->writers.removeOne(writer);
}

QList<LogWriter*> Logger::writers() const
{
    QMutexLocker l(&_d->mutex);
    return _d->writers;
}

} // namespace core
} // namespace qxf
