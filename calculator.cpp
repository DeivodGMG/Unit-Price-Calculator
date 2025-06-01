/*Aqui se encuentran los comportamiento de la clase Calculator
El mainLayout varios hbox, esos hbox contienen los widgets.
*/

#include "calculator.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{//Aca defino las opciones de los combos en tablas
    unitConversionFactors = {
        {"micrograms (ug)", 1e-6}, {"milligrams (mg)", 1e-3}, {"grams (g)", 1.0},
        {"kilograms (kg)", 1e3}, {"metric tons (t)", 1e6}, {"grains (gr)", 0.0647989},
        {"drachms (dr)", 1.77185}, {"ounces (oz)", 28.3495}, {"pounds (lb)", 453.592},
        {"stones (st)", 6350.29}, {"US short tons (US ton)", 9.07185e5}, {"imperial tons (long ton)", 1.01605e6},
        {"troy ounces (oz t)", 31.1035}
    };

    volumeConversionFactors = {
        {"milliliters (ml)", 1.0}, {"liters (l)", 1000.0}, {"cubic meters (m³)", 1e6},
        {"teaspoons (tsp)", 4.92892}, {"tablespoons (tbsp)", 14.7868}, {"fluid ounces (fl oz)", 29.5735},
        {"cups (cup)", 236.588}, {"pints (pt)", 473.176}, {"quarts (qt)", 946.353},
        {"gallons (gal)", 3785.41}
    };

    QStringList weightUnits = unitConversionFactors.keys();
    QStringList volumeUnits = volumeConversionFactors.keys();
    QStringList allModes = {"Weight", "Volume", "Items", "Items with Weight", "Items with Volume"};

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // -------- Option A --------
    QLabel *titleA = new QLabel("Option A", this);
    QFont boldFont;
    boldFont.setBold(true);
    titleA->setFont(boldFont);
    mainLayout->addWidget(titleA);

    QHBoxLayout *modeLayoutA = new QHBoxLayout();
    QLabel *modeLabelA = new QLabel("Mode:", this);
    modeSelectorA = new QComboBox(this);
    modeSelectorA->addItems(allModes);
    modeLayoutA->addWidget(modeLabelA);
    modeLayoutA->addWidget(modeSelectorA);
    mainLayout->addLayout(modeLayoutA);

    QHBoxLayout *itemCountLayoutA = new QHBoxLayout();
    itemCountLabelA = new QLabel("Number of items:", this);
    itemCountLineEditA = new QLineEdit(this);
    itemCountLayoutA->addWidget(itemCountLabelA);
    itemCountLayoutA->addWidget(itemCountLineEditA);
    mainLayout->addLayout(itemCountLayoutA);

    inputLabelA = new QLabel("Weight", this);
    le1 = new QLineEdit(this);
    le2 = new QLineEdit(this);
    le3 = new QLineEdit(this);
    combo = new QComboBox(this); combo->addItems(weightUnits);
    combo2 = new QComboBox(this); combo2->addItems(weightUnits);

    QHBoxLayout *a1 = new QHBoxLayout();
    a1->addWidget(inputLabelA); a1->addWidget(le1); a1->addWidget(combo);
    QHBoxLayout *a2 = new QHBoxLayout();
    a2->addWidget(new QLabel("Cost [MXN]:", this)); a2->addWidget(le2);
    QHBoxLayout *a3 = new QHBoxLayout();
    a3->addWidget(new QLabel("Unit Price:", this)); a3->addWidget(le3); a3->addWidget(combo2);

    mainLayout->addLayout(a1);
    mainLayout->addLayout(a2);
    mainLayout->addLayout(a3);

    // -------- Option B --------
    QLabel *titleB = new QLabel("Option B", this);
    titleB->setFont(boldFont);
    mainLayout->addWidget(titleB);

    QHBoxLayout *modeLayoutB = new QHBoxLayout();
    QLabel *modeLabelB = new QLabel("Mode:", this);
    modeSelectorB = new QComboBox(this);
    modeSelectorB->addItems(allModes);
    modeLayoutB->addWidget(modeLabelB);
    modeLayoutB->addWidget(modeSelectorB);
    mainLayout->addLayout(modeLayoutB);

    QHBoxLayout *itemCountLayoutB = new QHBoxLayout();
    itemCountLabelB = new QLabel("Number of items:", this);
    itemCountLineEditB = new QLineEdit(this);
    itemCountLayoutB->addWidget(itemCountLabelB);
    itemCountLayoutB->addWidget(itemCountLineEditB);
    mainLayout->addLayout(itemCountLayoutB);

    inputLabelB = new QLabel("Weight", this);
    le4 = new QLineEdit(this);
    le5 = new QLineEdit(this);
    le6 = new QLineEdit(this);
    combo3 = new QComboBox(this); combo3->addItems(weightUnits);
    combo4 = new QComboBox(this); combo4->addItems(weightUnits);

    QHBoxLayout *b1 = new QHBoxLayout();
    b1->addWidget(inputLabelB); b1->addWidget(le4); b1->addWidget(combo3);
    QHBoxLayout *b2 = new QHBoxLayout();
    b2->addWidget(new QLabel("Cost [MXN]:", this)); b2->addWidget(le5);
    QHBoxLayout *b3 = new QHBoxLayout();
    b3->addWidget(new QLabel("Unit Price:", this)); b3->addWidget(le6); b3->addWidget(combo4);

    mainLayout->addLayout(b1);
    mainLayout->addLayout(b2);
    mainLayout->addLayout(b3);

    // -------- Botón de limpiar --------
    QPushButton *clearButton = new QPushButton("Clear All", this);
    mainLayout->addWidget(clearButton);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::clearAllFields);

    setLayout(mainLayout);

    connect(modeSelectorA, &QComboBox::currentTextChanged, this, &Calculator::onModeChangedA);
    connect(modeSelectorB, &QComboBox::currentTextChanged, this, &Calculator::onModeChangedB);

    connect(le1, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceA);
    connect(le2, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceA);
    connect(itemCountLineEditA, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceA);
    connect(combo, &QComboBox::currentTextChanged, this, &Calculator::updateUnitPriceA);
    connect(combo2, &QComboBox::currentTextChanged, this, &Calculator::updateUnitPriceA);

    connect(le4, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceB);
    connect(le5, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceB);
    connect(itemCountLineEditB, &QLineEdit::textChanged, this, &Calculator::updateUnitPriceB);
    connect(combo3, &QComboBox::currentTextChanged, this, &Calculator::updateUnitPriceB);
    connect(combo4, &QComboBox::currentTextChanged, this, &Calculator::updateUnitPriceB);

    itemCountLabelA->setVisible(false);
    itemCountLineEditA->setVisible(false);
    itemCountLabelB->setVisible(false);
    itemCountLineEditB->setVisible(false);
}

void Calculator::onModeChangedA(const QString &mode)
{
    bool isItems = mode.contains("Items");
    bool isVolume = mode.contains("Volume");

    itemCountLabelA->setVisible(isItems);
    itemCountLineEditA->setVisible(isItems);

    QString label = isVolume ? "Volume" : "Weight";
    inputLabelA->setText(label);

    QStringList units = isVolume ? volumeConversionFactors.keys() : unitConversionFactors.keys();
    combo->clear(); combo->addItems(units);
    combo2->clear(); combo2->addItems(units);

    updateUnitPriceA();
}

void Calculator::onModeChangedB(const QString &mode)
{
    bool isItems = mode.contains("Items");
    bool isVolume = mode.contains("Volume");

    itemCountLabelB->setVisible(isItems);
    itemCountLineEditB->setVisible(isItems);

    QString label = isVolume ? "Volume" : "Weight";
    inputLabelB->setText(label);

    QStringList units = isVolume ? volumeConversionFactors.keys() : unitConversionFactors.keys();
    combo3->clear(); combo3->addItems(units);
    combo4->clear(); combo4->addItems(units);

    updateUnitPriceB();
}

void Calculator::updateUnitPriceA()
{
    QString mode = modeSelectorA->currentText();
    bool ok1, ok2;
    double cantidad = le1->text().toDouble(&ok1);
    double costo = le2->text().toDouble(&ok2);
    int items = itemCountLineEditA->text().toInt();

    if (!ok1 || !ok2 || cantidad == 0.0 || (mode.contains("Items") && items <= 0)) {
        le3->setText("Err");
        return;
    }

    QString uIn = combo->currentText(), uOut = combo2->currentText();
    double fIn = mode.contains("Volume") ? volumeConversionFactors.value(uIn, 0.0)
  : unitConversionFactors.value(uIn, 0.0);
    double fOut = mode.contains("Volume") ? volumeConversionFactors.value(uOut, 0.0)
  : unitConversionFactors.value(uOut, 0.0);

    if (fIn == 0 || fOut == 0) {
        le3->setText("Err");
        return;
    }

    if (mode == "Items") {
        le3->setText(QString::number(costo / items, 'f', 2));
        return;
    }

    double total = cantidad;
    if (mode.contains("Items with")) total *= items;

    double conv = total * fIn;
    le3->setText(QString::number(costo / (conv / fOut), 'f', 2));
}

void Calculator::updateUnitPriceB()
{
    QString mode = modeSelectorB->currentText();
    bool ok1, ok2;
    double cantidad = le4->text().toDouble(&ok1);
    double costo = le5->text().toDouble(&ok2);
    int items = itemCountLineEditB->text().toInt();

    if (!ok1 || !ok2 || cantidad == 0.0 || (mode.contains("Items") && items <= 0)) {
        le6->setText("Err");
        return;
    }

    QString uIn = combo3->currentText(), uOut = combo4->currentText();
    double fIn = mode.contains("Volume") ? volumeConversionFactors.value(uIn, 0.0)
       : unitConversionFactors.value(uIn, 0.0);
    double fOut = mode.contains("Volume") ? volumeConversionFactors.value(uOut, 0.0)
          : unitConversionFactors.value(uOut, 0.0);

    if (fIn == 0 || fOut == 0) {
        le6->setText("Err");
        return;
    }

    if (mode == "Items") {
        le6->setText(QString::number(costo / items, 'f', 2));
        return;
    }

    double total = cantidad;
    if (mode.contains("Items with")) total *= items;

    double conv = total * fIn;
    le6->setText(QString::number(costo / (conv / fOut), 'f', 2));
}


void Calculator::clearAllFields()
{
    le1->clear();
    le2->clear();
    le3->clear();
    le4->clear();
    le5->clear();
    le6->clear();
    itemCountLineEditA->clear();
    itemCountLineEditB->clear();
}
