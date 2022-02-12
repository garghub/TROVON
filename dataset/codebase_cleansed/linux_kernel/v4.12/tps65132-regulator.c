static int tps65132_regulator_enable(struct regulator_dev *rdev)
{
struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];
int ret;
if (!IS_ERR(rpdata->en_gpiod)) {
gpiod_set_value_cansleep(rpdata->en_gpiod, 1);
rpdata->ena_gpio_state = 1;
}
if (rdev->constraints->active_discharge ==
REGULATOR_ACTIVE_DISCHARGE_DISABLE) {
ret = regulator_set_active_discharge_regmap(rdev, false);
if (ret < 0) {
dev_err(tps->dev, "Failed to disable active discharge: %d\n",
ret);
return ret;
}
}
return 0;
}
static int tps65132_regulator_disable(struct regulator_dev *rdev)
{
struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];
if (!IS_ERR(rpdata->en_gpiod)) {
gpiod_set_value_cansleep(rpdata->en_gpiod, 0);
rpdata->ena_gpio_state = 0;
}
if (!IS_ERR(rpdata->act_dis_gpiod)) {
gpiod_set_value_cansleep(rpdata->act_dis_gpiod, 1);
usleep_range(rpdata->act_dis_time_us, rpdata->act_dis_time_us +
TPS65132_ACT_DIS_TIME_SLACK);
gpiod_set_value_cansleep(rpdata->act_dis_gpiod, 0);
}
return 0;
}
static int tps65132_regulator_is_enabled(struct regulator_dev *rdev)
{
struct tps65132_regulator *tps = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[id];
if (!IS_ERR(rpdata->en_gpiod))
return rpdata->ena_gpio_state;
return 1;
}
static int tps65132_of_parse_cb(struct device_node *np,
const struct regulator_desc *desc,
struct regulator_config *config)
{
struct tps65132_regulator *tps = config->driver_data;
struct tps65132_reg_pdata *rpdata = &tps->reg_pdata[desc->id];
int ret;
rpdata->en_gpiod = devm_fwnode_get_index_gpiod_from_child(tps->dev,
"enable", 0, &np->fwnode, 0, "enable");
if (IS_ERR(rpdata->en_gpiod)) {
ret = PTR_ERR(rpdata->en_gpiod);
if (ret == -EPROBE_DEFER)
return ret;
return 0;
}
rpdata->act_dis_gpiod = devm_fwnode_get_index_gpiod_from_child(
tps->dev, "active-discharge", 0,
&np->fwnode, 0, "active-discharge");
if (IS_ERR(rpdata->act_dis_gpiod)) {
ret = PTR_ERR(rpdata->act_dis_gpiod);
if (ret == -EPROBE_DEFER)
return ret;
return 0;
}
ret = of_property_read_u32(np, "ti,active-discharge-time-us",
&rpdata->act_dis_time_us);
if (ret < 0) {
dev_err(tps->dev, "Failed to read active discharge time:%d\n",
ret);
return ret;
}
return 0;
}
static int tps65132_probe(struct i2c_client *client,
const struct i2c_device_id *client_id)
{
struct device *dev = &client->dev;
struct tps65132_regulator *tps;
struct regulator_config config = { };
int id;
int ret;
tps = devm_kzalloc(dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
tps->rmap = devm_regmap_init_i2c(client, &tps65132_regmap_config);
if (IS_ERR(tps->rmap)) {
ret = PTR_ERR(tps->rmap);
dev_err(dev, "regmap init failed: %d\n", ret);
return ret;
}
i2c_set_clientdata(client, tps);
tps->dev = dev;
for (id = 0; id < TPS65132_MAX_REGULATORS; ++id) {
tps->rdesc[id] = &tps_regs_desc[id];
config.regmap = tps->rmap;
config.dev = dev;
config.driver_data = tps;
tps->rdev[id] = devm_regulator_register(dev,
tps->rdesc[id], &config);
if (IS_ERR(tps->rdev[id])) {
ret = PTR_ERR(tps->rdev[id]);
dev_err(dev, "regulator %s register failed: %d\n",
tps->rdesc[id]->name, ret);
return ret;
}
}
return 0;
}
