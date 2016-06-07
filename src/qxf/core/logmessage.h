#ifndef QXF_CORE_LOGMESSAGE_H
#define QXF_CORE_LOGMESSAGE_H

#include <qxf/global.h>
#include <qxf/core/loglevel.h>
#include <QDateTime>

namespace qxf {
namespace core {

struct QXF_CORE_EXPORT LogMessage
{
    Qt::HANDLE threadId;
    QString threadName;
    QDateTime timestamp;
    LogLevel level;
    QString data;
};

} // namespace core
} // namespace qxf

#endif // QXF_CORE_LOGMESSAGE_H
