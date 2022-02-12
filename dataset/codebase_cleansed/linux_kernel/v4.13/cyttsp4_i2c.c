static int cyttsp4_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cyttsp4 *ts;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C functionality not Supported\n");
return -EIO;
}
ts = cyttsp4_probe(&cyttsp4_i2c_bus_ops, &client->dev, client->irq,
CYTTSP4_I2C_DATA_SIZE);
return PTR_ERR_OR_ZERO(ts);
}
static int cyttsp4_i2c_remove(struct i2c_client *client)
{
struct cyttsp4 *ts = i2c_get_clientdata(client);
cyttsp4_remove(ts);
return 0;
}
