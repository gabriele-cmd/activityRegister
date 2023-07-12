#include "Register.h"

void Register::addActivity(QDate d, Activity& a){
    activities.insert(d, a);
}

void Register::removeActivity(Activity a){
    for(auto it = activities.begin(); it != activities.end(); it++){
        if(it.value() == a)
            activities.erase(it);
    }
}

bool Register::isNotActivity(const QDate &date){
    if(this->activities.count(date) == 0)
        return true;
    return false;
}

QMultiMap<QDate, Activity> Register::getActivities() const{
    return activities;
}


void Register::listActivities(QDate& d) const{
    auto range = activities.equal_range(d);
    for (auto it = range.first; it != range.second; ++it) {
        qDebug() << "Date: " << it.key() << ", Start time: " << it.value().getStartTime() << ", End time: " << it.value().getEndTime() << ", Activity: " << it.value().getDescription();
    }
}

bool Register::findActivity(Activity& a) const{
    for(auto it = activities.begin(); it != activities.end(); it++){
        if(it.value() == a)
            return true;
    }
    return false;
}

void Register::modifyActivity(Activity& a, QDate d, QTime st, QTime et, QString desc){
    for(auto it = activities.begin(); it != activities.end(); it++){
        if(it.value() == a){
            it.value().setDate(d);
            it.value().setStartTime(st);
            it.value().setEndTime(et);
            it.value().setDescription(desc);
        }
    }
}

QMultiMap<QDate, Activity> Register::getUncompletedActivities() const {
    QMultiMap<QDate, Activity> uncompleted;
    for (auto it = activities.begin(); it != activities.end(); it++) {
        if ((it.value().getDate() > QDate::currentDate()) || (it.value().getDate() == QDate::currentDate() && it.value().getEndTime() > QTime::currentTime()))
            uncompleted.insert(it.key(), it.value());
    }
    return uncompleted;
}

QMultiMap<QDate, Activity> Register::getCompletedActivities() const {
    QMultiMap<QDate, Activity> completed;
    for (auto it = activities.begin(); it != activities.end(); it++) {
        if ((it.value().getDate() < QDate::currentDate()) || (it.value().getDate() == QDate::currentDate() && it.value().getEndTime() < QTime::currentTime()))
            completed.insert(it.key(), it.value());
    }
    return completed;
}