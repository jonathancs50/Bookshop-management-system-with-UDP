
#include "addcustomerwidget.h"

AddCustomerWidget::AddCustomerWidget(QWidget *parent)
    : QWidget{parent},
    label1(new QLabel("Complete the required data")),
    label2(new QLabel("Customer Name")),
    lineEdit(new QLineEdit()),
    button(new QPushButton("Add New Customer"))
{
    setWindowTitle("Add New Customer");
    setupGui();
}

void AddCustomerWidget::setupGui()
{
    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(label1);
    layout->addRow(label2, lineEdit);
    layout->addWidget(button);

    this->setLayout(layout);
}

void AddCustomerWidget::pressedBtn()
{
    lineEdit->clear();
}

