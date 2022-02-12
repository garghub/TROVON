static int set_x2apic_phys_mode(char *arg)
{
x2apic_phys = 1;
return 0;
}
static int x2apic_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
if (x2apic_phys)
return x2apic_enabled();
else
return 0;
}
static void
__x2apic_send_IPI_mask(const struct cpumask *mask, int vector, int apic_dest)
{
unsigned long query_cpu;
unsigned long this_cpu;
unsigned long flags;
x2apic_wrmsr_fence();
local_irq_save(flags);
this_cpu = smp_processor_id();
for_each_cpu(query_cpu, mask) {
if (apic_dest == APIC_DEST_ALLBUT && this_cpu == query_cpu)
continue;
__x2apic_send_IPI_dest(per_cpu(x86_cpu_to_apicid, query_cpu),
vector, APIC_DEST_PHYSICAL);
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
static unsigned int x2apic_cpu_mask_to_apicid(const struct cpumask *cpumask)
{
int cpu = cpumask_first(cpumask);
if ((unsigned)cpu < nr_cpu_ids)
return per_cpu(x86_cpu_to_apicid, cpu);
else
return BAD_APICID;
}
static unsigned int
x2apic_cpu_mask_to_apicid_and(const struct cpumask *cpumask,
const struct cpumask *andmask)
{
int cpu;
for_each_cpu_and(cpu, cpumask, andmask) {
if (cpumask_test_cpu(cpu, cpu_online_mask))
break;
}
return per_cpu(x86_cpu_to_apicid, cpu);
}
static void init_x2apic_ldr(void)
{
}
static int x2apic_phys_probe(void)
{
if (x2apic_mode && x2apic_phys)
return 1;
return apic == &apic_x2apic_phys;
}
