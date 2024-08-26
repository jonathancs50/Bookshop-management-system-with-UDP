
#ifndef UDP_H
#define UDP_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTextEdit>



class UDP : public QMainWindow

{
    Q_OBJECT

public:
    UDP(QWidget *parent = nullptr);
private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* udpSocket;
    QTextEdit* textEdit;
};

#endif // UDP_H
