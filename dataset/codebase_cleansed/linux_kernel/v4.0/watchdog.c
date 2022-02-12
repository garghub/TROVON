void watchdog_enable_hardlockup_detector(bool val)
{
hardlockup_detector_enabled = val;
}
bool watchdog_hardlockup_detector_is_enabled(void)
{
return hardlockup_detector_enabled;
}
static int __init hardlockup_panic_setup(char *str)
{
if (!strncmp(str, "panic", 5))
hardlockup_panic = 1;
else if (!strncmp(str, "nopanic", 7))
hardlockup_panic = 0;
else if (!strncmp(str, "0", 1))
watchdog_user_enabled = 0;
else if (!strncmp(str, "1", 1) || !strncmp(str, "2", 1)) {
watchdog_user_enabled = 1;
watchdog_enable_hardlockup_detector(true);
}
return 1;
}
static int __init softlockup_panic_setup(char *str)
{
softlockup_panic = simple_strtoul(str, NULL, 0);
return 1;
}
static int __init nowatchdog_setup(char *str)
{
watchdog_user_enabled = 0;
return 1;
}
static int __init nosoftlockup_setup(char *str)
{
watchdog_user_enabled = 0;
return 1;
}
static int __init softlockup_all_cpu_backtrace_setup(char *str)
{
sysctl_softlockup_all_cpu_backtrace =
!!simple_strtol(str, NULL, 0);
return 1;
}
static int get_softlockup_thresh(void)
{
return watchdog_thresh * 2;
}
static unsigned long get_timestamp(void)
{
return running_clock() >> 30LL;
}
static void set_sample_period(void)
{
sample_period = get_softlockup_thresh() * ((u64)NSEC_PER_SEC / 5);
}
static void __touch_watchdog(void)
{
__this_cpu_write(watchdog_touch_ts, get_timestamp());
}
void touch_softlockup_watchdog(void)
{
raw_cpu_write(watchdog_touch_ts, 0);
}
void touch_all_softlockup_watchdogs(void)
{
int cpu;
for_each_online_cpu(cpu)
per_cpu(watchdog_touch_ts, cpu) = 0;
}
void touch_nmi_watchdog(void)
{
raw_cpu_write(watchdog_nmi_touch, true);
touch_softlockup_watchdog();
}
void touch_softlockup_watchdog_sync(void)
{
__this_cpu_write(softlockup_touch_sync, true);
__this_cpu_write(watchdog_touch_ts, 0);
}
static int is_hardlockup(void)
{
unsigned long hrint = __this_cpu_read(hrtimer_interrupts);
if (__this_cpu_read(hrtimer_interrupts_saved) == hrint)
return 1;
__this_cpu_write(hrtimer_interrupts_saved, hrint);
return 0;
}
static int is_softlockup(unsigned long touch_ts)
{
unsigned long now = get_timestamp();
if (time_after(now, touch_ts + get_softlockup_thresh()))
return now - touch_ts;
return 0;
}
static void watchdog_overflow_callback(struct perf_event *event,
struct perf_sample_data *data,
struct pt_regs *regs)
{
event->hw.interrupts = 0;
if (__this_cpu_read(watchdog_nmi_touch) == true) {
__this_cpu_write(watchdog_nmi_touch, false);
return;
}
if (is_hardlockup()) {
int this_cpu = smp_processor_id();
if (__this_cpu_read(hard_watchdog_warn) == true)
return;
if (hardlockup_panic)
panic("Watchdog detected hard LOCKUP on cpu %d",
this_cpu);
else
WARN(1, "Watchdog detected hard LOCKUP on cpu %d",
this_cpu);
__this_cpu_write(hard_watchdog_warn, true);
return;
}
__this_cpu_write(hard_watchdog_warn, false);
return;
}
static void watchdog_interrupt_count(void)
{
__this_cpu_inc(hrtimer_interrupts);
}
static enum hrtimer_restart watchdog_timer_fn(struct hrtimer *hrtimer)
{
unsigned long touch_ts = __this_cpu_read(watchdog_touch_ts);
struct pt_regs *regs = get_irq_regs();
int duration;
int softlockup_all_cpu_backtrace = sysctl_softlockup_all_cpu_backtrace;
watchdog_interrupt_count();
wake_up_process(__this_cpu_read(softlockup_watchdog));
hrtimer_forward_now(hrtimer, ns_to_ktime(sample_period));
if (touch_ts == 0) {
if (unlikely(__this_cpu_read(softlockup_touch_sync))) {
__this_cpu_write(softlockup_touch_sync, false);
sched_clock_tick();
}
kvm_check_and_clear_guest_paused();
__touch_watchdog();
return HRTIMER_RESTART;
}
duration = is_softlockup(touch_ts);
if (unlikely(duration)) {
if (kvm_check_and_clear_guest_paused())
return HRTIMER_RESTART;
if (__this_cpu_read(soft_watchdog_warn) == true) {
if (__this_cpu_read(softlockup_task_ptr_saved) !=
current) {
__this_cpu_write(soft_watchdog_warn, false);
__touch_watchdog();
}
return HRTIMER_RESTART;
}
if (softlockup_all_cpu_backtrace) {
if (test_and_set_bit(0, &soft_lockup_nmi_warn)) {
__this_cpu_write(soft_watchdog_warn, true);
return HRTIMER_RESTART;
}
}
pr_emerg("BUG: soft lockup - CPU#%d stuck for %us! [%s:%d]\n",
smp_processor_id(), duration,
current->comm, task_pid_nr(current));
__this_cpu_write(softlockup_task_ptr_saved, current);
print_modules();
print_irqtrace_events(current);
if (regs)
show_regs(regs);
else
dump_stack();
if (softlockup_all_cpu_backtrace) {
trigger_allbutself_cpu_backtrace();
clear_bit(0, &soft_lockup_nmi_warn);
smp_mb__after_atomic();
}
add_taint(TAINT_SOFTLOCKUP, LOCKDEP_STILL_OK);
if (softlockup_panic)
panic("softlockup: hung tasks");
__this_cpu_write(soft_watchdog_warn, true);
} else
__this_cpu_write(soft_watchdog_warn, false);
return HRTIMER_RESTART;
}
static void watchdog_set_prio(unsigned int policy, unsigned int prio)
{
struct sched_param param = { .sched_priority = prio };
sched_setscheduler(current, policy, &param);
}
static void watchdog_enable(unsigned int cpu)
{
struct hrtimer *hrtimer = raw_cpu_ptr(&watchdog_hrtimer);
hrtimer_init(hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hrtimer->function = watchdog_timer_fn;
watchdog_nmi_enable(cpu);
hrtimer_start(hrtimer, ns_to_ktime(sample_period),
HRTIMER_MODE_REL_PINNED);
watchdog_set_prio(SCHED_FIFO, MAX_RT_PRIO - 1);
__touch_watchdog();
}
static void watchdog_disable(unsigned int cpu)
{
struct hrtimer *hrtimer = raw_cpu_ptr(&watchdog_hrtimer);
watchdog_set_prio(SCHED_NORMAL, 0);
hrtimer_cancel(hrtimer);
watchdog_nmi_disable(cpu);
}
static void watchdog_cleanup(unsigned int cpu, bool online)
{
watchdog_disable(cpu);
}
static int watchdog_should_run(unsigned int cpu)
{
return __this_cpu_read(hrtimer_interrupts) !=
__this_cpu_read(soft_lockup_hrtimer_cnt);
}
static void watchdog(unsigned int cpu)
{
__this_cpu_write(soft_lockup_hrtimer_cnt,
__this_cpu_read(hrtimer_interrupts));
__touch_watchdog();
}
static int watchdog_nmi_enable(unsigned int cpu)
{
struct perf_event_attr *wd_attr;
struct perf_event *event = per_cpu(watchdog_ev, cpu);
if (!watchdog_hardlockup_detector_is_enabled()) {
event = ERR_PTR(-ENOENT);
goto handle_err;
}
if (event && event->state > PERF_EVENT_STATE_OFF)
goto out;
if (event != NULL)
goto out_enable;
wd_attr = &wd_hw_attr;
wd_attr->sample_period = hw_nmi_get_sample_period(watchdog_thresh);
event = perf_event_create_kernel_counter(wd_attr, cpu, NULL, watchdog_overflow_callback, NULL);
handle_err:
if (cpu == 0 && IS_ERR(event))
cpu0_err = PTR_ERR(event);
if (!IS_ERR(event)) {
if (cpu == 0 || cpu0_err)
pr_info("enabled on all CPUs, permanently consumes one hw-PMU counter.\n");
goto out_save;
}
if (cpu > 0 && (PTR_ERR(event) == cpu0_err))
return PTR_ERR(event);
if (PTR_ERR(event) == -EOPNOTSUPP)
pr_info("disabled (cpu%i): not supported (no LAPIC?)\n", cpu);
else if (PTR_ERR(event) == -ENOENT)
pr_warn("disabled (cpu%i): hardware events not enabled\n",
cpu);
else
pr_err("disabled (cpu%i): unable to create perf event: %ld\n",
cpu, PTR_ERR(event));
return PTR_ERR(event);
out_save:
per_cpu(watchdog_ev, cpu) = event;
out_enable:
perf_event_enable(per_cpu(watchdog_ev, cpu));
out:
return 0;
}
static void watchdog_nmi_disable(unsigned int cpu)
{
struct perf_event *event = per_cpu(watchdog_ev, cpu);
if (event) {
perf_event_disable(event);
per_cpu(watchdog_ev, cpu) = NULL;
perf_event_release_kernel(event);
}
if (cpu == 0) {
cpu0_err = 0;
}
}
static int watchdog_nmi_enable(unsigned int cpu) { return 0; }
static void watchdog_nmi_disable(unsigned int cpu) { return; }
static void restart_watchdog_hrtimer(void *info)
{
struct hrtimer *hrtimer = raw_cpu_ptr(&watchdog_hrtimer);
int ret;
ret = hrtimer_try_to_cancel(hrtimer);
if (ret == 1)
hrtimer_start(hrtimer, ns_to_ktime(sample_period),
HRTIMER_MODE_REL_PINNED);
}
static void update_timers(int cpu)
{
watchdog_nmi_disable(cpu);
smp_call_function_single(cpu, restart_watchdog_hrtimer, NULL, 1);
watchdog_nmi_enable(cpu);
}
static void update_timers_all_cpus(void)
{
int cpu;
get_online_cpus();
for_each_online_cpu(cpu)
update_timers(cpu);
put_online_cpus();
}
static int watchdog_enable_all_cpus(bool sample_period_changed)
{
int err = 0;
if (!watchdog_running) {
err = smpboot_register_percpu_thread(&watchdog_threads);
if (err)
pr_err("Failed to create watchdog threads, disabled\n");
else
watchdog_running = 1;
} else if (sample_period_changed) {
update_timers_all_cpus();
}
return err;
}
static void watchdog_disable_all_cpus(void)
{
if (watchdog_running) {
watchdog_running = 0;
smpboot_unregister_percpu_thread(&watchdog_threads);
}
}
int proc_dowatchdog(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err, old_thresh, old_enabled;
bool old_hardlockup;
static DEFINE_MUTEX(watchdog_proc_mutex);
mutex_lock(&watchdog_proc_mutex);
old_thresh = ACCESS_ONCE(watchdog_thresh);
old_enabled = ACCESS_ONCE(watchdog_user_enabled);
old_hardlockup = watchdog_hardlockup_detector_is_enabled();
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (err || !write)
goto out;
set_sample_period();
if (watchdog_user_enabled && watchdog_thresh) {
if (watchdog_user_enabled != old_enabled)
watchdog_enable_hardlockup_detector(true);
err = watchdog_enable_all_cpus(old_thresh != watchdog_thresh);
} else
watchdog_disable_all_cpus();
if (err) {
watchdog_thresh = old_thresh;
watchdog_user_enabled = old_enabled;
watchdog_enable_hardlockup_detector(old_hardlockup);
}
out:
mutex_unlock(&watchdog_proc_mutex);
return err;
}
void __init lockup_detector_init(void)
{
set_sample_period();
if (watchdog_user_enabled)
watchdog_enable_all_cpus(false);
}
