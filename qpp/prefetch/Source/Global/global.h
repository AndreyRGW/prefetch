#include <QCoreApplication>

// Static class
class Global
{
public:
    static QCoreApplication *qCoreApplication;

    // Any init code
    static void init(int argc, char *argv[]);

    QString getSettingFilePath();

private:
    // Disallow creating an instance of this object
    Global() {}
};
