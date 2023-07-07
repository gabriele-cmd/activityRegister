#ifndef ACTIVITYREGISTER_NEWACTIVITYWINDOW_H
#define ACTIVITYREGISTER_NEWACTIVITYWINDOW_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <iostream>
#include "Register.h"

class NewActivityWindow : public QDialog {

Q_OBJECT

public:
    explicit NewActivityWindow(QWidget *parent = nullptr, Register *r = nullptr);
    ~NewActivityWindow() override;
    static bool activityCheck(QDateEdit *date, QTimeEdit *sT, QTimeEdit* eT, QTextEdit *description );

private:
    QLabel *labelNewActivity;
    QLabel *labelDate;
    QLabel *labelStartTime;
    QLabel *labelEndTime;
    QLabel *labelDescriptionActivity;

    QDateEdit *dateEditNewActivity;
    QTimeEdit *timeEditStartTime;
    QTimeEdit *timeEditEndTime;

    QTextEdit *textEditDescriptionActivity;

    QPushButton *buttonOk;
    QPushButton *buttonCancel;
};


#endif //ACTIVITYREGISTER_NEWACTIVITYWINDOW_H
