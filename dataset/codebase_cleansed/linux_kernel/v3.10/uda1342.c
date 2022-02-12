static int write_reg(struct i2c_client *client, int reg, int value)
{
i2c_smbus_write_word_data(client, reg, swab16(value));
return 0;
}
static int uda1342_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
switch (input) {
case UDA1342_IN1:
write_reg(client, 0x00, 0x1241);
break;
case UDA1342_IN2:
write_reg(client, 0x00, 0x1441);
break;
default:
v4l2_err(sd, "input %d not supported\n", input);
break;
}
return 0;
}
static int uda1342_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
dev_dbg(&client->dev, "initializing UDA1342 at address %d on %s\n",
client->addr, adapter->name);
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &uda1342_ops);
write_reg(client, 0x00, 0x8000);
write_reg(client, 0x00, 0x1241);
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
return 0;
}
static int uda1342_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
