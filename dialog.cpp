#include "dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{

//    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
//    this->setFixedSize(150,30);
//    this->setWindowFlags( Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
//    _pColorDialog = new ColorDialog(this);
//    _pColorDialog->setDefaultColor();
//    _pColorDialog->show();

    //_pFontDialog = new FontDialog(this);

    _pSizeDialog = new SizeDialog(this);
}

Dialog::~Dialog()
{
    if (!_pColorDialog)
    {
        delete _pColorDialog;
        _pColorDialog = NULL;
    }

    if (!_pFontDialog)
    {
        delete _pFontDialog;
        _pFontDialog = NULL;
    }

    if (!_pSizeDialog)
    {
        delete _pSizeDialog;
        _pSizeDialog = NULL;
    }
}

