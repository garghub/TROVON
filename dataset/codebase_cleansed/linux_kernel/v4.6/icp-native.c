static inline unsigned int icp_native_get_xirr(void)
{
int cpu = smp_processor_id();
unsigned int xirr;
xirr = kvmppc_get_xics_latch();
if (xirr)
return xirr;
return in_be32(&icp_native_regs[cpu]->xirr.word);
}
static inline void icp_native_set_xirr(unsigned int value)
{
int cpu = smp_processor_id();
out_be32(&icp_native_regs[cpu]->xirr.word, value);
}
static inline void icp_native_set_cppr(u8 value)
{
int cpu = smp_processor_id();
out_8(&icp_native_regs[cpu]->xirr.bytes[0], value);
}
static inline void icp_native_set_qirr(int n_cpu, u8 value)
{
out_8(&icp_native_regs[n_cpu]->qirr.bytes[0], value);
}
static void icp_native_set_cpu_priority(unsigned char cppr)
{
xics_set_base_cppr(cppr);
icp_native_set_cppr(cppr);
iosync();
}
void icp_native_eoi(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
iosync();
icp_native_set_xirr((xics_pop_cppr() << 24) | hw_irq);
}
static void icp_native_teardown_cpu(void)
{
int cpu = smp_processor_id();
icp_native_set_qirr(cpu, 0xff);
}
static void icp_native_flush_ipi(void)
{
icp_native_set_xirr((0x00 << 24) | XICS_IPI);
}
static unsigned int icp_native_get_irq(void)
{
unsigned int xirr = icp_native_get_xirr();
unsigned int vec = xirr & 0x00ffffff;
unsigned int irq;
if (vec == XICS_IRQ_SPURIOUS)
return NO_IRQ;
irq = irq_find_mapping(xics_host, vec);
if (likely(irq != NO_IRQ)) {
xics_push_cppr(vec);
return irq;
}
xics_mask_unknown_vec(vec);
icp_native_set_xirr(xirr);
return NO_IRQ;
}
static void icp_native_cause_ipi(int cpu, unsigned long data)
{
kvmppc_set_host_ipi(cpu, 1);
#ifdef CONFIG_PPC_DOORBELL
if (cpu_has_feature(CPU_FTR_DBELL)) {
if (cpumask_test_cpu(cpu, cpu_sibling_mask(get_cpu()))) {
doorbell_cause_ipi(cpu, data);
put_cpu();
return;
}
put_cpu();
}
#endif
icp_native_set_qirr(cpu, IPI_PRIORITY);
}
void icp_native_cause_ipi_rm(int cpu)
{
unsigned long xics_phys;
xics_phys = paca[cpu].kvm_hstate.xics_phys;
out_rm8((u8 *)(xics_phys + XICS_MFRR), IPI_PRIORITY);
}
void icp_native_flush_interrupt(void)
{
unsigned int xirr = icp_native_get_xirr();
unsigned int vec = xirr & 0x00ffffff;
if (vec == XICS_IRQ_SPURIOUS)
return;
if (vec == XICS_IPI) {
int cpu = smp_processor_id();
kvmppc_set_host_ipi(cpu, 0);
icp_native_set_qirr(cpu, 0xff);
} else {
pr_err("XICS: hw interrupt 0x%x to offline cpu, disabling\n",
vec);
xics_mask_unknown_vec(vec);
}
icp_native_set_xirr(xirr);
}
void xics_wake_cpu(int cpu)
{
icp_native_set_qirr(cpu, IPI_PRIORITY);
}
static irqreturn_t icp_native_ipi_action(int irq, void *dev_id)
{
int cpu = smp_processor_id();
kvmppc_set_host_ipi(cpu, 0);
icp_native_set_qirr(cpu, 0xff);
return smp_ipi_demux();
}
static int __init icp_native_map_one_cpu(int hw_id, unsigned long addr,
unsigned long size)
{
char *rname;
int i, cpu = -1;
for_each_possible_cpu(i) {
if (!cpu_present(i))
continue;
if (hw_id == get_hard_smp_processor_id(i)) {
cpu = i;
break;
}
}
if (cpu == -1)
return 0;
rname = kasprintf(GFP_KERNEL, "CPU %d [0x%x] Interrupt Presentation",
cpu, hw_id);
if (!request_mem_region(addr, size, rname)) {
pr_warning("icp_native: Could not reserve ICP MMIO"
" for CPU %d, interrupt server #0x%x\n",
cpu, hw_id);
return -EBUSY;
}
icp_native_regs[cpu] = ioremap(addr, size);
kvmppc_set_xics_phys(cpu, addr);
if (!icp_native_regs[cpu]) {
pr_warning("icp_native: Failed ioremap for CPU %d, "
"interrupt server #0x%x, addr %#lx\n",
cpu, hw_id, addr);
release_mem_region(addr, size);
return -ENOMEM;
}
return 0;
}
static int __init icp_native_init_one_node(struct device_node *np,
unsigned int *indx)
{
unsigned int ilen;
const __be32 *ireg;
int i;
int reg_tuple_size;
int num_servers = 0;
ireg = of_get_property(np, "ibm,interrupt-server-ranges", &ilen);
WARN_ON((ireg == NULL) || (ilen != 2*sizeof(u32)));
if (ireg) {
*indx = of_read_number(ireg, 1);
if (ilen >= 2*sizeof(u32))
num_servers = of_read_number(ireg + 1, 1);
}
ireg = of_get_property(np, "reg", &ilen);
if (!ireg) {
pr_err("icp_native: Can't find interrupt reg property");
return -1;
}
reg_tuple_size = (of_n_addr_cells(np) + of_n_size_cells(np)) * 4;
if (((ilen % reg_tuple_size) != 0)
|| (num_servers && (num_servers != (ilen / reg_tuple_size)))) {
pr_err("icp_native: ICP reg len (%d) != num servers (%d)",
ilen / reg_tuple_size, num_servers);
return -1;
}
for (i = 0; i < (ilen / reg_tuple_size); i++) {
struct resource r;
int err;
err = of_address_to_resource(np, i, &r);
if (err) {
pr_err("icp_native: Could not translate ICP MMIO"
" for interrupt server 0x%x (%d)\n", *indx, err);
return -1;
}
if (icp_native_map_one_cpu(*indx, r.start, resource_size(&r)))
return -1;
(*indx)++;
}
return 0;
}
int __init icp_native_init(void)
{
struct device_node *np;
u32 indx = 0;
int found = 0;
for_each_compatible_node(np, NULL, "ibm,ppc-xicp")
if (icp_native_init_one_node(np, &indx) == 0)
found = 1;
if (!found) {
for_each_node_by_type(np,
"PowerPC-External-Interrupt-Presentation") {
if (icp_native_init_one_node(np, &indx) == 0)
found = 1;
}
}
if (found == 0)
return -ENODEV;
icp_ops = &icp_native_ops;
return 0;
}
