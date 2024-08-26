
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QList>
#include "transaction.h"

class Customer
{
public:
    Customer(QString n);
    QString getCustomerName();
    QList<Transaction> getCustomersTransactionList();
    void setName(QString n);
    void addTransaction(Transaction newTransaction);
    QString toString();
private:
    QString name;
    QList<Transaction> customersTransactions;


};

#endif // CUSTOMER_H
