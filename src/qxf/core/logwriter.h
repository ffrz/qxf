#ifndef QXF_CORE_LOGWRITER_H
#define QXF_CORE_LOGWRITER_H

#include <qxf/global.h>

namespace qxf {
namespace core {

class LogMessage;

class QXF_CORE_EXPORT LogWriter
{
public:
    explicit LogWriter();
    virtual ~LogWriter();

    virtual void write(const LogMessage& msg) = 0;
    virtual void flush() = 0;

private:
    Q_DISABLE_COPY(LogWriter)
};

} // namespace core
} // namespace qxf

#endif // QXF_CORE_LOGWRITER_H
