static int tea6415c_s_routing(struct v4l2_subdev *sd,
u32 i, u32 o, u32 config)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 byte = 0;
int ret;
v4l2_dbg(1, debug, sd, "i=%d, o=%d\n", i, o);
if (0 == ((1 == i || 3 == i || 5 == i || 6 == i || 8 == i || 10 == i || 20 == i || 11 == i)
&& (18 == o || 17 == o || 16 == o || 15 == o || 14 == o || 13 == o)))
return -EINVAL;
switch (o) {
case 18:
byte = 0x00;
break;
case 14:
byte = 0x20;
break;
case 16:
byte = 0x10;
break;
case 17:
byte = 0x08;
break;
case 15:
byte = 0x18;
break;
case 13:
byte = 0x28;
break;
};
switch (i) {
case 5:
byte |= 0x00;
break;
case 8:
byte |= 0x04;
break;
case 3:
byte |= 0x02;
break;
case 20:
byte |= 0x06;
break;
case 6:
byte |= 0x01;
break;
case 10:
byte |= 0x05;
break;
case 1:
byte |= 0x03;
break;
case 11:
byte |= 0x07;
break;
};
ret = i2c_smbus_write_byte(client, byte);
if (ret) {
v4l2_dbg(1, debug, sd,
"i2c_smbus_write_byte() failed, ret:%d\n", ret);
return -EIO;
}
return ret;
}
static int tea6415c_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_TEA6415C, 0);
}
static int tea6415c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WRITE_BYTE))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
sd = kzalloc(sizeof(struct v4l2_subdev), GFP_KERNEL);
if (sd == NULL)
return -ENOMEM;
v4l2_i2c_subdev_init(sd, client, &tea6415c_ops);
return 0;
}
static int tea6415c_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(sd);
return 0;
}
static __init int init_tea6415c(void)
{
return i2c_add_driver(&tea6415c_driver);
}
static __exit void exit_tea6415c(void)
{
i2c_del_driver(&tea6415c_driver);
}
