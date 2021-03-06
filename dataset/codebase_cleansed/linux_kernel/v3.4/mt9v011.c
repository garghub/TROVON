static inline struct mt9v011 *to_mt9v011(struct v4l2_subdev *sd)
{
return container_of(sd, struct mt9v011, sd);
}
static int mt9v011_read(struct v4l2_subdev *sd, unsigned char addr)
{
struct i2c_client *c = v4l2_get_subdevdata(sd);
__be16 buffer;
int rc, val;
rc = i2c_master_send(c, &addr, 1);
if (rc != 1)
v4l2_dbg(0, debug, sd,
"i2c i/o error: rc == %d (should be 1)\n", rc);
msleep(10);
rc = i2c_master_recv(c, (char *)&buffer, 2);
if (rc != 2)
v4l2_dbg(0, debug, sd,
"i2c i/o error: rc == %d (should be 2)\n", rc);
val = be16_to_cpu(buffer);
v4l2_dbg(2, debug, sd, "mt9v011: read 0x%02x = 0x%04x\n", addr, val);
return val;
}
static void mt9v011_write(struct v4l2_subdev *sd, unsigned char addr,
u16 value)
{
struct i2c_client *c = v4l2_get_subdevdata(sd);
unsigned char buffer[3];
int rc;
buffer[0] = addr;
buffer[1] = value >> 8;
buffer[2] = value & 0xff;
v4l2_dbg(2, debug, sd,
"mt9v011: writing 0x%02x 0x%04x\n", buffer[0], value);
rc = i2c_master_send(c, buffer, 3);
if (rc != 3)
v4l2_dbg(0, debug, sd,
"i2c i/o error: rc == %d (should be 3)\n", rc);
}
static u16 calc_mt9v011_gain(s16 lineargain)
{
u16 digitalgain = 0;
u16 analogmult = 0;
u16 analoginit = 0;
if (lineargain < 0)
lineargain = 0;
lineargain += 0x0020;
if (lineargain > 2047)
lineargain = 2047;
if (lineargain > 1023) {
digitalgain = 3;
analogmult = 3;
analoginit = lineargain / 16;
} else if (lineargain > 511) {
digitalgain = 1;
analogmult = 3;
analoginit = lineargain / 8;
} else if (lineargain > 255) {
analogmult = 3;
analoginit = lineargain / 4;
} else if (lineargain > 127) {
analogmult = 1;
analoginit = lineargain / 2;
} else
analoginit = lineargain;
return analoginit + (analogmult << 7) + (digitalgain << 9);
}
static void set_balance(struct v4l2_subdev *sd)
{
struct mt9v011 *core = to_mt9v011(sd);
u16 green_gain, blue_gain, red_gain;
u16 exposure;
s16 bal;
exposure = core->exposure;
green_gain = calc_mt9v011_gain(core->global_gain);
bal = core->global_gain;
bal += (core->blue_bal * core->global_gain / (1 << 7));
blue_gain = calc_mt9v011_gain(bal);
bal = core->global_gain;
bal += (core->red_bal * core->global_gain / (1 << 7));
red_gain = calc_mt9v011_gain(bal);
mt9v011_write(sd, R2B_MT9V011_GREEN_1_GAIN, green_gain);
mt9v011_write(sd, R2E_MT9V011_GREEN_2_GAIN, green_gain);
mt9v011_write(sd, R2C_MT9V011_BLUE_GAIN, blue_gain);
mt9v011_write(sd, R2D_MT9V011_RED_GAIN, red_gain);
mt9v011_write(sd, R09_MT9V011_SHUTTER_WIDTH, exposure);
}
static void calc_fps(struct v4l2_subdev *sd, u32 *numerator, u32 *denominator)
{
struct mt9v011 *core = to_mt9v011(sd);
unsigned height, width, hblank, vblank, speed;
unsigned row_time, t_time;
u64 frames_per_ms;
unsigned tmp;
height = mt9v011_read(sd, R03_MT9V011_HEIGHT);
width = mt9v011_read(sd, R04_MT9V011_WIDTH);
hblank = mt9v011_read(sd, R05_MT9V011_HBLANK);
vblank = mt9v011_read(sd, R06_MT9V011_VBLANK);
speed = mt9v011_read(sd, R0A_MT9V011_CLK_SPEED);
row_time = (width + 113 + hblank) * (speed + 2);
t_time = row_time * (height + vblank + 1);
frames_per_ms = core->xtal * 1000l;
do_div(frames_per_ms, t_time);
tmp = frames_per_ms;
v4l2_dbg(1, debug, sd, "Programmed to %u.%03u fps (%d pixel clcks)\n",
tmp / 1000, tmp % 1000, t_time);
if (numerator && denominator) {
*numerator = 1000;
*denominator = (u32)frames_per_ms;
}
}
static u16 calc_speed(struct v4l2_subdev *sd, u32 numerator, u32 denominator)
{
struct mt9v011 *core = to_mt9v011(sd);
unsigned height, width, hblank, vblank;
unsigned row_time, line_time;
u64 t_time, speed;
if (!numerator || !denominator)
return 0;
height = mt9v011_read(sd, R03_MT9V011_HEIGHT);
width = mt9v011_read(sd, R04_MT9V011_WIDTH);
hblank = mt9v011_read(sd, R05_MT9V011_HBLANK);
vblank = mt9v011_read(sd, R06_MT9V011_VBLANK);
row_time = width + 113 + hblank;
line_time = height + vblank + 1;
t_time = core->xtal * ((u64)numerator);
t_time += denominator / 2;
do_div(t_time, denominator);
speed = t_time;
do_div(speed, row_time * line_time);
if (speed < 2)
speed = 0;
else
speed -= 2;
if (speed > 15)
return 15;
return (u16)speed;
}
static void set_res(struct v4l2_subdev *sd)
{
struct mt9v011 *core = to_mt9v011(sd);
unsigned vstart, hstart;
hstart = 20 + (640 - core->width) / 2;
mt9v011_write(sd, R02_MT9V011_COLSTART, hstart);
mt9v011_write(sd, R04_MT9V011_WIDTH, core->width);
mt9v011_write(sd, R05_MT9V011_HBLANK, 771 - core->width);
vstart = 8 + (480 - core->height) / 2;
mt9v011_write(sd, R01_MT9V011_ROWSTART, vstart);
mt9v011_write(sd, R03_MT9V011_HEIGHT, core->height);
mt9v011_write(sd, R06_MT9V011_VBLANK, 508 - core->height);
calc_fps(sd, NULL, NULL);
}
static void set_read_mode(struct v4l2_subdev *sd)
{
struct mt9v011 *core = to_mt9v011(sd);
unsigned mode = 0x1000;
if (core->hflip)
mode |= 0x4000;
if (core->vflip)
mode |= 0x8000;
mt9v011_write(sd, R20_MT9V011_READ_MODE, mode);
}
static int mt9v011_reset(struct v4l2_subdev *sd, u32 val)
{
int i;
for (i = 0; i < ARRAY_SIZE(mt9v011_init_default); i++)
mt9v011_write(sd, mt9v011_init_default[i].reg,
mt9v011_init_default[i].value);
set_balance(sd);
set_res(sd);
set_read_mode(sd);
return 0;
}
static int mt9v011_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct mt9v011 *core = to_mt9v011(sd);
v4l2_dbg(1, debug, sd, "g_ctrl called\n");
switch (ctrl->id) {
case V4L2_CID_GAIN:
ctrl->value = core->global_gain;
return 0;
case V4L2_CID_EXPOSURE:
ctrl->value = core->exposure;
return 0;
case V4L2_CID_RED_BALANCE:
ctrl->value = core->red_bal;
return 0;
case V4L2_CID_BLUE_BALANCE:
ctrl->value = core->blue_bal;
return 0;
case V4L2_CID_HFLIP:
ctrl->value = core->hflip ? 1 : 0;
return 0;
case V4L2_CID_VFLIP:
ctrl->value = core->vflip ? 1 : 0;
return 0;
}
return -EINVAL;
}
static int mt9v011_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
int i;
v4l2_dbg(1, debug, sd, "queryctrl called\n");
for (i = 0; i < ARRAY_SIZE(mt9v011_qctrl); i++)
if (qc->id && qc->id == mt9v011_qctrl[i].id) {
memcpy(qc, &(mt9v011_qctrl[i]),
sizeof(*qc));
return 0;
}
return -EINVAL;
}
static int mt9v011_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct mt9v011 *core = to_mt9v011(sd);
u8 i, n;
n = ARRAY_SIZE(mt9v011_qctrl);
for (i = 0; i < n; i++) {
if (ctrl->id != mt9v011_qctrl[i].id)
continue;
if (ctrl->value < mt9v011_qctrl[i].minimum ||
ctrl->value > mt9v011_qctrl[i].maximum)
return -ERANGE;
v4l2_dbg(1, debug, sd, "s_ctrl: id=%d, value=%d\n",
ctrl->id, ctrl->value);
break;
}
switch (ctrl->id) {
case V4L2_CID_GAIN:
core->global_gain = ctrl->value;
break;
case V4L2_CID_EXPOSURE:
core->exposure = ctrl->value;
break;
case V4L2_CID_RED_BALANCE:
core->red_bal = ctrl->value;
break;
case V4L2_CID_BLUE_BALANCE:
core->blue_bal = ctrl->value;
break;
case V4L2_CID_HFLIP:
core->hflip = ctrl->value;
set_read_mode(sd);
return 0;
case V4L2_CID_VFLIP:
core->vflip = ctrl->value;
set_read_mode(sd);
return 0;
default:
return -EINVAL;
}
set_balance(sd);
return 0;
}
static int mt9v011_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned index,
enum v4l2_mbus_pixelcode *code)
{
if (index > 0)
return -EINVAL;
*code = V4L2_MBUS_FMT_SGRBG8_1X8;
return 0;
}
static int mt9v011_try_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
if (fmt->code != V4L2_MBUS_FMT_SGRBG8_1X8)
return -EINVAL;
v4l_bound_align_image(&fmt->width, 48, 639, 1,
&fmt->height, 32, 480, 1, 0);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int mt9v011_g_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct v4l2_captureparm *cp = &parms->parm.capture;
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
memset(cp, 0, sizeof(struct v4l2_captureparm));
cp->capability = V4L2_CAP_TIMEPERFRAME;
calc_fps(sd,
&cp->timeperframe.numerator,
&cp->timeperframe.denominator);
return 0;
}
static int mt9v011_s_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *parms)
{
struct v4l2_captureparm *cp = &parms->parm.capture;
struct v4l2_fract *tpf = &cp->timeperframe;
u16 speed;
if (parms->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (cp->extendedmode != 0)
return -EINVAL;
speed = calc_speed(sd, tpf->numerator, tpf->denominator);
mt9v011_write(sd, R0A_MT9V011_CLK_SPEED, speed);
v4l2_dbg(1, debug, sd, "Setting speed to %d\n", speed);
calc_fps(sd, &tpf->numerator, &tpf->denominator);
return 0;
}
static int mt9v011_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
struct mt9v011 *core = to_mt9v011(sd);
int rc;
rc = mt9v011_try_mbus_fmt(sd, fmt);
if (rc < 0)
return -EINVAL;
core->width = fmt->width;
core->height = fmt->height;
set_res(sd);
return 0;
}
static int mt9v011_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = mt9v011_read(sd, reg->reg & 0xff);
reg->size = 2;
return 0;
}
static int mt9v011_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
mt9v011_write(sd, reg->reg & 0xff, reg->val & 0xffff);
return 0;
}
static int mt9v011_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
u16 version;
struct i2c_client *client = v4l2_get_subdevdata(sd);
version = mt9v011_read(sd, R00_MT9V011_CHIP_VERSION);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_MT9V011,
version);
}
static int mt9v011_probe(struct i2c_client *c,
const struct i2c_device_id *id)
{
u16 version;
struct mt9v011 *core;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(c->adapter,
I2C_FUNC_SMBUS_READ_BYTE | I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -EIO;
core = kzalloc(sizeof(struct mt9v011), GFP_KERNEL);
if (!core)
return -ENOMEM;
sd = &core->sd;
v4l2_i2c_subdev_init(sd, c, &mt9v011_ops);
version = mt9v011_read(sd, R00_MT9V011_CHIP_VERSION);
if ((version != MT9V011_VERSION) &&
(version != MT9V011_REV_B_VERSION)) {
v4l2_info(sd, "*** unknown micron chip detected (0x%04x).\n",
version);
kfree(core);
return -EINVAL;
}
core->global_gain = 0x0024;
core->exposure = 0x01fc;
core->width = 640;
core->height = 480;
core->xtal = 27000000;
if (c->dev.platform_data) {
struct mt9v011_platform_data *pdata = c->dev.platform_data;
core->xtal = pdata->xtal;
v4l2_dbg(1, debug, sd, "xtal set to %d.%03d MHz\n",
core->xtal / 1000000, (core->xtal / 1000) % 1000);
}
v4l_info(c, "chip found @ 0x%02x (%s - chip version 0x%04x)\n",
c->addr << 1, c->adapter->name, version);
return 0;
}
static int mt9v011_remove(struct i2c_client *c)
{
struct v4l2_subdev *sd = i2c_get_clientdata(c);
v4l2_dbg(1, debug, sd,
"mt9v011.c: removing mt9v011 adapter on address 0x%x\n",
c->addr << 1);
v4l2_device_unregister_subdev(sd);
kfree(to_mt9v011(sd));
return 0;
}
