static void once_deferred(struct work_struct *w)
{
struct once_work *work;
work = container_of(w, struct once_work, work);
BUG_ON(!static_key_enabled(work->key));
static_key_slow_dec(work->key);
kfree(work);
}
static void once_disable_jump(struct static_key *key)
{
struct once_work *w;
w = kmalloc(sizeof(*w), GFP_ATOMIC);
if (!w)
return;
INIT_WORK(&w->work, once_deferred);
w->key = key;
schedule_work(&w->work);
}
bool __do_once_start(bool *done, unsigned long *flags)
__acquires(once_lock)
{
spin_lock_irqsave(&once_lock, *flags);
if (*done) {
spin_unlock_irqrestore(&once_lock, *flags);
__acquire(once_lock);
return false;
}
return true;
}
void __do_once_done(bool *done, struct static_key *once_key,
unsigned long *flags)
__releases(once_lock)
{
*done = true;
spin_unlock_irqrestore(&once_lock, *flags);
once_disable_jump(once_key);
}
