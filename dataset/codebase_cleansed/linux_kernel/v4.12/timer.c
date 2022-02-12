void timers_update_migration(bool update_nohz)
{
bool on = sysctl_timer_migration && tick_nohz_active;
unsigned int cpu;
if (this_cpu_read(timer_bases[BASE_STD].migration_enabled) == on)
return;
for_each_possible_cpu(cpu) {
per_cpu(timer_bases[BASE_STD].migration_enabled, cpu) = on;
per_cpu(timer_bases[BASE_DEF].migration_enabled, cpu) = on;
per_cpu(hrtimer_bases.migration_enabled, cpu) = on;
if (!update_nohz)
continue;
per_cpu(timer_bases[BASE_STD].nohz_active, cpu) = true;
per_cpu(timer_bases[BASE_DEF].nohz_active, cpu) = true;
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
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (!ret && write)
timers_update_migration(false);
mutex_unlock(&mutex);
return ret;
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
static inline unsigned int timer_get_idx(struct timer_list *timer)
{
return (timer->flags & TIMER_ARRAYMASK) >> TIMER_ARRAYSHIFT;
}
static inline void timer_set_idx(struct timer_list *timer, unsigned int idx)
{
timer->flags = (timer->flags & ~TIMER_ARRAYMASK) |
idx << TIMER_ARRAYSHIFT;
}
static inline unsigned calc_index(unsigned expires, unsigned lvl)
{
expires = (expires + LVL_GRAN(lvl)) >> LVL_SHIFT(lvl);
return LVL_OFFS(lvl) + (expires & LVL_MASK);
}
static int calc_wheel_index(unsigned long expires, unsigned long clk)
{
unsigned long delta = expires - clk;
unsigned int idx;
if (delta < LVL_START(1)) {
idx = calc_index(expires, 0);
} else if (delta < LVL_START(2)) {
idx = calc_index(expires, 1);
} else if (delta < LVL_START(3)) {
idx = calc_index(expires, 2);
} else if (delta < LVL_START(4)) {
idx = calc_index(expires, 3);
} else if (delta < LVL_START(5)) {
idx = calc_index(expires, 4);
} else if (delta < LVL_START(6)) {
idx = calc_index(expires, 5);
} else if (delta < LVL_START(7)) {
idx = calc_index(expires, 6);
} else if (LVL_DEPTH > 8 && delta < LVL_START(8)) {
idx = calc_index(expires, 7);
} else if ((long) delta < 0) {
idx = clk & LVL_MASK;
} else {
if (expires >= WHEEL_TIMEOUT_CUTOFF)
expires = WHEEL_TIMEOUT_MAX;
idx = calc_index(expires, LVL_DEPTH - 1);
}
return idx;
}
static void enqueue_timer(struct timer_base *base, struct timer_list *timer,
unsigned int idx)
{
hlist_add_head(&timer->entry, base->vectors + idx);
__set_bit(idx, base->pending_map);
timer_set_idx(timer, idx);
}
static void
__internal_add_timer(struct timer_base *base, struct timer_list *timer)
{
unsigned int idx;
idx = calc_wheel_index(timer->expires, base->clk);
enqueue_timer(base, timer, idx);
}
static void
trigger_dyntick_cpu(struct timer_base *base, struct timer_list *timer)
{
if (!IS_ENABLED(CONFIG_NO_HZ_COMMON) || !base->nohz_active)
return;
if (timer->flags & TIMER_DEFERRABLE) {
if (tick_nohz_full_cpu(base->cpu))
wake_up_nohz_cpu(base->cpu);
return;
}
if (!base->is_idle)
return;
if (time_after_eq(timer->expires, base->next_expiry))
return;
base->next_expiry = timer->expires;
wake_up_nohz_cpu(base->cpu);
}
static void
internal_add_timer(struct timer_base *base, struct timer_list *timer)
{
__internal_add_timer(base, timer);
trigger_dyntick_cpu(base, timer);
}
static void *timer_debug_hint(void *addr)
{
return ((struct timer_list *) addr)->function;
}
static bool timer_is_static_object(void *addr)
{
struct timer_list *timer = addr;
return (timer->entry.pprev == NULL &&
timer->entry.next == TIMER_ENTRY_STATIC);
}
static bool timer_fixup_init(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
del_timer_sync(timer);
debug_object_init(timer, &timer_debug_descr);
return true;
default:
return false;
}
}
static void stub_timer(unsigned long data)
{
WARN_ON(1);
}
static bool timer_fixup_activate(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
setup_timer(timer, stub_timer, 0);
return true;
case ODEBUG_STATE_ACTIVE:
WARN_ON(1);
default:
return false;
}
}
static bool timer_fixup_free(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
del_timer_sync(timer);
debug_object_free(timer, &timer_debug_descr);
return true;
default:
return false;
}
}
static bool timer_fixup_assert_init(void *addr, enum debug_obj_state state)
{
struct timer_list *timer = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
setup_timer(timer, stub_timer, 0);
return true;
default:
return false;
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
static int detach_if_pending(struct timer_list *timer, struct timer_base *base,
bool clear_pending)
{
unsigned idx = timer_get_idx(timer);
if (!timer_pending(timer))
return 0;
if (hlist_is_singular_node(&timer->entry, base->vectors + idx))
__clear_bit(idx, base->pending_map);
detach_timer(timer, clear_pending);
return 1;
}
static inline struct timer_base *get_timer_cpu_base(u32 tflags, u32 cpu)
{
struct timer_base *base = per_cpu_ptr(&timer_bases[BASE_STD], cpu);
if (IS_ENABLED(CONFIG_NO_HZ_COMMON) && base->nohz_active &&
(tflags & TIMER_DEFERRABLE))
base = per_cpu_ptr(&timer_bases[BASE_DEF], cpu);
return base;
}
static inline struct timer_base *get_timer_this_cpu_base(u32 tflags)
{
struct timer_base *base = this_cpu_ptr(&timer_bases[BASE_STD]);
if (IS_ENABLED(CONFIG_NO_HZ_COMMON) && base->nohz_active &&
(tflags & TIMER_DEFERRABLE))
base = this_cpu_ptr(&timer_bases[BASE_DEF]);
return base;
}
static inline struct timer_base *get_timer_base(u32 tflags)
{
return get_timer_cpu_base(tflags, tflags & TIMER_CPUMASK);
}
static inline struct timer_base *
get_target_base(struct timer_base *base, unsigned tflags)
{
#ifdef CONFIG_SMP
if ((tflags & TIMER_PINNED) || !base->migration_enabled)
return get_timer_this_cpu_base(tflags);
return get_timer_cpu_base(tflags, get_nohz_timer_target());
#else
return get_timer_this_cpu_base(tflags);
#endif
}
static inline void forward_timer_base(struct timer_base *base)
{
unsigned long jnow = READ_ONCE(jiffies);
if (!base->is_idle || (long) (jnow - base->clk) < 2)
return;
if (time_after(base->next_expiry, jnow))
base->clk = jnow;
else
base->clk = base->next_expiry;
}
static inline struct timer_base *
get_target_base(struct timer_base *base, unsigned tflags)
{
return get_timer_this_cpu_base(tflags);
}
static inline void forward_timer_base(struct timer_base *base) { }
static struct timer_base *lock_timer_base(struct timer_list *timer,
unsigned long *flags)
__acquires(timer->base->lock)
{
for (;;) {
struct timer_base *base;
u32 tf;
tf = READ_ONCE(timer->flags);
if (!(tf & TIMER_MIGRATING)) {
base = get_timer_base(tf);
spin_lock_irqsave(&base->lock, *flags);
if (timer->flags == tf)
return base;
spin_unlock_irqrestore(&base->lock, *flags);
}
cpu_relax();
}
}
static inline int
__mod_timer(struct timer_list *timer, unsigned long expires, bool pending_only)
{
struct timer_base *base, *new_base;
unsigned int idx = UINT_MAX;
unsigned long clk = 0, flags;
int ret = 0;
BUG_ON(!timer->function);
if (timer_pending(timer)) {
if (timer->expires == expires)
return 1;
base = lock_timer_base(timer, &flags);
clk = base->clk;
idx = calc_wheel_index(expires, clk);
if (idx == timer_get_idx(timer)) {
timer->expires = expires;
ret = 1;
goto out_unlock;
}
} else {
base = lock_timer_base(timer, &flags);
}
ret = detach_if_pending(timer, base, false);
if (!ret && pending_only)
goto out_unlock;
debug_activate(timer, expires);
new_base = get_target_base(base, timer->flags);
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
forward_timer_base(base);
timer->expires = expires;
if (idx != UINT_MAX && clk == base->clk) {
enqueue_timer(base, timer, idx);
trigger_dyntick_cpu(base, timer);
} else {
internal_add_timer(base, timer);
}
out_unlock:
spin_unlock_irqrestore(&base->lock, flags);
return ret;
}
int mod_timer_pending(struct timer_list *timer, unsigned long expires)
{
return __mod_timer(timer, expires, true);
}
int mod_timer(struct timer_list *timer, unsigned long expires)
{
return __mod_timer(timer, expires, false);
}
void add_timer(struct timer_list *timer)
{
BUG_ON(timer_pending(timer));
mod_timer(timer, timer->expires);
}
void add_timer_on(struct timer_list *timer, int cpu)
{
struct timer_base *new_base, *base;
unsigned long flags;
BUG_ON(timer_pending(timer) || !timer->function);
new_base = get_timer_cpu_base(timer->flags, cpu);
base = lock_timer_base(timer, &flags);
if (base != new_base) {
timer->flags |= TIMER_MIGRATING;
spin_unlock(&base->lock);
base = new_base;
spin_lock(&base->lock);
WRITE_ONCE(timer->flags,
(timer->flags & ~TIMER_BASEMASK) | cpu);
}
debug_activate(timer, timer->expires);
internal_add_timer(base, timer);
spin_unlock_irqrestore(&base->lock, flags);
}
int del_timer(struct timer_list *timer)
{
struct timer_base *base;
unsigned long flags;
int ret = 0;
debug_assert_init(timer);
if (timer_pending(timer)) {
base = lock_timer_base(timer, &flags);
ret = detach_if_pending(timer, base, true);
spin_unlock_irqrestore(&base->lock, flags);
}
return ret;
}
int try_to_del_timer_sync(struct timer_list *timer)
{
struct timer_base *base;
unsigned long flags;
int ret = -1;
debug_assert_init(timer);
base = lock_timer_base(timer, &flags);
if (base->running_timer != timer)
ret = detach_if_pending(timer, base, true);
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
static void expire_timers(struct timer_base *base, struct hlist_head *head)
{
while (!hlist_empty(head)) {
struct timer_list *timer;
void (*fn)(unsigned long);
unsigned long data;
timer = hlist_entry(head->first, struct timer_list, entry);
base->running_timer = timer;
detach_timer(timer, true);
fn = timer->function;
data = timer->data;
if (timer->flags & TIMER_IRQSAFE) {
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
static int __collect_expired_timers(struct timer_base *base,
struct hlist_head *heads)
{
unsigned long clk = base->clk;
struct hlist_head *vec;
int i, levels = 0;
unsigned int idx;
for (i = 0; i < LVL_DEPTH; i++) {
idx = (clk & LVL_MASK) + i * LVL_SIZE;
if (__test_and_clear_bit(idx, base->pending_map)) {
vec = base->vectors + idx;
hlist_move_list(vec, heads++);
levels++;
}
if (clk & LVL_CLK_MASK)
break;
clk >>= LVL_CLK_SHIFT;
}
return levels;
}
static int next_pending_bucket(struct timer_base *base, unsigned offset,
unsigned clk)
{
unsigned pos, start = offset + clk;
unsigned end = offset + LVL_SIZE;
pos = find_next_bit(base->pending_map, end, start);
if (pos < end)
return pos - start;
pos = find_next_bit(base->pending_map, start, offset);
return pos < start ? pos + LVL_SIZE - start : -1;
}
static unsigned long __next_timer_interrupt(struct timer_base *base)
{
unsigned long clk, next, adj;
unsigned lvl, offset = 0;
next = base->clk + NEXT_TIMER_MAX_DELTA;
clk = base->clk;
for (lvl = 0; lvl < LVL_DEPTH; lvl++, offset += LVL_SIZE) {
int pos = next_pending_bucket(base, offset, clk & LVL_MASK);
if (pos >= 0) {
unsigned long tmp = clk + (unsigned long) pos;
tmp <<= LVL_SHIFT(lvl);
if (time_before(tmp, next))
next = tmp;
}
adj = clk & LVL_CLK_MASK ? 1 : 0;
clk >>= LVL_CLK_SHIFT;
clk += adj;
}
return next;
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
struct timer_base *base = this_cpu_ptr(&timer_bases[BASE_STD]);
u64 expires = KTIME_MAX;
unsigned long nextevt;
bool is_max_delta;
if (cpu_is_offline(smp_processor_id()))
return expires;
spin_lock(&base->lock);
nextevt = __next_timer_interrupt(base);
is_max_delta = (nextevt == base->clk + NEXT_TIMER_MAX_DELTA);
base->next_expiry = nextevt;
if (time_after(basej, base->clk)) {
if (time_after(nextevt, basej))
base->clk = basej;
else if (time_after(nextevt, base->clk))
base->clk = nextevt;
}
if (time_before_eq(nextevt, basej)) {
expires = basem;
base->is_idle = false;
} else {
if (!is_max_delta)
expires = basem + (nextevt - basej) * TICK_NSEC;
if ((expires - basem) > TICK_NSEC)
base->is_idle = true;
}
spin_unlock(&base->lock);
return cmp_next_hrtimer_event(basem, expires);
}
void timer_clear_idle(void)
{
struct timer_base *base = this_cpu_ptr(&timer_bases[BASE_STD]);
base->is_idle = false;
}
static int collect_expired_timers(struct timer_base *base,
struct hlist_head *heads)
{
if ((long)(jiffies - base->clk) > 2) {
unsigned long next = __next_timer_interrupt(base);
if (time_after(next, jiffies)) {
base->clk = jiffies - 1;
return 0;
}
base->clk = next;
}
return __collect_expired_timers(base, heads);
}
static inline int collect_expired_timers(struct timer_base *base,
struct hlist_head *heads)
{
return __collect_expired_timers(base, heads);
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
if (IS_ENABLED(CONFIG_POSIX_TIMERS))
run_posix_cpu_timers(p);
}
static inline void __run_timers(struct timer_base *base)
{
struct hlist_head heads[LVL_DEPTH];
int levels;
if (!time_after_eq(jiffies, base->clk))
return;
spin_lock_irq(&base->lock);
while (time_after_eq(jiffies, base->clk)) {
levels = collect_expired_timers(base, heads);
base->clk++;
while (levels--)
expire_timers(base, heads + levels);
}
base->running_timer = NULL;
spin_unlock_irq(&base->lock);
}
static __latent_entropy void run_timer_softirq(struct softirq_action *h)
{
struct timer_base *base = this_cpu_ptr(&timer_bases[BASE_STD]);
__run_timers(base);
if (IS_ENABLED(CONFIG_NO_HZ_COMMON) && base->nohz_active)
__run_timers(this_cpu_ptr(&timer_bases[BASE_DEF]));
}
void run_local_timers(void)
{
struct timer_base *base = this_cpu_ptr(&timer_bases[BASE_STD]);
hrtimer_run_queues();
if (time_before(jiffies, base->clk)) {
if (!IS_ENABLED(CONFIG_NO_HZ_COMMON) || !base->nohz_active)
return;
base++;
if (time_before(jiffies, base->clk))
return;
}
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
__mod_timer(&timer, expire, false);
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
signed long __sched schedule_timeout_idle(signed long timeout)
{
__set_current_state(TASK_IDLE);
return schedule_timeout(timeout);
}
static void migrate_timer_list(struct timer_base *new_base, struct hlist_head *head)
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
int timers_dead_cpu(unsigned int cpu)
{
struct timer_base *old_base;
struct timer_base *new_base;
int b, i;
BUG_ON(cpu_online(cpu));
for (b = 0; b < NR_BASES; b++) {
old_base = per_cpu_ptr(&timer_bases[b], cpu);
new_base = get_cpu_ptr(&timer_bases[b]);
spin_lock_irq(&new_base->lock);
spin_lock_nested(&old_base->lock, SINGLE_DEPTH_NESTING);
BUG_ON(old_base->running_timer);
for (i = 0; i < WHEEL_SIZE; i++)
migrate_timer_list(new_base, old_base->vectors + i);
spin_unlock(&old_base->lock);
spin_unlock_irq(&new_base->lock);
put_cpu_ptr(&timer_bases);
}
return 0;
}
static void __init init_timer_cpu(int cpu)
{
struct timer_base *base;
int i;
for (i = 0; i < NR_BASES; i++) {
base = per_cpu_ptr(&timer_bases[i], cpu);
base->cpu = cpu;
spin_lock_init(&base->lock);
base->clk = jiffies;
}
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
void __sched usleep_range(unsigned long min, unsigned long max)
{
ktime_t exp = ktime_add_us(ktime_get(), min);
u64 delta = (u64)(max - min) * NSEC_PER_USEC;
for (;;) {
__set_current_state(TASK_UNINTERRUPTIBLE);
if (!schedule_hrtimeout_range(&exp, delta, HRTIMER_MODE_ABS))
break;
}
}
