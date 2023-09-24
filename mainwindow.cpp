#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mathengine.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      AboutDialogPtr(std::make_unique<AboutDialog>()),
      MathEnginePtr(std::make_unique<MathEngine>()),
      Op(MathOp::Undefined),
      a(0.0),
      b(0.0)
{
    ui->setupUi(this);
    CLS();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DzeroButton_released()
{
    qDebug("Num00 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "00");
}

void MainWindow::on_ZeroButton_released()
{
    qDebug("Num0 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "0");
}

void MainWindow::on_DecButton_released()
{
    qDebug("Dec button clicked !");
    ui->LCD->setText(ui->LCD->text() + ".");
}

void MainWindow::on_No1_released()
{
    qDebug("Num1 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "1");
}

void MainWindow::on_No2_released()
{
    qDebug("Num2 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "2");
}


void MainWindow::on_No3_released()
{
    qDebug("Num3 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "3");
}

void MainWindow::on_No4_released()
{
    qDebug("Num4 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "4");
}

void MainWindow::on_No5_released()
{
    qDebug("Num5 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "5");
}

void MainWindow::on_No6_released()
{
    qDebug("Num6 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "6");
}

void MainWindow::on_No7_released()
{
    qDebug("Num7 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "7");
}


void MainWindow::on_No8_released()
{
   qDebug("Num8 button clicked !");
   ui->LCD->setText(ui->LCD->text() + "8");
}

void MainWindow::on_No9_released()
{
    qDebug("Num9 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "9");
}

//----------------------------------------------
void MainWindow::on_SinButton_released()
{
    qDebug("Sin button clicked !");
    Op = MathOp::Sin;
}

void MainWindow::on_CosButton_released()
{
    qDebug("Cos button clicked !");
    Op = MathOp::Cos;
}


void MainWindow::on_TanButton_released()
{
    qDebug("Tan button clicked !");
    Op = MathOp::Tan;
}


void MainWindow::on_AsinButton_released()
{
    qDebug("ASin button clicked !");
    Op = MathOp::Asin;
}


void MainWindow::on_AcosButton_released()
{
    qDebug("ACos button clicked !");
    Op = MathOp::Acos;
}


void MainWindow::on_AtanButton_released()
{
    qDebug("ATan button clicked !");
    Op = MathOp::Atan;
}


void MainWindow::on_SquaredButton_released()
{
    qDebug("Squared button clicked !");
    Op = MathOp::Squared;
}


void MainWindow::on_SqRtButton_released()
{
    qDebug("SqrRT button clicked !");
    Op = MathOp::Sqrt;
}


void MainWindow::on_ExpButton_released()
{
    qDebug("Exp button clicked !");
    Op = MathOp::Exp;
}


void MainWindow::on_CbRtButton_released()
{
    qDebug("CbRT button clicked !");
    Op = MathOp::CuRt;
}


void MainWindow::on_LogButton_released()
{
    qDebug("Log button clicked !");
    Op = MathOp::Log;
}


void MainWindow::on_LognButton_released()
{
    qDebug("LogN button clicked !");
    Op = MathOp::LogN;
}


void MainWindow::on_AddButton_released()
{
    qDebug("Add button clicked !");
    Op = MathOp::Add;
    a = ui->LCD->text().toDouble();
    CLS();
}


void MainWindow::on_SubButton_released()
{
    qDebug("Sub button clicked !");
    Op = MathOp::Sub;
    CLS();
}


void MainWindow::on_DivButton_released()
{
    qDebug("Div button clicked !");
    Op = MathOp::Div;
    CLS();
}


void MainWindow::on_MultipButton_released()
{
    qDebug("Multip button clicked !");
    Op = MathOp::Multi;
    CLS();
}

//---------- MISC FUNCTIONS ----------
void MainWindow::CLS()
{
    ui->LCD->setText("");
}

void MainWindow::on_EqualButton_released()
{
    b = ui->LCD->text().toDouble();
    ui->LCD->setText(QString::number((MathEnginePtr->ExecuteOp(Op, a, b))));
}

void MainWindow::on_Reset_released()
{
    qDebug("Reset button clicked");
    CLS();
    a= 0.0;
    b= 0.0;
    Op = MathOp::Undefined ;
}


void MainWindow::on_RoundButton_released()
{
    AboutDialogPtr->exec();
}

