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
*/

#ifndef UTILS_H
#define UTILS_H

namespace tm_pp
{

template <bool COND, class T, class F>
struct Select
{
    typedef F result;
};

template <class T, class F>
struct Select<true, T, F>
{
    typedef T result;
};

template <template <class> class... Predicates>
struct And
{
    template <class T>
    struct Predicate
    {
        enum { value = true };
    };
};

template <template <class> class Pred, template<class> class... Predicates>
struct And<Pred, Predicates...>
{
    template <class T>
    struct Predicate
    {
        enum { value = Pred<T>::value && And<Predicates...>::template Predicate<T>::value };
    };
};

}
#endif
