static unsigned bigsmp_get_apic_id(unsigned long x)
{
return (x >> 24) & 0xFF;
}
static int bigsmp_apic_id_registered(void)
{
return 1;
}
static unsigned long bigsmp_check_apicid_used(physid_mask_t *map, int apicid)
{
return 0;
}
static unsigned long bigsmp_check_apicid_present(int bit)
{
return 1;
}
static int bigsmp_early_logical_apicid(int cpu)
{
return early_per_cpu(x86_cpu_to_apicid, cpu);
}
static inline unsigned long calculate_ldr(int cpu)
{
unsigned long val, id;
val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
id = per_cpu(x86_bios_cpu_apicid, cpu);
val |= SET_APIC_LOGICAL_ID(id);
return val;
}
static void bigsmp_init_apic_ldr(void)
{
unsigned long val;
int cpu = smp_processor_id();
apic_write(APIC_DFR, APIC_DFR_FLAT);
val = calculate_ldr(cpu);
apic_write(APIC_LDR, val);
}
static void bigsmp_setup_apic_routing(void)
{
printk(KERN_INFO
"Enabling APIC mode: Physflat. Using %d I/O APICs\n",
nr_ioapics);
}
static int bigsmp_cpu_present_to_apicid(int mps_cpu)
{
if (mps_cpu < nr_cpu_ids)
return (int) per_cpu(x86_bios_cpu_apicid, mps_cpu);
return BAD_APICID;
}
static void bigsmp_ioapic_phys_id_map(physid_mask_t *phys_map, physid_mask_t *retmap)
{
physids_promote(0xFFL, retmap);
}
static int bigsmp_check_phys_apicid_present(int phys_apicid)
{
return 1;
}
static int bigsmp_phys_pkg_id(int cpuid_apic, int index_msb)
{
return cpuid_apic >> index_msb;
}
static inline void bigsmp_send_IPI_mask(const struct cpumask *mask, int vector)
{
default_send_IPI_mask_sequence_phys(mask, vector);
}
static void bigsmp_send_IPI_allbutself(int vector)
{
default_send_IPI_mask_allbutself_phys(cpu_online_mask, vector);
}
static void bigsmp_send_IPI_all(int vector)
{
bigsmp_send_IPI_mask(cpu_online_mask, vector);
}
static int hp_ht_bigsmp(const struct dmi_system_id *d)
{
printk(KERN_NOTICE "%s detected: force use of apic=bigsmp\n", d->ident);
dmi_bigsmp = 1;
return 0;
}
static int probe_bigsmp(void)
{
if (def_to_bigsmp)
dmi_bigsmp = 1;
else
dmi_check_system(bigsmp_dmi_table);
return dmi_bigsmp;
}
void __init generic_bigsmp_probe(void)
{
unsigned int cpu;
if (!probe_bigsmp())
return;
apic = &apic_bigsmp;
for_each_possible_cpu(cpu) {
if (early_per_cpu(x86_cpu_to_logical_apicid,
cpu) == BAD_APICID)
continue;
early_per_cpu(x86_cpu_to_logical_apicid, cpu) =
bigsmp_early_logical_apicid(cpu);
}
pr_info("Overriding APIC driver with %s\n", apic_bigsmp.name);
}
