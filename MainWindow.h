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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void clickedAddActivity();
    void clickedListActivity(QDate date);

private:
    Register* activityRegister;
    QCalendarWidget *calendar;

};

#endif //ACTIVITYREGISTER_MAINWINDOW_H
