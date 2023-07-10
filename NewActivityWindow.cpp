#include "NewActivityWindow.h"

NewActivityWindow::NewActivityWindow(QWidget *parent, Register *r) : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint){
    this->setFixedSize(500,600);
    this->setWindowTitle("New Activity");
    this->move(520,81);
    this->setStyleSheet("* { color: purple }");

    labelNewActivity = new QLabel("New Activity:",this);
    labelNewActivity->setFixedWidth(400);
    QFont fontLabelNewActivity("Arial", 17, QFont::Bold);
    labelNewActivity->setFont(fontLabelNewActivity);
    labelNewActivity->move(175,40);

    //new activity date
    labelDate = new QLabel("Date: ", this);
    QFont fontLabelDate("Arial", 11);
    labelDate->setFont(fontLabelDate);
    labelDate->move(10, 105);
    dateEditNewActivity = new QDateEdit(QDate::currentDate(), this);
    dateEditNewActivity->setDisplayFormat("dd/MM/yyyy");
    dateEditNewActivity->setFixedWidth(150);
    QFont fontDateEdit("Arial", 10);
    dateEditNewActivity->setFont(fontDateEdit);
    dateEditNewActivity->move(135,103);

    //new activity starting time
    labelStartTime = new QLabel("Starting time: ", this);
    QFont fontLabelStartTime("Arial", 11);
    labelStartTime->setFont(fontLabelStartTime);
    labelStartTime->move(10, 160);
    timeEditStartTime = new QTimeEdit(QTime::currentTime(), this);
    timeEditStartTime->setFixedWidth(70);
    QFont fontTimeEdit("Arial", 10);
    timeEditStartTime->setFont(fontTimeEdit);
    timeEditStartTime->move(135,158);

    //new activity ending time
    labelEndTime = new QLabel("End time: ", this);
    QFont fontLabelEndTime("Arial", 11);
    labelEndTime->setFont(fontLabelEndTime);
    labelEndTime->move(10,220);
    timeEditEndTime = new QTimeEdit(QTime::currentTime().addSecs(3600), this);
    timeEditEndTime->setFixedWidth(70);
    timeEditEndTime->setFont(fontTimeEdit);
    timeEditEndTime->move(135, 218);

    //new activity description
    labelDescriptionActivity = new QLabel("Description activity: ", this);
    QFont fontLabelDescriptionActivity("Arial", 11);
    labelDescriptionActivity->setFont(fontLabelDescriptionActivity);
    labelDescriptionActivity->move(10, 280);
    textEditDescriptionActivity = new QTextEdit(this);
    textEditDescriptionActivity->setFixedSize(480, 200);
    QFont fontTextEditDescriptionActivity("Arial", 10);
    textEditDescriptionActivity->setFont(fontTextEditDescriptionActivity);
    textEditDescriptionActivity->move(10,320);

    //OK button
    buttonOk = new QPushButton("OK", this);
    buttonOk->setFixedSize(40,30);

    QFont fontButtonOk("Arial", 10);
    buttonOk->setFont(fontButtonOk);
    buttonOk->move(375,545);
    buttonOk->setStyleSheet("* { color: green }");

    connect(buttonOk, &QPushButton::clicked, this, [r, this](){
        if(NewActivityWindow::activityCheck(r, dateEditNewActivity, timeEditStartTime, timeEditEndTime, textEditDescriptionActivity)){
            Activity a(textEditDescriptionActivity->toPlainText(), timeEditStartTime->time(), timeEditEndTime->time(), dateEditNewActivity->date());

            r->addActivity(dateEditNewActivity->date(), a);
            this->close();
        }
    });

    //CANCEL button
    buttonCancel = new QPushButton("CANCEL", this);
    buttonCancel->setFixedSize(70, 30);

    QFont fontButtonCancel("Arial", 10);
    buttonCancel->setFont(fontButtonCancel);
    buttonCancel->move(420,545);
    buttonCancel->setStyleSheet("* { color: red }");

    connect(buttonCancel, &QPushButton::clicked, this, [this](){
        this->close();
    });
};

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
            messageBox.setWindowTitle("Warning");
            messageBox.setText("Seems like you are already busy during this time!\nAre you sure you want to add a new activity?");
            messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            messageBox.setDefaultButton(QMessageBox::No);
            int choice = messageBox.exec();
            if (choice == QMessageBox::No) {
                return false;
            } else {
                break; // exit the loop if the user chooses to proceed anyway
            }
        }
    }
    return true;
}
