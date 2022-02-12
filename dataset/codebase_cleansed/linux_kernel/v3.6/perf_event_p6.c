static u64 p6_pmu_event_map(int hw_event)
{
return p6_perfmon_event_map[hw_event];
}
static void p6_pmu_disable_all(void)
{
u64 val;
rdmsrl(MSR_P6_EVNTSEL0, val);
val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(MSR_P6_EVNTSEL0, val);
}
static void p6_pmu_enable_all(int added)
{
unsigned long val;
rdmsrl(MSR_P6_EVNTSEL0, val);
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
wrmsrl(MSR_P6_EVNTSEL0, val);
}
static inline void
p6_pmu_disable_event(struct perf_event *event)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
u64 val = P6_NOP_EVENT;
if (cpuc->enabled)
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
(void)wrmsrl_safe(hwc->config_base, val);
}
static void p6_pmu_enable_event(struct perf_event *event)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
u64 val;
val = hwc->config;
if (cpuc->enabled)
val |= ARCH_PERFMON_EVENTSEL_ENABLE;
(void)wrmsrl_safe(hwc->config_base, val);
}
__init int p6_pmu_init(void)
{
switch (boot_cpu_data.x86_model) {
case 1:
case 3:
case 5:
case 6:
case 7:
case 8:
case 11:
case 9:
case 13:
break;
default:
pr_cont("unsupported p6 CPU model %d ",
boot_cpu_data.x86_model);
return -ENODEV;
}
x86_pmu = p6_pmu;
return 0;
}
