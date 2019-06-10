/********************************************************************************
** Form generated from reading UI file 'w_options.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_OPTIONS_H
#define UI_W_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Options
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lPoints;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lnPoints;
    QVBoxLayout *verticalLayout;
    QPushButton *pbPointsP;
    QPushButton *pbPointsM;
    QLabel *lTemps;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lnTemps;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbTempsP;
    QPushButton *pbTempsM;
    QPushButton *pbAnnuler;
    QPushButton *pbValider;

    void setupUi(QWidget *W_Options)
    {
        if (W_Options->objectName().isEmpty())
            W_Options->setObjectName(QStringLiteral("W_Options"));
        W_Options->resize(800, 480);
        verticalLayoutWidget_2 = new QWidget(W_Options);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 631, 451));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lPoints = new QLabel(verticalLayoutWidget_2);
        lPoints->setObjectName(QStringLiteral("lPoints"));

        verticalLayout_3->addWidget(lPoints);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lnPoints = new QLCDNumber(verticalLayoutWidget_2);
        lnPoints->setObjectName(QStringLiteral("lnPoints"));

        horizontalLayout->addWidget(lnPoints);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbPointsP = new QPushButton(verticalLayoutWidget_2);
        pbPointsP->setObjectName(QStringLiteral("pbPointsP"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbPointsP->sizePolicy().hasHeightForWidth());
        pbPointsP->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pbPointsP);

        pbPointsM = new QPushButton(verticalLayoutWidget_2);
        pbPointsM->setObjectName(QStringLiteral("pbPointsM"));
        sizePolicy.setHeightForWidth(pbPointsM->sizePolicy().hasHeightForWidth());
        pbPointsM->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pbPointsM);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        lTemps = new QLabel(verticalLayoutWidget_2);
        lTemps->setObjectName(QStringLiteral("lTemps"));

        verticalLayout_3->addWidget(lTemps);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lnTemps = new QLCDNumber(verticalLayoutWidget_2);
        lnTemps->setObjectName(QStringLiteral("lnTemps"));

        horizontalLayout_2->addWidget(lnTemps);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pbTempsP = new QPushButton(verticalLayoutWidget_2);
        pbTempsP->setObjectName(QStringLiteral("pbTempsP"));
        sizePolicy.setHeightForWidth(pbTempsP->sizePolicy().hasHeightForWidth());
        pbTempsP->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pbTempsP);

        pbTempsM = new QPushButton(verticalLayoutWidget_2);
        pbTempsM->setObjectName(QStringLiteral("pbTempsM"));
        sizePolicy.setHeightForWidth(pbTempsM->sizePolicy().hasHeightForWidth());
        pbTempsM->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pbTempsM);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pbAnnuler = new QPushButton(W_Options);
        pbAnnuler->setObjectName(QStringLiteral("pbAnnuler"));
        pbAnnuler->setGeometry(QRect(660, 360, 121, 101));
        pbValider = new QPushButton(W_Options);
        pbValider->setObjectName(QStringLiteral("pbValider"));
        pbValider->setGeometry(QRect(660, 240, 121, 101));

        retranslateUi(W_Options);

        QMetaObject::connectSlotsByName(W_Options);
    } // setupUi

    void retranslateUi(QWidget *W_Options)
    {
        W_Options->setWindowTitle(QApplication::translate("W_Options", "Form", nullptr));
        lPoints->setText(QApplication::translate("W_Options", "Nombre de point de vie:", nullptr));
        pbPointsP->setText(QApplication::translate("W_Options", "+", nullptr));
        pbPointsM->setText(QApplication::translate("W_Options", "-", nullptr));
        lTemps->setText(QApplication::translate("W_Options", "Limite de temps de jeu:", nullptr));
        pbTempsP->setText(QApplication::translate("W_Options", "+", nullptr));
        pbTempsM->setText(QApplication::translate("W_Options", "-", nullptr));
        pbAnnuler->setText(QApplication::translate("W_Options", "Annuler", nullptr));
        pbValider->setText(QApplication::translate("W_Options", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Options: public Ui_W_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_OPTIONS_H
