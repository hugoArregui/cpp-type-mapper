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
