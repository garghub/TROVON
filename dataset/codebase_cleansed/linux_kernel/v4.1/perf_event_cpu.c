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
struct arm_pmu *pmu = container_of(b, struct arm_pmu, hotplug_nb);
if ((action & ~CPU_TASKS_FROZEN) != CPU_STARTING)
return NOTIFY_DONE;
if (pmu->reset)
pmu->reset(pmu);
else
return NOTIFY_DONE;
return NOTIFY_OK;
}
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
for_each_possible_cpu(cpu) {
struct pmu_hw_events *events = per_cpu_ptr(cpu_hw_events, cpu);
raw_spin_lock_init(&events->pmu_lock);
events->percpu_pmu = cpu_pmu;
}
cpu_pmu->hw_events = cpu_hw_events;
cpu_pmu->request_irq = cpu_pmu_request_irq;
cpu_pmu->free_irq = cpu_pmu_free_irq;
if (cpu_pmu->reset)
on_each_cpu(cpu_pmu->reset, cpu_pmu, 1);
if (!platform_get_irq(cpu_pmu->plat_device, 0))
cpu_pmu->pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
return 0;
out_hw_events:
free_percpu(cpu_hw_events);
return err;
}
static void cpu_pmu_destroy(struct arm_pmu *cpu_pmu)
{
unregister_cpu_notifier(&cpu_pmu->hotplug_nb);
free_percpu(cpu_pmu->hw_events);
}
static int probe_current_pmu(struct arm_pmu *pmu)
{
int cpu = get_cpu();
unsigned int cpuid = read_cpuid_id();
int ret = -ENODEV;
const struct pmu_probe_info *info;
pr_info("probing PMU on CPU %d\n", cpu);
for (info = pmu_probe_table; info->init != NULL; info++) {
if ((cpuid & info->mask) != info->cpuid)
continue;
ret = info->init(pmu);
break;
}
put_cpu();
return ret;
}
static int of_pmu_irq_cfg(struct platform_device *pdev)
{
int i, irq;
int *irqs;
irq = platform_get_irq(pdev, 0);
if (irq >= 0 && irq_is_percpu(irq))
return 0;
irqs = kcalloc(pdev->num_resources, sizeof(*irqs), GFP_KERNEL);
if (!irqs)
return -ENOMEM;
for (i = 0; i < pdev->num_resources; ++i) {
struct device_node *dn;
int cpu;
dn = of_parse_phandle(pdev->dev.of_node, "interrupt-affinity",
i);
if (!dn) {
pr_warn("Failed to parse %s/interrupt-affinity[%d]\n",
of_node_full_name(pdev->dev.of_node), i);
break;
}
for_each_possible_cpu(cpu)
if (arch_find_n_match_cpu_physical_id(dn, cpu, NULL))
break;
of_node_put(dn);
if (cpu >= nr_cpu_ids) {
pr_warn("Failed to find logical CPU for %s\n",
dn->name);
break;
}
irqs[i] = cpu;
}
if (i == pdev->num_resources)
cpu_pmu->irq_affinity = irqs;
else
kfree(irqs);
return 0;
}
static int cpu_pmu_device_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
const int (*init_fn)(struct arm_pmu *);
struct device_node *node = pdev->dev.of_node;
struct arm_pmu *pmu;
int ret = -ENODEV;
if (cpu_pmu) {
pr_info("attempt to register multiple PMU devices!\n");
return -ENOSPC;
}
pmu = kzalloc(sizeof(struct arm_pmu), GFP_KERNEL);
if (!pmu) {
pr_info("failed to allocate PMU device!\n");
return -ENOMEM;
}
cpu_pmu = pmu;
cpu_pmu->plat_device = pdev;
if (node && (of_id = of_match_node(cpu_pmu_of_device_ids, pdev->dev.of_node))) {
init_fn = of_id->data;
ret = of_pmu_irq_cfg(pdev);
if (!ret)
ret = init_fn(pmu);
} else {
ret = probe_current_pmu(pmu);
}
if (ret) {
pr_info("failed to probe PMU!\n");
goto out_free;
}
ret = cpu_pmu_init(cpu_pmu);
if (ret)
goto out_free;
ret = armpmu_register(cpu_pmu, -1);
if (ret)
goto out_destroy;
return 0;
out_destroy:
cpu_pmu_destroy(cpu_pmu);
out_free:
pr_info("failed to register PMU devices!\n");
kfree(pmu);
return ret;
}
static int __init register_pmu_driver(void)
{
return platform_driver_register(&cpu_pmu_driver);
}
