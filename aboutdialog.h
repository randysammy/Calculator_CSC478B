#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();
// error was detected by jenkins here - Randy
private slots:


    void on_BackButton_released();

private:
    Ui::AboutDialog *ui;

};

#endif // ABOUTDIALOG_H
