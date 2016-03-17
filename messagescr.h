#ifndef MESSAGESCR_H
#define MESSAGESCR_H

#include <QObject>
#include <QTextEdit>

class MessageScr : public QObject///класс осуществляет вывод сообщение из скрипта
{
    Q_OBJECT
public:
    explicit MessageScr(QObject *parent = 0);
    void setTextEdit(QTextEdit *t);
private:
    QTextEdit *test;

signals:

public slots:
    void showMessage(QString msg);
    void addText(QString msg);
};

#endif // MESSAGESCR_H
