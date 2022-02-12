static int max7300_i2c_write(struct device *dev, unsigned int reg,
unsigned int val)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_write_byte_data(client, reg, val);
}
static int max7300_i2c_read(struct device *dev, unsigned int reg)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_read_byte_data(client, reg);
}
static int max7300_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max7301 *ts;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
ts = devm_kzalloc(&client->dev, sizeof(struct max7301), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->read = max7300_i2c_read;
ts->write = max7300_i2c_write;
ts->dev = &client->dev;
ret = __max730x_probe(ts);
return ret;
}
static int max7300_remove(struct i2c_client *client)
{
return __max730x_remove(&client->dev);
}
static int __init max7300_init(void)
{
return i2c_add_driver(&max7300_driver);
}
static void __exit max7300_exit(void)
{
i2c_del_driver(&max7300_driver);
}
