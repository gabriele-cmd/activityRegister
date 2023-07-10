#include "../Register.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(TestRegister, testRegisterIsEmpty){
    Register r;

    ASSERT_TRUE(r.isNotActivity(QDate(2023,7,9)));
}

TEST(TestRegister, testRegisterIsNotEmpty){
    Register r;
    Activity *a = new Activity("Descrizione", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    r.addActivity(a->getDate(), *a);

    ASSERT_FALSE(r.isNotActivity(a->getDate()));
}

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
    r->addActivity(a1->getDate(), *a1);
    r->addActivity(a2->getDate(), *a2);
    r->removeActivity(*a1);

    ASSERT_FALSE(r->isNotActivity(a2->getDate()));
    ASSERT_TRUE(r->isNotActivity(a1->getDate()));
    ASSERT_EQ(1, r->getActivities().size());
}