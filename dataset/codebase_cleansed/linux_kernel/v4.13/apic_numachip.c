static unsigned int numachip1_get_apic_id(unsigned long x)
{
unsigned long value;
unsigned int id = (x >> 24) & 0xff;
if (static_cpu_has(X86_FEATURE_NODEID_MSR)) {
rdmsrl(MSR_FAM10H_NODE_ID, value);
id |= (value << 2) & 0xff00;
}
return id;
}
static unsigned long numachip1_set_apic_id(unsigned int id)
{
return (id & 0xff) << 24;
}
static unsigned int numachip2_get_apic_id(unsigned long x)
{
u64 mcfg;
rdmsrl(MSR_FAM10H_MMIO_CONF_BASE, mcfg);
return ((mcfg >> (28 - 8)) & 0xfff00) | (x >> 24);
}
static unsigned long numachip2_set_apic_id(unsigned int id)
{
return id << 24;
}
static int numachip_apic_id_valid(int apicid)
{
return 1;
}
static int numachip_apic_id_registered(void)
{
return 1;
}
static int numachip_phys_pkg_id(int initial_apic_id, int index_msb)
{
return initial_apic_id >> index_msb;
}
static void numachip1_apic_icr_write(int apicid, unsigned int val)
{
write_lcsr(CSR_G3_EXT_IRQ_GEN, (apicid << 16) | val);
}
static void numachip2_apic_icr_write(int apicid, unsigned int val)
{
numachip2_write32_lcsr(NUMACHIP2_APIC_ICR, (apicid << 12) | val);
}
static int numachip_wakeup_secondary(int phys_apicid, unsigned long start_rip)
{
numachip_apic_icr_write(phys_apicid, APIC_DM_INIT);
numachip_apic_icr_write(phys_apicid, APIC_DM_STARTUP |
(start_rip >> 12));
return 0;
}
static void numachip_send_IPI_one(int cpu, int vector)
{
int local_apicid, apicid = per_cpu(x86_cpu_to_apicid, cpu);
unsigned int dmode;
preempt_disable();
local_apicid = __this_cpu_read(x86_cpu_to_apicid);
if (!((apicid ^ local_apicid) >> NUMACHIP_LAPIC_BITS)) {
unsigned long flags;
local_irq_save(flags);
__default_send_IPI_dest_field(apicid, vector,
APIC_DEST_PHYSICAL);
local_irq_restore(flags);
preempt_enable();
return;
}
preempt_enable();
dmode = (vector == NMI_VECTOR) ? APIC_DM_NMI : APIC_DM_FIXED;
numachip_apic_icr_write(apicid, dmode | vector);
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
apic_write(APIC_SELF_IPI, vector);
}
static int __init numachip1_probe(void)
{
return apic == &apic_numachip1;
}
static int __init numachip2_probe(void)
{
return apic == &apic_numachip2;
}
static void fixup_cpu_id(struct cpuinfo_x86 *c, int node)
{
u64 val;
u32 nodes = 1;
this_cpu_write(cpu_llc_id, node);
if (static_cpu_has(X86_FEATURE_NODEID_MSR)) {
rdmsrl(MSR_FAM10H_NODE_ID, val);
nodes = ((val >> 3) & 7) + 1;
}
c->phys_proc_id = node / nodes;
}
static int __init numachip_system_init(void)
{
switch (numachip_system) {
case 1:
init_extra_mapping_uc(NUMACHIP_LCSR_BASE, NUMACHIP_LCSR_SIZE);
numachip_apic_icr_write = numachip1_apic_icr_write;
break;
case 2:
init_extra_mapping_uc(NUMACHIP2_LCSR_BASE, NUMACHIP2_LCSR_SIZE);
numachip_apic_icr_write = numachip2_apic_icr_write;
break;
default:
return 0;
}
x86_cpuinit.fixup_cpu_id = fixup_cpu_id;
x86_init.pci.arch_init = pci_numachip_init;
return 0;
}
static int numachip1_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
if ((strncmp(oem_id, "NUMASC", 6) != 0) ||
(strncmp(oem_table_id, "NCONNECT", 8) != 0))
return 0;
numachip_system = 1;
return 1;
}
static int numachip2_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
if ((strncmp(oem_id, "NUMASC", 6) != 0) ||
(strncmp(oem_table_id, "NCONECT2", 8) != 0))
return 0;
numachip_system = 2;
return 1;
}
static void numachip_apic_wait_icr_idle(void)
{
}
static u32 numachip_safe_apic_wait_icr_idle(void)
{
return 0;
}
