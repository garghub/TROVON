static __init int
channel_mod_init(void)
{
if (!unisys_spar_platform)
return -ENODEV;
return 0;
}
static __exit void
channel_mod_exit(void)
{
}
unsigned char
SignalInsert_withLock(CHANNEL_HEADER __iomem *pChannel, u32 Queue,
void *pSignal, spinlock_t *lock)
{
unsigned char result;
unsigned long flags;
spin_lock_irqsave(lock, flags);
result = visor_signal_insert(pChannel, Queue, pSignal);
spin_unlock_irqrestore(lock, flags);
return result;
}
unsigned char
SignalRemove_withLock(CHANNEL_HEADER __iomem *pChannel, u32 Queue,
void *pSignal, spinlock_t *lock)
{
unsigned char result;
spin_lock(lock);
result = visor_signal_remove(pChannel, Queue, pSignal);
spin_unlock(lock);
return result;
}
