#pragma once
#include <vector>

enum class MathOp {Undefined,Add, Sub, Multi, Div, Sin, Cos, Tan, Asin,
                   Acos, Atan, Sqrt, Squared, Log, LogN, TenTo, EtoExp, CuRt,
                   Exp,Cubed, Fact, Mean, Median, Rec};

struct Task
{
    MathOp Op;
    std::vector<double> Data;
};


/*
Connects signals and slots to buttons
(Requirement 1.1.0)
*/
class MathEngine
{

public:

    MathEngine();
    MathEngine(const MathEngine&)              = delete ;
    MathEngine& operator = (const MathEngine&) = delete ;
    MathEngine(MathEngine&&)                   = delete ;
    ~MathEngine();

    double Run(Task& task);


    static constexpr double Pi = 3.14159265359;
    static constexpr double e  = 2.71828182845;
private:
    double Add(Task&);
    double Sub(Task&);
    double Multi(Task&);
    double Div(Task&);
    double Sin(Task&);
    double Cos(Task&);
    double Tan(Task&);
    double Asin(Task&);
    double Acos(Task&);
    double Atan(Task&);
    double Sqrt(Task&);
    double Squared(Task&);
    double Log(Task&);
    double LogN(Task&task);
    double CuRt(Task&);
    double Exp(Task&);
    double Cubed(Task&);
    double Fact(Task&);

    double Mean(Task&);
    double Median(Task&);
    double TenTo(Task&);
    double EtoExp(Task&);
    double Rec(Task&);
};


