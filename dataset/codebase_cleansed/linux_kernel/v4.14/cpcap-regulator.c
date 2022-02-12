static int cpcap_regulator_enable(struct regulator_dev *rdev)
{
struct cpcap_regulator *regulator = rdev_get_drvdata(rdev);
int error, ignore;
error = regulator_enable_regmap(rdev);
if (error)
return error;
if (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC) {
error = regmap_update_bits(rdev->regmap, regulator->assign_reg,
regulator->assign_mask,
regulator->assign_mask);
if (error)
ignore = regulator_disable_regmap(rdev);
}
return error;
}
static int cpcap_regulator_disable(struct regulator_dev *rdev)
{
struct cpcap_regulator *regulator = rdev_get_drvdata(rdev);
int error, ignore;
if (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC) {
error = regmap_update_bits(rdev->regmap, regulator->assign_reg,
regulator->assign_mask, 0);
if (error)
return error;
}
error = regulator_disable_regmap(rdev);
if (error && (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC)) {
ignore = regmap_update_bits(rdev->regmap, regulator->assign_reg,
regulator->assign_mask,
regulator->assign_mask);
}
return error;
}
static unsigned int cpcap_map_mode(unsigned int mode)
{
switch (mode) {
case CPCAP_BIT_AUDIO_NORMAL_MODE:
return REGULATOR_MODE_NORMAL;
case CPCAP_BIT_AUDIO_LOW_PWR:
return REGULATOR_MODE_STANDBY;
default:
return -EINVAL;
}
}
static unsigned int cpcap_regulator_get_mode(struct regulator_dev *rdev)
{
int value;
regmap_read(rdev->regmap, rdev->desc->enable_reg, &value);
if (value & CPCAP_BIT_AUDIO_LOW_PWR)
return REGULATOR_MODE_STANDBY;
return REGULATOR_MODE_NORMAL;
}
static int cpcap_regulator_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
int value;
switch (mode) {
case REGULATOR_MODE_NORMAL:
value = CPCAP_BIT_AUDIO_NORMAL_MODE;
break;
case REGULATOR_MODE_STANDBY:
value = CPCAP_BIT_AUDIO_LOW_PWR;
break;
default:
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
CPCAP_BIT_AUDIO_LOW_PWR, value);
}
static int cpcap_regulator_probe(struct platform_device *pdev)
{
struct cpcap_ddata *ddata;
const struct of_device_id *match;
struct regulator_config config;
struct regulator_init_data init_data;
int i;
match = of_match_device(of_match_ptr(cpcap_regulator_id_table),
&pdev->dev);
if (!match)
return -EINVAL;
if (!match->data) {
dev_err(&pdev->dev, "no configuration data found\n");
return -ENODEV;
}
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
ddata->reg = dev_get_regmap(pdev->dev.parent, NULL);
if (!ddata->reg)
return -ENODEV;
ddata->dev = &pdev->dev;
ddata->soc = match->data;
platform_set_drvdata(pdev, ddata);
memset(&config, 0, sizeof(config));
memset(&init_data, 0, sizeof(init_data));
config.dev = &pdev->dev;
config.regmap = ddata->reg;
config.init_data = &init_data;
for (i = 0; i < CPCAP_NR_REGULATORS; i++) {
const struct cpcap_regulator *regulator = &ddata->soc[i];
struct regulator_dev *rdev;
if (!regulator->rdesc.name)
break;
if (regulator->rdesc.volt_table == unknown_val_tbl)
continue;
config.driver_data = (void *)regulator;
rdev = devm_regulator_register(&pdev->dev,
&regulator->rdesc,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
regulator->rdesc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
