#ifndef W_MENUDEJEU_H
#define W_MENUDEJEU_H

#include <iostream>
#include <QWidget>
#include <QObject>
#include <chrono>
#include <QString>
#include "c_tcpserver.h"

namespace Ui {
class W_MenuDeJeu;
}

class W_MenuDeJeu : public QWidget
{
    Q_OBJECT

public:
    explicit W_MenuDeJeu(int dureeTimer=0, int pointsMax=0, QWidget *parent = nullptr);
    ~W_MenuDeJeu() override;
    void setDureeTimer(int dureeTimer);
    void setPointsMax(int pointsMax);
    void displayPointsJ1();
    void displayPointsJ2();
    void incPointsJ1(void);
    void incPointsJ2(void);
    void decPointsJ1(void);
    void decPointsJ2(void);
    const QString timeToString(int timeInSec);
    void initAffichage(void);
    void TestVictoire(void);

public slots:
    void on_pbQuitter_clicked();
    void on_bpJ1Pret_clicked();
    void on_bpJ2Pret_clicked();
    void tankTouche(QString peerAdress);
    void newConnection(QString);
//    void on_printIP_clicked();

private:
    Ui::W_MenuDeJeu *ui;
    bool readyJ1;
    bool readyJ2;
    int dureeTimer;
    int pointsMax;
    int timer;
    int timerId;
    int m_pointsJ1;
    int m_pointsJ2;
    C_TcpServer *m_TcpServer;
    QString m_IPTank1;
    QString m_IPTank2;
    bool m_printIP;


protected:
    void timerEvent(QTimerEvent *event) override;
private slots:
    void on_pbPrintIP_clicked();
};

#endif // W_MENUDEJEU_H
