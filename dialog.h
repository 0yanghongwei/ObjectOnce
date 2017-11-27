#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "colordialog.h"
#include "fontdialog.h"
#include "sizedialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:

private:
    ColorDialog *_pColorDialog;
    FontDialog *_pFontDialog;
    SizeDialog *_pSizeDialog;
};

#endif // DIALOG_H
