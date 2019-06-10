#include "w_menudejeu.h"
#include "ui_w_menudejeu.h"

W_MenuDeJeu::W_MenuDeJeu(int dureeTimer, int pointsMax, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_MenuDeJeu)
{
    this->dureeTimer=dureeTimer;
    this->pointsMax=pointsMax;

    this->timerId=0;

    ui->setupUi(this);
    m_IPTank1="";
    m_IPTank2="";
    this->initAffichage();
    m_TcpServer=new C_TcpServer();
    connect(m_TcpServer, SIGNAL(signalTouche(QString)), this, SLOT(tankTouche(QString)));
    connect(m_TcpServer, SIGNAL(sendIP(QString)), this, SLOT(newConnection(QString)));
    m_printIP=false;}

W_MenuDeJeu::~W_MenuDeJeu()
{
    delete ui;
    delete m_TcpServer;
}

void W_MenuDeJeu::on_pbQuitter_clicked()
{
    this->hide();

    if(this->timerId!=0) this->killTimer(timerId);
    this->initAffichage();
    this->m_TcpServer->setStatus(false);
    this->m_TcpServer->stopGame();
}

void W_MenuDeJeu::on_bpJ1Pret_clicked()
{
    this->readyJ1=true;
    if(this->readyJ1==true && this->readyJ2==true && ui->bpJ1Pret->isEnabled())
    {
        this->m_TcpServer->setStatus(true);
        this->m_TcpServer->startGame();
        this->timerId=this->startTimer(1000);
    }

    ui->bpJ1Pret->setEnabled(false);
    ui->bpJ1Pret->setText("Go!");
}

void W_MenuDeJeu::on_bpJ2Pret_clicked()
{
    this->readyJ2=true;
    if(this->readyJ1==true && this->readyJ2==true && ui->bpJ2Pret->isEnabled())
    {
        this->m_TcpServer->setStatus(true);
        this->m_TcpServer->startGame();
        this->timerId=this->startTimer(1000);
    }

    ui->bpJ2Pret->setEnabled(false);
    ui->bpJ2Pret->setText("Go!");

}

//SLOT
void W_MenuDeJeu::tankTouche(QString peerAddress)
{
    if(peerAddress==m_IPTank1)
    {
        m_pointsJ1--;
        ui->lnPointsJ1->display(this->m_pointsJ1);
        this->TestVictoire();
    }
    if(peerAddress==m_IPTank2)
    {
        m_pointsJ2--;
        ui->lnPointsJ2->display(this->m_pointsJ2);
        this->TestVictoire();
    }

}

//SIGNAL

void W_MenuDeJeu::newConnection(QString peerAddress)
{
    if(m_IPTank1=="")
    {
        m_IPTank1=peerAddress;
    }
    else if(m_IPTank2=="" && m_IPTank1!=m_IPTank2)
    {
        m_IPTank2=peerAddress;
    }
}

void W_MenuDeJeu::timerEvent(QTimerEvent *event)
{
    if(timerId==event->timerId() && timer>0)
    {
        timer--;
        ui->lnTimer->display(timeToString(timer));
    }
    else if (timer==0)
    {
        this->m_TcpServer->setStatus(false);
        this->m_TcpServer->stopGame();
        ui->lnTimer->display(timeToString(timer));
        if(m_pointsJ1>m_pointsJ2) ui->lPartie->setText("Partie terminée! Joueur 1 a gagné!");
        if(m_pointsJ1<m_pointsJ2) ui->lPartie->setText("Partie terminée! Joueur 2 a gagné!");
        if(m_pointsJ1==m_pointsJ2) ui->lPartie->setText("Partie terminée! Match nul!");
    }
}

void W_MenuDeJeu::setDureeTimer(int dureeTimer)
{
    this->dureeTimer=dureeTimer;
}

void W_MenuDeJeu::setPointsMax(int pointsMax)
{
    this->pointsMax=pointsMax;
}

void W_MenuDeJeu::displayPointsJ1()
{
    ui->lnPointsJ1->display(this->m_pointsJ1);
}

void W_MenuDeJeu::displayPointsJ2()
{
    ui->lnPointsJ2->display(this->m_pointsJ2);
}

void W_MenuDeJeu::decPointsJ1(void)
{
    this->m_pointsJ1--;
}

void W_MenuDeJeu::decPointsJ2(void)
{
    this->m_pointsJ2--;
}

void W_MenuDeJeu::incPointsJ1(void)
{
    this->m_pointsJ1++;
}

void W_MenuDeJeu::incPointsJ2(void)
{
    this->m_pointsJ2++;
}

const QString W_MenuDeJeu::timeToString(int timeInSec)
{
    int min=timeInSec/60;
    int sec=timeInSec%60;
    QString secStr;
    if(sec>9) secStr=QString::number(sec);
    else secStr="0"+QString::number(sec);
    const QString s=QString::number(min)+":"+secStr;

    return s;
}

void W_MenuDeJeu::initAffichage()
{
    this->timer=dureeTimer;
    this->m_pointsJ1=pointsMax;
    this->m_pointsJ2=pointsMax;
    this->readyJ1=false;
    this->readyJ2=false;
    ui->bpJ1Pret->setText("Joueur 1 prêt?");
    ui->bpJ2Pret->setText("Joueur 2 prêt?");
    ui->bpJ1Pret->setEnabled(true);
    ui->bpJ2Pret->setEnabled(true);
    ui->lnPointsJ1->display(this->pointsMax);
    ui->lnPointsJ2->display(this->pointsMax);
    ui->lnTimer->display(timeToString(timer));
    ui->lPartie->setText("Partie à " + QString::number(pointsMax) + " points de vie.");
    this->displayPointsJ1();
    this->displayPointsJ2();
}

void W_MenuDeJeu::TestVictoire()
{

    if(m_pointsJ2==0)
    {
        ui->lPartie->setText("Partie terminée! Joueur 1 a gagné!");
        this->killTimer(timerId);
    }
    if(m_pointsJ1==0)
    {
        ui->lPartie->setText("Partie terminée! Joueur 2 a gagné!");
        this->killTimer(timerId);
    }
}

void W_MenuDeJeu::on_pbPrintIP_clicked()
{
    if(m_printIP==true)
    {
        if(m_IPTank1!="") ui->lJ1->setText(m_IPTank1);
        else ui->lJ1->setText("pas d'IP");
        if(m_IPTank2!="") ui->lJ2->setText(m_IPTank2);
        else ui->lJ2->setText("pas d'IP");
        m_printIP=false;
    }
    else
    {
        ui->lJ1->setText("Points de vie Joueur 1:");
        ui->lJ2->setText("Points de vie Joueur 2:");
        m_printIP=true;
    }
}
