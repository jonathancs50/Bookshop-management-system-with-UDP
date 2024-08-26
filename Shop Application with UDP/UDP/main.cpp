
#include "udp.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDP w;
    w.show();

    QUdpSocket udpSocket;

    //listen for incoming data on any port
    if (!udpSocket.bind(QHostAddress::Any, 12345)) {
        qDebug() << "Failed to bind to port";
        return 1;
    }

    QObject::connect(&udpSocket, &QUdpSocket::readyRead, [&]() {
        while (udpSocket.hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(datagram.data(), datagram.size());

            //display the received data
            qDebug() << "Received data:" << datagram;
        }
    });
    return a.exec();
}
