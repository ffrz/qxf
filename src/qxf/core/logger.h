#ifndef QXF_CORE_LOGGER_H
#define QXF_CORE_LOGGER_H

#include <qxf/global.h>
#include <qxf/core/loglevel.h>

#include <QThread>

namespace qxf {
namespace core {

class LogWriter;
class LogMessage;

class QXF_CORE_EXPORT Logger : public QThread
{
    Q_OBJECT

public:
    explicit Logger(QObject* parent = 0);
    ~Logger();

    void log(LogLevel level, const QString& message);

    void addWriter(LogWriter* writer);
    void removeWriter(LogWriter* writer);
    QList<LogWriter*> writers() const;

    inline static Logger* instance() { return _self; }

private slots:
    void writeMessages();

protected:
    void run();

private:
    struct _Data;
    _Data* _d;
    static Logger* _self;

    Q_DISABLE_COPY(Logger)
};

} // namespace core
} // namespace qxf

#define qxfLog(lv,msg) qxf::core::Logger::instance()->log(lv, msg)

#endif // QXF_CORE_LOGGER_H
