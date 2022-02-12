static inline struct bt856 *to_bt856(struct v4l2_subdev *sd)
{
return container_of(sd, struct bt856, sd);
}
static inline int bt856_write(struct bt856 *encoder, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(&encoder->sd);
encoder->reg[reg - BT856_REG_OFFSET] = value;
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int bt856_setbit(struct bt856 *encoder, u8 reg, u8 bit, u8 value)
{
return bt856_write(encoder, reg,
(encoder->reg[reg - BT856_REG_OFFSET] & ~(1 << bit)) |
(value ? (1 << bit) : 0));
}
static void bt856_dump(struct bt856 *encoder)
{
int i;
v4l2_info(&encoder->sd, "register dump:\n");
for (i = 0; i < BT856_NR_REG; i += 2)
printk(KERN_CONT " %02x", encoder->reg[i]);
printk(KERN_CONT "\n");
}
static int bt856_init(struct v4l2_subdev *sd, u32 arg)
{
struct bt856 *encoder = to_bt856(sd);
v4l2_dbg(1, debug, sd, "init\n");
bt856_write(encoder, 0xdc, 0x18);
bt856_write(encoder, 0xda, 0);
bt856_write(encoder, 0xde, 0);
bt856_setbit(encoder, 0xdc, 3, 1);
bt856_setbit(encoder, 0xdc, 4, 1);
if (encoder->norm & V4L2_STD_NTSC)
bt856_setbit(encoder, 0xdc, 2, 0);
else
bt856_setbit(encoder, 0xdc, 2, 1);
bt856_setbit(encoder, 0xdc, 1, 1);
bt856_setbit(encoder, 0xde, 4, 0);
bt856_setbit(encoder, 0xde, 3, 1);
if (debug != 0)
bt856_dump(encoder);
return 0;
}
static int bt856_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct bt856 *encoder = to_bt856(sd);
v4l2_dbg(1, debug, sd, "set norm %llx\n", (unsigned long long)std);
if (std & V4L2_STD_NTSC) {
bt856_setbit(encoder, 0xdc, 2, 0);
} else if (std & V4L2_STD_PAL) {
bt856_setbit(encoder, 0xdc, 2, 1);
bt856_setbit(encoder, 0xda, 0, 0);
} else {
return -EINVAL;
}
encoder->norm = std;
if (debug != 0)
bt856_dump(encoder);
return 0;
}
static int bt856_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct bt856 *encoder = to_bt856(sd);
v4l2_dbg(1, debug, sd, "set input %d\n", input);
switch (input) {
case 0:
bt856_setbit(encoder, 0xde, 4, 0);
bt856_setbit(encoder, 0xde, 3, 1);
bt856_setbit(encoder, 0xdc, 3, 1);
bt856_setbit(encoder, 0xdc, 6, 0);
break;
case 1:
bt856_setbit(encoder, 0xde, 4, 0);
bt856_setbit(encoder, 0xde, 3, 1);
bt856_setbit(encoder, 0xdc, 3, 1);
bt856_setbit(encoder, 0xdc, 6, 1);
break;
case 2:
bt856_setbit(encoder, 0xdc, 3, 0);
bt856_setbit(encoder, 0xde, 4, 1);
break;
default:
return -EINVAL;
}
if (debug != 0)
bt856_dump(encoder);
return 0;
}
static int bt856_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bt856 *encoder;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
encoder = devm_kzalloc(&client->dev, sizeof(*encoder), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
sd = &encoder->sd;
v4l2_i2c_subdev_init(sd, client, &bt856_ops);
encoder->norm = V4L2_STD_NTSC;
bt856_write(encoder, 0xdc, 0x18);
bt856_write(encoder, 0xda, 0);
bt856_write(encoder, 0xde, 0);
bt856_setbit(encoder, 0xdc, 3, 1);
bt856_setbit(encoder, 0xdc, 4, 1);
if (encoder->norm & V4L2_STD_NTSC)
bt856_setbit(encoder, 0xdc, 2, 0);
else
bt856_setbit(encoder, 0xdc, 2, 1);
bt856_setbit(encoder, 0xdc, 1, 1);
bt856_setbit(encoder, 0xde, 4, 0);
bt856_setbit(encoder, 0xde, 3, 1);
if (debug != 0)
bt856_dump(encoder);
return 0;
}
static int bt856_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
return 0;
}
