const char *perf_pmu_name(void)
{
if (!cpu_pmu)
return NULL;
return cpu_pmu->name;
}
int perf_num_counters(void)
{
int max_events = 0;
if (cpu_pmu != NULL)
max_events = cpu_pmu->num_events;
return max_events;
}
static struct pmu_hw_events *cpu_pmu_get_cpu_events(void)
{
return &__get_cpu_var(cpu_hw_events);
}
static void cpu_pmu_free_irq(struct arm_pmu *cpu_pmu)
{
int i, irq, irqs;
struct platform_device *pmu_device = cpu_pmu->plat_device;
irqs = min(pmu_device->num_resources, num_possible_cpus());
for (i = 0; i < irqs; ++i) {
if (!cpumask_test_and_clear_cpu(i, &cpu_pmu->active_irqs))
continue;
irq = platform_get_irq(pmu_device, i);
if (irq >= 0)
free_irq(irq, cpu_pmu);
}
}
static int cpu_pmu_request_irq(struct arm_pmu *cpu_pmu, irq_handler_t handler)
{
int i, err, irq, irqs;
struct platform_device *pmu_device = cpu_pmu->plat_device;
if (!pmu_device)
return -ENODEV;
irqs = min(pmu_device->num_resources, num_possible_cpus());
if (irqs < 1) {
pr_err("no irqs for PMUs defined\n");
return -ENODEV;
}
for (i = 0; i < irqs; ++i) {
err = 0;
irq = platform_get_irq(pmu_device, i);
if (irq < 0)
continue;
if (irq_set_affinity(irq, cpumask_of(i)) && irqs > 1) {
pr_warning("unable to set irq affinity (irq=%d, cpu=%u)\n",
irq, i);
continue;
}
err = request_irq(irq, handler, IRQF_NOBALANCING, "arm-pmu",
cpu_pmu);
if (err) {
pr_err("unable to request IRQ%d for ARM PMU counters\n",
irq);
return err;
}
cpumask_set_cpu(i, &cpu_pmu->active_irqs);
}
return 0;
}
static void cpu_pmu_init(struct arm_pmu *cpu_pmu)
{
int cpu;
for_each_possible_cpu(cpu) {
struct pmu_hw_events *events = &per_cpu(cpu_hw_events, cpu);
events->events = per_cpu(hw_events, cpu);
events->used_mask = per_cpu(used_mask, cpu);
raw_spin_lock_init(&events->pmu_lock);
}
cpu_pmu->get_hw_events = cpu_pmu_get_cpu_events;
cpu_pmu->request_irq = cpu_pmu_request_irq;
cpu_pmu->free_irq = cpu_pmu_free_irq;
if (cpu_pmu && cpu_pmu->reset)
on_each_cpu(cpu_pmu->reset, cpu_pmu, 1);
}
static int __cpuinit cpu_pmu_notify(struct notifier_block *b,
unsigned long action, void *hcpu)
{
if ((action & ~CPU_TASKS_FROZEN) != CPU_STARTING)
return NOTIFY_DONE;
if (cpu_pmu && cpu_pmu->reset)
cpu_pmu->reset(cpu_pmu);
else
return NOTIFY_DONE;
return NOTIFY_OK;
}
static int probe_current_pmu(struct arm_pmu *pmu)
{
int cpu = get_cpu();
unsigned long cpuid = read_cpuid_id();
unsigned long implementor = (cpuid & 0xFF000000) >> 24;
unsigned long part_number = (cpuid & 0xFFF0);
int ret = -ENODEV;
pr_info("probing PMU on CPU %d\n", cpu);
if (0x41 == implementor) {
switch (part_number) {
case 0xB360:
case 0xB560:
case 0xB760:
ret = armv6pmu_init(pmu);
break;
case 0xB020:
ret = armv6mpcore_pmu_init(pmu);
break;
case 0xC080:
ret = armv7_a8_pmu_init(pmu);
break;
case 0xC090:
ret = armv7_a9_pmu_init(pmu);
break;
case 0xC050:
ret = armv7_a5_pmu_init(pmu);
break;
case 0xC0F0:
ret = armv7_a15_pmu_init(pmu);
break;
case 0xC070:
ret = armv7_a7_pmu_init(pmu);
break;
}
} else if (0x69 == implementor) {
part_number = (cpuid >> 13) & 0x7;
switch (part_number) {
case 1:
ret = xscale1pmu_init(pmu);
break;
case 2:
ret = xscale2pmu_init(pmu);
break;
}
}
put_cpu();
return ret;
}
static int cpu_pmu_device_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
int (*init_fn)(struct arm_pmu *);
struct device_node *node = pdev->dev.of_node;
struct arm_pmu *pmu;
int ret = -ENODEV;
if (cpu_pmu) {
pr_info("attempt to register multiple PMU devices!");
return -ENOSPC;
}
pmu = kzalloc(sizeof(struct arm_pmu), GFP_KERNEL);
if (!pmu) {
pr_info("failed to allocate PMU device!");
return -ENOMEM;
}
if (node && (of_id = of_match_node(cpu_pmu_of_device_ids, pdev->dev.of_node))) {
init_fn = of_id->data;
ret = init_fn(pmu);
} else {
ret = probe_current_pmu(pmu);
}
if (ret) {
pr_info("failed to register PMU devices!");
kfree(pmu);
return ret;
}
cpu_pmu = pmu;
cpu_pmu->plat_device = pdev;
cpu_pmu_init(cpu_pmu);
armpmu_register(cpu_pmu, PERF_TYPE_RAW);
return 0;
}
static int __init register_pmu_driver(void)
{
int err;
err = register_cpu_notifier(&cpu_pmu_hotplug_notifier);
if (err)
return err;
err = platform_driver_register(&cpu_pmu_driver);
if (err)
unregister_cpu_notifier(&cpu_pmu_hotplug_notifier);
return err;
}
