static int act8865_pdata_from_dt(struct device *dev,
struct device_node **of_node,
struct act8865_platform_data *pdata)
{
int matched, i;
struct device_node *np;
struct act8865_regulator_data *regulator;
np = of_get_child_by_name(dev->of_node, "regulators");
if (!np) {
dev_err(dev, "missing 'regulators' subnode in DT\n");
return -EINVAL;
}
matched = of_regulator_match(dev, np,
act8865_matches, ARRAY_SIZE(act8865_matches));
of_node_put(np);
if (matched <= 0)
return matched;
pdata->regulators = devm_kzalloc(dev,
sizeof(struct act8865_regulator_data) *
ARRAY_SIZE(act8865_matches), GFP_KERNEL);
if (!pdata->regulators)
return -ENOMEM;
pdata->num_regulators = matched;
regulator = pdata->regulators;
for (i = 0; i < ARRAY_SIZE(act8865_matches); i++) {
regulator->id = i;
regulator->name = act8865_matches[i].name;
regulator->platform_data = act8865_matches[i].init_data;
of_node[i] = act8865_matches[i].of_node;
regulator++;
}
return 0;
}
static inline int act8865_pdata_from_dt(struct device *dev,
struct device_node **of_node,
struct act8865_platform_data *pdata)
{
return 0;
}
static int act8865_pmic_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct regulator_dev *rdev;
struct device *dev = &client->dev;
struct act8865_platform_data *pdata = dev_get_platdata(dev);
struct regulator_config config = { };
struct act8865 *act8865;
struct device_node *of_node[ACT8865_REG_NUM];
int i, id;
int ret = -EINVAL;
int error;
if (dev->of_node && !pdata) {
const struct of_device_id *id;
struct act8865_platform_data pdata_of;
id = of_match_device(of_match_ptr(act8865_dt_ids), dev);
if (!id)
return -ENODEV;
ret = act8865_pdata_from_dt(dev, of_node, &pdata_of);
if (ret < 0)
return ret;
pdata = &pdata_of;
}
if (pdata->num_regulators > ACT8865_REG_NUM) {
dev_err(dev, "Too many regulators found!\n");
return -EINVAL;
}
act8865 = devm_kzalloc(dev, sizeof(struct act8865), GFP_KERNEL);
if (!act8865)
return -ENOMEM;
act8865->regmap = devm_regmap_init_i2c(client, &act8865_regmap_config);
if (IS_ERR(act8865->regmap)) {
error = PTR_ERR(act8865->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
for (i = 0; i < ACT8865_REG_NUM; i++) {
id = pdata->regulators[i].id;
config.dev = dev;
config.init_data = pdata->regulators[i].platform_data;
config.of_node = of_node[i];
config.driver_data = act8865;
config.regmap = act8865->regmap;
rdev = devm_regulator_register(&client->dev, &act8865_reg[i],
&config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register %s\n",
act8865_reg[id].name);
return PTR_ERR(rdev);
}
}
i2c_set_clientdata(client, act8865);
return 0;
}
