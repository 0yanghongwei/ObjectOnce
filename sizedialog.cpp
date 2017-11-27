#include "sizedialog.h"
#include <QToolButton>

SizeDialog::SizeDialog(QWidget *parent) : QWidget(parent)
{
    QToolButton *_pToolButton_One = new QToolButton(this);
    _pToolButton_One->setText("One");
    _pToolButton_One->setGeometry(0, 0, 30, 30);
    QToolButton *_pToolButton_Two = new QToolButton(this);
    _pToolButton_Two->setText("Two");
    _pToolButton_Two->setGeometry(30, 0, 30, 30);
    QToolButton *_pToolButton_Three = new QToolButton(this);
    _pToolButton_Three->setText("Three");
    _pToolButton_Three->setGeometry(60, 0, 30, 30);
}
