CONFIG += c++11
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Source/Core/Example/mutex_example.h \
    Source/Core/ReadFile/run_sleep.h \
    Source/Core/ReadFile/run_timer.h \
    Source/Core/Thread/Read/const_crtrt.h \
    Source/Core/Thread/Read/read_thread_crtrt.h \
    Source/Core/Thread/Sleep/sleep_thread.h \
    Source/Core/ReadFile/read_file.h \
    Source/Core/const_core.h \
    Source/Core/scan_cache.h \
    Source/Core/start_process.h \
    Source/Core/startup.h \
    Source/Define/define.h \
    Source/Global/global.h \
    Source/Input/Thread/input_loop_thread.h \
    Source/Input/stdin.h \
    Source/Interface/Dpi/dpi.h \
    Source/Interface/MainWindow/mainwindow.h \
    Source/Interface/TrayIcon/Action/custom_action.h \
    Source/Interface/TrayIcon/const_tray_icon.h \
    Source/Interface/TrayIcon/tray_icon.h \
    Source/Output/log.h \
    Source/Output/const_log.h \
    Source/Output/stdout.h \
    Source/Setting/const_setting.h \
    Source/Setting/setting.h \
    Source/Translate/const_translator_loader.h \
    Source/Translate/translate_define.h \
    Source/Translate/translate_tool.h \
    Source/Translate/translator_loader.h

SOURCES += \
    Source/Core/ReadFile/init.cpp \
    Source/Core/ReadFile/run.cpp \
    Source/Core/ReadFile/run_sleep.cpp \
    Source/Core/ReadFile/run_timer.cpp \
    Source/Core/ReadFile/read_file.cpp \
    Source/Core/Thread/Read/init_crtrt.cpp \
    Source/Core/Thread/Read/read_thread_crtrt.cpp \
    Source/Core/Thread/Read/run_crtrt.cpp \
    Source/Core/Thread/Sleep/sleep_thread.cpp \
    Source/Core/const_core.cpp \
    Source/Core/const_core_tdummy.cpp \
    Source/Core/scan_cache.cpp \
    Source/Core/start_process.cpp \
    Source/Core/startup.cpp \
    Source/Global/const_global.cpp \
    Source/Global/global.cpp \
    Source/Input/Thread/InputLoop/Level1/exit_itill1.cpp \
    Source/Input/Thread/InputLoop/Level1/expiresc_itill1.cpp \
    Source/Input/Thread/InputLoop/Level1/pause_itill1.cpp \
    Source/Input/Thread/InputLoop/Level1/resume_itill1.cpp \
    Source/Input/Thread/InputLoop/Level1/test_itill1.cpp \
    Source/Input/Thread/InputLoop/Level1/traydc_itill1.cpp \
    Source/Input/Thread/InputLoop/Level2/lang_itill1.cpp \
    Source/Input/Thread/InputLoop/Level2/run_itill1.cpp \
    Source/Input/Thread/input_loop_thread.cpp \
    Source/Input/const_input.cpp \
    Source/Input/const_input_tdummy.cpp \
    Source/Input/stdin.cpp \
    Source/Interface/Dpi/dpi.cpp \
    Source/Interface/MainWindow/const_mainwindow.cpp \
    Source/Interface/MainWindow/const_mainwindow_tdummy.cpp \
    Source/Interface/MainWindow/mainwindow.cpp \
    Source/Interface/TrayIcon/Action/custom_action.cpp \
    Source/Interface/TrayIcon/tray_icon.cpp \
    Source/Output/log.cpp \
    Source/Output/const_log.cpp \
    Source/Output/stdout.cpp \
    Source/Setting/const_setting.cpp \
    Source/Setting/setting.cpp \
    Source/Translate/init_file.cpp \
    Source/Translate/init_message.cpp \
    Source/Translate/translate_tool.cpp \
    main.cpp
TRANSLATIONS += \
    Source/Translate/File/prefetch_en_US.ts \
    Source/Translate/File/prefetch_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Source/Interface/MainWindow/mainwindow.ui

# My setting

# Compile with console
#CONFIG += console

# Enable c++11 for QT 4.8.7
QMAKE_CXXFLAGS += -std=c++11

# Compiler -Ofast here we go again
QMAKE_CFLAGS_RELEASE -= -O
QMAKE_CFLAGS_RELEASE -= -O1
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE -= -O3
QMAKE_CFLAGS_RELEASE *= -Ofast

# Icon
RC_FILE = prefetch.rc

RESOURCES += \
    prefetch.qrc

# Third party library
INCLUDEPATH += $$PWD/../ThirdParty/boost
