static s32 bmp085_read_calibration_data(struct i2c_client *client)
{
u16 tmp[BMP085_CALIBRATION_DATA_LENGTH];
struct bmp085_data *data = i2c_get_clientdata(client);
struct bmp085_calibration_data *cali = &(data->calibration);
s32 status = i2c_smbus_read_i2c_block_data(client,
BMP085_CALIBRATION_DATA_START,
BMP085_CALIBRATION_DATA_LENGTH*sizeof(u16),
(u8 *)tmp);
if (status < 0)
return status;
if (status != BMP085_CALIBRATION_DATA_LENGTH*sizeof(u16))
return -EIO;
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
status = i2c_smbus_write_byte_data(data->client, BMP085_CTRL_REG,
BMP085_TEMP_MEASUREMENT);
if (status != 0) {
dev_err(&data->client->dev,
"Error while requesting temperature measurement.\n");
goto exit;
}
msleep(BMP085_TEMP_CONVERSION_TIME);
status = i2c_smbus_read_i2c_block_data(data->client,
BMP085_CONVERSION_REGISTER_MSB, sizeof(tmp), (u8 *)&tmp);
if (status < 0)
goto exit;
if (status != sizeof(tmp)) {
dev_err(&data->client->dev,
"Error while reading temperature measurement result\n");
status = -EIO;
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
status = i2c_smbus_write_byte_data(data->client, BMP085_CTRL_REG,
BMP085_PRESSURE_MEASUREMENT + (data->oversampling_setting<<6));
if (status != 0) {
dev_err(&data->client->dev,
"Error while requesting pressure measurement.\n");
goto exit;
}
msleep(2+(3 << data->oversampling_setting));
status = i2c_smbus_read_i2c_block_data(data->client,
BMP085_CONVERSION_REGISTER_MSB, 3, ((u8 *)&tmp)+1);
if (status < 0)
goto exit;
if (status != 3) {
dev_err(&data->client->dev,
"Error while reading pressure measurement results\n");
status = -EIO;
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
if (status != 0)
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
if (data->last_temp_measurement + 1*HZ < jiffies) {
status = bmp085_get_temperature(data, NULL);
if (status != 0)
goto exit;
}
status = bmp085_update_raw_pressure(data);
if (status != 0)
goto exit;
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
exit:
return status;
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
struct i2c_client *client = to_i2c_client(dev);
struct bmp085_data *data = i2c_get_clientdata(client);
unsigned long oversampling;
int success = strict_strtoul(buf, 10, &oversampling);
if (success == 0) {
bmp085_set_oversampling(data, oversampling);
return count;
}
return success;
}
static ssize_t show_oversampling(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct bmp085_data *data = i2c_get_clientdata(client);
return sprintf(buf, "%u\n", bmp085_get_oversampling(data));
}
static ssize_t show_temperature(struct device *dev,
struct device_attribute *attr, char *buf)
{
int temperature;
int status;
struct i2c_client *client = to_i2c_client(dev);
struct bmp085_data *data = i2c_get_clientdata(client);
status = bmp085_get_temperature(data, &temperature);
if (status != 0)
return status;
else
return sprintf(buf, "%d\n", temperature);
}
static ssize_t show_pressure(struct device *dev,
struct device_attribute *attr, char *buf)
{
int pressure;
int status;
struct i2c_client *client = to_i2c_client(dev);
struct bmp085_data *data = i2c_get_clientdata(client);
status = bmp085_get_pressure(data, &pressure);
if (status != 0)
return status;
else
return sprintf(buf, "%d\n", pressure);
}
static int bmp085_detect(struct i2c_client *client, struct i2c_board_info *info)
{
if (client->addr != BMP085_I2C_ADDRESS)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, BMP085_CHIP_ID_REG) != BMP085_CHIP_ID)
return -ENODEV;
return 0;
}
static int bmp085_init_client(struct i2c_client *client)
{
unsigned char version;
int status;
struct bmp085_data *data = i2c_get_clientdata(client);
data->client = client;
status = bmp085_read_calibration_data(client);
if (status != 0)
goto exit;
version = i2c_smbus_read_byte_data(client, BMP085_VERSION_REG);
data->last_temp_measurement = 0;
data->oversampling_setting = 3;
mutex_init(&data->lock);
dev_info(&data->client->dev, "BMP085 ver. %d.%d found.\n",
(version & 0x0F), (version & 0xF0) >> 4);
exit:
return status;
}
static int __devinit bmp085_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bmp085_data *data;
int err = 0;
data = kzalloc(sizeof(struct bmp085_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
data->oversampling_setting = 0x00;
i2c_set_clientdata(client, data);
err = bmp085_init_client(client);
if (err != 0)
goto exit_free;
err = sysfs_create_group(&client->dev.kobj, &bmp085_attr_group);
if (err)
goto exit_free;
dev_info(&data->client->dev, "Successfully initialized bmp085!\n");
goto exit;
exit_free:
kfree(data);
exit:
return err;
}
static int __devexit bmp085_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &bmp085_attr_group);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init bmp085_init(void)
{
return i2c_add_driver(&bmp085_driver);
}
static void __exit bmp085_exit(void)
{
i2c_del_driver(&bmp085_driver);
}
