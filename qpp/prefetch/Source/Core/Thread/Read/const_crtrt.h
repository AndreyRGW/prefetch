#ifndef Const_ReadThread_h
#define Const_ReadThread_h

#include <QString>

namespace Const_ReadThread
{
    // %1: Qt format path, something like "C:/"
    const QString SearchPatternTemplate = "%1*";

    // ReadBufferSize in MB
    const int MegabyteMultiplier = 1024 * 1024;
}

#endif
