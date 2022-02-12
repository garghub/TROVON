static int mpl115_i2c_init(struct device *dev)
{
return 0;
}
static int mpl115_i2c_read(struct device *dev, u8 address)
{
return i2c_smbus_read_word_swapped(to_i2c_client(dev), address);
}
static int mpl115_i2c_write(struct device *dev, u8 address, u8 value)
{
return i2c_smbus_write_byte_data(to_i2c_client(dev), address, value);
}
static int mpl115_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
return mpl115_probe(&client->dev, id->name, &mpl115_i2c_ops);
}
