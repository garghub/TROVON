static inline struct device *to_tps6586x_dev(struct regulator_dev *rdev)
{
return rdev_get_dev(rdev)->parent;
}
static int tps6586x_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct tps6586x_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps6586x_dev(rdev);
int ret, val, rid = rdev_get_id(rdev);
uint8_t mask;
val = selector << (ffs(rdev->desc->vsel_mask) - 1);
mask = rdev->desc->vsel_mask;
ret = tps6586x_update(parent, rdev->desc->vsel_reg, val, mask);
if (ret)
return ret;
switch (rid) {
case TPS6586X_ID_LDO_2:
case TPS6586X_ID_LDO_4:
case TPS6586X_ID_SM_0:
case TPS6586X_ID_SM_1:
ret = tps6586x_set_bits(parent, ri->go_reg, 1 << ri->go_bit);
break;
}
return ret;
}
static inline int tps6586x_regulator_preinit(struct device *parent,
struct tps6586x_regulator *ri)
{
uint8_t val1, val2;
int ret;
if (ri->enable_reg[0] == ri->enable_reg[1] &&
ri->enable_bit[0] == ri->enable_bit[1])
return 0;
ret = tps6586x_read(parent, ri->enable_reg[0], &val1);
if (ret)
return ret;
ret = tps6586x_read(parent, ri->enable_reg[1], &val2);
if (ret)
return ret;
if (!(val2 & (1 << ri->enable_bit[1])))
return 0;
if (!(val1 & (1 << ri->enable_bit[0]))) {
ret = tps6586x_set_bits(parent, ri->enable_reg[0],
1 << ri->enable_bit[0]);
if (ret)
return ret;
}
return tps6586x_clr_bits(parent, ri->enable_reg[1],
1 << ri->enable_bit[1]);
}
static int tps6586x_regulator_set_slew_rate(struct platform_device *pdev)
{
struct device *parent = pdev->dev.parent;
struct regulator_init_data *p = pdev->dev.platform_data;
struct tps6586x_settings *setting = p->driver_data;
uint8_t reg;
if (setting == NULL)
return 0;
if (!(setting->slew_rate & TPS6586X_SLEW_RATE_SET))
return 0;
switch (pdev->id) {
case TPS6586X_ID_SM_0:
reg = TPS6586X_SM0SL;
break;
case TPS6586X_ID_SM_1:
reg = TPS6586X_SM1SL;
break;
default:
dev_warn(&pdev->dev, "Only SM0/SM1 can set slew rate\n");
return -EINVAL;
}
return tps6586x_write(parent, reg,
setting->slew_rate & TPS6586X_SLEW_RATE_MASK);
}
static inline struct tps6586x_regulator *find_regulator_info(int id)
{
struct tps6586x_regulator *ri;
int i;
for (i = 0; i < ARRAY_SIZE(tps6586x_regulator); i++) {
ri = &tps6586x_regulator[i];
if (ri->desc.id == id)
return ri;
}
return NULL;
}
static int __devinit tps6586x_regulator_probe(struct platform_device *pdev)
{
struct tps6586x_regulator *ri = NULL;
struct regulator_config config = { };
struct regulator_dev *rdev;
int id = pdev->id;
int err;
dev_dbg(&pdev->dev, "Probing regulator %d\n", id);
ri = find_regulator_info(id);
if (ri == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
err = tps6586x_regulator_preinit(pdev->dev.parent, ri);
if (err)
return err;
config.dev = pdev->dev.parent;
config.of_node = pdev->dev.of_node;
config.init_data = pdev->dev.platform_data;
config.driver_data = ri;
rdev = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return tps6586x_regulator_set_slew_rate(pdev);
}
static int __devexit tps6586x_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init tps6586x_regulator_init(void)
{
return platform_driver_register(&tps6586x_regulator_driver);
}
static void __exit tps6586x_regulator_exit(void)
{
platform_driver_unregister(&tps6586x_regulator_driver);
}
