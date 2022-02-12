static inline u8 read_byte(struct i2c_client *client, u8 reg)
{
int res = i2c_smbus_read_byte_data(client, reg);
if (res < 0) {
dev_err(&client->dev,
"Unable to read from register 0x%02x.\n", reg);
return 0;
};
return res & 0xff;
}
static inline int write_byte(struct i2c_client *client, u8 reg, u8 data)
{
int res = i2c_smbus_write_byte_data(client, reg, data);
if (res < 0) {
dev_err(&client->dev,
"Unable to write value 0x%02x to register 0x%02x.\n",
data, reg);
};
return res;
}
static ssize_t show_u8(struct device *dev, struct device_attribute *attr,
char *buf)
{
SETUP_SHOW_data_param(dev, attr);
return sprintf(buf, "%u\n", data->reg[param->msb[0]]);
}
static ssize_t store_u8(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval = SENSORS_LIMIT(reqval, 0, 255);
mutex_lock(&data->update_lock);
data->reg[param->msb[0]] = reqval;
write_byte(client, param->msb[0], reqval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_bitmask(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
return sprintf(buf, "%u\n",
(data->reg[param->msb[0]] >> param->
shift[0]) & param->mask[0]);
}
static ssize_t store_bitmask(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
u8 currval;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval = SENSORS_LIMIT(reqval, 0, param->mask[0]);
reqval = (reqval & param->mask[0]) << param->shift[0];
mutex_lock(&data->update_lock);
currval = read_byte(client, param->msb[0]);
reqval |= (currval & ~(param->mask[0] << param->shift[0]));
data->reg[param->msb[0]] = reqval;
write_byte(client, param->msb[0], reqval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan16(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u16 regval;
mutex_lock(&data->update_lock);
regval = (data->reg[param->msb[0]] << 8) | data->reg[param->lsb[0]];
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n",
(regval == 0 ? -1 : (regval) ==
0xffff ? 0 : 5400000 / regval));
}
static ssize_t store_fan16(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval =
(reqval <= 0 ? 0xffff : SENSORS_LIMIT(5400000 / reqval, 0, 0xfffe));
mutex_lock(&data->update_lock);
data->reg[param->msb[0]] = (reqval >> 8) & 0xff;
data->reg[param->lsb[0]] = reqval & 0xff;
write_byte(client, param->msb[0], data->reg[param->msb[0]]);
write_byte(client, param->lsb[0], data->reg[param->lsb[0]]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in10(struct device *dev, struct device_attribute *attr,
char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u16 regval;
u8 nr = sda->index;
mutex_lock(&data->update_lock);
regval = (data->reg[param->msb[0]] << 8) | (data->reg[param->lsb[0]]);
mutex_unlock(&data->update_lock);
regval = (regval >> 6) * asc7621_in_scaling[nr] / (0xc0 << 2);
return sprintf(buf, "%u\n", regval);
}
static ssize_t show_in8(struct device *dev, struct device_attribute *attr,
char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 nr = sda->index;
return sprintf(buf, "%u\n",
((data->reg[param->msb[0]] *
asc7621_in_scaling[nr]) / 0xc0));
}
static ssize_t store_in8(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
u8 nr = sda->index;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval = SENSORS_LIMIT(reqval, 0, 0xffff);
reqval = reqval * 0xc0 / asc7621_in_scaling[nr];
reqval = SENSORS_LIMIT(reqval, 0, 0xff);
mutex_lock(&data->update_lock);
data->reg[param->msb[0]] = reqval;
write_byte(client, param->msb[0], reqval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp8(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
return sprintf(buf, "%d\n", ((s8) data->reg[param->msb[0]]) * 1000);
}
static ssize_t store_temp8(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
s8 temp;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval = SENSORS_LIMIT(reqval, -127000, 127000);
temp = reqval / 1000;
mutex_lock(&data->update_lock);
data->reg[param->msb[0]] = temp;
write_byte(client, param->msb[0], temp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp10(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 msb, lsb;
int temp;
mutex_lock(&data->update_lock);
msb = data->reg[param->msb[0]];
lsb = (data->reg[param->lsb[0]] >> 6) & 0x03;
temp = (((s8) msb) * 1000) + (lsb * 250);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_temp62(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 regval = data->reg[param->msb[0]];
int temp = ((s8) (regval & 0xfc) * 1000) + ((regval & 0x03) * 250);
return sprintf(buf, "%d\n", temp);
}
static ssize_t store_temp62(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval, i, f;
s8 temp;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
reqval = SENSORS_LIMIT(reqval, -32000, 31750);
i = reqval / 1000;
f = reqval - (i * 1000);
temp = i << 2;
temp |= f / 250;
mutex_lock(&data->update_lock);
data->reg[param->msb[0]] = temp;
write_byte(client, param->msb[0], temp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_ap2_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
long auto_point1;
u8 regval;
int temp;
mutex_lock(&data->update_lock);
auto_point1 = ((s8) data->reg[param->msb[1]]) * 1000;
regval =
((data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0]);
temp = auto_point1 + asc7621_range_map[SENSORS_LIMIT(regval, 0, 15)];
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp);
}
static ssize_t store_ap2_temp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval, auto_point1;
int i;
u8 currval, newval = 0;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
mutex_lock(&data->update_lock);
auto_point1 = data->reg[param->msb[1]] * 1000;
reqval = SENSORS_LIMIT(reqval, auto_point1 + 2000, auto_point1 + 80000);
for (i = ARRAY_SIZE(asc7621_range_map) - 1; i >= 0; i--) {
if (reqval >= auto_point1 + asc7621_range_map[i]) {
newval = i;
break;
}
}
newval = (newval & param->mask[0]) << param->shift[0];
currval = read_byte(client, param->msb[0]);
newval |= (currval & ~(param->mask[0] << param->shift[0]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_ac(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 config, altbit, regval;
u8 map[] = {
0x01, 0x02, 0x04, 0x1f, 0x00, 0x06, 0x07, 0x10,
0x08, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f
};
mutex_lock(&data->update_lock);
config = (data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0];
altbit = (data->reg[param->msb[1]] >> param->shift[1]) & param->mask[1];
regval = config | (altbit << 3);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n", map[SENSORS_LIMIT(regval, 0, 15)]);
}
static ssize_t store_pwm_ac(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
unsigned long reqval;
u8 currval, config, altbit, newval;
u16 map[] = {
0x04, 0x00, 0x01, 0xff, 0x02, 0xff, 0x05, 0x06,
0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03,
};
if (strict_strtoul(buf, 10, &reqval))
return -EINVAL;
if (reqval > 31)
return -EINVAL;
reqval = map[reqval];
if (reqval == 0xff)
return -EINVAL;
config = reqval & 0x07;
altbit = (reqval >> 3) & 0x01;
config = (config & param->mask[0]) << param->shift[0];
altbit = (altbit & param->mask[1]) << param->shift[1];
mutex_lock(&data->update_lock);
currval = read_byte(client, param->msb[0]);
newval = config | (currval & ~(param->mask[0] << param->shift[0]));
newval = altbit | (newval & ~(param->mask[1] << param->shift[1]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 config, altbit, minoff, val, newval;
mutex_lock(&data->update_lock);
config = (data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0];
altbit = (data->reg[param->msb[1]] >> param->shift[1]) & param->mask[1];
minoff = (data->reg[param->msb[2]] >> param->shift[2]) & param->mask[2];
mutex_unlock(&data->update_lock);
val = config | (altbit << 3);
newval = 0;
if (val == 3 || val >= 10)
newval = 255;
else if (val == 4)
newval = 0;
else if (val == 7)
newval = 1;
else if (minoff == 1)
newval = 2;
else
newval = 3;
return sprintf(buf, "%u\n", newval);
}
static ssize_t store_pwm_enable(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
u8 currval, config, altbit, newval, minoff = 255;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
switch (reqval) {
case 0:
newval = 0x04;
break;
case 1:
newval = 0x07;
break;
case 2:
newval = 0x00;
minoff = 1;
break;
case 3:
newval = 0x00;
minoff = 0;
break;
case 255:
newval = 0x03;
break;
default:
return -EINVAL;
}
config = newval & 0x07;
altbit = (newval >> 3) & 0x01;
mutex_lock(&data->update_lock);
config = (config & param->mask[0]) << param->shift[0];
altbit = (altbit & param->mask[1]) << param->shift[1];
currval = read_byte(client, param->msb[0]);
newval = config | (currval & ~(param->mask[0] << param->shift[0]));
newval = altbit | (newval & ~(param->mask[1] << param->shift[1]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
if (minoff < 255) {
minoff = (minoff & param->mask[2]) << param->shift[2];
currval = read_byte(client, param->msb[2]);
newval =
minoff | (currval & ~(param->mask[2] << param->shift[2]));
data->reg[param->msb[2]] = newval;
write_byte(client, param->msb[2], newval);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_freq(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 regval =
(data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0];
regval = SENSORS_LIMIT(regval, 0, 15);
return sprintf(buf, "%u\n", asc7621_pwm_freq_map[regval]);
}
static ssize_t store_pwm_freq(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
unsigned long reqval;
u8 currval, newval = 255;
int i;
if (strict_strtoul(buf, 10, &reqval))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(asc7621_pwm_freq_map); i++) {
if (reqval == asc7621_pwm_freq_map[i]) {
newval = i;
break;
}
}
if (newval == 255)
return -EINVAL;
newval = (newval & param->mask[0]) << param->shift[0];
mutex_lock(&data->update_lock);
currval = read_byte(client, param->msb[0]);
newval |= (currval & ~(param->mask[0] << param->shift[0]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_ast(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 regval =
(data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0];
regval = SENSORS_LIMIT(regval, 0, 7);
return sprintf(buf, "%u\n", asc7621_pwm_auto_spinup_map[regval]);
}
static ssize_t store_pwm_ast(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
u8 currval, newval = 255;
u32 i;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(asc7621_pwm_auto_spinup_map); i++) {
if (reqval == asc7621_pwm_auto_spinup_map[i]) {
newval = i;
break;
}
}
if (newval == 255)
return -EINVAL;
newval = (newval & param->mask[0]) << param->shift[0];
mutex_lock(&data->update_lock);
currval = read_byte(client, param->msb[0]);
newval |= (currval & ~(param->mask[0] << param->shift[0]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_st(struct device *dev,
struct device_attribute *attr, char *buf)
{
SETUP_SHOW_data_param(dev, attr);
u8 regval =
(data->reg[param->msb[0]] >> param->shift[0]) & param->mask[0];
regval = SENSORS_LIMIT(regval, 0, 7);
return sprintf(buf, "%u\n", asc7621_temp_smoothing_time_map[regval]);
}
static ssize_t store_temp_st(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
SETUP_STORE_data_param(dev, attr);
long reqval;
u8 currval, newval = 255;
u32 i;
if (strict_strtol(buf, 10, &reqval))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(asc7621_temp_smoothing_time_map); i++) {
if (reqval == asc7621_temp_smoothing_time_map[i]) {
newval = i;
break;
}
}
if (newval == 255)
return -EINVAL;
newval = (newval & param->mask[0]) << param->shift[0];
mutex_lock(&data->update_lock);
currval = read_byte(client, param->msb[0]);
newval |= (currval & ~(param->mask[0] << param->shift[0]));
data->reg[param->msb[0]] = newval;
write_byte(client, param->msb[0], newval);
mutex_unlock(&data->update_lock);
return count;
}
static struct asc7621_data *asc7621_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct asc7621_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (!data->valid ||
time_after(jiffies, data->last_high_reading + INTERVAL_HIGH)) {
for (i = 0; i < ARRAY_SIZE(asc7621_register_priorities); i++) {
if (asc7621_register_priorities[i] == PRI_HIGH) {
data->reg[i] =
i2c_smbus_read_byte_data(client, i) & 0xff;
}
}
data->last_high_reading = jiffies;
};
if (!data->valid ||
time_after(jiffies, data->last_low_reading + INTERVAL_LOW)) {
for (i = 0; i < ARRAY_SIZE(asc7621_params); i++) {
if (asc7621_register_priorities[i] == PRI_LOW) {
data->reg[i] =
i2c_smbus_read_byte_data(client, i) & 0xff;
}
}
data->last_low_reading = jiffies;
};
data->valid = 1;
mutex_unlock(&data->update_lock);
return data;
}
static inline int valid_address_for_chip(int chip_type, int address)
{
int i;
for (i = 0; asc7621_chips[chip_type].addresses[i] != I2C_CLIENT_END;
i++) {
if (asc7621_chips[chip_type].addresses[i] == address)
return 1;
}
return 0;
}
static void asc7621_init_client(struct i2c_client *client)
{
int value;
value = read_byte(client, 0x40);
if (value & 0x02) {
dev_err(&client->dev,
"Client (%d,0x%02x) config is locked.\n",
i2c_adapter_id(client->adapter), client->addr);
};
if (!(value & 0x04)) {
dev_err(&client->dev, "Client (%d,0x%02x) is not ready.\n",
i2c_adapter_id(client->adapter), client->addr);
};
value = (value & ~0x02) | 0x01;
write_byte(client, 0x40, value & 0xff);
}
static int
asc7621_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct asc7621_data *data;
int i, err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
data = kzalloc(sizeof(struct asc7621_data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->valid = 0;
mutex_init(&data->update_lock);
asc7621_init_client(client);
for (i = 0; i < ARRAY_SIZE(asc7621_params); i++) {
err =
device_create_file(&client->dev,
&(asc7621_params[i].sda.dev_attr));
if (err)
goto exit_remove;
}
data->class_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->class_dev)) {
err = PTR_ERR(data->class_dev);
goto exit_remove;
}
return 0;
exit_remove:
for (i = 0; i < ARRAY_SIZE(asc7621_params); i++) {
device_remove_file(&client->dev,
&(asc7621_params[i].sda.dev_attr));
}
kfree(data);
return err;
}
static int asc7621_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int company, verstep, chip_index;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
for (chip_index = FIRST_CHIP; chip_index <= LAST_CHIP; chip_index++) {
if (!valid_address_for_chip(chip_index, client->addr))
continue;
company = read_byte(client,
asc7621_chips[chip_index].company_reg);
verstep = read_byte(client,
asc7621_chips[chip_index].verstep_reg);
if (company == asc7621_chips[chip_index].company_id &&
verstep == asc7621_chips[chip_index].verstep_id) {
strlcpy(info->type, asc7621_chips[chip_index].name,
I2C_NAME_SIZE);
dev_info(&adapter->dev, "Matched %s at 0x%02x\n",
asc7621_chips[chip_index].name, client->addr);
return 0;
}
}
return -ENODEV;
}
static int asc7621_remove(struct i2c_client *client)
{
struct asc7621_data *data = i2c_get_clientdata(client);
int i;
hwmon_device_unregister(data->class_dev);
for (i = 0; i < ARRAY_SIZE(asc7621_params); i++) {
device_remove_file(&client->dev,
&(asc7621_params[i].sda.dev_attr));
}
kfree(data);
return 0;
}
static int __init sm_asc7621_init(void)
{
int i, j;
for (i = 0; i < ARRAY_SIZE(asc7621_params); i++) {
for (j = 0; j < ARRAY_SIZE(asc7621_params[i].msb); j++)
asc7621_register_priorities[asc7621_params[i].msb[j]] =
asc7621_params[i].priority;
for (j = 0; j < ARRAY_SIZE(asc7621_params[i].lsb); j++)
asc7621_register_priorities[asc7621_params[i].lsb[j]] =
asc7621_params[i].priority;
}
return i2c_add_driver(&asc7621_driver);
}
static void __exit sm_asc7621_exit(void)
{
i2c_del_driver(&asc7621_driver);
}
