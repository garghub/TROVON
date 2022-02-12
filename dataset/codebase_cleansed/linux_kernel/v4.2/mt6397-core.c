static void mt6397_irq_lock(struct irq_data *data)
{
struct mt6397_chip *mt6397 = irq_get_chip_data(data->irq);
mutex_lock(&mt6397->irqlock);
}
static void mt6397_irq_sync_unlock(struct irq_data *data)
{
struct mt6397_chip *mt6397 = irq_get_chip_data(data->irq);
regmap_write(mt6397->regmap, MT6397_INT_CON0, mt6397->irq_masks_cur[0]);
regmap_write(mt6397->regmap, MT6397_INT_CON1, mt6397->irq_masks_cur[1]);
mutex_unlock(&mt6397->irqlock);
}
static void mt6397_irq_disable(struct irq_data *data)
{
struct mt6397_chip *mt6397 = irq_get_chip_data(data->irq);
int shift = data->hwirq & 0xf;
int reg = data->hwirq >> 4;
mt6397->irq_masks_cur[reg] &= ~BIT(shift);
}
static void mt6397_irq_enable(struct irq_data *data)
{
struct mt6397_chip *mt6397 = irq_get_chip_data(data->irq);
int shift = data->hwirq & 0xf;
int reg = data->hwirq >> 4;
mt6397->irq_masks_cur[reg] |= BIT(shift);
}
static void mt6397_irq_handle_reg(struct mt6397_chip *mt6397, int reg,
int irqbase)
{
unsigned int status;
int i, irq, ret;
ret = regmap_read(mt6397->regmap, reg, &status);
if (ret) {
dev_err(mt6397->dev, "Failed to read irq status: %d\n", ret);
return;
}
for (i = 0; i < 16; i++) {
if (status & BIT(i)) {
irq = irq_find_mapping(mt6397->irq_domain, irqbase + i);
if (irq)
handle_nested_irq(irq);
}
}
regmap_write(mt6397->regmap, reg, status);
}
static irqreturn_t mt6397_irq_thread(int irq, void *data)
{
struct mt6397_chip *mt6397 = data;
mt6397_irq_handle_reg(mt6397, MT6397_INT_STATUS0, 0);
mt6397_irq_handle_reg(mt6397, MT6397_INT_STATUS1, 16);
return IRQ_HANDLED;
}
static int mt6397_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
struct mt6397_chip *mt6397 = d->host_data;
irq_set_chip_data(irq, mt6397);
irq_set_chip_and_handler(irq, &mt6397_irq_chip, handle_level_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
return 0;
}
static int mt6397_irq_init(struct mt6397_chip *mt6397)
{
int ret;
mutex_init(&mt6397->irqlock);
regmap_write(mt6397->regmap, MT6397_INT_CON0, 0x0);
regmap_write(mt6397->regmap, MT6397_INT_CON1, 0x0);
mt6397->irq_domain = irq_domain_add_linear(mt6397->dev->of_node,
MT6397_IRQ_NR, &mt6397_irq_domain_ops, mt6397);
if (!mt6397->irq_domain) {
dev_err(mt6397->dev, "could not create irq domain\n");
return -ENOMEM;
}
ret = devm_request_threaded_irq(mt6397->dev, mt6397->irq, NULL,
mt6397_irq_thread, IRQF_ONESHOT, "mt6397-pmic", mt6397);
if (ret) {
dev_err(mt6397->dev, "failed to register irq=%d; err: %d\n",
mt6397->irq, ret);
return ret;
}
return 0;
}
static int mt6397_probe(struct platform_device *pdev)
{
int ret;
struct mt6397_chip *mt6397;
mt6397 = devm_kzalloc(&pdev->dev, sizeof(*mt6397), GFP_KERNEL);
if (!mt6397)
return -ENOMEM;
mt6397->dev = &pdev->dev;
mt6397->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!mt6397->regmap)
return -ENODEV;
platform_set_drvdata(pdev, mt6397);
mt6397->irq = platform_get_irq(pdev, 0);
if (mt6397->irq > 0) {
ret = mt6397_irq_init(mt6397);
if (ret)
return ret;
}
ret = mfd_add_devices(&pdev->dev, -1, mt6397_devs,
ARRAY_SIZE(mt6397_devs), NULL, 0, NULL);
if (ret)
dev_err(&pdev->dev, "failed to add child devices: %d\n", ret);
return ret;
}
static int mt6397_remove(struct platform_device *pdev)
{
mfd_remove_devices(&pdev->dev);
return 0;
}
