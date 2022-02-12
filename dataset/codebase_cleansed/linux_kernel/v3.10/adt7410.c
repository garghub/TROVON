static int adt7410_i2c_read_word(struct device *dev, u8 reg)
{
return i2c_smbus_read_word_swapped(to_i2c_client(dev), reg);
}
static int adt7410_i2c_write_word(struct device *dev, u8 reg, u16 data)
{
return i2c_smbus_write_word_swapped(to_i2c_client(dev), reg, data);
}
static int adt7410_i2c_read_byte(struct device *dev, u8 reg)
{
return i2c_smbus_read_byte_data(to_i2c_client(dev), reg);
}
static int adt7410_i2c_write_byte(struct device *dev, u8 reg, u8 data)
{
return i2c_smbus_write_byte_data(to_i2c_client(dev), reg, data);
}
static int adt7410_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
return adt7x10_probe(&client->dev, NULL, client->irq, &adt7410_i2c_ops);
}
static int adt7410_i2c_remove(struct i2c_client *client)
{
return adt7x10_remove(&client->dev, client->irq);
}
