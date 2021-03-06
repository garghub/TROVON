static int hw_to_current(const unsigned int *tbl, size_t size, unsigned int val)
{
if (val >= size)
return -EINVAL;
return tbl[val];
}
static int current_to_hw(const unsigned int *tbl, size_t size, unsigned int val)
{
size_t i;
for (i = 0; i < size; i++)
if (val < tbl[i])
break;
return i > 0 ? i - 1 : -EINVAL;
}
static int smb347_read(struct smb347_charger *smb, u8 reg)
{
int ret;
ret = i2c_smbus_read_byte_data(smb->client, reg);
if (ret < 0)
dev_warn(&smb->client->dev, "failed to read reg 0x%x: %d\n",
reg, ret);
return ret;
}
static int smb347_write(struct smb347_charger *smb, u8 reg, u8 val)
{
int ret;
ret = i2c_smbus_write_byte_data(smb->client, reg, val);
if (ret < 0)
dev_warn(&smb->client->dev, "failed to write reg 0x%x: %d\n",
reg, ret);
return ret;
}
static int smb347_update_status(struct smb347_charger *smb)
{
bool usb = false;
bool dc = false;
int ret;
ret = smb347_read(smb, IRQSTAT_E);
if (ret < 0)
return ret;
if (smb->pdata->use_mains)
dc = !(ret & IRQSTAT_E_DCIN_UV_STAT);
if (smb->pdata->use_usb)
usb = !(ret & IRQSTAT_E_USBIN_UV_STAT);
mutex_lock(&smb->lock);
ret = smb->mains_online != dc || smb->usb_online != usb;
smb->mains_online = dc;
smb->usb_online = usb;
mutex_unlock(&smb->lock);
return ret;
}
static bool smb347_is_online(struct smb347_charger *smb)
{
bool ret;
mutex_lock(&smb->lock);
ret = smb->usb_online || smb->mains_online;
mutex_unlock(&smb->lock);
return ret;
}
static int smb347_charging_status(struct smb347_charger *smb)
{
int ret;
if (!smb347_is_online(smb))
return 0;
ret = smb347_read(smb, STAT_C);
if (ret < 0)
return 0;
return (ret & STAT_C_CHG_MASK) >> STAT_C_CHG_SHIFT;
}
static int smb347_charging_set(struct smb347_charger *smb, bool enable)
{
int ret = 0;
if (smb->pdata->enable_control != SMB347_CHG_ENABLE_SW) {
dev_dbg(&smb->client->dev,
"charging enable/disable in SW disabled\n");
return 0;
}
mutex_lock(&smb->lock);
if (smb->charging_enabled != enable) {
ret = smb347_read(smb, CMD_A);
if (ret < 0)
goto out;
smb->charging_enabled = enable;
if (enable)
ret |= CMD_A_CHG_ENABLED;
else
ret &= ~CMD_A_CHG_ENABLED;
ret = smb347_write(smb, CMD_A, ret);
}
out:
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
static int smb347_update_online(struct smb347_charger *smb)
{
int ret;
if (smb347_is_online(smb)) {
ret = smb347_charging_enable(smb);
if (ret < 0)
dev_err(&smb->client->dev,
"failed to enable charging\n");
} else {
ret = smb347_charging_disable(smb);
if (ret < 0)
dev_err(&smb->client->dev,
"failed to disable charging\n");
}
return ret;
}
static int smb347_set_charge_current(struct smb347_charger *smb)
{
int ret, val;
ret = smb347_read(smb, CFG_CHARGE_CURRENT);
if (ret < 0)
return ret;
if (smb->pdata->max_charge_current) {
val = current_to_hw(fcc_tbl, ARRAY_SIZE(fcc_tbl),
smb->pdata->max_charge_current);
if (val < 0)
return val;
ret &= ~CFG_CHARGE_CURRENT_FCC_MASK;
ret |= val << CFG_CHARGE_CURRENT_FCC_SHIFT;
}
if (smb->pdata->pre_charge_current) {
val = current_to_hw(pcc_tbl, ARRAY_SIZE(pcc_tbl),
smb->pdata->pre_charge_current);
if (val < 0)
return val;
ret &= ~CFG_CHARGE_CURRENT_PCC_MASK;
ret |= val << CFG_CHARGE_CURRENT_PCC_SHIFT;
}
if (smb->pdata->termination_current) {
val = current_to_hw(tc_tbl, ARRAY_SIZE(tc_tbl),
smb->pdata->termination_current);
if (val < 0)
return val;
ret &= ~CFG_CHARGE_CURRENT_TC_MASK;
ret |= val;
}
return smb347_write(smb, CFG_CHARGE_CURRENT, ret);
}
static int smb347_set_current_limits(struct smb347_charger *smb)
{
int ret, val;
ret = smb347_read(smb, CFG_CURRENT_LIMIT);
if (ret < 0)
return ret;
if (smb->pdata->mains_current_limit) {
val = current_to_hw(icl_tbl, ARRAY_SIZE(icl_tbl),
smb->pdata->mains_current_limit);
if (val < 0)
return val;
ret &= ~CFG_CURRENT_LIMIT_DC_MASK;
ret |= val << CFG_CURRENT_LIMIT_DC_SHIFT;
}
if (smb->pdata->usb_hc_current_limit) {
val = current_to_hw(icl_tbl, ARRAY_SIZE(icl_tbl),
smb->pdata->usb_hc_current_limit);
if (val < 0)
return val;
ret &= ~CFG_CURRENT_LIMIT_USB_MASK;
ret |= val;
}
return smb347_write(smb, CFG_CURRENT_LIMIT, ret);
}
static int smb347_set_voltage_limits(struct smb347_charger *smb)
{
int ret, val;
ret = smb347_read(smb, CFG_FLOAT_VOLTAGE);
if (ret < 0)
return ret;
if (smb->pdata->pre_to_fast_voltage) {
val = smb->pdata->pre_to_fast_voltage;
val = clamp_val(val, 2400000, 3000000) - 2400000;
val /= 200000;
ret &= ~CFG_FLOAT_VOLTAGE_THRESHOLD_MASK;
ret |= val << CFG_FLOAT_VOLTAGE_THRESHOLD_SHIFT;
}
if (smb->pdata->max_charge_voltage) {
val = smb->pdata->max_charge_voltage;
val = clamp_val(val, 3500000, 4500000) - 3500000;
val /= 20000;
ret |= val;
}
return smb347_write(smb, CFG_FLOAT_VOLTAGE, ret);
}
static int smb347_set_temp_limits(struct smb347_charger *smb)
{
bool enable_therm_monitor = false;
int ret, val;
if (smb->pdata->chip_temp_threshold) {
val = smb->pdata->chip_temp_threshold;
val = clamp_val(val, 100, 130) - 100;
val /= 10;
ret = smb347_read(smb, CFG_OTG);
if (ret < 0)
return ret;
ret &= ~CFG_OTG_TEMP_THRESHOLD_MASK;
ret |= val << CFG_OTG_TEMP_THRESHOLD_SHIFT;
ret = smb347_write(smb, CFG_OTG, ret);
if (ret < 0)
return ret;
}
ret = smb347_read(smb, CFG_TEMP_LIMIT);
if (ret < 0)
return ret;
if (smb->pdata->soft_cold_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->soft_cold_temp_limit;
val = clamp_val(val, 0, 15);
val /= 5;
val = ~val & 0x3;
ret &= ~CFG_TEMP_LIMIT_SOFT_COLD_MASK;
ret |= val << CFG_TEMP_LIMIT_SOFT_COLD_SHIFT;
enable_therm_monitor = true;
}
if (smb->pdata->soft_hot_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->soft_hot_temp_limit;
val = clamp_val(val, 40, 55) - 40;
val /= 5;
ret &= ~CFG_TEMP_LIMIT_SOFT_HOT_MASK;
ret |= val << CFG_TEMP_LIMIT_SOFT_HOT_SHIFT;
enable_therm_monitor = true;
}
if (smb->pdata->hard_cold_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->hard_cold_temp_limit;
val = clamp_val(val, -5, 10) + 5;
val /= 5;
val = ~val & 0x3;
ret &= ~CFG_TEMP_LIMIT_HARD_COLD_MASK;
ret |= val << CFG_TEMP_LIMIT_HARD_COLD_SHIFT;
enable_therm_monitor = true;
}
if (smb->pdata->hard_hot_temp_limit != SMB347_TEMP_USE_DEFAULT) {
val = smb->pdata->hard_hot_temp_limit;
val = clamp_val(val, 50, 65) - 50;
val /= 5;
ret &= ~CFG_TEMP_LIMIT_HARD_HOT_MASK;
ret |= val << CFG_TEMP_LIMIT_HARD_HOT_SHIFT;
enable_therm_monitor = true;
}
ret = smb347_write(smb, CFG_TEMP_LIMIT, ret);
if (ret < 0)
return ret;
if (enable_therm_monitor) {
ret = smb347_read(smb, CFG_THERM);
if (ret < 0)
return ret;
ret &= ~CFG_THERM_MONITOR_DISABLED;
ret = smb347_write(smb, CFG_THERM, ret);
if (ret < 0)
return ret;
}
if (smb->pdata->suspend_on_hard_temp_limit) {
ret = smb347_read(smb, CFG_SYSOK);
if (ret < 0)
return ret;
ret &= ~CFG_SYSOK_SUSPEND_HARD_LIMIT_DISABLED;
ret = smb347_write(smb, CFG_SYSOK, ret);
if (ret < 0)
return ret;
}
if (smb->pdata->soft_temp_limit_compensation !=
SMB347_SOFT_TEMP_COMPENSATE_DEFAULT) {
val = smb->pdata->soft_temp_limit_compensation & 0x3;
ret = smb347_read(smb, CFG_THERM);
if (ret < 0)
return ret;
ret &= ~CFG_THERM_SOFT_HOT_COMPENSATION_MASK;
ret |= val << CFG_THERM_SOFT_HOT_COMPENSATION_SHIFT;
ret &= ~CFG_THERM_SOFT_COLD_COMPENSATION_MASK;
ret |= val << CFG_THERM_SOFT_COLD_COMPENSATION_SHIFT;
ret = smb347_write(smb, CFG_THERM, ret);
if (ret < 0)
return ret;
}
if (smb->pdata->charge_current_compensation) {
val = current_to_hw(ccc_tbl, ARRAY_SIZE(ccc_tbl),
smb->pdata->charge_current_compensation);
if (val < 0)
return val;
ret = smb347_read(smb, CFG_OTG);
if (ret < 0)
return ret;
ret &= ~CFG_OTG_CC_COMPENSATION_MASK;
ret |= (val & 0x3) << CFG_OTG_CC_COMPENSATION_SHIFT;
ret = smb347_write(smb, CFG_OTG, ret);
if (ret < 0)
return ret;
}
return ret;
}
static int smb347_set_writable(struct smb347_charger *smb, bool writable)
{
int ret;
ret = smb347_read(smb, CMD_A);
if (ret < 0)
return ret;
if (writable)
ret |= CMD_A_ALLOW_WRITE;
else
ret &= ~CMD_A_ALLOW_WRITE;
return smb347_write(smb, CMD_A, ret);
}
static int smb347_hw_init(struct smb347_charger *smb)
{
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
ret = smb347_read(smb, CMD_A);
if (ret < 0)
goto fail;
ret |= CMD_A_SUSPEND_ENABLED;
ret = smb347_write(smb, CMD_A, ret);
if (ret < 0)
goto fail;
}
ret = smb347_read(smb, CFG_OTHER);
if (ret < 0)
goto fail;
ret &= ~CFG_OTHER_RID_MASK;
if (smb->pdata->use_usb_otg)
ret |= CFG_OTHER_RID_ENABLED_AUTO_OTG;
ret = smb347_write(smb, CFG_OTHER, ret);
if (ret < 0)
goto fail;
ret = smb347_read(smb, CFG_PIN);
if (ret < 0)
goto fail;
ret &= ~CFG_PIN_EN_CTRL_MASK;
switch (smb->pdata->enable_control) {
case SMB347_CHG_ENABLE_SW:
break;
case SMB347_CHG_ENABLE_PIN_ACTIVE_LOW:
ret |= CFG_PIN_EN_CTRL_ACTIVE_LOW;
break;
case SMB347_CHG_ENABLE_PIN_ACTIVE_HIGH:
ret |= CFG_PIN_EN_CTRL_ACTIVE_HIGH;
break;
}
ret &= ~CFG_PIN_EN_APSD_IRQ;
ret = smb347_write(smb, CFG_PIN, ret);
if (ret < 0)
goto fail;
ret = smb347_update_status(smb);
if (ret < 0)
goto fail;
ret = smb347_update_online(smb);
fail:
smb347_set_writable(smb, false);
return ret;
}
static irqreturn_t smb347_interrupt(int irq, void *data)
{
struct smb347_charger *smb = data;
int stat_c, irqstat_e, irqstat_c;
irqreturn_t ret = IRQ_NONE;
stat_c = smb347_read(smb, STAT_C);
if (stat_c < 0) {
dev_warn(&smb->client->dev, "reading STAT_C failed\n");
return IRQ_NONE;
}
irqstat_c = smb347_read(smb, IRQSTAT_C);
if (irqstat_c < 0) {
dev_warn(&smb->client->dev, "reading IRQSTAT_C failed\n");
return IRQ_NONE;
}
irqstat_e = smb347_read(smb, IRQSTAT_E);
if (irqstat_e < 0) {
dev_warn(&smb->client->dev, "reading IRQSTAT_E failed\n");
return IRQ_NONE;
}
if (stat_c & STAT_C_CHARGER_ERROR) {
dev_err(&smb->client->dev,
"error in charger, disabling charging\n");
smb347_charging_disable(smb);
power_supply_changed(&smb->battery);
ret = IRQ_HANDLED;
}
if (irqstat_c & (IRQSTAT_C_TERMINATION_IRQ | IRQSTAT_C_TAPER_IRQ)) {
if (irqstat_c & IRQSTAT_C_TERMINATION_STAT)
power_supply_changed(&smb->battery);
ret = IRQ_HANDLED;
}
if (irqstat_e & (IRQSTAT_E_USBIN_UV_IRQ | IRQSTAT_E_DCIN_UV_IRQ)) {
if (smb347_update_status(smb) > 0) {
smb347_update_online(smb);
power_supply_changed(&smb->mains);
power_supply_changed(&smb->usb);
}
ret = IRQ_HANDLED;
}
return ret;
}
static int smb347_irq_set(struct smb347_charger *smb, bool enable)
{
int ret;
ret = smb347_set_writable(smb, true);
if (ret < 0)
return ret;
if (enable) {
ret = smb347_write(smb, CFG_FAULT_IRQ, CFG_FAULT_IRQ_DCIN_UV);
if (ret < 0)
goto fail;
ret = smb347_write(smb, CFG_STATUS_IRQ,
CFG_STATUS_IRQ_TERMINATION_OR_TAPER);
if (ret < 0)
goto fail;
ret = smb347_read(smb, CFG_PIN);
if (ret < 0)
goto fail;
ret |= CFG_PIN_EN_CHARGER_ERROR;
ret = smb347_write(smb, CFG_PIN, ret);
} else {
ret = smb347_write(smb, CFG_FAULT_IRQ, 0);
if (ret < 0)
goto fail;
ret = smb347_write(smb, CFG_STATUS_IRQ, 0);
if (ret < 0)
goto fail;
ret = smb347_read(smb, CFG_PIN);
if (ret < 0)
goto fail;
ret &= ~CFG_PIN_EN_CHARGER_ERROR;
ret = smb347_write(smb, CFG_PIN, ret);
}
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
static int smb347_irq_init(struct smb347_charger *smb)
{
const struct smb347_charger_platform_data *pdata = smb->pdata;
int ret, irq = gpio_to_irq(pdata->irq_gpio);
ret = gpio_request_one(pdata->irq_gpio, GPIOF_IN, smb->client->name);
if (ret < 0)
goto fail;
ret = request_threaded_irq(irq, NULL, smb347_interrupt,
IRQF_TRIGGER_FALLING, smb->client->name,
smb);
if (ret < 0)
goto fail_gpio;
ret = smb347_set_writable(smb, true);
if (ret < 0)
goto fail_irq;
ret = smb347_read(smb, CFG_STAT);
if (ret < 0)
goto fail_readonly;
ret &= ~CFG_STAT_ACTIVE_HIGH;
ret |= CFG_STAT_DISABLED;
ret = smb347_write(smb, CFG_STAT, ret);
if (ret < 0)
goto fail_readonly;
ret = smb347_irq_enable(smb);
if (ret < 0)
goto fail_readonly;
smb347_set_writable(smb, false);
smb->client->irq = irq;
return 0;
fail_readonly:
smb347_set_writable(smb, false);
fail_irq:
free_irq(irq, smb);
fail_gpio:
gpio_free(pdata->irq_gpio);
fail:
smb->client->irq = 0;
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
ret = smb347_update_status(smb);
if (ret < 0)
return ret;
switch (prop) {
case POWER_SUPPLY_PROP_STATUS:
if (!smb347_is_online(smb)) {
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
}
if (smb347_charging_status(smb))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_FULL;
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
if (!smb347_is_online(smb))
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
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (!smb347_is_online(smb))
return -ENODATA;
ret = smb347_read(smb, STAT_A);
if (ret < 0)
return ret;
ret &= STAT_A_FLOAT_VOLTAGE_MASK;
if (ret > 0x3d)
ret = 0x3d;
val->intval = 3500000 + ret * 20000;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
if (!smb347_is_online(smb))
return -ENODATA;
ret = smb347_read(smb, STAT_B);
if (ret < 0)
return ret;
if (ret & 0x20) {
val->intval = hw_to_current(fcc_tbl,
ARRAY_SIZE(fcc_tbl),
ret & 7);
} else {
ret >>= 3;
val->intval = hw_to_current(pcc_tbl,
ARRAY_SIZE(pcc_tbl),
ret & 7);
}
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
static int smb347_debugfs_show(struct seq_file *s, void *data)
{
struct smb347_charger *smb = s->private;
int ret;
u8 reg;
seq_printf(s, "Control registers:\n");
seq_printf(s, "==================\n");
for (reg = CFG_CHARGE_CURRENT; reg <= CFG_ADDRESS; reg++) {
ret = smb347_read(smb, reg);
seq_printf(s, "0x%02x:\t0x%02x\n", reg, ret);
}
seq_printf(s, "\n");
seq_printf(s, "Command registers:\n");
seq_printf(s, "==================\n");
ret = smb347_read(smb, CMD_A);
seq_printf(s, "0x%02x:\t0x%02x\n", CMD_A, ret);
ret = smb347_read(smb, CMD_B);
seq_printf(s, "0x%02x:\t0x%02x\n", CMD_B, ret);
ret = smb347_read(smb, CMD_C);
seq_printf(s, "0x%02x:\t0x%02x\n", CMD_C, ret);
seq_printf(s, "\n");
seq_printf(s, "Interrupt status registers:\n");
seq_printf(s, "===========================\n");
for (reg = IRQSTAT_A; reg <= IRQSTAT_F; reg++) {
ret = smb347_read(smb, reg);
seq_printf(s, "0x%02x:\t0x%02x\n", reg, ret);
}
seq_printf(s, "\n");
seq_printf(s, "Status registers:\n");
seq_printf(s, "=================\n");
for (reg = STAT_A; reg <= STAT_E; reg++) {
ret = smb347_read(smb, reg);
seq_printf(s, "0x%02x:\t0x%02x\n", reg, ret);
}
return 0;
}
static int smb347_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, smb347_debugfs_show, inode->i_private);
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
smb->client = client;
smb->pdata = pdata;
ret = smb347_hw_init(smb);
if (ret < 0)
return ret;
smb->mains.name = "smb347-mains";
smb->mains.type = POWER_SUPPLY_TYPE_MAINS;
smb->mains.get_property = smb347_mains_get_property;
smb->mains.properties = smb347_mains_properties;
smb->mains.num_properties = ARRAY_SIZE(smb347_mains_properties);
smb->mains.supplied_to = battery;
smb->mains.num_supplicants = ARRAY_SIZE(battery);
smb->usb.name = "smb347-usb";
smb->usb.type = POWER_SUPPLY_TYPE_USB;
smb->usb.get_property = smb347_usb_get_property;
smb->usb.properties = smb347_usb_properties;
smb->usb.num_properties = ARRAY_SIZE(smb347_usb_properties);
smb->usb.supplied_to = battery;
smb->usb.num_supplicants = ARRAY_SIZE(battery);
smb->battery.name = "smb347-battery";
smb->battery.type = POWER_SUPPLY_TYPE_BATTERY;
smb->battery.get_property = smb347_battery_get_property;
smb->battery.properties = smb347_battery_properties;
smb->battery.num_properties = ARRAY_SIZE(smb347_battery_properties);
ret = power_supply_register(dev, &smb->mains);
if (ret < 0)
return ret;
ret = power_supply_register(dev, &smb->usb);
if (ret < 0) {
power_supply_unregister(&smb->mains);
return ret;
}
ret = power_supply_register(dev, &smb->battery);
if (ret < 0) {
power_supply_unregister(&smb->usb);
power_supply_unregister(&smb->mains);
return ret;
}
if (pdata->irq_gpio >= 0) {
ret = smb347_irq_init(smb);
if (ret < 0) {
dev_warn(dev, "failed to initialize IRQ: %d\n", ret);
dev_warn(dev, "disabling IRQ support\n");
}
}
smb->dentry = debugfs_create_file("smb347-regs", S_IRUSR, NULL, smb,
&smb347_debugfs_fops);
return 0;
}
static int smb347_remove(struct i2c_client *client)
{
struct smb347_charger *smb = i2c_get_clientdata(client);
if (!IS_ERR_OR_NULL(smb->dentry))
debugfs_remove(smb->dentry);
if (client->irq) {
smb347_irq_disable(smb);
free_irq(client->irq, smb);
gpio_free(smb->pdata->irq_gpio);
}
power_supply_unregister(&smb->battery);
power_supply_unregister(&smb->usb);
power_supply_unregister(&smb->mains);
return 0;
}
static int __init smb347_init(void)
{
return i2c_add_driver(&smb347_driver);
}
static void __exit smb347_exit(void)
{
i2c_del_driver(&smb347_driver);
}
