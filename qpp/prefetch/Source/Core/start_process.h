#include <QString>

class StartProcess
{
public:
    // Cool stuff
    // Use startDetached to avoid print to console
    // QProcess: Destroyed while process is still running.
    static void startProcess(QString fileName);
};
