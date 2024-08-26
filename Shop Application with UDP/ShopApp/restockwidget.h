
#ifndef RESTOCKWIDGET_H
#define RESTOCKWIDGET_H


#include <QWidget>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include "item.h"


class RestockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RestockWidget(QWidget *parent = nullptr);

    void setComboBox(QList<Item> list);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *button;
    QSpinBox * spinBox;

    void setupGui();
    void pressedBtn();
signals:

};

#endif // RESTOCKWIDGET_H
