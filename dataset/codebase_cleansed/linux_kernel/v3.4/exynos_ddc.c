static int s5p_ddc_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
hdmi_attach_ddc_client(client);
dev_info(&client->adapter->dev, "attached s5p_ddc "
"into i2c adapter successfully\n");
return 0;
}
static int s5p_ddc_remove(struct i2c_client *client)
{
dev_info(&client->adapter->dev, "detached s5p_ddc "
"from i2c adapter successfully\n");
return 0;
}
