static inline struct saa7110 *to_saa7110(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa7110, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct saa7110, hdl)->sd;
}
static int saa7110_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct saa7110 *decoder = to_saa7110(sd);
decoder->reg[reg] = value;
return i2c_smbus_write_byte_data(client, reg, value);
}
static int saa7110_write_block(struct v4l2_subdev *sd, const u8 *data, unsigned int len)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct saa7110 *decoder = to_saa7110(sd);
int ret = -1;
u8 reg = *data;
if (reg + (len - 1) > SAA7110_NR_REG)
return ret;
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
ret = i2c_master_send(client, data, len);
memcpy(decoder->reg + reg, data + 1, len - 1);
} else {
for (++data, --len; len; len--) {
ret = saa7110_write(sd, reg++, *data++);
if (ret < 0)
break;
}
}
return ret;
}
static inline int saa7110_read(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte(client);
}
static int saa7110_selmux(struct v4l2_subdev *sd, int chan)
{
static const unsigned char modes[9][8] = {
{FRESP_06H_COMPST, 0xD9, 0x17, 0x40, 0x03,
0x44, 0x75, 0x16},
{FRESP_06H_COMPST, 0xD8, 0x17, 0x40, 0x03,
0x44, 0x75, 0x16},
{FRESP_06H_COMPST, 0xBA, 0x07, 0x91, 0x03,
0x60, 0xB5, 0x05},
{FRESP_06H_COMPST, 0xB8, 0x07, 0x91, 0x03,
0x60, 0xB5, 0x05},
{FRESP_06H_COMPST, 0x7C, 0x07, 0xD2, 0x83,
0x60, 0xB5, 0x03},
{FRESP_06H_COMPST, 0x78, 0x07, 0xD2, 0x83,
0x60, 0xB5, 0x03},
{FRESP_06H_SVIDEO, 0x59, 0x17, 0x42, 0xA3,
0x44, 0x75, 0x12},
{FRESP_06H_SVIDEO, 0x9A, 0x17, 0xB1, 0x13,
0x60, 0xB5, 0x14},
{FRESP_06H_SVIDEO, 0x3C, 0x27, 0xC1, 0x23,
0x44, 0x75, 0x21}
};
struct saa7110 *decoder = to_saa7110(sd);
const unsigned char *ptr = modes[chan];
saa7110_write(sd, 0x06, ptr[0]);
saa7110_write(sd, 0x20, ptr[1]);
saa7110_write(sd, 0x21, ptr[2]);
saa7110_write(sd, 0x22, ptr[3]);
saa7110_write(sd, 0x2C, ptr[4]);
saa7110_write(sd, 0x30, ptr[5]);
saa7110_write(sd, 0x31, ptr[6]);
saa7110_write(sd, 0x21, ptr[7]);
decoder->input = chan;
return 0;
}
static v4l2_std_id determine_norm(struct v4l2_subdev *sd)
{
DEFINE_WAIT(wait);
struct saa7110 *decoder = to_saa7110(sd);
int status;
saa7110_write_block(sd, initseq, sizeof(initseq));
saa7110_selmux(sd, decoder->input);
prepare_to_wait(&decoder->wq, &wait, TASK_UNINTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(250));
finish_wait(&decoder->wq, &wait);
status = saa7110_read(sd);
if (status & 0x40) {
v4l2_dbg(1, debug, sd, "status=0x%02x (no signal)\n", status);
return V4L2_STD_UNKNOWN;
}
if ((status & 3) == 0) {
saa7110_write(sd, 0x06, 0x83);
if (status & 0x20) {
v4l2_dbg(1, debug, sd, "status=0x%02x (NTSC/no color)\n", status);
return V4L2_STD_NTSC;
}
v4l2_dbg(1, debug, sd, "status=0x%02x (PAL/no color)\n", status);
return V4L2_STD_PAL;
}
if (status & 0x20) {
v4l2_dbg(1, debug, sd, "status=0x%02x (NTSC)\n", status);
saa7110_write(sd, 0x0D, 0x86);
saa7110_write(sd, 0x0F, 0x50);
saa7110_write(sd, 0x11, 0x2C);
return V4L2_STD_NTSC;
}
saa7110_write(sd, 0x0D, 0x86);
saa7110_write(sd, 0x0F, 0x10);
saa7110_write(sd, 0x11, 0x59);
prepare_to_wait(&decoder->wq, &wait, TASK_UNINTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(250));
finish_wait(&decoder->wq, &wait);
status = saa7110_read(sd);
if ((status & 0x03) == 0x01) {
v4l2_dbg(1, debug, sd, "status=0x%02x (SECAM)\n", status);
saa7110_write(sd, 0x0D, 0x87);
return V4L2_STD_SECAM;
}
v4l2_dbg(1, debug, sd, "status=0x%02x (PAL)\n", status);
return V4L2_STD_PAL;
}
static int saa7110_g_input_status(struct v4l2_subdev *sd, u32 *pstatus)
{
struct saa7110 *decoder = to_saa7110(sd);
int res = V4L2_IN_ST_NO_SIGNAL;
int status = saa7110_read(sd);
v4l2_dbg(1, debug, sd, "status=0x%02x norm=%llx\n",
status, (unsigned long long)decoder->norm);
if (!(status & 0x40))
res = 0;
if (!(status & 0x03))
res |= V4L2_IN_ST_NO_COLOR;
*pstatus = res;
return 0;
}
static int saa7110_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
*std &= determine_norm(sd);
return 0;
}
static int saa7110_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa7110 *decoder = to_saa7110(sd);
if (decoder->norm != std) {
decoder->norm = std;
if (std & V4L2_STD_NTSC) {
saa7110_write(sd, 0x0D, 0x86);
saa7110_write(sd, 0x0F, 0x50);
saa7110_write(sd, 0x11, 0x2C);
v4l2_dbg(1, debug, sd, "switched to NTSC\n");
} else if (std & V4L2_STD_PAL) {
saa7110_write(sd, 0x0D, 0x86);
saa7110_write(sd, 0x0F, 0x10);
saa7110_write(sd, 0x11, 0x59);
v4l2_dbg(1, debug, sd, "switched to PAL\n");
} else if (std & V4L2_STD_SECAM) {
saa7110_write(sd, 0x0D, 0x87);
saa7110_write(sd, 0x0F, 0x10);
saa7110_write(sd, 0x11, 0x59);
v4l2_dbg(1, debug, sd, "switched to SECAM\n");
} else {
return -EINVAL;
}
}
return 0;
}
static int saa7110_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa7110 *decoder = to_saa7110(sd);
if (input >= SAA7110_MAX_INPUT) {
v4l2_dbg(1, debug, sd, "input=%d not available\n", input);
return -EINVAL;
}
if (decoder->input != input) {
saa7110_selmux(sd, input);
v4l2_dbg(1, debug, sd, "switched to input=%d\n", input);
}
return 0;
}
static int saa7110_s_stream(struct v4l2_subdev *sd, int enable)
{
struct saa7110 *decoder = to_saa7110(sd);
if (decoder->enable != enable) {
decoder->enable = enable;
saa7110_write(sd, 0x0E, enable ? 0x18 : 0x80);
v4l2_dbg(1, debug, sd, "YUV %s\n", enable ? "on" : "off");
}
return 0;
}
static int saa7110_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
saa7110_write(sd, 0x19, ctrl->val);
break;
case V4L2_CID_CONTRAST:
saa7110_write(sd, 0x13, ctrl->val);
break;
case V4L2_CID_SATURATION:
saa7110_write(sd, 0x12, ctrl->val);
break;
case V4L2_CID_HUE:
saa7110_write(sd, 0x07, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa7110_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa7110 *decoder;
struct v4l2_subdev *sd;
int rv;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE | I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -ENODEV;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
decoder = devm_kzalloc(&client->dev, sizeof(*decoder), GFP_KERNEL);
if (!decoder)
return -ENOMEM;
sd = &decoder->sd;
v4l2_i2c_subdev_init(sd, client, &saa7110_ops);
decoder->norm = V4L2_STD_PAL;
decoder->input = 0;
decoder->enable = 1;
v4l2_ctrl_handler_init(&decoder->hdl, 2);
v4l2_ctrl_new_std(&decoder->hdl, &saa7110_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&decoder->hdl, &saa7110_ctrl_ops,
V4L2_CID_CONTRAST, 0, 127, 1, 64);
v4l2_ctrl_new_std(&decoder->hdl, &saa7110_ctrl_ops,
V4L2_CID_SATURATION, 0, 127, 1, 64);
v4l2_ctrl_new_std(&decoder->hdl, &saa7110_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
sd->ctrl_handler = &decoder->hdl;
if (decoder->hdl.error) {
int err = decoder->hdl.error;
v4l2_ctrl_handler_free(&decoder->hdl);
return err;
}
v4l2_ctrl_handler_setup(&decoder->hdl);
init_waitqueue_head(&decoder->wq);
rv = saa7110_write_block(sd, initseq, sizeof(initseq));
if (rv < 0) {
v4l2_dbg(1, debug, sd, "init status %d\n", rv);
} else {
int ver, status;
saa7110_write(sd, 0x21, 0x10);
saa7110_write(sd, 0x0e, 0x18);
saa7110_write(sd, 0x0D, 0x04);
ver = saa7110_read(sd);
saa7110_write(sd, 0x0D, 0x06);
status = saa7110_read(sd);
v4l2_dbg(1, debug, sd, "version %x, status=0x%02x\n",
ver, status);
saa7110_write(sd, 0x0D, 0x86);
saa7110_write(sd, 0x0F, 0x10);
saa7110_write(sd, 0x11, 0x59);
}
return 0;
}
static int saa7110_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct saa7110 *decoder = to_saa7110(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&decoder->hdl);
return 0;
}
