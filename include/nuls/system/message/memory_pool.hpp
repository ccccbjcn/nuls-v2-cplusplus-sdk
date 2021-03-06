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
#ifndef LIBNULS_SYSTEM_MESSAGE_MEMORY_POOL_HPP
#define LIBNULS_SYSTEM_MESSAGE_MEMORY_POOL_HPP

#include <istream>
#include <memory>
#include <string>
#include <nuls/system/define.hpp>
#include <nuls/system/utility/data.hpp>
#include <nuls/system/utility/reader.hpp>
#include <nuls/system/utility/writer.hpp>

namespace libnuls {
namespace system {
namespace message {

class BC_API memory_pool
{
public:
    typedef std::shared_ptr<memory_pool> ptr;
    typedef std::shared_ptr<const memory_pool> const_ptr;

    static memory_pool factory(uint32_t version, const data_chunk& data);
    static memory_pool factory(uint32_t version, std::istream& stream);
    static memory_pool factory(uint32_t version, reader& source);
    static size_t satoshi_fixed_size(uint32_t version);

    memory_pool();
    memory_pool(const memory_pool& other);
    memory_pool(memory_pool&& other);

    bool from_data(uint32_t version, const data_chunk& data);
    bool from_data(uint32_t version, std::istream& stream);
    bool from_data(uint32_t version, reader& source);
    data_chunk to_data(uint32_t version) const;
    void to_data(uint32_t version, std::ostream& stream) const;
    void to_data(uint32_t version, writer& sink) const;
    bool is_valid() const;
    void reset();
    size_t serialized_size(uint32_t version) const;

    static const std::string command;
    static const uint32_t version_minimum;
    static const uint32_t version_maximum;

protected:
    memory_pool(bool insufficient_version);

private:
    bool insufficient_version_;
};

} // namespace message
} // namespace system
} // namespace libnuls

#endif
