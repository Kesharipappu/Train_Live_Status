/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar_2;
    QTableWidget *tableWidget;
    QPushButton *pushButtonFetch;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditTrainNumber;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelUpdatedTime;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelTrainName;
    QLabel *labelCurrentDateTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(805, 876);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        statusbar_2 = new QStatusBar(centralwidget);
        statusbar_2->setObjectName("statusbar_2");
        statusbar_2->setGeometry(QRect(-70, 140, 3, 21));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 170, 641, 621));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: rgb(26,26,42); /* Cornflower Blue background */\n"
"    color: rgb(255,255,255); /* Black text */\n"
"    gridline-color: rgb(255,255,255); /* Black grid lines */\n"
"    font-family: Arial, sans-serif; /* Modern, clean font */\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: rgb(65, 105, 225); /* Royal Blue header background */\n"
"    color: rgb(255,255,255); /* White text for headers */\n"
"    font-weight: bold; /* Bold text for headers */\n"
"    border: 1px solid rgb(255, 255, 255); /* White border for headers */\n"
"}\n"
"QTableWidget::item:alternate {\n"
"    background-color: rgb(173, 216, 230); /* Light Blue for alternate rows */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: rgb(255, 215, 0); /* Gold for selected items */\n"
"    color: rgb(0, 0, 0); /* Black text for selected items */\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: rgb(135, 206, 250); /* Light Sky Blue for hovered items */\n"
"}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setDefaultSectionSize(108);
        pushButtonFetch = new QPushButton(centralwidget);
        pushButtonFetch->setObjectName("pushButtonFetch");
        pushButtonFetch->setGeometry(QRect(440, 10, 151, 41));
        pushButtonFetch->setStyleSheet(QString::fromUtf8("/*background-color: rgb(255, 132, 77);*/\n"
"QPushButton {\n"
"    background-color: rgb(255, 132, 77); /* Orange background */\n"
"    color: rgb(0, 0, 0); /* Black text */\n"
"    border: 2px solid rgb(205, 92, 92); /* Indian Red border */\n"
"    padding: 10px 20px; /* Padding for better appearance */\n"
"    border-radius: 5px; /* Rounded corners for a modern look */\n"
"    font-size: 16px; /* Adjust font size */\n"
"    font-weight: bold; /* Bold text */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Smooth transition */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(255, 69, 0); /* Red-Orange on hover */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border-color: rgb(255, 255, 255); /* White border on focus */\n"
"    box-shadow: 0 0 5px rgba(255, 255, 255, 0.5); /* Optional shadow on focus */\n"
"}\n"
""));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(152, 11, 261, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        horizontalLayout_3->addWidget(label_3);

        lineEditTrainNumber = new QLineEdit(layoutWidget);
        lineEditTrainNumber->setObjectName("lineEditTrainNumber");
        lineEditTrainNumber->setStyleSheet(QString::fromUtf8("/*background-color: rgb(158, 109, 97,0%);*/\n"
" background-color: rgba(255, 255, 255, 0.8);\n"
"color: rgb(0, 0, 0);\n"
"border: 1px solid rgb(100, 100, 100);\n"
" padding: 5px;\n"
" border-radius: 5px;"));

        horizontalLayout_3->addWidget(lineEditTrainNumber);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(160, 110, 421, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        horizontalLayout->addWidget(label);

        labelUpdatedTime = new QLabel(layoutWidget1);
        labelUpdatedTime->setObjectName("labelUpdatedTime");
        labelUpdatedTime->setFont(font);
        labelUpdatedTime->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        horizontalLayout->addWidget(labelUpdatedTime);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(90, 60, 531, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        horizontalLayout_2->addWidget(label_2);

        labelTrainName = new QLabel(layoutWidget2);
        labelTrainName->setObjectName("labelTrainName");
        labelTrainName->setFont(font);
        labelTrainName->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        horizontalLayout_2->addWidget(labelTrainName);

        labelCurrentDateTime = new QLabel(centralwidget);
        labelCurrentDateTime->setObjectName("labelCurrentDateTime");
        labelCurrentDateTime->setGeometry(QRect(180, 140, 441, 20));
        labelCurrentDateTime->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 805, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonFetch->setText(QCoreApplication::translate("MainWindow", "Fetch Details", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Train Number", nullptr));
#if QT_CONFIG(tooltip)
        lineEditTrainNumber->setToolTip(QCoreApplication::translate("MainWindow", "Please Enter Valid Train No", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditTrainNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Train Number", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Last Updated :", nullptr));
        labelUpdatedTime->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Train No and Name :", nullptr));
        labelTrainName->setText(QString());
        labelCurrentDateTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
