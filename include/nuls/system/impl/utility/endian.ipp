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
#ifndef LIBNULS_SYSTEM_ENDIAN_IPP
#define LIBNULS_SYSTEM_ENDIAN_IPP

#include <type_traits>

namespace libnuls {
namespace system {

#define VERIFY_UNSIGNED(T) static_assert(std::is_unsigned<T>::value, \
    "The endian functions only work on unsigned types")

template <typename Integer, typename Iterator>
Integer from_big_endian(Iterator start, const Iterator end)
{
    VERIFY_UNSIGNED(Integer);
    Integer out = 0;
    size_t index = sizeof(Integer);

    while (0 < index && start != end)
        out |= static_cast<Integer>(*start++) << (8 * --index);

    return out;
}

template <typename Integer, typename Iterator>
Integer from_little_endian(Iterator start, const Iterator end)
{
    //// TODO: Type traits does not work for uint256_t.
    ////VERIFY_UNSIGNED(Integer);
    Integer out = 0;
    size_t index = 0;

    while (index < sizeof(Integer) && start != end)
        out |= static_cast<Integer>(*start++) << (8 * index++);

    return out;
}

template <typename Integer, typename Iterator>
Integer from_big_endian_unsafe(Iterator start)
{
    VERIFY_UNSIGNED(Integer);
    Integer out = 0;
    size_t index = sizeof(Integer);

    while (0 < index)
        out |= static_cast<Integer>(*start++) << (8 * --index);

    return out;
}

template <typename Integer, typename Iterator>
Integer from_little_endian_unsafe(Iterator start)
{
    VERIFY_UNSIGNED(Integer);
    Integer out = 0;
    size_t index = 0;

    while (index < sizeof(Integer))
        out |= static_cast<Integer>(*start++) << (8 * index++);

    return out;
}

template <typename Integer>
Integer from_big_endian_stream_unsafe(std::istream& stream)
{
    VERIFY_UNSIGNED(Integer);
    Integer out = 0;

    for (size_t index = sizeof(Integer); (index > 0) && stream; index--)
    {
        uint8_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof value);
        out |= static_cast<Integer>(value) << (8 * (index - 1));
    }

    return out;
}

template <typename Integer>
Integer from_little_endian_stream_unsafe(std::istream& stream)
{
    VERIFY_UNSIGNED(Integer);
    Integer out = 0;

    for (size_t index = 0; (index < sizeof(Integer)) && stream; index++)
    {
        uint8_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof value);
        out |= static_cast<Integer>(value) << (8 * index);
    }

    return out;
}

template <typename Integer>
byte_array<sizeof(Integer)> to_big_endian(Integer value)
{
    VERIFY_UNSIGNED(Integer);
    byte_array<sizeof(Integer)> out;

    for (auto it = out.rbegin(); it != out.rend(); ++it)
    {
        *it = static_cast<uint8_t>(value);
        value >>= 8;
    }

    return out;
}

template <typename Integer>
byte_array<sizeof(Integer)> to_little_endian(Integer value)
{
    VERIFY_UNSIGNED(Integer);
    byte_array<sizeof(Integer)> out;

    for (auto it = out.begin(); it != out.end(); ++it)
    {
        *it = static_cast<uint8_t>(value);
        value >>= 8;
    }

    return out;
}

#undef VERIFY_UNSIGNED

} // namespace system
} // namespace libnuls

#endif

