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
