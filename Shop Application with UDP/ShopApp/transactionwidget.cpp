
#include "transactionwidget.h"
#include "item.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QDateEdit>
#include <QListView>
#include <QMessageBox>
#include <QStringListModel>
#include <QSpinBox>

TransactionWidget::TransactionWidget(QWidget *parent)
    : QWidget{parent},
    comboBoxCustomers(new QComboBox),
    spinBox(new QSpinBox),
    listView(new QListView),
    comboBoxItems(new QComboBox),
    button(new QPushButton("Done")),
    btnAdd(new QPushButton("Add")),
    model(new QStringListModel),
    lblOutputType(new QLabel(""))
{
    setWindowTitle("New Transaction");
    setMinimumSize(350,300);

    //Connecting the List view to the model
    this->listView->setModel(model);


    //Setup GUI
    setupGUI();

    //Connect signals and slot
    connect(button,&QPushButton::clicked,this,&TransactionWidget::pressedBtn);
    connect(btnAdd,&QPushButton::clicked,this,&TransactionWidget::pressedAddItemBtn);
    connect(comboBoxCustomers,&QComboBox::activated,this,&TransactionWidget::startTransaction);
    connect(comboBoxItems,&QComboBox::activated,this,&TransactionWidget::findIndexForList);
    connect(spinBox,&QSpinBox::valueChanged,this,&TransactionWidget::spinBoxChanged);

}

void TransactionWidget::pressedAddItemBtn()
{
    //Add the data to the String list

    QString addedItem="";

    addedItem="Item:"+listOfItemsAvaliable[comboBoxItemIndex].getName()+"    Type:"+
                listOfItemsAvaliable[comboBoxItemIndex].getQStringType()+"     Quantity:"+
                QString::number(spinBox->value());


    // String list
    list.append(addedItem);
    model->setStringList(list);

    //Transaction List
    Item tempItem(listOfItemsAvaliable[comboBoxItemIndex].getName(),listOfItemsAvaliable[comboBoxItemIndex].getType(),spinBox->value());
    currentTransacton.addItem(tempItem);

    //Deduct the quanity from item list cause item was purchased
    int qDiff=qAbs(spinBox->value()-listOfItemsAvaliable[comboBoxItemIndex].getQuantity());
    listOfItemsAvaliable[comboBoxItemIndex].setQuantity(qDiff);

    spinBox->setValue(0);
    lblOutputType->setText("");
    comboBoxItems->setCurrentIndex(-1);
    btnAdd->setEnabled(false);

}

void TransactionWidget::pressedBtn()
{


}


void TransactionWidget::setupGUI()
{

    // Grid layout
    QGridLayout * layout(new QGridLayout());
    QLabel * lblHeader(new QLabel("Complete the required data"));
    QLabel *lblCustomer(new QLabel("Select the customer:"));
    QLabel *lblItem(new QLabel("Select the item:"));
    QLabel *lblItemType(new QLabel("Item Type"));
    QLabel *lblItemQuantity(new QLabel("Item quantity:"));


    comboBoxCustomers->setCurrentIndex(-1);
    comboBoxItems->setCurrentIndex(-1);

    //addwidget(widget, row,column, row span, column span)
    //Add the Name label and edit line
    layout->addWidget(lblHeader,0,0);

    layout->addWidget(lblCustomer,1,0);
    layout->addWidget(comboBoxCustomers,1,1);
    //Add the lable birthdate and date edit line
    layout->addWidget(lblItem,2,0);
    layout->addWidget(comboBoxItems,2,1);
    //Add the Contract type label and combo box
    layout->addWidget(lblItemType,3,0);
    layout->addWidget(lblOutputType,3,1);
    //Add the quantity
    layout->addWidget(lblItemQuantity,4,0);
    layout->addWidget(spinBox,4,1);
    //Add the addBtn
    layout->addWidget(btnAdd,5,1);
    //Add the button and listview
    layout->addWidget(listView,6,0,1,2);
    layout->addWidget(button,7,1);
    // Make column 2 size bigger to show customer/items name
    layout->setColumnStretch(1,2);


    setLayout(layout);

    //Set everthing to false except comboBox customer so the user must select a customer first
    comboBoxItems->setEnabled(false);
    spinBox->setEnabled(false);
    btnAdd->setEnabled(false);
    button->setEnabled(false);

}

void TransactionWidget::setLists(QList<Customer> c, QList<Item> item)
{
        for(int i=0;i<c.size();i++){
        comboBoxCustomers->addItem(c[i].getCustomerName());
        Customer newCustomer(c[i].getCustomerName());
        listOfCustomers.append(newCustomer);
    }
        for(int i=0;i<item.size();i++){
        comboBoxItems->addItem(item[i].getName());
        Item newItem(item[i].getName(),item[i].getType(),item[i].getQuantity());
        listOfItemsAvaliable.append(newItem);
        }
}

void TransactionWidget::startTransaction()
{

        comboBoxItems->setEnabled(true);
        comboBoxItems->setCurrentIndex(-1);
        spinBox->setValue(0);
        spinBox->setEnabled(true);
        button->setEnabled(true);

        comboBoxCustomerIndex=comboBoxCustomers->currentIndex();

        //Create the transaction date and clear list
        currentTransacton.setDate(QDateTime::currentDateTime());
        currentTransacton.wipeTransaction();
        //Clear the list if theres anything on there
        list.clear();
        model->setStringList(list);

}

void TransactionWidget::findIndexForList()
{
        comboBoxItemIndex=comboBoxItems->currentIndex();
        lblOutputType->setText(listOfItemsAvaliable[comboBoxItemIndex].getQStringType());
        spinBox->setMaximum(listOfItemsAvaliable[comboBoxItemIndex].getQuantity());
        spinBox->setMinimum(0);

}

void TransactionWidget::spinBoxChanged()
{
        if(spinBox->value()>0){

            btnAdd->setEnabled(true);
        }


}

void TransactionWidget::clearModel()
{
        list.clear();
        model->setStringList(list);
        comboBoxCustomers->setCurrentIndex(-1);

}
