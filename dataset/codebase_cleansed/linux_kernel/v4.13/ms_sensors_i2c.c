int ms_sensors_reset(void *cli, u8 cmd, unsigned int delay)
{
int ret;
struct i2c_client *client = cli;
ret = i2c_smbus_write_byte(client, cmd);
if (ret) {
dev_err(&client->dev, "Failed to reset device\n");
return ret;
}
usleep_range(delay, delay + 1000);
return 0;
}
int ms_sensors_read_prom_word(void *cli, int cmd, u16 *word)
{
int ret;
struct i2c_client *client = cli;
ret = i2c_smbus_read_word_swapped(client, cmd);
if (ret < 0) {
dev_err(&client->dev, "Failed to read prom word\n");
return ret;
}
*word = ret;
return 0;
}
int ms_sensors_convert_and_read(void *cli, u8 conv, u8 rd,
unsigned int delay, u32 *adc)
{
int ret;
__be32 buf = 0;
struct i2c_client *client = cli;
ret = i2c_smbus_write_byte(client, conv);
if (ret)
goto err;
usleep_range(delay, delay + 1000);
if (rd != MS_SENSORS_NO_READ_CMD)
ret = i2c_smbus_read_i2c_block_data(client, rd, 3, (u8 *)&buf);
else
ret = i2c_master_recv(client, (u8 *)&buf, 3);
if (ret < 0)
goto err;
dev_dbg(&client->dev, "ADC raw value : %x\n", be32_to_cpu(buf) >> 8);
*adc = be32_to_cpu(buf) >> 8;
return 0;
err:
dev_err(&client->dev, "Unable to make sensor adc conversion\n");
return ret;
}
static bool ms_sensors_crc_valid(u32 value)
{
u32 polynom = 0x988000;
u32 msb = 0x800000;
u32 mask = 0xFF8000;
u32 result = value & 0xFFFF00;
u8 crc = value & 0xFF;
while (msb != 0x80) {
if (result & msb)
result = ((result ^ polynom) & mask)
| (result & ~mask);
msb >>= 1;
mask >>= 1;
polynom >>= 1;
}
return result == crc;
}
int ms_sensors_read_serial(struct i2c_client *client, u64 *sn)
{
u8 i;
__be64 rcv_buf = 0;
u64 rcv_val;
__be16 send_buf;
int ret;
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.flags = client->flags,
.len = 2,
.buf = (__u8 *)&send_buf,
},
{
.addr = client->addr,
.flags = client->flags | I2C_M_RD,
.buf = (__u8 *)&rcv_buf,
},
};
send_buf = cpu_to_be16(MS_SENSORS_SERIAL_READ_MSB);
msg[1].len = 8;
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0) {
dev_err(&client->dev, "Unable to read device serial number");
return ret;
}
rcv_val = be64_to_cpu(rcv_buf);
dev_dbg(&client->dev, "Serial MSB raw : %llx\n", rcv_val);
for (i = 0; i < 64; i += 16) {
if (!ms_sensors_crc_valid((rcv_val >> i) & 0xFFFF))
return -ENODEV;
}
*sn = (((rcv_val >> 32) & 0xFF000000) |
((rcv_val >> 24) & 0x00FF0000) |
((rcv_val >> 16) & 0x0000FF00) |
((rcv_val >> 8) & 0x000000FF)) << 16;
send_buf = cpu_to_be16(MS_SENSORS_SERIAL_READ_LSB);
msg[1].len = 6;
rcv_buf = 0;
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0) {
dev_err(&client->dev, "Unable to read device serial number");
return ret;
}
rcv_val = be64_to_cpu(rcv_buf) >> 16;
dev_dbg(&client->dev, "Serial MSB raw : %llx\n", rcv_val);
for (i = 0; i < 48; i += 24) {
if (!ms_sensors_crc_valid((rcv_val >> i) & 0xFFFFFF))
return -ENODEV;
}
*sn |= (rcv_val & 0xFFFF00) << 40 | (rcv_val >> 32);
return 0;
}
static int ms_sensors_read_config_reg(struct i2c_client *client,
u8 *config_reg)
{
int ret;
ret = i2c_smbus_write_byte(client, MS_SENSORS_CONFIG_REG_READ);
if (ret) {
dev_err(&client->dev, "Unable to read config register");
return ret;
}
ret = i2c_master_recv(client, config_reg, 1);
if (ret < 0) {
dev_err(&client->dev, "Unable to read config register");
return ret;
}
dev_dbg(&client->dev, "Config register :%x\n", *config_reg);
return 0;
}
ssize_t ms_sensors_write_resolution(struct ms_ht_dev *dev_data,
u8 i)
{
u8 config_reg;
int ret;
ret = ms_sensors_read_config_reg(dev_data->client, &config_reg);
if (ret)
return ret;
config_reg &= 0x7E;
config_reg |= ((i & 1) << 7) + ((i & 2) >> 1);
return i2c_smbus_write_byte_data(dev_data->client,
MS_SENSORS_CONFIG_REG_WRITE,
config_reg);
}
ssize_t ms_sensors_show_battery_low(struct ms_ht_dev *dev_data,
char *buf)
{
int ret;
u8 config_reg;
mutex_lock(&dev_data->lock);
ret = ms_sensors_read_config_reg(dev_data->client, &config_reg);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
return sprintf(buf, "%d\n", (config_reg & 0x40) >> 6);
}
ssize_t ms_sensors_show_heater(struct ms_ht_dev *dev_data,
char *buf)
{
u8 config_reg;
int ret;
mutex_lock(&dev_data->lock);
ret = ms_sensors_read_config_reg(dev_data->client, &config_reg);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
return sprintf(buf, "%d\n", (config_reg & 0x4) >> 2);
}
ssize_t ms_sensors_write_heater(struct ms_ht_dev *dev_data,
const char *buf, size_t len)
{
u8 val, config_reg;
int ret;
ret = kstrtou8(buf, 10, &val);
if (ret)
return ret;
if (val > 1)
return -EINVAL;
mutex_lock(&dev_data->lock);
ret = ms_sensors_read_config_reg(dev_data->client, &config_reg);
if (ret) {
mutex_unlock(&dev_data->lock);
return ret;
}
config_reg &= 0xFB;
config_reg |= val << 2;
ret = i2c_smbus_write_byte_data(dev_data->client,
MS_SENSORS_CONFIG_REG_WRITE,
config_reg);
mutex_unlock(&dev_data->lock);
if (ret) {
dev_err(&dev_data->client->dev, "Unable to write config register\n");
return ret;
}
return len;
}
int ms_sensors_ht_read_temperature(struct ms_ht_dev *dev_data,
s32 *temperature)
{
int ret;
u32 adc;
u16 delay;
mutex_lock(&dev_data->lock);
delay = ms_sensors_ht_t_conversion_time[dev_data->res_index];
ret = ms_sensors_convert_and_read(dev_data->client,
MS_SENSORS_HT_T_CONVERSION_START,
MS_SENSORS_NO_READ_CMD,
delay, &adc);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
if (!ms_sensors_crc_valid(adc)) {
dev_err(&dev_data->client->dev,
"Temperature read crc check error\n");
return -ENODEV;
}
*temperature = (((s64)(adc >> 8) * 175720) >> 16) - 46850;
return 0;
}
int ms_sensors_ht_read_humidity(struct ms_ht_dev *dev_data,
u32 *humidity)
{
int ret;
u32 adc;
u16 delay;
mutex_lock(&dev_data->lock);
delay = ms_sensors_ht_h_conversion_time[dev_data->res_index];
ret = ms_sensors_convert_and_read(dev_data->client,
MS_SENSORS_HT_H_CONVERSION_START,
MS_SENSORS_NO_READ_CMD,
delay, &adc);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
if (!ms_sensors_crc_valid(adc)) {
dev_err(&dev_data->client->dev,
"Humidity read crc check error\n");
return -ENODEV;
}
*humidity = (((s32)(adc >> 8) * 12500) >> 16) * 10 - 6000;
if (*humidity >= 100000)
*humidity = 100000;
return 0;
}
static bool ms_sensors_tp_crc_valid(u16 *prom, u8 len)
{
unsigned int cnt, n_bit;
u16 n_rem = 0x0000, crc_read = prom[0], crc = (*prom & 0xF000) >> 12;
prom[len - 1] = 0;
prom[0] &= 0x0FFF;
for (cnt = 0; cnt < len * 2; cnt++) {
if (cnt % 2 == 1)
n_rem ^= prom[cnt >> 1] & 0x00FF;
else
n_rem ^= prom[cnt >> 1] >> 8;
for (n_bit = 8; n_bit > 0; n_bit--) {
if (n_rem & 0x8000)
n_rem = (n_rem << 1) ^ 0x3000;
else
n_rem <<= 1;
}
}
n_rem >>= 12;
prom[0] = crc_read;
return n_rem == crc;
}
int ms_sensors_tp_read_prom(struct ms_tp_dev *dev_data)
{
int i, ret;
for (i = 0; i < MS_SENSORS_TP_PROM_WORDS_NB; i++) {
ret = ms_sensors_read_prom_word(
dev_data->client,
MS_SENSORS_TP_PROM_READ + (i << 1),
&dev_data->prom[i]);
if (ret)
return ret;
}
if (!ms_sensors_tp_crc_valid(dev_data->prom,
MS_SENSORS_TP_PROM_WORDS_NB + 1)) {
dev_err(&dev_data->client->dev,
"Calibration coefficients crc check error\n");
return -ENODEV;
}
return 0;
}
int ms_sensors_read_temp_and_pressure(struct ms_tp_dev *dev_data,
int *temperature,
unsigned int *pressure)
{
int ret;
u32 t_adc, p_adc;
s32 dt, temp;
s64 off, sens, t2, off2, sens2;
u16 *prom = dev_data->prom, delay;
mutex_lock(&dev_data->lock);
delay = ms_sensors_tp_conversion_time[dev_data->res_index];
ret = ms_sensors_convert_and_read(
dev_data->client,
MS_SENSORS_TP_T_CONVERSION_START +
dev_data->res_index * 2,
MS_SENSORS_TP_ADC_READ,
delay, &t_adc);
if (ret) {
mutex_unlock(&dev_data->lock);
return ret;
}
ret = ms_sensors_convert_and_read(
dev_data->client,
MS_SENSORS_TP_P_CONVERSION_START +
dev_data->res_index * 2,
MS_SENSORS_TP_ADC_READ,
delay, &p_adc);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
dt = (s32)t_adc - (prom[5] << 8);
temp = 2000 + (((s64)dt * prom[6]) >> 23);
if (temp < 2000) {
s64 tmp = (s64)temp - 2000;
t2 = (3 * ((s64)dt * (s64)dt)) >> 33;
off2 = (61 * tmp * tmp) >> 4;
sens2 = (29 * tmp * tmp) >> 4;
if (temp < -1500) {
s64 tmp = (s64)temp + 1500;
off2 += 17 * tmp * tmp;
sens2 += 9 * tmp * tmp;
}
} else {
t2 = (5 * ((s64)dt * (s64)dt)) >> 38;
off2 = 0;
sens2 = 0;
}
off = (((s64)prom[2]) << 17) + ((((s64)prom[4]) * (s64)dt) >> 6);
off -= off2;
sens = (((s64)prom[1]) << 16) + (((s64)prom[3] * dt) >> 7);
sens -= sens2;
*temperature = (temp - t2) * 10;
*pressure = (u32)(((((s64)p_adc * sens) >> 21) - off) >> 15);
return 0;
}
