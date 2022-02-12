static void reg_r(struct gspca_dev *gspca_dev,
u16 value, int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
if (len > USB_BUF_SZ) {
PERR("reg_r: buffer overflow\n");
return;
}
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, 0,
gspca_dev->usb_buf, len,
500);
PDEBUG(D_USBI, "reg_r [%02x] -> %02x", value, gspca_dev->usb_buf[0]);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w1(struct gspca_dev *gspca_dev,
u16 value,
u8 data)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "reg_w1 [%04x] = %02x", value, data);
gspca_dev->usb_buf[0] = data;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value,
0,
gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w1 err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
u16 value,
const u8 *buffer,
int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "reg_w [%04x] = %02x %02x ..",
value, buffer[0], buffer[1]);
if (len > USB_BUF_SZ) {
PERR("reg_w: buffer overflow\n");
return;
}
memcpy(gspca_dev->usb_buf, buffer, len);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, 0,
gspca_dev->usb_buf, len,
500);
if (ret < 0) {
pr_err("reg_w err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void i2c_w1(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "i2c_w1 [%02x] = %02x", reg, val);
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_OM6802:
case SENSOR_GC0307:
gspca_dev->usb_buf[0] = 0x80 | (2 << 4);
break;
default:
gspca_dev->usb_buf[0] = 0x81 | (2 << 4);
break;
}
gspca_dev->usb_buf[1] = sd->i2c_addr;
gspca_dev->usb_buf[2] = reg;
gspca_dev->usb_buf[3] = val;
gspca_dev->usb_buf[4] = 0;
gspca_dev->usb_buf[5] = 0;
gspca_dev->usb_buf[6] = 0;
gspca_dev->usb_buf[7] = 0x10;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x08,
0,
gspca_dev->usb_buf, 8,
500);
msleep(2);
if (ret < 0) {
pr_err("i2c_w1 err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void i2c_w8(struct gspca_dev *gspca_dev,
const u8 *buffer)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "i2c_w8 [%02x] = %02x ..",
buffer[2], buffer[3]);
memcpy(gspca_dev->usb_buf, buffer, 8);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x08, 0,
gspca_dev->usb_buf, 8,
500);
msleep(2);
if (ret < 0) {
pr_err("i2c_w8 err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void i2c_r(struct gspca_dev *gspca_dev, u8 reg, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 mode[8];
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_OM6802:
case SENSOR_GC0307:
mode[0] = 0x80 | 0x10;
break;
default:
mode[0] = 0x81 | 0x10;
break;
}
mode[1] = sd->i2c_addr;
mode[2] = reg;
mode[3] = 0;
mode[4] = 0;
mode[5] = 0;
mode[6] = 0;
mode[7] = 0x10;
i2c_w8(gspca_dev, mode);
msleep(2);
mode[0] = (mode[0] & 0x81) | (len << 4) | 0x02;
mode[2] = 0;
i2c_w8(gspca_dev, mode);
msleep(2);
reg_r(gspca_dev, 0x0a, 5);
}
static void hv7131r_probe(struct gspca_dev *gspca_dev)
{
i2c_w1(gspca_dev, 0x02, 0);
msleep(10);
reg_w1(gspca_dev, 0x02, 0x66);
msleep(10);
i2c_r(gspca_dev, 0, 5);
if (gspca_dev->usb_buf[0] == 0x02
&& gspca_dev->usb_buf[1] == 0x09
&& gspca_dev->usb_buf[2] == 0x01) {
PDEBUG(D_PROBE, "Sensor HV7131R found");
return;
}
pr_warn("Erroneous HV7131R ID 0x%02x 0x%02x 0x%02x\n",
gspca_dev->usb_buf[0], gspca_dev->usb_buf[1],
gspca_dev->usb_buf[2]);
}
static void mi0360_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, j;
u16 val = 0;
static const u8 probe_tb[][4][8] = {
{
{0xb0, 0x5d, 0x07, 0x00, 0x02, 0x00, 0x00, 0x10},
{0x90, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xa2, 0x5d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xb0, 0x5d, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10}
},
{
{0xb0, 0x5c, 0x01, 0x00, 0x04, 0x00, 0x00, 0x10},
{0x90, 0x5c, 0x36, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xa2, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10},
{}
},
};
for (i = 0; i < ARRAY_SIZE(probe_tb); i++) {
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x08);
for (j = 0; j < 3; j++)
i2c_w8(gspca_dev, probe_tb[i][j]);
msleep(2);
reg_r(gspca_dev, 0x0a, 5);
val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
if (probe_tb[i][3][0] != 0)
i2c_w8(gspca_dev, probe_tb[i][3]);
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if (val != 0xffff)
break;
}
if (gspca_dev->usb_err < 0)
return;
switch (val) {
case 0x8221:
PDEBUG(D_PROBE, "Sensor mi0360b");
sd->sensor = SENSOR_MI0360B;
break;
case 0x823a:
PDEBUG(D_PROBE, "Sensor mt9v111");
sd->sensor = SENSOR_MT9V111;
break;
case 0x8243:
PDEBUG(D_PROBE, "Sensor mi0360");
break;
default:
PDEBUG(D_PROBE, "Unknown sensor %04x - forced to mi0360", val);
break;
}
}
static void ov7630_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 val;
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x08);
sd->i2c_addr = 0x21;
i2c_r(gspca_dev, 0x0a, 2);
val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if (gspca_dev->usb_err < 0)
return;
if (val == 0x7628) {
sd->sensor = SENSOR_SOI768;
gspca_dev->cam.input_flags =
V4L2_IN_ST_VFLIP | V4L2_IN_ST_HFLIP;
PDEBUG(D_PROBE, "Sensor soi768");
return;
}
PDEBUG(D_PROBE, "Sensor ov%04x", val);
}
static void ov7648_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 val;
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x08);
sd->i2c_addr = 0x21;
i2c_r(gspca_dev, 0x0a, 2);
val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if ((val & 0xff00) == 0x7600) {
PDEBUG(D_PROBE, "Sensor ov%04x", val);
return;
}
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x08);
sd->i2c_addr = 0x6e;
i2c_r(gspca_dev, 0x00, 2);
val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if (gspca_dev->usb_err < 0)
return;
if (val == 0x1030) {
PDEBUG(D_PROBE, "Sensor po1030");
sd->sensor = SENSOR_PO1030;
return;
}
pr_err("Unknown sensor %04x\n", val);
}
static void po2030n_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 val;
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x08);
reg_w1(gspca_dev, 0x02, 0x22);
sd->i2c_addr = 0x21;
i2c_r(gspca_dev, 0x00, 1);
val = gspca_dev->usb_buf[4];
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if (val == 0x99) {
PDEBUG(D_PROBE, "Sensor gc0307");
sd->sensor = SENSOR_GC0307;
return;
}
reg_w1(gspca_dev, 0x17, 0x62);
reg_w1(gspca_dev, 0x01, 0x0a);
sd->i2c_addr = 0x6e;
i2c_r(gspca_dev, 0x00, 2);
val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
reg_w1(gspca_dev, 0x01, 0x29);
reg_w1(gspca_dev, 0x17, 0x42);
if (gspca_dev->usb_err < 0)
return;
if (val == 0x2030) {
PDEBUG(D_PROBE, "Sensor po2030n");
} else {
pr_err("Unknown sensor ID %04x\n", val);
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
sd->bridge = id->driver_info >> 16;
sd->sensor = id->driver_info >> 8;
sd->flags = id->driver_info;
cam = &gspca_dev->cam;
if (sd->sensor == SENSOR_ADCM1700) {
cam->cam_mode = cif_mode;
cam->nmodes = ARRAY_SIZE(cif_mode);
} else {
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
}
cam->npkt = 24;
sd->ag_cnt = -1;
sd->quality = QUALITY_DEF;
INIT_WORK(&sd->work, qual_upd);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const u8 *sn9c1xx;
u8 regGpio[] = { 0x29, 0x70 };
u8 regF1;
reg_w1(gspca_dev, 0xf1, 0x01);
reg_r(gspca_dev, 0x00, 1);
reg_w1(gspca_dev, 0xf1, 0x00);
reg_r(gspca_dev, 0x00, 1);
regF1 = gspca_dev->usb_buf[0];
if (gspca_dev->usb_err < 0)
return gspca_dev->usb_err;
PDEBUG(D_PROBE, "Sonix chip id: %02x", regF1);
if (gspca_dev->audio)
regGpio[1] |= 0x04;
switch (sd->bridge) {
case BRIDGE_SN9C102P:
case BRIDGE_SN9C105:
if (regF1 != 0x11)
return -ENODEV;
break;
default:
if (regF1 != 0x12)
return -ENODEV;
}
switch (sd->sensor) {
case SENSOR_MI0360:
mi0360_probe(gspca_dev);
break;
case SENSOR_OV7630:
ov7630_probe(gspca_dev);
break;
case SENSOR_OV7648:
ov7648_probe(gspca_dev);
break;
case SENSOR_PO2030N:
po2030n_probe(gspca_dev);
break;
}
switch (sd->bridge) {
case BRIDGE_SN9C102P:
reg_w1(gspca_dev, 0x02, regGpio[1]);
break;
default:
reg_w(gspca_dev, 0x01, regGpio, 2);
break;
}
reg_w1(gspca_dev, 0xf1, 0x00);
sn9c1xx = sn_tb[sd->sensor];
sd->i2c_addr = sn9c1xx[9];
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 14);
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
#define CONTRAST_MAX 127
sd->contrast = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, CONTRAST_MAX, 1, 20);
#define COLORS_DEF 25
sd->saturation = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 40, 1, COLORS_DEF);
sd->red_bal = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 24, 40, 1, 32);
sd->blue_bal = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 24, 40, 1, 32);
#define GAMMA_DEF 20
sd->gamma = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAMMA, 0, 40, 1, GAMMA_DEF);
if (sd->sensor == SENSOR_OM6802)
sd->sharpness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 255, 1, 16);
else
sd->sharpness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 255, 1, 90);
if (sd->flags & F_ILLUM)
sd->illum = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_ILLUMINATORS_1, 0, 1, 1, 0);
if (sd->sensor == SENSOR_PO2030N) {
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 500, 1500, 1, 1024);
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 4, 49, 1, 15);
sd->hflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
}
if (sd->sensor != SENSOR_ADCM1700 && sd->sensor != SENSOR_OV7660 &&
sd->sensor != SENSOR_PO1030 && sd->sensor != SENSOR_SOI768 &&
sd->sensor != SENSOR_SP80708)
gspca_dev->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
if (sd->sensor == SENSOR_HV7131R || sd->sensor == SENSOR_OV7630 ||
sd->sensor == SENSOR_OV7648 || sd->sensor == SENSOR_PO2030N)
sd->vflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
if (sd->sensor == SENSOR_OV7630 || sd->sensor == SENSOR_OV7648 ||
sd->sensor == SENSOR_OV7660)
sd->freq = v4l2_ctrl_new_std_menu(hdl, &sd_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 0,
V4L2_CID_POWER_LINE_FREQUENCY_50HZ);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_cluster(2, &sd->red_bal);
if (sd->sensor == SENSOR_PO2030N) {
v4l2_ctrl_cluster(2, &sd->vflip);
v4l2_ctrl_auto_cluster(3, &gspca_dev->autogain, 0, false);
}
return 0;
}
static u32 expo_adjust(struct gspca_dev *gspca_dev,
u32 expo)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_GC0307: {
int a, b;
a = 19 + expo * 25 / 256;
i2c_w1(gspca_dev, 0x68, a);
a -= 12;
b = a * a * 4;
i2c_w1(gspca_dev, 0x03, b >> 8);
i2c_w1(gspca_dev, 0x04, b);
break;
}
case SENSOR_HV7131R: {
u8 Expodoit[] =
{ 0xc1, 0x11, 0x25, 0x00, 0x00, 0x00, 0x00, 0x16 };
Expodoit[3] = expo >> 16;
Expodoit[4] = expo >> 8;
Expodoit[5] = expo;
i2c_w8(gspca_dev, Expodoit);
break;
}
case SENSOR_MI0360:
case SENSOR_MI0360B: {
u8 expoMi[] =
{ 0xb1, 0x5d, 0x09, 0x00, 0x00, 0x00, 0x00, 0x16 };
static const u8 doit[] =
{ 0xb1, 0x5d, 0x07, 0x00, 0x03, 0x00, 0x00, 0x10 };
static const u8 sensorgo[] =
{ 0xb1, 0x5d, 0x07, 0x00, 0x02, 0x00, 0x00, 0x10 };
if (expo > 0x0635)
expo = 0x0635;
else if (expo < 0x0001)
expo = 0x0001;
expoMi[3] = expo >> 8;
expoMi[4] = expo;
i2c_w8(gspca_dev, expoMi);
i2c_w8(gspca_dev, doit);
i2c_w8(gspca_dev, sensorgo);
break;
}
case SENSOR_MO4000: {
u8 expoMof[] =
{ 0xa1, 0x21, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x10 };
u8 expoMo10[] =
{ 0xa1, 0x21, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10 };
static const u8 gainMo[] =
{ 0xa1, 0x21, 0x00, 0x10, 0x00, 0x00, 0x00, 0x1d };
if (expo > 0x1fff)
expo = 0x1fff;
else if (expo < 0x0001)
expo = 0x0001;
expoMof[3] = (expo & 0x03fc) >> 2;
i2c_w8(gspca_dev, expoMof);
expoMo10[3] = ((expo & 0x1c00) >> 10)
| ((expo & 0x0003) << 4);
i2c_w8(gspca_dev, expoMo10);
i2c_w8(gspca_dev, gainMo);
PDEBUG(D_FRAM, "set exposure %d",
((expoMo10[3] & 0x07) << 10)
| (expoMof[3] << 2)
| ((expoMo10[3] & 0x30) >> 4));
break;
}
case SENSOR_MT9V111: {
u8 expo_c1[] =
{ 0xb1, 0x5c, 0x09, 0x00, 0x00, 0x00, 0x00, 0x10 };
if (expo > 0x0390)
expo = 0x0390;
else if (expo < 0x0060)
expo = 0x0060;
expo_c1[3] = expo >> 8;
expo_c1[4] = expo;
i2c_w8(gspca_dev, expo_c1);
break;
}
case SENSOR_OM6802: {
u8 gainOm[] =
{ 0xa0, 0x34, 0xe5, 0x00, 0x00, 0x00, 0x00, 0x10 };
if (expo > 0x03ff)
expo = 0x03ff;
if (expo < 0x0001)
expo = 0x0001;
gainOm[3] = expo >> 2;
i2c_w8(gspca_dev, gainOm);
reg_w1(gspca_dev, 0x96, expo >> 5);
PDEBUG(D_FRAM, "set exposure %d", gainOm[3]);
break;
}
}
return expo;
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned int expo;
int brightness = sd->brightness->val;
u8 k2;
k2 = (brightness - 0x80) >> 2;
switch (sd->sensor) {
case SENSOR_ADCM1700:
if (k2 > 0x1f)
k2 = 0;
break;
case SENSOR_HV7131R:
expo = brightness << 12;
if (expo > 0x002dc6c0)
expo = 0x002dc6c0;
else if (expo < 0x02a0)
expo = 0x02a0;
sd->exposure = expo_adjust(gspca_dev, expo);
break;
case SENSOR_MI0360:
case SENSOR_MO4000:
expo = brightness << 4;
sd->exposure = expo_adjust(gspca_dev, expo);
break;
case SENSOR_MI0360B:
expo = brightness << 2;
sd->exposure = expo_adjust(gspca_dev, expo);
break;
case SENSOR_GC0307:
expo = brightness;
sd->exposure = expo_adjust(gspca_dev, expo);
return;
case SENSOR_MT9V111:
expo = brightness << 2;
sd->exposure = expo_adjust(gspca_dev, expo);
return;
case SENSOR_OM6802:
expo = brightness << 2;
sd->exposure = expo_adjust(gspca_dev, expo);
return;
}
reg_w1(gspca_dev, 0x96, k2);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 k2;
u8 contrast[6];
k2 = sd->contrast->val * 37 / (CONTRAST_MAX + 1)
+ 37;
contrast[0] = (k2 + 1) / 2;
contrast[1] = 0;
contrast[2] = k2;
contrast[3] = 0;
contrast[4] = k2 / 5;
contrast[5] = 0;
reg_w(gspca_dev, 0x84, contrast, sizeof contrast);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, v, colors;
const s16 *uv;
u8 reg8a[12];
static const s16 uv_com[6] = {
-24, -38, 64,
62, -51, -9
};
static const s16 uv_mi0360b[6] = {
-20, -38, 64,
60, -51, -9
};
colors = sd->saturation->val;
if (sd->sensor == SENSOR_MI0360B)
uv = uv_mi0360b;
else
uv = uv_com;
for (i = 0; i < 6; i++) {
v = uv[i] * colors / COLORS_DEF;
reg8a[i * 2] = v;
reg8a[i * 2 + 1] = (v >> 8) & 0x0f;
}
reg_w(gspca_dev, 0x8a, reg8a, sizeof reg8a);
}
static void setredblue(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PO2030N) {
u8 rg1b[] =
{0xc1, 0x6e, 0x16, 0x00, 0x40, 0x00, 0x00, 0x10};
rg1b[3] = sd->red_bal->val * 2;
rg1b[5] = sd->blue_bal->val * 2;
i2c_w8(gspca_dev, rg1b);
return;
}
reg_w1(gspca_dev, 0x05, sd->red_bal->val);
reg_w1(gspca_dev, 0x06, sd->blue_bal->val);
}
static void setgamma(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, val;
u8 gamma[17];
const u8 *gamma_base;
static const u8 delta[17] = {
0x00, 0x14, 0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1a,
0x18, 0x13, 0x10, 0x0e, 0x08, 0x07, 0x04, 0x02, 0x00
};
switch (sd->sensor) {
case SENSOR_ADCM1700:
gamma_base = gamma_spec_0;
break;
case SENSOR_HV7131R:
case SENSOR_MI0360B:
case SENSOR_MT9V111:
gamma_base = gamma_spec_1;
break;
case SENSOR_GC0307:
gamma_base = gamma_spec_2;
break;
case SENSOR_SP80708:
gamma_base = gamma_spec_3;
break;
default:
gamma_base = gamma_def;
break;
}
val = sd->gamma->val;
for (i = 0; i < sizeof gamma; i++)
gamma[i] = gamma_base[i]
+ delta[i] * (val - GAMMA_DEF) / 32;
reg_w(gspca_dev, 0x20, gamma, sizeof gamma);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PO2030N) {
u8 rexpo[] =
{0xa1, 0x6e, 0x1a, 0x00, 0x40, 0x00, 0x00, 0x10};
rexpo[3] = gspca_dev->exposure->val >> 8;
i2c_w8(gspca_dev, rexpo);
msleep(6);
rexpo[2] = 0x1b;
rexpo[3] = gspca_dev->exposure->val;
i2c_w8(gspca_dev, rexpo);
}
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_OV7630:
case SENSOR_OV7648: {
u8 comb;
if (sd->sensor == SENSOR_OV7630)
comb = 0xc0;
else
comb = 0xa0;
if (gspca_dev->autogain->val)
comb |= 0x03;
i2c_w1(&sd->gspca_dev, 0x13, comb);
return;
}
}
if (gspca_dev->autogain->val)
sd->ag_cnt = AG_CNT_START;
else
sd->ag_cnt = -1;
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_PO2030N) {
u8 rgain[] =
{0xa1, 0x6e, 0x15, 0x00, 0x40, 0x00, 0x00, 0x15};
rgain[3] = gspca_dev->gain->val;
i2c_w8(gspca_dev, rgain);
}
}
static void sethvflip(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 comn;
switch (sd->sensor) {
case SENSOR_HV7131R:
comn = 0x18;
if (sd->vflip->val)
comn |= 0x01;
i2c_w1(gspca_dev, 0x01, comn);
break;
case SENSOR_OV7630:
comn = 0x02;
if (!sd->vflip->val)
comn |= 0x80;
i2c_w1(gspca_dev, 0x75, comn);
break;
case SENSOR_OV7648:
comn = 0x06;
if (sd->vflip->val)
comn |= 0x80;
i2c_w1(gspca_dev, 0x75, comn);
break;
case SENSOR_PO2030N:
comn = 0x0a;
if (sd->hflip->val)
comn |= 0x80;
if (sd->vflip->val)
comn |= 0x40;
i2c_w1(&sd->gspca_dev, 0x1e, comn);
break;
}
}
static void setsharpness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w1(gspca_dev, 0x99, sd->sharpness->val);
}
static void setillum(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_ADCM1700:
reg_w1(gspca_dev, 0x02,
sd->illum->val ? 0x64 : 0x60);
break;
case SENSOR_MT9V111:
reg_w1(gspca_dev, 0x02,
sd->illum->val ? 0x77 : 0x74);
break;
}
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_OV7660) {
u8 com8;
com8 = 0xdf;
switch (sd->freq->val) {
case 0:
i2c_w1(gspca_dev, 0x13, com8 | 0x20);
break;
case 1:
i2c_w1(gspca_dev, 0x13, com8);
i2c_w1(gspca_dev, 0x3b, 0x0a);
break;
case 2:
i2c_w1(gspca_dev, 0x13, com8);
i2c_w1(gspca_dev, 0x3b, 0x02);
break;
}
} else {
u8 reg2a = 0, reg2b = 0, reg2d = 0;
switch (sd->sensor) {
case SENSOR_OV7630:
reg2a = 0x08;
reg2d = 0x01;
break;
case SENSOR_OV7648:
reg2a = 0x11;
reg2d = 0x81;
break;
}
switch (sd->freq->val) {
case 0:
break;
case 1:
reg2a |= 0x80;
reg2b = 0xac;
reg2d |= 0x04;
break;
case 2:
reg2a |= 0x80;
reg2d |= 0x04;
break;
}
i2c_w1(gspca_dev, 0x2a, reg2a);
i2c_w1(gspca_dev, 0x2b, reg2b);
i2c_w1(gspca_dev, 0x2d, reg2d);
}
}
static void setjpegqual(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
#if USB_BUF_SZ < 64
#error "No room enough in usb_buf for quantization table"
#endif
memcpy(gspca_dev->usb_buf, &sd->jpeg_hdr[JPEG_QT0_OFFSET], 64);
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x0100, 0,
gspca_dev->usb_buf, 64,
500);
memcpy(gspca_dev->usb_buf, &sd->jpeg_hdr[JPEG_QT1_OFFSET], 64);
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x0140, 0,
gspca_dev->usb_buf, 64,
500);
sd->reg18 ^= 0x40;
reg_w1(gspca_dev, 0x18, sd->reg18);
}
static void qual_upd(struct work_struct *work)
{
struct sd *sd = container_of(work, struct sd, work);
struct gspca_dev *gspca_dev = &sd->gspca_dev;
mutex_lock(&gspca_dev->usb_lock);
PDEBUG(D_STREAM, "qual_upd %d%%", sd->quality);
gspca_dev->usb_err = 0;
setjpegqual(gspca_dev);
mutex_unlock(&gspca_dev->usb_lock);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
u8 reg01, reg17;
u8 reg0102[2];
const u8 *sn9c1xx;
const u8 (*init)[8];
const u8 *reg9a;
int mode;
static const u8 reg9a_def[] =
{0x00, 0x40, 0x20, 0x00, 0x00, 0x00};
static const u8 reg9a_spec[] =
{0x00, 0x40, 0x38, 0x30, 0x00, 0x20};
static const u8 regd4[] = {0x60, 0x00, 0x00};
static const u8 C0[] = { 0x2d, 0x2d, 0x3a, 0x05, 0x04, 0x3f };
static const u8 CA[] = { 0x28, 0xd8, 0x14, 0xec };
static const u8 CA_adcm1700[] =
{ 0x14, 0xec, 0x0a, 0xf6 };
static const u8 CA_po2030n[] =
{ 0x1e, 0xe2, 0x14, 0xec };
static const u8 CE[] = { 0x32, 0xdd, 0x2d, 0xdd };
static const u8 CE_gc0307[] =
{ 0x32, 0xce, 0x2d, 0xd3 };
static const u8 CE_ov76xx[] =
{ 0x32, 0xdd, 0x32, 0xdd };
static const u8 CE_po2030n[] =
{ 0x14, 0xe7, 0x1e, 0xdd };
jpeg_define(sd->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x21);
sn9c1xx = sn_tb[sd->sensor];
reg01 = sn9c1xx[1];
if (sd->flags & F_PDN_INV)
reg01 ^= S_PDN_INV;
reg_w1(gspca_dev, 0x01, reg01);
reg0102[0] = reg01;
reg0102[1] = sn9c1xx[2];
if (gspca_dev->audio)
reg0102[1] |= 0x04;
reg_w(gspca_dev, 0x01, reg0102, 2);
reg_w(gspca_dev, 0x08, &sn9c1xx[8], 2);
reg_w(gspca_dev, 0x17, &sn9c1xx[0x17], 5);
switch (sd->sensor) {
case SENSOR_GC0307:
case SENSOR_OV7660:
case SENSOR_PO1030:
case SENSOR_PO2030N:
case SENSOR_SOI768:
case SENSOR_SP80708:
reg9a = reg9a_spec;
break;
default:
reg9a = reg9a_def;
break;
}
reg_w(gspca_dev, 0x9a, reg9a, 6);
reg_w(gspca_dev, 0xd4, regd4, sizeof regd4);
reg_w(gspca_dev, 0x03, &sn9c1xx[3], 0x0f);
reg17 = sn9c1xx[0x17];
switch (sd->sensor) {
case SENSOR_GC0307:
msleep(50);
break;
case SENSOR_OM6802:
msleep(10);
reg_w1(gspca_dev, 0x02, 0x73);
reg17 |= SEN_CLK_EN;
reg_w1(gspca_dev, 0x17, reg17);
reg_w1(gspca_dev, 0x01, 0x22);
msleep(100);
reg01 = SCL_SEL_OD | S_PDN_INV;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x04;
break;
}
reg01 |= SYS_SEL_48M;
reg_w1(gspca_dev, 0x01, reg01);
reg17 |= SEN_CLK_EN;
reg_w1(gspca_dev, 0x17, reg17);
reg01 &= ~S_PWR_DN;
reg_w1(gspca_dev, 0x01, reg01);
reg01 &= ~SCL_SEL_OD;
reg_w1(gspca_dev, 0x01, reg01);
switch (sd->sensor) {
case SENSOR_HV7131R:
hv7131r_probe(gspca_dev);
break;
case SENSOR_OM6802:
msleep(10);
reg_w1(gspca_dev, 0x01, reg01);
i2c_w8(gspca_dev, om6802_init0[0]);
i2c_w8(gspca_dev, om6802_init0[1]);
msleep(15);
reg_w1(gspca_dev, 0x02, 0x71);
msleep(150);
break;
case SENSOR_SP80708:
msleep(100);
reg_w1(gspca_dev, 0x02, 0x62);
break;
}
i2c_w_seq(gspca_dev, sensor_init[sd->sensor]);
reg_w1(gspca_dev, 0x15, sn9c1xx[0x15]);
reg_w1(gspca_dev, 0x16, sn9c1xx[0x16]);
reg_w1(gspca_dev, 0x12, sn9c1xx[0x12]);
reg_w1(gspca_dev, 0x13, sn9c1xx[0x13]);
reg_w1(gspca_dev, 0x18, sn9c1xx[0x18]);
if (sd->sensor == SENSOR_ADCM1700) {
reg_w1(gspca_dev, 0xd2, 0x3a);
reg_w1(gspca_dev, 0xd3, 0x30);
} else {
reg_w1(gspca_dev, 0xd2, 0x6a);
reg_w1(gspca_dev, 0xd3, 0x50);
}
reg_w1(gspca_dev, 0xc6, 0x00);
reg_w1(gspca_dev, 0xc7, 0x00);
if (sd->sensor == SENSOR_ADCM1700) {
reg_w1(gspca_dev, 0xc8, 0x2c);
reg_w1(gspca_dev, 0xc9, 0x24);
} else {
reg_w1(gspca_dev, 0xc8, 0x50);
reg_w1(gspca_dev, 0xc9, 0x3c);
}
reg_w1(gspca_dev, 0x18, sn9c1xx[0x18]);
switch (sd->sensor) {
case SENSOR_OM6802:
break;
default:
reg17 |= DEF_EN;
break;
}
reg_w1(gspca_dev, 0x17, reg17);
reg_w1(gspca_dev, 0x05, 0x00);
reg_w1(gspca_dev, 0x07, 0x00);
reg_w1(gspca_dev, 0x06, 0x00);
reg_w1(gspca_dev, 0x14, sn9c1xx[0x14]);
setgamma(gspca_dev);
for (i = 0; i < 8; i++)
reg_w(gspca_dev, 0x84, reg84, sizeof reg84);
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_OV7660:
case SENSOR_SP80708:
reg_w1(gspca_dev, 0x9a, 0x05);
break;
case SENSOR_GC0307:
case SENSOR_MT9V111:
case SENSOR_MI0360B:
reg_w1(gspca_dev, 0x9a, 0x07);
break;
case SENSOR_OV7630:
case SENSOR_OV7648:
reg_w1(gspca_dev, 0x9a, 0x0a);
break;
case SENSOR_PO2030N:
case SENSOR_SOI768:
reg_w1(gspca_dev, 0x9a, 0x06);
break;
default:
reg_w1(gspca_dev, 0x9a, 0x08);
break;
}
setsharpness(gspca_dev);
reg_w(gspca_dev, 0x84, reg84, sizeof reg84);
reg_w1(gspca_dev, 0x05, 0x20);
reg_w1(gspca_dev, 0x07, 0x20);
reg_w1(gspca_dev, 0x06, 0x20);
init = NULL;
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
reg01 |= SYS_SEL_48M | V_TX_EN;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x02;
switch (sd->sensor) {
case SENSOR_ADCM1700:
init = adcm1700_sensor_param1;
break;
case SENSOR_GC0307:
init = gc0307_sensor_param1;
break;
case SENSOR_HV7131R:
case SENSOR_MI0360:
if (!mode)
reg01 &= ~SYS_SEL_48M;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x01;
break;
case SENSOR_MI0360B:
init = mi0360b_sensor_param1;
break;
case SENSOR_MO4000:
if (mode) {
reg01 &= ~SYS_SEL_48M;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x01;
}
break;
case SENSOR_MT9V111:
init = mt9v111_sensor_param1;
break;
case SENSOR_OM6802:
init = om6802_sensor_param1;
if (!mode) {
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x04;
} else {
reg01 &= ~SYS_SEL_48M;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x02;
}
break;
case SENSOR_OV7630:
init = ov7630_sensor_param1;
break;
case SENSOR_OV7648:
init = ov7648_sensor_param1;
reg17 &= ~MCK_SIZE_MASK;
reg17 |= 0x01;
break;
case SENSOR_OV7660:
init = ov7660_sensor_param1;
break;
case SENSOR_PO1030:
init = po1030_sensor_param1;
break;
case SENSOR_PO2030N:
init = po2030n_sensor_param1;
break;
case SENSOR_SOI768:
init = soi768_sensor_param1;
break;
case SENSOR_SP80708:
init = sp80708_sensor_param1;
break;
}
if (init != NULL) {
i2c_w_seq(gspca_dev, init);
}
reg_w(gspca_dev, 0xc0, C0, 6);
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_GC0307:
case SENSOR_SOI768:
reg_w(gspca_dev, 0xca, CA_adcm1700, 4);
break;
case SENSOR_PO2030N:
reg_w(gspca_dev, 0xca, CA_po2030n, 4);
break;
default:
reg_w(gspca_dev, 0xca, CA, 4);
break;
}
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_OV7630:
case SENSOR_OV7648:
case SENSOR_OV7660:
case SENSOR_SOI768:
reg_w(gspca_dev, 0xce, CE_ov76xx, 4);
break;
case SENSOR_GC0307:
reg_w(gspca_dev, 0xce, CE_gc0307, 4);
break;
case SENSOR_PO2030N:
reg_w(gspca_dev, 0xce, CE_po2030n, 4);
break;
default:
reg_w(gspca_dev, 0xce, CE, 4);
break;
}
sd->reg18 = sn9c1xx[0x18] | (mode << 4) | 0x40;
reg_w1(gspca_dev, 0x18, sd->reg18);
setjpegqual(gspca_dev);
reg_w1(gspca_dev, 0x17, reg17);
reg_w1(gspca_dev, 0x01, reg01);
sd->reg01 = reg01;
sd->reg17 = reg17;
sd->pktsz = sd->npkt = 0;
sd->nchg = sd->short_mark = 0;
sd->work_thread = create_singlethread_workqueue(MODULE_NAME);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
static const u8 stophv7131[] =
{ 0xa1, 0x11, 0x02, 0x09, 0x00, 0x00, 0x00, 0x10 };
static const u8 stopmi0360[] =
{ 0xb1, 0x5d, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10 };
static const u8 stopov7648[] =
{ 0xa1, 0x21, 0x76, 0x20, 0x00, 0x00, 0x00, 0x10 };
static const u8 stopsoi768[] =
{ 0xa1, 0x21, 0x12, 0x80, 0x00, 0x00, 0x00, 0x10 };
u8 reg01;
u8 reg17;
reg01 = sd->reg01;
reg17 = sd->reg17 & ~SEN_CLK_EN;
switch (sd->sensor) {
case SENSOR_ADCM1700:
case SENSOR_GC0307:
case SENSOR_PO2030N:
case SENSOR_SP80708:
reg01 |= LED;
reg_w1(gspca_dev, 0x01, reg01);
reg01 &= ~(LED | V_TX_EN);
reg_w1(gspca_dev, 0x01, reg01);
break;
case SENSOR_HV7131R:
reg01 &= ~V_TX_EN;
reg_w1(gspca_dev, 0x01, reg01);
i2c_w8(gspca_dev, stophv7131);
break;
case SENSOR_MI0360:
case SENSOR_MI0360B:
reg01 &= ~V_TX_EN;
reg_w1(gspca_dev, 0x01, reg01);
i2c_w8(gspca_dev, stopmi0360);
break;
case SENSOR_MT9V111:
case SENSOR_OM6802:
case SENSOR_PO1030:
reg01 &= ~V_TX_EN;
reg_w1(gspca_dev, 0x01, reg01);
break;
case SENSOR_OV7630:
case SENSOR_OV7648:
reg01 &= ~V_TX_EN;
reg_w1(gspca_dev, 0x01, reg01);
i2c_w8(gspca_dev, stopov7648);
break;
case SENSOR_OV7660:
reg01 &= ~V_TX_EN;
reg_w1(gspca_dev, 0x01, reg01);
break;
case SENSOR_SOI768:
i2c_w8(gspca_dev, stopsoi768);
break;
}
reg01 |= SCL_SEL_OD;
reg_w1(gspca_dev, 0x01, reg01);
reg01 |= S_PWR_DN;
reg_w1(gspca_dev, 0x01, reg01);
reg_w1(gspca_dev, 0x17, reg17);
reg01 &= ~SYS_SEL_48M;
reg_w1(gspca_dev, 0x01, reg01);
reg01 |= LED;
reg_w1(gspca_dev, 0x01, reg01);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->work_thread != NULL) {
mutex_unlock(&gspca_dev->usb_lock);
destroy_workqueue(sd->work_thread);
mutex_lock(&gspca_dev->usb_lock);
sd->work_thread = NULL;
}
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int delta;
int expotimes;
u8 luma_mean = 130;
u8 luma_delta = 20;
if (sd->ag_cnt < 0)
return;
if (--sd->ag_cnt >= 0)
return;
sd->ag_cnt = AG_CNT_START;
delta = atomic_read(&sd->avg_lum);
PDEBUG(D_FRAM, "mean lum %d", delta);
if (sd->sensor == SENSOR_PO2030N) {
gspca_expo_autogain(gspca_dev, delta, luma_mean, luma_delta,
15, 1024);
return;
}
if (delta < luma_mean - luma_delta ||
delta > luma_mean + luma_delta) {
switch (sd->sensor) {
case SENSOR_GC0307:
expotimes = sd->exposure;
expotimes += (luma_mean - delta) >> 6;
if (expotimes < 0)
expotimes = 0;
sd->exposure = expo_adjust(gspca_dev,
(unsigned int) expotimes);
break;
case SENSOR_HV7131R:
expotimes = sd->exposure >> 8;
expotimes += (luma_mean - delta) >> 4;
if (expotimes < 0)
expotimes = 0;
sd->exposure = expo_adjust(gspca_dev,
(unsigned int) (expotimes << 8));
break;
case SENSOR_OM6802:
case SENSOR_MT9V111:
expotimes = sd->exposure;
expotimes += (luma_mean - delta) >> 2;
if (expotimes < 0)
expotimes = 0;
sd->exposure = expo_adjust(gspca_dev,
(unsigned int) expotimes);
setredblue(gspca_dev);
break;
default:
expotimes = sd->exposure;
expotimes += (luma_mean - delta) >> 6;
if (expotimes < 0)
expotimes = 0;
sd->exposure = expo_adjust(gspca_dev,
(unsigned int) expotimes);
setredblue(gspca_dev);
break;
}
}
}
static void set_lum(struct sd *sd,
u8 *data)
{
int avg_lum;
avg_lum = (data[27] << 8) + data[28]
+ (data[31] << 8) + data[32]
+ (data[23] << 8) + data[24]
+ (data[35] << 8) + data[36]
+ (data[29] << 10) + (data[30] << 2);
avg_lum >>= 10;
atomic_set(&sd->avg_lum, avg_lum);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, new_qual;
sd->npkt++;
sd->pktsz += len;
i = sd->short_mark;
if (i != 0) {
sd->short_mark = 0;
if (i < 0
&& data[0] == 0xff
&& data[1] == 0x00)
goto marker_found;
if (data[0] == 0xff && data[1] == 0xff) {
i = 0;
goto marker_found;
}
len -= i;
if (len <= 0)
return;
data += i;
}
for (i = len - 1; --i >= 0; ) {
if (data[i] != 0xff) {
i--;
continue;
}
if (data[i + 1] == 0xff) {
if (i + 2 >= len || data[i + 2] == 0x00)
goto marker_found;
}
}
if (data[len - 1] == 0xff)
sd->short_mark = -1;
if (gspca_dev->last_packet_type == LAST_PACKET)
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
return;
marker_found:
new_qual = 0;
if (i > 2) {
if (data[i - 2] != 0xff || data[i - 1] != 0xd9) {
gspca_dev->last_packet_type = DISCARD_PACKET;
new_qual = -3;
}
} else if (i + 6 < len) {
if (data[i + 6] & 0x08) {
gspca_dev->last_packet_type = DISCARD_PACKET;
new_qual = -5;
}
}
gspca_frame_add(gspca_dev, LAST_PACKET, data, i);
if (new_qual == 0) {
int r;
r = (sd->pktsz * 100) /
(sd->npkt *
gspca_dev->urb[0]->iso_frame_desc[0].length);
if (r >= 85)
new_qual = -3;
else if (r < 75)
new_qual = 2;
}
if (new_qual != 0) {
sd->nchg += new_qual;
if (sd->nchg < -6 || sd->nchg >= 12) {
sd->nchg = 0;
new_qual += sd->quality;
if (new_qual < QUALITY_MIN)
new_qual = QUALITY_MIN;
else if (new_qual > QUALITY_MAX)
new_qual = QUALITY_MAX;
if (new_qual != sd->quality) {
sd->quality = new_qual;
queue_work(sd->work_thread, &sd->work);
}
}
} else {
sd->nchg = 0;
}
sd->pktsz = sd->npkt = 0;
if (i + 62 > len) {
sd->short_mark = i + 62 - len;
return;
}
if (sd->ag_cnt >= 0)
set_lum(sd, data + i);
i += 62;
if (i < len) {
data += i;
len -= i;
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
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
setbrightness(gspca_dev);
break;
case V4L2_CID_CONTRAST:
setcontrast(gspca_dev);
break;
case V4L2_CID_SATURATION:
setcolors(gspca_dev);
break;
case V4L2_CID_RED_BALANCE:
setredblue(gspca_dev);
break;
case V4L2_CID_GAMMA:
setgamma(gspca_dev);
break;
case V4L2_CID_AUTOGAIN:
setautogain(gspca_dev);
setexposure(gspca_dev);
setgain(gspca_dev);
break;
case V4L2_CID_VFLIP:
sethvflip(gspca_dev);
break;
case V4L2_CID_SHARPNESS:
setsharpness(gspca_dev);
break;
case V4L2_CID_ILLUMINATORS_1:
setillum(gspca_dev);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
setfreq(gspca_dev);
break;
default:
return -EINVAL;
}
return gspca_dev->usb_err;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
if (len == 1 && data[0] == 1) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
return ret;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
