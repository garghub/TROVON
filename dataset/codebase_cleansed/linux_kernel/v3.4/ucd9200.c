static int ucd9200_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
u8 block_buffer[I2C_SMBUS_BLOCK_MAX + 1];
struct pmbus_driver_info *info;
const struct i2c_device_id *mid;
int i, j, ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA))
return -ENODEV;
ret = i2c_smbus_read_block_data(client, UCD9200_DEVICE_ID,
block_buffer);
if (ret < 0) {
dev_err(&client->dev, "Failed to read device ID\n");
return ret;
}
block_buffer[ret] = '\0';
dev_info(&client->dev, "Device ID %s\n", block_buffer);
for (mid = ucd9200_id; mid->name[0]; mid++) {
if (!strncasecmp(mid->name, block_buffer, strlen(mid->name)))
break;
}
if (!mid->name[0]) {
dev_err(&client->dev, "Unsupported device\n");
return -ENODEV;
}
if (id->driver_data != ucd9200 && id->driver_data != mid->driver_data)
dev_notice(&client->dev,
"Device mismatch: Configured %s, detected %s\n",
id->name, mid->name);
info = devm_kzalloc(&client->dev, sizeof(struct pmbus_driver_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
ret = i2c_smbus_read_block_data(client, UCD9200_PHASE_INFO,
block_buffer);
if (ret < 0) {
dev_err(&client->dev, "Failed to read phase information\n");
return ret;
}
info->pages = 0;
for (i = 0; i < ret; i++) {
if (!block_buffer[i])
break;
info->pages++;
}
if (!info->pages) {
dev_err(&client->dev, "No rails configured\n");
return -ENODEV;
}
dev_info(&client->dev, "%d rails configured\n", info->pages);
for (i = 0; i < info->pages; i++) {
for (j = 0; j < 3; j++) {
ret = i2c_smbus_write_byte_data(client, PMBUS_PAGE, i);
if (ret < 0)
continue;
ret = i2c_smbus_write_byte_data(client, PMBUS_PHASE,
0xff);
if (ret < 0)
continue;
break;
}
if (ret < 0) {
dev_err(&client->dev,
"Failed to initialize PHASE registers\n");
return ret;
}
}
if (info->pages > 1)
i2c_smbus_write_byte_data(client, PMBUS_PAGE, 0);
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT |
PMBUS_HAVE_IIN | PMBUS_HAVE_PIN |
PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT |
PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT |
PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP |
PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
for (i = 1; i < info->pages; i++)
info->func[i] = PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT |
PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT |
PMBUS_HAVE_POUT |
PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
if (mid->driver_data == ucd9240)
info->func[0] |= PMBUS_HAVE_FAN12 | PMBUS_HAVE_STATUS_FAN12;
return pmbus_do_probe(client, mid, info);
}
