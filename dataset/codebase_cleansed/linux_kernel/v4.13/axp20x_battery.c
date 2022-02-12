static int axp20x_battery_get_max_voltage(struct axp20x_batt_ps *axp20x_batt,
int *val)
{
int ret, reg;
ret = regmap_read(axp20x_batt->regmap, AXP20X_CHRG_CTRL1, &reg);
if (ret)
return ret;
switch (reg & AXP20X_CHRG_CTRL1_TGT_VOLT) {
case AXP20X_CHRG_CTRL1_TGT_4_1V:
*val = 4100000;
break;
case AXP20X_CHRG_CTRL1_TGT_4_15V:
*val = 4150000;
break;
case AXP20X_CHRG_CTRL1_TGT_4_2V:
*val = 4200000;
break;
case AXP20X_CHRG_CTRL1_TGT_4_36V:
*val = 4360000;
break;
default:
return -EINVAL;
}
return 0;
}
static int axp22x_battery_get_max_voltage(struct axp20x_batt_ps *axp20x_batt,
int *val)
{
int ret, reg;
ret = regmap_read(axp20x_batt->regmap, AXP20X_CHRG_CTRL1, &reg);
if (ret)
return ret;
switch (reg & AXP20X_CHRG_CTRL1_TGT_VOLT) {
case AXP20X_CHRG_CTRL1_TGT_4_1V:
*val = 4100000;
break;
case AXP20X_CHRG_CTRL1_TGT_4_2V:
*val = 4200000;
break;
case AXP22X_CHRG_CTRL1_TGT_4_22V:
*val = 4220000;
break;
case AXP22X_CHRG_CTRL1_TGT_4_24V:
*val = 4240000;
break;
default:
return -EINVAL;
}
return 0;
}
static void raw_to_constant_charge_current(struct axp20x_batt_ps *axp, int *val)
{
if (axp->axp_id == AXP209_ID)
*val = *val * 100000 + 300000;
else
*val = *val * 150000 + 300000;
}
static void constant_charge_current_to_raw(struct axp20x_batt_ps *axp, int *val)
{
if (axp->axp_id == AXP209_ID)
*val = (*val - 300000) / 100000;
else
*val = (*val - 300000) / 150000;
}
static int axp20x_get_constant_charge_current(struct axp20x_batt_ps *axp,
int *val)
{
int ret;
ret = regmap_read(axp->regmap, AXP20X_CHRG_CTRL1, val);
if (ret)
return ret;
*val &= AXP20X_CHRG_CTRL1_TGT_CURR;
raw_to_constant_charge_current(axp, val);
return 0;
}
static int axp20x_battery_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct axp20x_batt_ps *axp20x_batt = power_supply_get_drvdata(psy);
struct iio_channel *chan;
int ret = 0, reg, val1;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
case POWER_SUPPLY_PROP_ONLINE:
ret = regmap_read(axp20x_batt->regmap, AXP20X_PWR_OP_MODE,
&reg);
if (ret)
return ret;
val->intval = !!(reg & AXP20X_PWR_OP_BATT_PRESENT);
break;
case POWER_SUPPLY_PROP_STATUS:
ret = regmap_read(axp20x_batt->regmap, AXP20X_PWR_INPUT_STATUS,
&reg);
if (ret)
return ret;
if (reg & AXP20X_PWR_STATUS_BAT_CHARGING) {
val->intval = POWER_SUPPLY_STATUS_CHARGING;
return 0;
}
ret = iio_read_channel_processed(axp20x_batt->batt_dischrg_i,
&val1);
if (ret)
return ret;
if (val1) {
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
return 0;
}
ret = regmap_read(axp20x_batt->regmap, AXP20X_FG_RES, &val1);
if (ret)
return ret;
if ((val1 & AXP209_FG_PERCENT) == 100)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = regmap_read(axp20x_batt->regmap, AXP20X_PWR_OP_MODE,
&val1);
if (ret)
return ret;
if (val1 & AXP20X_PWR_OP_BATT_ACTIVATED) {
val->intval = POWER_SUPPLY_HEALTH_DEAD;
return 0;
}
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
ret = axp20x_get_constant_charge_current(axp20x_batt,
&val->intval);
if (ret)
return ret;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
val->intval = axp20x_batt->max_ccc;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = regmap_read(axp20x_batt->regmap, AXP20X_PWR_INPUT_STATUS,
&reg);
if (ret)
return ret;
if (reg & AXP20X_PWR_STATUS_BAT_CHARGING)
chan = axp20x_batt->batt_chrg_i;
else
chan = axp20x_batt->batt_dischrg_i;
ret = iio_read_channel_processed(chan, &val->intval);
if (ret)
return ret;
val->intval *= 1000;
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = regmap_read(axp20x_batt->regmap, AXP20X_PWR_OP_MODE,
&reg);
if (ret)
return ret;
if (!(reg & AXP20X_PWR_OP_BATT_PRESENT)) {
val->intval = 100;
return 0;
}
ret = regmap_read(axp20x_batt->regmap, AXP20X_FG_RES, &reg);
if (ret)
return ret;
if (axp20x_batt->axp_id == AXP221_ID &&
!(reg & AXP22X_FG_VALID))
return -EINVAL;
val->intval = reg & AXP209_FG_PERCENT;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
if (axp20x_batt->axp_id == AXP209_ID)
return axp20x_battery_get_max_voltage(axp20x_batt,
&val->intval);
return axp22x_battery_get_max_voltage(axp20x_batt,
&val->intval);
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
ret = regmap_read(axp20x_batt->regmap, AXP20X_V_OFF, &reg);
if (ret)
return ret;
val->intval = 2600000 + 100000 * (reg & AXP20X_V_OFF_MASK);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = iio_read_channel_processed(axp20x_batt->batt_v,
&val->intval);
if (ret)
return ret;
val->intval *= 1000;
break;
default:
return -EINVAL;
}
return 0;
}
static int axp20x_battery_set_max_voltage(struct axp20x_batt_ps *axp20x_batt,
int val)
{
switch (val) {
case 4100000:
val = AXP20X_CHRG_CTRL1_TGT_4_1V;
break;
case 4150000:
if (axp20x_batt->axp_id == AXP221_ID)
return -EINVAL;
val = AXP20X_CHRG_CTRL1_TGT_4_15V;
break;
case 4200000:
val = AXP20X_CHRG_CTRL1_TGT_4_2V;
break;
default:
return -EINVAL;
}
return regmap_update_bits(axp20x_batt->regmap, AXP20X_CHRG_CTRL1,
AXP20X_CHRG_CTRL1_TGT_VOLT, val);
}
static int axp20x_set_constant_charge_current(struct axp20x_batt_ps *axp_batt,
int charge_current)
{
if (charge_current > axp_batt->max_ccc)
return -EINVAL;
constant_charge_current_to_raw(axp_batt, &charge_current);
if (charge_current > AXP20X_CHRG_CTRL1_TGT_CURR || charge_current < 0)
return -EINVAL;
return regmap_update_bits(axp_batt->regmap, AXP20X_CHRG_CTRL1,
AXP20X_CHRG_CTRL1_TGT_CURR, charge_current);
}
static int axp20x_set_max_constant_charge_current(struct axp20x_batt_ps *axp,
int charge_current)
{
bool lower_max = false;
constant_charge_current_to_raw(axp, &charge_current);
if (charge_current > AXP20X_CHRG_CTRL1_TGT_CURR || charge_current < 0)
return -EINVAL;
raw_to_constant_charge_current(axp, &charge_current);
if (charge_current > axp->max_ccc)
dev_warn(axp->dev,
"Setting max constant charge current higher than previously defined. Note that increasing the constant charge current may damage your battery.\n");
else
lower_max = true;
axp->max_ccc = charge_current;
if (lower_max) {
int current_cc;
axp20x_get_constant_charge_current(axp, &current_cc);
if (current_cc > charge_current)
axp20x_set_constant_charge_current(axp, charge_current);
}
return 0;
}
static int axp20x_set_voltage_min_design(struct axp20x_batt_ps *axp_batt,
int min_voltage)
{
int val1 = (min_voltage - 2600000) / 100000;
if (val1 < 0 || val1 > AXP20X_V_OFF_MASK)
return -EINVAL;
return regmap_update_bits(axp_batt->regmap, AXP20X_V_OFF,
AXP20X_V_OFF_MASK, val1);
}
static int axp20x_battery_set_prop(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct axp20x_batt_ps *axp20x_batt = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
return axp20x_set_voltage_min_design(axp20x_batt, val->intval);
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
return axp20x_battery_set_max_voltage(axp20x_batt, val->intval);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
return axp20x_set_constant_charge_current(axp20x_batt,
val->intval);
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
return axp20x_set_max_constant_charge_current(axp20x_batt,
val->intval);
default:
return -EINVAL;
}
}
static int axp20x_battery_prop_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
return psp == POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN ||
psp == POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN ||
psp == POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT ||
psp == POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX;
}
static int axp20x_power_probe(struct platform_device *pdev)
{
struct axp20x_batt_ps *axp20x_batt;
struct power_supply_config psy_cfg = {};
struct power_supply_battery_info info;
if (!of_device_is_available(pdev->dev.of_node))
return -ENODEV;
axp20x_batt = devm_kzalloc(&pdev->dev, sizeof(*axp20x_batt),
GFP_KERNEL);
if (!axp20x_batt)
return -ENOMEM;
axp20x_batt->dev = &pdev->dev;
axp20x_batt->batt_v = devm_iio_channel_get(&pdev->dev, "batt_v");
if (IS_ERR(axp20x_batt->batt_v)) {
if (PTR_ERR(axp20x_batt->batt_v) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(axp20x_batt->batt_v);
}
axp20x_batt->batt_chrg_i = devm_iio_channel_get(&pdev->dev,
"batt_chrg_i");
if (IS_ERR(axp20x_batt->batt_chrg_i)) {
if (PTR_ERR(axp20x_batt->batt_chrg_i) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(axp20x_batt->batt_chrg_i);
}
axp20x_batt->batt_dischrg_i = devm_iio_channel_get(&pdev->dev,
"batt_dischrg_i");
if (IS_ERR(axp20x_batt->batt_dischrg_i)) {
if (PTR_ERR(axp20x_batt->batt_dischrg_i) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(axp20x_batt->batt_dischrg_i);
}
axp20x_batt->regmap = dev_get_regmap(pdev->dev.parent, NULL);
platform_set_drvdata(pdev, axp20x_batt);
psy_cfg.drv_data = axp20x_batt;
psy_cfg.of_node = pdev->dev.of_node;
axp20x_batt->axp_id = (uintptr_t)of_device_get_match_data(&pdev->dev);
axp20x_batt->batt = devm_power_supply_register(&pdev->dev,
&axp20x_batt_ps_desc,
&psy_cfg);
if (IS_ERR(axp20x_batt->batt)) {
dev_err(&pdev->dev, "failed to register power supply: %ld\n",
PTR_ERR(axp20x_batt->batt));
return PTR_ERR(axp20x_batt->batt);
}
if (!power_supply_get_battery_info(axp20x_batt->batt, &info)) {
int vmin = info.voltage_min_design_uv;
int ccc = info.constant_charge_current_max_ua;
if (vmin > 0 && axp20x_set_voltage_min_design(axp20x_batt,
vmin))
dev_err(&pdev->dev,
"couldn't set voltage_min_design\n");
axp20x_batt->max_ccc = ccc;
if (ccc <= 0 || axp20x_set_constant_charge_current(axp20x_batt,
ccc)) {
dev_err(&pdev->dev,
"couldn't set constant charge current from DT: fallback to minimum value\n");
ccc = 300000;
axp20x_batt->max_ccc = ccc;
axp20x_set_constant_charge_current(axp20x_batt, ccc);
}
}
axp20x_get_constant_charge_current(axp20x_batt,
&axp20x_batt->max_ccc);
return 0;
}
