#include "gtest/gtest.h"
#include <iostream>
#include "../Activity.h"
//.
TEST(TestActivity, testActivityNotEqual) {
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,7,9));

    ASSERT_TRUE(a1->operator!=(*a2));
}

TEST(TestActivity, testActivityEqual) {
    Activity *a1 = new Activity("Descrizione1", QTime(12,00), QTime(13,00), QDate(2023,7,9));
    Activity *a2 = new Activity("Descrizione2", QTime(15,00), QTime(16,00), QDate(2023,7,9));

    ASSERT_TRUE(a1->operator==(*a2));
}