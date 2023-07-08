#include "MainWindow.h"
#include "NewActivityWindow.h"
#include "ListActivityWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
        this->setFixedSize(600,600);
        Register activityRegister;
        ListActivityWindow listActivityWindow(nullptr, QDate::currentDate(), &activityRegister);

        calendar = new QCalendarWidget(this);
        calendar->resize(400,400);
        calendar->move(100,100);
        calendar->setGridVisible(true);
        connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(clickedListActivity(QDate)));

        //button for new activity
        auto buttonNewActivity = new QPushButton("New Activity", this);
        QFont fontButtonNewActivity("Arial", 10);
        buttonNewActivity->setFont(fontButtonNewActivity);
        buttonNewActivity->move(400,520);

        //button for removing activity
        auto buttonRemoveActivity = new QPushButton("Remove Activity", this);
        QFont fontButtonRemoveActivity("Arial", 10);
        buttonRemoveActivity->setFont(fontButtonRemoveActivity);
        buttonRemoveActivity->move(400,550);

        //connect(buttonNewActivity, SIGNAL(clicked()), this, SLOT(clickedAddActivity()));
        connect(buttonNewActivity, SIGNAL(clicked()), this, SLOT(handleNewActivityClicked()));
        connect(&listActivityWindow, SIGNAL(newActivityClicked(QDate)), this, SLOT(clickedAddActivity(QDate)));
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
    newActivityWindow.exec();
}

void MainWindow::clickedAddActivity(QDate date) {
    NewActivityWindow newActivityWindow(nullptr, date, &activityRegister);
    newActivityWindow.setWindowTitle("New Activity");
    newActivityWindow.exec();
}

void MainWindow::clickedListActivity(QDate date){
    ListActivityWindow listActivityWindow(nullptr, date, &activityRegister);
    listActivityWindow.setWindowTitle("List Activity");
    listActivityWindow.exec();
}

/*
void MainWindow::clickedRemoveActivity(){
    QMessageBox messageBox;
    messageBox.setWindowTitle("Warning!");
    messageBox.setText("Are you sure you want to delete this activity?");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    int ret = messageBox.exec();

    switch (ret) {
        case QMessageBox::Yes:
            activityRegister.removeActivity();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
    }
}
 */

void MainWindow::handleNewActivityClicked() {
    QDate selected = calendar->selectedDate();
    emit newActivityClicked(selected);
}