static int ad7879_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ad7879 *ts = i2c_get_clientdata(client);
ad7879_suspend(ts);
return 0;
}
static int ad7879_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ad7879 *ts = i2c_get_clientdata(client);
ad7879_resume(ts);
return 0;
}
static int ad7879_i2c_read(struct device *dev, u8 reg)
{
struct i2c_client *client = to_i2c_client(dev);
return swab16(i2c_smbus_read_word_data(client, reg));
}
static int ad7879_i2c_multi_read(struct device *dev,
u8 first_reg, u8 count, u16 *buf)
{
struct i2c_client *client = to_i2c_client(dev);
u8 idx;
i2c_smbus_read_i2c_block_data(client, first_reg, count * 2, (u8 *)buf);
for (idx = 0; idx < count; ++idx)
buf[idx] = swab16(buf[idx]);
return 0;
}
static int ad7879_i2c_write(struct device *dev, u8 reg, u16 val)
{
struct i2c_client *client = to_i2c_client(dev);
return i2c_smbus_write_word_data(client, reg, swab16(val));
}
static int __devinit ad7879_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad7879 *ts;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev, "SMBUS Word Data not Supported\n");
return -EIO;
}
ts = ad7879_probe(&client->dev, AD7879_DEVID, client->irq,
&ad7879_i2c_bus_ops);
if (IS_ERR(ts))
return PTR_ERR(ts);
i2c_set_clientdata(client, ts);
return 0;
}
static int __devexit ad7879_i2c_remove(struct i2c_client *client)
{
struct ad7879 *ts = i2c_get_clientdata(client);
ad7879_remove(ts);
return 0;
}
static int __init ad7879_i2c_init(void)
{
return i2c_add_driver(&ad7879_i2c_driver);
}
static void __exit ad7879_i2c_exit(void)
{
i2c_del_driver(&ad7879_i2c_driver);
}
