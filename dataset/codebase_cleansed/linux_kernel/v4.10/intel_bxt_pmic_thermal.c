static irqreturn_t pmic_thermal_irq_handler(int irq, void *data)
{
struct platform_device *pdev = data;
struct thermal_zone_device *tzd;
struct pmic_thermal_data *td;
struct intel_soc_pmic *pmic;
struct regmap *regmap;
u8 reg_val, mask, irq_stat, trip;
u16 reg, evt_stat_reg;
int i, j, ret;
pmic = dev_get_drvdata(pdev->dev.parent);
regmap = pmic->regmap;
td = (struct pmic_thermal_data *)
platform_get_device_id(pdev)->driver_data;
for (i = 0; i < td->num_maps; i++) {
for (j = 0; j < td->maps[i].num_trips; j++) {
reg = td->maps[i].trip_config[j].irq_reg;
mask = td->maps[i].trip_config[j].irq_mask;
if (regmap_read(regmap, reg, &ret))
return IRQ_HANDLED;
reg_val = (u8)ret;
irq_stat = ((u8)ret & mask);
if (!irq_stat)
continue;
evt_stat_reg = td->maps[i].trip_config[j].evt_stat;
if (regmap_read(regmap, evt_stat_reg, &ret))
return IRQ_HANDLED;
trip = td->maps[i].trip_config[j].trip_num;
tzd = thermal_zone_get_zone_by_name(td->maps[i].handle);
if (!IS_ERR(tzd))
thermal_zone_device_update(tzd,
THERMAL_EVENT_UNSPECIFIED);
regmap_write(regmap, reg, reg_val & mask);
}
}
return IRQ_HANDLED;
}
static int pmic_thermal_probe(struct platform_device *pdev)
{
struct regmap_irq_chip_data *regmap_irq_chip;
struct pmic_thermal_data *thermal_data;
int ret, irq, virq, i, j, pmic_irq_count;
struct intel_soc_pmic *pmic;
struct regmap *regmap;
struct device *dev;
u16 reg;
u8 mask;
dev = &pdev->dev;
pmic = dev_get_drvdata(pdev->dev.parent);
if (!pmic) {
dev_err(dev, "Failed to get struct intel_soc_pmic pointer\n");
return -ENODEV;
}
thermal_data = (struct pmic_thermal_data *)
platform_get_device_id(pdev)->driver_data;
if (!thermal_data) {
dev_err(dev, "No thermal data initialized!!\n");
return -ENODEV;
}
regmap = pmic->regmap;
regmap_irq_chip = pmic->irq_chip_data_level2;
pmic_irq_count = 0;
while ((irq = platform_get_irq(pdev, pmic_irq_count)) != -ENXIO) {
virq = regmap_irq_get_virq(regmap_irq_chip, irq);
if (virq < 0) {
dev_err(dev, "failed to get virq by irq %d\n", irq);
return virq;
}
ret = devm_request_threaded_irq(&pdev->dev, virq,
NULL, pmic_thermal_irq_handler,
IRQF_ONESHOT, "pmic_thermal", pdev);
if (ret) {
dev_err(dev, "request irq(%d) failed: %d\n", virq, ret);
return ret;
}
pmic_irq_count++;
}
for (i = 0; i < thermal_data->num_maps; i++) {
for (j = 0; j < thermal_data->maps[i].num_trips; j++) {
reg = thermal_data->maps[i].trip_config[j].irq_en;
mask = thermal_data->maps[i].trip_config[j].irq_en_mask;
ret = regmap_update_bits(regmap, reg, mask, 0x00);
if (ret)
return ret;
}
}
return 0;
}
