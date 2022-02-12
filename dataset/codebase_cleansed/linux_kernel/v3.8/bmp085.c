static s32 bmp085_read_calibration_data(struct bmp085_data *data)
{
u16 tmp[BMP085_CALIBRATION_DATA_LENGTH];
struct bmp085_calibration_data *cali = &(data->calibration);
s32 status = regmap_bulk_read(data->regmap,
BMP085_CALIBRATION_DATA_START, (u8 *)tmp,
(BMP085_CALIBRATION_DATA_LENGTH << 1));
if (status < 0)
return status;
cali->AC1 = be16_to_cpu(tmp[0]);
cali->AC2 = be16_to_cpu(tmp[1]);
cali->AC3 = be16_to_cpu(tmp[2]);
cali->AC4 = be16_to_cpu(tmp[3]);
cali->AC5 = be16_to_cpu(tmp[4]);
cali->AC6 = be16_to_cpu(tmp[5]);
cali->B1 = be16_to_cpu(tmp[6]);
cali->B2 = be16_to_cpu(tmp[7]);
cali->MB = be16_to_cpu(tmp[8]);
cali->MC = be16_to_cpu(tmp[9]);
cali->MD = be16_to_cpu(tmp[10]);
return 0;
}
static s32 bmp085_update_raw_temperature(struct bmp085_data *data)
{
u16 tmp;
s32 status;
mutex_lock(&data->lock);
status = regmap_write(data->regmap, BMP085_CTRL_REG,
BMP085_TEMP_MEASUREMENT);
if (status < 0) {
dev_err(data->dev,
"Error while requesting temperature measurement.\n");
goto exit;
}
msleep(BMP085_TEMP_CONVERSION_TIME);
status = regmap_bulk_read(data->regmap, BMP085_CONVERSION_REGISTER_MSB,
&tmp, sizeof(tmp));
if (status < 0) {
dev_err(data->dev,
"Error while reading temperature measurement result\n");
goto exit;
}
data->raw_temperature = be16_to_cpu(tmp);
data->last_temp_measurement = jiffies;
status = 0;
exit:
mutex_unlock(&data->lock);
return status;
}
static s32 bmp085_update_raw_pressure(struct bmp085_data *data)
{
u32 tmp = 0;
s32 status;
mutex_lock(&data->lock);
status = regmap_write(data->regmap, BMP085_CTRL_REG,
BMP085_PRESSURE_MEASUREMENT +
(data->oversampling_setting << 6));
if (status < 0) {
dev_err(data->dev,
"Error while requesting pressure measurement.\n");
goto exit;
}
msleep(2+(3 << data->oversampling_setting));
status = regmap_bulk_read(data->regmap, BMP085_CONVERSION_REGISTER_MSB,
((u8 *)&tmp)+1, 3);
if (status < 0) {
dev_err(data->dev,
"Error while reading pressure measurement results\n");
goto exit;
}
data->raw_pressure = be32_to_cpu((tmp));
data->raw_pressure >>= (8-data->oversampling_setting);
status = 0;
exit:
mutex_unlock(&data->lock);
return status;
}
static s32 bmp085_get_temperature(struct bmp085_data *data, int *temperature)
{
struct bmp085_calibration_data *cali = &data->calibration;
long x1, x2;
int status;
status = bmp085_update_raw_temperature(data);
if (status < 0)
goto exit;
x1 = ((data->raw_temperature - cali->AC6) * cali->AC5) >> 15;
x2 = (cali->MC << 11) / (x1 + cali->MD);
data->b6 = x1 + x2 - 4000;
if (temperature != NULL)
*temperature = (x1+x2+8) >> 4;
exit:
return status;
}
static s32 bmp085_get_pressure(struct bmp085_data *data, int *pressure)
{
struct bmp085_calibration_data *cali = &data->calibration;
s32 x1, x2, x3, b3;
u32 b4, b7;
s32 p;
int status;
if ((data->last_temp_measurement == 0) ||
time_is_before_jiffies(data->last_temp_measurement + 1*HZ)) {
status = bmp085_get_temperature(data, NULL);
if (status < 0)
return status;
}
status = bmp085_update_raw_pressure(data);
if (status < 0)
return status;
x1 = (data->b6 * data->b6) >> 12;
x1 *= cali->B2;
x1 >>= 11;
x2 = cali->AC2 * data->b6;
x2 >>= 11;
x3 = x1 + x2;
b3 = (((((s32)cali->AC1) * 4 + x3) << data->oversampling_setting) + 2);
b3 >>= 2;
x1 = (cali->AC3 * data->b6) >> 13;
x2 = (cali->B1 * ((data->b6 * data->b6) >> 12)) >> 16;
x3 = (x1 + x2 + 2) >> 2;
b4 = (cali->AC4 * (u32)(x3 + 32768)) >> 15;
b7 = ((u32)data->raw_pressure - b3) *
(50000 >> data->oversampling_setting);
p = ((b7 < 0x80000000) ? ((b7 << 1) / b4) : ((b7 / b4) * 2));
x1 = p >> 8;
x1 *= x1;
x1 = (x1 * 3038) >> 16;
x2 = (-7357 * p) >> 16;
p += (x1 + x2 + 3791) >> 4;
*pressure = p;
return 0;
}
static void bmp085_set_oversampling(struct bmp085_data *data,
unsigned char oversampling)
{
if (oversampling > 3)
oversampling = 3;
data->oversampling_setting = oversampling;
}
static unsigned char bmp085_get_oversampling(struct bmp085_data *data)
{
return data->oversampling_setting;
}
static ssize_t set_oversampling(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bmp085_data *data = dev_get_drvdata(dev);
unsigned long oversampling;
int err = kstrtoul(buf, 10, &oversampling);
if (err == 0) {
mutex_lock(&data->lock);
bmp085_set_oversampling(data, oversampling);
mutex_unlock(&data->lock);
return count;
}
return err;
}
static ssize_t show_oversampling(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bmp085_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", bmp085_get_oversampling(data));
}
static ssize_t show_temperature(struct device *dev,
struct device_attribute *attr, char *buf)
{
int temperature;
int status;
struct bmp085_data *data = dev_get_drvdata(dev);
status = bmp085_get_temperature(data, &temperature);
if (status < 0)
return status;
else
return sprintf(buf, "%d\n", temperature);
}
static ssize_t show_pressure(struct device *dev,
struct device_attribute *attr, char *buf)
{
int pressure;
int status;
struct bmp085_data *data = dev_get_drvdata(dev);
status = bmp085_get_pressure(data, &pressure);
if (status < 0)
return status;
else
return sprintf(buf, "%d\n", pressure);
}
int bmp085_detect(struct device *dev)
{
struct bmp085_data *data = dev_get_drvdata(dev);
unsigned int id;
int ret;
ret = regmap_read(data->regmap, BMP085_CHIP_ID_REG, &id);
if (ret < 0)
return ret;
if (id != data->chip_id)
return -ENODEV;
return 0;
}
static void __init bmp085_get_of_properties(struct bmp085_data *data)
{
#ifdef CONFIG_OF
struct device_node *np = data->dev->of_node;
u32 prop;
if (!np)
return;
if (!of_property_read_u32(np, "chip-id", &prop))
data->chip_id = prop & 0xff;
if (!of_property_read_u32(np, "temp-measurement-period", &prop))
data->temp_measurement_period = (prop/100)*HZ;
if (!of_property_read_u32(np, "default-oversampling", &prop))
data->oversampling_setting = prop & 0xff;
#endif
}
static int bmp085_init_client(struct bmp085_data *data)
{
int status = bmp085_read_calibration_data(data);
if (status < 0)
return status;
data->chip_id = BMP085_CHIP_ID;
data->last_temp_measurement = 0;
data->temp_measurement_period = 1*HZ;
data->oversampling_setting = 3;
bmp085_get_of_properties(data);
mutex_init(&data->lock);
return 0;
}
int bmp085_probe(struct device *dev, struct regmap *regmap)
{
struct bmp085_data *data;
int err = 0;
data = kzalloc(sizeof(struct bmp085_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
dev_set_drvdata(dev, data);
data->dev = dev;
data->regmap = regmap;
err = bmp085_init_client(data);
if (err < 0)
goto exit_free;
err = bmp085_detect(dev);
if (err < 0) {
dev_err(dev, "%s: chip_id failed!\n", BMP085_NAME);
goto exit_free;
}
err = sysfs_create_group(&dev->kobj, &bmp085_attr_group);
if (err)
goto exit_free;
dev_info(dev, "Successfully initialized %s!\n", BMP085_NAME);
return 0;
exit_free:
kfree(data);
exit:
return err;
}
int bmp085_remove(struct device *dev)
{
struct bmp085_data *data = dev_get_drvdata(dev);
sysfs_remove_group(&data->dev->kobj, &bmp085_attr_group);
kfree(data);
return 0;
}
