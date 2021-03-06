/**
 * Copyright (c) 2020 libnuls developers (see AUTHORS)
 *
 * This file is part of libnuls.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <nuls/system/unicode/unicode_istream.hpp>

#include <cstddef>
#include <iostream>
#include <nuls/system/unicode/unicode_streambuf.hpp>

namespace libnuls {
namespace system {

unicode_istream::unicode_istream(
#ifdef _MSC_VER
    std::istream&, std::wistream& wide_stream, size_t size)
#else
    std::istream& narrow_stream, std::wistream&, size_t)
#endif
#ifdef _MSC_VER
  : std::istream(new unicode_streambuf(wide_stream.rdbuf(), size))
#else
  : std::istream(narrow_stream.rdbuf())
#endif
{
}

unicode_istream::~unicode_istream()
{
#ifdef _MSC_VER
    delete rdbuf();
#endif
}

} // namespace system
} // namespace libnuls
