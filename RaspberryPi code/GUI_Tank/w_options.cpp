#include "w_options.h"
#include "ui_w_options.h"

W_Options::W_Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Options)
{
    this->m_pointMax_Sav=1;
    this->m_dureeJeu_Sav=180;
    this->m_pointMax=1;
    this->m_dureeJeu=180;

    ui->setupUi(this);

    ui->lnPoints->display(m_pointMax);
    ui->lnTemps->display(timeToString(m_dureeJeu));
}

W_Options::~W_Options()
{
    delete ui;
}

void W_Options::on_pbAnnuler_clicked()
{
    this->hide();
    ui->lnTemps->display(timeToString(m_dureeJeu_Sav));
    ui->lnPoints->display(m_pointMax_Sav);
}

void W_Options::on_pbPointsP_clicked()
{
    if(m_pointMax<POINTS_MAX) m_pointMax++;
    ui->lnPoints->display(m_pointMax);
}

void W_Options::on_pbPointsM_clicked()
{
    if(m_pointMax>POINTS_MIN) m_pointMax--;
    ui->lnPoints->display(m_pointMax);
}

void W_Options::on_pbTempsP_clicked()
{
    if(m_dureeJeu<DUREE_MAX) m_dureeJeu+=30;
    ui->lnTemps->display(timeToString(m_dureeJeu));
}

void W_Options::on_pbTempsM_clicked()
{
    if(m_dureeJeu>DUREE_MIN) m_dureeJeu-=30;
    ui->lnTemps->display(timeToString(m_dureeJeu));
}

int W_Options::getTimer()
{
    return this->m_dureeJeu_Sav;
}

int W_Options::getPoints()
{
    return this->m_pointMax_Sav;
}

void W_Options::on_pbValider_clicked()
{
    m_dureeJeu_Sav=m_dureeJeu;
    m_pointMax_Sav=m_pointMax;

    this->hide();
}

const QString W_Options::timeToString(int timeInSec)
{
    int min=timeInSec/60;
    int sec=timeInSec%60;
    QString secStr;
    if(sec>9) secStr=QString::number(sec);
    else secStr="0"+QString::number(sec);
    const QString s=QString::number(min)+":"+secStr;

    return s;
}









