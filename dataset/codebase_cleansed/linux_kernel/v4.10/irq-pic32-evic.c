asmlinkage void __weak plat_irq_dispatch(void)
{
unsigned int irq, hwirq;
hwirq = readl(evic_base + REG_INTSTAT) & 0xFF;
irq = irq_linear_revmap(evic_irq_domain, hwirq);
do_IRQ(irq);
}
static struct evic_chip_data *irqd_to_priv(struct irq_data *data)
{
return (struct evic_chip_data *)data->domain->host_data;
}
static int pic32_set_ext_polarity(int bit, u32 type)
{
switch (type) {
case IRQ_TYPE_EDGE_RISING:
writel(BIT(bit), evic_base + PIC32_SET(REG_INTCON));
break;
case IRQ_TYPE_EDGE_FALLING:
writel(BIT(bit), evic_base + PIC32_CLR(REG_INTCON));
break;
default:
return -EINVAL;
}
return 0;
}
static int pic32_set_type_edge(struct irq_data *data,
unsigned int flow_type)
{
struct evic_chip_data *priv = irqd_to_priv(data);
int ret;
int i;
if (!(flow_type & IRQ_TYPE_EDGE_BOTH))
return -EBADR;
for (i = 0; i < ARRAY_SIZE(priv->ext_irqs); i++) {
if (priv->ext_irqs[i] == data->hwirq) {
ret = pic32_set_ext_polarity(i, flow_type);
if (ret)
return ret;
}
}
irqd_set_trigger_type(data, flow_type);
return IRQ_SET_MASK_OK;
}
static void pic32_bind_evic_interrupt(int irq, int set)
{
writel(set, evic_base + REG_OFF_OFFSET + irq * 4);
}
static void pic32_set_irq_priority(int irq, int priority)
{
u32 reg, shift;
reg = irq / 4;
shift = (irq % 4) * 8;
writel(PRIORITY_MASK << shift,
evic_base + PIC32_CLR(REG_IPC_OFFSET + reg * 0x10));
writel(priority << shift,
evic_base + PIC32_SET(REG_IPC_OFFSET + reg * 0x10));
}
static int pic32_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
struct evic_chip_data *priv = d->host_data;
struct irq_data *data;
int ret;
u32 iecclr, ifsclr;
u32 reg, mask;
ret = irq_map_generic_chip(d, virq, hw);
if (ret)
return ret;
if (priv->irq_types[hw] & IRQ_TYPE_SENSE_MASK) {
data = irq_domain_get_irq_data(d, virq);
irqd_set_trigger_type(data, priv->irq_types[hw]);
irq_setup_alt_chip(data, priv->irq_types[hw]);
}
IRQ_REG_MASK(hw, reg, mask);
iecclr = PIC32_CLR(REG_IEC_OFFSET + reg * 0x10);
ifsclr = PIC32_CLR(REG_IFS_OFFSET + reg * 0x10);
writel(mask, evic_base + iecclr);
writel(mask, evic_base + ifsclr);
pic32_set_irq_priority(hw, PIC32_INT_PRI(2, 0));
return ret;
}
int pic32_irq_domain_xlate(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_type)
{
struct evic_chip_data *priv = d->host_data;
if (WARN_ON(intsize < 2))
return -EINVAL;
if (WARN_ON(intspec[0] >= NR_IRQS))
return -EINVAL;
*out_hwirq = intspec[0];
*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;
priv->irq_types[intspec[0]] = intspec[1] & IRQ_TYPE_SENSE_MASK;
return 0;
}
static void __init pic32_ext_irq_of_init(struct irq_domain *domain)
{
struct device_node *node = irq_domain_get_of_node(domain);
struct evic_chip_data *priv = domain->host_data;
struct property *prop;
const __le32 *p;
u32 hwirq;
int i = 0;
const char *pname = "microchip,external-irqs";
of_property_for_each_u32(node, pname, prop, p, hwirq) {
if (i >= ARRAY_SIZE(priv->ext_irqs)) {
pr_warn("More than %d external irq, skip rest\n",
ARRAY_SIZE(priv->ext_irqs));
break;
}
priv->ext_irqs[i] = hwirq;
i++;
}
}
static int __init pic32_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_chip_generic *gc;
struct evic_chip_data *priv;
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
int nchips, ret;
int i;
nchips = DIV_ROUND_UP(NR_IRQS, 32);
evic_base = of_iomap(node, 0);
if (!evic_base)
return -ENOMEM;
priv = kcalloc(nchips, sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto err_iounmap;
}
evic_irq_domain = irq_domain_add_linear(node, nchips * 32,
&pic32_irq_domain_ops,
priv);
if (!evic_irq_domain) {
ret = -ENOMEM;
goto err_free_priv;
}
ret = irq_alloc_domain_generic_chips(evic_irq_domain, 32, 2,
"evic-level", handle_level_irq,
clr, 0, 0);
if (ret)
goto err_domain_remove;
board_bind_eic_interrupt = &pic32_bind_evic_interrupt;
for (i = 0; i < nchips; i++) {
u32 ifsclr = PIC32_CLR(REG_IFS_OFFSET + (i * 0x10));
u32 iec = REG_IEC_OFFSET + (i * 0x10);
gc = irq_get_domain_generic_chip(evic_irq_domain, i * 32);
gc->reg_base = evic_base;
gc->unused = 0;
gc->chip_types[0].type = IRQ_TYPE_LEVEL_MASK;
gc->chip_types[0].handler = handle_fasteoi_irq;
gc->chip_types[0].regs.ack = ifsclr;
gc->chip_types[0].regs.mask = iec;
gc->chip_types[0].chip.name = "evic-level";
gc->chip_types[0].chip.irq_eoi = irq_gc_ack_set_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.flags = IRQCHIP_SKIP_SET_WAKE;
gc->chip_types[1].type = IRQ_TYPE_EDGE_BOTH;
gc->chip_types[1].handler = handle_edge_irq;
gc->chip_types[1].regs.ack = ifsclr;
gc->chip_types[1].regs.mask = iec;
gc->chip_types[1].chip.name = "evic-edge";
gc->chip_types[1].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[1].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[1].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[1].chip.irq_set_type = pic32_set_type_edge;
gc->chip_types[1].chip.flags = IRQCHIP_SKIP_SET_WAKE;
gc->private = &priv[i];
}
irq_set_default_host(evic_irq_domain);
pic32_ext_irq_of_init(evic_irq_domain);
return 0;
err_domain_remove:
irq_domain_remove(evic_irq_domain);
err_free_priv:
kfree(priv);
err_iounmap:
iounmap(evic_base);
return ret;
}
