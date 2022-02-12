static void ts4800_irq_mask(struct irq_data *d)
{
struct ts4800_irq_data *data = irq_data_get_irq_chip_data(d);
u16 reg = readw(data->base + IRQ_MASK);
u16 mask = 1 << d->hwirq;
writew(reg | mask, data->base + IRQ_MASK);
}
static void ts4800_irq_unmask(struct irq_data *d)
{
struct ts4800_irq_data *data = irq_data_get_irq_chip_data(d);
u16 reg = readw(data->base + IRQ_MASK);
u16 mask = 1 << d->hwirq;
writew(reg & ~mask, data->base + IRQ_MASK);
}
static int ts4800_irqdomain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct ts4800_irq_data *data = d->host_data;
irq_set_chip_and_handler(irq, &data->irq_chip, handle_simple_irq);
irq_set_chip_data(irq, data);
irq_set_noprobe(irq);
return 0;
}
static void ts4800_ic_chained_handle_irq(struct irq_desc *desc)
{
struct ts4800_irq_data *data = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
u16 status = readw(data->base + IRQ_STATUS);
chained_irq_enter(chip, desc);
if (unlikely(status == 0)) {
handle_bad_irq(desc);
goto out;
}
do {
unsigned int bit = __ffs(status);
int irq = irq_find_mapping(data->domain, bit);
status &= ~(1 << bit);
generic_handle_irq(irq);
} while (status);
out:
chained_irq_exit(chip, desc);
}
static int ts4800_ic_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct ts4800_irq_data *data;
struct irq_chip *irq_chip;
struct resource *res;
int parent_irq;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
writew(0xFFFF, data->base + IRQ_MASK);
parent_irq = irq_of_parse_and_map(node, 0);
if (!parent_irq) {
dev_err(&pdev->dev, "failed to get parent IRQ\n");
return -EINVAL;
}
irq_chip = &data->irq_chip;
irq_chip->name = dev_name(&pdev->dev);
irq_chip->irq_mask = ts4800_irq_mask;
irq_chip->irq_unmask = ts4800_irq_unmask;
data->domain = irq_domain_add_linear(node, 8, &ts4800_ic_ops, data);
if (!data->domain) {
dev_err(&pdev->dev, "cannot add IRQ domain\n");
return -ENOMEM;
}
irq_set_chained_handler_and_data(parent_irq,
ts4800_ic_chained_handle_irq, data);
platform_set_drvdata(pdev, data);
return 0;
}
static int ts4800_ic_remove(struct platform_device *pdev)
{
struct ts4800_irq_data *data = platform_get_drvdata(pdev);
irq_domain_remove(data->domain);
return 0;
}
