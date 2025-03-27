#include "mainwindow.h"
#include "collatzcounter.h"
#include "ui_mainwindow.h"
#include <Qthread>
#include <QMessageBox>
#include <thread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect( ui->threadSlider,SIGNAL(valueChanged(int)),ui->threadNumSlider,SLOT(setValue(int)));

    int maxThreads = std::thread::hardware_concurrency();
    ui->threadSlider->setMinimum(1);
    ui->threadSlider->setMaximum(maxThreads);
     ui->threadNumSlider->setMinimum(1);
    ui->threadNumSlider->setMaximum(maxThreads);

    ui->Stop_button->setEnabled(false);

    connect(ui->Start_button,&QPushButton::clicked,this,&MainWindow::on_Start_button_clicked);
    connect(ui->Stop_button,&QPushButton::clicked,this,&MainWindow::on_Stop_button_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_button_clicked()
{
    long long n = ui->spinBox->value();
    int numThreads = ui->threadSlider->value();

    ui->textOutput->clear();

    ui->Start_button->setEnabled(false);
    ui->Stop_button->setEnabled(true);
    CollatzCounter* collatzCounter = new CollatzCounter(n,numThreads);
    QThread* threadUI = new QThread();

    connect(threadUI, &QThread::started, collatzCounter, &CollatzCounter::StartCalc);
    connect(collatzCounter,&CollatzCounter::calcFinished,this,&MainWindow::finishedCalculation);
    connect(collatzCounter, &CollatzCounter::calcFinished, threadUI, &QThread::quit);
    connect(threadUI, &QThread::finished, threadUI, &QObject::deleteLater);
    connect(threadUI, &QThread::finished, collatzCounter, &QObject::deleteLater);

    collatzCounter->moveToThread(threadUI);
    threadUI->start();

}

void MainWindow::on_Stop_button_clicked()
{
    if(collatzCounter)
    {
        collatzCounter->StopCalc();
    }
    ui->Start_button->setEnabled(true);
    ui->Stop_button->setEnabled(false);
}

void MainWindow::finishedCalculation(long long maxNum, long long maxSteps,int time)
{

    if(maxNum == -1 && maxSteps == -1 && time == - 1)
    {
        QMessageBox::critical(this,"Error","Memory...");
        return;
    }


    ui->textOutput->setText(QString("Number with max steps: %1\nCount of steps: %2\nTime: %3 ms")
                                .arg(maxNum)
                                .arg(maxSteps)
                                .arg(time));

    ui->Start_button->setEnabled(true);
    ui->Stop_button->setEnabled(false);
}




