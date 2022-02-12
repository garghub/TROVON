void timers_update_migration(bool update_nohz)
{
bool on = sysctl_timer_migration && tick_nohz_active;
unsigned int cpu;
if (this_cpu_read(tvec_bases.migration_enabled) == on)
return;
for_each_possible_cpu(cpu) {
per_cpu(tvec_bases.migration_enabled, cpu) = on;
per_cpu(hrtimer_bases.migration_enabled, cpu) = on;
if (!update_nohz)
continue;
per_cpu(tvec_bases.nohz_active, cpu) = true;
per_cpu(hrtimer_bases.nohz_active, cpu) = true;
}
}
int timer_migration_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
static DEFINE_MUTEX(mutex);
int ret;
mutex_lock(&mutex);
ret = proc_dointvec(table, write, buffer, lenp, ppos);
if (!ret && write)
timers_update_migration(false);
mutex_unlock(&mutex);
return ret;
}
static inline struct tvec_base *get_target_base(struct tvec_base *base,
int pinned)
{
if (pinned || !base->migration_enabled)
return this_cpu_ptr(&tvec_bases);
return per_cpu_ptr(&tvec_bases, get_nohz_timer_target());
}
static inline struct tvec_base *get_target_base(struct tvec_base *base,
int pinned)
{
return this_cpu_ptr(&tvec_bases);
}
static unsigned long round_jiffies_common(unsigned long j, int cpu,
bool force_up)
{
int rem;
unsigned long original = j;
j += cpu * 3;
rem = j % HZ;
if (rem < HZ/4 && !force_up)
j = j - rem;
else
j = j - rem + HZ;
j -= cpu * 3;
return time_is_after_jiffies(j) ? j : original;
}
unsigned long __round_jiffies(unsigned long j, int cpu)
{
return round_jiffies_common(j, cpu, false);
}
unsigned long __round_jiffies_relative(unsigned long j, int cpu)
{
unsigned long j0 = jiffies;
return round_jiffies_common(j + j0, cpu, false) - j0;
}
unsigned long round_jiffies(unsigned long j)
{
return round_jiffies_common(j, raw_smp_processor_id(), false);
}
unsigned long round_jiffies_relative(unsigned long j)
{
return __round_jiffies_relative(j, raw_smp_processor_id());
}
unsigned long __round_jiffies_up(unsigned long j, int cpu)
{
return round_jiffies_common(j, cpu, true);
}
unsigned long __round_jiffies_up_relative(unsigned long j, int cpu)
{
unsigned long j0 = jiffies;
return round_jiffies_common(j + j0, cpu, true) - j0;
}
unsigned long round_jiffies_up(unsigned long j)
{
return round_jiffies_common(j, raw_smp_processor_id(), true);
}
unsigned long round_jiffies_up_relative(unsigned long j)
{
return __round_jiffies_up_relative(j, raw_smp_processor_id());
}
void set_timer_slack(struct timer_list *timer, int slack_hz)
{
timer->slack = slack_hz;
}
static void
__internal_add_timer(struct tvec_base *base, struct timer_list *timer)
{
unsigned long expires = timer->expires;
unsigned long idx = expires - base->timer_jiffies;
struct hlist_head *vec;
if (idx < TVR_SIZE) {
int i = expires & TVR_MASK;
vec = base->tv1.vec + i;
} else if (idx < 1 << (TVR_BITS + TVN_BITS)) {
int i = (expires >> TVR_BITS) & TVN_MASK;
vec = base->tv2.vec + i;
} else if (idx < 1 << (TVR_BITS + 2 * TVN_BITS)) {
int i = (expires >> (TVR_BITS + TVN_BITS)) & TVN_MASK;
vec = base->tv3.vec + i;
} else if (idx < 1 << (TVR_BITS + 3 * TVN_BITS)) {
int i = (expires >> (TVR_BITS + 2 * TVN_BITS)) & TVN_MASK;
vec = base->tv4.vec + i;
} else if ((signed long) idx < 0) {
vec = base->tv1.vec + (base->timer_jiffies & TVR_MASK);
} else {
int i;
if (idx > MAX_TVAL) {
idx = MAX_TVAL;
expires = idx + base->timer_jiffies;
}
i = (expires >> (TVR_BITS + 3 * TVN_BITS)) & TVN_MASK;
vec = base->tv5.vec + i;
}
hlist_add_head(&timer->entry, vec);
}
static void internal_add_timer(struct tvec_base *base, struct timer_list *timer)
{
if (!base->all_timers++)
base->timer_jiffies = jiffies;
__internal_add_timer(base, timer);
if (!(timer->flags & TIMER_DEFERRABLE)) {
if (!base->active_timers++ ||
time_before(timer->expires, base->next_timer))
base->next_timer = timer->expires;
}
if (base->nohz_active) {
if (!(timer->flags & TIMER_DEFERRABLE) ||
tick_nohz_full_cpu(base->cpu))
wake_up_nohz_cpu(base->cpu);
}
}
void __timer_stats_timer_set_start_info(struct timer_list *timer, void *addr)
{
if (timer->start_site)
return;
timer->start_site = addr;
memcpy(timer->start_comm, current->comm, TASK_COMM_LEN);
timer->start_pid = current->pid;
}
static void timer_stats_account_timer(struct timer_list *timer)
{
if (likely(!timer->start_site))
return;
timer_stats_update_stats(timer, timer->start_pid, timer->start_site,
timer->function, timer->start_comm,
timer->flags);
}
static void timer_stats_account_timer(struct timer_list *timer) {}
static void *timer_debug_hint(void *addr)
{
return ((struct timer_list *) addr)->function;
}
static int timer_fixup_init(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
del_timer_sync(timer);
debug_object_init(timer, &timer_debug_descr);
return 1;
default:
return 0;
}
}
static void stub_timer(unsigned long data)
{
WARN_ON(1);
}
static int timer_fixup_activate(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
if (timer->entry.pprev == NULL &&
timer->entry.next == TIMER_ENTRY_STATIC) {
debug_object_init(timer, &timer_debug_descr);
debug_object_activate(timer, &timer_debug_descr);
return 0;
} else {
setup_timer(timer, stub_timer, 0);
return 1;
}
return 0;
case ODEBUG_STATE_ACTIVE:
WARN_ON(1);
default:
return 0;
}
}
static int timer_fixup_free(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
del_timer_sync(timer);
debug_object_free(timer, &timer_debug_descr);
return 1;
default:
return 0;
}
}
static int timer_fixup_assert_init(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
if (timer->entry.next == TIMER_ENTRY_STATIC) {
debug_object_init(timer, &timer_debug_descr);
return 0;
} else {
setup_timer(timer, stub_timer, 0);
return 1;
}
default:
return 0;
}
}
static inline void debug_timer_init(struct timer_list *timer)
{
debug_object_init(timer, &timer_debug_descr);
}
static inline void debug_timer_activate(struct timer_list *timer)
{
debug_object_activate(timer, &timer_debug_descr);
}
static inline void debug_timer_deactivate(struct timer_list *timer)
{
debug_object_deactivate(timer, &timer_debug_descr);
}
static inline void debug_timer_free(struct timer_list *timer)
{
debug_object_free(timer, &timer_debug_descr);
}
static inline void debug_timer_assert_init(struct timer_list *timer)
{
debug_object_assert_init(timer, &timer_debug_descr);
}
void init_timer_on_stack_key(struct timer_list *timer, unsigned int flags,
const char *name, struct lock_class_key *key)
{
debug_object_init_on_stack(timer, &timer_debug_descr);
do_init_timer(timer, flags, name, key);
}
void destroy_timer_on_stack(struct timer_list *timer)
{
debug_object_free(timer, &timer_debug_descr);
}
static inline void debug_timer_init(struct timer_list *timer) { }
static inline void debug_timer_activate(struct timer_list *timer) { }
static inline void debug_timer_deactivate(struct timer_list *timer) { }
static inline void debug_timer_assert_init(struct timer_list *timer) { }
static inline void debug_init(struct timer_list *timer)
{
debug_timer_init(timer);
trace_timer_init(timer);
}
static inline void
debug_activate(struct timer_list *timer, unsigned long expires)
{
debug_timer_activate(timer);
trace_timer_start(timer, expires, timer->flags);
}
static inline void debug_deactivate(struct timer_list *timer)
{
debug_timer_deactivate(timer);
trace_timer_cancel(timer);
}
static inline void debug_assert_init(struct timer_list *timer)
{
debug_timer_assert_init(timer);
}
static void do_init_timer(struct timer_list *timer, unsigned int flags,
const char *name, struct lock_class_key *key)
{
timer->entry.pprev = NULL;
timer->flags = flags | raw_smp_processor_id();
timer->slack = -1;
#ifdef CONFIG_TIMER_STATS
timer->start_site = NULL;
timer->start_pid = -1;
memset(timer->start_comm, 0, TASK_COMM_LEN);
#endif
lockdep_init_map(&timer->lockdep_map, name, key, 0);
}
void init_timer_key(struct timer_list *timer, unsigned int flags,
const char *name, struct lock_class_key *key)
{
debug_init(timer);
do_init_timer(timer, flags, name, key);
}
static inline void detach_timer(struct timer_list *timer, bool clear_pending)
{
struct hlist_node *entry = &timer->entry;
debug_deactivate(timer);
__hlist_del(entry);
if (clear_pending)
entry->pprev = NULL;
entry->next = LIST_POISON2;
}
static inline void
detach_expired_timer(struct timer_list *timer, struct tvec_base *base)
{
detach_timer(timer, true);
if (!(timer->flags & TIMER_DEFERRABLE))
base->active_timers--;
base->all_timers--;
}
static int detach_if_pending(struct timer_list *timer, struct tvec_base *base,
bool clear_pending)
{
if (!timer_pending(timer))
return 0;
detach_timer(timer, clear_pending);
if (!(timer->flags & TIMER_DEFERRABLE)) {
base->active_timers--;
if (timer->expires == base->next_timer)
base->next_timer = base->timer_jiffies;
}
if (!--base->all_timers)
base->timer_jiffies = jiffies;
return 1;
}
static struct tvec_base *lock_timer_base(struct timer_list *timer,
unsigned long *flags)
__acquires(timer->base->lock)
{
for (;;) {
u32 tf = timer->flags;
struct tvec_base *base;
if (!(tf & TIMER_MIGRATING)) {
base = per_cpu_ptr(&tvec_bases, tf & TIMER_CPUMASK);
spin_lock_irqsave(&base->lock, *flags);
if (timer->flags == tf)
return base;
spin_unlock_irqrestore(&base->lock, *flags);
}
cpu_relax();
}
}
static inline int
__mod_timer(struct timer_list *timer, unsigned long expires,
bool pending_only, int pinned)
{
struct tvec_base *base, *new_base;
unsigned long flags;
int ret = 0;
timer_stats_timer_set_start_info(timer);
BUG_ON(!timer->function);
base = lock_timer_base(timer, &flags);
ret = detach_if_pending(timer, base, false);
if (!ret && pending_only)
goto out_unlock;
debug_activate(timer, expires);
new_base = get_target_base(base, pinned);
if (base != new_base) {
if (likely(base->running_timer != timer)) {
timer->flags |= TIMER_MIGRATING;
spin_unlock(&base->lock);
base = new_base;
spin_lock(&base->lock);
WRITE_ONCE(timer->flags,
(timer->flags & ~TIMER_BASEMASK) | base->cpu);
}
}
timer->expires = expires;
internal_add_timer(base, timer);
out_unlock:
spin_unlock_irqrestore(&base->lock, flags);
return ret;
}
int mod_timer_pending(struct timer_list *timer, unsigned long expires)
{
return __mod_timer(timer, expires, true, TIMER_NOT_PINNED);
}
static inline
unsigned long apply_slack(struct timer_list *timer, unsigned long expires)
{
unsigned long expires_limit, mask;
int bit;
if (timer->slack >= 0) {
expires_limit = expires + timer->slack;
} else {
long delta = expires - jiffies;
if (delta < 256)
return expires;
expires_limit = expires + delta / 256;
}
mask = expires ^ expires_limit;
if (mask == 0)
return expires;
bit = find_last_bit(&mask, BITS_PER_LONG);
mask = (1UL << bit) - 1;
expires_limit = expires_limit & ~(mask);
return expires_limit;
}
int mod_timer(struct timer_list *timer, unsigned long expires)
{
expires = apply_slack(timer, expires);
if (timer_pending(timer) && timer->expires == expires)
return 1;
return __mod_timer(timer, expires, false, TIMER_NOT_PINNED);
}
int mod_timer_pinned(struct timer_list *timer, unsigned long expires)
{
if (timer->expires == expires && timer_pending(timer))
return 1;
return __mod_timer(timer, expires, false, TIMER_PINNED);
}
void add_timer(struct timer_list *timer)
{
BUG_ON(timer_pending(timer));
mod_timer(timer, timer->expires);
}
void add_timer_on(struct timer_list *timer, int cpu)
{
struct tvec_base *base = per_cpu_ptr(&tvec_bases, cpu);
unsigned long flags;
timer_stats_timer_set_start_info(timer);
BUG_ON(timer_pending(timer) || !timer->function);
spin_lock_irqsave(&base->lock, flags);
timer->flags = (timer->flags & ~TIMER_BASEMASK) | cpu;
debug_activate(timer, timer->expires);
internal_add_timer(base, timer);
spin_unlock_irqrestore(&base->lock, flags);
}
int del_timer(struct timer_list *timer)
{
struct tvec_base *base;
unsigned long flags;
int ret = 0;
debug_assert_init(timer);
timer_stats_timer_clear_start_info(timer);
if (timer_pending(timer)) {
base = lock_timer_base(timer, &flags);
ret = detach_if_pending(timer, base, true);
spin_unlock_irqrestore(&base->lock, flags);
}
return ret;
}
int try_to_del_timer_sync(struct timer_list *timer)
{
struct tvec_base *base;
unsigned long flags;
int ret = -1;
debug_assert_init(timer);
base = lock_timer_base(timer, &flags);
if (base->running_timer != timer) {
timer_stats_timer_clear_start_info(timer);
ret = detach_if_pending(timer, base, true);
}
spin_unlock_irqrestore(&base->lock, flags);
return ret;
}
int del_timer_sync(struct timer_list *timer)
{
#ifdef CONFIG_LOCKDEP
unsigned long flags;
local_irq_save(flags);
lock_map_acquire(&timer->lockdep_map);
lock_map_release(&timer->lockdep_map);
local_irq_restore(flags);
#endif
WARN_ON(in_irq() && !(timer->flags & TIMER_IRQSAFE));
for (;;) {
int ret = try_to_del_timer_sync(timer);
if (ret >= 0)
return ret;
cpu_relax();
}
}
static int cascade(struct tvec_base *base, struct tvec *tv, int index)
{
struct timer_list *timer;
struct hlist_node *tmp;
struct hlist_head tv_list;
hlist_move_list(tv->vec + index, &tv_list);
hlist_for_each_entry_safe(timer, tmp, &tv_list, entry) {
__internal_add_timer(base, timer);
}
return index;
}
static void call_timer_fn(struct timer_list *timer, void (*fn)(unsigned long),
unsigned long data)
{
int count = preempt_count();
#ifdef CONFIG_LOCKDEP
struct lockdep_map lockdep_map;
lockdep_copy_map(&lockdep_map, &timer->lockdep_map);
#endif
lock_map_acquire(&lockdep_map);
trace_timer_expire_entry(timer);
fn(data);
trace_timer_expire_exit(timer);
lock_map_release(&lockdep_map);
if (count != preempt_count()) {
WARN_ONCE(1, "timer: %pF preempt leak: %08x -> %08x\n",
fn, count, preempt_count());
preempt_count_set(count);
}
}
static inline void __run_timers(struct tvec_base *base)
{
struct timer_list *timer;
spin_lock_irq(&base->lock);
while (time_after_eq(jiffies, base->timer_jiffies)) {
struct hlist_head work_list;
struct hlist_head *head = &work_list;
int index;
if (!base->all_timers) {
base->timer_jiffies = jiffies;
break;
}
index = base->timer_jiffies & TVR_MASK;
if (!index &&
(!cascade(base, &base->tv2, INDEX(0))) &&
(!cascade(base, &base->tv3, INDEX(1))) &&
!cascade(base, &base->tv4, INDEX(2)))
cascade(base, &base->tv5, INDEX(3));
++base->timer_jiffies;
hlist_move_list(base->tv1.vec + index, head);
while (!hlist_empty(head)) {
void (*fn)(unsigned long);
unsigned long data;
bool irqsafe;
timer = hlist_entry(head->first, struct timer_list, entry);
fn = timer->function;
data = timer->data;
irqsafe = timer->flags & TIMER_IRQSAFE;
timer_stats_account_timer(timer);
base->running_timer = timer;
detach_expired_timer(timer, base);
if (irqsafe) {
spin_unlock(&base->lock);
call_timer_fn(timer, fn, data);
spin_lock(&base->lock);
} else {
spin_unlock_irq(&base->lock);
call_timer_fn(timer, fn, data);
spin_lock_irq(&base->lock);
}
}
}
base->running_timer = NULL;
spin_unlock_irq(&base->lock);
}
static unsigned long __next_timer_interrupt(struct tvec_base *base)
{
unsigned long timer_jiffies = base->timer_jiffies;
unsigned long expires = timer_jiffies + NEXT_TIMER_MAX_DELTA;
int index, slot, array, found = 0;
struct timer_list *nte;
struct tvec *varray[4];
index = slot = timer_jiffies & TVR_MASK;
do {
hlist_for_each_entry(nte, base->tv1.vec + slot, entry) {
if (nte->flags & TIMER_DEFERRABLE)
continue;
found = 1;
expires = nte->expires;
if (!index || slot < index)
goto cascade;
return expires;
}
slot = (slot + 1) & TVR_MASK;
} while (slot != index);
cascade:
if (index)
timer_jiffies += TVR_SIZE - index;
timer_jiffies >>= TVR_BITS;
varray[0] = &base->tv2;
varray[1] = &base->tv3;
varray[2] = &base->tv4;
varray[3] = &base->tv5;
for (array = 0; array < 4; array++) {
struct tvec *varp = varray[array];
index = slot = timer_jiffies & TVN_MASK;
do {
hlist_for_each_entry(nte, varp->vec + slot, entry) {
if (nte->flags & TIMER_DEFERRABLE)
continue;
found = 1;
if (time_before(nte->expires, expires))
expires = nte->expires;
}
if (found) {
if (!index || slot < index)
break;
return expires;
}
slot = (slot + 1) & TVN_MASK;
} while (slot != index);
if (index)
timer_jiffies += TVN_SIZE - index;
timer_jiffies >>= TVN_BITS;
}
return expires;
}
static u64 cmp_next_hrtimer_event(u64 basem, u64 expires)
{
u64 nextevt = hrtimer_get_next_event();
if (expires <= nextevt)
return expires;
if (nextevt <= basem)
return basem;
return DIV_ROUND_UP_ULL(nextevt, TICK_NSEC) * TICK_NSEC;
}
u64 get_next_timer_interrupt(unsigned long basej, u64 basem)
{
struct tvec_base *base = this_cpu_ptr(&tvec_bases);
u64 expires = KTIME_MAX;
unsigned long nextevt;
if (cpu_is_offline(smp_processor_id()))
return expires;
spin_lock(&base->lock);
if (base->active_timers) {
if (time_before_eq(base->next_timer, base->timer_jiffies))
base->next_timer = __next_timer_interrupt(base);
nextevt = base->next_timer;
if (time_before_eq(nextevt, basej))
expires = basem;
else
expires = basem + (nextevt - basej) * TICK_NSEC;
}
spin_unlock(&base->lock);
return cmp_next_hrtimer_event(basem, expires);
}
void update_process_times(int user_tick)
{
struct task_struct *p = current;
account_process_tick(p, user_tick);
run_local_timers();
rcu_check_callbacks(user_tick);
#ifdef CONFIG_IRQ_WORK
if (in_irq())
irq_work_tick();
#endif
scheduler_tick();
run_posix_cpu_timers(p);
}
static void run_timer_softirq(struct softirq_action *h)
{
struct tvec_base *base = this_cpu_ptr(&tvec_bases);
if (time_after_eq(jiffies, base->timer_jiffies))
__run_timers(base);
}
void run_local_timers(void)
{
hrtimer_run_queues();
raise_softirq(TIMER_SOFTIRQ);
}
static void process_timeout(unsigned long __data)
{
wake_up_process((struct task_struct *)__data);
}
signed long __sched schedule_timeout(signed long timeout)
{
struct timer_list timer;
unsigned long expire;
switch (timeout)
{
case MAX_SCHEDULE_TIMEOUT:
schedule();
goto out;
default:
if (timeout < 0) {
printk(KERN_ERR "schedule_timeout: wrong timeout "
"value %lx\n", timeout);
dump_stack();
current->state = TASK_RUNNING;
goto out;
}
}
expire = timeout + jiffies;
setup_timer_on_stack(&timer, process_timeout, (unsigned long)current);
__mod_timer(&timer, expire, false, TIMER_NOT_PINNED);
schedule();
del_singleshot_timer_sync(&timer);
destroy_timer_on_stack(&timer);
timeout = expire - jiffies;
out:
return timeout < 0 ? 0 : timeout;
}
signed long __sched schedule_timeout_interruptible(signed long timeout)
{
__set_current_state(TASK_INTERRUPTIBLE);
return schedule_timeout(timeout);
}
signed long __sched schedule_timeout_killable(signed long timeout)
{
__set_current_state(TASK_KILLABLE);
return schedule_timeout(timeout);
}
signed long __sched schedule_timeout_uninterruptible(signed long timeout)
{
__set_current_state(TASK_UNINTERRUPTIBLE);
return schedule_timeout(timeout);
}
static void migrate_timer_list(struct tvec_base *new_base, struct hlist_head *head)
{
struct timer_list *timer;
int cpu = new_base->cpu;
while (!hlist_empty(head)) {
timer = hlist_entry(head->first, struct timer_list, entry);
detach_timer(timer, false);
timer->flags = (timer->flags & ~TIMER_BASEMASK) | cpu;
internal_add_timer(new_base, timer);
}
}
static void migrate_timers(int cpu)
{
struct tvec_base *old_base;
struct tvec_base *new_base;
int i;
BUG_ON(cpu_online(cpu));
old_base = per_cpu_ptr(&tvec_bases, cpu);
new_base = get_cpu_ptr(&tvec_bases);
spin_lock_irq(&new_base->lock);
spin_lock_nested(&old_base->lock, SINGLE_DEPTH_NESTING);
BUG_ON(old_base->running_timer);
for (i = 0; i < TVR_SIZE; i++)
migrate_timer_list(new_base, old_base->tv1.vec + i);
for (i = 0; i < TVN_SIZE; i++) {
migrate_timer_list(new_base, old_base->tv2.vec + i);
migrate_timer_list(new_base, old_base->tv3.vec + i);
migrate_timer_list(new_base, old_base->tv4.vec + i);
migrate_timer_list(new_base, old_base->tv5.vec + i);
}
old_base->active_timers = 0;
old_base->all_timers = 0;
spin_unlock(&old_base->lock);
spin_unlock_irq(&new_base->lock);
put_cpu_ptr(&tvec_bases);
}
static int timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action) {
case CPU_DEAD:
case CPU_DEAD_FROZEN:
migrate_timers((long)hcpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static inline void timer_register_cpu_notifier(void)
{
cpu_notifier(timer_cpu_notify, 0);
}
static inline void timer_register_cpu_notifier(void) { }
static void __init init_timer_cpu(int cpu)
{
struct tvec_base *base = per_cpu_ptr(&tvec_bases, cpu);
base->cpu = cpu;
spin_lock_init(&base->lock);
base->timer_jiffies = jiffies;
base->next_timer = base->timer_jiffies;
}
static void __init init_timer_cpus(void)
{
int cpu;
for_each_possible_cpu(cpu)
init_timer_cpu(cpu);
}
void __init init_timers(void)
{
init_timer_cpus();
init_timer_stats();
timer_register_cpu_notifier();
open_softirq(TIMER_SOFTIRQ, run_timer_softirq);
}
void msleep(unsigned int msecs)
{
unsigned long timeout = msecs_to_jiffies(msecs) + 1;
while (timeout)
timeout = schedule_timeout_uninterruptible(timeout);
}
unsigned long msleep_interruptible(unsigned int msecs)
{
unsigned long timeout = msecs_to_jiffies(msecs) + 1;
while (timeout && !signal_pending(current))
timeout = schedule_timeout_interruptible(timeout);
return jiffies_to_msecs(timeout);
}
static void __sched do_usleep_range(unsigned long min, unsigned long max)
{
ktime_t kmin;
unsigned long delta;
kmin = ktime_set(0, min * NSEC_PER_USEC);
delta = (max - min) * NSEC_PER_USEC;
schedule_hrtimeout_range(&kmin, delta, HRTIMER_MODE_REL);
}
void __sched usleep_range(unsigned long min, unsigned long max)
{
__set_current_state(TASK_UNINTERRUPTIBLE);
do_usleep_range(min, max);
}
