void
add_wait_queue_exclusive_head(wait_queue_head_t *waitq, wait_queue_t *link)
{
unsigned long flags;
spin_lock_irqsave(&waitq->lock, flags);
__add_wait_queue_exclusive(waitq, link);
spin_unlock_irqrestore(&waitq->lock, flags);
}
sigset_t
cfs_block_allsigs(void)
{
unsigned long flags;
sigset_t old;
spin_lock_irqsave(&current->sighand->siglock, flags);
old = current->blocked;
sigfillset(&current->blocked);
recalc_sigpending();
spin_unlock_irqrestore(&current->sighand->siglock, flags);
return old;
}
sigset_t cfs_block_sigs(unsigned long sigs)
{
unsigned long flags;
sigset_t old;
spin_lock_irqsave(&current->sighand->siglock, flags);
old = current->blocked;
sigaddsetmask(&current->blocked, sigs);
recalc_sigpending();
spin_unlock_irqrestore(&current->sighand->siglock, flags);
return old;
}
sigset_t cfs_block_sigsinv(unsigned long sigs)
{
unsigned long flags;
sigset_t old;
spin_lock_irqsave(&current->sighand->siglock, flags);
old = current->blocked;
sigaddsetmask(&current->blocked, ~sigs);
recalc_sigpending();
spin_unlock_irqrestore(&current->sighand->siglock, flags);
return old;
}
void
cfs_restore_sigs(sigset_t old)
{
unsigned long flags;
spin_lock_irqsave(&current->sighand->siglock, flags);
current->blocked = old;
recalc_sigpending();
spin_unlock_irqrestore(&current->sighand->siglock, flags);
}
int
cfs_signal_pending(void)
{
return signal_pending(current);
}
void
cfs_clear_sigpending(void)
{
unsigned long flags;
spin_lock_irqsave(&current->sighand->siglock, flags);
clear_tsk_thread_flag(current, TIF_SIGPENDING);
spin_unlock_irqrestore(&current->sighand->siglock, flags);
}
