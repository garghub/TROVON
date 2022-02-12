static __always_inline void
rspin_until_writer_unlock(struct qrwlock *lock, u32 cnts)
{
while ((cnts & _QW_WMASK) == _QW_LOCKED) {
cpu_relax_lowlatency();
cnts = atomic_read_acquire(&lock->cnts);
}
}
void queued_read_lock_slowpath(struct qrwlock *lock, u32 cnts)
{
if (unlikely(in_interrupt())) {
rspin_until_writer_unlock(lock, cnts);
return;
}
atomic_sub(_QR_BIAS, &lock->cnts);
arch_spin_lock(&lock->lock);
cnts = atomic_add_return_acquire(_QR_BIAS, &lock->cnts) - _QR_BIAS;
rspin_until_writer_unlock(lock, cnts);
arch_spin_unlock(&lock->lock);
}
void queued_write_lock_slowpath(struct qrwlock *lock)
{
u32 cnts;
arch_spin_lock(&lock->lock);
if (!atomic_read(&lock->cnts) &&
(atomic_cmpxchg_acquire(&lock->cnts, 0, _QW_LOCKED) == 0))
goto unlock;
for (;;) {
struct __qrwlock *l = (struct __qrwlock *)lock;
if (!READ_ONCE(l->wmode) &&
(cmpxchg_relaxed(&l->wmode, 0, _QW_WAITING) == 0))
break;
cpu_relax_lowlatency();
}
for (;;) {
cnts = atomic_read(&lock->cnts);
if ((cnts == _QW_WAITING) &&
(atomic_cmpxchg_acquire(&lock->cnts, _QW_WAITING,
_QW_LOCKED) == _QW_WAITING))
break;
cpu_relax_lowlatency();
}
unlock:
arch_spin_unlock(&lock->lock);
}
