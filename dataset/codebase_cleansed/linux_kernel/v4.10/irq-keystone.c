static inline u32 keystone_irq_readl(struct keystone_irq_device *kirq)
{
int ret;
u32 val = 0;
ret = regmap_read(kirq->devctrl_regs, kirq->devctrl_offset, &val);
if (ret < 0)
dev_dbg(kirq->dev, "irq read failed ret(%d)\n", ret);
return val;
}
static inline void
keystone_irq_writel(struct keystone_irq_device *kirq, u32 value)
{
int ret;
ret = regmap_write(kirq->devctrl_regs, kirq->devctrl_offset, value);
if (ret < 0)
dev_dbg(kirq->dev, "irq write failed ret(%d)\n", ret);
}
static void keystone_irq_setmask(struct irq_data *d)
{
struct keystone_irq_device *kirq = irq_data_get_irq_chip_data(d);
kirq->mask |= BIT(d->hwirq);
dev_dbg(kirq->dev, "mask %lu [%x]\n", d->hwirq, kirq->mask);
}
static void keystone_irq_unmask(struct irq_data *d)
{
struct keystone_irq_device *kirq = irq_data_get_irq_chip_data(d);
kirq->mask &= ~BIT(d->hwirq);
dev_dbg(kirq->dev, "unmask %lu [%x]\n", d->hwirq, kirq->mask);
}
static void keystone_irq_ack(struct irq_data *d)
{
}
static irqreturn_t keystone_irq_handler(int irq, void *keystone_irq)
{
struct keystone_irq_device *kirq = keystone_irq;
unsigned long wa_lock_flags;
unsigned long pending;
int src, virq;
dev_dbg(kirq->dev, "start irq %d\n", irq);
pending = keystone_irq_readl(kirq);
keystone_irq_writel(kirq, pending);
dev_dbg(kirq->dev, "pending 0x%lx, mask 0x%x\n", pending, kirq->mask);
pending = (pending >> BIT_OFS) & ~kirq->mask;
dev_dbg(kirq->dev, "pending after mask 0x%lx\n", pending);
for (src = 0; src < KEYSTONE_N_IRQ; src++) {
if (BIT(src) & pending) {
virq = irq_find_mapping(kirq->irqd, src);
dev_dbg(kirq->dev, "dispatch bit %d, virq %d\n",
src, virq);
if (!virq)
dev_warn(kirq->dev, "spurious irq detected hwirq %d, virq %d\n",
src, virq);
raw_spin_lock_irqsave(&kirq->wa_lock, wa_lock_flags);
generic_handle_irq(virq);
raw_spin_unlock_irqrestore(&kirq->wa_lock,
wa_lock_flags);
}
}
dev_dbg(kirq->dev, "end irq %d\n", irq);
return IRQ_HANDLED;
}
static int keystone_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct keystone_irq_device *kirq = h->host_data;
irq_set_chip_data(virq, kirq);
irq_set_chip_and_handler(virq, &kirq->chip, handle_level_irq);
irq_set_probe(virq);
return 0;
}
static int keystone_irq_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct keystone_irq_device *kirq;
int ret;
if (np == NULL)
return -EINVAL;
kirq = devm_kzalloc(dev, sizeof(*kirq), GFP_KERNEL);
if (!kirq)
return -ENOMEM;
kirq->devctrl_regs =
syscon_regmap_lookup_by_phandle(np, "ti,syscon-dev");
if (IS_ERR(kirq->devctrl_regs))
return PTR_ERR(kirq->devctrl_regs);
ret = of_property_read_u32_index(np, "ti,syscon-dev", 1,
&kirq->devctrl_offset);
if (ret) {
dev_err(dev, "couldn't read the devctrl_offset offset!\n");
return ret;
}
kirq->irq = platform_get_irq(pdev, 0);
if (kirq->irq < 0) {
dev_err(dev, "no irq resource %d\n", kirq->irq);
return kirq->irq;
}
kirq->dev = dev;
kirq->mask = ~0x0;
kirq->chip.name = "keystone-irq";
kirq->chip.irq_ack = keystone_irq_ack;
kirq->chip.irq_mask = keystone_irq_setmask;
kirq->chip.irq_unmask = keystone_irq_unmask;
kirq->irqd = irq_domain_add_linear(np, KEYSTONE_N_IRQ,
&keystone_irq_ops, kirq);
if (!kirq->irqd) {
dev_err(dev, "IRQ domain registration failed\n");
return -ENODEV;
}
raw_spin_lock_init(&kirq->wa_lock);
platform_set_drvdata(pdev, kirq);
ret = request_irq(kirq->irq, keystone_irq_handler,
0, dev_name(dev), kirq);
if (ret) {
irq_domain_remove(kirq->irqd);
return ret;
}
keystone_irq_writel(kirq, ~0x0);
dev_info(dev, "irqchip registered, nr_irqs %u\n", KEYSTONE_N_IRQ);
return 0;
}
static int keystone_irq_remove(struct platform_device *pdev)
{
struct keystone_irq_device *kirq = platform_get_drvdata(pdev);
int hwirq;
free_irq(kirq->irq, kirq);
for (hwirq = 0; hwirq < KEYSTONE_N_IRQ; hwirq++)
irq_dispose_mapping(irq_find_mapping(kirq->irqd, hwirq));
irq_domain_remove(kirq->irqd);
return 0;
}
