#include <gtest/gtest.h>
#include <memlock/memlock.hpp>

TEST(MemlockTest, LockMemory) {
    char data[1024] = {0};
    EXPECT_TRUE(memlock::lock_memory(data, sizeof(data)));
    EXPECT_TRUE(memlock::unlock_memory(data, sizeof(data)));
}

TEST(MemlockTest, RAII_Lock) {
    char data[1024] = {0};
    {
        memlock::MemoryLock lock(data, sizeof(data));
        EXPECT_TRUE(lock.is_locked());
    }
}

TEST(MemlockTest, SecureMemset) {
    char data[4] = {1, 2, 3, 4};
    memlock::secure_memset(data, 0, sizeof(data));
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(data[i], 0);
    }

    char data2[4] = {0, 0, 0, 0};
    memlock::secure_memset(data2, 0xFF, sizeof(data2));
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ((unsigned char)data2[i], 0xFF);
    }
}
