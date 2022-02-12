static bool test_aperfmperf(int idx)
{
return boot_cpu_has(X86_FEATURE_APERFMPERF);
}
static bool test_intel(int idx)
{
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL ||
boot_cpu_data.x86 != 6)
return false;
switch (boot_cpu_data.x86_model) {
case 30:
case 26:
case 46:
case 37:
case 44:
case 47:
case 42:
case 45:
case 58:
case 62:
case 60:
case 63:
case 69:
case 70:
case 61:
case 86:
case 71:
case 79:
case 55:
case 77:
case 76:
if (idx == PERF_MSR_SMI)
return true;
break;
case 78:
case 94:
if (idx == PERF_MSR_SMI || idx == PERF_MSR_PPERF)
return true;
break;
}
return false;
}
static int msr_event_init(struct perf_event *event)
{
u64 cfg = event->attr.config;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (cfg >= PERF_MSR_EVENT_MAX)
return -EINVAL;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
if (!msr[cfg].attr)
return -EINVAL;
event->hw.idx = -1;
event->hw.event_base = msr[cfg].msr;
event->hw.config = cfg;
return 0;
}
static inline u64 msr_read_counter(struct perf_event *event)
{
u64 now;
if (event->hw.event_base)
rdmsrl(event->hw.event_base, now);
else
rdtscll(now);
return now;
}
static void msr_event_update(struct perf_event *event)
{
u64 prev, now;
s64 delta;
again:
prev = local64_read(&event->hw.prev_count);
now = msr_read_counter(event);
if (local64_cmpxchg(&event->hw.prev_count, prev, now) != prev)
goto again;
delta = now - prev;
if (unlikely(event->hw.event_base == MSR_SMI_COUNT)) {
delta <<= 32;
delta >>= 32;
}
local64_add(now - prev, &event->count);
}
static void msr_event_start(struct perf_event *event, int flags)
{
u64 now;
now = msr_read_counter(event);
local64_set(&event->hw.prev_count, now);
}
static void msr_event_stop(struct perf_event *event, int flags)
{
msr_event_update(event);
}
static void msr_event_del(struct perf_event *event, int flags)
{
msr_event_stop(event, PERF_EF_UPDATE);
}
static int msr_event_add(struct perf_event *event, int flags)
{
if (flags & PERF_EF_START)
msr_event_start(event, flags);
return 0;
}
static int __init msr_init(void)
{
int i, j = 0;
if (!boot_cpu_has(X86_FEATURE_TSC)) {
pr_cont("no MSR PMU driver.\n");
return 0;
}
for (i = PERF_MSR_TSC + 1; i < PERF_MSR_EVENT_MAX; i++) {
u64 val;
if (!msr[i].test(i) || rdmsrl_safe(msr[i].msr, &val))
msr[i].attr = NULL;
}
for (i = 0; i < PERF_MSR_EVENT_MAX; i++) {
if (msr[i].attr)
events_attrs[j++] = &msr[i].attr->attr.attr;
}
events_attrs[j] = NULL;
perf_pmu_register(&pmu_msr, "msr", -1);
return 0;
}
