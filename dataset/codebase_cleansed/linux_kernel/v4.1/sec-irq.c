int sec_irq_init(struct sec_pmic_dev *sec_pmic)
{
int ret = 0;
int type = sec_pmic->device_type;
const struct regmap_irq_chip *sec_irq_chip;
if (!sec_pmic->irq) {
dev_warn(sec_pmic->dev,
"No interrupt specified, no interrupts\n");
sec_pmic->irq_base = 0;
return 0;
}
switch (type) {
case S5M8763X:
sec_irq_chip = &s5m8763_irq_chip;
break;
case S5M8767X:
sec_irq_chip = &s5m8767_irq_chip;
break;
case S2MPS11X:
sec_irq_chip = &s2mps11_irq_chip;
break;
case S2MPS13X:
sec_irq_chip = &s2mps13_irq_chip;
break;
case S2MPS14X:
sec_irq_chip = &s2mps14_irq_chip;
break;
case S2MPU02:
sec_irq_chip = &s2mpu02_irq_chip;
break;
default:
dev_err(sec_pmic->dev, "Unknown device type %lu\n",
sec_pmic->device_type);
return -EINVAL;
}
ret = regmap_add_irq_chip(sec_pmic->regmap_pmic, sec_pmic->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
sec_pmic->irq_base, sec_irq_chip,
&sec_pmic->irq_data);
if (ret != 0) {
dev_err(sec_pmic->dev, "Failed to register IRQ chip: %d\n", ret);
return ret;
}
BUILD_BUG_ON(((enum s2mps14_irq)S2MPS11_IRQ_RTCA0) != S2MPS14_IRQ_RTCA0);
return 0;
}
void sec_irq_exit(struct sec_pmic_dev *sec_pmic)
{
regmap_del_irq_chip(sec_pmic->irq, sec_pmic->irq_data);
}
