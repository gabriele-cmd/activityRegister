#include "ListActivityWindow.h"
#include "MainWindow.h"

ListActivityWindow::ListActivityWindow(QWidget *parent, QDate date, Register *r) : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint) {

    this->setFixedSize(500,600);
    this->move(520,81);
    this->setStyleSheet("* { color:purple }");

    //list of activities
    labelListActivity = new QLabel("List Activity", this);
    QFont fontLabelListActivity("Arial", 17, QFont::Bold);
    labelListActivity->setFont(fontLabelListActivity);
    labelListActivity->move(185 ,40);

    //date of the activities
    QString s = "Date:   ";
    s += QString(date.toString("dd/MM/yyyy"));
    labelDate = new QLabel(s, this);
    QFont fontLabelDate("Arial", 12);
    labelDate->setFont(fontLabelDate);
    labelDate->move(10,100);

    QFont fontLabel("Arial", 10);

    if(r->isNotActivity(date)){ //if there are no activities on that date
        createEmptyLabel();
    }else {
        //scroll area
        scrollAreaListActivity = new QScrollArea(this);
        scrollAreaListActivity->setFixedSize(480, 350);
        scrollAreaListActivity->move(10, 140);
        scrollAreaListActivity->setWidgetResizable(true);
        scrollAreaListActivity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaListActivity->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        qWidget = new QWidget(this);
        QGridLayout *gridLayout = new QGridLayout(qWidget);

        std::vector<Activity> sortedActivities; //vector that stores all the activites

        for (auto it : r->getActivities()) { //storing...
            if (it.getDate() == date) {
                sortedActivities.push_back(it);
            }
        }

        //sorts the activites by starting time this way new activities are inserted in the right order
        std::sort(sortedActivities.begin(), sortedActivities.end(), [](const Activity& a1, const Activity& a2) {
            return a1.getStartTime() < a2.getStartTime();
        });

        int i = 0;
        for (const auto& activity : sortedActivities) {
            QGroupBox *groupBox = new QGroupBox(this);
            QVBoxLayout *vbox = new QVBoxLayout(groupBox);

            QString stringStartTime = "Starting time: ";
            stringStartTime += QString(activity.getStartTime().toString("hh:mm"));
            QLabel *labelStartTime = new QLabel(stringStartTime);
            labelStartTime->setFont(fontLabel);
            vbox->addWidget(labelStartTime);

            QString stringEndTime = "End time: ";
            stringEndTime += QString(activity.getEndTime().toString("hh:mm"));
            QLabel *labelEndTime = new QLabel(stringEndTime);
            labelEndTime->setFont(fontLabel);
            vbox->addWidget(labelEndTime);

            QLabel *labelDescription = new QLabel("Description: " + activity.getDescription());
            labelDescription->setWordWrap(true);
            labelDescription->setMaximumWidth(412);
            labelDescription->setFont(fontLabel);
            vbox->addWidget(labelDescription);

            QPushButton *buttonDelete = new QPushButton("Delete", this);
            buttonDelete->setFixedSize(60, 40);
            buttonDelete->setStyleSheet("* { color: red }");

            connect(buttonDelete, &QPushButton::clicked, this, [this, groupBox, r, activity, date]() {
                r->removeActivity(activity.getActivity());
                delete groupBox;
                if (r->isNotActivity(date)) {
                    delete this->scrollAreaListActivity;
                    this->createEmptyLabel();
                }
            });
            vbox->addWidget(buttonDelete);
            groupBox->setLayout(vbox);
            gridLayout->addWidget(groupBox, i++, 0);
        }

        scrollAreaListActivity->setWidget(qWidget);
    }
}
ListActivityWindow::~ListActivityWindow() {
    delete labelListActivity;
    delete labelDate;
}

void ListActivityWindow::createEmptyLabel() {
    QLabel *labelEmpty = new QLabel("There are no activities in this date", this);
    QFont fontLabelEmpty("Arial", 16, QFont::Bold);
    labelEmpty->setFont(fontLabelEmpty);
    labelEmpty->move(80, 180);
    labelEmpty->setStyleSheet("* { color: red }");
}
