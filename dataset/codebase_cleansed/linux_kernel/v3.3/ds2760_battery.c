static int battery_interpolate(int array[], int temp)
{
int index, dt;
if (temp <= 0)
return array[0];
if (temp >= 40)
return array[4];
index = temp / 10;
dt = temp % 10;
return array[index] + (((array[index + 1] - array[index]) * dt) / 10);
}
static int ds2760_battery_read_status(struct ds2760_device_info *di)
{
int ret, i, start, count, scale[5];
if (di->update_time && time_before(jiffies, di->update_time +
msecs_to_jiffies(cache_time)))
return 0;
if (di->update_time == 0) {
start = 0;
count = DS2760_DATA_SIZE;
} else {
start = DS2760_VOLTAGE_MSB;
count = DS2760_TEMP_LSB - start + 1;
}
ret = w1_ds2760_read(di->w1_dev, di->raw + start, start, count);
if (ret != count) {
dev_warn(di->dev, "call to w1_ds2760_read failed (0x%p)\n",
di->w1_dev);
return 1;
}
di->update_time = jiffies;
di->voltage_raw = (di->raw[DS2760_VOLTAGE_MSB] << 3) |
(di->raw[DS2760_VOLTAGE_LSB] >> 5);
di->voltage_uV = di->voltage_raw * 4880;
di->current_raw =
(((signed char)di->raw[DS2760_CURRENT_MSB]) << 5) |
(di->raw[DS2760_CURRENT_LSB] >> 3);
di->current_uA = di->current_raw * 625;
di->accum_current_raw =
(((signed char)di->raw[DS2760_CURRENT_ACCUM_MSB]) << 8) |
di->raw[DS2760_CURRENT_ACCUM_LSB];
di->accum_current_uAh = di->accum_current_raw * 250;
di->temp_raw = (((signed char)di->raw[DS2760_TEMP_MSB]) << 3) |
(di->raw[DS2760_TEMP_LSB] >> 5);
di->temp_C = di->temp_raw + (di->temp_raw / 4);
if (di->raw[DS2760_RATED_CAPACITY] < ARRAY_SIZE(rated_capacities))
di->rated_capacity = rated_capacities[
(unsigned int)di->raw[DS2760_RATED_CAPACITY]];
else
di->rated_capacity = di->raw[DS2760_RATED_CAPACITY] * 10;
di->rated_capacity *= 1000;
di->full_active_uAh = di->raw[DS2760_ACTIVE_FULL] << 8 |
di->raw[DS2760_ACTIVE_FULL + 1];
if (di->full_active_uAh == 0)
di->full_active_uAh = di->rated_capacity / 1000L;
scale[0] = di->full_active_uAh;
for (i = 1; i < 5; i++)
scale[i] = scale[i - 1] + di->raw[DS2760_ACTIVE_FULL + 1 + i];
di->full_active_uAh = battery_interpolate(scale, di->temp_C / 10);
di->full_active_uAh *= 1000;
scale[4] = di->raw[DS2760_ACTIVE_EMPTY + 4];
for (i = 3; i >= 0; i--)
scale[i] = scale[i + 1] + di->raw[DS2760_ACTIVE_EMPTY + i];
di->empty_uAh = battery_interpolate(scale, di->temp_C / 10);
di->empty_uAh *= 1000;
if (di->full_active_uAh == di->empty_uAh)
di->rem_capacity = 0;
else
di->rem_capacity = ((di->accum_current_uAh - di->empty_uAh) * 100L) /
(di->full_active_uAh - di->empty_uAh);
if (di->rem_capacity < 0)
di->rem_capacity = 0;
if (di->rem_capacity > 100)
di->rem_capacity = 100;
if (di->current_uA < -100L)
di->life_sec = -((di->accum_current_uAh - di->empty_uAh) * 36L)
/ (di->current_uA / 100L);
else
di->life_sec = 0;
return 0;
}
static void ds2760_battery_set_current_accum(struct ds2760_device_info *di,
unsigned int acr_val)
{
unsigned char acr[2];
acr_val *= 4L;
acr_val /= 1000;
acr[0] = acr_val >> 8;
acr[1] = acr_val & 0xff;
if (w1_ds2760_write(di->w1_dev, acr, DS2760_CURRENT_ACCUM_MSB, 2) < 2)
dev_warn(di->dev, "ACR write failed\n");
}
static void ds2760_battery_update_status(struct ds2760_device_info *di)
{
int old_charge_status = di->charge_status;
ds2760_battery_read_status(di);
if (di->charge_status == POWER_SUPPLY_STATUS_UNKNOWN)
di->full_counter = 0;
if (power_supply_am_i_supplied(&di->bat)) {
if (di->current_uA > 10000) {
di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
di->full_counter = 0;
} else if (di->current_uA < -5000) {
if (di->charge_status != POWER_SUPPLY_STATUS_NOT_CHARGING)
dev_notice(di->dev, "not enough power to "
"charge\n");
di->charge_status = POWER_SUPPLY_STATUS_NOT_CHARGING;
di->full_counter = 0;
} else if (di->current_uA < 10000 &&
di->charge_status != POWER_SUPPLY_STATUS_FULL) {
di->full_counter++;
if (di->full_counter < 2) {
di->charge_status = POWER_SUPPLY_STATUS_CHARGING;
} else {
di->charge_status = POWER_SUPPLY_STATUS_FULL;
ds2760_battery_set_current_accum(di,
di->full_active_uAh);
}
}
} else {
di->charge_status = POWER_SUPPLY_STATUS_DISCHARGING;
di->full_counter = 0;
}
if (di->charge_status != old_charge_status)
power_supply_changed(&di->bat);
}
static void ds2760_battery_write_status(struct ds2760_device_info *di,
char status)
{
if (status == di->raw[DS2760_STATUS_REG])
return;
w1_ds2760_write(di->w1_dev, &status, DS2760_STATUS_WRITE_REG, 1);
w1_ds2760_store_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
w1_ds2760_recall_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
}
static void ds2760_battery_write_rated_capacity(struct ds2760_device_info *di,
unsigned char rated_capacity)
{
if (rated_capacity == di->raw[DS2760_RATED_CAPACITY])
return;
w1_ds2760_write(di->w1_dev, &rated_capacity, DS2760_RATED_CAPACITY, 1);
w1_ds2760_store_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
w1_ds2760_recall_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
}
static void ds2760_battery_write_active_full(struct ds2760_device_info *di,
int active_full)
{
unsigned char tmp[2] = {
active_full >> 8,
active_full & 0xff
};
if (tmp[0] == di->raw[DS2760_ACTIVE_FULL] &&
tmp[1] == di->raw[DS2760_ACTIVE_FULL + 1])
return;
w1_ds2760_write(di->w1_dev, tmp, DS2760_ACTIVE_FULL, sizeof(tmp));
w1_ds2760_store_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK0);
w1_ds2760_recall_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK0);
di->raw[DS2760_ACTIVE_FULL] = tmp[0];
di->raw[DS2760_ACTIVE_FULL + 1] = tmp[1];
}
static void ds2760_battery_work(struct work_struct *work)
{
struct ds2760_device_info *di = container_of(work,
struct ds2760_device_info, monitor_work.work);
const int interval = HZ * 60;
dev_dbg(di->dev, "%s\n", __func__);
ds2760_battery_update_status(di);
queue_delayed_work(di->monitor_wqueue, &di->monitor_work, interval);
}
static void ds2760_battery_external_power_changed(struct power_supply *psy)
{
struct ds2760_device_info *di = to_ds2760_device_info(psy);
dev_dbg(di->dev, "%s\n", __func__);
cancel_delayed_work(&di->monitor_work);
queue_delayed_work(di->monitor_wqueue, &di->monitor_work, HZ/10);
}
static void ds2760_battery_set_charged_work(struct work_struct *work)
{
char bias;
struct ds2760_device_info *di = container_of(work,
struct ds2760_device_info, set_charged_work.work);
dev_dbg(di->dev, "%s\n", __func__);
ds2760_battery_read_status(di);
if (!power_supply_am_i_supplied(&di->bat))
return;
bias = (signed char) di->current_raw +
(signed char) di->raw[DS2760_CURRENT_OFFSET_BIAS];
dev_dbg(di->dev, "%s: bias = %d\n", __func__, bias);
w1_ds2760_write(di->w1_dev, &bias, DS2760_CURRENT_OFFSET_BIAS, 1);
w1_ds2760_store_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
w1_ds2760_recall_eeprom(di->w1_dev, DS2760_EEPROM_BLOCK1);
di->raw[DS2760_CURRENT_OFFSET_BIAS] = bias;
}
static void ds2760_battery_set_charged(struct power_supply *psy)
{
struct ds2760_device_info *di = to_ds2760_device_info(psy);
cancel_delayed_work(&di->set_charged_work);
queue_delayed_work(di->monitor_wqueue, &di->set_charged_work, HZ * 20);
}
static int ds2760_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct ds2760_device_info *di = to_ds2760_device_info(psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = di->charge_status;
return 0;
default:
break;
}
ds2760_battery_read_status(di);
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = di->voltage_uV;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
val->intval = di->current_uA;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = di->rated_capacity;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
val->intval = di->full_active_uAh;
break;
case POWER_SUPPLY_PROP_CHARGE_EMPTY:
val->intval = di->empty_uAh;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
val->intval = di->accum_current_uAh;
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = di->temp_C;
break;
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_NOW:
val->intval = di->life_sec;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = di->rem_capacity;
break;
default:
return -EINVAL;
}
return 0;
}
static int ds2760_battery_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct ds2760_device_info *di = to_ds2760_device_info(psy);
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_FULL:
ds2760_battery_write_active_full(di, val->intval / 1000L);
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
ds2760_battery_set_current_accum(di, val->intval);
break;
default:
return -EPERM;
}
return 0;
}
static int ds2760_battery_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_FULL:
case POWER_SUPPLY_PROP_CHARGE_NOW:
return 1;
default:
break;
}
return 0;
}
static int ds2760_battery_probe(struct platform_device *pdev)
{
char status;
int retval = 0;
struct ds2760_device_info *di;
di = kzalloc(sizeof(*di), GFP_KERNEL);
if (!di) {
retval = -ENOMEM;
goto di_alloc_failed;
}
platform_set_drvdata(pdev, di);
di->dev = &pdev->dev;
di->w1_dev = pdev->dev.parent;
di->bat.name = dev_name(&pdev->dev);
di->bat.type = POWER_SUPPLY_TYPE_BATTERY;
di->bat.properties = ds2760_battery_props;
di->bat.num_properties = ARRAY_SIZE(ds2760_battery_props);
di->bat.get_property = ds2760_battery_get_property;
di->bat.set_property = ds2760_battery_set_property;
di->bat.property_is_writeable =
ds2760_battery_property_is_writeable;
di->bat.set_charged = ds2760_battery_set_charged;
di->bat.external_power_changed =
ds2760_battery_external_power_changed;
di->charge_status = POWER_SUPPLY_STATUS_UNKNOWN;
ds2760_battery_read_status(di);
status = di->raw[DS2760_STATUS_REG];
if (pmod_enabled)
status |= DS2760_STATUS_PMOD;
else
status &= ~DS2760_STATUS_PMOD;
ds2760_battery_write_status(di, status);
if (rated_capacity)
ds2760_battery_write_rated_capacity(di, rated_capacity);
if (current_accum)
ds2760_battery_set_current_accum(di, current_accum);
retval = power_supply_register(&pdev->dev, &di->bat);
if (retval) {
dev_err(di->dev, "failed to register battery\n");
goto batt_failed;
}
INIT_DELAYED_WORK(&di->monitor_work, ds2760_battery_work);
INIT_DELAYED_WORK(&di->set_charged_work,
ds2760_battery_set_charged_work);
di->monitor_wqueue = create_singlethread_workqueue(dev_name(&pdev->dev));
if (!di->monitor_wqueue) {
retval = -ESRCH;
goto workqueue_failed;
}
queue_delayed_work(di->monitor_wqueue, &di->monitor_work, HZ * 1);
goto success;
workqueue_failed:
power_supply_unregister(&di->bat);
batt_failed:
kfree(di);
di_alloc_failed:
success:
return retval;
}
static int ds2760_battery_remove(struct platform_device *pdev)
{
struct ds2760_device_info *di = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&di->monitor_work);
cancel_delayed_work_sync(&di->set_charged_work);
destroy_workqueue(di->monitor_wqueue);
power_supply_unregister(&di->bat);
kfree(di);
return 0;
}
static int ds2760_battery_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct ds2760_device_info *di = platform_get_drvdata(pdev);
di->charge_status = POWER_SUPPLY_STATUS_UNKNOWN;
return 0;
}
static int ds2760_battery_resume(struct platform_device *pdev)
{
struct ds2760_device_info *di = platform_get_drvdata(pdev);
di->charge_status = POWER_SUPPLY_STATUS_UNKNOWN;
power_supply_changed(&di->bat);
cancel_delayed_work(&di->monitor_work);
queue_delayed_work(di->monitor_wqueue, &di->monitor_work, HZ);
return 0;
}
