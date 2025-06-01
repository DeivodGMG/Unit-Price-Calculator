#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QMap>

class QLineEdit;
class QLabel;
class QComboBox;
class QPushButton;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onModeChangedA(const QString &mode);
    void onModeChangedB(const QString &mode);
    void updateUnitPriceA();
    void updateUnitPriceB();
    void clearAllFields();  

private:
    QMap<QString, double> unitConversionFactors;
    QMap<QString, double> volumeConversionFactors;

    QComboBox *modeSelectorA;
    QComboBox *modeSelectorB;

    QLabel *itemCountLabelA;
    QLabel *itemCountLabelB;
    QLineEdit *itemCountLineEditA;
    QLineEdit *itemCountLineEditB;

    QLabel *inputLabelA;
    QLabel *inputLabelB;

    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *le3;
    QComboBox *combo;
    QComboBox *combo2;

    QLineEdit *le4;
    QLineEdit *le5;
    QLineEdit *le6;
    QComboBox *combo3;
    QComboBox *combo4;

    QPushButton *clearButton;  
};

#endif // CALCULATOR_H
