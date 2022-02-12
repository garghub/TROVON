static int st_syscfg_power_ctrl(struct st_thermal_sensor *sensor,
enum st_thermal_power_state power_state)
{
return regmap_field_write(sensor->pwr, power_state);
}
static int st_syscfg_alloc_regfields(struct st_thermal_sensor *sensor)
{
struct device *dev = sensor->dev;
sensor->pwr = devm_regmap_field_alloc(dev, sensor->regmap,
sensor->cdata->reg_fields[TEMP_PWR]);
if (IS_ERR(sensor->pwr)) {
dev_err(dev, "failed to alloc syscfg regfields\n");
return PTR_ERR(sensor->pwr);
}
return 0;
}
static int st_syscfg_regmap_init(struct st_thermal_sensor *sensor)
{
sensor->regmap =
syscon_regmap_lookup_by_compatible(sensor->cdata->sys_compat);
if (IS_ERR(sensor->regmap)) {
dev_err(sensor->dev, "failed to find syscfg regmap\n");
return PTR_ERR(sensor->regmap);
}
return 0;
}
int st_syscfg_probe(struct platform_device *pdev)
{
return st_thermal_register(pdev, st_syscfg_thermal_of_match);
}
int st_syscfg_remove(struct platform_device *pdev)
{
return st_thermal_unregister(pdev);
}
