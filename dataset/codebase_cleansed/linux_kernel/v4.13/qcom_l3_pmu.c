static inline u32 get_event_type(struct perf_event *event)
{
return (event->attr.config) & L3_EVTYPE_MASK;
}
static inline bool event_uses_long_counter(struct perf_event *event)
{
return !!(event->attr.config & BIT_ULL(L3_EVENT_LC_BIT));
}
static inline int event_num_counters(struct perf_event *event)
{
return event_uses_long_counter(event) ? 2 : 1;
}
static void qcom_l3_cache__64bit_counter_start(struct perf_event *event)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 evsel = get_event_type(event);
u32 gang;
gang = readl_relaxed(l3pmu->regs + L3_M_BC_GANG);
gang |= GANG_EN(idx + 1);
writel_relaxed(gang, l3pmu->regs + L3_M_BC_GANG);
local64_set(&event->hw.prev_count, 0);
writel_relaxed(0, l3pmu->regs + L3_HML3_PM_EVCNTR(idx + 1));
writel_relaxed(0, l3pmu->regs + L3_HML3_PM_EVCNTR(idx));
writel_relaxed(EVSEL(0), l3pmu->regs + L3_HML3_PM_EVTYPE(idx + 1));
writel_relaxed(EVSEL(evsel), l3pmu->regs + L3_HML3_PM_EVTYPE(idx));
writel_relaxed(PMCNT_RESET, l3pmu->regs + L3_HML3_PM_CNTCTL(idx + 1));
writel_relaxed(PMCNTENSET(idx + 1), l3pmu->regs + L3_M_BC_CNTENSET);
writel_relaxed(PMCNT_RESET, l3pmu->regs + L3_HML3_PM_CNTCTL(idx));
writel_relaxed(PMCNTENSET(idx), l3pmu->regs + L3_M_BC_CNTENSET);
}
static void qcom_l3_cache__64bit_counter_stop(struct perf_event *event,
int flags)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 gang = readl_relaxed(l3pmu->regs + L3_M_BC_GANG);
writel_relaxed(PMCNTENCLR(idx), l3pmu->regs + L3_M_BC_CNTENCLR);
writel_relaxed(PMCNTENCLR(idx + 1), l3pmu->regs + L3_M_BC_CNTENCLR);
writel_relaxed(gang & ~GANG_EN(idx + 1), l3pmu->regs + L3_M_BC_GANG);
}
static void qcom_l3_cache__64bit_counter_update(struct perf_event *event)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 hi, lo;
u64 prev, new;
do {
prev = local64_read(&event->hw.prev_count);
do {
hi = readl_relaxed(l3pmu->regs + L3_HML3_PM_EVCNTR(idx + 1));
lo = readl_relaxed(l3pmu->regs + L3_HML3_PM_EVCNTR(idx));
} while (hi != readl_relaxed(l3pmu->regs + L3_HML3_PM_EVCNTR(idx + 1)));
new = ((u64)hi << 32) | lo;
} while (local64_cmpxchg(&event->hw.prev_count, prev, new) != prev);
local64_add(new - prev, &event->count);
}
static void qcom_l3_cache__32bit_counter_start(struct perf_event *event)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 evsel = get_event_type(event);
u32 irqctl = readl_relaxed(l3pmu->regs + L3_M_BC_IRQCTL);
writel_relaxed(irqctl | PMIRQONMSBEN(idx), l3pmu->regs + L3_M_BC_IRQCTL);
local64_set(&event->hw.prev_count, 0);
writel_relaxed(0, l3pmu->regs + L3_HML3_PM_EVCNTR(idx));
writel_relaxed(EVSEL(evsel), l3pmu->regs + L3_HML3_PM_EVTYPE(idx));
writel_relaxed(PMINTENSET(idx), l3pmu->regs + L3_M_BC_INTENSET);
writel_relaxed(PMCNT_RESET, l3pmu->regs + L3_HML3_PM_CNTCTL(idx));
writel_relaxed(PMCNTENSET(idx), l3pmu->regs + L3_M_BC_CNTENSET);
}
static void qcom_l3_cache__32bit_counter_stop(struct perf_event *event,
int flags)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 irqctl = readl_relaxed(l3pmu->regs + L3_M_BC_IRQCTL);
writel_relaxed(PMCNTENCLR(idx), l3pmu->regs + L3_M_BC_CNTENCLR);
writel_relaxed(PMINTENCLR(idx), l3pmu->regs + L3_M_BC_INTENCLR);
writel_relaxed(irqctl & ~PMIRQONMSBEN(idx), l3pmu->regs + L3_M_BC_IRQCTL);
}
static void qcom_l3_cache__32bit_counter_update(struct perf_event *event)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
int idx = event->hw.idx;
u32 prev, new;
do {
prev = local64_read(&event->hw.prev_count);
new = readl_relaxed(l3pmu->regs + L3_HML3_PM_EVCNTR(idx));
} while (local64_cmpxchg(&event->hw.prev_count, prev, new) != prev);
local64_add(new - prev, &event->count);
}
static
const struct l3cache_event_ops *l3cache_event_get_ops(struct perf_event *event)
{
if (event_uses_long_counter(event))
return &event_ops_long;
else
return &event_ops_std;
}
static inline void qcom_l3_cache__init(struct l3cache_pmu *l3pmu)
{
int i;
writel_relaxed(BC_RESET, l3pmu->regs + L3_M_BC_CR);
writel(BC_SATROLL_CR_RESET, l3pmu->regs + L3_M_BC_SATROLL_CR);
writel_relaxed(BC_CNTENCLR_RESET, l3pmu->regs + L3_M_BC_CNTENCLR);
writel_relaxed(BC_INTENCLR_RESET, l3pmu->regs + L3_M_BC_INTENCLR);
writel_relaxed(PMOVSRCLR_RESET, l3pmu->regs + L3_M_BC_OVSR);
writel_relaxed(BC_GANG_RESET, l3pmu->regs + L3_M_BC_GANG);
writel_relaxed(BC_IRQCTL_RESET, l3pmu->regs + L3_M_BC_IRQCTL);
writel_relaxed(PM_CR_RESET, l3pmu->regs + L3_HML3_PM_CR);
for (i = 0; i < L3_NUM_COUNTERS; ++i) {
writel_relaxed(PMCNT_RESET, l3pmu->regs + L3_HML3_PM_CNTCTL(i));
writel_relaxed(EVSEL(0), l3pmu->regs + L3_HML3_PM_EVTYPE(i));
}
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRA);
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRAM);
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRB);
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRBM);
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRC);
writel_relaxed(PM_FLTR_RESET, l3pmu->regs + L3_HML3_PM_FILTRCM);
writel(BC_ENABLE, l3pmu->regs + L3_M_BC_CR);
}
static irqreturn_t qcom_l3_cache__handle_irq(int irq_num, void *data)
{
struct l3cache_pmu *l3pmu = data;
long status = readl_relaxed(l3pmu->regs + L3_M_BC_OVSR);
int idx;
if (status == 0)
return IRQ_NONE;
writel_relaxed(status, l3pmu->regs + L3_M_BC_OVSR);
for_each_set_bit(idx, &status, L3_NUM_COUNTERS) {
struct perf_event *event;
const struct l3cache_event_ops *ops;
event = l3pmu->events[idx];
if (!event)
continue;
ops = l3cache_event_get_ops(event);
ops->update(event);
}
return IRQ_HANDLED;
}
static void qcom_l3_cache__pmu_enable(struct pmu *pmu)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(pmu);
wmb();
writel_relaxed(BC_ENABLE, l3pmu->regs + L3_M_BC_CR);
}
static void qcom_l3_cache__pmu_disable(struct pmu *pmu)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(pmu);
writel_relaxed(0, l3pmu->regs + L3_M_BC_CR);
wmb();
}
static bool qcom_l3_cache__validate_event_group(struct perf_event *event)
{
struct perf_event *leader = event->group_leader;
struct perf_event *sibling;
int counters = 0;
if (leader->pmu != event->pmu && !is_software_event(leader))
return false;
counters = event_num_counters(event);
counters += event_num_counters(leader);
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (is_software_event(sibling))
continue;
if (sibling->pmu != event->pmu)
return false;
counters += event_num_counters(sibling);
}
return counters <= L3_NUM_COUNTERS;
}
static int qcom_l3_cache__event_init(struct perf_event *event)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_hv || event->attr.exclude_idle)
return -EINVAL;
if (hwc->sample_period)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
if (!qcom_l3_cache__validate_event_group(event))
return -EINVAL;
hwc->idx = -1;
event->cpu = cpumask_first(&l3pmu->cpumask);
return 0;
}
static void qcom_l3_cache__event_start(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
const struct l3cache_event_ops *ops = l3cache_event_get_ops(event);
hwc->state = 0;
ops->start(event);
}
static void qcom_l3_cache__event_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
const struct l3cache_event_ops *ops = l3cache_event_get_ops(event);
if (hwc->state & PERF_HES_STOPPED)
return;
ops->stop(event, flags);
if (flags & PERF_EF_UPDATE)
ops->update(event);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
static int qcom_l3_cache__event_add(struct perf_event *event, int flags)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int order = event_uses_long_counter(event) ? 1 : 0;
int idx;
idx = bitmap_find_free_region(l3pmu->used_mask, L3_NUM_COUNTERS, order);
if (idx < 0)
return -EAGAIN;
hwc->idx = idx;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
l3pmu->events[idx] = event;
if (flags & PERF_EF_START)
qcom_l3_cache__event_start(event, 0);
perf_event_update_userpage(event);
return 0;
}
static void qcom_l3_cache__event_del(struct perf_event *event, int flags)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int order = event_uses_long_counter(event) ? 1 : 0;
qcom_l3_cache__event_stop(event, flags | PERF_EF_UPDATE);
l3pmu->events[hwc->idx] = NULL;
bitmap_release_region(l3pmu->used_mask, hwc->idx, order);
perf_event_update_userpage(event);
}
static void qcom_l3_cache__event_read(struct perf_event *event)
{
const struct l3cache_event_ops *ops = l3cache_event_get_ops(event);
ops->update(event);
}
static ssize_t l3cache_pmu_format_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dev_ext_attribute *eattr;
eattr = container_of(attr, struct dev_ext_attribute, attr);
return sprintf(buf, "%s\n", (char *) eattr->var);
}
static ssize_t l3cache_pmu_event_show(struct device *dev,
struct device_attribute *attr, char *page)
{
struct perf_pmu_events_attr *pmu_attr;
pmu_attr = container_of(attr, struct perf_pmu_events_attr, attr);
return sprintf(page, "event=0x%02llx\n", pmu_attr->id);
}
static ssize_t qcom_l3_cache_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct l3cache_pmu *l3pmu = to_l3cache_pmu(dev_get_drvdata(dev));
return cpumap_print_to_pagebuf(true, buf, &l3pmu->cpumask);
}
static int qcom_l3_cache_pmu_online_cpu(unsigned int cpu, struct hlist_node *node)
{
struct l3cache_pmu *l3pmu = hlist_entry_safe(node, struct l3cache_pmu, node);
if (cpumask_empty(&l3pmu->cpumask))
cpumask_set_cpu(cpu, &l3pmu->cpumask);
return 0;
}
static int qcom_l3_cache_pmu_offline_cpu(unsigned int cpu, struct hlist_node *node)
{
struct l3cache_pmu *l3pmu = hlist_entry_safe(node, struct l3cache_pmu, node);
unsigned int target;
if (!cpumask_test_and_clear_cpu(cpu, &l3pmu->cpumask))
return 0;
target = cpumask_any_but(cpu_online_mask, cpu);
if (target >= nr_cpu_ids)
return 0;
perf_pmu_migrate_context(&l3pmu->pmu, cpu, target);
cpumask_set_cpu(target, &l3pmu->cpumask);
return 0;
}
static int qcom_l3_cache_pmu_probe(struct platform_device *pdev)
{
struct l3cache_pmu *l3pmu;
struct acpi_device *acpi_dev;
struct resource *memrc;
int ret;
char *name;
acpi_dev = ACPI_COMPANION(&pdev->dev);
if (!acpi_dev)
return -ENODEV;
l3pmu = devm_kzalloc(&pdev->dev, sizeof(*l3pmu), GFP_KERNEL);
name = devm_kasprintf(&pdev->dev, GFP_KERNEL, "l3cache_%s_%s",
acpi_dev->parent->pnp.unique_id, acpi_dev->pnp.unique_id);
if (!l3pmu || !name)
return -ENOMEM;
l3pmu->pmu = (struct pmu) {
.task_ctx_nr = perf_invalid_context,
.pmu_enable = qcom_l3_cache__pmu_enable,
.pmu_disable = qcom_l3_cache__pmu_disable,
.event_init = qcom_l3_cache__event_init,
.add = qcom_l3_cache__event_add,
.del = qcom_l3_cache__event_del,
.start = qcom_l3_cache__event_start,
.stop = qcom_l3_cache__event_stop,
.read = qcom_l3_cache__event_read,
.attr_groups = qcom_l3_cache_pmu_attr_grps,
};
memrc = platform_get_resource(pdev, IORESOURCE_MEM, 0);
l3pmu->regs = devm_ioremap_resource(&pdev->dev, memrc);
if (IS_ERR(l3pmu->regs)) {
dev_err(&pdev->dev, "Can't map PMU @%pa\n", &memrc->start);
return PTR_ERR(l3pmu->regs);
}
qcom_l3_cache__init(l3pmu);
ret = platform_get_irq(pdev, 0);
if (ret <= 0)
return ret;
ret = devm_request_irq(&pdev->dev, ret, qcom_l3_cache__handle_irq, 0,
name, l3pmu);
if (ret) {
dev_err(&pdev->dev, "Request for IRQ failed for slice @%pa\n",
&memrc->start);
return ret;
}
ret = cpuhp_state_add_instance(CPUHP_AP_PERF_ARM_QCOM_L3_ONLINE, &l3pmu->node);
if (ret) {
dev_err(&pdev->dev, "Error %d registering hotplug", ret);
return ret;
}
ret = perf_pmu_register(&l3pmu->pmu, name, -1);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register L3 cache PMU (%d)\n", ret);
return ret;
}
dev_info(&pdev->dev, "Registered %s, type: %d\n", name, l3pmu->pmu.type);
return 0;
}
static int __init register_qcom_l3_cache_pmu_driver(void)
{
int ret;
ret = cpuhp_setup_state_multi(CPUHP_AP_PERF_ARM_QCOM_L3_ONLINE,
"perf/qcom/l3cache:online",
qcom_l3_cache_pmu_online_cpu,
qcom_l3_cache_pmu_offline_cpu);
if (ret)
return ret;
return platform_driver_register(&qcom_l3_cache_pmu_driver);
}
