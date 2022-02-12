static int __used atomic_dec_and_lock_1(atomic_t *atomic, spinlock_t *lock)
{
spin_lock(lock);
if (atomic_dec_and_test(atomic))
return 1;
spin_unlock(lock);
return 0;
}
