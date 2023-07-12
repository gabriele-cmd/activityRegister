#ifndef ACTIVITYREGISTER_REGISTER_H
#define ACTIVITYREGISTER_REGISTER_H

#include "QList"
#include <QFile>
#include <QTextStream>
#include <memory>
#include "Activity.h"
using namespace std;

class Register {
public:
    Register() = default;
    ~Register() = default;

    void addActivity(QDate d, Activity& a);
    void removeActivity(Activity a);
    bool isNotActivity(const QDate &date); //isEmpty check for a specific date

    void listActivities(QDate& d) const; //shows activities by date (unused)
    bool findActivity(Activity& a) const; //finds a certain activity (unused)
    void modifyActivity(Activity& a, QDate d, QTime st, QTime et, QString desc); //modifies an activity with new parameters (unused)
    QMultiMap<QDate, Activity> getUncompletedActivities() const; //shows uncompleted activities based on current date (unused)
    QMultiMap<QDate, Activity> getCompletedActivities() const; //shows completed activities based on current date (unused)

    QMultiMap<QDate, Activity> getActivities() const;

private:
    QMultiMap<QDate, Activity> activities;
};



#endif //ACTIVITYREGISTER_REGISTER_H
