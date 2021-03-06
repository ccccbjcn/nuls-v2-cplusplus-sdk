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
#ifndef LIBNULS_SYSTEM_LOG_SOURCE_HPP
#define LIBNULS_SYSTEM_LOG_SOURCE_HPP

#include <string>
#include <boost/log/attributes/clock.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <nuls/system/define.hpp>
#include <nuls/system/log/attributes.hpp>
#include <nuls/system/log/severity.hpp>

namespace libnuls {
namespace system {
namespace log {

typedef boost::log::sources::severity_channel_logger_mt<severity, std::string>
    severity_source;

BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(source, severity_source)
{
    static const auto name = attributes::timestamp.get_name();
    severity_source logger;
    logger.add_attribute(name, boost::log::attributes::utc_clock());
    return logger;
}

#define BC_LOG_SEVERITY(id, level) \
    BOOST_LOG_CHANNEL_SEV(nuls::system::log::source::get(), id,\
    nuls::system::log::severity::level)

#define LOG_VERBOSE(module) BC_LOG_SEVERITY(module, verbose)
#define LOG_DEBUG(module) BC_LOG_SEVERITY(module, debug)
#define LOG_INFO(module) BC_LOG_SEVERITY(module, info)
#define LOG_WARNING(module) BC_LOG_SEVERITY(module, warning)
#define LOG_ERROR(module) BC_LOG_SEVERITY(module, error)
#define LOG_FATAL(module) BC_LOG_SEVERITY(module, fatal)

} // namespace log
} // namespace system
} // namespace libnuls

#endif
