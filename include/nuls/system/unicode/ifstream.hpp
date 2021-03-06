﻿/**
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
#ifndef LIBNULS_SYSTEM_IFSTREAM_HPP
#define LIBNULS_SYSTEM_IFSTREAM_HPP

#include <fstream>
#include <string>
#include <nuls/system/define.hpp>

namespace libnuls {
namespace system {

/**
 * Use nuls::system::ifstream in place of std::ifstream.
 * This provides utf8 to utf16 path translation for Windows.
 */
class BC_API ifstream
  : public std::ifstream
{
public:
    /**
     * Construct nuls::system::ifstream.
     * @param[in]  path  The utf8 path to the file.
     * @param[in]  mode  The file opening mode.
     */
    ifstream(const std::string& path,
        std::ifstream::openmode mode=std::ifstream::in);
};

} // namespace system
} // namespace libnuls

#endif
