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
#include "tm_pp/targets.h"

TEST(Targets, To)
{
    META_ASSERT_EQ<Type<int>::To<float>::type, int>::ASSERT();
    META_ASSERT_EQ<Unconst::To<const int>::type, int>::ASSERT();
}
