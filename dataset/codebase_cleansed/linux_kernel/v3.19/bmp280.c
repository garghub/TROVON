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
static int bmp280_read_compensation_temp(struct bmp280_data *data,
struct bmp280_comp_temp *comp)
{
int ret;
__le16 buf[BMP280_COMP_TEMP_REG_COUNT / 2];
ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_TEMP_START,
buf, BMP280_COMP_TEMP_REG_COUNT);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read temperature calibration parameters\n");
return ret;
}
comp->dig_t1 = (u16) le16_to_cpu(buf[0]);
comp->dig_t2 = (s16) le16_to_cpu(buf[1]);
comp->dig_t3 = (s16) le16_to_cpu(buf[2]);
return 0;
}
static int bmp280_read_compensation_press(struct bmp280_data *data,
struct bmp280_comp_press *comp)
{
int ret;
__le16 buf[BMP280_COMP_PRESS_REG_COUNT / 2];
ret = regmap_bulk_read(data->regmap, BMP280_REG_COMP_PRESS_START,
buf, BMP280_COMP_PRESS_REG_COUNT);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to read pressure calibration parameters\n");
return ret;
}
comp->dig_p1 = (u16) le16_to_cpu(buf[0]);
comp->dig_p2 = (s16) le16_to_cpu(buf[1]);
comp->dig_p3 = (s16) le16_to_cpu(buf[2]);
comp->dig_p4 = (s16) le16_to_cpu(buf[3]);
comp->dig_p5 = (s16) le16_to_cpu(buf[4]);
comp->dig_p6 = (s16) le16_to_cpu(buf[5]);
comp->dig_p7 = (s16) le16_to_cpu(buf[6]);
comp->dig_p8 = (s16) le16_to_cpu(buf[7]);
comp->dig_p9 = (s16) le16_to_cpu(buf[8]);
return 0;
}
static s32 bmp280_compensate_temp(struct bmp280_data *data,
struct bmp280_comp_temp *comp,
s32 adc_temp)
{
s32 var1, var2, t;
var1 = (((adc_temp >> 3) - ((s32) comp->dig_t1 << 1)) *
((s32) comp->dig_t2)) >> 11;
var2 = (((((adc_temp >> 4) - ((s32) comp->dig_t1)) *
((adc_temp >> 4) - ((s32) comp->dig_t1))) >> 12) *
((s32) comp->dig_t3)) >> 14;
data->t_fine = var1 + var2;
t = (data->t_fine * 5 + 128) >> 8;
return t;
}
static u32 bmp280_compensate_press(struct bmp280_data *data,
struct bmp280_comp_press *comp,
s32 adc_press)
{
s64 var1, var2, p;
var1 = ((s64) data->t_fine) - 128000;
var2 = var1 * var1 * (s64) comp->dig_p6;
var2 = var2 + ((var1 * (s64) comp->dig_p5) << 17);
var2 = var2 + (((s64) comp->dig_p4) << 35);
var1 = ((var1 * var1 * (s64) comp->dig_p3) >> 8) +
((var1 * (s64) comp->dig_p2) << 12);
var1 = (((((s64) 1) << 47) + var1)) * ((s64) comp->dig_p1) >> 33;
if (var1 == 0)
return 0;
p = ((((s64) 1048576 - adc_press) << 31) - var2) * 3125;
p = div64_s64(p, var1);
var1 = (((s64) comp->dig_p9) * (p >> 13) * (p >> 13)) >> 25;
var2 = (((s64) comp->dig_p8) * p) >> 19;
p = ((p + var1 + var2) >> 8) + (((s64) comp->dig_p7) << 4);
return (u32) p;
}
static int bmp280_read_temp(struct bmp280_data *data,
int *val)
{
int ret;
__be32 tmp = 0;
s32 adc_temp, comp_temp;
struct bmp280_comp_temp comp;
ret = bmp280_read_compensation_temp(data, &comp);
if (ret < 0)
return ret;
ret = regmap_bulk_read(data->regmap, BMP280_REG_TEMP_MSB,
(u8 *) &tmp, 3);
if (ret < 0) {
dev_err(&data->client->dev, "failed to read temperature\n");
return ret;
}
adc_temp = be32_to_cpu(tmp) >> 12;
comp_temp = bmp280_compensate_temp(data, &comp, adc_temp);
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
struct bmp280_comp_press comp;
ret = bmp280_read_compensation_press(data, &comp);
if (ret < 0)
return ret;
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
comp_press = bmp280_compensate_press(data, &comp, adc_press);
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
ret = bmp280_read_press(data, val, val2);
break;
case IIO_TEMP:
ret = bmp280_read_temp(data, val);
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
static int bmp280_chip_init(struct bmp280_data *data)
{
int ret;
ret = regmap_update_bits(data->regmap, BMP280_REG_CTRL_MEAS,
BMP280_OSRS_TEMP_MASK |
BMP280_OSRS_PRESS_MASK |
BMP280_MODE_MASK,
BMP280_OSRS_TEMP_2X |
BMP280_OSRS_PRESS_16X |
BMP280_MODE_NORMAL);
if (ret < 0) {
dev_err(&data->client->dev,
"failed to write config register\n");
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
i2c_set_clientdata(client, indio_dev);
data = iio_priv(indio_dev);
mutex_init(&data->lock);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->channels = bmp280_channels;
indio_dev->num_channels = ARRAY_SIZE(bmp280_channels);
indio_dev->info = &bmp280_info;
indio_dev->modes = INDIO_DIRECT_MODE;
data->regmap = devm_regmap_init_i2c(client, &bmp280_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = regmap_read(data->regmap, BMP280_REG_ID, &chip_id);
if (ret < 0)
return ret;
if (chip_id != BMP280_CHIP_ID) {
dev_err(&client->dev, "bad chip id. expected %x got %x\n",
BMP280_CHIP_ID, chip_id);
return -EINVAL;
}
ret = bmp280_chip_init(data);
if (ret < 0)
return ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
