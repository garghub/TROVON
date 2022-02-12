static int flat_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
return 1;
}
void flat_init_apic_ldr(void)
{
unsigned long val;
unsigned long num, id;
num = smp_processor_id();
id = 1UL << num;
apic_write(APIC_DFR, APIC_DFR_FLAT);
val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
val |= SET_APIC_LOGICAL_ID(id);
apic_write(APIC_LDR, val);
}
static void _flat_send_IPI_mask(unsigned long mask, int vector)
{
unsigned long flags;
local_irq_save(flags);
__default_send_IPI_dest_field(mask, vector, apic->dest_logical);
local_irq_restore(flags);
}
static void flat_send_IPI_mask(const struct cpumask *cpumask, int vector)
{
unsigned long mask = cpumask_bits(cpumask)[0];
_flat_send_IPI_mask(mask, vector);
}
static void
flat_send_IPI_mask_allbutself(const struct cpumask *cpumask, int vector)
{
unsigned long mask = cpumask_bits(cpumask)[0];
int cpu = smp_processor_id();
if (cpu < BITS_PER_LONG)
clear_bit(cpu, &mask);
_flat_send_IPI_mask(mask, vector);
}
static void flat_send_IPI_allbutself(int vector)
{
int cpu = smp_processor_id();
#ifdef CONFIG_HOTPLUG_CPU
int hotplug = 1;
#else
int hotplug = 0;
#endif
if (hotplug || vector == NMI_VECTOR) {
if (!cpumask_equal(cpu_online_mask, cpumask_of(cpu))) {
unsigned long mask = cpumask_bits(cpu_online_mask)[0];
if (cpu < BITS_PER_LONG)
clear_bit(cpu, &mask);
_flat_send_IPI_mask(mask, vector);
}
} else if (num_online_cpus() > 1) {
__default_send_IPI_shortcut(APIC_DEST_ALLBUT,
vector, apic->dest_logical);
}
}
static void flat_send_IPI_all(int vector)
{
if (vector == NMI_VECTOR) {
flat_send_IPI_mask(cpu_online_mask, vector);
} else {
__default_send_IPI_shortcut(APIC_DEST_ALLINC,
vector, apic->dest_logical);
}
}
static unsigned int flat_get_apic_id(unsigned long x)
{
return (x >> 24) & 0xFF;
}
static unsigned long set_apic_id(unsigned int id)
{
return (id & 0xFF) << 24;
}
static unsigned int read_xapic_id(void)
{
return flat_get_apic_id(apic_read(APIC_ID));
}
static int flat_apic_id_registered(void)
{
return physid_isset(read_xapic_id(), phys_cpu_present_map);
}
static int flat_phys_pkg_id(int initial_apic_id, int index_msb)
{
return initial_apic_id >> index_msb;
}
static int flat_probe(void)
{
return 1;
}
static int physflat_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
#ifdef CONFIG_ACPI
if (acpi_gbl_FADT.header.revision >= FADT2_REVISION_ID &&
(acpi_gbl_FADT.flags & ACPI_FADT_APIC_PHYSICAL)) {
printk(KERN_DEBUG "system APIC only can use physical flat");
return 1;
}
if (!strncmp(oem_id, "IBM", 3) && !strncmp(oem_table_id, "EXA", 3)) {
printk(KERN_DEBUG "IBM Summit detected, will use apic physical");
return 1;
}
#endif
return 0;
}
static void physflat_send_IPI_allbutself(int vector)
{
default_send_IPI_mask_allbutself_phys(cpu_online_mask, vector);
}
static void physflat_send_IPI_all(int vector)
{
default_send_IPI_mask_sequence_phys(cpu_online_mask, vector);
}
static int physflat_probe(void)
{
if (apic == &apic_physflat || num_possible_cpus() > 8)
return 1;
return 0;
}
