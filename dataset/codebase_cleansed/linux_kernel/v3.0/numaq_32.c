static inline void numaq_register_node(int node, struct sys_cfg_data *scd)
{
struct eachquadmem *eq = scd->eq + node;
u64 start = (u64)(eq->hi_shrd_mem_start - eq->priv_mem_size) << 20;
u64 end = (u64)(eq->hi_shrd_mem_start + eq->hi_shrd_mem_size) << 20;
int ret;
node_set(node, numa_nodes_parsed);
ret = numa_add_memblk(node, start, end);
BUG_ON(ret < 0);
}
static void __init smp_dump_qct(void)
{
struct sys_cfg_data *scd;
int node;
scd = (void *)__va(SYS_CFG_DATA_PRIV_ADDR);
for_each_node(node) {
if (scd->quads_present31_0 & (1 << node))
numaq_register_node(node, scd);
}
}
void __cpuinit numaq_tsc_disable(void)
{
if (!found_numaq)
return;
if (num_online_nodes() > 1) {
printk(KERN_DEBUG "NUMAQ: disabling TSC\n");
setup_clear_cpu_cap(X86_FEATURE_TSC);
}
}
static void __init numaq_tsc_init(void)
{
numaq_tsc_disable();
}
static inline int generate_logical_apicid(int quad, int phys_apicid)
{
return (quad << 4) + (phys_apicid ? phys_apicid << 1 : 1);
}
static int mpc_apic_id(struct mpc_cpu *m)
{
int quad = translation_table[mpc_record]->trans_quad;
int logical_apicid = generate_logical_apicid(quad, m->apicid);
printk(KERN_DEBUG
"Processor #%d %u:%u APIC version %d (quad %d, apic %d)\n",
m->apicid, (m->cpufeature & CPU_FAMILY_MASK) >> 8,
(m->cpufeature & CPU_MODEL_MASK) >> 4,
m->apicver, quad, logical_apicid);
return logical_apicid;
}
static void mpc_oem_bus_info(struct mpc_bus *m, char *name)
{
int quad = translation_table[mpc_record]->trans_quad;
int local = translation_table[mpc_record]->trans_local;
mp_bus_id_to_node[m->busid] = quad;
mp_bus_id_to_local[m->busid] = local;
printk(KERN_INFO "Bus #%d is %s (node %d)\n", m->busid, name, quad);
}
static void mpc_oem_pci_bus(struct mpc_bus *m)
{
int quad = translation_table[mpc_record]->trans_quad;
int local = translation_table[mpc_record]->trans_local;
quad_local_to_mp_bus_id[quad][local] = m->busid;
}
static void numaq_mpc_record(unsigned int mode)
{
if (!mode)
mpc_record = 0;
else
mpc_record++;
}
static void __init MP_translation_info(struct mpc_trans *m)
{
printk(KERN_INFO
"Translation: record %d, type %d, quad %d, global %d, local %d\n",
mpc_record, m->trans_type, m->trans_quad, m->trans_global,
m->trans_local);
if (mpc_record >= MAX_MPC_ENTRY)
printk(KERN_ERR "MAX_MPC_ENTRY exceeded!\n");
else
translation_table[mpc_record] = m;
if (m->trans_quad < MAX_NUMNODES && !node_online(m->trans_quad))
node_set_online(m->trans_quad);
}
static int __init mpf_checksum(unsigned char *mp, int len)
{
int sum = 0;
while (len--)
sum += *mp++;
return sum & 0xFF;
}
static void __init smp_read_mpc_oem(struct mpc_table *mpc)
{
struct mpc_oemtable *oemtable = (void *)(long)mpc->oemptr;
int count = sizeof(*oemtable);
unsigned char *oemptr = ((unsigned char *)oemtable) + count;
mpc_record = 0;
printk(KERN_INFO
"Found an OEM MPC table at %8p - parsing it...\n", oemtable);
if (memcmp(oemtable->signature, MPC_OEM_SIGNATURE, 4)) {
printk(KERN_WARNING
"SMP mpc oemtable: bad signature [%c%c%c%c]!\n",
oemtable->signature[0], oemtable->signature[1],
oemtable->signature[2], oemtable->signature[3]);
return;
}
if (mpf_checksum((unsigned char *)oemtable, oemtable->length)) {
printk(KERN_WARNING "SMP oem mptable: checksum error!\n");
return;
}
while (count < oemtable->length) {
switch (*oemptr) {
case MP_TRANSLATION:
{
struct mpc_trans *m = (void *)oemptr;
MP_translation_info(m);
oemptr += sizeof(*m);
count += sizeof(*m);
++mpc_record;
break;
}
default:
printk(KERN_WARNING
"Unrecognised OEM table entry type! - %d\n",
(int)*oemptr);
return;
}
}
}
static __init void early_check_numaq(void)
{
if (smp_found_config)
early_get_smp_config();
if (found_numaq) {
x86_init.mpparse.mpc_record = numaq_mpc_record;
x86_init.mpparse.setup_ioapic_ids = x86_init_noop;
x86_init.mpparse.mpc_apic_id = mpc_apic_id;
x86_init.mpparse.smp_read_mpc_oem = smp_read_mpc_oem;
x86_init.mpparse.mpc_oem_pci_bus = mpc_oem_pci_bus;
x86_init.mpparse.mpc_oem_bus_info = mpc_oem_bus_info;
x86_init.timers.tsc_pre_init = numaq_tsc_init;
x86_init.pci.init = pci_numaq_init;
}
}
int __init numaq_numa_init(void)
{
early_check_numaq();
if (!found_numaq)
return -ENOENT;
smp_dump_qct();
return 0;
}
static inline unsigned int numaq_get_apic_id(unsigned long x)
{
return (x >> 24) & 0x0F;
}
static inline void numaq_send_IPI_mask(const struct cpumask *mask, int vector)
{
default_send_IPI_mask_sequence_logical(mask, vector);
}
static inline void numaq_send_IPI_allbutself(int vector)
{
default_send_IPI_mask_allbutself_logical(cpu_online_mask, vector);
}
static inline void numaq_send_IPI_all(int vector)
{
numaq_send_IPI_mask(cpu_online_mask, vector);
}
static inline void numaq_smp_callin_clear_local_apic(void)
{
clear_local_APIC();
}
static inline const struct cpumask *numaq_target_cpus(void)
{
return cpu_all_mask;
}
static unsigned long numaq_check_apicid_used(physid_mask_t *map, int apicid)
{
return physid_isset(apicid, *map);
}
static inline unsigned long numaq_check_apicid_present(int bit)
{
return physid_isset(bit, phys_cpu_present_map);
}
static inline int numaq_apic_id_registered(void)
{
return 1;
}
static inline void numaq_init_apic_ldr(void)
{
}
static inline void numaq_setup_apic_routing(void)
{
printk(KERN_INFO
"Enabling APIC mode: NUMA-Q. Using %d I/O APICs\n",
nr_ioapics);
}
static inline int numaq_multi_timer_check(int apic, int irq)
{
return apic != 0 && irq == 0;
}
static inline void numaq_ioapic_phys_id_map(physid_mask_t *phys_map, physid_mask_t *retmap)
{
return physids_promote(0xFUL, retmap);
}
static inline int numaq_cpu_present_to_apicid(int mps_cpu)
{
if (mps_cpu < 60)
return ((mps_cpu >> 2) << 4) | (1 << (mps_cpu & 0x3));
else
return BAD_APICID;
}
static inline int numaq_apicid_to_node(int logical_apicid)
{
return logical_apicid >> 4;
}
static int numaq_numa_cpu_node(int cpu)
{
int logical_apicid = early_per_cpu(x86_cpu_to_logical_apicid, cpu);
if (logical_apicid != BAD_APICID)
return numaq_apicid_to_node(logical_apicid);
return NUMA_NO_NODE;
}
static void numaq_apicid_to_cpu_present(int logical_apicid, physid_mask_t *retmap)
{
int node = numaq_apicid_to_node(logical_apicid);
int cpu = __ffs(logical_apicid & 0xf);
physid_set_mask_of_physid(cpu + 4*node, retmap);
}
static inline int numaq_check_phys_apicid_present(int phys_apicid)
{
return 1;
}
static unsigned int numaq_cpu_mask_to_apicid(const struct cpumask *cpumask)
{
return 0x0F;
}
static inline unsigned int
numaq_cpu_mask_to_apicid_and(const struct cpumask *cpumask,
const struct cpumask *andmask)
{
return 0x0F;
}
static inline int numaq_phys_pkg_id(int cpuid_apic, int index_msb)
{
return cpuid_apic >> index_msb;
}
static int
numaq_mps_oem_check(struct mpc_table *mpc, char *oem, char *productid)
{
if (strncmp(oem, "IBM NUMA", 8))
printk(KERN_ERR "Warning! Not a NUMA-Q system!\n");
else
found_numaq = 1;
return found_numaq;
}
static int probe_numaq(void)
{
return found_numaq;
}
static void numaq_vector_allocation_domain(int cpu, struct cpumask *retmask)
{
cpumask_clear(retmask);
cpumask_bits(retmask)[0] = APIC_ALL_CPUS;
}
static void numaq_setup_portio_remap(void)
{
int num_quads = num_online_nodes();
if (num_quads <= 1)
return;
printk(KERN_INFO
"Remapping cross-quad port I/O for %d quads\n", num_quads);
xquad_portio = ioremap(XQUAD_PORTIO_BASE, num_quads*XQUAD_PORTIO_QUAD);
printk(KERN_INFO
"xquad_portio vaddr 0x%08lx, len %08lx\n",
(u_long) xquad_portio, (u_long) num_quads*XQUAD_PORTIO_QUAD);
}
