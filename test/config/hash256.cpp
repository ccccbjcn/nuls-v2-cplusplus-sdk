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
#include <boost/test/unit_test.hpp>
#include <boost/program_options.hpp>
#include <nuls/system.hpp>

using namespace nuls::system;
using namespace nuls::system::config;

BOOST_AUTO_TEST_SUITE(hash256_tests)

BOOST_AUTO_TEST_SUITE(hash256__construct)

BOOST_AUTO_TEST_CASE(hash256__construct__default__null_hash)
{
    const hash256 uninitialized_hash;
    const auto expectation = encode_hash(null_hash);
    const auto result = encode_hash(uninitialized_hash);
    BOOST_REQUIRE_EQUAL(expectation, result);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
