#pragma once

enum class MathOp {Undefined,Add, Sub, Multi, Div, Sin, Cos, Tan, Asin,
                   Acos, Atan, Sqrt, Squared, Log, LogN, CuRt,
                   Exp,Cubed};

class MathEngine
{


public:

    MathEngine();
    MathEngine(const MathEngine&)              = delete ;
    MathEngine& operator = (const MathEngine&) = delete ;
    MathEngine(MathEngine&&)                   = delete ;
    ~MathEngine();

    double ExecuteOp(MathOp op, double a, double b);

private:
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
    double Exp(double,double);
    double Cubed(double);


    static constexpr double Pi = 3.14159;

};


