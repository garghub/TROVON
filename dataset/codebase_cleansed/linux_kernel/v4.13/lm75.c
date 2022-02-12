static inline long lm75_reg_to_mc(s16 temp, u8 resolution)
{
return ((temp >> (16 - resolution)) * 1000) >> (resolution - 8);
}
static int lm75_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *val)
{
struct lm75_data *data = dev_get_drvdata(dev);
unsigned int regval;
int err, reg;
switch (type) {
case hwmon_chip:
switch (attr) {
case hwmon_chip_update_interval:
*val = data->sample_time;
break;;
default:
return -EINVAL;
}
break;
case hwmon_temp:
switch (attr) {
case hwmon_temp_input:
reg = LM75_REG_TEMP;
break;
case hwmon_temp_max:
reg = LM75_REG_MAX;
break;
case hwmon_temp_max_hyst:
reg = LM75_REG_HYST;
break;
default:
return -EINVAL;
}
err = regmap_read(data->regmap, reg, &regval);
if (err < 0)
return err;
*val = lm75_reg_to_mc(regval, data->resolution);
break;
default:
return -EINVAL;
}
return 0;
}
static int lm75_write(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long temp)
{
struct lm75_data *data = dev_get_drvdata(dev);
u8 resolution;
int reg;
if (type != hwmon_temp)
return -EINVAL;
switch (attr) {
case hwmon_temp_max:
reg = LM75_REG_MAX;
break;
case hwmon_temp_max_hyst:
reg = LM75_REG_HYST;
break;
default:
return -EINVAL;
}
if (data->resolution_limits)
resolution = data->resolution_limits;
else
resolution = data->resolution;
temp = clamp_val(temp, LM75_TEMP_MIN, LM75_TEMP_MAX);
temp = DIV_ROUND_CLOSEST(temp << (resolution - 8),
1000) << (16 - resolution);
return regmap_write(data->regmap, reg, temp);
}
static umode_t lm75_is_visible(const void *data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
switch (type) {
case hwmon_chip:
switch (attr) {
case hwmon_chip_update_interval:
return S_IRUGO;
}
break;
case hwmon_temp:
switch (attr) {
case hwmon_temp_input:
return S_IRUGO;
case hwmon_temp_max:
case hwmon_temp_max_hyst:
return S_IRUGO | S_IWUSR;
}
break;
default:
break;
}
return 0;
}
static bool lm75_is_writeable_reg(struct device *dev, unsigned int reg)
{
return reg != LM75_REG_TEMP;
}
static bool lm75_is_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == LM75_REG_TEMP;
}
static void lm75_remove(void *data)
{
struct lm75_data *lm75 = data;
struct i2c_client *client = lm75->client;
i2c_smbus_write_byte_data(client, LM75_REG_CONF, lm75->orig_conf);
}
static int
lm75_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct lm75_data *data;
int status, err;
u8 set_mask, clr_mask;
int new;
enum lm75_type kind;
if (client->dev.of_node)
kind = (enum lm75_type)of_device_get_match_data(&client->dev);
else
kind = id->driver_data;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -EIO;
data = devm_kzalloc(dev, sizeof(struct lm75_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
data->regmap = devm_regmap_init_i2c(client, &lm75_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
set_mask = 0;
clr_mask = LM75_SHUTDOWN;
switch (kind) {
case adt75:
clr_mask |= 1 << 5;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC / 8;
break;
case ds1775:
case ds75:
case stds75:
clr_mask |= 3 << 5;
set_mask |= 2 << 5;
data->resolution = 11;
data->sample_time = MSEC_PER_SEC;
break;
case ds7505:
set_mask |= 3 << 5;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC / 4;
break;
case g751:
case lm75:
case lm75a:
data->resolution = 9;
data->sample_time = MSEC_PER_SEC / 2;
break;
case lm75b:
data->resolution = 11;
data->sample_time = MSEC_PER_SEC / 4;
break;
case max6625:
data->resolution = 9;
data->sample_time = MSEC_PER_SEC / 4;
break;
case max6626:
data->resolution = 12;
data->resolution_limits = 9;
data->sample_time = MSEC_PER_SEC / 4;
break;
case tcn75:
data->resolution = 9;
data->sample_time = MSEC_PER_SEC / 8;
break;
case mcp980x:
data->resolution_limits = 9;
case tmp100:
case tmp101:
set_mask |= 3 << 5;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC;
clr_mask |= 1 << 7;
break;
case tmp112:
set_mask |= 3 << 5;
clr_mask |= 1 << 7;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC / 4;
break;
case tmp105:
case tmp175:
case tmp275:
case tmp75:
set_mask |= 3 << 5;
clr_mask |= 1 << 7;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC / 2;
break;
case tmp75c:
clr_mask |= 1 << 5;
data->resolution = 12;
data->sample_time = MSEC_PER_SEC / 4;
break;
}
status = i2c_smbus_read_byte_data(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(dev, "Can't read config? %d\n", status);
return status;
}
data->orig_conf = status;
new = status & ~clr_mask;
new |= set_mask;
if (status != new)
i2c_smbus_write_byte_data(client, LM75_REG_CONF, new);
err = devm_add_action_or_reset(dev, lm75_remove, data);
if (err)
return err;
dev_dbg(dev, "Config %02x\n", new);
hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
data, &lm75_chip_info,
NULL);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "%s: sensor '%s'\n", dev_name(hwmon_dev), client->name);
return 0;
}
static int lm75_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
int i;
int conf, hyst, os;
bool is_lm75a = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
conf = i2c_smbus_read_byte_data(new_client, 1);
if (conf & 0xe0)
return -ENODEV;
if (i2c_smbus_read_byte_data(new_client, 7) == LM75A_ID) {
if (i2c_smbus_read_byte_data(new_client, 4) != 0xff
|| i2c_smbus_read_byte_data(new_client, 5) != 0xff
|| i2c_smbus_read_byte_data(new_client, 6) != 0xff)
return -ENODEV;
is_lm75a = 1;
hyst = i2c_smbus_read_byte_data(new_client, 2);
os = i2c_smbus_read_byte_data(new_client, 3);
} else {
hyst = i2c_smbus_read_byte_data(new_client, 2);
if (i2c_smbus_read_byte_data(new_client, 4) != hyst
|| i2c_smbus_read_byte_data(new_client, 5) != hyst
|| i2c_smbus_read_byte_data(new_client, 6) != hyst
|| i2c_smbus_read_byte_data(new_client, 7) != hyst)
return -ENODEV;
os = i2c_smbus_read_byte_data(new_client, 3);
if (i2c_smbus_read_byte_data(new_client, 4) != os
|| i2c_smbus_read_byte_data(new_client, 5) != os
|| i2c_smbus_read_byte_data(new_client, 6) != os
|| i2c_smbus_read_byte_data(new_client, 7) != os)
return -ENODEV;
}
if (hyst == 0 && os == 0)
return -ENODEV;
for (i = 8; i <= 248; i += 40) {
if (i2c_smbus_read_byte_data(new_client, i + 1) != conf
|| i2c_smbus_read_byte_data(new_client, i + 2) != hyst
|| i2c_smbus_read_byte_data(new_client, i + 3) != os)
return -ENODEV;
if (is_lm75a && i2c_smbus_read_byte_data(new_client, i + 7)
!= LM75A_ID)
return -ENODEV;
}
strlcpy(info->type, is_lm75a ? "lm75a" : "lm75", I2C_NAME_SIZE);
return 0;
}
static int lm75_suspend(struct device *dev)
{
int status;
struct i2c_client *client = to_i2c_client(dev);
status = i2c_smbus_read_byte_data(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", status);
return status;
}
status = status | LM75_SHUTDOWN;
i2c_smbus_write_byte_data(client, LM75_REG_CONF, status);
return 0;
}
static int lm75_resume(struct device *dev)
{
int status;
struct i2c_client *client = to_i2c_client(dev);
status = i2c_smbus_read_byte_data(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", status);
return status;
}
status = status & ~LM75_SHUTDOWN;
i2c_smbus_write_byte_data(client, LM75_REG_CONF, status);
return 0;
}
