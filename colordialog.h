#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QWidget>
#include <QTableWidget>
#include <QColor>
#include <QList>

typedef QList<QColor>  ColorList;
class ColorDialog : public QWidget
{
    Q_OBJECT
public:
    explicit ColorDialog(QWidget *parent = nullptr);
    ~ColorDialog();

    void setDefaultColor();

signals:
    void signalSendColor(QColor color);
public slots:

    void slotSetColor(QTableWidgetItem*item);
private:
    QTableWidget *_pTableWidget;
    ColorList * _pColorList;
};

#endif // COLORDIALOG_H
