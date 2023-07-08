#ifndef ACTIVITYREGISTER_LISTACTIVITYWINDOW_H
#define ACTIVITYREGISTER_LISTACTIVITYWINDOW_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtCore/QDate>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtCore/QSignalMapper>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QTextEdit>
#include "Register.h"
#include <iostream>

class ListActivityWindow : public QDialog {

Q_OBJECT

public:
    ListActivityWindow(QWidget *parent = nullptr, QDate date = QDate::currentDate(), Register *r = nullptr);
    ~ListActivityWindow();

signals:
    void newActivityClicked(QDate date);

private slots:
    void createEmptyLabel();
    //void handleNewActivityClicked();

private:
    QLabel *labelListActivity;
    QLabel *labelDate;
    QScrollArea *scrollAreaListActivity;
    QWidget *qWidget;

    //QDate selectedDate;

};



#endif //ACTIVITYREGISTER_LISTACTIVITYWINDOW_H
