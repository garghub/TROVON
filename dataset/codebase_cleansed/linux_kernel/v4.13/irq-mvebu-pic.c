static void mvebu_pic_reset(struct mvebu_pic *pic)
{
writel(0, pic->base + PIC_MASK);
writel(PIC_MAX_IRQ_MASK, pic->base + PIC_CAUSE);
}
static void mvebu_pic_eoi_irq(struct irq_data *d)
{
struct mvebu_pic *pic = irq_data_get_irq_chip_data(d);
writel(1 << d->hwirq, pic->base + PIC_CAUSE);
}
static void mvebu_pic_mask_irq(struct irq_data *d)
{
struct mvebu_pic *pic = irq_data_get_irq_chip_data(d);
u32 reg;
reg = readl(pic->base + PIC_MASK);
reg |= (1 << d->hwirq);
writel(reg, pic->base + PIC_MASK);
}
static void mvebu_pic_unmask_irq(struct irq_data *d)
{
struct mvebu_pic *pic = irq_data_get_irq_chip_data(d);
u32 reg;
reg = readl(pic->base + PIC_MASK);
reg &= ~(1 << d->hwirq);
writel(reg, pic->base + PIC_MASK);
}
static int mvebu_pic_irq_map(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hwirq)
{
struct mvebu_pic *pic = domain->host_data;
irq_set_percpu_devid(virq);
irq_set_chip_data(virq, pic);
irq_set_chip_and_handler(virq, &pic->irq_chip,
handle_percpu_devid_irq);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_probe(virq);
return 0;
}
static void mvebu_pic_handle_cascade_irq(struct irq_desc *desc)
{
struct mvebu_pic *pic = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long irqmap, irqn;
unsigned int cascade_irq;
irqmap = readl_relaxed(pic->base + PIC_CAUSE);
chained_irq_enter(chip, desc);
for_each_set_bit(irqn, &irqmap, BITS_PER_LONG) {
cascade_irq = irq_find_mapping(pic->domain, irqn);
generic_handle_irq(cascade_irq);
}
chained_irq_exit(chip, desc);
}
static void mvebu_pic_enable_percpu_irq(void *data)
{
struct mvebu_pic *pic = data;
mvebu_pic_reset(pic);
enable_percpu_irq(pic->parent_irq, IRQ_TYPE_NONE);
}
static void mvebu_pic_disable_percpu_irq(void *data)
{
struct mvebu_pic *pic = data;
disable_percpu_irq(pic->parent_irq);
}
static int mvebu_pic_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct mvebu_pic *pic;
struct irq_chip *irq_chip;
struct resource *res;
pic = devm_kzalloc(&pdev->dev, sizeof(struct mvebu_pic), GFP_KERNEL);
if (!pic)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pic->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pic->base))
return PTR_ERR(pic->base);
irq_chip = &pic->irq_chip;
irq_chip->name = dev_name(&pdev->dev);
irq_chip->irq_mask = mvebu_pic_mask_irq;
irq_chip->irq_unmask = mvebu_pic_unmask_irq;
irq_chip->irq_eoi = mvebu_pic_eoi_irq;
pic->parent_irq = irq_of_parse_and_map(node, 0);
if (pic->parent_irq <= 0) {
dev_err(&pdev->dev, "Failed to parse parent interrupt\n");
return -EINVAL;
}
pic->domain = irq_domain_add_linear(node, PIC_MAX_IRQS,
&mvebu_pic_domain_ops, pic);
if (!pic->domain) {
dev_err(&pdev->dev, "Failed to allocate irq domain\n");
return -ENOMEM;
}
irq_set_chained_handler(pic->parent_irq, mvebu_pic_handle_cascade_irq);
irq_set_handler_data(pic->parent_irq, pic);
on_each_cpu(mvebu_pic_enable_percpu_irq, pic, 1);
platform_set_drvdata(pdev, pic);
return 0;
}
static int mvebu_pic_remove(struct platform_device *pdev)
{
struct mvebu_pic *pic = platform_get_drvdata(pdev);
on_each_cpu(mvebu_pic_disable_percpu_irq, pic, 1);
irq_domain_remove(pic->domain);
return 0;
}
