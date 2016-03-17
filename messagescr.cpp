#include "messagescr.h"
#include <QMessageBox>

MessageScr::MessageScr(QObject *parent ) : QObject(parent)
{

}

void MessageScr::setTextEdit(QTextEdit *t){
    this->test=t;

}

void MessageScr::showMessage(QString msg){

    QMessageBox msgBox;
    msgBox.setText("Message from script: "+msg);
    msgBox.exec();
}

void MessageScr::addText(QString msg){

this->test->append(msg);
}
