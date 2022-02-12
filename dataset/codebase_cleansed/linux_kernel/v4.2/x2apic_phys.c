static int set_x2apic_phys_mode(char *arg)
{
x2apic_phys = 1;
return 0;
}
static bool x2apic_fadt_phys(void)
{
#ifdef CONFIG_ACPI
if ((acpi_gbl_FADT.header.revision >= FADT2_REVISION_ID) &&
(acpi_gbl_FADT.flags & ACPI_FADT_APIC_PHYSICAL)) {
printk(KERN_DEBUG "System requires x2apic physical mode\n");
return true;
}
#endif
return false;
}
static int x2apic_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
return x2apic_enabled() && (x2apic_phys || x2apic_fadt_phys());
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
static void init_x2apic_ldr(void)
{
}
static int x2apic_phys_probe(void)
{
if (x2apic_mode && (x2apic_phys || x2apic_fadt_phys()))
return 1;
return apic == &apic_x2apic_phys;
}
