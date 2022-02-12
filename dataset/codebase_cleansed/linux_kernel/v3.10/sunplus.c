static void reg_r(struct gspca_dev *gspca_dev,
u8 req,
u16 index,
u16 len)
{
int ret;
if (len > USB_BUF_SZ) {
PERR("reg_r: buffer overflow\n");
return;
}
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index,
len ? gspca_dev->usb_buf : NULL, len,
500);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w_1(struct gspca_dev *gspca_dev,
u8 req,
u16 value,
u16 index,
u16 byte)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
gspca_dev->usb_buf[0] = byte;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index,
gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w_1 err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w_riv(struct gspca_dev *gspca_dev,
u8 req, u16 index, u16 value)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
if (ret < 0) {
pr_err("reg_w_riv err %d\n", ret);
gspca_dev->usb_err = ret;
return;
}
PDEBUG(D_USBO, "reg_w_riv: 0x%02x,0x%04x:0x%04x",
req, index, value);
}
static void write_vector(struct gspca_dev *gspca_dev,
const struct cmd *data, int ncmds)
{
while (--ncmds >= 0) {
reg_w_riv(gspca_dev, data->req, data->idx, data->val);
data++;
}
}
static void setup_qtable(struct gspca_dev *gspca_dev,
const u8 qtable[2][64])
{
int i;
for (i = 0; i < 64; i++)
reg_w_riv(gspca_dev, 0x00, 0x2800 + i, qtable[0][i]);
for (i = 0; i < 64; i++)
reg_w_riv(gspca_dev, 0x00, 0x2840 + i, qtable[1][i]);
}
static void spca504_acknowledged_command(struct gspca_dev *gspca_dev,
u8 req, u16 idx, u16 val)
{
reg_w_riv(gspca_dev, req, idx, val);
reg_r(gspca_dev, 0x01, 0x0001, 1);
PDEBUG(D_FRAM, "before wait 0x%04x", gspca_dev->usb_buf[0]);
reg_w_riv(gspca_dev, req, idx, val);
msleep(200);
reg_r(gspca_dev, 0x01, 0x0001, 1);
PDEBUG(D_FRAM, "after wait 0x%04x", gspca_dev->usb_buf[0]);
}
static void spca504_read_info(struct gspca_dev *gspca_dev)
{
int i;
u8 info[6];
if (gspca_debug < D_STREAM)
return;
for (i = 0; i < 6; i++) {
reg_r(gspca_dev, 0, i, 1);
info[i] = gspca_dev->usb_buf[0];
}
PDEBUG(D_STREAM,
"Read info: %d %d %d %d %d %d."
" Should be 1,0,2,2,0,0",
info[0], info[1], info[2],
info[3], info[4], info[5]);
}
static void spca504A_acknowledged_command(struct gspca_dev *gspca_dev,
u8 req,
u16 idx, u16 val, u8 endcode, u8 count)
{
u16 status;
reg_w_riv(gspca_dev, req, idx, val);
reg_r(gspca_dev, 0x01, 0x0001, 1);
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_FRAM, "Status 0x%02x Need 0x%02x",
gspca_dev->usb_buf[0], endcode);
if (!count)
return;
count = 200;
while (--count > 0) {
msleep(10);
reg_r(gspca_dev, 0x01, 0x0001, 1);
status = gspca_dev->usb_buf[0];
if (status == endcode) {
PDEBUG(D_FRAM, "status 0x%04x after wait %d",
status, 200 - count);
break;
}
}
}
static void spca504B_PollingDataReady(struct gspca_dev *gspca_dev)
{
int count = 10;
while (--count > 0) {
reg_r(gspca_dev, 0x21, 0, 1);
if ((gspca_dev->usb_buf[0] & 0x01) == 0)
break;
msleep(10);
}
}
static void spca504B_WaitCmdStatus(struct gspca_dev *gspca_dev)
{
int count = 50;
while (--count > 0) {
reg_r(gspca_dev, 0x21, 1, 1);
if (gspca_dev->usb_buf[0] != 0) {
reg_w_1(gspca_dev, 0x21, 0, 1, 0);
reg_r(gspca_dev, 0x21, 1, 1);
spca504B_PollingDataReady(gspca_dev);
break;
}
msleep(10);
}
}
static void spca50x_GetFirmware(struct gspca_dev *gspca_dev)
{
u8 *data;
if (gspca_debug < D_STREAM)
return;
data = gspca_dev->usb_buf;
reg_r(gspca_dev, 0x20, 0, 5);
PDEBUG(D_STREAM, "FirmWare: %d %d %d %d %d",
data[0], data[1], data[2], data[3], data[4]);
reg_r(gspca_dev, 0x23, 0, 64);
reg_r(gspca_dev, 0x23, 1, 64);
}
static void spca504B_SetSizeType(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 Size;
Size = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
switch (sd->bridge) {
case BRIDGE_SPCA533:
reg_w_riv(gspca_dev, 0x31, 0, 0);
spca504B_WaitCmdStatus(gspca_dev);
spca504B_PollingDataReady(gspca_dev);
spca50x_GetFirmware(gspca_dev);
reg_w_1(gspca_dev, 0x24, 0, 8, 2);
reg_r(gspca_dev, 0x24, 8, 1);
reg_w_1(gspca_dev, 0x25, 0, 4, Size);
reg_r(gspca_dev, 0x25, 4, 1);
spca504B_PollingDataReady(gspca_dev);
reg_w_riv(gspca_dev, 0x31, 0x0004, 0x00);
spca504B_WaitCmdStatus(gspca_dev);
spca504B_PollingDataReady(gspca_dev);
break;
default:
reg_w_1(gspca_dev, 0x25, 0, 4, Size);
reg_r(gspca_dev, 0x25, 4, 1);
reg_w_1(gspca_dev, 0x27, 0, 0, 6);
reg_r(gspca_dev, 0x27, 0, 1);
spca504B_PollingDataReady(gspca_dev);
break;
case BRIDGE_SPCA504:
Size += 3;
if (sd->subtype == AiptekMiniPenCam13) {
spca504A_acknowledged_command(gspca_dev,
0x08, Size, 0,
0x80 | (Size & 0x0f), 1);
spca504A_acknowledged_command(gspca_dev,
1, 3, 0, 0x9f, 0);
} else {
spca504_acknowledged_command(gspca_dev, 0x08, Size, 0);
}
break;
case BRIDGE_SPCA504C:
reg_w_riv(gspca_dev, 0xa0, (0x0500 | (Size & 0x0f)), 0x00);
reg_w_riv(gspca_dev, 0x20, 0x01, 0x0500 | (Size & 0x0f));
break;
}
}
static void spca504_wait_status(struct gspca_dev *gspca_dev)
{
int cnt;
cnt = 256;
while (--cnt > 0) {
reg_r(gspca_dev, 0x06, 0x00, 1);
if (gspca_dev->usb_buf[0] == 0)
return;
msleep(10);
}
}
static void spca504B_setQtable(struct gspca_dev *gspca_dev)
{
reg_w_1(gspca_dev, 0x26, 0, 0, 3);
reg_r(gspca_dev, 0x26, 0, 1);
spca504B_PollingDataReady(gspca_dev);
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg;
reg = sd->bridge == BRIDGE_SPCA536 ? 0x20f0 : 0x21a7;
reg_w_riv(gspca_dev, 0x00, reg, val);
}
static void setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg;
reg = sd->bridge == BRIDGE_SPCA536 ? 0x20f1 : 0x21a8;
reg_w_riv(gspca_dev, 0x00, reg, val);
}
static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg;
reg = sd->bridge == BRIDGE_SPCA536 ? 0x20f6 : 0x21ae;
reg_w_riv(gspca_dev, 0x00, reg, val);
}
static void init_ctl_reg(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int pollreg = 1;
switch (sd->bridge) {
case BRIDGE_SPCA504:
case BRIDGE_SPCA504C:
pollreg = 0;
default:
reg_w_riv(gspca_dev, 0, 0x21ad, 0x00);
reg_w_riv(gspca_dev, 0, 0x21ac, 0x01);
reg_w_riv(gspca_dev, 0, 0x21a3, 0x00);
break;
case BRIDGE_SPCA536:
reg_w_riv(gspca_dev, 0, 0x20f5, 0x40);
reg_w_riv(gspca_dev, 0, 0x20f4, 0x01);
reg_w_riv(gspca_dev, 0, 0x2089, 0x00);
break;
}
if (pollreg)
spca504B_PollingDataReady(gspca_dev);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
sd->bridge = id->driver_info >> 8;
sd->subtype = id->driver_info;
if (sd->subtype == AiptekMiniPenCam13) {
reg_r(gspca_dev, 0x20, 0, 1);
switch (gspca_dev->usb_buf[0]) {
case 1:
break;
case 2:
sd->bridge = BRIDGE_SPCA504B;
sd->subtype = 0;
break;
default:
return -ENODEV;
}
}
switch (sd->bridge) {
default:
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
break;
case BRIDGE_SPCA533:
cam->cam_mode = custom_mode;
if (sd->subtype == MegaImageVI)
cam->nmodes = ARRAY_SIZE(custom_mode) - 1;
else
cam->nmodes = ARRAY_SIZE(custom_mode);
break;
case BRIDGE_SPCA504C:
cam->cam_mode = vga_mode2;
cam->nmodes = ARRAY_SIZE(vga_mode2);
break;
}
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->bridge) {
case BRIDGE_SPCA504B:
reg_w_riv(gspca_dev, 0x1d, 0x00, 0);
reg_w_riv(gspca_dev, 0x00, 0x2306, 0x01);
reg_w_riv(gspca_dev, 0x00, 0x0d04, 0x00);
reg_w_riv(gspca_dev, 0x00, 0x2000, 0x00);
reg_w_riv(gspca_dev, 0x00, 0x2301, 0x13);
reg_w_riv(gspca_dev, 0x00, 0x2306, 0x00);
case BRIDGE_SPCA533:
spca504B_PollingDataReady(gspca_dev);
spca50x_GetFirmware(gspca_dev);
break;
case BRIDGE_SPCA536:
spca50x_GetFirmware(gspca_dev);
reg_r(gspca_dev, 0x00, 0x5002, 1);
reg_w_1(gspca_dev, 0x24, 0, 0, 0);
reg_r(gspca_dev, 0x24, 0, 1);
spca504B_PollingDataReady(gspca_dev);
reg_w_riv(gspca_dev, 0x34, 0, 0);
spca504B_WaitCmdStatus(gspca_dev);
break;
case BRIDGE_SPCA504C:
PDEBUG(D_STREAM, "Opening SPCA504 (PC-CAM 600)");
reg_w_riv(gspca_dev, 0xe0, 0x0000, 0x0000);
reg_w_riv(gspca_dev, 0xe0, 0x0000, 0x0001);
spca504_wait_status(gspca_dev);
if (sd->subtype == LogitechClickSmart420)
write_vector(gspca_dev,
spca504A_clicksmart420_open_data,
ARRAY_SIZE(spca504A_clicksmart420_open_data));
else
write_vector(gspca_dev, spca504_pccam600_open_data,
ARRAY_SIZE(spca504_pccam600_open_data));
setup_qtable(gspca_dev, qtable_creative_pccam);
break;
default:
PDEBUG(D_STREAM, "Opening SPCA504");
if (sd->subtype == AiptekMiniPenCam13) {
spca504_read_info(gspca_dev);
spca504A_acknowledged_command(gspca_dev, 0x24,
8, 3, 0x9e, 1);
spca504A_acknowledged_command(gspca_dev, 0x24,
8, 3, 0x9e, 0);
spca504A_acknowledged_command(gspca_dev, 0x24,
0, 0, 0x9d, 1);
spca504A_acknowledged_command(gspca_dev, 0x08,
6, 0, 0x86, 1);
reg_w_riv(gspca_dev, 0x00, 0x270c, 0x05);
reg_w_riv(gspca_dev, 0x00, 0x2310, 0x05);
spca504A_acknowledged_command(gspca_dev, 0x01,
0x0f, 0, 0xff, 0);
}
reg_w_riv(gspca_dev, 0, 0x2000, 0);
reg_w_riv(gspca_dev, 0, 0x2883, 1);
setup_qtable(gspca_dev, qtable_spca504_default);
break;
}
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int enable;
jpeg_define(sd->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x22);
jpeg_set_qual(sd->jpeg_hdr, QUALITY);
if (sd->bridge == BRIDGE_SPCA504B)
spca504B_setQtable(gspca_dev);
spca504B_SetSizeType(gspca_dev);
switch (sd->bridge) {
default:
switch (sd->subtype) {
case MegapixV4:
case LogitechClickSmart820:
case MegaImageVI:
reg_w_riv(gspca_dev, 0xf0, 0, 0);
spca504B_WaitCmdStatus(gspca_dev);
reg_r(gspca_dev, 0xf0, 4, 0);
spca504B_WaitCmdStatus(gspca_dev);
break;
default:
reg_w_riv(gspca_dev, 0x31, 0x0004, 0x00);
spca504B_WaitCmdStatus(gspca_dev);
spca504B_PollingDataReady(gspca_dev);
break;
}
break;
case BRIDGE_SPCA504:
if (sd->subtype == AiptekMiniPenCam13) {
spca504_read_info(gspca_dev);
spca504A_acknowledged_command(gspca_dev, 0x24,
8, 3, 0x9e, 1);
spca504A_acknowledged_command(gspca_dev, 0x24,
8, 3, 0x9e, 0);
spca504A_acknowledged_command(gspca_dev, 0x24,
0, 0, 0x9d, 1);
} else {
spca504_acknowledged_command(gspca_dev, 0x24, 8, 3);
spca504_read_info(gspca_dev);
spca504_acknowledged_command(gspca_dev, 0x24, 8, 3);
spca504_acknowledged_command(gspca_dev, 0x24, 0, 0);
}
spca504B_SetSizeType(gspca_dev);
reg_w_riv(gspca_dev, 0x00, 0x270c, 0x05);
reg_w_riv(gspca_dev, 0x00, 0x2310, 0x05);
break;
case BRIDGE_SPCA504C:
if (sd->subtype == LogitechClickSmart420) {
write_vector(gspca_dev,
spca504A_clicksmart420_init_data,
ARRAY_SIZE(spca504A_clicksmart420_init_data));
} else {
write_vector(gspca_dev, spca504_pccam600_init_data,
ARRAY_SIZE(spca504_pccam600_init_data));
}
enable = (sd->autogain ? 0x04 : 0x01);
reg_w_riv(gspca_dev, 0x0c, 0x0000, enable);
reg_w_riv(gspca_dev, 0xb0, 0x0000, enable);
reg_w_riv(gspca_dev, 0x30, 0x0001, 800);
reg_w_riv(gspca_dev, 0x30, 0x0002, 1600);
spca504B_SetSizeType(gspca_dev);
break;
}
init_ctl_reg(gspca_dev);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->bridge) {
default:
reg_w_riv(gspca_dev, 0x31, 0, 0);
spca504B_WaitCmdStatus(gspca_dev);
spca504B_PollingDataReady(gspca_dev);
break;
case BRIDGE_SPCA504:
case BRIDGE_SPCA504C:
reg_w_riv(gspca_dev, 0x00, 0x2000, 0x0000);
if (sd->subtype == AiptekMiniPenCam13) {
spca504A_acknowledged_command(gspca_dev, 0x24,
0x00, 0x00, 0x9d, 1);
spca504A_acknowledged_command(gspca_dev, 0x01,
0x0f, 0x00, 0xff, 1);
} else {
spca504_acknowledged_command(gspca_dev, 0x24, 0, 0);
reg_w_riv(gspca_dev, 0x01, 0x000f, 0x0000);
}
break;
}
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, sof = 0;
static u8 ffd9[] = {0xff, 0xd9};
switch (sd->bridge) {
case BRIDGE_SPCA533:
if (data[0] == 0xff) {
if (data[1] != 0x01) {
return;
}
sof = 1;
data += SPCA533_OFFSET_DATA;
len -= SPCA533_OFFSET_DATA;
} else {
data += 1;
len -= 1;
}
break;
case BRIDGE_SPCA536:
if (data[0] == 0xff) {
sof = 1;
data += SPCA536_OFFSET_DATA;
len -= SPCA536_OFFSET_DATA;
} else {
data += 2;
len -= 2;
}
break;
default:
switch (data[0]) {
case 0xfe:
sof = 1;
data += SPCA50X_OFFSET_DATA;
len -= SPCA50X_OFFSET_DATA;
break;
case 0xff:
return;
default:
data += 1;
len -= 1;
break;
}
break;
case BRIDGE_SPCA504C:
switch (data[0]) {
case 0xfe:
sof = 1;
data += SPCA504_PCCAM600_OFFSET_DATA;
len -= SPCA504_PCCAM600_OFFSET_DATA;
break;
case 0xff:
return;
default:
data += 1;
len -= 1;
break;
}
break;
}
if (sof) {
gspca_frame_add(gspca_dev, LAST_PACKET,
ffd9, 2);
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
}
i = 0;
do {
if (data[i] == 0xff) {
gspca_frame_add(gspca_dev, INTER_PACKET,
data, i + 1);
len -= i;
data += i;
*data = 0x00;
i = 0;
}
i++;
} while (i < len);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
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
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 0x20);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 0x1a);
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
