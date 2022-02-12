static int tcm825x_read_reg(struct i2c_client *client, int reg)
{
int err;
struct i2c_msg msg[2];
u8 reg_buf, data_buf = 0;
if (!client->adapter)
return -ENODEV;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = 1;
msg[0].buf = &reg_buf;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = 1;
msg[1].buf = &data_buf;
reg_buf = reg;
err = i2c_transfer(client->adapter, msg, 2);
if (err < 0)
return err;
return data_buf;
}
static int tcm825x_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
int err;
struct i2c_msg msg[1];
unsigned char data[2];
if (!client->adapter)
return -ENODEV;
msg->addr = client->addr;
msg->flags = 0;
msg->len = 2;
msg->buf = data;
data[0] = reg;
data[1] = val;
err = i2c_transfer(client->adapter, msg, 1);
if (err >= 0)
return 0;
return err;
}
static int __tcm825x_write_reg_mask(struct i2c_client *client,
u8 reg, u8 val, u8 mask)
{
int rc;
rc = tcm825x_read_reg(client, reg);
if (rc < 0)
return rc;
rc &= (~mask);
val &= mask;
val |= rc;
rc = tcm825x_write_reg(client, reg, val);
if (rc)
return rc;
return 0;
}
static int tcm825x_write_default_regs(struct i2c_client *client,
const struct tcm825x_reg *reglist)
{
int err;
const struct tcm825x_reg *next = reglist;
while (!((next->reg == TCM825X_REG_TERM)
&& (next->val == TCM825X_VAL_TERM))) {
err = tcm825x_write_reg(client, next->reg, next->val);
if (err) {
dev_err(&client->dev, "register writing failed\n");
return err;
}
next++;
}
return 0;
}
static struct vcontrol *find_vctrl(int id)
{
int i;
if (id < V4L2_CID_BASE)
return NULL;
for (i = 0; i < ARRAY_SIZE(video_control); i++)
if (video_control[i].qc.id == id)
return &video_control[i];
return NULL;
}
static enum image_size tcm825x_find_size(struct v4l2_int_device *s,
unsigned int width,
unsigned int height)
{
enum image_size isize;
unsigned long pixels = width * height;
struct tcm825x_sensor *sensor = s->priv;
for (isize = subQCIF; isize < VGA; isize++) {
if (tcm825x_sizes[isize + 1].height
* tcm825x_sizes[isize + 1].width > pixels) {
dev_dbg(&sensor->i2c_client->dev, "size %d\n", isize);
return isize;
}
}
dev_dbg(&sensor->i2c_client->dev, "format default VGA\n");
return VGA;
}
static int tcm825x_configure(struct v4l2_int_device *s)
{
struct tcm825x_sensor *sensor = s->priv;
struct v4l2_pix_format *pix = &sensor->pix;
enum image_size isize = tcm825x_find_size(s, pix->width, pix->height);
struct v4l2_fract *fper = &sensor->timeperframe;
enum pixel_format pfmt;
int err;
u32 tgt_fps;
u8 val;
err = tcm825x_write_default_regs(
sensor->i2c_client, sensor->platform_data->default_regs());
if (err)
return err;
val = tcm825x_siz_reg[isize]->val;
dev_dbg(&sensor->i2c_client->dev,
"configuring image size %d\n", isize);
err = tcm825x_write_reg_mask(sensor->i2c_client,
tcm825x_siz_reg[isize]->reg, val);
if (err)
return err;
switch (pix->pixelformat) {
default:
case V4L2_PIX_FMT_RGB565:
pfmt = RGB565;
break;
case V4L2_PIX_FMT_UYVY:
pfmt = YUV422;
break;
}
dev_dbg(&sensor->i2c_client->dev,
"configuring pixel format %d\n", pfmt);
val = tcm825x_fmt_reg[pfmt]->val;
err = tcm825x_write_reg_mask(sensor->i2c_client,
tcm825x_fmt_reg[pfmt]->reg, val);
if (err)
return err;
tgt_fps = fper->denominator / fper->numerator;
if (tgt_fps <= HIGH_FPS_MODE_LOWER_LIMIT) {
val = tcm825x_read_reg(sensor->i2c_client, 0x02);
val |= 0x80;
tcm825x_write_reg(sensor->i2c_client, 0x02, val);
}
return 0;
}
static int ioctl_queryctrl(struct v4l2_int_device *s,
struct v4l2_queryctrl *qc)
{
struct vcontrol *control;
control = find_vctrl(qc->id);
if (control == NULL)
return -EINVAL;
*qc = control->qc;
return 0;
}
static int ioctl_g_ctrl(struct v4l2_int_device *s,
struct v4l2_control *vc)
{
struct tcm825x_sensor *sensor = s->priv;
struct i2c_client *client = sensor->i2c_client;
int val, r;
struct vcontrol *lvc;
if (vc->id == V4L2_CID_EXPOSURE) {
int val_lower, val_upper;
val_upper = tcm825x_read_reg(client,
TCM825X_ADDR(TCM825X_ESRSPD_U));
if (val_upper < 0)
return val_upper;
val_lower = tcm825x_read_reg(client,
TCM825X_ADDR(TCM825X_ESRSPD_L));
if (val_lower < 0)
return val_lower;
vc->value = ((val_upper & 0x1f) << 8) | (val_lower);
return 0;
}
lvc = find_vctrl(vc->id);
if (lvc == NULL)
return -EINVAL;
r = tcm825x_read_reg(client, TCM825X_ADDR(lvc->reg));
if (r < 0)
return r;
val = r & TCM825X_MASK(lvc->reg);
val >>= lvc->start_bit;
if (val < 0)
return val;
if (vc->id == V4L2_CID_HFLIP || vc->id == V4L2_CID_VFLIP)
val ^= sensor->platform_data->is_upside_down();
vc->value = val;
return 0;
}
static int ioctl_s_ctrl(struct v4l2_int_device *s,
struct v4l2_control *vc)
{
struct tcm825x_sensor *sensor = s->priv;
struct i2c_client *client = sensor->i2c_client;
struct vcontrol *lvc;
int val = vc->value;
if (vc->id == V4L2_CID_EXPOSURE) {
int val_lower, val_upper;
val_lower = val & TCM825X_MASK(TCM825X_ESRSPD_L);
val_upper = (val >> 8) & TCM825X_MASK(TCM825X_ESRSPD_U);
if (tcm825x_write_reg_mask(client,
TCM825X_ESRSPD_U, val_upper))
return -EIO;
if (tcm825x_write_reg_mask(client,
TCM825X_ESRSPD_L, val_lower))
return -EIO;
return 0;
}
lvc = find_vctrl(vc->id);
if (lvc == NULL)
return -EINVAL;
if (vc->id == V4L2_CID_HFLIP || vc->id == V4L2_CID_VFLIP)
val ^= sensor->platform_data->is_upside_down();
val = val << lvc->start_bit;
if (tcm825x_write_reg_mask(client, lvc->reg, val))
return -EIO;
return 0;
}
static int ioctl_enum_fmt_cap(struct v4l2_int_device *s,
struct v4l2_fmtdesc *fmt)
{
int index = fmt->index;
switch (fmt->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
if (index >= TCM825X_NUM_CAPTURE_FORMATS)
return -EINVAL;
break;
default:
return -EINVAL;
}
fmt->flags = tcm825x_formats[index].flags;
strlcpy(fmt->description, tcm825x_formats[index].description,
sizeof(fmt->description));
fmt->pixelformat = tcm825x_formats[index].pixelformat;
return 0;
}
static int ioctl_try_fmt_cap(struct v4l2_int_device *s,
struct v4l2_format *f)
{
struct tcm825x_sensor *sensor = s->priv;
enum image_size isize;
int ifmt;
struct v4l2_pix_format *pix = &f->fmt.pix;
isize = tcm825x_find_size(s, pix->width, pix->height);
dev_dbg(&sensor->i2c_client->dev, "isize = %d num_capture = %lu\n",
isize, (unsigned long)TCM825X_NUM_CAPTURE_FORMATS);
pix->width = tcm825x_sizes[isize].width;
pix->height = tcm825x_sizes[isize].height;
for (ifmt = 0; ifmt < TCM825X_NUM_CAPTURE_FORMATS; ifmt++)
if (pix->pixelformat == tcm825x_formats[ifmt].pixelformat)
break;
if (ifmt == TCM825X_NUM_CAPTURE_FORMATS)
ifmt = 0;
pix->pixelformat = tcm825x_formats[ifmt].pixelformat;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = pix->width * TCM825X_BYTES_PER_PIXEL;
pix->sizeimage = pix->bytesperline * pix->height;
pix->priv = 0;
dev_dbg(&sensor->i2c_client->dev, "format = 0x%08x\n",
pix->pixelformat);
switch (pix->pixelformat) {
case V4L2_PIX_FMT_UYVY:
default:
pix->colorspace = V4L2_COLORSPACE_JPEG;
break;
case V4L2_PIX_FMT_RGB565:
pix->colorspace = V4L2_COLORSPACE_SRGB;
break;
}
return 0;
}
static int ioctl_s_fmt_cap(struct v4l2_int_device *s,
struct v4l2_format *f)
{
struct tcm825x_sensor *sensor = s->priv;
struct v4l2_pix_format *pix = &f->fmt.pix;
int rval;
rval = ioctl_try_fmt_cap(s, f);
if (rval)
return rval;
rval = tcm825x_configure(s);
sensor->pix = *pix;
return rval;
}
static int ioctl_g_fmt_cap(struct v4l2_int_device *s,
struct v4l2_format *f)
{
struct tcm825x_sensor *sensor = s->priv;
f->fmt.pix = sensor->pix;
return 0;
}
static int ioctl_g_parm(struct v4l2_int_device *s,
struct v4l2_streamparm *a)
{
struct tcm825x_sensor *sensor = s->priv;
struct v4l2_captureparm *cparm = &a->parm.capture;
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
memset(a, 0, sizeof(*a));
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
cparm->capability = V4L2_CAP_TIMEPERFRAME;
cparm->timeperframe = sensor->timeperframe;
return 0;
}
static int ioctl_s_parm(struct v4l2_int_device *s,
struct v4l2_streamparm *a)
{
struct tcm825x_sensor *sensor = s->priv;
struct v4l2_fract *timeperframe = &a->parm.capture.timeperframe;
u32 tgt_fps;
int rval;
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if ((timeperframe->numerator == 0)
|| (timeperframe->denominator == 0)) {
timeperframe->denominator = DEFAULT_FPS;
timeperframe->numerator = 1;
}
tgt_fps = timeperframe->denominator / timeperframe->numerator;
if (tgt_fps > MAX_FPS) {
timeperframe->denominator = MAX_FPS;
timeperframe->numerator = 1;
} else if (tgt_fps < MIN_FPS) {
timeperframe->denominator = MIN_FPS;
timeperframe->numerator = 1;
}
sensor->timeperframe = *timeperframe;
rval = tcm825x_configure(s);
return rval;
}
static int ioctl_s_power(struct v4l2_int_device *s, int on)
{
struct tcm825x_sensor *sensor = s->priv;
return sensor->platform_data->power_set(on);
}
static int ioctl_g_ifparm(struct v4l2_int_device *s, struct v4l2_ifparm *p)
{
struct tcm825x_sensor *sensor = s->priv;
struct v4l2_fract *timeperframe = &sensor->timeperframe;
u32 tgt_xclk;
u32 tgt_fps;
int rval;
rval = sensor->platform_data->ifparm(p);
if (rval)
return rval;
tgt_fps = timeperframe->denominator / timeperframe->numerator;
tgt_xclk = (tgt_fps <= HIGH_FPS_MODE_LOWER_LIMIT) ?
(2457 * tgt_fps) / MAX_HALF_FPS :
(2457 * tgt_fps) / MAX_FPS;
tgt_xclk *= 10000;
tgt_xclk = min(tgt_xclk, (u32)TCM825X_XCLK_MAX);
tgt_xclk = max(tgt_xclk, (u32)TCM825X_XCLK_MIN);
p->u.bt656.clock_curr = tgt_xclk;
return 0;
}
static int ioctl_g_needs_reset(struct v4l2_int_device *s, void *buf)
{
struct tcm825x_sensor *sensor = s->priv;
return sensor->platform_data->needs_reset(s, buf, &sensor->pix);
}
static int ioctl_reset(struct v4l2_int_device *s)
{
return -EBUSY;
}
static int ioctl_init(struct v4l2_int_device *s)
{
return tcm825x_configure(s);
}
static int ioctl_dev_exit(struct v4l2_int_device *s)
{
return 0;
}
static int ioctl_dev_init(struct v4l2_int_device *s)
{
struct tcm825x_sensor *sensor = s->priv;
int r;
r = tcm825x_read_reg(sensor->i2c_client, 0x01);
if (r < 0)
return r;
if (r == 0) {
dev_err(&sensor->i2c_client->dev, "device not detected\n");
return -EIO;
}
return 0;
}
static int tcm825x_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct tcm825x_sensor *sensor = &tcm825x;
if (i2c_get_clientdata(client))
return -EBUSY;
sensor->platform_data = client->dev.platform_data;
if (sensor->platform_data == NULL
|| !sensor->platform_data->is_okay())
return -ENODEV;
sensor->v4l2_int_device = &tcm825x_int_device;
sensor->i2c_client = client;
i2c_set_clientdata(client, sensor);
sensor->pix.width = tcm825x_sizes[QVGA].width;
sensor->pix.height = tcm825x_sizes[QVGA].height;
sensor->pix.pixelformat = V4L2_PIX_FMT_RGB565;
return v4l2_int_device_register(sensor->v4l2_int_device);
}
static int tcm825x_remove(struct i2c_client *client)
{
struct tcm825x_sensor *sensor = i2c_get_clientdata(client);
if (!client->adapter)
return -ENODEV;
v4l2_int_device_unregister(sensor->v4l2_int_device);
return 0;
}
static int __init tcm825x_init(void)
{
int rval;
rval = i2c_add_driver(&tcm825x_i2c_driver);
if (rval)
pr_info("%s: failed registering " TCM825X_NAME "\n",
__func__);
return rval;
}
static void __exit tcm825x_exit(void)
{
i2c_del_driver(&tcm825x_i2c_driver);
}
