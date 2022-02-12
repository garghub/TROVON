static int cyttsp_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cyttsp *ts;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C functionality not Supported\n");
return -EIO;
}
ts = cyttsp_probe(&cyttsp_i2c_bus_ops, &client->dev, client->irq,
CY_I2C_DATA_SIZE);
if (IS_ERR(ts))
return PTR_ERR(ts);
i2c_set_clientdata(client, ts);
return 0;
}
static int cyttsp_i2c_remove(struct i2c_client *client)
{
struct cyttsp *ts = i2c_get_clientdata(client);
cyttsp_remove(ts);
return 0;
}
