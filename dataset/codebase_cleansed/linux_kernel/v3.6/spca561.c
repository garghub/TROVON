static void reg_w_val(struct usb_device *dev, __u16 index, __u8 value)
{
int ret;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
PDEBUG(D_USBO, "reg write: 0x%02x:0x%02x", index, value);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
}
static void write_vector(struct gspca_dev *gspca_dev,
const __u16 data[][2])
{
struct usb_device *dev = gspca_dev->dev;
int i;
i = 0;
while (data[i][1] != 0) {
reg_w_val(dev, data[i][1], data[i][0]);
i++;
}
}
static void reg_r(struct gspca_dev *gspca_dev,
__u16 index, __u16 length)
{
usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, length, 500);
}
static void reg_w_buf(struct gspca_dev *gspca_dev,
__u16 index, __u16 len)
{
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, len, 500);
}
static void i2c_write(struct gspca_dev *gspca_dev, __u16 value, __u16 reg)
{
int retry = 60;
reg_w_val(gspca_dev->dev, 0x8801, reg);
reg_w_val(gspca_dev->dev, 0x8805, value);
reg_w_val(gspca_dev->dev, 0x8800, value >> 8);
do {
reg_r(gspca_dev, 0x8803, 1);
if (!gspca_dev->usb_buf[0])
return;
msleep(10);
} while (--retry);
}
static int i2c_read(struct gspca_dev *gspca_dev, __u16 reg, __u8 mode)
{
int retry = 60;
__u8 value;
reg_w_val(gspca_dev->dev, 0x8804, 0x92);
reg_w_val(gspca_dev->dev, 0x8801, reg);
reg_w_val(gspca_dev->dev, 0x8802, mode | 0x01);
do {
reg_r(gspca_dev, 0x8803, 1);
if (!gspca_dev->usb_buf[0]) {
reg_r(gspca_dev, 0x8800, 1);
value = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8805, 1);
return ((int) value << 8) | gspca_dev->usb_buf[0];
}
msleep(10);
} while (--retry);
return -1;
}
static void init_161rev12A(struct gspca_dev *gspca_dev)
{
write_vector(gspca_dev, spca561_161rev12A_data1);
sensor_mapwrite(gspca_dev, Pb100_1map8300);
write_vector(gspca_dev, spca561_161rev12A_data2);
sensor_mapwrite(gspca_dev, Pb100_2map8300);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
__u16 vendor, product;
__u8 data1, data2;
reg_r(gspca_dev, 0x8104, 1);
data1 = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8105, 1);
data2 = gspca_dev->usb_buf[0];
vendor = (data2 << 8) | data1;
reg_r(gspca_dev, 0x8106, 1);
data1 = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8107, 1);
data2 = gspca_dev->usb_buf[0];
product = (data2 << 8) | data1;
if (vendor != id->idVendor || product != id->idProduct) {
PDEBUG(D_PROBE, "Bad vendor / product from device");
return -EINVAL;
}
cam = &gspca_dev->cam;
cam->needs_full_bandwidth = 1;
sd->chip_revision = id->driver_info;
if (sd->chip_revision == Rev012A) {
cam->cam_mode = sif_012a_mode;
cam->nmodes = ARRAY_SIZE(sif_012a_mode);
} else {
cam->cam_mode = sif_072a_mode;
cam->nmodes = ARRAY_SIZE(sif_072a_mode);
}
sd->expo12a = EXPO12A_DEF;
return 0;
}
static int sd_init_12a(struct gspca_dev *gspca_dev)
{
PDEBUG(D_STREAM, "Chip revision: 012a");
init_161rev12A(gspca_dev);
return 0;
}
static int sd_init_72a(struct gspca_dev *gspca_dev)
{
PDEBUG(D_STREAM, "Chip revision: 072a");
write_vector(gspca_dev, rev72a_reset);
msleep(200);
write_vector(gspca_dev, rev72a_init_data1);
write_sensor_72a(gspca_dev, rev72a_init_sensor1);
write_vector(gspca_dev, rev72a_init_data2);
write_sensor_72a(gspca_dev, rev72a_init_sensor2);
reg_w_val(gspca_dev->dev, 0x8112, 0x30);
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
__u16 reg;
if (sd->chip_revision == Rev012A)
reg = 0x8610;
else
reg = 0x8611;
reg_w_val(dev, reg + 0, val);
reg_w_val(dev, reg + 1, val);
reg_w_val(dev, reg + 2, val);
reg_w_val(dev, reg + 3, val);
}
static void setwhite(struct gspca_dev *gspca_dev, s32 white, s32 contrast)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
__u8 blue, red;
__u16 reg;
red = 0x20 + white * 3 / 8;
blue = 0x90 - white * 5 / 8;
if (sd->chip_revision == Rev012A) {
reg = 0x8614;
} else {
reg = 0x8651;
red += contrast - 0x20;
blue += contrast - 0x20;
reg_w_val(dev, 0x8652, contrast + 0x20);
reg_w_val(dev, 0x8654, contrast + 0x20);
}
reg_w_val(dev, reg, red);
reg_w_val(dev, reg + 2, blue);
}
static void setexposure(struct gspca_dev *gspca_dev, s32 val)
{
int i, expo = 0;
int table[] = { 0, 450, 550, 625, EXPOSURE_MAX };
for (i = 0; i < ARRAY_SIZE(table) - 1; i++) {
if (val <= table[i + 1]) {
expo = val - table[i];
if (i)
expo += 300;
expo |= i << 11;
break;
}
}
gspca_dev->usb_buf[0] = expo;
gspca_dev->usb_buf[1] = expo >> 8;
reg_w_buf(gspca_dev, 0x8309, 2);
}
static void setgain(struct gspca_dev *gspca_dev, s32 val)
{
if (val < 64)
gspca_dev->usb_buf[0] = val;
else if (val < 128)
gspca_dev->usb_buf[0] = (val / 2) | 0x40;
else
gspca_dev->usb_buf[0] = (val / 4) | 0xc0;
gspca_dev->usb_buf[1] = 0;
reg_w_buf(gspca_dev, 0x8335, 2);
}
static void setautogain(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
if (val)
sd->ag_cnt = AG_CNT_START;
else
sd->ag_cnt = -1;
}
static int sd_start_12a(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
int mode;
static const __u8 Reg8391[8] =
{0x92, 0x30, 0x20, 0x00, 0x0c, 0x00, 0x00, 0x00};
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
if (mode <= 1) {
reg_w_val(dev, 0x8500, 0x10 | mode);
} else {
reg_w_val(dev, 0x8500, mode);
}
gspca_dev->usb_buf[0] = 0xaa;
gspca_dev->usb_buf[1] = 0x00;
reg_w_buf(gspca_dev, 0x8307, 2);
reg_w_val(gspca_dev->dev, 0x8700, 0x8a);
reg_w_val(gspca_dev->dev, 0x8112, 0x1e | 0x20);
reg_w_val(gspca_dev->dev, 0x850b, 0x03);
memcpy(gspca_dev->usb_buf, Reg8391, 8);
reg_w_buf(gspca_dev, 0x8391, 8);
reg_w_buf(gspca_dev, 0x8390, 8);
reg_w_val(gspca_dev->dev, 0x8114, 0x00);
return 0;
}
static int sd_start_72a(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
int Clck;
int mode;
write_vector(gspca_dev, rev72a_reset);
msleep(200);
write_vector(gspca_dev, rev72a_init_data1);
write_sensor_72a(gspca_dev, rev72a_init_sensor1);
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
switch (mode) {
default:
case 0:
Clck = 0x27;
break;
case 1:
Clck = 0x25;
break;
case 2:
Clck = 0x22;
break;
case 3:
Clck = 0x21;
break;
}
reg_w_val(dev, 0x8700, Clck);
reg_w_val(dev, 0x8702, 0x81);
reg_w_val(dev, 0x8500, mode);
write_sensor_72a(gspca_dev, rev72a_init_sensor2);
setwhite(gspca_dev, v4l2_ctrl_g_ctrl(sd->hue),
v4l2_ctrl_g_ctrl(sd->contrast));
setautogain(gspca_dev, v4l2_ctrl_g_ctrl(sd->autogain));
reg_w_val(dev, 0x8112, 0x10 | 0x20);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->chip_revision == Rev012A) {
reg_w_val(gspca_dev->dev, 0x8112, 0x0e);
reg_w_val(gspca_dev->dev, 0x8114, 0x08);
} else {
reg_w_val(gspca_dev->dev, 0x8112, 0x20);
}
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int expotimes;
int pixelclk;
int gainG;
__u8 R, Gr, Gb, B;
int y;
__u8 luma_mean = 110;
__u8 luma_delta = 20;
__u8 spring = 4;
if (sd->ag_cnt < 0)
return;
if (--sd->ag_cnt >= 0)
return;
sd->ag_cnt = AG_CNT_START;
switch (sd->chip_revision) {
case Rev072A:
reg_r(gspca_dev, 0x8621, 1);
Gr = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8622, 1);
R = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8623, 1);
B = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0x8624, 1);
Gb = gspca_dev->usb_buf[0];
y = (77 * R + 75 * (Gr + Gb) + 29 * B) >> 8;
if (y < luma_mean - luma_delta ||
y > luma_mean + luma_delta) {
expotimes = i2c_read(gspca_dev, 0x09, 0x10);
pixelclk = 0x0800;
expotimes = expotimes & 0x07ff;
gainG = i2c_read(gspca_dev, 0x35, 0x10);
expotimes += (luma_mean - y) >> spring;
gainG += (luma_mean - y) / 50;
if (gainG > 0x3f)
gainG = 0x3f;
else if (gainG < 3)
gainG = 3;
i2c_write(gspca_dev, gainG, 0x35);
if (expotimes > 0x0256)
expotimes = 0x0256;
else if (expotimes < 3)
expotimes = 3;
i2c_write(gspca_dev, expotimes | pixelclk, 0x09);
}
break;
}
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
len--;
switch (*data++) {
case 0:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
if (len < 2) {
PDEBUG(D_ERR, "Short SOF packet, ignoring");
gspca_dev->last_packet_type = DISCARD_PACKET;
return;
}
#if defined(CONFIG_INPUT) || defined(CONFIG_INPUT_MODULE)
if (data[0] & 0x20) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
}
#endif
if (data[1] & 0x10) {
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
} else {
if (sd->chip_revision == Rev012A) {
data += 20;
len -= 20;
} else {
data += 16;
len -= 16;
}
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
}
return;
case 0xff:
return;
}
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
setwhite(gspca_dev, sd->hue->val, ctrl->val);
break;
case V4L2_CID_HUE:
setwhite(gspca_dev, ctrl->val, 0);
break;
case V4L2_CID_EXPOSURE:
setexposure(gspca_dev, ctrl->val);
break;
case V4L2_CID_GAIN:
setgain(gspca_dev, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
setautogain(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls_12a(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 3);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, 1, 0x7f, 1, 0x40);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 1, EXPOSURE_MAX, 1, 700);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 63);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_init_controls_72a(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 4);
sd->contrast = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0x3f, 1, 0x20);
sd->hue = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, 1, 0x7f, 1, 0x40);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 0x3f, 1, 0x20);
sd->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_cluster(2, &sd->contrast);
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
sd_desc[id->driver_info],
sizeof(struct sd),
THIS_MODULE);
}
