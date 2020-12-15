#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QThread>
#include <QElapsedTimer>
#include <QDebug>

#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setPingPong(bool enable);

public slots:
    void handleData(const void *buffer, int len, int from);
    void handleError(const std::string& errorMsg, int from);

signals:
    void triggerPingPong(const int index = 0);

private:
    Ui::Dialog *ui;
    QThread workerThread;
    Worker *threadWorker;
    bool isPingPong = true;

    QElapsedTimer dpsTimer; // timer for data per second
    int dpsCount = 0;

};
#endif // DIALOG_H
