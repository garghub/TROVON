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
static int pmu_parse_percpu_irq(struct arm_pmu *pmu, int irq)
{
int cpu, ret;
struct pmu_hw_events __percpu *hw_events = pmu->hw_events;
ret = irq_get_percpu_devid_partition(irq, &pmu->supported_cpus);
if (ret)
return ret;
for_each_cpu(cpu, &pmu->supported_cpus)
per_cpu(hw_events->irq, cpu) = irq;
return 0;
}
static bool pmu_has_irq_affinity(struct device_node *node)
{
return !!of_find_property(node, "interrupt-affinity", NULL);
}
static int pmu_parse_irq_affinity(struct device_node *node, int i)
{
struct device_node *dn;
int cpu;
if (!pmu_has_irq_affinity(node))
return i;
dn = of_parse_phandle(node, "interrupt-affinity", i);
if (!dn) {
pr_warn("failed to parse interrupt-affinity[%d] for %s\n",
i, node->name);
return -EINVAL;
}
for_each_possible_cpu(cpu) {
struct device_node *cpu_dn;
cpu_dn = of_cpu_device_node_get(cpu);
of_node_put(cpu_dn);
if (dn == cpu_dn)
break;
}
if (cpu >= nr_cpu_ids) {
pr_warn("failed to find logical CPU for %s\n", dn->name);
}
of_node_put(dn);
return cpu;
}
static int pmu_parse_irqs(struct arm_pmu *pmu)
{
int i = 0, num_irqs;
struct platform_device *pdev = pmu->plat_device;
struct pmu_hw_events __percpu *hw_events = pmu->hw_events;
num_irqs = platform_irq_count(pdev);
if (num_irqs < 0) {
pr_err("unable to count PMU IRQs\n");
return num_irqs;
}
if (num_irqs == 0) {
pr_warn("no irqs for PMU, sampling events not supported\n");
pmu->pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
cpumask_setall(&pmu->supported_cpus);
return 0;
}
if (num_irqs == 1) {
int irq = platform_get_irq(pdev, 0);
if (irq && irq_is_percpu(irq))
return pmu_parse_percpu_irq(pmu, irq);
}
if (!pmu_has_irq_affinity(pdev->dev.of_node)) {
pr_warn("no interrupt-affinity property for %pOF, guessing.\n",
pdev->dev.of_node);
}
if (dev_get_platdata(&pdev->dev))
cpumask_setall(&pmu->supported_cpus);
for (i = 0; i < num_irqs; i++) {
int cpu, irq;
irq = platform_get_irq(pdev, i);
if (WARN_ON(irq <= 0))
continue;
if (irq_is_percpu(irq)) {
pr_warn("multiple PPIs or mismatched SPI/PPI detected\n");
return -EINVAL;
}
cpu = pmu_parse_irq_affinity(pdev->dev.of_node, i);
if (cpu < 0)
return cpu;
if (cpu >= nr_cpu_ids)
continue;
if (per_cpu(hw_events->irq, cpu)) {
pr_warn("multiple PMU IRQs for the same CPU detected\n");
return -EINVAL;
}
per_cpu(hw_events->irq, cpu) = irq;
cpumask_set_cpu(cpu, &pmu->supported_cpus);
}
return 0;
}
int arm_pmu_device_probe(struct platform_device *pdev,
const struct of_device_id *of_table,
const struct pmu_probe_info *probe_table)
{
const struct of_device_id *of_id;
armpmu_init_fn init_fn;
struct device_node *node = pdev->dev.of_node;
struct arm_pmu *pmu;
int ret = -ENODEV;
pmu = armpmu_alloc();
if (!pmu)
return -ENOMEM;
pmu->plat_device = pdev;
ret = pmu_parse_irqs(pmu);
if (ret)
goto out_free;
if (node && (of_id = of_match_node(of_table, pdev->dev.of_node))) {
init_fn = of_id->data;
pmu->secure_access = of_property_read_bool(pdev->dev.of_node,
"secure-reg-access");
if (IS_ENABLED(CONFIG_ARM64) && pmu->secure_access) {
pr_warn("ignoring \"secure-reg-access\" property for arm64\n");
pmu->secure_access = false;
}
ret = init_fn(pmu);
} else if (probe_table) {
cpumask_setall(&pmu->supported_cpus);
ret = probe_current_pmu(pmu, probe_table);
}
if (ret) {
pr_info("%pOF: failed to probe PMU!\n", node);
goto out_free;
}
ret = armpmu_request_irqs(pmu);
if (ret)
goto out_free_irqs;
ret = armpmu_register(pmu);
if (ret)
goto out_free;
return 0;
out_free_irqs:
armpmu_free_irqs(pmu);
out_free:
pr_info("%pOF: failed to register PMU devices!\n", node);
armpmu_free(pmu);
return ret;
}
