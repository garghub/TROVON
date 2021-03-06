static inline void w9966_set_state(struct w9966 *cam, int mask, int val)
{
cam->dev_state = (cam->dev_state & ~mask) ^ val;
}
static inline int w9966_get_state(struct w9966 *cam, int mask, int val)
{
return ((cam->dev_state & mask) == val);
}
static void w9966_pdev_claim(struct w9966 *cam)
{
if (w9966_get_state(cam, W9966_STATE_CLAIMED, W9966_STATE_CLAIMED))
return;
parport_claim_or_block(cam->pdev);
w9966_set_state(cam, W9966_STATE_CLAIMED, W9966_STATE_CLAIMED);
}
static void w9966_pdev_release(struct w9966 *cam)
{
if (w9966_get_state(cam, W9966_STATE_CLAIMED, 0))
return;
parport_release(cam->pdev);
w9966_set_state(cam, W9966_STATE_CLAIMED, 0);
}
static int w9966_read_reg(struct w9966 *cam, int reg)
{
const unsigned char addr = 0x80 | (reg & 0x1f);
unsigned char val;
if (parport_negotiate(cam->pport, cam->ppmode | IEEE1284_ADDR) != 0)
return -1;
if (parport_write(cam->pport, &addr, 1) != 1)
return -1;
if (parport_negotiate(cam->pport, cam->ppmode | IEEE1284_DATA) != 0)
return -1;
if (parport_read(cam->pport, &val, 1) != 1)
return -1;
return val;
}
static int w9966_write_reg(struct w9966 *cam, int reg, int data)
{
const unsigned char addr = 0xc0 | (reg & 0x1f);
const unsigned char val = data;
if (parport_negotiate(cam->pport, cam->ppmode | IEEE1284_ADDR) != 0)
return -1;
if (parport_write(cam->pport, &addr, 1) != 1)
return -1;
if (parport_negotiate(cam->pport, cam->ppmode | IEEE1284_DATA) != 0)
return -1;
if (parport_write(cam->pport, &val, 1) != 1)
return -1;
return 0;
}
static void w9966_i2c_setsda(struct w9966 *cam, int state)
{
if (state)
cam->i2c_state |= W9966_I2C_W_DATA;
else
cam->i2c_state &= ~W9966_I2C_W_DATA;
w9966_write_reg(cam, 0x18, cam->i2c_state);
udelay(5);
}
static int w9966_i2c_getscl(struct w9966 *cam)
{
const unsigned char state = w9966_read_reg(cam, 0x18);
return ((state & W9966_I2C_R_CLOCK) > 0);
}
static int w9966_i2c_setscl(struct w9966 *cam, int state)
{
unsigned long timeout;
if (state)
cam->i2c_state |= W9966_I2C_W_CLOCK;
else
cam->i2c_state &= ~W9966_I2C_W_CLOCK;
w9966_write_reg(cam, 0x18, cam->i2c_state);
udelay(5);
if (state) {
timeout = jiffies + 100;
while (!w9966_i2c_getscl(cam)) {
if (time_after(jiffies, timeout))
return -1;
}
}
return 0;
}
static int w9966_i2c_wbyte(struct w9966 *cam, int data)
{
int i;
for (i = 7; i >= 0; i--) {
w9966_i2c_setsda(cam, (data >> i) & 0x01);
if (w9966_i2c_setscl(cam, 1) == -1)
return -1;
w9966_i2c_setscl(cam, 0);
}
w9966_i2c_setsda(cam, 1);
if (w9966_i2c_setscl(cam, 1) == -1)
return -1;
w9966_i2c_setscl(cam, 0);
return 0;
}
static int w9966_write_reg_i2c(struct w9966 *cam, int reg, int data)
{
w9966_i2c_setsda(cam, 0);
w9966_i2c_setscl(cam, 0);
if (w9966_i2c_wbyte(cam, W9966_I2C_W_ID) == -1 ||
w9966_i2c_wbyte(cam, reg) == -1 ||
w9966_i2c_wbyte(cam, data) == -1)
return -1;
w9966_i2c_setsda(cam, 0);
if (w9966_i2c_setscl(cam, 1) == -1)
return -1;
w9966_i2c_setsda(cam, 1);
return 0;
}
static int w9966_findlen(int near, int size, int maxlen)
{
int bestlen = size;
int besterr = abs(near - bestlen);
int len;
for (len = size + 1; len < maxlen; len++) {
int err;
if (((64 * size) % len) != 0)
continue;
err = abs(near - len);
if (err > besterr)
break;
besterr = err;
bestlen = len;
}
return bestlen;
}
static int w9966_calcscale(int size, int min, int max, int *beg, int *end, unsigned char *factor)
{
int maxlen = max - min;
int len = *end - *beg + 1;
int newlen = w9966_findlen(len, size, maxlen);
int err = newlen - len;
if (newlen > maxlen || newlen < size)
return -1;
*factor = (64 * size) / newlen;
if (*factor == 64)
*factor = 0x00;
else
*factor |= 0x80;
*beg -= err / 2;
*end += err - (err / 2);
if (*beg < min) {
*end += min - *beg;
*beg += min - *beg;
}
if (*end > max) {
*beg -= *end - max;
*end -= *end - max;
}
return 0;
}
static int w9966_setup(struct w9966 *cam, int x1, int y1, int x2, int y2, int w, int h)
{
unsigned int i;
unsigned int enh_s, enh_e;
unsigned char scale_x, scale_y;
unsigned char regs[0x1c];
unsigned char saa7111_regs[] = {
0x21, 0x00, 0xd8, 0x23, 0x00, 0x80, 0x80, 0x00,
0x88, 0x10, 0x80, 0x40, 0x40, 0x00, 0x01, 0x00,
0x48, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x71, 0xe7, 0x00, 0x00, 0xc0
};
if (w * h * 2 > W9966_SRAMSIZE) {
DPRINTF("capture window exceeds SRAM size!.\n");
w = 200; h = 160;
}
w &= ~0x1;
if (w < 2)
w = 2;
if (h < 1)
h = 1;
if (w > W9966_WND_MAX_W)
w = W9966_WND_MAX_W;
if (h > W9966_WND_MAX_H)
h = W9966_WND_MAX_H;
cam->width = w;
cam->height = h;
enh_s = 0;
enh_e = w * h * 2;
if (w9966_calcscale(w, W9966_WND_MIN_X, W9966_WND_MAX_X, &x1, &x2, &scale_x) != 0 ||
w9966_calcscale(h, W9966_WND_MIN_Y, W9966_WND_MAX_Y, &y1, &y2, &scale_y) != 0)
return -1;
DPRINTF("%dx%d, x: %d<->%d, y: %d<->%d, sx: %d/64, sy: %d/64.\n",
w, h, x1, x2, y1, y2, scale_x & ~0x80, scale_y & ~0x80);
regs[0x00] = 0x00;
regs[0x01] = 0x18;
regs[0x02] = scale_y;
regs[0x03] = scale_x;
regs[0x04] = (x1 & 0x0ff);
regs[0x05] = (x1 & 0x300)>>8;
regs[0x06] = (y1 & 0x0ff);
regs[0x07] = (y1 & 0x300)>>8;
regs[0x08] = (x2 & 0x0ff);
regs[0x09] = (x2 & 0x300)>>8;
regs[0x0a] = (y2 & 0x0ff);
regs[0x0c] = W9966_SRAMID;
regs[0x0d] = (enh_s & 0x000ff);
regs[0x0e] = (enh_s & 0x0ff00) >> 8;
regs[0x0f] = (enh_s & 0x70000) >> 16;
regs[0x10] = (enh_e & 0x000ff);
regs[0x11] = (enh_e & 0x0ff00) >> 8;
regs[0x12] = (enh_e & 0x70000) >> 16;
regs[0x13] = 0x40;
regs[0x17] = 0x00;
regs[0x18] = cam->i2c_state = 0x00;
regs[0x19] = 0xff;
regs[0x1a] = 0xff;
regs[0x1b] = 0x10;
saa7111_regs[0x0a] = cam->brightness;
saa7111_regs[0x0b] = cam->contrast;
saa7111_regs[0x0c] = cam->color;
saa7111_regs[0x0d] = cam->hue;
if (w9966_write_reg(cam, 0x00, 0x03) == -1)
return -1;
for (i = 0; i < 0x1c; i++)
if (w9966_write_reg(cam, i, regs[i]) == -1)
return -1;
for (i = 0; i < 0x20; i++)
if (w9966_write_reg_i2c(cam, i, saa7111_regs[i]) == -1)
return -1;
return 0;
}
static int cam_querycap(struct file *file, void *priv,
struct v4l2_capability *vcap)
{
struct w9966 *cam = video_drvdata(file);
strlcpy(vcap->driver, cam->v4l2_dev.name, sizeof(vcap->driver));
strlcpy(vcap->card, W9966_DRIVERNAME, sizeof(vcap->card));
strlcpy(vcap->bus_info, "parport", sizeof(vcap->bus_info));
vcap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_READWRITE;
vcap->capabilities = vcap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int cam_enum_input(struct file *file, void *fh, struct v4l2_input *vin)
{
if (vin->index > 0)
return -EINVAL;
strlcpy(vin->name, "Camera", sizeof(vin->name));
vin->type = V4L2_INPUT_TYPE_CAMERA;
vin->audioset = 0;
vin->tuner = 0;
vin->std = 0;
vin->status = 0;
return 0;
}
static int cam_g_input(struct file *file, void *fh, unsigned int *inp)
{
*inp = 0;
return 0;
}
static int cam_s_input(struct file *file, void *fh, unsigned int inp)
{
return (inp > 0) ? -EINVAL : 0;
}
static int cam_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct w9966 *cam =
container_of(ctrl->handler, struct w9966, hdl);
int ret = 0;
mutex_lock(&cam->lock);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cam->brightness = ctrl->val;
break;
case V4L2_CID_CONTRAST:
cam->contrast = ctrl->val;
break;
case V4L2_CID_SATURATION:
cam->color = ctrl->val;
break;
case V4L2_CID_HUE:
cam->hue = ctrl->val;
break;
default:
ret = -EINVAL;
break;
}
if (ret == 0) {
w9966_pdev_claim(cam);
if (w9966_write_reg_i2c(cam, 0x0a, cam->brightness) == -1 ||
w9966_write_reg_i2c(cam, 0x0b, cam->contrast) == -1 ||
w9966_write_reg_i2c(cam, 0x0c, cam->color) == -1 ||
w9966_write_reg_i2c(cam, 0x0d, cam->hue) == -1) {
ret = -EIO;
}
w9966_pdev_release(cam);
}
mutex_unlock(&cam->lock);
return ret;
}
static int cam_g_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct w9966 *cam = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
pix->width = cam->width;
pix->height = cam->height;
pix->pixelformat = V4L2_PIX_FMT_YUYV;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = 2 * cam->width;
pix->sizeimage = 2 * cam->width * cam->height;
pix->colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int cam_try_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct v4l2_pix_format *pix = &fmt->fmt.pix;
if (pix->width < 2)
pix->width = 2;
if (pix->height < 1)
pix->height = 1;
if (pix->width > W9966_WND_MAX_W)
pix->width = W9966_WND_MAX_W;
if (pix->height > W9966_WND_MAX_H)
pix->height = W9966_WND_MAX_H;
pix->pixelformat = V4L2_PIX_FMT_YUYV;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = 2 * pix->width;
pix->sizeimage = 2 * pix->width * pix->height;
pix->colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int cam_s_fmt_vid_cap(struct file *file, void *fh, struct v4l2_format *fmt)
{
struct w9966 *cam = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
int ret = cam_try_fmt_vid_cap(file, fh, fmt);
if (ret)
return ret;
mutex_lock(&cam->lock);
w9966_pdev_claim(cam);
ret = w9966_setup(cam, 0, 0, 1023, 1023, pix->width, pix->height);
w9966_pdev_release(cam);
mutex_unlock(&cam->lock);
return ret;
}
static int cam_enum_fmt_vid_cap(struct file *file, void *fh, struct v4l2_fmtdesc *fmt)
{
static struct v4l2_fmtdesc formats[] = {
{ 0, 0, 0,
"YUV 4:2:2", V4L2_PIX_FMT_YUYV,
{ 0, 0, 0, 0 }
},
};
enum v4l2_buf_type type = fmt->type;
if (fmt->index > 0)
return -EINVAL;
*fmt = formats[fmt->index];
fmt->type = type;
return 0;
}
static ssize_t w9966_v4l_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct w9966 *cam = video_drvdata(file);
unsigned char addr = 0xa0;
unsigned char __user *dest = (unsigned char __user *)buf;
unsigned long dleft = count;
unsigned char *tbuf;
if (count > cam->width * cam->height * 2)
return -EINVAL;
mutex_lock(&cam->lock);
w9966_pdev_claim(cam);
w9966_write_reg(cam, 0x00, 0x02);
w9966_write_reg(cam, 0x00, 0x00);
w9966_write_reg(cam, 0x01, 0x98);
if ((parport_negotiate(cam->pport, cam->ppmode|IEEE1284_ADDR) != 0) ||
(parport_write(cam->pport, &addr, 1) != 1) ||
(parport_negotiate(cam->pport, cam->ppmode|IEEE1284_DATA) != 0)) {
w9966_pdev_release(cam);
mutex_unlock(&cam->lock);
return -EFAULT;
}
tbuf = kmalloc(W9966_RBUFFER, GFP_KERNEL);
if (tbuf == NULL) {
count = -ENOMEM;
goto out;
}
while (dleft > 0) {
unsigned long tsize = (dleft > W9966_RBUFFER) ? W9966_RBUFFER : dleft;
if (parport_read(cam->pport, tbuf, tsize) < tsize) {
count = -EFAULT;
goto out;
}
if (copy_to_user(dest, tbuf, tsize) != 0) {
count = -EFAULT;
goto out;
}
dest += tsize;
dleft -= tsize;
}
w9966_write_reg(cam, 0x01, 0x18);
out:
kfree(tbuf);
w9966_pdev_release(cam);
mutex_unlock(&cam->lock);
return count;
}
static int w9966_init(struct w9966 *cam, struct parport *port)
{
struct v4l2_device *v4l2_dev = &cam->v4l2_dev;
if (cam->dev_state != 0)
return -1;
strlcpy(v4l2_dev->name, "w9966", sizeof(v4l2_dev->name));
if (v4l2_device_register(NULL, v4l2_dev) < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return -1;
}
v4l2_ctrl_handler_init(&cam->hdl, 4);
v4l2_ctrl_new_std(&cam->hdl, &cam_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&cam->hdl, &cam_ctrl_ops,
V4L2_CID_CONTRAST, -64, 64, 1, 64);
v4l2_ctrl_new_std(&cam->hdl, &cam_ctrl_ops,
V4L2_CID_SATURATION, -64, 64, 1, 64);
v4l2_ctrl_new_std(&cam->hdl, &cam_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
if (cam->hdl.error) {
v4l2_err(v4l2_dev, "couldn't register controls\n");
return -1;
}
cam->pport = port;
cam->brightness = 128;
cam->contrast = 64;
cam->color = 64;
cam->hue = 0;
switch (parmode) {
default:
case 0:
if (port->modes & PARPORT_MODE_ECP)
cam->ppmode = IEEE1284_MODE_ECP;
else if (port->modes & PARPORT_MODE_EPP)
cam->ppmode = IEEE1284_MODE_EPP;
else
cam->ppmode = IEEE1284_MODE_ECP;
break;
case 1:
cam->ppmode = IEEE1284_MODE_ECP;
break;
case 2:
cam->ppmode = IEEE1284_MODE_EPP;
break;
}
cam->pdev = parport_register_device(port, "w9966", NULL, NULL, NULL, 0, NULL);
if (cam->pdev == NULL) {
DPRINTF("parport_register_device() failed\n");
return -1;
}
w9966_set_state(cam, W9966_STATE_PDEV, W9966_STATE_PDEV);
w9966_pdev_claim(cam);
if (w9966_setup(cam, 0, 0, 1023, 1023, 200, 160) != 0) {
DPRINTF("w9966_setup() failed.\n");
return -1;
}
w9966_pdev_release(cam);
strlcpy(cam->vdev.name, W9966_DRIVERNAME, sizeof(cam->vdev.name));
cam->vdev.v4l2_dev = v4l2_dev;
cam->vdev.fops = &w9966_fops;
cam->vdev.ioctl_ops = &w9966_ioctl_ops;
cam->vdev.release = video_device_release_empty;
cam->vdev.ctrl_handler = &cam->hdl;
set_bit(V4L2_FL_USE_FH_PRIO, &cam->vdev.flags);
video_set_drvdata(&cam->vdev, cam);
mutex_init(&cam->lock);
if (video_register_device(&cam->vdev, VFL_TYPE_GRABBER, video_nr) < 0)
return -1;
w9966_set_state(cam, W9966_STATE_VDEV, W9966_STATE_VDEV);
v4l2_info(v4l2_dev, "Found and initialized a webcam on %s.\n",
cam->pport->name);
return 0;
}
static void w9966_term(struct w9966 *cam)
{
if (w9966_get_state(cam, W9966_STATE_VDEV, W9966_STATE_VDEV)) {
video_unregister_device(&cam->vdev);
w9966_set_state(cam, W9966_STATE_VDEV, 0);
}
v4l2_ctrl_handler_free(&cam->hdl);
if (w9966_get_state(cam, W9966_STATE_PDEV, W9966_STATE_PDEV)) {
w9966_pdev_claim(cam);
parport_negotiate(cam->pport, IEEE1284_MODE_COMPAT);
w9966_pdev_release(cam);
}
if (w9966_get_state(cam, W9966_STATE_PDEV, W9966_STATE_PDEV)) {
parport_unregister_device(cam->pdev);
w9966_set_state(cam, W9966_STATE_PDEV, 0);
}
memset(cam, 0, sizeof(*cam));
}
static void w9966_attach(struct parport *port)
{
int i;
for (i = 0; i < W9966_MAXCAMS; i++) {
if (w9966_cams[i].dev_state != 0)
continue;
if (strcmp(pardev[i], "aggressive") == 0 || strcmp(pardev[i], port->name) == 0) {
if (w9966_init(&w9966_cams[i], port) != 0)
w9966_term(&w9966_cams[i]);
break;
}
}
}
static void w9966_detach(struct parport *port)
{
int i;
for (i = 0; i < W9966_MAXCAMS; i++)
if (w9966_cams[i].dev_state != 0 && w9966_cams[i].pport == port)
w9966_term(&w9966_cams[i]);
}
static int __init w9966_mod_init(void)
{
int i;
for (i = 0; i < W9966_MAXCAMS; i++)
w9966_cams[i].dev_state = 0;
return parport_register_driver(&w9966_ppd);
}
static void __exit w9966_mod_term(void)
{
parport_unregister_driver(&w9966_ppd);
}
