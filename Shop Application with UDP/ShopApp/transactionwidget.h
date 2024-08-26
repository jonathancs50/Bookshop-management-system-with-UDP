
#ifndef TRANSACTIONWIDGET_H
#define TRANSACTIONWIDGET_H

#include "customer.h"       //Customer-Name, QList<Transaction>
#include "item.h"
#include "transaction.h"    //Transaction- QDate, QList<Items>

#include <QWidget>
class QDateTimeEdit;
class QListView;
class QTextEdit;
class QPushButton;
class QComboBox;
class QStringListModel;
class QLabel;
class QSpinBox;

class TransactionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TransactionWidget(QWidget *parent = nullptr);
    void pressedAddItemBtn();
    void pressedBtn();
    void setupGUI();
    void setLists(QList<Customer> c,QList<Item> item);
    void startTransaction();
    void findIndexForList();
    void spinBoxChanged();
    void clearModel();


    QComboBox * comboBoxCustomers;
    QComboBox * comboBoxItems;
    QSpinBox * spinBox;
    QListView * listView;
    QPushButton * button;
    QPushButton *btnAdd;
    QLabel * lblOutputType;

    QStringListModel *model;
    QStringList list;
    int comboBoxItemIndex;
    int comboBoxCustomerIndex;

    //Customer List
    QList<Customer> listOfCustomers;
    QList<Item> listOfItemsAvaliable;
    //Transaction
    Transaction currentTransacton;

signals:

};

#endif // TRANSACTIONWIDGET_H

//Process of the Widget
//1. Load in the avaliable customers
//2. Load in the avaliable items
//3. User selects a customer so we lock in that customer for the whole transaction, create a new transaction(add the date and intialize empty item list), clear the QStringLIst list variable;
//4. User Selects item so we display the type of item
//5. User presses add, we add item to transaction list, clear the inputs (except customer), update the item list
//6. User clicks done this means transaction was completed and we update the systems memory to have the completed transaction
