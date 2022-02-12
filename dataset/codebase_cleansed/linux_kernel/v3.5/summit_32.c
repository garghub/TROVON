static unsigned summit_get_apic_id(unsigned long x)
{
return (x >> 24) & 0xFF;
}
static inline void summit_send_IPI_mask(const struct cpumask *mask, int vector)
{
default_send_IPI_mask_sequence_logical(mask, vector);
}
static void summit_send_IPI_allbutself(int vector)
{
default_send_IPI_mask_allbutself_logical(cpu_online_mask, vector);
}
static void summit_send_IPI_all(int vector)
{
summit_send_IPI_mask(cpu_online_mask, vector);
}
static inline void setup_summit(void) {}
static int summit_mps_oem_check(struct mpc_table *mpc, char *oem,
char *productid)
{
if (!strncmp(oem, "IBM ENSW", 8) &&
(!strncmp(productid, "VIGIL SMP", 9)
|| !strncmp(productid, "EXA", 3)
|| !strncmp(productid, "RUTHLESS SMP", 12))){
mark_tsc_unstable("Summit based system");
use_cyclone = 1;
setup_summit();
return 1;
}
return 0;
}
static int summit_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
if (!strncmp(oem_id, "IBM", 3) &&
(!strncmp(oem_table_id, "SERVIGIL", 8)
|| !strncmp(oem_table_id, "EXA", 3))){
mark_tsc_unstable("Summit based system");
use_cyclone = 1;
setup_summit();
return 1;
}
return 0;
}
static inline int is_WPEG(struct rio_detail *rio){
return (rio->type == CompatWPEG || rio->type == AltWPEG ||
rio->type == LookOutAWPEG || rio->type == LookOutBWPEG);
}
static const struct cpumask *summit_target_cpus(void)
{
return cpumask_of(0);
}
static unsigned long summit_check_apicid_used(physid_mask_t *map, int apicid)
{
return 0;
}
static unsigned long summit_check_apicid_present(int bit)
{
return 1;
}
static int summit_early_logical_apicid(int cpu)
{
int count = 0;
u8 my_id = early_per_cpu(x86_cpu_to_apicid, cpu);
u8 my_cluster = APIC_CLUSTER(my_id);
#ifdef CONFIG_SMP
u8 lid;
int i;
for (count = 0, i = nr_cpu_ids; --i >= 0; ) {
lid = early_per_cpu(x86_cpu_to_logical_apicid, i);
if (lid != BAD_APICID && APIC_CLUSTER(lid) == my_cluster)
++count;
}
#endif
BUG_ON(count >= XAPIC_DEST_CPUS_SHIFT);
return my_cluster | (1UL << count);
}
static void summit_init_apic_ldr(void)
{
int cpu = smp_processor_id();
unsigned long id = early_per_cpu(x86_cpu_to_logical_apicid, cpu);
unsigned long val;
apic_write(APIC_DFR, SUMMIT_APIC_DFR_VALUE);
val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
val |= SET_APIC_LOGICAL_ID(id);
apic_write(APIC_LDR, val);
}
static int summit_apic_id_registered(void)
{
return 1;
}
static void summit_setup_apic_routing(void)
{
printk("Enabling APIC mode: Summit. Using %d I/O APICs\n",
nr_ioapics);
}
static int summit_cpu_present_to_apicid(int mps_cpu)
{
if (mps_cpu < nr_cpu_ids)
return (int)per_cpu(x86_bios_cpu_apicid, mps_cpu);
else
return BAD_APICID;
}
static void summit_ioapic_phys_id_map(physid_mask_t *phys_id_map, physid_mask_t *retmap)
{
physids_promote(0x0FL, retmap);
}
static void summit_apicid_to_cpu_present(int apicid, physid_mask_t *retmap)
{
physid_set_mask_of_physid(0, retmap);
}
static int summit_check_phys_apicid_present(int physical_apicid)
{
return 1;
}
static unsigned int summit_cpu_mask_to_apicid(const struct cpumask *cpumask)
{
unsigned int round = 0;
int cpu, apicid = 0;
for_each_cpu(cpu, cpumask) {
int new_apicid = early_per_cpu(x86_cpu_to_logical_apicid, cpu);
if (round && APIC_CLUSTER(apicid) != APIC_CLUSTER(new_apicid)) {
printk("%s: Not a valid mask!\n", __func__);
return BAD_APICID;
}
apicid |= new_apicid;
round++;
}
return apicid;
}
static unsigned int summit_cpu_mask_to_apicid_and(const struct cpumask *inmask,
const struct cpumask *andmask)
{
int apicid = early_per_cpu(x86_cpu_to_logical_apicid, 0);
cpumask_var_t cpumask;
if (!alloc_cpumask_var(&cpumask, GFP_ATOMIC))
return apicid;
cpumask_and(cpumask, inmask, andmask);
cpumask_and(cpumask, cpumask, cpu_online_mask);
apicid = summit_cpu_mask_to_apicid(cpumask);
free_cpumask_var(cpumask);
return apicid;
}
static int summit_phys_pkg_id(int cpuid_apic, int index_msb)
{
return hard_smp_processor_id() >> index_msb;
}
static int probe_summit(void)
{
return 0;
}
static void summit_vector_allocation_domain(int cpu, struct cpumask *retmask)
{
cpumask_clear(retmask);
cpumask_bits(retmask)[0] = APIC_ALL_CPUS;
}
static int setup_pci_node_map_for_wpeg(int wpeg_num, int last_bus)
{
int twister = 0, node = 0;
int i, bus, num_buses;
for (i = 0; i < rio_table_hdr->num_rio_dev; i++) {
if (rio_devs[i]->node_id == rio_devs[wpeg_num]->owner_id) {
twister = rio_devs[i]->owner_id;
break;
}
}
if (i == rio_table_hdr->num_rio_dev) {
printk(KERN_ERR "%s: Couldn't find owner Cyclone for Winnipeg!\n", __func__);
return last_bus;
}
for (i = 0; i < rio_table_hdr->num_scal_dev; i++) {
if (scal_devs[i]->node_id == twister) {
node = scal_devs[i]->node_id;
break;
}
}
if (i == rio_table_hdr->num_scal_dev) {
printk(KERN_ERR "%s: Couldn't find owner Twister for Cyclone!\n", __func__);
return last_bus;
}
switch (rio_devs[wpeg_num]->type) {
case CompatWPEG:
num_buses = 5;
break;
case AltWPEG:
num_buses = 7;
break;
case LookOutAWPEG:
case LookOutBWPEG:
num_buses = 9;
break;
default:
printk(KERN_INFO "%s: Unsupported Winnipeg type!\n", __func__);
return last_bus;
}
for (bus = last_bus; bus < last_bus + num_buses; bus++)
mp_bus_id_to_node[bus] = node;
return bus;
}
static int build_detail_arrays(void)
{
unsigned long ptr;
int i, scal_detail_size, rio_detail_size;
if (rio_table_hdr->num_scal_dev > MAX_NUMNODES) {
printk(KERN_WARNING "%s: MAX_NUMNODES too low! Defined as %d, but system has %d nodes.\n", __func__, MAX_NUMNODES, rio_table_hdr->num_scal_dev);
return 0;
}
switch (rio_table_hdr->version) {
default:
printk(KERN_WARNING "%s: Invalid Rio Grande Table Version: %d\n", __func__, rio_table_hdr->version);
return 0;
case 2:
scal_detail_size = 11;
rio_detail_size = 13;
break;
case 3:
scal_detail_size = 12;
rio_detail_size = 15;
break;
}
ptr = (unsigned long)rio_table_hdr + 3;
for (i = 0; i < rio_table_hdr->num_scal_dev; i++, ptr += scal_detail_size)
scal_devs[i] = (struct scal_detail *)ptr;
for (i = 0; i < rio_table_hdr->num_rio_dev; i++, ptr += rio_detail_size)
rio_devs[i] = (struct rio_detail *)ptr;
return 1;
}
void setup_summit(void)
{
unsigned long ptr;
unsigned short offset;
int i, next_wpeg, next_bus = 0;
ptr = get_bios_ebda();
ptr = (unsigned long)phys_to_virt(ptr);
rio_table_hdr = NULL;
offset = 0x180;
while (offset) {
if (*((unsigned short *)(ptr + offset + 2)) == 0x4752) {
rio_table_hdr = (struct rio_table_hdr *)(ptr + offset + 4);
break;
}
offset = *((unsigned short *)(ptr + offset));
}
if (!rio_table_hdr) {
printk(KERN_ERR "%s: Unable to locate Rio Grande Table in EBDA - bailing!\n", __func__);
return;
}
if (!build_detail_arrays())
return;
next_wpeg = 0;
do {
for (i = 0; i < rio_table_hdr->num_rio_dev; i++) {
if (is_WPEG(rio_devs[i]) && rio_devs[i]->WP_index == next_wpeg) {
next_bus = setup_pci_node_map_for_wpeg(i, next_bus);
next_wpeg++;
break;
}
}
if (i == rio_table_hdr->num_rio_dev)
next_wpeg = 0;
} while (next_wpeg != 0);
}
