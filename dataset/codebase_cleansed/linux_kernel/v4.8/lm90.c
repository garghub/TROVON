static inline s32 adm1032_write_byte(struct i2c_client *client, u8 value)
{
return i2c_smbus_xfer(client->adapter, client->addr,
client->flags & ~I2C_CLIENT_PEC,
I2C_SMBUS_WRITE, value, I2C_SMBUS_BYTE, NULL);
}
static int lm90_read_reg(struct i2c_client *client, u8 reg)
{
int err;
if (client->flags & I2C_CLIENT_PEC) {
err = adm1032_write_byte(client, reg);
if (err >= 0)
err = i2c_smbus_read_byte(client);
} else
err = i2c_smbus_read_byte_data(client, reg);
return err;
}
static int lm90_read16(struct i2c_client *client, u8 regh, u8 regl)
{
int oldh, newh, l;
oldh = lm90_read_reg(client, regh);
if (oldh < 0)
return oldh;
l = lm90_read_reg(client, regl);
if (l < 0)
return l;
newh = lm90_read_reg(client, regh);
if (newh < 0)
return newh;
if (oldh != newh) {
l = lm90_read_reg(client, regl);
if (l < 0)
return l;
}
return (newh << 8) | l;
}
static inline int lm90_select_remote_channel(struct i2c_client *client,
struct lm90_data *data,
int channel)
{
int config;
if (data->kind == max6696) {
config = lm90_read_reg(client, LM90_REG_R_CONFIG1);
if (config < 0)
return config;
config &= ~0x08;
if (channel)
config |= 0x08;
i2c_smbus_write_byte_data(client, LM90_REG_W_CONFIG1,
config);
}
return 0;
}
static void lm90_set_convrate(struct i2c_client *client, struct lm90_data *data,
unsigned int interval)
{
int i;
unsigned int update_interval;
interval <<= 6;
for (i = 0, update_interval = LM90_MAX_CONVRATE_MS << 6;
i < data->max_convrate; i++, update_interval >>= 1)
if (interval >= update_interval * 3 / 4)
break;
i2c_smbus_write_byte_data(client, LM90_REG_W_CONVRATE, i);
data->update_interval = DIV_ROUND_CLOSEST(update_interval, 64);
}
static int lm90_update_limits(struct device *dev)
{
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int val;
val = lm90_read_reg(client, LM90_REG_R_LOCAL_CRIT);
if (val < 0)
return val;
data->temp8[LOCAL_CRIT] = val;
val = lm90_read_reg(client, LM90_REG_R_REMOTE_CRIT);
if (val < 0)
return val;
data->temp8[REMOTE_CRIT] = val;
val = lm90_read_reg(client, LM90_REG_R_TCRIT_HYST);
if (val < 0)
return val;
data->temp_hyst = val;
val = lm90_read_reg(client, LM90_REG_R_REMOTE_LOWH);
if (val < 0)
return val;
data->temp11[REMOTE_LOW] = val << 8;
if (data->flags & LM90_HAVE_REM_LIMIT_EXT) {
val = lm90_read_reg(client, LM90_REG_R_REMOTE_LOWL);
if (val < 0)
return val;
data->temp11[REMOTE_LOW] |= val;
}
val = lm90_read_reg(client, LM90_REG_R_REMOTE_HIGHH);
if (val < 0)
return val;
data->temp11[REMOTE_HIGH] = val << 8;
if (data->flags & LM90_HAVE_REM_LIMIT_EXT) {
val = lm90_read_reg(client, LM90_REG_R_REMOTE_HIGHL);
if (val < 0)
return val;
data->temp11[REMOTE_HIGH] |= val;
}
if (data->flags & LM90_HAVE_OFFSET) {
val = lm90_read16(client, LM90_REG_R_REMOTE_OFFSH,
LM90_REG_R_REMOTE_OFFSL);
if (val < 0)
return val;
data->temp11[REMOTE_OFFSET] = val;
}
if (data->flags & LM90_HAVE_EMERGENCY) {
val = lm90_read_reg(client, MAX6659_REG_R_LOCAL_EMERG);
if (val < 0)
return val;
data->temp8[LOCAL_EMERG] = val;
val = lm90_read_reg(client, MAX6659_REG_R_REMOTE_EMERG);
if (val < 0)
return val;
data->temp8[REMOTE_EMERG] = val;
}
if (data->kind == max6696) {
val = lm90_select_remote_channel(client, data, 1);
if (val < 0)
return val;
val = lm90_read_reg(client, LM90_REG_R_REMOTE_CRIT);
if (val < 0)
return val;
data->temp8[REMOTE2_CRIT] = val;
val = lm90_read_reg(client, MAX6659_REG_R_REMOTE_EMERG);
if (val < 0)
return val;
data->temp8[REMOTE2_EMERG] = val;
val = lm90_read_reg(client, LM90_REG_R_REMOTE_LOWH);
if (val < 0)
return val;
data->temp11[REMOTE2_LOW] = val << 8;
val = lm90_read_reg(client, LM90_REG_R_REMOTE_HIGHH);
if (val < 0)
return val;
data->temp11[REMOTE2_HIGH] = val << 8;
lm90_select_remote_channel(client, data, 0);
}
return 0;
}
static struct lm90_data *lm90_update_device(struct device *dev)
{
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long next_update;
int val = 0;
mutex_lock(&data->update_lock);
if (!data->valid) {
val = lm90_update_limits(dev);
if (val < 0)
goto error;
}
next_update = data->last_updated +
msecs_to_jiffies(data->update_interval);
if (time_after(jiffies, next_update) || !data->valid) {
dev_dbg(&client->dev, "Updating lm90 data.\n");
data->valid = false;
val = lm90_read_reg(client, LM90_REG_R_LOCAL_LOW);
if (val < 0)
goto error;
data->temp8[LOCAL_LOW] = val;
val = lm90_read_reg(client, LM90_REG_R_LOCAL_HIGH);
if (val < 0)
goto error;
data->temp8[LOCAL_HIGH] = val;
if (data->reg_local_ext) {
val = lm90_read16(client, LM90_REG_R_LOCAL_TEMP,
data->reg_local_ext);
if (val < 0)
goto error;
data->temp11[LOCAL_TEMP] = val;
} else {
val = lm90_read_reg(client, LM90_REG_R_LOCAL_TEMP);
if (val < 0)
goto error;
data->temp11[LOCAL_TEMP] = val << 8;
}
val = lm90_read16(client, LM90_REG_R_REMOTE_TEMPH,
LM90_REG_R_REMOTE_TEMPL);
if (val < 0)
goto error;
data->temp11[REMOTE_TEMP] = val;
val = lm90_read_reg(client, LM90_REG_R_STATUS);
if (val < 0)
goto error;
data->alarms = val;
if (data->kind == max6696) {
val = lm90_select_remote_channel(client, data, 1);
if (val < 0)
goto error;
val = lm90_read16(client, LM90_REG_R_REMOTE_TEMPH,
LM90_REG_R_REMOTE_TEMPL);
if (val < 0)
goto error;
data->temp11[REMOTE2_TEMP] = val;
lm90_select_remote_channel(client, data, 0);
val = lm90_read_reg(client, MAX6696_REG_R_STATUS2);
if (val < 0)
goto error;
data->alarms |= val << 8;
}
if (!(data->config_orig & 0x80) &&
!(data->alarms & data->alert_alarms)) {
val = lm90_read_reg(client, LM90_REG_R_CONFIG1);
if (val < 0)
goto error;
if (val & 0x80) {
dev_dbg(&client->dev, "Re-enabling ALERT#\n");
i2c_smbus_write_byte_data(client,
LM90_REG_W_CONFIG1,
val & ~0x80);
}
}
data->last_updated = jiffies;
data->valid = true;
}
error:
mutex_unlock(&data->update_lock);
if (val < 0)
return ERR_PTR(val);
return data;
}
static inline int temp_from_s8(s8 val)
{
return val * 1000;
}
static inline int temp_from_u8(u8 val)
{
return val * 1000;
}
static inline int temp_from_s16(s16 val)
{
return val / 32 * 125;
}
static inline int temp_from_u16(u16 val)
{
return val / 32 * 125;
}
static s8 temp_to_s8(long val)
{
if (val <= -128000)
return -128;
if (val >= 127000)
return 127;
if (val < 0)
return (val - 500) / 1000;
return (val + 500) / 1000;
}
static u8 temp_to_u8(long val)
{
if (val <= 0)
return 0;
if (val >= 255000)
return 255;
return (val + 500) / 1000;
}
static s16 temp_to_s16(long val)
{
if (val <= -128000)
return 0x8000;
if (val >= 127875)
return 0x7FE0;
if (val < 0)
return (val - 62) / 125 * 32;
return (val + 62) / 125 * 32;
}
static u8 hyst_to_reg(long val)
{
if (val <= 0)
return 0;
if (val >= 30500)
return 31;
return (val + 500) / 1000;
}
static inline int temp_from_u8_adt7461(struct lm90_data *data, u8 val)
{
if (data->flags & LM90_FLAG_ADT7461_EXT)
return (val - 64) * 1000;
return temp_from_s8(val);
}
static inline int temp_from_u16_adt7461(struct lm90_data *data, u16 val)
{
if (data->flags & LM90_FLAG_ADT7461_EXT)
return (val - 0x4000) / 64 * 250;
return temp_from_s16(val);
}
static u8 temp_to_u8_adt7461(struct lm90_data *data, long val)
{
if (data->flags & LM90_FLAG_ADT7461_EXT) {
if (val <= -64000)
return 0;
if (val >= 191000)
return 0xFF;
return (val + 500 + 64000) / 1000;
}
if (val <= 0)
return 0;
if (val >= 127000)
return 127;
return (val + 500) / 1000;
}
static u16 temp_to_u16_adt7461(struct lm90_data *data, long val)
{
if (data->flags & LM90_FLAG_ADT7461_EXT) {
if (val <= -64000)
return 0;
if (val >= 191750)
return 0xFFC0;
return (val + 64000 + 125) / 250 * 64;
}
if (val <= 0)
return 0;
if (val >= 127750)
return 0x7FC0;
return (val + 125) / 250 * 64;
}
static ssize_t show_temp8(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm90_data *data = lm90_update_device(dev);
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->kind == adt7461 || data->kind == tmp451)
temp = temp_from_u8_adt7461(data, data->temp8[attr->index]);
else if (data->kind == max6646)
temp = temp_from_u8(data->temp8[attr->index]);
else
temp = temp_from_s8(data->temp8[attr->index]);
if (data->kind == lm99 && attr->index == 3)
temp += 16000;
return sprintf(buf, "%d\n", temp);
}
static ssize_t set_temp8(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
static const u8 reg[TEMP8_REG_NUM] = {
LM90_REG_W_LOCAL_LOW,
LM90_REG_W_LOCAL_HIGH,
LM90_REG_W_LOCAL_CRIT,
LM90_REG_W_REMOTE_CRIT,
MAX6659_REG_W_LOCAL_EMERG,
MAX6659_REG_W_REMOTE_EMERG,
LM90_REG_W_REMOTE_CRIT,
MAX6659_REG_W_REMOTE_EMERG,
};
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
if (data->kind == lm99 && attr->index == 3)
val -= 16000;
mutex_lock(&data->update_lock);
if (data->kind == adt7461 || data->kind == tmp451)
data->temp8[nr] = temp_to_u8_adt7461(data, val);
else if (data->kind == max6646)
data->temp8[nr] = temp_to_u8(val);
else
data->temp8[nr] = temp_to_s8(val);
lm90_select_remote_channel(client, data, nr >= 6);
i2c_smbus_write_byte_data(client, reg[nr], data->temp8[nr]);
lm90_select_remote_channel(client, data, 0);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp11(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct lm90_data *data = lm90_update_device(dev);
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->kind == adt7461 || data->kind == tmp451)
temp = temp_from_u16_adt7461(data, data->temp11[attr->index]);
else if (data->kind == max6646)
temp = temp_from_u16(data->temp11[attr->index]);
else
temp = temp_from_s16(data->temp11[attr->index]);
if (data->kind == lm99 && attr->index <= 2)
temp += 16000;
return sprintf(buf, "%d\n", temp);
}
static ssize_t set_temp11(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct {
u8 high;
u8 low;
int channel;
} reg[5] = {
{ LM90_REG_W_REMOTE_LOWH, LM90_REG_W_REMOTE_LOWL, 0 },
{ LM90_REG_W_REMOTE_HIGHH, LM90_REG_W_REMOTE_HIGHL, 0 },
{ LM90_REG_W_REMOTE_OFFSH, LM90_REG_W_REMOTE_OFFSL, 0 },
{ LM90_REG_W_REMOTE_LOWH, LM90_REG_W_REMOTE_LOWL, 1 },
{ LM90_REG_W_REMOTE_HIGHH, LM90_REG_W_REMOTE_HIGHL, 1 }
};
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int nr = attr->nr;
int index = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
if (data->kind == lm99 && index <= 2)
val -= 16000;
mutex_lock(&data->update_lock);
if (data->kind == adt7461 || data->kind == tmp451)
data->temp11[index] = temp_to_u16_adt7461(data, val);
else if (data->kind == max6646)
data->temp11[index] = temp_to_u8(val) << 8;
else if (data->flags & LM90_HAVE_REM_LIMIT_EXT)
data->temp11[index] = temp_to_s16(val);
else
data->temp11[index] = temp_to_s8(val) << 8;
lm90_select_remote_channel(client, data, reg[nr].channel);
i2c_smbus_write_byte_data(client, reg[nr].high,
data->temp11[index] >> 8);
if (data->flags & LM90_HAVE_REM_LIMIT_EXT)
i2c_smbus_write_byte_data(client, reg[nr].low,
data->temp11[index] & 0xff);
lm90_select_remote_channel(client, data, 0);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temphyst(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm90_data *data = lm90_update_device(dev);
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->kind == adt7461 || data->kind == tmp451)
temp = temp_from_u8_adt7461(data, data->temp8[attr->index]);
else if (data->kind == max6646)
temp = temp_from_u8(data->temp8[attr->index]);
else
temp = temp_from_s8(data->temp8[attr->index]);
if (data->kind == lm99 && attr->index == 3)
temp += 16000;
return sprintf(buf, "%d\n", temp - temp_from_s8(data->temp_hyst));
}
static ssize_t set_temphyst(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
int temp;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
if (data->kind == adt7461 || data->kind == tmp451)
temp = temp_from_u8_adt7461(data, data->temp8[LOCAL_CRIT]);
else if (data->kind == max6646)
temp = temp_from_u8(data->temp8[LOCAL_CRIT]);
else
temp = temp_from_s8(data->temp8[LOCAL_CRIT]);
data->temp_hyst = hyst_to_reg(temp - val);
i2c_smbus_write_byte_data(client, LM90_REG_W_TCRIT_HYST,
data->temp_hyst);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm90_data *data = lm90_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm90_data *data = lm90_update_device(dev);
int bitnr = attr->index;
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_update_interval(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm90_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->update_interval);
}
static ssize_t set_update_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm90_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
lm90_set_convrate(client, data, clamp_val(val, 0, 100000));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pec(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return sprintf(buf, "%d\n", !!(client->flags & I2C_CLIENT_PEC));
}
static ssize_t set_pec(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
switch (val) {
case 0:
client->flags &= ~I2C_CLIENT_PEC;
break;
case 1:
client->flags |= I2C_CLIENT_PEC;
break;
default:
return -EINVAL;
}
return count;
}
static int lm90_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
const char *name = NULL;
int man_id, chip_id, config1, config2, convrate;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, LM90_REG_R_MAN_ID);
chip_id = i2c_smbus_read_byte_data(client, LM90_REG_R_CHIP_ID);
config1 = i2c_smbus_read_byte_data(client, LM90_REG_R_CONFIG1);
convrate = i2c_smbus_read_byte_data(client, LM90_REG_R_CONVRATE);
if (man_id < 0 || chip_id < 0 || config1 < 0 || convrate < 0)
return -ENODEV;
if (man_id == 0x01 || man_id == 0x5C || man_id == 0x41) {
config2 = i2c_smbus_read_byte_data(client, LM90_REG_R_CONFIG2);
if (config2 < 0)
return -ENODEV;
} else
config2 = 0;
if ((address == 0x4C || address == 0x4D)
&& man_id == 0x01) {
if ((config1 & 0x2A) == 0x00
&& (config2 & 0xF8) == 0x00
&& convrate <= 0x09) {
if (address == 0x4C
&& (chip_id & 0xF0) == 0x20) {
name = "lm90";
} else
if ((chip_id & 0xF0) == 0x30) {
name = "lm99";
dev_info(&adapter->dev,
"Assuming LM99 chip at 0x%02x\n",
address);
dev_info(&adapter->dev,
"If it is an LM89, instantiate it "
"with the new_device sysfs "
"interface\n");
} else
if (address == 0x4C
&& (chip_id & 0xF0) == 0x10) {
name = "lm86";
}
}
} else
if ((address == 0x4C || address == 0x4D)
&& man_id == 0x41) {
if ((chip_id & 0xF0) == 0x40
&& (config1 & 0x3F) == 0x00
&& convrate <= 0x0A) {
name = "adm1032";
if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_BYTE))
info->flags |= I2C_CLIENT_PEC;
} else
if (chip_id == 0x51
&& (config1 & 0x1B) == 0x00
&& convrate <= 0x0A) {
name = "adt7461";
} else
if (chip_id == 0x57
&& (config1 & 0x1B) == 0x00
&& convrate <= 0x0A) {
name = "adt7461a";
}
} else
if (man_id == 0x4D) {
int emerg, emerg2, status2;
emerg = i2c_smbus_read_byte_data(client,
MAX6659_REG_R_REMOTE_EMERG);
man_id = i2c_smbus_read_byte_data(client,
LM90_REG_R_MAN_ID);
emerg2 = i2c_smbus_read_byte_data(client,
MAX6659_REG_R_REMOTE_EMERG);
status2 = i2c_smbus_read_byte_data(client,
MAX6696_REG_R_STATUS2);
if (emerg < 0 || man_id < 0 || emerg2 < 0 || status2 < 0)
return -ENODEV;
if (chip_id == man_id
&& (address == 0x4C || address == 0x4D || address == 0x4E)
&& (config1 & 0x1F) == (man_id & 0x0F)
&& convrate <= 0x09) {
if (address == 0x4C)
name = "max6657";
else
name = "max6659";
} else
if (chip_id == 0x01
&& (config1 & 0x10) == 0x00
&& (status2 & 0x01) == 0x00
&& emerg == emerg2
&& convrate <= 0x07) {
name = "max6696";
} else
if (chip_id == 0x01
&& (config1 & 0x03) == 0x00
&& convrate <= 0x07) {
name = "max6680";
} else
if (chip_id == 0x59
&& (config1 & 0x3f) == 0x00
&& convrate <= 0x07) {
name = "max6646";
}
} else
if (address == 0x4C
&& man_id == 0x5C) {
if ((config1 & 0x2A) == 0x00
&& (config2 & 0xF8) == 0x00) {
if (chip_id == 0x01
&& convrate <= 0x09) {
name = "w83l771";
} else
if ((chip_id & 0xFE) == 0x10
&& convrate <= 0x08) {
name = "w83l771";
}
}
} else
if (address >= 0x48 && address <= 0x4F
&& man_id == 0xA1) {
if (chip_id == 0x00
&& (config1 & 0x2A) == 0x00
&& (config2 & 0xFE) == 0x00
&& convrate <= 0x09) {
name = "sa56004";
}
} else
if ((address == 0x4C || address == 0x4D)
&& man_id == 0x47) {
if (chip_id == 0x01
&& (config1 & 0x3F) == 0x00
&& convrate <= 0x08)
name = "g781";
} else
if (address == 0x4C
&& man_id == 0x55) {
int local_ext;
local_ext = i2c_smbus_read_byte_data(client,
TMP451_REG_R_LOCAL_TEMPL);
if (chip_id == 0x00
&& (config1 & 0x1B) == 0x00
&& convrate <= 0x09
&& (local_ext & 0x0F) == 0x00)
name = "tmp451";
}
if (!name) {
dev_dbg(&adapter->dev,
"Unsupported chip at 0x%02x (man_id=0x%02X, "
"chip_id=0x%02X)\n", address, man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static void lm90_restore_conf(void *_data)
{
struct lm90_data *data = _data;
struct i2c_client *client = data->client;
i2c_smbus_write_byte_data(client, LM90_REG_W_CONVRATE,
data->convrate_orig);
i2c_smbus_write_byte_data(client, LM90_REG_W_CONFIG1,
data->config_orig);
}
static int lm90_init_client(struct i2c_client *client, struct lm90_data *data)
{
int config, convrate;
convrate = lm90_read_reg(client, LM90_REG_R_CONVRATE);
if (convrate < 0)
return convrate;
data->convrate_orig = convrate;
lm90_set_convrate(client, data, 500);
config = lm90_read_reg(client, LM90_REG_R_CONFIG1);
if (config < 0)
return config;
data->config_orig = config;
if (data->kind == adt7461 || data->kind == tmp451) {
if (config & 0x04)
data->flags |= LM90_FLAG_ADT7461_EXT;
}
if (data->kind == max6680)
config |= 0x18;
if (data->kind == max6696)
config &= ~0x08;
config &= 0xBF;
if (config != data->config_orig)
i2c_smbus_write_byte_data(client, LM90_REG_W_CONFIG1, config);
return devm_add_action_or_reset(&client->dev, lm90_restore_conf, data);
}
static bool lm90_is_tripped(struct i2c_client *client, u16 *status)
{
struct lm90_data *data = i2c_get_clientdata(client);
int st, st2 = 0;
st = lm90_read_reg(client, LM90_REG_R_STATUS);
if (st < 0)
return false;
if (data->kind == max6696) {
st2 = lm90_read_reg(client, MAX6696_REG_R_STATUS2);
if (st2 < 0)
return false;
}
*status = st | (st2 << 8);
if ((st & 0x7f) == 0 && (st2 & 0xfe) == 0)
return false;
if ((st & (LM90_STATUS_LLOW | LM90_STATUS_LHIGH | LM90_STATUS_LTHRM)) ||
(st2 & MAX6696_STATUS2_LOT2))
dev_warn(&client->dev,
"temp%d out of range, please check!\n", 1);
if ((st & (LM90_STATUS_RLOW | LM90_STATUS_RHIGH | LM90_STATUS_RTHRM)) ||
(st2 & MAX6696_STATUS2_ROT2))
dev_warn(&client->dev,
"temp%d out of range, please check!\n", 2);
if (st & LM90_STATUS_ROPEN)
dev_warn(&client->dev,
"temp%d diode open, please check!\n", 2);
if (st2 & (MAX6696_STATUS2_R2LOW | MAX6696_STATUS2_R2HIGH |
MAX6696_STATUS2_R2THRM | MAX6696_STATUS2_R2OT2))
dev_warn(&client->dev,
"temp%d out of range, please check!\n", 3);
if (st2 & MAX6696_STATUS2_R2OPEN)
dev_warn(&client->dev,
"temp%d diode open, please check!\n", 3);
return true;
}
static irqreturn_t lm90_irq_thread(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
u16 status;
if (lm90_is_tripped(client, &status))
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static void lm90_remove_pec(void *dev)
{
device_remove_file(dev, &dev_attr_pec);
}
static void lm90_regulator_disable(void *regulator)
{
regulator_disable(regulator);
}
static int lm90_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct i2c_adapter *adapter = to_i2c_adapter(dev->parent);
struct lm90_data *data;
struct regulator *regulator;
struct device *hwmon_dev;
int groups = 0;
int err;
regulator = devm_regulator_get(dev, "vcc");
if (IS_ERR(regulator))
return PTR_ERR(regulator);
err = regulator_enable(regulator);
if (err < 0) {
dev_err(dev, "Failed to enable regulator: %d\n", err);
return err;
}
err = devm_add_action_or_reset(dev, lm90_regulator_disable, regulator);
if (err)
return err;
data = devm_kzalloc(dev, sizeof(struct lm90_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->kind = id->driver_data;
if (data->kind == adm1032) {
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
client->flags &= ~I2C_CLIENT_PEC;
}
data->alert_alarms = lm90_params[data->kind].alert_alarms;
data->flags = lm90_params[data->kind].flags;
data->reg_local_ext = lm90_params[data->kind].reg_local_ext;
data->max_convrate = lm90_params[data->kind].max_convrate;
err = lm90_init_client(client, data);
if (err < 0) {
dev_err(dev, "Failed to initialize device\n");
return err;
}
data->groups[groups++] = &lm90_group;
if (data->flags & LM90_HAVE_OFFSET)
data->groups[groups++] = &lm90_temp2_offset_group;
if (data->flags & LM90_HAVE_EMERGENCY)
data->groups[groups++] = &lm90_emergency_group;
if (data->flags & LM90_HAVE_EMERGENCY_ALARM)
data->groups[groups++] = &lm90_emergency_alarm_group;
if (data->flags & LM90_HAVE_TEMP3)
data->groups[groups++] = &lm90_temp3_group;
if (client->flags & I2C_CLIENT_PEC) {
err = device_create_file(dev, &dev_attr_pec);
if (err)
return err;
err = devm_add_action_or_reset(dev, lm90_remove_pec, dev);
if (err)
return err;
}
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
if (client->irq) {
dev_dbg(dev, "IRQ: %d\n", client->irq);
err = devm_request_threaded_irq(dev, client->irq,
NULL, lm90_irq_thread,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"lm90", client);
if (err < 0) {
dev_err(dev, "cannot request IRQ %d\n", client->irq);
return err;
}
}
return 0;
}
static void lm90_alert(struct i2c_client *client, enum i2c_alert_protocol type,
unsigned int flag)
{
u16 alarms;
if (type != I2C_PROTOCOL_SMBUS_ALERT)
return;
if (lm90_is_tripped(client, &alarms)) {
struct lm90_data *data = i2c_get_clientdata(client);
if ((data->flags & LM90_HAVE_BROKEN_ALERT) &&
(alarms & data->alert_alarms)) {
int config;
dev_dbg(&client->dev, "Disabling ALERT#\n");
config = lm90_read_reg(client, LM90_REG_R_CONFIG1);
if (config >= 0)
i2c_smbus_write_byte_data(client,
LM90_REG_W_CONFIG1,
config | 0x80);
}
} else {
dev_info(&client->dev, "Everything OK\n");
}
}
