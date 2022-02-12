static void set_l2_indirect_reg(u64 reg, u64 val)
{
unsigned long flags;
raw_spin_lock_irqsave(&l2_access_lock, flags);
write_sysreg_s(reg, L2CPUSRSELR_EL1);
isb();
write_sysreg_s(val, L2CPUSRDR_EL1);
isb();
raw_spin_unlock_irqrestore(&l2_access_lock, flags);
}
static u64 get_l2_indirect_reg(u64 reg)
{
u64 val;
unsigned long flags;
raw_spin_lock_irqsave(&l2_access_lock, flags);
write_sysreg_s(reg, L2CPUSRSELR_EL1);
isb();
val = read_sysreg_s(L2CPUSRDR_EL1);
raw_spin_unlock_irqrestore(&l2_access_lock, flags);
return val;
}
static inline u32 idx_to_reg_bit(u32 idx)
{
if (idx == l2_cycle_ctr_idx)
return BIT(L2CYCLE_CTR_BIT);
return BIT(idx);
}
static inline struct cluster_pmu *get_cluster_pmu(
struct l2cache_pmu *l2cache_pmu, int cpu)
{
return *per_cpu_ptr(l2cache_pmu->pmu_cluster, cpu);
}
static void cluster_pmu_reset(void)
{
set_l2_indirect_reg(L2PMCR, L2PMCR_RESET_ALL);
set_l2_indirect_reg(L2PMCNTENCLR, l2_counter_present_mask);
set_l2_indirect_reg(L2PMINTENCLR, l2_counter_present_mask);
set_l2_indirect_reg(L2PMOVSCLR, l2_counter_present_mask);
}
static inline void cluster_pmu_enable(void)
{
set_l2_indirect_reg(L2PMCR, L2PMCR_COUNTERS_ENABLE);
}
static inline void cluster_pmu_disable(void)
{
set_l2_indirect_reg(L2PMCR, L2PMCR_COUNTERS_DISABLE);
}
static inline void cluster_pmu_counter_set_value(u32 idx, u64 value)
{
if (idx == l2_cycle_ctr_idx)
set_l2_indirect_reg(L2PMCCNTR, value);
else
set_l2_indirect_reg(reg_idx(IA_L2PMXEVCNTR, idx), value);
}
static inline u64 cluster_pmu_counter_get_value(u32 idx)
{
u64 value;
if (idx == l2_cycle_ctr_idx)
value = get_l2_indirect_reg(L2PMCCNTR);
else
value = get_l2_indirect_reg(reg_idx(IA_L2PMXEVCNTR, idx));
return value;
}
static inline void cluster_pmu_counter_enable(u32 idx)
{
set_l2_indirect_reg(L2PMCNTENSET, idx_to_reg_bit(idx));
}
static inline void cluster_pmu_counter_disable(u32 idx)
{
set_l2_indirect_reg(L2PMCNTENCLR, idx_to_reg_bit(idx));
}
static inline void cluster_pmu_counter_enable_interrupt(u32 idx)
{
set_l2_indirect_reg(L2PMINTENSET, idx_to_reg_bit(idx));
}
static inline void cluster_pmu_counter_disable_interrupt(u32 idx)
{
set_l2_indirect_reg(L2PMINTENCLR, idx_to_reg_bit(idx));
}
static inline void cluster_pmu_set_evccntcr(u32 val)
{
set_l2_indirect_reg(L2PMCCNTCR, val);
}
static inline void cluster_pmu_set_evcntcr(u32 ctr, u32 val)
{
set_l2_indirect_reg(reg_idx(IA_L2PMXEVCNTCR, ctr), val);
}
static inline void cluster_pmu_set_evtyper(u32 ctr, u32 val)
{
set_l2_indirect_reg(reg_idx(IA_L2PMXEVTYPER, ctr), val);
}
static void cluster_pmu_set_resr(struct cluster_pmu *cluster,
u32 event_group, u32 event_cc)
{
u64 field;
u64 resr_val;
u32 shift;
unsigned long flags;
shift = L2PMRESR_GROUP_BITS * event_group;
field = ((u64)(event_cc & L2PMRESR_GROUP_MASK) << shift);
spin_lock_irqsave(&cluster->pmu_lock, flags);
resr_val = get_l2_indirect_reg(L2PMRESR);
resr_val &= ~(L2PMRESR_GROUP_MASK << shift);
resr_val |= field;
resr_val |= L2PMRESR_EN;
set_l2_indirect_reg(L2PMRESR, resr_val);
spin_unlock_irqrestore(&cluster->pmu_lock, flags);
}
static inline void cluster_pmu_set_evfilter_sys_mode(u32 ctr)
{
u32 val = L2PMXEVFILTER_SUFILTER_ALL |
L2PMXEVFILTER_ORGFILTER_IDINDEP |
L2PMXEVFILTER_ORGFILTER_ALL;
set_l2_indirect_reg(reg_idx(IA_L2PMXEVFILTER, ctr), val);
}
static inline u32 cluster_pmu_getreset_ovsr(void)
{
u32 result = get_l2_indirect_reg(L2PMOVSSET);
set_l2_indirect_reg(L2PMOVSCLR, result);
return result;
}
static inline bool cluster_pmu_has_overflowed(u32 ovsr)
{
return !!(ovsr & l2_counter_present_mask);
}
static inline bool cluster_pmu_counter_has_overflowed(u32 ovsr, u32 idx)
{
return !!(ovsr & idx_to_reg_bit(idx));
}
static void l2_cache_event_update(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 delta, prev, now;
u32 idx = hwc->idx;
do {
prev = local64_read(&hwc->prev_count);
now = cluster_pmu_counter_get_value(idx);
} while (local64_cmpxchg(&hwc->prev_count, prev, now) != prev);
delta = now - prev;
if (idx != l2_cycle_ctr_idx)
delta &= 0xffffffff;
local64_add(delta, &event->count);
}
static void l2_cache_cluster_set_period(struct cluster_pmu *cluster,
struct hw_perf_event *hwc)
{
u32 idx = hwc->idx;
u64 new;
if (idx == l2_cycle_ctr_idx)
new = L2_CYCLE_COUNTER_RELOAD;
else
new = L2_COUNTER_RELOAD;
local64_set(&hwc->prev_count, new);
cluster_pmu_counter_set_value(idx, new);
}
static int l2_cache_get_event_idx(struct cluster_pmu *cluster,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int idx;
int num_ctrs = cluster->l2cache_pmu->num_counters - 1;
unsigned int group;
if (hwc->config_base == L2CYCLE_CTR_RAW_CODE) {
if (test_and_set_bit(l2_cycle_ctr_idx, cluster->used_counters))
return -EAGAIN;
return l2_cycle_ctr_idx;
}
idx = find_first_zero_bit(cluster->used_counters, num_ctrs);
if (idx == num_ctrs)
return -EAGAIN;
group = L2_EVT_GROUP(hwc->config_base);
if (test_bit(group, cluster->used_groups))
return -EAGAIN;
set_bit(idx, cluster->used_counters);
set_bit(group, cluster->used_groups);
return idx;
}
static void l2_cache_clear_event_idx(struct cluster_pmu *cluster,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
clear_bit(idx, cluster->used_counters);
if (hwc->config_base != L2CYCLE_CTR_RAW_CODE)
clear_bit(L2_EVT_GROUP(hwc->config_base), cluster->used_groups);
}
static irqreturn_t l2_cache_handle_irq(int irq_num, void *data)
{
struct cluster_pmu *cluster = data;
int num_counters = cluster->l2cache_pmu->num_counters;
u32 ovsr;
int idx;
ovsr = cluster_pmu_getreset_ovsr();
if (!cluster_pmu_has_overflowed(ovsr))
return IRQ_NONE;
for_each_set_bit(idx, cluster->used_counters, num_counters) {
struct perf_event *event = cluster->events[idx];
struct hw_perf_event *hwc;
if (WARN_ON_ONCE(!event))
continue;
if (!cluster_pmu_counter_has_overflowed(ovsr, idx))
continue;
l2_cache_event_update(event);
hwc = &event->hw;
l2_cache_cluster_set_period(cluster, hwc);
}
return IRQ_HANDLED;
}
static void l2_cache_pmu_enable(struct pmu *pmu)
{
cluster_pmu_enable();
}
static void l2_cache_pmu_disable(struct pmu *pmu)
{
cluster_pmu_disable();
}
static int l2_cache_event_init(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct cluster_pmu *cluster;
struct perf_event *sibling;
struct l2cache_pmu *l2cache_pmu;
if (event->attr.type != event->pmu->type)
return -ENOENT;
l2cache_pmu = to_l2cache_pmu(event->pmu);
if (hwc->sample_period) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Sampling not supported\n");
return -EOPNOTSUPP;
}
if (event->cpu < 0) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Per-task mode not supported\n");
return -EOPNOTSUPP;
}
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_hv || event->attr.exclude_idle) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Can't exclude execution levels\n");
return -EOPNOTSUPP;
}
if (((L2_EVT_GROUP(event->attr.config) > L2_EVT_GROUP_MAX) ||
((event->attr.config & ~L2_EVT_MASK) != 0)) &&
(event->attr.config != L2CYCLE_CTR_RAW_CODE)) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Invalid config %llx\n",
event->attr.config);
return -EINVAL;
}
if (event->group_leader->pmu != event->pmu &&
!is_software_event(event->group_leader)) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Can't create mixed PMU group\n");
return -EINVAL;
}
list_for_each_entry(sibling, &event->group_leader->sibling_list,
group_entry)
if (sibling->pmu != event->pmu &&
!is_software_event(sibling)) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Can't create mixed PMU group\n");
return -EINVAL;
}
cluster = get_cluster_pmu(l2cache_pmu, event->cpu);
if (!cluster) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"CPU%d not associated with L2 cluster\n", event->cpu);
return -EINVAL;
}
if ((event->group_leader != event) &&
(cluster->on_cpu != event->group_leader->cpu)) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Can't create group on CPUs %d and %d",
event->cpu, event->group_leader->cpu);
return -EINVAL;
}
if ((event != event->group_leader) &&
!is_software_event(event->group_leader) &&
(L2_EVT_GROUP(event->group_leader->attr.config) ==
L2_EVT_GROUP(event->attr.config))) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Column exclusion: conflicting events %llx %llx\n",
event->group_leader->attr.config,
event->attr.config);
return -EINVAL;
}
list_for_each_entry(sibling, &event->group_leader->sibling_list,
group_entry) {
if ((sibling != event) &&
!is_software_event(sibling) &&
(L2_EVT_GROUP(sibling->attr.config) ==
L2_EVT_GROUP(event->attr.config))) {
dev_dbg_ratelimited(&l2cache_pmu->pdev->dev,
"Column exclusion: conflicting events %llx %llx\n",
sibling->attr.config,
event->attr.config);
return -EINVAL;
}
}
hwc->idx = -1;
hwc->config_base = event->attr.config;
event->cpu = cluster->on_cpu;
return 0;
}
static void l2_cache_event_start(struct perf_event *event, int flags)
{
struct cluster_pmu *cluster;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
u32 config;
u32 event_cc, event_group;
hwc->state = 0;
cluster = get_cluster_pmu(to_l2cache_pmu(event->pmu), event->cpu);
l2_cache_cluster_set_period(cluster, hwc);
if (hwc->config_base == L2CYCLE_CTR_RAW_CODE) {
cluster_pmu_set_evccntcr(0);
} else {
config = hwc->config_base;
event_cc = L2_EVT_CODE(config);
event_group = L2_EVT_GROUP(config);
cluster_pmu_set_evcntcr(idx, 0);
cluster_pmu_set_evtyper(idx, event_group);
cluster_pmu_set_resr(cluster, event_group, event_cc);
cluster_pmu_set_evfilter_sys_mode(idx);
}
cluster_pmu_counter_enable_interrupt(idx);
cluster_pmu_counter_enable(idx);
}
static void l2_cache_event_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
if (hwc->state & PERF_HES_STOPPED)
return;
cluster_pmu_counter_disable_interrupt(idx);
cluster_pmu_counter_disable(idx);
if (flags & PERF_EF_UPDATE)
l2_cache_event_update(event);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
static int l2_cache_event_add(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
int idx;
int err = 0;
struct cluster_pmu *cluster;
cluster = get_cluster_pmu(to_l2cache_pmu(event->pmu), event->cpu);
idx = l2_cache_get_event_idx(cluster, event);
if (idx < 0)
return idx;
hwc->idx = idx;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
cluster->events[idx] = event;
local64_set(&hwc->prev_count, 0);
if (flags & PERF_EF_START)
l2_cache_event_start(event, flags);
perf_event_update_userpage(event);
return err;
}
static void l2_cache_event_del(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
struct cluster_pmu *cluster;
int idx = hwc->idx;
cluster = get_cluster_pmu(to_l2cache_pmu(event->pmu), event->cpu);
l2_cache_event_stop(event, flags | PERF_EF_UPDATE);
cluster->events[idx] = NULL;
l2_cache_clear_event_idx(cluster, event);
perf_event_update_userpage(event);
}
static void l2_cache_event_read(struct perf_event *event)
{
l2_cache_event_update(event);
}
static ssize_t l2_cache_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct l2cache_pmu *l2cache_pmu = to_l2cache_pmu(dev_get_drvdata(dev));
return cpumap_print_to_pagebuf(true, buf, &l2cache_pmu->cpumask);
}
static int get_num_counters(void)
{
int val;
val = get_l2_indirect_reg(L2PMCR);
return ((val >> L2PMCR_NUM_EV_SHIFT) & L2PMCR_NUM_EV_MASK) + 1;
}
static struct cluster_pmu *l2_cache_associate_cpu_with_cluster(
struct l2cache_pmu *l2cache_pmu, int cpu)
{
u64 mpidr;
int cpu_cluster_id;
struct cluster_pmu *cluster = NULL;
mpidr = read_cpuid_mpidr();
if (mpidr & MPIDR_MT_BITMASK)
cpu_cluster_id = MPIDR_AFFINITY_LEVEL(mpidr, 2);
else
cpu_cluster_id = MPIDR_AFFINITY_LEVEL(mpidr, 1);
list_for_each_entry(cluster, &l2cache_pmu->clusters, next) {
if (cluster->cluster_id != cpu_cluster_id)
continue;
dev_info(&l2cache_pmu->pdev->dev,
"CPU%d associated with cluster %d\n", cpu,
cluster->cluster_id);
cpumask_set_cpu(cpu, &cluster->cluster_cpus);
*per_cpu_ptr(l2cache_pmu->pmu_cluster, cpu) = cluster;
break;
}
return cluster;
}
static int l2cache_pmu_online_cpu(unsigned int cpu, struct hlist_node *node)
{
struct cluster_pmu *cluster;
struct l2cache_pmu *l2cache_pmu;
l2cache_pmu = hlist_entry_safe(node, struct l2cache_pmu, node);
cluster = get_cluster_pmu(l2cache_pmu, cpu);
if (!cluster) {
cluster = l2_cache_associate_cpu_with_cluster(l2cache_pmu, cpu);
if (!cluster) {
WARN_ONCE(1, "No L2 cache cluster for CPU%d\n", cpu);
return 0;
}
}
if (cluster->on_cpu != -1)
return 0;
cluster->on_cpu = cpu;
cpumask_set_cpu(cpu, &l2cache_pmu->cpumask);
cluster_pmu_reset();
WARN_ON(irq_set_affinity(cluster->irq, cpumask_of(cpu)));
enable_irq(cluster->irq);
return 0;
}
static int l2cache_pmu_offline_cpu(unsigned int cpu, struct hlist_node *node)
{
struct cluster_pmu *cluster;
struct l2cache_pmu *l2cache_pmu;
cpumask_t cluster_online_cpus;
unsigned int target;
l2cache_pmu = hlist_entry_safe(node, struct l2cache_pmu, node);
cluster = get_cluster_pmu(l2cache_pmu, cpu);
if (!cluster)
return 0;
if (cluster->on_cpu != cpu)
return 0;
cpumask_clear_cpu(cpu, &l2cache_pmu->cpumask);
cluster->on_cpu = -1;
cpumask_and(&cluster_online_cpus, &cluster->cluster_cpus,
cpu_online_mask);
target = cpumask_any_but(&cluster_online_cpus, cpu);
if (target >= nr_cpu_ids) {
disable_irq(cluster->irq);
return 0;
}
perf_pmu_migrate_context(&l2cache_pmu->pmu, cpu, target);
cluster->on_cpu = target;
cpumask_set_cpu(target, &l2cache_pmu->cpumask);
WARN_ON(irq_set_affinity(cluster->irq, cpumask_of(target)));
return 0;
}
static int l2_cache_pmu_probe_cluster(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev->parent);
struct platform_device *sdev = to_platform_device(dev);
struct l2cache_pmu *l2cache_pmu = data;
struct cluster_pmu *cluster;
struct acpi_device *device;
unsigned long fw_cluster_id;
int err;
int irq;
if (acpi_bus_get_device(ACPI_HANDLE(dev), &device))
return -ENODEV;
if (kstrtoul(device->pnp.unique_id, 10, &fw_cluster_id) < 0) {
dev_err(&pdev->dev, "unable to read ACPI uid\n");
return -ENODEV;
}
cluster = devm_kzalloc(&pdev->dev, sizeof(*cluster), GFP_KERNEL);
if (!cluster)
return -ENOMEM;
INIT_LIST_HEAD(&cluster->next);
list_add(&cluster->next, &l2cache_pmu->clusters);
cluster->cluster_id = fw_cluster_id;
irq = platform_get_irq(sdev, 0);
if (irq < 0) {
dev_err(&pdev->dev,
"Failed to get valid irq for cluster %ld\n",
fw_cluster_id);
return irq;
}
irq_set_status_flags(irq, IRQ_NOAUTOEN);
cluster->irq = irq;
cluster->l2cache_pmu = l2cache_pmu;
cluster->on_cpu = -1;
err = devm_request_irq(&pdev->dev, irq, l2_cache_handle_irq,
IRQF_NOBALANCING | IRQF_NO_THREAD,
"l2-cache-pmu", cluster);
if (err) {
dev_err(&pdev->dev,
"Unable to request IRQ%d for L2 PMU counters\n", irq);
return err;
}
dev_info(&pdev->dev,
"Registered L2 cache PMU cluster %ld\n", fw_cluster_id);
spin_lock_init(&cluster->pmu_lock);
l2cache_pmu->num_pmus++;
return 0;
}
static int l2_cache_pmu_probe(struct platform_device *pdev)
{
int err;
struct l2cache_pmu *l2cache_pmu;
l2cache_pmu =
devm_kzalloc(&pdev->dev, sizeof(*l2cache_pmu), GFP_KERNEL);
if (!l2cache_pmu)
return -ENOMEM;
INIT_LIST_HEAD(&l2cache_pmu->clusters);
platform_set_drvdata(pdev, l2cache_pmu);
l2cache_pmu->pmu = (struct pmu) {
.name = "l2cache_0",
.task_ctx_nr = perf_invalid_context,
.pmu_enable = l2_cache_pmu_enable,
.pmu_disable = l2_cache_pmu_disable,
.event_init = l2_cache_event_init,
.add = l2_cache_event_add,
.del = l2_cache_event_del,
.start = l2_cache_event_start,
.stop = l2_cache_event_stop,
.read = l2_cache_event_read,
.attr_groups = l2_cache_pmu_attr_grps,
};
l2cache_pmu->num_counters = get_num_counters();
l2cache_pmu->pdev = pdev;
l2cache_pmu->pmu_cluster = devm_alloc_percpu(&pdev->dev,
struct cluster_pmu *);
if (!l2cache_pmu->pmu_cluster)
return -ENOMEM;
l2_cycle_ctr_idx = l2cache_pmu->num_counters - 1;
l2_counter_present_mask = GENMASK(l2cache_pmu->num_counters - 2, 0) |
BIT(L2CYCLE_CTR_BIT);
cpumask_clear(&l2cache_pmu->cpumask);
err = device_for_each_child(&pdev->dev, l2cache_pmu,
l2_cache_pmu_probe_cluster);
if (err)
return err;
if (l2cache_pmu->num_pmus == 0) {
dev_err(&pdev->dev, "No hardware L2 cache PMUs found\n");
return -ENODEV;
}
err = cpuhp_state_add_instance(CPUHP_AP_PERF_ARM_QCOM_L2_ONLINE,
&l2cache_pmu->node);
if (err) {
dev_err(&pdev->dev, "Error %d registering hotplug", err);
return err;
}
err = perf_pmu_register(&l2cache_pmu->pmu, l2cache_pmu->pmu.name, -1);
if (err) {
dev_err(&pdev->dev, "Error %d registering L2 cache PMU\n", err);
goto out_unregister;
}
dev_info(&pdev->dev, "Registered L2 cache PMU using %d HW PMUs\n",
l2cache_pmu->num_pmus);
return err;
out_unregister:
cpuhp_state_remove_instance(CPUHP_AP_PERF_ARM_QCOM_L2_ONLINE,
&l2cache_pmu->node);
return err;
}
static int l2_cache_pmu_remove(struct platform_device *pdev)
{
struct l2cache_pmu *l2cache_pmu =
to_l2cache_pmu(platform_get_drvdata(pdev));
perf_pmu_unregister(&l2cache_pmu->pmu);
cpuhp_state_remove_instance(CPUHP_AP_PERF_ARM_QCOM_L2_ONLINE,
&l2cache_pmu->node);
return 0;
}
static int __init register_l2_cache_pmu_driver(void)
{
int err;
err = cpuhp_setup_state_multi(CPUHP_AP_PERF_ARM_QCOM_L2_ONLINE,
"AP_PERF_ARM_QCOM_L2_ONLINE",
l2cache_pmu_online_cpu,
l2cache_pmu_offline_cpu);
if (err)
return err;
return platform_driver_register(&l2_cache_pmu_driver);
}
