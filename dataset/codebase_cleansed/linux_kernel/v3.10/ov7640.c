static int write_regs(struct i2c_client *client, const u8 *regs)
{
int i;
for (i = 0; regs[i] != 0xFF; i += 2)
if (i2c_smbus_write_byte_data(client, regs[i], regs[i + 1]) < 0)
return -1;
return 0;
}
static int ov7640_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &ov7640_ops);
client->flags = I2C_CLIENT_SCCB;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
if (write_regs(client, initial_registers) < 0) {
v4l_err(client, "error initializing OV7640\n");
kfree(sd);
return -ENODEV;
}
return 0;
}
static int ov7640_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
