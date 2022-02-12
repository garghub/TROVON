static void icp_opal_teardown_cpu(void)
{
int hw_cpu = hard_smp_processor_id();
opal_int_set_mfrr(hw_cpu, 0xff);
}
static void icp_opal_flush_ipi(void)
{
opal_int_eoi((0x00 << 24) | XICS_IPI);
}
static unsigned int icp_opal_get_irq(void)
{
unsigned int xirr;
unsigned int vec;
unsigned int irq;
int64_t rc;
rc = opal_int_get_xirr(&xirr, false);
if (rc < 0)
return NO_IRQ;
xirr = be32_to_cpu(xirr);
vec = xirr & 0x00ffffff;
if (vec == XICS_IRQ_SPURIOUS)
return NO_IRQ;
irq = irq_find_mapping(xics_host, vec);
if (likely(irq != NO_IRQ)) {
xics_push_cppr(vec);
return irq;
}
xics_mask_unknown_vec(vec);
opal_int_eoi(xirr);
return NO_IRQ;
}
static void icp_opal_set_cpu_priority(unsigned char cppr)
{
xics_set_base_cppr(cppr);
opal_int_set_cppr(cppr);
iosync();
}
static void icp_opal_eoi(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
int64_t rc;
iosync();
rc = opal_int_eoi((xics_pop_cppr() << 24) | hw_irq);
if (rc > 0)
force_external_irq_replay();
}
static void icp_opal_cause_ipi(int cpu, unsigned long data)
{
int hw_cpu = get_hard_smp_processor_id(cpu);
opal_int_set_mfrr(hw_cpu, IPI_PRIORITY);
}
static irqreturn_t icp_opal_ipi_action(int irq, void *dev_id)
{
int hw_cpu = hard_smp_processor_id();
opal_int_set_mfrr(hw_cpu, 0xff);
return smp_ipi_demux();
}
int icp_opal_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "ibm,opal-intc");
if (!np)
return -ENODEV;
icp_ops = &icp_opal_ops;
printk("XICS: Using OPAL ICP fallbacks\n");
return 0;
}
