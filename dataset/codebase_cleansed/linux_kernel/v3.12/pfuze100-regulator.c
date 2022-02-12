static int pfuze100_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
struct pfuze_chip *pfuze100 = rdev_get_drvdata(rdev);
int id = rdev->desc->id;
unsigned int ramp_bits;
int ret;
if (id < PFUZE100_SWBST) {
ramp_delay = 12500 / ramp_delay;
ramp_bits = (ramp_delay >> 1) - (ramp_delay >> 3);
ret = regmap_update_bits(pfuze100->regmap,
rdev->desc->vsel_reg + 4,
0xc0, ramp_bits << 6);
if (ret < 0)
dev_err(pfuze100->dev, "ramp failed, err %d\n", ret);
} else
ret = -EACCES;
return ret;
}
static int pfuze_parse_regulators_dt(struct pfuze_chip *chip)
{
struct device *dev = chip->dev;
struct device_node *np, *parent;
int ret;
np = of_node_get(dev->parent->of_node);
if (!np)
return 0;
parent = of_find_node_by_name(np, "regulators");
if (!parent) {
dev_err(dev, "regulators node not found\n");
return -EINVAL;
}
ret = of_regulator_match(dev, parent, pfuze100_matches,
ARRAY_SIZE(pfuze100_matches));
of_node_put(parent);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n",
ret);
return ret;
}
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return pfuze100_matches[index].init_data;
}
static inline struct device_node *match_of_node(int index)
{
return pfuze100_matches[index].of_node;
}
static int pfuze_parse_regulators_dt(struct pfuze_chip *chip)
{
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return NULL;
}
static inline struct device_node *match_of_node(int index)
{
return NULL;
}
static int pfuze_identify(struct pfuze_chip *pfuze_chip)
{
unsigned int value;
int ret;
ret = regmap_read(pfuze_chip->regmap, PFUZE100_DEVICEID, &value);
if (ret)
return ret;
if (value & 0x0f) {
dev_warn(pfuze_chip->dev, "Illegal ID: %x\n", value);
return -ENODEV;
}
ret = regmap_read(pfuze_chip->regmap, PFUZE100_REVID, &value);
if (ret)
return ret;
dev_info(pfuze_chip->dev,
"Full lay: %x, Metal lay: %x\n",
(value & 0xf0) >> 4, value & 0x0f);
ret = regmap_read(pfuze_chip->regmap, PFUZE100_FABID, &value);
if (ret)
return ret;
dev_info(pfuze_chip->dev, "FAB: %x, FIN: %x\n",
(value & 0xc) >> 2, value & 0x3);
return 0;
}
static int pfuze100_regulator_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pfuze_chip *pfuze_chip;
struct pfuze_regulator_platform_data *pdata =
dev_get_platdata(&client->dev);
struct regulator_config config = { };
int i, ret;
pfuze_chip = devm_kzalloc(&client->dev, sizeof(*pfuze_chip),
GFP_KERNEL);
if (!pfuze_chip)
return -ENOMEM;
i2c_set_clientdata(client, pfuze_chip);
memcpy(pfuze_chip->regulator_descs, pfuze100_regulators,
sizeof(pfuze_chip->regulator_descs));
pfuze_chip->dev = &client->dev;
pfuze_chip->regmap = devm_regmap_init_i2c(client, &pfuze_regmap_config);
if (IS_ERR(pfuze_chip->regmap)) {
ret = PTR_ERR(pfuze_chip->regmap);
dev_err(&client->dev,
"regmap allocation failed with err %d\n", ret);
return ret;
}
ret = pfuze_identify(pfuze_chip);
if (ret) {
dev_err(&client->dev, "unrecognized pfuze chip ID!\n");
return ret;
}
ret = pfuze_parse_regulators_dt(pfuze_chip);
if (ret)
return ret;
for (i = 0; i < PFUZE100_MAX_REGULATOR; i++) {
struct regulator_init_data *init_data;
struct regulator_desc *desc;
int val;
desc = &pfuze_chip->regulator_descs[i].desc;
if (pdata)
init_data = pdata->init_data[i];
else
init_data = match_init_data(i);
if (i > PFUZE100_SW1C && i < PFUZE100_SWBST) {
regmap_read(pfuze_chip->regmap, desc->vsel_reg, &val);
if (val & 0x40) {
desc->min_uV = 800000;
desc->uV_step = 50000;
desc->n_voltages = 51;
}
}
config.dev = &client->dev;
config.init_data = init_data;
config.driver_data = pfuze_chip;
config.of_node = match_of_node(i);
pfuze_chip->regulators[i] = regulator_register(desc, &config);
if (IS_ERR(pfuze_chip->regulators[i])) {
dev_err(&client->dev, "register regulator%s failed\n",
pfuze100_regulators[i].desc.name);
ret = PTR_ERR(pfuze_chip->regulators[i]);
while (--i >= 0)
regulator_unregister(pfuze_chip->regulators[i]);
return ret;
}
}
return 0;
}
static int pfuze100_regulator_remove(struct i2c_client *client)
{
int i;
struct pfuze_chip *pfuze_chip = i2c_get_clientdata(client);
for (i = 0; i < PFUZE100_MAX_REGULATOR; i++)
regulator_unregister(pfuze_chip->regulators[i]);
return 0;
}
