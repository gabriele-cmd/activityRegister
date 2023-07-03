#ifndef ACTIVITYREGISTER_REGISTER_H
#define ACTIVITYREGISTER_REGISTER_H

#include"QList"
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
    bool findActivity(Activity& a) const;
    bool isNotActivity(const QDate &date);
    void listActivities(QDate& d) const;
    QString getDescripiton(Activity& a) const;

    QMultiMap<QDate, Activity> getActivities() const;

private:
    QMultiMap<QDate, Activity> activities;
};



#endif //ACTIVITYREGISTER_REGISTER_H
