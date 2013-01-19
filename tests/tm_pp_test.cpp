/*
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
#include "tm_pp/tm_pp.h"
#include "tm_pp/predicates.h"

using namespace tm_pp;

typedef TypeMapper<Type<double>, is_integral, is_equal<float>::To> NumberToDoubleMapper;
typedef TypeMapper<Type<int>, And<is_pointer, is_const>::Predicate> ConstPointerToInt;

TEST(TM_PP, simple_mappers)
{
    META_ASSERT_EQ<NumberToDoubleMapper::Map<int>::type, double>::ASSERT();
    META_ASSERT_EQ<ConstPointerToInt::Map<char *const>::type, int>::ASSERT();
}

typedef CompoundMapper<NumberToDoubleMapper, ConstPointerToInt> CMapper;
TEST(TM_PP, compound_mapper)
{
    META_ASSERT_EQ<CMapper::Map<float>::type, double>::ASSERT();
    META_ASSERT_EQ<CMapper::Map<int *const>::type, int>::ASSERT();
}

typedef TypeMapper<Unconst, is_integral> IntegralUnconstMapper;
typedef TypeMapper<Const, is_integral> IntegralConstMapper;
TEST(TM_PP, complex_targets_mapper)
{
    META_ASSERT_EQ<IntegralUnconstMapper::Map<int>::type, int>::ASSERT();
    META_ASSERT_EQ<IntegralUnconstMapper::Map<const int>::type, int>::ASSERT();
    META_ASSERT_EQ<IntegralConstMapper::Map<int>::type, const int>::ASSERT();
}
