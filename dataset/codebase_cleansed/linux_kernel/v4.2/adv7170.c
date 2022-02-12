static inline struct adv7170 *to_adv7170(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7170, sd);
}
static inline int adv7170_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct adv7170 *encoder = to_adv7170(sd);
encoder->reg[reg] = value;
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int adv7170_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int adv7170_write_block(struct v4l2_subdev *sd,
const u8 *data, unsigned int len)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct adv7170 *encoder = to_adv7170(sd);
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
ret = adv7170_write(sd, reg, *data++);
if (ret < 0)
break;
len -= 2;
}
}
return ret;
}
static int adv7170_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7170 *encoder = to_adv7170(sd);
v4l2_dbg(1, debug, sd, "set norm %llx\n", (unsigned long long)std);
if (std & V4L2_STD_NTSC) {
adv7170_write_block(sd, init_NTSC, sizeof(init_NTSC));
if (encoder->input == 0)
adv7170_write(sd, 0x02, 0x0e);
adv7170_write(sd, 0x07, TR0MODE | TR0RST);
adv7170_write(sd, 0x07, TR0MODE);
} else if (std & V4L2_STD_PAL) {
adv7170_write_block(sd, init_PAL, sizeof(init_PAL));
if (encoder->input == 0)
adv7170_write(sd, 0x02, 0x0e);
adv7170_write(sd, 0x07, TR0MODE | TR0RST);
adv7170_write(sd, 0x07, TR0MODE);
} else {
v4l2_dbg(1, debug, sd, "illegal norm: %llx\n",
(unsigned long long)std);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "switched to %llx\n", (unsigned long long)std);
encoder->norm = std;
return 0;
}
static int adv7170_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7170 *encoder = to_adv7170(sd);
v4l2_dbg(1, debug, sd, "set input from %s\n",
input == 0 ? "decoder" : "ZR36060");
switch (input) {
case 0:
adv7170_write(sd, 0x01, 0x20);
adv7170_write(sd, 0x08, TR1CAPT);
adv7170_write(sd, 0x02, 0x0e);
adv7170_write(sd, 0x07, TR0MODE | TR0RST);
adv7170_write(sd, 0x07, TR0MODE);
break;
case 1:
adv7170_write(sd, 0x01, 0x00);
adv7170_write(sd, 0x08, TR1PLAY);
adv7170_write(sd, 0x02, 0x08);
adv7170_write(sd, 0x07, TR0MODE | TR0RST);
adv7170_write(sd, 0x07, TR0MODE);
break;
default:
v4l2_dbg(1, debug, sd, "illegal input: %d\n", input);
return -EINVAL;
}
v4l2_dbg(1, debug, sd, "switched to %s\n", inputs[input]);
encoder->input = input;
return 0;
}
static int adv7170_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad || code->index >= ARRAY_SIZE(adv7170_codes))
return -EINVAL;
code->code = adv7170_codes[code->index];
return 0;
}
static int adv7170_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
u8 val = adv7170_read(sd, 0x7);
if (format->pad)
return -EINVAL;
if ((val & 0x40) == (1 << 6))
mf->code = MEDIA_BUS_FMT_UYVY8_1X16;
else
mf->code = MEDIA_BUS_FMT_UYVY8_2X8;
mf->colorspace = V4L2_COLORSPACE_SMPTE170M;
mf->width = 0;
mf->height = 0;
mf->field = V4L2_FIELD_ANY;
return 0;
}
static int adv7170_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *mf = &format->format;
u8 val = adv7170_read(sd, 0x7);
int ret = 0;
if (format->pad)
return -EINVAL;
switch (mf->code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
val &= ~0x40;
break;
case MEDIA_BUS_FMT_UYVY8_1X16:
val |= 0x40;
break;
default:
v4l2_dbg(1, debug, sd,
"illegal v4l2_mbus_framefmt code: %d\n", mf->code);
return -EINVAL;
}
if (format->which == V4L2_SUBDEV_FORMAT_ACTIVE)
ret = adv7170_write(sd, 0x7, val);
return ret;
}
static int adv7170_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7170 *encoder;
struct v4l2_subdev *sd;
int i;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
encoder = devm_kzalloc(&client->dev, sizeof(*encoder), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
sd = &encoder->sd;
v4l2_i2c_subdev_init(sd, client, &adv7170_ops);
encoder->norm = V4L2_STD_NTSC;
encoder->input = 0;
i = adv7170_write_block(sd, init_NTSC, sizeof(init_NTSC));
if (i >= 0) {
i = adv7170_write(sd, 0x07, TR0MODE | TR0RST);
i = adv7170_write(sd, 0x07, TR0MODE);
i = adv7170_read(sd, 0x12);
v4l2_dbg(1, debug, sd, "revision %d\n", i & 1);
}
if (i < 0)
v4l2_dbg(1, debug, sd, "init error 0x%x\n", i);
return 0;
}
static int adv7170_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
return 0;
}
