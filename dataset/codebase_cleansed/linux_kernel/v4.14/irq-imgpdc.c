static void pdc_write(struct pdc_intc_priv *priv, unsigned int reg_offs,
unsigned int data)
{
iowrite32(data, priv->pdc_base + reg_offs);
}
static unsigned int pdc_read(struct pdc_intc_priv *priv,
unsigned int reg_offs)
{
return ioread32(priv->pdc_base + reg_offs);
}
static unsigned int hwirq_is_syswake(irq_hw_number_t hw)
{
return hw >= SYS0_HWIRQ;
}
static unsigned int hwirq_to_syswake(irq_hw_number_t hw)
{
return hw - SYS0_HWIRQ;
}
static irq_hw_number_t syswake_to_hwirq(unsigned int syswake)
{
return SYS0_HWIRQ + syswake;
}
static struct pdc_intc_priv *irqd_to_priv(struct irq_data *data)
{
return (struct pdc_intc_priv *)data->domain->host_data;
}
static void perip_irq_mask(struct irq_data *data)
{
struct pdc_intc_priv *priv = irqd_to_priv(data);
raw_spin_lock(&priv->lock);
priv->irq_route &= ~data->mask;
pdc_write(priv, PDC_IRQ_ROUTE, priv->irq_route);
raw_spin_unlock(&priv->lock);
}
static void perip_irq_unmask(struct irq_data *data)
{
struct pdc_intc_priv *priv = irqd_to_priv(data);
raw_spin_lock(&priv->lock);
priv->irq_route |= data->mask;
pdc_write(priv, PDC_IRQ_ROUTE, priv->irq_route);
raw_spin_unlock(&priv->lock);
}
static int syswake_irq_set_type(struct irq_data *data, unsigned int flow_type)
{
struct pdc_intc_priv *priv = irqd_to_priv(data);
unsigned int syswake = hwirq_to_syswake(data->hwirq);
unsigned int irq_mode;
unsigned int soc_sys_wake_regoff, soc_sys_wake;
switch (flow_type) {
case IRQ_TYPE_EDGE_BOTH:
irq_mode = PDC_SYS_WAKE_INT_CHANGE;
break;
case IRQ_TYPE_EDGE_RISING:
irq_mode = PDC_SYS_WAKE_INT_UP;
break;
case IRQ_TYPE_EDGE_FALLING:
irq_mode = PDC_SYS_WAKE_INT_DOWN;
break;
case IRQ_TYPE_LEVEL_HIGH:
irq_mode = PDC_SYS_WAKE_INT_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
irq_mode = PDC_SYS_WAKE_INT_LOW;
break;
default:
return -EINVAL;
}
raw_spin_lock(&priv->lock);
soc_sys_wake_regoff = PDC_SYS_WAKE_BASE + syswake*PDC_SYS_WAKE_STRIDE;
soc_sys_wake = pdc_read(priv, soc_sys_wake_regoff);
soc_sys_wake &= ~PDC_SYS_WAKE_INT_MODE;
soc_sys_wake |= irq_mode << PDC_SYS_WAKE_INT_MODE_SHIFT;
pdc_write(priv, soc_sys_wake_regoff, soc_sys_wake);
irq_setup_alt_chip(data, flow_type);
raw_spin_unlock(&priv->lock);
return 0;
}
static int pdc_irq_set_wake(struct irq_data *data, unsigned int on)
{
struct pdc_intc_priv *priv = irqd_to_priv(data);
irq_hw_number_t hw = data->hwirq;
unsigned int mask = (1 << 16) << hw;
unsigned int dst_irq;
raw_spin_lock(&priv->lock);
if (on)
priv->irq_route |= mask;
else
priv->irq_route &= ~mask;
pdc_write(priv, PDC_IRQ_ROUTE, priv->irq_route);
raw_spin_unlock(&priv->lock);
if (hwirq_is_syswake(hw))
dst_irq = priv->syswake_irq;
else
dst_irq = priv->perip_irqs[hw];
irq_set_irq_wake(dst_irq, on);
return 0;
}
static void pdc_intc_perip_isr(struct irq_desc *desc)
{
unsigned int irq = irq_desc_get_irq(desc);
struct pdc_intc_priv *priv;
unsigned int i, irq_no;
priv = (struct pdc_intc_priv *)irq_desc_get_handler_data(desc);
for (i = 0; i < priv->nr_perips; ++i)
if (irq == priv->perip_irqs[i])
goto found;
return;
found:
irq_no = irq_linear_revmap(priv->domain, i);
generic_handle_irq(irq_no);
}
static void pdc_intc_syswake_isr(struct irq_desc *desc)
{
struct pdc_intc_priv *priv;
unsigned int syswake, irq_no;
unsigned int status;
priv = (struct pdc_intc_priv *)irq_desc_get_handler_data(desc);
status = pdc_read(priv, PDC_IRQ_STATUS) &
pdc_read(priv, PDC_IRQ_ENABLE);
status &= (1 << priv->nr_syswakes) - 1;
for (syswake = 0; status; status >>= 1, ++syswake) {
if (!(status & 1))
continue;
irq_no = irq_linear_revmap(priv->domain,
syswake_to_hwirq(syswake));
generic_handle_irq(irq_no);
}
}
static void pdc_intc_setup(struct pdc_intc_priv *priv)
{
int i;
unsigned int soc_sys_wake_regoff;
unsigned int soc_sys_wake;
pdc_write(priv, PDC_IRQ_ENABLE, 0);
priv->irq_route = ((PDC_IRQ_ROUTE_EXT_EN_SYS0 << priv->nr_syswakes) -
PDC_IRQ_ROUTE_EXT_EN_SYS0);
pdc_write(priv, PDC_IRQ_ROUTE, priv->irq_route);
for (i = 0; i < priv->nr_syswakes; ++i) {
soc_sys_wake_regoff = PDC_SYS_WAKE_BASE + i*PDC_SYS_WAKE_STRIDE;
soc_sys_wake = PDC_SYS_WAKE_INT_NONE
<< PDC_SYS_WAKE_INT_MODE_SHIFT;
pdc_write(priv, soc_sys_wake_regoff, soc_sys_wake);
}
}
static int pdc_intc_probe(struct platform_device *pdev)
{
struct pdc_intc_priv *priv;
struct device_node *node = pdev->dev.of_node;
struct resource *res_regs;
struct irq_chip_generic *gc;
unsigned int i;
int irq, ret;
u32 val;
if (!node)
return -ENOENT;
res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_regs == NULL) {
dev_err(&pdev->dev, "cannot find registers resource\n");
return -ENOENT;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
raw_spin_lock_init(&priv->lock);
platform_set_drvdata(pdev, priv);
priv->pdc_base = devm_ioremap(&pdev->dev, res_regs->start,
res_regs->end - res_regs->start);
if (!priv->pdc_base)
return -EIO;
ret = of_property_read_u32(node, "num-perips", &val);
if (ret) {
dev_err(&pdev->dev, "No num-perips node property found\n");
return -EINVAL;
}
if (val > SYS0_HWIRQ) {
dev_err(&pdev->dev, "num-perips (%u) out of range\n", val);
return -EINVAL;
}
priv->nr_perips = val;
ret = of_property_read_u32(node, "num-syswakes", &val);
if (ret) {
dev_err(&pdev->dev, "No num-syswakes node property found\n");
return -EINVAL;
}
if (val > SYS0_HWIRQ) {
dev_err(&pdev->dev, "num-syswakes (%u) out of range\n", val);
return -EINVAL;
}
priv->nr_syswakes = val;
priv->perip_irqs = devm_kzalloc(&pdev->dev, 4 * priv->nr_perips,
GFP_KERNEL);
if (!priv->perip_irqs) {
dev_err(&pdev->dev, "cannot allocate perip IRQ list\n");
return -ENOMEM;
}
for (i = 0; i < priv->nr_perips; ++i) {
irq = platform_get_irq(pdev, 1 + i);
if (irq < 0) {
dev_err(&pdev->dev, "cannot find perip IRQ #%u\n", i);
return irq;
}
priv->perip_irqs[i] = irq;
}
if (platform_get_irq(pdev, 1 + i) >= 0) {
dev_err(&pdev->dev, "surplus perip IRQs detected\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "cannot find syswake IRQ\n");
return irq;
}
priv->syswake_irq = irq;
priv->domain = irq_domain_add_linear(node, 16, &irq_generic_chip_ops,
priv);
if (unlikely(!priv->domain)) {
dev_err(&pdev->dev, "cannot add IRQ domain\n");
return -ENOMEM;
}
ret = irq_alloc_domain_generic_chips(priv->domain, 8, 2, "pdc",
handle_level_irq, 0, 0,
IRQ_GC_INIT_NESTED_LOCK);
if (ret)
goto err_generic;
gc = irq_get_domain_generic_chip(priv->domain, 0);
gc->unused = ~(BIT(priv->nr_perips) - 1);
gc->reg_base = priv->pdc_base;
gc->chip_types[0].regs.mask = PDC_IRQ_ROUTE;
gc->chip_types[0].chip.irq_mask = perip_irq_mask;
gc->chip_types[0].chip.irq_unmask = perip_irq_unmask;
gc->chip_types[0].chip.irq_set_wake = pdc_irq_set_wake;
gc = irq_get_domain_generic_chip(priv->domain, 8);
gc->unused = ~(BIT(priv->nr_syswakes) - 1);
gc->reg_base = priv->pdc_base;
gc->chip_types[0].type = IRQ_TYPE_EDGE_BOTH;
gc->chip_types[0].handler = handle_edge_irq;
gc->chip_types[0].regs.ack = PDC_IRQ_CLEAR;
gc->chip_types[0].regs.mask = PDC_IRQ_ENABLE;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.irq_set_type = syswake_irq_set_type;
gc->chip_types[0].chip.irq_set_wake = pdc_irq_set_wake;
gc->chip_types[0].chip.flags = IRQCHIP_MASK_ON_SUSPEND;
gc->chip_types[1].type = IRQ_TYPE_LEVEL_MASK;
gc->chip_types[1].handler = handle_level_irq;
gc->chip_types[1].regs.ack = PDC_IRQ_CLEAR;
gc->chip_types[1].regs.mask = PDC_IRQ_ENABLE;
gc->chip_types[1].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[1].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[1].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[1].chip.irq_set_type = syswake_irq_set_type;
gc->chip_types[1].chip.irq_set_wake = pdc_irq_set_wake;
gc->chip_types[1].chip.flags = IRQCHIP_MASK_ON_SUSPEND;
pdc_intc_setup(priv);
for (i = 0; i < priv->nr_perips; ++i) {
irq = priv->perip_irqs[i];
irq_set_chained_handler_and_data(irq, pdc_intc_perip_isr,
priv);
}
irq_set_chained_handler_and_data(priv->syswake_irq,
pdc_intc_syswake_isr, priv);
dev_info(&pdev->dev,
"PDC IRQ controller initialised (%u perip IRQs, %u syswake IRQs)\n",
priv->nr_perips,
priv->nr_syswakes);
return 0;
err_generic:
irq_domain_remove(priv->domain);
return ret;
}
static int pdc_intc_remove(struct platform_device *pdev)
{
struct pdc_intc_priv *priv = platform_get_drvdata(pdev);
irq_domain_remove(priv->domain);
return 0;
}
static int __init pdc_intc_init(void)
{
return platform_driver_register(&pdc_intc_driver);
}
