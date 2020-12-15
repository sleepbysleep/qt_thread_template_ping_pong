# qt_thread_template_ping_pong
This is a QThread example in the way of ping-pong interaction.
There are three steps to do threading.
1. create a object from Worker, and move into QThread.
2. set up corresponding signals, and slots.
3. establish ping-pong operation between Dialog, and WorkerThread.

# Object from Worker and to WorkerThread
![alt text](https://github.com/sleepbysleep/qt_thread_template_ping_pong/edit/main/images/worker_thread.png)

# Layout of signals and slots
![alt text](https://github.com/sleepbysleep/qt_thread_template_ping_pong/edit/main/images/signals_slots.png)

# Ping-Pong Operation
![alt text](https://github.com/sleepbysleep/qt_thread_template_ping_pong/edit/main/images/ping_pong.png)
