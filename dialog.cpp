#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle(QString(tr("QtThreadTemplate")));
    //connect();
    this->threadWorker = new Worker();
    this->threadWorker->moveToThread(&this->workerThread);

    connect(&workerThread, &QThread::finished, this->threadWorker, &QObject::deleteLater);
    connect(this, &Dialog::triggerPingPong, this->threadWorker, &Worker::doSomething);
    connect(this->threadWorker, &Worker::dataReady, this, &Dialog::handleData);
    connect(this->threadWorker, &Worker::errorAlert, this, &Dialog::handleError);

    this->workerThread.start();
    this->dpsTimer.start();
    this->setPingPong(true);

    emit triggerPingPong(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::handleData(const void *buffer, int len, int from)
{
    // TODO: Process data
    ++this->dpsCount;
    int elapsed_tme = this->dpsTimer.elapsed();
    if (elapsed_tme > 1000 and this->dpsCount > 0) {
        //std::cout << frames << " during " << elapsedTime << std::endl;
        double dps = (double)this->dpsCount * 1000.0 / (double)(elapsed_tme);
        this->setWindowTitle(QString(tr("QtThreadTemplate - %1 [Data Per Sec]")).arg(dps, 3, 'f', 0, ' '));
        this->dpsCount = 0;
        this->dpsTimer.restart();
    }

    if (this->isPingPong) {
        emit triggerPingPong(from);
    }
}

void Dialog::handleError(const std::string& errorMsg, int from)
{
    // TODO: handle or report error
}

void Dialog::setPingPong(bool enable)
{
    this->isPingPong = enable;
}
