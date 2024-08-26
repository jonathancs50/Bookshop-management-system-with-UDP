
#include "transaction.h"

Transaction::Transaction()
{

}

QDateTime Transaction::getTransactionDate()
{
    return tDate;
}

QList<Item> Transaction::getTransactionList()
{
    return itemList;
}

void Transaction::setDate(QDateTime date)
{
    tDate=date;
}

void Transaction::addItem(Item newItem)
{
    itemList.append(newItem);
}

void Transaction::wipeTransaction()
{
    itemList.clear();
}

QString Transaction::toString()
{
    QString str;
    str=str+tDate.toString()+"/n";
    for(int j=0;j<itemList.size();j++)
    {
        str=str+"Item "+QString::number(j+1)+" "+itemList[j].getName();
        str=str+"  "+itemList[j].getQStringType();
        str=str+"  "+QString::number(itemList[j].getQuantity());
    }
    return str;
}

