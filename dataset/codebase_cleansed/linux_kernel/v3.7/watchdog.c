static int __init hardlockup_panic_setup(char *str)
{
if (!strncmp(str, "panic", 5))
hardlockup_panic = 1;
else if (!strncmp(str, "nopanic", 7))
hardlockup_panic = 0;
else if (!strncmp(str, "0", 1))
watchdog_enabled = 0;
return 1;
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
watchdog_enabled = 0;
return 1;
}
static int get_softlockup_thresh(void)
{
return watchdog_thresh * 2;
}
static unsigned long get_timestamp(int this_cpu)
{
return cpu_clock(this_cpu) >> 30LL;
}
static u64 get_sample_period(void)
{
return get_softlockup_thresh() * ((u64)NSEC_PER_SEC / 5);
}
static void __touch_watchdog(void)
{
int this_cpu = smp_processor_id();
__this_cpu_write(watchdog_touch_ts, get_timestamp(this_cpu));
}
void touch_softlockup_watchdog(void)
{
__this_cpu_write(watchdog_touch_ts, 0);
}
void touch_all_softlockup_watchdogs(void)
{
int cpu;
for_each_online_cpu(cpu)
per_cpu(watchdog_touch_ts, cpu) = 0;
}
void touch_nmi_watchdog(void)
{
if (watchdog_enabled) {
unsigned cpu;
for_each_present_cpu(cpu) {
if (per_cpu(watchdog_nmi_touch, cpu) != true)
per_cpu(watchdog_nmi_touch, cpu) = true;
}
}
touch_softlockup_watchdog();
}
void touch_softlockup_watchdog_sync(void)
{
__raw_get_cpu_var(softlockup_touch_sync) = true;
__raw_get_cpu_var(watchdog_touch_ts) = 0;
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
unsigned long now = get_timestamp(smp_processor_id());
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
panic("Watchdog detected hard LOCKUP on cpu %d", this_cpu);
else
WARN(1, "Watchdog detected hard LOCKUP on cpu %d", this_cpu);
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
watchdog_interrupt_count();
wake_up_process(__this_cpu_read(softlockup_watchdog));
hrtimer_forward_now(hrtimer, ns_to_ktime(get_sample_period()));
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
if (__this_cpu_read(soft_watchdog_warn) == true)
return HRTIMER_RESTART;
printk(KERN_EMERG "BUG: soft lockup - CPU#%d stuck for %us! [%s:%d]\n",
smp_processor_id(), duration,
current->comm, task_pid_nr(current));
print_modules();
print_irqtrace_events(current);
if (regs)
show_regs(regs);
else
dump_stack();
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
struct hrtimer *hrtimer = &__raw_get_cpu_var(watchdog_hrtimer);
if (!watchdog_enabled) {
kthread_park(current);
return;
}
watchdog_nmi_enable(cpu);
hrtimer_init(hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hrtimer->function = watchdog_timer_fn;
hrtimer_start(hrtimer, ns_to_ktime(get_sample_period()),
HRTIMER_MODE_REL_PINNED);
watchdog_set_prio(SCHED_FIFO, MAX_RT_PRIO - 1);
__touch_watchdog();
}
static void watchdog_disable(unsigned int cpu)
{
struct hrtimer *hrtimer = &__raw_get_cpu_var(watchdog_hrtimer);
if (!watchdog_enabled)
return;
watchdog_set_prio(SCHED_NORMAL, 0);
hrtimer_cancel(hrtimer);
watchdog_nmi_disable(cpu);
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
if (event && event->state > PERF_EVENT_STATE_OFF)
goto out;
if (event != NULL)
goto out_enable;
wd_attr = &wd_hw_attr;
wd_attr->sample_period = hw_nmi_get_sample_period(watchdog_thresh);
event = perf_event_create_kernel_counter(wd_attr, cpu, NULL, watchdog_overflow_callback, NULL);
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
pr_warning("disabled (cpu%i): hardware events not enabled\n",
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
return;
}
static int watchdog_nmi_enable(unsigned int cpu) { return 0; }
static void watchdog_nmi_disable(unsigned int cpu) { return; }
static void watchdog_enable_all_cpus(void)
{
unsigned int cpu;
if (watchdog_disabled) {
watchdog_disabled = 0;
for_each_online_cpu(cpu)
kthread_unpark(per_cpu(softlockup_watchdog, cpu));
}
}
static void watchdog_disable_all_cpus(void)
{
unsigned int cpu;
if (!watchdog_disabled) {
watchdog_disabled = 1;
for_each_online_cpu(cpu)
kthread_park(per_cpu(softlockup_watchdog, cpu));
}
}
int proc_dowatchdog(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
if (watchdog_disabled < 0)
return -ENODEV;
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (ret || !write)
return ret;
if (watchdog_enabled && watchdog_thresh)
watchdog_enable_all_cpus();
else
watchdog_disable_all_cpus();
return ret;
}
void __init lockup_detector_init(void)
{
if (smpboot_register_percpu_thread(&watchdog_threads)) {
pr_err("Failed to create watchdog threads, disabled\n");
watchdog_disabled = -ENODEV;
}
}
