#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mathengine.h"
#include "aboutdialog.h"


bool is2ndClicked = false;
//Construcutor for main window class

MainWindow::MainWindow(QWidget *parent)// constructor for the main window class takes qwidget pointer parent as argument
    : QMainWindow(parent), // initalize base class
      ui(new Ui::MainWindow),// creates a new instance of the ui::mainwindow class stores it in ui member variable
      AboutDialogPtr(std::make_unique<AboutDialog>()), // creates a unique pointer to aboutdialog instance (do we reference this back when we call the ____ ?)
      MathEnginePtr(std::make_unique<MathEngine>()), // create a unique pointer to a math engine instance ( do we reference this back when we call the math functions?)
      Op(MathOp::Undefined), // used store operation type
      a(0.0), // initalize a with value of 0.0
      b(0.0) // initalize b with value of 0.0

{
    ui->setupUi(this); // calls setup Ui function of the ui object using this as an argument.

    CLS(); // reset calculator to be blank
}

MainWindow::~MainWindow()
{
    delete ui;
}

// member functions belonging to a MainWindow Class

void MainWindow::on_DzeroButton_released()// member function for MainWindow Class
{
    qDebug("Num00 button clicked !"); // outputs debug message to terminal, help track signal
    ui->LCD->setText(ui->LCD->text() + "00"); // updates text in the widget ui->LCD
}

// change a value to negative, grabs the current value in LCD that will be our current a
void MainWindow::on_ToNegButton_released()
{
    qDebug("Negative button clicked!");
    double current_number = ui->LCD->text().toDouble() * -1; // grabs current var in the LCD and make it negative assign to new variable
    ui->LCD->setText(QString::number(current_number)); // displays the negative value in calcultor

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

void MainWindow::on_SecondButton_released()
{
    qDebug("2nd button clicked !");
    if(is2ndClicked==true){
        is2ndClicked = false;
        ui->SecondButton->setStyleSheet("background-color:rgb(230, 145, 56);font: 12pt 'Rockwell'; "); // set color to orange

        qDebug() << "Second is " << is2ndClicked;

    }else{
        is2ndClicked = true;
        ui->SecondButton->setStyleSheet("background-color:rgb(204, 204, 0); font: 12pt 'Rockwell';"); // set color to yellow if 2nd is on

        qDebug() << "Second is " << is2ndClicked;


    }
}
//Buttons for operations

//----------------------------------------------
void MainWindow::on_SinButton_released()
{
    qDebug("Sin button clicked !");

    // check if 2nd clicked if true send sin inverse
    if(is2ndClicked == true){
        on_AsinButton_released();

    }else{
        double current_num = ui->LCD->text().toDouble(); // grab the current num convert to double and store it
        Op = MathOp::Sin; // Stores operation as sun in Op
        ui->LCD_2->setText("sin(" + convertToString(current_num) + ")" ); // display function in left LCD_2 like this sin(current_num)
    }

}

void MainWindow::on_CosButton_released()
{
    qDebug("Cos button clicked !");

    if(is2ndClicked == true){
        on_AcosButton_released(); // run arccos function
    }else{
        double current_num = ui->LCD->text().toDouble();
        Op = MathOp::Cos;
        ui->LCD_2->setText("cos(" + convertToString(current_num) + ")" );
    }

}


void MainWindow::on_TanButton_released()
{
    qDebug("Tan button clicked !");

    if(is2ndClicked == true){
        on_AtanButton_released(); // run arctan function
    }else{
        double current_num = ui->LCD->text().toDouble();
        Op = MathOp::Tan;
        ui->LCD_2->setText("tan(" + convertToString(current_num) + ")" );
    }

}


void MainWindow::on_AsinButton_released()
{
    qDebug("ASin button clicked !");

    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Asin;
    ui->LCD_2->setText("arcsin(" + convertToString(current_num) + ")" );
}


void MainWindow::on_AcosButton_released()
{
    qDebug("ACos button clicked !");

    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Acos;
    ui->LCD_2->setText("arccos(" + convertToString(current_num) + ")" );
}


void MainWindow::on_AtanButton_released()
{
    qDebug("ATan button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Atan;
    ui->LCD_2->setText("arctan(" + convertToString(current_num) + ")" );
}


void MainWindow::on_SquaredButton_released()
{
    qDebug("Squared button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Squared;
    ui->LCD_2->setText(convertToString(current_num) + "²" );
}


void MainWindow::on_SqRtButton_released()
{
    qDebug("SqrRT button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Sqrt;
    ui->LCD_2->setText( "√(" +convertToString(current_num) + ")" );
}


void MainWindow::on_ExpButton_released()
{
    qDebug("Exp button clicked !");
    Op = MathOp::Exp;
    a = ui->LCD->text().toDouble();
    CLS();
}


void MainWindow::on_CbRtButton_released()
{
    qDebug("CbRT button clicked !");
    if(is2ndClicked==true){
        Op = MathOp::Cubed;
    }else{
        Op = MathOp::CuRt;
    }
}

// log base 10
void MainWindow::on_LogButton_released()
{
    qDebug("Log button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Log;
    ui->LCD_2->setText( "log(" +convertToString(current_num) + ")" );
}

// ln natural logarthim
void MainWindow::on_LognButton_released()
{
    qDebug("LogN button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::LogN;
    ui->LCD_2->setText( "ln(" +convertToString(current_num) + ")" );
}

// stores Mathop::Add
void MainWindow::on_AddButton_released()
{
    qDebug("Add button clicked !"); // logs message in terminal when add button is clicked
    Op = MathOp::Add; // Set the operation equal to MathOp::Add
    a = ui->LCD->text().toDouble(); // grabs text in LCD converts to double and assigns to a
    CLS();// clear screen
}


void MainWindow::on_SubButton_released()
{
    qDebug("Sub button clicked !");
    Op = MathOp::Sub;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}


void MainWindow::on_DivButton_released()
{
    qDebug("Div button clicked !");
    Op = MathOp::Div;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}


void MainWindow::on_MultipButton_released()
{
    qDebug("Multip button clicked !");
    Op = MathOp::Multi;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}

//---------- MISC FUNCTIONS ----------
void MainWindow::CLS()
{
    ui->LCD->setText(""); // clear screen
    ui->LCD_2->setText("");
}
// converts a and b to strings and returns it
QString MainWindow::convertToString(double num)
{
    QString myString = QString::number(num);
    return myString;

}

//Unit Conversions

void MainWindow::on_FeetToInches_released(){
    if(is2ndClicked == true){ // conversion for inches to feet
        a = ui->LCD->text().toDouble();
        double convertedValue = a / 12;
        ui->LCD_2->setText( convertToString(convertedValue) + " inches" );
    }else{ // conversion for feet to inches
        a = ui->LCD->text().toDouble();
        double convertedValue = a * 12;
        ui->LCD_2->setText( convertToString(convertedValue) + " inches" );
    }


}

void MainWindow::on_OuncesToGrams_released(){
    if(is2ndClicked == true){ // conversion for grams to ounces
        a = ui->LCD->text().toDouble();
        double convertedValue = a * 0.035275;
        ui->LCD_2->setText( convertToString(convertedValue) + " ounces" );
    }else{ // conversion for ounces to gram
        a = ui->LCD->text().toDouble();
        double convertedValue = a / 0.035275;
        ui->LCD_2->setText( convertToString(convertedValue) + " grams" );
    }

}

void MainWindow::on_GallonsToLiters_released(){
    if(is2ndClicked == true){ // conversion for liters to gallons
        a = ui->LCD->text().toDouble();
        double convertedValue = a * 0.264172;
        ui->LCD_2->setText( convertToString(convertedValue) + " gallons" );
    }else{ // conversion for gallons to liters
        a = ui->LCD->text().toDouble();
        double convertedValue = a / 0.264172;
        ui->LCD_2->setText( convertToString(convertedValue) + " liters" );
    }

}
// WIP Discuss how this will work
void MainWindow::on_DegreeToRad_released(){

}

// negative exponent (recirpocal of x)
void MainWindow::on_XtoNeg_released(){
    if(is2ndClicked==true){
        on_Factorial_released();
    }else{
        a = ui->LCD->text().toDouble();
        double convertedValue = 1 / a;
        ui->LCD_2->setText( convertToString(convertedValue));
    }
}

void MainWindow::on_Factorial_released(){
    a = ui->LCD->text().toDouble();
    double factorial = 1.0;
    for(int i = 1; i <= a; ++i) {
        factorial *= i;
    }
    ui->LCD_2->setText( convertToString(factorial) );



}

// Pi
void MainWindow::on_Pi_released(){
    ui->LCD->setText(ui->LCD->text() + "3.14159265358");

}

void MainWindow::on_EqualButton_released()
{
    b = ui->LCD->text().toDouble();// grabs text displayed on lcd converts to double and assign to b
    ui->LCD->setText(QString::number((MathEnginePtr->ExecuteOp(Op, a, b)))); // execute operation using a and b and display on LCD
    qDebug("Equal button clicked !");

    //Debug code helps see what the current a and b are
    qDebug("Variable a is ");
    qDebug() << convertToString(a);
    qDebug("Variable b is ");
    qDebug()<< convertToString(b);
}

void MainWindow::on_Reset_released()
{
    qDebug("Reset button clicked");
    CLS(); // clear screen CLS() function
    a= 0.0; // set a and b to 0.0
    b= 0.0;
    Op = MathOp::Undefined ; // set the current operation to undefined
}


void MainWindow::on_RoundButton_released()
{
    AboutDialogPtr->exec();
}

