static async_cookie_t __lowest_in_progress(struct list_head *running)
{
struct async_entry *entry;
if (!list_empty(running)) {
entry = list_first_entry(running,
struct async_entry, list);
return entry->cookie;
}
list_for_each_entry(entry, &async_pending, list)
if (entry->running == running)
return entry->cookie;
return next_cookie;
}
static async_cookie_t lowest_in_progress(struct list_head *running)
{
unsigned long flags;
async_cookie_t ret;
spin_lock_irqsave(&async_lock, flags);
ret = __lowest_in_progress(running);
spin_unlock_irqrestore(&async_lock, flags);
return ret;
}
static void async_run_entry_fn(struct work_struct *work)
{
struct async_entry *entry =
container_of(work, struct async_entry, work);
unsigned long flags;
ktime_t calltime, delta, rettime;
spin_lock_irqsave(&async_lock, flags);
list_move_tail(&entry->list, entry->running);
spin_unlock_irqrestore(&async_lock, flags);
if (initcall_debug && system_state == SYSTEM_BOOTING) {
printk(KERN_DEBUG "calling %lli_%pF @ %i\n",
(long long)entry->cookie,
entry->func, task_pid_nr(current));
calltime = ktime_get();
}
entry->func(entry->data, entry->cookie);
if (initcall_debug && system_state == SYSTEM_BOOTING) {
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
printk(KERN_DEBUG "initcall %lli_%pF returned 0 after %lld usecs\n",
(long long)entry->cookie,
entry->func,
(long long)ktime_to_ns(delta) >> 10);
}
spin_lock_irqsave(&async_lock, flags);
list_del(&entry->list);
kfree(entry);
atomic_dec(&entry_count);
spin_unlock_irqrestore(&async_lock, flags);
wake_up(&async_done);
}
static async_cookie_t __async_schedule(async_func_ptr *ptr, void *data, struct list_head *running)
{
struct async_entry *entry;
unsigned long flags;
async_cookie_t newcookie;
entry = kzalloc(sizeof(struct async_entry), GFP_ATOMIC);
if (!entry || atomic_read(&entry_count) > MAX_WORK) {
kfree(entry);
spin_lock_irqsave(&async_lock, flags);
newcookie = next_cookie++;
spin_unlock_irqrestore(&async_lock, flags);
ptr(data, newcookie);
return newcookie;
}
INIT_WORK(&entry->work, async_run_entry_fn);
entry->func = ptr;
entry->data = data;
entry->running = running;
spin_lock_irqsave(&async_lock, flags);
newcookie = entry->cookie = next_cookie++;
list_add_tail(&entry->list, &async_pending);
atomic_inc(&entry_count);
spin_unlock_irqrestore(&async_lock, flags);
queue_work(system_unbound_wq, &entry->work);
return newcookie;
}
async_cookie_t async_schedule(async_func_ptr *ptr, void *data)
{
return __async_schedule(ptr, data, &async_running);
}
async_cookie_t async_schedule_domain(async_func_ptr *ptr, void *data,
struct list_head *running)
{
return __async_schedule(ptr, data, running);
}
void async_synchronize_full(void)
{
do {
async_synchronize_cookie(next_cookie);
} while (!list_empty(&async_running) || !list_empty(&async_pending));
}
void async_synchronize_full_domain(struct list_head *list)
{
async_synchronize_cookie_domain(next_cookie, list);
}
void async_synchronize_cookie_domain(async_cookie_t cookie,
struct list_head *running)
{
ktime_t starttime, delta, endtime;
if (initcall_debug && system_state == SYSTEM_BOOTING) {
printk(KERN_DEBUG "async_waiting @ %i\n", task_pid_nr(current));
starttime = ktime_get();
}
wait_event(async_done, lowest_in_progress(running) >= cookie);
if (initcall_debug && system_state == SYSTEM_BOOTING) {
endtime = ktime_get();
delta = ktime_sub(endtime, starttime);
printk(KERN_DEBUG "async_continuing @ %i after %lli usec\n",
task_pid_nr(current),
(long long)ktime_to_ns(delta) >> 10);
}
}
void async_synchronize_cookie(async_cookie_t cookie)
{
async_synchronize_cookie_domain(cookie, &async_running);
}
