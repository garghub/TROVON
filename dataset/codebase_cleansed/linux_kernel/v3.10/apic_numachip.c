static unsigned int get_apic_id(unsigned long x)
{
unsigned long value;
unsigned int id;
rdmsrl(MSR_FAM10H_NODE_ID, value);
id = ((x >> 24) & 0xffU) | ((value << 2) & 0x3f00U);
return id;
}
static unsigned long set_apic_id(unsigned int id)
{
unsigned long x;
x = ((id & 0xffU) << 24);
return x;
}
static unsigned int read_xapic_id(void)
{
return get_apic_id(apic_read(APIC_ID));
}
static int numachip_apic_id_valid(int apicid)
{
return 1;
}
static int numachip_apic_id_registered(void)
{
return physid_isset(read_xapic_id(), phys_cpu_present_map);
}
static int numachip_phys_pkg_id(int initial_apic_id, int index_msb)
{
return initial_apic_id >> index_msb;
}
static int __cpuinit numachip_wakeup_secondary(int phys_apicid, unsigned long start_rip)
{
union numachip_csr_g3_ext_irq_gen int_gen;
int_gen.s._destination_apic_id = phys_apicid;
int_gen.s._vector = 0;
int_gen.s._msgtype = APIC_DM_INIT >> 8;
int_gen.s._index = 0;
write_lcsr(CSR_G3_EXT_IRQ_GEN, int_gen.v);
int_gen.s._msgtype = APIC_DM_STARTUP >> 8;
int_gen.s._vector = start_rip >> 12;
write_lcsr(CSR_G3_EXT_IRQ_GEN, int_gen.v);
atomic_set(&init_deasserted, 1);
return 0;
}
static void numachip_send_IPI_one(int cpu, int vector)
{
union numachip_csr_g3_ext_irq_gen int_gen;
int apicid = per_cpu(x86_cpu_to_apicid, cpu);
int_gen.s._destination_apic_id = apicid;
int_gen.s._vector = vector;
int_gen.s._msgtype = (vector == NMI_VECTOR ? APIC_DM_NMI : APIC_DM_FIXED) >> 8;
int_gen.s._index = 0;
write_lcsr(CSR_G3_EXT_IRQ_GEN, int_gen.v);
}
static void numachip_send_IPI_mask(const struct cpumask *mask, int vector)
{
unsigned int cpu;
for_each_cpu(cpu, mask)
numachip_send_IPI_one(cpu, vector);
}
static void numachip_send_IPI_mask_allbutself(const struct cpumask *mask,
int vector)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
for_each_cpu(cpu, mask) {
if (cpu != this_cpu)
numachip_send_IPI_one(cpu, vector);
}
}
static void numachip_send_IPI_allbutself(int vector)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
for_each_online_cpu(cpu) {
if (cpu != this_cpu)
numachip_send_IPI_one(cpu, vector);
}
}
static void numachip_send_IPI_all(int vector)
{
numachip_send_IPI_mask(cpu_online_mask, vector);
}
static void numachip_send_IPI_self(int vector)
{
__default_send_IPI_shortcut(APIC_DEST_SELF, vector, APIC_DEST_PHYSICAL);
}
static int __init numachip_probe(void)
{
return apic == &apic_numachip;
}
static void __init map_csrs(void)
{
printk(KERN_INFO "NumaChip: Mapping local CSR space (%016llx - %016llx)\n",
NUMACHIP_LCSR_BASE, NUMACHIP_LCSR_BASE + NUMACHIP_LCSR_SIZE - 1);
init_extra_mapping_uc(NUMACHIP_LCSR_BASE, NUMACHIP_LCSR_SIZE);
printk(KERN_INFO "NumaChip: Mapping global CSR space (%016llx - %016llx)\n",
NUMACHIP_GCSR_BASE, NUMACHIP_GCSR_BASE + NUMACHIP_GCSR_SIZE - 1);
init_extra_mapping_uc(NUMACHIP_GCSR_BASE, NUMACHIP_GCSR_SIZE);
}
static void fixup_cpu_id(struct cpuinfo_x86 *c, int node)
{
if (c->phys_proc_id != node) {
c->phys_proc_id = node;
per_cpu(cpu_llc_id, smp_processor_id()) = node;
}
}
static int __init numachip_system_init(void)
{
unsigned int val;
if (!numachip_system)
return 0;
x86_cpuinit.fixup_cpu_id = fixup_cpu_id;
x86_init.pci.arch_init = pci_numachip_init;
map_csrs();
val = read_lcsr(CSR_G0_NODE_IDS);
printk(KERN_INFO "NumaChip: Local NodeID = %08x\n", val);
return 0;
}
static int numachip_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
if (!strncmp(oem_id, "NUMASC", 6)) {
numachip_system = 1;
return 1;
}
return 0;
}
