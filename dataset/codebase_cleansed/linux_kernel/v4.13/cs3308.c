static inline int cs3308_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int cs3308_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int cs3308_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
reg->val = cs3308_read(sd, reg->reg & 0xffff);
reg->size = 1;
return 0;
}
static int cs3308_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
cs3308_write(sd, reg->reg & 0xffff, reg->val & 0xff);
return 0;
}
static int cs3308_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
unsigned i;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
if ((i2c_smbus_read_byte_data(client, 0x1c) & 0xf0) != 0xe0)
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &cs3308_ops);
cs3308_write(sd, 0x0d, 0x00);
cs3308_write(sd, 0x0e, 0x00);
cs3308_write(sd, 0x0b, 0x00);
for (i = 1; i <= 8; i++)
cs3308_write(sd, i, 0xd2);
cs3308_write(sd, 0x0a, 0x00);
return 0;
}
static int cs3308_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
