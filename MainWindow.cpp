#include "MainWindow.h"
#include "NewActivityWindow.h"
#include "ListActivityWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
        this->setFixedSize(600,600);
        activityRegister = new Register;

        calendar = new QCalendarWidget(this);
        calendar->resize(500,500);
        calendar->move(50,30);
        calendar->setGridVisible(true);
        calendar->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendar->setMinimumDate(QDate(2020,1,1));
        calendar->setMaximumDate(QDate(2050,12,31));

        //connecting the selection of a date to the displaying of the activities in said date
        connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(clickedListActivity(QDate)));

        //button for new activity
        auto buttonNewActivity = new QPushButton("New Activity", this);
        QFont fontButtonNewActivity("Arial", 10);
        buttonNewActivity->setFont(fontButtonNewActivity);
        buttonNewActivity->move(340,550);

        //button for removing activity
        auto buttonRemoveActivity = new QPushButton("Remove Activity", this);
        QFont fontButtonRemoveActivity("Arial", 10);
        buttonRemoveActivity->setFont(fontButtonRemoveActivity);
        buttonRemoveActivity->move(450,550);

        connect(buttonNewActivity, SIGNAL(clicked()), this, SLOT(clickedAddActivity()));
}
MainWindow::~MainWindow(){
    delete calendar;
    delete activityRegister;
}

void MainWindow::clickedAddActivity() {
    NewActivityWindow newActivityWindow(nullptr, activityRegister);
    newActivityWindow.setWindowTitle("New Activity");
    newActivityWindow.exec();
}

void MainWindow::clickedListActivity(QDate date){
    ListActivityWindow listActivityWindow(nullptr, date, activityRegister);
    listActivityWindow.setWindowTitle("List Activity");
    listActivityWindow.exec();
}