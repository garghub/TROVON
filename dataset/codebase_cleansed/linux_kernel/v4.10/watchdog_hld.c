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
void touch_nmi_watchdog(void)
{
raw_cpu_write(watchdog_nmi_touch, true);
touch_softlockup_watchdog();
}
static void watchdog_overflow_callback(struct perf_event *event,
struct perf_sample_data *data,
struct pt_regs *regs)
{
event->hw.interrupts = 0;
if (atomic_read(&watchdog_park_in_progress) != 0)
return;
if (__this_cpu_read(watchdog_nmi_touch) == true) {
__this_cpu_write(watchdog_nmi_touch, false);
return;
}
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
int watchdog_nmi_enable(unsigned int cpu)
{
struct perf_event_attr *wd_attr;
struct perf_event *event = per_cpu(watchdog_ev, cpu);
if (!(watchdog_enabled & NMI_WATCHDOG_ENABLED))
goto out;
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
smp_mb__before_atomic();
clear_bit(NMI_WATCHDOG_ENABLED_BIT, &watchdog_enabled);
smp_mb__after_atomic();
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
pr_info("Shutting down hard lockup detector on all cpus\n");
return PTR_ERR(event);
out_save:
per_cpu(watchdog_ev, cpu) = event;
out_enable:
perf_event_enable(per_cpu(watchdog_ev, cpu));
out:
return 0;
}
void watchdog_nmi_disable(unsigned int cpu)
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
