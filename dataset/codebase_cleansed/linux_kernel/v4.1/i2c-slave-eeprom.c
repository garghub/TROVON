static int i2c_slave_eeprom_slave_cb(struct i2c_client *client,
enum i2c_slave_event event, u8 *val)
{
struct eeprom_data *eeprom = i2c_get_clientdata(client);
switch (event) {
case I2C_SLAVE_WRITE_RECEIVED:
if (eeprom->first_write) {
eeprom->buffer_idx = *val;
eeprom->first_write = false;
} else {
spin_lock(&eeprom->buffer_lock);
eeprom->buffer[eeprom->buffer_idx++] = *val;
spin_unlock(&eeprom->buffer_lock);
}
break;
case I2C_SLAVE_READ_PROCESSED:
eeprom->buffer_idx++;
case I2C_SLAVE_READ_REQUESTED:
spin_lock(&eeprom->buffer_lock);
*val = eeprom->buffer[eeprom->buffer_idx];
spin_unlock(&eeprom->buffer_lock);
break;
case I2C_SLAVE_STOP:
case I2C_SLAVE_WRITE_REQUESTED:
eeprom->first_write = true;
break;
default:
break;
}
return 0;
}
static ssize_t i2c_slave_eeprom_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
struct eeprom_data *eeprom;
unsigned long flags;
if (off + count > attr->size)
return -EFBIG;
eeprom = dev_get_drvdata(container_of(kobj, struct device, kobj));
spin_lock_irqsave(&eeprom->buffer_lock, flags);
memcpy(buf, &eeprom->buffer[off], count);
spin_unlock_irqrestore(&eeprom->buffer_lock, flags);
return count;
}
static ssize_t i2c_slave_eeprom_bin_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
struct eeprom_data *eeprom;
unsigned long flags;
if (off + count > attr->size)
return -EFBIG;
eeprom = dev_get_drvdata(container_of(kobj, struct device, kobj));
spin_lock_irqsave(&eeprom->buffer_lock, flags);
memcpy(&eeprom->buffer[off], buf, count);
spin_unlock_irqrestore(&eeprom->buffer_lock, flags);
return count;
}
static int i2c_slave_eeprom_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct eeprom_data *eeprom;
int ret;
unsigned size = id->driver_data;
eeprom = devm_kzalloc(&client->dev, sizeof(struct eeprom_data) + size, GFP_KERNEL);
if (!eeprom)
return -ENOMEM;
eeprom->first_write = true;
spin_lock_init(&eeprom->buffer_lock);
i2c_set_clientdata(client, eeprom);
sysfs_bin_attr_init(&eeprom->bin);
eeprom->bin.attr.name = "slave-eeprom";
eeprom->bin.attr.mode = S_IRUSR | S_IWUSR;
eeprom->bin.read = i2c_slave_eeprom_bin_read;
eeprom->bin.write = i2c_slave_eeprom_bin_write;
eeprom->bin.size = size;
ret = sysfs_create_bin_file(&client->dev.kobj, &eeprom->bin);
if (ret)
return ret;
ret = i2c_slave_register(client, i2c_slave_eeprom_slave_cb);
if (ret) {
sysfs_remove_bin_file(&client->dev.kobj, &eeprom->bin);
return ret;
}
return 0;
}
static int i2c_slave_eeprom_remove(struct i2c_client *client)
{
struct eeprom_data *eeprom = i2c_get_clientdata(client);
i2c_slave_unregister(client);
sysfs_remove_bin_file(&client->dev.kobj, &eeprom->bin);
return 0;
}
