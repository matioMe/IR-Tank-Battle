#include "c_tcpserver.h"

#include <QDebug>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QAbstractSocket>
#include <iostream>
#include <wiringPi.h>

C_TcpServer::C_TcpServer(QWidget *parent): _server(this)
{
    std::cout<< "Programme lancé"<<std::endl;
    _server.listen(QHostAddress::Any, 4242);//change 4242

    m_status=false;
    m_ipTank1=new QHostAddress("");
    m_ipTank2=new QHostAddress("");
    Tank1_socket= new QTcpSocket();
    Tank2_socket= new QTcpSocket();

    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

C_TcpServer::~C_TcpServer()
{
    delete Tank1_socket;
    delete Tank2_socket;
    delete m_ipTank1;
    delete m_ipTank2;
}

void C_TcpServer::onNewConnection()
{
    QTcpSocket *clientSocket = _server.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    //connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

    _sockets.push_back(clientSocket);

    for (QTcpSocket* socket : _sockets) {

        //socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " connected to server !\n"));
        std::cout<<clientSocket->peerAddress().toString().toStdString() << " connected to server !\n" << std::endl;
        if(m_ipTank1->isNull() && clientSocket->peerAddress() != *m_ipTank2)
        {
            //std::cout<<"T1 Avant: "<<m_ipTank1->toString().toStdString()<<std::endl;
            m_ipTank1->setAddress(clientSocket->peerAddress().toString());
            emit sendIP(clientSocket->peerAddress().toString());
            //std::cout<<"T1 Après: "<<m_ipTank1->toString().toStdString()<<std::endl;
        }
        else if(m_ipTank2->isNull() && clientSocket->peerAddress() != *m_ipTank1)
        {
            //std::cout<<"T2 Avant: "<<m_ipTank1->toString().toStdString()<<std::endl;
            m_ipTank2->setAddress(clientSocket->peerAddress().toString());
            emit sendIP(clientSocket->peerAddress().toString());
            //std::cout<<"T2 Après: "<<m_ipTank1->toString().toStdString()<<std::endl;
        }
        std::cout<<"T1 Fin: "<<m_ipTank1->toString().toStdString()<<std::endl;
        std::cout<<"T2 Fin: "<<m_ipTank2->toString().toStdString()<<std::endl;

    }
}

void C_TcpServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void C_TcpServer::onReadyRead()
{
    std::cout<< "Ready read"<<std::endl;
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    std::cout<< "Data: " << datas.data() <<std::endl;

    for (QTcpSocket* socket : _sockets) {
        if (socket == sender)
        {
            std::cout<< "Envoi data client " << datas.data() <<std::endl;

            if(datas.toStdString()=="GET /STATUS")
            {
                if(m_status==true) sender->write("START\n");
                if(m_status==false) sender->write("STOP\n");

            }
            if(datas.toStdString()=="GET /TOUCHE")
            {
                //sender->write("TOUCHE_OK\n");
                //envoie un signal
                emit signalTouche(socket->peerAddress().toString());
            }
        }
    }
}

int C_TcpServer::getStatus()
{
    return this->m_status;
}


void C_TcpServer::setStatus(int status)
{
    this->m_status=status;
    return ;
}


void C_TcpServer::stopGame()
{
    if(!m_ipTank1->isNull())
    {
        Tank1_socket->connectToHost(*m_ipTank1, 80, QIODevice::WriteOnly);
        Tank1_socket->write("GET /STOP");
        Tank1_socket->disconnectFromHost();
    }
    if(!m_ipTank2->isNull())
    {
        Tank2_socket->connectToHost(*m_ipTank2, 80, QIODevice::WriteOnly);
        Tank2_socket->write("GET /STOP");
        Tank2_socket->disconnectFromHost();
    }
}


void C_TcpServer::startGame()
{
    if(!m_ipTank1->isNull())
    {
        Tank1_socket->connectToHost(*m_ipTank1, 80, QIODevice::WriteOnly);
        //const char* t = "GET" + m_ipTank1->toString().toStdString() + "START";
        Tank1_socket->write("GET /START");
        Tank1_socket->disconnectFromHost();
    }
    if(!m_ipTank2->isNull())
    {
        Tank2_socket->connectToHost(*m_ipTank2, 80, QIODevice::WriteOnly);
        Tank2_socket->write("GET /START");
        Tank2_socket->disconnectFromHost();
    }
}

