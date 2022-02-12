static int act8945a_get_charger_state(struct regmap *regmap, int *val)
{
int ret;
unsigned int status, state;
ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
state &= APCH_STATE_CSTATE;
state >>= APCH_STATE_CSTATE_SHIFT;
if (state == APCH_STATE_CSTATE_EOC) {
if (status & APCH_STATUS_CHGDAT)
*val = POWER_SUPPLY_STATUS_FULL;
else
*val = POWER_SUPPLY_STATUS_NOT_CHARGING;
} else if ((state == APCH_STATE_CSTATE_FAST) ||
(state == APCH_STATE_CSTATE_PRE)) {
*val = POWER_SUPPLY_STATUS_CHARGING;
} else {
*val = POWER_SUPPLY_STATUS_NOT_CHARGING;
}
return 0;
}
static int act8945a_get_charge_type(struct regmap *regmap, int *val)
{
int ret;
unsigned int state;
ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
state &= APCH_STATE_CSTATE;
state >>= APCH_STATE_CSTATE_SHIFT;
switch (state) {
case APCH_STATE_CSTATE_PRE:
*val = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case APCH_STATE_CSTATE_FAST:
*val = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
case APCH_STATE_CSTATE_EOC:
case APCH_STATE_CSTATE_DISABLED:
default:
*val = POWER_SUPPLY_CHARGE_TYPE_NONE;
}
return 0;
}
static int act8945a_get_battery_health(struct act8945a_charger *charger,
struct regmap *regmap, int *val)
{
int ret;
unsigned int status;
ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
if (charger->battery_temperature && !(status & APCH_STATUS_TEMPDAT))
*val = POWER_SUPPLY_HEALTH_OVERHEAT;
else if (!(status & APCH_STATUS_INDAT))
*val = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
else if (status & APCH_STATUS_TIMRDAT)
*val = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
else
*val = POWER_SUPPLY_HEALTH_GOOD;
return 0;
}
static int act8945a_charger_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct act8945a_charger *charger = power_supply_get_drvdata(psy);
struct regmap *regmap = charger->regmap;
int ret = 0;
switch (prop) {
case POWER_SUPPLY_PROP_STATUS:
ret = act8945a_get_charger_state(regmap, &val->intval);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = act8945a_get_charge_type(regmap, &val->intval);
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = act8945a_get_battery_health(charger,
regmap, &val->intval);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = act8945a_charger_model;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = act8945a_charger_manufacturer;
break;
default:
return -EINVAL;
}
return ret;
}
static int act8945a_charger_config(struct device *dev,
struct act8945a_charger *charger)
{
struct device_node *np = dev->of_node;
enum of_gpio_flags flags;
struct regmap *regmap = charger->regmap;
u32 total_time_out;
u32 pre_time_out;
u32 input_voltage_threshold;
int chglev_pin;
unsigned int value = 0;
if (!np) {
dev_err(dev, "no charger of node\n");
return -EINVAL;
}
charger->battery_temperature = of_property_read_bool(np,
"active-semi,check-battery-temperature");
chglev_pin = of_get_named_gpio_flags(np,
"active-semi,chglev-gpios", 0, &flags);
if (gpio_is_valid(chglev_pin)) {
gpio_set_value(chglev_pin,
((flags == OF_GPIO_ACTIVE_LOW) ? 0 : 1));
}
if (of_property_read_u32(np,
"active-semi,input-voltage-threshold-microvolt",
&input_voltage_threshold))
input_voltage_threshold = DEFAULT_INPUT_OVP_THRESHOLD;
if (of_property_read_u32(np,
"active-semi,precondition-timeout",
&pre_time_out))
pre_time_out = DEFAULT_PRE_TIME_OUT;
if (of_property_read_u32(np, "active-semi,total-timeout",
&total_time_out))
total_time_out = DEFAULT_TOTAL_TIME_OUT;
switch (input_voltage_threshold) {
case 8000:
value |= APCH_CFG_OVPSET_8V;
break;
case 7500:
value |= APCH_CFG_OVPSET_7V5;
break;
case 7000:
value |= APCH_CFG_OVPSET_7V;
break;
case 6600:
default:
value |= APCH_CFG_OVPSET_6V6;
break;
}
switch (pre_time_out) {
case 60:
value |= APCH_CFG_PRETIMO_60_MIN;
break;
case 80:
value |= APCH_CFG_PRETIMO_80_MIN;
break;
case 0:
value |= APCH_CFG_PRETIMO_DISABLED;
break;
case 40:
default:
value |= APCH_CFG_PRETIMO_40_MIN;
break;
}
switch (total_time_out) {
case 4:
value |= APCH_CFG_TOTTIMO_4_HOUR;
break;
case 5:
value |= APCH_CFG_TOTTIMO_5_HOUR;
break;
case 0:
value |= APCH_CFG_TOTTIMO_DISABLED;
break;
case 3:
default:
value |= APCH_CFG_TOTTIMO_3_HOUR;
break;
}
return regmap_write(regmap, ACT8945A_APCH_CFG, value);
}
static int act8945a_charger_probe(struct platform_device *pdev)
{
struct act8945a_charger *charger;
struct power_supply *psy;
struct power_supply_config psy_cfg = {};
int ret;
charger = devm_kzalloc(&pdev->dev, sizeof(*charger), GFP_KERNEL);
if (!charger)
return -ENOMEM;
charger->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!charger->regmap) {
dev_err(&pdev->dev, "Parent did not provide regmap\n");
return -EINVAL;
}
ret = act8945a_charger_config(pdev->dev.parent, charger);
if (ret)
return ret;
psy_cfg.of_node = pdev->dev.parent->of_node;
psy_cfg.drv_data = charger;
psy = devm_power_supply_register(&pdev->dev,
&act8945a_charger_desc,
&psy_cfg);
if (IS_ERR(psy)) {
dev_err(&pdev->dev, "failed to register power supply\n");
return PTR_ERR(psy);
}
return 0;
}
