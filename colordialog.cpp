#include "colordialog.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDebug>

ColorDialog::ColorDialog(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(150,30);
    _pTableWidget = new QTableWidget(2,9,this);
    _pTableWidget->setStyleSheet("background-color:#eeeeee");
    _pTableWidget->verticalHeader()->setVisible(false);//隐藏列表头
    _pTableWidget->horizontalHeader()->setVisible(false);//隐藏行表头
    _pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置为不可编辑
    _pTableWidget->setSelectionMode(QAbstractItemView::NoSelection);//单选

    //设置单元格大小
    //设置行高
    for (int i = 0; i < _pTableWidget->rowCount(); i++)
    {
        _pTableWidget->setRowHeight(i, 15);
    }
    //设置列宽
    for (int i = 0; i < _pTableWidget->columnCount(); i++)
    {
        _pTableWidget->setColumnWidth(i, 15);
    }

    _pTableWidget->setSpan(0, 0, 2, 1);//合并单元格
    _pTableWidget->setColumnWidth(0, 30);//设置大小

    //设置
    _pColorList = new ColorList;
    _pColorList->append(QColor("#000000"));
    _pColorList->append(QColor("#999999"));
    _pColorList->append(QColor("#990000"));
    _pColorList->append(QColor("#ffcc66"));
    _pColorList->append(QColor("#339900"));
    _pColorList->append(QColor("#003399"));
    _pColorList->append(QColor("#660066"));
    _pColorList->append(QColor("#009999"));
    _pColorList->append(QColor("#ffffff"));
    _pColorList->append(QColor("#cccccc"));
    _pColorList->append(QColor("#ff0000"));
    _pColorList->append(QColor("#ffff00"));
    _pColorList->append(QColor("#99cc00"));
    _pColorList->append(QColor("#3399ff"));
    _pColorList->append(QColor("#ff00cc"));
    _pColorList->append(QColor("#00ffff"));

    for (int i = 0; i < _pTableWidget->rowCount(); i++)
    {
        for (int j = 1; j < _pTableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem("");
            item->setBackgroundColor(_pColorList->at(i * 8 + j - 1));
            _pTableWidget->setItem(i,j,item);
        }
    }

    _pTableWidget->show();

    connect(_pTableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(slotSetColor(QTableWidgetItem*)));
}

ColorDialog::~ColorDialog()
{
    delete _pTableWidget;
    delete _pColorList;
}

void ColorDialog::setDefaultColor()
{
    QTableWidgetItem *item = new QTableWidgetItem("");
    item->setBackgroundColor(_pColorList->at(0));
   // _pTableWidget->setItem(i,j,item);
    emit _pTableWidget->itemClicked(item);
    delete item;
}

void ColorDialog::slotSetColor(QTableWidgetItem* item)
{
    QTableWidgetItem * _item = new QTableWidgetItem(*item);
    _pTableWidget->setItem(0,0,_item);
    emit signalSendColor(_item->backgroundColor());
}
