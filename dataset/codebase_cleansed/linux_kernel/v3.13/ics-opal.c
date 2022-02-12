static int ics_opal_mangle_server(int server)
{
return server << 2;
}
static int ics_opal_unmangle_server(int server)
{
return server >> 2;
}
static void ics_opal_unmask_irq(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
int64_t rc;
int server;
pr_devel("ics-hal: unmask virq %d [hw 0x%x]\n", d->irq, hw_irq);
if (hw_irq == XICS_IPI || hw_irq == XICS_IRQ_SPURIOUS)
return;
server = xics_get_irq_server(d->irq, d->affinity, 0);
server = ics_opal_mangle_server(server);
rc = opal_set_xive(hw_irq, server, DEFAULT_PRIORITY);
if (rc != OPAL_SUCCESS)
pr_err("%s: opal_set_xive(irq=%d [hw 0x%x] server=%x)"
" error %lld\n",
__func__, d->irq, hw_irq, server, rc);
}
static unsigned int ics_opal_startup(struct irq_data *d)
{
#ifdef CONFIG_PCI_MSI
if (d->msi_desc)
unmask_msi_irq(d);
#endif
ics_opal_unmask_irq(d);
return 0;
}
static void ics_opal_mask_real_irq(unsigned int hw_irq)
{
int server = ics_opal_mangle_server(xics_default_server);
int64_t rc;
if (hw_irq == XICS_IPI)
return;
rc = opal_set_xive(hw_irq, server, 0xff);
if (rc != OPAL_SUCCESS)
pr_err("%s: opal_set_xive(0xff) irq=%u returned %lld\n",
__func__, hw_irq, rc);
}
static void ics_opal_mask_irq(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
pr_devel("ics-hal: mask virq %d [hw 0x%x]\n", d->irq, hw_irq);
if (hw_irq == XICS_IPI || hw_irq == XICS_IRQ_SPURIOUS)
return;
ics_opal_mask_real_irq(hw_irq);
}
static int ics_opal_set_affinity(struct irq_data *d,
const struct cpumask *cpumask,
bool force)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
__be16 oserver;
int16_t server;
int8_t priority;
int64_t rc;
int wanted_server;
if (hw_irq == XICS_IPI || hw_irq == XICS_IRQ_SPURIOUS)
return -1;
rc = opal_get_xive(hw_irq, &oserver, &priority);
if (rc != OPAL_SUCCESS) {
pr_err("%s: opal_get_xive(irq=%d [hw 0x%x]) error %lld\n",
__func__, d->irq, hw_irq, rc);
return -1;
}
server = be16_to_cpu(oserver);
wanted_server = xics_get_irq_server(d->irq, cpumask, 1);
if (wanted_server < 0) {
char cpulist[128];
cpumask_scnprintf(cpulist, sizeof(cpulist), cpumask);
pr_warning("%s: No online cpus in the mask %s for irq %d\n",
__func__, cpulist, d->irq);
return -1;
}
server = ics_opal_mangle_server(wanted_server);
pr_devel("ics-hal: set-affinity irq %d [hw 0x%x] server: 0x%x/0x%x\n",
d->irq, hw_irq, wanted_server, server);
rc = opal_set_xive(hw_irq, server, priority);
if (rc != OPAL_SUCCESS) {
pr_err("%s: opal_set_xive(irq=%d [hw 0x%x] server=%x)"
" error %lld\n",
__func__, d->irq, hw_irq, server, rc);
return -1;
}
return IRQ_SET_MASK_OK;
}
static int ics_opal_host_match(struct ics *ics, struct device_node *node)
{
return 1;
}
static int ics_opal_map(struct ics *ics, unsigned int virq)
{
unsigned int hw_irq = (unsigned int)virq_to_hw(virq);
int64_t rc;
__be16 server;
int8_t priority;
if (WARN_ON(hw_irq == XICS_IPI || hw_irq == XICS_IRQ_SPURIOUS))
return -EINVAL;
rc = opal_get_xive(hw_irq, &server, &priority);
if (rc != OPAL_SUCCESS)
return -ENXIO;
irq_set_chip_and_handler(virq, &ics_opal_irq_chip, handle_fasteoi_irq);
irq_set_chip_data(virq, &ics_hal);
return 0;
}
static void ics_opal_mask_unknown(struct ics *ics, unsigned long vec)
{
int64_t rc;
__be16 server;
int8_t priority;
rc = opal_get_xive(vec, &server, &priority);
if (rc != OPAL_SUCCESS)
return;
ics_opal_mask_real_irq(vec);
}
static long ics_opal_get_server(struct ics *ics, unsigned long vec)
{
int64_t rc;
__be16 server;
int8_t priority;
rc = opal_get_xive(vec, &server, &priority);
if (rc != OPAL_SUCCESS)
return -1;
return ics_opal_unmangle_server(be16_to_cpu(server));
}
int __init ics_opal_init(void)
{
if (!firmware_has_feature(FW_FEATURE_OPAL))
return -ENODEV;
ics_opal_irq_chip.irq_eoi = icp_ops->eoi;
xics_register_ics(&ics_hal);
pr_info("ICS OPAL backend registered\n");
return 0;
}
