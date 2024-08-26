
#ifndef ADDITEMSWIDGET_H
#define ADDITEMSWIDGET_H


#include <QWidget>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

class AddItemsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddItemsWidget(QWidget *parent = nullptr);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *button;
    QSpinBox * spinBox;

    void setupGui();
    void pressedBtn();
signals:

};

#endif // ADDITEMSWIDGET_H
