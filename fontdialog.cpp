#include "fontdialog.h"
#include <QListView>
#include <QDebug>

FontDialog::FontDialog(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(80,30);

    _pLabel = new QLabel("A", this);
    _pLabel->setFont(QFont("",20));
    _pLabel->setGeometry(3, 7, 20, 20);
    _pComboBox = new QComboBox(this);
    _pComboBox->setGeometry(28,7,50,20);
    _pComboBox->setMaxVisibleItems(6);
    _pComboBox->setStyleSheet("QComboBox{border:1px solid gray;}"
      "QComboBox QAbstractItemView::item{height:20px;}"); //下拉按钮

//    _pComboBox->setStyleSheet("QComboBox{border:1px solid gray;}"
//      "QComboBox QAbstractItemView::item{height:20px;}" //下拉选项高度
//      "QComboBox::down-arrow{image:url(:/icon/arrowdown);}" //下拉箭头
//      "QComboBox::drop-down{border:0px;}"); //下拉按钮
     _pComboBox->setView(new QListView());

    _pComboBox->addItem("8");
    _pComboBox->addItem("9");
    _pComboBox->addItem("10");
    _pComboBox->addItem("11");
    _pComboBox->addItem("12");
    _pComboBox->addItem("14");
    _pComboBox->addItem("16");
    _pComboBox->addItem("18");
    _pComboBox->addItem("20");
    _pComboBox->addItem("22");

    connect(_pComboBox, SIGNAL(activated(QString)), this, SLOT(slotGetFontSize(QString)));

}

FontDialog::~FontDialog()
{
    delete _pLabel;
    delete _pComboBox;
}

void FontDialog::slotGetFontSize(QString size)
{
    emit signalSendFontSize(size.toInt());
}
