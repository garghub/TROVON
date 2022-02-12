static int da9052_map_irq(struct da9052 *da9052, int irq)
{
return regmap_irq_get_virq(da9052->irq_data, irq);
}
int da9052_enable_irq(struct da9052 *da9052, int irq)
{
irq = da9052_map_irq(da9052, irq);
if (irq < 0)
return irq;
enable_irq(irq);
return 0;
}
int da9052_disable_irq(struct da9052 *da9052, int irq)
{
irq = da9052_map_irq(da9052, irq);
if (irq < 0)
return irq;
disable_irq(irq);
return 0;
}
int da9052_disable_irq_nosync(struct da9052 *da9052, int irq)
{
irq = da9052_map_irq(da9052, irq);
if (irq < 0)
return irq;
disable_irq_nosync(irq);
return 0;
}
int da9052_request_irq(struct da9052 *da9052, int irq, char *name,
irq_handler_t handler, void *data)
{
irq = da9052_map_irq(da9052, irq);
if (irq < 0)
return irq;
return request_threaded_irq(irq, NULL, handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
name, data);
}
void da9052_free_irq(struct da9052 *da9052, int irq, void *data)
{
irq = da9052_map_irq(da9052, irq);
if (irq < 0)
return;
free_irq(irq, data);
}
static irqreturn_t da9052_auxadc_irq(int irq, void *irq_data)
{
struct da9052 *da9052 = irq_data;
complete(&da9052->done);
return IRQ_HANDLED;
}
int da9052_irq_init(struct da9052 *da9052)
{
int ret;
ret = regmap_add_irq_chip(da9052->regmap, da9052->chip_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
-1, &da9052_regmap_irq_chip,
&da9052->irq_data);
if (ret < 0) {
dev_err(da9052->dev, "regmap_add_irq_chip failed: %d\n", ret);
goto regmap_err;
}
ret = da9052_request_irq(da9052, DA9052_IRQ_ADC_EOM, "adc-irq",
da9052_auxadc_irq, da9052);
if (ret != 0) {
dev_err(da9052->dev, "DA9052_IRQ_ADC_EOM failed: %d\n", ret);
goto request_irq_err;
}
return 0;
request_irq_err:
regmap_del_irq_chip(da9052->chip_irq, da9052->irq_data);
regmap_err:
return ret;
}
int da9052_irq_exit(struct da9052 *da9052)
{
da9052_free_irq(da9052, DA9052_IRQ_ADC_EOM , da9052);
regmap_del_irq_chip(da9052->chip_irq, da9052->irq_data);
return 0;
}
