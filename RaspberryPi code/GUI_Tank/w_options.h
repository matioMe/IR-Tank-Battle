#ifndef W_OPTIONS_H
#define W_OPTIONS_H

#include <QWidget>
#include <QLCDNumber>

#define POINTS_MAX 10
#define POINTS_MIN 1
#define DUREE_MAX 600
#define DUREE_MIN 60

namespace Ui {
class W_Options;
}

class W_Options : public QWidget
{
    Q_OBJECT

public:
    explicit W_Options(QWidget *parent = nullptr);
    int getTimer();
    int getPoints();
    const QString timeToString(int timeInSec);
    ~W_Options();

private slots:
    void on_pbAnnuler_clicked();
    void on_pbPointsP_clicked();
    void on_pbPointsM_clicked();
    void on_pbTempsP_clicked();
    void on_pbTempsM_clicked();
    void on_pbValider_clicked();

private:
    Ui::W_Options *ui;
    int m_pointMax;
    int m_dureeJeu;
    int m_pointMax_Sav;
    int m_dureeJeu_Sav;

};

#endif // W_OPTIONS_H
