static ssize_t ds1682_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
__le32 val = 0;
int rc;
dev_dbg(dev, "ds1682_show() called on %s\n", attr->attr.name);
rc = i2c_smbus_read_i2c_block_data(client, sattr->index, sattr->nr,
(u8 *) & val);
if (rc < 0)
return -EIO;
if (sattr->nr == 4)
return sprintf(buf, "%llu\n",
((unsigned long long)le32_to_cpu(val)) * 250);
return sprintf(buf, "%li\n", (long)le32_to_cpu(val));
}
static ssize_t ds1682_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
char *endp;
u64 val;
__le32 val_le;
int rc;
dev_dbg(dev, "ds1682_store() called on %s\n", attr->attr.name);
val = simple_strtoull(buf, &endp, 0);
if (buf == endp) {
dev_dbg(dev, "input string not a number\n");
return -EINVAL;
}
if (sattr->nr == 4)
do_div(val, 250);
val_le = cpu_to_le32(val);
rc = i2c_smbus_write_i2c_block_data(client, sattr->index, sattr->nr,
(u8 *) & val_le);
if (rc < 0) {
dev_err(dev, "register write failed; reg=0x%x, size=%i\n",
sattr->index, sattr->nr);
return -EIO;
}
return count;
}
static ssize_t ds1682_eeprom_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct i2c_client *client = kobj_to_i2c_client(kobj);
int rc;
dev_dbg(&client->dev, "ds1682_eeprom_read(p=%p, off=%lli, c=%zi)\n",
buf, off, count);
if (off >= DS1682_EEPROM_SIZE)
return 0;
if (off + count > DS1682_EEPROM_SIZE)
count = DS1682_EEPROM_SIZE - off;
rc = i2c_smbus_read_i2c_block_data(client, DS1682_REG_EEPROM + off,
count, buf);
if (rc < 0)
return -EIO;
return count;
}
static ssize_t ds1682_eeprom_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct i2c_client *client = kobj_to_i2c_client(kobj);
dev_dbg(&client->dev, "ds1682_eeprom_write(p=%p, off=%lli, c=%zi)\n",
buf, off, count);
if (off >= DS1682_EEPROM_SIZE)
return -ENOSPC;
if (off + count > DS1682_EEPROM_SIZE)
count = DS1682_EEPROM_SIZE - off;
if (i2c_smbus_write_i2c_block_data(client, DS1682_REG_EEPROM + off,
count, buf) < 0)
return -EIO;
return count;
}
static int ds1682_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_I2C_BLOCK)) {
dev_err(&client->dev, "i2c bus does not support the ds1682\n");
rc = -ENODEV;
goto exit;
}
rc = sysfs_create_group(&client->dev.kobj, &ds1682_group);
if (rc)
goto exit;
rc = sysfs_create_bin_file(&client->dev.kobj, &ds1682_eeprom_attr);
if (rc)
goto exit_bin_attr;
return 0;
exit_bin_attr:
sysfs_remove_group(&client->dev.kobj, &ds1682_group);
exit:
return rc;
}
static int ds1682_remove(struct i2c_client *client)
{
sysfs_remove_bin_file(&client->dev.kobj, &ds1682_eeprom_attr);
sysfs_remove_group(&client->dev.kobj, &ds1682_group);
return 0;
}
