static inline u64 rapl_read_counter(struct perf_event *event)
{
u64 raw;
rdmsrl(event->hw.event_base, raw);
return raw;
}
static inline u64 rapl_scale(u64 v, int cfg)
{
if (cfg > NR_RAPL_DOMAINS) {
pr_warn("invalid domain %d, failed to scale data\n", cfg);
return v;
}
return v << (32 - rapl_hw_unit[cfg - 1]);
}
static u64 rapl_event_update(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 prev_raw_count, new_raw_count;
s64 delta, sdelta;
int shift = RAPL_CNTR_WIDTH;
again:
prev_raw_count = local64_read(&hwc->prev_count);
rdmsrl(event->hw.event_base, new_raw_count);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count) {
cpu_relax();
goto again;
}
delta = (new_raw_count << shift) - (prev_raw_count << shift);
delta >>= shift;
sdelta = rapl_scale(delta, event->hw.config);
local64_add(sdelta, &event->count);
return new_raw_count;
}
static void rapl_start_hrtimer(struct rapl_pmu *pmu)
{
hrtimer_start(&pmu->hrtimer, pmu->timer_interval,
HRTIMER_MODE_REL_PINNED);
}
static void rapl_stop_hrtimer(struct rapl_pmu *pmu)
{
hrtimer_cancel(&pmu->hrtimer);
}
static enum hrtimer_restart rapl_hrtimer_handle(struct hrtimer *hrtimer)
{
struct rapl_pmu *pmu = __this_cpu_read(rapl_pmu);
struct perf_event *event;
unsigned long flags;
if (!pmu->n_active)
return HRTIMER_NORESTART;
spin_lock_irqsave(&pmu->lock, flags);
list_for_each_entry(event, &pmu->active_list, active_entry) {
rapl_event_update(event);
}
spin_unlock_irqrestore(&pmu->lock, flags);
hrtimer_forward_now(hrtimer, pmu->timer_interval);
return HRTIMER_RESTART;
}
static void rapl_hrtimer_init(struct rapl_pmu *pmu)
{
struct hrtimer *hr = &pmu->hrtimer;
hrtimer_init(hr, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hr->function = rapl_hrtimer_handle;
}
static void __rapl_pmu_event_start(struct rapl_pmu *pmu,
struct perf_event *event)
{
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
event->hw.state = 0;
list_add_tail(&event->active_entry, &pmu->active_list);
local64_set(&event->hw.prev_count, rapl_read_counter(event));
pmu->n_active++;
if (pmu->n_active == 1)
rapl_start_hrtimer(pmu);
}
static void rapl_pmu_event_start(struct perf_event *event, int mode)
{
struct rapl_pmu *pmu = __this_cpu_read(rapl_pmu);
unsigned long flags;
spin_lock_irqsave(&pmu->lock, flags);
__rapl_pmu_event_start(pmu, event);
spin_unlock_irqrestore(&pmu->lock, flags);
}
static void rapl_pmu_event_stop(struct perf_event *event, int mode)
{
struct rapl_pmu *pmu = __this_cpu_read(rapl_pmu);
struct hw_perf_event *hwc = &event->hw;
unsigned long flags;
spin_lock_irqsave(&pmu->lock, flags);
if (!(hwc->state & PERF_HES_STOPPED)) {
WARN_ON_ONCE(pmu->n_active <= 0);
pmu->n_active--;
if (pmu->n_active == 0)
rapl_stop_hrtimer(pmu);
list_del(&event->active_entry);
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
}
if ((mode & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
rapl_event_update(event);
hwc->state |= PERF_HES_UPTODATE;
}
spin_unlock_irqrestore(&pmu->lock, flags);
}
static int rapl_pmu_event_add(struct perf_event *event, int mode)
{
struct rapl_pmu *pmu = __this_cpu_read(rapl_pmu);
struct hw_perf_event *hwc = &event->hw;
unsigned long flags;
spin_lock_irqsave(&pmu->lock, flags);
hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (mode & PERF_EF_START)
__rapl_pmu_event_start(pmu, event);
spin_unlock_irqrestore(&pmu->lock, flags);
return 0;
}
static void rapl_pmu_event_del(struct perf_event *event, int flags)
{
rapl_pmu_event_stop(event, PERF_EF_UPDATE);
}
static int rapl_pmu_event_init(struct perf_event *event)
{
u64 cfg = event->attr.config & RAPL_EVENT_MASK;
int bit, msr, ret = 0;
if (event->attr.type != rapl_pmu_class.type)
return -ENOENT;
if (event->attr.config & ~RAPL_EVENT_MASK)
return -EINVAL;
switch (cfg) {
case INTEL_RAPL_PP0:
bit = RAPL_IDX_PP0_NRG_STAT;
msr = MSR_PP0_ENERGY_STATUS;
break;
case INTEL_RAPL_PKG:
bit = RAPL_IDX_PKG_NRG_STAT;
msr = MSR_PKG_ENERGY_STATUS;
break;
case INTEL_RAPL_RAM:
bit = RAPL_IDX_RAM_NRG_STAT;
msr = MSR_DRAM_ENERGY_STATUS;
break;
case INTEL_RAPL_PP1:
bit = RAPL_IDX_PP1_NRG_STAT;
msr = MSR_PP1_ENERGY_STATUS;
break;
default:
return -EINVAL;
}
if (!(rapl_cntr_mask & (1 << bit)))
return -EINVAL;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
event->hw.event_base = msr;
event->hw.config = cfg;
event->hw.idx = bit;
return ret;
}
static void rapl_pmu_event_read(struct perf_event *event)
{
rapl_event_update(event);
}
static ssize_t rapl_get_attr_cpumask(struct device *dev,
struct device_attribute *attr, char *buf)
{
return cpumap_print_to_pagebuf(true, buf, &rapl_cpu_mask);
}
static ssize_t rapl_sysfs_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
struct perf_pmu_events_attr *pmu_attr = \
container_of(attr, struct perf_pmu_events_attr, attr);
if (pmu_attr->event_str)
return sprintf(page, "%s", pmu_attr->event_str);
return 0;
}
static void rapl_cpu_exit(int cpu)
{
struct rapl_pmu *pmu = per_cpu(rapl_pmu, cpu);
int i, phys_id = topology_physical_package_id(cpu);
int target = -1;
for_each_online_cpu(i) {
if (i == cpu)
continue;
if (phys_id == topology_physical_package_id(i)) {
target = i;
break;
}
}
if (cpumask_test_and_clear_cpu(cpu, &rapl_cpu_mask) && target >= 0)
cpumask_set_cpu(target, &rapl_cpu_mask);
WARN_ON(cpumask_empty(&rapl_cpu_mask));
if (target >= 0)
perf_pmu_migrate_context(pmu->pmu, cpu, target);
rapl_stop_hrtimer(pmu);
}
static void rapl_cpu_init(int cpu)
{
int i, phys_id = topology_physical_package_id(cpu);
for_each_cpu(i, &rapl_cpu_mask) {
if (phys_id == topology_physical_package_id(i))
return;
}
cpumask_set_cpu(cpu, &rapl_cpu_mask);
}
static __init void rapl_hsw_server_quirk(void)
{
rapl_hw_unit[RAPL_IDX_RAM_NRG_STAT] = 16;
}
static int rapl_cpu_prepare(int cpu)
{
struct rapl_pmu *pmu = per_cpu(rapl_pmu, cpu);
int phys_id = topology_physical_package_id(cpu);
u64 ms;
if (pmu)
return 0;
if (phys_id < 0)
return -1;
pmu = kzalloc_node(sizeof(*pmu), GFP_KERNEL, cpu_to_node(cpu));
if (!pmu)
return -1;
spin_lock_init(&pmu->lock);
INIT_LIST_HEAD(&pmu->active_list);
pmu->pmu = &rapl_pmu_class;
if (rapl_hw_unit[0] < 32)
ms = (1000 / (2 * 100)) * (1ULL << (32 - rapl_hw_unit[0] - 1));
else
ms = 2;
pmu->timer_interval = ms_to_ktime(ms);
rapl_hrtimer_init(pmu);
per_cpu(rapl_pmu, cpu) = pmu;
per_cpu(rapl_pmu_to_free, cpu) = NULL;
return 0;
}
static void rapl_cpu_kfree(int cpu)
{
struct rapl_pmu *pmu = per_cpu(rapl_pmu_to_free, cpu);
kfree(pmu);
per_cpu(rapl_pmu_to_free, cpu) = NULL;
}
static int rapl_cpu_dying(int cpu)
{
struct rapl_pmu *pmu = per_cpu(rapl_pmu, cpu);
if (!pmu)
return 0;
per_cpu(rapl_pmu, cpu) = NULL;
per_cpu(rapl_pmu_to_free, cpu) = pmu;
return 0;
}
static int rapl_cpu_notifier(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
rapl_cpu_prepare(cpu);
break;
case CPU_STARTING:
rapl_cpu_init(cpu);
break;
case CPU_UP_CANCELED:
case CPU_DYING:
rapl_cpu_dying(cpu);
break;
case CPU_ONLINE:
case CPU_DEAD:
rapl_cpu_kfree(cpu);
break;
case CPU_DOWN_PREPARE:
rapl_cpu_exit(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static int rapl_check_hw_unit(void)
{
u64 msr_rapl_power_unit_bits;
int i;
if (rdmsrl_safe(MSR_RAPL_POWER_UNIT, &msr_rapl_power_unit_bits))
return -1;
for (i = 0; i < NR_RAPL_DOMAINS; i++)
rapl_hw_unit[i] = (msr_rapl_power_unit_bits >> 8) & 0x1FULL;
return 0;
}
static int __init rapl_pmu_init(void)
{
struct rapl_pmu *pmu;
int cpu, ret;
struct x86_pmu_quirk *quirk;
int i;
if (!x86_match_cpu(rapl_cpu_match))
return 0;
switch (boot_cpu_data.x86_model) {
case 42:
case 58:
rapl_cntr_mask = RAPL_IDX_CLN;
rapl_pmu_events_group.attrs = rapl_events_cln_attr;
break;
case 63:
rapl_add_quirk(rapl_hsw_server_quirk);
rapl_cntr_mask = RAPL_IDX_SRV;
rapl_pmu_events_group.attrs = rapl_events_srv_attr;
break;
case 60:
case 69:
case 61:
rapl_cntr_mask = RAPL_IDX_HSW;
rapl_pmu_events_group.attrs = rapl_events_hsw_attr;
break;
case 45:
case 62:
rapl_cntr_mask = RAPL_IDX_SRV;
rapl_pmu_events_group.attrs = rapl_events_srv_attr;
break;
case 87:
rapl_add_quirk(rapl_hsw_server_quirk);
rapl_cntr_mask = RAPL_IDX_KNL;
rapl_pmu_events_group.attrs = rapl_events_knl_attr;
default:
return 0;
}
ret = rapl_check_hw_unit();
if (ret)
return ret;
for (quirk = rapl_quirks; quirk; quirk = quirk->next)
quirk->func();
cpu_notifier_register_begin();
for_each_online_cpu(cpu) {
ret = rapl_cpu_prepare(cpu);
if (ret)
goto out;
rapl_cpu_init(cpu);
}
__perf_cpu_notifier(rapl_cpu_notifier);
ret = perf_pmu_register(&rapl_pmu_class, "power", -1);
if (WARN_ON(ret)) {
pr_info("RAPL PMU detected, registration failed (%d), RAPL PMU disabled\n", ret);
cpu_notifier_register_done();
return -1;
}
pmu = __this_cpu_read(rapl_pmu);
pr_info("RAPL PMU detected,"
" API unit is 2^-32 Joules,"
" %d fixed counters"
" %llu ms ovfl timer\n",
hweight32(rapl_cntr_mask),
ktime_to_ms(pmu->timer_interval));
for (i = 0; i < NR_RAPL_DOMAINS; i++) {
if (rapl_cntr_mask & (1 << i)) {
pr_info("hw unit of domain %s 2^-%d Joules\n",
rapl_domain_names[i], rapl_hw_unit[i]);
}
}
out:
cpu_notifier_register_done();
return 0;
}
