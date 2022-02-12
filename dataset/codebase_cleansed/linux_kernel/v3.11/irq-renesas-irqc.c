static void irqc_dbg(struct irqc_irq *i, char *str)
{
dev_dbg(&i->p->pdev->dev, "%s (%d:%d:%d)\n",
str, i->requested_irq, i->hw_irq, i->domain_irq);
}
static void irqc_irq_enable(struct irq_data *d)
{
struct irqc_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
irqc_dbg(&p->irq[hw_irq], "enable");
iowrite32(BIT(hw_irq), p->cpu_int_base + IRQC_EN_SET);
}
static void irqc_irq_disable(struct irq_data *d)
{
struct irqc_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
irqc_dbg(&p->irq[hw_irq], "disable");
iowrite32(BIT(hw_irq), p->cpu_int_base + IRQC_EN_STS);
}
static int irqc_irq_set_type(struct irq_data *d, unsigned int type)
{
struct irqc_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
unsigned char value = irqc_sense[type & IRQ_TYPE_SENSE_MASK];
unsigned long tmp;
irqc_dbg(&p->irq[hw_irq], "sense");
if (!(value & INTC_IRQ_SENSE_VALID))
return -EINVAL;
tmp = ioread32(p->iomem + IRQC_CONFIG(hw_irq));
tmp &= ~0x3f;
tmp |= value ^ INTC_IRQ_SENSE_VALID;
iowrite32(tmp, p->iomem + IRQC_CONFIG(hw_irq));
return 0;
}
static irqreturn_t irqc_irq_handler(int irq, void *dev_id)
{
struct irqc_irq *i = dev_id;
struct irqc_priv *p = i->p;
unsigned long bit = BIT(i->hw_irq);
irqc_dbg(i, "demux1");
if (ioread32(p->iomem + DETECT_STATUS) & bit) {
iowrite32(bit, p->iomem + DETECT_STATUS);
irqc_dbg(i, "demux2");
generic_handle_irq(i->domain_irq);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int irqc_irq_domain_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct irqc_priv *p = h->host_data;
p->irq[hw].domain_irq = virq;
p->irq[hw].hw_irq = hw;
irqc_dbg(&p->irq[hw], "map");
irq_set_chip_data(virq, h->host_data);
irq_set_chip_and_handler(virq, &p->irq_chip, handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int irqc_probe(struct platform_device *pdev)
{
struct renesas_irqc_config *pdata = pdev->dev.platform_data;
struct irqc_priv *p;
struct resource *io;
struct resource *irq;
struct irq_chip *irq_chip;
const char *name = dev_name(&pdev->dev);
int ret;
int k;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
ret = -ENOMEM;
goto err0;
}
if (pdata)
memcpy(&p->config, pdata, sizeof(*pdata));
p->pdev = pdev;
platform_set_drvdata(pdev, p);
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!io) {
dev_err(&pdev->dev, "not enough IOMEM resources\n");
ret = -EINVAL;
goto err1;
}
for (k = 0; k < IRQC_IRQ_MAX; k++) {
irq = platform_get_resource(pdev, IORESOURCE_IRQ, k);
if (!irq)
break;
p->irq[k].p = p;
p->irq[k].requested_irq = irq->start;
}
p->number_of_irqs = k;
if (p->number_of_irqs < 1) {
dev_err(&pdev->dev, "not enough IRQ resources\n");
ret = -EINVAL;
goto err1;
}
p->iomem = ioremap_nocache(io->start, resource_size(io));
if (!p->iomem) {
dev_err(&pdev->dev, "failed to remap IOMEM\n");
ret = -ENXIO;
goto err2;
}
p->cpu_int_base = p->iomem + IRQC_INT_CPU_BASE(0);
irq_chip = &p->irq_chip;
irq_chip->name = name;
irq_chip->irq_mask = irqc_irq_disable;
irq_chip->irq_unmask = irqc_irq_enable;
irq_chip->irq_enable = irqc_irq_enable;
irq_chip->irq_disable = irqc_irq_disable;
irq_chip->irq_set_type = irqc_irq_set_type;
irq_chip->flags = IRQCHIP_SKIP_SET_WAKE;
p->irq_domain = irq_domain_add_simple(pdev->dev.of_node,
p->number_of_irqs,
p->config.irq_base,
&irqc_irq_domain_ops, p);
if (!p->irq_domain) {
ret = -ENXIO;
dev_err(&pdev->dev, "cannot initialize irq domain\n");
goto err2;
}
for (k = 0; k < p->number_of_irqs; k++) {
if (request_irq(p->irq[k].requested_irq, irqc_irq_handler,
0, name, &p->irq[k])) {
dev_err(&pdev->dev, "failed to request IRQ\n");
ret = -ENOENT;
goto err3;
}
}
dev_info(&pdev->dev, "driving %d irqs\n", p->number_of_irqs);
if (p->config.irq_base) {
if (p->config.irq_base != p->irq[0].domain_irq)
dev_warn(&pdev->dev, "irq base mismatch (%d/%d)\n",
p->config.irq_base, p->irq[0].domain_irq);
}
return 0;
err3:
while (--k >= 0)
free_irq(p->irq[k].requested_irq, &p->irq[k]);
irq_domain_remove(p->irq_domain);
err2:
iounmap(p->iomem);
err1:
kfree(p);
err0:
return ret;
}
static int irqc_remove(struct platform_device *pdev)
{
struct irqc_priv *p = platform_get_drvdata(pdev);
int k;
for (k = 0; k < p->number_of_irqs; k++)
free_irq(p->irq[k].requested_irq, &p->irq[k]);
irq_domain_remove(p->irq_domain);
iounmap(p->iomem);
kfree(p);
return 0;
}
static int __init irqc_init(void)
{
return platform_driver_register(&irqc_device_driver);
}
static void __exit irqc_exit(void)
{
platform_driver_unregister(&irqc_device_driver);
}
