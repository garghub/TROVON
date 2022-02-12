static ktime_t mmdc_pmu_timer_period(void)
{
return ns_to_ktime((u64)mmdc_pmu_poll_period_us * 1000);
}
static ssize_t mmdc_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mmdc_pmu *pmu_mmdc = dev_get_drvdata(dev);
return cpumap_print_to_pagebuf(true, buf, &pmu_mmdc->cpu);
}
static u32 mmdc_pmu_read_counter(struct mmdc_pmu *pmu_mmdc, int cfg)
{
void __iomem *mmdc_base, *reg;
mmdc_base = pmu_mmdc->mmdc_base;
switch (cfg) {
case TOTAL_CYCLES:
reg = mmdc_base + MMDC_MADPSR0;
break;
case BUSY_CYCLES:
reg = mmdc_base + MMDC_MADPSR1;
break;
case READ_ACCESSES:
reg = mmdc_base + MMDC_MADPSR2;
break;
case WRITE_ACCESSES:
reg = mmdc_base + MMDC_MADPSR3;
break;
case READ_BYTES:
reg = mmdc_base + MMDC_MADPSR4;
break;
case WRITE_BYTES:
reg = mmdc_base + MMDC_MADPSR5;
break;
default:
return WARN_ONCE(1,
"invalid configuration %d for mmdc counter", cfg);
}
return readl(reg);
}
static int mmdc_pmu_offline_cpu(unsigned int cpu, struct hlist_node *node)
{
struct mmdc_pmu *pmu_mmdc = hlist_entry_safe(node, struct mmdc_pmu, node);
int target;
if (!cpumask_test_and_clear_cpu(cpu, &pmu_mmdc->cpu))
return 0;
target = cpumask_any_but(cpu_online_mask, cpu);
if (target >= nr_cpu_ids)
return 0;
perf_pmu_migrate_context(&pmu_mmdc->pmu, cpu, target);
cpumask_set_cpu(target, &pmu_mmdc->cpu);
return 0;
}
static bool mmdc_pmu_group_event_is_valid(struct perf_event *event,
struct pmu *pmu,
unsigned long *used_counters)
{
int cfg = event->attr.config;
if (is_software_event(event))
return true;
if (event->pmu != pmu)
return false;
return !test_and_set_bit(cfg, used_counters);
}
static bool mmdc_pmu_group_is_valid(struct perf_event *event)
{
struct pmu *pmu = event->pmu;
struct perf_event *leader = event->group_leader;
struct perf_event *sibling;
unsigned long counter_mask = 0;
set_bit(leader->attr.config, &counter_mask);
if (event != leader) {
if (!mmdc_pmu_group_event_is_valid(event, pmu, &counter_mask))
return false;
}
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (!mmdc_pmu_group_event_is_valid(sibling, pmu, &counter_mask))
return false;
}
return true;
}
static int mmdc_pmu_event_init(struct perf_event *event)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
int cfg = event->attr.config;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (is_sampling_event(event) || event->attach_state & PERF_ATTACH_TASK)
return -EOPNOTSUPP;
if (event->cpu < 0) {
dev_warn(pmu_mmdc->dev, "Can't provide per-task data!\n");
return -EOPNOTSUPP;
}
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
if (cfg < 0 || cfg >= MMDC_NUM_COUNTERS)
return -EINVAL;
if (!mmdc_pmu_group_is_valid(event))
return -EINVAL;
event->cpu = cpumask_first(&pmu_mmdc->cpu);
return 0;
}
static void mmdc_pmu_event_update(struct perf_event *event)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
u64 delta, prev_raw_count, new_raw_count;
do {
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = mmdc_pmu_read_counter(pmu_mmdc,
event->attr.config);
} while (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count);
delta = (new_raw_count - prev_raw_count) & 0xFFFFFFFF;
local64_add(delta, &event->count);
}
static void mmdc_pmu_event_start(struct perf_event *event, int flags)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
void __iomem *mmdc_base, *reg;
u32 val;
mmdc_base = pmu_mmdc->mmdc_base;
reg = mmdc_base + MMDC_MADPCR0;
hrtimer_start(&pmu_mmdc->hrtimer, mmdc_pmu_timer_period(),
HRTIMER_MODE_REL_PINNED);
local64_set(&hwc->prev_count, 0);
writel(DBG_RST, reg);
val = event->attr.config1;
reg = mmdc_base + MMDC_MADPCR1;
writel(val, reg);
reg = mmdc_base + MMDC_MADPCR0;
val = DBG_EN;
if (pmu_mmdc->devtype_data->flags & MMDC_FLAG_PROFILE_SEL)
val |= PROFILE_SEL;
writel(val, reg);
}
static int mmdc_pmu_event_add(struct perf_event *event, int flags)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int cfg = event->attr.config;
if (flags & PERF_EF_START)
mmdc_pmu_event_start(event, flags);
if (pmu_mmdc->mmdc_events[cfg] != NULL)
return -EAGAIN;
pmu_mmdc->mmdc_events[cfg] = event;
pmu_mmdc->active_events++;
local64_set(&hwc->prev_count, mmdc_pmu_read_counter(pmu_mmdc, cfg));
return 0;
}
static void mmdc_pmu_event_stop(struct perf_event *event, int flags)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
void __iomem *mmdc_base, *reg;
mmdc_base = pmu_mmdc->mmdc_base;
reg = mmdc_base + MMDC_MADPCR0;
writel(PRF_FRZ, reg);
reg = mmdc_base + MMDC_MADPCR1;
writel(MMDC_PRF_AXI_ID_CLEAR, reg);
mmdc_pmu_event_update(event);
}
static void mmdc_pmu_event_del(struct perf_event *event, int flags)
{
struct mmdc_pmu *pmu_mmdc = to_mmdc_pmu(event->pmu);
int cfg = event->attr.config;
pmu_mmdc->mmdc_events[cfg] = NULL;
pmu_mmdc->active_events--;
if (pmu_mmdc->active_events == 0)
hrtimer_cancel(&pmu_mmdc->hrtimer);
mmdc_pmu_event_stop(event, PERF_EF_UPDATE);
}
static void mmdc_pmu_overflow_handler(struct mmdc_pmu *pmu_mmdc)
{
int i;
for (i = 0; i < MMDC_NUM_COUNTERS; i++) {
struct perf_event *event = pmu_mmdc->mmdc_events[i];
if (event)
mmdc_pmu_event_update(event);
}
}
static enum hrtimer_restart mmdc_pmu_timer_handler(struct hrtimer *hrtimer)
{
struct mmdc_pmu *pmu_mmdc = container_of(hrtimer, struct mmdc_pmu,
hrtimer);
mmdc_pmu_overflow_handler(pmu_mmdc);
hrtimer_forward_now(hrtimer, mmdc_pmu_timer_period());
return HRTIMER_RESTART;
}
static int mmdc_pmu_init(struct mmdc_pmu *pmu_mmdc,
void __iomem *mmdc_base, struct device *dev)
{
int mmdc_num;
*pmu_mmdc = (struct mmdc_pmu) {
.pmu = (struct pmu) {
.task_ctx_nr = perf_invalid_context,
.attr_groups = attr_groups,
.event_init = mmdc_pmu_event_init,
.add = mmdc_pmu_event_add,
.del = mmdc_pmu_event_del,
.start = mmdc_pmu_event_start,
.stop = mmdc_pmu_event_stop,
.read = mmdc_pmu_event_update,
},
.mmdc_base = mmdc_base,
.dev = dev,
.active_events = 0,
};
mmdc_num = ida_simple_get(&mmdc_ida, 0, 0, GFP_KERNEL);
return mmdc_num;
}
static int imx_mmdc_remove(struct platform_device *pdev)
{
struct mmdc_pmu *pmu_mmdc = platform_get_drvdata(pdev);
cpuhp_state_remove_instance_nocalls(cpuhp_mmdc_state, &pmu_mmdc->node);
perf_pmu_unregister(&pmu_mmdc->pmu);
kfree(pmu_mmdc);
return 0;
}
static int imx_mmdc_perf_init(struct platform_device *pdev, void __iomem *mmdc_base)
{
struct mmdc_pmu *pmu_mmdc;
char *name;
int mmdc_num;
int ret;
const struct of_device_id *of_id =
of_match_device(imx_mmdc_dt_ids, &pdev->dev);
pmu_mmdc = kzalloc(sizeof(*pmu_mmdc), GFP_KERNEL);
if (!pmu_mmdc) {
pr_err("failed to allocate PMU device!\n");
return -ENOMEM;
}
if (!cpuhp_mmdc_state) {
ret = cpuhp_setup_state_multi(CPUHP_AP_ONLINE_DYN,
"perf/arm/mmdc:online", NULL,
mmdc_pmu_offline_cpu);
if (ret < 0) {
pr_err("cpuhp_setup_state_multi failed\n");
goto pmu_free;
}
cpuhp_mmdc_state = ret;
}
mmdc_num = mmdc_pmu_init(pmu_mmdc, mmdc_base, &pdev->dev);
if (mmdc_num == 0)
name = "mmdc";
else
name = devm_kasprintf(&pdev->dev,
GFP_KERNEL, "mmdc%d", mmdc_num);
pmu_mmdc->devtype_data = (struct fsl_mmdc_devtype_data *)of_id->data;
hrtimer_init(&pmu_mmdc->hrtimer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
pmu_mmdc->hrtimer.function = mmdc_pmu_timer_handler;
cpumask_set_cpu(raw_smp_processor_id(), &pmu_mmdc->cpu);
cpuhp_state_add_instance_nocalls(cpuhp_mmdc_state, &pmu_mmdc->node);
ret = perf_pmu_register(&(pmu_mmdc->pmu), name, -1);
if (ret)
goto pmu_register_err;
platform_set_drvdata(pdev, pmu_mmdc);
return 0;
pmu_register_err:
pr_warn("MMDC Perf PMU failed (%d), disabled\n", ret);
cpuhp_state_remove_instance_nocalls(cpuhp_mmdc_state, &pmu_mmdc->node);
hrtimer_cancel(&pmu_mmdc->hrtimer);
pmu_free:
kfree(pmu_mmdc);
return ret;
}
static int imx_mmdc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
void __iomem *mmdc_base, *reg;
u32 val;
int timeout = 0x400;
mmdc_base = of_iomap(np, 0);
WARN_ON(!mmdc_base);
reg = mmdc_base + MMDC_MDMISC;
val = readl_relaxed(reg);
ddr_type = (val & BM_MMDC_MDMISC_DDR_TYPE) >>
BP_MMDC_MDMISC_DDR_TYPE;
reg = mmdc_base + MMDC_MAPSR;
val = readl_relaxed(reg);
val &= ~(1 << BP_MMDC_MAPSR_PSD);
writel_relaxed(val, reg);
while (!(readl_relaxed(reg) & 1 << BP_MMDC_MAPSR_PSS) && --timeout)
cpu_relax();
if (unlikely(!timeout)) {
pr_warn("%s: failed to enable automatic power saving\n",
__func__);
return -EBUSY;
}
return imx_mmdc_perf_init(pdev, mmdc_base);
}
int imx_mmdc_get_ddr_type(void)
{
return ddr_type;
}
static int __init imx_mmdc_init(void)
{
return platform_driver_register(&imx_mmdc_driver);
}
