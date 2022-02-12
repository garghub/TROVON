static u64 knc_pmu_event_map(int hw_event)
{
return knc_perfmon_event_map[hw_event];
}
static void knc_pmu_disable_all(void)
{
u64 val;
rdmsrl(MSR_KNC_IA32_PERF_GLOBAL_CTRL, val);
val &= ~(KNC_ENABLE_COUNTER0|KNC_ENABLE_COUNTER1);
wrmsrl(MSR_KNC_IA32_PERF_GLOBAL_CTRL, val);
}
static void knc_pmu_enable_all(int added)
{
u64 val;
rdmsrl(MSR_KNC_IA32_PERF_GLOBAL_CTRL, val);
val |= (KNC_ENABLE_COUNTER0|KNC_ENABLE_COUNTER1);
wrmsrl(MSR_KNC_IA32_PERF_GLOBAL_CTRL, val);
}
static inline void
knc_pmu_disable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 val;
val = hwc->config;
val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
(void)wrmsrl_safe(hwc->config_base + hwc->idx, val);
}
static void knc_pmu_enable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 val;
val = hwc->config;
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
(void)wrmsrl_safe(hwc->config_base + hwc->idx, val);
}
static inline u64 knc_pmu_get_status(void)
{
u64 status;
rdmsrl(MSR_KNC_IA32_PERF_GLOBAL_STATUS, status);
return status;
}
static inline void knc_pmu_ack_status(u64 ack)
{
wrmsrl(MSR_KNC_IA32_PERF_GLOBAL_OVF_CONTROL, ack);
}
static int knc_pmu_handle_irq(struct pt_regs *regs)
{
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
int handled = 0;
int bit, loops;
u64 status;
cpuc = &__get_cpu_var(cpu_hw_events);
knc_pmu_disable_all();
status = knc_pmu_get_status();
if (!status) {
knc_pmu_enable_all(0);
return handled;
}
loops = 0;
again:
knc_pmu_ack_status(status);
if (++loops > 100) {
WARN_ONCE(1, "perf: irq loop stuck!\n");
perf_event_print_debug();
goto done;
}
inc_irq_stat(apic_perf_irqs);
for_each_set_bit(bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct perf_event *event = cpuc->events[bit];
handled++;
if (!test_bit(bit, cpuc->active_mask))
continue;
if (!intel_pmu_save_and_restart(event))
continue;
perf_sample_data_init(&data, 0, event->hw.last_period);
if (perf_event_overflow(event, &data, regs))
x86_pmu_stop(event, 0);
}
status = knc_pmu_get_status();
if (status)
goto again;
done:
knc_pmu_enable_all(0);
return handled;
}
__init int knc_pmu_init(void)
{
x86_pmu = knc_pmu;
memcpy(hw_cache_event_ids, knc_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
return 0;
}
