static int l2x0_pmu_find_idx(void)
{
int i;
for (i = 0; i < PMU_NR_COUNTERS; i++) {
if (!events[i])
return i;
}
return -1;
}
static int l2x0_pmu_num_active_counters(void)
{
int i, cnt = 0;
for (i = 0; i < PMU_NR_COUNTERS; i++) {
if (events[i])
cnt++;
}
return cnt;
}
static void l2x0_pmu_counter_config_write(int idx, u32 val)
{
writel_relaxed(val, l2x0_base + L2X0_EVENT_CNT0_CFG - 4 * idx);
}
static u32 l2x0_pmu_counter_read(int idx)
{
return readl_relaxed(l2x0_base + L2X0_EVENT_CNT0_VAL - 4 * idx);
}
static void l2x0_pmu_counter_write(int idx, u32 val)
{
writel_relaxed(val, l2x0_base + L2X0_EVENT_CNT0_VAL - 4 * idx);
}
static void __l2x0_pmu_enable(void)
{
u32 val = readl_relaxed(l2x0_base + L2X0_EVENT_CNT_CTRL);
val |= L2X0_EVENT_CNT_CTRL_ENABLE;
writel_relaxed(val, l2x0_base + L2X0_EVENT_CNT_CTRL);
}
static void __l2x0_pmu_disable(void)
{
u32 val = readl_relaxed(l2x0_base + L2X0_EVENT_CNT_CTRL);
val &= ~L2X0_EVENT_CNT_CTRL_ENABLE;
writel_relaxed(val, l2x0_base + L2X0_EVENT_CNT_CTRL);
}
static void l2x0_pmu_enable(struct pmu *pmu)
{
if (l2x0_pmu_num_active_counters() == 0)
return;
__l2x0_pmu_enable();
}
static void l2x0_pmu_disable(struct pmu *pmu)
{
if (l2x0_pmu_num_active_counters() == 0)
return;
__l2x0_pmu_disable();
}
static void warn_if_saturated(u32 count)
{
if (count != 0xffffffff)
return;
pr_warn_ratelimited("L2X0 counter saturated. Poll period too long\n");
}
static void l2x0_pmu_event_read(struct perf_event *event)
{
struct hw_perf_event *hw = &event->hw;
u64 prev_count, new_count, mask;
do {
prev_count = local64_read(&hw->prev_count);
new_count = l2x0_pmu_counter_read(hw->idx);
} while (local64_xchg(&hw->prev_count, new_count) != prev_count);
mask = GENMASK_ULL(31, 0);
local64_add((new_count - prev_count) & mask, &event->count);
warn_if_saturated(new_count);
}
static void l2x0_pmu_event_configure(struct perf_event *event)
{
struct hw_perf_event *hw = &event->hw;
local64_set(&hw->prev_count, 0);
l2x0_pmu_counter_write(hw->idx, 0);
}
static enum hrtimer_restart l2x0_pmu_poll(struct hrtimer *hrtimer)
{
unsigned long flags;
int i;
local_irq_save(flags);
__l2x0_pmu_disable();
for (i = 0; i < PMU_NR_COUNTERS; i++) {
struct perf_event *event = events[i];
if (!event)
continue;
l2x0_pmu_event_read(event);
l2x0_pmu_event_configure(event);
}
__l2x0_pmu_enable();
local_irq_restore(flags);
hrtimer_forward_now(hrtimer, l2x0_pmu_poll_period);
return HRTIMER_RESTART;
}
static void __l2x0_pmu_event_enable(int idx, u32 event)
{
u32 val;
val = event << L2X0_EVENT_CNT_CFG_SRC_SHIFT;
val |= L2X0_EVENT_CNT_CFG_INT_DISABLED;
l2x0_pmu_counter_config_write(idx, val);
}
static void l2x0_pmu_event_start(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
if (flags & PERF_EF_RELOAD) {
WARN_ON_ONCE(!(hw->state & PERF_HES_UPTODATE));
l2x0_pmu_event_configure(event);
}
hw->state = 0;
__l2x0_pmu_event_enable(hw->idx, hw->config_base);
}
static void __l2x0_pmu_event_disable(int idx)
{
u32 val;
val = L2X0_EVENT_CNT_CFG_SRC_DISABLED << L2X0_EVENT_CNT_CFG_SRC_SHIFT;
val |= L2X0_EVENT_CNT_CFG_INT_DISABLED;
l2x0_pmu_counter_config_write(idx, val);
}
static void l2x0_pmu_event_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
if (WARN_ON_ONCE(event->hw.state & PERF_HES_STOPPED))
return;
__l2x0_pmu_event_disable(hw->idx);
hw->state |= PERF_HES_STOPPED;
if (flags & PERF_EF_UPDATE) {
l2x0_pmu_event_read(event);
hw->state |= PERF_HES_UPTODATE;
}
}
static int l2x0_pmu_event_add(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
int idx = l2x0_pmu_find_idx();
if (idx == -1)
return -EAGAIN;
if (l2x0_pmu_num_active_counters() == 0)
hrtimer_start(&l2x0_pmu_hrtimer, l2x0_pmu_poll_period,
HRTIMER_MODE_REL_PINNED);
events[idx] = event;
hw->idx = idx;
l2x0_pmu_event_configure(event);
hw->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
l2x0_pmu_event_start(event, 0);
return 0;
}
static void l2x0_pmu_event_del(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
l2x0_pmu_event_stop(event, PERF_EF_UPDATE);
events[hw->idx] = NULL;
hw->idx = -1;
if (l2x0_pmu_num_active_counters() == 0)
hrtimer_cancel(&l2x0_pmu_hrtimer);
}
static bool l2x0_pmu_group_is_valid(struct perf_event *event)
{
struct pmu *pmu = event->pmu;
struct perf_event *leader = event->group_leader;
struct perf_event *sibling;
int num_hw = 0;
if (leader->pmu == pmu)
num_hw++;
else if (!is_software_event(leader))
return false;
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (sibling->pmu == pmu)
num_hw++;
else if (!is_software_event(sibling))
return false;
}
return num_hw <= PMU_NR_COUNTERS;
}
static int l2x0_pmu_event_init(struct perf_event *event)
{
struct hw_perf_event *hw = &event->hw;
if (event->attr.type != l2x0_pmu->type)
return -ENOENT;
if (is_sampling_event(event) ||
event->attach_state & PERF_ATTACH_TASK)
return -EINVAL;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
if (event->attr.config & ~L2X0_EVENT_CNT_CFG_SRC_MASK)
return -EINVAL;
hw->config_base = event->attr.config;
if (!l2x0_pmu_group_is_valid(event))
return -EINVAL;
event->cpu = cpumask_first(&pmu_cpu);
return 0;
}
static ssize_t l2x0_pmu_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct l2x0_event_attribute *lattr;
lattr = container_of(attr, typeof(*lattr), attr);
return snprintf(buf, PAGE_SIZE, "config=0x%x\n", lattr->config);
}
static umode_t l2x0_pmu_event_attr_is_visible(struct kobject *kobj,
struct attribute *attr,
int unused)
{
struct device *dev = kobj_to_dev(kobj);
struct pmu *pmu = dev_get_drvdata(dev);
struct l2x0_event_attribute *lattr;
lattr = container_of(attr, typeof(*lattr), attr.attr);
if (!lattr->pl310_only || strcmp("l2c_310", pmu->name) == 0)
return attr->mode;
return 0;
}
static ssize_t l2x0_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return cpumap_print_to_pagebuf(true, buf, &pmu_cpu);
}
static void l2x0_pmu_reset(void)
{
int i;
__l2x0_pmu_disable();
for (i = 0; i < PMU_NR_COUNTERS; i++)
__l2x0_pmu_event_disable(i);
}
static int l2x0_pmu_offline_cpu(unsigned int cpu)
{
unsigned int target;
if (!cpumask_test_and_clear_cpu(cpu, &pmu_cpu))
return 0;
target = cpumask_any_but(cpu_online_mask, cpu);
if (target >= nr_cpu_ids)
return 0;
perf_pmu_migrate_context(l2x0_pmu, cpu, target);
cpumask_set_cpu(target, &pmu_cpu);
return 0;
}
void l2x0_pmu_suspend(void)
{
int i;
if (!l2x0_pmu)
return;
l2x0_pmu_disable(l2x0_pmu);
for (i = 0; i < PMU_NR_COUNTERS; i++) {
if (events[i])
l2x0_pmu_event_stop(events[i], PERF_EF_UPDATE);
}
}
void l2x0_pmu_resume(void)
{
int i;
if (!l2x0_pmu)
return;
l2x0_pmu_reset();
for (i = 0; i < PMU_NR_COUNTERS; i++) {
if (events[i])
l2x0_pmu_event_start(events[i], PERF_EF_RELOAD);
}
l2x0_pmu_enable(l2x0_pmu);
}
void __init l2x0_pmu_register(void __iomem *base, u32 part)
{
switch (part & L2X0_CACHE_ID_PART_MASK) {
case L2X0_CACHE_ID_PART_L220:
l2x0_name = "l2c_220";
break;
case L2X0_CACHE_ID_PART_L310:
l2x0_name = "l2c_310";
break;
default:
return;
}
l2x0_base = base;
}
static __init int l2x0_pmu_init(void)
{
int ret;
if (!l2x0_base)
return 0;
l2x0_pmu = kzalloc(sizeof(*l2x0_pmu), GFP_KERNEL);
if (!l2x0_pmu) {
pr_warn("Unable to allocate L2x0 PMU\n");
return -ENOMEM;
}
*l2x0_pmu = (struct pmu) {
.task_ctx_nr = perf_invalid_context,
.pmu_enable = l2x0_pmu_enable,
.pmu_disable = l2x0_pmu_disable,
.read = l2x0_pmu_event_read,
.start = l2x0_pmu_event_start,
.stop = l2x0_pmu_event_stop,
.add = l2x0_pmu_event_add,
.del = l2x0_pmu_event_del,
.event_init = l2x0_pmu_event_init,
.attr_groups = l2x0_pmu_attr_groups,
};
l2x0_pmu_reset();
l2x0_pmu_poll_period = ms_to_ktime(1000);
hrtimer_init(&l2x0_pmu_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
l2x0_pmu_hrtimer.function = l2x0_pmu_poll;
cpumask_set_cpu(0, &pmu_cpu);
ret = cpuhp_setup_state_nocalls(CPUHP_AP_PERF_ARM_L2X0_ONLINE,
"perf/arm/l2x0:online", NULL,
l2x0_pmu_offline_cpu);
if (ret)
goto out_pmu;
ret = perf_pmu_register(l2x0_pmu, l2x0_name, -1);
if (ret)
goto out_cpuhp;
return 0;
out_cpuhp:
cpuhp_remove_state_nocalls(CPUHP_AP_PERF_ARM_L2X0_ONLINE);
out_pmu:
kfree(l2x0_pmu);
l2x0_pmu = NULL;
return ret;
}
