static int ucd9000_get_fan_config(struct i2c_client *client, int fan)
{
int fan_config = 0;
struct ucd9000_data *data
= to_ucd9000_data(pmbus_get_driver_info(client));
if (data->fan_data[fan][3] & 1)
fan_config |= PB_FAN_2_INSTALLED;
fan_config |= (data->fan_data[fan][3] & 0x06) >> 1;
return fan_config;
}
static int ucd9000_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret = 0;
int fan_config;
switch (reg) {
case PMBUS_FAN_CONFIG_12:
if (page)
return -EINVAL;
ret = ucd9000_get_fan_config(client, 0);
if (ret < 0)
return ret;
fan_config = ret << 4;
ret = ucd9000_get_fan_config(client, 1);
if (ret < 0)
return ret;
fan_config |= ret;
ret = fan_config;
break;
case PMBUS_FAN_CONFIG_34:
if (page)
return -EINVAL;
ret = ucd9000_get_fan_config(client, 2);
if (ret < 0)
return ret;
fan_config = ret << 4;
ret = ucd9000_get_fan_config(client, 3);
if (ret < 0)
return ret;
fan_config |= ret;
ret = fan_config;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ucd9000_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
u8 block_buffer[I2C_SMBUS_BLOCK_MAX + 1];
struct ucd9000_data *data;
struct pmbus_driver_info *info;
const struct i2c_device_id *mid;
int i, ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA))
return -ENODEV;
ret = i2c_smbus_read_block_data(client, UCD9000_DEVICE_ID,
block_buffer);
if (ret < 0) {
dev_err(&client->dev, "Failed to read device ID\n");
return ret;
}
block_buffer[ret] = '\0';
dev_info(&client->dev, "Device ID %s\n", block_buffer);
for (mid = ucd9000_id; mid->name[0]; mid++) {
if (!strncasecmp(mid->name, block_buffer, strlen(mid->name)))
break;
}
if (!mid->name[0]) {
dev_err(&client->dev, "Unsupported device\n");
return -ENODEV;
}
if (id->driver_data != ucd9000 && id->driver_data != mid->driver_data)
dev_notice(&client->dev,
"Device mismatch: Configured %s, detected %s\n",
id->name, mid->name);
data = kzalloc(sizeof(struct ucd9000_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
info = &data->info;
ret = i2c_smbus_read_byte_data(client, UCD9000_NUM_PAGES);
if (ret < 0) {
dev_err(&client->dev,
"Failed to read number of active pages\n");
goto out;
}
info->pages = ret;
if (!info->pages) {
dev_err(&client->dev, "No pages configured\n");
ret = -ENODEV;
goto out;
}
info->func[0] = PMBUS_HAVE_TEMP;
ret = i2c_smbus_read_block_data(client, UCD9000_MONITOR_CONFIG,
block_buffer);
if (ret <= 0) {
dev_err(&client->dev, "Failed to read configuration data\n");
ret = -ENODEV;
goto out;
}
for (i = 0; i < ret; i++) {
int page = UCD9000_MON_PAGE(block_buffer[i]);
if (page >= info->pages)
continue;
switch (UCD9000_MON_TYPE(block_buffer[i])) {
case UCD9000_MON_VOLTAGE:
case UCD9000_MON_VOLTAGE_HW:
info->func[page] |= PMBUS_HAVE_VOUT
| PMBUS_HAVE_STATUS_VOUT;
break;
case UCD9000_MON_TEMPERATURE:
info->func[page] |= PMBUS_HAVE_TEMP2
| PMBUS_HAVE_STATUS_TEMP;
break;
case UCD9000_MON_CURRENT:
info->func[page] |= PMBUS_HAVE_IOUT
| PMBUS_HAVE_STATUS_IOUT;
break;
default:
break;
}
}
if (mid->driver_data == ucd90124) {
for (i = 0; i < UCD9000_NUM_FAN; i++) {
i2c_smbus_write_byte_data(client,
UCD9000_FAN_CONFIG_INDEX, i);
ret = i2c_smbus_read_block_data(client,
UCD9000_FAN_CONFIG,
data->fan_data[i]);
if (ret < 0)
goto out;
}
i2c_smbus_write_byte_data(client, UCD9000_FAN_CONFIG_INDEX, 0);
info->read_byte_data = ucd9000_read_byte_data;
info->func[0] |= PMBUS_HAVE_FAN12 | PMBUS_HAVE_STATUS_FAN12
| PMBUS_HAVE_FAN34 | PMBUS_HAVE_STATUS_FAN34;
}
ret = pmbus_do_probe(client, mid, info);
if (ret < 0)
goto out;
return 0;
out:
kfree(data);
return ret;
}
static int ucd9000_remove(struct i2c_client *client)
{
int ret;
struct ucd9000_data *data;
data = to_ucd9000_data(pmbus_get_driver_info(client));
ret = pmbus_do_remove(client);
kfree(data);
return ret;
}
static int __init ucd9000_init(void)
{
return i2c_add_driver(&ucd9000_driver);
}
static void __exit ucd9000_exit(void)
{
i2c_del_driver(&ucd9000_driver);
}
