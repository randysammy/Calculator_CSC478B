#include "mathengine.h"
#include <cmath>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <iostream>

MathEngine::MathEngine()
{
}

MathEngine::~MathEngine()
{
}

/*

Math Engine to identify and store current operation
(Requirement 3.6.0)
*/

double MathEngine::Run(Task& task)
{
    switch(task.Op)
    {
    case (MathOp::Add):
        return Add(task);
        break;

    case (MathOp::Sub):
        return Sub(task);
        break;

    case (MathOp::Multi):
        return Multi(task);
        break;

    case (MathOp::Div):
        return Div(task);
        break;

    case (MathOp::Sin):
        return Sin(task);
        break;

    case (MathOp::Cos):
        return Cos(task);
        break;

    case (MathOp::Tan):
        return Tan(task);
        break;

    case (MathOp::Asin):
        return Asin(task);
        break;

    case (MathOp::Acos):
        return Acos(task);
        break;

    case (MathOp::Atan):
        return Atan(task);
        break;

    case (MathOp::Sqrt):
        return Sqrt(task);
        break;

    case (MathOp::Squared):
        return Squared(task);
        break;

    case (MathOp::Log):
        return Log(task);
        break;

    case (MathOp::LogN):
        return LogN(task);
        break;

    case (MathOp::CuRt):
        return CuRt(task);
        break;

    case (MathOp::Exp):
        return Exp(task);
        break;

    case (MathOp::Cubed):
        return Cubed(task);
        break;

    case (MathOp::Fact):
        return Fact(task);
        break;

    case (MathOp::Mean):
        return Mean(task);
        break;

    case (MathOp::Median):
        return Median(task);
        break;

    case (MathOp::TenTo):
        return TenTo(task);
        break;

    case (MathOp::EtoExp):
        return EtoExp(task);
        break;
    case (MathOp::Rec):
        return Rec(task);
        break;

    default:
        throw std::runtime_error("Undefined mathmatical operation!");

    }
}


/*

Addition operation
(Requirement 2.0.1)

*/
inline double MathEngine::Add(Task& task)
{
    return std::accumulate(task.Data.begin(),task.Data.end(),.0);
}
/*

Subtraction operation
(Requirement 2.0.2)

*/
inline double MathEngine::Sub(Task& task)
{
    return std::accumulate( std::next(std::begin(task.Data)), task.Data.end(), *task.Data.begin(),
                    std::minus<double>());
}
/*

Multiplication operation
(Requirement 2.0.3)

*/
inline double MathEngine::Multi(Task& task)
{
    return std::accumulate(task.Data.begin(), task.Data.end(),1.0,
                           std::multiplies<double>());
}

/*

Division operation
(Requirement 2.0.4)

*/
inline double MathEngine::Div(Task& task)
{
    return std::accumulate( std::next(std::begin(task.Data)), task.Data.end(), *task.Data.begin(),
                           std::divides<double>());
}
/*

Sin function
(Requirement 3.0.1)

*/
double MathEngine::Sin(Task& task)
{
    auto num = task.Data.at(0);
    return sin( ((num * Pi) / 180) );
}
/*

Cos function
(Requirement 3.0.2)

*/
double MathEngine::Cos(Task& task)
{
    auto num = task.Data.at(0);
    return cos( ((num * Pi) / 180) );
}
/*

Tan function
(Requirement 3.0.3)

*/
double MathEngine::Tan(Task& task)
{
    auto num = task.Data.at(0);
    return round(tan( ((num * Pi) / 180) ));
}

/*

Arcsin function
(Requirement 3.0.4)

*/
double MathEngine::Asin(Task& task)
{
    auto num = task.Data.at(0);
    return asin( ((num * Pi) / 180));
}

/*

Arccos function
(Requirement 3.0.5)

*/
double MathEngine::Acos(Task& task)
{
    auto num = task.Data.at(0);
    return acos(((num * Pi) / 180));
}


/*

Arctan function
(Requirement 3.0.6)

*/
double MathEngine::Atan(Task& task)
{
    auto num = task.Data.at(0);
    return atan(((num * Pi) / 180));
}
/*

Square root function
(Requirement 3.3.2)

*/
double MathEngine::Sqrt(Task& task)
{
    auto num = task.Data.at(0);
    return sqrt(num);
}

/*

Square of a number
(Requirement 3.3.1)

*/
double MathEngine::Squared(Task& task)
{
    auto num = task.Data.at(0);
    return num * num;
}

/*

Cube of a number
(Requirement 3.1.0)

*/
double MathEngine::Cubed(Task& task)
{
    auto num = task.Data.at(0);
    return num * num * num;
}

/*
(Requirement 3.7.0)
factorial function
*/
 double MathEngine::Fact(Task& task)
{

    double factorial = 1.0;
    for(int i = 1; i <= task.Data.at(0); ++i)
    {
        factorial *= i;
    }
    return factorial;
}

/*

Common log base10 of a number
(Requirement 3.2.1)

*/
double MathEngine::Log(Task& task)
{
    auto num = task.Data.at(0);
    return log10(num);
}

/*

Natural log or ln of a number
(Requirement 3.2.2)

*/
double MathEngine::LogN(Task& task)
{
    auto num = task.Data.at(0);
    return log(num) ;
}
/*

CubeRoot of a number
(Requirement 3.1.0)

*/
double MathEngine::CuRt(Task& task)
{
    auto num = task.Data.at(0);
    return cbrt(num);
}
/*

Exponent of a number
(Requirement 3.3.3)

*/
double MathEngine::Exp(Task& task)
{
    auto num = task.Data.at(0);
    auto exp = task.Data.at(1);
    return pow(num,exp)  ;
}

/*
Finds mean in an array
(Requirement 3.5.2)
*/
double MathEngine::Mean(Task& task)
{
    return std::accumulate(task.Data.begin(),task.Data.end(),0.0)  /  static_cast<double>(task.Data.size());
}

/*∞

Finds median in an array

(Requirement 3.5.3)
*/
double MathEngine::Median(Task& task)
{
    std::vector<double> sortedValues = task.Data; // create copy of the vector array
    std::sort(sortedValues.begin(), sortedValues.end());// sort in asceding order

    int size = sortedValues.size();// get size of array
    if (size % 2 == 0)
    { // checks if array is even
        int mid = size / 2; // find index of middle element
        return (sortedValues[mid - 1] + sortedValues[mid]) / 2.0; // return avg of two middle elements
    }
    else
    { // array is odd
        int mid = size / 2; // find index of middle element
        return sortedValues[mid]; // return middle value
    }
}

double MathEngine::TenTo(Task& task)
{
    auto exp = task.Data.at(1);
    return pow(10,exp);
}

double MathEngine::EtoExp(Task& task)
{
    auto exp = task.Data.at(1);
    return pow(e,exp);
}

double MathEngine::Rec(Task& task)
{
    auto num = task.Data.at(1);
    return 1/num ; //should check for 0 here
}
