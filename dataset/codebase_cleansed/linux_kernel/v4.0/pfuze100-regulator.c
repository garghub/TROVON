static int pfuze100_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
struct pfuze_chip *pfuze100 = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
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
np = of_node_get(dev->of_node);
if (!np)
return -EINVAL;
parent = of_get_child_by_name(np, "regulators");
if (!parent) {
dev_err(dev, "regulators node not found\n");
return -EINVAL;
}
switch (chip->chip_id) {
case PFUZE3000:
pfuze_matches = pfuze3000_matches;
ret = of_regulator_match(dev, parent, pfuze3000_matches,
ARRAY_SIZE(pfuze3000_matches));
break;
case PFUZE200:
pfuze_matches = pfuze200_matches;
ret = of_regulator_match(dev, parent, pfuze200_matches,
ARRAY_SIZE(pfuze200_matches));
break;
case PFUZE100:
default:
pfuze_matches = pfuze100_matches;
ret = of_regulator_match(dev, parent, pfuze100_matches,
ARRAY_SIZE(pfuze100_matches));
break;
}
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
return pfuze_matches[index].init_data;
}
static inline struct device_node *match_of_node(int index)
{
return pfuze_matches[index].of_node;
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
if (((value & 0x0f) == 0x8) && (pfuze_chip->chip_id == PFUZE100)) {
dev_info(pfuze_chip->dev, "Assuming misprogrammed ID=0x8");
} else if ((value & 0x0f) != pfuze_chip->chip_id &&
(value & 0xf0) >> 4 != pfuze_chip->chip_id) {
dev_warn(pfuze_chip->dev, "Illegal ID: %x\n", value);
return -ENODEV;
}
ret = regmap_read(pfuze_chip->regmap, PFUZE100_REVID, &value);
if (ret)
return ret;
dev_info(pfuze_chip->dev,
"Full layer: %x, Metal layer: %x\n",
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
const struct of_device_id *match;
u32 regulator_num;
u32 sw_check_start, sw_check_end, sw_hi = 0x40;
pfuze_chip = devm_kzalloc(&client->dev, sizeof(*pfuze_chip),
GFP_KERNEL);
if (!pfuze_chip)
return -ENOMEM;
if (client->dev.of_node) {
match = of_match_device(of_match_ptr(pfuze_dt_ids),
&client->dev);
if (!match) {
dev_err(&client->dev, "Error: No device match found\n");
return -ENODEV;
}
pfuze_chip->chip_id = (int)(long)match->data;
} else if (id) {
pfuze_chip->chip_id = id->driver_data;
} else {
dev_err(&client->dev, "No dts match or id table match found\n");
return -ENODEV;
}
i2c_set_clientdata(client, pfuze_chip);
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
switch (pfuze_chip->chip_id) {
case PFUZE3000:
pfuze_regulators = pfuze3000_regulators;
regulator_num = ARRAY_SIZE(pfuze3000_regulators);
sw_check_start = PFUZE3000_SW2;
sw_check_end = PFUZE3000_SW2;
sw_hi = 1 << 3;
break;
case PFUZE200:
pfuze_regulators = pfuze200_regulators;
regulator_num = ARRAY_SIZE(pfuze200_regulators);
sw_check_start = PFUZE200_SW2;
sw_check_end = PFUZE200_SW3B;
break;
case PFUZE100:
default:
pfuze_regulators = pfuze100_regulators;
regulator_num = ARRAY_SIZE(pfuze100_regulators);
sw_check_start = PFUZE100_SW2;
sw_check_end = PFUZE100_SW4;
break;
}
dev_info(&client->dev, "pfuze%s found.\n",
(pfuze_chip->chip_id == PFUZE100) ? "100" :
((pfuze_chip->chip_id == PFUZE200) ? "200" : "3000"));
memcpy(pfuze_chip->regulator_descs, pfuze_regulators,
sizeof(pfuze_chip->regulator_descs));
ret = pfuze_parse_regulators_dt(pfuze_chip);
if (ret)
return ret;
for (i = 0; i < regulator_num; i++) {
struct regulator_init_data *init_data;
struct regulator_desc *desc;
int val;
desc = &pfuze_chip->regulator_descs[i].desc;
if (pdata)
init_data = pdata->init_data[i];
else
init_data = match_init_data(i);
if (i >= sw_check_start && i <= sw_check_end) {
regmap_read(pfuze_chip->regmap, desc->vsel_reg, &val);
if (val & sw_hi) {
if (pfuze_chip->chip_id == PFUZE3000) {
desc->volt_table = pfuze3000_sw2hi;
desc->n_voltages = ARRAY_SIZE(pfuze3000_sw2hi);
} else {
desc->min_uV = 800000;
desc->uV_step = 50000;
desc->n_voltages = 51;
}
}
}
config.dev = &client->dev;
config.init_data = init_data;
config.driver_data = pfuze_chip;
config.of_node = match_of_node(i);
config.ena_gpio = -EINVAL;
pfuze_chip->regulators[i] =
devm_regulator_register(&client->dev, desc, &config);
if (IS_ERR(pfuze_chip->regulators[i])) {
dev_err(&client->dev, "register regulator%s failed\n",
pfuze_regulators[i].desc.name);
return PTR_ERR(pfuze_chip->regulators[i]);
}
}
return 0;
}
