static int intel_soc_pmic_find_gpio_irq(struct device *dev)
{
struct gpio_desc *desc;
int irq;
desc = devm_gpiod_get_index(dev, "intel_soc_pmic", 0, GPIOD_IN);
if (IS_ERR(desc))
return PTR_ERR(desc);
irq = gpiod_to_irq(desc);
if (irq < 0)
dev_warn(dev, "Can't get irq: %d\n", irq);
return irq;
}
static int intel_soc_pmic_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct device *dev = &i2c->dev;
const struct acpi_device_id *id;
struct intel_soc_pmic_config *config;
struct intel_soc_pmic *pmic;
int ret;
int irq;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id || !id->driver_data)
return -ENODEV;
config = (struct intel_soc_pmic_config *)id->driver_data;
pmic = devm_kzalloc(dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
dev_set_drvdata(dev, pmic);
pmic->regmap = devm_regmap_init_i2c(i2c, config->regmap_config);
irq = intel_soc_pmic_find_gpio_irq(dev);
pmic->irq = (irq < 0) ? i2c->irq : irq;
ret = regmap_add_irq_chip(pmic->regmap, pmic->irq,
config->irq_flags | IRQF_ONESHOT,
0, config->irq_chip,
&pmic->irq_chip_data);
if (ret)
return ret;
ret = enable_irq_wake(pmic->irq);
if (ret)
dev_warn(dev, "Can't enable IRQ as wake source: %d\n", ret);
ret = mfd_add_devices(dev, -1, config->cell_dev,
config->n_cell_devs, NULL, 0,
regmap_irq_get_domain(pmic->irq_chip_data));
if (ret)
goto err_del_irq_chip;
return 0;
err_del_irq_chip:
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data);
return ret;
}
static int intel_soc_pmic_i2c_remove(struct i2c_client *i2c)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(&i2c->dev);
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data);
mfd_remove_devices(&i2c->dev);
return 0;
}
static void intel_soc_pmic_shutdown(struct i2c_client *i2c)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(&i2c->dev);
disable_irq(pmic->irq);
return;
}
static int intel_soc_pmic_suspend(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
disable_irq(pmic->irq);
return 0;
}
static int intel_soc_pmic_resume(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
enable_irq(pmic->irq);
return 0;
}
