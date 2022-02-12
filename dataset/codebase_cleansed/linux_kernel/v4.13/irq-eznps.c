static void nps400_irq_mask(struct irq_data *irqd)
{
unsigned int ienb;
unsigned int irq = irqd_to_hwirq(irqd);
ienb = read_aux_reg(AUX_IENABLE);
ienb &= ~(1 << irq);
write_aux_reg(AUX_IENABLE, ienb);
}
static void nps400_irq_unmask(struct irq_data *irqd)
{
unsigned int ienb;
unsigned int irq = irqd_to_hwirq(irqd);
ienb = read_aux_reg(AUX_IENABLE);
ienb |= (1 << irq);
write_aux_reg(AUX_IENABLE, ienb);
}
static void nps400_irq_eoi_global(struct irq_data *irqd)
{
unsigned int __maybe_unused irq = irqd_to_hwirq(irqd);
write_aux_reg(CTOP_AUX_IACK, 1 << irq);
mb();
nps_ack_gic();
}
static void nps400_irq_ack(struct irq_data *irqd)
{
unsigned int __maybe_unused irq = irqd_to_hwirq(irqd);
write_aux_reg(CTOP_AUX_IACK, 1 << irq);
}
static int nps400_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
switch (hw) {
case NPS_TIMER0_IRQ:
#ifdef CONFIG_SMP
case NPS_IPI_IRQ:
#endif
irq_set_percpu_devid(virq);
irq_set_chip_and_handler(virq, &nps400_irq_chip_percpu,
handle_percpu_devid_irq);
break;
default:
irq_set_chip_and_handler(virq, &nps400_irq_chip_fasteoi,
handle_fasteoi_irq);
break;
}
return 0;
}
static int __init nps400_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *nps400_root_domain;
if (parent) {
pr_err("DeviceTree incore ic not a root irq controller\n");
return -EINVAL;
}
nps400_root_domain = irq_domain_add_linear(node, NPS_NR_CPU_IRQS,
&nps400_irq_ops, NULL);
if (!nps400_root_domain) {
pr_err("nps400 root irq domain not avail\n");
return -ENOMEM;
}
irq_set_default_host(nps400_root_domain);
#ifdef CONFIG_SMP
irq_create_mapping(nps400_root_domain, NPS_IPI_IRQ);
#endif
return 0;
}
