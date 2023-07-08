#ifndef ACTIVITYREGISTER_MAINWINDOW_H
#define ACTIVITYREGISTER_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QPushButton>
#include "Register.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/*signals:
    void newActivityClicked(QDate date);*/

private slots:
    void clickedAddActivity();
    void clickedListActivity(QDate date);

    //UNIMPLEMENTED
    //void clickedAddActivity(QDate date);
    //void clickedRemoveActivity();
    //void clickedFindActivity();
    //void handleNewActivityClicked(QDate date);

private:
    Register* activityRegister;
    QCalendarWidget *calendar;
    QPushButton* addActButton;
    QPushButton* deleteActButton;

};


#endif //ACTIVITYREGISTER_MAINWINDOW_H
