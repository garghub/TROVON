static void icp_opal_teardown_cpu(void)
{
int hw_cpu = hard_smp_processor_id();
opal_int_set_mfrr(hw_cpu, 0xff);
}
static void icp_opal_flush_ipi(void)
{
if (opal_int_eoi((0x00 << 24) | XICS_IPI) > 0)
force_external_irq_replay();
}
static unsigned int icp_opal_get_xirr(void)
{
unsigned int kvm_xirr;
__be32 hw_xirr;
int64_t rc;
kvm_xirr = kvmppc_get_xics_latch();
if (kvm_xirr)
return kvm_xirr;
rc = opal_int_get_xirr(&hw_xirr, false);
if (rc < 0)
return 0;
return be32_to_cpu(hw_xirr);
}
static unsigned int icp_opal_get_irq(void)
{
unsigned int xirr;
unsigned int vec;
unsigned int irq;
xirr = icp_opal_get_xirr();
vec = xirr & 0x00ffffff;
if (vec == XICS_IRQ_SPURIOUS)
return 0;
irq = irq_find_mapping(xics_host, vec);
if (likely(irq)) {
xics_push_cppr(vec);
return irq;
}
xics_mask_unknown_vec(vec);
if (opal_int_eoi(xirr) > 0)
force_external_irq_replay();
return 0;
}
static void icp_opal_set_cpu_priority(unsigned char cppr)
{
if (cppr >= DEFAULT_PRIORITY)
cppr = LOWEST_PRIORITY;
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
kvmppc_set_host_ipi(cpu, 1);
opal_int_set_mfrr(hw_cpu, IPI_PRIORITY);
}
static irqreturn_t icp_opal_ipi_action(int irq, void *dev_id)
{
int cpu = smp_processor_id();
kvmppc_set_host_ipi(cpu, 0);
opal_int_set_mfrr(get_hard_smp_processor_id(cpu), 0xff);
return smp_ipi_demux();
}
void icp_opal_flush_interrupt(void)
{
unsigned int xirr;
unsigned int vec;
do {
xirr = icp_opal_get_xirr();
vec = xirr & 0x00ffffff;
if (vec == XICS_IRQ_SPURIOUS)
break;
if (vec == XICS_IPI) {
int cpu = smp_processor_id();
kvmppc_set_host_ipi(cpu, 0);
opal_int_set_mfrr(get_hard_smp_processor_id(cpu), 0xff);
} else {
pr_err("XICS: hw interrupt 0x%x to offline cpu, "
"disabling\n", vec);
xics_mask_unknown_vec(vec);
}
} while (opal_int_eoi(xirr) > 0);
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
