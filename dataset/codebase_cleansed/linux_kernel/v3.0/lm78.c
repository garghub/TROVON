static inline u8 IN_TO_REG(unsigned long val)
{
unsigned long nval = SENSORS_LIMIT(val, 0, 4080);
return (nval + 8) / 16;
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm <= 0)
return 255;
return SENSORS_LIMIT((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline int FAN_FROM_REG(u8 val, int div)
{
return val==0 ? -1 : val==255 ? 0 : 1350000/(val*div);
}
static inline s8 TEMP_TO_REG(int val)
{
int nval = SENSORS_LIMIT(val, -128000, 127000) ;
return nval<0 ? (nval-500)/1000 : (nval+500)/1000;
}
static inline int TEMP_FROM_REG(s8 val)
{
return val * 1000;
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in[attr->index]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[attr->index]));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[attr->index]));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = dev_get_drvdata(dev);
unsigned long val = simple_strtoul(buf, NULL, 10);
int nr = attr->index;
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val);
lm78_write_value(data, LM78_REG_IN_MIN(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = dev_get_drvdata(dev);
unsigned long val = simple_strtoul(buf, NULL, 10);
int nr = attr->index;
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val);
lm78_write_value(data, LM78_REG_IN_MAX(nr), data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp));
}
static ssize_t show_temp_over(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_over));
}
static ssize_t set_temp_over(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct lm78_data *data = dev_get_drvdata(dev);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_over = TEMP_TO_REG(val);
lm78_write_value(data, LM78_REG_TEMP_OVER, data->temp_over);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_hyst(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_hyst));
}
static ssize_t set_temp_hyst(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct lm78_data *data = dev_get_drvdata(dev);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_hyst = TEMP_TO_REG(val);
lm78_write_value(data, LM78_REG_TEMP_HYST, data->temp_hyst);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
int nr = attr->index;
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr])) );
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
int nr = attr->index;
return sprintf(buf,"%d\n", FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])) );
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
lm78_write_value(data, LM78_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[attr->index]));
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm78_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val = simple_strtoul(buf, NULL, 10);
unsigned long min;
u8 reg;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
switch (val) {
case 1: data->fan_div[nr] = 0; break;
case 2: data->fan_div[nr] = 1; break;
case 4: data->fan_div[nr] = 2; break;
case 8: data->fan_div[nr] = 3; break;
default:
dev_err(dev, "fan_div value %ld not "
"supported. Choose one of 1, 2, 4 or 8!\n", val);
mutex_unlock(&data->update_lock);
return -EINVAL;
}
reg = lm78_read_value(data, LM78_REG_VID_FANDIV);
switch (nr) {
case 0:
reg = (reg & 0xcf) | (data->fan_div[nr] << 4);
break;
case 1:
reg = (reg & 0x3f) | (data->fan_div[nr] << 6);
break;
}
lm78_write_value(data, LM78_REG_VID_FANDIV, reg);
data->fan_min[nr] =
FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
lm78_write_value(data, LM78_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_vid(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, 82));
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm78_data *data = lm78_update_device(dev);
int nr = to_sensor_dev_attr(da)->index;
return sprintf(buf, "%u\n", (data->alarms >> nr) & 1);
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct lm78_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int lm78_alias_detect(struct i2c_client *client, u8 chipid)
{
struct lm78_data *isa;
int i;
if (!pdev)
return 0;
isa = platform_get_drvdata(pdev);
if (lm78_read_value(isa, LM78_REG_I2C_ADDR) != client->addr)
return 0;
if ((lm78_read_value(isa, LM78_REG_CHIPID) & 0xfe) != (chipid & 0xfe))
return 0;
for (i = 0x2b; i <= 0x3d; i++) {
if (lm78_read_value(isa, i) !=
i2c_smbus_read_byte_data(client, i))
return 0;
}
if (lm78_read_value(isa, LM78_REG_CONFIG) !=
i2c_smbus_read_byte_data(client, LM78_REG_CONFIG))
return 0;
for (i = 0x43; i <= 0x46; i++) {
if (lm78_read_value(isa, i) !=
i2c_smbus_read_byte_data(client, i))
return 0;
}
return 1;
}
static int lm78_i2c_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
int i;
struct lm78_data *isa = pdev ? platform_get_drvdata(pdev) : NULL;
const char *client_name;
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (isa)
mutex_lock(&isa->update_lock);
if ((i2c_smbus_read_byte_data(client, LM78_REG_CONFIG) & 0x80)
|| i2c_smbus_read_byte_data(client, LM78_REG_I2C_ADDR) != address)
goto err_nodev;
i = i2c_smbus_read_byte_data(client, 0x4f);
if (i == 0xa3 || i == 0x5c)
goto err_nodev;
i = i2c_smbus_read_byte_data(client, LM78_REG_CHIPID);
if (i == 0x00 || i == 0x20
|| i == 0x40)
client_name = "lm78";
else if ((i & 0xfe) == 0xc0)
client_name = "lm79";
else
goto err_nodev;
if (lm78_alias_detect(client, i)) {
dev_dbg(&adapter->dev, "Device at 0x%02x appears to "
"be the same as ISA device\n", address);
goto err_nodev;
}
if (isa)
mutex_unlock(&isa->update_lock);
strlcpy(info->type, client_name, I2C_NAME_SIZE);
return 0;
err_nodev:
if (isa)
mutex_unlock(&isa->update_lock);
return -ENODEV;
}
static int lm78_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm78_data *data;
int err;
data = kzalloc(sizeof(struct lm78_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->client = client;
data->type = id->driver_data;
lm78_init_device(data);
err = sysfs_create_group(&client->dev.kobj, &lm78_group);
if (err)
goto ERROR3;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto ERROR4;
}
return 0;
ERROR4:
sysfs_remove_group(&client->dev.kobj, &lm78_group);
ERROR3:
kfree(data);
return err;
}
static int lm78_i2c_remove(struct i2c_client *client)
{
struct lm78_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm78_group);
kfree(data);
return 0;
}
static int __devinit lm78_isa_probe(struct platform_device *pdev)
{
int err;
struct lm78_data *data;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!request_region(res->start + LM78_ADDR_REG_OFFSET, 2, "lm78")) {
err = -EBUSY;
goto exit;
}
if (!(data = kzalloc(sizeof(struct lm78_data), GFP_KERNEL))) {
err = -ENOMEM;
goto exit_release_region;
}
mutex_init(&data->lock);
data->isa_addr = res->start;
platform_set_drvdata(pdev, data);
if (lm78_read_value(data, LM78_REG_CHIPID) & 0x80) {
data->type = lm79;
data->name = "lm79";
} else {
data->type = lm78;
data->name = "lm78";
}
lm78_init_device(data);
if ((err = sysfs_create_group(&pdev->dev.kobj, &lm78_group))
|| (err = device_create_file(&pdev->dev, &dev_attr_name)))
goto exit_remove_files;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&pdev->dev.kobj, &lm78_group);
device_remove_file(&pdev->dev, &dev_attr_name);
kfree(data);
exit_release_region:
release_region(res->start + LM78_ADDR_REG_OFFSET, 2);
exit:
return err;
}
static int __devexit lm78_isa_remove(struct platform_device *pdev)
{
struct lm78_data *data = platform_get_drvdata(pdev);
struct resource *res;
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &lm78_group);
device_remove_file(&pdev->dev, &dev_attr_name);
kfree(data);
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
release_region(res->start + LM78_ADDR_REG_OFFSET, 2);
return 0;
}
static int lm78_read_value(struct lm78_data *data, u8 reg)
{
struct i2c_client *client = data->client;
if (!client) {
int res;
mutex_lock(&data->lock);
outb_p(reg, data->isa_addr + LM78_ADDR_REG_OFFSET);
res = inb_p(data->isa_addr + LM78_DATA_REG_OFFSET);
mutex_unlock(&data->lock);
return res;
} else
return i2c_smbus_read_byte_data(client, reg);
}
static int lm78_write_value(struct lm78_data *data, u8 reg, u8 value)
{
struct i2c_client *client = data->client;
if (!client) {
mutex_lock(&data->lock);
outb_p(reg, data->isa_addr + LM78_ADDR_REG_OFFSET);
outb_p(value, data->isa_addr + LM78_DATA_REG_OFFSET);
mutex_unlock(&data->lock);
return 0;
} else
return i2c_smbus_write_byte_data(client, reg, value);
}
static void lm78_init_device(struct lm78_data *data)
{
u8 config;
int i;
config = lm78_read_value(data, LM78_REG_CONFIG);
if ((config & 0x09) != 0x01)
lm78_write_value(data, LM78_REG_CONFIG,
(config & 0xf7) | 0x01);
for (i = 0; i < 3; i++) {
data->fan_min[i] = lm78_read_value(data,
LM78_REG_FAN_MIN(i));
}
mutex_init(&data->update_lock);
}
static struct lm78_data *lm78_update_device(struct device *dev)
{
struct lm78_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(dev, "Starting lm78 update\n");
for (i = 0; i <= 6; i++) {
data->in[i] =
lm78_read_value(data, LM78_REG_IN(i));
data->in_min[i] =
lm78_read_value(data, LM78_REG_IN_MIN(i));
data->in_max[i] =
lm78_read_value(data, LM78_REG_IN_MAX(i));
}
for (i = 0; i < 3; i++) {
data->fan[i] =
lm78_read_value(data, LM78_REG_FAN(i));
data->fan_min[i] =
lm78_read_value(data, LM78_REG_FAN_MIN(i));
}
data->temp = lm78_read_value(data, LM78_REG_TEMP);
data->temp_over =
lm78_read_value(data, LM78_REG_TEMP_OVER);
data->temp_hyst =
lm78_read_value(data, LM78_REG_TEMP_HYST);
i = lm78_read_value(data, LM78_REG_VID_FANDIV);
data->vid = i & 0x0f;
if (data->type == lm79)
data->vid |=
(lm78_read_value(data, LM78_REG_CHIPID) &
0x01) << 4;
else
data->vid |= 0x10;
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = i >> 6;
data->alarms = lm78_read_value(data, LM78_REG_ALARM1) +
(lm78_read_value(data, LM78_REG_ALARM2) << 8);
data->last_updated = jiffies;
data->valid = 1;
data->fan_div[2] = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init lm78_isa_found(unsigned short address)
{
int val, save, found = 0;
int port;
for (port = address; port < address + LM78_EXTENT; port++) {
if (!request_region(port, 1, "lm78")) {
pr_debug("Failed to request port 0x%x\n", port);
goto release;
}
}
#define REALLY_SLOW_IO
val = inb_p(address + 1);
if (inb_p(address + 2) != val
|| inb_p(address + 3) != val
|| inb_p(address + 7) != val)
goto release;
#undef REALLY_SLOW_IO
save = inb_p(address + LM78_ADDR_REG_OFFSET);
if (save & 0x80)
goto release;
val = ~save & 0x7f;
outb_p(val, address + LM78_ADDR_REG_OFFSET);
if (inb_p(address + LM78_ADDR_REG_OFFSET) != (val | 0x80)) {
outb_p(save, address + LM78_ADDR_REG_OFFSET);
goto release;
}
outb_p(LM78_REG_CONFIG, address + LM78_ADDR_REG_OFFSET);
val = inb_p(address + LM78_DATA_REG_OFFSET);
if (val & 0x80)
goto release;
outb_p(LM78_REG_I2C_ADDR, address + LM78_ADDR_REG_OFFSET);
val = inb_p(address + LM78_DATA_REG_OFFSET);
if (val < 0x03 || val > 0x77)
goto release;
if (inb_p(address + LM78_ADDR_REG_OFFSET) & 0x80)
goto release;
outb_p(0x4f, address + LM78_ADDR_REG_OFFSET);
val = inb_p(address + LM78_DATA_REG_OFFSET);
if (val == 0xa3 || val == 0x5c)
goto release;
outb_p(0x58, address + LM78_ADDR_REG_OFFSET);
val = inb_p(address + LM78_DATA_REG_OFFSET);
if (val == 0x90)
goto release;
outb_p(LM78_REG_CHIPID, address + LM78_ADDR_REG_OFFSET);
val = inb_p(address + LM78_DATA_REG_OFFSET);
if (val == 0x00 || val == 0x20
|| val == 0x40
|| (val & 0xfe) == 0xc0)
found = 1;
if (found)
pr_info("Found an %s chip at %#x\n",
val & 0x80 ? "LM79" : "LM78", (int)address);
release:
for (port--; port >= address; port--)
release_region(port, 1);
return found;
}
static int __init lm78_isa_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + LM78_EXTENT - 1,
.name = "lm78",
.flags = IORESOURCE_IO,
};
int err;
pdev = platform_device_alloc("lm78", address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
err = platform_device_add_resources(pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add(pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(pdev);
exit:
pdev = NULL;
return err;
}
static int __init sm_lm78_init(void)
{
int res;
if (lm78_isa_found(isa_address)) {
res = platform_driver_register(&lm78_isa_driver);
if (res)
goto exit;
res = lm78_isa_device_add(isa_address);
if (res)
goto exit_unreg_isa_driver;
}
res = i2c_add_driver(&lm78_driver);
if (res)
goto exit_unreg_isa_device;
return 0;
exit_unreg_isa_device:
platform_device_unregister(pdev);
exit_unreg_isa_driver:
platform_driver_unregister(&lm78_isa_driver);
exit:
return res;
}
static void __exit sm_lm78_exit(void)
{
if (pdev) {
platform_device_unregister(pdev);
platform_driver_unregister(&lm78_isa_driver);
}
i2c_del_driver(&lm78_driver);
}
