#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
class Calculator : public QWidget {

  public:
    Calculator(QWidget *parent = nullptr);

  private:
  //Weight
  QLabel *label1;
  QLabel *labelCombo1;
  QComboBox *combo;
   //Cost
  QLabel *label2;
};
