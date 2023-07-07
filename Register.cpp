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

bool Register::findActivity(Activity& a) const{
    for(auto it = activities.begin(); it != activities.end(); it++){
        if(it.value() == a)
            return true;
    }
    return false;
}

void Register::listActivities(QDate& d) const{
    auto range = activities.equal_range(d);
    for (auto it = range.first; it != range.second; ++it) {
        qDebug() << "Date: " << it.key() << ", Activity: " << it.value().getDescription();
    }
}
QString Register::getDescripiton(Activity& a) const{
    for(auto it = activities.begin(); it != activities.end(); it++){
        if(it.value() == a)
            return it.value().getDescription();
    }
    return "ATTIVITA' NON TROVATA";
}

bool Register::isNotActivity(const QDate &date){
    if(this->activities.count(date) == 0)
        return true;
    return false;
}

QMultiMap<QDate, Activity> Register::getActivities() const{
    return activities;
}