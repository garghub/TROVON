static inline void\r\ndefault_spin_lock_flags(arch_spinlock_t *lock, unsigned long flags)\r\n{\r\narch_spin_lock(lock);\r\n}
