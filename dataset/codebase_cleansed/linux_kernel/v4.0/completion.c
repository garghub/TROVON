void complete(struct completion *x)
{
unsigned long flags;
spin_lock_irqsave(&x->wait.lock, flags);
x->done++;
__wake_up_locked(&x->wait, TASK_NORMAL, 1);
spin_unlock_irqrestore(&x->wait.lock, flags);
}
void complete_all(struct completion *x)
{
unsigned long flags;
spin_lock_irqsave(&x->wait.lock, flags);
x->done += UINT_MAX/2;
__wake_up_locked(&x->wait, TASK_NORMAL, 0);
spin_unlock_irqrestore(&x->wait.lock, flags);
}
static inline long __sched
do_wait_for_common(struct completion *x,
long (*action)(long), long timeout, int state)
{
if (!x->done) {
DECLARE_WAITQUEUE(wait, current);
__add_wait_queue_tail_exclusive(&x->wait, &wait);
do {
if (signal_pending_state(state, current)) {
timeout = -ERESTARTSYS;
break;
}
__set_current_state(state);
spin_unlock_irq(&x->wait.lock);
timeout = action(timeout);
spin_lock_irq(&x->wait.lock);
} while (!x->done && timeout);
__remove_wait_queue(&x->wait, &wait);
if (!x->done)
return timeout;
}
x->done--;
return timeout ?: 1;
}
static inline long __sched
__wait_for_common(struct completion *x,
long (*action)(long), long timeout, int state)
{
might_sleep();
spin_lock_irq(&x->wait.lock);
timeout = do_wait_for_common(x, action, timeout, state);
spin_unlock_irq(&x->wait.lock);
return timeout;
}
static long __sched
wait_for_common(struct completion *x, long timeout, int state)
{
return __wait_for_common(x, schedule_timeout, timeout, state);
}
static long __sched
wait_for_common_io(struct completion *x, long timeout, int state)
{
return __wait_for_common(x, io_schedule_timeout, timeout, state);
}
void __sched wait_for_completion(struct completion *x)
{
wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_UNINTERRUPTIBLE);
}
unsigned long __sched
wait_for_completion_timeout(struct completion *x, unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_UNINTERRUPTIBLE);
}
void __sched wait_for_completion_io(struct completion *x)
{
wait_for_common_io(x, MAX_SCHEDULE_TIMEOUT, TASK_UNINTERRUPTIBLE);
}
unsigned long __sched
wait_for_completion_io_timeout(struct completion *x, unsigned long timeout)
{
return wait_for_common_io(x, timeout, TASK_UNINTERRUPTIBLE);
}
int __sched wait_for_completion_interruptible(struct completion *x)
{
long t = wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_INTERRUPTIBLE);
if (t == -ERESTARTSYS)
return t;
return 0;
}
long __sched
wait_for_completion_interruptible_timeout(struct completion *x,
unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_INTERRUPTIBLE);
}
int __sched wait_for_completion_killable(struct completion *x)
{
long t = wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_KILLABLE);
if (t == -ERESTARTSYS)
return t;
return 0;
}
long __sched
wait_for_completion_killable_timeout(struct completion *x,
unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_KILLABLE);
}
bool try_wait_for_completion(struct completion *x)
{
unsigned long flags;
int ret = 1;
if (!READ_ONCE(x->done))
return 0;
spin_lock_irqsave(&x->wait.lock, flags);
if (!x->done)
ret = 0;
else
x->done--;
spin_unlock_irqrestore(&x->wait.lock, flags);
return ret;
}
bool completion_done(struct completion *x)
{
if (!READ_ONCE(x->done))
return false;
smp_rmb();
spin_unlock_wait(&x->wait.lock);
return true;
}
