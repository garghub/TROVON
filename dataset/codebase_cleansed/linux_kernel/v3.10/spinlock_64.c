static inline u32 arch_spin_read_noalloc(void *lock)
{
return atomic_cmpxchg((atomic_t *)lock, -1, -1);
}
void arch_spin_lock_slow(arch_spinlock_t *lock, u32 my_ticket)
{
if (unlikely(my_ticket & __ARCH_SPIN_NEXT_OVERFLOW)) {
__insn_fetchand4(&lock->lock, ~__ARCH_SPIN_NEXT_OVERFLOW);
my_ticket &= ~__ARCH_SPIN_NEXT_OVERFLOW;
}
for (;;) {
u32 val = arch_spin_read_noalloc(lock);
u32 delta = my_ticket - arch_spin_current(val);
if (delta == 0)
return;
relax((128 / CYCLES_PER_RELAX_LOOP) * delta);
}
}
int arch_spin_trylock(arch_spinlock_t *lock)
{
u32 val = arch_spin_read_noalloc(lock);
if (unlikely(arch_spin_current(val) != arch_spin_next(val)))
return 0;
return cmpxchg(&lock->lock, val, (val + 1) & ~__ARCH_SPIN_NEXT_OVERFLOW)
== val;
}
void arch_spin_unlock_wait(arch_spinlock_t *lock)
{
u32 iterations = 0;
while (arch_spin_is_locked(lock))
delay_backoff(iterations++);
}
void __read_lock_failed(arch_rwlock_t *rw)
{
u32 val;
int iterations = 0;
do {
delay_backoff(iterations++);
val = __insn_fetchaddgez4(&rw->lock, 1);
} while (unlikely(arch_write_val_locked(val)));
}
void __write_lock_failed(arch_rwlock_t *rw, u32 val)
{
int iterations = 0;
do {
if (!arch_write_val_locked(val))
val = __insn_fetchand4(&rw->lock, ~__WRITE_LOCK_BIT);
delay_backoff(iterations++);
val = __insn_fetchor4(&rw->lock, __WRITE_LOCK_BIT);
} while (val != 0);
}
