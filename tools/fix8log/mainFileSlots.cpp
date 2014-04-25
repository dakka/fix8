#include "mainwindow.h"
#include "messagearea.h"
#include "globals.h"
#include "intItem.h"
#include "worksheet.h"
#include <QDebug>
#include <QtWidgets>
#include <iostream>
#include <string.h>
#include <fix8/f8includes.hpp>
#include <message.hpp>
#include <Myfix_types.hpp>
#include <Myfix_router.hpp>
#include <Myfix_classes.hpp>


using namespace FIX8;
void MainWindow::createTabSlot()
{
    QString str;
    if (!fileDialog) {
        QStringList filters;
        if (fileFilter == "*.logs")
            filters << "*.log" << "*";
        else
            filters <<  "*" << "*.log";
        fileDialog = new QFileDialog(this);
        fileDialog->setWindowTitle("Fix8 File Selector");
        fileDialog->setNameFilters(filters);
        fileDialog->setLabelText(QFileDialog::FileName,"Fix Log:");
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        fileDialog->setOption(QFileDialog::ReadOnly,true);
        connect(fileDialog,SIGNAL(directoryEntered(const QString &)),this,SLOT(fileDirChangedSlot(const QString &)));
        connect(fileDialog,SIGNAL(finished(int)),this,SLOT(fileSelectionFinishedSlot(int)));
        connect(fileDialog,SIGNAL(filterSelected(QString)),this,SLOT(fileFilterSelectedSlot(QString)));
        fileDialog->restoreState(fileDirState);
        fileDialog->setDirectory(lastSelectedDir);
    }
    fileDialog->show();


}
void MainWindow::fileDirChangedSlot(const QString &newDir)
{
    qDebug() << "FILE DIR CHANGED SLOT";
    QSettings settings("fix8","logviewer");
    QByteArray ba = fileDialog->saveState();
    qDebug() << "saving dir state as : " << ba;
    settings.setValue("FileDirState",ba);
    settings.setValue("LastSelectedDir",newDir);
}

void MainWindow::fileFilterSelectedSlot(QString filter)
{
    QSettings settings("fix8","logviewer");
    settings.setValue("FileFilter",filter);
}

void MainWindow::fileSelectionFinishedSlot(int returnCode)
{
    //typedef std::map<std::string, unsigned> MessageCount;
    bool bstatus;
    int index;
    QStringList fileList;
    QString fileName;
    if (returnCode != QDialog::Accepted)
        return;
    if (!fileDialog) {
        qWarning() << "Error - file dialog is null, cannot get values" << __FILE__ << __LINE__;
        return;
    }
    QByteArray prevHeaderSettings;
    bool havePreviousHeader = false;
    QSettings settings("fix8","logviewer");
    settings.setValue("FileDirState",fileDialog->saveState());
    fileList = fileDialog->selectedFiles();

    QStringListIterator iter(fileList);
    if (tabW->count() > 0) {
        WorkSheet *oldWorkSheet = qobject_cast <WorkSheet *> (tabW->widget(tabW->count() -1));
        if (oldWorkSheet) {
            prevHeaderSettings = oldWorkSheet->fixTable->horizontalHeader()->saveState();
            havePreviousHeader = true;
        }
    }

    while(iter.hasNext()) {
        fileName = iter.next();
        QFileInfo fi(fileName);
        WorkSheet *workSheet = new WorkSheet(this);
        workSheet->splitter->restoreState(messageSplitterSettings);
        if (havePreviousHeader)
            workSheet->fixTable->horizontalHeader()->restoreState(prevHeaderSettings);
        QList <GUI::Message> messageList;
        bstatus = workSheet->loadFileName(fileName,messageList);
        if (!bstatus) {
            GUI::Message msg("Loading File: " + fileName + " Failed",GUI::Message::ErrorMsg);
            messageList.append(msg);
        }
        if (messageList.count() > 0) {
            QListIterator <GUI::Message> messageIter(messageList);
            while(messageIter.hasNext()) {
                GUI::Message message = messageIter.next();
                displayConsoleMessage(message);
            }
        }
        index = tabW->addTab(workSheet,fi.fileName());
        tabW->setToolTip(fileName);
    }
    if (tabW->count() > 0) {
        stackW->setCurrentWidget(workAreaSplitter);
        copyTabA->setEnabled(true);
        showMessageA->setEnabled(true);
        if (tabW->count() > 1)
            tabW->setCurrentIndex(index);
    }
    else {
        stackW->setCurrentWidget(noDataL);
        copyTabA->setEnabled(false);
        showMessageA->setEnabled(false);
    }
}
void MainWindow::displayConsoleMessage(GUI::Message message)
{
    QString str;
    QString timeStr = QTime::currentTime().toString() +
            " - " + message.msg;
    switch (message.messageType) {
    case GUI::Message::ErrorMsg:
        str = "<FONT COLOR=\"red\">" + timeStr + "</FONT>";
        break;
    case GUI::Message::WarningMsg:
        str = "<FONT COLOR=\"gold\">" + timeStr + "</FONT>";
        break;
    default:
        str = "<FONT COLOR=\"white\">" + timeStr + "</FONT>";
    }
    consoleArea->append(str);
}
void MainWindow::tabCloseRequestSlot(int tabPosition)
{
    WorkSheet *worksheet =  qobject_cast <WorkSheet *> (tabW->widget(tabPosition));
    tabW->removeTab(tabPosition);

    if (tabW->count() > 0) {
        stackW->setCurrentWidget(workAreaSplitter);
        copyTabA->setEnabled(true);
        showMessageA->setEnabled(true);
    }
    else {
        stackW->setCurrentWidget(noDataL);
        copyTabA->setEnabled(false);
        showMessageA->setEnabled(false);

    }

    if (worksheet) {
        qDebug() << "1 Delete Work SHeet later" << __FILE__;
        delete worksheet;
        qDebug() << "2 Delete Work SHeet later" << __FILE__;

    }

}
void MainWindow::closeSlot()
{
    writeSettings();
    emit deleteWindow(this);

}
void MainWindow::copyWindowSlot()
{
    qDebug() << "Cop Window" << __FILE__;
    emit copyWindow(this);
}
void MainWindow::copyTabSlot()
{
    WorkSheet *workSheet;
    WorkSheet *newWorkSheet;
    if (tabW->count() < 1) {
        qWarning() << "No tabs to copy" << __FILE__ << __LINE__;
        return;
    }
    workSheet = qobject_cast <WorkSheet *> (tabW->currentWidget());
    if (!workSheet) {
        qWarning() << "No work sheet to copy" << __FILE__ << __LINE__;
        return;
    }
    newWorkSheet = new WorkSheet(*workSheet);
    QString fileName = workSheet->getFileName();
    QFileInfo fi(fileName);
    int index = tabW->addTab(newWorkSheet,fi.fileName());
    tabW->setToolTip(fileName);
    tabW->setCurrentIndex(index);
}
