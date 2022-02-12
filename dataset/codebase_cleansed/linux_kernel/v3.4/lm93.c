static int LM93_VID_FROM_REG(u8 reg)
{
return vid_from_reg((reg & 0x3f), 100);
}
static unsigned LM93_IN_FROM_REG(int nr, u8 reg)
{
const long uV_max = lm93_vin_val_max[nr] * 1000;
const long uV_min = lm93_vin_val_min[nr] * 1000;
const long slope = (uV_max - uV_min) /
(lm93_vin_reg_max[nr] - lm93_vin_reg_min[nr]);
const long intercept = uV_min - slope * lm93_vin_reg_min[nr];
return (slope * reg + intercept + 500) / 1000;
}
static u8 LM93_IN_TO_REG(int nr, unsigned val)
{
const long mV = SENSORS_LIMIT(val,
lm93_vin_val_min[nr], lm93_vin_val_max[nr]);
const long uV = mV * 1000;
const long uV_max = lm93_vin_val_max[nr] * 1000;
const long uV_min = lm93_vin_val_min[nr] * 1000;
const long slope = (uV_max - uV_min) /
(lm93_vin_reg_max[nr] - lm93_vin_reg_min[nr]);
const long intercept = uV_min - slope * lm93_vin_reg_min[nr];
u8 result = ((uV - intercept + (slope/2)) / slope);
result = SENSORS_LIMIT(result,
lm93_vin_reg_min[nr], lm93_vin_reg_max[nr]);
return result;
}
static unsigned LM93_IN_REL_FROM_REG(u8 reg, int upper, int vid)
{
const long uV_offset = upper ? (((reg >> 4 & 0x0f) + 1) * 12500) :
(((reg >> 0 & 0x0f) + 1) * -25000);
const long uV_vid = vid * 1000;
return (uV_vid + uV_offset + 5000) / 10000;
}
static u8 LM93_IN_REL_TO_REG(unsigned val, int upper, int vid)
{
long uV_offset = vid * 1000 - val * 10000;
if (upper) {
uV_offset = SENSORS_LIMIT(uV_offset, 12500, 200000);
return (u8)((uV_offset / 12500 - 1) << 4);
} else {
uV_offset = SENSORS_LIMIT(uV_offset, -400000, -25000);
return (u8)((uV_offset / -25000 - 1) << 0);
}
}
static int LM93_TEMP_FROM_REG(u8 reg)
{
return (s8)reg * 1000;
}
static u8 LM93_TEMP_TO_REG(long temp)
{
int ntemp = SENSORS_LIMIT(temp, LM93_TEMP_MIN, LM93_TEMP_MAX);
ntemp += (ntemp < 0 ? -500 : 500);
return (u8)(ntemp / 1000);
}
static int LM93_TEMP_OFFSET_MODE_FROM_REG(u8 sfc2, int nr)
{
return sfc2 & (nr < 2 ? 0x10 : 0x20);
}
static int LM93_TEMP_OFFSET_FROM_REG(u8 reg, int mode)
{
return (reg & 0x0f) * (mode ? 5 : 10);
}
static u8 LM93_TEMP_OFFSET_TO_REG(int off, int mode)
{
int factor = mode ? 5 : 10;
off = SENSORS_LIMIT(off, LM93_TEMP_OFFSET_MIN,
mode ? LM93_TEMP_OFFSET_MAX1 : LM93_TEMP_OFFSET_MAX0);
return (u8)((off + factor/2) / factor);
}
static int LM93_TEMP_AUTO_OFFSET_FROM_REG(u8 reg, int nr, int mode)
{
if (nr < 2)
return LM93_TEMP_OFFSET_FROM_REG(reg & 0x0f, mode);
else
return LM93_TEMP_OFFSET_FROM_REG(reg >> 4 & 0x0f, mode);
}
static u8 LM93_TEMP_AUTO_OFFSET_TO_REG(u8 old, int off, int nr, int mode)
{
u8 new = LM93_TEMP_OFFSET_TO_REG(off, mode);
if (nr < 2)
return (old & 0xf0) | (new & 0x0f);
else
return (new << 4 & 0xf0) | (old & 0x0f);
}
static int LM93_AUTO_BOOST_HYST_FROM_REGS(struct lm93_data *data, int nr,
int mode)
{
u8 reg;
switch (nr) {
case 0:
reg = data->boost_hyst[0] & 0x0f;
break;
case 1:
reg = data->boost_hyst[0] >> 4 & 0x0f;
break;
case 2:
reg = data->boost_hyst[1] & 0x0f;
break;
case 3:
default:
reg = data->boost_hyst[1] >> 4 & 0x0f;
break;
}
return LM93_TEMP_FROM_REG(data->boost[nr]) -
LM93_TEMP_OFFSET_FROM_REG(reg, mode);
}
static u8 LM93_AUTO_BOOST_HYST_TO_REG(struct lm93_data *data, long hyst,
int nr, int mode)
{
u8 reg = LM93_TEMP_OFFSET_TO_REG(
(LM93_TEMP_FROM_REG(data->boost[nr]) - hyst), mode);
switch (nr) {
case 0:
reg = (data->boost_hyst[0] & 0xf0) | (reg & 0x0f);
break;
case 1:
reg = (reg << 4 & 0xf0) | (data->boost_hyst[0] & 0x0f);
break;
case 2:
reg = (data->boost_hyst[1] & 0xf0) | (reg & 0x0f);
break;
case 3:
default:
reg = (reg << 4 & 0xf0) | (data->boost_hyst[1] & 0x0f);
break;
}
return reg;
}
static int LM93_PWM_FROM_REG(u8 reg, enum pwm_freq freq)
{
return lm93_pwm_map[freq][reg & 0x0f];
}
static u8 LM93_PWM_TO_REG(int pwm, enum pwm_freq freq)
{
int i;
for (i = 0; i < 13; i++)
if (pwm <= lm93_pwm_map[freq][i])
break;
return (u8)i;
}
static int LM93_FAN_FROM_REG(u16 regs)
{
const u16 count = le16_to_cpu(regs) >> 2;
return count == 0 ? -1 : count == 0x3fff ? 0 : 1350000 / count;
}
static u16 LM93_FAN_TO_REG(long rpm)
{
u16 count, regs;
if (rpm == 0) {
count = 0x3fff;
} else {
rpm = SENSORS_LIMIT(rpm, 1, 1000000);
count = SENSORS_LIMIT((1350000 + rpm) / rpm, 1, 0x3ffe);
}
regs = count << 2;
return cpu_to_le16(regs);
}
static int LM93_PWM_FREQ_FROM_REG(u8 reg)
{
return lm93_pwm_freq_map[reg & 0x07];
}
static u8 LM93_PWM_FREQ_TO_REG(int freq)
{
int i;
for (i = 7; i > 0; i--)
if (freq <= lm93_pwm_freq_map[i])
break;
return (u8)i;
}
static int LM93_SPINUP_TIME_FROM_REG(u8 reg)
{
return lm93_spinup_time_map[reg >> 5 & 0x07];
}
static u8 LM93_SPINUP_TIME_TO_REG(int time)
{
int i;
for (i = 0; i < 7; i++)
if (time <= lm93_spinup_time_map[i])
break;
return (u8)i;
}
static int LM93_RAMP_FROM_REG(u8 reg)
{
return (reg & 0x0f) * 5;
}
static u8 LM93_RAMP_TO_REG(int ramp)
{
ramp = SENSORS_LIMIT(ramp, LM93_RAMP_MIN, LM93_RAMP_MAX);
return (u8)((ramp + 2) / 5);
}
static u8 LM93_PROCHOT_TO_REG(long prochot)
{
prochot = SENSORS_LIMIT(prochot, 0, 255);
return (u8)prochot;
}
static int LM93_INTERVAL_FROM_REG(u8 reg)
{
return lm93_interval_map[reg & 0x0f];
}
static u8 LM93_INTERVAL_TO_REG(long interval)
{
int i;
for (i = 0; i < 9; i++)
if (interval <= lm93_interval_map[i])
break;
return (u8)i;
}
static unsigned LM93_GPI_FROM_REG(u8 reg)
{
return ~reg & 0xff;
}
static unsigned LM93_ALARMS_FROM_REG(struct block1_t b1)
{
unsigned result;
result = b1.host_status_2 & 0x3f;
if (vccp_limit_type[0])
result |= (b1.host_status_4 & 0x10) << 2;
else
result |= b1.host_status_2 & 0x40;
if (vccp_limit_type[1])
result |= (b1.host_status_4 & 0x20) << 2;
else
result |= b1.host_status_2 & 0x80;
result |= b1.host_status_3 << 8;
result |= (b1.fan_status & 0x0f) << 16;
result |= (b1.p1_prochot_status & 0x80) << 13;
result |= (b1.p2_prochot_status & 0x80) << 14;
result |= (b1.host_status_4 & 0xfc) << 20;
result |= (b1.host_status_1 & 0x07) << 28;
return result;
}
static u8 lm93_read_byte(struct i2c_client *client, u8 reg)
{
int value, i;
for (i = 1; i <= MAX_RETRIES; i++) {
value = i2c_smbus_read_byte_data(client, reg);
if (value >= 0) {
return value;
} else {
dev_warn(&client->dev, "lm93: read byte data failed, "
"address 0x%02x.\n", reg);
mdelay(i + 3);
}
}
dev_err(&client->dev, "lm93: All read byte retries failed!!\n");
return 0;
}
static int lm93_write_byte(struct i2c_client *client, u8 reg, u8 value)
{
int result;
result = i2c_smbus_write_byte_data(client, reg, value);
if (result < 0)
dev_warn(&client->dev, "lm93: write byte data failed, "
"0x%02x at address 0x%02x.\n", value, reg);
return result;
}
static u16 lm93_read_word(struct i2c_client *client, u8 reg)
{
int value, i;
for (i = 1; i <= MAX_RETRIES; i++) {
value = i2c_smbus_read_word_data(client, reg);
if (value >= 0) {
return value;
} else {
dev_warn(&client->dev, "lm93: read word data failed, "
"address 0x%02x.\n", reg);
mdelay(i + 3);
}
}
dev_err(&client->dev, "lm93: All read word retries failed!!\n");
return 0;
}
static int lm93_write_word(struct i2c_client *client, u8 reg, u16 value)
{
int result;
result = i2c_smbus_write_word_data(client, reg, value);
if (result < 0)
dev_warn(&client->dev, "lm93: write word data failed, "
"0x%04x at address 0x%02x.\n", value, reg);
return result;
}
static void lm93_read_block(struct i2c_client *client, u8 fbn, u8 *values)
{
int i, result = 0;
for (i = 1; i <= MAX_RETRIES; i++) {
result = i2c_smbus_read_block_data(client,
lm93_block_read_cmds[fbn].cmd, lm93_block_buffer);
if (result == lm93_block_read_cmds[fbn].len) {
break;
} else {
dev_warn(&client->dev, "lm93: block read data failed, "
"command 0x%02x.\n",
lm93_block_read_cmds[fbn].cmd);
mdelay(i + 3);
}
}
if (result == lm93_block_read_cmds[fbn].len) {
memcpy(values, lm93_block_buffer,
lm93_block_read_cmds[fbn].len);
} else {
}
}
static struct lm93_data *lm93_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
const unsigned long interval = HZ + (HZ / 2);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + interval) ||
!data->valid) {
data->update(data, client);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static void lm93_update_client_common(struct lm93_data *data,
struct i2c_client *client)
{
int i;
u8 *ptr;
for (i = 0; i < 4; i++) {
data->temp_lim[i].min =
lm93_read_byte(client, LM93_REG_TEMP_MIN(i));
data->temp_lim[i].max =
lm93_read_byte(client, LM93_REG_TEMP_MAX(i));
}
data->config = lm93_read_byte(client, LM93_REG_CONFIG);
for (i = 0; i < 2; i++)
data->vid[i] = lm93_read_byte(client, LM93_REG_VID(i));
for (i = 0; i < 2; i++)
data->prochot_max[i] = lm93_read_byte(client,
LM93_REG_PROCHOT_MAX(i));
for (i = 0; i < 2; i++)
data->vccp_limits[i] = lm93_read_byte(client,
LM93_REG_VCCP_LIMIT_OFF(i));
data->gpi = lm93_read_byte(client, LM93_REG_GPI);
data->prochot_override = lm93_read_byte(client,
LM93_REG_PROCHOT_OVERRIDE);
data->prochot_interval = lm93_read_byte(client,
LM93_REG_PROCHOT_INTERVAL);
for (i = 0; i < 4; i++)
data->boost[i] = lm93_read_byte(client, LM93_REG_BOOST(i));
data->boost_hyst[0] = lm93_read_byte(client, LM93_REG_BOOST_HYST_12);
data->boost_hyst[1] = lm93_read_byte(client, LM93_REG_BOOST_HYST_34);
data->auto_pwm_min_hyst[0] =
lm93_read_byte(client, LM93_REG_PWM_MIN_HYST_12);
data->auto_pwm_min_hyst[1] =
lm93_read_byte(client, LM93_REG_PWM_MIN_HYST_34);
data->pwm_ramp_ctl = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);
data->sfc1 = lm93_read_byte(client, LM93_REG_SFC1);
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
data->sf_tach_to_pwm = lm93_read_byte(client,
LM93_REG_SF_TACH_TO_PWM);
for (i = 0, ptr = (u8 *)(&data->block1); i < 8; i++)
lm93_write_byte(client, LM93_REG_HOST_ERROR_1 + i, *(ptr + i));
}
static void lm93_update_client_full(struct lm93_data *data,
struct i2c_client *client)
{
dev_dbg(&client->dev, "starting device update (block data enabled)\n");
lm93_read_block(client, 3, (u8 *)(data->block3));
lm93_read_block(client, 7, (u8 *)(data->block7));
lm93_read_block(client, 2, (u8 *)(data->block2));
lm93_read_block(client, 4, (u8 *)(data->block4));
lm93_read_block(client, 5, (u8 *)(data->block5));
lm93_read_block(client, 8, (u8 *)(data->block8));
lm93_read_block(client, 9, (u8 *)(data->block9));
lm93_read_block(client, 1, (u8 *)(&data->block1));
lm93_read_block(client, 10, (u8 *)(&data->block10));
lm93_update_client_common(data, client);
}
static void lm93_update_client_min(struct lm93_data *data,
struct i2c_client *client)
{
int i, j;
u8 *ptr;
dev_dbg(&client->dev, "starting device update (block data disabled)\n");
for (i = 0; i < 16; i++) {
data->block3[i] =
lm93_read_byte(client, LM93_REG_IN(i));
data->block7[i].min =
lm93_read_byte(client, LM93_REG_IN_MIN(i));
data->block7[i].max =
lm93_read_byte(client, LM93_REG_IN_MAX(i));
}
for (i = 0; i < 4; i++) {
data->block2[i] =
lm93_read_byte(client, LM93_REG_TEMP(i));
}
for (i = 0; i < 2; i++) {
data->block4[i].cur =
lm93_read_byte(client, LM93_REG_PROCHOT_CUR(i));
data->block4[i].avg =
lm93_read_byte(client, LM93_REG_PROCHOT_AVG(i));
}
for (i = 0; i < 4; i++) {
data->block5[i] =
lm93_read_word(client, LM93_REG_FAN(i));
data->block8[i] =
lm93_read_word(client, LM93_REG_FAN_MIN(i));
}
for (i = 0; i < 2; i++) {
for (j = 0; j < 4; j++) {
data->block9[i][j] =
lm93_read_byte(client, LM93_REG_PWM_CTL(i, j));
}
}
for (i = 0, ptr = (u8 *)(&data->block1); i < 8; i++) {
*(ptr + i) =
lm93_read_byte(client, LM93_REG_HOST_ERROR_1 + i);
}
for (i = 0; i < 4; i++) {
data->block10.base[i] =
lm93_read_byte(client, LM93_REG_TEMP_BASE(i));
}
for (i = 0; i < 12; i++) {
data->block10.offset[i] =
lm93_read_byte(client, LM93_REG_TEMP_OFFSET(i));
}
lm93_update_client_common(data, client);
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_IN_FROM_REG(nr, data->block3[nr]));
}
static ssize_t show_in_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
int vccp = nr - 6;
long rc, vid;
if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
vid = LM93_VID_FROM_REG(data->vid[vccp]);
rc = LM93_IN_MIN_FROM_REG(data->vccp_limits[vccp], vid);
} else {
rc = LM93_IN_FROM_REG(nr, data->block7[nr].min);
}
return sprintf(buf, "%ld\n", rc);
}
static ssize_t store_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
int vccp = nr - 6;
long vid;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
vid = LM93_VID_FROM_REG(data->vid[vccp]);
data->vccp_limits[vccp] = (data->vccp_limits[vccp] & 0xf0) |
LM93_IN_REL_TO_REG(val, 0, vid);
lm93_write_byte(client, LM93_REG_VCCP_LIMIT_OFF(vccp),
data->vccp_limits[vccp]);
} else {
data->block7[nr].min = LM93_IN_TO_REG(nr, val);
lm93_write_byte(client, LM93_REG_IN_MIN(nr),
data->block7[nr].min);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
int vccp = nr - 6;
long rc, vid;
if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
vid = LM93_VID_FROM_REG(data->vid[vccp]);
rc = LM93_IN_MAX_FROM_REG(data->vccp_limits[vccp], vid);
} else {
rc = LM93_IN_FROM_REG(nr, data->block7[nr].max);
}
return sprintf(buf, "%ld\n", rc);
}
static ssize_t store_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
int vccp = nr - 6;
long vid;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if ((nr == 6 || nr == 7) && vccp_limit_type[vccp]) {
vid = LM93_VID_FROM_REG(data->vid[vccp]);
data->vccp_limits[vccp] = (data->vccp_limits[vccp] & 0x0f) |
LM93_IN_REL_TO_REG(val, 1, vid);
lm93_write_byte(client, LM93_REG_VCCP_LIMIT_OFF(vccp),
data->vccp_limits[vccp]);
} else {
data->block7[nr].max = LM93_IN_TO_REG(nr, val);
lm93_write_byte(client, LM93_REG_IN_MAX(nr),
data->block7[nr].max);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->block2[nr]));
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->temp_lim[nr].min));
}
static ssize_t store_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_lim[nr].min = LM93_TEMP_TO_REG(val);
lm93_write_byte(client, LM93_REG_TEMP_MIN(nr), data->temp_lim[nr].min);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->temp_lim[nr].max));
}
static ssize_t store_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_lim[nr].max = LM93_TEMP_TO_REG(val);
lm93_write_byte(client, LM93_REG_TEMP_MAX(nr), data->temp_lim[nr].max);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_base(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->block10.base[nr]));
}
static ssize_t store_temp_auto_base(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->block10.base[nr] = LM93_TEMP_TO_REG(val);
lm93_write_byte(client, LM93_REG_TEMP_BASE(nr), data->block10.base[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_boost(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_TEMP_FROM_REG(data->boost[nr]));
}
static ssize_t store_temp_auto_boost(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->boost[nr] = LM93_TEMP_TO_REG(val);
lm93_write_byte(client, LM93_REG_BOOST(nr), data->boost[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_boost_hyst(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
return sprintf(buf, "%d\n",
LM93_AUTO_BOOST_HYST_FROM_REGS(data, nr, mode));
}
static ssize_t store_temp_auto_boost_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
data->boost_hyst[nr/2] = LM93_AUTO_BOOST_HYST_TO_REG(data, val, nr, 1);
lm93_write_byte(client, LM93_REG_BOOST_HYST(nr),
data->boost_hyst[nr/2]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_offset(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *s_attr = to_sensor_dev_attr_2(attr);
int nr = s_attr->index;
int ofs = s_attr->nr;
struct lm93_data *data = lm93_update_device(dev);
int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
return sprintf(buf, "%d\n",
LM93_TEMP_AUTO_OFFSET_FROM_REG(data->block10.offset[ofs],
nr, mode));
}
static ssize_t store_temp_auto_offset(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *s_attr = to_sensor_dev_attr_2(attr);
int nr = s_attr->index;
int ofs = s_attr->nr;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
data->block10.offset[ofs] = LM93_TEMP_AUTO_OFFSET_TO_REG(
data->block10.offset[ofs], val, nr, 1);
lm93_write_byte(client, LM93_REG_TEMP_OFFSET(ofs),
data->block10.offset[ofs]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_pwm_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
u8 reg, ctl4;
struct lm93_data *data = lm93_update_device(dev);
reg = data->auto_pwm_min_hyst[nr/2] >> 4 & 0x0f;
ctl4 = data->block9[nr][LM93_PWM_CTL4];
return sprintf(buf, "%d\n", LM93_PWM_FROM_REG(reg, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ));
}
static ssize_t store_temp_auto_pwm_min(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 reg, ctl4;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
reg = lm93_read_byte(client, LM93_REG_PWM_MIN_HYST(nr));
ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
reg = (reg & 0x0f) |
LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ :
LM93_PWM_MAP_HI_FREQ) << 4;
data->auto_pwm_min_hyst[nr/2] = reg;
lm93_write_byte(client, LM93_REG_PWM_MIN_HYST(nr), reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_offset_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
int mode = LM93_TEMP_OFFSET_MODE_FROM_REG(data->sfc2, nr);
return sprintf(buf, "%d\n", LM93_TEMP_OFFSET_FROM_REG(
data->auto_pwm_min_hyst[nr / 2], mode));
}
static ssize_t store_temp_auto_offset_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
data->sfc2 |= ((nr < 2) ? 0x10 : 0x20);
lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
reg = data->auto_pwm_min_hyst[nr/2];
reg = (reg & 0xf0) | (LM93_TEMP_OFFSET_TO_REG(val, 1) & 0x0f);
data->auto_pwm_min_hyst[nr/2] = reg;
lm93_write_byte(client, LM93_REG_PWM_MIN_HYST(nr), reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *s_attr = to_sensor_dev_attr(attr);
int nr = s_attr->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_FAN_FROM_REG(data->block5[nr]));
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_FAN_FROM_REG(data->block8[nr]));
}
static ssize_t store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->block8[nr] = LM93_FAN_TO_REG(val);
lm93_write_word(client, LM93_REG_FAN_MIN(nr), data->block8[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_smart_tach(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
long rc = 0;
int mapping;
mapping = (data->sf_tach_to_pwm >> (nr * 2)) & 0x03;
if (mapping && ((data->sfc2 >> nr) & 0x01))
rc = mapping;
return sprintf(buf, "%ld\n", rc);
}
static void lm93_write_fan_smart_tach(struct i2c_client *client,
struct lm93_data *data, int fan, long value)
{
data->sf_tach_to_pwm = lm93_read_byte(client, LM93_REG_SF_TACH_TO_PWM);
data->sf_tach_to_pwm &= ~(0x3 << fan * 2);
data->sf_tach_to_pwm |= value << fan * 2;
lm93_write_byte(client, LM93_REG_SF_TACH_TO_PWM, data->sf_tach_to_pwm);
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
if (value)
data->sfc2 |= 1 << fan;
else
data->sfc2 &= ~(1 << fan);
lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
}
static ssize_t store_fan_smart_tach(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (0 <= val && val <= 2) {
if (val) {
u8 ctl4 = lm93_read_byte(client,
LM93_REG_PWM_CTL(val - 1, LM93_PWM_CTL4));
if ((ctl4 & 0x07) == 0)
val = 0;
}
lm93_write_fan_smart_tach(client, data, nr, val);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
u8 ctl2, ctl4;
long rc;
ctl2 = data->block9[nr][LM93_PWM_CTL2];
ctl4 = data->block9[nr][LM93_PWM_CTL4];
if (ctl2 & 0x01)
rc = data->pwm_override[nr];
else
rc = LM93_PWM_FROM_REG(ctl2 >> 4, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ);
return sprintf(buf, "%ld\n", rc);
}
static ssize_t store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ctl2, ctl4;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ctl2 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2));
ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
ctl2 = (ctl2 & 0x0f) | LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ) << 4;
data->pwm_override[nr] = LM93_PWM_FROM_REG(ctl2 >> 4,
(ctl4 & 0x07) ? LM93_PWM_MAP_LO_FREQ :
LM93_PWM_MAP_HI_FREQ);
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2), ctl2);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
u8 ctl2;
long rc;
ctl2 = data->block9[nr][LM93_PWM_CTL2];
if (ctl2 & 0x01)
rc = ((ctl2 & 0xF0) == 0xF0) ? 0 : 1;
else
rc = 2;
return sprintf(buf, "%ld\n", rc);
}
static ssize_t store_pwm_enable(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ctl2;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ctl2 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2));
switch (val) {
case 0:
ctl2 |= 0xF1;
break;
case 1:
ctl2 |= 0x01;
break;
case 2:
ctl2 &= ~0x01;
break;
default:
mutex_unlock(&data->update_lock);
return -EINVAL;
}
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL2), ctl2);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_freq(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
u8 ctl4;
ctl4 = data->block9[nr][LM93_PWM_CTL4];
return sprintf(buf, "%d\n", LM93_PWM_FREQ_FROM_REG(ctl4));
}
static void lm93_disable_fan_smart_tach(struct i2c_client *client,
struct lm93_data *data, int pwm)
{
int mapping = lm93_read_byte(client, LM93_REG_SF_TACH_TO_PWM);
int mask;
mapping = (mapping >> pwm) & 0x55;
mask = mapping & 0x01;
mask |= (mapping & 0x04) >> 1;
mask |= (mapping & 0x10) >> 2;
mask |= (mapping & 0x40) >> 3;
data->sfc2 = lm93_read_byte(client, LM93_REG_SFC2);
data->sfc2 &= ~mask;
lm93_write_byte(client, LM93_REG_SFC2, data->sfc2);
}
static ssize_t store_pwm_freq(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ctl4;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
ctl4 = (ctl4 & 0xf8) | LM93_PWM_FREQ_TO_REG(val);
data->block9[nr][LM93_PWM_CTL4] = ctl4;
if (!ctl4)
lm93_disable_fan_smart_tach(client, data, nr);
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4), ctl4);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_channels(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", data->block9[nr][LM93_PWM_CTL1]);
}
static ssize_t store_pwm_auto_channels(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->block9[nr][LM93_PWM_CTL1] = SENSORS_LIMIT(val, 0, 255);
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL1),
data->block9[nr][LM93_PWM_CTL1]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_spinup_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
u8 ctl3, ctl4;
ctl3 = data->block9[nr][LM93_PWM_CTL3];
ctl4 = data->block9[nr][LM93_PWM_CTL4];
return sprintf(buf, "%d\n",
LM93_PWM_FROM_REG(ctl3 & 0x0f, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ : LM93_PWM_MAP_HI_FREQ));
}
static ssize_t store_pwm_auto_spinup_min(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ctl3, ctl4;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ctl3 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3));
ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
ctl3 = (ctl3 & 0xf0) | LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
LM93_PWM_MAP_LO_FREQ :
LM93_PWM_MAP_HI_FREQ);
data->block9[nr][LM93_PWM_CTL3] = ctl3;
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3), ctl3);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_spinup_time(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_SPINUP_TIME_FROM_REG(
data->block9[nr][LM93_PWM_CTL3]));
}
static ssize_t store_pwm_auto_spinup_time(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ctl3;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ctl3 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3));
ctl3 = (ctl3 & 0x1f) | (LM93_SPINUP_TIME_TO_REG(val) << 5 & 0xe0);
data->block9[nr][LM93_PWM_CTL3] = ctl3;
lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3), ctl3);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_prochot_ramp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n",
LM93_RAMP_FROM_REG(data->pwm_ramp_ctl >> 4 & 0x0f));
}
static ssize_t store_pwm_auto_prochot_ramp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ramp;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ramp = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);
ramp = (ramp & 0x0f) | (LM93_RAMP_TO_REG(val) << 4 & 0xf0);
lm93_write_byte(client, LM93_REG_PWM_RAMP_CTL, ramp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_vrdhot_ramp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n",
LM93_RAMP_FROM_REG(data->pwm_ramp_ctl & 0x0f));
}
static ssize_t store_pwm_auto_vrdhot_ramp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 ramp;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
ramp = lm93_read_byte(client, LM93_REG_PWM_RAMP_CTL);
ramp = (ramp & 0xf0) | (LM93_RAMP_TO_REG(val) & 0x0f);
lm93_write_byte(client, LM93_REG_PWM_RAMP_CTL, ramp);
mutex_unlock(&data->update_lock);
return 0;
}
static ssize_t show_vid(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_VID_FROM_REG(data->vid[nr]));
}
static ssize_t show_prochot(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", data->block4[nr].cur);
}
static ssize_t show_prochot_avg(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", data->block4[nr].avg);
}
static ssize_t show_prochot_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", data->prochot_max[nr]);
}
static ssize_t store_prochot_max(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->prochot_max[nr] = LM93_PROCHOT_TO_REG(val);
lm93_write_byte(client, LM93_REG_PROCHOT_MAX(nr),
data->prochot_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_prochot_override(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n",
(data->prochot_override & prochot_override_mask[nr]) ? 1 : 0);
}
static ssize_t store_prochot_override(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (val)
data->prochot_override |= prochot_override_mask[nr];
else
data->prochot_override &= (~prochot_override_mask[nr]);
lm93_write_byte(client, LM93_REG_PROCHOT_OVERRIDE,
data->prochot_override);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_prochot_interval(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
u8 tmp;
if (nr == 1)
tmp = (data->prochot_interval & 0xf0) >> 4;
else
tmp = data->prochot_interval & 0x0f;
return sprintf(buf, "%d\n", LM93_INTERVAL_FROM_REG(tmp));
}
static ssize_t store_prochot_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
u8 tmp;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
tmp = lm93_read_byte(client, LM93_REG_PROCHOT_INTERVAL);
if (nr == 1)
tmp = (tmp & 0x0f) | (LM93_INTERVAL_TO_REG(val) << 4);
else
tmp = (tmp & 0xf0) | LM93_INTERVAL_TO_REG(val);
data->prochot_interval = tmp;
lm93_write_byte(client, LM93_REG_PROCHOT_INTERVAL, tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_prochot_override_duty_cycle(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", data->prochot_override & 0x0f);
}
static ssize_t store_prochot_override_duty_cycle(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->prochot_override = (data->prochot_override & 0xf0) |
SENSORS_LIMIT(val, 0, 15);
lm93_write_byte(client, LM93_REG_PROCHOT_OVERRIDE,
data->prochot_override);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_prochot_short(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", (data->config & 0x10) ? 1 : 0);
}
static ssize_t store_prochot_short(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm93_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (val)
data->config |= 0x10;
else
data->config &= ~0x10;
lm93_write_byte(client, LM93_REG_CONFIG, data->config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_vrdhot(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = (to_sensor_dev_attr(attr))->index;
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n",
data->block1.host_status_1 & (1 << (nr + 4)) ? 1 : 0);
}
static ssize_t show_gpio(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_GPI_FROM_REG(data->gpi));
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm93_data *data = lm93_update_device(dev);
return sprintf(buf, "%d\n", LM93_ALARMS_FROM_REG(data->block1));
}
static void lm93_init_client(struct i2c_client *client)
{
int i;
u8 reg;
reg = lm93_read_byte(client, LM93_REG_GPI_VID_CTL);
lm93_write_byte(client, LM93_REG_GPI_VID_CTL,
reg | (vid_agtl ? 0x03 : 0x00));
if (init) {
reg = lm93_read_byte(client, LM93_REG_CONFIG);
lm93_write_byte(client, LM93_REG_CONFIG, reg | 0x08);
reg = lm93_read_byte(client, LM93_REG_STATUS_CONTROL);
lm93_write_byte(client, LM93_REG_STATUS_CONTROL, reg | 0x02);
lm93_write_byte(client, LM93_REG_SLEEP_CONTROL, 0);
reg = lm93_read_byte(client, LM93_REG_MISC_ERR_MASK);
reg &= ~0x03;
reg &= ~(vccp_limit_type[0] ? 0x10 : 0);
reg &= ~(vccp_limit_type[1] ? 0x20 : 0);
lm93_write_byte(client, LM93_REG_MISC_ERR_MASK, reg);
}
reg = lm93_read_byte(client, LM93_REG_CONFIG);
lm93_write_byte(client, LM93_REG_CONFIG, reg | 0x01);
for (i = 0; i < 20; i++) {
msleep(10);
if ((lm93_read_byte(client, LM93_REG_CONFIG) & 0x80) == 0x80)
return;
}
dev_warn(&client->dev, "timed out waiting for sensor "
"chip to signal ready!\n");
}
static int lm93_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int mfr, ver;
const char *name;
if (!i2c_check_functionality(adapter, LM93_SMBUS_FUNC_MIN))
return -ENODEV;
mfr = lm93_read_byte(client, LM93_REG_MFR_ID);
if (mfr != 0x01) {
dev_dbg(&adapter->dev,
"detect failed, bad manufacturer id 0x%02x!\n", mfr);
return -ENODEV;
}
ver = lm93_read_byte(client, LM93_REG_VER);
switch (ver) {
case LM93_MFR_ID:
case LM93_MFR_ID_PROTOTYPE:
name = "lm93";
break;
case LM94_MFR_ID_2:
case LM94_MFR_ID:
case LM94_MFR_ID_PROTOTYPE:
name = "lm94";
break;
default:
dev_dbg(&adapter->dev,
"detect failed, bad version id 0x%02x!\n", ver);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
dev_dbg(&adapter->dev, "loading %s at %d, 0x%02x\n",
client->name, i2c_adapter_id(client->adapter),
client->addr);
return 0;
}
static int lm93_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm93_data *data;
int err, func;
void (*update)(struct lm93_data *, struct i2c_client *);
func = i2c_get_functionality(client->adapter);
if (((LM93_SMBUS_FUNC_FULL & func) == LM93_SMBUS_FUNC_FULL) &&
(!disable_block)) {
dev_dbg(&client->dev, "using SMBus block data transactions\n");
update = lm93_update_client_full;
} else if ((LM93_SMBUS_FUNC_MIN & func) == LM93_SMBUS_FUNC_MIN) {
dev_dbg(&client->dev, "disabled SMBus block data "
"transactions\n");
update = lm93_update_client_min;
} else {
dev_dbg(&client->dev, "detect failed, "
"smbus byte and/or word data not supported!\n");
err = -ENODEV;
goto err_out;
}
data = kzalloc(sizeof(struct lm93_data), GFP_KERNEL);
if (!data) {
dev_dbg(&client->dev, "out of memory!\n");
err = -ENOMEM;
goto err_out;
}
i2c_set_clientdata(client, data);
data->valid = 0;
data->update = update;
mutex_init(&data->update_lock);
lm93_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &lm93_attr_grp);
if (err)
goto err_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (!IS_ERR(data->hwmon_dev))
return 0;
err = PTR_ERR(data->hwmon_dev);
dev_err(&client->dev, "error registering hwmon device.\n");
sysfs_remove_group(&client->dev.kobj, &lm93_attr_grp);
err_free:
kfree(data);
err_out:
return err;
}
static int lm93_remove(struct i2c_client *client)
{
struct lm93_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm93_attr_grp);
kfree(data);
return 0;
}
