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

#ifndef TARGETS_H
#define TARGETS_H

template <class T>
struct Type
{
    template <class From>
    struct To
    {
        typedef T type;
    };
};

struct Unconst
{
    template <class From>
    struct To
    {
        typedef typename std::remove_const<From>::type type;
    };
};

struct Const
{
    template <class From>
    struct To
    {
        typedef typename std::add_const<From>::type type;
    };
};
#endif
