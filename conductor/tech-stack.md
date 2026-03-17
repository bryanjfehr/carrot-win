# Tech Stack: Carrot Memory Security

## Core Language & Runtime
- **C++ (C++17 or later):** Necessary for low-level memory management and direct access to the Windows API.
- **Windows API:** Specifically using `memoryapi.h` for `VirtualLock` and `VirtualUnlock`.

## Cryptographic Libraries
- **Sodium (libsodium):** For handling shared secrets and other cryptographic primitives common in the Carrot protocol.
- **ZeroMQ (cppzmq):** If applicable for secure communication between wallet components.

## Development & Build Tools
- **CMake:** For cross-platform-compatible project configuration (with a focus on Windows/MSVC).
- **Microsoft Visual Studio / MSVC:** The primary compiler and development environment for Windows-native applications.
- **vcpkg:** For dependency management (libsodium, cppzmq, boost).

## Testing Frameworks
- **Google Test (gtest):** For unit and integration testing of the memory-locking wrappers.
- **Windows Driver Kit (WDK) Tools:** For advanced memory analysis and verification if needed.
