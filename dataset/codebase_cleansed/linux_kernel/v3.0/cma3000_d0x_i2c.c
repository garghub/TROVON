static int cma3000_i2c_set(struct device *dev,
u8 reg, u8 val, char *msg)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret < 0)
dev_err(&client->dev,
"%s failed (%s, %d)\n", __func__, msg, ret);
return ret;
}
static int cma3000_i2c_read(struct device *dev, u8 reg, char *msg)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
dev_err(&client->dev,
"%s failed (%s, %d)\n", __func__, msg, ret);
return ret;
}
static int __devinit cma3000_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cma3000_accl_data *data;
data = cma3000_init(&client->dev, client->irq, &cma3000_i2c_bops);
if (IS_ERR(data))
return PTR_ERR(data);
i2c_set_clientdata(client, data);
return 0;
}
static int __devexit cma3000_i2c_remove(struct i2c_client *client)
{
struct cma3000_accl_data *data = i2c_get_clientdata(client);
cma3000_exit(data);
return 0;
}
static int cma3000_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct cma3000_accl_data *data = i2c_get_clientdata(client);
cma3000_suspend(data);
return 0;
}
static int cma3000_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct cma3000_accl_data *data = i2c_get_clientdata(client);
cma3000_resume(data);
return 0;
}
static int __init cma3000_i2c_init(void)
{
return i2c_add_driver(&cma3000_i2c_driver);
}
static void __exit cma3000_i2c_exit(void)
{
i2c_del_driver(&cma3000_i2c_driver);
}
