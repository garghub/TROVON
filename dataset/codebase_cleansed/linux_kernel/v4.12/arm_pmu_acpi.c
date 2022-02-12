static int arm_pmu_acpi_register_irq(int cpu)
{
struct acpi_madt_generic_interrupt *gicc;
int gsi, trigger;
gicc = acpi_cpu_get_madt_gicc(cpu);
if (WARN_ON(!gicc))
return -EINVAL;
gsi = gicc->performance_interrupt;
if (!gsi)
return 0;
if (gicc->flags & ACPI_MADT_PERFORMANCE_IRQ_MODE)
trigger = ACPI_EDGE_SENSITIVE;
else
trigger = ACPI_LEVEL_SENSITIVE;
return acpi_register_gsi(NULL, gsi, trigger, ACPI_ACTIVE_HIGH);
}
static void arm_pmu_acpi_unregister_irq(int cpu)
{
struct acpi_madt_generic_interrupt *gicc;
int gsi;
gicc = acpi_cpu_get_madt_gicc(cpu);
if (!gicc)
return;
gsi = gicc->performance_interrupt;
acpi_unregister_gsi(gsi);
}
static int arm_pmu_acpi_parse_irqs(void)
{
int irq, cpu, irq_cpu, err;
for_each_possible_cpu(cpu) {
irq = arm_pmu_acpi_register_irq(cpu);
if (irq < 0) {
err = irq;
pr_warn("Unable to parse ACPI PMU IRQ for CPU%d: %d\n",
cpu, err);
goto out_err;
} else if (irq == 0) {
pr_warn("No ACPI PMU IRQ for CPU%d\n", cpu);
}
per_cpu(pmu_irqs, cpu) = irq;
}
return 0;
out_err:
for_each_possible_cpu(cpu) {
irq = per_cpu(pmu_irqs, cpu);
if (!irq)
continue;
arm_pmu_acpi_unregister_irq(cpu);
for_each_possible_cpu(irq_cpu) {
if (per_cpu(pmu_irqs, irq_cpu) == irq)
per_cpu(pmu_irqs, irq_cpu) = 0;
}
}
return err;
}
static struct arm_pmu *arm_pmu_acpi_find_alloc_pmu(void)
{
unsigned long cpuid = read_cpuid_id();
struct arm_pmu *pmu;
int cpu;
for_each_possible_cpu(cpu) {
pmu = per_cpu(probed_pmus, cpu);
if (!pmu || pmu->acpi_cpuid != cpuid)
continue;
return pmu;
}
pmu = armpmu_alloc();
if (!pmu) {
pr_warn("Unable to allocate PMU for CPU%d\n",
smp_processor_id());
return NULL;
}
pmu->acpi_cpuid = cpuid;
return pmu;
}
static int arm_pmu_acpi_cpu_starting(unsigned int cpu)
{
struct arm_pmu *pmu;
struct pmu_hw_events __percpu *hw_events;
int irq;
if (per_cpu(probed_pmus, cpu))
return 0;
irq = per_cpu(pmu_irqs, cpu);
pmu = arm_pmu_acpi_find_alloc_pmu();
if (!pmu)
return -ENOMEM;
cpumask_set_cpu(cpu, &pmu->supported_cpus);
per_cpu(probed_pmus, cpu) = pmu;
hw_events = pmu->hw_events;
per_cpu(hw_events->irq, cpu) = irq;
armpmu_request_irq(pmu, cpu);
return 0;
}
int arm_pmu_acpi_probe(armpmu_init_fn init_fn)
{
int pmu_idx = 0;
int cpu, ret;
if (acpi_disabled)
return 0;
for_each_possible_cpu(cpu) {
struct arm_pmu *pmu = per_cpu(probed_pmus, cpu);
char *base_name;
if (!pmu || pmu->name)
continue;
ret = init_fn(pmu);
if (ret == -ENODEV) {
continue;
} else if (ret) {
pr_warn("Unable to initialise PMU for CPU%d\n", cpu);
return ret;
}
base_name = pmu->name;
pmu->name = kasprintf(GFP_KERNEL, "%s_%d", base_name, pmu_idx++);
if (!pmu->name) {
pr_warn("Unable to allocate PMU name for CPU%d\n", cpu);
return -ENOMEM;
}
ret = armpmu_register(pmu);
if (ret) {
pr_warn("Failed to register PMU for CPU%d\n", cpu);
return ret;
}
}
return 0;
}
static int arm_pmu_acpi_init(void)
{
int ret;
if (acpi_disabled)
return 0;
ret = arm_pmu_acpi_parse_irqs();
if (ret)
return ret;
ret = cpuhp_setup_state(CPUHP_AP_PERF_ARM_ACPI_STARTING,
"perf/arm/pmu_acpi:starting",
arm_pmu_acpi_cpu_starting, NULL);
return ret;
}
