void hardlockup_detector_disable(void)
{
watchdog_enabled &= ~NMI_WATCHDOG_ENABLED;
}
static int __init hardlockup_panic_setup(char *str)
{
if (!strncmp(str, "panic", 5))
hardlockup_panic = 1;
else if (!strncmp(str, "nopanic", 7))
hardlockup_panic = 0;
else if (!strncmp(str, "0", 1))
watchdog_enabled &= ~NMI_WATCHDOG_ENABLED;
else if (!strncmp(str, "1", 1))
watchdog_enabled |= NMI_WATCHDOG_ENABLED;
return 1;
}
int __weak watchdog_nmi_enable(unsigned int cpu)
{
return 0;
}
void __weak watchdog_nmi_disable(unsigned int cpu)
{
}
void __weak watchdog_nmi_reconfigure(void)
{
}
static int __init softlockup_panic_setup(char *str)
{
softlockup_panic = simple_strtoul(str, NULL, 0);
return 1;
}
static int __init nowatchdog_setup(char *str)
{
watchdog_enabled = 0;
return 1;
}
static int __init nosoftlockup_setup(char *str)
{
watchdog_enabled &= ~SOFT_WATCHDOG_ENABLED;
return 1;
}
static int __init softlockup_all_cpu_backtrace_setup(char *str)
{
sysctl_softlockup_all_cpu_backtrace =
!!simple_strtol(str, NULL, 0);
return 1;
}
static int __init hardlockup_all_cpu_backtrace_setup(char *str)
{
sysctl_hardlockup_all_cpu_backtrace =
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
for_each_watchdog_cpu(cpu)
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
if (atomic_read(&watchdog_park_in_progress) != 0)
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
if (!(watchdog_enabled & NMI_WATCHDOG_ENABLED))
watchdog_nmi_disable(cpu);
}
static int watchdog_park_threads(void)
{
int cpu, ret = 0;
atomic_set(&watchdog_park_in_progress, 1);
for_each_watchdog_cpu(cpu) {
ret = kthread_park(per_cpu(softlockup_watchdog, cpu));
if (ret)
break;
}
atomic_set(&watchdog_park_in_progress, 0);
return ret;
}
static void watchdog_unpark_threads(void)
{
int cpu;
for_each_watchdog_cpu(cpu)
kthread_unpark(per_cpu(softlockup_watchdog, cpu));
}
static int update_watchdog_all_cpus(void)
{
int ret;
ret = watchdog_park_threads();
if (ret)
return ret;
watchdog_unpark_threads();
return 0;
}
static int watchdog_enable_all_cpus(void)
{
int err = 0;
if (!watchdog_running) {
err = smpboot_register_percpu_thread_cpumask(&watchdog_threads,
&watchdog_cpumask);
if (err)
pr_err("Failed to create watchdog threads, disabled\n");
else
watchdog_running = 1;
} else {
err = update_watchdog_all_cpus();
if (err) {
watchdog_disable_all_cpus();
pr_err("Failed to update lockup detectors, disabled\n");
}
}
if (err)
watchdog_enabled = 0;
return err;
}
static void watchdog_disable_all_cpus(void)
{
if (watchdog_running) {
watchdog_running = 0;
smpboot_unregister_percpu_thread(&watchdog_threads);
}
}
static int watchdog_update_cpus(void)
{
return smpboot_update_cpumask_percpu_thread(
&watchdog_threads, &watchdog_cpumask);
}
static int watchdog_park_threads(void)
{
return 0;
}
static void watchdog_unpark_threads(void)
{
}
static int watchdog_enable_all_cpus(void)
{
return 0;
}
static void watchdog_disable_all_cpus(void)
{
}
static int watchdog_update_cpus(void)
{
return 0;
}
static void set_sample_period(void)
{
}
int lockup_detector_suspend(void)
{
int ret = 0;
get_online_cpus();
mutex_lock(&watchdog_proc_mutex);
if (watchdog_running && !watchdog_suspended)
ret = watchdog_park_threads();
if (ret == 0)
watchdog_suspended++;
else {
watchdog_disable_all_cpus();
pr_err("Failed to suspend lockup detectors, disabled\n");
watchdog_enabled = 0;
}
watchdog_nmi_reconfigure();
mutex_unlock(&watchdog_proc_mutex);
return ret;
}
void lockup_detector_resume(void)
{
mutex_lock(&watchdog_proc_mutex);
watchdog_suspended--;
if (watchdog_running && !watchdog_suspended)
watchdog_unpark_threads();
watchdog_nmi_reconfigure();
mutex_unlock(&watchdog_proc_mutex);
put_online_cpus();
}
static int proc_watchdog_update(void)
{
int err = 0;
if (watchdog_enabled && watchdog_thresh)
err = watchdog_enable_all_cpus();
else
watchdog_disable_all_cpus();
watchdog_nmi_reconfigure();
return err;
}
static int proc_watchdog_common(int which, struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err, old, new;
int *watchdog_param = (int *)table->data;
get_online_cpus();
mutex_lock(&watchdog_proc_mutex);
if (watchdog_suspended) {
err = -EAGAIN;
goto out;
}
if (!write) {
*watchdog_param = (watchdog_enabled & which) != 0;
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
} else {
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (err)
goto out;
do {
old = watchdog_enabled;
if (*watchdog_param)
new = old | which;
else
new = old & ~which;
} while (cmpxchg(&watchdog_enabled, old, new) != old);
if (old == new)
goto out;
err = proc_watchdog_update();
}
out:
mutex_unlock(&watchdog_proc_mutex);
put_online_cpus();
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
int err, old, new;
get_online_cpus();
mutex_lock(&watchdog_proc_mutex);
if (watchdog_suspended) {
err = -EAGAIN;
goto out;
}
old = ACCESS_ONCE(watchdog_thresh);
err = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (err || !write)
goto out;
new = ACCESS_ONCE(watchdog_thresh);
if (old == new)
goto out;
set_sample_period();
err = proc_watchdog_update();
if (err) {
watchdog_thresh = old;
set_sample_period();
}
out:
mutex_unlock(&watchdog_proc_mutex);
put_online_cpus();
return err;
}
int proc_watchdog_cpumask(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int err;
get_online_cpus();
mutex_lock(&watchdog_proc_mutex);
if (watchdog_suspended) {
err = -EAGAIN;
goto out;
}
err = proc_do_large_bitmap(table, write, buffer, lenp, ppos);
if (!err && write) {
cpumask_and(&watchdog_cpumask, &watchdog_cpumask,
cpu_possible_mask);
if (watchdog_running) {
if (watchdog_update_cpus() != 0)
pr_err("cpumask update failed\n");
}
watchdog_nmi_reconfigure();
}
out:
mutex_unlock(&watchdog_proc_mutex);
put_online_cpus();
return err;
}
void __init lockup_detector_init(void)
{
set_sample_period();
#ifdef CONFIG_NO_HZ_FULL
if (tick_nohz_full_enabled()) {
pr_info("Disabling watchdog on nohz_full cores by default\n");
cpumask_copy(&watchdog_cpumask, housekeeping_mask);
} else
cpumask_copy(&watchdog_cpumask, cpu_possible_mask);
#else
cpumask_copy(&watchdog_cpumask, cpu_possible_mask);
#endif
if (watchdog_enabled)
watchdog_enable_all_cpus();
}
