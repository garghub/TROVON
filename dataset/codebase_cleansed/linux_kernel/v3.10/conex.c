static void reg_r(struct gspca_dev *gspca_dev,
__u16 index,
__u16 len)
{
struct usb_device *dev = gspca_dev->dev;
if (len > USB_BUF_SZ) {
PERR("reg_r: buffer overflow\n");
return;
}
usb_control_msg(dev,
usb_rcvctrlpipe(dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, len,
500);
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
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, 1, 500);
}
static void reg_w(struct gspca_dev *gspca_dev,
__u16 index,
const __u8 *buffer,
__u16 len)
{
struct usb_device *dev = gspca_dev->dev;
if (len > USB_BUF_SZ) {
PERR("reg_w: buffer overflow\n");
return;
}
PDEBUG(D_USBO, "reg write [%02x] = %02x..", index, *buffer);
memcpy(gspca_dev->usb_buf, buffer, len);
usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, len, 500);
}
static void cx11646_fw(struct gspca_dev*gspca_dev)
{
int i = 0;
reg_w_val(gspca_dev, 0x006a, 0x02);
while (cx11646_fw1[i][1]) {
reg_w(gspca_dev, 0x006b, cx11646_fw1[i], 3);
i++;
}
reg_w_val(gspca_dev, 0x006a, 0x00);
}
static void cx_sensor(struct gspca_dev*gspca_dev)
{
int i = 0;
int length;
const __u8 *ptsensor = cxsensor;
reg_w(gspca_dev, 0x0020, reg20, 8);
reg_w(gspca_dev, 0x0028, reg28, 8);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0092, 0x03);
switch (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
case 0:
reg_w(gspca_dev, 0x0071, reg71a, 4);
break;
case 1:
reg_w(gspca_dev, 0x0071, reg71b, 4);
break;
default:
reg_w(gspca_dev, 0x0071, reg71c, 4);
break;
case 3:
reg_w(gspca_dev, 0x0071, reg71d, 4);
break;
}
reg_w(gspca_dev, 0x007b, reg7b, 6);
reg_w_val(gspca_dev, 0x00f8, 0x00);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0098, 0x41);
for (i = 0; i < 11; i++) {
if (i == 3 || i == 5 || i == 8)
length = 8;
else
length = 4;
reg_w(gspca_dev, 0x00e5, ptsensor, length);
if (length == 4)
reg_r(gspca_dev, 0x00e8, 1);
else
reg_r(gspca_dev, 0x00e8, length);
ptsensor += length;
}
reg_r(gspca_dev, 0x00e7, 8);
}
static void cx11646_initsize(struct gspca_dev *gspca_dev)
{
const __u8 *cxinit;
static const __u8 reg12[] = { 0x08, 0x05, 0x07, 0x04, 0x24 };
static const __u8 reg17[] =
{ 0x0a, 0x00, 0xf2, 0x01, 0x0f, 0x00, 0x97, 0x02 };
switch (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
case 0:
cxinit = cx_inits_640;
break;
case 1:
cxinit = cx_inits_352;
break;
default:
cxinit = cx_inits_320;
break;
case 3:
cxinit = cx_inits_176;
break;
}
reg_w_val(gspca_dev, 0x009a, 0x01);
reg_w_val(gspca_dev, 0x0010, 0x10);
reg_w(gspca_dev, 0x0012, reg12, 5);
reg_w(gspca_dev, 0x0017, reg17, 8);
reg_w_val(gspca_dev, 0x00c0, 0x00);
reg_w_val(gspca_dev, 0x00c1, 0x04);
reg_w_val(gspca_dev, 0x00c2, 0x04);
reg_w(gspca_dev, 0x0061, cxinit, 8);
cxinit += 8;
reg_w(gspca_dev, 0x00ca, cxinit, 8);
cxinit += 8;
reg_w(gspca_dev, 0x00d2, cxinit, 8);
cxinit += 8;
reg_w(gspca_dev, 0x00da, cxinit, 6);
cxinit += 8;
reg_w(gspca_dev, 0x0041, cxinit, 8);
cxinit += 8;
reg_w(gspca_dev, 0x0049, cxinit, 8);
cxinit += 8;
reg_w(gspca_dev, 0x0051, cxinit, 2);
reg_r(gspca_dev, 0x0010, 1);
}
static void cx11646_jpegInit(struct gspca_dev*gspca_dev)
{
int i;
int length;
reg_w_val(gspca_dev, 0x00c0, 0x01);
reg_w_val(gspca_dev, 0x00c3, 0x00);
reg_w_val(gspca_dev, 0x00c0, 0x00);
reg_r(gspca_dev, 0x0001, 1);
length = 8;
for (i = 0; i < 79; i++) {
if (i == 78)
length = 6;
reg_w(gspca_dev, 0x0008, cx_jpeg_init[i], length);
}
reg_r(gspca_dev, 0x0002, 1);
reg_w_val(gspca_dev, 0x0055, 0x14);
}
static void cx11646_jpeg(struct gspca_dev*gspca_dev)
{
int i;
int length;
__u8 Reg55;
int retry;
reg_w_val(gspca_dev, 0x00c0, 0x01);
reg_w_val(gspca_dev, 0x00c3, 0x00);
reg_w_val(gspca_dev, 0x00c0, 0x00);
reg_r(gspca_dev, 0x0001, 1);
length = 8;
switch (gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv) {
case 0:
for (i = 0; i < 27; i++) {
if (i == 26)
length = 2;
reg_w(gspca_dev, 0x0008, cxjpeg_640[i], length);
}
Reg55 = 0x28;
break;
case 1:
for (i = 0; i < 27; i++) {
if (i == 26)
length = 2;
reg_w(gspca_dev, 0x0008, cxjpeg_352[i], length);
}
Reg55 = 0x16;
break;
default:
for (i = 0; i < 27; i++) {
if (i == 26)
length = 2;
reg_w(gspca_dev, 0x0008, cxjpeg_320[i], length);
}
Reg55 = 0x14;
break;
case 3:
for (i = 0; i < 27; i++) {
if (i == 26)
length = 2;
reg_w(gspca_dev, 0x0008, cxjpeg_176[i], length);
}
Reg55 = 0x0B;
break;
}
reg_r(gspca_dev, 0x0002, 1);
reg_w_val(gspca_dev, 0x0055, Reg55);
reg_r(gspca_dev, 0x0002, 1);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0054, 0x02);
reg_w_val(gspca_dev, 0x0054, 0x01);
reg_w_val(gspca_dev, 0x0000, 0x94);
reg_w_val(gspca_dev, 0x0053, 0xc0);
reg_w_val(gspca_dev, 0x00fc, 0xe1);
reg_w_val(gspca_dev, 0x0000, 0x00);
retry = 50;
do {
reg_r(gspca_dev, 0x0002, 1);
if (gspca_dev->usb_buf[0] == 0x00)
break;
reg_w_val(gspca_dev, 0x0053, 0x00);
} while (--retry);
if (retry == 0)
PERR("Damned Errors sending jpeg Table");
reg_r(gspca_dev, 0x0001, 1);
length = 8;
for (i = 0; i < 18; i++) {
if (i == 17)
length = 2;
reg_w(gspca_dev, 0x0008, cxjpeg_qtable[i], length);
}
reg_r(gspca_dev, 0x0002, 1);
reg_r(gspca_dev, 0x0053, 1);
reg_w_val(gspca_dev, 0x0054, 0x02);
reg_w_val(gspca_dev, 0x0054, 0x01);
reg_w_val(gspca_dev, 0x0000, 0x94);
reg_w_val(gspca_dev, 0x0053, 0xc0);
reg_r(gspca_dev, 0x0038, 1);
reg_r(gspca_dev, 0x0038, 1);
reg_r(gspca_dev, 0x001f, 1);
reg_w(gspca_dev, 0x0012, reg12, 5);
reg_w(gspca_dev, 0x00e5, regE5_8, 8);
reg_r(gspca_dev, 0x00e8, 8);
reg_w(gspca_dev, 0x00e5, regE5a, 4);
reg_r(gspca_dev, 0x00e8, 1);
reg_w_val(gspca_dev, 0x009a, 0x01);
reg_w(gspca_dev, 0x00e5, regE5b, 4);
reg_r(gspca_dev, 0x00e8, 1);
reg_w(gspca_dev, 0x00e5, regE5c, 4);
reg_r(gspca_dev, 0x00e8, 1);
reg_w(gspca_dev, 0x0051, reg51, 2);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0070, reg70);
}
static void cx11646_init1(struct gspca_dev *gspca_dev)
{
int i = 0;
reg_w_val(gspca_dev, 0x0010, 0x00);
reg_w_val(gspca_dev, 0x0053, 0x00);
reg_w_val(gspca_dev, 0x0052, 0x00);
reg_w_val(gspca_dev, 0x009b, 0x2f);
reg_w_val(gspca_dev, 0x009c, 0x10);
reg_r(gspca_dev, 0x0098, 1);
reg_w_val(gspca_dev, 0x0098, 0x40);
reg_r(gspca_dev, 0x0099, 1);
reg_w_val(gspca_dev, 0x0099, 0x07);
reg_w_val(gspca_dev, 0x0039, 0x40);
reg_w_val(gspca_dev, 0x003c, 0xff);
reg_w_val(gspca_dev, 0x003f, 0x1f);
reg_w_val(gspca_dev, 0x003d, 0x40);
reg_r(gspca_dev, 0x0099, 1);
while (cx_sensor_init[i][0]) {
reg_w_val(gspca_dev, 0x00e5, cx_sensor_init[i][0]);
reg_r(gspca_dev, 0x00e8, 1);
if (i == 1) {
reg_w_val(gspca_dev, 0x00ed, 0x01);
reg_r(gspca_dev, 0x00ed, 1);
}
i++;
}
reg_w_val(gspca_dev, 0x00c3, 0x00);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
cx11646_init1(gspca_dev);
cx11646_initsize(gspca_dev);
cx11646_fw(gspca_dev);
cx_sensor(gspca_dev);
cx11646_jpegInit(gspca_dev);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
jpeg_define(sd->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x22);
jpeg_set_qual(sd->jpeg_hdr, QUALITY);
cx11646_initsize(gspca_dev);
cx11646_fw(gspca_dev);
cx_sensor(gspca_dev);
cx11646_jpeg(gspca_dev);
return 0;
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
int retry = 50;
if (!gspca_dev->present)
return;
reg_w_val(gspca_dev, 0x0000, 0x00);
reg_r(gspca_dev, 0x0002, 1);
reg_w_val(gspca_dev, 0x0053, 0x00);
while (retry--) {
reg_r(gspca_dev, 0x0053, 1);
if (gspca_dev->usb_buf[0] == 0)
break;
}
reg_w_val(gspca_dev, 0x0000, 0x00);
reg_r(gspca_dev, 0x0002, 1);
reg_w_val(gspca_dev, 0x0010, 0x00);
reg_r(gspca_dev, 0x0033, 1);
reg_w_val(gspca_dev, 0x00fc, 0xe0);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (data[0] == 0xff && data[1] == 0xd8) {
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
data += 2;
len -= 2;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val, s32 sat)
{
__u8 regE5cbx[] = { 0x88, 0x00, 0xd4, 0x01, 0x88, 0x01, 0x01, 0x01 };
__u8 reg51c[2];
regE5cbx[2] = val;
reg_w(gspca_dev, 0x00e5, regE5cbx, 8);
reg_r(gspca_dev, 0x00e8, 8);
reg_w(gspca_dev, 0x00e5, regE5c, 4);
reg_r(gspca_dev, 0x00e8, 1);
reg51c[0] = 0x77;
reg51c[1] = sat;
reg_w(gspca_dev, 0x0051, reg51c, 2);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0070, reg70);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val, s32 sat)
{
__u8 regE5acx[] = { 0x88, 0x0a, 0x0c, 0x01 };
__u8 reg51c[2];
regE5acx[2] = val;
reg_w(gspca_dev, 0x00e5, regE5acx, 4);
reg_r(gspca_dev, 0x00e8, 1);
reg51c[0] = 0x77;
reg51c[1] = sat;
reg_w(gspca_dev, 0x0051, reg51c, 2);
reg_w(gspca_dev, 0x0010, reg10, 2);
reg_w_val(gspca_dev, 0x0070, reg70);
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
setbrightness(gspca_dev, ctrl->val, sd->sat->cur.val);
break;
case V4L2_CID_CONTRAST:
setcontrast(gspca_dev, ctrl->val, sd->sat->cur.val);
break;
case V4L2_CID_SATURATION:
setbrightness(gspca_dev, sd->brightness->cur.val, ctrl->val);
setcontrast(gspca_dev, sd->contrast->cur.val, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 3);
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 0xd4);
sd->contrast = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0x0a, 0x1f, 1, 0x0c);
sd->sat = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 7, 1, 3);
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
