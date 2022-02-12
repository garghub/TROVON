void
add_wait_queue_exclusive_head(wait_queue_head_t *waitq, wait_queue_t *link)
{
unsigned long flags;
spin_lock_irqsave(&waitq->lock, flags);
__add_wait_queue_exclusive(waitq, link);
spin_unlock_irqrestore(&waitq->lock, flags);
}
void cfs_init_timer(struct timer_list *t)
{
init_timer(t);
}
void cfs_timer_init(struct timer_list *t, cfs_timer_func_t *func, void *arg)
{
init_timer(t);
t->function = func;
t->data = (unsigned long)arg;
}
void cfs_timer_done(struct timer_list *t)
{
return;
}
void cfs_timer_arm(struct timer_list *t, cfs_time_t deadline)
{
mod_timer(t, deadline);
}
void cfs_timer_disarm(struct timer_list *t)
{
del_timer(t);
}
int cfs_timer_is_armed(struct timer_list *t)
{
return timer_pending(t);
}
cfs_time_t cfs_timer_deadline(struct timer_list *t)
{
return t->expires;
}
void cfs_enter_debugger(void)
{
#if defined(CONFIG_KGDB)
#else
#endif
}
sigset_t
cfs_block_allsigs(void)
{
unsigned long flags;
sigset_t old;
SIGNAL_MASK_LOCK(current, flags);
old = current->blocked;
sigfillset(&current->blocked);
recalc_sigpending();
SIGNAL_MASK_UNLOCK(current, flags);
return old;
}
sigset_t cfs_block_sigs(unsigned long sigs)
{
unsigned long flags;
sigset_t old;
SIGNAL_MASK_LOCK(current, flags);
old = current->blocked;
sigaddsetmask(&current->blocked, sigs);
recalc_sigpending();
SIGNAL_MASK_UNLOCK(current, flags);
return old;
}
sigset_t cfs_block_sigsinv(unsigned long sigs)
{
unsigned long flags;
sigset_t old;
SIGNAL_MASK_LOCK(current, flags);
old = current->blocked;
sigaddsetmask(&current->blocked, ~sigs);
recalc_sigpending();
SIGNAL_MASK_UNLOCK(current, flags);
return old;
}
void
cfs_restore_sigs (sigset_t old)
{
unsigned long flags;
SIGNAL_MASK_LOCK(current, flags);
current->blocked = old;
recalc_sigpending();
SIGNAL_MASK_UNLOCK(current, flags);
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
SIGNAL_MASK_LOCK(current, flags);
clear_tsk_thread_flag(current, TIF_SIGPENDING);
SIGNAL_MASK_UNLOCK(current, flags);
}
int
libcfs_arch_init(void)
{
return 0;
}
void
libcfs_arch_cleanup(void)
{
return;
}
