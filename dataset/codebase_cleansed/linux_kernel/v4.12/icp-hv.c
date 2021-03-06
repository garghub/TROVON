static inline unsigned int icp_hv_get_xirr(unsigned char cppr)
{
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
long rc;
unsigned int ret = XICS_IRQ_SPURIOUS;
rc = plpar_hcall(H_XIRR, retbuf, cppr);
if (rc == H_SUCCESS) {
ret = (unsigned int)retbuf[0];
} else {
pr_err("%s: bad return code xirr cppr=0x%x returned %ld\n",
__func__, cppr, rc);
WARN_ON_ONCE(1);
}
return ret;
}
static inline void icp_hv_set_cppr(u8 value)
{
long rc = plpar_hcall_norets(H_CPPR, value);
if (rc != H_SUCCESS) {
pr_err("%s: bad return code cppr cppr=0x%x returned %ld\n",
__func__, value, rc);
WARN_ON_ONCE(1);
}
}
static inline void icp_hv_set_xirr(unsigned int value)
{
long rc = plpar_hcall_norets(H_EOI, value);
if (rc != H_SUCCESS) {
pr_err("%s: bad return code eoi xirr=0x%x returned %ld\n",
__func__, value, rc);
WARN_ON_ONCE(1);
icp_hv_set_cppr(value >> 24);
}
}
static inline void icp_hv_set_qirr(int n_cpu , u8 value)
{
int hw_cpu = get_hard_smp_processor_id(n_cpu);
long rc;
mb();
rc = plpar_hcall_norets(H_IPI, hw_cpu, value);
if (rc != H_SUCCESS) {
pr_err("%s: bad return code qirr cpu=%d hw_cpu=%d mfrr=0x%x "
"returned %ld\n", __func__, n_cpu, hw_cpu, value, rc);
WARN_ON_ONCE(1);
}
}
static void icp_hv_eoi(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
iosync();
icp_hv_set_xirr((xics_pop_cppr() << 24) | hw_irq);
}
static void icp_hv_teardown_cpu(void)
{
int cpu = smp_processor_id();
icp_hv_set_qirr(cpu, 0xff);
}
static void icp_hv_flush_ipi(void)
{
icp_hv_set_xirr((0x00 << 24) | XICS_IPI);
}
static unsigned int icp_hv_get_irq(void)
{
unsigned int xirr = icp_hv_get_xirr(xics_cppr_top());
unsigned int vec = xirr & 0x00ffffff;
unsigned int irq;
if (vec == XICS_IRQ_SPURIOUS)
return 0;
irq = irq_find_mapping(xics_host, vec);
if (likely(irq)) {
xics_push_cppr(vec);
return irq;
}
xics_mask_unknown_vec(vec);
icp_hv_set_xirr(xirr);
return 0;
}
static void icp_hv_set_cpu_priority(unsigned char cppr)
{
xics_set_base_cppr(cppr);
icp_hv_set_cppr(cppr);
iosync();
}
static void icp_hv_cause_ipi(int cpu)
{
icp_hv_set_qirr(cpu, IPI_PRIORITY);
}
static irqreturn_t icp_hv_ipi_action(int irq, void *dev_id)
{
int cpu = smp_processor_id();
icp_hv_set_qirr(cpu, 0xff);
return smp_ipi_demux();
}
int icp_hv_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "ibm,ppc-xicp");
if (!np)
np = of_find_node_by_type(NULL,
"PowerPC-External-Interrupt-Presentation");
if (!np)
return -ENODEV;
icp_ops = &icp_hv_ops;
return 0;
}
