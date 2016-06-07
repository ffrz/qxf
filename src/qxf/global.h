#ifndef QXF_GLOBAL_H
#define QXF_GLOBAL_H

#include <qglobal.h>

#if defined(QXF_BUILD_CORE_LIBRARY)
#  define QXF_CORE_EXPORT Q_DECL_EXPORT
#else
#  define QXF_CORE_EXPORT Q_DECL_IMPORT
#endif

#if defined(QXF_BUILD_GUI_LIBRARY)
#  define QXF_GUI_EXPORT Q_DECL_EXPORT
#else
#  define QXF_GUI_EXPORT Q_DECL_IMPORT
#endif

#if defined(QXF_BUILD_WIDGETS_LIBRARY)
#  define QXF_WIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define QXF_WIDGETS_EXPORT Q_DECL_IMPORT
#endif

#endif // QXF_GLOBAL_H
