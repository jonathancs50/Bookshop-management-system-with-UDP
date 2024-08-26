
#ifndef ITEM_H
#define ITEM_H

#include <QString>



class Item
{
public:
    enum Type { M, B };
    Item(QString n,Type t,int q);
    void setName(QString n);
    void setType(Type t);
    void setQuantity(int i);
    QString getName();
    Type getType();
    int getQuantity();
    QString getQStringType();
private:
    QString name;
    Type type;
    int quantity;
};

#endif // ITEM_H
