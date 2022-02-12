static void reg_r(struct gspca_dev *gspca_dev,
__u16 index,
__u16 len)
{
struct usb_device *dev = gspca_dev->dev;
#ifdef GSPCA_DEBUG
if (len > USB_BUF_SZ) {
pr_err("reg_r: buffer overflow\n");
return;
}
#endif
usb_control_msg(dev,
usb_rcvctrlpipe(dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0,
index, gspca_dev->usb_buf, len, 500);
PDEBUG(D_USBI, "reg read [%02x] -> %02x ..",
index, gspca_dev->usb_buf[0]);
}
static void reg_w_val(struct gspca_dev *gspca_dev,
__u16 index,
__u8 val)
{
struct usb_device *dev = gspca_dev->dev;
gspca_dev->usb_buf[0] = val;
usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0,
index, gspca_dev->usb_buf, 1, 500);
}
static void reg_w(struct gspca_dev *gspca_dev,
__u16 index,
const __u8 *buffer,
__u16 len)
{
struct usb_device *dev = gspca_dev->dev;
#ifdef GSPCA_DEBUG
if (len > USB_BUF_SZ) {
pr_err("reg_w: buffer overflow\n");
return;
}
PDEBUG(D_USBO, "reg write [%02x] = %02x..", index, *buffer);
#endif
memcpy(gspca_dev->usb_buf, buffer, len);
usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0, index, gspca_dev->usb_buf, len, 500);
}
static int i2c_w(struct gspca_dev *gspca_dev,
__u8 reg,
const __u8 *buffer,
int len, __u8 mode)
{
__u8 ptchcount;
reg_w_val(gspca_dev, ET_I2C_BASE, 0x40);
ptchcount = ((len & 0x07) << 4) | (mode & 0x03);
reg_w_val(gspca_dev, ET_I2C_COUNT, ptchcount);
reg_w_val(gspca_dev, ET_I2C_REG, reg);
while (--len >= 0)
reg_w_val(gspca_dev, ET_I2C_DATA0 + len, buffer[len]);
return 0;
}
static int i2c_r(struct gspca_dev *gspca_dev,
__u8 reg)
{
reg_w_val(gspca_dev, ET_I2C_BASE, 0x40);
reg_w_val(gspca_dev, ET_I2C_COUNT, 0x11);
reg_w_val(gspca_dev, ET_I2C_REG, reg);
reg_w_val(gspca_dev, ET_I2C_PREFETCH, 0x02);
reg_w_val(gspca_dev, ET_I2C_PREFETCH, 0x00);
reg_r(gspca_dev, ET_I2C_DATA0, 1);
return 0;
}
static int Et_WaitStatus(struct gspca_dev *gspca_dev)
{
int retry = 10;
while (retry--) {
reg_r(gspca_dev, ET_ClCK, 1);
if (gspca_dev->usb_buf[0] != 0)
return 1;
}
return 0;
}
static int et_video(struct gspca_dev *gspca_dev,
int on)
{
int ret;
reg_w_val(gspca_dev, ET_GPIO_OUT,
on ? 0x10
: 0);
ret = Et_WaitStatus(gspca_dev);
if (ret != 0)
PDEBUG(D_ERR, "timeout video on/off");
return ret;
}
static void Et_init2(struct gspca_dev *gspca_dev)
{
__u8 value;
static const __u8 FormLine[] = { 0x84, 0x03, 0x14, 0xf4, 0x01, 0x05 };
PDEBUG(D_STREAM, "Open Init2 ET");
reg_w_val(gspca_dev, ET_GPIO_DIR_CTRL, 0x2f);
reg_w_val(gspca_dev, ET_GPIO_OUT, 0x10);
reg_r(gspca_dev, ET_GPIO_IN, 1);
reg_w_val(gspca_dev, ET_ClCK, 0x14);
reg_w_val(gspca_dev, ET_CTRL, 0x1b);
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv)
value = ET_COMP_VAL1;
else
value = ET_COMP_VAL0;
reg_w_val(gspca_dev, ET_COMP, value);
reg_w_val(gspca_dev, ET_MAXQt, 0x1f);
reg_w_val(gspca_dev, ET_MINQt, 0x04);
reg_w_val(gspca_dev, ET_REG1d, 0xff);
reg_w_val(gspca_dev, ET_REG1e, 0xff);
reg_w_val(gspca_dev, ET_REG1f, 0xff);
reg_w_val(gspca_dev, ET_REG20, 0x35);
reg_w_val(gspca_dev, ET_REG21, 0x01);
reg_w_val(gspca_dev, ET_REG22, 0x00);
reg_w_val(gspca_dev, ET_REG23, 0xff);
reg_w_val(gspca_dev, ET_REG24, 0xff);
reg_w_val(gspca_dev, ET_REG25, 0x0f);
reg_w_val(gspca_dev, 0x30, 0x11);
reg_w_val(gspca_dev, 0x31, 0x40);
reg_w_val(gspca_dev, 0x32, 0x00);
reg_w_val(gspca_dev, ET_O_RED, 0x00);
reg_w_val(gspca_dev, ET_O_GREEN1, 0x00);
reg_w_val(gspca_dev, ET_O_BLUE, 0x00);
reg_w_val(gspca_dev, ET_O_GREEN2, 0x00);
reg_w_val(gspca_dev, ET_G_RED, 0x80);
reg_w_val(gspca_dev, ET_G_GREEN1, 0x80);
reg_w_val(gspca_dev, ET_G_BLUE, 0x80);
reg_w_val(gspca_dev, ET_G_GREEN2, 0x80);
reg_w_val(gspca_dev, ET_G_GR_H, 0x00);
reg_w_val(gspca_dev, ET_G_GB_H, 0x00);
reg_w_val(gspca_dev, 0x61, 0x80);
reg_w_val(gspca_dev, 0x62, 0x02);
reg_w_val(gspca_dev, 0x63, 0x03);
reg_w_val(gspca_dev, 0x64, 0x14);
reg_w_val(gspca_dev, 0x65, 0x0e);
reg_w_val(gspca_dev, 0x66, 0x02);
reg_w_val(gspca_dev, 0x67, 0x02);
reg_w_val(gspca_dev, ET_SYNCHRO, 0x8f);
reg_w_val(gspca_dev, ET_STARTX, 0x69);
reg_w_val(gspca_dev, ET_STARTY, 0x0d);
reg_w_val(gspca_dev, ET_WIDTH_LOW, 0x80);
reg_w_val(gspca_dev, ET_HEIGTH_LOW, 0xe0);
reg_w_val(gspca_dev, ET_W_H_HEIGTH, 0x60);
reg_w_val(gspca_dev, ET_REG6e, 0x86);
reg_w_val(gspca_dev, ET_REG6f, 0x01);
reg_w_val(gspca_dev, ET_REG70, 0x26);
reg_w_val(gspca_dev, ET_REG71, 0x7a);
reg_w_val(gspca_dev, ET_REG72, 0x01);
reg_w_val(gspca_dev, ET_REG73, 0x00);
reg_w_val(gspca_dev, ET_REG74, 0x18);
reg_w_val(gspca_dev, ET_REG75, 0x0f);
reg_w_val(gspca_dev, 0x8a, 0x20);
reg_w_val(gspca_dev, 0x8d, 0x0f);
reg_w_val(gspca_dev, 0x8e, 0x08);
reg_w_val(gspca_dev, 0x03, 0x08);
reg_w_val(gspca_dev, ET_PXL_CLK, 0x03);
reg_w_val(gspca_dev, 0x81, 0xff);
reg_w_val(gspca_dev, 0x80, 0x00);
reg_w_val(gspca_dev, 0x81, 0xff);
reg_w_val(gspca_dev, 0x80, 0x20);
reg_w_val(gspca_dev, 0x03, 0x01);
reg_w_val(gspca_dev, 0x03, 0x00);
reg_w_val(gspca_dev, 0x03, 0x08);
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv)
value = 0x04;
else
value = 0x1e;
reg_w_val(gspca_dev, ET_PXL_CLK, value);
reg_w(gspca_dev, 0x62, FormLine, 6);
reg_w_val(gspca_dev, 0x81, 0x47);
reg_w_val(gspca_dev, 0x80, 0x40);
reg_w_val(gspca_dev, 0x81, 0x30);
reg_w_val(gspca_dev, 0x80, 0x20);
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
int i;
for (i = 0; i < 4; i++)
reg_w_val(gspca_dev, ET_O_RED + i, val);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
__u8 RGBG[] = { 0x80, 0x80, 0x80, 0x80, 0x00, 0x00 };
memset(RGBG, val, sizeof(RGBG) - 2);
reg_w(gspca_dev, ET_G_RED, RGBG, 6);
}
static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 I2cc[] = { 0x05, 0x02, 0x02, 0x05, 0x0d };
__u8 i2cflags = 0x01;
I2cc[3] = val;
I2cc[0] = 15 - val;
if (sd->sensor == SENSOR_PAS106) {
i2c_w(gspca_dev, PAS106_REG13, &i2cflags, 1, 3);
i2c_w(gspca_dev, PAS106_REG9, I2cc, sizeof I2cc, 1);
}
}
static s32 getcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PAS106) {
i2c_r(gspca_dev, PAS106_REG9 + 3);
return gspca_dev->usb_buf[0] & 0x0f;
}
return 0;
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->autogain)
sd->ag_cnt = AG_CNT_START;
else
sd->ag_cnt = -1;
}
static void Et_init1(struct gspca_dev *gspca_dev)
{
__u8 value;
__u8 I2c0[] = { 0x0a, 0x12, 0x05, 0x6d, 0xcd, 0x00, 0x01, 0x00 };
PDEBUG(D_STREAM, "Open Init1 ET");
reg_w_val(gspca_dev, ET_GPIO_DIR_CTRL, 7);
reg_r(gspca_dev, ET_GPIO_IN, 1);
reg_w_val(gspca_dev, ET_RESET_ALL, 1);
reg_w_val(gspca_dev, ET_RESET_ALL, 0);
reg_w_val(gspca_dev, ET_ClCK, 0x10);
reg_w_val(gspca_dev, ET_CTRL, 0x19);
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv)
value = ET_COMP_VAL1;
else
value = ET_COMP_VAL0;
PDEBUG(D_STREAM, "Open mode %d Compression %d",
gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv,
value);
reg_w_val(gspca_dev, ET_COMP, value);
reg_w_val(gspca_dev, ET_MAXQt, 0x1d);
reg_w_val(gspca_dev, ET_MINQt, 0x02);
reg_w_val(gspca_dev, ET_REG1d, 0xff);
reg_w_val(gspca_dev, ET_REG1e, 0xff);
reg_w_val(gspca_dev, ET_REG1f, 0xff);
reg_w_val(gspca_dev, ET_REG20, 0x35);
reg_w_val(gspca_dev, ET_REG21, 0x01);
reg_w_val(gspca_dev, ET_REG22, 0x00);
reg_w_val(gspca_dev, ET_REG23, 0xf7);
reg_w_val(gspca_dev, ET_REG24, 0xff);
reg_w_val(gspca_dev, ET_REG25, 0x07);
reg_w_val(gspca_dev, ET_G_RED, 0x80);
reg_w_val(gspca_dev, ET_G_GREEN1, 0x80);
reg_w_val(gspca_dev, ET_G_BLUE, 0x80);
reg_w_val(gspca_dev, ET_G_GREEN2, 0x80);
reg_w_val(gspca_dev, ET_G_GR_H, 0x00);
reg_w_val(gspca_dev, ET_G_GB_H, 0x00);
reg_w_val(gspca_dev, ET_SYNCHRO, 0xf0);
reg_w_val(gspca_dev, ET_STARTX, 0x56);
reg_w_val(gspca_dev, ET_STARTY, 0x05);
reg_w_val(gspca_dev, ET_WIDTH_LOW, 0x60);
reg_w_val(gspca_dev, ET_HEIGTH_LOW, 0x20);
reg_w_val(gspca_dev, ET_W_H_HEIGTH, 0x50);
reg_w_val(gspca_dev, ET_REG6e, 0x86);
reg_w_val(gspca_dev, ET_REG6f, 0x01);
reg_w_val(gspca_dev, ET_REG70, 0x86);
reg_w_val(gspca_dev, ET_REG71, 0x14);
reg_w_val(gspca_dev, ET_REG72, 0x00);
reg_w_val(gspca_dev, ET_REG73, 0x00);
reg_w_val(gspca_dev, ET_REG74, 0x00);
reg_w_val(gspca_dev, ET_REG75, 0x0a);
reg_w_val(gspca_dev, ET_I2C_CLK, 0x04);
reg_w_val(gspca_dev, ET_PXL_CLK, 0x01);
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
I2c0[0] = 0x06;
i2c_w(gspca_dev, PAS106_REG2, I2c0, sizeof I2c0, 1);
i2c_w(gspca_dev, PAS106_REG9, I2c2, sizeof I2c2, 1);
value = 0x06;
i2c_w(gspca_dev, PAS106_REG2, &value, 1, 1);
i2c_w(gspca_dev, PAS106_REG3, I2c3, sizeof I2c3, 1);
value = 0x04;
i2c_w(gspca_dev, PAS106_REG0e, &value, 1, 1);
} else {
I2c0[0] = 0x0a;
i2c_w(gspca_dev, PAS106_REG2, I2c0, sizeof I2c0, 1);
i2c_w(gspca_dev, PAS106_REG9, I2c2, sizeof I2c2, 1);
value = 0x0a;
i2c_w(gspca_dev, PAS106_REG2, &value, 1, 1);
i2c_w(gspca_dev, PAS106_REG3, I2c3, sizeof I2c3, 1);
value = 0x04;
i2c_w(gspca_dev, PAS106_REG0e, &value, 1, 1);
}
i2c_w(gspca_dev, PAS106_REG7, I2c4, sizeof I2c4, 1);
reg_w(gspca_dev, ET_G_RED, GainRGBG, 6);
setcolors(gspca_dev, getcolors(gspca_dev));
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
sd->sensor = id->driver_info;
if (sd->sensor == SENSOR_PAS106) {
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
} else {
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
}
sd->ag_cnt = -1;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PAS106)
Et_init1(gspca_dev);
else
Et_init2(gspca_dev);
reg_w_val(gspca_dev, ET_RESET_ALL, 0x08);
et_video(gspca_dev, 0);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PAS106)
Et_init1(gspca_dev);
else
Et_init2(gspca_dev);
setautogain(gspca_dev);
reg_w_val(gspca_dev, ET_RESET_ALL, 0x08);
et_video(gspca_dev, 1);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
et_video(gspca_dev, 0);
}
static __u8 Et_getgainG(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PAS106) {
i2c_r(gspca_dev, PAS106_REG0e);
PDEBUG(D_CONF, "Etoms gain G %d", gspca_dev->usb_buf[0]);
return gspca_dev->usb_buf[0];
}
return 0x1f;
}
static void Et_setgainG(struct gspca_dev *gspca_dev, __u8 gain)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PAS106) {
__u8 i2cflags = 0x01;
i2c_w(gspca_dev, PAS106_REG13, &i2cflags, 1, 3);
i2c_w(gspca_dev, PAS106_REG0e, &gain, 1, 1);
}
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 luma;
__u8 luma_mean = 128;
__u8 luma_delta = 20;
__u8 spring = 4;
int Gbright;
__u8 r, g, b;
if (sd->ag_cnt < 0)
return;
if (--sd->ag_cnt >= 0)
return;
sd->ag_cnt = AG_CNT_START;
Gbright = Et_getgainG(gspca_dev);
reg_r(gspca_dev, ET_LUMA_CENTER, 4);
g = (gspca_dev->usb_buf[0] + gspca_dev->usb_buf[3]) >> 1;
r = gspca_dev->usb_buf[1];
b = gspca_dev->usb_buf[2];
r = ((r << 8) - (r << 4) - (r << 3)) >> 10;
b = ((b << 7) >> 10);
g = ((g << 9) + (g << 7) + (g << 5)) >> 10;
luma = LIMIT(r + g + b);
PDEBUG(D_FRAM, "Etoms luma G %d", luma);
if (luma < luma_mean - luma_delta || luma > luma_mean + luma_delta) {
Gbright += (luma_mean - luma) >> spring;
Gbright = BLIMIT(Gbright);
PDEBUG(D_FRAM, "Etoms Gbright %d", Gbright);
Et_setgainG(gspca_dev, (__u8) Gbright);
}
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int seqframe;
seqframe = data[0] & 0x3f;
len = (int) (((data[0] & 0xc0) << 2) | data[1]);
if (seqframe == 0x3f) {
PDEBUG(D_FRAM,
"header packet found datalength %d !!", len);
PDEBUG(D_FRAM, "G %d R %d G %d B %d",
data[2], data[3], data[4], data[5]);
data += 30;
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
return;
}
if (len) {
data += 8;
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
} else {
gspca_dev->last_packet_type = DISCARD_PACKET;
}
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
setbrightness(gspca_dev, ctrl->val);
break;
case V4L2_CID_CONTRAST:
setcontrast(gspca_dev, ctrl->val);
break;
case V4L2_CID_SATURATION:
setcolors(gspca_dev, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
sd->autogain = ctrl->val;
setautogain(gspca_dev);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 1, 127, 1, 63);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 127);
if (sd->sensor == SENSOR_PAS106)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 15, 1, 7);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
