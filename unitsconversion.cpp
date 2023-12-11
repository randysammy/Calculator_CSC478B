#include "unitsconversion.h"
#include <stdexcept>

UnitsConversion::UnitsConversion()
{
}

UnitsConversion::~UnitsConversion()
{
}


double UnitsConversion::Convert(Units unit, double value)
{
    switch(unit)
    {
    case (Units::InToFt):
        return InchesToFeet(value);
        break;

    case (Units::FtToIn):
        return FeetToInches(value);
        break;

    case (Units::OzToGr):
        return OuncesToGrams(value);
        break;

    case (Units::GrToOz):
        return GramsToOunces(value);
        break;

    case (Units::LtToGal):
        return LitersToGallons(value);
        break;

    case (Units::GalToLt):
        return GallonsToLiters(value);
        break;

    case (Units::RadToDeg):
        return RadToDegrees(value);
        break;

    case (Units::DegToRad):
        return DegreeToRad(value);
        break;


    default:
        throw std::runtime_error("Undefined unit conversion operation!");

    }
}

double UnitsConversion::FeetToInches(double num)
{
    return num * 12 ;
}

double UnitsConversion::InchesToFeet(double num)
{
    return num / 12 ;
}

double UnitsConversion::OuncesToGrams(double num)
{
    return (num / 0.035275) ;
}

double UnitsConversion::GramsToOunces(double num)
{
    return (num * 0.035275) ;
}

double UnitsConversion::GallonsToLiters(double num)
{
    return (num / 0.264172);
}

double UnitsConversion::LitersToGallons(double num)
{
    return (num * 0.264172);
}

double UnitsConversion::DegreeToRad(double num)
{
    return (num * (3.14159265359/180));
}

double UnitsConversion::RadToDegrees(double num)
{
    return (num * (180/3.14159265359));
}
