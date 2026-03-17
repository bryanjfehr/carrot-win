#include <memlock/memlock.hpp>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memoryapi.h>

namespace memlock {

void secure_memset(void* ptr, int value, size_t size) {
    if (ptr && size > 0) {
        // Use SecureZeroMemory for zeroing, or a simple volatile loop for other values
        if (value == 0) {
            SecureZeroMemory(ptr, size);
        } else {
            volatile unsigned char* vptr = (volatile unsigned char*)ptr;
            while (size--) {
                *vptr++ = (unsigned char)value;
            }
        }
    }
}

bool lock_memory(void* ptr, size_t size) {
    if (!ptr || size == 0) return false;
    return VirtualLock(ptr, size) != 0;
}

bool unlock_memory(void* ptr, size_t size) {
    if (!ptr || size == 0) return false;
    return VirtualUnlock(ptr, size) != 0;
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
