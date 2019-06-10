/********************************************************************************
** Form generated from reading UI file 'w_menudejeu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MENUDEJEU_H
#define UI_W_MENUDEJEU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_MenuDeJeu
{
public:
    QPushButton *pbQuitter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *bpJ1Pret;
    QVBoxLayout *verticalLayout_3;
    QLabel *lTimer;
    QLCDNumber *lnTimer;
    QPushButton *bpJ2Pret;
    QGridLayout *gridLayout;
    QLabel *lJ1;
    QLCDNumber *lnPointsJ1;
    QLabel *lJ2;
    QLCDNumber *lnPointsJ2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *lPartie;
    QPushButton *pbPrintIP;

    void setupUi(QWidget *W_MenuDeJeu)
    {
        if (W_MenuDeJeu->objectName().isEmpty())
            W_MenuDeJeu->setObjectName(QStringLiteral("W_MenuDeJeu"));
        W_MenuDeJeu->resize(800, 480);
        pbQuitter = new QPushButton(W_MenuDeJeu);
        pbQuitter->setObjectName(QStringLiteral("pbQuitter"));
        pbQuitter->setGeometry(QRect(672, 410, 111, 61));
        verticalLayoutWidget_2 = new QWidget(W_MenuDeJeu);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 771, 391));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bpJ1Pret = new QPushButton(verticalLayoutWidget_2);
        bpJ1Pret->setObjectName(QStringLiteral("bpJ1Pret"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bpJ1Pret->sizePolicy().hasHeightForWidth());
        bpJ1Pret->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(bpJ1Pret);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lTimer = new QLabel(verticalLayoutWidget_2);
        lTimer->setObjectName(QStringLiteral("lTimer"));
        lTimer->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lTimer);

        lnTimer = new QLCDNumber(verticalLayoutWidget_2);
        lnTimer->setObjectName(QStringLiteral("lnTimer"));
        sizePolicy.setHeightForWidth(lnTimer->sizePolicy().hasHeightForWidth());
        lnTimer->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(lnTimer);


        horizontalLayout->addLayout(verticalLayout_3);

        bpJ2Pret = new QPushButton(verticalLayoutWidget_2);
        bpJ2Pret->setObjectName(QStringLiteral("bpJ2Pret"));
        sizePolicy.setHeightForWidth(bpJ2Pret->sizePolicy().hasHeightForWidth());
        bpJ2Pret->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(bpJ2Pret);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lJ1 = new QLabel(verticalLayoutWidget_2);
        lJ1->setObjectName(QStringLiteral("lJ1"));
        lJ1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lJ1, 0, 0, 1, 1);

        lnPointsJ1 = new QLCDNumber(verticalLayoutWidget_2);
        lnPointsJ1->setObjectName(QStringLiteral("lnPointsJ1"));

        gridLayout->addWidget(lnPointsJ1, 1, 0, 1, 1);

        lJ2 = new QLabel(verticalLayoutWidget_2);
        lJ2->setObjectName(QStringLiteral("lJ2"));
        lJ2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lJ2, 0, 1, 1, 1);

        lnPointsJ2 = new QLCDNumber(verticalLayoutWidget_2);
        lnPointsJ2->setObjectName(QStringLiteral("lnPointsJ2"));
        sizePolicy.setHeightForWidth(lnPointsJ2->sizePolicy().hasHeightForWidth());
        lnPointsJ2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lnPointsJ2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayoutWidget_3 = new QWidget(W_MenuDeJeu);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(210, 400, 381, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lPartie = new QLabel(verticalLayoutWidget_3);
        lPartie->setObjectName(QStringLiteral("lPartie"));
        lPartie->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lPartie);

        pbPrintIP = new QPushButton(W_MenuDeJeu);
        pbPrintIP->setObjectName(QStringLiteral("pbPrintIP"));
        pbPrintIP->setGeometry(QRect(10, 410, 111, 61));

        retranslateUi(W_MenuDeJeu);

        QMetaObject::connectSlotsByName(W_MenuDeJeu);
    } // setupUi

    void retranslateUi(QWidget *W_MenuDeJeu)
    {
        W_MenuDeJeu->setWindowTitle(QApplication::translate("W_MenuDeJeu", "Form", nullptr));
        pbQuitter->setText(QApplication::translate("W_MenuDeJeu", "Quitter", nullptr));
        bpJ1Pret->setText(QApplication::translate("W_MenuDeJeu", "Joueur 1 pr\303\252t!", nullptr));
        lTimer->setText(QApplication::translate("W_MenuDeJeu", "Temps retant:", nullptr));
        bpJ2Pret->setText(QApplication::translate("W_MenuDeJeu", "Joueur 2 pr\303\252t!", nullptr));
        lJ1->setText(QApplication::translate("W_MenuDeJeu", "Points de vie joueur 1:", nullptr));
        lJ2->setText(QApplication::translate("W_MenuDeJeu", "Points de vie joueur 2:", nullptr));
        lPartie->setText(QApplication::translate("W_MenuDeJeu", "Partie en X points!", nullptr));
        pbPrintIP->setText(QApplication::translate("W_MenuDeJeu", "IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_MenuDeJeu: public Ui_W_MenuDeJeu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MENUDEJEU_H
