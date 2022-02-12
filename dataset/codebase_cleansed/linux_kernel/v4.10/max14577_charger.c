static enum max14577_muic_charger_type maxim_get_charger_type(
enum maxim_device_type dev_type, u8 val) {
switch (val) {
case MAX14577_CHARGER_TYPE_NONE:
case MAX14577_CHARGER_TYPE_USB:
case MAX14577_CHARGER_TYPE_DOWNSTREAM_PORT:
case MAX14577_CHARGER_TYPE_DEDICATED_CHG:
case MAX14577_CHARGER_TYPE_SPECIAL_500MA:
case MAX14577_CHARGER_TYPE_SPECIAL_1A:
return val;
case MAX14577_CHARGER_TYPE_DEAD_BATTERY:
case MAX14577_CHARGER_TYPE_RESERVED:
if (dev_type == MAXIM_DEVICE_TYPE_MAX77836)
val |= 0x8;
return val;
default:
WARN_ONCE(1, "max14577: Unsupported chgtyp register value 0x%02x", val);
return val;
}
}
static int max14577_get_charger_state(struct max14577_charger *chg, int *val)
{
struct regmap *rmap = chg->max14577->regmap;
int ret;
u8 reg_data;
ret = max14577_read_reg(rmap, MAX14577_CHG_REG_CHG_CTRL2, &reg_data);
if (ret < 0)
goto out;
if ((reg_data & CHGCTRL2_MBCHOSTEN_MASK) == 0) {
*val = POWER_SUPPLY_STATUS_DISCHARGING;
goto out;
}
ret = max14577_read_reg(rmap, MAX14577_CHG_REG_STATUS3, &reg_data);
if (ret < 0)
goto out;
if (reg_data & STATUS3_CGMBC_MASK) {
if (reg_data & STATUS3_EOC_MASK)
*val = POWER_SUPPLY_STATUS_FULL;
else
*val = POWER_SUPPLY_STATUS_CHARGING;
goto out;
}
*val = POWER_SUPPLY_STATUS_DISCHARGING;
out:
return ret;
}
static int max14577_get_charge_type(struct max14577_charger *chg, int *val)
{
int ret, charging;
ret = max14577_get_charger_state(chg, &charging);
if (ret < 0)
return ret;
if (charging == POWER_SUPPLY_STATUS_CHARGING)
*val = POWER_SUPPLY_CHARGE_TYPE_FAST;
else
*val = POWER_SUPPLY_CHARGE_TYPE_NONE;
return 0;
}
static int max14577_get_online(struct max14577_charger *chg, int *val)
{
struct regmap *rmap = chg->max14577->regmap;
u8 reg_data;
int ret;
enum max14577_muic_charger_type chg_type;
ret = max14577_read_reg(rmap, MAX14577_MUIC_REG_STATUS2, &reg_data);
if (ret < 0)
return ret;
reg_data = ((reg_data & STATUS2_CHGTYP_MASK) >> STATUS2_CHGTYP_SHIFT);
chg_type = maxim_get_charger_type(chg->max14577->dev_type, reg_data);
switch (chg_type) {
case MAX14577_CHARGER_TYPE_USB:
case MAX14577_CHARGER_TYPE_DEDICATED_CHG:
case MAX14577_CHARGER_TYPE_SPECIAL_500MA:
case MAX14577_CHARGER_TYPE_SPECIAL_1A:
case MAX14577_CHARGER_TYPE_DEAD_BATTERY:
case MAX77836_CHARGER_TYPE_SPECIAL_BIAS:
*val = 1;
break;
case MAX14577_CHARGER_TYPE_NONE:
case MAX14577_CHARGER_TYPE_DOWNSTREAM_PORT:
case MAX14577_CHARGER_TYPE_RESERVED:
case MAX77836_CHARGER_TYPE_RESERVED:
default:
*val = 0;
}
return 0;
}
static int max14577_get_battery_health(struct max14577_charger *chg, int *val)
{
struct regmap *rmap = chg->max14577->regmap;
int ret;
u8 reg_data;
enum max14577_muic_charger_type chg_type;
ret = max14577_read_reg(rmap, MAX14577_MUIC_REG_STATUS2, &reg_data);
if (ret < 0)
goto out;
reg_data = ((reg_data & STATUS2_CHGTYP_MASK) >> STATUS2_CHGTYP_SHIFT);
chg_type = maxim_get_charger_type(chg->max14577->dev_type, reg_data);
if (chg_type == MAX14577_CHARGER_TYPE_DEAD_BATTERY) {
*val = POWER_SUPPLY_HEALTH_DEAD;
goto out;
}
ret = max14577_read_reg(rmap, MAX14577_CHG_REG_STATUS3, &reg_data);
if (ret < 0)
goto out;
if (reg_data & STATUS3_OVP_MASK) {
*val = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
goto out;
}
*val = POWER_SUPPLY_HEALTH_GOOD;
out:
return ret;
}
static int max14577_get_present(struct max14577_charger *chg, int *val)
{
*val = 1;
return 0;
}
static int max14577_set_fast_charge_timer(struct max14577_charger *chg,
unsigned long hours)
{
u8 reg_data;
switch (hours) {
case 5 ... 7:
reg_data = hours - 3;
break;
case 0:
reg_data = 0x7;
break;
default:
dev_err(chg->dev, "Wrong value for Fast-Charge Timer: %lu\n",
hours);
return -EINVAL;
}
reg_data <<= CHGCTRL1_TCHW_SHIFT;
return max14577_update_reg(chg->max14577->regmap,
MAX14577_REG_CHGCTRL1, CHGCTRL1_TCHW_MASK, reg_data);
}
static int max14577_init_constant_voltage(struct max14577_charger *chg,
unsigned int uvolt)
{
u8 reg_data;
if (uvolt < MAXIM_CHARGER_CONSTANT_VOLTAGE_MIN ||
uvolt > MAXIM_CHARGER_CONSTANT_VOLTAGE_MAX)
return -EINVAL;
if (uvolt == 4200000)
reg_data = 0x0;
else if (uvolt == MAXIM_CHARGER_CONSTANT_VOLTAGE_MAX)
reg_data = 0x1f;
else if (uvolt <= 4280000) {
unsigned int val = uvolt;
val -= MAXIM_CHARGER_CONSTANT_VOLTAGE_MIN;
val /= MAXIM_CHARGER_CONSTANT_VOLTAGE_STEP;
if (uvolt <= 4180000)
reg_data = 0x1 + val;
else
reg_data = val;
} else
return -EINVAL;
reg_data <<= CHGCTRL3_MBCCVWRC_SHIFT;
return max14577_write_reg(chg->max14577->regmap,
MAX14577_CHG_REG_CHG_CTRL3, reg_data);
}
static int max14577_init_eoc(struct max14577_charger *chg,
unsigned int uamp)
{
unsigned int current_bits = 0xf;
u8 reg_data;
switch (chg->max14577->dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
if (uamp < 5000)
return -EINVAL;
if (uamp >= 7500 && uamp < 10000)
current_bits = 0x0;
else if (uamp <= 50000) {
current_bits = uamp / 5000;
} else {
uamp = min(uamp, 100000U) - 50000U;
current_bits = 0xa + uamp / 10000;
}
break;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
if (uamp < MAX14577_CHARGER_EOC_CURRENT_LIMIT_MIN)
return -EINVAL;
uamp = min(uamp, MAX14577_CHARGER_EOC_CURRENT_LIMIT_MAX);
uamp -= MAX14577_CHARGER_EOC_CURRENT_LIMIT_MIN;
current_bits = uamp / MAX14577_CHARGER_EOC_CURRENT_LIMIT_STEP;
break;
}
reg_data = current_bits << CHGCTRL5_EOCS_SHIFT;
return max14577_update_reg(chg->max14577->regmap,
MAX14577_CHG_REG_CHG_CTRL5, CHGCTRL5_EOCS_MASK,
reg_data);
}
static int max14577_init_fast_charge(struct max14577_charger *chg,
unsigned int uamp)
{
u8 reg_data;
int ret;
const struct maxim_charger_current *limits =
&maxim_charger_currents[chg->max14577->dev_type];
ret = maxim_charger_calc_reg_current(limits, uamp, uamp, &reg_data);
if (ret) {
dev_err(chg->dev, "Wrong value for fast charge: %u\n", uamp);
return ret;
}
return max14577_update_reg(chg->max14577->regmap,
MAX14577_CHG_REG_CHG_CTRL4,
CHGCTRL4_MBCICHWRCL_MASK | CHGCTRL4_MBCICHWRCH_MASK,
reg_data);
}
static int max14577_charger_reg_init(struct max14577_charger *chg)
{
struct regmap *rmap = chg->max14577->regmap;
u8 reg_data;
int ret;
reg_data = 0x1 << CDETCTRL1_CHGDETEN_SHIFT;
max14577_update_reg(rmap, MAX14577_REG_CDETCTRL1,
CDETCTRL1_CHGDETEN_MASK | CDETCTRL1_CHGTYPMAN_MASK,
reg_data);
reg_data = 0x1 << CHGCTRL2_VCHGR_RC_SHIFT;
reg_data |= 0x1 << CHGCTRL2_MBCHOSTEN_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL2, reg_data);
reg_data = 0x0 << CHGCTRL6_AUTOSTOP_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL6, reg_data);
ret = max14577_init_constant_voltage(chg, chg->pdata->constant_uvolt);
if (ret)
return ret;
ret = max14577_init_eoc(chg, chg->pdata->eoc_uamp);
if (ret)
return ret;
ret = max14577_init_fast_charge(chg, chg->pdata->fast_charge_uamp);
if (ret)
return ret;
ret = max14577_set_fast_charge_timer(chg,
MAXIM_CHARGER_FAST_CHARGE_TIMER_DEFAULT);
if (ret)
return ret;
switch (chg->pdata->ovp_uvolt) {
case 7500000:
reg_data = 0x0;
break;
case 6000000:
case 6500000:
case 7000000:
reg_data = 0x1 + (chg->pdata->ovp_uvolt - 6000000) / 500000;
break;
default:
dev_err(chg->dev, "Wrong value for OVP: %u\n",
chg->pdata->ovp_uvolt);
return -EINVAL;
}
reg_data <<= CHGCTRL7_OTPCGHCVS_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL7, reg_data);
return 0;
}
static int max14577_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max14577_charger *chg = power_supply_get_drvdata(psy);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = max14577_get_charger_state(chg, &val->intval);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = max14577_get_charge_type(chg, &val->intval);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = max14577_get_battery_health(chg, &val->intval);
break;
case POWER_SUPPLY_PROP_PRESENT:
ret = max14577_get_present(chg, &val->intval);
break;
case POWER_SUPPLY_PROP_ONLINE:
ret = max14577_get_online(chg, &val->intval);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
BUILD_BUG_ON(ARRAY_SIZE(model_names) != MAXIM_DEVICE_TYPE_NUM);
val->strval = model_names[chg->max14577->dev_type];
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = manufacturer;
break;
default:
return -EINVAL;
}
return ret;
}
static struct max14577_charger_platform_data *max14577_charger_dt_init(
struct platform_device *pdev)
{
struct max14577_charger_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
int ret;
if (!np) {
dev_err(&pdev->dev, "No charger OF node\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
ret = of_property_read_u32(np, "maxim,constant-uvolt",
&pdata->constant_uvolt);
if (ret) {
dev_err(&pdev->dev, "Cannot parse maxim,constant-uvolt field from DT\n");
return ERR_PTR(ret);
}
ret = of_property_read_u32(np, "maxim,fast-charge-uamp",
&pdata->fast_charge_uamp);
if (ret) {
dev_err(&pdev->dev, "Cannot parse maxim,fast-charge-uamp field from DT\n");
return ERR_PTR(ret);
}
ret = of_property_read_u32(np, "maxim,eoc-uamp", &pdata->eoc_uamp);
if (ret) {
dev_err(&pdev->dev, "Cannot parse maxim,eoc-uamp field from DT\n");
return ERR_PTR(ret);
}
ret = of_property_read_u32(np, "maxim,ovp-uvolt", &pdata->ovp_uvolt);
if (ret) {
dev_err(&pdev->dev, "Cannot parse maxim,ovp-uvolt field from DT\n");
return ERR_PTR(ret);
}
return pdata;
}
static struct max14577_charger_platform_data *max14577_charger_dt_init(
struct platform_device *pdev)
{
return NULL;
}
static ssize_t show_fast_charge_timer(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct max14577_charger *chg = dev_get_drvdata(dev);
u8 reg_data;
int ret;
unsigned int val;
ret = max14577_read_reg(chg->max14577->regmap, MAX14577_REG_CHGCTRL1,
&reg_data);
if (ret)
return ret;
reg_data &= CHGCTRL1_TCHW_MASK;
reg_data >>= CHGCTRL1_TCHW_SHIFT;
switch (reg_data) {
case 0x2 ... 0x4:
val = reg_data + 3;
break;
case 0x7:
val = 0;
break;
default:
val = 5;
break;
}
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static ssize_t store_fast_charge_timer(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct max14577_charger *chg = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
ret = max14577_set_fast_charge_timer(chg, val);
if (ret)
return ret;
return count;
}
static int max14577_charger_probe(struct platform_device *pdev)
{
struct max14577_charger *chg;
struct power_supply_config psy_cfg = {};
struct max14577 *max14577 = dev_get_drvdata(pdev->dev.parent);
int ret;
chg = devm_kzalloc(&pdev->dev, sizeof(*chg), GFP_KERNEL);
if (!chg)
return -ENOMEM;
platform_set_drvdata(pdev, chg);
chg->dev = &pdev->dev;
chg->max14577 = max14577;
chg->pdata = max14577_charger_dt_init(pdev);
if (IS_ERR_OR_NULL(chg->pdata))
return PTR_ERR(chg->pdata);
ret = max14577_charger_reg_init(chg);
if (ret)
return ret;
ret = device_create_file(&pdev->dev, &dev_attr_fast_charge_timer);
if (ret) {
dev_err(&pdev->dev, "failed: create sysfs entry\n");
return ret;
}
psy_cfg.drv_data = chg;
chg->charger = power_supply_register(&pdev->dev, &max14577_charger_desc,
&psy_cfg);
if (IS_ERR(chg->charger)) {
dev_err(&pdev->dev, "failed: power supply register\n");
ret = PTR_ERR(chg->charger);
goto err;
}
BUILD_BUG_ON(MAX14577_CHARGER_EOC_CURRENT_LIMIT_MIN +
MAX14577_CHARGER_EOC_CURRENT_LIMIT_STEP * 0xf !=
MAX14577_CHARGER_EOC_CURRENT_LIMIT_MAX);
return 0;
err:
device_remove_file(&pdev->dev, &dev_attr_fast_charge_timer);
return ret;
}
static int max14577_charger_remove(struct platform_device *pdev)
{
struct max14577_charger *chg = platform_get_drvdata(pdev);
device_remove_file(&pdev->dev, &dev_attr_fast_charge_timer);
power_supply_unregister(chg->charger);
return 0;
}
