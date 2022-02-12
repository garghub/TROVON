static int max1586_v3_get_voltage_sel(struct regulator_dev *rdev)
{
struct max1586_data *max1586 = rdev_get_drvdata(rdev);
return max1586->v3_curr_sel;
}
static int max1586_v3_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct max1586_data *max1586 = rdev_get_drvdata(rdev);
struct i2c_client *client = max1586->client;
int ret;
u8 v3_prog;
dev_dbg(&client->dev, "changing voltage v3 to %dmv\n",
regulator_list_voltage_linear(rdev, selector) / 1000);
v3_prog = I2C_V3_SELECT | (u8) selector;
ret = i2c_smbus_write_byte(client, v3_prog);
if (ret)
return ret;
max1586->v3_curr_sel = selector;
return 0;
}
static int max1586_v6_get_voltage_sel(struct regulator_dev *rdev)
{
struct max1586_data *max1586 = rdev_get_drvdata(rdev);
return max1586->v6_curr_sel;
}
static int max1586_v6_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct max1586_data *max1586 = rdev_get_drvdata(rdev);
struct i2c_client *client = max1586->client;
u8 v6_prog;
int ret;
dev_dbg(&client->dev, "changing voltage v6 to %dmv\n",
rdev->desc->volt_table[selector] / 1000);
v6_prog = I2C_V6_SELECT | (u8) selector;
ret = i2c_smbus_write_byte(client, v6_prog);
if (ret)
return ret;
max1586->v6_curr_sel = selector;
return 0;
}
static int of_get_max1586_platform_data(struct device *dev,
struct max1586_platform_data *pdata)
{
struct max1586_subdev_data *sub;
struct of_regulator_match rmatch[ARRAY_SIZE(max1586_reg)] = { };
struct device_node *np = dev->of_node;
int i, matched;
if (of_property_read_u32(np, "v3-gain",
&pdata->v3_gain) < 0) {
dev_err(dev, "%pOF has no 'v3-gain' property\n", np);
return -EINVAL;
}
np = of_get_child_by_name(np, "regulators");
if (!np) {
dev_err(dev, "missing 'regulators' subnode in DT\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(rmatch); i++)
rmatch[i].name = max1586_reg[i].name;
matched = of_regulator_match(dev, np, rmatch, ARRAY_SIZE(rmatch));
of_node_put(np);
if (matched <= 0)
return matched;
pdata->subdevs = devm_kzalloc(dev, sizeof(struct max1586_subdev_data) *
matched, GFP_KERNEL);
if (!pdata->subdevs)
return -ENOMEM;
pdata->num_subdevs = matched;
sub = pdata->subdevs;
for (i = 0; i < matched; i++) {
sub->id = i;
sub->name = rmatch[i].of_node->name;
sub->platform_data = rmatch[i].init_data;
sub++;
}
return 0;
}
static int max1586_pmic_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct max1586_platform_data *pdata, pdata_of;
struct regulator_config config = { };
struct max1586_data *max1586;
int i, id, ret;
const struct of_device_id *match;
pdata = dev_get_platdata(&client->dev);
if (client->dev.of_node && !pdata) {
match = of_match_device(of_match_ptr(max1586_of_match),
&client->dev);
if (!match) {
dev_err(&client->dev, "Error: No device match found\n");
return -ENODEV;
}
ret = of_get_max1586_platform_data(&client->dev, &pdata_of);
if (ret < 0)
return ret;
pdata = &pdata_of;
}
max1586 = devm_kzalloc(&client->dev, sizeof(struct max1586_data),
GFP_KERNEL);
if (!max1586)
return -ENOMEM;
max1586->client = client;
if (!pdata->v3_gain)
return -EINVAL;
max1586->min_uV = MAX1586_V3_MIN_UV / 1000 * pdata->v3_gain / 1000;
max1586->max_uV = MAX1586_V3_MAX_UV / 1000 * pdata->v3_gain / 1000;
max1586->v3_curr_sel = 24;
max1586->v6_curr_sel = 0;
for (i = 0; i < pdata->num_subdevs && i <= MAX1586_V6; i++) {
struct regulator_dev *rdev;
id = pdata->subdevs[i].id;
if (!pdata->subdevs[i].platform_data)
continue;
if (id < MAX1586_V3 || id > MAX1586_V6) {
dev_err(&client->dev, "invalid regulator id %d\n", id);
return -EINVAL;
}
if (id == MAX1586_V3) {
max1586_reg[id].min_uV = max1586->min_uV;
max1586_reg[id].uV_step =
(max1586->max_uV - max1586->min_uV) /
MAX1586_V3_MAX_VSEL;
}
config.dev = &client->dev;
config.init_data = pdata->subdevs[i].platform_data;
config.driver_data = max1586;
rdev = devm_regulator_register(&client->dev,
&max1586_reg[id], &config);
if (IS_ERR(rdev)) {
dev_err(&client->dev, "failed to register %s\n",
max1586_reg[id].name);
return PTR_ERR(rdev);
}
}
i2c_set_clientdata(client, max1586);
dev_info(&client->dev, "Maxim 1586 regulator driver loaded\n");
return 0;
}
static int __init max1586_pmic_init(void)
{
return i2c_add_driver(&max1586_pmic_driver);
}
static void __exit max1586_pmic_exit(void)
{
i2c_del_driver(&max1586_pmic_driver);
}
