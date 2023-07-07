#include "MainWindow.h"
#include "NewActivityWindow.h"
#include "ListActivityWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
        this->setFixedSize(600,600);
        Register activityRegister;

        calendar = new QCalendarWidget(this);
        calendar->resize(400,400);
        calendar->move(100,100);
        calendar->setGridVisible(true);
        connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(clickedListActivity(QDate)));


        auto buttonNewActivity = new QPushButton("New Activity", this);
        QFont fontButtonNewActivity("Arial", 10);
        buttonNewActivity->setFont(fontButtonNewActivity);
        buttonNewActivity->move(400,520);

        auto buttonRemoveActivity = new QPushButton("Remove Activity", this);
        QFont fontButtonRemoveActivity("Arial", 10);
        buttonRemoveActivity->setFont(fontButtonRemoveActivity);
        buttonRemoveActivity->move(400,550);

        connect(buttonNewActivity, SIGNAL(clicked()), this, SLOT(clickedAddActivity()));
        connect(buttonRemoveActivity, SIGNAL(clicked()), this, SLOT(clickedRemoveActivity()));
}
MainWindow::~MainWindow(){
    delete calendar;
    delete addActButton;
    delete deleteActButton;
}

void MainWindow::clickedAddActivity() {
    NewActivityWindow newActivityWindow(nullptr, &activityRegister);
    newActivityWindow.setWindowTitle("New Activity");
    newActivityWindow.setWindowIcon(QIcon("../image/iconNewActivityWindow.png"));
    newActivityWindow.exec();
}

void MainWindow::clickedListActivity(QDate date){
    ListActivityWindow listActivityWindow(nullptr, date, &activityRegister);
    listActivityWindow.setWindowTitle("List Activity");
    listActivityWindow.setWindowIcon(QIcon("../image/listActivityWindow.png"));

    listActivityWindow.exec();

}