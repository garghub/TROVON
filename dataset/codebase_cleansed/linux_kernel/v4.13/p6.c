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
struct hw_perf_event *hwc = &event->hw;
u64 val = P6_NOP_EVENT;
(void)wrmsrl_safe(hwc->config_base, val);
}
static void p6_pmu_enable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 val;
val = hwc->config;
(void)wrmsrl_safe(hwc->config_base, val);
}
static __init void p6_pmu_rdpmc_quirk(void)
{
if (boot_cpu_data.x86_mask < 9) {
pr_warn("Userspace RDPMC support disabled due to a CPU erratum\n");
x86_pmu.attr_rdpmc_broken = 1;
x86_pmu.attr_rdpmc = 0;
}
}
__init int p6_pmu_init(void)
{
x86_pmu = p6_pmu;
switch (boot_cpu_data.x86_model) {
case 1:
x86_add_quirk(p6_pmu_rdpmc_quirk);
break;
case 3:
case 5:
case 6:
break;
case 7:
case 8:
case 10:
case 11:
break;
case 9:
case 13:
break;
default:
pr_cont("unsupported p6 CPU model %d ", boot_cpu_data.x86_model);
return -ENODEV;
}
memcpy(hw_cache_event_ids, p6_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
return 0;
}
