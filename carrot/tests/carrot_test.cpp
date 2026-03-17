#include <gtest/gtest.h>
#include <carrot/carrot.hpp>
#include <sodium.h>

TEST(CarrotTest, ScanEnote_Correct) {
    ASSERT_GE(sodium_init(), 0);

    carrot::Bytes32 k_v; // Private view key
    carrot::Bytes32 D_e; // Ephemeral pubkey
    carrot::Bytes32 K_o; // Output pubkey
    carrot::Bytes input_context = { 'C', 0, 0, 0 }; // Coinbase context

    // Random keys
    crypto_core_ed25519_scalar_random(k_v.data());
    carrot::Bytes32 d_e;
    crypto_core_ed25519_scalar_random(d_e.data());
    
    // Compute D_e = d_e * B (Curve25519)
    ASSERT_EQ(crypto_scalarmult_curve25519_base(D_e.data(), d_e.data()), 0);

    // Compute s_sr = d_e * ConvertPointE(K_v) which is same as k_v * D_e
    carrot::Bytes32 s_sr;
    ASSERT_EQ(crypto_scalarmult_curve25519(s_sr.data(), k_v.data(), D_e.data()), 0);

    // Compute K_o (dummy)
    crypto_core_ed25519_random(K_o.data());

    // Compute expected view tag
    auto vt = carrot::compute_view_tag(s_sr, input_context, K_o);

    // Scan
    EXPECT_TRUE(carrot::scan_enote(k_v, D_e, K_o, input_context, vt));
}

TEST(CarrotTest, ScanEnote_WrongVT) {
    ASSERT_GE(sodium_init(), 0);

    carrot::Bytes32 k_v;
    carrot::Bytes32 D_e;
    carrot::Bytes32 K_o;
    carrot::Bytes input_context = { 'C', 0, 0, 0 };

    crypto_core_ed25519_scalar_random(k_v.data());
    carrot::Bytes32 d_e;
    crypto_core_ed25519_scalar_random(d_e.data());
    ASSERT_EQ(crypto_scalarmult_curve25519_base(D_e.data(), d_e.data()), 0);
    crypto_core_ed25519_random(K_o.data());

    std::array<unsigned char, 3> vt = { 0, 0, 0 };

    // Should fail with high probability (1 - 1/2^24)
    EXPECT_FALSE(carrot::scan_enote(k_v, D_e, K_o, input_context, vt));
}
