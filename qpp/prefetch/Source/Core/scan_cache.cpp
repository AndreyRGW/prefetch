#include <QFileInfo>
#include <QApplication>

#include "scan_cache.h"
#include "Thread\read_thread.h"
#include "..\Setting\setting.h"
#include "const_core.h"

QSettings *ScanCache::cache = NULL;
bool ScanCache::cacheFileExist = false;

Setting::GetGenericResult<QString> init_getCacheFilePath(int argc, QStringList argv)
{
    Setting::GetGenericResult<QString> getCacheFilePath;

    if (argc != 2)
    {
        getCacheFilePath.success = false;
        return getCacheFilePath;
    }

    auto settingFile = QFileInfo(argv[1]);
    QString cacheFileName = settingFile.baseName() + Const_Cache::DefaultCacheFilePathSuffix;
    auto cacheFile = QFileInfo(cacheFileName);
    ScanCache::cacheFileExist = cacheFile.exists();

    getCacheFilePath.result = cacheFileName;
    return getCacheFilePath;
}

void ScanCache::init(int argc, QStringList argv)
{
    // Cache file path default value
    QString cacheFilePath = Const_Cache::DefaultCacheFilePath;

    // Get cache file path
    auto getCacheFilePath = init_getCacheFilePath(argc, argv);
    if (getCacheFilePath.success)
    {
        cacheFilePath = getCacheFilePath.result;
    }
    cacheFilePath = QApplication::applicationDirPath() + Const_Cache::PathSplitter + cacheFilePath;

    // Read ini from exe stored folder
    cache = new QSettings(cacheFilePath, QSettings::IniFormat);
}

void ScanCache::saveScanCache(QList<QRunnable *> *readThreadQueueAddress)
{
    using namespace Const_Cache::ConfigGroupName;

    auto readThreadQueue = *readThreadQueueAddress;
    QMap<QString, QString> result;
    for (int i = 0; i < readThreadQueue.size(); ++i)
    {
        auto thread = (ReadThread *)readThreadQueue[i];

        auto key = QString::number(i);
        auto value = thread->filePath;

        result.insert(key, value);
    }

    Setting::setArray(ScanFolder, result, cache);
    cache->sync();
}
