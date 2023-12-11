#pragma once

#include <QMainWindow>
#include "mathengine.h"
#include "unitsconversion.h"
#include "aboutdialog.h"

enum class LCDs {LCD1, LCD2, Both};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

/*
Connects signals and slots to buttons
(Requirement 1.1.0)
*/
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
// error detected by jenkins here - Randy
    //Ignore any warnings below . . . "for now ;) "
private slots:
    void on_SinButton_released();

    void on_No7_released();

    void on_No8_released();

    void on_No9_released();

    void on_No4_released();

    void on_DzeroButton_released();

    void on_ZeroButton_released();

    void on_DecButton_released();

    void on_No1_released();

    void on_No2_released();

    void on_No3_released();

    void on_No5_released();

    void on_No6_released();

    void on_CosButton_released();

    void on_TanButton_released();

    void on_SquaredButton_released();

    void on_SqRtButton_released();

    void on_ExpButton_released();

    void on_CbRtButton_released();

    void on_LogButton_released();

    void on_LognButton_released();

    void on_AddButton_released();

    void on_SubButton_released();

    void on_DivButton_released();

    void on_MultipButton_released();

    void on_EqualButton_released();

    void on_Reset_released();

    void on_RoundButton_released();

    void on_SecondButton_released();

    QString convertToString(double);

    void on_ToNegButton_released();

    void on_FeetToInches_released();

    void on_OuncesToGrams_released();

    void on_GallonsToLiters_released();

    void on_XtoNeg_released();

    void on_DegreeToRad_released();

    void on_Pi_released();

    void on_Median_released();

    void on_Mean_released();

    void on_EnterButton_released();

private:
    void CLS(LCDs);

    void DeactivateSecondFuncButton();
    void HandleTask();
    double GetNumOnScreen();
    void LoadUiButtons();

    void EnableDisableGroupButtons(std::vector<QString>,bool);
    void EnableDisableAllButtons(bool);
    void EnableDisableKeyPad(bool);

    Ui::MainWindow *ui;
    std::unique_ptr<AboutDialog>AboutDialogPtr;
    std::unique_ptr<MathEngine>MathEnginePtr;
    std::unique_ptr<UnitsConversion>UnitConversionPtr;
    std::unordered_map<QString,QPushButton*>AllMathOpButtons;

    Task task;
    bool is2ndFunButtonActive ;
};

