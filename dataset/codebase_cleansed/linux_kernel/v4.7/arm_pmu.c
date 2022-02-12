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
int err = 0;
if (!cpumask_test_cpu(smp_processor_id(), &armpmu->supported_cpus))
return -ENOENT;
perf_pmu_disable(event->pmu);
idx = armpmu->get_event_idx(hw_events, event);
if (idx < 0) {
err = idx;
goto out;
}
event->hw.idx = idx;
armpmu->disable(event);
hw_events->events[idx] = event;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
armpmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
out:
perf_pmu_enable(event->pmu);
return err;
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
static irqreturn_t armpmu_dispatch_irq(int irq, void *dev)
{
struct arm_pmu *armpmu;
struct platform_device *plat_device;
struct arm_pmu_platdata *plat;
int ret;
u64 start_clock, finish_clock;
armpmu = *(void **)dev;
plat_device = armpmu->plat_device;
plat = dev_get_platdata(&plat_device->dev);
start_clock = sched_clock();
if (plat && plat->handle_irq)
ret = plat->handle_irq(irq, armpmu, armpmu->handle_irq);
else
ret = armpmu->handle_irq(irq, armpmu);
finish_clock = sched_clock();
perf_sample_event_took(finish_clock - start_clock);
return ret;
}
static void
armpmu_release_hardware(struct arm_pmu *armpmu)
{
armpmu->free_irq(armpmu);
}
static int
armpmu_reserve_hardware(struct arm_pmu *armpmu)
{
int err = armpmu->request_irq(armpmu, armpmu_dispatch_irq);
if (err) {
armpmu_release_hardware(armpmu);
return err;
}
return 0;
}
static void
hw_perf_event_destroy(struct perf_event *event)
{
struct arm_pmu *armpmu = to_arm_pmu(event->pmu);
atomic_t *active_events = &armpmu->active_events;
struct mutex *pmu_reserve_mutex = &armpmu->reserve_mutex;
if (atomic_dec_and_mutex_lock(active_events, pmu_reserve_mutex)) {
armpmu_release_hardware(armpmu);
mutex_unlock(pmu_reserve_mutex);
}
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
int err = 0;
atomic_t *active_events = &armpmu->active_events;
if (event->cpu != -1 &&
!cpumask_test_cpu(event->cpu, &armpmu->supported_cpus))
return -ENOENT;
if (has_branch_stack(event))
return -EOPNOTSUPP;
if (armpmu->map_event(event) == -ENOENT)
return -ENOENT;
event->destroy = hw_perf_event_destroy;
if (!atomic_inc_not_zero(active_events)) {
mutex_lock(&armpmu->reserve_mutex);
if (atomic_read(active_events) == 0)
err = armpmu_reserve_hardware(armpmu);
if (!err)
atomic_inc(active_events);
mutex_unlock(&armpmu->reserve_mutex);
}
if (err)
return err;
err = __hw_perf_event_init(event);
if (err)
hw_perf_event_destroy(event);
return err;
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
static void armpmu_init(struct arm_pmu *armpmu)
{
atomic_set(&armpmu->active_events, 0);
mutex_init(&armpmu->reserve_mutex);
armpmu->pmu = (struct pmu) {
.pmu_enable = armpmu_enable,
.pmu_disable = armpmu_disable,
.event_init = armpmu_event_init,
.add = armpmu_add,
.del = armpmu_del,
.start = armpmu_start,
.stop = armpmu_stop,
.read = armpmu_read,
.filter_match = armpmu_filter_match,
};
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
static void cpu_pmu_enable_percpu_irq(void *data)
{
int irq = *(int *)data;
enable_percpu_irq(irq, IRQ_TYPE_NONE);
}
static void cpu_pmu_disable_percpu_irq(void *data)
{
int irq = *(int *)data;
disable_percpu_irq(irq);
}
static void cpu_pmu_free_irq(struct arm_pmu *cpu_pmu)
{
int i, irq, irqs;
struct platform_device *pmu_device = cpu_pmu->plat_device;
struct pmu_hw_events __percpu *hw_events = cpu_pmu->hw_events;
irqs = min(pmu_device->num_resources, num_possible_cpus());
irq = platform_get_irq(pmu_device, 0);
if (irq >= 0 && irq_is_percpu(irq)) {
on_each_cpu(cpu_pmu_disable_percpu_irq, &irq, 1);
free_percpu_irq(irq, &hw_events->percpu_pmu);
} else {
for (i = 0; i < irqs; ++i) {
int cpu = i;
if (cpu_pmu->irq_affinity)
cpu = cpu_pmu->irq_affinity[i];
if (!cpumask_test_and_clear_cpu(cpu, &cpu_pmu->active_irqs))
continue;
irq = platform_get_irq(pmu_device, i);
if (irq >= 0)
free_irq(irq, per_cpu_ptr(&hw_events->percpu_pmu, cpu));
}
}
}
static int cpu_pmu_request_irq(struct arm_pmu *cpu_pmu, irq_handler_t handler)
{
int i, err, irq, irqs;
struct platform_device *pmu_device = cpu_pmu->plat_device;
struct pmu_hw_events __percpu *hw_events = cpu_pmu->hw_events;
if (!pmu_device)
return -ENODEV;
irqs = min(pmu_device->num_resources, num_possible_cpus());
if (irqs < 1) {
pr_warn_once("perf/ARM: No irqs for PMU defined, sampling events not supported\n");
return 0;
}
irq = platform_get_irq(pmu_device, 0);
if (irq >= 0 && irq_is_percpu(irq)) {
err = request_percpu_irq(irq, handler, "arm-pmu",
&hw_events->percpu_pmu);
if (err) {
pr_err("unable to request IRQ%d for ARM PMU counters\n",
irq);
return err;
}
on_each_cpu(cpu_pmu_enable_percpu_irq, &irq, 1);
} else {
for (i = 0; i < irqs; ++i) {
int cpu = i;
err = 0;
irq = platform_get_irq(pmu_device, i);
if (irq < 0)
continue;
if (cpu_pmu->irq_affinity)
cpu = cpu_pmu->irq_affinity[i];
if (irq_set_affinity(irq, cpumask_of(cpu)) && irqs > 1) {
pr_warn("unable to set irq affinity (irq=%d, cpu=%u)\n",
irq, cpu);
continue;
}
err = request_irq(irq, handler,
IRQF_NOBALANCING | IRQF_NO_THREAD, "arm-pmu",
per_cpu_ptr(&hw_events->percpu_pmu, cpu));
if (err) {
pr_err("unable to request IRQ%d for ARM PMU counters\n",
irq);
return err;
}
cpumask_set_cpu(cpu, &cpu_pmu->active_irqs);
}
}
return 0;
}
static int cpu_pmu_notify(struct notifier_block *b, unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct arm_pmu *pmu = container_of(b, struct arm_pmu, hotplug_nb);
if ((action & ~CPU_TASKS_FROZEN) != CPU_STARTING)
return NOTIFY_DONE;
if (!cpumask_test_cpu(cpu, &pmu->supported_cpus))
return NOTIFY_DONE;
if (pmu->reset)
pmu->reset(pmu);
else
return NOTIFY_DONE;
return NOTIFY_OK;
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
int cpu;
struct pmu_hw_events __percpu *cpu_hw_events;
cpu_hw_events = alloc_percpu(struct pmu_hw_events);
if (!cpu_hw_events)
return -ENOMEM;
cpu_pmu->hotplug_nb.notifier_call = cpu_pmu_notify;
err = register_cpu_notifier(&cpu_pmu->hotplug_nb);
if (err)
goto out_hw_events;
err = cpu_pm_pmu_register(cpu_pmu);
if (err)
goto out_unregister;
for_each_possible_cpu(cpu) {
struct pmu_hw_events *events = per_cpu_ptr(cpu_hw_events, cpu);
raw_spin_lock_init(&events->pmu_lock);
events->percpu_pmu = cpu_pmu;
}
cpu_pmu->hw_events = cpu_hw_events;
cpu_pmu->request_irq = cpu_pmu_request_irq;
cpu_pmu->free_irq = cpu_pmu_free_irq;
if (cpu_pmu->reset)
on_each_cpu_mask(&cpu_pmu->supported_cpus, cpu_pmu->reset,
cpu_pmu, 1);
if (!platform_get_irq(cpu_pmu->plat_device, 0))
cpu_pmu->pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
cpu_pmu->pmu.capabilities |= PERF_PMU_CAP_HETEROGENEOUS_CPUS;
return 0;
out_unregister:
unregister_cpu_notifier(&cpu_pmu->hotplug_nb);
out_hw_events:
free_percpu(cpu_hw_events);
return err;
}
static void cpu_pmu_destroy(struct arm_pmu *cpu_pmu)
{
cpu_pm_pmu_unregister(cpu_pmu);
unregister_cpu_notifier(&cpu_pmu->hotplug_nb);
free_percpu(cpu_pmu->hw_events);
}
static int probe_current_pmu(struct arm_pmu *pmu,
const struct pmu_probe_info *info)
{
int cpu = get_cpu();
unsigned int cpuid = read_cpuid_id();
int ret = -ENODEV;
pr_info("probing PMU on CPU %d\n", cpu);
for (; info->init != NULL; info++) {
if ((cpuid & info->mask) != info->cpuid)
continue;
ret = info->init(pmu);
break;
}
put_cpu();
return ret;
}
static int of_pmu_irq_cfg(struct arm_pmu *pmu)
{
int *irqs, i = 0;
bool using_spi = false;
struct platform_device *pdev = pmu->plat_device;
irqs = kcalloc(pdev->num_resources, sizeof(*irqs), GFP_KERNEL);
if (!irqs)
return -ENOMEM;
do {
struct device_node *dn;
int cpu, irq;
dn = of_parse_phandle(pdev->dev.of_node, "interrupt-affinity", i);
if (!dn)
break;
irq = platform_get_irq(pdev, i);
if (irq >= 0) {
bool spi = !irq_is_percpu(irq);
if (i > 0 && spi != using_spi) {
pr_err("PPI/SPI IRQ type mismatch for %s!\n",
dn->name);
kfree(irqs);
return -EINVAL;
}
using_spi = spi;
}
for_each_possible_cpu(cpu) {
struct device_node *cpu_dn;
cpu_dn = of_cpu_device_node_get(cpu);
of_node_put(cpu_dn);
if (dn == cpu_dn)
break;
}
if (cpu >= nr_cpu_ids) {
pr_warn("Failed to find logical CPU for %s\n",
dn->name);
of_node_put(dn);
cpumask_setall(&pmu->supported_cpus);
break;
}
of_node_put(dn);
if (using_spi) {
if (i >= pdev->num_resources)
break;
irqs[i] = cpu;
}
cpumask_set_cpu(cpu, &pmu->supported_cpus);
i++;
} while (1);
if (cpumask_weight(&pmu->supported_cpus) == 0)
cpumask_setall(&pmu->supported_cpus);
if (using_spi && i == pdev->num_resources)
pmu->irq_affinity = irqs;
else
kfree(irqs);
return 0;
}
int arm_pmu_device_probe(struct platform_device *pdev,
const struct of_device_id *of_table,
const struct pmu_probe_info *probe_table)
{
const struct of_device_id *of_id;
const int (*init_fn)(struct arm_pmu *);
struct device_node *node = pdev->dev.of_node;
struct arm_pmu *pmu;
int ret = -ENODEV;
pmu = kzalloc(sizeof(struct arm_pmu), GFP_KERNEL);
if (!pmu) {
pr_info("failed to allocate PMU device!\n");
return -ENOMEM;
}
armpmu_init(pmu);
pmu->plat_device = pdev;
if (node && (of_id = of_match_node(of_table, pdev->dev.of_node))) {
init_fn = of_id->data;
pmu->secure_access = of_property_read_bool(pdev->dev.of_node,
"secure-reg-access");
if (IS_ENABLED(CONFIG_ARM64) && pmu->secure_access) {
pr_warn("ignoring \"secure-reg-access\" property for arm64\n");
pmu->secure_access = false;
}
ret = of_pmu_irq_cfg(pmu);
if (!ret)
ret = init_fn(pmu);
} else {
cpumask_setall(&pmu->supported_cpus);
ret = probe_current_pmu(pmu, probe_table);
}
if (ret) {
pr_info("%s: failed to probe PMU!\n", of_node_full_name(node));
goto out_free;
}
ret = cpu_pmu_init(pmu);
if (ret)
goto out_free;
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
out_free:
pr_info("%s: failed to register PMU devices!\n",
of_node_full_name(node));
kfree(pmu->irq_affinity);
kfree(pmu);
return ret;
}
