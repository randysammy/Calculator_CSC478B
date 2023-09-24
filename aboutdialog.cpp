#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    qDebug("AboutDialog object created");
    setWindowTitle("About TeamX");
}

AboutDialog::~AboutDialog()
{
    delete ui;
    qDebug("AboutDialog object destroyed");
}



void AboutDialog::on_BackButton_released()
{
    this->close();
}

