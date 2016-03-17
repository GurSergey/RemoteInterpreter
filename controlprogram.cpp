#include "controlprogram.h"
#include <QVector>

ControlProgram::ControlProgram(QObject *parent) : QObject(parent)
{

}

void ControlProgram::NameProgram(QString Name){
    this->NameExeVector.append(Name);
}
