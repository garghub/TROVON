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
static int tps6586x_regulator_set_slew_rate(struct platform_device *pdev,
int id, struct regulator_init_data *p)
{
struct device *parent = pdev->dev.parent;
struct tps6586x_settings *setting = p->driver_data;
uint8_t reg;
if (setting == NULL)
return 0;
if (!(setting->slew_rate & TPS6586X_SLEW_RATE_SET))
return 0;
switch (id) {
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
static struct tps6586x_platform_data *tps6586x_parse_regulator_dt(
struct platform_device *pdev,
struct of_regulator_match **tps6586x_reg_matches)
{
const unsigned int num = ARRAY_SIZE(tps6586x_matches);
struct device_node *np = pdev->dev.parent->of_node;
struct device_node *regs;
const char *sys_rail = NULL;
unsigned int i;
struct tps6586x_platform_data *pdata;
int err;
regs = of_find_node_by_name(np, "regulators");
if (!regs) {
dev_err(&pdev->dev, "regulator node not found\n");
return NULL;
}
err = of_regulator_match(&pdev->dev, regs, tps6586x_matches, num);
if (err < 0) {
dev_err(&pdev->dev, "Regulator match failed, e %d\n", err);
of_node_put(regs);
return NULL;
}
of_node_put(regs);
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(&pdev->dev, "Memory alloction failed\n");
return NULL;
}
for (i = 0; i < num; i++) {
int id;
if (!tps6586x_matches[i].init_data)
continue;
pdata->reg_init_data[i] = tps6586x_matches[i].init_data;
id = (int)tps6586x_matches[i].driver_data;
if (id == TPS6586X_ID_SYS)
sys_rail = pdata->reg_init_data[i]->constraints.name;
if ((id == TPS6586X_ID_LDO_5) || (id == TPS6586X_ID_LDO_RTC))
pdata->reg_init_data[i]->supply_regulator = sys_rail;
}
*tps6586x_reg_matches = tps6586x_matches;
return pdata;
}
static struct tps6586x_platform_data *tps6586x_parse_regulator_dt(
struct platform_device *pdev,
struct of_regulator_match **tps6586x_reg_matches)
{
*tps6586x_reg_matches = NULL;
return NULL;
}
static int tps6586x_regulator_probe(struct platform_device *pdev)
{
struct tps6586x_regulator *ri = NULL;
struct regulator_config config = { };
struct regulator_dev **rdev;
struct regulator_init_data *reg_data;
struct tps6586x_platform_data *pdata;
struct of_regulator_match *tps6586x_reg_matches = NULL;
int id;
int err;
dev_dbg(&pdev->dev, "Probing regulator\n");
pdata = dev_get_platdata(pdev->dev.parent);
if ((!pdata) && (pdev->dev.parent->of_node))
pdata = tps6586x_parse_regulator_dt(pdev,
&tps6586x_reg_matches);
if (!pdata) {
dev_err(&pdev->dev, "Platform data not available, exiting\n");
return -ENODEV;
}
rdev = devm_kzalloc(&pdev->dev, TPS6586X_ID_MAX_REGULATOR *
sizeof(*rdev), GFP_KERNEL);
if (!rdev) {
dev_err(&pdev->dev, "Mmemory alloc failed\n");
return -ENOMEM;
}
for (id = 0; id < TPS6586X_ID_MAX_REGULATOR; ++id) {
reg_data = pdata->reg_init_data[id];
ri = find_regulator_info(id);
if (!ri) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
err = -EINVAL;
goto fail;
}
err = tps6586x_regulator_preinit(pdev->dev.parent, ri);
if (err) {
dev_err(&pdev->dev,
"regulator %d preinit failed, e %d\n", id, err);
goto fail;
}
config.dev = pdev->dev.parent;
config.init_data = reg_data;
config.driver_data = ri;
if (tps6586x_reg_matches)
config.of_node = tps6586x_reg_matches[id].of_node;
rdev[id] = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev[id])) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
err = PTR_ERR(rdev[id]);
goto fail;
}
if (reg_data) {
err = tps6586x_regulator_set_slew_rate(pdev, id,
reg_data);
if (err < 0) {
dev_err(&pdev->dev,
"Slew rate config failed, e %d\n", err);
regulator_unregister(rdev[id]);
goto fail;
}
}
}
platform_set_drvdata(pdev, rdev);
return 0;
fail:
while (--id >= 0)
regulator_unregister(rdev[id]);
return err;
}
static int tps6586x_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev **rdev = platform_get_drvdata(pdev);
int id = TPS6586X_ID_MAX_REGULATOR;
while (--id >= 0)
regulator_unregister(rdev[id]);
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
