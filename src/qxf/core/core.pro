include(../../qxf.pri)
QT = core
TARGET = qxf.core
TEMPLATE = lib
DEFINES += QXF_BUILD_CORE_LIBRARY

HEADERS += \
    logger.h \
    logwriter.h \
    logconsolewriter.h \
    logmessage.h \
    loglevel.h \
    logfilewriter.h \
    simplecrypt.h

SOURCES += \
    logger.cpp \
    logwriter.cpp \
    logconsolewriter.cpp \
    logfilewriter.cpp \
    simplecrypt.cpp
