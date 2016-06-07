#ifndef QXF_CORE_LOGFILEWRITER_H
#define QXF_CORE_LOGFILEWRITER_H

#include <qxf/core/logwriter.h>

class QFile;

namespace qxf {
namespace core {

class QXF_CORE_EXPORT LogFileWriter : public LogWriter
{
public:
    LogFileWriter(const QString& fileName);
    ~LogFileWriter();

    virtual void write(const LogMessage& msg);
    virtual void flush();

private:
    QFile* _file;
};

} // namespace core
} // namespace qxf

#endif // QXF_CORE_LOGFILEWRITER_H
