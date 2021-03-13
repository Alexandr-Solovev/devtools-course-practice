// Copyright 2021 Solovev Aleksandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_Equal) {
    ComplexNumber c1(7.0, 10.0);

    EXPECT_EQ(c1, c1);
}

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_NoEqual) {
    ComplexNumber c1(7.0, 10.0);
    ComplexNumber c2(11.0, 2.0);

    EXPECT_NE(c1, c2);
}

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_Multiply) {
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(7.5, 1.0);
    ComplexNumber result = c1;
    result = result * c2;

    EXPECT_EQ((c1.getRe() * c2.getRe()) - (c1.getIm() * c2.getIm()), result.getRe());
    EXPECT_EQ((c1.getRe() * c2.getIm()) + (c1.getIm() * c2.getRe()), result.getIm());
}

TEST(Solovev_Aleksandr_ComplexNumberTest, Test_Add) {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber result = c1 + c2;

    EXPECT_EQ((c1.getRe() + c2.getRe()), result.getRe());
    EXPECT_EQ((c1.getIm() + c2.getIm()), result.getIm());
}
