#include "logfilewriter.h"
#include "logmessage.h"

#include <QFile>
#include <QVector>

namespace {
static const QVector<const char*> loglevelstrings{
    "Debug",
    "Info",
    "Warning",
    "Critical",
    "Fatal"
};
}

namespace qxf {
namespace core {

LogFileWriter::LogFileWriter(const QString& fileName)
    : _file(new QFile(fileName))
{
    _file->open(QFile::WriteOnly | QFile::Append | QFile::Unbuffered);
}

LogFileWriter::~LogFileWriter()
{
    flush();
    delete _file;
}

void LogFileWriter::write(const LogMessage& message)
{
    _file->write(QString("%1|%2:%3|%4|%5\r\n").arg(
                     message.timestamp.toString("dd-MM-yyyy hh:mm:ss.zzz"),
                     QString::number((quintptr)message.threadId),
                     message.threadName,
                     loglevelstrings[message.level],
                     message.data
                   ).toUtf8());
}

void LogFileWriter::flush()
{
    _file->flush();
}

} // namespace core
} // namespace qxf
