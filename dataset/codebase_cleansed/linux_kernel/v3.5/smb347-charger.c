static int current_to_hw(const unsigned int *tbl, size_t size, unsigned int val)
{
size_t i;
for (i = 0; i < size; i++)
if (val < tbl[i])
break;
return i > 0 ? i - 1 : -EINVAL;
}
static int smb347_update_ps_status(struct smb347_charger *smb)
{
bool usb = false;
bool dc = false;
unsigned int val;
int ret;
ret = regmap_read(smb->regmap, IRQSTAT_E, &val);
if (ret < 0)
return ret;
if (smb->pdata->use_mains)
dc = !(val & IRQSTAT_E_DCIN_UV_STAT);
if (smb->pdata->use_usb)
usb = !(val & IRQSTAT_E_USBIN_UV_STAT);
mutex_lock(&smb->lock);
ret = smb->mains_online != dc || smb->usb_online != usb;
smb->mains_online = dc;
smb->usb_online = usb;
mutex_unlock(&smb->lock);
return ret;
}
static bool smb347_is_ps_online(struct smb347_charger *smb)
{
bool ret;
mutex_lock(&smb->lock);
ret = smb->usb_online || smb->mains_online;
mutex_unlock(&smb->lock);
return ret;
}
static int smb347_charging_status(struct smb347_charger *smb)
{
unsigned int val;
int ret;
if (!smb347_is_ps_online(smb))
return 0;
ret = regmap_read(smb->regmap, STAT_C, &val);
if (ret < 0)
return 0;
return (val & STAT_C_CHG_MASK) >> STAT_C_CHG_SHIFT;
}
static int smb347_charging_set(struct smb347_charger *smb, bool enable)
{
int ret = 0;
if (smb->pdata->enable_control != SMB347_CHG_ENABLE_SW) {
dev_dbg(smb->dev, "charging enable/disable in SW disabled\n");
return 0;
}
mutex_lock(&smb->lock);
if (smb->charging_enabled != enable) {
ret = regmap_update_bits(smb->regmap, CMD_A, CMD_A_CHG_ENABLED,
enable ? CMD_A_CHG_ENABLED : 0);
if (!ret)
smb->charging_enabled = enable;
}
mutex_unlock(&smb->lock);
return ret;
}
static inline int smb347_charging_enable(struct smb347_charger *smb)
{
return smb347_charging_set(smb, true);
}
static inline int smb347_charging_disable(struct smb347_charger *smb)
{
return smb347_charging_set(smb, false);
}
static int smb347_start_stop_charging(struct smb347_charger *smb)
{
int ret;
if (smb347_is_ps_online(smb)) {
ret = smb347_charging_enable(smb);
if (ret < 0)
dev_err(smb->dev, "failed to enable charging\n");
} else {
ret = smb347_charging_disable(smb);
if (ret < 0)
dev_err(smb->dev, "failed to disable charging\n");
}
return ret;
}
static int smb347_set_charge_current(struct smb347_charger *smb)
{
int ret;
if (smb->pdata->max_charge_current) {
ret = current_to_hw(fcc_tbl, ARRAY_SIZE(fcc_tbl),
smb->pdata->max_charge_current);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_CHARGE_CURRENT,
CFG_CHARGE_CURRENT_FCC_MASK,
ret << CFG_CHARGE_CURRENT_FCC_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->pre_charge_current) {
ret = current_to_hw(pcc_tbl, ARRAY_SIZE(pcc_tbl),
smb->pdata->pre_charge_current);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_CHARGE_CURRENT,
CFG_CHARGE_CURRENT_PCC_MASK,
ret << CFG_CHARGE_CURRENT_PCC_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->termination_current) {
ret = current_to_hw(tc_tbl, ARRAY_SIZE(tc_tbl),
smb->pdata->termination_current);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_CHARGE_CURRENT,
CFG_CHARGE_CURRENT_TC_MASK, ret);
if (ret < 0)
return ret;
}
return 0;
}
static int smb347_set_current_limits(struct smb347_charger *smb)
{
int ret;
if (smb->pdata->mains_current_limit) {
ret = current_to_hw(icl_tbl, ARRAY_SIZE(icl_tbl),
smb->pdata->mains_current_limit);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_CURRENT_LIMIT,
CFG_CURRENT_LIMIT_DC_MASK,
ret << CFG_CURRENT_LIMIT_DC_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->usb_hc_current_limit) {
ret = current_to_hw(icl_tbl, ARRAY_SIZE(icl_tbl),
smb->pdata->usb_hc_current_limit);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_CURRENT_LIMIT,
CFG_CURRENT_LIMIT_USB_MASK, ret);
if (ret < 0)
return ret;
}
return 0;
}
static int smb347_set_voltage_limits(struct smb347_charger *smb)
{
int ret;
if (smb->pdata->pre_to_fast_voltage) {
ret = smb->pdata->pre_to_fast_voltage;
ret = clamp_val(ret, 2400000, 3000000) - 2400000;
ret /= 200000;
ret = regmap_update_bits(smb->regmap, CFG_FLOAT_VOLTAGE,
CFG_FLOAT_VOLTAGE_THRESHOLD_MASK,
ret << CFG_FLOAT_VOLTAGE_THRESHOLD_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->max_charge_voltage) {
ret = smb->pdata->max_charge_voltage;
ret = clamp_val(ret, 3500000, 4500000) - 3500000;
ret /= 20000;
ret = regmap_update_bits(smb->regmap, CFG_FLOAT_VOLTAGE,
CFG_FLOAT_VOLTAGE_FLOAT_MASK, ret);
if (ret < 0)
return ret;
}
return 0;
}
static int smb347_set_temp_limits(struct smb347_charger *smb)
{
bool enable_therm_monitor = false;
int ret = 0;
int val;
if (smb->pdata->chip_temp_threshold) {
val = smb->pdata->chip_temp_threshold;
val = clamp_val(val, 100, 130) - 100;
val /= 10;
ret = regmap_update_bits(smb->regmap, CFG_OTG,
CFG_OTG_TEMP_THRESHOLD_MASK,
val << CFG_OTG_TEMP_THRESHOLD_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->soft_cold_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->soft_cold_temp_limit;
val = clamp_val(val, 0, 15);
val /= 5;
val = ~val & 0x3;
ret = regmap_update_bits(smb->regmap, CFG_TEMP_LIMIT,
CFG_TEMP_LIMIT_SOFT_COLD_MASK,
val << CFG_TEMP_LIMIT_SOFT_COLD_SHIFT);
if (ret < 0)
return ret;
enable_therm_monitor = true;
}
if (smb->pdata->soft_hot_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->soft_hot_temp_limit;
val = clamp_val(val, 40, 55) - 40;
val /= 5;
ret = regmap_update_bits(smb->regmap, CFG_TEMP_LIMIT,
CFG_TEMP_LIMIT_SOFT_HOT_MASK,
val << CFG_TEMP_LIMIT_SOFT_HOT_SHIFT);
if (ret < 0)
return ret;
enable_therm_monitor = true;
}
if (smb->pdata->hard_cold_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->hard_cold_temp_limit;
val = clamp_val(val, -5, 10) + 5;
val /= 5;
val = ~val & 0x3;
ret = regmap_update_bits(smb->regmap, CFG_TEMP_LIMIT,
CFG_TEMP_LIMIT_HARD_COLD_MASK,
val << CFG_TEMP_LIMIT_HARD_COLD_SHIFT);
if (ret < 0)
return ret;
enable_therm_monitor = true;
}
if (smb->pdata->hard_hot_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->hard_hot_temp_limit;
val = clamp_val(val, 50, 65) - 50;
val /= 5;
ret = regmap_update_bits(smb->regmap, CFG_TEMP_LIMIT,
CFG_TEMP_LIMIT_HARD_HOT_MASK,
val << CFG_TEMP_LIMIT_HARD_HOT_SHIFT);
if (ret < 0)
return ret;
enable_therm_monitor = true;
}
if (enable_therm_monitor) {
ret = regmap_update_bits(smb->regmap, CFG_THERM,
CFG_THERM_MONITOR_DISABLED, 0);
if (ret < 0)
return ret;
}
if (smb->pdata->suspend_on_hard_temp_limit) {
ret = regmap_update_bits(smb->regmap, CFG_SYSOK,
CFG_SYSOK_SUSPEND_HARD_LIMIT_DISABLED, 0);
if (ret < 0)
return ret;
}
if (smb->pdata->soft_temp_limit_compensation !=
SMB347_SOFT_TEMP_COMPENSATE_DEFAULT) {
val = smb->pdata->soft_temp_limit_compensation & 0x3;
ret = regmap_update_bits(smb->regmap, CFG_THERM,
CFG_THERM_SOFT_HOT_COMPENSATION_MASK,
val << CFG_THERM_SOFT_HOT_COMPENSATION_SHIFT);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_THERM,
CFG_THERM_SOFT_COLD_COMPENSATION_MASK,
val << CFG_THERM_SOFT_COLD_COMPENSATION_SHIFT);
if (ret < 0)
return ret;
}
if (smb->pdata->charge_current_compensation) {
val = current_to_hw(ccc_tbl, ARRAY_SIZE(ccc_tbl),
smb->pdata->charge_current_compensation);
if (val < 0)
return val;
ret = regmap_update_bits(smb->regmap, CFG_OTG,
CFG_OTG_CC_COMPENSATION_MASK,
(val & 0x3) << CFG_OTG_CC_COMPENSATION_SHIFT);
if (ret < 0)
return ret;
}
return ret;
}
static int smb347_set_writable(struct smb347_charger *smb, bool writable)
{
return regmap_update_bits(smb->regmap, CMD_A, CMD_A_ALLOW_WRITE,
writable ? CMD_A_ALLOW_WRITE : 0);
}
static int smb347_hw_init(struct smb347_charger *smb)
{
unsigned int val;
int ret;
ret = smb347_set_writable(smb, true);
if (ret < 0)
return ret;
ret = smb347_set_charge_current(smb);
if (ret < 0)
goto fail;
ret = smb347_set_current_limits(smb);
if (ret < 0)
goto fail;
ret = smb347_set_voltage_limits(smb);
if (ret < 0)
goto fail;
ret = smb347_set_temp_limits(smb);
if (ret < 0)
goto fail;
if (!smb->pdata->use_usb) {
ret = regmap_update_bits(smb->regmap, CMD_A,
CMD_A_SUSPEND_ENABLED,
CMD_A_SUSPEND_ENABLED);
if (ret < 0)
goto fail;
}
ret = regmap_update_bits(smb->regmap, CFG_OTHER, CFG_OTHER_RID_MASK,
smb->pdata->use_usb_otg ? CFG_OTHER_RID_ENABLED_AUTO_OTG : 0);
if (ret < 0)
goto fail;
switch (smb->pdata->enable_control) {
case SMB347_CHG_ENABLE_PIN_ACTIVE_LOW:
val = CFG_PIN_EN_CTRL_ACTIVE_LOW;
break;
case SMB347_CHG_ENABLE_PIN_ACTIVE_HIGH:
val = CFG_PIN_EN_CTRL_ACTIVE_HIGH;
break;
default:
val = 0;
break;
}
ret = regmap_update_bits(smb->regmap, CFG_PIN, CFG_PIN_EN_CTRL_MASK,
val);
if (ret < 0)
goto fail;
ret = regmap_update_bits(smb->regmap, CFG_PIN, CFG_PIN_EN_APSD_IRQ, 0);
if (ret < 0)
goto fail;
ret = smb347_update_ps_status(smb);
if (ret < 0)
goto fail;
ret = smb347_start_stop_charging(smb);
fail:
smb347_set_writable(smb, false);
return ret;
}
static irqreturn_t smb347_interrupt(int irq, void *data)
{
struct smb347_charger *smb = data;
unsigned int stat_c, irqstat_e, irqstat_c;
bool handled = false;
int ret;
ret = regmap_read(smb->regmap, STAT_C, &stat_c);
if (ret < 0) {
dev_warn(smb->dev, "reading STAT_C failed\n");
return IRQ_NONE;
}
ret = regmap_read(smb->regmap, IRQSTAT_C, &irqstat_c);
if (ret < 0) {
dev_warn(smb->dev, "reading IRQSTAT_C failed\n");
return IRQ_NONE;
}
ret = regmap_read(smb->regmap, IRQSTAT_E, &irqstat_e);
if (ret < 0) {
dev_warn(smb->dev, "reading IRQSTAT_E failed\n");
return IRQ_NONE;
}
if (stat_c & STAT_C_CHARGER_ERROR) {
dev_err(smb->dev, "error in charger, disabling charging\n");
smb347_charging_disable(smb);
power_supply_changed(&smb->battery);
handled = true;
}
if (irqstat_c & (IRQSTAT_C_TERMINATION_IRQ | IRQSTAT_C_TAPER_IRQ)) {
if (irqstat_c & IRQSTAT_C_TERMINATION_STAT)
power_supply_changed(&smb->battery);
handled = true;
}
if (irqstat_e & (IRQSTAT_E_USBIN_UV_IRQ | IRQSTAT_E_DCIN_UV_IRQ)) {
if (smb347_update_ps_status(smb) > 0) {
smb347_start_stop_charging(smb);
if (smb->pdata->use_mains)
power_supply_changed(&smb->mains);
if (smb->pdata->use_usb)
power_supply_changed(&smb->usb);
}
handled = true;
}
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static int smb347_irq_set(struct smb347_charger *smb, bool enable)
{
int ret;
ret = smb347_set_writable(smb, true);
if (ret < 0)
return ret;
ret = regmap_update_bits(smb->regmap, CFG_FAULT_IRQ, 0xff,
enable ? CFG_FAULT_IRQ_DCIN_UV : 0);
if (ret < 0)
goto fail;
ret = regmap_update_bits(smb->regmap, CFG_STATUS_IRQ, 0xff,
enable ? CFG_STATUS_IRQ_TERMINATION_OR_TAPER : 0);
if (ret < 0)
goto fail;
ret = regmap_update_bits(smb->regmap, CFG_PIN, CFG_PIN_EN_CHARGER_ERROR,
enable ? CFG_PIN_EN_CHARGER_ERROR : 0);
fail:
smb347_set_writable(smb, false);
return ret;
}
static inline int smb347_irq_enable(struct smb347_charger *smb)
{
return smb347_irq_set(smb, true);
}
static inline int smb347_irq_disable(struct smb347_charger *smb)
{
return smb347_irq_set(smb, false);
}
static int smb347_irq_init(struct smb347_charger *smb,
struct i2c_client *client)
{
const struct smb347_charger_platform_data *pdata = smb->pdata;
int ret, irq = gpio_to_irq(pdata->irq_gpio);
ret = gpio_request_one(pdata->irq_gpio, GPIOF_IN, client->name);
if (ret < 0)
goto fail;
ret = request_threaded_irq(irq, NULL, smb347_interrupt,
IRQF_TRIGGER_FALLING, client->name, smb);
if (ret < 0)
goto fail_gpio;
ret = smb347_set_writable(smb, true);
if (ret < 0)
goto fail_irq;
ret = regmap_update_bits(smb->regmap, CFG_STAT,
CFG_STAT_ACTIVE_HIGH | CFG_STAT_DISABLED,
CFG_STAT_DISABLED);
if (ret < 0)
goto fail_readonly;
smb347_set_writable(smb, false);
client->irq = irq;
return 0;
fail_readonly:
smb347_set_writable(smb, false);
fail_irq:
free_irq(irq, smb);
fail_gpio:
gpio_free(pdata->irq_gpio);
fail:
client->irq = 0;
return ret;
}
static int smb347_mains_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct smb347_charger *smb =
container_of(psy, struct smb347_charger, mains);
if (prop == POWER_SUPPLY_PROP_ONLINE) {
val->intval = smb->mains_online;
return 0;
}
return -EINVAL;
}
static int smb347_usb_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct smb347_charger *smb =
container_of(psy, struct smb347_charger, usb);
if (prop == POWER_SUPPLY_PROP_ONLINE) {
val->intval = smb->usb_online;
return 0;
}
return -EINVAL;
}
static int smb347_battery_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct smb347_charger *smb =
container_of(psy, struct smb347_charger, battery);
const struct smb347_charger_platform_data *pdata = smb->pdata;
int ret;
ret = smb347_update_ps_status(smb);
if (ret < 0)
return ret;
switch (prop) {
case POWER_SUPPLY_PROP_STATUS:
if (!smb347_is_ps_online(smb)) {
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
}
if (smb347_charging_status(smb))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_FULL;
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
if (!smb347_is_ps_online(smb))
return -ENODATA;
switch (smb347_charging_status(smb)) {
case 1:
val->intval = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case 2:
val->intval = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
default:
val->intval = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
}
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = pdata->battery_info.technology;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = pdata->battery_info.voltage_min_design;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = pdata->battery_info.voltage_max_design;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = pdata->battery_info.charge_full_design;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = pdata->battery_info.name;
break;
default:
return -EINVAL;
}
return 0;
}
static bool smb347_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case IRQSTAT_A:
case IRQSTAT_C:
case IRQSTAT_E:
case IRQSTAT_F:
case STAT_A:
case STAT_B:
case STAT_C:
case STAT_E:
return true;
}
return false;
}
static bool smb347_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case CFG_CHARGE_CURRENT:
case CFG_CURRENT_LIMIT:
case CFG_FLOAT_VOLTAGE:
case CFG_STAT:
case CFG_PIN:
case CFG_THERM:
case CFG_SYSOK:
case CFG_OTHER:
case CFG_OTG:
case CFG_TEMP_LIMIT:
case CFG_FAULT_IRQ:
case CFG_STATUS_IRQ:
case CFG_ADDRESS:
case CMD_A:
case CMD_B:
case CMD_C:
return true;
}
return smb347_volatile_reg(dev, reg);
}
static int smb347_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static char *battery[] = { "smb347-battery" };
const struct smb347_charger_platform_data *pdata;
struct device *dev = &client->dev;
struct smb347_charger *smb;
int ret;
pdata = dev->platform_data;
if (!pdata)
return -EINVAL;
if (!pdata->use_mains && !pdata->use_usb)
return -EINVAL;
smb = devm_kzalloc(dev, sizeof(*smb), GFP_KERNEL);
if (!smb)
return -ENOMEM;
i2c_set_clientdata(client, smb);
mutex_init(&smb->lock);
smb->dev = &client->dev;
smb->pdata = pdata;
smb->regmap = devm_regmap_init_i2c(client, &smb347_regmap);
if (IS_ERR(smb->regmap))
return PTR_ERR(smb->regmap);
ret = smb347_hw_init(smb);
if (ret < 0)
return ret;
if (smb->pdata->use_mains) {
smb->mains.name = "smb347-mains";
smb->mains.type = POWER_SUPPLY_TYPE_MAINS;
smb->mains.get_property = smb347_mains_get_property;
smb->mains.properties = smb347_mains_properties;
smb->mains.num_properties = ARRAY_SIZE(smb347_mains_properties);
smb->mains.supplied_to = battery;
smb->mains.num_supplicants = ARRAY_SIZE(battery);
ret = power_supply_register(dev, &smb->mains);
if (ret < 0)
return ret;
}
if (smb->pdata->use_usb) {
smb->usb.name = "smb347-usb";
smb->usb.type = POWER_SUPPLY_TYPE_USB;
smb->usb.get_property = smb347_usb_get_property;
smb->usb.properties = smb347_usb_properties;
smb->usb.num_properties = ARRAY_SIZE(smb347_usb_properties);
smb->usb.supplied_to = battery;
smb->usb.num_supplicants = ARRAY_SIZE(battery);
ret = power_supply_register(dev, &smb->usb);
if (ret < 0) {
if (smb->pdata->use_mains)
power_supply_unregister(&smb->mains);
return ret;
}
}
smb->battery.name = "smb347-battery";
smb->battery.type = POWER_SUPPLY_TYPE_BATTERY;
smb->battery.get_property = smb347_battery_get_property;
smb->battery.properties = smb347_battery_properties;
smb->battery.num_properties = ARRAY_SIZE(smb347_battery_properties);
ret = power_supply_register(dev, &smb->battery);
if (ret < 0) {
if (smb->pdata->use_usb)
power_supply_unregister(&smb->usb);
if (smb->pdata->use_mains)
power_supply_unregister(&smb->mains);
return ret;
}
if (pdata->irq_gpio >= 0) {
ret = smb347_irq_init(smb, client);
if (ret < 0) {
dev_warn(dev, "failed to initialize IRQ: %d\n", ret);
dev_warn(dev, "disabling IRQ support\n");
} else {
smb347_irq_enable(smb);
}
}
return 0;
}
static int smb347_remove(struct i2c_client *client)
{
struct smb347_charger *smb = i2c_get_clientdata(client);
if (client->irq) {
smb347_irq_disable(smb);
free_irq(client->irq, smb);
gpio_free(smb->pdata->irq_gpio);
}
power_supply_unregister(&smb->battery);
if (smb->pdata->use_usb)
power_supply_unregister(&smb->usb);
if (smb->pdata->use_mains)
power_supply_unregister(&smb->mains);
return 0;
}
