static u8 ec_read_u8(u8 addr)
{
u8 value;
ec_read(addr, &value);
return value;
}
static s8 ec_read_s8(u8 addr)
{
return (s8)ec_read_u8(addr);
}
static u16 ec_read_u16(u8 addr)
{
int hi, lo;
lo = ec_read_u8(addr);
hi = ec_read_u8(addr + 1);
return (hi << 8) + lo;
}
static s16 ec_read_s16(u8 addr)
{
return (s16) ec_read_u16(addr);
}
static void ec_read_sequence(u8 addr, u8 *buf, int len)
{
int i;
for (i = 0; i < len; i++)
ec_read(addr + i, buf + i);
}
static int set_backlight_level(int level)
{
if (level < 0 || level > BACKLIGHT_LEVEL_MAX)
return -EINVAL;
ec_write(BACKLIGHT_LEVEL_ADDR, level);
return 0;
}
static int get_backlight_level(void)
{
return (int) ec_read_u8(BACKLIGHT_LEVEL_ADDR);
}
static void set_backlight_state(bool on)
{
u8 data = on ? BACKLIGHT_STATE_ON_DATA : BACKLIGHT_STATE_OFF_DATA;
ec_transaction(BACKLIGHT_STATE_ADDR, &data, 1, NULL, 0);
}
static void pwm_enable_control(void)
{
unsigned char writeData = PWM_ENABLE_DATA;
ec_transaction(PWM_ENABLE_ADDR, &writeData, 1, NULL, 0);
}
static void pwm_disable_control(void)
{
unsigned char writeData = PWM_DISABLE_DATA;
ec_transaction(PWM_DISABLE_ADDR, &writeData, 1, NULL, 0);
}
static void set_pwm(int pwm)
{
ec_transaction(PWM_ADDRESS, &pwm_lookup_table[pwm], 1, NULL, 0);
}
static int get_fan_rpm(void)
{
u8 value, data = FAN_DATA;
ec_transaction(FAN_ADDRESS, &data, 1, &value, 1);
return 100 * (int)value;
}
static int bl_get_brightness(struct backlight_device *b)
{
return get_backlight_level();
}
static int bl_update_status(struct backlight_device *b)
{
int ret = set_backlight_level(b->props.brightness);
if (ret)
return ret;
set_backlight_state((b->props.power == FB_BLANK_UNBLANK)
&& !(b->props.state & BL_CORE_SUSPENDED)
&& !(b->props.state & BL_CORE_FBBLANK));
return 0;
}
static int compal_rfkill_set(void *data, bool blocked)
{
unsigned long radio = (unsigned long) data;
u8 result = ec_read_u8(WIRELESS_ADDR);
u8 value;
if (!blocked)
value = (u8) (result | radio);
else
value = (u8) (result & ~radio);
ec_write(WIRELESS_ADDR, value);
return 0;
}
static void compal_rfkill_poll(struct rfkill *rfkill, void *data)
{
u8 result = ec_read_u8(WIRELESS_ADDR);
bool hw_blocked = !(result & WIRELESS_KILLSWITCH);
rfkill_set_hw_state(rfkill, hw_blocked);
}
static ssize_t hwmon_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", DRIVER_NAME);
}
static ssize_t pwm_enable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct compal_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->pwm_enable);
}
static ssize_t pwm_enable_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct compal_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (val < 0)
return -EINVAL;
data->pwm_enable = val;
switch (val) {
case 0:
pwm_enable_control();
set_pwm(255);
break;
case 1:
pwm_enable_control();
set_pwm(data->curr_pwm);
break;
default:
pwm_disable_control();
break;
}
return count;
}
static ssize_t pwm_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct compal_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%hhu\n", data->curr_pwm);
}
static ssize_t pwm_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct compal_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (val < 0 || val > 255)
return -EINVAL;
data->curr_pwm = val;
if (data->pwm_enable != 1)
return count;
set_pwm(val);
return count;
}
static ssize_t fan_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", get_fan_rpm());
}
static int bat_status(void)
{
u8 status0 = ec_read_u8(BAT_STATUS0);
u8 status1 = ec_read_u8(BAT_STATUS1);
if (status0 & BAT_S0_CHARGING)
return POWER_SUPPLY_STATUS_CHARGING;
if (status0 & BAT_S0_DISCHARGE)
return POWER_SUPPLY_STATUS_DISCHARGING;
if (status1 & BAT_S1_FULL)
return POWER_SUPPLY_STATUS_FULL;
return POWER_SUPPLY_STATUS_NOT_CHARGING;
}
static int bat_health(void)
{
u8 status = ec_read_u8(BAT_STOP_CHARGE1);
if (status & BAT_STOP_CHRG1_OVERTEMPERATURE)
return POWER_SUPPLY_HEALTH_OVERHEAT;
if (status & BAT_STOP_CHRG1_OVERVOLTAGE)
return POWER_SUPPLY_HEALTH_OVERVOLTAGE;
if (status & BAT_STOP_CHRG1_BAD_CELL)
return POWER_SUPPLY_HEALTH_DEAD;
if (status & BAT_STOP_CHRG1_COMM_FAIL)
return POWER_SUPPLY_HEALTH_UNKNOWN;
return POWER_SUPPLY_HEALTH_GOOD;
}
static int bat_is_present(void)
{
u8 status = ec_read_u8(BAT_STATUS2);
return ((status & BAT_S1_EXISTS) != 0);
}
static int bat_technology(void)
{
u8 status = ec_read_u8(BAT_STATUS1);
if (status & BAT_S1_LiION_OR_NiMH)
return POWER_SUPPLY_TECHNOLOGY_LION;
return POWER_SUPPLY_TECHNOLOGY_NiMH;
}
static int bat_capacity_level(void)
{
u8 status0 = ec_read_u8(BAT_STATUS0);
u8 status1 = ec_read_u8(BAT_STATUS1);
u8 status2 = ec_read_u8(BAT_STATUS2);
if (status0 & BAT_S0_DISCHRG_CRITICAL
|| status1 & BAT_S1_EMPTY
|| status2 & BAT_S2_LOW_LOW)
return POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
if (status0 & BAT_S0_LOW)
return POWER_SUPPLY_CAPACITY_LEVEL_LOW;
if (status1 & BAT_S1_FULL)
return POWER_SUPPLY_CAPACITY_LEVEL_FULL;
return POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
}
static int bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct compal_data *data;
data = container_of(psy, struct compal_data, psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = bat_status();
break;
case POWER_SUPPLY_PROP_HEALTH:
val->intval = bat_health();
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = bat_is_present();
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = bat_technology();
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = ec_read_u16(BAT_VOLTAGE_DESIGN) * 1000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = ec_read_u16(BAT_VOLTAGE_NOW) * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
val->intval = ec_read_s16(BAT_CURRENT_NOW) * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
val->intval = ec_read_s16(BAT_CURRENT_AVG) * 1000;
break;
case POWER_SUPPLY_PROP_POWER_NOW:
val->intval = ec_read_u8(BAT_POWER) * 1000000;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = ec_read_u16(BAT_CHARGE_DESIGN) * 1000;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
val->intval = ec_read_u16(BAT_CHARGE_NOW) * 1000;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = ec_read_u8(BAT_CAPACITY);
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
val->intval = bat_capacity_level();
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = ((222 - (int)ec_read_u8(BAT_TEMP)) * 1000) >> 8;
break;
case POWER_SUPPLY_PROP_TEMP_AMBIENT:
val->intval = ec_read_s8(BAT_TEMP_AVG) * 10;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = data->bat_model_name;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = data->bat_manufacturer_name;
break;
case POWER_SUPPLY_PROP_SERIAL_NUMBER:
val->strval = data->bat_serial_number;
break;
default:
break;
}
return 0;
}
static int dmi_check_cb(const struct dmi_system_id *id)
{
pr_info("Identified laptop model '%s'\n", id->ident);
extra_features = false;
return 1;
}
static int dmi_check_cb_extra(const struct dmi_system_id *id)
{
pr_info("Identified laptop model '%s', enabling extra features\n",
id->ident);
extra_features = true;
return 1;
}
static void initialize_power_supply_data(struct compal_data *data)
{
data->psy.name = DRIVER_NAME;
data->psy.type = POWER_SUPPLY_TYPE_BATTERY;
data->psy.properties = compal_bat_properties;
data->psy.num_properties = ARRAY_SIZE(compal_bat_properties);
data->psy.get_property = bat_get_property;
ec_read_sequence(BAT_MANUFACTURER_NAME_ADDR,
data->bat_manufacturer_name,
BAT_MANUFACTURER_NAME_LEN);
data->bat_manufacturer_name[BAT_MANUFACTURER_NAME_LEN] = 0;
ec_read_sequence(BAT_MODEL_NAME_ADDR,
data->bat_model_name,
BAT_MODEL_NAME_LEN);
data->bat_model_name[BAT_MODEL_NAME_LEN] = 0;
scnprintf(data->bat_serial_number, BAT_SERIAL_NUMBER_LEN + 1, "%d",
ec_read_u16(BAT_SERIAL_NUMBER_ADDR));
}
static void initialize_fan_control_data(struct compal_data *data)
{
data->pwm_enable = 2;
data->curr_pwm = 255;
}
static int setup_rfkill(void)
{
int ret;
wifi_rfkill = rfkill_alloc("compal-wifi", &compal_device->dev,
RFKILL_TYPE_WLAN, &compal_rfkill_ops,
(void *) WIRELESS_WLAN);
if (!wifi_rfkill)
return -ENOMEM;
ret = rfkill_register(wifi_rfkill);
if (ret)
goto err_wifi;
bt_rfkill = rfkill_alloc("compal-bluetooth", &compal_device->dev,
RFKILL_TYPE_BLUETOOTH, &compal_rfkill_ops,
(void *) WIRELESS_BT);
if (!bt_rfkill) {
ret = -ENOMEM;
goto err_allocate_bt;
}
ret = rfkill_register(bt_rfkill);
if (ret)
goto err_register_bt;
return 0;
err_register_bt:
rfkill_destroy(bt_rfkill);
err_allocate_bt:
rfkill_unregister(wifi_rfkill);
err_wifi:
rfkill_destroy(wifi_rfkill);
return ret;
}
static int __init compal_init(void)
{
int ret;
if (acpi_disabled) {
pr_err("ACPI needs to be enabled for this driver to work!\n");
return -ENODEV;
}
if (!force && !dmi_check_system(compal_dmi_table)) {
pr_err("Motherboard not recognized (You could try the module's force-parameter)\n");
return -ENODEV;
}
if (!acpi_video_backlight_support()) {
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = BACKLIGHT_LEVEL_MAX;
compalbl_device = backlight_device_register(DRIVER_NAME,
NULL, NULL,
&compalbl_ops,
&props);
if (IS_ERR(compalbl_device))
return PTR_ERR(compalbl_device);
}
ret = platform_driver_register(&compal_driver);
if (ret)
goto err_backlight;
compal_device = platform_device_alloc(DRIVER_NAME, -1);
if (!compal_device) {
ret = -ENOMEM;
goto err_platform_driver;
}
ret = platform_device_add(compal_device);
if (ret)
goto err_platform_device;
ret = setup_rfkill();
if (ret)
goto err_rfkill;
pr_info("Driver " DRIVER_VERSION " successfully loaded\n");
return 0;
err_rfkill:
platform_device_del(compal_device);
err_platform_device:
platform_device_put(compal_device);
err_platform_driver:
platform_driver_unregister(&compal_driver);
err_backlight:
backlight_device_unregister(compalbl_device);
return ret;
}
static int compal_probe(struct platform_device *pdev)
{
int err;
struct compal_data *data;
if (!extra_features)
return 0;
data = kzalloc(sizeof(struct compal_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
initialize_fan_control_data(data);
err = sysfs_create_group(&pdev->dev.kobj, &compal_attribute_group);
if (err) {
kfree(data);
return err;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj,
&compal_attribute_group);
kfree(data);
return err;
}
initialize_power_supply_data(data);
power_supply_register(&compal_device->dev, &data->psy);
platform_set_drvdata(pdev, data);
return 0;
}
static void __exit compal_cleanup(void)
{
platform_device_unregister(compal_device);
platform_driver_unregister(&compal_driver);
backlight_device_unregister(compalbl_device);
rfkill_unregister(wifi_rfkill);
rfkill_unregister(bt_rfkill);
rfkill_destroy(wifi_rfkill);
rfkill_destroy(bt_rfkill);
pr_info("Driver unloaded\n");
}
static int compal_remove(struct platform_device *pdev)
{
struct compal_data *data;
if (!extra_features)
return 0;
pr_info("Unloading: resetting fan control to motherboard\n");
pwm_disable_control();
data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
power_supply_unregister(&data->psy);
kfree(data);
sysfs_remove_group(&pdev->dev.kobj, &compal_attribute_group);
return 0;
}
