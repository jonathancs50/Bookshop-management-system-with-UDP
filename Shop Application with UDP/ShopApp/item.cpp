
#include "item.h"

Item::Item(QString n,Type t,int q)
{
    name=n;
    type=t;
    quantity=q;
}

void Item::setName(QString n)
{
    name=n;
}

void Item::setType(Type t)
{
    type=t;
}

void Item::setQuantity(int i)
{
    quantity=i;
}

QString Item::getName()
{
    return name;
}

Item::Type Item::getType()
{
    return type;
}

int Item::getQuantity()
{
    return quantity;
}

QString Item::getQStringType()
{
    if(type==Type::B)
    {
        return "B";
    }
    else
    {
        return "M";
    }
}

