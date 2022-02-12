static int max14577_get_charger_state(struct max14577_charger *chg)
{
struct regmap *rmap = chg->max14577->regmap;
int state = POWER_SUPPLY_STATUS_DISCHARGING;
u8 reg_data;
max14577_read_reg(rmap, MAX14577_CHG_REG_CHG_CTRL2, &reg_data);
if ((reg_data & CHGCTRL2_MBCHOSTEN_MASK) == 0)
goto state_set;
max14577_read_reg(rmap, MAX14577_CHG_REG_STATUS3, &reg_data);
if (reg_data & STATUS3_CGMBC_MASK) {
if (reg_data & STATUS3_EOC_MASK)
state = POWER_SUPPLY_STATUS_FULL;
else
state = POWER_SUPPLY_STATUS_CHARGING;
goto state_set;
}
state_set:
chg->charging_state = state;
return state;
}
static int max14577_get_charge_type(struct max14577_charger *chg)
{
if (max14577_get_charger_state(chg) == POWER_SUPPLY_STATUS_CHARGING)
return POWER_SUPPLY_CHARGE_TYPE_FAST;
return POWER_SUPPLY_CHARGE_TYPE_NONE;
}
static int max14577_get_online(struct max14577_charger *chg)
{
struct regmap *rmap = chg->max14577->regmap;
u8 reg_data;
max14577_read_reg(rmap, MAX14577_MUIC_REG_STATUS2, &reg_data);
reg_data = ((reg_data & STATUS2_CHGTYP_MASK) >> STATUS2_CHGTYP_SHIFT);
switch (reg_data) {
case MAX14577_CHARGER_TYPE_USB:
case MAX14577_CHARGER_TYPE_DEDICATED_CHG:
case MAX14577_CHARGER_TYPE_SPECIAL_500MA:
case MAX14577_CHARGER_TYPE_SPECIAL_1A:
case MAX14577_CHARGER_TYPE_DEAD_BATTERY:
return 1;
case MAX14577_CHARGER_TYPE_NONE:
case MAX14577_CHARGER_TYPE_DOWNSTREAM_PORT:
case MAX14577_CHARGER_TYPE_RESERVED:
default:
return 0;
}
}
static int max14577_get_battery_health(struct max14577_charger *chg)
{
struct regmap *rmap = chg->max14577->regmap;
int state = POWER_SUPPLY_HEALTH_GOOD;
u8 reg_data;
max14577_read_reg(rmap, MAX14577_MUIC_REG_STATUS2, &reg_data);
reg_data = ((reg_data & STATUS2_CHGTYP_MASK) >> STATUS2_CHGTYP_SHIFT);
if (reg_data == MAX14577_CHARGER_TYPE_DEAD_BATTERY) {
state = POWER_SUPPLY_HEALTH_DEAD;
goto state_set;
}
max14577_read_reg(rmap, MAX14577_CHG_REG_STATUS3, &reg_data);
if (reg_data & STATUS3_OVP_MASK) {
state = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
goto state_set;
}
state_set:
chg->battery_state = state;
return state;
}
static int max14577_get_present(struct max14577_charger *chg)
{
return 1;
}
static void max14577_charger_reg_init(struct max14577_charger *chg)
{
struct regmap *rmap = chg->max14577->regmap;
u8 reg_data;
reg_data = 0x1 << CDETCTRL1_CHGDETEN_SHIFT;
max14577_update_reg(rmap, MAX14577_REG_CDETCTRL1,
CDETCTRL1_CHGDETEN_MASK | CDETCTRL1_CHGTYPMAN_MASK,
reg_data);
reg_data = 0x3 << CHGCTRL1_TCHW_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL1, reg_data);
reg_data = 0x1 << CHGCTRL2_VCHGR_RC_SHIFT;
reg_data |= 0x1 << CHGCTRL2_MBCHOSTEN_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL2, reg_data);
reg_data = 0xf << CHGCTRL3_MBCCVWRC_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL3, reg_data);
reg_data = 0x1 << CHGCTRL4_MBCICHWRCL_SHIFT;
reg_data |= 0x5 << CHGCTRL4_MBCICHWRCH_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL4, reg_data);
reg_data = 0x0 << CHGCTRL5_EOCS_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL5, reg_data);
reg_data = 0x0 << CHGCTRL6_AUTOSTOP_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL6, reg_data);
reg_data = 0x2 << CHGCTRL7_OTPCGHCVS_SHIFT;
max14577_write_reg(rmap, MAX14577_REG_CHGCTRL7, reg_data);
}
static int max14577_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max14577_charger *chg = container_of(psy,
struct max14577_charger,
charger);
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = max14577_get_charger_state(chg);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
val->intval = max14577_get_charge_type(chg);
break;
case POWER_SUPPLY_PROP_HEALTH:
val->intval = max14577_get_battery_health(chg);
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = max14577_get_present(chg);
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = max14577_get_online(chg);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = model_name;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = manufacturer;
break;
default:
return -EINVAL;
}
return ret;
}
static int max14577_charger_probe(struct platform_device *pdev)
{
struct max14577_charger *chg;
struct max14577 *max14577 = dev_get_drvdata(pdev->dev.parent);
int ret;
chg = devm_kzalloc(&pdev->dev, sizeof(*chg), GFP_KERNEL);
if (!chg)
return -ENOMEM;
platform_set_drvdata(pdev, chg);
chg->dev = &pdev->dev;
chg->max14577 = max14577;
max14577_charger_reg_init(chg);
chg->charger.name = "max14577-charger",
chg->charger.type = POWER_SUPPLY_TYPE_BATTERY,
chg->charger.properties = max14577_charger_props,
chg->charger.num_properties = ARRAY_SIZE(max14577_charger_props),
chg->charger.get_property = max14577_charger_get_property,
ret = power_supply_register(&pdev->dev, &chg->charger);
if (ret) {
dev_err(&pdev->dev, "failed: power supply register\n");
return ret;
}
return 0;
}
static int max14577_charger_remove(struct platform_device *pdev)
{
struct max14577_charger *chg = platform_get_drvdata(pdev);
power_supply_unregister(&chg->charger);
return 0;
}
