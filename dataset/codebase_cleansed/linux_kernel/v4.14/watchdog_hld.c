void arch_touch_nmi_watchdog(void)
{
raw_cpu_write(watchdog_nmi_touch, true);
}
void watchdog_update_hrtimer_threshold(u64 period)
{
watchdog_hrtimer_sample_threshold = period * 2;
}
static bool watchdog_check_timestamp(void)
{
ktime_t delta, now = ktime_get_mono_fast_ns();
delta = now - __this_cpu_read(last_timestamp);
if (delta < watchdog_hrtimer_sample_threshold) {
if (__this_cpu_inc_return(nmi_rearmed) < 10)
return false;
}
__this_cpu_write(nmi_rearmed, 0);
__this_cpu_write(last_timestamp, now);
return true;
}
static inline bool watchdog_check_timestamp(void)
{
return true;
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
if (!watchdog_check_timestamp())
return;
if (is_hardlockup()) {
int this_cpu = smp_processor_id();
if (__this_cpu_read(hard_watchdog_warn) == true)
return;
pr_emerg("Watchdog detected hard LOCKUP on cpu %d", this_cpu);
print_modules();
print_irqtrace_events(current);
if (regs)
show_regs(regs);
else
dump_stack();
if (sysctl_hardlockup_all_cpu_backtrace &&
!test_and_set_bit(0, &hardlockup_allcpu_dumped))
trigger_allbutself_cpu_backtrace();
if (hardlockup_panic)
nmi_panic(regs, "Hard LOCKUP");
__this_cpu_write(hard_watchdog_warn, true);
return;
}
__this_cpu_write(hard_watchdog_warn, false);
return;
}
static int hardlockup_detector_event_create(void)
{
unsigned int cpu = smp_processor_id();
struct perf_event_attr *wd_attr;
struct perf_event *evt;
wd_attr = &wd_hw_attr;
wd_attr->sample_period = hw_nmi_get_sample_period(watchdog_thresh);
evt = perf_event_create_kernel_counter(wd_attr, cpu, NULL,
watchdog_overflow_callback, NULL);
if (IS_ERR(evt)) {
pr_info("Perf event create on CPU %d failed with %ld\n", cpu,
PTR_ERR(evt));
return PTR_ERR(evt);
}
this_cpu_write(watchdog_ev, evt);
return 0;
}
void hardlockup_detector_perf_enable(void)
{
if (hardlockup_detector_event_create())
return;
if (!atomic_fetch_inc(&watchdog_cpus))
pr_info("Enabled. Permanently consumes one hw-PMU counter.\n");
perf_event_enable(this_cpu_read(watchdog_ev));
}
void hardlockup_detector_perf_disable(void)
{
struct perf_event *event = this_cpu_read(watchdog_ev);
if (event) {
perf_event_disable(event);
this_cpu_write(watchdog_ev, NULL);
this_cpu_write(dead_event, event);
cpumask_set_cpu(smp_processor_id(), &dead_events_mask);
atomic_dec(&watchdog_cpus);
}
}
void hardlockup_detector_perf_cleanup(void)
{
int cpu;
for_each_cpu(cpu, &dead_events_mask) {
struct perf_event *event = per_cpu(dead_event, cpu);
if (event)
perf_event_release_kernel(event);
per_cpu(dead_event, cpu) = NULL;
}
cpumask_clear(&dead_events_mask);
}
void __init hardlockup_detector_perf_stop(void)
{
int cpu;
lockdep_assert_cpus_held();
for_each_online_cpu(cpu) {
struct perf_event *event = per_cpu(watchdog_ev, cpu);
if (event)
perf_event_disable(event);
}
}
void __init hardlockup_detector_perf_restart(void)
{
int cpu;
lockdep_assert_cpus_held();
if (!(watchdog_enabled & NMI_WATCHDOG_ENABLED))
return;
for_each_online_cpu(cpu) {
struct perf_event *event = per_cpu(watchdog_ev, cpu);
if (event)
perf_event_enable(event);
}
}
int __init hardlockup_detector_perf_init(void)
{
int ret = hardlockup_detector_event_create();
if (ret) {
pr_info("Perf NMI watchdog permanently disabled\n");
} else {
perf_event_release_kernel(this_cpu_read(watchdog_ev));
this_cpu_write(watchdog_ev, NULL);
}
return ret;
}
