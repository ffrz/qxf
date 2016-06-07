#ifndef QXF_CORE_LOGCONSOLEWRITER_H
#define QXF_CORE_LOGCONSOLEWRITER_H

#include <qxf/core/logwriter.h>

namespace qxf {
namespace core {

class QXF_CORE_EXPORT LogConsoleWriter : public LogWriter
{
public:
    explicit LogConsoleWriter();

    void write(const LogMessage& message);
    void flush();
};

} // namespace core
} // namespace qxf

#endif // QXF_CORE_LOGCONSOLEWRITER_H
