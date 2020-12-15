#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void dataReady(const void *buffer, int len, int from);
    void errorAlert(const std::string& error, int from);

public slots:
    void doSomething(const int typeOfSource);

private:
    unsigned char buffer[256];
};

#endif // WORKER_H
