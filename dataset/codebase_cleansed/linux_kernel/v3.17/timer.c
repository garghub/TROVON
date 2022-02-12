static inline unsigned int tbase_get_deferrable(struct tvec_base *base)
{
return ((unsigned int)(unsigned long)base & TIMER_DEFERRABLE);
}
static inline unsigned int tbase_get_irqsafe(struct tvec_base *base)
{
return ((unsigned int)(unsigned long)base & TIMER_IRQSAFE);
}
static inline struct tvec_base *tbase_get_base(struct tvec_base *base)
{
return ((struct tvec_base *)((unsigned long)base & ~TIMER_FLAG_MASK));
}
static inline void
timer_set_base(struct timer_list *timer, struct tvec_base *new_base)
{
unsigned long flags = (unsigned long)timer->base & TIMER_FLAG_MASK;
timer->base = (struct tvec_base *)((unsigned long)(new_base) | flags);
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
static bool catchup_timer_jiffies(struct tvec_base *base)
{
if (!base->all_timers) {
base->timer_jiffies = jiffies;
return true;
}
return false;
}
static void
__internal_add_timer(struct tvec_base *base, struct timer_list *timer)
{
unsigned long expires = timer->expires;
unsigned long idx = expires - base->timer_jiffies;
struct list_head *vec;
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
list_add_tail(&timer->entry, vec);
}
static void internal_add_timer(struct tvec_base *base, struct timer_list *timer)
{
(void)catchup_timer_jiffies(base);
__internal_add_timer(base, timer);
if (!tbase_get_deferrable(timer->base)) {
if (!base->active_timers++ ||
time_before(timer->expires, base->next_timer))
base->next_timer = timer->expires;
}
base->all_timers++;
if (!tbase_get_deferrable(base) || tick_nohz_full_cpu(base->cpu))
wake_up_nohz_cpu(base->cpu);
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
unsigned int flag = 0;
if (likely(!timer->start_site))
return;
if (unlikely(tbase_get_deferrable(timer->base)))
flag |= TIMER_STATS_FLAG_DEFERRABLE;
timer_stats_update_stats(timer, timer->start_pid, timer->start_site,
timer->function, timer->start_comm, flag);
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
if (timer->entry.next == NULL &&
timer->entry.prev == TIMER_ENTRY_STATIC) {
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
if (timer->entry.prev == TIMER_ENTRY_STATIC) {
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
trace_timer_start(timer, expires);
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
struct tvec_base *base = __raw_get_cpu_var(tvec_bases);
timer->entry.next = NULL;
timer->base = (void *)((unsigned long)base | flags);
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
struct list_head *entry = &timer->entry;
debug_deactivate(timer);
__list_del(entry->prev, entry->next);
if (clear_pending)
entry->next = NULL;
entry->prev = LIST_POISON2;
}
static inline void
detach_expired_timer(struct timer_list *timer, struct tvec_base *base)
{
detach_timer(timer, true);
if (!tbase_get_deferrable(timer->base))
base->active_timers--;
base->all_timers--;
(void)catchup_timer_jiffies(base);
}
static int detach_if_pending(struct timer_list *timer, struct tvec_base *base,
bool clear_pending)
{
if (!timer_pending(timer))
return 0;
detach_timer(timer, clear_pending);
if (!tbase_get_deferrable(timer->base)) {
base->active_timers--;
if (timer->expires == base->next_timer)
base->next_timer = base->timer_jiffies;
}
base->all_timers--;
(void)catchup_timer_jiffies(base);
return 1;
}
static struct tvec_base *lock_timer_base(struct timer_list *timer,
unsigned long *flags)
__acquires(timer->base->lock)
{
struct tvec_base *base;
for (;;) {
struct tvec_base *prelock_base = timer->base;
base = tbase_get_base(prelock_base);
if (likely(base != NULL)) {
spin_lock_irqsave(&base->lock, *flags);
if (likely(prelock_base == timer->base))
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
int ret = 0 , cpu;
timer_stats_timer_set_start_info(timer);
BUG_ON(!timer->function);
base = lock_timer_base(timer, &flags);
ret = detach_if_pending(timer, base, false);
if (!ret && pending_only)
goto out_unlock;
debug_activate(timer, expires);
cpu = get_nohz_timer_target(pinned);
new_base = per_cpu(tvec_bases, cpu);
if (base != new_base) {
if (likely(base->running_timer != timer)) {
timer_set_base(timer, NULL);
spin_unlock(&base->lock);
base = new_base;
spin_lock(&base->lock);
timer_set_base(timer, base);
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
struct tvec_base *base = per_cpu(tvec_bases, cpu);
unsigned long flags;
timer_stats_timer_set_start_info(timer);
BUG_ON(timer_pending(timer) || !timer->function);
spin_lock_irqsave(&base->lock, flags);
timer_set_base(timer, base);
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
WARN_ON(in_irq() && !tbase_get_irqsafe(timer->base));
for (;;) {
int ret = try_to_del_timer_sync(timer);
if (ret >= 0)
return ret;
cpu_relax();
}
}
static int cascade(struct tvec_base *base, struct tvec *tv, int index)
{
struct timer_list *timer, *tmp;
struct list_head tv_list;
list_replace_init(tv->vec + index, &tv_list);
list_for_each_entry_safe(timer, tmp, &tv_list, entry) {
BUG_ON(tbase_get_base(timer->base) != base);
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
if (catchup_timer_jiffies(base)) {
spin_unlock_irq(&base->lock);
return;
}
while (time_after_eq(jiffies, base->timer_jiffies)) {
struct list_head work_list;
struct list_head *head = &work_list;
int index = base->timer_jiffies & TVR_MASK;
if (!index &&
(!cascade(base, &base->tv2, INDEX(0))) &&
(!cascade(base, &base->tv3, INDEX(1))) &&
!cascade(base, &base->tv4, INDEX(2)))
cascade(base, &base->tv5, INDEX(3));
++base->timer_jiffies;
list_replace_init(base->tv1.vec + index, head);
while (!list_empty(head)) {
void (*fn)(unsigned long);
unsigned long data;
bool irqsafe;
timer = list_first_entry(head, struct timer_list,entry);
fn = timer->function;
data = timer->data;
irqsafe = tbase_get_irqsafe(timer->base);
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
list_for_each_entry(nte, base->tv1.vec + slot, entry) {
if (tbase_get_deferrable(nte->base))
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
list_for_each_entry(nte, varp->vec + slot, entry) {
if (tbase_get_deferrable(nte->base))
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
static unsigned long cmp_next_hrtimer_event(unsigned long now,
unsigned long expires)
{
ktime_t hr_delta = hrtimer_get_next_event();
struct timespec tsdelta;
unsigned long delta;
if (hr_delta.tv64 == KTIME_MAX)
return expires;
if (hr_delta.tv64 <= 0)
return now + 1;
tsdelta = ktime_to_timespec(hr_delta);
delta = timespec_to_jiffies(&tsdelta);
if (delta > NEXT_TIMER_MAX_DELTA)
delta = NEXT_TIMER_MAX_DELTA;
if (delta < 1)
delta = 1;
now += delta;
if (time_before(now, expires))
return now;
return expires;
}
unsigned long get_next_timer_interrupt(unsigned long now)
{
struct tvec_base *base = __this_cpu_read(tvec_bases);
unsigned long expires = now + NEXT_TIMER_MAX_DELTA;
if (cpu_is_offline(smp_processor_id()))
return expires;
spin_lock(&base->lock);
if (base->active_timers) {
if (time_before_eq(base->next_timer, base->timer_jiffies))
base->next_timer = __next_timer_interrupt(base);
expires = base->next_timer;
}
spin_unlock(&base->lock);
if (time_before_eq(expires, now))
return now;
return cmp_next_hrtimer_event(now, expires);
}
void update_process_times(int user_tick)
{
struct task_struct *p = current;
int cpu = smp_processor_id();
account_process_tick(p, user_tick);
run_local_timers();
rcu_check_callbacks(cpu, user_tick);
#ifdef CONFIG_IRQ_WORK
if (in_irq())
irq_work_run();
#endif
scheduler_tick();
run_posix_cpu_timers(p);
}
static void run_timer_softirq(struct softirq_action *h)
{
struct tvec_base *base = __this_cpu_read(tvec_bases);
hrtimer_run_pending();
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
static int init_timers_cpu(int cpu)
{
int j;
struct tvec_base *base;
static char tvec_base_done[NR_CPUS];
if (!tvec_base_done[cpu]) {
static char boot_done;
if (boot_done) {
base = kzalloc_node(sizeof(*base), GFP_KERNEL,
cpu_to_node(cpu));
if (!base)
return -ENOMEM;
if (WARN_ON(base != tbase_get_base(base))) {
kfree(base);
return -ENOMEM;
}
per_cpu(tvec_bases, cpu) = base;
} else {
boot_done = 1;
base = &boot_tvec_bases;
}
spin_lock_init(&base->lock);
tvec_base_done[cpu] = 1;
base->cpu = cpu;
} else {
base = per_cpu(tvec_bases, cpu);
}
for (j = 0; j < TVN_SIZE; j++) {
INIT_LIST_HEAD(base->tv5.vec + j);
INIT_LIST_HEAD(base->tv4.vec + j);
INIT_LIST_HEAD(base->tv3.vec + j);
INIT_LIST_HEAD(base->tv2.vec + j);
}
for (j = 0; j < TVR_SIZE; j++)
INIT_LIST_HEAD(base->tv1.vec + j);
base->timer_jiffies = jiffies;
base->next_timer = base->timer_jiffies;
base->active_timers = 0;
base->all_timers = 0;
return 0;
}
static void migrate_timer_list(struct tvec_base *new_base, struct list_head *head)
{
struct timer_list *timer;
while (!list_empty(head)) {
timer = list_first_entry(head, struct timer_list, entry);
detach_timer(timer, false);
timer_set_base(timer, new_base);
internal_add_timer(new_base, timer);
}
}
static void migrate_timers(int cpu)
{
struct tvec_base *old_base;
struct tvec_base *new_base;
int i;
BUG_ON(cpu_online(cpu));
old_base = per_cpu(tvec_bases, cpu);
new_base = get_cpu_var(tvec_bases);
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
spin_unlock(&old_base->lock);
spin_unlock_irq(&new_base->lock);
put_cpu_var(tvec_bases);
}
static int timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
int err;
switch(action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
err = init_timers_cpu(cpu);
if (err < 0)
return notifier_from_errno(err);
break;
#ifdef CONFIG_HOTPLUG_CPU
case CPU_DEAD:
case CPU_DEAD_FROZEN:
migrate_timers(cpu);
break;
#endif
default:
break;
}
return NOTIFY_OK;
}
void __init init_timers(void)
{
int err;
BUILD_BUG_ON(__alignof__(struct tvec_base) & TIMER_FLAG_MASK);
err = timer_cpu_notify(&timers_nb, (unsigned long)CPU_UP_PREPARE,
(void *)(long)smp_processor_id());
BUG_ON(err != NOTIFY_OK);
init_timer_stats();
register_cpu_notifier(&timers_nb);
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
static int __sched do_usleep_range(unsigned long min, unsigned long max)
{
ktime_t kmin;
unsigned long delta;
kmin = ktime_set(0, min * NSEC_PER_USEC);
delta = (max - min) * NSEC_PER_USEC;
return schedule_hrtimeout_range(&kmin, delta, HRTIMER_MODE_REL);
}
void usleep_range(unsigned long min, unsigned long max)
{
__set_current_state(TASK_UNINTERRUPTIBLE);
do_usleep_range(min, max);
}
