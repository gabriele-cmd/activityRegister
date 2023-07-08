#include "NewActivityWindow.h"

NewActivityWindow::NewActivityWindow(QWidget *parent, Register *r) : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint){
    this->setFixedSize(500,625); //dimensione fissa della finestra
    this->setWindowTitle("New Activity"); //titolo della finestra

    labelNewActivity = new QLabel("New Activity",this);
    labelNewActivity->setFixedWidth(400);
    QFont fontLabelNewActivity("Arial", 15, QFont::Bold);
    labelNewActivity->setFont(fontLabelNewActivity);
    labelNewActivity->move(170,30);

    //data della nuova attività
    labelDate = new QLabel("Date: ", this);
    QFont fontLabelDate("Arial", 11);
    labelDate->setFont(fontLabelDate);
    labelDate->move(10, 100);
    dateEditNewActivity = new QDateEdit(QDate::currentDate(), this);
    dateEditNewActivity->setDisplayFormat("dd/MM/yyyy");
    dateEditNewActivity->setFixedWidth(150);
    QFont fontDateEdit("Arial", 10);
    dateEditNewActivity->setFont(fontDateEdit);
    dateEditNewActivity->move(135,98);

    //orario inizio attività
    labelStartTime = new QLabel("Starting time: ", this);
    QFont fontLabelStartTime("Arial", 11);
    labelStartTime->setFont(fontLabelStartTime);
    labelStartTime->move(10, 150);
    timeEditStartTime = new QTimeEdit(QTime::currentTime(), this);
    timeEditStartTime->setFixedWidth(70);
    QFont fontTimeEdit("Arial", 10);
    timeEditStartTime->setFont(fontTimeEdit);
    timeEditStartTime->move(135,148);

    //orario fine attività
    labelEndTime = new QLabel("End time: ", this);
    QFont fontLabelEndTime("Arial", 11);
    labelEndTime->setFont(fontLabelEndTime);
    labelEndTime->move(10,200);
    timeEditEndTime = new QTimeEdit(QTime::currentTime(), this);
    timeEditEndTime->setFixedWidth(70);
    timeEditEndTime->setFont(fontTimeEdit);
    timeEditEndTime->move(135, 198);

    //descrizione attività
    labelDescriptionActivity = new QLabel("Description activity: ", this);
    QFont fontLabelDescriptionActivity("Arial", 11);
    labelDescriptionActivity->setFont(fontLabelDescriptionActivity);
    labelDescriptionActivity->move(10, 300);
    textEditDescriptionActivity = new QTextEdit(this);
    textEditDescriptionActivity->setFixedSize(480, 200);
    QFont fontTextEditDescriptionActivity("Arial", 10);
    textEditDescriptionActivity->setFont(fontTextEditDescriptionActivity);
    textEditDescriptionActivity->move(10,325);

    //bottone ok
    buttonOk = new QPushButton("Ok", this);
    buttonOk->setFixedSize(40,40);

    QFont fontButtonOk("Arial", 10);
    buttonOk->setFont(fontButtonOk);
    buttonOk->move(450,575);
    connect(buttonOk, &QPushButton::clicked, this, [r, this](){
        if(NewActivityWindow::activityCheck(r, dateEditNewActivity, timeEditStartTime, timeEditEndTime, textEditDescriptionActivity)){
            Activity a(textEditDescriptionActivity->toPlainText(), timeEditStartTime->time(), timeEditEndTime->time(), dateEditNewActivity->date());

            r->addActivity(dateEditNewActivity->date(), a);
            this->close();
        }
    });

    //bottone cancel
    buttonCancel = new QPushButton("Cancel", this);
    buttonCancel->setFixedSize(70, 40);
    connect(buttonCancel, &QPushButton::clicked, this, [this](){
        this->close();
    });

    QFont fontButtonCancel("Arial", 10);
    buttonCancel->setFont(fontButtonCancel);
    buttonCancel->move(370,575);
    connect(buttonCancel, &QPushButton::clicked, this, [this](){this->close();} );

};

//constructor with date as parameter
NewActivityWindow::NewActivityWindow(QWidget *parent, QDate date, Register *r) {
    this->setFixedSize(500,625); //dimensione fissa della finestra
    this->setWindowTitle("New Activity"); //titolo della finestra

    labelNewActivity = new QLabel("New Activity",this);
    labelNewActivity->setFixedWidth(400);
    QFont fontLabelNewActivity("Arial", 15, QFont::Bold);
    labelNewActivity->setFont(fontLabelNewActivity);
    labelNewActivity->move(170,30);

    //data della nuova attività
    labelDate = new QLabel("Date: ", this);
    QFont fontLabelDate("Arial", 11);
    labelDate->setFont(fontLabelDate);
    labelDate->move(10, 100);
    dateEditNewActivity = new QDateEdit(date, this);
    dateEditNewActivity->setDisplayFormat("dd/MM/yyyy");
    dateEditNewActivity->setFixedWidth(150);
    QFont fontDateEdit("Arial", 10);
    dateEditNewActivity->setFont(fontDateEdit);
    dateEditNewActivity->move(135,98);

    //orario inizio attività
    labelStartTime = new QLabel("Starting time: ", this);
    QFont fontLabelStartTime("Arial", 11);
    labelStartTime->setFont(fontLabelStartTime);
    labelStartTime->move(10, 150);
    timeEditStartTime = new QTimeEdit(QTime::currentTime(), this);
    timeEditStartTime->setFixedWidth(70);
    QFont fontTimeEdit("Arial", 10);
    timeEditStartTime->setFont(fontTimeEdit);
    timeEditStartTime->move(135,148);

    //orario fine attività
    labelEndTime = new QLabel("End time: ", this);
    QFont fontLabelEndTime("Arial", 11);
    labelEndTime->setFont(fontLabelEndTime);
    labelEndTime->move(10,200);
    timeEditEndTime = new QTimeEdit(QTime::currentTime(), this);
    timeEditEndTime->setFixedWidth(70);
    timeEditEndTime->setFont(fontTimeEdit);
    timeEditEndTime->move(135, 198);

    //descrizione attività
    labelDescriptionActivity = new QLabel("Description activity: ", this);
    QFont fontLabelDescriptionActivity("Arial", 11);
    labelDescriptionActivity->setFont(fontLabelDescriptionActivity);
    labelDescriptionActivity->move(10, 300);
    textEditDescriptionActivity = new QTextEdit(this);
    textEditDescriptionActivity->setFixedSize(480, 200);
    QFont fontTextEditDescriptionActivity("Arial", 10);
    textEditDescriptionActivity->setFont(fontTextEditDescriptionActivity);
    textEditDescriptionActivity->move(10,325);

    //bottone ok
    buttonOk = new QPushButton("Ok", this);
    buttonOk->setFixedSize(40,40);

    QFont fontButtonOk("Arial", 10);
    buttonOk->setFont(fontButtonOk);
    buttonOk->move(450,575);
    connect(buttonOk, &QPushButton::clicked, this, [r, this](){
        if(NewActivityWindow::activityCheck(r,dateEditNewActivity, timeEditStartTime, timeEditEndTime, textEditDescriptionActivity)){
            Activity a(textEditDescriptionActivity->toPlainText(), timeEditStartTime->time(), timeEditEndTime->time(), dateEditNewActivity->date());

            r->addActivity(dateEditNewActivity->date(), a);
            this->close();
        }
    });

    //bottone cancel
    buttonCancel = new QPushButton("Cancel", this);
    buttonCancel->setFixedSize(70, 40);
    connect(buttonCancel, &QPushButton::clicked, this, [this](){
        this->close();
    });

    QFont fontButtonCancel("Arial", 10);
    buttonCancel->setFont(fontButtonCancel);
    buttonCancel->move(370,575);
    connect(buttonCancel, &QPushButton::clicked, this, [this](){this->close();} );

}

NewActivityWindow::~NewActivityWindow() {
    delete labelNewActivity;
    delete labelDate;
    delete labelStartTime;
    delete labelEndTime;
    delete labelDescriptionActivity;
    delete dateEditNewActivity;
    delete timeEditStartTime;
    delete timeEditEndTime;
    delete textEditDescriptionActivity;
    delete buttonOk;
    delete buttonCancel;
}

bool NewActivityWindow::activityCheck(Register* r, QDateEdit *date, QTimeEdit *sT, QTimeEdit *eT, QTextEdit *description) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Error");

    //checkin if date is valid
    if(date->date().isNull() || date->date().year() > 2100 || date->date().year() < QDate::currentDate().year() || date->date().month() < QDate::currentDate().month() || date->date().day() < QDate::currentDate().day()){
        messageBox.setText("Date is not correct!");
        messageBox.exec();
        return false;
    }

    //checking if start and ending times are not the same and if end time is not after start time
    if(eT->time()<sT->time() || (eT->time().hour() == sT->time().hour() && eT->time().minute() == sT->time().minute())){
        messageBox.setText("Times are not correct!");
        messageBox.exec();
        return false;
    }

    //description is mandatory, checking if it has been given
    if(description->toPlainText().isEmpty()){
        messageBox.setText("Description is not correct!");
        messageBox.exec();
        return false;
    }

    for (const auto& it : r->getActivities()) {
        if (it.getDate() == date->date() && ((sT->time() >= it.getStartTime() && sT->time() <= it.getEndTime()) || (eT->time() >= it.getStartTime() && eT->time() <= it.getEndTime()) || (sT->time() <= it.getStartTime() && eT->time() >= it.getEndTime()))) {
            QMessageBox confirmBox;
            confirmBox.setWindowTitle("Warning");
            confirmBox.setText("Seems like you are already busy during this time!\nAre you sure you want to add a new activity?");
            confirmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            confirmBox.setDefaultButton(QMessageBox::No);
            int choice = confirmBox.exec();
            if (choice == QMessageBox::No) {
                return false;
            } else {
                break; // exit the loop if the user chooses to proceed
            }
        }
    }
    return true;
}
