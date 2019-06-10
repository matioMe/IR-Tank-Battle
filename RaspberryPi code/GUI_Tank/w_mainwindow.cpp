#include "w_mainwindow.h"
#include "ui_w_mainwindow.h"

W_MainWindow::W_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_MainWindow)
{
    ui->setupUi(this);
    m_WOptions=new W_Options();
    m_WJeu=new W_MenuDeJeu(m_WOptions->getTimer(),m_WOptions->getPoints());

}

W_MainWindow::~W_MainWindow()
{
    delete ui;
    delete m_WJeu;
    delete m_WOptions;
}

void W_MainWindow::on_pbOptions_clicked()
{
    m_WOptions->show();
}

void W_MainWindow::on_pbLancerPartie_clicked()
{
    m_WJeu->setPointsMax(m_WOptions->getPoints());
    m_WJeu->setDureeTimer(m_WOptions->getTimer());
    m_WJeu->initAffichage();
    m_WJeu->show();
}

void W_MainWindow::on_pbEteindre_clicked()
{
    //system("echo \"coupurePi\"");
    //system("/home/pi/scripts/test.sh &");

    std::exit(EXIT_SUCCESS);
}
