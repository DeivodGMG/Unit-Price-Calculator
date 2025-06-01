#include <QVBoxLayout>
#include <QFont>
#include "calculator.h"
#include <QHBoxLayout>
#include <QLineEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent) {
auto *hbox = new  QHBoxLayout(this);
auto *hvox = new  QVBoxLayout(this);
//Las opciones del Combobox
QStringList units = {"micrograms", "miligrams", "grams (g)", "kilograms (kg)", "metric tons (t)", "grains (gr)", "drachms (dr)", "ounces (oz)", "pounds (lb)", "stones (st)", "US short tons (US ton)", "imperial tons (long ton0)", "troy ounces (oz t)"};
//-----------------------------------
// SECCION DE WEIGHT
label1 = new QLabel("Weight", this);
combo = new QComboBox();
QLineEdit *le1 = new QLineEdit(this);


combo->addItems(units);
hvox->addWidget(label1);
hbox->addWidget(le1);
hbox->addWidget(combo);
hbox->addSpacing(15);

  labelCombo1 = new QLabel("Arch", this);
  hbox->addWidget(labelCombo1);

//


   //connect(combo, qOverload<const QString &>(&QComboBox::activated),
   //  label, &QLabel::setText);
 
}
