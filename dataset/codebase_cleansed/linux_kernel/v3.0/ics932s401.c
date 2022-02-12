static struct ics932s401_data *ics932s401_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ics932s401_data *data = i2c_get_clientdata(client);
unsigned long local_jiffies = jiffies;
int i, temp;
mutex_lock(&data->lock);
if (time_before(local_jiffies, data->sensors_last_updated +
SENSOR_REFRESH_INTERVAL)
&& data->sensors_valid)
goto out;
for (i = 0; i < NUM_MIRRORED_REGS; i++) {
temp = i2c_smbus_read_word_data(client, regs_to_copy[i]);
data->regs[regs_to_copy[i]] = temp >> 8;
}
data->sensors_last_updated = local_jiffies;
data->sensors_valid = 1;
out:
mutex_unlock(&data->lock);
return data;
}
static ssize_t show_spread_enabled(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
if (data->regs[ICS932S401_REG_CFG2] & ICS932S401_CFG1_SPREAD)
return sprintf(buf, "1\n");
return sprintf(buf, "0\n");
}
static int calculate_cpu_freq(struct ics932s401_data *data)
{
int m, n, freq;
m = data->regs[ICS932S401_REG_CPU_M_CTRL] & ICS932S401_M_MASK;
n = data->regs[ICS932S401_REG_CPU_N_CTRL];
n |= ((int)data->regs[ICS932S401_REG_CPU_M_CTRL] & 0x80) << 1;
n |= ((int)data->regs[ICS932S401_REG_CPU_M_CTRL] & 0x40) << 3;
freq = BASE_CLOCK * (n + 8) / (m + 2);
freq /= divisors[data->regs[ICS932S401_REG_CPU_DIVISOR] >>
ICS932S401_CPU_DIVISOR_SHIFT];
return freq;
}
static ssize_t show_cpu_clock(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
return sprintf(buf, "%d\n", calculate_cpu_freq(data));
}
static ssize_t show_cpu_clock_sel(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
int freq;
if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
freq = calculate_cpu_freq(data);
else {
int fid = data->regs[ICS932S401_REG_CFG7] & ICS932S401_FS_MASK;
freq = fs_speeds[fid];
if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_CPU_ALT) {
switch (freq) {
case 166666:
freq = 160000;
break;
case 333333:
freq = 320000;
break;
}
}
}
return sprintf(buf, "%d\n", freq);
}
static int calculate_src_freq(struct ics932s401_data *data)
{
int m, n, freq;
m = data->regs[ICS932S401_REG_SRC_M_CTRL] & ICS932S401_M_MASK;
n = data->regs[ICS932S401_REG_SRC_N_CTRL];
n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x80) << 1;
n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x40) << 3;
freq = BASE_CLOCK * (n + 8) / (m + 2);
freq /= divisors[data->regs[ICS932S401_REG_PCISRC_DIVISOR] &
ICS932S401_SRC_DIVISOR_MASK];
return freq;
}
static ssize_t show_src_clock(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
return sprintf(buf, "%d\n", calculate_src_freq(data));
}
static ssize_t show_src_clock_sel(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
int freq;
if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
freq = calculate_src_freq(data);
else
if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_CPU_ALT &&
data->regs[ICS932S401_REG_CTRL] & ICS932S401_SRC_ALT)
freq = 96000;
else
freq = 100000;
return sprintf(buf, "%d\n", freq);
}
static int calculate_pci_freq(struct ics932s401_data *data)
{
int m, n, freq;
m = data->regs[ICS932S401_REG_SRC_M_CTRL] & ICS932S401_M_MASK;
n = data->regs[ICS932S401_REG_SRC_N_CTRL];
n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x80) << 1;
n |= ((int)data->regs[ICS932S401_REG_SRC_M_CTRL] & 0x40) << 3;
freq = BASE_CLOCK * (n + 8) / (m + 2);
freq /= divisors[data->regs[ICS932S401_REG_PCISRC_DIVISOR] >>
ICS932S401_PCI_DIVISOR_SHIFT];
return freq;
}
static ssize_t show_pci_clock(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
return sprintf(buf, "%d\n", calculate_pci_freq(data));
}
static ssize_t show_pci_clock_sel(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
int freq;
if (data->regs[ICS932S401_REG_CTRL] & ICS932S401_MN_ENABLED)
freq = calculate_pci_freq(data);
else
freq = 33333;
return sprintf(buf, "%d\n", freq);
}
static ssize_t show_value(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int x;
if (devattr == &dev_attr_usb_clock)
x = 48000;
else if (devattr == &dev_attr_ref_clock)
x = BASE_CLOCK;
else
BUG();
return sprintf(buf, "%d\n", x);
}
static ssize_t show_spread(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct ics932s401_data *data = ics932s401_update_device(dev);
int reg;
unsigned long val;
if (!(data->regs[ICS932S401_REG_CFG2] & ICS932S401_CFG1_SPREAD))
return sprintf(buf, "0%%\n");
if (devattr == &dev_attr_src_spread)
reg = ICS932S401_REG_SRC_SPREAD1;
else if (devattr == &dev_attr_cpu_spread)
reg = ICS932S401_REG_CPU_SPREAD1;
else
BUG();
val = data->regs[reg] | (data->regs[reg + 1] << 8);
val &= ICS932S401_SPREAD_MASK;
val = 500000 * val / 16384;
return sprintf(buf, "-0.%lu%%\n", val);
}
static int ics932s401_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int vendor, device, revision;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
vendor = i2c_smbus_read_word_data(client, ICS932S401_REG_VENDOR_REV);
vendor >>= 8;
revision = vendor >> ICS932S401_REV_SHIFT;
vendor &= ICS932S401_VENDOR_MASK;
if (vendor != ICS932S401_VENDOR)
return -ENODEV;
device = i2c_smbus_read_word_data(client, ICS932S401_REG_DEVICE);
device >>= 8;
if (device != ICS932S401_DEVICE)
return -ENODEV;
if (revision != ICS932S401_REV)
dev_info(&adapter->dev, "Unknown revision %d\n", revision);
strlcpy(info->type, "ics932s401", I2C_NAME_SIZE);
return 0;
}
static int ics932s401_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ics932s401_data *data;
int err;
data = kzalloc(sizeof(struct ics932s401_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
dev_info(&client->dev, "%s chip found\n", client->name);
data->attrs.attrs = ics932s401_attr;
err = sysfs_create_group(&client->dev.kobj, &data->attrs);
if (err)
goto exit_free;
return 0;
exit_free:
kfree(data);
exit:
return err;
}
static int ics932s401_remove(struct i2c_client *client)
{
struct ics932s401_data *data = i2c_get_clientdata(client);
sysfs_remove_group(&client->dev.kobj, &data->attrs);
kfree(data);
return 0;
}
static int __init ics932s401_init(void)
{
return i2c_add_driver(&ics932s401_driver);
}
static void __exit ics932s401_exit(void)
{
i2c_del_driver(&ics932s401_driver);
}
