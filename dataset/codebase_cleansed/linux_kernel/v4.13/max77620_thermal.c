static int max77620_thermal_read_temp(void *data, int *temp)
{
struct max77620_therm_info *mtherm = data;
unsigned int val;
int ret;
ret = regmap_read(mtherm->rmap, MAX77620_REG_STATLBT, &val);
if (ret < 0) {
dev_err(mtherm->dev, "Failed to read STATLBT: %d\n", ret);
return ret;
}
if (val & MAX77620_IRQ_TJALRM2_MASK)
*temp = MAX77620_TJALARM2_TEMP;
else if (val & MAX77620_IRQ_TJALRM1_MASK)
*temp = MAX77620_TJALARM1_TEMP;
else
*temp = MAX77620_NORMAL_OPERATING_TEMP;
return 0;
}
static irqreturn_t max77620_thermal_irq(int irq, void *data)
{
struct max77620_therm_info *mtherm = data;
if (irq == mtherm->irq_tjalarm1)
dev_warn(mtherm->dev, "Junction Temp Alarm1(120C) occurred\n");
else if (irq == mtherm->irq_tjalarm2)
dev_crit(mtherm->dev, "Junction Temp Alarm2(140C) occurred\n");
thermal_zone_device_update(mtherm->tz_device,
THERMAL_EVENT_UNSPECIFIED);
return IRQ_HANDLED;
}
static int max77620_thermal_probe(struct platform_device *pdev)
{
struct max77620_therm_info *mtherm;
int ret;
mtherm = devm_kzalloc(&pdev->dev, sizeof(*mtherm), GFP_KERNEL);
if (!mtherm)
return -ENOMEM;
mtherm->irq_tjalarm1 = platform_get_irq(pdev, 0);
mtherm->irq_tjalarm2 = platform_get_irq(pdev, 1);
if ((mtherm->irq_tjalarm1 < 0) || (mtherm->irq_tjalarm2 < 0)) {
dev_err(&pdev->dev, "Alarm irq number not available\n");
return -EINVAL;
}
mtherm->dev = &pdev->dev;
mtherm->rmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!mtherm->rmap) {
dev_err(&pdev->dev, "Failed to get parent regmap\n");
return -ENODEV;
}
device_set_of_node_from_dev(&pdev->dev, pdev->dev.parent);
mtherm->tz_device = devm_thermal_zone_of_sensor_register(&pdev->dev, 0,
mtherm, &max77620_thermal_ops);
if (IS_ERR(mtherm->tz_device)) {
ret = PTR_ERR(mtherm->tz_device);
dev_err(&pdev->dev, "Failed to register thermal zone: %d\n",
ret);
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, mtherm->irq_tjalarm1, NULL,
max77620_thermal_irq,
IRQF_ONESHOT | IRQF_SHARED,
dev_name(&pdev->dev), mtherm);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request irq1: %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, mtherm->irq_tjalarm2, NULL,
max77620_thermal_irq,
IRQF_ONESHOT | IRQF_SHARED,
dev_name(&pdev->dev), mtherm);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request irq2: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, mtherm);
return 0;
}
