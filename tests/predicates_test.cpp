/*
    Minimalistic C++ header-only type mapper library
    Copyright (C) 2011 Hugo Arregui

    This file is part of the tm++ Library.

    tm++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    tm++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with tm++.  If not, see <http://www.gnu.org/licenses/>.
    This is a test file
*/

#include "test_base.h"
#include "tm_pp/predicates.h"

using tm_pp::is_equal;
using tm_pp::is_pointer;
using tm_pp::is_integral;
using tm_pp::is_const;
using tm_pp::is_fundamental;
using tm_pp::is_reference;
using tm_pp::And;

TEST(Predicates, is_equal)
{
    ASSERT_TRUE(bool(is_equal<int>::To<int>::value));
}

TEST(Predicates, is_pointer)
{
    ASSERT_TRUE(bool(is_pointer<int*>::value));
    ASSERT_TRUE(bool(is_pointer<int *const>::value));
}

TEST(Predicates, is_integral)
{
    ASSERT_TRUE(bool(is_integral<int>::value));
    ASSERT_TRUE(bool(is_integral<unsigned int>::value));
    ASSERT_TRUE(bool(is_integral<short int>::value));
    ASSERT_TRUE(bool(is_integral<unsigned short int>::value));
    ASSERT_TRUE(bool(is_integral<long int>::value));
    ASSERT_TRUE(bool(is_integral<unsigned long int>::value));
    ASSERT_TRUE(bool(is_integral<char>::value));
    ASSERT_TRUE(bool(is_integral<signed char>::value));
    ASSERT_TRUE(bool(is_integral<unsigned char>::value));
}

TEST(Predicates, is_const)
{
    ASSERT_TRUE(bool(is_const<const int>::value));
    ASSERT_TRUE(bool(is_const<int *const>::value));
    ASSERT_FALSE(bool(is_const<const int*>::value));
}

TEST(Predicates, is_fundamental)
{
    ASSERT_TRUE(bool(is_fundamental<char>::value));
    ASSERT_TRUE(bool(is_fundamental<bool>::value));
    ASSERT_TRUE(bool(is_fundamental<float>::value));
    ASSERT_TRUE(bool(is_fundamental<const double>::value));
    ASSERT_TRUE(bool(is_fundamental<const char>::value));
}

TEST(Predicates, is_reference)
{
    ASSERT_TRUE(bool(is_reference<int&>::value));
    ASSERT_TRUE(bool(is_reference<const int& >::value));
}

TEST(Predicates, And)
{
    ASSERT_TRUE(bool(And<is_const, is_pointer>::Predicate<char* const>::value));
    ASSERT_FALSE(bool(And<is_const, is_integral>::Predicate<const float>::value));
}
