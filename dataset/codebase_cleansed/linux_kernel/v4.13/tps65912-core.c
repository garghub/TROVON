int tps65912_device_init(struct tps65912 *tps)
{
int ret;
ret = regmap_add_irq_chip(tps->regmap, tps->irq, IRQF_ONESHOT, 0,
&tps65912_irq_chip, &tps->irq_data);
if (ret)
return ret;
ret = mfd_add_devices(tps->dev, PLATFORM_DEVID_AUTO, tps65912_cells,
ARRAY_SIZE(tps65912_cells), NULL, 0,
regmap_irq_get_domain(tps->irq_data));
if (ret) {
regmap_del_irq_chip(tps->irq, tps->irq_data);
return ret;
}
return 0;
}
int tps65912_device_exit(struct tps65912 *tps)
{
regmap_del_irq_chip(tps->irq, tps->irq_data);
return 0;
}
