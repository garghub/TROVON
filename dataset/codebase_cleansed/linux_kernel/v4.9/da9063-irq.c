int da9063_irq_init(struct da9063 *da9063)
{
int ret;
if (!da9063->chip_irq) {
dev_err(da9063->dev, "No IRQ configured\n");
return -EINVAL;
}
ret = regmap_add_irq_chip(da9063->regmap, da9063->chip_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT | IRQF_SHARED,
da9063->irq_base, &da9063_irq_chip,
&da9063->regmap_irq);
if (ret) {
dev_err(da9063->dev, "Failed to reguest IRQ %d: %d\n",
da9063->chip_irq, ret);
return ret;
}
return 0;
}
void da9063_irq_exit(struct da9063 *da9063)
{
regmap_del_irq_chip(da9063->chip_irq, da9063->regmap_irq);
}
