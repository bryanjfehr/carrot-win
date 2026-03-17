#pragma once

#include <vector>
#include <string>
#include <array>
#include <memlock/memlock.hpp>

namespace carrot {

using Bytes32 = std::array<unsigned char, 32>;
using Bytes64 = std::array<unsigned char, 64>;
using Bytes = std::vector<unsigned char>;

/**
 * @brief Computes the context-bound shared secret s_sr_ctx.
 * @param s_sr The base shared secret.
 * @param D_e The ephemeral public key.
 * @param input_context The input context.
 * @return The context-bound shared secret.
 */
Bytes32 compute_s_sr_ctx(const Bytes32& s_sr, const Bytes32& D_e, const Bytes& input_context);

/**
 * @brief Computes the view tag vt.
 * @param s_sr The base shared secret.
 * @param input_context The input context.
 * @param K_o The output public key.
 * @return The 3-byte view tag.
 */
std::array<unsigned char, 3> compute_view_tag(const Bytes32& s_sr, const Bytes& input_context, const Bytes32& K_o);

/**
 * @brief Performs the enote scan process.
 * @param k_v The private view key.
 * @param D_e The ephemeral public key.
 * @param K_o The output public key.
 * @param input_context The input context.
 * @param vt The expected view tag.
 * @return True if the scan is successful.
 */
bool scan_enote(const Bytes32& k_v, const Bytes32& D_e, const Bytes32& K_o, const Bytes& input_context, const std::array<unsigned char, 3>& vt);

} // namespace carrot
