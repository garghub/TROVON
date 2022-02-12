static int max77620_get_fps_period_reg_value(struct max77620_chip *chip,
int tperiod)
{
int fps_min_period;
int i;
switch (chip->chip_id) {
case MAX20024:
fps_min_period = MAX20024_FPS_PERIOD_MIN_US;
break;
case MAX77620:
fps_min_period = MAX77620_FPS_PERIOD_MIN_US;
break;
default:
return -EINVAL;
}
for (i = 0; i < 7; i++) {
if (fps_min_period >= tperiod)
return i;
fps_min_period *= 2;
}
return i;
}
static int max77620_config_fps(struct max77620_chip *chip,
struct device_node *fps_np)
{
struct device *dev = chip->dev;
unsigned int mask = 0, config = 0;
u32 fps_max_period;
u32 param_val;
int tperiod, fps_id;
int ret;
char fps_name[10];
switch (chip->chip_id) {
case MAX20024:
fps_max_period = MAX20024_FPS_PERIOD_MAX_US;
break;
case MAX77620:
fps_max_period = MAX77620_FPS_PERIOD_MAX_US;
break;
default:
return -EINVAL;
}
for (fps_id = 0; fps_id < MAX77620_FPS_COUNT; fps_id++) {
sprintf(fps_name, "fps%d", fps_id);
if (!strcmp(fps_np->name, fps_name))
break;
}
if (fps_id == MAX77620_FPS_COUNT) {
dev_err(dev, "FPS node name %s is not valid\n", fps_np->name);
return -EINVAL;
}
ret = of_property_read_u32(fps_np, "maxim,shutdown-fps-time-period-us",
&param_val);
if (!ret) {
mask |= MAX77620_FPS_TIME_PERIOD_MASK;
chip->shutdown_fps_period[fps_id] = min(param_val,
fps_max_period);
tperiod = max77620_get_fps_period_reg_value(chip,
chip->shutdown_fps_period[fps_id]);
config |= tperiod << MAX77620_FPS_TIME_PERIOD_SHIFT;
}
ret = of_property_read_u32(fps_np, "maxim,suspend-fps-time-period-us",
&param_val);
if (!ret)
chip->suspend_fps_period[fps_id] = min(param_val,
fps_max_period);
ret = of_property_read_u32(fps_np, "maxim,fps-event-source",
&param_val);
if (!ret) {
if (param_val > 2) {
dev_err(dev, "FPS%d event-source invalid\n", fps_id);
return -EINVAL;
}
mask |= MAX77620_FPS_EN_SRC_MASK;
config |= param_val << MAX77620_FPS_EN_SRC_SHIFT;
if (param_val == 2) {
mask |= MAX77620_FPS_ENFPS_SW_MASK;
config |= MAX77620_FPS_ENFPS_SW;
}
}
if (!chip->sleep_enable && !chip->enable_global_lpm) {
ret = of_property_read_u32(fps_np,
"maxim,device-state-on-disabled-event",
&param_val);
if (!ret) {
if (param_val == 0)
chip->sleep_enable = true;
else if (param_val == 1)
chip->enable_global_lpm = true;
}
}
ret = regmap_update_bits(chip->rmap, MAX77620_REG_FPS_CFG0 + fps_id,
mask, config);
if (ret < 0) {
dev_err(dev, "Failed to update FPS CFG: %d\n", ret);
return ret;
}
return 0;
}
static int max77620_initialise_fps(struct max77620_chip *chip)
{
struct device *dev = chip->dev;
struct device_node *fps_np, *fps_child;
u8 config;
int fps_id;
int ret;
for (fps_id = 0; fps_id < MAX77620_FPS_COUNT; fps_id++) {
chip->shutdown_fps_period[fps_id] = -1;
chip->suspend_fps_period[fps_id] = -1;
}
fps_np = of_get_child_by_name(dev->of_node, "fps");
if (!fps_np)
goto skip_fps;
for_each_child_of_node(fps_np, fps_child) {
ret = max77620_config_fps(chip, fps_child);
if (ret < 0)
return ret;
}
config = chip->enable_global_lpm ? MAX77620_ONOFFCNFG2_SLP_LPM_MSK : 0;
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG2,
MAX77620_ONOFFCNFG2_SLP_LPM_MSK, config);
if (ret < 0) {
dev_err(dev, "Failed to update SLP_LPM: %d\n", ret);
return ret;
}
skip_fps:
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG2,
MAX77620_ONOFFCNFG2_WK_EN0,
MAX77620_ONOFFCNFG2_WK_EN0);
if (ret < 0) {
dev_err(dev, "Failed to update WK_EN0: %d\n", ret);
return ret;
}
if ((chip->chip_id == MAX20024) && chip->sleep_enable) {
config = MAX77620_ONOFFCNFG1_SLPEN | MAX20024_ONOFFCNFG1_CLRSE;
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG1,
config, config);
if (ret < 0) {
dev_err(dev, "Failed to update SLPEN: %d\n", ret);
return ret;
}
}
return 0;
}
static int max77620_read_es_version(struct max77620_chip *chip)
{
unsigned int val;
u8 cid_val[6];
int i;
int ret;
for (i = MAX77620_REG_CID0; i <= MAX77620_REG_CID5; i++) {
ret = regmap_read(chip->rmap, i, &val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CID: %d\n", ret);
return ret;
}
dev_dbg(chip->dev, "CID%d: 0x%02x\n",
i - MAX77620_REG_CID0, val);
cid_val[i - MAX77620_REG_CID0] = val;
}
dev_info(chip->dev, "PMIC Version OTP:0x%02X and ES:0x%X\n",
cid_val[4], MAX77620_CID5_DIDM(cid_val[5]));
return ret;
}
static int max77620_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct regmap_config *rmap_config;
struct max77620_chip *chip;
const struct mfd_cell *mfd_cells;
int n_mfd_cells;
int ret;
chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
i2c_set_clientdata(client, chip);
chip->dev = &client->dev;
chip->irq_base = -1;
chip->chip_irq = client->irq;
chip->chip_id = (enum max77620_chip_id)id->driver_data;
switch (chip->chip_id) {
case MAX77620:
mfd_cells = max77620_children;
n_mfd_cells = ARRAY_SIZE(max77620_children);
rmap_config = &max77620_regmap_config;
break;
case MAX20024:
mfd_cells = max20024_children;
n_mfd_cells = ARRAY_SIZE(max20024_children);
rmap_config = &max20024_regmap_config;
break;
default:
dev_err(chip->dev, "ChipID is invalid %d\n", chip->chip_id);
return -EINVAL;
}
chip->rmap = devm_regmap_init_i2c(client, rmap_config);
if (IS_ERR(chip->rmap)) {
ret = PTR_ERR(chip->rmap);
dev_err(chip->dev, "Failed to intialise regmap: %d\n", ret);
return ret;
}
ret = max77620_read_es_version(chip);
if (ret < 0)
return ret;
ret = devm_regmap_add_irq_chip(chip->dev, chip->rmap, client->irq,
IRQF_ONESHOT | IRQF_SHARED,
chip->irq_base, &max77620_top_irq_chip,
&chip->top_irq_data);
if (ret < 0) {
dev_err(chip->dev, "Failed to add regmap irq: %d\n", ret);
return ret;
}
ret = max77620_initialise_fps(chip);
if (ret < 0)
return ret;
ret = devm_mfd_add_devices(chip->dev, PLATFORM_DEVID_NONE,
mfd_cells, n_mfd_cells, NULL, 0,
regmap_irq_get_domain(chip->top_irq_data));
if (ret < 0) {
dev_err(chip->dev, "Failed to add MFD children: %d\n", ret);
return ret;
}
return 0;
}
static int max77620_set_fps_period(struct max77620_chip *chip,
int fps_id, int time_period)
{
int period = max77620_get_fps_period_reg_value(chip, time_period);
int ret;
ret = regmap_update_bits(chip->rmap, MAX77620_REG_FPS_CFG0 + fps_id,
MAX77620_FPS_TIME_PERIOD_MASK,
period << MAX77620_FPS_TIME_PERIOD_SHIFT);
if (ret < 0) {
dev_err(chip->dev, "Failed to update FPS period: %d\n", ret);
return ret;
}
return 0;
}
static int max77620_i2c_suspend(struct device *dev)
{
struct max77620_chip *chip = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(dev);
unsigned int config;
int fps;
int ret;
for (fps = 0; fps < MAX77620_FPS_COUNT; fps++) {
if (chip->suspend_fps_period[fps] < 0)
continue;
ret = max77620_set_fps_period(chip, fps,
chip->suspend_fps_period[fps]);
if (ret < 0)
return ret;
}
if (chip->chip_id == MAX20024)
goto out;
config = (chip->sleep_enable) ? MAX77620_ONOFFCNFG1_SLPEN : 0;
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG1,
MAX77620_ONOFFCNFG1_SLPEN,
config);
if (ret < 0) {
dev_err(dev, "Failed to configure sleep in suspend: %d\n", ret);
return ret;
}
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG2,
MAX77620_ONOFFCNFG2_WK_EN0, 0);
if (ret < 0) {
dev_err(dev, "Failed to configure WK_EN in suspend: %d\n", ret);
return ret;
}
out:
disable_irq(client->irq);
return 0;
}
static int max77620_i2c_resume(struct device *dev)
{
struct max77620_chip *chip = dev_get_drvdata(dev);
struct i2c_client *client = to_i2c_client(dev);
int ret;
int fps;
for (fps = 0; fps < MAX77620_FPS_COUNT; fps++) {
if (chip->shutdown_fps_period[fps] < 0)
continue;
ret = max77620_set_fps_period(chip, fps,
chip->shutdown_fps_period[fps]);
if (ret < 0)
return ret;
}
if (chip->chip_id == MAX20024)
goto out;
ret = regmap_update_bits(chip->rmap, MAX77620_REG_ONOFFCNFG2,
MAX77620_ONOFFCNFG2_WK_EN0,
MAX77620_ONOFFCNFG2_WK_EN0);
if (ret < 0) {
dev_err(dev, "Failed to configure WK_EN0 n resume: %d\n", ret);
return ret;
}
out:
enable_irq(client->irq);
return 0;
}
