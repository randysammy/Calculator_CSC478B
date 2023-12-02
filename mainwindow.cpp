#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mathengine.h"
#include "aboutdialog.h"
#include "QTimer"

QString num; // creates empty string hold current data set
QVector<double> dataVector; // creates empty vector to hold data set
// set of bool functions used to toggle the 2nd functionalily

bool isModeFunction = false;
bool isMeanFunction = false;
bool isMedianFunction = false;
bool is2ndClicked = false;

/*

Creates standard interface for user

(Requirement 1.0.0)
*/
MainWindow::MainWindow(QWidget *parent)// constructor for the main window class takes qwidget pointer parent as argument
    : QMainWindow(parent), // initalize base class
      ui(new Ui::MainWindow),// creates a new instance of the ui::mainwindow class stores it in ui member variable
      AboutDialogPtr(std::make_unique<AboutDialog>()), // creates a unique pointer to aboutdialog instance
      MathEnginePtr(std::make_unique<MathEngine>()), // create a unique pointer to a math engine instance
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

/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/

void MainWindow::on_DzeroButton_released()// member function for MainWindow Class
{
    qDebug("Num00 button clicked !"); // outputs debug message to terminal, help track signal
    ui->LCD->setText(ui->LCD->text() + "00"); // updates text in the widget ui->LCD
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
}
/*

Returns decimal to UI
(Requirement 2.2.0)
*/
void MainWindow::on_DecButton_released()
{
    qDebug("Dec button clicked !");
    ui->LCD->setText(ui->LCD->text() + ".");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No1_released()
{
    qDebug("Num1 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "1");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No2_released()
{
    qDebug("Num2 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "2");
}

/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No3_released()
{
    qDebug("Num3 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "3");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No4_released()
{
    qDebug("Num4 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "4");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No5_released()
{
    qDebug("Num5 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "5");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No6_released()
{
    qDebug("Num6 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "6");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No7_released()
{
    qDebug("Num7 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "7");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/

void MainWindow::on_No8_released()
{
   qDebug("Num8 button clicked !");
   ui->LCD->setText(ui->LCD->text() + "8");
}
/*

Returns digits 0-9 to UI
(Requirement 2.3.0)
*/
void MainWindow::on_No9_released()
{
    qDebug("Num9 button clicked !");
    ui->LCD->setText(ui->LCD->text() + "9");
}

/*

Second button function allows users to access secondary functions

(Requirement 3.9.0)
*/
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

// Functions for operations

/*

Sin function
(Requirement 3.0.1)

*/
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
/*

Cos function
(Requirement 3.0.2)

*/
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

/*

Tan function
(Requirement 3.0.3)

*/
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

/*

Arcsin function
(Requirement 3.0.4)

*/
void MainWindow::on_AsinButton_released()
{
    qDebug("ASin button clicked !");

    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Asin;
    ui->LCD_2->setText("arcsin(" + convertToString(current_num) + ")" );
}

/*

Arccos function
(Requirement 3.0.5)

*/

void MainWindow::on_AcosButton_released()
{
    qDebug("ACos button clicked !");

    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Acos;
    ui->LCD_2->setText("arccos(" + convertToString(current_num) + ")" );
}

/*

Arctan function
(Requirement 3.0.6)

*/
void MainWindow::on_AtanButton_released()
{
    qDebug("ATan button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Atan;
    ui->LCD_2->setText("arctan(" + convertToString(current_num) + ")" );
}

/*

Square of a number
(Requirement 3.3.1)

*/
void MainWindow::on_SquaredButton_released()
{
    qDebug("Squared button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Squared;
    ui->LCD_2->setText(convertToString(current_num) + "²" );
}

/*

Square root function
(Requirement 3.3.2)

*/
void MainWindow::on_SqRtButton_released()
{
    qDebug("SqrRT button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Sqrt;
    ui->LCD_2->setText( "√(" +convertToString(current_num) + ")" );
}


/*

Exponent of a number
(Requirement 3.3.3)

*/
void MainWindow::on_ExpButton_released()
{
    qDebug("Exp button clicked !");
    Op = MathOp::Exp;
    a = ui->LCD->text().toDouble();
    CLS();
}

/*

CubeRoot of a number
(Requirement 3.1.0)

*/
void MainWindow::on_CbRtButton_released()
{
    qDebug("CbRT button clicked !");
    double current_num = ui->LCD->text().toDouble();

    if(is2ndClicked==true){
        Op = MathOp::Cubed;
        ui->LCD_2->setText(convertToString(current_num) + "³" );

    }else{
        Op = MathOp::CuRt;
        ui->LCD_2->setText("∛( " + convertToString(current_num) + ")" );

    }
}
/*

Common log base10 of a number
(Requirement 3.2.1)

*/
// log base 10 function
void MainWindow::on_LogButton_released()
{
    qDebug("Log button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::Log;
    ui->LCD_2->setText( "log(" +convertToString(current_num) + ")" );
}
/*

Natural log or ln of a number
(Requirement 3.2.2)

*/
// ln natural logarthim function
void MainWindow::on_LognButton_released()
{
    qDebug("LogN button clicked !");
    double current_num = ui->LCD->text().toDouble();
    Op = MathOp::LogN;
    ui->LCD_2->setText( "ln(" +convertToString(current_num) + ")" );
}

/*

Addition operation
(Requirement 2.0.1)

*/
void MainWindow::on_AddButton_released()
{
    qDebug("Add button clicked !"); // logs message in terminal when add button is clicked
    Op = MathOp::Add; // Set the operation equal to MathOp::Add
    a = ui->LCD->text().toDouble(); // grabs text in LCD converts to double and assigns to a
    CLS();// clear screen
}

/*

Subtraction operation
(Requirement 2.0.2)

*/
void MainWindow::on_SubButton_released()
{
    qDebug("Sub button clicked !");
    Op = MathOp::Sub;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}

/*

Division operation
(Requirement 2.0.4)

*/
void MainWindow::on_DivButton_released()
{
    qDebug("Div button clicked !");
    Op = MathOp::Div;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}

/*

Multiplication operation
(Requirement 2.0.3)

*/
void MainWindow::on_MultipButton_released()
{
    qDebug("Multip button clicked !");
    Op = MathOp::Multi;
    a = ui->LCD->text().toDouble(); //gets text in LCD converts to double and assign to var a
    CLS();
}

//---------- MISC FUNCTIONS ----------

/*

Reset calcutlrou UI

(Requirement 2.5.0)

*/
void MainWindow::CLS()
{
    ui->LCD->setText(""); // clear 1st LCD
    ui->LCD_2->setText("");// cleard 2nd LCD
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

void MainWindow::on_FeetToInches_released(){
    if(is2ndClicked == true){ // conversion for inches to feet
        a = ui->LCD->text().toDouble();
        double convertedValue = a / 12;
        ui->LCD_2->setText( convertToString(convertedValue) + " feet" );
    }else{ // conversion for feet to inches
        a = ui->LCD->text().toDouble();
        double convertedValue = a * 12;
        ui->LCD_2->setText( convertToString(convertedValue) + " inches" );
    }


}
/*

Converts ounces to grams and vice versa

(Requirement 3.4.3 - 3.4.4)
*/

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
/*

Converts gallons to liter  and vice versa

(Requirement 3.4.7 - 3.4.8)
*/

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

/*

Converts degree to radians and vice versa

(Requirement 3.4.5 - 3.4.6)
*/

void MainWindow::on_DegreeToRad_released(){
    if(is2ndClicked == true){ // convert rad to degree
        a = ui->LCD->text().toDouble();// grab value from UI
        double convertedValue = a * (180/3.14159265359);
        ui->LCD_2->setText(convertToString(convertedValue) + "°");
    }else{ // convert degree to rad
        a = ui->LCD->text().toDouble();// grab value from UI
        double convertedValue = a * (3.14159265359/180);
        ui->LCD_2->setText(convertToString(convertedValue) + " radians");
    }


}


/*

Produces reciprocal of a number

(Requirement 3.8.0)
*/

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


/*

Produces factorial of an number

(Requirement 3.7.0)
*/
// factorial function
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

/*

Resets initalize values for calc.
(Requirement 2.5.0)
*/
void MainWindow::on_Reset_released()
{
    qDebug("Reset button clicked");
    CLS(); // clear screen CLS() function
    a= 0.0; // set a and b to 0.0
    b= 0.0;
    isModeFunction = false;
    isMedianFunction = false;
    isMeanFunction = false;

    num = "" ; // resets string for mode, median, function
    dataVector.clear(); // resets vector array

    Op = MathOp::Undefined ; // set the current operation to undefined
}


void MainWindow::on_RoundButton_released()
{
    AboutDialogPtr->exec();
}

/*

Finds mode in an array

(Requirement 3.5.1)
*/

QVector<double> findMode(const QVector<double> &numbers) {
    QMap<double, int> countMap; // creates hashmap with double as key and int as values

    //iterate each element in numbers
    for (const double &num : numbers) {
        countMap[num]++; //increment by 1 in map
    }

    QVector<double> modes;// create vector to store modes
    int maxCount = 0; // counter to keep track of max


    for (const auto &key : countMap.keys()) { // iterate the keys in hashmap
        int count = countMap[key]; // store the count of current iteration
        if (count > maxCount) { // if current count is greater than max
            maxCount = count; // set max count to current value in the iteration
        }
    }

    // collect all numbers with the max count
    for (const auto &key : countMap.keys()) { // iterate the kets in hashmap
        if (countMap[key] == maxCount) { // if the current value is equal to max count
            modes.append(key); // append mode vector
        }
    }

    return modes;
}

/*

Finds median in an array

(Requirement 3.5.3)
*/
double findMedian(const QVector<double>& values) {
    if (values.isEmpty()) { // if vector is empty
        return 0.0;
    }

    QVector<double> sortedValues = values; // create copy of the vector array
    std::sort(sortedValues.begin(), sortedValues.end());// sort in asceding order

    int size = sortedValues.size();// get size of array
    if (size % 2 == 0) { // checks if array is even
        int mid = size / 2; // find index of middle element
        return (sortedValues[mid - 1] + sortedValues[mid]) / 2.0; // return avg of two middle elements
    } else { // array is odd
        int mid = size / 2; // find index of middle element
        return sortedValues[mid]; // return middle value
    }
}

/*

Finds mean in an array

(Requirement 3.5.2)
*/
double findMean(const QVector<double>& values) {
    if (values.isEmpty()) { // if vector is empty
        return 0.0;
    }

    double sum = 0.0; // initlize sum to 0
    for (const double& value : values) { // itereate through array
        sum += value; // add each element to sum
    }

    return sum / values.size(); // return the mean sum / num of elements
}



/*

Finds mode in an array

(Requirement 3.5.1)
*/


void MainWindow::on_Mode_released(){


    isModeFunction = true; // set is mode to true

    qDebug("Runnings mode function");

    ui->LCD_2->setText( "Mode()" ); // displays Mode() on second LCD


    double number = ui->LCD->text().toDouble(); // set number equal to current value in right LCD
    dataVector.push_front(number); // push number into vector

    num = num  + convertToString(number)+ ","; // produce a string with multiple numbers for display ex, 1,2,3,4

    ui->LCD_2->setText( "Mode(" + num  +  ")" ); // displays Mode on second LCD with the curret set of numbers as a string



    //qDebug()<< dataVector;

    ui->LCD->setText( "" ); // clear screen so we can take a new number for mode


}

/*

Finds mean in an array

(Requirement 3.5.2)
*/

void MainWindow::on_Mean_released(){

    isMeanFunction = true; // set is mean to true

    qDebug("Runnings mean function");

    ui->LCD_2->setText( "Mean()" ); // displays Mode() on second LCD

    double number = ui->LCD->text().toDouble(); // grab the current number on right LCD and store it in number var

    dataVector.push_front(number); // push number into vector

    num = num  + convertToString(number)+ ","; // converts the current number to string and concatene with previous numbers ex. 9,


    ui->LCD_2->setText( "Mean(" + num  +  ")" ); // displays Mode on second LCD with the curret set of numbers as a string

    //qDebug()<< dataVector;

    ui->LCD->setText( "" ); // clear screen so we can take a new number for mode


}

/*

Finds median in an array

(Requirement 3.5.3)
*/

void MainWindow::on_Median_released(){

    isMedianFunction = true; // set is median to true

    qDebug("Runnings median function");

    ui->LCD_2->setText( "Median()" ); // displays Mode() on second LCD

    double number = ui->LCD->text().toDouble(); // grab the current number on right LCD and store it in number var

    dataVector.push_front(number); // push number into vector

    num = num  + convertToString(number)+ ","; // converts the current number to string and concatene with previous numbers ex. 9,


    ui->LCD_2->setText( "Median(" + num  +  ")" ); // displays Mode on second LCD with the curret set of numbers as a string

    //qDebug()<< dataVector;
    ui->LCD->setText( "" ); // clear screen so we can take a new number for mode




}
/*

Allows user to return result to UI
(Requirement 2.4.0)
*/
void MainWindow::on_EqualButton_released()
{

    qDebug("Equal button clicked !");

    // checks if want to find mode, mean or median function
    if(isModeFunction==true){
        QVector<double> modes = findMode(dataVector); // creates array to store mode
        ui->LCD->setText(convertToString(modes[0]));// sets ui to first element of string
        isModeFunction = false;
        num = "" ; // resets string for mode, median, function
        dataVector.clear(); // resets vector array
        return;
    }

    if(isMeanFunction==true){
        double mean = findMean(dataVector);
        ui->LCD->setText(convertToString(mean));
        isMeanFunction = false;
        num = "" ; // resets string for mode, median, function
        dataVector.clear(); // resets vector array
        return;
    }

    if(isMedianFunction==true){
        double median = findMedian(dataVector);
        ui->LCD->setText(convertToString(median));
        isMedianFunction = false;
        num = "" ; // resets string for mode, median, function
        dataVector.clear(); // resets vector array
        return;
    }

    b = ui->LCD->text().toDouble();// grabs text displayed on lcd converts to double and assign to b
    ui->LCD->setText(QString::number((MathEnginePtr->ExecuteOp(Op, a, b)))); // execute operation using a and b and display on LCD


}
