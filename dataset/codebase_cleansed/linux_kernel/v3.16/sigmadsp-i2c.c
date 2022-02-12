static int sigma_action_write_i2c(void *control_data,
const struct sigma_action *sa, size_t len)
{
return i2c_master_send(control_data, (const unsigned char *)&sa->addr,
len);
}
int process_sigma_firmware(struct i2c_client *client, const char *name)
{
struct sigma_firmware ssfw;
ssfw.control_data = client;
ssfw.write = sigma_action_write_i2c;
return _process_sigma_firmware(&client->dev, &ssfw, name);
}
