#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      MathEnginePtr(std::make_unique<MathEngine>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DzeroButton_released()
{
    qDebug("Num00 button clicked !");
    ui->LCD->setText("00");
}

void MainWindow::on_ZeroButton_released()
{
    qDebug("Num0 button clicked !");
    ui->LCD->setText("0");
}

void MainWindow::on_DecButton_released()
{
    qDebug("Dec button clicked !");
    ui->LCD->setText(".");
}

void MainWindow::on_No1_released()
{
    qDebug("Num1 button clicked !");
    ui->LCD->setText("1");
}

void MainWindow::on_No2_released()
{
    qDebug("Num2 button clicked !");
    ui->LCD->setText("2");
}


void MainWindow::on_No3_released()
{
    qDebug("Num3 button clicked !");
    ui->LCD->setText("3");
}

void MainWindow::on_No4_released()
{
    qDebug("Num4 button clicked !");
    //ui->LCD->
}

void MainWindow::on_No5_released()
{
    qDebug("Num5 button clicked !");
}

void MainWindow::on_No6_released()
{
    qDebug("Num6 button clicked !");
}

void MainWindow::on_No7_released()
{
    qDebug("Num7 button clicked !");
}


void MainWindow::on_No8_released()
{
   qDebug("Num8 button clicked !");
}

void MainWindow::on_No9_released()
{
    qDebug("Num9 button clicked !");
}

void MainWindow::on_SinButton_released()
{
    qDebug("Sin button clicked !");
}

void MainWindow::on_CosButton_released()
{
    qDebug("Cos button clicked !");
}


void MainWindow::on_TanButton_released()
{
    qDebug("Tan button clicked !");
}


void MainWindow::on_AsinButton_released()
{
    qDebug("ASin button clicked !");
}



void MainWindow::on_AcosButton_released()
{
    qDebug("ACos button clicked !");
}


void MainWindow::on_AtanButton_released()
{
    qDebug("ATan button clicked !");
}


void MainWindow::on_SquaredButton_released()
{
    qDebug("Squared button clicked !");
}


void MainWindow::on_SqRtButton_released()
{
    qDebug("SqrRT button clicked !");
}


void MainWindow::on_ExpButton_released()
{
    qDebug("Exp button clicked !");
}


void MainWindow::on_CbRtButton_released()
{
    qDebug("CbRT button clicked !");
}


void MainWindow::on_LogButton_released()
{
    qDebug("Log button clicked !");
}


void MainWindow::on_LognButton_released()
{
    qDebug("LogN button clicked !");
}


void MainWindow::on_AddButton_released()
{
    qDebug("Add button clicked !");
}


void MainWindow::on_SubButton_released()
{
    qDebug("Sub button clicked !");
}


void MainWindow::on_DivButton_released()
{
    qDebug("Div button clicked !");
}


void MainWindow::on_MultipButton_released()
{
    qDebug("Multip button clicked !");
}

