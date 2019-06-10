#ifndef C_TCPSERVER_H
#define C_TCPSERVER_H

#include <QWidget>
#include <QAbstractSocket>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QTcpServer>
#include <QIODevice>
#include <QSslSocket>
#include <QSslPreSharedKeyAuthenticator>
#include <iostream>

class C_TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit C_TcpServer(QWidget *parent = 0);
    void setStatus(int);
    int getStatus();
    void stopGame();
    void startGame();
    ~C_TcpServer();
    const QTcpSocket returnIP(QTcpSocket Tank);

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();


signals:
    void signalTouche(QString peerAdress);
    void sendIP(QString);
private:
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
    bool m_status;
    QHostAddress* m_ipTank1;
    QHostAddress* m_ipTank2;
    QTcpSocket* Tank1_socket;
    QTcpSocket* Tank2_socket;


};


#endif // C_TCPSERVER_H
