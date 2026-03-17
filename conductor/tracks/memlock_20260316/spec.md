# Specification: Implement Windows Memory Protection for Carrot Protocol

## Track Description
Implement a C++ wrapper for the `VirtualLock` and `VirtualUnlock` Windows APIs to ensure that sensitive cryptographic materials (shared secrets, view tags) in the Carrot protocol are pinned in physical RAM and never swapped to disk.

## Scope
- Implementation of a C++ class for RAII-style memory locking.
- Integration of the locking logic into Carrot's shared secret and view tag routines.
- Comprehensive unit testing for the memory-locking functionality.
- Verification of memory pinning using Windows diagnostic tools.

## Requirements
- Support for `VirtualLock` and `VirtualUnlock` Windows APIs.
- RAII-based resource management for automatic unlocking.
- Custom `secure_memset` to zero out memory before unlocking and freeing.
- Proper error handling for system-wide memory-locking limits.
