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
}
write_sequnlock(&jiffies_lock);
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
touch_softlockup_watchdog();
if (is_idle_task(current))
ts->idle_jiffies++;
}
#endif
update_process_times(user_mode(regs));
profile_tick(CPU_PROFILING);
}
static bool can_stop_full_tick(void)
{
WARN_ON_ONCE(!irqs_disabled());
if (!sched_can_stop_tick()) {
trace_tick_stop(0, "more than 1 task in runqueue\n");
return false;
}
if (!posix_cpu_timers_can_stop_tick(current)) {
trace_tick_stop(0, "posix timers running\n");
return false;
}
if (!perf_event_can_stop_tick()) {
trace_tick_stop(0, "perf events running\n");
return false;
}
#ifdef CONFIG_HAVE_UNSTABLE_SCHED_CLOCK
if (!sched_clock_stable) {
trace_tick_stop(0, "unstable sched clock\n");
return false;
}
#endif
return true;
}
void tick_nohz_full_check(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
if (tick_nohz_full_cpu(smp_processor_id())) {
if (ts->tick_stopped && !is_idle_task(current)) {
if (!can_stop_full_tick())
tick_nohz_restart_sched_tick(ts, ktime_get());
}
}
}
static void nohz_full_kick_work_func(struct irq_work *work)
{
tick_nohz_full_check();
}
void tick_nohz_full_kick(void)
{
if (tick_nohz_full_cpu(smp_processor_id()))
irq_work_queue(&__get_cpu_var(nohz_full_kick_work));
}
static void nohz_full_kick_ipi(void *info)
{
tick_nohz_full_check();
}
void tick_nohz_full_kick_all(void)
{
if (!have_nohz_full_mask)
return;
preempt_disable();
smp_call_function_many(nohz_full_mask,
nohz_full_kick_ipi, NULL, false);
preempt_enable();
}
void tick_nohz_task_switch(struct task_struct *tsk)
{
unsigned long flags;
local_irq_save(flags);
if (!tick_nohz_full_cpu(smp_processor_id()))
goto out;
if (tick_nohz_tick_stopped() && !can_stop_full_tick())
tick_nohz_full_kick();
out:
local_irq_restore(flags);
}
int tick_nohz_full_cpu(int cpu)
{
if (!have_nohz_full_mask)
return 0;
return cpumask_test_cpu(cpu, nohz_full_mask);
}
static int __init tick_nohz_full_setup(char *str)
{
int cpu;
alloc_bootmem_cpumask_var(&nohz_full_mask);
if (cpulist_parse(str, nohz_full_mask) < 0) {
pr_warning("NOHZ: Incorrect nohz_full cpumask\n");
return 1;
}
cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, nohz_full_mask)) {
pr_warning("NO_HZ: Clearing %d from nohz_full range for timekeeping\n", cpu);
cpumask_clear_cpu(cpu, nohz_full_mask);
}
have_nohz_full_mask = true;
return 1;
}
static int __cpuinit tick_nohz_cpu_down_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
if (have_nohz_full_mask && tick_do_timer_cpu == cpu)
return NOTIFY_BAD;
break;
}
return NOTIFY_OK;
}
static int tick_nohz_init_all(void)
{
int err = -1;
#ifdef CONFIG_NO_HZ_FULL_ALL
if (!alloc_cpumask_var(&nohz_full_mask, GFP_KERNEL)) {
pr_err("NO_HZ: Can't allocate full dynticks cpumask\n");
return err;
}
err = 0;
cpumask_setall(nohz_full_mask);
cpumask_clear_cpu(smp_processor_id(), nohz_full_mask);
have_nohz_full_mask = true;
#endif
return err;
}
void __init tick_nohz_init(void)
{
int cpu;
if (!have_nohz_full_mask) {
if (tick_nohz_init_all() < 0)
return;
}
cpu_notifier(tick_nohz_cpu_down_callback, 0);
for_each_cpu(cpu, nohz_full_mask) {
if (!rcu_is_nocb_cpu(cpu)) {
pr_warning("NO_HZ: CPU %d is not RCU nocb: "
"cleared from nohz_full range", cpu);
cpumask_clear_cpu(cpu, nohz_full_mask);
}
}
cpulist_scnprintf(nohz_full_buf, sizeof(nohz_full_buf), nohz_full_mask);
pr_info("NO_HZ: Full dynticks CPUs: %s.\n", nohz_full_buf);
}
static int __init setup_tick_nohz(char *str)
{
if (!strcmp(str, "off"))
tick_nohz_enabled = 0;
else if (!strcmp(str, "on"))
tick_nohz_enabled = 1;
else
return 0;
return 1;
}
static void tick_nohz_update_jiffies(ktime_t now)
{
int cpu = smp_processor_id();
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
unsigned long flags;
ts->idle_waketime = now;
local_irq_save(flags);
tick_do_update_jiffies64(now);
local_irq_restore(flags);
touch_softlockup_watchdog();
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
static void tick_nohz_stop_idle(int cpu, ktime_t now)
{
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
update_ts_time_stats(cpu, ts, now, NULL);
ts->idle_active = 0;
sched_clock_idle_wakeup_event(0);
}
static ktime_t tick_nohz_start_idle(int cpu, struct tick_sched *ts)
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
if (!tick_nohz_enabled)
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
if (!tick_nohz_enabled)
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
static ktime_t tick_nohz_stop_sched_tick(struct tick_sched *ts,
ktime_t now, int cpu)
{
unsigned long seq, last_jiffies, next_jiffies, delta_jiffies;
ktime_t last_update, expires, ret = { .tv64 = 0 };
unsigned long rcu_delta_jiffies;
struct clock_event_device *dev = __get_cpu_var(tick_cpu_device).evtdev;
u64 time_delta;
do {
seq = read_seqbegin(&jiffies_lock);
last_update = last_jiffies_update;
last_jiffies = jiffies;
time_delta = timekeeping_max_deferment();
} while (read_seqretry(&jiffies_lock, seq));
if (rcu_needs_cpu(cpu, &rcu_delta_jiffies) ||
arch_needs_cpu(cpu) || irq_work_needs_cpu()) {
next_jiffies = last_jiffies + 1;
delta_jiffies = 1;
} else {
next_jiffies = get_next_timer_interrupt(last_jiffies);
delta_jiffies = next_jiffies - last_jiffies;
if (rcu_delta_jiffies < delta_jiffies) {
next_jiffies = last_jiffies + rcu_delta_jiffies;
delta_jiffies = rcu_delta_jiffies;
}
}
if (!ts->tick_stopped && delta_jiffies <= 1)
goto out;
if ((long)delta_jiffies >= 1) {
if (cpu == tick_do_timer_cpu) {
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
ts->do_timer_last = 1;
} else if (tick_do_timer_cpu != TICK_DO_TIMER_NONE) {
time_delta = KTIME_MAX;
ts->do_timer_last = 0;
} else if (!ts->do_timer_last) {
time_delta = KTIME_MAX;
}
#ifdef CONFIG_NO_HZ_FULL
if (!ts->inidle) {
time_delta = min(time_delta,
scheduler_tick_max_deferment());
}
#endif
if (likely(delta_jiffies < NEXT_TIMER_MAX_DELTA)) {
time_delta = min_t(u64, time_delta,
tick_period.tv64 * delta_jiffies);
}
if (time_delta < KTIME_MAX)
expires = ktime_add_ns(last_update, time_delta);
else
expires.tv64 = KTIME_MAX;
if (ts->tick_stopped && ktime_equal(expires, dev->next_event))
goto out;
ret = expires;
if (!ts->tick_stopped) {
nohz_balance_enter_idle(cpu);
calc_load_enter_idle();
ts->last_tick = hrtimer_get_expires(&ts->sched_timer);
ts->tick_stopped = 1;
trace_tick_stop(1, " ");
}
if (unlikely(expires.tv64 == KTIME_MAX)) {
if (ts->nohz_mode == NOHZ_MODE_HIGHRES)
hrtimer_cancel(&ts->sched_timer);
goto out;
}
if (ts->nohz_mode == NOHZ_MODE_HIGHRES) {
hrtimer_start(&ts->sched_timer, expires,
HRTIMER_MODE_ABS_PINNED);
if (hrtimer_active(&ts->sched_timer))
goto out;
} else if (!tick_program_event(expires, 0))
goto out;
tick_do_update_jiffies64(ktime_get());
}
raise_softirq_irqoff(TIMER_SOFTIRQ);
out:
ts->next_jiffies = next_jiffies;
ts->last_jiffies = last_jiffies;
ts->sleep_length = ktime_sub(dev->next_event, now);
return ret;
}
static void tick_nohz_full_stop_tick(struct tick_sched *ts)
{
#ifdef CONFIG_NO_HZ_FULL
int cpu = smp_processor_id();
if (!tick_nohz_full_cpu(cpu) || is_idle_task(current))
return;
if (!ts->tick_stopped && ts->nohz_mode == NOHZ_MODE_INACTIVE)
return;
if (!can_stop_full_tick())
return;
tick_nohz_stop_sched_tick(ts, ktime_get(), cpu);
#endif
}
static bool can_stop_idle_tick(int cpu, struct tick_sched *ts)
{
if (unlikely(!cpu_online(cpu))) {
if (cpu == tick_do_timer_cpu)
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
return false;
}
if (unlikely(ts->nohz_mode == NOHZ_MODE_INACTIVE))
return false;
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
if (have_nohz_full_mask) {
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
now = tick_nohz_start_idle(cpu, ts);
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
ts = &__get_cpu_var(tick_cpu_sched);
ts->inidle = 1;
__tick_nohz_idle_enter(ts);
local_irq_enable();
}
void tick_nohz_irq_exit(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
if (ts->inidle) {
menu_hrtimer_cancel();
__tick_nohz_idle_enter(ts);
} else {
tick_nohz_full_stop_tick(ts);
}
}
ktime_t tick_nohz_get_sleep_length(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
return ts->sleep_length;
}
static void tick_nohz_restart(struct tick_sched *ts, ktime_t now)
{
hrtimer_cancel(&ts->sched_timer);
hrtimer_set_expires(&ts->sched_timer, ts->last_tick);
while (1) {
hrtimer_forward(&ts->sched_timer, now, tick_period);
if (ts->nohz_mode == NOHZ_MODE_HIGHRES) {
hrtimer_start_expires(&ts->sched_timer,
HRTIMER_MODE_ABS_PINNED);
if (hrtimer_active(&ts->sched_timer))
break;
} else {
if (!tick_program_event(
hrtimer_get_expires(&ts->sched_timer), 0))
break;
}
now = ktime_get();
tick_do_update_jiffies64(now);
}
}
static void tick_nohz_restart_sched_tick(struct tick_sched *ts, ktime_t now)
{
tick_do_update_jiffies64(now);
update_cpu_load_nohz();
calc_load_exit_idle();
touch_softlockup_watchdog();
ts->tick_stopped = 0;
ts->idle_exittime = now;
tick_nohz_restart(ts, now);
}
static void tick_nohz_account_idle_ticks(struct tick_sched *ts)
{
#ifndef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
unsigned long ticks;
if (vtime_accounting_enabled())
return;
ticks = jiffies - ts->idle_jiffies;
if (ticks && ticks < LONG_MAX)
account_idle_ticks(ticks);
#endif
}
void tick_nohz_idle_exit(void)
{
int cpu = smp_processor_id();
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t now;
local_irq_disable();
WARN_ON_ONCE(!ts->inidle);
ts->inidle = 0;
menu_hrtimer_cancel();
if (ts->idle_active || ts->tick_stopped)
now = ktime_get();
if (ts->idle_active)
tick_nohz_stop_idle(cpu, now);
if (ts->tick_stopped) {
tick_nohz_restart_sched_tick(ts, now);
tick_nohz_account_idle_ticks(ts);
}
local_irq_enable();
}
static int tick_nohz_reprogram(struct tick_sched *ts, ktime_t now)
{
hrtimer_forward(&ts->sched_timer, now, tick_period);
return tick_program_event(hrtimer_get_expires(&ts->sched_timer), 0);
}
static void tick_nohz_handler(struct clock_event_device *dev)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
struct pt_regs *regs = get_irq_regs();
ktime_t now = ktime_get();
dev->next_event.tv64 = KTIME_MAX;
tick_sched_do_timer(now);
tick_sched_handle(ts, regs);
while (tick_nohz_reprogram(ts, now)) {
now = ktime_get();
tick_do_update_jiffies64(now);
}
}
static void tick_nohz_switch_to_nohz(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
ktime_t next;
if (!tick_nohz_enabled)
return;
local_irq_disable();
if (tick_switch_to_oneshot(tick_nohz_handler)) {
local_irq_enable();
return;
}
ts->nohz_mode = NOHZ_MODE_LOWRES;
hrtimer_init(&ts->sched_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
next = tick_init_jiffy_update();
for (;;) {
hrtimer_set_expires(&ts->sched_timer, next);
if (!tick_program_event(next, 0))
break;
next = ktime_add(next, tick_period);
}
local_irq_enable();
}
static void tick_nohz_kick_tick(int cpu, ktime_t now)
{
#if 0
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t delta;
delta = ktime_sub(hrtimer_get_expires(&ts->sched_timer), now);
if (delta.tv64 <= tick_period.tv64)
return;
tick_nohz_restart(ts, now);
#endif
}
static inline void tick_check_nohz(int cpu)
{
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
ktime_t now;
if (!ts->idle_active && !ts->tick_stopped)
return;
now = ktime_get();
if (ts->idle_active)
tick_nohz_stop_idle(cpu, now);
if (ts->tick_stopped) {
tick_nohz_update_jiffies(now);
tick_nohz_kick_tick(cpu, now);
}
}
static inline void tick_nohz_switch_to_nohz(void) { }
static inline void tick_check_nohz(int cpu) { }
void tick_check_idle(int cpu)
{
tick_check_oneshot_broadcast(cpu);
tick_check_nohz(cpu);
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
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
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
for (;;) {
hrtimer_forward(&ts->sched_timer, now, tick_period);
hrtimer_start_expires(&ts->sched_timer,
HRTIMER_MODE_ABS_PINNED);
if (hrtimer_active(&ts->sched_timer))
break;
now = ktime_get();
}
#ifdef CONFIG_NO_HZ_COMMON
if (tick_nohz_enabled)
ts->nohz_mode = NOHZ_MODE_HIGHRES;
#endif
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
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
set_bit(0, &ts->check_clocks);
}
int tick_check_oneshot_change(int allow_nohz)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
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
