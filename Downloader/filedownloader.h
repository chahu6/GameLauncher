#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QObject *parent = nullptr);
    void StartDownload();

signals:
    void onDownloadProgress(int);
    void onDownloadPause();
    void OnDownloadContinue();
    void onDownloadFinished();
    void onDownloadFailed();
};

#endif // FILEDOWNLOADER_H
