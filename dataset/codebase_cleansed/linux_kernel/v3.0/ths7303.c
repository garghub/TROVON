static int ths7303_setvalue(struct v4l2_subdev *sd, v4l2_std_id std)
{
int err = 0;
u8 val;
struct i2c_client *client;
client = v4l2_get_subdevdata(sd);
if (std & (V4L2_STD_ALL & ~V4L2_STD_SECAM)) {
val = 0x02;
v4l2_dbg(1, debug, sd, "setting value for SDTV format\n");
} else {
val = 0x00;
v4l2_dbg(1, debug, sd, "disabling all channels\n");
}
err |= i2c_smbus_write_byte_data(client, 0x01, val);
err |= i2c_smbus_write_byte_data(client, 0x02, val);
err |= i2c_smbus_write_byte_data(client, 0x03, val);
if (err)
v4l2_err(sd, "write failed\n");
return err;
}
static int ths7303_s_std_output(struct v4l2_subdev *sd, v4l2_std_id norm)
{
return ths7303_setvalue(sd, norm);
}
static int ths7303_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_THS7303, 0);
}
static int ths7303_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
v4l2_std_id std_id = V4L2_STD_NTSC;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &ths7303_ops);
return ths7303_setvalue(sd, std_id);
}
static int ths7303_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
static int __init ths7303_init(void)
{
return i2c_add_driver(&ths7303_driver);
}
static void __exit ths7303_exit(void)
{
i2c_del_driver(&ths7303_driver);
}
