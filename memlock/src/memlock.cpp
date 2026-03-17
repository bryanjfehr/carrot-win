#include <memlock/memlock.hpp>

namespace memlock {

void secure_memset(void* ptr, int value, size_t size) {
    // Placeholder
}

bool lock_memory(void* ptr, size_t size) {
    // Placeholder
    return false;
}

bool unlock_memory(void* ptr, size_t size) {
    // Placeholder
    return false;
}

MemoryLock::MemoryLock(void* ptr, size_t size) : m_ptr(ptr), m_size(size), m_locked(false) {
    m_locked = lock_memory(ptr, size);
}

MemoryLock::~MemoryLock() {
    if (m_locked) {
        secure_memset(m_ptr, 0, m_size);
        unlock_memory(m_ptr, m_size);
    }
}

} // namespace memlock
