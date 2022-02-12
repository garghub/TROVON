static int s5p_ddc_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
hdmi_attach_ddc_client(client);
dev_info(&client->adapter->dev,
"attached %s into i2c adapter successfully\n",
client->name);
return 0;
}
static int s5p_ddc_remove(struct i2c_client *client)
{
dev_info(&client->adapter->dev,
"detached %s from i2c adapter successfully\n",
client->name);
return 0;
}
