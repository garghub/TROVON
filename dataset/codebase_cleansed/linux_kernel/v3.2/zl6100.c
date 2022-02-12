static inline void zl6100_wait(const struct zl6100_data *data)
{
if (delay) {
s64 delta = ktime_us_delta(ktime_get(), data->access);
if (delta < delay)
udelay(delay - delta);
}
}
static int zl6100_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct zl6100_data *data = to_zl6100_data(info);
int ret;
if (page || reg >= PMBUS_VIRT_BASE)
return -ENXIO;
zl6100_wait(data);
ret = pmbus_read_word_data(client, page, reg);
data->access = ktime_get();
return ret;
}
static int zl6100_read_byte_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct zl6100_data *data = to_zl6100_data(info);
int ret;
if (page > 0)
return -ENXIO;
zl6100_wait(data);
ret = pmbus_read_byte_data(client, page, reg);
data->access = ktime_get();
return ret;
}
static int zl6100_write_word_data(struct i2c_client *client, int page, int reg,
u16 word)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct zl6100_data *data = to_zl6100_data(info);
int ret;
if (page || reg >= PMBUS_VIRT_BASE)
return -ENXIO;
zl6100_wait(data);
ret = pmbus_write_word_data(client, page, reg, word);
data->access = ktime_get();
return ret;
}
static int zl6100_write_byte(struct i2c_client *client, int page, u8 value)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct zl6100_data *data = to_zl6100_data(info);
int ret;
if (page > 0)
return -ENXIO;
zl6100_wait(data);
ret = pmbus_write_byte(client, page, value);
data->access = ktime_get();
return ret;
}
static int zl6100_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct zl6100_data *data;
struct pmbus_driver_info *info;
u8 device_id[I2C_SMBUS_BLOCK_MAX + 1];
const struct i2c_device_id *mid;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA
| I2C_FUNC_SMBUS_READ_BLOCK_DATA))
return -ENODEV;
ret = i2c_smbus_read_block_data(client, ZL6100_DEVICE_ID,
device_id);
if (ret < 0) {
dev_err(&client->dev, "Failed to read device ID\n");
return ret;
}
device_id[ret] = '\0';
dev_info(&client->dev, "Device ID %s\n", device_id);
mid = NULL;
for (mid = zl6100_id; mid->name[0]; mid++) {
if (!strncasecmp(mid->name, device_id, strlen(mid->name)))
break;
}
if (!mid->name[0]) {
dev_err(&client->dev, "Unsupported device\n");
return -ENODEV;
}
if (id->driver_data != mid->driver_data)
dev_notice(&client->dev,
"Device mismatch: Configured %s, detected %s\n",
id->name, mid->name);
data = kzalloc(sizeof(struct zl6100_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->id = mid->driver_data;
if (data->id == zl2004 || data->id == zl6105)
delay = 0;
data->access = ktime_get();
zl6100_wait(data);
data->access = ktime_get();
info = &data->info;
info->pages = 1;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
info->read_word_data = zl6100_read_word_data;
info->read_byte_data = zl6100_read_byte_data;
info->write_word_data = zl6100_write_word_data;
info->write_byte = zl6100_write_byte;
ret = pmbus_do_probe(client, mid, info);
if (ret)
goto err_mem;
return 0;
err_mem:
kfree(data);
return ret;
}
static int zl6100_remove(struct i2c_client *client)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
const struct zl6100_data *data = to_zl6100_data(info);
pmbus_do_remove(client);
kfree(data);
return 0;
}
static int __init zl6100_init(void)
{
return i2c_add_driver(&zl6100_driver);
}
static void __exit zl6100_exit(void)
{
i2c_del_driver(&zl6100_driver);
}
