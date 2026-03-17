#pragma once

#include <stddef.h>

namespace memlock {

/**
 * @brief Zero out memory in a way that the compiler cannot optimize away.
 */
void secure_memset(void* ptr, int value, size_t size);

/**
 * @brief Locks a memory region into physical RAM to prevent it from being paged to disk.
 */
bool lock_memory(void* ptr, size_t size);

/**
 * @brief Unlocks a previously locked memory region.
 */
bool unlock_memory(void* ptr, size_t size);

/**
 * @brief RAII class for memory locking.
 */
class MemoryLock {
public:
    MemoryLock(void* ptr, size_t size);
    ~MemoryLock();

    bool is_locked() const { return m_locked; }

private:
    void* m_ptr;
    size_t m_size;
    bool m_locked;
};

} // namespace memlock
