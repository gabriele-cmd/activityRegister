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

bool Register::isNotActivity(const QDate &date){
    if(this->activities.count(date) == 0)
        return true;
    return false;
}

QMultiMap<QDate, Activity> Register::getActivities() const{
    return activities;
}