
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "item.h"
#include <QList>
#include <QDate>


class Transaction
{
public:
    Transaction();
    QDateTime getTransactionDate();
    QList<Item> getTransactionList();
    void setDate(QDateTime date);
    void addItem(Item newItem);
    void wipeTransaction();
    QString toString();



private:
    QDateTime tDate;
    QList<Item> itemList; //List of all items purchased in the transaction
};

#endif // TRANSACTION_H
