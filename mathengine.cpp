#include "mathengine.h"
#include <qdebug.h>
MathEngine::MathEngine()
{
    qDebug("MathEngine object created");
}

MathEngine::~MathEngine()
{
    qDebug("MathEngine object destroyed");
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
    if (b == 0)
    {
        return NAN;
    }
    else
    {
        return a/b;
    }
}

double MathEngine::Sin(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Cos(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Tan(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Asin(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Acos(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Atan(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Sqrt(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Squared(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Log(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::LogN(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::CuRt(double)
{
    // WIP
    return 0.0 ;
}

double MathEngine::Exp(double)
{
    // WIP
    return 0.0 ;
}

