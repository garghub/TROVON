static int x2apic_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
return x2apic_enabled();
}
static inline u32 x2apic_cluster(int cpu)
{
return per_cpu(x86_cpu_to_logical_apicid, cpu) >> 16;
}
static void x2apic_send_IPI(int cpu, int vector)
{
u32 dest = per_cpu(x86_cpu_to_logical_apicid, cpu);
x2apic_wrmsr_fence();
__x2apic_send_IPI_dest(dest, vector, APIC_DEST_LOGICAL);
}
static void
__x2apic_send_IPI_mask(const struct cpumask *mask, int vector, int apic_dest)
{
struct cpumask *cpus_in_cluster_ptr;
struct cpumask *ipi_mask_ptr;
unsigned int cpu, this_cpu;
unsigned long flags;
u32 dest;
x2apic_wrmsr_fence();
local_irq_save(flags);
this_cpu = smp_processor_id();
ipi_mask_ptr = this_cpu_cpumask_var_ptr(ipi_mask);
cpumask_copy(ipi_mask_ptr, mask);
for_each_cpu(cpu, ipi_mask_ptr) {
unsigned long i;
cpus_in_cluster_ptr = per_cpu(cpus_in_cluster, cpu);
dest = 0;
for_each_cpu_and(i, ipi_mask_ptr, cpus_in_cluster_ptr) {
if (apic_dest == APIC_DEST_ALLINC || i != this_cpu)
dest |= per_cpu(x86_cpu_to_logical_apicid, i);
}
if (!dest)
continue;
__x2apic_send_IPI_dest(dest, vector, apic->dest_logical);
cpumask_andnot(ipi_mask_ptr, ipi_mask_ptr, cpus_in_cluster_ptr);
}
local_irq_restore(flags);
}
static void x2apic_send_IPI_mask(const struct cpumask *mask, int vector)
{
__x2apic_send_IPI_mask(mask, vector, APIC_DEST_ALLINC);
}
static void
x2apic_send_IPI_mask_allbutself(const struct cpumask *mask, int vector)
{
__x2apic_send_IPI_mask(mask, vector, APIC_DEST_ALLBUT);
}
static void x2apic_send_IPI_allbutself(int vector)
{
__x2apic_send_IPI_mask(cpu_online_mask, vector, APIC_DEST_ALLBUT);
}
static void x2apic_send_IPI_all(int vector)
{
__x2apic_send_IPI_mask(cpu_online_mask, vector, APIC_DEST_ALLINC);
}
static int
x2apic_cpu_mask_to_apicid(const struct cpumask *mask, struct irq_data *irqdata,
unsigned int *apicid)
{
struct cpumask *effmsk = irq_data_get_effective_affinity_mask(irqdata);
unsigned int cpu;
u32 dest = 0;
u16 cluster;
cpu = cpumask_first(mask);
if (cpu >= nr_cpu_ids)
return -EINVAL;
dest = per_cpu(x86_cpu_to_logical_apicid, cpu);
cluster = x2apic_cluster(cpu);
cpumask_clear(effmsk);
for_each_cpu(cpu, mask) {
if (cluster != x2apic_cluster(cpu))
continue;
dest |= per_cpu(x86_cpu_to_logical_apicid, cpu);
cpumask_set_cpu(cpu, effmsk);
}
*apicid = dest;
return 0;
}
static void init_x2apic_ldr(void)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
per_cpu(x86_cpu_to_logical_apicid, this_cpu) = apic_read(APIC_LDR);
cpumask_set_cpu(this_cpu, per_cpu(cpus_in_cluster, this_cpu));
for_each_online_cpu(cpu) {
if (x2apic_cluster(this_cpu) != x2apic_cluster(cpu))
continue;
cpumask_set_cpu(this_cpu, per_cpu(cpus_in_cluster, cpu));
cpumask_set_cpu(cpu, per_cpu(cpus_in_cluster, this_cpu));
}
}
static int x2apic_prepare_cpu(unsigned int cpu)
{
if (!zalloc_cpumask_var(&per_cpu(cpus_in_cluster, cpu), GFP_KERNEL))
return -ENOMEM;
if (!zalloc_cpumask_var(&per_cpu(ipi_mask, cpu), GFP_KERNEL)) {
free_cpumask_var(per_cpu(cpus_in_cluster, cpu));
return -ENOMEM;
}
return 0;
}
static int x2apic_dead_cpu(unsigned int this_cpu)
{
int cpu;
for_each_online_cpu(cpu) {
if (x2apic_cluster(this_cpu) != x2apic_cluster(cpu))
continue;
cpumask_clear_cpu(this_cpu, per_cpu(cpus_in_cluster, cpu));
cpumask_clear_cpu(cpu, per_cpu(cpus_in_cluster, this_cpu));
}
free_cpumask_var(per_cpu(cpus_in_cluster, this_cpu));
free_cpumask_var(per_cpu(ipi_mask, this_cpu));
return 0;
}
static int x2apic_cluster_probe(void)
{
int cpu = smp_processor_id();
int ret;
if (!x2apic_mode)
return 0;
ret = cpuhp_setup_state(CPUHP_X2APIC_PREPARE, "x86/x2apic:prepare",
x2apic_prepare_cpu, x2apic_dead_cpu);
if (ret < 0) {
pr_err("Failed to register X2APIC_PREPARE\n");
return 0;
}
cpumask_set_cpu(cpu, per_cpu(cpus_in_cluster, cpu));
return 1;
}
static const struct cpumask *x2apic_cluster_target_cpus(void)
{
return cpu_all_mask;
}
static void cluster_vector_allocation_domain(int cpu, struct cpumask *retmask,
const struct cpumask *mask)
{
if (mask == x2apic_cluster_target_cpus())
cpumask_copy(retmask, cpumask_of(cpu));
else
cpumask_and(retmask, mask, per_cpu(cpus_in_cluster, cpu));
}
