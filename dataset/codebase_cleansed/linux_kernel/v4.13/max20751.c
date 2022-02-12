static int max20751_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &max20751_info);
}
