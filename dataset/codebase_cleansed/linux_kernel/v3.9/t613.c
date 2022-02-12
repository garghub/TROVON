static u8 reg_r(struct gspca_dev *gspca_dev,
u16 index)
{
usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index,
gspca_dev->usb_buf, 1, 500);
return gspca_dev->usb_buf[0];
}
static void reg_w(struct gspca_dev *gspca_dev,
u16 index)
{
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, index,
NULL, 0, 500);
}
static void reg_w_buf(struct gspca_dev *gspca_dev,
const u8 *buffer, u16 len)
{
if (len <= USB_BUF_SZ) {
memcpy(gspca_dev->usb_buf, buffer, len);
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x01, 0,
gspca_dev->usb_buf, len, 500);
} else {
u8 *tmpbuf;
tmpbuf = kmemdup(buffer, len, GFP_KERNEL);
if (!tmpbuf) {
pr_err("Out of memory\n");
return;
}
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x01, 0,
tmpbuf, len, 500);
kfree(tmpbuf);
}
}
static void reg_w_ixbuf(struct gspca_dev *gspca_dev,
u8 reg,
const u8 *buffer, u16 len)
{
int i;
u8 *p, *tmpbuf;
if (len * 2 <= USB_BUF_SZ) {
p = tmpbuf = gspca_dev->usb_buf;
} else {
p = tmpbuf = kmalloc(len * 2, GFP_KERNEL);
if (!tmpbuf) {
pr_err("Out of memory\n");
return;
}
}
i = len;
while (--i >= 0) {
*p++ = reg++;
*p++ = *buffer++;
}
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x01, 0,
tmpbuf, len * 2, 500);
if (len * 2 > USB_BUF_SZ)
kfree(tmpbuf);
}
static void om6802_sensor_init(struct gspca_dev *gspca_dev)
{
int i;
const u8 *p;
u8 byte;
u8 val[6] = {0x62, 0, 0x64, 0, 0x60, 0x05};
static const u8 sensor_init[] = {
0xdf, 0x6d,
0xdd, 0x18,
0x5a, 0xe0,
0x5c, 0x07,
0x5d, 0xb0,
0x5e, 0x1e,
0x60, 0x71,
0xef, 0x00,
0xe9, 0x00,
0xea, 0x00,
0x90, 0x24,
0x91, 0xb2,
0x82, 0x32,
0xfd, 0x41,
0x00
};
reg_w_buf(gspca_dev, sensor_reset, sizeof sensor_reset);
msleep(100);
i = 4;
while (--i > 0) {
byte = reg_r(gspca_dev, 0x0060);
if (!(byte & 0x01))
break;
msleep(100);
}
byte = reg_r(gspca_dev, 0x0063);
if (byte != 0x17) {
pr_err("Bad sensor reset %02x\n", byte);
}
p = sensor_init;
while (*p != 0) {
val[1] = *p++;
val[3] = *p++;
if (*p == 0)
reg_w(gspca_dev, 0x3c80);
reg_w_buf(gspca_dev, val, sizeof val);
i = 4;
while (--i >= 0) {
msleep(15);
byte = reg_r(gspca_dev, 0x60);
if (!(byte & 0x01))
break;
}
}
msleep(15);
reg_w(gspca_dev, 0x3c80);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam = &gspca_dev->cam;
cam->cam_mode = vga_mode_t16;
cam->nmodes = ARRAY_SIZE(vga_mode_t16);
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 brightness)
{
u8 set6[4] = { 0x8f, 0x24, 0xc3, 0x00 };
if (brightness < 7) {
set6[1] = 0x26;
set6[3] = 0x70 - brightness * 0x10;
} else {
set6[3] = 0x00 + ((brightness - 7) * 0x10);
}
reg_w_buf(gspca_dev, set6, sizeof set6);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 contrast)
{
u16 reg_to_write;
if (contrast < 7)
reg_to_write = 0x8ea9 - contrast * 0x200;
else
reg_to_write = 0x00a9 + (contrast - 7) * 0x200;
reg_w(gspca_dev, reg_to_write);
}
static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
u16 reg_to_write;
reg_to_write = 0x80bb + val * 0x100;
reg_w(gspca_dev, reg_to_write);
}
static void setgamma(struct gspca_dev *gspca_dev, s32 val)
{
PDEBUG(D_CONF, "Gamma: %d", val);
reg_w_ixbuf(gspca_dev, 0x90,
gamma_table[val], sizeof gamma_table[0]);
}
static void setawb_n_RGB(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 all_gain_reg[8] = {
0x87, 0x00, 0x88, 0x00, 0x89, 0x00, 0x80, 0x00 };
s32 red_gain, blue_gain, green_gain;
green_gain = sd->gain->val;
red_gain = green_gain + sd->red_balance->val;
if (red_gain > 0x40)
red_gain = 0x40;
else if (red_gain < 0x10)
red_gain = 0x10;
blue_gain = green_gain + sd->blue_balance->val;
if (blue_gain > 0x40)
blue_gain = 0x40;
else if (blue_gain < 0x10)
blue_gain = 0x10;
all_gain_reg[1] = red_gain;
all_gain_reg[3] = blue_gain;
all_gain_reg[5] = green_gain;
all_gain_reg[7] = sensor_data[sd->sensor].reg80;
if (!sd->awb->val)
all_gain_reg[7] &= ~0x04;
reg_w_buf(gspca_dev, all_gain_reg, sizeof all_gain_reg);
}
static void setsharpness(struct gspca_dev *gspca_dev, s32 val)
{
u16 reg_to_write;
reg_to_write = 0x0aa6 + 0x1000 * val;
reg_w(gspca_dev, reg_to_write);
}
static void setfreq(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 reg66;
u8 freq[4] = { 0x66, 0x00, 0xa8, 0xe8 };
switch (sd->sensor) {
case SENSOR_LT168G:
if (val != 0)
freq[3] = 0xa8;
reg66 = 0x41;
break;
case SENSOR_OM6802:
reg66 = 0xca;
break;
default:
reg66 = 0x40;
break;
}
switch (val) {
case 0:
freq[3] = 0xf0;
break;
case 2:
reg66 &= ~0x40;
break;
}
freq[1] = reg66;
reg_w_buf(gspca_dev, freq, sizeof freq);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const struct additional_sensor_data *sensor;
int i;
u16 sensor_id;
u8 test_byte = 0;
static const u8 read_indexs[] =
{ 0x0a, 0x0b, 0x66, 0x80, 0x81, 0x8e, 0x8f, 0xa5,
0xa6, 0xa8, 0xbb, 0xbc, 0xc6, 0x00 };
static const u8 n1[] =
{0x08, 0x03, 0x09, 0x03, 0x12, 0x04};
static const u8 n2[] =
{0x08, 0x00};
sensor_id = (reg_r(gspca_dev, 0x06) << 8)
| reg_r(gspca_dev, 0x07);
switch (sensor_id & 0xff0f) {
case 0x0801:
PDEBUG(D_PROBE, "sensor tas5130a");
sd->sensor = SENSOR_TAS5130A;
break;
case 0x0802:
PDEBUG(D_PROBE, "sensor lt168g");
sd->sensor = SENSOR_LT168G;
break;
case 0x0803:
PDEBUG(D_PROBE, "sensor 'other'");
sd->sensor = SENSOR_OTHER;
break;
case 0x0807:
PDEBUG(D_PROBE, "sensor om6802");
sd->sensor = SENSOR_OM6802;
break;
default:
pr_err("unknown sensor %04x\n", sensor_id);
return -EINVAL;
}
if (sd->sensor == SENSOR_OM6802) {
reg_w_buf(gspca_dev, n1, sizeof n1);
i = 5;
while (--i >= 0) {
reg_w_buf(gspca_dev, sensor_reset, sizeof sensor_reset);
test_byte = reg_r(gspca_dev, 0x0063);
msleep(100);
if (test_byte == 0x17)
break;
}
if (i < 0) {
pr_err("Bad sensor reset %02x\n", test_byte);
return -EIO;
}
reg_w_buf(gspca_dev, n2, sizeof n2);
}
i = 0;
while (read_indexs[i] != 0x00) {
test_byte = reg_r(gspca_dev, read_indexs[i]);
PDEBUG(D_STREAM, "Reg 0x%02x = 0x%02x", read_indexs[i],
test_byte);
i++;
}
sensor = &sensor_data[sd->sensor];
reg_w_buf(gspca_dev, sensor->n3, sizeof sensor->n3);
reg_w_buf(gspca_dev, sensor->n4, sensor->n4sz);
if (sd->sensor == SENSOR_LT168G) {
test_byte = reg_r(gspca_dev, 0x80);
PDEBUG(D_STREAM, "Reg 0x%02x = 0x%02x", 0x80,
test_byte);
reg_w(gspca_dev, 0x6c80);
}
reg_w_ixbuf(gspca_dev, 0xd0, sensor->data1, sizeof sensor->data1);
reg_w_ixbuf(gspca_dev, 0xc7, sensor->data2, sizeof sensor->data2);
reg_w_ixbuf(gspca_dev, 0xe0, sensor->data3, sizeof sensor->data3);
reg_w(gspca_dev, (sensor->reg80 << 8) + 0x80);
reg_w(gspca_dev, (sensor->reg80 << 8) + 0x80);
reg_w(gspca_dev, (sensor->reg8e << 8) + 0x8e);
reg_w(gspca_dev, (0x20 << 8) + 0x87);
reg_w(gspca_dev, (0x20 << 8) + 0x88);
reg_w(gspca_dev, (0x20 << 8) + 0x89);
reg_w_buf(gspca_dev, sensor->data5, sizeof sensor->data5);
reg_w_buf(gspca_dev, sensor->nset8, sizeof sensor->nset8);
reg_w_buf(gspca_dev, sensor->stream, sizeof sensor->stream);
if (sd->sensor == SENSOR_LT168G) {
test_byte = reg_r(gspca_dev, 0x80);
PDEBUG(D_STREAM, "Reg 0x%02x = 0x%02x", 0x80,
test_byte);
reg_w(gspca_dev, 0x6c80);
}
reg_w_ixbuf(gspca_dev, 0xd0, sensor->data1, sizeof sensor->data1);
reg_w_ixbuf(gspca_dev, 0xc7, sensor->data2, sizeof sensor->data2);
reg_w_ixbuf(gspca_dev, 0xe0, sensor->data3, sizeof sensor->data3);
return 0;
}
static void setmirror(struct gspca_dev *gspca_dev, s32 val)
{
u8 hflipcmd[8] =
{0x62, 0x07, 0x63, 0x03, 0x64, 0x00, 0x60, 0x09};
if (val)
hflipcmd[3] = 0x01;
reg_w_buf(gspca_dev, hflipcmd, sizeof hflipcmd);
}
static void seteffect(struct gspca_dev *gspca_dev, s32 val)
{
int idx = 0;
switch (val) {
case V4L2_COLORFX_NONE:
break;
case V4L2_COLORFX_BW:
idx = 2;
break;
case V4L2_COLORFX_SEPIA:
idx = 3;
break;
case V4L2_COLORFX_SKETCH:
idx = 4;
break;
case V4L2_COLORFX_NEGATIVE:
idx = 6;
break;
default:
break;
}
reg_w_buf(gspca_dev, effects_table[idx],
sizeof effects_table[0]);
if (val == V4L2_COLORFX_SKETCH)
reg_w(gspca_dev, 0x4aa6);
else
reg_w(gspca_dev, 0xfaa6);
}
static void poll_sensor(struct gspca_dev *gspca_dev)
{
static const u8 poll1[] =
{0x67, 0x05, 0x68, 0x81, 0x69, 0x80, 0x6a, 0x82,
0x6b, 0x68, 0x6c, 0x69, 0x72, 0xd9, 0x73, 0x34,
0x74, 0x32, 0x75, 0x92, 0x76, 0x00, 0x09, 0x01,
0x60, 0x14};
static const u8 poll2[] =
{0x67, 0x02, 0x68, 0x71, 0x69, 0x72, 0x72, 0xa9,
0x73, 0x02, 0x73, 0x02, 0x60, 0x14};
static const u8 noise03[] =
{0xa6, 0x0a, 0xea, 0xcf, 0xbe, 0x26, 0xb1, 0x5f,
0xa1, 0xb1, 0xda, 0x6b, 0xdb, 0x98, 0xdf, 0x0c,
0xc2, 0x80, 0xc3, 0x10};
PDEBUG(D_STREAM, "[Sensor requires polling]");
reg_w_buf(gspca_dev, poll1, sizeof poll1);
reg_w_buf(gspca_dev, poll2, sizeof poll2);
reg_w_buf(gspca_dev, noise03, sizeof noise03);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const struct additional_sensor_data *sensor;
int i, mode;
u8 t2[] = { 0x07, 0x00, 0x0d, 0x60, 0x0e, 0x80 };
static const u8 t3[] =
{ 0x07, 0x00, 0x88, 0x02, 0x06, 0x00, 0xe7, 0x01 };
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
switch (mode) {
case 0:
break;
case 1:
t2[1] = 0x40;
break;
case 2:
t2[1] = 0x10;
break;
case 3:
t2[1] = 0x50;
break;
default:
t2[1] = 0x20;
break;
}
switch (sd->sensor) {
case SENSOR_OM6802:
om6802_sensor_init(gspca_dev);
break;
case SENSOR_TAS5130A:
i = 0;
for (;;) {
reg_w_buf(gspca_dev, tas5130a_sensor_init[i],
sizeof tas5130a_sensor_init[0]);
if (i >= ARRAY_SIZE(tas5130a_sensor_init) - 1)
break;
i++;
}
reg_w(gspca_dev, 0x3c80);
reg_w_buf(gspca_dev, tas5130a_sensor_init[i],
sizeof tas5130a_sensor_init[0]);
reg_w(gspca_dev, 0x3c80);
break;
}
sensor = &sensor_data[sd->sensor];
setfreq(gspca_dev, v4l2_ctrl_g_ctrl(sd->freq));
reg_r(gspca_dev, 0x0012);
reg_w_buf(gspca_dev, t2, sizeof t2);
reg_w_ixbuf(gspca_dev, 0xb3, t3, sizeof t3);
reg_w(gspca_dev, 0x0013);
msleep(15);
reg_w_buf(gspca_dev, sensor->stream, sizeof sensor->stream);
reg_w_buf(gspca_dev, sensor->stream, sizeof sensor->stream);
if (sd->sensor == SENSOR_OM6802)
poll_sensor(gspca_dev);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w_buf(gspca_dev, sensor_data[sd->sensor].stream,
sizeof sensor_data[sd->sensor].stream);
reg_w_buf(gspca_dev, sensor_data[sd->sensor].stream,
sizeof sensor_data[sd->sensor].stream);
if (sd->sensor == SENSOR_OM6802) {
msleep(20);
reg_w(gspca_dev, 0x0309);
}
#if IS_ENABLED(CONFIG_INPUT)
if (sd->button_pressed) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
sd->button_pressed = 0;
}
#endif
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int pkt_type;
if (data[0] == 0x5a) {
#if IS_ENABLED(CONFIG_INPUT)
if (len > 20) {
u8 state = (data[20] & 0x80) ? 1 : 0;
if (sd->button_pressed != state) {
input_report_key(gspca_dev->input_dev,
KEY_CAMERA, state);
input_sync(gspca_dev->input_dev);
sd->button_pressed = state;
}
}
#endif
return;
}
data += 2;
len -= 2;
if (data[0] == 0xff && data[1] == 0xd8)
pkt_type = FIRST_PACKET;
else if (data[len - 2] == 0xff && data[len - 1] == 0xd9)
pkt_type = LAST_PACKET;
else
pkt_type = INTER_PACKET;
gspca_frame_add(gspca_dev, pkt_type, data, len);
}
static int sd_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
s32 red_gain, blue_gain, green_gain;
gspca_dev->usb_err = 0;
switch (ctrl->id) {
case V4L2_CID_AUTO_WHITE_BALANCE:
red_gain = reg_r(gspca_dev, 0x0087);
if (red_gain > 0x40)
red_gain = 0x40;
else if (red_gain < 0x10)
red_gain = 0x10;
blue_gain = reg_r(gspca_dev, 0x0088);
if (blue_gain > 0x40)
blue_gain = 0x40;
else if (blue_gain < 0x10)
blue_gain = 0x10;
green_gain = reg_r(gspca_dev, 0x0089);
if (green_gain > 0x40)
green_gain = 0x40;
else if (green_gain < 0x10)
green_gain = 0x10;
sd->gain->val = green_gain;
sd->red_balance->val = red_gain - green_gain;
sd->blue_balance->val = blue_gain - green_gain;
break;
}
return 0;
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
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
case V4L2_CID_GAMMA:
setgamma(gspca_dev, ctrl->val);
break;
case V4L2_CID_HFLIP:
setmirror(gspca_dev, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
setsharpness(gspca_dev, ctrl->val);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
setfreq(gspca_dev, ctrl->val);
break;
case V4L2_CID_BACKLIGHT_COMPENSATION:
reg_w(gspca_dev, ctrl->val ? 0xf48e : 0xb48e);
break;
case V4L2_CID_AUTO_WHITE_BALANCE:
setawb_n_RGB(gspca_dev);
break;
case V4L2_CID_COLORFX:
seteffect(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 12);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 14, 1, 8);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0x0d, 1, 7);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 0xf, 1, 5);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAMMA, 0, GAMMA_MAX, 1, 10);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BACKLIGHT_COMPENSATION, 0, 1, 1, 1);
if (sd->sensor == SENSOR_TAS5130A)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
sd->awb = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1);
sd->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0x10, 0x40, 1, 0x20);
sd->blue_balance = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BLUE_BALANCE, -0x30, 0x30, 1, 0);
sd->red_balance = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, -0x30, 0x30, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 15, 1, 6);
v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_COLORFX, V4L2_COLORFX_SKETCH,
~((1 << V4L2_COLORFX_NONE) |
(1 << V4L2_COLORFX_BW) |
(1 << V4L2_COLORFX_SEPIA) |
(1 << V4L2_COLORFX_SKETCH) |
(1 << V4L2_COLORFX_NEGATIVE)),
V4L2_COLORFX_NONE);
sd->freq = v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 1,
V4L2_CID_POWER_LINE_FREQUENCY_50HZ);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_auto_cluster(4, &sd->awb, 0, true);
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
