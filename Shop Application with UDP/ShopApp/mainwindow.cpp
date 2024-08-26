
#include "mainwindow.h"
#include <QDebug>
#include <QToolBar>
#include <QHeaderView>
#include <QUdpSocket>
#include <QHostAddress>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QFile>

void MainWindow::AddRoot(Customer customer)
{
    QTreeWidgetItem * c=new QTreeWidgetItem(treeWidget);
    c->setText(0,customer.getCustomerName());
    treeWidget->addTopLevelItem(c);

    for(int i=0;i<customer.getCustomersTransactionList().size();i++)
    {
        QTreeWidgetItem * date=new QTreeWidgetItem(c);
        date->setText(0,customer.getCustomersTransactionList()[i].getTransactionDate().toString());
        for(int j=0;j<customer.getCustomersTransactionList()[i].getTransactionList().size();j++)
        {

            AddChild(date,customer.getCustomersTransactionList()[i].getTransactionList()[j]); //AddChild(parent, item)

        }

    }

}

void MainWindow::AddChild(QTreeWidgetItem * parent,Item item)
{
    QTreeWidgetItem * itm=new QTreeWidgetItem();
    itm->setText(0,item.getName());
    itm->setText(1,item.getQStringType());
    itm->setText(2,QString::number(item.getQuantity()));
    parent->addChild(itm);


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupGUI();
    setWindowTitle("Shop");
    setMinimumSize(500,300);


    //Data to input
    Item item1("Holes",Item::B,15);
    Item item2("The Great Gatsby",Item::B,15);
    Item item3("Time",Item::M,15);
    Item item4("To Kill a Mockingbird",Item::B,15);
    Item item5("The Catcher in the Rye",Item::B,15);
    Item item6("Nation Geographic",Item::M,15);
    Item item7("Vogue",Item::M,15);
    Item item8("The Hobbit",Item::B,15);
    Item item9("Forbes",Item::M,0);
    Item item10("1984",Item::B,15);

    itemStockList<<item1<<item2<<item3<<item4<<item5<<item6<<item7<<item8<<item9<<item10;

    Customer c1("Jonathan");
    Transaction t1;
    Item itemC("Holes",Item::B,1);
    Item itemC2("The Great Gatsby",Item::B,1);
    Item itemC3("Time",Item::M,2);
    Item itemC4("To Kill a Mockingbird",Item::B,1);
    t1.setDate(QDateTime::currentDateTime());
    t1.addItem(itemC);
    t1.addItem(itemC2);
    t1.addItem(itemC3);
    t1.addItem(itemC4);
    c1.addTransaction(t1);


    Customer c2("Tom");
    Customer c3("Nelson");
    customerTransactionRecord<<c1<<c2<<c3;

    backupcustomerTransactionRecord=customerTransactionRecord;
    backupitemStockList=itemStockList;
    refreshTreeView();

}

MainWindow::~MainWindow()
{
}


void MainWindow::setupGUI()
{

    // Create a QTreeWidget instance
    treeWidget = new QTreeWidget(this);

    // Set column count and header labels
    treeWidget->setColumnCount(3);
    QStringList headerLabels;
    headerLabels << "Transaction"<<"Type"<<"Quantity";
    treeWidget->setHeaderLabels(headerLabels);
    treeWidget->setColumnWidth(0,200);



    // Add the tree widget to the main window
    setCentralWidget(treeWidget);



    QToolBar *toolBar = new QToolBar(this);
    addToolBar(toolBar);

    QAction *udpAction = toolBar->addAction(tr("Send data with UDP"));
    connect(udpAction, &QAction::triggered, this, &MainWindow::sendDataOverUDP);
    QAction *restoreAction = toolBar->addAction(tr("Restore records"));
    connect(restoreAction, &QAction::triggered, this, &MainWindow::restoreRecords);


    //Create the menu bar
    menuBar = new QMenuBar(this);

    //Create the menus and popup menues
    add = new QMenu("Add");


    writeFile = new QAction("Write to File", this);
    addItem = new QAction("Add new item", this);
    addCustomer = new QAction("Add new customer", this);
    restockItem=new QAction("Restock an item",this);
    addTransaction=new QAction("New Transaction");


    add->addAction(addItem);
    add->addAction(addCustomer);
    add->addAction(restockItem);
    add->addAction(addTransaction);

    connect(addItem, &QAction::triggered, this, &MainWindow::addItemsWidget);
    connect(addCustomer, &QAction::triggered, this, &MainWindow::addCustomerWidget);
    connect(restockItem, &QAction::triggered, this, &MainWindow::restockWidget);
    connect(addTransaction, &QAction::triggered, this, &MainWindow::transactionWidget);



    menuBar->addMenu(add);

    setMenuBar(menuBar);

    //Connect the functions to the Widget buttons
    connect(addItemsW.button, &QPushButton::clicked, this, &MainWindow::addNewItem);
    connect(addCustomerW.button, &QPushButton::clicked, this, &MainWindow::addNewCustomer);
    connect(restockW.button, &QPushButton::clicked, this, &MainWindow::restockItems);
    connect(transactionW.btnAdd, &QPushButton::clicked, this, &MainWindow::newTransaction);
    connect(transactionW.button, &QPushButton::clicked, this, &MainWindow::completeTransaction);


}

void MainWindow::addNewItem()
{

    if(addItemsW.lineEdit->text()!="" && addItemsW.spinBox->value()>0)
    {
        Item::Type t;
        if(addItemsW.comboBox->currentIndex()==0){
            t= Item::B;
        }
        else{
            t=Item::M;
        }
        Item newItem(addItemsW.lineEdit->text(),t,addItemsW.spinBox->value());
        itemStockList.append(newItem);

        addItemsW.pressedBtn();
        addItemsW.close();
    }
}

void MainWindow::addNewCustomer()
{
    Customer newC(addCustomerW.lineEdit->text());
    customerTransactionRecord.append(newC);
    refreshTreeView();
    addCustomerW.pressedBtn();
    addCustomerW.close();

}

void MainWindow::restockItems()
{
    restockW.pressedBtn();
    restockW.close();
}

void MainWindow::newTransaction()
{

    //    transactionW.pressedAddItemBtn();
}

void MainWindow::completeTransaction()
{
    //When I transaction is complete the following has to happen:
    //1. Get the index of the customer that made the transaction
    int index=transactionW.comboBoxCustomerIndex;
    //2. Take the transaction and add it to the CustomersPurchaseList
    customerTransactionRecord[index].addTransaction(transactionW.currentTransacton);
    qInfo()<<transactionW.currentTransacton.toString();
    //3. Update the items quanities
    itemStockList=transactionW.listOfItemsAvaliable;
    refreshTreeView();
    transactionW.currentTransacton.wipeTransaction();
    transactionW.clearModel();
    transactionW.comboBoxCustomers->clear();
    //4. Close widget
    transactionW.close();


}

void MainWindow::refreshTreeView()
{

    treeWidget->clear();
    for(int i=0;i<customerTransactionRecord.size();i++)
    {
        AddRoot(customerTransactionRecord[i]);
    }

    treeWidget->expandAll();

}

void MainWindow::restoreRecords()
{
    customerTransactionRecord=backupcustomerTransactionRecord;
    itemStockList=backupitemStockList;
    refreshTreeView();
}

void MainWindow::addItemsWidget()
{
    addItemsW.show();
}

void MainWindow::addCustomerWidget()
{
    addCustomerW.show();
}

void MainWindow::restockWidget()
{
    restockW.setComboBox(itemStockList);
    restockW.show();
}

void MainWindow::transactionWidget()
{
    transactionW.setLists(customerTransactionRecord,itemStockList);
    transactionW.show();

}

void MainWindow::sendDataOverUDP()
{

    QFile file("customerTransactionRecord.xml");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartDocument();
        for(int i=0;i<customerTransactionRecord.size();i++)//loop over the customrs
        {
            //Get customer name
            xmlWriter.writeStartElement("customer");
            xmlWriter.writeAttribute("name", customerTransactionRecord[i].getCustomerName());

            for(int j=0;j<customerTransactionRecord[i].getCustomersTransactionList().size();j++)//loop over the transaction list
            {
                //Get the transaction date
                xmlWriter.writeStartElement("transaction");
                xmlWriter.writeAttribute("date", customerTransactionRecord[i].getCustomersTransactionList()[j].getTransactionDate().toString());

                for(int k=0;k<customerTransactionRecord[i].getCustomersTransactionList()[j].getTransactionList().size();k++)
                {
                    //Get the list of items in the transaction
                    xmlWriter.writeStartElement("lineitem");
                    xmlWriter.writeAttribute("name", customerTransactionRecord[i].getCustomersTransactionList()[j].getTransactionList()[k].getName());
                    xmlWriter.writeAttribute("type", customerTransactionRecord[i].getCustomersTransactionList()[j].getTransactionList()[k].getQStringType());
                    xmlWriter.writeAttribute("quantity", QString::number(customerTransactionRecord[i].getCustomersTransactionList()[j].getTransactionList()[k].getQuantity()));

                    xmlWriter.writeEndElement(); // Close the 'lineitem' element
                }

                 xmlWriter.writeEndElement(); // Close the 'transaction' element
            }
            xmlWriter.writeEndElement(); // Close the 'customer' element
        }


        xmlWriter.writeEndDocument();

        file.close();
    }

    QString xmlData="";

    //Convert the XML file to a QString
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
         xmlData = stream.readAll();

        file.close();

    }

    //convert XML string to a QByteArray for sending
    QByteArray datagram = xmlData.toUtf8();

    //create UDP socket
    QUdpSocket udpSocket;

    //send the QByteArray over UDP
    udpSocket.writeDatagram(datagram, QHostAddress::Broadcast, 12345);

    QMessageBox::information(this, tr("Data Sent"), tr("Data has been sent via UDP."));
}
