#include "mathengine.h"
#include <qdebug.h>
#include <cmath>

// Math engine constructor
MathEngine::MathEngine()
{
    qDebug("MathEngine object created");
}

MathEngine::~MathEngine()
{
    qDebug("MathEngine object destroyed");
}

/*

Math Engine to identify and store current operation
(Requirement 3.6.0)
*/

double MathEngine::ExecuteOp(MathOp op, double a, double b)
{
    switch(op)
    {
        case (MathOp::Add):
            return Add(a,b);
            break;

        case (MathOp::Sub):
            return Sub(a,b);
            break;

        case (MathOp::Multi):
            return Multi(a,b);
            break;

        case (MathOp::Div):
            return Div(a,b);
            break;

        case (MathOp::Sin):
            return Sin(b);
            break;

        case (MathOp::Cos):
            return Cos(b);
            break;

        case (MathOp::Tan):
            return Tan(b);
            break;

        case (MathOp::Asin):
            return Asin(b);
            break;

        case (MathOp::Acos):
            return Acos(b);
            break;

        case (MathOp::Atan):
            return Atan(b);
            break;

        case (MathOp::Sqrt):
            return Sqrt(b);
            break;

        case (MathOp::Squared):
            return Squared(b);
            break;

        case (MathOp::Log):
            return Log(b);
            break;

        case (MathOp::LogN):
            return LogN(b);
            break;

        case (MathOp::CuRt):
            return CuRt(b);
            break;

        case (MathOp::Exp):
            return Exp(a,b);
            break;

        case (MathOp::Cubed):
            return Cubed(b);
            break;


        default:
        throw std::runtime_error("Undefined mathmatical operation!");

    }
}

/*

Addition operation
(Requirement 2.0.1)

*/
inline double MathEngine::Add(double a, double b)
{
    return a+b;
}
/*

Subtraction operation
(Requirement 2.0.2)

*/
inline double MathEngine::Sub(double a, double b)
{
    return a-b;
}
/*

Multiplication operation
(Requirement 2.0.3)

*/
inline double MathEngine::Multi(double a, double b)
{
    return a*b;
}

/*

Division operation
(Requirement 2.0.4)

*/
inline double MathEngine::Div(double a, double b)
{
    return b ? (a/b) : NAN;
}
/*

Sin function
(Requirement 3.0.1)

*/
double MathEngine::Sin(double degree)
{
    return sin( ((degree * Pi) / 180) );
}
/*

Cos function
(Requirement 3.0.2)

*/
double MathEngine::Cos(double degree)
{
    return cos( ((degree * Pi) / 180) );
}
/*

Tan function
(Requirement 3.0.3)

*/
double MathEngine::Tan(double degree)
{
   return tan( ((degree * Pi) / 180) );
}

/*

Arcsin function
(Requirement 3.0.4)

*/
double MathEngine::Asin(double degree)
{
    return asin(degree) * 180.0/Pi;
}

/*

Arccos function
(Requirement 3.0.5)

*/
double MathEngine::Acos(double degree)
{
    return acos(degree) * 180.0/Pi;
}


/*

Arctan function
(Requirement 3.0.6)

*/
double MathEngine::Atan(double degree)
{
    return atan(degree) * 180.0/Pi;
}
/*

Square root function
(Requirement 3.3.2)

*/
double MathEngine::Sqrt(double num)
{
    return sqrt(num);
}

/*

Square of a number
(Requirement 3.3.1)

*/
double MathEngine::Squared(double num)
{
    return num*num;
}

/*

Cube of a number
(Requirement 3.1.0)

*/
double MathEngine::Cubed(double num)
{
    return num*num*num;
}
/*

Common log base10 of a number
(Requirement 3.2.1)

*/
double MathEngine::Log(double num)
{
    return log10(num);
}

/*

Natural log or ln of a number
(Requirement 3.2.2)

*/
double MathEngine::LogN(double num)
{
    return log(num) ;
}
/*

CubeRoot of a number
(Requirement 3.1.0)

*/
double MathEngine::CuRt(double num)
{
    return cbrt(num);
}
/*

Exponent of a number
(Requirement 3.3.3)

*/
double MathEngine::Exp(double a,double b)
{

    return pow(a,b)  ;
}

