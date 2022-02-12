static void xgene_gpio_set_bit(struct gpio_chip *gc,
void __iomem *reg, u32 gpio, int val)
{
u32 data;
data = gc->read_reg(reg);
if (val)
data |= GPIO_MASK(gpio);
else
data &= ~GPIO_MASK(gpio);
gc->write_reg(reg, data);
}
static int xgene_gpio_sb_irq_set_type(struct irq_data *d, unsigned int type)
{
struct xgene_gpio_sb *priv = irq_data_get_irq_chip_data(d);
int gpio = HWIRQ_TO_GPIO(priv, d->hwirq);
int lvl_type = GPIO_INT_LEVEL_H;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
case IRQ_TYPE_LEVEL_HIGH:
lvl_type = GPIO_INT_LEVEL_H;
break;
case IRQ_TYPE_EDGE_FALLING:
case IRQ_TYPE_LEVEL_LOW:
lvl_type = GPIO_INT_LEVEL_L;
break;
default:
break;
}
xgene_gpio_set_bit(&priv->gc, priv->regs + MPA_GPIO_SEL_LO,
gpio * 2, 1);
xgene_gpio_set_bit(&priv->gc, priv->regs + MPA_GPIO_INT_LVL,
d->hwirq, lvl_type);
if (type & IRQ_TYPE_EDGE_BOTH)
return irq_chip_set_type_parent(d, IRQ_TYPE_EDGE_RISING);
else
return irq_chip_set_type_parent(d, IRQ_TYPE_LEVEL_HIGH);
}
static int xgene_gpio_sb_to_irq(struct gpio_chip *gc, u32 gpio)
{
struct xgene_gpio_sb *priv = gpiochip_get_data(gc);
struct irq_fwspec fwspec;
if ((gpio < priv->irq_start) ||
(gpio > HWIRQ_TO_GPIO(priv, priv->nirq)))
return -ENXIO;
if (gc->parent->of_node)
fwspec.fwnode = of_node_to_fwnode(gc->parent->of_node);
else
fwspec.fwnode = gc->parent->fwnode;
fwspec.param_count = 2;
fwspec.param[0] = GPIO_TO_HWIRQ(priv, gpio);
fwspec.param[1] = IRQ_TYPE_NONE;
return irq_create_fwspec_mapping(&fwspec);
}
static void xgene_gpio_sb_domain_activate(struct irq_domain *d,
struct irq_data *irq_data)
{
struct xgene_gpio_sb *priv = d->host_data;
u32 gpio = HWIRQ_TO_GPIO(priv, irq_data->hwirq);
if (gpiochip_lock_as_irq(&priv->gc, gpio)) {
dev_err(priv->gc.parent,
"Unable to configure XGene GPIO standby pin %d as IRQ\n",
gpio);
return;
}
xgene_gpio_set_bit(&priv->gc, priv->regs + MPA_GPIO_SEL_LO,
gpio * 2, 1);
}
static void xgene_gpio_sb_domain_deactivate(struct irq_domain *d,
struct irq_data *irq_data)
{
struct xgene_gpio_sb *priv = d->host_data;
u32 gpio = HWIRQ_TO_GPIO(priv, irq_data->hwirq);
gpiochip_unlock_as_irq(&priv->gc, gpio);
xgene_gpio_set_bit(&priv->gc, priv->regs + MPA_GPIO_SEL_LO,
gpio * 2, 0);
}
static int xgene_gpio_sb_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
struct xgene_gpio_sb *priv = d->host_data;
if ((fwspec->param_count != 2) ||
(fwspec->param[0] >= priv->nirq))
return -EINVAL;
*hwirq = fwspec->param[0];
*type = fwspec->param[1];
return 0;
}
static int xgene_gpio_sb_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs, void *data)
{
struct irq_fwspec *fwspec = data;
struct irq_fwspec parent_fwspec;
struct xgene_gpio_sb *priv = domain->host_data;
irq_hw_number_t hwirq;
unsigned int i;
hwirq = fwspec->param[0];
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&xgene_gpio_sb_irq_chip, priv);
parent_fwspec.fwnode = domain->parent->fwnode;
if (is_of_node(parent_fwspec.fwnode)) {
parent_fwspec.param_count = 3;
parent_fwspec.param[0] = 0;
parent_fwspec.param[1] = hwirq + priv->parent_irq_base - 32;
parent_fwspec.param[2] = fwspec->param[1];
} else if (is_fwnode_irqchip(parent_fwspec.fwnode)) {
parent_fwspec.param_count = 2;
parent_fwspec.param[0] = hwirq + priv->parent_irq_base;
parent_fwspec.param[1] = fwspec->param[1];
} else
return -EINVAL;
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
&parent_fwspec);
}
static void xgene_gpio_sb_domain_free(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *d;
unsigned int i;
for (i = 0; i < nr_irqs; i++) {
d = irq_domain_get_irq_data(domain, virq + i);
irq_domain_reset_irq_data(d);
}
}
static int xgene_gpio_sb_probe(struct platform_device *pdev)
{
struct xgene_gpio_sb *priv;
int ret;
struct resource *res;
void __iomem *regs;
struct irq_domain *parent_domain = NULL;
struct fwnode_handle *fwnode;
u32 val32;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
priv->regs = regs;
ret = platform_get_irq(pdev, 0);
if (ret > 0) {
priv->parent_irq_base = irq_get_irq_data(ret)->hwirq;
parent_domain = irq_get_irq_data(ret)->domain;
}
if (!parent_domain) {
dev_err(&pdev->dev, "unable to obtain parent domain\n");
return -ENODEV;
}
ret = bgpio_init(&priv->gc, &pdev->dev, 4,
regs + MPA_GPIO_IN_ADDR,
regs + MPA_GPIO_OUT_ADDR, NULL,
regs + MPA_GPIO_OE_ADDR, NULL, 0);
if (ret)
return ret;
priv->gc.to_irq = xgene_gpio_sb_to_irq;
priv->irq_start = XGENE_DFLT_IRQ_START_PIN;
if (!device_property_read_u32(&pdev->dev,
XGENE_IRQ_START_PROPERTY, &val32))
priv->irq_start = val32;
priv->nirq = XGENE_DFLT_MAX_NIRQ;
if (!device_property_read_u32(&pdev->dev, XGENE_NIRQ_PROPERTY, &val32))
priv->nirq = val32;
priv->gc.ngpio = XGENE_DFLT_MAX_NGPIO;
if (!device_property_read_u32(&pdev->dev, XGENE_NGPIO_PROPERTY, &val32))
priv->gc.ngpio = val32;
dev_info(&pdev->dev, "Support %d gpios, %d irqs start from pin %d\n",
priv->gc.ngpio, priv->nirq, priv->irq_start);
platform_set_drvdata(pdev, priv);
if (pdev->dev.of_node)
fwnode = of_node_to_fwnode(pdev->dev.of_node);
else
fwnode = pdev->dev.fwnode;
priv->irq_domain = irq_domain_create_hierarchy(parent_domain,
0, priv->nirq, fwnode,
&xgene_gpio_sb_domain_ops, priv);
if (!priv->irq_domain)
return -ENODEV;
priv->gc.irqdomain = priv->irq_domain;
ret = devm_gpiochip_add_data(&pdev->dev, &priv->gc, priv);
if (ret) {
dev_err(&pdev->dev,
"failed to register X-Gene GPIO Standby driver\n");
irq_domain_remove(priv->irq_domain);
return ret;
}
dev_info(&pdev->dev, "X-Gene GPIO Standby driver registered\n");
if (priv->nirq > 0) {
acpi_gpiochip_request_interrupts(&priv->gc);
}
return ret;
}
static int xgene_gpio_sb_remove(struct platform_device *pdev)
{
struct xgene_gpio_sb *priv = platform_get_drvdata(pdev);
if (priv->nirq > 0) {
acpi_gpiochip_free_interrupts(&priv->gc);
}
irq_domain_remove(priv->irq_domain);
return 0;
}
