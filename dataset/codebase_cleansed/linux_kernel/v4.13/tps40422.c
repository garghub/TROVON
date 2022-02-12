static int tps40422_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &tps40422_info);
}
