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
write_seqlock(&xtime_lock);
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
write_sequnlock(&xtime_lock);
}
static ktime_t tick_init_jiffy_update(void)
{
ktime_t period;
write_seqlock(&xtime_lock);
if (last_jiffies_update.tv64 == 0)
last_jiffies_update = tick_next_period;
period = last_jiffies_update;
write_sequnlock(&xtime_lock);
return period;
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
ktime_t now;
now = ktime_get();
update_ts_time_stats(cpu, ts, now, NULL);
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
void tick_nohz_stop_sched_tick(int inidle)
{
unsigned long seq, last_jiffies, next_jiffies, delta_jiffies, flags;
struct tick_sched *ts;
ktime_t last_update, expires, now;
struct clock_event_device *dev = __get_cpu_var(tick_cpu_device).evtdev;
u64 time_delta;
int cpu;
local_irq_save(flags);
cpu = smp_processor_id();
ts = &per_cpu(tick_cpu_sched, cpu);
if (!inidle && !ts->inidle)
goto end;
ts->inidle = 1;
now = tick_nohz_start_idle(cpu, ts);
if (unlikely(!cpu_online(cpu))) {
if (cpu == tick_do_timer_cpu)
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
}
if (unlikely(ts->nohz_mode == NOHZ_MODE_INACTIVE))
goto end;
if (need_resched())
goto end;
if (unlikely(local_softirq_pending() && cpu_online(cpu))) {
static int ratelimit;
if (ratelimit < 10) {
printk(KERN_ERR "NOHZ: local_softirq_pending %02x\n",
(unsigned int) local_softirq_pending());
ratelimit++;
}
goto end;
}
ts->idle_calls++;
do {
seq = read_seqbegin(&xtime_lock);
last_update = last_jiffies_update;
last_jiffies = jiffies;
time_delta = timekeeping_max_deferment();
} while (read_seqretry(&xtime_lock, seq));
if (rcu_needs_cpu(cpu) || printk_needs_cpu(cpu) ||
arch_needs_cpu(cpu)) {
next_jiffies = last_jiffies + 1;
delta_jiffies = 1;
} else {
next_jiffies = get_next_timer_interrupt(last_jiffies);
delta_jiffies = next_jiffies - last_jiffies;
}
if (!ts->tick_stopped && delta_jiffies == 1)
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
if (!ts->tick_stopped) {
select_nohz_load_balancer(1);
ts->idle_tick = hrtimer_get_expires(&ts->sched_timer);
ts->tick_stopped = 1;
ts->idle_jiffies = last_jiffies;
rcu_enter_nohz();
}
ts->idle_sleeps++;
ts->idle_expires = expires;
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
end:
local_irq_restore(flags);
}
ktime_t tick_nohz_get_sleep_length(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
return ts->sleep_length;
}
static void tick_nohz_restart(struct tick_sched *ts, ktime_t now)
{
hrtimer_cancel(&ts->sched_timer);
hrtimer_set_expires(&ts->sched_timer, ts->idle_tick);
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
tick_do_update_jiffies64(now);
now = ktime_get();
}
}
void tick_nohz_restart_sched_tick(void)
{
int cpu = smp_processor_id();
struct tick_sched *ts = &per_cpu(tick_cpu_sched, cpu);
#ifndef CONFIG_VIRT_CPU_ACCOUNTING
unsigned long ticks;
#endif
ktime_t now;
local_irq_disable();
if (ts->idle_active || (ts->inidle && ts->tick_stopped))
now = ktime_get();
if (ts->idle_active)
tick_nohz_stop_idle(cpu, now);
if (!ts->inidle || !ts->tick_stopped) {
ts->inidle = 0;
local_irq_enable();
return;
}
ts->inidle = 0;
rcu_exit_nohz();
select_nohz_load_balancer(0);
tick_do_update_jiffies64(now);
#ifndef CONFIG_VIRT_CPU_ACCOUNTING
ticks = jiffies - ts->idle_jiffies;
if (ticks && ticks < LONG_MAX)
account_idle_ticks(ticks);
#endif
touch_softlockup_watchdog();
ts->tick_stopped = 0;
ts->idle_exittime = now;
tick_nohz_restart(ts, now);
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
int cpu = smp_processor_id();
ktime_t now = ktime_get();
dev->next_event.tv64 = KTIME_MAX;
if (unlikely(tick_do_timer_cpu == TICK_DO_TIMER_NONE))
tick_do_timer_cpu = cpu;
if (tick_do_timer_cpu == cpu)
tick_do_update_jiffies64(now);
if (ts->tick_stopped) {
touch_softlockup_watchdog();
ts->idle_jiffies++;
}
update_process_times(user_mode(regs));
profile_tick(CPU_PROFILING);
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
int cpu = smp_processor_id();
#ifdef CONFIG_NO_HZ
if (unlikely(tick_do_timer_cpu == TICK_DO_TIMER_NONE))
tick_do_timer_cpu = cpu;
#endif
if (tick_do_timer_cpu == cpu)
tick_do_update_jiffies64(now);
if (regs) {
if (ts->tick_stopped) {
touch_softlockup_watchdog();
ts->idle_jiffies++;
}
update_process_times(user_mode(regs));
profile_tick(CPU_PROFILING);
}
hrtimer_forward(timer, now, tick_period);
return HRTIMER_RESTART;
}
void tick_setup_sched_timer(void)
{
struct tick_sched *ts = &__get_cpu_var(tick_cpu_sched);
ktime_t now = ktime_get();
hrtimer_init(&ts->sched_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ts->sched_timer.function = tick_sched_timer;
hrtimer_set_expires(&ts->sched_timer, tick_init_jiffy_update());
for (;;) {
hrtimer_forward(&ts->sched_timer, now, tick_period);
hrtimer_start_expires(&ts->sched_timer,
HRTIMER_MODE_ABS_PINNED);
if (hrtimer_active(&ts->sched_timer))
break;
now = ktime_get();
}
#ifdef CONFIG_NO_HZ
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
ts->nohz_mode = NOHZ_MODE_INACTIVE;
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
