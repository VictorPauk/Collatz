/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Exit;
    QPushButton *Start_button;
    QPushButton *Stop_button;
    QSlider *threadSlider;
    QTextEdit *textOutput;
    QSpinBox *spinBox;
    QProgressBar *threadNumSlider;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(600, 530, 181, 61));
        Start_button = new QPushButton(centralwidget);
        Start_button->setObjectName("Start_button");
        Start_button->setGeometry(QRect(30, 120, 83, 29));
        Stop_button = new QPushButton(centralwidget);
        Stop_button->setObjectName("Stop_button");
        Stop_button->setEnabled(false);
        Stop_button->setGeometry(QRect(150, 120, 83, 29));
        threadSlider = new QSlider(centralwidget);
        threadSlider->setObjectName("threadSlider");
        threadSlider->setGeometry(QRect(310, 80, 481, 20));
        threadSlider->setMinimum(1);
        threadSlider->setOrientation(Qt::Orientation::Horizontal);
        textOutput = new QTextEdit(centralwidget);
        textOutput->setObjectName("textOutput");
        textOutput->setGeometry(QRect(20, 160, 291, 421));
        textOutput->setReadOnly(true);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 80, 251, 29));
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000000000);
        threadNumSlider = new QProgressBar(centralwidget);
        threadNumSlider->setObjectName("threadNumSlider");
        threadNumSlider->setGeometry(QRect(510, 100, 41, 23));
        threadNumSlider->setMinimum(1);
        threadNumSlider->setValue(1);
        threadNumSlider->setTextVisible(true);
        threadNumSlider->setOrientation(Qt::Orientation::Horizontal);
        threadNumSlider->setInvertedAppearance(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 40, 91, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 39, 181, 31));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(Exit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Start_button->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Stop_button->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        threadNumSlider->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Threads", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter your number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
