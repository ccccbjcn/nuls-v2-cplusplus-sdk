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
#ifndef LIBNULS_SYSTEM_MESSAGE_HEADERS_HPP
#define LIBNULS_SYSTEM_MESSAGE_HEADERS_HPP

#include <cstdint>
#include <initializer_list>
#include <istream>
#include <memory>
#include <string>
#include <nuls/system/define.hpp>
#include <nuls/system/math/hash.hpp>
#include <nuls/system/message/header.hpp>
#include <nuls/system/message/inventory.hpp>
#include <nuls/system/message/inventory_vector.hpp>
#include <nuls/system/utility/data.hpp>
#include <nuls/system/utility/reader.hpp>
#include <nuls/system/utility/writer.hpp>

namespace libnuls {
namespace system {
namespace message {

class BC_API headers
{
public:
    typedef std::shared_ptr<headers> ptr;
    typedef std::shared_ptr<const headers> const_ptr;

    static headers factory(uint32_t version, const data_chunk& data);
    static headers factory(uint32_t version, std::istream& stream);
    static headers factory(uint32_t version, reader& source);

    headers();
    headers(const header::list& values);
    headers(header::list&& values);
    headers(const std::initializer_list<header>& values);
    headers(const headers& other);
    headers(headers&& other);

    header::list& elements();
    const header::list& elements() const;
    void set_elements(const header::list& values);
    void set_elements(header::list&& values);

    bool is_sequential() const;
    void to_hashes(hash_list& out) const;
    void to_inventory(inventory_vector::list& out,
        inventory::type_id type) const;

    bool from_data(uint32_t version, const data_chunk& data);
    bool from_data(uint32_t version, std::istream& stream);
    bool from_data(uint32_t version, reader& source);
    data_chunk to_data(uint32_t version) const;
    void to_data(uint32_t version, std::ostream& stream) const;
    void to_data(uint32_t version, writer& sink) const;
    bool is_valid() const;
    void reset();
    size_t serialized_size(uint32_t version) const;

    // This class is move assignable but not copy assignable.
    headers& operator=(headers&& other);
    void operator=(const headers&) = delete;

    bool operator==(const headers& other) const;
    bool operator!=(const headers& other) const;

    static const std::string command;
    static const uint32_t version_minimum;
    static const uint32_t version_maximum;

private:
    header::list elements_;
};

} // namespace message
} // namespace system
} // namespace libnuls

#endif
