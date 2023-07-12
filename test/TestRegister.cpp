#include "../Register.h"
#include <gtest/gtest.h>
#include <iostream>

//testing empty registers
TEST(TestRegister, testRegisterIsNotActivity){
    Register r;

    ASSERT_TRUE(r.isNotActivity(QDate(2023,7,9)));
}

//testing not empty registers
TEST(TestRegister, testRegisterIsNotEmpty){
    Register r;
    Activity *a = new Activity("Descrizione", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    r.addActivity(a->getDate(), *a);

    ASSERT_FALSE(r.isNotActivity(a->getDate()));
}

//testing add and remove activities features
TEST(TestRegister, testRegisterAddActivity) {
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,2,24));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);

    ASSERT_FALSE(r->isNotActivity(a1->getDate()));
    ASSERT_FALSE(r->isNotActivity(a2->getDate()));
    ASSERT_EQ(2, r->getActivities().size());
}

TEST(TestRegister, testRegisterRemoveActivity) {
    Register *r = new Register();


    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,12));
    Activity *a3 = new Activity("Descrizione3", QTime(15,00), QTime(16,00), QDate(2023,8,12));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);
    r->removeActivity(*a1);
    r->removeActivity(*a3);


    ASSERT_FALSE(r->isNotActivity(a2->getDate()));
    ASSERT_TRUE(r->isNotActivity(a1->getDate()));
    ASSERT_EQ(1, r->getActivities().size());
}

//tests finding an activity
TEST(TestRegister, testRegisterFindActivity) {
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,12));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);

    ASSERT_TRUE(r->findActivity(*a1));
    ASSERT_TRUE(r->findActivity(*a2));
}

//tests getting uncompleted activities
TEST(TestRegister, testGetUncompletedActivities){
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,16));
    Activity *a3 = new Activity("Descrizione3", QTime(15,00), QTime(16,00), QDate(2023,8,23));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);
    r->addActivity(a3->getDate(), *a3);

    ASSERT_EQ(2, r->getUncompletedActivities().size());
}

//tests getting completed activities
TEST(TestRegister, testGetCompletedActivities){
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,16));
    Activity *a3 = new Activity("Descrizione3", QTime(15,00), QTime(16,00), QDate(2023,8,23));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);
    r->addActivity(a3->getDate(), *a3);

    ASSERT_EQ(1, r->getCompletedActivities().size());
}

//tests modifying an activity
TEST(TestRegister, testModifyActivity){
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,16));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);

    ASSERT_EQ(2, r->getActivities().size());
    ASSERT_EQ("Descrizione1", r->getActivities().value(a1->getDate(), *a1).getDescription());
    ASSERT_EQ("Descrizione2", r->getActivities().value(a2->getDate(), *a2).getDescription());

    r->modifyActivity(*a1,  QDate(2023,7,9), QTime(12,00), QTime(13,00), "Descrizione1 modificata");

    ASSERT_EQ(2, r->getActivities().size());
    ASSERT_EQ("Descrizione1 modificata", r->getActivities().value(a1->getDate(), *a1).getDescription());
    ASSERT_EQ("Descrizione2", r->getActivities().value(a2->getDate(), *a2).getDescription());
}

//tests removing an activity
TEST(TestRegister, testRemovingUnexistingActivity){
    Register *r = new Register();
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,8,16));
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);

    ASSERT_EQ(2, r->getActivities().size());
    ASSERT_EQ("Descrizione1", r->getActivities().value(a1->getDate(), *a1).getDescription());
    ASSERT_EQ("Descrizione2", r->getActivities().value(a2->getDate(), *a2).getDescription());

    r->removeActivity(*a1);
    r->removeActivity(*a1);

    ASSERT_EQ(1, r->getActivities().size());
    ASSERT_EQ("Descrizione2", r->getActivities().value(a2->getDate(), *a2).getDescription());
}