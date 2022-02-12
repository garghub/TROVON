static bool bq24257_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BQ24257_REG_2:
case BQ24257_REG_4:
return false;
default:
return true;
}
}
static int bq24257_field_read(struct bq24257_device *bq,
enum bq24257_fields field_id)
{
int ret;
int val;
ret = regmap_field_read(bq->rmap_fields[field_id], &val);
if (ret < 0)
return ret;
return val;
}
static int bq24257_field_write(struct bq24257_device *bq,
enum bq24257_fields field_id, u8 val)
{
return regmap_field_write(bq->rmap_fields[field_id], val);
}
static u8 bq24257_find_idx(u32 value, const u32 *map, u8 map_size)
{
u8 idx;
for (idx = 1; idx < map_size; idx++)
if (value < map[idx])
break;
return idx - 1;
}
static int bq24257_get_input_current_limit(struct bq24257_device *bq,
union power_supply_propval *val)
{
int ret;
ret = bq24257_field_read(bq, F_IILIMIT);
if (ret < 0)
return ret;
if (ret >= BQ24257_IILIMIT_MAP_SIZE)
return -ENODATA;
val->intval = bq24257_iilimit_map[ret];
return 0;
}
static int bq24257_set_input_current_limit(struct bq24257_device *bq,
const union power_supply_propval *val)
{
if (bq->iilimit_autoset_enable)
cancel_delayed_work_sync(&bq->iilimit_setup_work);
return bq24257_field_write(bq, F_IILIMIT,
bq24257_find_idx(val->intval,
bq24257_iilimit_map,
BQ24257_IILIMIT_MAP_SIZE));
}
static int bq24257_power_supply_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct bq24257_device *bq = power_supply_get_drvdata(psy);
struct bq24257_state state;
mutex_lock(&bq->lock);
state = bq->state;
mutex_unlock(&bq->lock);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (!state.power_good)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (state.status == STATUS_READY)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (state.status == STATUS_CHARGE_IN_PROGRESS)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (state.status == STATUS_CHARGE_DONE)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = BQ24257_MANUFACTURER;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = bq2425x_chip_name[bq->chip];
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = state.power_good;
break;
case POWER_SUPPLY_PROP_HEALTH:
switch (state.fault) {
case FAULT_NORMAL:
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case FAULT_INPUT_OVP:
case FAULT_BAT_OVP:
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
break;
case FAULT_TS:
case FAULT_BAT_TS:
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
break;
case FAULT_TIMER:
val->intval = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
break;
default:
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
}
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
val->intval = bq24257_ichg_map[bq->init_data.ichg];
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
val->intval = bq24257_ichg_map[BQ24257_ICHG_MAP_SIZE - 1];
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
val->intval = bq24257_vbat_map[bq->init_data.vbat];
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
val->intval = bq24257_vbat_map[BQ24257_VBAT_MAP_SIZE - 1];
break;
case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
val->intval = bq24257_iterm_map[bq->init_data.iterm];
break;
case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
return bq24257_get_input_current_limit(bq, val);
default:
return -EINVAL;
}
return 0;
}
static int bq24257_power_supply_set_property(struct power_supply *psy,
enum power_supply_property prop,
const union power_supply_propval *val)
{
struct bq24257_device *bq = power_supply_get_drvdata(psy);
switch (prop) {
case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
return bq24257_set_input_current_limit(bq, val);
default:
return -EINVAL;
}
}
static int bq24257_power_supply_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
switch (psp) {
case POWER_SUPPLY_PROP_INPUT_CURRENT_LIMIT:
return true;
default:
return false;
}
}
static int bq24257_get_chip_state(struct bq24257_device *bq,
struct bq24257_state *state)
{
int ret;
ret = bq24257_field_read(bq, F_STAT);
if (ret < 0)
return ret;
state->status = ret;
ret = bq24257_field_read(bq, F_FAULT);
if (ret < 0)
return ret;
state->fault = ret;
if (bq->pg)
state->power_good = !gpiod_get_value_cansleep(bq->pg);
else
switch (state->fault) {
case FAULT_INPUT_OVP:
case FAULT_INPUT_UVLO:
case FAULT_INPUT_LDO_LOW:
state->power_good = false;
break;
default:
state->power_good = true;
}
return 0;
}
static bool bq24257_state_changed(struct bq24257_device *bq,
struct bq24257_state *new_state)
{
int ret;
mutex_lock(&bq->lock);
ret = (bq->state.status != new_state->status ||
bq->state.fault != new_state->fault ||
bq->state.power_good != new_state->power_good);
mutex_unlock(&bq->lock);
return ret;
}
static int bq24257_iilimit_autoset(struct bq24257_device *bq)
{
int loop_status;
int iilimit;
int port_type;
int ret;
const u8 new_iilimit[] = {
[PORT_TYPE_DCP] = IILIMIT_2000,
[PORT_TYPE_CDP] = IILIMIT_2000,
[PORT_TYPE_SDP] = IILIMIT_500,
[PORT_TYPE_NON_STANDARD] = IILIMIT_500
};
ret = bq24257_field_read(bq, F_LOOP_STATUS);
if (ret < 0)
goto error;
loop_status = ret;
ret = bq24257_field_read(bq, F_IILIMIT);
if (ret < 0)
goto error;
iilimit = ret;
if (loop_status == LOOP_STATUS_IN_DPM && iilimit == IILIMIT_500)
return 0;
ret = bq24257_field_read(bq, F_USB_DET);
if (ret < 0)
goto error;
port_type = ret;
ret = bq24257_field_write(bq, F_IILIMIT, new_iilimit[port_type]);
if (ret < 0)
goto error;
ret = bq24257_field_write(bq, F_TMR, SAFETY_TIMER_360);
if (ret < 0)
goto error;
ret = bq24257_field_write(bq, F_CLR_VDP, 1);
if (ret < 0)
goto error;
dev_dbg(bq->dev, "port/loop = %d/%d -> iilimit = %d\n",
port_type, loop_status, new_iilimit[port_type]);
return 0;
error:
dev_err(bq->dev, "%s: Error communicating with the chip.\n", __func__);
return ret;
}
static void bq24257_iilimit_setup_work(struct work_struct *work)
{
struct bq24257_device *bq = container_of(work, struct bq24257_device,
iilimit_setup_work.work);
bq24257_iilimit_autoset(bq);
}
static void bq24257_handle_state_change(struct bq24257_device *bq,
struct bq24257_state *new_state)
{
int ret;
struct bq24257_state old_state;
mutex_lock(&bq->lock);
old_state = bq->state;
mutex_unlock(&bq->lock);
if (!new_state->power_good) {
dev_dbg(bq->dev, "Power removed\n");
if (bq->iilimit_autoset_enable) {
cancel_delayed_work_sync(&bq->iilimit_setup_work);
ret = bq24257_field_write(bq, F_DPDM_EN, 1);
if (ret < 0)
goto error;
}
ret = bq24257_field_write(bq, F_IILIMIT, bq->init_data.iilimit);
if (ret < 0)
goto error;
} else if (!old_state.power_good) {
dev_dbg(bq->dev, "Power inserted\n");
if (bq->iilimit_autoset_enable)
schedule_delayed_work(&bq->iilimit_setup_work,
msecs_to_jiffies(BQ24257_ILIM_SET_DELAY));
} else if (new_state->fault == FAULT_NO_BAT) {
dev_warn(bq->dev, "Battery removed\n");
} else if (new_state->fault == FAULT_TIMER) {
dev_err(bq->dev, "Safety timer expired! Battery dead?\n");
}
return;
error:
dev_err(bq->dev, "%s: Error communicating with the chip.\n", __func__);
}
static irqreturn_t bq24257_irq_handler_thread(int irq, void *private)
{
int ret;
struct bq24257_device *bq = private;
struct bq24257_state state;
ret = bq24257_get_chip_state(bq, &state);
if (ret < 0)
return IRQ_HANDLED;
if (!bq24257_state_changed(bq, &state))
return IRQ_HANDLED;
dev_dbg(bq->dev, "irq(state changed): status/fault/pg = %d/%d/%d\n",
state.status, state.fault, state.power_good);
bq24257_handle_state_change(bq, &state);
mutex_lock(&bq->lock);
bq->state = state;
mutex_unlock(&bq->lock);
power_supply_changed(bq->charger);
return IRQ_HANDLED;
}
static int bq24257_hw_init(struct bq24257_device *bq)
{
int ret;
int i;
struct bq24257_state state;
const struct {
int field;
u32 value;
} init_data[] = {
{F_ICHG, bq->init_data.ichg},
{F_VBAT, bq->init_data.vbat},
{F_ITERM, bq->init_data.iterm},
{F_VOVP, bq->init_data.vovp},
{F_VINDPM, bq->init_data.vindpm},
};
ret = bq24257_field_write(bq, F_WD_EN, 0);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(init_data); i++) {
ret = bq24257_field_write(bq, init_data[i].field,
init_data[i].value);
if (ret < 0)
return ret;
}
ret = bq24257_get_chip_state(bq, &state);
if (ret < 0)
return ret;
mutex_lock(&bq->lock);
bq->state = state;
mutex_unlock(&bq->lock);
if (!bq->iilimit_autoset_enable) {
dev_dbg(bq->dev, "manually setting iilimit = %u\n",
bq->init_data.iilimit);
ret = bq24257_field_write(bq, F_IILIMIT,
bq->init_data.iilimit);
if (ret < 0)
return ret;
} else if (!state.power_good)
ret = bq24257_field_write(bq, F_DPDM_EN, 1);
else if (state.fault != FAULT_NO_BAT)
ret = bq24257_iilimit_autoset(bq);
return ret;
}
static ssize_t bq24257_show_ovp_voltage(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24257_device *bq = power_supply_get_drvdata(psy);
return scnprintf(buf, PAGE_SIZE, "%u\n",
bq24257_vovp_map[bq->init_data.vovp]);
}
static ssize_t bq24257_show_in_dpm_voltage(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24257_device *bq = power_supply_get_drvdata(psy);
return scnprintf(buf, PAGE_SIZE, "%u\n",
bq24257_vindpm_map[bq->init_data.vindpm]);
}
static ssize_t bq24257_sysfs_show_enable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24257_device *bq = power_supply_get_drvdata(psy);
int ret;
if (strcmp(attr->attr.name, "high_impedance_enable") == 0)
ret = bq24257_field_read(bq, F_HZ_MODE);
else if (strcmp(attr->attr.name, "sysoff_enable") == 0)
ret = bq24257_field_read(bq, F_SYSOFF);
else
return -EINVAL;
if (ret < 0)
return ret;
return scnprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t bq24257_sysfs_set_enable(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24257_device *bq = power_supply_get_drvdata(psy);
long val;
int ret;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if (strcmp(attr->attr.name, "high_impedance_enable") == 0)
ret = bq24257_field_write(bq, F_HZ_MODE, (bool)val);
else if (strcmp(attr->attr.name, "sysoff_enable") == 0)
ret = bq24257_field_write(bq, F_SYSOFF, (bool)val);
else
return -EINVAL;
if (ret < 0)
return ret;
return count;
}
static int bq24257_power_supply_init(struct bq24257_device *bq)
{
struct power_supply_config psy_cfg = { .drv_data = bq, };
psy_cfg.supplied_to = bq24257_charger_supplied_to;
psy_cfg.num_supplicants = ARRAY_SIZE(bq24257_charger_supplied_to);
bq->charger = devm_power_supply_register(bq->dev,
&bq24257_power_supply_desc,
&psy_cfg);
return PTR_ERR_OR_ZERO(bq->charger);
}
static void bq24257_pg_gpio_probe(struct bq24257_device *bq)
{
bq->pg = devm_gpiod_get_optional(bq->dev, BQ24257_PG_GPIO, GPIOD_IN);
if (PTR_ERR(bq->pg) == -EPROBE_DEFER) {
dev_info(bq->dev, "probe retry requested for PG pin\n");
return;
} else if (IS_ERR(bq->pg)) {
dev_err(bq->dev, "error probing PG pin\n");
bq->pg = NULL;
return;
}
if (bq->pg)
dev_dbg(bq->dev, "probed PG pin = %d\n", desc_to_gpio(bq->pg));
}
static int bq24257_fw_probe(struct bq24257_device *bq)
{
int ret;
u32 property;
ret = device_property_read_u32(bq->dev, "ti,charge-current", &property);
if (ret < 0)
return ret;
bq->init_data.ichg = bq24257_find_idx(property, bq24257_ichg_map,
BQ24257_ICHG_MAP_SIZE);
ret = device_property_read_u32(bq->dev, "ti,battery-regulation-voltage",
&property);
if (ret < 0)
return ret;
bq->init_data.vbat = bq24257_find_idx(property, bq24257_vbat_map,
BQ24257_VBAT_MAP_SIZE);
ret = device_property_read_u32(bq->dev, "ti,termination-current",
&property);
if (ret < 0)
return ret;
bq->init_data.iterm = bq24257_find_idx(property, bq24257_iterm_map,
BQ24257_ITERM_MAP_SIZE);
ret = device_property_read_u32(bq->dev, "ti,current-limit",
&property);
if (ret < 0) {
bq->iilimit_autoset_enable = true;
bq->init_data.iilimit = IILIMIT_500;
} else
bq->init_data.iilimit =
bq24257_find_idx(property,
bq24257_iilimit_map,
BQ24257_IILIMIT_MAP_SIZE);
ret = device_property_read_u32(bq->dev, "ti,ovp-voltage",
&property);
if (ret < 0)
bq->init_data.vovp = VOVP_6500;
else
bq->init_data.vovp = bq24257_find_idx(property,
bq24257_vovp_map,
BQ24257_VOVP_MAP_SIZE);
ret = device_property_read_u32(bq->dev, "ti,in-dpm-voltage",
&property);
if (ret < 0)
bq->init_data.vindpm = VINDPM_4360;
else
bq->init_data.vindpm =
bq24257_find_idx(property,
bq24257_vindpm_map,
BQ24257_VINDPM_MAP_SIZE);
return 0;
}
static int bq24257_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct device *dev = &client->dev;
const struct acpi_device_id *acpi_id;
struct bq24257_device *bq;
int ret;
int i;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(dev, "No support for SMBUS_BYTE_DATA\n");
return -ENODEV;
}
bq = devm_kzalloc(dev, sizeof(*bq), GFP_KERNEL);
if (!bq)
return -ENOMEM;
bq->client = client;
bq->dev = dev;
if (ACPI_HANDLE(dev)) {
acpi_id = acpi_match_device(dev->driver->acpi_match_table,
&client->dev);
if (!acpi_id) {
dev_err(dev, "Failed to match ACPI device\n");
return -ENODEV;
}
bq->chip = (enum bq2425x_chip)acpi_id->driver_data;
} else {
bq->chip = (enum bq2425x_chip)id->driver_data;
}
mutex_init(&bq->lock);
bq->rmap = devm_regmap_init_i2c(client, &bq24257_regmap_config);
if (IS_ERR(bq->rmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(bq->rmap);
}
for (i = 0; i < ARRAY_SIZE(bq24257_reg_fields); i++) {
const struct reg_field *reg_fields = bq24257_reg_fields;
bq->rmap_fields[i] = devm_regmap_field_alloc(dev, bq->rmap,
reg_fields[i]);
if (IS_ERR(bq->rmap_fields[i])) {
dev_err(dev, "cannot allocate regmap field\n");
return PTR_ERR(bq->rmap_fields[i]);
}
}
i2c_set_clientdata(client, bq);
if (!dev->platform_data) {
ret = bq24257_fw_probe(bq);
if (ret < 0) {
dev_err(dev, "Cannot read device properties.\n");
return ret;
}
} else {
return -ENODEV;
}
if (bq->chip == BQ24250)
bq->iilimit_autoset_enable = false;
if (bq->iilimit_autoset_enable)
INIT_DELAYED_WORK(&bq->iilimit_setup_work,
bq24257_iilimit_setup_work);
if (bq->chip != BQ24250)
bq24257_pg_gpio_probe(bq);
if (PTR_ERR(bq->pg) == -EPROBE_DEFER)
return PTR_ERR(bq->pg);
else if (!bq->pg)
dev_info(bq->dev, "using SW-based power-good detection\n");
ret = bq24257_field_write(bq, F_RESET, 1);
if (ret < 0)
return ret;
ret = bq24257_field_write(bq, F_RESET, 0);
if (ret < 0)
return ret;
ret = bq24257_hw_init(bq);
if (ret < 0) {
dev_err(dev, "Cannot initialize the chip.\n");
return ret;
}
ret = devm_request_threaded_irq(dev, client->irq, NULL,
bq24257_irq_handler_thread,
IRQF_TRIGGER_FALLING |
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
bq2425x_chip_name[bq->chip], bq);
if (ret) {
dev_err(dev, "Failed to request IRQ #%d\n", client->irq);
return ret;
}
ret = bq24257_power_supply_init(bq);
if (ret < 0) {
dev_err(dev, "Failed to register power supply\n");
return ret;
}
ret = sysfs_create_group(&bq->charger->dev.kobj, &bq24257_attr_group);
if (ret < 0) {
dev_err(dev, "Can't create sysfs entries\n");
return ret;
}
return 0;
}
static int bq24257_remove(struct i2c_client *client)
{
struct bq24257_device *bq = i2c_get_clientdata(client);
if (bq->iilimit_autoset_enable)
cancel_delayed_work_sync(&bq->iilimit_setup_work);
sysfs_remove_group(&bq->charger->dev.kobj, &bq24257_attr_group);
bq24257_field_write(bq, F_RESET, 1);
return 0;
}
static int bq24257_suspend(struct device *dev)
{
struct bq24257_device *bq = dev_get_drvdata(dev);
int ret = 0;
if (bq->iilimit_autoset_enable)
cancel_delayed_work_sync(&bq->iilimit_setup_work);
ret = bq24257_field_write(bq, F_RESET, 1);
if (ret < 0)
dev_err(bq->dev, "Cannot reset chip to standalone mode.\n");
return ret;
}
static int bq24257_resume(struct device *dev)
{
int ret;
struct bq24257_device *bq = dev_get_drvdata(dev);
ret = regcache_drop_region(bq->rmap, BQ24257_REG_1, BQ24257_REG_7);
if (ret < 0)
return ret;
ret = bq24257_field_write(bq, F_RESET, 0);
if (ret < 0)
return ret;
ret = bq24257_hw_init(bq);
if (ret < 0) {
dev_err(bq->dev, "Cannot init chip after resume.\n");
return ret;
}
power_supply_changed(bq->charger);
return 0;
}
