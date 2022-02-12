static int reg_r(struct gspca_dev *gspca_dev, u16 reg, u16 length)
{
struct usb_device *dev = gspca_dev->dev;
int result;
result = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
reg,
0x00,
gspca_dev->usb_buf,
length,
500);
if (unlikely(result < 0 || result != length)) {
err("Read register failed 0x%02X", reg);
return -EIO;
}
return 0;
}
static int reg_w(struct gspca_dev *gspca_dev, u16 reg,
const u8 *buffer, int length)
{
struct usb_device *dev = gspca_dev->dev;
int result;
memcpy(gspca_dev->usb_buf, buffer, length);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x08,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
reg,
0x00,
gspca_dev->usb_buf,
length,
500);
if (unlikely(result < 0 || result != length)) {
err("Write register failed index 0x%02X", reg);
return -EIO;
}
return 0;
}
static int reg_w1(struct gspca_dev *gspca_dev, u16 reg, const u8 value)
{
u8 data[1] = {value};
return reg_w(gspca_dev, reg, data, 1);
}
static int i2c_w(struct gspca_dev *gspca_dev, const u8 *buffer)
{
int i;
reg_w(gspca_dev, 0x10c0, buffer, 8);
for (i = 0; i < 5; i++) {
reg_r(gspca_dev, 0x10c0, 1);
if (gspca_dev->usb_buf[0] & 0x04) {
if (gspca_dev->usb_buf[0] & 0x08)
return -EIO;
return 0;
}
msleep(1);
}
return -EIO;
}
static int i2c_w1(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = 0x81 | (2 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = val;
row[4] = 0x00;
row[5] = 0x00;
row[6] = 0x00;
row[7] = 0x10;
return i2c_w(gspca_dev, row);
}
static int i2c_w2(struct gspca_dev *gspca_dev, u8 reg, u16 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = 0x81 | (3 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = (val >> 8) & 0xff;
row[4] = val & 0xff;
row[5] = 0x00;
row[6] = 0x00;
row[7] = 0x10;
return i2c_w(gspca_dev, row);
}
static int i2c_r1(struct gspca_dev *gspca_dev, u8 reg, u8 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = 0x81 | (1 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = 0;
row[4] = 0;
row[5] = 0;
row[6] = 0;
row[7] = 0x10;
if (i2c_w(gspca_dev, row) < 0)
return -EIO;
row[0] = 0x81 | (1 << 4) | 0x02;
row[2] = 0;
if (i2c_w(gspca_dev, row) < 0)
return -EIO;
if (reg_r(gspca_dev, 0x10c2, 5) < 0)
return -EIO;
*val = gspca_dev->usb_buf[4];
return 0;
}
static int i2c_r2(struct gspca_dev *gspca_dev, u8 reg, u16 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = 0x81 | (1 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = 0;
row[4] = 0;
row[5] = 0;
row[6] = 0;
row[7] = 0x10;
if (i2c_w(gspca_dev, row) < 0)
return -EIO;
row[0] = 0x81 | (2 << 4) | 0x02;
row[2] = 0;
if (i2c_w(gspca_dev, row) < 0)
return -EIO;
if (reg_r(gspca_dev, 0x10c2, 5) < 0)
return -EIO;
*val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
return 0;
}
static int ov9650_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
u16 id;
struct sd *sd = (struct sd *) gspca_dev;
if (i2c_r2(gspca_dev, 0x1c, &id) < 0)
return -EINVAL;
if (id != 0x7fa2) {
err("sensor id for ov9650 doesn't match (0x%04x)", id);
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(ov9650_init); i++) {
if (i2c_w1(gspca_dev, ov9650_init[i].reg,
ov9650_init[i].val) < 0) {
err("OV9650 sensor initialization failed");
return -ENODEV;
}
}
sd->hstart = 1;
sd->vstart = 7;
return 0;
}
static int ov9655_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
struct sd *sd = (struct sd *) gspca_dev;
for (i = 0; i < ARRAY_SIZE(ov9655_init); i++) {
if (i2c_w1(gspca_dev, ov9655_init[i].reg,
ov9655_init[i].val) < 0) {
err("OV9655 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << HFLIP_IDX) | (1 << VFLIP_IDX);
sd->hstart = 1;
sd->vstart = 2;
return 0;
}
static int soi968_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
struct sd *sd = (struct sd *) gspca_dev;
for (i = 0; i < ARRAY_SIZE(soi968_init); i++) {
if (i2c_w1(gspca_dev, soi968_init[i].reg,
soi968_init[i].val) < 0) {
err("SOI968 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << HFLIP_IDX) | (1 << VFLIP_IDX)
| (1 << EXPOSURE_IDX);
sd->hstart = 60;
sd->vstart = 11;
return 0;
}
static int ov7660_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
struct sd *sd = (struct sd *) gspca_dev;
for (i = 0; i < ARRAY_SIZE(ov7660_init); i++) {
if (i2c_w1(gspca_dev, ov7660_init[i].reg,
ov7660_init[i].val) < 0) {
err("OV7660 sensor initialization failed");
return -ENODEV;
}
}
sd->hstart = 3;
sd->vstart = 3;
return 0;
}
static int ov7670_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
struct sd *sd = (struct sd *) gspca_dev;
for (i = 0; i < ARRAY_SIZE(ov7670_init); i++) {
if (i2c_w1(gspca_dev, ov7670_init[i].reg,
ov7670_init[i].val) < 0) {
err("OV7670 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << HFLIP_IDX) | (1 << VFLIP_IDX);
sd->hstart = 0;
sd->vstart = 1;
return 0;
}
static int mt9v_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
u16 value;
int ret;
sd->i2c_addr = 0x5d;
ret = i2c_r2(gspca_dev, 0xff, &value);
if ((ret == 0) && (value == 0x8243)) {
for (i = 0; i < ARRAY_SIZE(mt9v011_init); i++) {
if (i2c_w2(gspca_dev, mt9v011_init[i].reg,
mt9v011_init[i].val) < 0) {
err("MT9V011 sensor initialization failed");
return -ENODEV;
}
}
sd->hstart = 2;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V011;
info("MT9V011 sensor detected");
return 0;
}
sd->i2c_addr = 0x5c;
i2c_w2(gspca_dev, 0x01, 0x0004);
ret = i2c_r2(gspca_dev, 0xff, &value);
if ((ret == 0) && (value == 0x823a)) {
for (i = 0; i < ARRAY_SIZE(mt9v111_init); i++) {
if (i2c_w2(gspca_dev, mt9v111_init[i].reg,
mt9v111_init[i].val) < 0) {
err("MT9V111 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << EXPOSURE_IDX)
| (1 << AUTOGAIN_IDX)
| (1 << GAIN_IDX);
sd->hstart = 2;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V111;
info("MT9V111 sensor detected");
return 0;
}
sd->i2c_addr = 0x5d;
ret = i2c_w2(gspca_dev, 0xf0, 0x0000);
if (ret < 0) {
sd->i2c_addr = 0x48;
i2c_w2(gspca_dev, 0xf0, 0x0000);
}
ret = i2c_r2(gspca_dev, 0x00, &value);
if ((ret == 0) && (value == 0x1229)) {
for (i = 0; i < ARRAY_SIZE(mt9v112_init); i++) {
if (i2c_w2(gspca_dev, mt9v112_init[i].reg,
mt9v112_init[i].val) < 0) {
err("MT9V112 sensor initialization failed");
return -ENODEV;
}
}
sd->hstart = 6;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V112;
info("MT9V112 sensor detected");
return 0;
}
return -ENODEV;
}
static int mt9m112_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
for (i = 0; i < ARRAY_SIZE(mt9m112_init); i++) {
if (i2c_w2(gspca_dev, mt9m112_init[i].reg,
mt9m112_init[i].val) < 0) {
err("MT9M112 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << EXPOSURE_IDX) | (1 << AUTOGAIN_IDX)
| (1 << GAIN_IDX);
sd->hstart = 0;
sd->vstart = 2;
return 0;
}
static int mt9m111_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
for (i = 0; i < ARRAY_SIZE(mt9m111_init); i++) {
if (i2c_w2(gspca_dev, mt9m111_init[i].reg,
mt9m111_init[i].val) < 0) {
err("MT9M111 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << EXPOSURE_IDX) | (1 << AUTOGAIN_IDX)
| (1 << GAIN_IDX);
sd->hstart = 0;
sd->vstart = 2;
return 0;
}
static int mt9m001_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
u16 id;
if (i2c_r2(gspca_dev, 0x00, &id) < 0)
return -EINVAL;
switch (id) {
case 0x8411:
case 0x8421:
info("MT9M001 color sensor detected");
break;
case 0x8431:
info("MT9M001 mono sensor detected");
break;
default:
err("No MT9M001 chip detected, ID = %x\n", id);
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(mt9m001_init); i++) {
if (i2c_w2(gspca_dev, mt9m001_init[i].reg,
mt9m001_init[i].val) < 0) {
err("MT9M001 sensor initialization failed");
return -ENODEV;
}
}
gspca_dev->ctrl_dis = (1 << HFLIP_IDX) | (1 << VFLIP_IDX);
sd->hstart = 1;
sd->vstart = 1;
return 0;
}
static int hv7131r_init_sensor(struct gspca_dev *gspca_dev)
{
int i;
struct sd *sd = (struct sd *) gspca_dev;
for (i = 0; i < ARRAY_SIZE(hv7131r_init); i++) {
if (i2c_w1(gspca_dev, hv7131r_init[i].reg,
hv7131r_init[i].val) < 0) {
err("HV7131R Sensor initialization failed");
return -ENODEV;
}
}
sd->hstart = 0;
sd->vstart = 1;
return 0;
}
static int set_cmatrix(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 hue_coord, hue_index = 180 + sd->hue;
u8 cmatrix[21];
memset(cmatrix, 0, sizeof cmatrix);
cmatrix[2] = (sd->contrast * 0x25 / 0x100) + 0x26;
cmatrix[0] = 0x13 + (cmatrix[2] - 0x26) * 0x13 / 0x25;
cmatrix[4] = 0x07 + (cmatrix[2] - 0x26) * 0x07 / 0x25;
cmatrix[18] = sd->brightness - 0x80;
hue_coord = (hsv_red_x[hue_index] * sd->saturation) >> 8;
cmatrix[6] = hue_coord;
cmatrix[7] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_red_y[hue_index] * sd->saturation) >> 8;
cmatrix[8] = hue_coord;
cmatrix[9] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_green_x[hue_index] * sd->saturation) >> 8;
cmatrix[10] = hue_coord;
cmatrix[11] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_green_y[hue_index] * sd->saturation) >> 8;
cmatrix[12] = hue_coord;
cmatrix[13] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_blue_x[hue_index] * sd->saturation) >> 8;
cmatrix[14] = hue_coord;
cmatrix[15] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_blue_y[hue_index] * sd->saturation) >> 8;
cmatrix[16] = hue_coord;
cmatrix[17] = (hue_coord >> 8) & 0x0f;
return reg_w(gspca_dev, 0x10e1, cmatrix, 21);
}
static int set_gamma(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gamma[17];
u8 gval = sd->gamma * 0xb8 / 0x100;
gamma[0] = 0x0a;
gamma[1] = 0x13 + (gval * (0xcb - 0x13) / 0xb8);
gamma[2] = 0x25 + (gval * (0xee - 0x25) / 0xb8);
gamma[3] = 0x37 + (gval * (0xfa - 0x37) / 0xb8);
gamma[4] = 0x45 + (gval * (0xfc - 0x45) / 0xb8);
gamma[5] = 0x55 + (gval * (0xfb - 0x55) / 0xb8);
gamma[6] = 0x65 + (gval * (0xfc - 0x65) / 0xb8);
gamma[7] = 0x74 + (gval * (0xfd - 0x74) / 0xb8);
gamma[8] = 0x83 + (gval * (0xfe - 0x83) / 0xb8);
gamma[9] = 0x92 + (gval * (0xfc - 0x92) / 0xb8);
gamma[10] = 0xa1 + (gval * (0xfc - 0xa1) / 0xb8);
gamma[11] = 0xb0 + (gval * (0xfc - 0xb0) / 0xb8);
gamma[12] = 0xbf + (gval * (0xfb - 0xbf) / 0xb8);
gamma[13] = 0xce + (gval * (0xfb - 0xce) / 0xb8);
gamma[14] = 0xdf + (gval * (0xfd - 0xdf) / 0xb8);
gamma[15] = 0xea + (gval * (0xf9 - 0xea) / 0xb8);
gamma[16] = 0xf5;
return reg_w(gspca_dev, 0x1190, gamma, 17);
}
static int set_redblue(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w1(gspca_dev, 0x118c, sd->red);
reg_w1(gspca_dev, 0x118f, sd->blue);
return 0;
}
static int set_hvflip(struct gspca_dev *gspca_dev)
{
u8 value, tslb, hflip, vflip;
u16 value2;
struct sd *sd = (struct sd *) gspca_dev;
if ((sd->flags & FLIP_DETECT) && dmi_check_system(flip_dmi_table)) {
hflip = !sd->hflip;
vflip = !sd->vflip;
} else {
hflip = sd->hflip;
vflip = sd->vflip;
}
switch (sd->sensor) {
case SENSOR_OV7660:
value = 0x01;
if (hflip)
value |= 0x20;
if (vflip) {
value |= 0x10;
sd->vstart = 2;
} else
sd->vstart = 3;
reg_w1(gspca_dev, 0x1182, sd->vstart);
i2c_w1(gspca_dev, 0x1e, value);
break;
case SENSOR_OV9650:
i2c_r1(gspca_dev, 0x1e, &value);
value &= ~0x30;
tslb = 0x01;
if (hflip)
value |= 0x20;
if (vflip) {
value |= 0x10;
tslb = 0x49;
}
i2c_w1(gspca_dev, 0x1e, value);
i2c_w1(gspca_dev, 0x3a, tslb);
break;
case SENSOR_MT9V111:
case SENSOR_MT9V011:
i2c_r2(gspca_dev, 0x20, &value2);
value2 &= ~0xc0a0;
if (hflip)
value2 |= 0x8080;
if (vflip)
value2 |= 0x4020;
i2c_w2(gspca_dev, 0x20, value2);
break;
case SENSOR_MT9M112:
case SENSOR_MT9M111:
case SENSOR_MT9V112:
i2c_r2(gspca_dev, 0x20, &value2);
value2 &= ~0x0003;
if (hflip)
value2 |= 0x0002;
if (vflip)
value2 |= 0x0001;
i2c_w2(gspca_dev, 0x20, value2);
break;
case SENSOR_HV7131R:
i2c_r1(gspca_dev, 0x01, &value);
value &= ~0x03;
if (vflip)
value |= 0x01;
if (hflip)
value |= 0x02;
i2c_w1(gspca_dev, 0x01, value);
break;
}
return 0;
}
static int set_exposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 exp[8] = {0x81, sd->i2c_addr, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e};
switch (sd->sensor) {
case SENSOR_OV7660:
case SENSOR_OV7670:
case SENSOR_OV9655:
case SENSOR_OV9650:
exp[0] |= (3 << 4);
exp[2] = 0x2d;
exp[3] = sd->exposure & 0xff;
exp[4] = sd->exposure >> 8;
break;
case SENSOR_MT9M001:
case SENSOR_MT9V112:
case SENSOR_MT9V011:
exp[0] |= (3 << 4);
exp[2] = 0x09;
exp[3] = sd->exposure >> 8;
exp[4] = sd->exposure & 0xff;
break;
case SENSOR_HV7131R:
exp[0] |= (4 << 4);
exp[2] = 0x25;
exp[3] = (sd->exposure >> 5) & 0xff;
exp[4] = (sd->exposure << 3) & 0xff;
exp[5] = 0;
break;
default:
return 0;
}
i2c_w(gspca_dev, exp);
return 0;
}
static int set_gain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gain[8] = {0x81, sd->i2c_addr, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d};
switch (sd->sensor) {
case SENSOR_OV7660:
case SENSOR_OV7670:
case SENSOR_SOI968:
case SENSOR_OV9655:
case SENSOR_OV9650:
gain[0] |= (2 << 4);
gain[3] = ov_gain[sd->gain];
break;
case SENSOR_MT9V011:
gain[0] |= (3 << 4);
gain[2] = 0x35;
gain[3] = micron1_gain[sd->gain] >> 8;
gain[4] = micron1_gain[sd->gain] & 0xff;
break;
case SENSOR_MT9V112:
gain[0] |= (3 << 4);
gain[2] = 0x2f;
gain[3] = micron1_gain[sd->gain] >> 8;
gain[4] = micron1_gain[sd->gain] & 0xff;
break;
case SENSOR_MT9M001:
gain[0] |= (3 << 4);
gain[2] = 0x2f;
gain[3] = micron2_gain[sd->gain] >> 8;
gain[4] = micron2_gain[sd->gain] & 0xff;
break;
case SENSOR_HV7131R:
gain[0] |= (2 << 4);
gain[2] = 0x30;
gain[3] = hv7131r_gain[sd->gain];
break;
default:
return 0;
}
i2c_w(gspca_dev, gain);
return 0;
}
static int sd_setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->brightness = val;
if (gspca_dev->streaming)
return set_cmatrix(gspca_dev);
return 0;
}
static int sd_getbrightness(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->brightness;
return 0;
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
return set_cmatrix(gspca_dev);
return 0;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return 0;
}
static int sd_setsaturation(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->saturation = val;
if (gspca_dev->streaming)
return set_cmatrix(gspca_dev);
return 0;
}
static int sd_getsaturation(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->saturation;
return 0;
}
static int sd_sethue(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->hue = val;
if (gspca_dev->streaming)
return set_cmatrix(gspca_dev);
return 0;
}
static int sd_gethue(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->hue;
return 0;
}
static int sd_setgamma(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gamma = val;
if (gspca_dev->streaming)
return set_gamma(gspca_dev);
return 0;
}
static int sd_getgamma(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gamma;
return 0;
}
static int sd_setredbalance(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->red = val;
if (gspca_dev->streaming)
return set_redblue(gspca_dev);
return 0;
}
static int sd_getredbalance(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->red;
return 0;
}
static int sd_setbluebalance(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->blue = val;
if (gspca_dev->streaming)
return set_redblue(gspca_dev);
return 0;
}
static int sd_getbluebalance(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->blue;
return 0;
}
static int sd_sethflip(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->hflip = val;
if (gspca_dev->streaming)
return set_hvflip(gspca_dev);
return 0;
}
static int sd_gethflip(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->hflip;
return 0;
}
static int sd_setvflip(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vflip = val;
if (gspca_dev->streaming)
return set_hvflip(gspca_dev);
return 0;
}
static int sd_getvflip(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->vflip;
return 0;
}
static int sd_setexposure(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
return set_exposure(gspca_dev);
return 0;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
return set_gain(gspca_dev);
return 0;
}
static int sd_getgain(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setautoexposure(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->auto_exposure = val;
return 0;
}
static int sd_getautoexposure(struct gspca_dev *gspca_dev, s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->auto_exposure;
return 0;
}
static int sd_dbg_g_register(struct gspca_dev *gspca_dev,
struct v4l2_dbg_register *reg)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_HOST:
if (reg->match.addr != 0)
return -EINVAL;
if (reg->reg < 0x1000 || reg->reg > 0x11ff)
return -EINVAL;
if (reg_r(gspca_dev, reg->reg, 1) < 0)
return -EINVAL;
reg->val = gspca_dev->usb_buf[0];
return 0;
case V4L2_CHIP_MATCH_I2C_ADDR:
if (reg->match.addr != sd->i2c_addr)
return -EINVAL;
if (sd->sensor >= SENSOR_MT9V011 &&
sd->sensor <= SENSOR_MT9M112) {
if (i2c_r2(gspca_dev, reg->reg, (u16 *)&reg->val) < 0)
return -EINVAL;
} else {
if (i2c_r1(gspca_dev, reg->reg, (u8 *)&reg->val) < 0)
return -EINVAL;
}
return 0;
}
return -EINVAL;
}
static int sd_dbg_s_register(struct gspca_dev *gspca_dev,
struct v4l2_dbg_register *reg)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_HOST:
if (reg->match.addr != 0)
return -EINVAL;
if (reg->reg < 0x1000 || reg->reg > 0x11ff)
return -EINVAL;
if (reg_w1(gspca_dev, reg->reg, reg->val) < 0)
return -EINVAL;
return 0;
case V4L2_CHIP_MATCH_I2C_ADDR:
if (reg->match.addr != sd->i2c_addr)
return -EINVAL;
if (sd->sensor >= SENSOR_MT9V011 &&
sd->sensor <= SENSOR_MT9M112) {
if (i2c_w2(gspca_dev, reg->reg, reg->val) < 0)
return -EINVAL;
} else {
if (i2c_w1(gspca_dev, reg->reg, reg->val) < 0)
return -EINVAL;
}
return 0;
}
return -EINVAL;
}
static int sd_chip_ident(struct gspca_dev *gspca_dev,
struct v4l2_dbg_chip_ident *chip)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (chip->match.type) {
case V4L2_CHIP_MATCH_HOST:
if (chip->match.addr != 0)
return -EINVAL;
chip->revision = 0;
chip->ident = V4L2_IDENT_SN9C20X;
return 0;
case V4L2_CHIP_MATCH_I2C_ADDR:
if (chip->match.addr != sd->i2c_addr)
return -EINVAL;
chip->revision = 0;
chip->ident = i2c_ident[sd->sensor];
return 0;
}
return -EINVAL;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
sd->sensor = (id->driver_info >> 8) & 0xff;
sd->i2c_addr = id->driver_info & 0xff;
sd->flags = (id->driver_info >> 16) & 0xff;
switch (sd->sensor) {
case SENSOR_MT9M112:
case SENSOR_MT9M111:
case SENSOR_OV9650:
case SENSOR_SOI968:
cam->cam_mode = sxga_mode;
cam->nmodes = ARRAY_SIZE(sxga_mode);
break;
case SENSOR_MT9M001:
cam->cam_mode = mono_mode;
cam->nmodes = ARRAY_SIZE(mono_mode);
break;
default:
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
break;
}
sd->old_step = 0;
sd->older_step = 0;
sd->exposure_step = 16;
sd->brightness = BRIGHTNESS_DEFAULT;
sd->contrast = CONTRAST_DEFAULT;
sd->saturation = SATURATION_DEFAULT;
sd->hue = HUE_DEFAULT;
sd->gamma = GAMMA_DEFAULT;
sd->red = RED_DEFAULT;
sd->blue = BLUE_DEFAULT;
sd->hflip = HFLIP_DEFAULT;
sd->vflip = VFLIP_DEFAULT;
sd->exposure = EXPOSURE_DEFAULT;
sd->gain = GAIN_DEFAULT;
sd->auto_exposure = AUTO_EXPOSURE_DEFAULT;
sd->quality = 95;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
u8 value;
u8 i2c_init[9] =
{0x80, sd->i2c_addr, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03};
for (i = 0; i < ARRAY_SIZE(bridge_init); i++) {
value = bridge_init[i][1];
if (reg_w(gspca_dev, bridge_init[i][0], &value, 1) < 0) {
err("Device initialization failed");
return -ENODEV;
}
}
if (sd->flags & LED_REVERSE)
reg_w1(gspca_dev, 0x1006, 0x00);
else
reg_w1(gspca_dev, 0x1006, 0x20);
if (reg_w(gspca_dev, 0x10c0, i2c_init, 9) < 0) {
err("Device initialization failed");
return -ENODEV;
}
switch (sd->sensor) {
case SENSOR_OV9650:
if (ov9650_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("OV9650 sensor detected");
break;
case SENSOR_OV9655:
if (ov9655_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("OV9655 sensor detected");
break;
case SENSOR_SOI968:
if (soi968_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("SOI968 sensor detected");
break;
case SENSOR_OV7660:
if (ov7660_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("OV7660 sensor detected");
break;
case SENSOR_OV7670:
if (ov7670_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("OV7670 sensor detected");
break;
case SENSOR_MT9VPRB:
if (mt9v_init_sensor(gspca_dev) < 0)
return -ENODEV;
break;
case SENSOR_MT9M111:
if (mt9m111_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("MT9M111 sensor detected");
break;
case SENSOR_MT9M112:
if (mt9m112_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("MT9M112 sensor detected");
break;
case SENSOR_MT9M001:
if (mt9m001_init_sensor(gspca_dev) < 0)
return -ENODEV;
break;
case SENSOR_HV7131R:
if (hv7131r_init_sensor(gspca_dev) < 0)
return -ENODEV;
info("HV7131R sensor detected");
break;
default:
info("Unsupported Sensor");
return -ENODEV;
}
return 0;
}
static void configure_sensor_output(struct gspca_dev *gspca_dev, int mode)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 value;
switch (sd->sensor) {
case SENSOR_SOI968:
if (mode & MODE_SXGA) {
i2c_w1(gspca_dev, 0x17, 0x1d);
i2c_w1(gspca_dev, 0x18, 0xbd);
i2c_w1(gspca_dev, 0x19, 0x01);
i2c_w1(gspca_dev, 0x1a, 0x81);
i2c_w1(gspca_dev, 0x12, 0x00);
sd->hstart = 140;
sd->vstart = 19;
} else {
i2c_w1(gspca_dev, 0x17, 0x13);
i2c_w1(gspca_dev, 0x18, 0x63);
i2c_w1(gspca_dev, 0x19, 0x01);
i2c_w1(gspca_dev, 0x1a, 0x79);
i2c_w1(gspca_dev, 0x12, 0x40);
sd->hstart = 60;
sd->vstart = 11;
}
break;
case SENSOR_OV9650:
if (mode & MODE_SXGA) {
i2c_w1(gspca_dev, 0x17, 0x1b);
i2c_w1(gspca_dev, 0x18, 0xbc);
i2c_w1(gspca_dev, 0x19, 0x01);
i2c_w1(gspca_dev, 0x1a, 0x82);
i2c_r1(gspca_dev, 0x12, &value);
i2c_w1(gspca_dev, 0x12, value & 0x07);
} else {
i2c_w1(gspca_dev, 0x17, 0x24);
i2c_w1(gspca_dev, 0x18, 0xc5);
i2c_w1(gspca_dev, 0x19, 0x00);
i2c_w1(gspca_dev, 0x1a, 0x3c);
i2c_r1(gspca_dev, 0x12, &value);
i2c_w1(gspca_dev, 0x12, (value & 0x7) | 0x40);
}
break;
case SENSOR_MT9M112:
case SENSOR_MT9M111:
if (mode & MODE_SXGA) {
i2c_w2(gspca_dev, 0xf0, 0x0002);
i2c_w2(gspca_dev, 0xc8, 0x970b);
i2c_w2(gspca_dev, 0xf0, 0x0000);
} else {
i2c_w2(gspca_dev, 0xf0, 0x0002);
i2c_w2(gspca_dev, 0xc8, 0x8000);
i2c_w2(gspca_dev, 0xf0, 0x0000);
}
break;
}
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
int width = gspca_dev->width;
int height = gspca_dev->height;
u8 fmt, scale = 0;
jpeg_define(sd->jpeg_hdr, height, width,
0x21);
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
if (mode & MODE_RAW)
fmt = 0x2d;
else if (mode & MODE_JPEG)
fmt = 0x2c;
else
fmt = 0x2f;
switch (mode & SCALE_MASK) {
case SCALE_1280x1024:
scale = 0xc0;
info("Set 1280x1024");
break;
case SCALE_640x480:
scale = 0x80;
info("Set 640x480");
break;
case SCALE_320x240:
scale = 0x90;
info("Set 320x240");
break;
case SCALE_160x120:
scale = 0xa0;
info("Set 160x120");
break;
}
configure_sensor_output(gspca_dev, mode);
reg_w(gspca_dev, 0x1100, &sd->jpeg_hdr[JPEG_QT0_OFFSET], 64);
reg_w(gspca_dev, 0x1140, &sd->jpeg_hdr[JPEG_QT1_OFFSET], 64);
reg_w(gspca_dev, 0x10fb, CLR_WIN(width, height), 5);
reg_w(gspca_dev, 0x1180, HW_WIN(mode, sd->hstart, sd->vstart), 6);
reg_w1(gspca_dev, 0x1189, scale);
reg_w1(gspca_dev, 0x10e0, fmt);
set_cmatrix(gspca_dev);
set_gamma(gspca_dev);
set_redblue(gspca_dev);
set_gain(gspca_dev);
set_exposure(gspca_dev);
set_hvflip(gspca_dev);
reg_w1(gspca_dev, 0x1007, 0x20);
reg_r(gspca_dev, 0x1061, 1);
reg_w1(gspca_dev, 0x1061, gspca_dev->usb_buf[0] | 0x02);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w1(gspca_dev, 0x1007, 0x00);
reg_r(gspca_dev, 0x1061, 1);
reg_w1(gspca_dev, 0x1061, gspca_dev->usb_buf[0] & ~0x02);
}
static void do_autoexposure(struct gspca_dev *gspca_dev, u16 avg_lum)
{
struct sd *sd = (struct sd *) gspca_dev;
s16 new_exp;
if (avg_lum < MIN_AVG_LUM) {
if (sd->exposure > 0x1770)
return;
new_exp = sd->exposure + sd->exposure_step;
if (new_exp > 0x1770)
new_exp = 0x1770;
if (new_exp < 0x10)
new_exp = 0x10;
sd->exposure = new_exp;
set_exposure(gspca_dev);
sd->older_step = sd->old_step;
sd->old_step = 1;
if (sd->old_step ^ sd->older_step)
sd->exposure_step /= 2;
else
sd->exposure_step += 2;
}
if (avg_lum > MAX_AVG_LUM) {
if (sd->exposure < 0x10)
return;
new_exp = sd->exposure - sd->exposure_step;
if (new_exp > 0x1700)
new_exp = 0x1770;
if (new_exp < 0x10)
new_exp = 0x10;
sd->exposure = new_exp;
set_exposure(gspca_dev);
sd->older_step = sd->old_step;
sd->old_step = 0;
if (sd->old_step ^ sd->older_step)
sd->exposure_step /= 2;
else
sd->exposure_step += 2;
}
}
static void do_autogain(struct gspca_dev *gspca_dev, u16 avg_lum)
{
struct sd *sd = (struct sd *) gspca_dev;
if (avg_lum < MIN_AVG_LUM) {
if (sd->gain + 1 <= 28) {
sd->gain++;
set_gain(gspca_dev);
}
}
if (avg_lum > MAX_AVG_LUM) {
if (sd->gain > 0) {
sd->gain--;
set_gain(gspca_dev);
}
}
}
static void sd_dqcallback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum;
if (!sd->auto_exposure)
return;
avg_lum = atomic_read(&sd->avg_lum);
if (sd->sensor == SENSOR_SOI968)
do_autogain(gspca_dev, avg_lum);
else
do_autoexposure(gspca_dev, avg_lum);
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret = -EINVAL;
if (!(sd->flags & HAS_NO_BUTTON) && len == 1) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
return ret;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum;
static u8 frame_header[] =
{0xff, 0xff, 0x00, 0xc4, 0xc4, 0x96};
if (len == 64 && memcmp(data, frame_header, 6) == 0) {
avg_lum = ((data[35] >> 2) & 3) |
(data[20] << 2) |
(data[19] << 10);
avg_lum += ((data[35] >> 4) & 3) |
(data[22] << 2) |
(data[21] << 10);
avg_lum += ((data[35] >> 6) & 3) |
(data[24] << 2) |
(data[23] << 10);
avg_lum += (data[36] & 3) |
(data[26] << 2) |
(data[25] << 10);
avg_lum += ((data[36] >> 2) & 3) |
(data[28] << 2) |
(data[27] << 10);
avg_lum += ((data[36] >> 4) & 3) |
(data[30] << 2) |
(data[29] << 10);
avg_lum += ((data[36] >> 6) & 3) |
(data[32] << 2) |
(data[31] << 10);
avg_lum += ((data[44] >> 4) & 3) |
(data[34] << 2) |
(data[33] << 10);
avg_lum >>= 9;
atomic_set(&sd->avg_lum, avg_lum);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
return;
}
if (gspca_dev->last_packet_type == LAST_PACKET) {
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv
& MODE_JPEG) {
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
gspca_frame_add(gspca_dev, INTER_PACKET,
data, len);
} else {
gspca_frame_add(gspca_dev, FIRST_PACKET,
data, len);
}
} else {
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
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
