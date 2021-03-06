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
#ifndef LIBNULS_SYSTEM_WALLET_STEALTH_RECEIVER_HPP
#define LIBNULS_SYSTEM_WALLET_STEALTH_RECEIVER_HPP

#include <cstdint>
#include <nuls/system/define.hpp>
#include <nuls/system/math/elliptic_curve.hpp>
#include <nuls/system/utility/binary.hpp>
#include <nuls/system/wallet/payment_address.hpp>
#include <nuls/system/wallet/stealth_address.hpp>

namespace libnuls {
namespace system {
namespace wallet {

/// This class does not support multisignature stealth addresses.
class BC_API stealth_receiver
{
public:
    /// Constructors.
    stealth_receiver(const ec_secret& scan_private,
        const ec_secret& spend_private, const binary& filter,
        uint8_t version=payment_address::mainnet_p2kh);

    /// Caller must test after construct.
    operator bool() const;

    /// Get the stealth address.
    const wallet::stealth_address& stealth_address() const;

    /// Derive a payment address to compare against the blockchain.
    bool derive_address(payment_address& out_address,
        const ec_compressed& ephemeral_public) const;

    /// Once address is discovered, derive the private spend key.
    bool derive_private(ec_secret& out_private,
        const ec_compressed& ephemeral_public) const;

private:
    const uint8_t version_;
    const ec_secret scan_private_;
    const ec_secret spend_private_;
    ec_compressed spend_public_;
    wallet::stealth_address address_;
};

} // namespace wallet
} // namespace system
} // namespace libnuls

#endif
