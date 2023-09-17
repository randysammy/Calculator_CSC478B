#pragma once


class MathEngine
{


public:

    MathEngine();
    MathEngine(const MathEngine&)              = delete ;
    MathEngine& operator = (const MathEngine&) = delete ;
    MathEngine(MathEngine&&)                   = delete ;
    ~MathEngine();

    double Add(double, double);
    double Sub(double, double);
    double Multi(double, double);
    double Div(double,double);
    double Sin(double);
    double Cos(double);
    double Tan(double);
    double Asin(double);
    double Acos(double);
    double Atan(double);
    double Sqrt(double);
    double Squared(double);
    double Log(double);
    double LogN(double);
    double CuRt(double);
    double Exp(double);

private:
    static constexpr double Pi = 3.14;

};


