static struct i2c_client *__add_probed_i2c_device(
const char *name,
int bus,
struct i2c_board_info *info,
const unsigned short *alt_addr_list)
{
const struct dmi_device *dmi_dev;
const struct dmi_dev_onboard *dev_data;
struct i2c_adapter *adapter;
struct i2c_client *client = NULL;
const unsigned short addr_list[] = { info->addr, I2C_CLIENT_END };
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
client = i2c_new_probed_device(adapter, info, addr_list, NULL);
if (!client && alt_addr_list) {
struct i2c_board_info dummy_info = {
I2C_BOARD_INFO("dummy", info->addr),
};
struct i2c_client *dummy;
dummy = i2c_new_probed_device(adapter, &dummy_info,
alt_addr_list, NULL);
if (dummy) {
pr_debug("%s %d-%02x is probed at %02x\n",
__func__, bus, info->addr, dummy->addr);
i2c_unregister_device(dummy);
client = i2c_new_device(adapter, info);
}
}
if (!client)
pr_notice("%s failed to register device %d-%02x\n",
__func__, bus, info->addr);
else
pr_debug("%s added i2c device %d-%02x\n",
__func__, bus, info->addr);
i2c_put_adapter(adapter);
return client;
}
static int __find_i2c_adap(struct device *dev, void *data)
{
struct i2c_lookup *lookup = data;
static const char *prefix = "i2c-";
struct i2c_adapter *adapter;
if (strncmp(dev_name(dev), prefix, strlen(prefix)) != 0)
return 0;
adapter = to_i2c_adapter(dev);
if (strncmp(adapter->name, lookup->name, strlen(lookup->name)) == 0 &&
lookup->n++ == lookup->instance)
return 1;
return 0;
}
static int find_i2c_adapter_num(enum i2c_adapter_type type)
{
struct device *dev = NULL;
struct i2c_adapter *adapter;
struct i2c_lookup lookup;
memset(&lookup, 0, sizeof(lookup));
lookup.name = i2c_adapter_names[type];
lookup.instance = (type == I2C_ADAPTER_DESIGNWARE_1) ? 1 : 0;
dev = bus_find_device(&i2c_bus_type, NULL, &lookup, __find_i2c_adap);
if (!dev) {
pr_notice("%s: i2c adapter %s not found on system.\n", __func__,
lookup.name);
return -ENODEV;
}
adapter = to_i2c_adapter(dev);
return adapter->nr;
}
static struct i2c_client *add_probed_i2c_device(
const char *name,
enum i2c_adapter_type type,
struct i2c_board_info *info,
const unsigned short *addrs)
{
return __add_probed_i2c_device(name,
find_i2c_adapter_num(type),
info,
addrs);
}
static struct i2c_client *add_i2c_device(const char *name,
enum i2c_adapter_type type,
struct i2c_board_info *info)
{
return __add_probed_i2c_device(name,
find_i2c_adapter_num(type),
info,
NULL);
}
static int setup_cyapa_tp(enum i2c_adapter_type type)
{
if (tp)
return 0;
tp = add_i2c_device("trackpad", type, &cyapa_device);
return (!tp) ? -EAGAIN : 0;
}
static int setup_atmel_224s_tp(enum i2c_adapter_type type)
{
const unsigned short addr_list[] = { ATMEL_TP_I2C_BL_ADDR,
I2C_CLIENT_END };
if (tp)
return 0;
tp = add_probed_i2c_device("trackpad", type,
&atmel_224s_tp_device, addr_list);
return (!tp) ? -EAGAIN : 0;
}
static int setup_atmel_1664s_ts(enum i2c_adapter_type type)
{
const unsigned short addr_list[] = { ATMEL_TS_I2C_BL_ADDR,
I2C_CLIENT_END };
if (ts)
return 0;
ts = add_probed_i2c_device("touchscreen", type,
&atmel_1664s_device, addr_list);
return (!ts) ? -EAGAIN : 0;
}
static int setup_isl29018_als(enum i2c_adapter_type type)
{
if (als)
return 0;
als = add_i2c_device("lightsensor", type, &isl_als_device);
return (!als) ? -EAGAIN : 0;
}
static int setup_tsl2583_als(enum i2c_adapter_type type)
{
if (als)
return 0;
als = add_i2c_device(NULL, type, &tsl2583_als_device);
return (!als) ? -EAGAIN : 0;
}
static int setup_tsl2563_als(enum i2c_adapter_type type)
{
if (als)
return 0;
als = add_i2c_device(NULL, type, &tsl2563_als_device);
return (!als) ? -EAGAIN : 0;
}
static int __init chromeos_laptop_dmi_matched(const struct dmi_system_id *id)
{
cros_laptop = (void *)id->driver_data;
pr_debug("DMI Matched %s.\n", id->ident);
return 1;
}
static int chromeos_laptop_probe(struct platform_device *pdev)
{
int i;
int ret = 0;
for (i = 0; i < MAX_I2C_PERIPHERALS; i++) {
struct i2c_peripheral *i2c_dev;
i2c_dev = &cros_laptop->i2c_peripherals[i];
if (i2c_dev->add == NULL)
break;
if (i2c_dev->state == TIMEDOUT || i2c_dev->state == PROBED)
continue;
if (find_i2c_adapter_num(i2c_dev->type) == -ENODEV) {
ret = -EPROBE_DEFER;
continue;
}
if (i2c_dev->add(i2c_dev->type) == -EAGAIN) {
if (++i2c_dev->tries < MAX_I2C_DEVICE_DEFERRALS) {
ret = -EPROBE_DEFER;
} else {
pr_notice("%s: Ran out of tries for device.\n",
__func__);
i2c_dev->state = TIMEDOUT;
}
} else {
i2c_dev->state = PROBED;
}
}
return ret;
}
static int __init chromeos_laptop_init(void)
{
int ret;
if (!dmi_check_system(chromeos_laptop_dmi_table)) {
pr_debug("%s unsupported system.\n", __func__);
return -ENODEV;
}
ret = platform_driver_register(&cros_platform_driver);
if (ret)
return ret;
cros_platform_device = platform_device_alloc("chromeos_laptop", -1);
if (!cros_platform_device) {
ret = -ENOMEM;
goto fail_platform_device1;
}
ret = platform_device_add(cros_platform_device);
if (ret)
goto fail_platform_device2;
return 0;
fail_platform_device2:
platform_device_put(cros_platform_device);
fail_platform_device1:
platform_driver_unregister(&cros_platform_driver);
return ret;
}
static void __exit chromeos_laptop_exit(void)
{
if (als)
i2c_unregister_device(als);
if (tp)
i2c_unregister_device(tp);
if (ts)
i2c_unregister_device(ts);
platform_device_unregister(cros_platform_device);
platform_driver_unregister(&cros_platform_driver);
}
