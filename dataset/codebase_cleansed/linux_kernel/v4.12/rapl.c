static inline struct rapl_pmu *cpu_to_rapl_pmu(unsigned int cpu)
{
unsigned int pkgid = topology_logical_package_id(cpu);
return pkgid < rapl_pmus->maxpkg ? rapl_pmus->pmus[pkgid] : NULL;
}
static inline u64 rapl_read_counter(struct perf_event *event)
{
u64 raw;
rdmsrl(event->hw.event_base, raw);
return raw;
}
static inline u64 rapl_scale(u64 v, int cfg)
{
if (cfg > NR_RAPL_DOMAINS) {
pr_warn("Invalid domain %d, failed to scale data\n", cfg);
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
static enum hrtimer_restart rapl_hrtimer_handle(struct hrtimer *hrtimer)
{
struct rapl_pmu *pmu = container_of(hrtimer, struct rapl_pmu, hrtimer);
struct perf_event *event;
unsigned long flags;
if (!pmu->n_active)
return HRTIMER_NORESTART;
raw_spin_lock_irqsave(&pmu->lock, flags);
list_for_each_entry(event, &pmu->active_list, active_entry)
rapl_event_update(event);
raw_spin_unlock_irqrestore(&pmu->lock, flags);
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
struct rapl_pmu *pmu = event->pmu_private;
unsigned long flags;
raw_spin_lock_irqsave(&pmu->lock, flags);
__rapl_pmu_event_start(pmu, event);
raw_spin_unlock_irqrestore(&pmu->lock, flags);
}
static void rapl_pmu_event_stop(struct perf_event *event, int mode)
{
struct rapl_pmu *pmu = event->pmu_private;
struct hw_perf_event *hwc = &event->hw;
unsigned long flags;
raw_spin_lock_irqsave(&pmu->lock, flags);
if (!(hwc->state & PERF_HES_STOPPED)) {
WARN_ON_ONCE(pmu->n_active <= 0);
pmu->n_active--;
if (pmu->n_active == 0)
hrtimer_cancel(&pmu->hrtimer);
list_del(&event->active_entry);
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
}
if ((mode & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
rapl_event_update(event);
hwc->state |= PERF_HES_UPTODATE;
}
raw_spin_unlock_irqrestore(&pmu->lock, flags);
}
static int rapl_pmu_event_add(struct perf_event *event, int mode)
{
struct rapl_pmu *pmu = event->pmu_private;
struct hw_perf_event *hwc = &event->hw;
unsigned long flags;
raw_spin_lock_irqsave(&pmu->lock, flags);
hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (mode & PERF_EF_START)
__rapl_pmu_event_start(pmu, event);
raw_spin_unlock_irqrestore(&pmu->lock, flags);
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
struct rapl_pmu *pmu;
if (event->attr.type != rapl_pmus->pmu.type)
return -ENOENT;
if (event->attr.config & ~RAPL_EVENT_MASK)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
event->event_caps |= PERF_EV_CAP_READ_ACTIVE_PKG;
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
case INTEL_RAPL_PSYS:
bit = RAPL_IDX_PSYS_NRG_STAT;
msr = MSR_PLATFORM_ENERGY_STATUS;
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
pmu = cpu_to_rapl_pmu(event->cpu);
if (!pmu)
return -EINVAL;
event->cpu = pmu->cpu;
event->pmu_private = pmu;
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
static int rapl_cpu_offline(unsigned int cpu)
{
struct rapl_pmu *pmu = cpu_to_rapl_pmu(cpu);
int target;
if (!cpumask_test_and_clear_cpu(cpu, &rapl_cpu_mask))
return 0;
pmu->cpu = -1;
target = cpumask_any_but(topology_core_cpumask(cpu), cpu);
if (target < nr_cpu_ids) {
cpumask_set_cpu(target, &rapl_cpu_mask);
pmu->cpu = target;
perf_pmu_migrate_context(pmu->pmu, cpu, target);
}
return 0;
}
static int rapl_cpu_online(unsigned int cpu)
{
struct rapl_pmu *pmu = cpu_to_rapl_pmu(cpu);
int target;
if (!pmu) {
pmu = kzalloc_node(sizeof(*pmu), GFP_KERNEL, cpu_to_node(cpu));
if (!pmu)
return -ENOMEM;
raw_spin_lock_init(&pmu->lock);
INIT_LIST_HEAD(&pmu->active_list);
pmu->pmu = &rapl_pmus->pmu;
pmu->timer_interval = ms_to_ktime(rapl_timer_ms);
rapl_hrtimer_init(pmu);
rapl_pmus->pmus[topology_logical_package_id(cpu)] = pmu;
}
target = cpumask_any_and(&rapl_cpu_mask, topology_core_cpumask(cpu));
if (target < nr_cpu_ids)
return 0;
cpumask_set_cpu(cpu, &rapl_cpu_mask);
pmu->cpu = cpu;
return 0;
}
static int rapl_check_hw_unit(bool apply_quirk)
{
u64 msr_rapl_power_unit_bits;
int i;
if (rdmsrl_safe(MSR_RAPL_POWER_UNIT, &msr_rapl_power_unit_bits))
return -1;
for (i = 0; i < NR_RAPL_DOMAINS; i++)
rapl_hw_unit[i] = (msr_rapl_power_unit_bits >> 8) & 0x1FULL;
if (apply_quirk)
rapl_hw_unit[RAPL_IDX_RAM_NRG_STAT] = 16;
rapl_timer_ms = 2;
if (rapl_hw_unit[0] < 32) {
rapl_timer_ms = (1000 / (2 * 100));
rapl_timer_ms *= (1ULL << (32 - rapl_hw_unit[0] - 1));
}
return 0;
}
static void __init rapl_advertise(void)
{
int i;
pr_info("API unit is 2^-32 Joules, %d fixed counters, %llu ms ovfl timer\n",
hweight32(rapl_cntr_mask), rapl_timer_ms);
for (i = 0; i < NR_RAPL_DOMAINS; i++) {
if (rapl_cntr_mask & (1 << i)) {
pr_info("hw unit of domain %s 2^-%d Joules\n",
rapl_domain_names[i], rapl_hw_unit[i]);
}
}
}
static void cleanup_rapl_pmus(void)
{
int i;
for (i = 0; i < rapl_pmus->maxpkg; i++)
kfree(rapl_pmus->pmus[i]);
kfree(rapl_pmus);
}
static int __init init_rapl_pmus(void)
{
int maxpkg = topology_max_packages();
size_t size;
size = sizeof(*rapl_pmus) + maxpkg * sizeof(struct rapl_pmu *);
rapl_pmus = kzalloc(size, GFP_KERNEL);
if (!rapl_pmus)
return -ENOMEM;
rapl_pmus->maxpkg = maxpkg;
rapl_pmus->pmu.attr_groups = rapl_attr_groups;
rapl_pmus->pmu.task_ctx_nr = perf_invalid_context;
rapl_pmus->pmu.event_init = rapl_pmu_event_init;
rapl_pmus->pmu.add = rapl_pmu_event_add;
rapl_pmus->pmu.del = rapl_pmu_event_del;
rapl_pmus->pmu.start = rapl_pmu_event_start;
rapl_pmus->pmu.stop = rapl_pmu_event_stop;
rapl_pmus->pmu.read = rapl_pmu_event_read;
rapl_pmus->pmu.module = THIS_MODULE;
return 0;
}
static int __init rapl_pmu_init(void)
{
const struct x86_cpu_id *id;
struct intel_rapl_init_fun *rapl_init;
bool apply_quirk;
int ret;
id = x86_match_cpu(rapl_cpu_match);
if (!id)
return -ENODEV;
rapl_init = (struct intel_rapl_init_fun *)id->driver_data;
apply_quirk = rapl_init->apply_quirk;
rapl_cntr_mask = rapl_init->cntr_mask;
rapl_pmu_events_group.attrs = rapl_init->attrs;
ret = rapl_check_hw_unit(apply_quirk);
if (ret)
return ret;
ret = init_rapl_pmus();
if (ret)
return ret;
ret = cpuhp_setup_state(CPUHP_AP_PERF_X86_RAPL_ONLINE,
"perf/x86/rapl:online",
rapl_cpu_online, rapl_cpu_offline);
if (ret)
goto out;
ret = perf_pmu_register(&rapl_pmus->pmu, "power", -1);
if (ret)
goto out1;
rapl_advertise();
return 0;
out1:
cpuhp_remove_state(CPUHP_AP_PERF_X86_RAPL_ONLINE);
out:
pr_warn("Initialization failed (%d), disabled\n", ret);
cleanup_rapl_pmus();
return ret;
}
static void __exit intel_rapl_exit(void)
{
cpuhp_remove_state_nocalls(CPUHP_AP_PERF_X86_RAPL_ONLINE);
perf_pmu_unregister(&rapl_pmus->pmu);
cleanup_rapl_pmus();
}
