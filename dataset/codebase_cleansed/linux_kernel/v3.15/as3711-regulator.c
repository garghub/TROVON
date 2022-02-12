static int as3711_set_mode_sd(struct regulator_dev *rdev, unsigned int mode)
{
unsigned int fast_bit = rdev->desc->enable_mask,
low_noise_bit = fast_bit << 4;
u8 val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = fast_bit | low_noise_bit;
break;
case REGULATOR_MODE_NORMAL:
val = low_noise_bit;
break;
case REGULATOR_MODE_IDLE:
val = 0;
break;
default:
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, AS3711_SD_CONTROL_1,
low_noise_bit | fast_bit, val);
}
static unsigned int as3711_get_mode_sd(struct regulator_dev *rdev)
{
unsigned int fast_bit = rdev->desc->enable_mask,
low_noise_bit = fast_bit << 4, mask = fast_bit | low_noise_bit;
unsigned int val;
int ret = regmap_read(rdev->regmap, AS3711_SD_CONTROL_1, &val);
if (ret < 0)
return ret;
if ((val & mask) == mask)
return REGULATOR_MODE_FAST;
if ((val & mask) == low_noise_bit)
return REGULATOR_MODE_NORMAL;
if (!(val & mask))
return REGULATOR_MODE_IDLE;
return -EINVAL;
}
static int as3711_regulator_parse_dt(struct device *dev,
struct device_node **of_node, const int count)
{
struct as3711_regulator_pdata *pdata = dev_get_platdata(dev);
struct device_node *regulators =
of_get_child_by_name(dev->parent->of_node, "regulators");
struct of_regulator_match *match;
int ret, i;
if (!regulators) {
dev_err(dev, "regulator node not found\n");
return -ENODEV;
}
ret = of_regulator_match(dev->parent, regulators,
as3711_regulator_matches, count);
of_node_put(regulators);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n", ret);
return ret;
}
for (i = 0, match = as3711_regulator_matches; i < count; i++, match++)
if (match->of_node) {
pdata->init_data[i] = match->init_data;
of_node[i] = match->of_node;
}
return 0;
}
static int as3711_regulator_probe(struct platform_device *pdev)
{
struct as3711_regulator_pdata *pdata = dev_get_platdata(&pdev->dev);
struct as3711 *as3711 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = {.dev = &pdev->dev,};
struct as3711_regulator *reg = NULL;
struct as3711_regulator *regs;
struct device_node *of_node[AS3711_REGULATOR_NUM] = {};
struct regulator_dev *rdev;
struct as3711_regulator_info *ri;
int ret;
int id;
if (!pdata) {
dev_err(&pdev->dev, "No platform data...\n");
return -ENODEV;
}
if (pdev->dev.parent->of_node) {
ret = as3711_regulator_parse_dt(&pdev->dev, of_node, AS3711_REGULATOR_NUM);
if (ret < 0) {
dev_err(&pdev->dev, "DT parsing failed: %d\n", ret);
return ret;
}
}
regs = devm_kzalloc(&pdev->dev, AS3711_REGULATOR_NUM *
sizeof(struct as3711_regulator), GFP_KERNEL);
if (!regs)
return -ENOMEM;
for (id = 0, ri = as3711_reg_info; id < AS3711_REGULATOR_NUM; ++id, ri++) {
reg = &regs[id];
reg->reg_info = ri;
config.init_data = pdata->init_data[id];
config.driver_data = reg;
config.regmap = as3711->regmap;
config.of_node = of_node[id];
rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
reg->rdev = rdev;
}
platform_set_drvdata(pdev, regs);
return 0;
}
static int __init as3711_regulator_init(void)
{
return platform_driver_register(&as3711_regulator_driver);
}
static void __exit as3711_regulator_exit(void)
{
platform_driver_unregister(&as3711_regulator_driver);
}
