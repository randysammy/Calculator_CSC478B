#include "mainwindow.h"
#include "./ui_mainwindow.h"

/*

Creates standard interface for user

(Requirement 1.0.0)
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    AboutDialogPtr(std::make_unique<AboutDialog>()),
    MathEnginePtr(std::make_unique<MathEngine>()),
    UnitConversionPtr(std::make_unique<UnitsConversion>()),
    is2ndFunButtonActive(false)

{
    ui->setupUi(this); // calls setup Ui function of the ui object using this as an argument.
    on_Reset_released(); // reset calculator to be blank
    LoadUiButtons(); //Add all UI push buttons to a vector
    Task t1 ;
    t1.Data = {1,2,3,6,4};
    t1.Op = MathOp::Mean;
    qDebug()<<"Meeeeeeeeeeeeeeeeean = " <<MathEnginePtr->Run(t1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/

void MainWindow::on_DzeroButton_released()// member function for MainWindow Class
{
    qDebug("Num00 button clicked !"); // outputs debug message to terminal, help track signal
    ui->LCD->setText(ui->LCD->text() + "00"); // updates text in the widget ui->LCD
    ui->LCD2->setText(ui->LCD2->text() + "00"); // updates text in the widget ui->LCD2
}

/*

Changes current value to negative
(Requirement 2.1.0)
*/
void MainWindow::on_ToNegButton_released()
{
    qDebug("Negative button clicked!");
    double current_number = ui->LCD->text().toDouble() * -1; // grabs current var in the LCD and make it negative assign to new variable
    ui->LCD->setText(QString::number(current_number)); // displays the negative value in calcultor

}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_ZeroButton_released()
{
    qDebug("Num0 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "0");
    ui->LCD2->setText(ui->LCD2->text() + "0");
}
/*

Returns decimal to UI
(Requirement 2.2.0)
*/
void MainWindow::on_DecButton_released()
{
    qDebug("Dec button clicked !");
    ui->LCD->setText(ui->LCD->text() + ".");
    ui->LCD2->setText(ui->LCD2->text() + ".");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No1_released()
{
    qDebug("Num1 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "1");
    ui->LCD2->setText(ui->LCD2->text() + "1");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No2_released()
{
    qDebug("Num2 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "2");
    ui->LCD2->setText(ui->LCD2->text() + "2");
}

/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No3_released()
{
    qDebug("Num3 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "3");
    ui->LCD2->setText(ui->LCD2->text() + "3");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No4_released()
{
    qDebug("Num4 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "4");
    ui->LCD2->setText(ui->LCD2->text() + "4");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No5_released()
{
    qDebug("Num5 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "5");
    ui->LCD2->setText(ui->LCD2->text() + "5");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No6_released()
{
    qDebug("Num6 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "6");
    ui->LCD2->setText(ui->LCD2->text() + "6");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No7_released()
{
    qDebug("Num7 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "7");
    ui->LCD2->setText(ui->LCD2->text() + "7");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/

void MainWindow::on_No8_released()
{
   qDebug("Num8 button clicked !");
   ui->LCD->setText(ui->LCD->text() + "8");
   ui->LCD2->setText(ui->LCD2->text() + "8");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No9_released()
{
    qDebug("Num9 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "9");
    ui->LCD2->setText(ui->LCD2->text() + "9");
}

/*

Second button function allows users to access secondary functions

(Requirement 3.9.0)
*/
void MainWindow::on_SecondButton_released()
{
    qDebug("2nd button clicked !");
    if(is2ndFunButtonActive){
        is2ndFunButtonActive = false;
        ui->SecondButton->setStyleSheet("background-color:rgb(230, 145, 56);font: 12pt 'Rockwell'; "); // set color to orange

        qDebug() << "Second is " << is2ndFunButtonActive;

    }else{
        is2ndFunButtonActive = true;
        ui->SecondButton->setStyleSheet("background-color:rgb(204, 204, 0); font: 12pt 'Rockwell';"); // set color to yellow if 2nd is on

        qDebug() << "Second is " << is2ndFunButtonActive;
    }
}

// Functions for operations

/*

Sin/ArcSin function
(Requirement 3.0.1 / 3.0.4)

*/
void MainWindow::on_SinButton_released()
{
    qDebug("Sin/ArcSin button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);

    if(is2ndFunButtonActive) //Asin
    {
        ui->LCD2->setText("arcsin(" + ui->LCD->text()+")" );
        task.Op = MathOp::Asin;
    }
    else
    {
        ui->LCD2->setText( "sin(" + ui->LCD->text()+")" ); // display function in left LCD2 like this sin(current_num)
        task.Op = MathOp::Sin;
    }
    task.Data.push_back(GetNumOnScreen());
}
/*

Cos/ArCos function
(Requirement 3.0.2 / 3.0.5)

*/
void MainWindow::on_CosButton_released()
{
    qDebug("Cos/ArCcos button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);

    if(is2ndFunButtonActive) //ArCos
    {
        ui->LCD2->setText("arccos(" + ui->LCD->text()+")" );
        task.Op = MathOp::Acos;
    }
    else
    {
        ui->LCD2->setText( "cos(" + ui->LCD->text()+")" ); // display function in left LCD2 like this sin(current_num)
        task.Op = MathOp::Cos;
    }
    task.Data.push_back(GetNumOnScreen());
}

/*

Tan/ArcTan function
(Requirement 3.0.3 / 3.0.6)

*/
void MainWindow::on_TanButton_released()
{
    qDebug("Tan/ArcTan button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);

    if(is2ndFunButtonActive) //ArCos
    {
        ui->LCD2->setText("arctan(" + ui->LCD->text()+")" );
        task.Op = MathOp::Atan;
    }
    else
    {
        ui->LCD2->setText( "tan(" + ui->LCD->text()+")" ); // display function in left LCD2 like this sin(current_num)
        task.Op = MathOp::Tan;
    }
    task.Data.push_back(GetNumOnScreen());
}

/*

Square of a number
(Requirement 3.3.1)

*/
void MainWindow::on_SquaredButton_released()
{
    qDebug("Squared button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);
    ui->LCD2->setText(ui->LCD->text()+"²" );
    task.Op = MathOp::Squared;
    task.Data.push_back(GetNumOnScreen());
}

/*

Square root function
(Requirement 3.3.2)

*/
void MainWindow::on_SqRtButton_released()
{
    qDebug("SqrRT button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);
    ui->LCD2->setText( "√(" +ui->LCD->text() + ")" );
    task.Op = MathOp::Sqrt;
    task.Data.push_back(GetNumOnScreen());
}


/*

Exponent of a number
(Requirement 3.3.3)

*/
void MainWindow::on_ExpButton_released()
{
    qDebug("Exp button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);
    ui->LCD2->setText( "(" +ui->LCD->text() + ")" +"^");
    task.Op = MathOp::Exp;
    task.Data.push_back(GetNumOnScreen());
    /* Note that Exp value will be grabbed by HandleTask function
     * Without clearing the screen the number will be added to the exp
     * Therefor it is required here
     */
    CLS(LCDs::LCD1);
}

/*

CubeRoot of a number
(Requirement 3.1.0)

*/
void MainWindow::on_CbRtButton_released()
{
    qDebug("CbRT button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);


    if(is2ndFunButtonActive)
    {
        task.Op = MathOp::Cubed;
        ui->LCD2->setText(ui->LCD->text() + "³" );
    }
    else
    {
        task.Op = MathOp::CuRt;
        ui->LCD2->setText("∛( " + ui->LCD->text() + ")" );
    }
    task.Data.push_back(GetNumOnScreen());
}
/*

Common log base10 of a number / 10^X
(Requirement 3.2.1)

*/
// log base 10 function
void MainWindow::on_LogButton_released()
{
    qDebug("Log/10^x button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);

    if(is2ndFunButtonActive)
    {
        ui->LCD2->setText(+ "(10)^" + ui->LCD->text());
        task.Op = MathOp::TenTo;
    }
    else
    {
        ui->LCD2->setText("log("+ ui->LCD->text()+")" );
        task.Op = MathOp::Log ;
    }
    task.Data.push_back(GetNumOnScreen());
}
/*

Natural log or ln of a number
(Requirement 3.2.2)

*/
// ln natural logarthim function
void MainWindow::on_LognButton_released()
{
    qDebug("ln / e^x button clicked !");
    EnableDisableKeyPad(false); //disable keypad
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);

    if(is2ndFunButtonActive)
    {
        ui->LCD2->setText(+ "(e)^" + ui->LCD->text());
        task.Op = MathOp::EtoExp;
    }
    else
    {
        ui->LCD2->setText("ln("+ ui->LCD->text()+")");
        task.Op = MathOp::LogN;
    }
    task.Data.push_back(GetNumOnScreen());
}

/*

Addition operation
(Requirement 2.0.1)

*/
void MainWindow::on_AddButton_released()
{
    qDebug("Add button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"AddButton","EqualButton"},true);
    if(task.Op == MathOp::Add || task.Op == MathOp::Undefined)
    {
        task.Op = MathOp::Add;
        task.Data.push_back(GetNumOnScreen());
        CLS(LCDs::LCD1);
        ui->LCD2->setText(ui->LCD2->text() + "+");
    }
    else
    {
        HandleTask();
        task.Op = MathOp::Add;
        CLS(LCDs::LCD1);
        ui->LCD2->setText(ui->LCD2->text() + "+");
    }
}

/*

Subtraction operation
(Requirement 2.0.2)

*/
void MainWindow::on_SubButton_released()
{
    qDebug("Sub button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"SubButton","EqualButton"},true);
    if(task.Op == MathOp::Sub || task.Op == MathOp::Undefined )
    {
        task.Op = MathOp::Sub;
        task.Data.push_back(GetNumOnScreen());
        CLS(LCDs::LCD1);
        ui->LCD2->setText(ui->LCD2->text() + "-");
    }
    else
    {
        HandleTask();
    }

}

/*

Division operation
(Requirement 2.0.4)

*/
void MainWindow::on_DivButton_released()
{
    qDebug("Division button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"DivButton","EqualButton"},true);
    if(task.Op == MathOp::Div || task.Op == MathOp::Undefined )
    {
        task.Op = MathOp::Div;
        task.Data.push_back(GetNumOnScreen());
        CLS(LCDs::LCD1);
        ui->LCD2->setText(ui->LCD2->text() + "/");
    }
    else
    {
        HandleTask();
    }

}

/*

Multiplication operation
(Requirement 2.0.3)

*/
void MainWindow::on_MultipButton_released()
{
    EnableDisableGroupButtons(std::vector<QString>{"MultipButton","EqualButton"},true);
    if(task.Op == MathOp::Multi || task.Op == MathOp::Undefined )
    {
        task.Op = MathOp::Multi;
        task.Data.push_back(GetNumOnScreen());
        CLS(LCDs::LCD1);
        ui->LCD2->setText(ui->LCD2->text() + "*");
    }
    else
    {
        HandleTask();
    }
    qDebug("Multi button clicked !");
}

//---------- MISC FUNCTIONS ----------

/*

Reset calcutlrou UI

(Requirement 2.5.0)

*/
void MainWindow::CLS(LCDs lcd)
{
    switch(lcd)
    {
    case (LCDs::LCD1):
        ui->LCD->setText(""); // clear 1st LCD
        break;

    case (LCDs::LCD2):
        ui->LCD2->setText("");// cleard 2nd LCD
        break;

    case (LCDs::Both):
        ui->LCD->setText(""); // clear 1st LCD
        ui->LCD2->setText("");// cleard 2nd LCD
        break;
    default:
        throw std::runtime_error("Undefined CLS operation!");
    }
}

/*

Converts double type to string for UI
(Requirement 1.4.0)
*/

QString MainWindow::convertToString(double num)
{
    QString myString = QString::number(num);
    return myString;

}

//Unit Conversion functions - each unit conversion function converts between both units

/*

Converts feet to inches and vice versa

(Requirement 3.4.1 - 3.4.2)
*/

void MainWindow::on_FeetToInches_released()
{
    qDebug("Feet-Inches button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset"},true);
    EnableDisableKeyPad(false);
    if(is2ndFunButtonActive)
    { // conversion for inches to feet
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::InToFt,GetNumOnScreen())) + " feet" );
    }
    else
    { // conversion for feet to inches
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::FtToIn,GetNumOnScreen())) + " inches");
    }
}
/*

Converts ounces to grams and vice versa

(Requirement 3.4.3 - 3.4.4)
*/

void MainWindow::on_OuncesToGrams_released()
{
    qDebug("Grams-Ounces button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset"},true);
    EnableDisableKeyPad(false);

    if(is2ndFunButtonActive)
    { // conversion for grams to ounces
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::GrToOz,GetNumOnScreen())) + " ounces" );
    }

    else
    { // conversion for ounces to gram
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::OzToGr,GetNumOnScreen())) + " grams" );
    }

}
/*

Converts gallons to liter  and vice versa

(Requirement 3.4.7 - 3.4.8)
*/

void MainWindow::on_GallonsToLiters_released()
{
    qDebug("Gal-Liter button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset"},true);
    EnableDisableKeyPad(false);

    if(is2ndFunButtonActive)
    { // conversion for liters to gallons
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::LtToGal,GetNumOnScreen())) + " Gallons" );
    }else
    { // conversion for gallons to liters
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::GalToLt,GetNumOnScreen())) + " Liters" );
    }
}

/*

Converts degree to radians and vice versa

(Requirement 3.4.5 - 3.4.6)
*/

void MainWindow::on_DegreeToRad_released()
{
    qDebug("Deg to Radr button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset"},true);
    EnableDisableKeyPad(false);

    if(is2ndFunButtonActive)
    { // convert rad to degree
        ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::RadToDeg,GetNumOnScreen())) + "°" );
    }
    else
    { // convert degree to rad
       ui->LCD2->setText(convertToString(UnitConversionPtr->Convert(Units::DegToRad,GetNumOnScreen())) + "Radians" );
    }
}

/*

Produces reciprocal of a number & Factorial fucntion

(Requirement 3.8.0  -  3.7.0)
*/

// negative exponent (recirpocal of x) and factorial function
void MainWindow::on_XtoNeg_released()
{
    qDebug("Deg to Radr button clicked !");
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton"},true);
    EnableDisableKeyPad(false);
    if(is2ndFunButtonActive)
    {//factorial
       ui->LCD2->setText("!" + ui->LCD->text());
       task.Op = MathOp::Fact;

    }
    else
    {
        task.Op = MathOp::Rec;
    }
    task.Data.push_back(GetNumOnScreen());
}

// Pi
void MainWindow::on_Pi_released()
{
    ui->LCD->setText(ui->LCD->text() + convertToString(MathEnginePtr->Pi));
}

/*

Resets initalize values for calc.
(Requirement 2.5.0)
*/
void MainWindow::on_Reset_released()
{
    qDebug("Reset button clicked");
    CLS(LCDs::Both); // clear screen CLS(LCDs::Both) function
    DeactivateSecondFuncButton();
    EnableDisableAllButtons(true);
    EnableDisableKeyPad(true);
    task.Data.clear();
    task.Op = MathOp::Undefined;
}


void MainWindow::on_RoundButton_released()
{
    AboutDialogPtr->exec();
}

/*

Finds mean in an array

(Requirement 3.5.2)
*/

void MainWindow::on_Mean_released()
{
    CLS(LCDs::Both);
    qDebug("Mean function button clicked");
    task.Op = MathOp::Mean;
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton","EnterButton"},true);
    ui->LCD2->setText("Mean ");
}
/*

Finds median in an array

(Requirement 3.5.3)
*/

void MainWindow::on_Median_released()
{
    qDebug("Mean function button clicked");
    CLS(LCDs::Both);
    task.Op = MathOp::Median;
    EnableDisableGroupButtons(std::vector<QString>{"Reset","EqualButton","EnterButton"},true);
    ui->LCD2->setText("Median ");
}
/*

Allows user to return result to UI
(Requirement 2.4.0)
*/
void MainWindow::on_EqualButton_released()
{

    HandleTask();
    ui->LCD2->setText(ui->LCD->text());
    EnableDisableAllButtons(true);
    EnableDisableKeyPad(true);
    DeactivateSecondFuncButton();
}

void MainWindow::on_EnterButton_released()
{
    ui->LCD2->setText(ui->LCD2->text() + " ");
    task.Data.push_back(GetNumOnScreen());
    CLS(LCDs::LCD1); // clear for the next number to be entered
}

void MainWindow::DeactivateSecondFuncButton()
{
    is2ndFunButtonActive = false;
    ui->SecondButton->setStyleSheet("background-color:rgb(230, 145, 56);font: 12pt 'Rockwell'; "); // set color to orange
}

void MainWindow::HandleTask()
{
    qDebug()<<"Size is"<<task.Data.size();
    if (task.Data.size())
    {
        //Edge case, mean and median data input might not have anything on the screen when enter is clicked
        if((task.Op != MathOp::Mean) && (task.Op != MathOp::Median))
            {
                task.Data.push_back(GetNumOnScreen());
            }
            ui->LCD->setText(convertToString(MathEnginePtr->Run(task)));
            qDebug()<<MathEnginePtr->Run(task);
            task.Data.clear();
            task.Op = MathOp::Undefined; //not sure I need this for now     
    }
    else
    {
            qDebug()<<"WARNING, HandleTask called with NO DATA !!?";
    }
}

double MainWindow::GetNumOnScreen()
{
    if(!ui->LCD->text().isEmpty())
    {
            return ui->LCD->text().toDouble();
    }
    else
    {
            qDebug()<<"WARNING, GetNumOnScreen called with invalid value !!?";
            CLS(LCDs::Both);
            EnableDisableGroupButtons(std::vector<QString>{"Reset"},true);
            EnableDisableKeyPad(false);
            ui->LCD2->setText("ERROR, invalid value, please reset");
            return 0.0 ;
    }

}


//-----------------------------UI helpers-----------------------------
//Fille a map where K = button name and V = a pointer to the button on the UI
void MainWindow::LoadUiButtons()
{
    auto AdvBox = ui->AdvOpsBox->findChildren<QPushButton*>();
    for(const auto& button : AdvBox)
    {
            AllMathOpButtons.insert(qMakePair(button->objectName(),button));
    }
    auto SimpleOps = ui->SimpleOpBox->findChildren<QPushButton*>();
    for(const auto& button : SimpleOps)
    {
            AllMathOpButtons.insert(qMakePair(button->objectName(),button));
    }
}

void MainWindow::EnableDisableAllButtons(bool isEnabled)
{
    for(const auto& button :AllMathOpButtons)
    {
           button.second->setEnabled(isEnabled);
    }
}

//Used to enable/disble a group of buttons
void MainWindow::EnableDisableGroupButtons(std::vector<QString>ButtonsToEnable, bool isEnabled)
{
    EnableDisableAllButtons(false); //disable all first
    for(const auto& ButtonName :ButtonsToEnable)
    {
           AllMathOpButtons.at(ButtonName)->setEnabled(isEnabled);
    }
}

void MainWindow::EnableDisableKeyPad(bool isEnabled)
{
    auto KeyPadButtons = ui->KeyPadBox->findChildren<QPushButton*>();
    for (const auto& button : KeyPadButtons)
    {
           button->setEnabled(isEnabled);
    }
}
