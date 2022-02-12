static void eic_ack_irq(struct irq_data *d)
{
struct eic *eic = irq_data_get_irq_chip_data(d);
eic_writel(eic, ICR, 1 << (d->irq - eic->first_irq));
}
static void eic_mask_irq(struct irq_data *d)
{
struct eic *eic = irq_data_get_irq_chip_data(d);
eic_writel(eic, IDR, 1 << (d->irq - eic->first_irq));
}
static void eic_mask_ack_irq(struct irq_data *d)
{
struct eic *eic = irq_data_get_irq_chip_data(d);
eic_writel(eic, ICR, 1 << (d->irq - eic->first_irq));
eic_writel(eic, IDR, 1 << (d->irq - eic->first_irq));
}
static void eic_unmask_irq(struct irq_data *d)
{
struct eic *eic = irq_data_get_irq_chip_data(d);
eic_writel(eic, IER, 1 << (d->irq - eic->first_irq));
}
static int eic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
struct eic *eic = irq_data_get_irq_chip_data(d);
unsigned int irq = d->irq;
unsigned int i = irq - eic->first_irq;
u32 mode, edge, level;
flow_type &= IRQ_TYPE_SENSE_MASK;
if (flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_LEVEL_LOW;
mode = eic_readl(eic, MODE);
edge = eic_readl(eic, EDGE);
level = eic_readl(eic, LEVEL);
switch (flow_type) {
case IRQ_TYPE_LEVEL_LOW:
mode |= 1 << i;
level &= ~(1 << i);
break;
case IRQ_TYPE_LEVEL_HIGH:
mode |= 1 << i;
level |= 1 << i;
break;
case IRQ_TYPE_EDGE_RISING:
mode &= ~(1 << i);
edge |= 1 << i;
break;
case IRQ_TYPE_EDGE_FALLING:
mode &= ~(1 << i);
edge &= ~(1 << i);
break;
default:
return -EINVAL;
}
eic_writel(eic, MODE, mode);
eic_writel(eic, EDGE, edge);
eic_writel(eic, LEVEL, level);
irqd_set_trigger_type(d, flow_type);
if (flow_type & (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_LEVEL_HIGH))
irq_set_handler_locked(d, handle_level_irq);
else
irq_set_handler_locked(d, handle_edge_irq);
return IRQ_SET_MASK_OK_NOCOPY;
}
static void demux_eic_irq(struct irq_desc *desc)
{
struct eic *eic = irq_desc_get_handler_data(desc);
unsigned long status, pending;
unsigned int i;
status = eic_readl(eic, ISR);
pending = status & eic_readl(eic, IMR);
while (pending) {
i = fls(pending) - 1;
pending &= ~(1 << i);
generic_handle_irq(i + eic->first_irq);
}
}
int nmi_enable(void)
{
nmi_enabled = true;
if (nmi_eic)
eic_writel(nmi_eic, NMIC, EIC_NMIC_ENABLE);
return 0;
}
void nmi_disable(void)
{
if (nmi_eic)
eic_writel(nmi_eic, NMIC, 0);
nmi_enabled = false;
}
static int __init eic_probe(struct platform_device *pdev)
{
struct eic *eic;
struct resource *regs;
unsigned int i;
unsigned int nr_of_irqs;
unsigned int int_irq;
int ret;
u32 pattern;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
int_irq = platform_get_irq(pdev, 0);
if (!regs || (int)int_irq <= 0) {
dev_dbg(&pdev->dev, "missing regs and/or irq resource\n");
return -ENXIO;
}
ret = -ENOMEM;
eic = kzalloc(sizeof(struct eic), GFP_KERNEL);
if (!eic) {
dev_dbg(&pdev->dev, "no memory for eic structure\n");
goto err_kzalloc;
}
eic->first_irq = EIM_IRQ_BASE + 32 * pdev->id;
eic->regs = ioremap(regs->start, resource_size(regs));
if (!eic->regs) {
dev_dbg(&pdev->dev, "failed to map regs\n");
goto err_ioremap;
}
eic_writel(eic, IDR, ~0UL);
eic_writel(eic, MODE, ~0UL);
pattern = eic_readl(eic, MODE);
nr_of_irqs = fls(pattern);
eic_writel(eic, EDGE, 0UL);
eic_writel(eic, LEVEL, 0UL);
eic->chip = &eic_chip;
for (i = 0; i < nr_of_irqs; i++) {
irq_set_chip_and_handler(eic->first_irq + i, &eic_chip,
handle_level_irq);
irq_set_chip_data(eic->first_irq + i, eic);
}
irq_set_chained_handler_and_data(int_irq, demux_eic_irq, eic);
if (pdev->id == 0) {
nmi_eic = eic;
if (nmi_enabled)
nmi_enable();
}
dev_info(&pdev->dev,
"External Interrupt Controller at 0x%p, IRQ %u\n",
eic->regs, int_irq);
dev_info(&pdev->dev,
"Handling %u external IRQs, starting with IRQ %u\n",
nr_of_irqs, eic->first_irq);
return 0;
err_ioremap:
kfree(eic);
err_kzalloc:
return ret;
}
static int __init eic_init(void)
{
return platform_driver_probe(&eic_driver, eic_probe);
}
