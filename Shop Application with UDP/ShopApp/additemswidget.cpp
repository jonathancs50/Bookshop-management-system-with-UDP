
#include "additemswidget.h"


AddItemsWidget::AddItemsWidget(QWidget *parent)
    : QWidget{parent},
    label1(new QLabel("Complete the required data")),
    label2(new QLabel("Item type")),
    label3(new QLabel("Name of item")),
    label4(new QLabel("Quantity")),
    spinBox(new QSpinBox()),
    lineEdit(new QLineEdit()),
    comboBox(new QComboBox()),
    button(new QPushButton("Add item"))
{

    setupGui();
    setWindowTitle("Add New Item");

}

void AddItemsWidget::setupGui()
{

    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(label1);

    comboBox->addItem("Book");
    comboBox->addItem("Magazine");
    layout->addRow(label2, comboBox);
    layout->addRow(label3, lineEdit);
    layout->addRow(label4, spinBox);
    spinBox->setRange(0,1000);
    layout->addWidget(button);

    this->setLayout(layout);
}

void AddItemsWidget::pressedBtn()
{
    comboBox->setCurrentIndex(0);
    lineEdit->clear();
    spinBox->setValue(0);
}

