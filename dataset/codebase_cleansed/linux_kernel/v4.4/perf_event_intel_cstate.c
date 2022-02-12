bool test_core(int idx)
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
if (idx == PERF_CSTATE_CORE_C3_RES ||
idx == PERF_CSTATE_CORE_C6_RES)
return true;
break;
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
case 78:
case 94:
if (idx == PERF_CSTATE_CORE_C3_RES ||
idx == PERF_CSTATE_CORE_C6_RES ||
idx == PERF_CSTATE_CORE_C7_RES)
return true;
break;
case 55:
case 77:
case 76:
if (idx == PERF_CSTATE_CORE_C1_RES ||
idx == PERF_CSTATE_CORE_C6_RES)
return true;
break;
}
return false;
}
bool test_pkg(int idx)
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
if (idx == PERF_CSTATE_CORE_C3_RES ||
idx == PERF_CSTATE_CORE_C6_RES ||
idx == PERF_CSTATE_CORE_C7_RES)
return true;
break;
case 42:
case 45:
case 58:
case 62:
case 60:
case 63:
case 70:
case 61:
case 86:
case 71:
case 79:
case 78:
case 94:
if (idx == PERF_CSTATE_PKG_C2_RES ||
idx == PERF_CSTATE_PKG_C3_RES ||
idx == PERF_CSTATE_PKG_C6_RES ||
idx == PERF_CSTATE_PKG_C7_RES)
return true;
break;
case 55:
case 77:
case 76:
if (idx == PERF_CSTATE_CORE_C6_RES)
return true;
break;
case 69:
if (idx == PERF_CSTATE_PKG_C2_RES ||
idx == PERF_CSTATE_PKG_C3_RES ||
idx == PERF_CSTATE_PKG_C6_RES ||
idx == PERF_CSTATE_PKG_C7_RES ||
idx == PERF_CSTATE_PKG_C8_RES ||
idx == PERF_CSTATE_PKG_C9_RES ||
idx == PERF_CSTATE_PKG_C10_RES)
return true;
break;
}
return false;
}
static ssize_t cstate_get_attr_cpumask(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pmu *pmu = dev_get_drvdata(dev);
if (pmu == &cstate_core_pmu)
return cpumap_print_to_pagebuf(true, buf, &cstate_core_cpu_mask);
else if (pmu == &cstate_pkg_pmu)
return cpumap_print_to_pagebuf(true, buf, &cstate_pkg_cpu_mask);
else
return 0;
}
static int cstate_pmu_event_init(struct perf_event *event)
{
u64 cfg = event->attr.config;
int ret = 0;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
if (event->pmu == &cstate_core_pmu) {
if (cfg >= PERF_CSTATE_CORE_EVENT_MAX)
return -EINVAL;
if (!core_msr[cfg].attr)
return -EINVAL;
event->hw.event_base = core_msr[cfg].msr;
} else if (event->pmu == &cstate_pkg_pmu) {
if (cfg >= PERF_CSTATE_PKG_EVENT_MAX)
return -EINVAL;
if (!pkg_msr[cfg].attr)
return -EINVAL;
event->hw.event_base = pkg_msr[cfg].msr;
} else
return -ENOENT;
event->hw.config = cfg;
event->hw.idx = -1;
return ret;
}
static inline u64 cstate_pmu_read_counter(struct perf_event *event)
{
u64 val;
rdmsrl(event->hw.event_base, val);
return val;
}
static void cstate_pmu_event_update(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 prev_raw_count, new_raw_count;
again:
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = cstate_pmu_read_counter(event);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
local64_add(new_raw_count - prev_raw_count, &event->count);
}
static void cstate_pmu_event_start(struct perf_event *event, int mode)
{
local64_set(&event->hw.prev_count, cstate_pmu_read_counter(event));
}
static void cstate_pmu_event_stop(struct perf_event *event, int mode)
{
cstate_pmu_event_update(event);
}
static void cstate_pmu_event_del(struct perf_event *event, int mode)
{
cstate_pmu_event_stop(event, PERF_EF_UPDATE);
}
static int cstate_pmu_event_add(struct perf_event *event, int mode)
{
if (mode & PERF_EF_START)
cstate_pmu_event_start(event, mode);
return 0;
}
static void cstate_cpu_exit(int cpu)
{
int i, id, target;
if (has_cstate_core) {
id = topology_core_id(cpu);
target = -1;
for_each_online_cpu(i) {
if (i == cpu)
continue;
if (id == topology_core_id(i)) {
target = i;
break;
}
}
if (cpumask_test_and_clear_cpu(cpu, &cstate_core_cpu_mask) && target >= 0)
cpumask_set_cpu(target, &cstate_core_cpu_mask);
WARN_ON(cpumask_empty(&cstate_core_cpu_mask));
if (target >= 0)
perf_pmu_migrate_context(&cstate_core_pmu, cpu, target);
}
if (has_cstate_pkg) {
id = topology_physical_package_id(cpu);
target = -1;
for_each_online_cpu(i) {
if (i == cpu)
continue;
if (id == topology_physical_package_id(i)) {
target = i;
break;
}
}
if (cpumask_test_and_clear_cpu(cpu, &cstate_pkg_cpu_mask) && target >= 0)
cpumask_set_cpu(target, &cstate_pkg_cpu_mask);
WARN_ON(cpumask_empty(&cstate_pkg_cpu_mask));
if (target >= 0)
perf_pmu_migrate_context(&cstate_pkg_pmu, cpu, target);
}
}
static void cstate_cpu_init(int cpu)
{
int i, id;
if (has_cstate_core) {
id = topology_core_id(cpu);
for_each_cpu(i, &cstate_core_cpu_mask) {
if (id == topology_core_id(i))
break;
}
if (i >= nr_cpu_ids)
cpumask_set_cpu(cpu, &cstate_core_cpu_mask);
}
if (has_cstate_pkg) {
id = topology_physical_package_id(cpu);
for_each_cpu(i, &cstate_pkg_cpu_mask) {
if (id == topology_physical_package_id(i))
break;
}
if (i >= nr_cpu_ids)
cpumask_set_cpu(cpu, &cstate_pkg_cpu_mask);
}
}
static int cstate_cpu_notifier(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
break;
case CPU_STARTING:
cstate_cpu_init(cpu);
break;
case CPU_UP_CANCELED:
case CPU_DYING:
break;
case CPU_ONLINE:
case CPU_DEAD:
break;
case CPU_DOWN_PREPARE:
cstate_cpu_exit(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static bool cstate_probe_msr(struct perf_cstate_msr *msr,
struct attribute **events_attrs,
int max_event_nr)
{
int i, j = 0;
u64 val;
for (i = 0; i < max_event_nr; i++) {
if (!msr[i].test(i) || rdmsrl_safe(msr[i].msr, &val))
msr[i].attr = NULL;
}
for (i = 0; i < max_event_nr; i++) {
if (msr[i].attr)
events_attrs[j++] = &msr[i].attr->attr.attr;
}
events_attrs[j] = NULL;
return (j > 0) ? true : false;
}
static int __init cstate_init(void)
{
switch (boot_cpu_data.x86_model) {
case 55:
case 76:
case 77:
pkg_msr[PERF_CSTATE_PKG_C6_RES].msr = MSR_PKG_C7_RESIDENCY;
}
if (cstate_probe_msr(core_msr, core_events_attrs, PERF_CSTATE_CORE_EVENT_MAX))
has_cstate_core = true;
if (cstate_probe_msr(pkg_msr, pkg_events_attrs, PERF_CSTATE_PKG_EVENT_MAX))
has_cstate_pkg = true;
return (has_cstate_core || has_cstate_pkg) ? 0 : -ENODEV;
}
static void __init cstate_cpumask_init(void)
{
int cpu;
cpu_notifier_register_begin();
for_each_online_cpu(cpu)
cstate_cpu_init(cpu);
__perf_cpu_notifier(cstate_cpu_notifier);
cpu_notifier_register_done();
}
static void __init cstate_pmus_register(void)
{
int err;
if (has_cstate_core) {
err = perf_pmu_register(&cstate_core_pmu, cstate_core_pmu.name, -1);
if (WARN_ON(err))
pr_info("Failed to register PMU %s error %d\n",
cstate_core_pmu.name, err);
}
if (has_cstate_pkg) {
err = perf_pmu_register(&cstate_pkg_pmu, cstate_pkg_pmu.name, -1);
if (WARN_ON(err))
pr_info("Failed to register PMU %s error %d\n",
cstate_pkg_pmu.name, err);
}
}
static int __init cstate_pmu_init(void)
{
int err;
if (cpu_has_hypervisor)
return -ENODEV;
err = cstate_init();
if (err)
return err;
cstate_cpumask_init();
cstate_pmus_register();
return 0;
}
