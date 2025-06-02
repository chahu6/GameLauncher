HEADERS += \
    $$PWD/ComMessageBox.h \
    $$PWD/NoneCopy.h \
    $$PWD/ThreadPool.h \
    $$PWD/Utils.h \
    $$PWD/SingletonUtils.h \

SOURCES += \
    $$PWD/ComMessageBox.cpp \
    $$PWD/SingletonUtils.cpp \

INCLUDEPATH += Utils # 包含Utils目录，以后就不用在头文件加Utils/了
