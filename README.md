#TypeMapperPP

C++ type mapper library for C++0x

##Usage:

The type mapper is configured via TypeMapper class:

    TypeMapper<TARGET, PREDICATES....>

Example:

    typedef TypeMapper<Type<double>, is_integral> IntegralToDoubleMapper;

See tests/tm_pp_test.cpp for more examples.

##Target:

    Type<T>

Maps to type T.

    Uconst::To<T>

Maps to T with const attr removed.

    Const::To<T>

Maps to const T.

See tests/targets_test.cpp for more examples.

##Predicate:

    is_pointer<T>

    is_integral<T>

    is_const<T>

    is_fundamental<T>

    is_same<T>

    is_reference<T>

    is_equal<T>

See tests/predicates_test.cpp for more examples.
