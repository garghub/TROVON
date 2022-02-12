static int write_d8(void *client, u8 val)
{
return i2c_smbus_write_byte(client, val);
}
static int write_r8d8(void *client, u8 reg, u8 val)
{
return i2c_smbus_write_byte_data(client, reg, val);
}
static int write_r8d16(void *client, u8 reg, u16 val)
{
return i2c_smbus_write_word_data(client, reg, val);
}
static int read_d8(void *client)
{
return i2c_smbus_read_byte(client);
}
static int read_r8d8(void *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int read_r8d16(void *client, u8 reg)
{
return i2c_smbus_read_word_data(client, reg);
}
static int __devinit ad_dpot_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad_dpot_bus_data bdata = {
.client = client,
.bops = &bops,
};
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev, "SMBUS Word Data not Supported\n");
return -EIO;
}
return ad_dpot_probe(&client->dev, &bdata, id->driver_data, id->name);
}
static int __devexit ad_dpot_i2c_remove(struct i2c_client *client)
{
return ad_dpot_remove(&client->dev);
}
