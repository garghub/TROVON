static u64 amd_pmu_event_map(int hw_event)
{
return amd_perfmon_event_map[hw_event];
}
static int amd_pmu_hw_config(struct perf_event *event)
{
int ret = x86_pmu_hw_config(event);
if (ret)
return ret;
if (event->attr.type != PERF_TYPE_RAW)
return 0;
event->hw.config |= event->attr.config & AMD64_RAW_EVENT_MASK;
return 0;
}
static inline unsigned int amd_get_event_code(struct hw_perf_event *hwc)
{
return ((hwc->config >> 24) & 0x0f00) | (hwc->config & 0x00ff);
}
static inline int amd_is_nb_event(struct hw_perf_event *hwc)
{
return (hwc->config & 0xe0) == 0xe0;
}
static inline int amd_has_nb(struct cpu_hw_events *cpuc)
{
struct amd_nb *nb = cpuc->amd_nb;
return nb && nb->nb_id != -1;
}
static void amd_put_event_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct amd_nb *nb = cpuc->amd_nb;
int i;
if (!(amd_has_nb(cpuc) && amd_is_nb_event(hwc)))
return;
for (i = 0; i < x86_pmu.num_counters; i++) {
if (nb->owners[i] == event) {
cmpxchg(nb->owners+i, event, NULL);
break;
}
}
}
static struct event_constraint *
amd_get_event_constraints(struct cpu_hw_events *cpuc, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct amd_nb *nb = cpuc->amd_nb;
struct perf_event *old = NULL;
int max = x86_pmu.num_counters;
int i, j, k = -1;
if (!(amd_has_nb(cpuc) && amd_is_nb_event(hwc)))
return &unconstrained;
for (i = 0; i < max; i++) {
if (k == -1 && !nb->owners[i])
k = i;
if (nb->owners[i] == event)
goto done;
}
if (hwc->idx != -1) {
i = hwc->idx;
} else if (k != -1) {
i = k;
} else {
i = 0;
}
j = i;
do {
old = cmpxchg(nb->owners+i, NULL, event);
if (!old)
break;
if (++i == max)
i = 0;
} while (i != j);
done:
if (!old)
return &nb->event_constraints[i];
return &emptyconstraint;
}
static struct amd_nb *amd_alloc_nb(int cpu)
{
struct amd_nb *nb;
int i;
nb = kmalloc_node(sizeof(struct amd_nb), GFP_KERNEL | __GFP_ZERO,
cpu_to_node(cpu));
if (!nb)
return NULL;
nb->nb_id = -1;
for (i = 0; i < x86_pmu.num_counters; i++) {
__set_bit(i, nb->event_constraints[i].idxmsk);
nb->event_constraints[i].weight = 1;
}
return nb;
}
static int amd_pmu_cpu_prepare(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
WARN_ON_ONCE(cpuc->amd_nb);
if (boot_cpu_data.x86_max_cores < 2)
return NOTIFY_OK;
cpuc->amd_nb = amd_alloc_nb(cpu);
if (!cpuc->amd_nb)
return NOTIFY_BAD;
return NOTIFY_OK;
}
static void amd_pmu_cpu_starting(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
struct amd_nb *nb;
int i, nb_id;
if (boot_cpu_data.x86_max_cores < 2)
return;
nb_id = amd_get_nb_id(cpu);
WARN_ON_ONCE(nb_id == BAD_APICID);
for_each_online_cpu(i) {
nb = per_cpu(cpu_hw_events, i).amd_nb;
if (WARN_ON_ONCE(!nb))
continue;
if (nb->nb_id == nb_id) {
kfree(cpuc->amd_nb);
cpuc->amd_nb = nb;
break;
}
}
cpuc->amd_nb->nb_id = nb_id;
cpuc->amd_nb->refcnt++;
}
static void amd_pmu_cpu_dead(int cpu)
{
struct cpu_hw_events *cpuhw;
if (boot_cpu_data.x86_max_cores < 2)
return;
cpuhw = &per_cpu(cpu_hw_events, cpu);
if (cpuhw->amd_nb) {
struct amd_nb *nb = cpuhw->amd_nb;
if (nb->nb_id == -1 || --nb->refcnt == 0)
kfree(nb);
cpuhw->amd_nb = NULL;
}
}
static struct event_constraint *
amd_get_event_constraints_f15h(struct cpu_hw_events *cpuc, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
unsigned int event_code = amd_get_event_code(hwc);
switch (event_code & AMD_EVENT_TYPE_MASK) {
case AMD_EVENT_FP:
switch (event_code) {
case 0x000:
if (!(hwc->config & 0x0000F000ULL))
break;
if (!(hwc->config & 0x00000F00ULL))
break;
return &amd_f15_PMC3;
case 0x004:
if (hweight_long(hwc->config & ARCH_PERFMON_EVENTSEL_UMASK) <= 1)
break;
return &amd_f15_PMC3;
case 0x003:
case 0x00B:
case 0x00D:
return &amd_f15_PMC3;
}
return &amd_f15_PMC53;
case AMD_EVENT_LS:
case AMD_EVENT_DC:
case AMD_EVENT_EX_LS:
switch (event_code) {
case 0x023:
case 0x043:
case 0x045:
case 0x046:
case 0x054:
case 0x055:
return &amd_f15_PMC20;
case 0x02D:
return &amd_f15_PMC3;
case 0x02E:
return &amd_f15_PMC30;
default:
return &amd_f15_PMC50;
}
case AMD_EVENT_CU:
case AMD_EVENT_IC_DE:
case AMD_EVENT_DE:
switch (event_code) {
case 0x08F:
case 0x187:
case 0x188:
return &amd_f15_PMC0;
case 0x0DB ... 0x0DF:
case 0x1D6:
case 0x1D8:
return &amd_f15_PMC50;
default:
return &amd_f15_PMC20;
}
case AMD_EVENT_NB:
return &emptyconstraint;
default:
return &emptyconstraint;
}
}
static __init int amd_pmu_init(void)
{
if (boot_cpu_data.x86 < 6)
return -ENODEV;
switch (boot_cpu_data.x86) {
case 0x15:
if (!cpu_has_perfctr_core)
return -ENODEV;
x86_pmu = amd_pmu_f15h;
break;
default:
if (cpu_has_perfctr_core)
return -ENODEV;
x86_pmu = amd_pmu;
break;
}
memcpy(hw_cache_event_ids, amd_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
return 0;
}
static int amd_pmu_init(void)
{
return 0;
}
