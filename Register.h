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

    QMultiMap<QDate, Activity> getActivities() const;

private:
    QMultiMap<QDate, Activity> activities;
};



#endif //ACTIVITYREGISTER_REGISTER_H
