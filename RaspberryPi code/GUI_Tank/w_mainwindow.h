#ifndef W_MAINWINDOW_H
#define W_MAINWINDOW_H

#include <QMainWindow>
#include "w_menudejeu.h"
#include "w_options.h"

namespace Ui {
class W_MainWindow;
}

class W_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_MainWindow(QWidget *parent = nullptr);
    ~W_MainWindow();

private slots:
    void on_pbOptions_clicked();

    void on_pbLancerPartie_clicked();

    void on_pbEteindre_clicked();


private:
    Ui::W_MainWindow *ui;
    W_MenuDeJeu *m_WJeu;
    W_Options *m_WOptions;
};

#endif // W_MAINWINDOW_H
