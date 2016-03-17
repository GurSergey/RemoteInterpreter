#include "processsnapshot.h"
#include "windows.h"
#include "string.h"
#include "qdebug.h"
#include "qtimer.h"
#include <Tlhelp32.h>
#include <Winuser.h>
#include "psapi.h"


ProcessSnapshot::ProcessSnapshot(QObject *parent) : QObject(parent)
{

}

QString ProcessSnapshot::nameOfCurrentProgram()
{
HWND f=GetForegroundWindow();

TCHAR szTitle[255] = {0};
GetWindowText(f,szTitle,255);

TCHAR szTitle1[255] = {0};


DWORD pID ; // Получаем снапшот, ищем процесс, возвращаем PID
GetWindowThreadProcessId(f,&pID);
HANDLE proc= OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pID);
GetModuleBaseName(proc, 0, szTitle1, MAX_PATH);


TCHAR szTitle2[255] = {0};
GetClassName(f,szTitle2,255);


//ui->textBrowser->append("Class Name program: "+QString::fromWCharArray(szTitle2));
//ui->textBrowser->append("Title program: "+QString::fromWCharArray(szTitle));
//ui->textBrowser->append("Name exe file: "+QString::fromWCharArray(szTitle1));
//count++;
return QString::fromWCharArray(szTitle1);

}
