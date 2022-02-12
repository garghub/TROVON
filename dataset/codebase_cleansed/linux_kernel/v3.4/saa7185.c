static inline struct saa7185 *to_saa7185(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa7185, sd);
}
static inline int saa7185_read(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte(client);
}
static int saa7185_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct saa7185 *encoder = to_saa7185(sd);
v4l2_dbg(1, debug, sd, "%02x set to %02x\n", reg, value);
encoder->reg[reg] = value;
return i2c_smbus_write_byte_data(client, reg, value);
}
static int saa7185_write_block(struct v4l2_subdev *sd,
const u8 *data, unsigned int len)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct saa7185 *encoder = to_saa7185(sd);
int ret = -1;
u8 reg;
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
u8 block_data[32];
int block_len;
while (len >= 2) {
block_len = 0;
block_data[block_len++] = reg = data[0];
do {
block_data[block_len++] =
encoder->reg[reg++] = data[1];
len -= 2;
data += 2;
} while (len >= 2 && data[0] == reg && block_len < 32);
ret = i2c_master_send(client, block_data, block_len);
if (ret < 0)
break;
}
} else {
while (len >= 2) {
reg = *data++;
ret = saa7185_write(sd, reg, *data++);
if (ret < 0)
break;
len -= 2;
}
}
return ret;
}
static int saa7185_init(struct v4l2_subdev *sd, u32 val)
{
struct saa7185 *encoder = to_saa7185(sd);
saa7185_write_block(sd, init_common, sizeof(init_common));
if (encoder->norm & V4L2_STD_NTSC)
saa7185_write_block(sd, init_ntsc, sizeof(init_ntsc));
else
saa7185_write_block(sd, init_pal, sizeof(init_pal));
return 0;
}
static int saa7185_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa7185 *encoder = to_saa7185(sd);
if (std & V4L2_STD_NTSC)
saa7185_write_block(sd, init_ntsc, sizeof(init_ntsc));
else if (std & V4L2_STD_PAL)
saa7185_write_block(sd, init_pal, sizeof(init_pal));
else
return -EINVAL;
encoder->norm = std;
return 0;
}
static int saa7185_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa7185 *encoder = to_saa7185(sd);
switch (input) {
case 0:
saa7185_write(sd, 0x3a, 0x0f);
saa7185_write(sd, 0x61, (encoder->reg[0x61] & 0xf7) | 0x08);
saa7185_write(sd, 0x6e, 0x01);
break;
case 1:
saa7185_write(sd, 0x3a, 0x0f);
saa7185_write(sd, 0x61, (encoder->reg[0x61] & 0xf7) | 0x00);
saa7185_write(sd, 0x6e, 0x00);
break;
case 2:
saa7185_write(sd, 0x3a, 0x8f);
saa7185_write(sd, 0x61, (encoder->reg[0x61] & 0xf7) | 0x08);
saa7185_write(sd, 0x6e, 0x01);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa7185_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_SAA7185, 0);
}
static int saa7185_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int i;
struct saa7185 *encoder;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
encoder = kzalloc(sizeof(struct saa7185), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
encoder->norm = V4L2_STD_NTSC;
sd = &encoder->sd;
v4l2_i2c_subdev_init(sd, client, &saa7185_ops);
i = saa7185_write_block(sd, init_common, sizeof(init_common));
if (i >= 0)
i = saa7185_write_block(sd, init_ntsc, sizeof(init_ntsc));
if (i < 0)
v4l2_dbg(1, debug, sd, "init error %d\n", i);
else
v4l2_dbg(1, debug, sd, "revision 0x%x\n",
saa7185_read(sd) >> 5);
return 0;
}
static int saa7185_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct saa7185 *encoder = to_saa7185(sd);
v4l2_device_unregister_subdev(sd);
saa7185_write(sd, 0x61, (encoder->reg[0x61]) | 0x40);
kfree(encoder);
return 0;
}
