static int hdmiphy_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
hdmi_attach_hdmiphy_client(client);
dev_info(&client->adapter->dev, "attached s5p_hdmiphy "
"into i2c adapter successfully\n");
return 0;
}
static int hdmiphy_remove(struct i2c_client *client)
{
dev_info(&client->adapter->dev, "detached s5p_hdmiphy "
"from i2c adapter successfully\n");
return 0;
}
