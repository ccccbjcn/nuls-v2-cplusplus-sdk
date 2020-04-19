///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 libnuls-system developers (see COPYING).
//
//        GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
//
///////////////////////////////////////////////////////////////////////////////
#ifndef LIBNULS_SYSTEM_HPP
#define LIBNULS_SYSTEM_HPP

/**
 * API Users: Include only this header. Direct use of other headers is fragile
 * and unsupported as header organization is subject to change.
 *
 * Maintainers: Do not include this header internal to this library.
 */

#include <nuls/system/compat.h>
#include <nuls/system/compat.hpp>
#include <nuls/system/constants.hpp>
#include <nuls/system/define.hpp>
#include <nuls/system/error.hpp>
#include <nuls/system/handlers.hpp>
#include <nuls/system/settings.hpp>
#include <nuls/system/version.hpp>
#include <nuls/system/chain/block.hpp>
#include <nuls/system/chain/block_filter.hpp>
#include <nuls/system/chain/chain_state.hpp>
#include <nuls/system/chain/compact.hpp>
#include <nuls/system/chain/header.hpp>
#include <nuls/system/chain/input.hpp>
#include <nuls/system/chain/input_point.hpp>
#include <nuls/system/chain/output.hpp>
#include <nuls/system/chain/output_point.hpp>
#include <nuls/system/chain/payment_record.hpp>
#include <nuls/system/chain/point.hpp>
#include <nuls/system/chain/point_value.hpp>
#include <nuls/system/chain/points_value.hpp>
#include <nuls/system/chain/script.hpp>
#include <nuls/system/chain/stealth_record.hpp>
#include <nuls/system/chain/transaction.hpp>
#include <nuls/system/chain/witness.hpp>
#include <nuls/system/config/authority.hpp>
#include <nuls/system/config/base16.hpp>
#include <nuls/system/config/base2.hpp>
#include <nuls/system/config/base58.hpp>
#include <nuls/system/config/base64.hpp>
#include <nuls/system/config/block.hpp>
#include <nuls/system/config/checkpoint.hpp>
#include <nuls/system/config/compact_filter.hpp>
#include <nuls/system/config/directory.hpp>
#include <nuls/system/config/endpoint.hpp>
#include <nuls/system/config/hash160.hpp>
#include <nuls/system/config/hash256.hpp>
#include <nuls/system/config/header.hpp>
#include <nuls/system/config/input.hpp>
#include <nuls/system/config/output.hpp>
#include <nuls/system/config/parameter.hpp>
#include <nuls/system/config/parser.hpp>
#include <nuls/system/config/point.hpp>
#include <nuls/system/config/printer.hpp>
#include <nuls/system/config/script.hpp>
#include <nuls/system/config/settings.hpp>
#include <nuls/system/config/sodium.hpp>
#include <nuls/system/config/transaction.hpp>
#include <nuls/system/formats/base_10.hpp>
#include <nuls/system/formats/base_16.hpp>
#include <nuls/system/formats/base_32.hpp>
#include <nuls/system/formats/base_58.hpp>
#include <nuls/system/formats/base_64.hpp>
#include <nuls/system/formats/base_85.hpp>
#include <nuls/system/log/attributes.hpp>
#include <nuls/system/log/file_char_traits.hpp>
#include <nuls/system/log/file_collector.hpp>
#include <nuls/system/log/file_collector_repository.hpp>
#include <nuls/system/log/file_counter_formatter.hpp>
#include <nuls/system/log/rotable_file.hpp>
#include <nuls/system/log/severity.hpp>
#include <nuls/system/log/sink.hpp>
#include <nuls/system/log/source.hpp>
#include <nuls/system/log/statsd_sink.hpp>
#include <nuls/system/log/statsd_source.hpp>
#include <nuls/system/log/udp_client_sink.hpp>
#include <nuls/system/log/features/counter.hpp>
#include <nuls/system/log/features/gauge.hpp>
#include <nuls/system/log/features/metric.hpp>
#include <nuls/system/log/features/rate.hpp>
#include <nuls/system/log/features/timer.hpp>
#include <nuls/system/machine/interpreter.hpp>
#include <nuls/system/machine/number.hpp>
#include <nuls/system/machine/opcode.hpp>
#include <nuls/system/machine/operation.hpp>
#include <nuls/system/machine/program.hpp>
#include <nuls/system/machine/rule_fork.hpp>
#include <nuls/system/machine/script_pattern.hpp>
#include <nuls/system/machine/script_version.hpp>
#include <nuls/system/machine/sighash_algorithm.hpp>
#include <nuls/system/math/checksum.hpp>
#include <nuls/system/math/crypto.hpp>
#include <nuls/system/math/ec_point.hpp>
#include <nuls/system/math/ec_scalar.hpp>
#include <nuls/system/math/elliptic_curve.hpp>
#include <nuls/system/math/golomb_coded_sets.hpp>
#include <nuls/system/math/hash.hpp>
#include <nuls/system/math/limits.hpp>
#include <nuls/system/math/ring_signature.hpp>
#include <nuls/system/math/siphash.hpp>
#include <nuls/system/math/stealth.hpp>
#include <nuls/system/message/address.hpp>
#include <nuls/system/message/alert.hpp>
#include <nuls/system/message/alert_payload.hpp>
#include <nuls/system/message/block.hpp>
#include <nuls/system/message/block_transactions.hpp>
#include <nuls/system/message/compact_block.hpp>
#include <nuls/system/message/compact_filter.hpp>
#include <nuls/system/message/compact_filter_checkpoint.hpp>
#include <nuls/system/message/compact_filter_headers.hpp>
#include <nuls/system/message/fee_filter.hpp>
#include <nuls/system/message/filter_add.hpp>
#include <nuls/system/message/filter_clear.hpp>
#include <nuls/system/message/filter_load.hpp>
#include <nuls/system/message/get_address.hpp>
#include <nuls/system/message/get_block_transactions.hpp>
#include <nuls/system/message/get_blocks.hpp>
#include <nuls/system/message/get_compact_filter_checkpoint.hpp>
#include <nuls/system/message/get_compact_filter_headers.hpp>
#include <nuls/system/message/get_compact_filters.hpp>
#include <nuls/system/message/get_data.hpp>
#include <nuls/system/message/get_headers.hpp>
#include <nuls/system/message/header.hpp>
#include <nuls/system/message/headers.hpp>
#include <nuls/system/message/heading.hpp>
#include <nuls/system/message/inventory.hpp>
#include <nuls/system/message/inventory_vector.hpp>
#include <nuls/system/message/memory_pool.hpp>
#include <nuls/system/message/merkle_block.hpp>
#include <nuls/system/message/messages.hpp>
#include <nuls/system/message/network_address.hpp>
#include <nuls/system/message/not_found.hpp>
#include <nuls/system/message/ping.hpp>
#include <nuls/system/message/pong.hpp>
#include <nuls/system/message/prefilled_transaction.hpp>
#include <nuls/system/message/reject.hpp>
#include <nuls/system/message/send_compact.hpp>
#include <nuls/system/message/send_headers.hpp>
#include <nuls/system/message/transaction.hpp>
#include <nuls/system/message/verack.hpp>
#include <nuls/system/message/version.hpp>
#include <nuls/system/unicode/console_streambuf.hpp>
#include <nuls/system/unicode/file_lock.hpp>
#include <nuls/system/unicode/ifstream.hpp>
#include <nuls/system/unicode/ofstream.hpp>
#include <nuls/system/unicode/unicode.hpp>
#include <nuls/system/unicode/unicode_istream.hpp>
#include <nuls/system/unicode/unicode_ostream.hpp>
#include <nuls/system/unicode/unicode_streambuf.hpp>
#include <nuls/system/utility/array_slice.hpp>
#include <nuls/system/utility/asio.hpp>
#include <nuls/system/utility/assert.hpp>
#include <nuls/system/utility/atomic.hpp>
#include <nuls/system/utility/binary.hpp>
#include <nuls/system/utility/bit_reader.hpp>
#include <nuls/system/utility/bit_writer.hpp>
#include <nuls/system/utility/collection.hpp>
#include <nuls/system/utility/color.hpp>
#include <nuls/system/utility/conditional_lock.hpp>
#include <nuls/system/utility/container_sink.hpp>
#include <nuls/system/utility/container_source.hpp>
#include <nuls/system/utility/data.hpp>
#include <nuls/system/utility/deadline.hpp>
#include <nuls/system/utility/decorator.hpp>
#include <nuls/system/utility/delegates.hpp>
#include <nuls/system/utility/deserializer.hpp>
#include <nuls/system/utility/dispatcher.hpp>
#include <nuls/system/utility/enable_shared_from_base.hpp>
#include <nuls/system/utility/endian.hpp>
#include <nuls/system/utility/exceptions.hpp>
#include <nuls/system/utility/flush_lock.hpp>
#include <nuls/system/utility/interprocess_lock.hpp>
#include <nuls/system/utility/istream_bit_reader.hpp>
#include <nuls/system/utility/istream_reader.hpp>
#include <nuls/system/utility/monitor.hpp>
#include <nuls/system/utility/neutrino_filter.hpp>
#include <nuls/system/utility/noncopyable.hpp>
#include <nuls/system/utility/ostream_bit_writer.hpp>
#include <nuls/system/utility/ostream_writer.hpp>
#include <nuls/system/utility/pending.hpp>
#include <nuls/system/utility/png.hpp>
#include <nuls/system/utility/prioritized_mutex.hpp>
#include <nuls/system/utility/property_tree.hpp>
#include <nuls/system/utility/pseudo_random.hpp>
#include <nuls/system/utility/reader.hpp>
#include <nuls/system/utility/resubscriber.hpp>
#include <nuls/system/utility/scope_lock.hpp>
#include <nuls/system/utility/sequencer.hpp>
#include <nuls/system/utility/sequential_lock.hpp>
#include <nuls/system/utility/serializer.hpp>
#include <nuls/system/utility/socket.hpp>
#include <nuls/system/utility/string.hpp>
#include <nuls/system/utility/subscriber.hpp>
#include <nuls/system/utility/synchronizer.hpp>
#include <nuls/system/utility/thread.hpp>
#include <nuls/system/utility/threadpool.hpp>
#include <nuls/system/utility/timer.hpp>
#include <nuls/system/utility/track.hpp>
#include <nuls/system/utility/work.hpp>
#include <nuls/system/utility/writer.hpp>
#include <nuls/system/wallet/bitcoin_uri.hpp>
#include <nuls/system/wallet/dictionary.hpp>
#include <nuls/system/wallet/ec_private.hpp>
#include <nuls/system/wallet/ec_public.hpp>
#include <nuls/system/wallet/ek_private.hpp>
#include <nuls/system/wallet/ek_public.hpp>
#include <nuls/system/wallet/ek_token.hpp>
#include <nuls/system/wallet/electrum.hpp>
#include <nuls/system/wallet/electrum_dictionary.hpp>
#include <nuls/system/wallet/encrypted_keys.hpp>
#include <nuls/system/wallet/hd_private.hpp>
#include <nuls/system/wallet/hd_public.hpp>
#include <nuls/system/wallet/message.hpp>
#include <nuls/system/wallet/mini_keys.hpp>
#include <nuls/system/wallet/mnemonic.hpp>
#include <nuls/system/wallet/payment_address.hpp>
#include <nuls/system/wallet/qrcode.hpp>
#include <nuls/system/wallet/select_outputs.hpp>
#include <nuls/system/wallet/stealth_address.hpp>
#include <nuls/system/wallet/stealth_receiver.hpp>
#include <nuls/system/wallet/stealth_sender.hpp>
#include <nuls/system/wallet/uri.hpp>
#include <nuls/system/wallet/uri_reader.hpp>
#include <nuls/system/wallet/witness_address.hpp>

#include <nuls/system/sdk/address.hpp>
#include <nuls/system/sdk/NulsSDKTool.hpp>

#include <nuls/system/model/account.hpp>

#endif
