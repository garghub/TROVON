static struct irqc_priv *irq_data_to_priv(struct irq_data *data)
{
return data->domain->host_data;
}
static void irqc_dbg(struct irqc_irq *i, char *str)
{
dev_dbg(&i->p->pdev->dev, "%s (%d:%d)\n",
str, i->requested_irq, i->hw_irq);
}
static int irqc_irq_set_type(struct irq_data *d, unsigned int type)
{
struct irqc_priv *p = irq_data_to_priv(d);
int hw_irq = irqd_to_hwirq(d);
unsigned char value = irqc_sense[type & IRQ_TYPE_SENSE_MASK];
u32 tmp;
irqc_dbg(&p->irq[hw_irq], "sense");
if (!value)
return -EINVAL;
tmp = ioread32(p->iomem + IRQC_CONFIG(hw_irq));
tmp &= ~0x3f;
tmp |= value;
iowrite32(tmp, p->iomem + IRQC_CONFIG(hw_irq));
return 0;
}
static int irqc_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct irqc_priv *p = irq_data_to_priv(d);
int hw_irq = irqd_to_hwirq(d);
irq_set_irq_wake(p->irq[hw_irq].requested_irq, on);
if (!p->clk)
return 0;
if (on)
clk_enable(p->clk);
else
clk_disable(p->clk);
return 0;
}
static irqreturn_t irqc_irq_handler(int irq, void *dev_id)
{
struct irqc_irq *i = dev_id;
struct irqc_priv *p = i->p;
u32 bit = BIT(i->hw_irq);
irqc_dbg(i, "demux1");
if (ioread32(p->iomem + DETECT_STATUS) & bit) {
iowrite32(bit, p->iomem + DETECT_STATUS);
irqc_dbg(i, "demux2");
generic_handle_irq(irq_find_mapping(p->irq_domain, i->hw_irq));
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int irqc_probe(struct platform_device *pdev)
{
struct irqc_priv *p;
struct resource *io;
struct resource *irq;
const char *name = dev_name(&pdev->dev);
int ret;
int k;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
ret = -ENOMEM;
goto err0;
}
p->pdev = pdev;
platform_set_drvdata(pdev, p);
p->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(p->clk)) {
dev_warn(&pdev->dev, "unable to get clock\n");
p->clk = NULL;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
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
p->irq[k].hw_irq = k;
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
p->irq_domain = irq_domain_add_linear(pdev->dev.of_node,
p->number_of_irqs,
&irq_generic_chip_ops, p);
if (!p->irq_domain) {
ret = -ENXIO;
dev_err(&pdev->dev, "cannot initialize irq domain\n");
goto err2;
}
ret = irq_alloc_domain_generic_chips(p->irq_domain, p->number_of_irqs,
1, name, handle_level_irq,
0, 0, IRQ_GC_INIT_NESTED_LOCK);
if (ret) {
dev_err(&pdev->dev, "cannot allocate generic chip\n");
goto err3;
}
p->gc = irq_get_domain_generic_chip(p->irq_domain, 0);
p->gc->reg_base = p->cpu_int_base;
p->gc->chip_types[0].regs.enable = IRQC_EN_SET;
p->gc->chip_types[0].regs.disable = IRQC_EN_STS;
p->gc->chip_types[0].chip.irq_mask = irq_gc_mask_disable_reg;
p->gc->chip_types[0].chip.irq_unmask = irq_gc_unmask_enable_reg;
p->gc->chip_types[0].chip.irq_set_type = irqc_irq_set_type;
p->gc->chip_types[0].chip.irq_set_wake = irqc_irq_set_wake;
p->gc->chip_types[0].chip.flags = IRQCHIP_MASK_ON_SUSPEND;
for (k = 0; k < p->number_of_irqs; k++) {
if (request_irq(p->irq[k].requested_irq, irqc_irq_handler,
0, name, &p->irq[k])) {
dev_err(&pdev->dev, "failed to request IRQ\n");
ret = -ENOENT;
goto err4;
}
}
dev_info(&pdev->dev, "driving %d irqs\n", p->number_of_irqs);
return 0;
err4:
while (--k >= 0)
free_irq(p->irq[k].requested_irq, &p->irq[k]);
err3:
irq_domain_remove(p->irq_domain);
err2:
iounmap(p->iomem);
err1:
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
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
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
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
