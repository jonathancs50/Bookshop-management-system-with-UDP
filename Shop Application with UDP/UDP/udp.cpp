
#include "udp.h"


UDP::UDP(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowTitle("UDP");
    setMinimumSize(400,400);

    //QTextEdit widget to display received data
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    //UDP socket for receiving data
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 12345);

    //connect the signal to the slot for reading datagrams
    connect(udpSocket, &QUdpSocket::readyRead, this, &UDP::readPendingDatagrams);
}

void UDP::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        QString receivedData="";
        //display xml data
        receivedData = QString::fromUtf8(datagram);
        textEdit->clear();

        textEdit->append(receivedData);
    }
}

