static inline void
default_spin_lock_flags(arch_spinlock_t *lock, unsigned long flags)
{
arch_spin_lock(lock);
}
