#include "Activity.h"
#include <QTime>
#include <QString>

//Constructor implementation
Activity::Activity(QString desc, QTime st, QTime et) : description(desc), startTime(st), endTime(et) {} //initializion list

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

//Overloading Operators implementation
bool Activity::operator==(const Activity &right) const {
    if(description == right.getDescription() && startTime == right.getStartTime() && endTime == right.getEndTime())
        return true;
    return false;
}
bool Activity::operator!=(const Activity &right) const {
    return !(right == *this);//literally the opposite of ==
}