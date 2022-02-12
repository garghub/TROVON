static int nct7904_bank_lock(struct nct7904_data *data, unsigned bank)
{
int ret;
mutex_lock(&data->bank_lock);
if (data->bank_sel == bank)
return 0;
ret = i2c_smbus_write_byte_data(data->client, BANK_SEL_REG, bank);
if (ret == 0)
data->bank_sel = bank;
else
data->bank_sel = -1;
return ret;
}
static inline void nct7904_bank_release(struct nct7904_data *data)
{
mutex_unlock(&data->bank_lock);
}
static int nct7904_read_reg(struct nct7904_data *data,
unsigned bank, unsigned reg)
{
struct i2c_client *client = data->client;
int ret;
ret = nct7904_bank_lock(data, bank);
if (ret == 0)
ret = i2c_smbus_read_byte_data(client, reg);
nct7904_bank_release(data);
return ret;
}
static int nct7904_read_reg16(struct nct7904_data *data,
unsigned bank, unsigned reg)
{
struct i2c_client *client = data->client;
int ret, hi;
ret = nct7904_bank_lock(data, bank);
if (ret == 0) {
ret = i2c_smbus_read_byte_data(client, reg);
if (ret >= 0) {
hi = ret;
ret = i2c_smbus_read_byte_data(client, reg + 1);
if (ret >= 0)
ret |= hi << 8;
}
}
nct7904_bank_release(data);
return ret;
}
static int nct7904_write_reg(struct nct7904_data *data,
unsigned bank, unsigned reg, u8 val)
{
struct i2c_client *client = data->client;
int ret;
ret = nct7904_bank_lock(data, bank);
if (ret == 0)
ret = i2c_smbus_write_byte_data(client, reg, val);
nct7904_bank_release(data);
return ret;
}
static ssize_t show_fan(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
int ret;
unsigned cnt, rpm;
ret = nct7904_read_reg16(data, BANK_0, FANIN1_HV_REG + index * 2);
if (ret < 0)
return ret;
cnt = ((ret & 0xff00) >> 3) | (ret & 0x1f);
if (cnt == 0x1fff)
rpm = 0;
else
rpm = 1350000 / cnt;
return sprintf(buf, "%u\n", rpm);
}
static umode_t nct7904_fanin_is_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7904_data *data = dev_get_drvdata(dev);
if (data->fanin_mask & (1 << n))
return a->mode;
return 0;
}
static ssize_t show_voltage(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
int ret;
int volt;
ret = nct7904_read_reg16(data, BANK_0, VSEN1_HV_REG + index * 2);
if (ret < 0)
return ret;
volt = ((ret & 0xff00) >> 5) | (ret & 0x7);
if (index < 14)
volt *= 2;
else
volt *= 6;
return sprintf(buf, "%d\n", volt);
}
static ssize_t show_ltemp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct nct7904_data *data = dev_get_drvdata(dev);
int ret;
int temp;
ret = nct7904_read_reg16(data, BANK_0, LTD_HV_REG);
if (ret < 0)
return ret;
temp = ((ret & 0xff00) >> 5) | (ret & 0x7);
temp = sign_extend32(temp, 10) * 125;
return sprintf(buf, "%d\n", temp);
}
static umode_t nct7904_vsen_is_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7904_data *data = dev_get_drvdata(dev);
if (data->vsen_mask & (1 << n))
return a->mode;
return 0;
}
static ssize_t show_tcpu(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
int ret;
int temp;
ret = nct7904_read_reg16(data, BANK_0, T_CPU1_HV_REG + index * 2);
if (ret < 0)
return ret;
temp = ((ret & 0xff00) >> 5) | (ret & 0x7);
temp = sign_extend32(temp, 10) * 125;
return sprintf(buf, "%d\n", temp);
}
static umode_t nct7904_tcpu_is_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7904_data *data = dev_get_drvdata(dev);
if (data->tcpu_mask & (1 << n))
return a->mode;
return 0;
}
static ssize_t store_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
if (val > 255)
return -EINVAL;
ret = nct7904_write_reg(data, BANK_3, FANCTL1_OUT_REG + index, val);
return ret ? ret : count;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
int val;
val = nct7904_read_reg(data, BANK_3, FANCTL1_OUT_REG + index);
if (val < 0)
return val;
return sprintf(buf, "%d\n", val);
}
static ssize_t store_mode(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
if (val > 1 || (val && !data->fan_mode[index]))
return -EINVAL;
ret = nct7904_write_reg(data, BANK_3, FANCTL1_FMR_REG + index,
val ? data->fan_mode[index] : 0);
return ret ? ret : count;
}
static ssize_t show_mode(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct nct7904_data *data = dev_get_drvdata(dev);
int val;
val = nct7904_read_reg(data, BANK_3, FANCTL1_FMR_REG + index);
if (val < 0)
return val;
return sprintf(buf, "%d\n", val ? 1 : 0);
}
static int nct7904_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
if (!i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_BYTE |
I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -ENODEV;
if (i2c_smbus_read_byte_data(client, VENDOR_ID_REG) != NUVOTON_ID ||
i2c_smbus_read_byte_data(client, CHIP_ID_REG) != NCT7904_ID ||
(i2c_smbus_read_byte_data(client, DEVICE_ID_REG) & 0xf0) != 0x50 ||
(i2c_smbus_read_byte_data(client, BANK_SEL_REG) & 0xf8) != 0x00)
return -ENODEV;
strlcpy(info->type, "nct7904", I2C_NAME_SIZE);
return 0;
}
static int nct7904_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct nct7904_data *data;
struct device *hwmon_dev;
struct device *dev = &client->dev;
int ret, i;
u32 mask;
data = devm_kzalloc(dev, sizeof(struct nct7904_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->bank_lock);
data->bank_sel = -1;
ret = nct7904_read_reg16(data, BANK_0, FANIN_CTRL0_REG);
if (ret < 0)
return ret;
data->fanin_mask = (ret >> 8) | ((ret & 0xff) << 8);
mask = 0;
ret = nct7904_read_reg16(data, BANK_0, VT_ADC_CTRL0_REG);
if (ret >= 0)
mask = (ret >> 8) | ((ret & 0xff) << 8);
ret = nct7904_read_reg(data, BANK_0, VT_ADC_CTRL2_REG);
if (ret >= 0)
mask |= (ret << 16);
data->vsen_mask = mask;
ret = nct7904_read_reg16(data, BANK_0, DTS_T_CTRL0_REG);
if (ret < 0)
return ret;
data->tcpu_mask = ((ret >> 8) & 0xf) | ((ret & 0xf) << 4);
for (i = 0; i < FANCTL_MAX; i++) {
ret = nct7904_read_reg(data, BANK_3, FANCTL1_FMR_REG + i);
if (ret < 0)
return ret;
data->fan_mode[i] = ret;
}
hwmon_dev =
devm_hwmon_device_register_with_groups(dev, client->name, data,
nct7904_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
