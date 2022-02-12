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
switch (state) {
case APCH_STATE_CSTATE_PRE:
case APCH_STATE_CSTATE_FAST:
*val = POWER_SUPPLY_STATUS_CHARGING;
break;
case APCH_STATE_CSTATE_EOC:
if (status & APCH_STATUS_CHGDAT)
*val = POWER_SUPPLY_STATUS_FULL;
else
*val = POWER_SUPPLY_STATUS_CHARGING;
break;
case APCH_STATE_CSTATE_DISABLED:
default:
if (!(status & APCH_STATUS_INDAT))
*val = POWER_SUPPLY_STATUS_DISCHARGING;
else
*val = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
}
return 0;
}
static int act8945a_get_charge_type(struct regmap *regmap, int *val)
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
switch (state) {
case APCH_STATE_CSTATE_PRE:
*val = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case APCH_STATE_CSTATE_FAST:
*val = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
case APCH_STATE_CSTATE_EOC:
*val = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
case APCH_STATE_CSTATE_DISABLED:
default:
if (!(status & APCH_STATUS_INDAT))
*val = POWER_SUPPLY_CHARGE_TYPE_NONE;
else
*val = POWER_SUPPLY_CHARGE_TYPE_UNKNOWN;
break;
}
return 0;
}
static int act8945a_get_battery_health(struct regmap *regmap, int *val)
{
int ret;
unsigned int status, state, config;
ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_CFG, &config);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
state &= APCH_STATE_CSTATE;
state >>= APCH_STATE_CSTATE_SHIFT;
switch (state) {
case APCH_STATE_CSTATE_DISABLED:
if (config & APCH_CFG_SUSCHG) {
*val = POWER_SUPPLY_HEALTH_UNKNOWN;
} else if (status & APCH_STATUS_INDAT) {
if (!(status & APCH_STATUS_TEMPDAT))
*val = POWER_SUPPLY_HEALTH_OVERHEAT;
else if (status & APCH_STATUS_TIMRDAT)
*val = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
else
*val = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
} else {
*val = POWER_SUPPLY_HEALTH_GOOD;
}
break;
case APCH_STATE_CSTATE_PRE:
case APCH_STATE_CSTATE_FAST:
case APCH_STATE_CSTATE_EOC:
default:
*val = POWER_SUPPLY_HEALTH_GOOD;
break;
}
return 0;
}
static int act8945a_get_capacity_level(struct act8945a_charger *charger,
struct regmap *regmap, int *val)
{
int ret;
unsigned int status, state, config;
int lbo_level = gpiod_get_value(charger->lbo_gpio);
ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_CFG, &config);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
state &= APCH_STATE_CSTATE;
state >>= APCH_STATE_CSTATE_SHIFT;
switch (state) {
case APCH_STATE_CSTATE_PRE:
*val = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
break;
case APCH_STATE_CSTATE_FAST:
if (lbo_level)
*val = POWER_SUPPLY_CAPACITY_LEVEL_HIGH;
else
*val = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
break;
case APCH_STATE_CSTATE_EOC:
if (status & APCH_STATUS_CHGDAT)
*val = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
else
*val = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
break;
case APCH_STATE_CSTATE_DISABLED:
default:
if (config & APCH_CFG_SUSCHG) {
*val = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
} else {
*val = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
if (!(status & APCH_STATUS_INDAT)) {
if (!lbo_level)
*val = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
}
}
break;
}
return 0;
}
static int act8945a_get_current_max(struct act8945a_charger *charger,
struct regmap *regmap, int *val)
{
int ret;
unsigned int status, state;
unsigned int acin_state;
int chgin_level = gpiod_get_value(charger->chglev_gpio);
ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
acin_state = (state & APCH_STATE_ACINSTAT) >> 1;
state &= APCH_STATE_CSTATE;
state >>= APCH_STATE_CSTATE_SHIFT;
switch (state) {
case APCH_STATE_CSTATE_PRE:
if (acin_state) {
if (chgin_level)
*val = MAX_CURRENT_AC_HIGH_PRE;
else
*val = MAX_CURRENT_AC_LOW_PRE;
} else {
*val = MAX_CURRENT_USB_PRE;
}
break;
case APCH_STATE_CSTATE_FAST:
if (acin_state) {
if (chgin_level)
*val = MAX_CURRENT_AC_HIGH;
else
*val = MAX_CURRENT_AC_LOW;
} else {
if (chgin_level)
*val = MAX_CURRENT_USB_HIGH;
else
*val = MAX_CURRENT_USB_LOW;
}
break;
case APCH_STATE_CSTATE_EOC:
case APCH_STATE_CSTATE_DISABLED:
default:
*val = 0;
break;
}
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
ret = act8945a_get_battery_health(regmap, &val->intval);
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
ret = act8945a_get_capacity_level(charger,
regmap, &val->intval);
break;
case POWER_SUPPLY_PROP_CURRENT_MAX:
ret = act8945a_get_current_max(charger,
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
static int act8945a_enable_interrupt(struct act8945a_charger *charger)
{
struct regmap *regmap = charger->regmap;
unsigned char ctrl;
int ret;
ctrl = APCH_CTRL_CHGEOCOUT | APCH_CTRL_CHGEOCIN |
APCH_CTRL_INDIS | APCH_CTRL_INCON |
APCH_CTRL_TEMPOUT | APCH_CTRL_TEMPIN |
APCH_CTRL_TIMRPRE | APCH_CTRL_TIMRTOT;
ret = regmap_write(regmap, ACT8945A_APCH_CTRL, ctrl);
if (ret)
return ret;
ctrl = APCH_STATUS_CHGSTAT | APCH_STATUS_INSTAT |
APCH_STATUS_TEMPSTAT | APCH_STATUS_TIMRSTAT;
ret = regmap_write(regmap, ACT8945A_APCH_STATUS, ctrl);
if (ret)
return ret;
return 0;
}
static unsigned int act8945a_set_supply_type(struct act8945a_charger *charger,
unsigned int *type)
{
unsigned int status, state;
int ret;
ret = regmap_read(charger->regmap, ACT8945A_APCH_STATUS, &status);
if (ret < 0)
return ret;
ret = regmap_read(charger->regmap, ACT8945A_APCH_STATE, &state);
if (ret < 0)
return ret;
if (status & APCH_STATUS_INDAT) {
if (state & APCH_STATE_ACINSTAT)
*type = POWER_SUPPLY_TYPE_MAINS;
else
*type = POWER_SUPPLY_TYPE_USB;
} else {
*type = POWER_SUPPLY_TYPE_BATTERY;
}
return 0;
}
static void act8945a_work(struct work_struct *work)
{
struct act8945a_charger *charger =
container_of(work, struct act8945a_charger, work);
act8945a_set_supply_type(charger, &charger->desc.type);
power_supply_changed(charger->psy);
}
static irqreturn_t act8945a_status_changed(int irq, void *dev_id)
{
struct act8945a_charger *charger = dev_id;
if (charger->init_done)
schedule_work(&charger->work);
return IRQ_HANDLED;
}
static int act8945a_charger_config(struct device *dev,
struct act8945a_charger *charger)
{
struct device_node *np = dev->of_node;
struct regmap *regmap = charger->regmap;
u32 total_time_out;
u32 pre_time_out;
u32 input_voltage_threshold;
int err, ret;
unsigned int tmp;
unsigned int value = 0;
if (!np) {
dev_err(dev, "no charger of node\n");
return -EINVAL;
}
ret = regmap_read(regmap, ACT8945A_APCH_CFG, &tmp);
if (ret)
return ret;
if (tmp & APCH_CFG_SUSCHG) {
value |= APCH_CFG_SUSCHG;
dev_info(dev, "have been suspended\n");
}
charger->lbo_gpio = devm_gpiod_get_optional(dev, "active-semi,lbo",
GPIOD_IN);
if (IS_ERR(charger->lbo_gpio)) {
err = PTR_ERR(charger->lbo_gpio);
dev_err(dev, "unable to claim gpio \"lbo\": %d\n", err);
return err;
}
ret = devm_request_irq(dev, gpiod_to_irq(charger->lbo_gpio),
act8945a_status_changed,
(IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING),
"act8945a_lbo_detect", charger);
if (ret)
dev_info(dev, "failed to request gpio \"lbo\" IRQ\n");
charger->chglev_gpio = devm_gpiod_get_optional(dev,
"active-semi,chglev",
GPIOD_IN);
if (IS_ERR(charger->chglev_gpio)) {
err = PTR_ERR(charger->chglev_gpio);
dev_err(dev, "unable to claim gpio \"chglev\": %d\n", err);
return err;
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
struct power_supply_config psy_cfg = {};
int irq, ret;
charger = devm_kzalloc(&pdev->dev, sizeof(*charger), GFP_KERNEL);
if (!charger)
return -ENOMEM;
charger->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!charger->regmap) {
dev_err(&pdev->dev, "Parent did not provide regmap\n");
return -EINVAL;
}
ret = act8945a_charger_config(&pdev->dev, charger);
if (ret)
return ret;
irq = of_irq_get(pdev->dev.of_node, 0);
if (irq == -EPROBE_DEFER) {
dev_err(&pdev->dev, "failed to find IRQ number\n");
return -EPROBE_DEFER;
}
ret = devm_request_irq(&pdev->dev, irq, act8945a_status_changed,
IRQF_TRIGGER_FALLING, "act8945a_interrupt",
charger);
if (ret) {
dev_err(&pdev->dev, "failed to request nIRQ pin IRQ\n");
return ret;
}
charger->desc.name = "act8945a-charger";
charger->desc.get_property = act8945a_charger_get_property;
charger->desc.properties = act8945a_charger_props;
charger->desc.num_properties = ARRAY_SIZE(act8945a_charger_props);
ret = act8945a_set_supply_type(charger, &charger->desc.type);
if (ret)
return -EINVAL;
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = charger;
charger->psy = devm_power_supply_register(&pdev->dev,
&charger->desc,
&psy_cfg);
if (IS_ERR(charger->psy)) {
dev_err(&pdev->dev, "failed to register power supply\n");
return PTR_ERR(charger->psy);
}
platform_set_drvdata(pdev, charger);
INIT_WORK(&charger->work, act8945a_work);
ret = act8945a_enable_interrupt(charger);
if (ret)
return -EIO;
charger->init_done = true;
return 0;
}
static int act8945a_charger_remove(struct platform_device *pdev)
{
struct act8945a_charger *charger = platform_get_drvdata(pdev);
charger->init_done = false;
cancel_work_sync(&charger->work);
return 0;
}
