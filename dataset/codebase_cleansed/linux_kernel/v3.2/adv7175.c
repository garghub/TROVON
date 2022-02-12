static inline struct adv7175 *to_adv7175(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7175, sd);
}
static inline int adv7175_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int adv7175_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int adv7175_write_block(struct v4l2_subdev *sd,
const u8 *data, unsigned int len)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = -1;
u8 reg;
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
u8 block_data[32];
int block_len;
while (len >= 2) {
block_len = 0;
block_data[block_len++] = reg = data[0];
do {
block_data[block_len++] = data[1];
reg++;
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
ret = adv7175_write(sd, reg, *data++);
if (ret < 0)
break;
len -= 2;
}
}
return ret;
}
static void set_subcarrier_freq(struct v4l2_subdev *sd, int pass_through)
{
if (pass_through)
adv7175_write(sd, 0x02, 0x00);
else
adv7175_write(sd, 0x02, 0x55);
adv7175_write(sd, 0x03, 0x55);
adv7175_write(sd, 0x04, 0x55);
adv7175_write(sd, 0x05, 0x25);
}
static int adv7175_init(struct v4l2_subdev *sd, u32 val)
{
adv7175_write_block(sd, init_common, sizeof(init_common));
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
return 0;
}
static int adv7175_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7175 *encoder = to_adv7175(sd);
if (std & V4L2_STD_NTSC) {
adv7175_write_block(sd, init_ntsc, sizeof(init_ntsc));
if (encoder->input == 0)
adv7175_write(sd, 0x0d, 0x4f);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
} else if (std & V4L2_STD_PAL) {
adv7175_write_block(sd, init_pal, sizeof(init_pal));
if (encoder->input == 0)
adv7175_write(sd, 0x0d, 0x4f);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
} else if (std & V4L2_STD_SECAM) {
adv7175_write_block(sd, init_pal, sizeof(init_pal));
if (encoder->input == 0)
adv7175_write(sd, 0x0d, 0x49);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
} else {
v4l2_dbg(1, debug, sd, "illegal norm: %llx\n",
(unsigned long long)std);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "switched to %llx\n", (unsigned long long)std);
encoder->norm = std;
return 0;
}
static int adv7175_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7175 *encoder = to_adv7175(sd);
switch (input) {
case 0:
adv7175_write(sd, 0x01, 0x00);
if (encoder->norm & V4L2_STD_NTSC)
set_subcarrier_freq(sd, 1);
adv7175_write(sd, 0x0c, TR1CAPT);
if (encoder->norm & V4L2_STD_SECAM)
adv7175_write(sd, 0x0d, 0x49);
else
adv7175_write(sd, 0x0d, 0x4f);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
break;
case 1:
adv7175_write(sd, 0x01, 0x00);
if (encoder->norm & V4L2_STD_NTSC)
set_subcarrier_freq(sd, 0);
adv7175_write(sd, 0x0c, TR1PLAY);
adv7175_write(sd, 0x0d, 0x49);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
break;
case 2:
adv7175_write(sd, 0x01, 0x80);
if (encoder->norm & V4L2_STD_NTSC)
set_subcarrier_freq(sd, 0);
adv7175_write(sd, 0x0d, 0x49);
adv7175_write(sd, 0x07, TR0MODE | TR0RST);
adv7175_write(sd, 0x07, TR0MODE);
break;
default:
v4l2_dbg(1, debug, sd, "illegal input: %d\n", input);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "switched to %s\n", inputs[input]);
encoder->input = input;
return 0;
}
static int adv7175_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index >= ARRAY_SIZE(adv7175_codes))
return -EINVAL;
*code = adv7175_codes[index];
return 0;
}
static int adv7175_g_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
u8 val = adv7175_read(sd, 0x7);
if ((val & 0x40) == (1 << 6))
mf->code = V4L2_MBUS_FMT_UYVY8_1X16;
else
mf->code = V4L2_MBUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
mf->width = 0;
mf->height = 0;
mf->field = V4L2_FIELD_ANY;
return 0;
}
static int adv7175_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
u8 val = adv7175_read(sd, 0x7);
int ret;
switch (mf->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
val &= ~0x40;
break;
case V4L2_MBUS_FMT_UYVY8_1X16:
val |= 0x40;
break;
default:
v4l2_dbg(1, debug, sd,
"illegal v4l2_mbus_framefmt code: %d\n", mf->code);
return -EINVAL;
}
ret = adv7175_write(sd, 0x7, val);
return ret;
}
static int adv7175_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_ADV7175, 0);
}
static int adv7175_s_power(struct v4l2_subdev *sd, int on)
{
if (on)
adv7175_write(sd, 0x01, 0x00);
else
adv7175_write(sd, 0x01, 0x78);
return 0;
}
static int adv7175_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int i;
struct adv7175 *encoder;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
encoder = kzalloc(sizeof(struct adv7175), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
sd = &encoder->sd;
v4l2_i2c_subdev_init(sd, client, &adv7175_ops);
encoder->norm = V4L2_STD_NTSC;
encoder->input = 0;
i = adv7175_write_block(sd, init_common, sizeof(init_common));
if (i >= 0) {
i = adv7175_write(sd, 0x07, TR0MODE | TR0RST);
i = adv7175_write(sd, 0x07, TR0MODE);
i = adv7175_read(sd, 0x12);
v4l2_dbg(1, debug, sd, "revision %d\n", i & 1);
}
if (i < 0)
v4l2_dbg(1, debug, sd, "init error 0x%x\n", i);
return 0;
}
static int adv7175_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_adv7175(sd));
return 0;
}
static __init int init_adv7175(void)
{
return i2c_add_driver(&adv7175_driver);
}
static __exit void exit_adv7175(void)
{
i2c_del_driver(&adv7175_driver);
}
