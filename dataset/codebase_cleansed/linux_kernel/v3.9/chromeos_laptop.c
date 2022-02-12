static struct i2c_client __init *__add_probed_i2c_device(
const char *name,
int bus,
struct i2c_board_info *info,
const unsigned short *addrs)
{
const struct dmi_device *dmi_dev;
const struct dmi_dev_onboard *dev_data;
struct i2c_adapter *adapter;
struct i2c_client *client;
if (bus < 0)
return NULL;
if (name) {
dmi_dev = dmi_find_device(DMI_DEV_TYPE_DEV_ONBOARD, name, NULL);
if (!dmi_dev) {
pr_err("%s failed to dmi find device %s.\n",
__func__,
name);
return NULL;
}
dev_data = (struct dmi_dev_onboard *)dmi_dev->device_data;
if (!dev_data) {
pr_err("%s failed to get data from dmi for %s.\n",
__func__, name);
return NULL;
}
info->irq = dev_data->instance;
}
adapter = i2c_get_adapter(bus);
if (!adapter) {
pr_err("%s failed to get i2c adapter %d.\n", __func__, bus);
return NULL;
}
client = i2c_new_probed_device(adapter, info, addrs, NULL);
if (!client)
pr_err("%s failed to register device %d-%02x\n",
__func__, bus, info->addr);
else
pr_debug("%s added i2c device %d-%02x\n",
__func__, bus, info->addr);
i2c_put_adapter(adapter);
return client;
}
static int __init __find_i2c_adap(struct device *dev, void *data)
{
const char *name = data;
static const char *prefix = "i2c-";
struct i2c_adapter *adapter;
if (strncmp(dev_name(dev), prefix, strlen(prefix)) != 0)
return 0;
adapter = to_i2c_adapter(dev);
return (strncmp(adapter->name, name, strlen(name)) == 0);
}
static int __init find_i2c_adapter_num(enum i2c_adapter_type type)
{
struct device *dev = NULL;
struct i2c_adapter *adapter;
const char *name = i2c_adapter_names[type];
dev = bus_find_device(&i2c_bus_type, NULL, (void *)name,
__find_i2c_adap);
if (!dev) {
pr_err("%s: i2c adapter %s not found on system.\n", __func__,
name);
return -ENODEV;
}
adapter = to_i2c_adapter(dev);
return adapter->nr;
}
static struct i2c_client __init *add_smbus_device(const char *name,
struct i2c_board_info *info)
{
return add_i2c_device(name, I2C_ADAPTER_SMBUS, info);
}
static int __init setup_cyapa_smbus_tp(const struct dmi_system_id *id)
{
tp = add_smbus_device("trackpad", &cyapa_device);
return 0;
}
static int __init setup_atmel_224s_tp(const struct dmi_system_id *id)
{
const unsigned short addr_list[] = { ATMEL_TP_I2C_BL_ADDR,
ATMEL_TP_I2C_ADDR,
I2C_CLIENT_END };
tp = add_probed_i2c_device("trackpad", I2C_ADAPTER_VGADDC,
&atmel_224s_tp_device, addr_list);
return 0;
}
static int __init setup_atmel_1664s_ts(const struct dmi_system_id *id)
{
const unsigned short addr_list[] = { ATMEL_TS_I2C_BL_ADDR,
ATMEL_TS_I2C_ADDR,
I2C_CLIENT_END };
ts = add_probed_i2c_device("touchscreen", I2C_ADAPTER_PANEL,
&atmel_1664s_device, addr_list);
return 0;
}
static int __init setup_isl29018_als(const struct dmi_system_id *id)
{
als = add_smbus_device("lightsensor", &isl_als_device);
return 0;
}
static int __init setup_isl29023_als(const struct dmi_system_id *id)
{
als = add_i2c_device("lightsensor", I2C_ADAPTER_PANEL,
&isl_als_device);
return 0;
}
static int __init setup_tsl2583_als(const struct dmi_system_id *id)
{
als = add_smbus_device(NULL, &tsl2583_als_device);
return 0;
}
static int __init setup_tsl2563_als(const struct dmi_system_id *id)
{
als = add_smbus_device(NULL, &tsl2563_als_device);
return 0;
}
static int __init chromeos_laptop_init(void)
{
if (!dmi_check_system(chromeos_laptop_dmi_table)) {
pr_debug("%s unsupported system.\n", __func__);
return -ENODEV;
}
return 0;
}
static void __exit chromeos_laptop_exit(void)
{
if (als)
i2c_unregister_device(als);
if (tp)
i2c_unregister_device(tp);
if (ts)
i2c_unregister_device(ts);
}
