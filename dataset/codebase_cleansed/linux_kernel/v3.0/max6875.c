static void max6875_update_slice(struct i2c_client *client, int slice)
{
struct max6875_data *data = i2c_get_clientdata(client);
int i, j, addr;
u8 *buf;
if (slice >= USER_EEPROM_SLICES)
return;
mutex_lock(&data->update_lock);
buf = &data->data[slice << SLICE_BITS];
if (!(data->valid & (1 << slice)) ||
time_after(jiffies, data->last_updated[slice])) {
dev_dbg(&client->dev, "Starting update of slice %u\n", slice);
data->valid &= ~(1 << slice);
addr = USER_EEPROM_BASE + (slice << SLICE_BITS);
if (i2c_smbus_write_byte_data(client, addr >> 8, addr & 0xFF)) {
dev_err(&client->dev, "address set failed\n");
goto exit_up;
}
if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
if (i2c_smbus_read_i2c_block_data(client,
MAX6875_CMD_BLK_READ,
SLICE_SIZE,
buf) != SLICE_SIZE) {
goto exit_up;
}
} else {
for (i = 0; i < SLICE_SIZE; i++) {
j = i2c_smbus_read_byte(client);
if (j < 0) {
goto exit_up;
}
buf[i] = j;
}
}
data->last_updated[slice] = jiffies;
data->valid |= (1 << slice);
}
exit_up:
mutex_unlock(&data->update_lock);
}
static ssize_t max6875_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct i2c_client *client = kobj_to_i2c_client(kobj);
struct max6875_data *data = i2c_get_clientdata(client);
int slice, max_slice;
if (off > USER_EEPROM_SIZE)
return 0;
if (off + count > USER_EEPROM_SIZE)
count = USER_EEPROM_SIZE - off;
max_slice = (off + count - 1) >> SLICE_BITS;
for (slice = (off >> SLICE_BITS); slice <= max_slice; slice++)
max6875_update_slice(client, slice);
memcpy(buf, &data->data[off], count);
return count;
}
static int max6875_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct max6875_data *data;
int err;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WRITE_BYTE_DATA
| I2C_FUNC_SMBUS_READ_BYTE))
return -ENODEV;
if (client->addr & 1)
return -ENODEV;
if (!(data = kzalloc(sizeof(struct max6875_data), GFP_KERNEL)))
return -ENOMEM;
data->fake_client = i2c_new_dummy(client->adapter, client->addr + 1);
if (!data->fake_client) {
err = -ENOMEM;
goto exit_kfree;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = sysfs_create_bin_file(&client->dev.kobj, &user_eeprom_attr);
if (err)
goto exit_remove_fake;
return 0;
exit_remove_fake:
i2c_unregister_device(data->fake_client);
exit_kfree:
kfree(data);
return err;
}
static int max6875_remove(struct i2c_client *client)
{
struct max6875_data *data = i2c_get_clientdata(client);
i2c_unregister_device(data->fake_client);
sysfs_remove_bin_file(&client->dev.kobj, &user_eeprom_attr);
kfree(data);
return 0;
}
static int __init max6875_init(void)
{
return i2c_add_driver(&max6875_driver);
}
static void __exit max6875_exit(void)
{
i2c_del_driver(&max6875_driver);
}
