
#include "customer.h"

Customer::Customer(QString n)
{
    name=n;
}

QString Customer::getCustomerName()
{
    return name;
}

QList<Transaction> Customer::getCustomersTransactionList()
{
    return customersTransactions;
}

void Customer::setName(QString n)
{
    name=n;
}

void Customer::addTransaction(Transaction newTransaction)
{
    customersTransactions.append(newTransaction);
}

QString Customer::toString()
{
    QString str;
    str="name: "+name+"\n";
    for(int i=0;i<customersTransactions.size();i++)
    {
        str=str+customersTransactions[i].getTransactionDate().toString()+"\n";
        for(int j=0;j<customersTransactions[i].getTransactionList().size();j++)
        {
            str=str+"Item "+QString::number(i)+" "+customersTransactions[i].getTransactionList()[j].getName();
            str=str+"  "+customersTransactions[i].getTransactionList()[j].getQStringType();
            str=str+"  "+QString::number(customersTransactions[i].getTransactionList()[j].getQuantity())+"\n";
        }
    }
    return str;
}

