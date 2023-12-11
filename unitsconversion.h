#pragma once

enum class Units {InToFt, FtToIn, OzToGr, GrToOz, LtToGal, GalToLt, RadToDeg, DegToRad};
class UnitsConversion
{
public:

    UnitsConversion();
    UnitsConversion(const UnitsConversion&)              = delete ;
    UnitsConversion& operator = (const UnitsConversion&) = delete ;
    UnitsConversion(UnitsConversion&&)                   = delete ;
    ~UnitsConversion();

    double Convert (Units, double);



private:
    double OuncesToGrams(double);
    double GramsToOunces(double);
    double GallonsToLiters(double);
    double LitersToGallons(double);
    double DegreeToRad (double);
    double RadToDegrees(double);
    double FeetToInches(double num);
    double InchesToFeet(double num);
};


