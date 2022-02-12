static bool da9055_register_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9055_REG_STATUS_A:
case DA9055_REG_STATUS_B:
case DA9055_REG_EVENT_A:
case DA9055_REG_EVENT_B:
case DA9055_REG_EVENT_C:
case DA9055_REG_IRQ_MASK_A:
case DA9055_REG_IRQ_MASK_B:
case DA9055_REG_IRQ_MASK_C:
case DA9055_REG_CONTROL_A:
case DA9055_REG_CONTROL_B:
case DA9055_REG_CONTROL_C:
case DA9055_REG_CONTROL_D:
case DA9055_REG_CONTROL_E:
case DA9055_REG_ADC_MAN:
case DA9055_REG_ADC_CONT:
case DA9055_REG_VSYS_MON:
case DA9055_REG_ADC_RES_L:
case DA9055_REG_ADC_RES_H:
case DA9055_REG_VSYS_RES:
case DA9055_REG_ADCIN1_RES:
case DA9055_REG_ADCIN2_RES:
case DA9055_REG_ADCIN3_RES:
case DA9055_REG_COUNT_S:
case DA9055_REG_COUNT_MI:
case DA9055_REG_COUNT_H:
case DA9055_REG_COUNT_D:
case DA9055_REG_COUNT_MO:
case DA9055_REG_COUNT_Y:
case DA9055_REG_ALARM_H:
case DA9055_REG_ALARM_D:
case DA9055_REG_ALARM_MI:
case DA9055_REG_ALARM_MO:
case DA9055_REG_ALARM_Y:
case DA9055_REG_GPIO0_1:
case DA9055_REG_GPIO2:
case DA9055_REG_GPIO_MODE0_2:
case DA9055_REG_BCORE_CONT:
case DA9055_REG_BMEM_CONT:
case DA9055_REG_LDO1_CONT:
case DA9055_REG_LDO2_CONT:
case DA9055_REG_LDO3_CONT:
case DA9055_REG_LDO4_CONT:
case DA9055_REG_LDO5_CONT:
case DA9055_REG_LDO6_CONT:
case DA9055_REG_BUCK_LIM:
case DA9055_REG_BCORE_MODE:
case DA9055_REG_VBCORE_A:
case DA9055_REG_VBMEM_A:
case DA9055_REG_VLDO1_A:
case DA9055_REG_VLDO2_A:
case DA9055_REG_VLDO3_A:
case DA9055_REG_VLDO4_A:
case DA9055_REG_VLDO5_A:
case DA9055_REG_VLDO6_A:
case DA9055_REG_VBCORE_B:
case DA9055_REG_VBMEM_B:
case DA9055_REG_VLDO1_B:
case DA9055_REG_VLDO2_B:
case DA9055_REG_VLDO3_B:
case DA9055_REG_VLDO4_B:
case DA9055_REG_VLDO5_B:
case DA9055_REG_VLDO6_B:
return true;
default:
return false;
}
}
static bool da9055_register_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9055_REG_STATUS_A:
case DA9055_REG_STATUS_B:
case DA9055_REG_EVENT_A:
case DA9055_REG_EVENT_B:
case DA9055_REG_EVENT_C:
case DA9055_REG_IRQ_MASK_A:
case DA9055_REG_IRQ_MASK_B:
case DA9055_REG_IRQ_MASK_C:
case DA9055_REG_CONTROL_A:
case DA9055_REG_CONTROL_B:
case DA9055_REG_CONTROL_C:
case DA9055_REG_CONTROL_D:
case DA9055_REG_CONTROL_E:
case DA9055_REG_ADC_MAN:
case DA9055_REG_ADC_CONT:
case DA9055_REG_VSYS_MON:
case DA9055_REG_ADC_RES_L:
case DA9055_REG_ADC_RES_H:
case DA9055_REG_VSYS_RES:
case DA9055_REG_ADCIN1_RES:
case DA9055_REG_ADCIN2_RES:
case DA9055_REG_ADCIN3_RES:
case DA9055_REG_COUNT_S:
case DA9055_REG_COUNT_MI:
case DA9055_REG_COUNT_H:
case DA9055_REG_COUNT_D:
case DA9055_REG_COUNT_MO:
case DA9055_REG_COUNT_Y:
case DA9055_REG_ALARM_H:
case DA9055_REG_ALARM_D:
case DA9055_REG_ALARM_MI:
case DA9055_REG_ALARM_MO:
case DA9055_REG_ALARM_Y:
case DA9055_REG_GPIO0_1:
case DA9055_REG_GPIO2:
case DA9055_REG_GPIO_MODE0_2:
case DA9055_REG_BCORE_CONT:
case DA9055_REG_BMEM_CONT:
case DA9055_REG_LDO1_CONT:
case DA9055_REG_LDO2_CONT:
case DA9055_REG_LDO3_CONT:
case DA9055_REG_LDO4_CONT:
case DA9055_REG_LDO5_CONT:
case DA9055_REG_LDO6_CONT:
case DA9055_REG_BUCK_LIM:
case DA9055_REG_BCORE_MODE:
case DA9055_REG_VBCORE_A:
case DA9055_REG_VBMEM_A:
case DA9055_REG_VLDO1_A:
case DA9055_REG_VLDO2_A:
case DA9055_REG_VLDO3_A:
case DA9055_REG_VLDO4_A:
case DA9055_REG_VLDO5_A:
case DA9055_REG_VLDO6_A:
case DA9055_REG_VBCORE_B:
case DA9055_REG_VBMEM_B:
case DA9055_REG_VLDO1_B:
case DA9055_REG_VLDO2_B:
case DA9055_REG_VLDO3_B:
case DA9055_REG_VLDO4_B:
case DA9055_REG_VLDO5_B:
case DA9055_REG_VLDO6_B:
return true;
default:
return false;
}
}
static bool da9055_register_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9055_REG_STATUS_A:
case DA9055_REG_STATUS_B:
case DA9055_REG_EVENT_A:
case DA9055_REG_EVENT_B:
case DA9055_REG_EVENT_C:
case DA9055_REG_CONTROL_A:
case DA9055_REG_CONTROL_E:
case DA9055_REG_ADC_MAN:
case DA9055_REG_ADC_RES_L:
case DA9055_REG_ADC_RES_H:
case DA9055_REG_VSYS_RES:
case DA9055_REG_ADCIN1_RES:
case DA9055_REG_ADCIN2_RES:
case DA9055_REG_ADCIN3_RES:
case DA9055_REG_COUNT_S:
case DA9055_REG_COUNT_MI:
case DA9055_REG_COUNT_H:
case DA9055_REG_COUNT_D:
case DA9055_REG_COUNT_MO:
case DA9055_REG_COUNT_Y:
case DA9055_REG_ALARM_MI:
case DA9055_REG_BCORE_CONT:
case DA9055_REG_BMEM_CONT:
case DA9055_REG_LDO1_CONT:
case DA9055_REG_LDO2_CONT:
case DA9055_REG_LDO3_CONT:
case DA9055_REG_LDO4_CONT:
case DA9055_REG_LDO5_CONT:
case DA9055_REG_LDO6_CONT:
return true;
default:
return false;
}
}
int __devinit da9055_device_init(struct da9055 *da9055)
{
struct da9055_pdata *pdata = da9055->dev->platform_data;
int ret;
if (pdata && pdata->init != NULL)
pdata->init(da9055);
if (!pdata || !pdata->irq_base)
da9055->irq_base = -1;
else
da9055->irq_base = pdata->irq_base;
ret = regmap_add_irq_chip(da9055->regmap, da9055->chip_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
da9055->irq_base, &da9055_regmap_irq_chip,
&da9055->irq_data);
if (ret < 0)
return ret;
da9055->irq_base = regmap_irq_chip_get_base(da9055->irq_data);
ret = mfd_add_devices(da9055->dev, -1,
da9055_devs, ARRAY_SIZE(da9055_devs),
NULL, da9055->irq_base, NULL);
if (ret)
goto err;
return 0;
err:
mfd_remove_devices(da9055->dev);
return ret;
}
void __devexit da9055_device_exit(struct da9055 *da9055)
{
regmap_del_irq_chip(da9055->chip_irq, da9055->irq_data);
mfd_remove_devices(da9055->dev);
}
