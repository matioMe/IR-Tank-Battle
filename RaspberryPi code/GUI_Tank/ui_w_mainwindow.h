/********************************************************************************
** Form generated from reading UI file 'w_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MAINWINDOW_H
#define UI_W_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pbLancerPartie;
    QPushButton *pbOptions;
    QPushButton *pbEteindre;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *W_MainWindow)
    {
        if (W_MainWindow->objectName().isEmpty())
            W_MainWindow->setObjectName(QStringLiteral("W_MainWindow"));
        W_MainWindow->resize(800, 480);
        W_MainWindow->setMinimumSize(QSize(800, 480));
        W_MainWindow->setMaximumSize(QSize(800, 480));
        centralWidget = new QWidget(W_MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 9, 781, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pbLancerPartie = new QPushButton(gridLayoutWidget);
        pbLancerPartie->setObjectName(QStringLiteral("pbLancerPartie"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbLancerPartie->sizePolicy().hasHeightForWidth());
        pbLancerPartie->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pbLancerPartie, 0, 0, 1, 1);

        pbOptions = new QPushButton(gridLayoutWidget);
        pbOptions->setObjectName(QStringLiteral("pbOptions"));
        sizePolicy.setHeightForWidth(pbOptions->sizePolicy().hasHeightForWidth());
        pbOptions->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pbOptions, 0, 1, 1, 1);

        pbEteindre = new QPushButton(centralWidget);
        pbEteindre->setObjectName(QStringLiteral("pbEteindre"));
        pbEteindre->setGeometry(QRect(610, 370, 171, 41));
        W_MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(W_MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        W_MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(W_MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        W_MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(W_MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        W_MainWindow->setStatusBar(statusBar);

        retranslateUi(W_MainWindow);

        QMetaObject::connectSlotsByName(W_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *W_MainWindow)
    {
        W_MainWindow->setWindowTitle(QApplication::translate("W_MainWindow", "W_MainWindow", nullptr));
        pbLancerPartie->setText(QApplication::translate("W_MainWindow", "Lancer une partie", nullptr));
        pbOptions->setText(QApplication::translate("W_MainWindow", "Options", nullptr));
        pbEteindre->setText(QApplication::translate("W_MainWindow", "Eteindre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_MainWindow: public Ui_W_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MAINWINDOW_H
