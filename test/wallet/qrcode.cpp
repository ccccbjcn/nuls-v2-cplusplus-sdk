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

#include <cstdint>
#include <nuls/system.hpp>

using namespace bc::system;
using namespace bc::system::wallet;

BOOST_AUTO_TEST_SUITE(qrcode_tests)

#ifdef WITH_QRENCODE

BOOST_AUTO_TEST_CASE(qrcode__invoke__qrencode_data__success)
{
    static const uint8_t expected_data[]
    {
        0x03, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0xc1, 0xc1, 0xc1, 0xc1,
        0xc1, 0xc1, 0xc1, 0xc0, 0x84, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x02,
        0x03, 0x03, 0x03, 0x02, 0x03, 0xc0, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1,
        0xc1, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc0, 0x85, 0x02, 0x03,
        0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x02, 0x03, 0xc0, 0xc1,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0,
        0xc1, 0xc0, 0x84, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x03, 0xc0, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0, 0xc1, 0xc1,
        0xc0, 0xc1, 0xc1, 0xc1, 0xc0, 0xc1, 0xc0, 0x85, 0x03, 0x03, 0x02, 0x03,
        0x03, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0xc0, 0xc1, 0xc0, 0xc1,
        0xc1, 0xc1, 0xc0, 0xc1, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0, 0xc1, 0xc0,
        0x84, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03,
        0x03, 0xc0, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0, 0xc1, 0xc1, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc1, 0xc0, 0x85, 0x03, 0x02, 0x03, 0x03, 0x03, 0x02,
        0x03, 0x02, 0x02, 0x03, 0x02, 0x02, 0xc0, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc0, 0x91, 0x90,
        0x91, 0x90, 0x91, 0x90, 0x91, 0x90, 0x91, 0x90, 0x91, 0x90, 0x91, 0xc0,
        0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0x84, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x03, 0x02, 0x02, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0x85, 0x85, 0x85, 0x85, 0x85, 0x84, 0x91, 0x85, 0x85, 0x03, 0x02, 0x03,
        0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x85, 0x84, 0x85,
        0x84, 0x85, 0x84, 0x85, 0x84, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x90,
        0x03, 0x03, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03,
        0x03, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02,
        0x03, 0x02, 0x03, 0x03, 0x91, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02,
        0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03,
        0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x90, 0x02, 0x03,
        0x02, 0x02, 0x02, 0x03, 0x02, 0x03, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02,
        0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x02, 0x02, 0x03, 0x03,
        0x02, 0x03, 0x91, 0x02, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03,
        0x02, 0x03, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x02, 0x03, 0x02,
        0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x90, 0x02, 0x03, 0x03, 0x02,
        0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02,
        0x91, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03,
        0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02,
        0x02, 0x03, 0x02, 0x03, 0x02, 0x90, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02,
        0x02, 0x02, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03,
        0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x91, 0x02,
        0x03, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02,
        0x03, 0x02, 0x02, 0x90, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x03,
        0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x02, 0x03,
        0x03, 0x03, 0x03, 0x02, 0x03, 0x02, 0x02, 0x02, 0x91, 0x02, 0x02, 0x02,
        0x03, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03,
        0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03,
        0x03, 0x90, 0x02, 0x03, 0x03, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x02,
        0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x03, 0x02, 0x03, 0x03,
        0x03, 0x02, 0x03, 0x03, 0x03, 0x02, 0x91, 0x02, 0x02, 0x03, 0x02, 0x02,
        0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x02, 0xa1, 0xa1, 0xa1, 0xa1,
        0xa1, 0x02, 0x03, 0x03, 0x02, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0x81, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0xa1, 0xa0, 0xa0, 0xa0, 0xa1, 0x03, 0x03, 0x03, 0x03, 0xc1, 0xc1,
        0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc0, 0x85, 0x02, 0x03, 0x03, 0x03, 0x03,
        0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0xa1, 0xa0, 0xa1, 0xa0, 0xa1, 0x02,
        0x03, 0x02, 0x02, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc0, 0x84,
        0x02, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0xa1,
        0xa0, 0xa0, 0xa0, 0xa1, 0x02, 0x02, 0x03, 0x03, 0xc1, 0xc0, 0xc1, 0xc1,
        0xc1, 0xc0, 0xc1, 0xc0, 0x85, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x03,
        0x02, 0x03, 0x02, 0x02, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0x03, 0x03, 0x03,
        0x03, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0, 0xc1, 0xc0, 0x85, 0x03, 0x02,
        0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x02, 0x02,
        0x02, 0x03, 0x02, 0x03, 0x03, 0x03, 0xc1, 0xc0, 0xc1, 0xc1, 0xc1, 0xc0,
        0xc1, 0xc0, 0x85, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0xc1,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc0, 0x85, 0x02, 0x02, 0x02, 0x03,
        0x03, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03,
        0x02, 0x02, 0x03, 0x02, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc0,
        0x85, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03,
        0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02
    };

    static const auto expected_data_length = sizeof(expected_data) / sizeof(uint8_t);
    static const std::string address = "bitcoin:1L4M4obtbpexxuKpLrDimMEYWB2Rx2yzus";
    const auto encoded_qrcode = qr::encode(to_chunk(address));

    BOOST_REQUIRE_EQUAL(encoded_qrcode.size(), expected_data_length);
    BOOST_REQUIRE(std::memcmp(encoded_qrcode.data(), expected_data, expected_data_length) == 0);
}

#endif // WITH_QRENCODE

BOOST_AUTO_TEST_SUITE_END()
