#include "logconsolewriter.h"
#include "logmessage.h"
#include <iostream>
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

LogConsoleWriter::LogConsoleWriter()
{
}

void LogConsoleWriter::write(const LogMessage& m)
{
    std::cout << QString("%1|%2:%3|%4|%5").arg(
                    m.timestamp.toString("dd-MM-yyyy hh:mm:ss.zzz"),
                    QString::number((quintptr)m.threadId),
                    m.threadName,
                    loglevelstrings[m.level],
                    m.data
                  ).toStdString()
               << std::endl;
}

void LogConsoleWriter::flush()
{
    std::cout.flush();
}

} // namespace core
} // namespace qxf
