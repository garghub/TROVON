static int
armpmu_map_raw_event(u32 raw_event_mask, u64 config)
{
return (int)(config & raw_event_mask);
}
int armpmu_event_set_period(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
s64 left = local64_read(&hwc->period_left);
s64 period = hwc->sample_period;
int ret = 0;
if (unlikely(left <= -period)) {
left = period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
}
if (unlikely(left <= 0)) {
left += period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
}
if (left > (armpmu->max_period >> 1))
left = armpmu->max_period >> 1;
local64_set(&hwc->prev_count, (u64)-left);
armpmu->write_counter(event, (u64)(-left) & 0xffffffff);
perf_event_update_userpage(event);
return ret;
}
u64 armpmu_event_update(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
u64 delta, prev_raw_count, new_raw_count;
again:
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = armpmu->read_counter(event);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
delta = (new_raw_count - prev_raw_count) & armpmu->max_period;
local64_add(delta, &event->count);
local64_sub(delta, &hwc->period_left);
return new_raw_count;
}
static void
armpmu_read(struct perf_event *event)
{
armpmu_event_update(event);
}
static void
armpmu_stop(struct perf_event *event, int flags)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
if (!(hwc->state & PERF_HES_STOPPED)) {
armpmu->disable(event);
armpmu_event_update(event);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
}
static void armpmu_start(struct perf_event *event, int flags)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
if (flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
armpmu_event_set_period(event);
armpmu->enable(event);
}
static void
armpmu_del(struct perf_event *event, int flags)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *hw_events = this_cpu_ptr(armpmu->hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
armpmu_stop(event, PERF_EF_UPDATE);
hw_events->events[idx] = NULL;
clear_bit(idx, hw_events->used_mask);
if (armpmu->clear_event_idx)
armpmu->clear_event_idx(hw_events, event);
perf_event_update_userpage(event);
}
static int
armpmu_add(struct perf_event *event, int flags)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *hw_events = this_cpu_ptr(armpmu->hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx;
if (!cpumask_test_cpu(smp_processor_id(), &armpmu->supported_cpus))
return -ENOENT;
idx = armpmu->get_event_idx(hw_events, event);
if (idx < 0)
return idx;
event->hw.idx = idx;
armpmu->disable(event);
hw_events->events[idx] = event;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
armpmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
return 0;
}
static int
validate_event(struct pmu *pmu, struct pmu_hw_events *hw_events,
struct perf_event *event)
{
struct arm_pmu *armpmu;
if (is_software_event(event))
return 1;
if (event->pmu != pmu)
return 0;
if (event->state < PERF_EVENT_STATE_OFF)
return 1;
if (event->state == PERF_EVENT_STATE_OFF && !event->attr.enable_on_exec)
return 1;
armpmu = to_arm_pmu(event->pmu);
return armpmu->get_event_idx(hw_events, event) >= 0;
}
static int
validate_group(struct perf_event *event)
{
struct perf_event *sibling, *leader = event->group_leader;
struct pmu_hw_events fake_pmu;
memset(&fake_pmu.used_mask, 0, sizeof(fake_pmu.used_mask));
if (!validate_event(event->pmu, &fake_pmu, leader))
return -EINVAL;
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (!validate_event(event->pmu, &fake_pmu, sibling))
return -EINVAL;
}
if (!validate_event(event->pmu, &fake_pmu, event))
return -EINVAL;
return 0;
}
static struct arm_pmu_platdata *armpmu_get_platdata(struct arm_pmu *armpmu)
{
struct platform_device *pdev = armpmu->plat_device;
return pdev ? dev_get_platdata(&pdev->dev) : NULL;
}
static irqreturn_t armpmu_dispatch_irq(int irq, void *dev)
{
struct arm_pmu *armpmu;
struct arm_pmu_platdata *plat;
int ret;
u64 start_clock, finish_clock;
armpmu = *(void **)dev;
plat = armpmu_get_platdata(armpmu);
start_clock = sched_clock();
if (plat && plat->handle_irq)
ret = plat->handle_irq(irq, armpmu, armpmu->handle_irq);
else
ret = armpmu->handle_irq(irq, armpmu);
finish_clock = sched_clock();
perf_sample_event_took(finish_clock - start_clock);
return ret;
}
static int
event_requires_mode_exclusion(struct perf_event_attr *attr)
{
return attr->exclude_idle || attr->exclude_user ||
attr->exclude_kernel || attr->exclude_hv;
}
static int
__hw_perf_event_init(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int mapping;
mapping = armpmu->map_event(event);
if (mapping < 0) {
pr_debug("event %x:%llx not supported\n", event->attr.type,
event->attr.config);
return mapping;
}
hwc->idx = -1;
hwc->config_base = 0;
hwc->config = 0;
hwc->event_base = 0;
if ((!armpmu->set_event_filter ||
armpmu->set_event_filter(hwc, &event->attr)) &&
event_requires_mode_exclusion(&event->attr)) {
pr_debug("ARM performance counters do not support "
"mode exclusion\n");
return -EOPNOTSUPP;
}
hwc->config_base |= (unsigned long)mapping;
if (!is_sampling_event(event)) {
hwc->sample_period = armpmu->max_period >> 1;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
if (event->group_leader != event) {
if (validate_group(event) != 0)
return -EINVAL;
}
return 0;
}
static int armpmu_event_init(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
if (event->cpu != -1 &&
!cpumask_test_cpu(event->cpu, &armpmu->supported_cpus))
return -ENOENT;
if (has_branch_stack(event))
return -EOPNOTSUPP;
if (armpmu->map_event(event) == -ENOENT)
return -ENOENT;
return __hw_perf_event_init(event);
}
static void armpmu_enable(struct pmu *pmu)
{
struct arm_pmu *armpmu = to_arm_pmu(pmu);
struct pmu_hw_events *hw_events = this_cpu_ptr(armpmu->hw_events);
int enabled = bitmap_weight(hw_events->used_mask, armpmu->num_events);
if (!cpumask_test_cpu(smp_processor_id(), &armpmu->supported_cpus))
return;
if (enabled)
armpmu->start(armpmu);
}
static void armpmu_disable(struct pmu *pmu)
{
struct arm_pmu *armpmu = to_arm_pmu(pmu);
if (!cpumask_test_cpu(smp_processor_id(), &armpmu->supported_cpus))
return;
armpmu->stop(armpmu);
}
static int armpmu_filter_match(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
unsigned int cpu = smp_processor_id();
return cpumask_test_cpu(cpu, &armpmu->supported_cpus);
}
static ssize_t armpmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct arm_pmu *armpmu = to_arm_pmu(dev_get_drvdata(dev));
return cpumap_print_to_pagebuf(true, buf, &armpmu->supported_cpus);
}
const char *perf_pmu_name(void)
{
if (!__oprofile_cpu_pmu)
return NULL;
return __oprofile_cpu_pmu->name;
}
int perf_num_counters(void)
{
int max_events = 0;
if (__oprofile_cpu_pmu != NULL)
max_events = __oprofile_cpu_pmu->num_events;
return max_events;
}
void armpmu_free_irq(struct arm_pmu *armpmu, int cpu)
{
struct pmu_hw_events __percpu *hw_events = armpmu->hw_events;
int irq = per_cpu(hw_events->irq, cpu);
if (!cpumask_test_and_clear_cpu(cpu, &armpmu->active_irqs))
return;
if (irq_is_percpu(irq)) {
free_percpu_irq(irq, &hw_events->percpu_pmu);
cpumask_clear(&armpmu->active_irqs);
return;
}
free_irq(irq, per_cpu_ptr(&hw_events->percpu_pmu, cpu));
}
void armpmu_free_irqs(struct arm_pmu *armpmu)
{
int cpu;
for_each_cpu(cpu, &armpmu->supported_cpus)
armpmu_free_irq(armpmu, cpu);
}
int armpmu_request_irq(struct arm_pmu *armpmu, int cpu)
{
int err = 0;
struct pmu_hw_events __percpu *hw_events = armpmu->hw_events;
const irq_handler_t handler = armpmu_dispatch_irq;
int irq = per_cpu(hw_events->irq, cpu);
if (!irq)
return 0;
if (irq_is_percpu(irq) && cpumask_empty(&armpmu->active_irqs)) {
err = request_percpu_irq(irq, handler, "arm-pmu",
&hw_events->percpu_pmu);
} else if (irq_is_percpu(irq)) {
int other_cpu = cpumask_first(&armpmu->active_irqs);
int other_irq = per_cpu(hw_events->irq, other_cpu);
if (irq != other_irq) {
pr_warn("mismatched PPIs detected.\n");
err = -EINVAL;
}
} else {
err = request_irq(irq, handler,
IRQF_NOBALANCING | IRQF_NO_THREAD, "arm-pmu",
per_cpu_ptr(&hw_events->percpu_pmu, cpu));
}
if (err) {
pr_err("unable to request IRQ%d for ARM PMU counters\n",
irq);
return err;
}
cpumask_set_cpu(cpu, &armpmu->active_irqs);
return 0;
}
int armpmu_request_irqs(struct arm_pmu *armpmu)
{
int cpu, err;
for_each_cpu(cpu, &armpmu->supported_cpus) {
err = armpmu_request_irq(armpmu, cpu);
if (err)
break;
}
return err;
}
static int armpmu_get_cpu_irq(struct arm_pmu *pmu, int cpu)
{
struct pmu_hw_events __percpu *hw_events = pmu->hw_events;
return per_cpu(hw_events->irq, cpu);
}
static int arm_perf_starting_cpu(unsigned int cpu, struct hlist_node *node)
{
struct arm_pmu *pmu = hlist_entry_safe(node, struct arm_pmu, node);
int irq;
if (!cpumask_test_cpu(cpu, &pmu->supported_cpus))
return 0;
if (pmu->reset)
pmu->reset(pmu);
irq = armpmu_get_cpu_irq(pmu, cpu);
if (irq) {
if (irq_is_percpu(irq)) {
enable_percpu_irq(irq, IRQ_TYPE_NONE);
return 0;
}
if (irq_force_affinity(irq, cpumask_of(cpu)) &&
num_possible_cpus() > 1) {
pr_warn("unable to set irq affinity (irq=%d, cpu=%u)\n",
irq, cpu);
}
}
return 0;
}
static int arm_perf_teardown_cpu(unsigned int cpu, struct hlist_node *node)
{
struct arm_pmu *pmu = hlist_entry_safe(node, struct arm_pmu, node);
int irq;
if (!cpumask_test_cpu(cpu, &pmu->supported_cpus))
return 0;
irq = armpmu_get_cpu_irq(pmu, cpu);
if (irq && irq_is_percpu(irq))
disable_percpu_irq(irq);
return 0;
}
static void cpu_pm_pmu_setup(struct arm_pmu *armpmu, unsigned long cmd)
{
struct pmu_hw_events *hw_events = this_cpu_ptr(armpmu->hw_events);
struct perf_event *event;
int idx;
for (idx = 0; idx < armpmu->num_events; idx++) {
if (!test_bit(idx, hw_events->used_mask))
continue;
event = hw_events->events[idx];
switch (cmd) {
case CPU_PM_ENTER:
armpmu_stop(event, PERF_EF_UPDATE);
break;
case CPU_PM_EXIT:
case CPU_PM_ENTER_FAILED:
RCU_NONIDLE(armpmu_start(event, PERF_EF_RELOAD));
break;
default:
break;
}
}
}
static int cpu_pm_pmu_notify(struct notifier_block *b, unsigned long cmd,
void *v)
{
struct arm_pmu *armpmu = container_of(b, struct arm_pmu, cpu_pm_nb);
struct pmu_hw_events *hw_events = this_cpu_ptr(armpmu->hw_events);
int enabled = bitmap_weight(hw_events->used_mask, armpmu->num_events);
if (!cpumask_test_cpu(smp_processor_id(), &armpmu->supported_cpus))
return NOTIFY_DONE;
if (cmd == CPU_PM_EXIT && armpmu->reset)
armpmu->reset(armpmu);
if (!enabled)
return NOTIFY_OK;
switch (cmd) {
case CPU_PM_ENTER:
armpmu->stop(armpmu);
cpu_pm_pmu_setup(armpmu, cmd);
break;
case CPU_PM_EXIT:
cpu_pm_pmu_setup(armpmu, cmd);
case CPU_PM_ENTER_FAILED:
armpmu->start(armpmu);
break;
default:
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static int cpu_pm_pmu_register(struct arm_pmu *cpu_pmu)
{
cpu_pmu->cpu_pm_nb.notifier_call = cpu_pm_pmu_notify;
return cpu_pm_register_notifier(&cpu_pmu->cpu_pm_nb);
}
static void cpu_pm_pmu_unregister(struct arm_pmu *cpu_pmu)
{
cpu_pm_unregister_notifier(&cpu_pmu->cpu_pm_nb);
}
static inline int cpu_pm_pmu_register(struct arm_pmu *cpu_pmu) { return 0; }
static inline void cpu_pm_pmu_unregister(struct arm_pmu *cpu_pmu) { }
static int cpu_pmu_init(struct arm_pmu *cpu_pmu)
{
int err;
err = cpuhp_state_add_instance(CPUHP_AP_PERF_ARM_STARTING,
&cpu_pmu->node);
if (err)
goto out;
err = cpu_pm_pmu_register(cpu_pmu);
if (err)
goto out_unregister;
return 0;
out_unregister:
cpuhp_state_remove_instance_nocalls(CPUHP_AP_PERF_ARM_STARTING,
&cpu_pmu->node);
out:
return err;
}
static void cpu_pmu_destroy(struct arm_pmu *cpu_pmu)
{
cpu_pm_pmu_unregister(cpu_pmu);
cpuhp_state_remove_instance_nocalls(CPUHP_AP_PERF_ARM_STARTING,
&cpu_pmu->node);
}
struct arm_pmu *armpmu_alloc(void)
{
struct arm_pmu *pmu;
int cpu;
pmu = kzalloc(sizeof(*pmu), GFP_KERNEL);
if (!pmu) {
pr_info("failed to allocate PMU device!\n");
goto out;
}
pmu->hw_events = alloc_percpu(struct pmu_hw_events);
if (!pmu->hw_events) {
pr_info("failed to allocate per-cpu PMU data.\n");
goto out_free_pmu;
}
pmu->pmu = (struct pmu) {
.pmu_enable = armpmu_enable,
.pmu_disable = armpmu_disable,
.event_init = armpmu_event_init,
.add = armpmu_add,
.del = armpmu_del,
.start = armpmu_start,
.stop = armpmu_stop,
.read = armpmu_read,
.filter_match = armpmu_filter_match,
.attr_groups = pmu->attr_groups,
.capabilities = PERF_PMU_CAP_HETEROGENEOUS_CPUS,
};
pmu->attr_groups[ARMPMU_ATTR_GROUP_COMMON] =
&armpmu_common_attr_group;
for_each_possible_cpu(cpu) {
struct pmu_hw_events *events;
events = per_cpu_ptr(pmu->hw_events, cpu);
raw_spin_lock_init(&events->pmu_lock);
events->percpu_pmu = pmu;
}
return pmu;
out_free_pmu:
kfree(pmu);
out:
return NULL;
}
void armpmu_free(struct arm_pmu *pmu)
{
free_percpu(pmu->hw_events);
kfree(pmu);
}
int armpmu_register(struct arm_pmu *pmu)
{
int ret;
ret = cpu_pmu_init(pmu);
if (ret)
return ret;
ret = perf_pmu_register(&pmu->pmu, pmu->name, -1);
if (ret)
goto out_destroy;
if (!__oprofile_cpu_pmu)
__oprofile_cpu_pmu = pmu;
pr_info("enabled with %s PMU driver, %d counters available\n",
pmu->name, pmu->num_events);
return 0;
out_destroy:
cpu_pmu_destroy(pmu);
return ret;
}
static int arm_pmu_hp_init(void)
{
int ret;
ret = cpuhp_setup_state_multi(CPUHP_AP_PERF_ARM_STARTING,
"perf/arm/pmu:starting",
arm_perf_starting_cpu,
arm_perf_teardown_cpu);
if (ret)
pr_err("CPU hotplug notifier for ARM PMU could not be registered: %d\n",
ret);
return ret;
}
