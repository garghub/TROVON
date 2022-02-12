static unsigned int pv88080_buck_get_mode(struct regulator_dev *rdev)
{
struct pv88080_regulator *info = rdev_get_drvdata(rdev);
unsigned int data;
int ret, mode = 0;
ret = regmap_read(rdev->regmap, info->mode_reg, &data);
if (ret < 0)
return ret;
switch (data & PV88080_BUCK1_MODE_MASK) {
case PV88080_BUCK_MODE_SYNC:
mode = REGULATOR_MODE_FAST;
break;
case PV88080_BUCK_MODE_AUTO:
mode = REGULATOR_MODE_NORMAL;
break;
case PV88080_BUCK_MODE_SLEEP:
mode = REGULATOR_MODE_STANDBY;
break;
default:
return -EINVAL;
}
return mode;
}
static int pv88080_buck_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct pv88080_regulator *info = rdev_get_drvdata(rdev);
int val = 0;
switch (mode) {
case REGULATOR_MODE_FAST:
val = PV88080_BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = PV88080_BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = PV88080_BUCK_MODE_SLEEP;
break;
default:
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, info->mode_reg,
PV88080_BUCK1_MODE_MASK, val);
}
static int pv88080_set_current_limit(struct regulator_dev *rdev, int min,
int max)
{
struct pv88080_regulator *info = rdev_get_drvdata(rdev);
int i;
for (i = info->n_current_limits; i >= 0; i--) {
if (min <= info->current_limits[i]
&& max >= info->current_limits[i]) {
return regmap_update_bits(rdev->regmap,
info->limit_reg,
info->limit_mask,
i << PV88080_BUCK1_ILIM_SHIFT);
}
}
return -EINVAL;
}
static int pv88080_get_current_limit(struct regulator_dev *rdev)
{
struct pv88080_regulator *info = rdev_get_drvdata(rdev);
unsigned int data;
int ret;
ret = regmap_read(rdev->regmap, info->limit_reg, &data);
if (ret < 0)
return ret;
data = (data & info->limit_mask) >> PV88080_BUCK1_ILIM_SHIFT;
return info->current_limits[data];
}
static irqreturn_t pv88080_irq_handler(int irq, void *data)
{
struct pv88080 *chip = data;
int i, reg_val, err, ret = IRQ_NONE;
err = regmap_read(chip->regmap, PV88080_REG_EVENT_A, &reg_val);
if (err < 0)
goto error_i2c;
if (reg_val & PV88080_E_VDD_FLT) {
for (i = 0; i < PV88080_MAX_REGULATORS; i++) {
if (chip->rdev[i] != NULL) {
regulator_notifier_call_chain(chip->rdev[i],
REGULATOR_EVENT_UNDER_VOLTAGE,
NULL);
}
}
err = regmap_write(chip->regmap, PV88080_REG_EVENT_A,
PV88080_E_VDD_FLT);
if (err < 0)
goto error_i2c;
ret = IRQ_HANDLED;
}
if (reg_val & PV88080_E_OVER_TEMP) {
for (i = 0; i < PV88080_MAX_REGULATORS; i++) {
if (chip->rdev[i] != NULL) {
regulator_notifier_call_chain(chip->rdev[i],
REGULATOR_EVENT_OVER_TEMP,
NULL);
}
}
err = regmap_write(chip->regmap, PV88080_REG_EVENT_A,
PV88080_E_OVER_TEMP);
if (err < 0)
goto error_i2c;
ret = IRQ_HANDLED;
}
return ret;
error_i2c:
dev_err(chip->dev, "I2C error : %d\n", err);
return IRQ_NONE;
}
static int pv88080_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regulator_init_data *init_data = dev_get_platdata(&i2c->dev);
struct pv88080 *chip;
const struct pv88080_compatible_regmap *regmap_config;
const struct of_device_id *match;
struct regulator_config config = { };
int i, error, ret;
unsigned int conf2, conf5;
chip = devm_kzalloc(&i2c->dev, sizeof(struct pv88080), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = &i2c->dev;
chip->regmap = devm_regmap_init_i2c(i2c, &pv88080_regmap_config);
if (IS_ERR(chip->regmap)) {
error = PTR_ERR(chip->regmap);
dev_err(chip->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
if (i2c->dev.of_node) {
match = of_match_node(pv88080_dt_ids, i2c->dev.of_node);
if (!match) {
dev_err(chip->dev, "Failed to get of_match_node\n");
return -EINVAL;
}
chip->type = (unsigned long)match->data;
} else {
chip->type = id->driver_data;
}
i2c_set_clientdata(i2c, chip);
if (i2c->irq != 0) {
ret = regmap_write(chip->regmap, PV88080_REG_MASK_A, 0xFF);
if (ret < 0) {
dev_err(chip->dev,
"Failed to mask A reg: %d\n", ret);
return ret;
}
ret = regmap_write(chip->regmap, PV88080_REG_MASK_B, 0xFF);
if (ret < 0) {
dev_err(chip->dev,
"Failed to mask B reg: %d\n", ret);
return ret;
}
ret = regmap_write(chip->regmap, PV88080_REG_MASK_C, 0xFF);
if (ret < 0) {
dev_err(chip->dev,
"Failed to mask C reg: %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(&i2c->dev, i2c->irq, NULL,
pv88080_irq_handler,
IRQF_TRIGGER_LOW|IRQF_ONESHOT,
"pv88080", chip);
if (ret != 0) {
dev_err(chip->dev, "Failed to request IRQ: %d\n",
i2c->irq);
return ret;
}
ret = regmap_update_bits(chip->regmap, PV88080_REG_MASK_A,
PV88080_M_VDD_FLT | PV88080_M_OVER_TEMP, 0);
if (ret < 0) {
dev_err(chip->dev,
"Failed to update mask reg: %d\n", ret);
return ret;
}
} else {
dev_warn(chip->dev, "No IRQ configured\n");
}
switch (chip->type) {
case TYPE_PV88080_AA:
chip->regmap_config = &pv88080_aa_regs;
break;
case TYPE_PV88080_BA:
chip->regmap_config = &pv88080_ba_regs;
break;
}
regmap_config = chip->regmap_config;
config.dev = chip->dev;
config.regmap = chip->regmap;
for (i = 0; i < PV88080_MAX_REGULATORS-1; i++) {
if (init_data)
config.init_data = &init_data[i];
pv88080_regulator_info[i].limit_reg
= regmap_config->buck_regmap[i].buck_limit_reg;
pv88080_regulator_info[i].limit_mask
= regmap_config->buck_regmap[i].buck_limit_mask;
pv88080_regulator_info[i].mode_reg
= regmap_config->buck_regmap[i].buck_mode_reg;
pv88080_regulator_info[i].conf2
= regmap_config->buck_regmap[i].buck_vdac_range_reg;
pv88080_regulator_info[i].conf5
= regmap_config->buck_regmap[i].buck_vrange_gain_reg;
pv88080_regulator_info[i].desc.enable_reg
= regmap_config->buck_regmap[i].buck_enable_reg;
pv88080_regulator_info[i].desc.enable_mask
= regmap_config->buck_regmap[i].buck_enable_mask;
pv88080_regulator_info[i].desc.vsel_reg
= regmap_config->buck_regmap[i].buck_vsel_reg;
pv88080_regulator_info[i].desc.vsel_mask
= regmap_config->buck_regmap[i].buck_vsel_mask;
ret = regmap_read(chip->regmap,
pv88080_regulator_info[i].conf2, &conf2);
if (ret < 0)
return ret;
conf2 = ((conf2 >> PV88080_BUCK_VDAC_RANGE_SHIFT) &
PV88080_BUCK_VDAC_RANGE_MASK);
ret = regmap_read(chip->regmap,
pv88080_regulator_info[i].conf5, &conf5);
if (ret < 0)
return ret;
conf5 = ((conf5 >> PV88080_BUCK_VRANGE_GAIN_SHIFT) &
PV88080_BUCK_VRANGE_GAIN_MASK);
pv88080_regulator_info[i].desc.min_uV =
pv88080_buck_vol[conf2].min_uV * (conf5+1);
pv88080_regulator_info[i].desc.uV_step =
pv88080_buck_vol[conf2].uV_step * (conf5+1);
pv88080_regulator_info[i].desc.n_voltages =
((pv88080_buck_vol[conf2].max_uV * (conf5+1))
- (pv88080_regulator_info[i].desc.min_uV))
/(pv88080_regulator_info[i].desc.uV_step) + 1;
config.driver_data = (void *)&pv88080_regulator_info[i];
chip->rdev[i] = devm_regulator_register(chip->dev,
&pv88080_regulator_info[i].desc, &config);
if (IS_ERR(chip->rdev[i])) {
dev_err(chip->dev,
"Failed to register PV88080 regulator\n");
return PTR_ERR(chip->rdev[i]);
}
}
pv88080_regulator_info[PV88080_ID_HVBUCK].desc.enable_reg
= regmap_config->hvbuck_enable_reg;
pv88080_regulator_info[PV88080_ID_HVBUCK].desc.enable_mask
= regmap_config->hvbuck_enable_mask;
pv88080_regulator_info[PV88080_ID_HVBUCK].desc.vsel_reg
= regmap_config->hvbuck_vsel_reg;
pv88080_regulator_info[PV88080_ID_HVBUCK].desc.vsel_mask
= regmap_config->hvbuck_vsel_mask;
if (init_data)
config.init_data = &init_data[PV88080_ID_HVBUCK];
config.driver_data = (void *)&pv88080_regulator_info[PV88080_ID_HVBUCK];
chip->rdev[PV88080_ID_HVBUCK] = devm_regulator_register(chip->dev,
&pv88080_regulator_info[PV88080_ID_HVBUCK].desc, &config);
if (IS_ERR(chip->rdev[PV88080_ID_HVBUCK])) {
dev_err(chip->dev, "Failed to register PV88080 regulator\n");
return PTR_ERR(chip->rdev[PV88080_ID_HVBUCK]);
}
return 0;
}
