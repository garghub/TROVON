static int ziirave_wdt_revision(struct i2c_client *client,
struct ziirave_wdt_rev *rev, u8 command)
{
int ret;
ret = i2c_smbus_read_byte_data(client, command);
if (ret < 0)
return ret;
rev->major = ret;
ret = i2c_smbus_read_byte_data(client, command + 1);
if (ret < 0)
return ret;
rev->minor = ret;
return 0;
}
static int ziirave_wdt_set_state(struct watchdog_device *wdd, int state)
{
struct i2c_client *client = to_i2c_client(wdd->parent);
return i2c_smbus_write_byte_data(client, ZIIRAVE_WDT_STATE, state);
}
static int ziirave_wdt_start(struct watchdog_device *wdd)
{
return ziirave_wdt_set_state(wdd, ZIIRAVE_STATE_ON);
}
static int ziirave_wdt_stop(struct watchdog_device *wdd)
{
return ziirave_wdt_set_state(wdd, ZIIRAVE_STATE_OFF);
}
static int ziirave_wdt_ping(struct watchdog_device *wdd)
{
struct i2c_client *client = to_i2c_client(wdd->parent);
return i2c_smbus_write_byte_data(client, ZIIRAVE_WDT_PING,
ZIIRAVE_PING_VALUE);
}
static int ziirave_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct i2c_client *client = to_i2c_client(wdd->parent);
int ret;
ret = i2c_smbus_write_byte_data(client, ZIIRAVE_WDT_TIMEOUT, timeout);
if (!ret)
wdd->timeout = timeout;
return ret;
}
static unsigned int ziirave_wdt_get_timeleft(struct watchdog_device *wdd)
{
struct i2c_client *client = to_i2c_client(wdd->parent);
int ret;
ret = i2c_smbus_read_byte_data(client, ZIIRAVE_WDT_TIME_LEFT);
if (ret < 0)
ret = 0;
return ret;
}
static ssize_t ziirave_wdt_sysfs_show_firm(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev->parent);
struct ziirave_wdt_data *w_priv = i2c_get_clientdata(client);
return sprintf(buf, "02.%02u.%02u", w_priv->firmware_rev.major,
w_priv->firmware_rev.minor);
}
static ssize_t ziirave_wdt_sysfs_show_boot(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev->parent);
struct ziirave_wdt_data *w_priv = i2c_get_clientdata(client);
return sprintf(buf, "01.%02u.%02u", w_priv->bootloader_rev.major,
w_priv->bootloader_rev.minor);
}
static ssize_t ziirave_wdt_sysfs_show_reason(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev->parent);
struct ziirave_wdt_data *w_priv = i2c_get_clientdata(client);
return sprintf(buf, "%s", ziirave_reasons[w_priv->reset_reason]);
}
static int ziirave_wdt_init_duration(struct i2c_client *client)
{
int ret;
if (!reset_duration) {
if (!client->dev.of_node)
ret = -ENODEV;
else
ret = of_property_read_u32(client->dev.of_node,
"reset-duration-ms",
&reset_duration);
if (ret) {
dev_info(&client->dev,
"Unable to set reset pulse duration, using default\n");
return 0;
}
}
if (reset_duration < 1 || reset_duration > 255)
return -EINVAL;
dev_info(&client->dev, "Setting reset duration to %dms",
reset_duration);
return i2c_smbus_write_byte_data(client, ZIIRAVE_WDT_RESET_DURATION,
reset_duration);
}
static int ziirave_wdt_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct ziirave_wdt_data *w_priv;
int val;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
w_priv = devm_kzalloc(&client->dev, sizeof(*w_priv), GFP_KERNEL);
if (!w_priv)
return -ENOMEM;
w_priv->wdd.info = &ziirave_wdt_info;
w_priv->wdd.ops = &ziirave_wdt_ops;
w_priv->wdd.min_timeout = ZIIRAVE_TIMEOUT_MIN;
w_priv->wdd.max_timeout = ZIIRAVE_TIMEOUT_MAX;
w_priv->wdd.parent = &client->dev;
w_priv->wdd.groups = ziirave_wdt_groups;
ret = watchdog_init_timeout(&w_priv->wdd, wdt_timeout, &client->dev);
if (ret) {
dev_info(&client->dev,
"Unable to select timeout value, using default\n");
}
if (w_priv->wdd.timeout == 0) {
val = i2c_smbus_read_byte_data(client, ZIIRAVE_WDT_TIMEOUT);
if (val < 0)
return val;
if (val < ZIIRAVE_TIMEOUT_MIN)
return -ENODEV;
w_priv->wdd.timeout = val;
} else {
ret = ziirave_wdt_set_timeout(&w_priv->wdd,
w_priv->wdd.timeout);
if (ret)
return ret;
dev_info(&client->dev, "Timeout set to %ds.",
w_priv->wdd.timeout);
}
watchdog_set_nowayout(&w_priv->wdd, nowayout);
i2c_set_clientdata(client, w_priv);
val = i2c_smbus_read_byte_data(client, ZIIRAVE_WDT_STATE);
if (val < 0)
return val;
if (val == ZIIRAVE_STATE_INITIAL)
ziirave_wdt_stop(&w_priv->wdd);
ret = ziirave_wdt_init_duration(client);
if (ret)
return ret;
ret = ziirave_wdt_revision(client, &w_priv->firmware_rev,
ZIIRAVE_WDT_FIRM_VER_MAJOR);
if (ret)
return ret;
ret = ziirave_wdt_revision(client, &w_priv->bootloader_rev,
ZIIRAVE_WDT_BOOT_VER_MAJOR);
if (ret)
return ret;
w_priv->reset_reason = i2c_smbus_read_byte_data(client,
ZIIRAVE_WDT_RESET_REASON);
if (w_priv->reset_reason < 0)
return w_priv->reset_reason;
if (w_priv->reset_reason >= ARRAY_SIZE(ziirave_reasons) ||
!ziirave_reasons[w_priv->reset_reason])
return -ENODEV;
ret = watchdog_register_device(&w_priv->wdd);
return ret;
}
static int ziirave_wdt_remove(struct i2c_client *client)
{
struct ziirave_wdt_data *w_priv = i2c_get_clientdata(client);
watchdog_unregister_device(&w_priv->wdd);
return 0;
}
