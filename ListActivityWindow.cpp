#include "ListActivityWindow.h"
#include "MainWindow.h"

ListActivityWindow::ListActivityWindow(QWidget *parent, QDate date, Register *r) : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint) {

    this->setFixedSize(500,500);

    //list of activities
    labelListActivity = new QLabel("List Activity", this);
    QFont fontLabelListActivity("Arial", 15, QFont::Bold);
    labelListActivity->setFont(fontLabelListActivity);
    labelListActivity->move(175 ,40);
    labelListActivity->setStyleSheet("* { color:red }");

    //date of the activities
    QString s = "Date:   ";
    s += QString(date.toString("dd/MM/yyyy"));
    labelDate = new QLabel(s, this);
    QFont fontLabelDate("Arial", 11);
    labelDate->setFont(fontLabelDate);
    labelDate->move(10,100);

    QFont fontLabel("Arial", 10);
    QFont fontTitle("Arial", 11, QFont::Bold);

    if(r->isNotActivity(date)){ //se non ci sono attività presenti in quella data
        createEmptyLabel();
    }else {

        //scroll area
        scrollAreaListActivity = new QScrollArea(this);
        scrollAreaListActivity->setFixedSize(480, 350);
        scrollAreaListActivity->move(10, 140);
        scrollAreaListActivity->setWidgetResizable(true);
        scrollAreaListActivity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        qWidget= new QWidget(this);

        QGridLayout *gridLayout = new QGridLayout(qWidget);

        QGroupBox *groupBox;
        QVBoxLayout *vbox;
        QPushButton *buttonDelete;
        QString stringDate, stringStartTime, stringEndTime;
        QLabel *labelStartTime, *labelEndTime, *labelDescription;

        int i = 0;
        for (auto it : r->getActivities()) {

            if(it.getDate() == date) {
                vbox = new QVBoxLayout;

                //label ora di inizio
                stringStartTime = "Starting time: ";
                stringStartTime += QString(it.getStartTime().toString("hh:mm"));
                labelStartTime = new QLabel(stringStartTime);
                labelStartTime->setFont(fontLabel);
                vbox->addWidget(labelStartTime);

                //label ora di fine
                stringEndTime = "End time: ";
                stringEndTime += QString(it.getEndTime().toString("hh:mm"));
                labelEndTime = new QLabel(stringEndTime);
                labelEndTime->setFont(fontLabel);
                vbox->addWidget(labelEndTime);

                //label descrizione
                labelDescription = new QLabel("Description:\n" + it.getDescription());
                labelDescription->setWordWrap(true);
                labelDescription->setMaximumWidth(412);
                labelDescription->setFont(fontLabel);
                vbox->addWidget(labelDescription);

                //button delete
                buttonDelete = new QPushButton((QIcon("../image/deleteActivity.png")), "");
                buttonDelete->setFixedSize(32, 32);
                connect(buttonDelete, &QPushButton::clicked, this, [this, groupBox, r, it, date]() {
                    r->removeActivity(it.getActivity());
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

        }
        scrollAreaListActivity->setWidget(qWidget);
    }

    auto buttonNewActivity = new QPushButton("New Activity", this);
    QFont fontButtonNewActivity("Arial", 10);
    buttonNewActivity->setFont(fontButtonNewActivity);
    buttonNewActivity->move(370,440);

    MainWindow mainWindow;
    //connecting signal to slot
    connect(&mainWindow, SIGNAL(newActivityClicked(QDate)), this, SLOT(clickedAddActivity(QDate)));
    this->selectedDate = date;
    connect(buttonNewActivity, SIGNAL(clicked()), parent, SLOT(handleNewActivityClicked()));

}
ListActivityWindow::~ListActivityWindow() {
    delete labelListActivity;
    delete labelDate;
}

void ListActivityWindow::createEmptyLabel() {
    QLabel *labelEmpty = new QLabel("There are no activities in this date", this);
    QFont fontLabelEmpty("Arial", 11, QFont::Bold);
    labelEmpty->setFont(fontLabelEmpty);
    labelEmpty->move(10, 140);
}

void ListActivityWindow::handleNewActivityClicked() {
    emit newActivityClicked(selectedDate);
}
