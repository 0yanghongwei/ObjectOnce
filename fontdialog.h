#ifndef FONTDIALOG_H
#define FONTDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>

class FontDialog : public QWidget
{
    Q_OBJECT
public:
    explicit FontDialog(QWidget *parent = nullptr);
    ~FontDialog();

signals:
    void signalSendFontSize(int);
public slots:
    void slotGetFontSize(QString size);
private:
    QLabel *_pLabel;
    QComboBox *_pComboBox;
};

#endif // FONTDIALOG_H
