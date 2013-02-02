/*
    Copyright (C) 2011 Hugo Arregui
    This file is part of the tm++ Library.

    All rights reserved.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. The name of the authors may not be used to endorse or promote products
       derived from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
    NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
    THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
