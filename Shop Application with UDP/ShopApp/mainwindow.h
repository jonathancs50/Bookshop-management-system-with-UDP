
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//Main Application
#include <QTreeView>
#include <QMenuBar>
#include <QMenu>
#include <QTreeWidget>
//Widgets
#include "additemswidget.h"
#include "addcustomerwidget.h"
#include "restockwidget.h"
#include "transactionwidget.h"

//Classes
#include "customer.h"
#include "item.h"
#include "transaction.h"

class MainWindow : public QMainWindow

{
    Q_OBJECT

    //Tree View
    void AddRoot(Customer customer);
    void AddChild(QTreeWidgetItem * parent,Item item);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addItemsWidget();
    void addCustomerWidget();
    void restockWidget();
    void transactionWidget();
private:

    void setupGUI();
    QMenuBar *menuBar;
    QMenu * file;
    QMenu * add;
    QMenu *restore;
    QAction * writeFile;
    QAction * addItem;
    QAction * addCustomer;
    QAction * addTransaction;
    QAction * restockItem;
    QAction * restoreFile;

    QTreeWidget *treeWidget;

    void addNewItem();
    void addNewCustomer();
    void restockItems();
    void newTransaction();
    void completeTransaction();
    void refreshTreeView();
    void restoreRecords();
    void sendDataOverUDP();

    //WIDGETS
    //Todo addItemsWidget, addCustomersWidget, restockItemsWidget, addTransactionWidget
    AddItemsWidget addItemsW;
    AddCustomerWidget addCustomerW;
    RestockWidget restockW;
    TransactionWidget transactionW;

    //LISTS
    QList<Customer> customerTransactionRecord;
    QList<Item> itemStockList;
    QList<Customer> backupcustomerTransactionRecord;
    QList<Item> backupitemStockList;
};

#endif // MAINWINDOW_H
