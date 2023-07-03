#ifndef ACTIVITYREGISTER_ACTIVITY_H
#define ACTIVITYREGISTER_ACTIVITY_H

#include <QTime>
#include <QString>

class Activity {
public:
    //Constructor
    Activity(QString desc, QTime st, QTime et);
    //Destructor
    ~Activity() = default;

    //Getters (const to disallow modifications)
    QString getDescription() const;
    QTime getStartTime() const;
    QTime getEndTime() const;

    //Setters
    void setDescription(QString desc);
    void setStartTime(QTime start);
    void setEndTime(QTime end);

    //Overloading operators
    bool operator==(const Activity& right) const;
    bool operator!=(const Activity& right) const;

private:
    QString description;
    QTime startTime;
    QTime endTime;
};


#endif //ACTIVITYREGISTER_ACTIVITY_H
