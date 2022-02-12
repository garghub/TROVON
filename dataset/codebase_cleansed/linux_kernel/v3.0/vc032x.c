static void reg_r_i(struct gspca_dev *gspca_dev,
u16 req,
u16 index,
u16 len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
1,
index, gspca_dev->usb_buf, len,
500);
if (ret < 0) {
err("reg_r err %d", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_r(struct gspca_dev *gspca_dev,
u16 req,
u16 index,
u16 len)
{
reg_r_i(gspca_dev, req, index, len);
#ifdef GSPCA_DEBUG
if (gspca_dev->usb_err < 0)
return;
if (len == 1)
PDEBUG(D_USBI, "GET %02x 0001 %04x %02x", req, index,
gspca_dev->usb_buf[0]);
else
PDEBUG(D_USBI, "GET %02x 0001 %04x %02x %02x %02x",
req, index,
gspca_dev->usb_buf[0],
gspca_dev->usb_buf[1],
gspca_dev->usb_buf[2]);
#endif
}
static void reg_w_i(struct gspca_dev *gspca_dev,
u16 req,
u16 value,
u16 index)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0,
500);
if (ret < 0) {
err("reg_w err %d", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
u16 req,
u16 value,
u16 index)
{
#ifdef GSPCA_DEBUG
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "SET %02x %04x %04x", req, value, index);
#endif
reg_w_i(gspca_dev, req, value, index);
}
static u16 read_sensor_register(struct gspca_dev *gspca_dev,
u16 address)
{
u8 ldata, mdata, hdata;
int retry = 50;
reg_r(gspca_dev, 0xa1, 0xb33f, 1);
if (!(gspca_dev->usb_buf[0] & 0x02)) {
err("I2c Bus Busy Wait %02x",
gspca_dev->usb_buf[0]);
return 0;
}
reg_w(gspca_dev, 0xa0, address, 0xb33a);
reg_w(gspca_dev, 0xa0, 0x02, 0xb339);
do {
reg_r(gspca_dev, 0xa1, 0xb33b, 1);
if (gspca_dev->usb_buf[0] == 0x00)
break;
msleep(40);
} while (--retry >= 0);
reg_r(gspca_dev, 0xa1, 0xb33e, 1);
ldata = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0xa1, 0xb33d, 1);
mdata = gspca_dev->usb_buf[0];
reg_r(gspca_dev, 0xa1, 0xb33c, 1);
hdata = gspca_dev->usb_buf[0];
if (hdata != 0 && mdata != 0 && ldata != 0)
PDEBUG(D_PROBE, "Read Sensor %02x%02x %02x",
hdata, mdata, ldata);
reg_r(gspca_dev, 0xa1, 0xb334, 1);
if (gspca_dev->usb_buf[0] == 0x02)
return (hdata << 8) + mdata;
return hdata;
}
static int vc032x_probe_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, n;
u16 value;
const struct sensor_info *ptsensor_info;
if (sd->flags & FL_SAMSUNG) {
reg_w(gspca_dev, 0xa0, 0x01, 0xb301);
reg_w(gspca_dev, 0x89, 0xf0ff, 0xffff);
}
reg_r(gspca_dev, 0xa1, 0xbfcf, 1);
PDEBUG(D_PROBE, "vc032%d check sensor header %02x",
sd->bridge == BRIDGE_VC0321 ? 1 : 3, gspca_dev->usb_buf[0]);
if (sd->bridge == BRIDGE_VC0321) {
ptsensor_info = vc0321_probe_data;
n = ARRAY_SIZE(vc0321_probe_data);
} else {
ptsensor_info = vc0323_probe_data;
n = ARRAY_SIZE(vc0323_probe_data);
}
for (i = 0; i < n; i++) {
reg_w(gspca_dev, 0xa0, 0x02, 0xb334);
reg_w(gspca_dev, 0xa0, ptsensor_info->m1, 0xb300);
reg_w(gspca_dev, 0xa0, ptsensor_info->m2, 0xb300);
reg_w(gspca_dev, 0xa0, 0x01, 0xb308);
reg_w(gspca_dev, 0xa0, 0x0c, 0xb309);
reg_w(gspca_dev, 0xa0, ptsensor_info->I2cAdd, 0xb335);
reg_w(gspca_dev, 0xa0, ptsensor_info->op, 0xb301);
value = read_sensor_register(gspca_dev, ptsensor_info->IdAdd);
if (value == 0 && ptsensor_info->IdAdd == 0x82)
value = read_sensor_register(gspca_dev, 0x83);
if (value != 0) {
PDEBUG(D_ERR|D_PROBE, "Sensor ID %04x (%d)",
value, i);
if (value == ptsensor_info->VpId)
return ptsensor_info->sensorId;
switch (value) {
case 0x3130:
return SENSOR_PO3130NC;
case 0x7673:
return SENSOR_OV7670;
case 0x8243:
return SENSOR_MI0360;
}
}
ptsensor_info++;
}
return -1;
}
static void i2c_write(struct gspca_dev *gspca_dev,
u8 reg, const u8 *val,
u8 size)
{
int retry;
#ifdef GSPCA_DEBUG
if (gspca_dev->usb_err < 0)
return;
if (size == 1)
PDEBUG(D_USBO, "i2c_w %02x %02x", reg, *val);
else
PDEBUG(D_USBO, "i2c_w %02x %02x%02x", reg, *val, val[1]);
#endif
reg_r_i(gspca_dev, 0xa1, 0xb33f, 1);
reg_w_i(gspca_dev, 0xa0, size, 0xb334);
reg_w_i(gspca_dev, 0xa0, reg, 0xb33a);
reg_w_i(gspca_dev, 0xa0, val[0], 0xb336);
if (size > 1)
reg_w_i(gspca_dev, 0xa0, val[1], 0xb337);
reg_w_i(gspca_dev, 0xa0, 0x01, 0xb339);
retry = 4;
do {
reg_r_i(gspca_dev, 0xa1, 0xb33b, 1);
if (gspca_dev->usb_buf[0] == 0)
break;
msleep(20);
} while (--retry > 0);
if (retry <= 0)
err("i2c_write timeout");
}
static void put_tab_to_reg(struct gspca_dev *gspca_dev,
const u8 *tab, u8 tabsize, u16 addr)
{
int j;
u16 ad = addr;
for (j = 0; j < tabsize; j++)
reg_w(gspca_dev, 0xa0, tab[j], ad++);
}
static void usb_exchange(struct gspca_dev *gspca_dev,
const u8 data[][4])
{
int i = 0;
for (;;) {
switch (data[i][3]) {
default:
return;
case 0xcc:
reg_w(gspca_dev, 0xa0, data[i][2],
(data[i][0]) << 8 | data[i][1]);
break;
case 0xaa:
i2c_write(gspca_dev, data[i][1], &data[i][2], 1);
break;
case 0xbb:
i2c_write(gspca_dev, data[i][0], &data[i][1], 2);
break;
case 0xdd:
msleep(data[i][1] * 256 + data[i][2] + 10);
break;
}
i++;
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->bridge = id->driver_info >> 8;
sd->flags = id->driver_info & 0xff;
if (id->idVendor == 0x046d &&
(id->idProduct == 0x0892 || id->idProduct == 0x0896))
sd->sensor = SENSOR_POxxxx;
sd->brightness = BRIGHTNESS_DEF;
sd->contrast = CONTRAST_DEF;
sd->colors = COLOR_DEF;
sd->hflip = HFLIP_DEF;
sd->vflip = VFLIP_DEF;
sd->lightfreq = FREQ_DEF;
sd->sharpness = SHARPNESS_DEF;
sd->gain = GAIN_DEF;
sd->exposure = EXPOSURE_DEF;
sd->autogain = AUTOGAIN_DEF;
sd->backlight = BACKLIGHT_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
int sensor;
static u8 npkt[NSENSORS] = {
[SENSOR_HV7131R] = 64,
[SENSOR_MI0360] = 32,
[SENSOR_MI1310_SOC] = 32,
[SENSOR_MI1320] = 64,
[SENSOR_MI1320_SOC] = 128,
[SENSOR_OV7660] = 32,
[SENSOR_OV7670] = 64,
[SENSOR_PO1200] = 128,
[SENSOR_PO3130NC] = 128,
[SENSOR_POxxxx] = 128,
};
if (sd->sensor != SENSOR_POxxxx)
sensor = vc032x_probe_sensor(gspca_dev);
else
sensor = sd->sensor;
switch (sensor) {
case -1:
err("Unknown sensor...");
return -EINVAL;
case SENSOR_HV7131R:
PDEBUG(D_PROBE, "Find Sensor HV7131R");
break;
case SENSOR_MI0360:
PDEBUG(D_PROBE, "Find Sensor MI0360");
sd->bridge = BRIDGE_VC0323;
break;
case SENSOR_MI1310_SOC:
PDEBUG(D_PROBE, "Find Sensor MI1310_SOC");
break;
case SENSOR_MI1320:
PDEBUG(D_PROBE, "Find Sensor MI1320");
break;
case SENSOR_MI1320_SOC:
PDEBUG(D_PROBE, "Find Sensor MI1320_SOC");
break;
case SENSOR_OV7660:
PDEBUG(D_PROBE, "Find Sensor OV7660");
break;
case SENSOR_OV7670:
PDEBUG(D_PROBE, "Find Sensor OV7670");
break;
case SENSOR_PO1200:
PDEBUG(D_PROBE, "Find Sensor PO1200");
break;
case SENSOR_PO3130NC:
PDEBUG(D_PROBE, "Find Sensor PO3130NC");
break;
case SENSOR_POxxxx:
PDEBUG(D_PROBE, "Sensor POxxxx");
break;
}
sd->sensor = sensor;
cam = &gspca_dev->cam;
if (sd->bridge == BRIDGE_VC0321) {
cam->cam_mode = vc0321_mode;
cam->nmodes = ARRAY_SIZE(vc0321_mode);
} else {
switch (sensor) {
case SENSOR_PO1200:
cam->cam_mode = svga_mode;
cam->nmodes = ARRAY_SIZE(svga_mode);
break;
case SENSOR_MI1310_SOC:
cam->cam_mode = vc0323_mode;
cam->nmodes = ARRAY_SIZE(vc0323_mode);
break;
case SENSOR_MI1320_SOC:
cam->cam_mode = bi_mode;
cam->nmodes = ARRAY_SIZE(bi_mode);
break;
case SENSOR_OV7670:
cam->cam_mode = bi_mode;
cam->nmodes = ARRAY_SIZE(bi_mode) - 1;
break;
default:
cam->cam_mode = vc0323_mode;
cam->nmodes = ARRAY_SIZE(vc0323_mode) - 1;
break;
}
}
cam->npkt = npkt[sd->sensor];
gspca_dev->ctrl_dis = ctrl_dis[sd->sensor];
if (sd->sensor == SENSOR_OV7670)
sd->flags |= FL_HFLIP | FL_VFLIP;
if (sd->bridge == BRIDGE_VC0321) {
reg_r(gspca_dev, 0x8a, 0, 3);
reg_w(gspca_dev, 0x87, 0x00, 0x0f0f);
reg_r(gspca_dev, 0x8b, 0, 3);
reg_w(gspca_dev, 0x88, 0x00, 0x0202);
if (sd->sensor == SENSOR_POxxxx) {
reg_r(gspca_dev, 0xa1, 0xb300, 1);
if (gspca_dev->usb_buf[0] != 0) {
reg_w(gspca_dev, 0xa0, 0x26, 0xb300);
reg_w(gspca_dev, 0xa0, 0x04, 0xb300);
}
reg_w(gspca_dev, 0xa0, 0x00, 0xb300);
}
}
return gspca_dev->usb_err;
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data;
if (gspca_dev->ctrl_dis & (1 << BRIGHTNESS_IDX))
return;
data = sd->brightness;
if (data >= 0x80)
data &= 0x7f;
else
data = 0xff ^ data;
i2c_write(gspca_dev, 0x98, &data, 1);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (gspca_dev->ctrl_dis & (1 << CONTRAST_IDX))
return;
i2c_write(gspca_dev, 0x99, &sd->contrast, 1);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data;
if (gspca_dev->ctrl_dis & (1 << COLORS_IDX))
return;
data = sd->colors - (sd->colors >> 3) - 1;
i2c_write(gspca_dev, 0x94, &data, 1);
i2c_write(gspca_dev, 0x95, &sd->colors, 1);
}
static void sethvflip(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data[2], hflip, vflip;
hflip = sd->hflip;
if (sd->flags & FL_HFLIP)
hflip = !hflip;
vflip = sd->vflip;
if (sd->flags & FL_VFLIP)
vflip = !vflip;
switch (sd->sensor) {
case SENSOR_MI1310_SOC:
case SENSOR_MI1320:
case SENSOR_MI1320_SOC:
data[0] = data[1] = 0;
i2c_write(gspca_dev, 0xf0, data, 2);
data[0] = sd->sensor == SENSOR_MI1310_SOC ? 0x03 : 0x01;
data[1] = 0x02 * hflip
| 0x01 * vflip;
i2c_write(gspca_dev, 0x20, data, 2);
break;
case SENSOR_OV7660:
case SENSOR_OV7670:
data[0] = sd->sensor == SENSOR_OV7660 ? 0x01 : 0x07;
data[0] |= OV7660_MVFP_MIRROR * hflip
| OV7660_MVFP_VFLIP * vflip;
i2c_write(gspca_dev, OV7660_REG_MVFP, data, 1);
break;
case SENSOR_PO1200:
data[0] = 0;
i2c_write(gspca_dev, 0x03, data, 1);
data[0] = 0x80 * hflip
| 0x40 * vflip
| 0x06;
i2c_write(gspca_dev, 0x1e, data, 1);
break;
}
}
static void setlightfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
static const u8 (*ov7660_freq_tb[3])[4] =
{ov7660_NoFliker, ov7660_50HZ, ov7660_60HZ};
if (sd->sensor != SENSOR_OV7660)
return;
usb_exchange(gspca_dev, ov7660_freq_tb[sd->lightfreq]);
}
static void setsharpness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data;
switch (sd->sensor) {
case SENSOR_PO1200:
data = 0;
i2c_write(gspca_dev, 0x03, &data, 1);
if (sd->sharpness < 0)
data = 0x6a;
else
data = 0xb5 + sd->sharpness * 3;
i2c_write(gspca_dev, 0x61, &data, 1);
break;
case SENSOR_POxxxx:
if (sd->sharpness < 0)
data = 0x7e;
else
data = 0x60 + sd->sharpness * 0x0f;
i2c_write(gspca_dev, 0x59, &data, 1);
break;
}
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (gspca_dev->ctrl_dis & (1 << GAIN_IDX))
return;
i2c_write(gspca_dev, 0x15, &sd->gain, 1);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 data;
if (gspca_dev->ctrl_dis & (1 << EXPOSURE_IDX))
return;
data = sd->exposure >> 8;
i2c_write(gspca_dev, 0x1a, &data, 1);
data = sd->exposure;
i2c_write(gspca_dev, 0x1b, &data, 1);
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
static const u8 data[2] = {0x28, 0x3c};
if (gspca_dev->ctrl_dis & (1 << AUTOGAIN_IDX))
return;
i2c_write(gspca_dev, 0xd1, &data[sd->autogain], 1);
}
static void setgamma(struct gspca_dev *gspca_dev)
{
usb_exchange(gspca_dev, poxxxx_gamma);
}
static void setbacklight(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 v;
u8 data;
data = (sd->backlight << 4) | 0x0f;
i2c_write(gspca_dev, 0xaa, &data, 1);
v = 613 + 12 * sd->backlight;
data = v >> 8;
i2c_write(gspca_dev, 0xc4, &data, 1);
data = v;
i2c_write(gspca_dev, 0xc5, &data, 1);
v = 1093 - 12 * sd->backlight;
data = v >> 8;
i2c_write(gspca_dev, 0xc6, &data, 1);
data = v;
i2c_write(gspca_dev, 0xc7, &data, 1);
v = 342 + 9 * sd->backlight;
data = v >> 8;
i2c_write(gspca_dev, 0xc8, &data, 1);
data = v;
i2c_write(gspca_dev, 0xc9, &data, 1);
v = 702 - 9 * sd->backlight;
data = v >> 8;
i2c_write(gspca_dev, 0xca, &data, 1);
data = v;
i2c_write(gspca_dev, 0xcb, &data, 1);
}
static void setwb(struct gspca_dev *gspca_dev)
{
static const u8 data[2] = {0x00, 0x00};
i2c_write(gspca_dev, 0x16, &data[0], 1);
i2c_write(gspca_dev, 0x18, &data[1], 1);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const u8 (*init)[4];
const u8 *GammaT = NULL;
const u8 *MatrixT = NULL;
int mode;
static const u8 (*mi1320_soc_init[])[4] = {
mi1320_soc_InitSXGA,
mi1320_soc_InitVGA,
mi1320_soc_InitQVGA,
};
if (sd->flags & FL_SAMSUNG) {
reg_w(gspca_dev, 0x89, 0xf0ff, 0xffff);
reg_w(gspca_dev, 0xa9, 0x8348, 0x000e);
reg_w(gspca_dev, 0xa9, 0x0000, 0x001a);
}
if (sd->bridge == BRIDGE_VC0321) {
reg_w(gspca_dev, 0xa0, 0xff, 0xbfec);
reg_w(gspca_dev, 0xa0, 0xff, 0xbfed);
reg_w(gspca_dev, 0xa0, 0xff, 0xbfee);
reg_w(gspca_dev, 0xa0, 0xff, 0xbfef);
sd->image_offset = 46;
} else {
if (gspca_dev->cam.cam_mode[gspca_dev->curr_mode].pixelformat
== V4L2_PIX_FMT_JPEG)
sd->image_offset = 0;
else
sd->image_offset = 32;
}
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
switch (sd->sensor) {
case SENSOR_HV7131R:
GammaT = hv7131r_gamma;
MatrixT = hv7131r_matrix;
if (mode)
init = hv7131r_initQVGA_data;
else
init = hv7131r_initVGA_data;
break;
case SENSOR_OV7660:
GammaT = ov7660_gamma;
MatrixT = ov7660_matrix;
if (mode)
init = ov7660_initQVGA_data;
else
init = ov7660_initVGA_data;
break;
case SENSOR_MI0360:
GammaT = mi1320_gamma;
MatrixT = mi0360_matrix;
if (mode)
init = mi0360_initQVGA_JPG;
else
init = mi0360_initVGA_JPG;
break;
case SENSOR_MI1310_SOC:
GammaT = mi1320_gamma;
MatrixT = mi1320_matrix;
switch (mode) {
case 1:
init = mi1310_socinitQVGA_JPG;
break;
case 0:
init = mi1310_socinitVGA_JPG;
break;
default:
init = mi1310_soc_InitSXGA_JPG;
break;
}
break;
case SENSOR_MI1320:
GammaT = mi1320_gamma;
MatrixT = mi1320_matrix;
if (mode)
init = mi1320_initQVGA_data;
else
init = mi1320_initVGA_data;
break;
case SENSOR_MI1320_SOC:
GammaT = mi1320_gamma;
MatrixT = mi1320_matrix;
init = mi1320_soc_init[mode];
break;
case SENSOR_OV7670:
init = mode == 1 ? ov7670_InitVGA : ov7670_InitQVGA;
break;
case SENSOR_PO3130NC:
GammaT = po3130_gamma;
MatrixT = po3130_matrix;
if (mode)
init = po3130_initQVGA_data;
else
init = po3130_initVGA_data;
usb_exchange(gspca_dev, init);
init = po3130_rundata;
break;
case SENSOR_PO1200:
GammaT = po1200_gamma;
MatrixT = po1200_matrix;
init = po1200_initVGA_data;
break;
default:
usb_exchange(gspca_dev, poxxxx_init_common);
setgamma(gspca_dev);
setbacklight(gspca_dev);
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setcolors(gspca_dev);
setsharpness(gspca_dev);
setautogain(gspca_dev);
setexposure(gspca_dev);
setgain(gspca_dev);
usb_exchange(gspca_dev, poxxxx_init_start_3);
if (mode)
init = poxxxx_initQVGA;
else
init = poxxxx_initVGA;
usb_exchange(gspca_dev, init);
reg_r(gspca_dev, 0x8c, 0x0000, 3);
reg_w(gspca_dev, 0xa0,
gspca_dev->usb_buf[2] & 1 ? 0 : 1,
0xb35c);
msleep(300);
init = poxxxx_init_end_1;
break;
}
usb_exchange(gspca_dev, init);
if (GammaT && MatrixT) {
put_tab_to_reg(gspca_dev, GammaT, 17, 0xb84a);
put_tab_to_reg(gspca_dev, GammaT, 17, 0xb85b);
put_tab_to_reg(gspca_dev, GammaT, 17, 0xb86c);
put_tab_to_reg(gspca_dev, MatrixT, 9, 0xb82c);
switch (sd->sensor) {
case SENSOR_PO1200:
case SENSOR_HV7131R:
reg_w(gspca_dev, 0x89, 0x0400, 0x1415);
break;
case SENSOR_MI1310_SOC:
reg_w(gspca_dev, 0x89, 0x058c, 0x0000);
break;
}
msleep(100);
sethvflip(gspca_dev);
setlightfreq(gspca_dev);
}
switch (sd->sensor) {
case SENSOR_OV7670:
reg_w(gspca_dev, 0x87, 0xffff, 0xffff);
reg_w(gspca_dev, 0x88, 0xff00, 0xf0f1);
reg_w(gspca_dev, 0xa0, 0x0000, 0xbfff);
break;
case SENSOR_POxxxx:
usb_exchange(gspca_dev, poxxxx_init_end_2);
setwb(gspca_dev);
msleep(80);
reg_w(gspca_dev, 0x89, 0xffff, 0xfdff);
break;
}
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->sensor) {
case SENSOR_MI1310_SOC:
reg_w(gspca_dev, 0x89, 0x058c, 0x00ff);
break;
case SENSOR_POxxxx:
return;
default:
if (!(sd->flags & FL_SAMSUNG))
reg_w(gspca_dev, 0x89, 0xffff, 0xffff);
break;
}
reg_w(gspca_dev, 0xa0, 0x01, 0xb301);
reg_w(gspca_dev, 0xa0, 0x09, 0xb003);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!gspca_dev->present)
return;
if (sd->sensor == SENSOR_MI1310_SOC)
reg_w(gspca_dev, 0x89, 0x058c, 0x00ff);
else if (!(sd->flags & FL_SAMSUNG))
reg_w(gspca_dev, 0x89, 0xffff, 0xffff);
if (sd->sensor == SENSOR_POxxxx) {
reg_w(gspca_dev, 0xa0, 0x26, 0xb300);
reg_w(gspca_dev, 0xa0, 0x04, 0xb300);
reg_w(gspca_dev, 0xa0, 0x00, 0xb300);
}
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (data[0] == 0xff && data[1] == 0xd8) {
PDEBUG(D_PACK,
"vc032x header packet found len %d", len);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
data += sd->image_offset;
len -= sd->image_offset;
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
return;
}
if (sd->bridge == BRIDGE_VC0321) {
int size, l;
l = gspca_dev->image_len;
size = gspca_dev->frsz;
if (len > size - l)
len = size - l;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_setbrightness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->brightness = val;
if (gspca_dev->streaming)
setbrightness(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getbrightness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->brightness;
return 0;
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
setcontrast(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return 0;
}
static int sd_setcolors(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->colors = val;
if (gspca_dev->streaming)
setcolors(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getcolors(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->colors;
return 0;
}
static int sd_sethflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->hflip = val;
if (gspca_dev->streaming)
sethvflip(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_gethflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->hflip;
return 0;
}
static int sd_setvflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vflip = val;
if (gspca_dev->streaming)
sethvflip(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getvflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->vflip;
return 0;
}
static int sd_setfreq(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->lightfreq = val;
if (gspca_dev->streaming)
setlightfreq(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getfreq(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->lightfreq;
return 0;
}
static int sd_setsharpness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->sharpness = val;
if (gspca_dev->streaming)
setsharpness(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getsharpness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->sharpness;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
setgain(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setexposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->autogain = val;
if (gspca_dev->streaming)
setautogain(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getautogain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->autogain;
return 0;
}
static int sd_setbacklight(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->backlight = val;
if (gspca_dev->streaming)
setbacklight(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getbacklight(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->backlight;
return 0;
}
static int sd_querymenu(struct gspca_dev *gspca_dev,
struct v4l2_querymenu *menu)
{
static const char *freq_nm[3] = {"NoFliker", "50 Hz", "60 Hz"};
switch (menu->id) {
case V4L2_CID_POWER_LINE_FREQUENCY:
if (menu->index >= ARRAY_SIZE(freq_nm))
break;
strcpy((char *) menu->name, freq_nm[menu->index]);
return 0;
}
return -EINVAL;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
static int __init sd_mod_init(void)
{
return usb_register(&sd_driver);
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
