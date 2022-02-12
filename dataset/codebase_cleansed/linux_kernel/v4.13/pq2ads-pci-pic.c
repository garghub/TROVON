static void pq2ads_pci_mask_irq(struct irq_data *d)
{
struct pq2ads_pci_pic *priv = irq_data_get_irq_chip_data(d);
int irq = NUM_IRQS - irqd_to_hwirq(d) - 1;
if (irq != -1) {
unsigned long flags;
raw_spin_lock_irqsave(&pci_pic_lock, flags);
setbits32(&priv->regs->mask, 1 << irq);
mb();
raw_spin_unlock_irqrestore(&pci_pic_lock, flags);
}
}
static void pq2ads_pci_unmask_irq(struct irq_data *d)
{
struct pq2ads_pci_pic *priv = irq_data_get_irq_chip_data(d);
int irq = NUM_IRQS - irqd_to_hwirq(d) - 1;
if (irq != -1) {
unsigned long flags;
raw_spin_lock_irqsave(&pci_pic_lock, flags);
clrbits32(&priv->regs->mask, 1 << irq);
raw_spin_unlock_irqrestore(&pci_pic_lock, flags);
}
}
static void pq2ads_pci_irq_demux(struct irq_desc *desc)
{
struct pq2ads_pci_pic *priv = irq_desc_get_handler_data(desc);
u32 stat, mask, pend;
int bit;
for (;;) {
stat = in_be32(&priv->regs->stat);
mask = in_be32(&priv->regs->mask);
pend = stat & ~mask;
if (!pend)
break;
for (bit = 0; pend != 0; ++bit, pend <<= 1) {
if (pend & 0x80000000) {
int virq = irq_linear_revmap(priv->host, bit);
generic_handle_irq(virq);
}
}
}
}
static int pci_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_data(virq, h->host_data);
irq_set_chip_and_handler(virq, &pq2ads_pci_ic, handle_level_irq);
return 0;
}
int __init pq2ads_pci_init_irq(void)
{
struct pq2ads_pci_pic *priv;
struct irq_domain *host;
struct device_node *np;
int ret = -ENODEV;
int irq;
np = of_find_compatible_node(NULL, NULL, "fsl,pq2ads-pci-pic");
if (!np) {
printk(KERN_ERR "No pci pic node in device tree.\n");
of_node_put(np);
goto out;
}
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
printk(KERN_ERR "No interrupt in pci pic node.\n");
of_node_put(np);
goto out;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
of_node_put(np);
ret = -ENOMEM;
goto out_unmap_irq;
}
priv->regs = of_iomap(np, 0);
if (!priv->regs) {
printk(KERN_ERR "Cannot map PCI PIC registers.\n");
goto out_free_kmalloc;
}
out_be32(&priv->regs->mask, ~0);
mb();
host = irq_domain_add_linear(np, NUM_IRQS, &pci_pic_host_ops, priv);
if (!host) {
ret = -ENOMEM;
goto out_unmap_regs;
}
priv->host = host;
irq_set_handler_data(irq, priv);
irq_set_chained_handler(irq, pq2ads_pci_irq_demux);
of_node_put(np);
return 0;
out_unmap_regs:
iounmap(priv->regs);
out_free_kmalloc:
kfree(priv);
of_node_put(np);
out_unmap_irq:
irq_dispose_mapping(irq);
out:
return ret;
}
