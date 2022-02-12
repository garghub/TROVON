static __always_inline void
rspin_until_writer_unlock(struct qrwlock *lock, u32 cnts)
{
while ((cnts & _QW_WMASK) == _QW_LOCKED) {
cpu_relax_lowlatency();
cnts = smp_load_acquire((u32 *)&lock->cnts);
}
}
void queue_read_lock_slowpath(struct qrwlock *lock)
{
u32 cnts;
if (unlikely(in_interrupt())) {
cnts = smp_load_acquire((u32 *)&lock->cnts);
rspin_until_writer_unlock(lock, cnts);
return;
}
atomic_sub(_QR_BIAS, &lock->cnts);
arch_spin_lock(&lock->lock);
while (atomic_read(&lock->cnts) & _QW_WMASK)
cpu_relax_lowlatency();
cnts = atomic_add_return(_QR_BIAS, &lock->cnts) - _QR_BIAS;
rspin_until_writer_unlock(lock, cnts);
arch_spin_unlock(&lock->lock);
}
void queue_write_lock_slowpath(struct qrwlock *lock)
{
u32 cnts;
arch_spin_lock(&lock->lock);
if (!atomic_read(&lock->cnts) &&
(atomic_cmpxchg(&lock->cnts, 0, _QW_LOCKED) == 0))
goto unlock;
for (;;) {
cnts = atomic_read(&lock->cnts);
if (!(cnts & _QW_WMASK) &&
(atomic_cmpxchg(&lock->cnts, cnts,
cnts | _QW_WAITING) == cnts))
break;
cpu_relax_lowlatency();
}
for (;;) {
cnts = atomic_read(&lock->cnts);
if ((cnts == _QW_WAITING) &&
(atomic_cmpxchg(&lock->cnts, _QW_WAITING,
_QW_LOCKED) == _QW_WAITING))
break;
cpu_relax_lowlatency();
}
unlock:
arch_spin_unlock(&lock->lock);
}
