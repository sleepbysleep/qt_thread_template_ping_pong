#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::doSomething(const int typeOfSource)
{
    //qDebug() << typeOfSource;
    // get the data from streamer
    switch (typeOfSource) {
    case 0: // from serial
        break;
    case 1: // from IP Cam
        break;
    case 2: // from tcp
        break;
    }

    emit dataReady(this->buffer, 100, typeOfSource);
}
