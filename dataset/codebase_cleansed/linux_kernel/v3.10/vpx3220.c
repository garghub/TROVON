static inline struct vpx3220 *to_vpx3220(struct v4l2_subdev *sd)
{
return container_of(sd, struct vpx3220, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct vpx3220, hdl)->sd;
}
static inline int vpx3220_write(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct vpx3220 *decoder = i2c_get_clientdata(client);
decoder->reg[reg] = value;
return i2c_smbus_write_byte_data(client, reg, value);
}
static inline int vpx3220_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int vpx3220_fp_status(struct v4l2_subdev *sd)
{
unsigned char status;
unsigned int i;
for (i = 0; i < VPX_TIMEOUT_COUNT; i++) {
status = vpx3220_read(sd, 0x29);
if (!(status & 4))
return 0;
udelay(10);
if (need_resched())
cond_resched();
}
return -1;
}
static int vpx3220_fp_write(struct v4l2_subdev *sd, u8 fpaddr, u16 data)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (i2c_smbus_write_word_data(client, 0x27, swab16(fpaddr)) == -1) {
v4l2_dbg(1, debug, sd, "%s: failed\n", __func__);
return -1;
}
if (vpx3220_fp_status(sd) < 0)
return -1;
if (i2c_smbus_write_word_data(client, 0x28, swab16(data)) == -1) {
v4l2_dbg(1, debug, sd, "%s: failed\n", __func__);
return -1;
}
return 0;
}
static u16 vpx3220_fp_read(struct v4l2_subdev *sd, u16 fpaddr)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
s16 data;
if (i2c_smbus_write_word_data(client, 0x26, swab16(fpaddr)) == -1) {
v4l2_dbg(1, debug, sd, "%s: failed\n", __func__);
return -1;
}
if (vpx3220_fp_status(sd) < 0)
return -1;
data = i2c_smbus_read_word_data(client, 0x28);
if (data == -1) {
v4l2_dbg(1, debug, sd, "%s: failed\n", __func__);
return -1;
}
return swab16(data);
}
static int vpx3220_write_block(struct v4l2_subdev *sd, const u8 *data, unsigned int len)
{
u8 reg;
int ret = -1;
while (len >= 2) {
reg = *data++;
ret = vpx3220_write(sd, reg, *data++);
if (ret < 0)
break;
len -= 2;
}
return ret;
}
static int vpx3220_write_fp_block(struct v4l2_subdev *sd,
const u16 *data, unsigned int len)
{
u8 reg;
int ret = 0;
while (len > 1) {
reg = *data++;
ret |= vpx3220_fp_write(sd, reg, *data++);
len -= 2;
}
return ret;
}
static int vpx3220_init(struct v4l2_subdev *sd, u32 val)
{
struct vpx3220 *decoder = to_vpx3220(sd);
vpx3220_write_block(sd, init_common, sizeof(init_common));
vpx3220_write_fp_block(sd, init_fp, sizeof(init_fp) >> 1);
if (decoder->norm & V4L2_STD_NTSC)
vpx3220_write_fp_block(sd, init_ntsc, sizeof(init_ntsc) >> 1);
else if (decoder->norm & V4L2_STD_PAL)
vpx3220_write_fp_block(sd, init_pal, sizeof(init_pal) >> 1);
else if (decoder->norm & V4L2_STD_SECAM)
vpx3220_write_fp_block(sd, init_secam, sizeof(init_secam) >> 1);
else
vpx3220_write_fp_block(sd, init_pal, sizeof(init_pal) >> 1);
return 0;
}
static int vpx3220_status(struct v4l2_subdev *sd, u32 *pstatus, v4l2_std_id *pstd)
{
int res = V4L2_IN_ST_NO_SIGNAL, status;
v4l2_std_id std = 0;
status = vpx3220_fp_read(sd, 0x0f3);
v4l2_dbg(1, debug, sd, "status: 0x%04x\n", status);
if (status < 0)
return status;
if ((status & 0x20) == 0) {
res = 0;
switch (status & 0x18) {
case 0x00:
case 0x10:
case 0x14:
case 0x18:
std = V4L2_STD_PAL;
break;
case 0x08:
std = V4L2_STD_SECAM;
break;
case 0x04:
case 0x0c:
case 0x1c:
std = V4L2_STD_NTSC;
break;
}
}
if (pstd)
*pstd = std;
if (pstatus)
*pstatus = res;
return 0;
}
static int vpx3220_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
v4l2_dbg(1, debug, sd, "querystd\n");
return vpx3220_status(sd, NULL, std);
}
static int vpx3220_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
v4l2_dbg(1, debug, sd, "g_input_status\n");
return vpx3220_status(sd, status, NULL);
}
static int vpx3220_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct vpx3220 *decoder = to_vpx3220(sd);
int temp_input;
temp_input = vpx3220_fp_read(sd, 0xf2);
v4l2_dbg(1, debug, sd, "s_std %llx\n", (unsigned long long)std);
if (std & V4L2_STD_NTSC) {
vpx3220_write_fp_block(sd, init_ntsc, sizeof(init_ntsc) >> 1);
v4l2_dbg(1, debug, sd, "norm switched to NTSC\n");
} else if (std & V4L2_STD_PAL) {
vpx3220_write_fp_block(sd, init_pal, sizeof(init_pal) >> 1);
v4l2_dbg(1, debug, sd, "norm switched to PAL\n");
} else if (std & V4L2_STD_SECAM) {
vpx3220_write_fp_block(sd, init_secam, sizeof(init_secam) >> 1);
v4l2_dbg(1, debug, sd, "norm switched to SECAM\n");
} else {
return -EINVAL;
}
decoder->norm = std;
vpx3220_fp_write(sd, 0xf2, temp_input | 0x0010);
udelay(10);
return 0;
}
static int vpx3220_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
int data;
const int input_vals[3][2] = {
{0x0c, 0},
{0x0d, 0},
{0x0e, 1}
};
if (input > 2)
return -EINVAL;
v4l2_dbg(1, debug, sd, "input switched to %s\n", inputs[input]);
vpx3220_write(sd, 0x33, input_vals[input][0]);
data = vpx3220_fp_read(sd, 0xf2) & ~(0x0020);
if (data < 0)
return data;
vpx3220_fp_write(sd, 0xf2,
data | (input_vals[input][1] << 5) | 0x0010);
udelay(10);
return 0;
}
static int vpx3220_s_stream(struct v4l2_subdev *sd, int enable)
{
v4l2_dbg(1, debug, sd, "s_stream %s\n", enable ? "on" : "off");
vpx3220_write(sd, 0xf2, (enable ? 0x1b : 0x00));
return 0;
}
static int vpx3220_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
vpx3220_write(sd, 0xe6, ctrl->val);
return 0;
case V4L2_CID_CONTRAST:
vpx3220_write(sd, 0xe7, ctrl->val + 192);
return 0;
case V4L2_CID_SATURATION:
vpx3220_fp_write(sd, 0xa0, ctrl->val);
return 0;
case V4L2_CID_HUE:
vpx3220_fp_write(sd, 0x1c, ctrl->val);
return 0;
}
return -EINVAL;
}
static int vpx3220_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct vpx3220 *decoder = to_vpx3220(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, decoder->ident, 0);
}
static int vpx3220_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct vpx3220 *decoder;
struct v4l2_subdev *sd;
const char *name = NULL;
u8 ver;
u16 pn;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
decoder = kzalloc(sizeof(struct vpx3220), GFP_KERNEL);
if (decoder == NULL)
return -ENOMEM;
sd = &decoder->sd;
v4l2_i2c_subdev_init(sd, client, &vpx3220_ops);
decoder->norm = V4L2_STD_PAL;
decoder->input = 0;
decoder->enable = 1;
v4l2_ctrl_handler_init(&decoder->hdl, 4);
v4l2_ctrl_new_std(&decoder->hdl, &vpx3220_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(&decoder->hdl, &vpx3220_ctrl_ops,
V4L2_CID_CONTRAST, 0, 63, 1, 32);
v4l2_ctrl_new_std(&decoder->hdl, &vpx3220_ctrl_ops,
V4L2_CID_SATURATION, 0, 4095, 1, 2048);
v4l2_ctrl_new_std(&decoder->hdl, &vpx3220_ctrl_ops,
V4L2_CID_HUE, -512, 511, 1, 0);
sd->ctrl_handler = &decoder->hdl;
if (decoder->hdl.error) {
int err = decoder->hdl.error;
v4l2_ctrl_handler_free(&decoder->hdl);
kfree(decoder);
return err;
}
v4l2_ctrl_handler_setup(&decoder->hdl);
ver = i2c_smbus_read_byte_data(client, 0x00);
pn = (i2c_smbus_read_byte_data(client, 0x02) << 8) +
i2c_smbus_read_byte_data(client, 0x01);
decoder->ident = V4L2_IDENT_VPX3220A;
if (ver == 0xec) {
switch (pn) {
case 0x4680:
name = "vpx3220a";
break;
case 0x4260:
name = "vpx3216b";
decoder->ident = V4L2_IDENT_VPX3216B;
break;
case 0x4280:
name = "vpx3214c";
decoder->ident = V4L2_IDENT_VPX3214C;
break;
}
}
if (name)
v4l2_info(sd, "%s found @ 0x%x (%s)\n", name,
client->addr << 1, client->adapter->name);
else
v4l2_info(sd, "chip (%02x:%04x) found @ 0x%x (%s)\n",
ver, pn, client->addr << 1, client->adapter->name);
vpx3220_write_block(sd, init_common, sizeof(init_common));
vpx3220_write_fp_block(sd, init_fp, sizeof(init_fp) >> 1);
vpx3220_write_fp_block(sd, init_pal, sizeof(init_pal) >> 1);
return 0;
}
static int vpx3220_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct vpx3220 *decoder = to_vpx3220(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&decoder->hdl);
kfree(decoder);
return 0;
}
