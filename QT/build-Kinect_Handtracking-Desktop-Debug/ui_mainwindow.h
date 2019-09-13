/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <viewport.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_start;
    QAction *act_stop;
    QAction *info_status;
    QAction *action_stop;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *minlabel;
    QSlider *minDepth;
    QLabel *maxlabel;
    QSlider *maxDepth;
    ViewPort *canvas;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuDevice;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(534, 487);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        act_start = new QAction(MainWindow);
        act_start->setObjectName(QString::fromUtf8("act_start"));
        act_stop = new QAction(MainWindow);
        act_stop->setObjectName(QString::fromUtf8("act_stop"));
        info_status = new QAction(MainWindow);
        info_status->setObjectName(QString::fromUtf8("info_status"));
        info_status->setEnabled(false);
        action_stop = new QAction(MainWindow);
        action_stop->setObjectName(QString::fromUtf8("action_stop"));
        action_stop->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(200, 200));
        centralWidget->setMaximumSize(QSize(653, 457));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        minlabel = new QLabel(centralWidget);
        minlabel->setObjectName(QString::fromUtf8("minlabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(minlabel->sizePolicy().hasHeightForWidth());
        minlabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(minlabel);

        minDepth = new QSlider(centralWidget);
        minDepth->setObjectName(QString::fromUtf8("minDepth"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(minDepth->sizePolicy().hasHeightForWidth());
        minDepth->setSizePolicy(sizePolicy3);
        minDepth->setMaximum(1500);
        minDepth->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(minDepth);

        maxlabel = new QLabel(centralWidget);
        maxlabel->setObjectName(QString::fromUtf8("maxlabel"));
        sizePolicy2.setHeightForWidth(maxlabel->sizePolicy().hasHeightForWidth());
        maxlabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(maxlabel);

        maxDepth = new QSlider(centralWidget);
        maxDepth->setObjectName(QString::fromUtf8("maxDepth"));
        maxDepth->setMinimumSize(QSize(0, 0));
        maxDepth->setMaximum(1500);
        maxDepth->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(maxDepth);

        canvas = new ViewPort(centralWidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy4);
        canvas->setMinimumSize(QSize(512, 424));
        canvas->setSizeIncrement(QSize(512, 525));
        canvas->setBaseSize(QSize(1024, 848));

        verticalLayout_2->addWidget(canvas);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 30));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QString::fromUtf8("menuDevice"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuDevice->menuAction());
        menuDevice->addAction(act_start);
        menuDevice->addAction(act_stop);
        menuDevice->addSeparator();
        menuDevice->addAction(info_status);
        menuDevice->addAction(action_stop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        act_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        act_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        info_status->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        action_stop->setText(QCoreApplication::translate("MainWindow", "Running", nullptr));
        minlabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        maxlabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuDevice->setTitle(QCoreApplication::translate("MainWindow", "Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
