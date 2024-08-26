
#ifndef ADDCUSTOMERWIDGET_H
#define ADDCUSTOMERWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

class AddCustomerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddCustomerWidget(QWidget *parent = nullptr);
    QPushButton * button;
    QLabel *label1;
    QLabel *label2;
    QLineEdit *lineEdit;

    void setupGui();
    void pressedBtn();
signals:

};

#endif // ADDCUSTOMERWIDGET_H
