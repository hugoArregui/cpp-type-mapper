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

#ifndef TM_PP_H
#define TM_PP_H

#include "targets.h"
#include "utils.h"

namespace tm_pp
{

template <class Target, template <class> class... Predicates>
struct TypeMapper
{
    template<class From>
    struct Map
    {
        typedef From type;
    };
};

template <class Target, template <class> class Predicate, template<class> class... Predicates>
struct TypeMapper<Target, Predicate, Predicates...>
{
    template<class From>
    struct Map
    {
        typedef typename TypeMapper<Target, Predicates...>::template Map<From>::type Else;
        typedef typename Target::template To<From>::type To;
        typedef typename Select<Predicate<From>::value, To, Else>::result type;
    };
};

template <class... Mapper>
struct CompoundMapper
{
    template<class From>
    struct Map
    {
        typedef From type;
    };
};

template <class Mapper, class... Mappers>
struct CompoundMapper<Mapper, Mappers...>
{
    template<class From>
    struct Map
    {
        typedef typename Mapper::template Map<From>::type Tmp;
        typedef typename CompoundMapper<Mappers...>::template Map<From>::type IfTrue;
        typedef typename Select<std::is_same<From, Tmp>::value, IfTrue, Tmp>::result type;
    };
};
}
#endif
