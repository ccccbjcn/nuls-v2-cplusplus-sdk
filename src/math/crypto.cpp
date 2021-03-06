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
#include <nuls/system/math/crypto.hpp>

#include <nuls/system/math/elliptic_curve.hpp>
#include <nuls/system/math/hash.hpp>
#include <nuls/system/utility/assert.hpp>
#include <nuls/system/utility/data.hpp>
#include "../math/external/aes256.h"

namespace libnuls {
namespace system {

void aes256_encrypt(const aes_secret& key, aes_block& block)
{
    aes256_context context;
    aes256_init(&context, key.data());
    aes256_encrypt_ecb(&context, block.data());
    aes256_done(&context);
}

void aes256_decrypt(const aes_secret& key, aes_block& block)
{
    aes256_context context;
    aes256_init(&context, key.data());
    aes256_decrypt_ecb(&context, block.data());
    aes256_done(&context);
}

} // namespace system
} // namespace libnuls
