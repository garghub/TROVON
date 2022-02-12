static void vt8500_irq_mask(struct irq_data *d)
{
struct vt8500_irq_data *priv = d->domain->host_data;
void __iomem *base = priv->base;
void __iomem *stat_reg = base + VT8500_ICIS + (d->hwirq < 32 ? 0 : 4);
u8 edge, dctr;
u32 status;
edge = readb(base + VT8500_ICDC + d->hwirq) & VT8500_EDGE;
if (edge) {
status = readl(stat_reg);
status |= (1 << (d->hwirq & 0x1f));
writel(status, stat_reg);
} else {
dctr = readb(base + VT8500_ICDC + d->hwirq);
dctr &= ~VT8500_INT_ENABLE;
writeb(dctr, base + VT8500_ICDC + d->hwirq);
}
}
static void vt8500_irq_unmask(struct irq_data *d)
{
struct vt8500_irq_data *priv = d->domain->host_data;
void __iomem *base = priv->base;
u8 dctr;
dctr = readb(base + VT8500_ICDC + d->hwirq);
dctr |= VT8500_INT_ENABLE;
writeb(dctr, base + VT8500_ICDC + d->hwirq);
}
static int vt8500_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct vt8500_irq_data *priv = d->domain->host_data;
void __iomem *base = priv->base;
u8 dctr;
dctr = readb(base + VT8500_ICDC + d->hwirq);
dctr &= ~VT8500_EDGE;
switch (flow_type) {
case IRQF_TRIGGER_LOW:
return -EINVAL;
case IRQF_TRIGGER_HIGH:
dctr |= VT8500_TRIGGER_HIGH;
__irq_set_handler_locked(d->irq, handle_level_irq);
break;
case IRQF_TRIGGER_FALLING:
dctr |= VT8500_TRIGGER_FALLING;
__irq_set_handler_locked(d->irq, handle_edge_irq);
break;
case IRQF_TRIGGER_RISING:
dctr |= VT8500_TRIGGER_RISING;
__irq_set_handler_locked(d->irq, handle_edge_irq);
break;
}
writeb(dctr, base + VT8500_ICDC + d->hwirq);
return 0;
}
static void __init vt8500_init_irq_hw(void __iomem *base)
{
u32 i;
writel(ICPC_ROTATE, base + VT8500_ICPC_IRQ);
writel(0x00, base + VT8500_ICPC_FIQ);
for (i = 0; i < 64; i++)
writeb(VT8500_INT_DISABLE | ICDC_IRQ, base + VT8500_ICDC + i);
}
static int vt8500_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &vt8500_irq_chip, handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static void __exception_irq_entry vt8500_handle_irq(struct pt_regs *regs)
{
u32 stat, i;
int irqnr, virq;
void __iomem *base;
for (i=0; i<active_cnt; i++) {
base = intc[i].base;
irqnr = readl_relaxed(base) & 0x3F;
if (irqnr == 63) {
stat = readl_relaxed(base + VT8500_ICIS + 4);
if (!(stat & BIT(31)))
continue;
}
virq = irq_find_mapping(intc[i].domain, irqnr);
handle_IRQ(virq, regs);
}
}
static int __init vt8500_irq_init(struct device_node *node,
struct device_node *parent)
{
int irq, i;
struct device_node *np = node;
if (active_cnt == VT8500_INTC_MAX) {
pr_err("%s: Interrupt controllers > VT8500_INTC_MAX\n",
__func__);
goto out;
}
intc[active_cnt].base = of_iomap(np, 0);
intc[active_cnt].domain = irq_domain_add_linear(node, 64,
&vt8500_irq_domain_ops, &intc[active_cnt]);
if (!intc[active_cnt].base) {
pr_err("%s: Unable to map IO memory\n", __func__);
goto out;
}
if (!intc[active_cnt].domain) {
pr_err("%s: Unable to add irq domain!\n", __func__);
goto out;
}
set_handle_irq(vt8500_handle_irq);
vt8500_init_irq_hw(intc[active_cnt].base);
pr_info("vt8500-irq: Added interrupt controller\n");
active_cnt++;
if (of_irq_count(np) != 0) {
if (of_irq_count(np) != 8) {
pr_err("%s: Incorrect IRQ map for slaved controller\n",
__func__);
return -EINVAL;
}
for (i = 0; i < 8; i++) {
irq = irq_of_parse_and_map(np, i);
enable_irq(irq);
}
pr_info("vt8500-irq: Enabled slave->parent interrupts\n");
}
out:
return 0;
}
