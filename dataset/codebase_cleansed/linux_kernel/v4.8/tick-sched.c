struct tick_sched *tick_get_tick_sched(int cpu)
{
return &per_cpu(tick_cpu_sched, cpu);
}
static void tick_do_update_jiffies64(ktime_t now)
{
unsigned long ticks = 0;
ktime_t delta;
delta = ktime_sub(now, last_jiffies_update);
if (delta.tv64 < tick_period.tv64)
return;
write_seqlock(&jiffies_lock);
delta = ktime_sub(now, last_jiffies_update);
if (delta.tv64 >= tick_period.tv64) {
delta = ktime_sub(delta, tick_period);
last_jiffies_update = ktime_add(last_jiffies_update,
tick_period);
if (unlikely(delta.tv64 >= tick_period.tv64)) {
s64 incr = ktime_to_ns(tick_period);
ticks = ktime_divns(delta, incr);
last_jiffies_update = ktime_add_ns(last_jiffies_update,
incr * ticks);
}
do_timer(++ticks);
tick_next_period = ktime_add(last_jiffies_update, tick_period);
} else {
write_sequnlock(&jiffies_lock);
return;
}
write_sequnlock(&jiffies_lock);
update_wall_time();
}
static ktime_t tick_init_jiffy_update(void)
{
ktime_t period;
write_seqlock(&jiffies_lock);
if (last_jiffies_update.tv64 == 0)
last_jiffies_update = tick_next_period;
period = last_jiffies_update;
write_sequnlock(&jiffies_lock);
return period;
}
static void tick_sched_do_timer(ktime_t now)
{
int cpu = smp_processor_id();
#ifdef CONFIG_NO_HZ_COMMON
if (unlikely(tick_do_timer_cpu == TICK_DO_TIMER_NONE)
&& !tick_nohz_full_cpu(cpu))
tick_do_timer_cpu = cpu;
#endif
if (tick_do_timer_cpu == cpu)
tick_do_update_jiffies64(now);
}
static void tick_sched_handle(struct tick_sched *ts, struct pt_regs *regs)
{
#ifdef CONFIG_NO_HZ_COMMON
if (ts->tick_stopped) {
touch_softlockup_watchdog_sched();
if (is_idle_task(current))
ts->idle_jiffies++;
}
#endif
update_process_times(user_mode(regs));
profile_tick(CPU_PROFILING);
}
static bool check_tick_dependency(atomic_t *dep)
{
int val = atomic_read(dep);
if (val & TICK_DEP_MASK_POSIX_TIMER) {
trace_tick_stop(0, TICK_DEP_MASK_POSIX_TIMER);
return true;
}
if (val & TICK_DEP_MASK_PERF_EVENTS) {
trace_tick_stop(0, TICK_DEP_MASK_PERF_EVENTS);
return true;
}
if (val & TICK_DEP_MASK_SCHED) {
trace_tick_stop(0, TICK_DEP_MASK_SCHED);
return true;
}
if (val & TICK_DEP_MASK_CLOCK_UNSTABLE) {
trace_tick_stop(0, TICK_DEP_MASK_CLOCK_UNSTABLE);
return true;
}
return false;
}
static bool can_stop_full_tick(struct tick_sched *ts)
{
WARN_ON_ONCE(!irqs_disabled());
if (check_tick_dependency(&tick_dep_mask))
return false;
if (check_tick_dependency(&ts->tick_dep_mask))
return false;
if (check_tick_dependency(&current->tick_dep_mask))
return false;
if (check_tick_dependency(&current->signal->tick_dep_mask))
return false;
return true;
}
static void nohz_full_kick_func(struct irq_work *work)
{
}
static void tick_nohz_full_kick(void)
{
if (!tick_nohz_full_cpu(smp_processor_id()))
return;
irq_work_queue(this_cpu_ptr(&nohz_full_kick_work));
}
void tick_nohz_full_kick_cpu(int cpu)
{
if (!tick_nohz_full_cpu(cpu))
return;
irq_work_queue_on(&per_cpu(nohz_full_kick_work, cpu), cpu);
}
static void tick_nohz_full_kick_all(void)
{
int cpu;
if (!tick_nohz_full_running)
return;
preempt_disable();
for_each_cpu_and(cpu, tick_nohz_full_mask, cpu_online_mask)
tick_nohz_full_kick_cpu(cpu);
preempt_enable();
}
static void tick_nohz_dep_set_all(atomic_t *dep,
enum tick_dep_bits bit)
{
int prev;
prev = atomic_fetch_or(BIT(bit), dep);
if (!prev)
tick_nohz_full_kick_all();
}
void tick_nohz_dep_set(enum tick_dep_bits bit)
{
tick_nohz_dep_set_all(&tick_dep_mask, bit);
}
void tick_nohz_dep_clear(enum tick_dep_bits bit)
{
atomic_andnot(BIT(bit), &tick_dep_mask);
}
void tick_nohz_dep_set_cpu(int cpu, enum tick_dep_bits bit)
{
int prev;
struct tick_sched *ts;
ts = per_cpu_ptr(&tick_cpu_sched, cpu);
prev = atomic_fetch_or(BIT(bit), &ts->tick_dep_mask);
if (!prev) {
preempt_disable();
if (cpu == smp_processor_id()) {
tick_nohz_full_kick();
} else {
if (!WARN_ON_ONCE(in_nmi()))
tick_nohz_full_kick_cpu(cpu);
}
preempt_enable();
}
}
void tick_nohz_dep_clear_cpu(int cpu, enum tick_dep_bits bit)
{
struct tick_sched *ts = per_cpu_ptr(&tick_cpu_sched, cpu);
atomic_andnot(BIT(bit), &ts->tick_dep_mask);
}
void tick_nohz_dep_set_task(struct task_struct *tsk, enum tick_dep_bits bit)
{
tick_nohz_dep_set_all(&tsk->tick_dep_mask, bit);
}
void tick_nohz_dep_clear_task(struct task_struct *tsk, enum tick_dep_bits bit)
{
atomic_andnot(BIT(bit), &tsk->tick_dep_mask);
}
void tick_nohz_dep_set_signal(struct signal_struct *sig, enum tick_dep_bits bit)
{
tick_nohz_dep_set_all(&sig->tick_dep_mask, bit);
}
void tick_nohz_dep_clear_signal(struct signal_struct *sig, enum tick_dep_bits bit)
{
atomic_andnot(BIT(bit), &sig->tick_dep_mask);
}
void __tick_nohz_task_switch(void)
{
unsigned long flags;
struct tick_sched *ts;
local_irq_save(flags);
if (!tick_nohz_full_cpu(smp_processor_id()))
goto out;
ts = this_cpu_ptr(&tick_cpu_sched);
if (ts->tick_stopped) {
if (atomic_read(&current->tick_dep_mask) ||
atomic_read(&current->signal->tick_dep_mask))
tick_nohz_full_kick();
}
out:
local_irq_restore(flags);
}
static int __init tick_nohz_full_setup(char *str)
{
alloc_bootmem_cpumask_var(&tick_nohz_full_mask);
if (cpulist_parse(str, tick_nohz_full_mask) < 0) {
pr_warn("NO_HZ: Incorrect nohz_full cpumask\n");
free_bootmem_cpumask_var(tick_nohz_full_mask);
return 1;
}
tick_nohz_full_running = true;
return 1;
}
static int tick_nohz_cpu_down_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
if (tick_nohz_full_running && tick_do_timer_cpu == cpu)
return NOTIFY_BAD;
break;
}
return NOTIFY_OK;
}
static int tick_nohz_init_all(void)
{
int err = -1;
#ifdef CONFIG_NO_HZ_FULL_ALL
if (!alloc_cpumask_var(&tick_nohz_full_mask, GFP_KERNEL)) {
WARN(1, "NO_HZ: Can't allocate full dynticks cpumask\n");
return err;
}
err = 0;
cpumask_setall(tick_nohz_full_mask);
tick_nohz_full_running = true;
#endif
return err;
}
void __init tick_nohz_init(void)
{
int cpu;
if (!tick_nohz_full_running) {
if (tick_nohz_init_all() < 0)
return;
}
if (!alloc_cpumask_var(&housekeeping_mask, GFP_KERNEL)) {
WARN(1, "NO_HZ: Can't allocate not-full dynticks cpumask\n");
cpumask_clear(tick_nohz_full_mask);
tick_nohz_full_running = false;
return;
}
if (!arch_irq_work_has_interrupt()) {
pr_warn("NO_HZ: Can't run full dynticks because arch doesn't support irq work self-IPIs\n");
cpumask_clear(tick_nohz_full_mask);
cpumask_copy(housekeeping_mask, cpu_possible_mask);
tick_nohz_full_running = false;
return;
}
cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, tick_nohz_full_mask)) {
pr_warn("NO_HZ: Clearing %d from nohz_full range for timekeeping\n",
cpu);
cpumask_clear_cpu(cpu, tick_nohz_full_mask);
}
cpumask_andnot(housekeeping_mask,
cpu_possible_mask, tick_nohz_full_mask);
for_each_cpu(cpu, tick_nohz_full_mask)
context_tracking_cpu_set(cpu);
cpu_notifier(tick_nohz_cpu_down_callback, 0);
pr_info("NO_HZ: Full dynticks CPUs: %*pbl.\n",
cpumask_pr_args(tick_nohz_full_mask));
WARN_ON_ONCE(cpumask_empty(housekeeping_mask));
}
static int __init setup_tick_nohz(char *str)
{
return (kstrtobool(str, &tick_nohz_enabled) == 0);
}
int tick_nohz_tick_stopped(void)
{
return __this_cpu_read(tick_cpu_sched.tick_stopped);
}
static void tick_nohz_update_jiffies(ktime_t now)
{
unsigned long flags;
__this_cpu_write(tick_cpu_sched.idle_waketime, now);
local_irq_save(flags);
tick_do_update_jiffies64(now);
local_irq_restore(flags);
touch_softlockup_watchdog_sched();
}
static void
update_ts_time_stats(int cpu, struct tick_sched *ts, ktime_t now, u64 *last_update_time)
{
ktime_t delta;
if (ts->idle_active) {
delta = ktime_sub(now, ts->idle_entrytime);
if (nr_iowait_cpu(cpu) > 0)
ts->iowait_sleeptime = ktime_add(ts->iowait_sleeptime, delta);
else
ts->idle_sleeptime = ktime_add(ts->idle_sleeptime, delta);
ts->idle_entrytime = now;
}
if (last_update_time)
*last_update_time = ktime_to_us(now);
}
static void tick_nohz_stop_idle(struct tick_sched *ts, ktime_t now)
{
update_ts_time_stats(smp_processor_id(), ts, now, NULL);
ts->idle_active = 0;
sched_clock_idle_wakeup_event(0);
}
static ktime_t tick_nohz_start_idle(struct tick_sched *ts)
{
ktime_t now = ktime_get();
ts->idle_entrytime = now;
ts->idle_active = 1;
sched_clock_idle_sleep_event();
return now;
}
u64 get_cpu_idle_time_us(int cpu, u64 *last_update_time)
{
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t now, idle;
if (!tick_nohz_active)
return -1;
now = ktime_get();
if (last_update_time) {
update_ts_time_stats(cpu, ts, now, last_update_time);
idle = ts->idle_sleeptime;
} else {
if (ts->idle_active && !nr_iowait_cpu(cpu)) {
ktime_t delta = ktime_sub(now, ts->idle_entrytime);
idle = ktime_add(ts->idle_sleeptime, delta);
} else {
idle = ts->idle_sleeptime;
}
}
return ktime_to_us(idle);
}
u64 get_cpu_iowait_time_us(int cpu, u64 *last_update_time)
{
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t now, iowait;
if (!tick_nohz_active)
return -1;
now = ktime_get();
if (last_update_time) {
update_ts_time_stats(cpu, ts, now, last_update_time);
iowait = ts->iowait_sleeptime;
} else {
if (ts->idle_active && nr_iowait_cpu(cpu) > 0) {
ktime_t delta = ktime_sub(now, ts->idle_entrytime);
iowait = ktime_add(ts->iowait_sleeptime, delta);
} else {
iowait = ts->iowait_sleeptime;
}
}
return ktime_to_us(iowait);
}
static void tick_nohz_restart(struct tick_sched *ts, ktime_t now)
{
hrtimer_cancel(&ts->sched_timer);
hrtimer_set_expires(&ts->sched_timer, ts->last_tick);
hrtimer_forward(&ts->sched_timer, now, tick_period);
if (ts->nohz_mode == NOHZ_MODE_HIGHRES)
hrtimer_start_expires(&ts->sched_timer, HRTIMER_MODE_ABS_PINNED);
else
tick_program_event(hrtimer_get_expires(&ts->sched_timer), 1);
}
static ktime_t tick_nohz_stop_sched_tick(struct tick_sched *ts,
ktime_t now, int cpu)
{
struct clock_event_device *dev = __this_cpu_read(tick_cpu_device.evtdev);
u64 basemono, next_tick, next_tmr, next_rcu, delta, expires;
unsigned long seq, basejiff;
ktime_t tick;
do {
seq = read_seqbegin(&jiffies_lock);
basemono = last_jiffies_update.tv64;
basejiff = jiffies;
} while (read_seqretry(&jiffies_lock, seq));
ts->last_jiffies = basejiff;
if (rcu_needs_cpu(basemono, &next_rcu) ||
arch_needs_cpu() || irq_work_needs_cpu()) {
next_tick = basemono + TICK_NSEC;
} else {
next_tmr = get_next_timer_interrupt(basejiff, basemono);
ts->next_timer = next_tmr;
next_tick = next_rcu < next_tmr ? next_rcu : next_tmr;
}
delta = next_tick - basemono;
if (delta <= (u64)TICK_NSEC) {
tick.tv64 = 0;
timer_clear_idle();
if (!ts->tick_stopped)
goto out;
if (delta == 0) {
tick_nohz_restart(ts, now);
goto out;
}
}
delta = timekeeping_max_deferment();
if (cpu == tick_do_timer_cpu) {
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
ts->do_timer_last = 1;
} else if (tick_do_timer_cpu != TICK_DO_TIMER_NONE) {
delta = KTIME_MAX;
ts->do_timer_last = 0;
} else if (!ts->do_timer_last) {
delta = KTIME_MAX;
}
#ifdef CONFIG_NO_HZ_FULL
if (!ts->inidle)
delta = min(delta, scheduler_tick_max_deferment());
#endif
if (delta < (KTIME_MAX - basemono))
expires = basemono + delta;
else
expires = KTIME_MAX;
expires = min_t(u64, expires, next_tick);
tick.tv64 = expires;
if (ts->tick_stopped && (expires == dev->next_event.tv64))
goto out;
if (!ts->tick_stopped) {
nohz_balance_enter_idle(cpu);
calc_load_enter_idle();
cpu_load_update_nohz_start();
ts->last_tick = hrtimer_get_expires(&ts->sched_timer);
ts->tick_stopped = 1;
trace_tick_stop(1, TICK_DEP_MASK_NONE);
}
if (unlikely(expires == KTIME_MAX)) {
if (ts->nohz_mode == NOHZ_MODE_HIGHRES)
hrtimer_cancel(&ts->sched_timer);
goto out;
}
if (ts->nohz_mode == NOHZ_MODE_HIGHRES)
hrtimer_start(&ts->sched_timer, tick, HRTIMER_MODE_ABS_PINNED);
else
tick_program_event(tick, 1);
out:
ts->sleep_length = ktime_sub(dev->next_event, now);
return tick;
}
static void tick_nohz_restart_sched_tick(struct tick_sched *ts, ktime_t now)
{
tick_do_update_jiffies64(now);
cpu_load_update_nohz_stop();
timer_clear_idle();
calc_load_exit_idle();
touch_softlockup_watchdog_sched();
ts->tick_stopped = 0;
ts->idle_exittime = now;
tick_nohz_restart(ts, now);
}
static void tick_nohz_full_update_tick(struct tick_sched *ts)
{
#ifdef CONFIG_NO_HZ_FULL
int cpu = smp_processor_id();
if (!tick_nohz_full_cpu(cpu))
return;
if (!ts->tick_stopped && ts->nohz_mode == NOHZ_MODE_INACTIVE)
return;
if (can_stop_full_tick(ts))
tick_nohz_stop_sched_tick(ts, ktime_get(), cpu);
else if (ts->tick_stopped)
tick_nohz_restart_sched_tick(ts, ktime_get());
#endif
}
static bool can_stop_idle_tick(int cpu, struct tick_sched *ts)
{
if (unlikely(!cpu_online(cpu))) {
if (cpu == tick_do_timer_cpu)
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
return false;
}
if (unlikely(ts->nohz_mode == NOHZ_MODE_INACTIVE)) {
ts->sleep_length = (ktime_t) { .tv64 = NSEC_PER_SEC/HZ };
return false;
}
if (need_resched())
return false;
if (unlikely(local_softirq_pending() && cpu_online(cpu))) {
static int ratelimit;
if (ratelimit < 10 &&
(local_softirq_pending() & SOFTIRQ_STOP_IDLE_MASK)) {
pr_warn("NOHZ: local_softirq_pending %02x\n",
(unsigned int) local_softirq_pending());
ratelimit++;
}
return false;
}
if (tick_nohz_full_enabled()) {
if (tick_do_timer_cpu == cpu)
return false;
if (tick_do_timer_cpu == TICK_DO_TIMER_NONE)
return false;
}
return true;
}
static void __tick_nohz_idle_enter(struct tick_sched *ts)
{
ktime_t now, expires;
int cpu = smp_processor_id();
now = tick_nohz_start_idle(ts);
if (can_stop_idle_tick(cpu, ts)) {
int was_stopped = ts->tick_stopped;
ts->idle_calls++;
expires = tick_nohz_stop_sched_tick(ts, now, cpu);
if (expires.tv64 > 0LL) {
ts->idle_sleeps++;
ts->idle_expires = expires;
}
if (!was_stopped && ts->tick_stopped)
ts->idle_jiffies = ts->last_jiffies;
}
}
void tick_nohz_idle_enter(void)
{
struct tick_sched *ts;
WARN_ON_ONCE(irqs_disabled());
set_cpu_sd_state_idle();
local_irq_disable();
ts = this_cpu_ptr(&tick_cpu_sched);
ts->inidle = 1;
__tick_nohz_idle_enter(ts);
local_irq_enable();
}
void tick_nohz_irq_exit(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
if (ts->inidle)
__tick_nohz_idle_enter(ts);
else
tick_nohz_full_update_tick(ts);
}
ktime_t tick_nohz_get_sleep_length(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
return ts->sleep_length;
}
static void tick_nohz_account_idle_ticks(struct tick_sched *ts)
{
#ifndef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
unsigned long ticks;
if (vtime_accounting_cpu_enabled())
return;
ticks = jiffies - ts->idle_jiffies;
if (ticks && ticks < LONG_MAX)
account_idle_ticks(ticks);
#endif
}
void tick_nohz_idle_exit(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
ktime_t now;
local_irq_disable();
WARN_ON_ONCE(!ts->inidle);
ts->inidle = 0;
if (ts->idle_active || ts->tick_stopped)
now = ktime_get();
if (ts->idle_active)
tick_nohz_stop_idle(ts, now);
if (ts->tick_stopped) {
tick_nohz_restart_sched_tick(ts, now);
tick_nohz_account_idle_ticks(ts);
}
local_irq_enable();
}
static void tick_nohz_handler(struct clock_event_device *dev)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
struct pt_regs *regs = get_irq_regs();
ktime_t now = ktime_get();
dev->next_event.tv64 = KTIME_MAX;
tick_sched_do_timer(now);
tick_sched_handle(ts, regs);
if (unlikely(ts->tick_stopped))
return;
hrtimer_forward(&ts->sched_timer, now, tick_period);
tick_program_event(hrtimer_get_expires(&ts->sched_timer), 1);
}
static inline void tick_nohz_activate(struct tick_sched *ts, int mode)
{
if (!tick_nohz_enabled)
return;
ts->nohz_mode = mode;
if (!test_and_set_bit(0, &tick_nohz_active))
timers_update_migration(true);
}
static void tick_nohz_switch_to_nohz(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
ktime_t next;
if (!tick_nohz_enabled)
return;
if (tick_switch_to_oneshot(tick_nohz_handler))
return;
hrtimer_init(&ts->sched_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
next = tick_init_jiffy_update();
hrtimer_set_expires(&ts->sched_timer, next);
hrtimer_forward_now(&ts->sched_timer, tick_period);
tick_program_event(hrtimer_get_expires(&ts->sched_timer), 1);
tick_nohz_activate(ts, NOHZ_MODE_LOWRES);
}
static inline void tick_nohz_irq_enter(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
ktime_t now;
if (!ts->idle_active && !ts->tick_stopped)
return;
now = ktime_get();
if (ts->idle_active)
tick_nohz_stop_idle(ts, now);
if (ts->tick_stopped)
tick_nohz_update_jiffies(now);
}
static inline void tick_nohz_switch_to_nohz(void) { }
static inline void tick_nohz_irq_enter(void) { }
static inline void tick_nohz_activate(struct tick_sched *ts, int mode) { }
void tick_irq_enter(void)
{
tick_check_oneshot_broadcast_this_cpu();
tick_nohz_irq_enter();
}
static enum hrtimer_restart tick_sched_timer(struct hrtimer *timer)
{
struct tick_sched *ts =
container_of(timer, struct tick_sched, sched_timer);
struct pt_regs *regs = get_irq_regs();
ktime_t now = ktime_get();
tick_sched_do_timer(now);
if (regs)
tick_sched_handle(ts, regs);
if (unlikely(ts->tick_stopped))
return HRTIMER_NORESTART;
hrtimer_forward(timer, now, tick_period);
return HRTIMER_RESTART;
}
static int __init skew_tick(char *str)
{
get_option(&str, &sched_skew_tick);
return 0;
}
void tick_setup_sched_timer(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
ktime_t now = ktime_get();
hrtimer_init(&ts->sched_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ts->sched_timer.function = tick_sched_timer;
hrtimer_set_expires(&ts->sched_timer, tick_init_jiffy_update());
if (sched_skew_tick) {
u64 offset = ktime_to_ns(tick_period) >> 1;
do_div(offset, num_possible_cpus());
offset *= smp_processor_id();
hrtimer_add_expires_ns(&ts->sched_timer, offset);
}
hrtimer_forward(&ts->sched_timer, now, tick_period);
hrtimer_start_expires(&ts->sched_timer, HRTIMER_MODE_ABS_PINNED);
tick_nohz_activate(ts, NOHZ_MODE_HIGHRES);
}
void tick_cancel_sched_timer(int cpu)
{
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
# ifdef CONFIG_HIGH_RES_TIMERS
if (ts->sched_timer.base)
hrtimer_cancel(&ts->sched_timer);
# endif
memset(ts, 0, sizeof(*ts));
}
void tick_clock_notify(void)
{
int cpu;
for_each_possible_cpu(cpu)
set_bit(0, &per_cpu(tick_cpu_sched, cpu).check_clocks);
}
void tick_oneshot_notify(void)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
set_bit(0, &ts->check_clocks);
}
int tick_check_oneshot_change(int allow_nohz)
{
struct tick_sched *ts = this_cpu_ptr(&tick_cpu_sched);
if (!test_and_clear_bit(0, &ts->check_clocks))
return 0;
if (ts->nohz_mode != NOHZ_MODE_INACTIVE)
return 0;
if (!timekeeping_valid_for_hres() || !tick_is_oneshot_available())
return 0;
if (!allow_nohz)
return 1;
tick_nohz_switch_to_nohz();
return 0;
}
