int sec_irq_init(struct sec_pmic_dev *sec_pmic)
{
int ret = 0;
int type = sec_pmic->device_type;
if (!sec_pmic->irq) {
dev_warn(sec_pmic->dev,
"No interrupt specified, no interrupts\n");
sec_pmic->irq_base = 0;
return 0;
}
switch (type) {
case S5M8763X:
ret = regmap_add_irq_chip(sec_pmic->regmap_pmic, sec_pmic->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
sec_pmic->irq_base, &s5m8763_irq_chip,
&sec_pmic->irq_data);
break;
case S5M8767X:
ret = regmap_add_irq_chip(sec_pmic->regmap_pmic, sec_pmic->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
sec_pmic->irq_base, &s5m8767_irq_chip,
&sec_pmic->irq_data);
break;
case S2MPS11X:
ret = regmap_add_irq_chip(sec_pmic->regmap_pmic, sec_pmic->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
sec_pmic->irq_base, &s2mps11_irq_chip,
&sec_pmic->irq_data);
break;
default:
dev_err(sec_pmic->dev, "Unknown device type %d\n",
sec_pmic->device_type);
return -EINVAL;
}
if (ret != 0) {
dev_err(sec_pmic->dev, "Failed to register IRQ chip: %d\n", ret);
return ret;
}
return 0;
}
void sec_irq_exit(struct sec_pmic_dev *sec_pmic)
{
regmap_del_irq_chip(sec_pmic->irq, sec_pmic->irq_data);
}
