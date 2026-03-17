# Product Guidelines

## Development Philosophy
- **Security First:** Prioritize cryptographic integrity and data protection above all else.
- **Fail-Safe Design:** If a memory lock fails, the application should handle the error gracefully, ideally by aborting the sensitive operation or falling back to a pre-defined secure state.
- **Efficiency:** Minimize overhead when pinning memory, ensuring that only the necessary secrets are locked.

## Coding Style & Patterns
- **Explicit Memory Management:** Given the low-level nature of `VirtualLock`, memory management must be precise and explicit. Always balance locks with unlocks.
- **Zero-on-Deallocate:** All sensitive memory must be overwritten with zeros before being freed to prevent data leakage in RAM.
- **Abstraction:** Provide clean, well-documented wrappers for Windows-specific APIs to maintain codebase clarity.

## Testing & Verification
- **Functional Testing:** Verify that memory locking and unlocking works as expected across different Windows versions.
- **Security Auditing:** Routinely check for memory leaks and ensure that secrets are correctly zeroed out after use.
- **Negative Testing:** Ensure the system handles scenarios where memory cannot be locked (e.g., system-wide lock limits reached).

## Documentation
- **Clear Comments:** Every use of a low-level API must be accompanied by a comment explaining why it's used and how it contributes to the project's security goals.
- **Architecture Diagrams:** Maintain clear documentation of the data flow and memory lifecycle.
