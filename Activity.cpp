#include "Activity.h"
#include <QTime>
#include <QString>

//Constructor implementation
Activity::Activity(QString desc, QTime st, QTime et, QDate d) : description(desc), startTime(st), endTime(et), date(d) {} //initializion list

//Getters implementation
QString Activity::getDescription() const {
    return description;
}
QTime Activity::getStartTime() const {
    return startTime;
}
QTime Activity::getEndTime() const {
    return endTime;
}
QDate Activity::getDate() const {
    return date;
}
Activity Activity::getActivity() const {
    return *this;
}

//Setters implementation
void Activity::setDescription(QString desc) {
    description = desc;
}
void Activity::setStartTime(QTime start) {
    startTime = start;
}
void Activity::setEndTime(QTime end) {
    endTime = end;
}
void Activity::setDate(QDate d) {
    date = d;
}

//Overloading Operators implementation
bool Activity::operator==(const Activity &right) const {
    if(description == right.getDescription() && startTime == right.getStartTime() && endTime == right.getEndTime())
        return true;
    return false;
}
bool Activity::operator!=(const Activity &right) const {
    return !(right == *this);//literally the opposite of ==
}