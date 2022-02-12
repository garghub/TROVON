static async_cookie_t lowest_in_progress(struct async_domain *domain)
{
struct list_head *pending;
async_cookie_t ret = ASYNC_COOKIE_MAX;
unsigned long flags;
spin_lock_irqsave(&async_lock, flags);
if (domain)
pending = &domain->pending;
else
pending = &async_global_pending;
if (!list_empty(pending))
ret = list_first_entry(pending, struct async_entry,
domain_list)->cookie;
spin_unlock_irqrestore(&async_lock, flags);
return ret;
}
static void async_run_entry_fn(struct work_struct *work)
{
struct async_entry *entry =
container_of(work, struct async_entry, work);
unsigned long flags;
ktime_t uninitialized_var(calltime), delta, rettime;
if (initcall_debug && system_state == SYSTEM_BOOTING) {
pr_debug("calling %lli_%pF @ %i\n",
(long long)entry->cookie,
entry->func, task_pid_nr(current));
calltime = ktime_get();
}
entry->func(entry->data, entry->cookie);
if (initcall_debug && system_state == SYSTEM_BOOTING) {
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
pr_debug("initcall %lli_%pF returned 0 after %lld usecs\n",
(long long)entry->cookie,
entry->func,
(long long)ktime_to_ns(delta) >> 10);
}
spin_lock_irqsave(&async_lock, flags);
list_del_init(&entry->domain_list);
list_del_init(&entry->global_list);
kfree(entry);
atomic_dec(&entry_count);
spin_unlock_irqrestore(&async_lock, flags);
wake_up(&async_done);
}
static async_cookie_t __async_schedule(async_func_t func, void *data, struct async_domain *domain)
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
func(data, newcookie);
return newcookie;
}
INIT_LIST_HEAD(&entry->domain_list);
INIT_LIST_HEAD(&entry->global_list);
INIT_WORK(&entry->work, async_run_entry_fn);
entry->func = func;
entry->data = data;
entry->domain = domain;
spin_lock_irqsave(&async_lock, flags);
newcookie = entry->cookie = next_cookie++;
list_add_tail(&entry->domain_list, &domain->pending);
if (domain->registered)
list_add_tail(&entry->global_list, &async_global_pending);
atomic_inc(&entry_count);
spin_unlock_irqrestore(&async_lock, flags);
current->flags |= PF_USED_ASYNC;
queue_work(system_unbound_wq, &entry->work);
return newcookie;
}
async_cookie_t async_schedule(async_func_t func, void *data)
{
return __async_schedule(func, data, &async_dfl_domain);
}
async_cookie_t async_schedule_domain(async_func_t func, void *data,
struct async_domain *domain)
{
return __async_schedule(func, data, domain);
}
void async_synchronize_full(void)
{
async_synchronize_full_domain(NULL);
}
void async_unregister_domain(struct async_domain *domain)
{
spin_lock_irq(&async_lock);
WARN_ON(!domain->registered || !list_empty(&domain->pending));
domain->registered = 0;
spin_unlock_irq(&async_lock);
}
void async_synchronize_full_domain(struct async_domain *domain)
{
async_synchronize_cookie_domain(ASYNC_COOKIE_MAX, domain);
}
void async_synchronize_cookie_domain(async_cookie_t cookie, struct async_domain *domain)
{
ktime_t uninitialized_var(starttime), delta, endtime;
if (initcall_debug && system_state == SYSTEM_BOOTING) {
pr_debug("async_waiting @ %i\n", task_pid_nr(current));
starttime = ktime_get();
}
wait_event(async_done, lowest_in_progress(domain) >= cookie);
if (initcall_debug && system_state == SYSTEM_BOOTING) {
endtime = ktime_get();
delta = ktime_sub(endtime, starttime);
pr_debug("async_continuing @ %i after %lli usec\n",
task_pid_nr(current),
(long long)ktime_to_ns(delta) >> 10);
}
}
void async_synchronize_cookie(async_cookie_t cookie)
{
async_synchronize_cookie_domain(cookie, &async_dfl_domain);
}
bool current_is_async(void)
{
struct worker *worker = current_wq_worker();
return worker && worker->current_func == async_run_entry_fn;
}
