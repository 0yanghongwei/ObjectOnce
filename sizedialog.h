#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QWidget>

class SizeDialog : public QWidget
{
    Q_OBJECT
public:
    explicit SizeDialog(QWidget *parent = nullptr);

signals:
    void signalSendSize(int);
public slots:
    void slotToolButtonClick(bool bClick);
};

#endif // SIZEDIALOG_H
