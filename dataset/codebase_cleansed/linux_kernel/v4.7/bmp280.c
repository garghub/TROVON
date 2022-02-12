static bool bmp280_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMP280_REG_CONFIG:
case BMP280_REG_CTRL_MEAS:
case BMP280_REG_RESET:
return true;
default:
return false;
};
}
static bool bmp280_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMP280_REG_TEMP_XLSB:
case BMP280_REG_TEMP_LSB:
case BMP280_REG_TEMP_MSB:
case BMP280_REG_PRESS_XLSB:
case BMP280_REG_PRESS_LSB:
case BMP280_REG_PRESS_MSB:
case BMP280_REG_STATUS:
return true;
default:
return false;
}
}
static s32 bmp280_compensate_temp(struct bmp280_data *data,
s32 adc_temp)
{
int ret;
s32 var1, var2;
__le16 buf[BMP280_COMP_TEMP_REG_COUNT / 2];
ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_TEMP_START,
buf, BMP280_COMP_TEMP_REG_COUNT);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read temperature calibration parameters\n");
return ret;
}
var1 = (((adc_temp >> 3) - ((s32)le16_to_cpu(buf[T1]) << 1)) *
((s32)(s16)le16_to_cpu(buf[T2]))) >> 11;
var2 = (((((adc_temp >> 4) - ((s32)le16_to_cpu(buf[T1]))) *
((adc_temp >> 4) - ((s32)le16_to_cpu(buf[T1])))) >> 12) *
((s32)(s16)le16_to_cpu(buf[T3]))) >> 14;
data->t_fine = var1 + var2;
return (data->t_fine * 5 + 128) >> 8;
}
static u32 bmp280_compensate_press(struct bmp280_data *data,
s32 adc_press)
{
int ret;
s64 var1, var2, p;
__le16 buf[BMP280_COMP_PRESS_REG_COUNT / 2];
ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_PRESS_START,
buf, BMP280_COMP_PRESS_REG_COUNT);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read pressure calibration parameters\n");
return ret;
}
var1 = ((s64)data->t_fine) - 128000;
var2 = var1 * var1 * (s64)(s16)le16_to_cpu(buf[P6]);
var2 += (var1 * (s64)(s16)le16_to_cpu(buf[P5])) << 17;
var2 += ((s64)(s16)le16_to_cpu(buf[P4])) << 35;
var1 = ((var1 * var1 * (s64)(s16)le16_to_cpu(buf[P3])) >> 8) +
((var1 * (s64)(s16)le16_to_cpu(buf[P2])) << 12);
var1 = ((((s64)1) << 47) + var1) * ((s64)le16_to_cpu(buf[P1])) >> 33;
if (var1 == 0)
return 0;
p = ((((s64)1048576 - adc_press) << 31) - var2) * 3125;
p = div64_s64(p, var1);
var1 = (((s64)(s16)le16_to_cpu(buf[P9])) * (p >> 13) * (p >> 13)) >> 25;
var2 = (((s64)(s16)le16_to_cpu(buf[P8])) * p) >> 19;
p = ((p + var1 + var2) >> 8) + (((s64)(s16)le16_to_cpu(buf[P7])) << 4);
return (u32)p;
}
static int bmp280_read_temp(struct bmp280_data *data,
int *val)
{
int ret;
__be32 tmp = 0;
s32 adc_temp, comp_temp;
ret = regmap_bulk_read(data->regmap, BMP280_REG_TEMP_MSB,
(u8 *) &tmp, 3);
if (ret < 0) {
dev_err(&data->client->dev, "failed to read temperature\n");
return ret;
}
adc_temp = be32_to_cpu(tmp) >> 12;
comp_temp = bmp280_compensate_temp(data, adc_temp);
if (val) {
*val = comp_temp * 10;
return IIO_VAL_INT;
}
return 0;
}
static int bmp280_read_press(struct bmp280_data *data,
int *val, int *val2)
{
int ret;
__be32 tmp = 0;
s32 adc_press;
u32 comp_press;
ret = bmp280_read_temp(data, NULL);
if (ret < 0)
return ret;
ret = regmap_bulk_read(data->regmap, BMP280_REG_PRESS_MSB,
(u8 *) &tmp, 3);
if (ret < 0) {
dev_err(&data->client->dev, "failed to read pressure\n");
return ret;
}
adc_press = be32_to_cpu(tmp) >> 12;
comp_press = bmp280_compensate_press(data, adc_press);
*val = comp_press;
*val2 = 256000;
return IIO_VAL_FRACTIONAL;
}
static int bmp280_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct bmp280_data *data = iio_priv(indio_dev);
mutex_lock(&data->lock);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_PRESSURE:
ret = data->chip_info->read_press(data, val, val2);
break;
case IIO_TEMP:
ret = data->chip_info->read_temp(data, val);
break;
default:
ret = -EINVAL;
break;
}
break;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
switch (chan->type) {
case IIO_PRESSURE:
*val = 1 << data->oversampling_press;
ret = IIO_VAL_INT;
break;
case IIO_TEMP:
*val = 1 << data->oversampling_temp;
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
return ret;
}
static int bmp280_write_oversampling_ratio_temp(struct bmp280_data *data,
int val)
{
int i;
const int *avail = data->chip_info->oversampling_temp_avail;
const int n = data->chip_info->num_oversampling_temp_avail;
for (i = 0; i < n; i++) {
if (avail[i] == val) {
data->oversampling_temp = ilog2(val);
return data->chip_info->chip_config(data);
}
}
return -EINVAL;
}
static int bmp280_write_oversampling_ratio_press(struct bmp280_data *data,
int val)
{
int i;
const int *avail = data->chip_info->oversampling_press_avail;
const int n = data->chip_info->num_oversampling_press_avail;
for (i = 0; i < n; i++) {
if (avail[i] == val) {
data->oversampling_press = ilog2(val);
return data->chip_info->chip_config(data);
}
}
return -EINVAL;
}
static int bmp280_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret = 0;
struct bmp280_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
mutex_lock(&data->lock);
switch (chan->type) {
case IIO_PRESSURE:
ret = bmp280_write_oversampling_ratio_press(data, val);
break;
case IIO_TEMP:
ret = bmp280_write_oversampling_ratio_temp(data, val);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
break;
default:
return -EINVAL;
}
return ret;
}
static ssize_t bmp280_show_avail(char *buf, const int *vals, const int n)
{
size_t len = 0;
int i;
for (i = 0; i < n; i++)
len += scnprintf(buf + len, PAGE_SIZE - len, "%d ", vals[i]);
buf[len - 1] = '\n';
return len;
}
static ssize_t bmp280_show_temp_oversampling_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bmp280_data *data = iio_priv(dev_to_iio_dev(dev));
return bmp280_show_avail(buf, data->chip_info->oversampling_temp_avail,
data->chip_info->num_oversampling_temp_avail);
}
static ssize_t bmp280_show_press_oversampling_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bmp280_data *data = iio_priv(dev_to_iio_dev(dev));
return bmp280_show_avail(buf, data->chip_info->oversampling_press_avail,
data->chip_info->num_oversampling_press_avail);
}
static int bmp280_chip_config(struct bmp280_data *data)
{
int ret;
u8 osrs = BMP280_OSRS_TEMP_X(data->oversampling_temp + 1) |
BMP280_OSRS_PRESS_X(data->oversampling_press + 1);
ret = regmap_update_bits(data->regmap, BMP280_REG_CTRL_MEAS,
BMP280_OSRS_TEMP_MASK |
BMP280_OSRS_PRESS_MASK |
BMP280_MODE_MASK,
osrs | BMP280_MODE_NORMAL);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to write ctrl_meas register\n");
return ret;
}
ret = regmap_update_bits(data->regmap, BMP280_REG_CONFIG,
BMP280_FILTER_MASK,
BMP280_FILTER_4X);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to write config register\n");
return ret;
}
return ret;
}
static bool bmp180_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMP280_REG_CTRL_MEAS:
case BMP280_REG_RESET:
return true;
default:
return false;
};
}
static bool bmp180_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case BMP180_REG_OUT_XLSB:
case BMP180_REG_OUT_LSB:
case BMP180_REG_OUT_MSB:
case BMP280_REG_CTRL_MEAS:
return true;
default:
return false;
}
}
static int bmp180_measure(struct bmp280_data *data, u8 ctrl_meas)
{
int ret;
const int conversion_time_max[] = { 4500, 7500, 13500, 25500 };
unsigned int delay_us;
unsigned int ctrl;
ret = regmap_write(data->regmap, BMP280_REG_CTRL_MEAS, ctrl_meas);
if (ret)
return ret;
if (ctrl_meas == BMP180_MEAS_TEMP)
delay_us = 4500;
else
delay_us = conversion_time_max[data->oversampling_press];
usleep_range(delay_us, delay_us + 1000);
ret = regmap_read(data->regmap, BMP280_REG_CTRL_MEAS, &ctrl);
if (ret)
return ret;
if (ctrl & BMP180_MEAS_SCO)
return -EIO;
return 0;
}
static int bmp180_read_adc_temp(struct bmp280_data *data, int *val)
{
int ret;
__be16 tmp = 0;
ret = bmp180_measure(data, BMP180_MEAS_TEMP);
if (ret)
return ret;
ret = regmap_bulk_read(data->regmap, BMP180_REG_OUT_MSB, (u8 *)&tmp, 2);
if (ret)
return ret;
*val = be16_to_cpu(tmp);
return 0;
}
static int bmp180_read_calib(struct bmp280_data *data,
struct bmp180_calib *calib)
{
int ret;
int i;
__be16 buf[BMP180_REG_CALIB_COUNT / 2];
ret = regmap_bulk_read(data->regmap, BMP180_REG_CALIB_START, buf,
sizeof(buf));
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(buf); i++) {
if (buf[i] == cpu_to_be16(0) || buf[i] == cpu_to_be16(0xffff))
return -EIO;
}
calib->AC1 = be16_to_cpu(buf[AC1]);
calib->AC2 = be16_to_cpu(buf[AC2]);
calib->AC3 = be16_to_cpu(buf[AC3]);
calib->AC4 = be16_to_cpu(buf[AC4]);
calib->AC5 = be16_to_cpu(buf[AC5]);
calib->AC6 = be16_to_cpu(buf[AC6]);
calib->B1 = be16_to_cpu(buf[B1]);
calib->B2 = be16_to_cpu(buf[B2]);
calib->MB = be16_to_cpu(buf[MB]);
calib->MC = be16_to_cpu(buf[MC]);
calib->MD = be16_to_cpu(buf[MD]);
return 0;
}
static s32 bmp180_compensate_temp(struct bmp280_data *data, s32 adc_temp)
{
int ret;
s32 x1, x2;
struct bmp180_calib calib;
ret = bmp180_read_calib(data, &calib);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read calibration coefficients\n");
return ret;
}
x1 = ((adc_temp - calib.AC6) * calib.AC5) >> 15;
x2 = (calib.MC << 11) / (x1 + calib.MD);
data->t_fine = x1 + x2;
return (data->t_fine + 8) >> 4;
}
static int bmp180_read_temp(struct bmp280_data *data, int *val)
{
int ret;
s32 adc_temp, comp_temp;
ret = bmp180_read_adc_temp(data, &adc_temp);
if (ret)
return ret;
comp_temp = bmp180_compensate_temp(data, adc_temp);
if (val) {
*val = comp_temp * 100;
return IIO_VAL_INT;
}
return 0;
}
static int bmp180_read_adc_press(struct bmp280_data *data, int *val)
{
int ret;
__be32 tmp = 0;
u8 oss = data->oversampling_press;
ret = bmp180_measure(data, BMP180_MEAS_PRESS_X(oss));
if (ret)
return ret;
ret = regmap_bulk_read(data->regmap, BMP180_REG_OUT_MSB, (u8 *)&tmp, 3);
if (ret)
return ret;
*val = (be32_to_cpu(tmp) >> 8) >> (8 - oss);
return 0;
}
static u32 bmp180_compensate_press(struct bmp280_data *data, s32 adc_press)
{
int ret;
s32 x1, x2, x3, p;
s32 b3, b6;
u32 b4, b7;
s32 oss = data->oversampling_press;
struct bmp180_calib calib;
ret = bmp180_read_calib(data, &calib);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read calibration coefficients\n");
return ret;
}
b6 = data->t_fine - 4000;
x1 = (calib.B2 * (b6 * b6 >> 12)) >> 11;
x2 = calib.AC2 * b6 >> 11;
x3 = x1 + x2;
b3 = ((((s32)calib.AC1 * 4 + x3) << oss) + 2) / 4;
x1 = calib.AC3 * b6 >> 13;
x2 = (calib.B1 * ((b6 * b6) >> 12)) >> 16;
x3 = (x1 + x2 + 2) >> 2;
b4 = calib.AC4 * (u32)(x3 + 32768) >> 15;
b7 = ((u32)adc_press - b3) * (50000 >> oss);
if (b7 < 0x80000000)
p = (b7 * 2) / b4;
else
p = (b7 / b4) * 2;
x1 = (p >> 8) * (p >> 8);
x1 = (x1 * 3038) >> 16;
x2 = (-7357 * p) >> 16;
return p + ((x1 + x2 + 3791) >> 4);
}
static int bmp180_read_press(struct bmp280_data *data,
int *val, int *val2)
{
int ret;
s32 adc_press;
u32 comp_press;
ret = bmp180_read_temp(data, NULL);
if (ret)
return ret;
ret = bmp180_read_adc_press(data, &adc_press);
if (ret)
return ret;
comp_press = bmp180_compensate_press(data, adc_press);
*val = comp_press;
*val2 = 1000;
return IIO_VAL_FRACTIONAL;
}
static int bmp180_chip_config(struct bmp280_data *data)
{
return 0;
}
static int bmp280_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct bmp280_data *data;
unsigned int chip_id;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
mutex_init(&data->lock);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->channels = bmp280_channels;
indio_dev->num_channels = ARRAY_SIZE(bmp280_channels);
indio_dev->info = &bmp280_info;
indio_dev->modes = INDIO_DIRECT_MODE;
switch (id->driver_data) {
case BMP180_CHIP_ID:
data->chip_info = &bmp180_chip_info;
data->oversampling_press = ilog2(8);
data->oversampling_temp = ilog2(1);
break;
case BMP280_CHIP_ID:
data->chip_info = &bmp280_chip_info;
data->oversampling_press = ilog2(16);
data->oversampling_temp = ilog2(2);
break;
default:
return -EINVAL;
}
data->regmap = devm_regmap_init_i2c(client,
data->chip_info->regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = regmap_read(data->regmap, BMP280_REG_ID, &chip_id);
if (ret < 0)
return ret;
if (chip_id != id->driver_data) {
dev_err(&client->dev, "bad chip id. expected %lx got %x\n",
id->driver_data, chip_id);
return -EINVAL;
}
ret = data->chip_info->chip_config(data);
if (ret < 0)
return ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
