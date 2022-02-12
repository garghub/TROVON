static void reg_w_buf(struct gspca_dev *gspca_dev,
u8 index,
const u8 *buffer, int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
memcpy(gspca_dev->usb_buf, buffer, len);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, len,
500);
if (ret < 0) {
pr_err("reg_w_buf failed i: %02x error %d\n",
index, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
u8 index,
u8 value)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
gspca_dev->usb_buf[0] = value;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, index, gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w() failed i: %02x v: %02x error %d\n",
index, value, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w_seq(struct gspca_dev *gspca_dev,
const u8 *seq, int len)
{
while (--len >= 0) {
reg_w(gspca_dev, seq[0], seq[1]);
seq += 2;
}
}
static void reg_w_page(struct gspca_dev *gspca_dev,
const u8 *page, int len)
{
int index;
int ret = 0;
if (gspca_dev->usb_err < 0)
return;
for (index = 0; index < len; index++) {
if (page[index] == SKIP)
continue;
gspca_dev->usb_buf[0] = page[index];
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, index, gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w_page() failed i: %02x v: %02x error %d\n",
index, page[index], ret);
gspca_dev->usb_err = ret;
break;
}
}
}
static void reg_w_var(struct gspca_dev *gspca_dev,
const u8 *seq,
const u8 *page3, unsigned int page3_len)
{
int index, len;
for (;;) {
index = *seq++;
len = *seq++;
switch (len) {
case END_OF_SEQUENCE:
return;
case LOAD_PAGE3:
reg_w_page(gspca_dev, page3, page3_len);
break;
default:
#ifdef GSPCA_DEBUG
if (len > USB_BUF_SZ) {
PDEBUG(D_ERR|D_STREAM,
"Incorrect variable sequence");
return;
}
#endif
while (len > 0) {
if (len < 8) {
reg_w_buf(gspca_dev,
index, seq, len);
seq += len;
break;
}
reg_w_buf(gspca_dev, index, seq, 8);
seq += 8;
index += 8;
len -= 8;
}
}
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
sd->flags = id->driver_info;
return 0;
}
static void setbrightcont(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, v;
static const u8 max[10] =
{0x29, 0x33, 0x42, 0x5a, 0x6e, 0x80, 0x9f, 0xbb,
0xd4, 0xec};
static const u8 delta[10] =
{0x35, 0x33, 0x33, 0x2f, 0x2a, 0x25, 0x1e, 0x17,
0x11, 0x0b};
reg_w(gspca_dev, 0xff, 0x00);
for (i = 0; i < 10; i++) {
v = max[i];
v += (sd->brightness->val - sd->brightness->maximum)
* 150 / sd->brightness->maximum;
v -= delta[i] * sd->contrast->val / sd->contrast->maximum;
if (v < 0)
v = 0;
else if (v > 0xff)
v = 0xff;
reg_w(gspca_dev, 0xa2 + i, v);
}
reg_w(gspca_dev, 0xdc, 0x01);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, v;
static const int a[9] =
{217, -212, 0, -101, 170, -67, -38, -315, 355};
static const int b[9] =
{19, 106, 0, 19, 106, 1, 19, 106, 1};
reg_w(gspca_dev, 0xff, 0x03);
reg_w(gspca_dev, 0x11, 0x01);
reg_w(gspca_dev, 0xff, 0x00);
for (i = 0; i < 9; i++) {
v = a[i] * sd->saturation->val / sd->saturation->maximum;
v += b[i];
reg_w(gspca_dev, 0x0f + 2 * i, (v >> 8) & 0x07);
reg_w(gspca_dev, 0x0f + 2 * i + 1, v);
}
reg_w(gspca_dev, 0xdc, 0x01);
}
static void setwhitebalance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0xff, 0x00);
reg_w(gspca_dev, 0xc6, sd->white_balance->val);
reg_w(gspca_dev, 0xdc, 0x01);
}
static void setredbalance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0xff, 0x00);
reg_w(gspca_dev, 0xc5, sd->red_balance->val);
reg_w(gspca_dev, 0xdc, 0x01);
}
static void setbluebalance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0xff, 0x00);
reg_w(gspca_dev, 0xc7, sd->blue_balance->val);
reg_w(gspca_dev, 0xdc, 0x01);
}
static void setgain(struct gspca_dev *gspca_dev)
{
u8 reg10, reg12;
if (gspca_dev->gain->val < 32) {
reg10 = gspca_dev->gain->val;
reg12 = 0;
} else {
reg10 = 31;
reg12 = gspca_dev->gain->val - 31;
}
reg_w(gspca_dev, 0xff, 0x03);
reg_w(gspca_dev, 0x10, reg10);
reg_w(gspca_dev, 0x12, reg12);
reg_w(gspca_dev, 0x11, 0x01);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
u8 clockdiv;
u16 exposure;
clockdiv = (90 * gspca_dev->exposure->val + 1999) / 2000;
if (clockdiv < 6)
clockdiv = 6;
else if (clockdiv > 63)
clockdiv = 63;
if (clockdiv < 6 || clockdiv > 12)
clockdiv = ((clockdiv + 2) / 3) * 3;
exposure = (gspca_dev->exposure->val * 45 * 448) / (1000 * clockdiv);
exposure = 448 - exposure;
reg_w(gspca_dev, 0xff, 0x03);
reg_w(gspca_dev, 0x02, clockdiv);
reg_w(gspca_dev, 0x0e, exposure & 0xff);
reg_w(gspca_dev, 0x0f, exposure >> 8);
reg_w(gspca_dev, 0x11, 0x01);
}
static void sethvflip(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data, hflip, vflip;
hflip = sd->hflip->val;
if (sd->flags & FL_HFLIP)
hflip = !hflip;
vflip = sd->vflip->val;
if (sd->flags & FL_VFLIP)
vflip = !vflip;
reg_w(gspca_dev, 0xff, 0x03);
data = (hflip ? 0x08 : 0x00) | (vflip ? 0x04 : 0x00);
reg_w(gspca_dev, 0x21, data);
reg_w(gspca_dev, 0x11, 0x01);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
reg_w_seq(gspca_dev, init_7302, sizeof(init_7302)/2);
return gspca_dev->usb_err;
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (ctrl->id == V4L2_CID_AUTOGAIN && ctrl->is_new && ctrl->val) {
gspca_dev->exposure->val = PAC7302_EXPOSURE_DEFAULT;
gspca_dev->gain->val = PAC7302_GAIN_DEFAULT;
sd->autogain_ignore_frames = PAC_AUTOGAIN_IGNORE_FRAMES;
}
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
setbrightcont(gspca_dev);
break;
case V4L2_CID_SATURATION:
setcolors(gspca_dev);
break;
case V4L2_CID_WHITE_BALANCE_TEMPERATURE:
setwhitebalance(gspca_dev);
break;
case V4L2_CID_RED_BALANCE:
setredbalance(gspca_dev);
break;
case V4L2_CID_BLUE_BALANCE:
setbluebalance(gspca_dev);
break;
case V4L2_CID_AUTOGAIN:
if (gspca_dev->exposure->is_new || (ctrl->is_new && ctrl->val))
setexposure(gspca_dev);
if (gspca_dev->gain->is_new || (ctrl->is_new && ctrl->val))
setgain(gspca_dev);
break;
case V4L2_CID_HFLIP:
sethvflip(gspca_dev);
break;
default:
return -EINVAL;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 11);
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 32, 1, 16);
sd->contrast = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 127);
sd->saturation = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 127);
sd->white_balance = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_WHITE_BALANCE_TEMPERATURE,
0, 255, 1, 4);
sd->red_balance = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 3, 1, 1);
sd->blue_balance = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 3, 1, 1);
gspca_dev->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 1023, 1,
PAC7302_EXPOSURE_DEFAULT);
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 62, 1,
PAC7302_GAIN_DEFAULT);
sd->hflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
sd->vflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_cluster(2, &sd->brightness);
v4l2_ctrl_auto_cluster(3, &gspca_dev->autogain, 0, false);
v4l2_ctrl_cluster(2, &sd->hflip);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w_var(gspca_dev, start_7302,
page3_7302, sizeof(page3_7302));
setbrightcont(gspca_dev);
setcolors(gspca_dev);
setwhitebalance(gspca_dev);
setredbalance(gspca_dev);
setbluebalance(gspca_dev);
setexposure(gspca_dev);
setgain(gspca_dev);
sethvflip(gspca_dev);
sd->sof_read = 0;
sd->autogain_ignore_frames = 0;
atomic_set(&sd->avg_lum, 270 + sd->brightness->val);
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x78, 0x01);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x78, 0x00);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
if (!gspca_dev->present)
return;
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x78, 0x40);
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum = atomic_read(&sd->avg_lum);
int desired_lum;
const int deadzone = 30;
if (sd->autogain_ignore_frames < 0)
return;
if (sd->autogain_ignore_frames > 0) {
sd->autogain_ignore_frames--;
} else {
desired_lum = 270 + sd->brightness->val;
if (gspca_expo_autogain(gspca_dev, avg_lum, desired_lum,
deadzone, PAC7302_GAIN_KNEE,
PAC7302_EXPOSURE_KNEE))
sd->autogain_ignore_frames =
PAC_AUTOGAIN_IGNORE_FRAMES;
}
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 *image;
u8 *sof;
sof = pac_find_sof(&sd->sof_read, data, len);
if (sof) {
int n, lum_offset, footer_length;
lum_offset = 61 + sizeof pac_sof_marker;
footer_length = 74;
n = (sof - data) - (footer_length + sizeof pac_sof_marker);
if (n < 0) {
gspca_dev->image_len += n;
n = 0;
} else {
gspca_frame_add(gspca_dev, INTER_PACKET, data, n);
}
image = gspca_dev->image;
if (image != NULL
&& image[gspca_dev->image_len - 2] == 0xff
&& image[gspca_dev->image_len - 1] == 0xd9)
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
n = sof - data;
len -= n;
data = sof;
if (gspca_dev->last_packet_type == LAST_PACKET &&
n >= lum_offset)
atomic_set(&sd->avg_lum, data[-lum_offset] +
data[-lum_offset + 1]);
gspca_frame_add(gspca_dev, FIRST_PACKET,
jpeg_header, sizeof jpeg_header);
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_dbg_s_register(struct gspca_dev *gspca_dev,
struct v4l2_dbg_register *reg)
{
u8 index;
u8 value;
if (reg->match.type == V4L2_CHIP_MATCH_HOST &&
reg->match.addr == 0 &&
(reg->reg < 0x000000ff) &&
(reg->val <= 0x000000ff)
) {
index = reg->reg;
value = reg->val;
reg_w(gspca_dev, 0xff, 0x00);
reg_w(gspca_dev, index, value);
reg_w(gspca_dev, 0xdc, 0x01);
}
return gspca_dev->usb_err;
}
static int sd_chip_ident(struct gspca_dev *gspca_dev,
struct v4l2_dbg_chip_ident *chip)
{
int ret = -EINVAL;
if (chip->match.type == V4L2_CHIP_MATCH_HOST &&
chip->match.addr == 0) {
chip->revision = 0;
chip->ident = V4L2_IDENT_UNKNOWN;
ret = 0;
}
return ret;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
u8 data0, data1;
if (len == 2) {
data0 = data[0];
data1 = data[1];
if ((data0 == 0x00 && data1 == 0x11) ||
(data0 == 0x22 && data1 == 0x33) ||
(data0 == 0x44 && data1 == 0x55) ||
(data0 == 0x66 && data1 == 0x77) ||
(data0 == 0x88 && data1 == 0x99) ||
(data0 == 0xaa && data1 == 0xbb) ||
(data0 == 0xcc && data1 == 0xdd) ||
(data0 == 0xee && data1 == 0xff)) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
}
return ret;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
