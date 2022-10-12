#include <QStringList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>

#include "..\Define\define.h"
#include "const_log.h"

// Automatically lock and unlock log mutex
#if LOG_ENABLED

#define IF_LOG_ENABLED(code) \
    {                        \
        Log::lock();         \
        code                 \
        Log::unlock();       \
    }

#else

#define IF_LOG_ENABLED(code)

#endif

// Print last known position report to log
#if LOG_ENABLED && LAST_KNOWN_POSITION_ENABLED

#define LAST_KNOWN_POSITION(location)                   \
    {                                                   \
        using namespace Const_Log::Message;             \
        typedef Const_Log::LastKnownLocationEnum le;    \
                                                        \
        /* Gather information */                        \
        QString file = __FILE__;                        \
        QString function = __FUNCTION__;                \
        QString line = QString::number(__LINE__);       \
                                                        \
        QString lastKnownLine;                          \
        switch (location)                               \
        {                                               \
        case le::BEGIN:                                 \
            lastKnownLine = LastKnownLocation_BEGIN;    \
            break;                                      \
        case le::END:                                   \
            lastKnownLine = LastKnownLocation_END;      \
            break;                                      \
        case le::INLINE:                                \
            lastKnownLine = LastKnownLocation_INLINE;   \
            break;                                      \
        }                                               \
        lastKnownLine += File + file + NewLine;         \
        lastKnownLine += Function + function + NewLine; \
        lastKnownLine += Line + line;                   \
                                                        \
        /* Print */                                     \
        Log::lock();                                    \
        *Log::logTextStream << lastKnownLine << endl;   \
        Log::logTextStream->flush();                    \
        Log::unlock();                                  \
    }
#else

#define LAST_KNOWN_POSITION(location)

#endif

class Log
{
public:
    static QString logFilePath;
    static QFile *logFile;
    static QTextStream *logTextStream;
    static void init(int argc, QStringList argv);

    // Log takes time to initialized
    //     However, a stdout may occur before Log has initialized
    //     Use mutex to delay the print request
    static QMutex *logMutex;

    // Wrap access to logMutex
    static void lock();

    // Wrap access to logMutex
    static void unlock();

    // Close log file
    static void shutdown();

private:
    static QMutex *getLockedMutex();
};
