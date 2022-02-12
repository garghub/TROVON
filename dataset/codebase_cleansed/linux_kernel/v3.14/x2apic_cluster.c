static int x2apic_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
return x2apic_enabled();
}
static inline u32 x2apic_cluster(int cpu)
{
return per_cpu(x86_cpu_to_logical_apicid, cpu) >> 16;
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
ipi_mask_ptr = __raw_get_cpu_var(ipi_mask);
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
x2apic_cpu_mask_to_apicid_and(const struct cpumask *cpumask,
const struct cpumask *andmask,
unsigned int *apicid)
{
u32 dest = 0;
u16 cluster;
int i;
for_each_cpu_and(i, cpumask, andmask) {
if (!cpumask_test_cpu(i, cpu_online_mask))
continue;
dest = per_cpu(x86_cpu_to_logical_apicid, i);
cluster = x2apic_cluster(i);
break;
}
if (!dest)
return -EINVAL;
for_each_cpu_and(i, cpumask, andmask) {
if (!cpumask_test_cpu(i, cpu_online_mask))
continue;
if (cluster != x2apic_cluster(i))
continue;
dest |= per_cpu(x86_cpu_to_logical_apicid, i);
}
*apicid = dest;
return 0;
}
static void init_x2apic_ldr(void)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
per_cpu(x86_cpu_to_logical_apicid, this_cpu) = apic_read(APIC_LDR);
__cpu_set(this_cpu, per_cpu(cpus_in_cluster, this_cpu));
for_each_online_cpu(cpu) {
if (x2apic_cluster(this_cpu) != x2apic_cluster(cpu))
continue;
__cpu_set(this_cpu, per_cpu(cpus_in_cluster, cpu));
__cpu_set(cpu, per_cpu(cpus_in_cluster, this_cpu));
}
}
static int
update_clusterinfo(struct notifier_block *nfb, unsigned long action, void *hcpu)
{
unsigned int this_cpu = (unsigned long)hcpu;
unsigned int cpu;
int err = 0;
switch (action) {
case CPU_UP_PREPARE:
if (!zalloc_cpumask_var(&per_cpu(cpus_in_cluster, this_cpu),
GFP_KERNEL)) {
err = -ENOMEM;
} else if (!zalloc_cpumask_var(&per_cpu(ipi_mask, this_cpu),
GFP_KERNEL)) {
free_cpumask_var(per_cpu(cpus_in_cluster, this_cpu));
err = -ENOMEM;
}
break;
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
case CPU_DEAD:
for_each_online_cpu(cpu) {
if (x2apic_cluster(this_cpu) != x2apic_cluster(cpu))
continue;
__cpu_clear(this_cpu, per_cpu(cpus_in_cluster, cpu));
__cpu_clear(cpu, per_cpu(cpus_in_cluster, this_cpu));
}
free_cpumask_var(per_cpu(cpus_in_cluster, this_cpu));
free_cpumask_var(per_cpu(ipi_mask, this_cpu));
break;
}
return notifier_from_errno(err);
}
static int x2apic_init_cpu_notifier(void)
{
int cpu = smp_processor_id();
zalloc_cpumask_var(&per_cpu(cpus_in_cluster, cpu), GFP_KERNEL);
zalloc_cpumask_var(&per_cpu(ipi_mask, cpu), GFP_KERNEL);
BUG_ON(!per_cpu(cpus_in_cluster, cpu) || !per_cpu(ipi_mask, cpu));
__cpu_set(cpu, per_cpu(cpus_in_cluster, cpu));
register_hotcpu_notifier(&x2apic_cpu_notifier);
return 1;
}
static int x2apic_cluster_probe(void)
{
if (x2apic_mode)
return x2apic_init_cpu_notifier();
else
return 0;
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
