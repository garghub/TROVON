static int lm363x_regulator_enable_time(struct regulator_dev *rdev)
{
enum lm363x_regulator_id id = rdev_get_id(rdev);
u8 val, addr, mask;
switch (id) {
case LM3631_LDO_CONT:
addr = LM3631_REG_ENTIME_VCONT;
mask = LM3631_ENTIME_CONT_MASK;
break;
case LM3631_LDO_OREF:
addr = LM3631_REG_ENTIME_VOREF;
mask = LM3631_ENTIME_MASK;
break;
case LM3631_LDO_POS:
addr = LM3631_REG_ENTIME_VPOS;
mask = LM3631_ENTIME_MASK;
break;
case LM3631_LDO_NEG:
addr = LM3631_REG_ENTIME_VNEG;
mask = LM3631_ENTIME_MASK;
break;
default:
return 0;
}
if (regmap_read(rdev->regmap, addr, (unsigned int *)&val))
return -EINVAL;
val = (val & mask) >> LM3631_ENTIME_SHIFT;
if (id == LM3631_LDO_CONT)
return ldo_cont_enable_time[val];
else
return ENABLE_TIME_USEC * val;
}
static int lm363x_regulator_of_get_enable_gpio(struct device_node *np, int id)
{
switch (id) {
case LM3632_LDO_POS:
return of_get_named_gpio(np, "ti,lcm-en1-gpio", 0);
case LM3632_LDO_NEG:
return of_get_named_gpio(np, "ti,lcm-en2-gpio", 0);
default:
return -EINVAL;
}
}
static int lm363x_regulator_probe(struct platform_device *pdev)
{
struct ti_lmu *lmu = dev_get_drvdata(pdev->dev.parent);
struct regmap *regmap = lmu->regmap;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
struct device *dev = &pdev->dev;
int id = pdev->id;
int ret, ena_gpio;
cfg.dev = dev;
cfg.regmap = regmap;
ena_gpio = lm363x_regulator_of_get_enable_gpio(dev->of_node, id);
if (gpio_is_valid(ena_gpio)) {
cfg.ena_gpio = ena_gpio;
cfg.ena_gpio_flags = GPIOF_OUT_INIT_LOW;
ret = regmap_update_bits(regmap, LM3632_REG_BIAS_CONFIG,
LM3632_EXT_EN_MASK,
LM3632_EXT_EN_MASK);
if (ret) {
dev_err(dev, "External pin err: %d\n", ret);
return ret;
}
}
rdev = devm_regulator_register(dev, &lm363x_regulator_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(dev, "[%d] regulator register err: %d\n", id, ret);
return ret;
}
return 0;
}
