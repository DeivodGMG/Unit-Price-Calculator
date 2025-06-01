#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent) {

    // Layout vertical principal
    auto *mainLayout = new QVBoxLayout(this);

    // -------------- PRIMERA FILA -------------------
    // Layout horizontal para la primera fila
    auto *hbox1 = new QHBoxLayout();

    QStringList units = {"micrograms (ug)", "milligrams (mg)", "grams (g)", "kilograms (kg)", "metric tons (t)", "grains (gr)", "drachms (dr)", "ounces (oz)", "pounds (lb)", "stones (st)", "US short tons (US ton)", "imperial tons (long ton0)", "troy ounces (oz t)"};

     QStringList units2 = {"micrograms (ug)", "milligrams (mg)", "grams (g)", "kilograms (kg)", "metric tons (t)", "grains (gr)", "drachms (dr)", "ounces (oz)", "pounds (lb)", "stones (st)", "US short tons (US ton)", "imperial tons (long ton0)", "troy ounces (oz t)"};

      QStringList units3 = {"micrograms (ug)", "milligrams (mg)", "grams (g)", "kilograms (kg)", "metric tons (t)", "grains (gr)", "drachms (dr)", "ounces (oz)", "pounds (lb)", "stones (st)", "US short tons (US ton)", "imperial tons (long ton0)", "troy ounces (oz t)"};

    label1 = new QLabel("Weight", this);
    combo = new QComboBox(this);
    QLineEdit *le1 = new QLineEdit(this);

    combo->addItems(units);

    hbox1->addWidget(label1);
    hbox1->addWidget(le1);
    hbox1->addWidget(combo);
    hbox1->addSpacing(15);

    labelCombo1 = new QLabel("Arch", this);
    hbox1->addWidget(labelCombo1);

    // Añadir la primera fila al layout principal
    mainLayout->addLayout(hbox1);

    // -------------- SEGUNDA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox2 = new QHBoxLayout();

    QLabel *label2 = new QLabel("Cost [MXN]", this);
    QLineEdit *le2 = new QLineEdit(this);

    hbox2->addWidget(label2);
    hbox2->addWidget(le2);

    // Añadir la segunda fila al layout principal
    mainLayout->addLayout(hbox2);


    // -------------- SEGUNDA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox3 = new QHBoxLayout();

    QLabel *label3 = new QLabel("Unit Price", this);
    QComboBox *combo2 = new QComboBox(this);
    QLineEdit *le3 = new QLineEdit(this);

    combo2->addItems(units3);  

    hbox3->addWidget(label3);
    hbox3->addWidget(le3);
    hbox3->addWidget(combo2);

    // Añadir la segunda fila al layout principal
    mainLayout->addLayout(hbox3);
//OPTION B
    // -------------- TERCERA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox4 = new QHBoxLayout();

    QLabel *label4 = new QLabel("---------------------OPTION B---------------------",this);

    hbox4->addWidget(label4);

   
    mainLayout->addLayout(hbox4);

  
    // Asignar layout principal al widget
  
   // -------------- CUARTA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox5 = new QHBoxLayout();

    QLabel *label5 = new QLabel("Weight", this);
    QComboBox *combo3 = new QComboBox(this);
    QLineEdit *le4 = new QLineEdit(this);

    combo3->addItems(units3);  

    hbox5->addWidget(label5);
    hbox5->addWidget(le4);
    hbox5->addWidget(combo3);

    mainLayout->addLayout(hbox5);


    // -------------- QUINTA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox6 = new QHBoxLayout();

    QLabel *label6 = new QLabel("Cost [MXN]", this);
    QLineEdit *le5 = new QLineEdit(this);

    hbox6->addWidget(label6);
    hbox6->addWidget(le5);

    mainLayout->addLayout(hbox6);


    // -------------- SEXTA FILA -------------------
    // Nueva fila con nuevos widgets
    auto *hbox7 = new QHBoxLayout();

    QLabel *label7 = new QLabel("Unit Price", this);
    QComboBox *combo4 = new QComboBox(this);
    QLineEdit *le6 = new QLineEdit(this);

    combo4->addItems(units3); 

    hbox7->addWidget(label7);
    hbox7->addWidget(le6);
    hbox7->addWidget(combo4);

    mainLayout->addLayout(hbox7);

 setLayout(mainLayout);

}
