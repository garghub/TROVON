static int adxl34x_smbus_read(struct device *dev, unsigned char reg)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_read_byte_data(client, reg);
}
static int adxl34x_smbus_write(struct device *dev,
unsigned char reg, unsigned char val)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_write_byte_data(client, reg, val);
}
static int adxl34x_smbus_read_block(struct device *dev,
unsigned char reg, int count,
void *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_read_i2c_block_data(client, reg, count, buf);
}
static int adxl34x_i2c_read_block(struct device *dev,
unsigned char reg, int count,
void *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
ret = i2c_master_send(client, &reg, 1);
if (ret < 0)
return ret;
ret = i2c_master_recv(client, buf, count);
if (ret < 0)
return ret;
if (ret != count)
return -EIO;
return 0;
}
static int adxl34x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adxl34x *ac;
int error;
error = i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA);
if (!error) {
dev_err(&client->dev, "SMBUS Byte Data not Supported\n");
return -EIO;
}
ac = adxl34x_probe(&client->dev, client->irq, false,
i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_I2C_BLOCK) ?
&adxl34x_smbus_bops : &adxl34x_i2c_bops);
if (IS_ERR(ac))
return PTR_ERR(ac);
i2c_set_clientdata(client, ac);
return 0;
}
static int adxl34x_i2c_remove(struct i2c_client *client)
{
struct adxl34x *ac = i2c_get_clientdata(client);
return adxl34x_remove(ac);
}
static int __maybe_unused adxl34x_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adxl34x *ac = i2c_get_clientdata(client);
adxl34x_suspend(ac);
return 0;
}
static int __maybe_unused adxl34x_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adxl34x *ac = i2c_get_clientdata(client);
adxl34x_resume(ac);
return 0;
}
