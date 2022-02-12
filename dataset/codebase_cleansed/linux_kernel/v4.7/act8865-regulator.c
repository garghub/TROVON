static int act8865_pdata_from_dt(struct device *dev,
struct act8865_platform_data *pdata,
unsigned long type)
{
int matched, i, num_matches;
struct device_node *np;
struct act8865_regulator_data *regulator;
struct of_regulator_match *matches;
np = of_get_child_by_name(dev->of_node, "regulators");
if (!np) {
dev_err(dev, "missing 'regulators' subnode in DT\n");
return -EINVAL;
}
switch (type) {
case ACT8600:
matches = act8600_matches;
num_matches = ARRAY_SIZE(act8600_matches);
break;
case ACT8846:
matches = act8846_matches;
num_matches = ARRAY_SIZE(act8846_matches);
break;
case ACT8865:
matches = act8865_matches;
num_matches = ARRAY_SIZE(act8865_matches);
break;
default:
dev_err(dev, "invalid device id %lu\n", type);
return -EINVAL;
}
matched = of_regulator_match(dev, np, matches, num_matches);
of_node_put(np);
if (matched <= 0)
return matched;
pdata->regulators = devm_kzalloc(dev,
sizeof(struct act8865_regulator_data) *
num_matches, GFP_KERNEL);
if (!pdata->regulators)
return -ENOMEM;
pdata->num_regulators = num_matches;
regulator = pdata->regulators;
for (i = 0; i < num_matches; i++) {
regulator->id = i;
regulator->name = matches[i].name;
regulator->init_data = matches[i].init_data;
regulator->of_node = matches[i].of_node;
regulator++;
}
return 0;
}
static inline int act8865_pdata_from_dt(struct device *dev,
struct act8865_platform_data *pdata,
unsigned long type)
{
return 0;
}
static struct act8865_regulator_data *act8865_get_regulator_data(
int id, struct act8865_platform_data *pdata)
{
int i;
if (!pdata)
return NULL;
for (i = 0; i < pdata->num_regulators; i++) {
if (pdata->regulators[i].id == id)
return &pdata->regulators[i];
}
return NULL;
}
static void act8865_power_off(void)
{
struct act8865 *act8865;
act8865 = i2c_get_clientdata(act8865_i2c_client);
regmap_write(act8865->regmap, act8865->off_reg, act8865->off_mask);
while (1);
}
static int act8865_pmic_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
const struct regulator_desc *regulators;
struct act8865_platform_data pdata_of, *pdata;
struct device *dev = &client->dev;
int i, ret, num_regulators;
struct act8865 *act8865;
const struct regmap_config *regmap_config;
unsigned long type;
int off_reg, off_mask;
int voltage_select = 0;
pdata = dev_get_platdata(dev);
if (dev->of_node && !pdata) {
const struct of_device_id *id;
id = of_match_device(of_match_ptr(act8865_dt_ids), dev);
if (!id)
return -ENODEV;
type = (unsigned long) id->data;
voltage_select = !!of_get_property(dev->of_node,
"active-semi,vsel-high",
NULL);
} else {
type = i2c_id->driver_data;
}
switch (type) {
case ACT8600:
regulators = act8600_regulators;
num_regulators = ARRAY_SIZE(act8600_regulators);
regmap_config = &act8600_regmap_config;
off_reg = -1;
off_mask = -1;
break;
case ACT8846:
regulators = act8846_regulators;
num_regulators = ARRAY_SIZE(act8846_regulators);
regmap_config = &act8865_regmap_config;
off_reg = ACT8846_GLB_OFF_CTRL;
off_mask = ACT8846_OFF_SYSMASK;
break;
case ACT8865:
if (voltage_select) {
regulators = act8865_alt_regulators;
num_regulators = ARRAY_SIZE(act8865_alt_regulators);
} else {
regulators = act8865_regulators;
num_regulators = ARRAY_SIZE(act8865_regulators);
}
regmap_config = &act8865_regmap_config;
off_reg = ACT8865_SYS_CTRL;
off_mask = ACT8865_MSTROFF;
break;
default:
dev_err(dev, "invalid device id %lu\n", type);
return -EINVAL;
}
if (dev->of_node && !pdata) {
ret = act8865_pdata_from_dt(dev, &pdata_of, type);
if (ret < 0)
return ret;
pdata = &pdata_of;
}
act8865 = devm_kzalloc(dev, sizeof(struct act8865), GFP_KERNEL);
if (!act8865)
return -ENOMEM;
act8865->regmap = devm_regmap_init_i2c(client, regmap_config);
if (IS_ERR(act8865->regmap)) {
ret = PTR_ERR(act8865->regmap);
dev_err(dev, "Failed to allocate register map: %d\n", ret);
return ret;
}
if (of_device_is_system_power_controller(dev->of_node)) {
if (!pm_power_off && (off_reg > 0)) {
act8865_i2c_client = client;
act8865->off_reg = off_reg;
act8865->off_mask = off_mask;
pm_power_off = act8865_power_off;
} else {
dev_err(dev, "Failed to set poweroff capability, already defined\n");
}
}
for (i = 0; i < num_regulators; i++) {
const struct regulator_desc *desc = &regulators[i];
struct regulator_config config = { };
struct act8865_regulator_data *rdata;
struct regulator_dev *rdev;
config.dev = dev;
config.driver_data = act8865;
config.regmap = act8865->regmap;
rdata = act8865_get_regulator_data(desc->id, pdata);
if (rdata) {
config.init_data = rdata->init_data;
config.of_node = rdata->of_node;
}
rdev = devm_regulator_register(dev, desc, &config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register %s\n", desc->name);
return PTR_ERR(rdev);
}
}
i2c_set_clientdata(client, act8865);
return 0;
}
