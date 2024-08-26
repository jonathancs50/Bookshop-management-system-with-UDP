
#include "restockwidget.h"

RestockWidget::RestockWidget(QWidget *parent)
    : QWidget{parent},

    label1(new QLabel("Complete the required data")),
    label2(new QLabel("Item type")),
    label3(new QLabel("Quantity")),
    spinBox(new QSpinBox()),
    comboBox(new QComboBox()),
    button(new QPushButton("Save"))
{
    setWindowTitle("Restock");
    setupGui();
}

void RestockWidget::setupGui()
{


    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(label1);
    layout->addRow(label2, comboBox);
    layout->addRow(label3, spinBox);
    spinBox->setRange(0,10000);
    layout->addWidget(button);

    this->setLayout(layout);

}

void RestockWidget::pressedBtn()
{
    comboBox->clear();
    spinBox->setValue(0);

}

void RestockWidget::setComboBox(QList<Item> list)
{
    for(int i=0;i<list.size();i++){
        comboBox->addItem(list[i].getName());
    }

}

