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

// A method of math engine that executes the operation using switch statement
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


inline double MathEngine::Add(double a, double b)
{
    return a+b;
}

inline double MathEngine::Sub(double a, double b)
{
    return a-b;
}

inline double MathEngine::Multi(double a, double b)
{
    return a*b;
}

inline double MathEngine::Div(double a, double b)
{
    return b ? (a/b) : NAN;
}

double MathEngine::Sin(double degree)
{
    return sin( ((degree * Pi) / 180) );
}

double MathEngine::Cos(double degree)
{
    return cos( ((degree * Pi) / 180) );
}

double MathEngine::Tan(double degree)
{
   return tan( ((degree * Pi) / 180) );
}

double MathEngine::Asin(double degree)
{
    return asin( ((degree * Pi) / 180) );
}

double MathEngine::Acos(double degree)
{
    return acos( ((degree * Pi) / 180) );
}

double MathEngine::Atan(double degree)
{
    return atan( ((degree * Pi) / 180) );
}

double MathEngine::Sqrt(double num)
{
    return sqrt(num);
}

double MathEngine::Squared(double num)
{
    return num*num;
}

double MathEngine::Cubed(double num)
{
    return num*num*num;
}

// this is the common log base 10
double MathEngine::Log(double num)
{
    return log10(num);
}
// Natural log or ln or log base e
double MathEngine::LogN(double num)
{
    return log(num) ;
}

double MathEngine::CuRt(double num)
{
    return cbrt(num);
}

double MathEngine::Exp(double a,double b)
{

    return pow(a,b)  ;
}

