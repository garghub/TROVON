void __init hardlockup_detector_disable(void)
{
nmi_watchdog_user_enabled = 0;
}
static int __init hardlockup_panic_setup(char *str)
{
if (!strncmp(str, "panic", 5))
hardlockup_panic = 1;
else if (!strncmp(str, "nopanic", 7))
hardlockup_panic = 0;
else if (!strncmp(str, "0", 1))
nmi_watchdog_user_enabled = 0;
else if (!strncmp(str, "1", 1))
nmi_watchdog_user_enabled = 1;
return 1;
}
static int __init hardlockup_all_cpu_backtrace_setup(char *str)
{
sysctl_hardlockup_all_cpu_backtrace = !!simple_strtol(str, NULL, 0);
return 1;
}
int __weak watchdog_nmi_enable(unsigned int cpu)
{
hardlockup_detector_perf_enable();
return 0;
}
void __weak watchdog_nmi_disable(unsigned int cpu)
{
hardlockup_detector_perf_disable();
}
int __weak __init watchdog_nmi_probe(void)
{
return hardlockup_detector_perf_init();
}
void __weak watchdog_nmi_stop(void) { }
void __weak watchdog_nmi_start(void) { }
static void lockup_detector_update_enable(void)
{
watchdog_enabled = 0;
if (!watchdog_user_enabled)
return;
if (nmi_watchdog_available && nmi_watchdog_user_enabled)
watchdog_enabled |= NMI_WATCHDOG_ENABLED;
if (soft_watchdog_user_enabled)
watchdog_enabled |= SOFT_WATCHDOG_ENABLED;
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
soft_watchdog_user_enabled = 0;
return 1;
}
static int __init softlockup_all_cpu_backtrace_setup(char *str)
{
sysctl_softlockup_all_cpu_backtrace = !!simple_strtol(str, NULL, 0);
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
watchdog_update_hrtimer_threshold(sample_period);
}
static void __touch_watchdog(void)
{
__this_cpu_write(watchdog_touch_ts, get_timestamp());
}
void touch_softlockup_watchdog_sched(void)
{
raw_cpu_write(watchdog_touch_ts, 0);
}
void touch_softlockup_watchdog(void)
{
touch_softlockup_watchdog_sched();
wq_watchdog_touch(raw_smp_processor_id());
}
void touch_all_softlockup_watchdogs(void)
{
int cpu;
for_each_cpu(cpu, &watchdog_allowed_mask)
per_cpu(watchdog_touch_ts, cpu) = 0;
wq_watchdog_touch(-1);
}
void touch_softlockup_watchdog_sync(void)
{
__this_cpu_write(softlockup_touch_sync, true);
__this_cpu_write(watchdog_touch_ts, 0);
}
static int is_softlockup(unsigned long touch_ts)
{
unsigned long now = get_timestamp();
if ((watchdog_enabled & SOFT_WATCHDOG_ENABLED) && watchdog_thresh){
if (time_after(now, touch_ts + get_softlockup_thresh()))
return now - touch_ts;
}
return 0;
}
bool is_hardlockup(void)
{
unsigned long hrint = __this_cpu_read(hrtimer_interrupts);
if (__this_cpu_read(hrtimer_interrupts_saved) == hrint)
return true;
__this_cpu_write(hrtimer_interrupts_saved, hrint);
return false;
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
if (!watchdog_enabled)
return HRTIMER_NORESTART;
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
struct hrtimer *hrtimer = this_cpu_ptr(&watchdog_hrtimer);
hrtimer_init(hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hrtimer->function = watchdog_timer_fn;
hrtimer_start(hrtimer, ns_to_ktime(sample_period),
HRTIMER_MODE_REL_PINNED);
__touch_watchdog();
if (watchdog_enabled & NMI_WATCHDOG_ENABLED)
watchdog_nmi_enable(cpu);
watchdog_set_prio(SCHED_FIFO, MAX_RT_PRIO - 1);
}
static void watchdog_disable(unsigned int cpu)
{
struct hrtimer *hrtimer = this_cpu_ptr(&watchdog_hrtimer);
watchdog_set_prio(SCHED_NORMAL, 0);
watchdog_nmi_disable(cpu);
hrtimer_cancel(hrtimer);
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
static void softlockup_update_smpboot_threads(void)
{
lockdep_assert_held(&watchdog_mutex);
if (!softlockup_threads_initialized)
return;
smpboot_update_cpumask_percpu_thread(&watchdog_threads,
&watchdog_allowed_mask);
}
static void softlockup_park_all_threads(void)
{
cpumask_clear(&watchdog_allowed_mask);
softlockup_update_smpboot_threads();
}
static void softlockup_unpark_threads(void)
{
cpumask_copy(&watchdog_allowed_mask, &watchdog_cpumask);
softlockup_update_smpboot_threads();
}
static void lockup_detector_reconfigure(void)
{
cpus_read_lock();
watchdog_nmi_stop();
softlockup_park_all_threads();
set_sample_period();
lockup_detector_update_enable();
if (watchdog_enabled && watchdog_thresh)
softlockup_unpark_threads();
watchdog_nmi_start();
cpus_read_unlock();
__lockup_detector_cleanup();
}
static __init void lockup_detector_setup(void)
{
int ret;
lockup_detector_update_enable();
if (!IS_ENABLED(CONFIG_SYSCTL) &&
!(watchdog_enabled && watchdog_thresh))
return;
ret = smpboot_register_percpu_thread_cpumask(&watchdog_threads,
&watchdog_allowed_mask);
if (ret) {
pr_err("Failed to initialize soft lockup detector threads\n");
return;
}
mutex_lock(&watchdog_mutex);
softlockup_threads_initialized = true;
lockup_detector_reconfigure();
mutex_unlock(&watchdog_mutex);
}
static inline int watchdog_park_threads(void) { return 0; }
static inline void watchdog_unpark_threads(void) { }
static inline int watchdog_enable_all_cpus(void) { return 0; }
static inline void watchdog_disable_all_cpus(void) { }
static void lockup_detector_reconfigure(void)
{
cpus_read_lock();
watchdog_nmi_stop();
lockup_detector_update_enable();
watchdog_nmi_start();
cpus_read_unlock();
}
static inline void lockup_detector_setup(void)
{
lockup_detector_reconfigure();
}
static void __lockup_detector_cleanup(void)
{
lockdep_assert_held(&watchdog_mutex);
hardlockup_detector_perf_cleanup();
}
void lockup_detector_cleanup(void)
{
mutex_lock(&watchdog_mutex);
__lockup_detector_cleanup();
mutex_unlock(&watchdog_mutex);
}
void lockup_detector_soft_poweroff(void)
{
watchdog_enabled = 0;
}
static void proc_watchdog_update(void)
{
cpumask_and(&watchdog_cpumask, &watchdog_cpumask, cpu_possible_mask);
lockup_detector_reconfigure();
}
static int proc_watchdog_common(int which, struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err, old, *param = table->data;
mutex_lock(&watchdog_mutex);
if (!write) {
*param = (watchdog_enabled & which) != 0;
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
} else {
old = READ_ONCE(*param);
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (!err && old != READ_ONCE(*param))
proc_watchdog_update();
}
mutex_unlock(&watchdog_mutex);
return err;
}
int proc_watchdog(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_watchdog_common(NMI_WATCHDOG_ENABLED|SOFT_WATCHDOG_ENABLED,
table, write, buffer, lenp, ppos);
}
int proc_nmi_watchdog(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
if (!nmi_watchdog_available && write)
return -ENOTSUPP;
return proc_watchdog_common(NMI_WATCHDOG_ENABLED,
table, write, buffer, lenp, ppos);
}
int proc_soft_watchdog(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_watchdog_common(SOFT_WATCHDOG_ENABLED,
table, write, buffer, lenp, ppos);
}
int proc_watchdog_thresh(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err, old;
mutex_lock(&watchdog_mutex);
old = READ_ONCE(watchdog_thresh);
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (!err && write && old != READ_ONCE(watchdog_thresh))
proc_watchdog_update();
mutex_unlock(&watchdog_mutex);
return err;
}
int proc_watchdog_cpumask(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err;
mutex_lock(&watchdog_mutex);
err = proc_do_large_bitmap(table, write, buffer, lenp, ppos);
if (!err && write)
proc_watchdog_update();
mutex_unlock(&watchdog_mutex);
return err;
}
void __init lockup_detector_init(void)
{
#ifdef CONFIG_NO_HZ_FULL
if (tick_nohz_full_enabled()) {
pr_info("Disabling watchdog on nohz_full cores by default\n");
cpumask_copy(&watchdog_cpumask, housekeeping_mask);
} else
cpumask_copy(&watchdog_cpumask, cpu_possible_mask);
#else
cpumask_copy(&watchdog_cpumask, cpu_possible_mask);
#endif
if (!watchdog_nmi_probe())
nmi_watchdog_available = true;
lockup_detector_setup();
}
