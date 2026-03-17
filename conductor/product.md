# Initial Concept

Analyze the Carrot protocol integration. Locate the specific routines where the wallet calculates the shared secret and evaluates the cryptographic view tags. Wrap the memory arrays holding these deciphered view tags and secrets in native Windows memory protection directives, specifically invoking the VirtualLock API function. Ensure this pins the sensitive data strictly in physical RAM, unconditionally preventing the OS from writing it to persistent storage or the paging file.

---

# Product Definition: Carrot Protocol Memory Security Enhancements

## Vision
Fortify the Carrot protocol's privacy-preserving mechanisms by ensuring that sensitive cryptographic materials—specifically shared secrets and view tags—never leave physical memory. This project provides a low-level Windows memory protection implementation that eliminates the risk of these secrets being leaked to persistent storage via the OS paging file or crash dumps.

## Goals
- **Memory Pinning:** Use Windows-native `VirtualLock` to lock sensitive memory regions in physical RAM.
- **Leak Prevention:** Prevent the operating system from swapping cryptographic view tags and shared secrets to disk.
- **Protocol Integrity:** Integrate these protections seamlessly into the existing Carrot wallet routines without degrading performance or reliability.
- **Security Assurance:** Provide a robust layer of defense against forensic disk analysis and swap-file-based data exfiltration.

## Target Users
- **Privacy-Conscious Users:** Individuals who require maximum protection for their transaction metadata and viewing keys.
- **Wallet Developers:** Developers building on the Carrot protocol who need a reference implementation for secure memory handling on Windows.

## Key Features
- **Automatic Memory Locking:** Routines that automatically identify and lock memory allocated for shared secret computation.
- **View Tag Protection:** Specialized handling for cryptographic view tags during the evaluation phase.
- **Safe Memory Deallocation:** Ensuring memory is properly unlocked and zeroed out before being returned to the system pool.
- **Windows Integration:** Optimized specifically for the Windows API (`VirtualLock`, `VirtualUnlock`).
