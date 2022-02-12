static void reg_r(struct gspca_dev *gspca_dev, u16 reg, u16 length)
{
struct usb_device *dev = gspca_dev->dev;
int result;
if (gspca_dev->usb_err < 0)
return;
result = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
reg,
0x00,
gspca_dev->usb_buf,
length,
500);
if (unlikely(result < 0 || result != length)) {
pr_err("Read register %02x failed %d\n", reg, result);
gspca_dev->usb_err = result;
}
}
static void reg_w(struct gspca_dev *gspca_dev, u16 reg,
const u8 *buffer, int length)
{
struct usb_device *dev = gspca_dev->dev;
int result;
if (gspca_dev->usb_err < 0)
return;
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
pr_err("Write register %02x failed %d\n", reg, result);
gspca_dev->usb_err = result;
}
}
static void reg_w1(struct gspca_dev *gspca_dev, u16 reg, const u8 value)
{
reg_w(gspca_dev, reg, &value, 1);
}
static void i2c_w(struct gspca_dev *gspca_dev, const u8 *buffer)
{
int i;
reg_w(gspca_dev, 0x10c0, buffer, 8);
for (i = 0; i < 5; i++) {
reg_r(gspca_dev, 0x10c0, 1);
if (gspca_dev->usb_err < 0)
return;
if (gspca_dev->usb_buf[0] & 0x04) {
if (gspca_dev->usb_buf[0] & 0x08) {
pr_err("i2c_w error\n");
gspca_dev->usb_err = -EIO;
}
return;
}
msleep(10);
}
pr_err("i2c_w reg %02x no response\n", buffer[2]);
}
static void i2c_w1(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = sd->i2c_intf | (2 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = val;
row[4] = 0x00;
row[5] = 0x00;
row[6] = 0x00;
row[7] = 0x10;
i2c_w(gspca_dev, row);
}
static void i2c_w1_buf(struct gspca_dev *gspca_dev,
const struct i2c_reg_u8 *buf, int sz)
{
while (--sz >= 0) {
i2c_w1(gspca_dev, buf->reg, buf->val);
buf++;
}
}
static void i2c_w2(struct gspca_dev *gspca_dev, u8 reg, u16 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = sd->i2c_intf | (3 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = val >> 8;
row[4] = val;
row[5] = 0x00;
row[6] = 0x00;
row[7] = 0x10;
i2c_w(gspca_dev, row);
}
static void i2c_w2_buf(struct gspca_dev *gspca_dev,
const struct i2c_reg_u16 *buf, int sz)
{
while (--sz >= 0) {
i2c_w2(gspca_dev, buf->reg, buf->val);
buf++;
}
}
static void i2c_r1(struct gspca_dev *gspca_dev, u8 reg, u8 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = sd->i2c_intf | (1 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = 0;
row[4] = 0;
row[5] = 0;
row[6] = 0;
row[7] = 0x10;
i2c_w(gspca_dev, row);
row[0] = sd->i2c_intf | (1 << 4) | 0x02;
row[2] = 0;
i2c_w(gspca_dev, row);
reg_r(gspca_dev, 0x10c2, 5);
*val = gspca_dev->usb_buf[4];
}
static void i2c_r2(struct gspca_dev *gspca_dev, u8 reg, u16 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 row[8];
row[0] = sd->i2c_intf | (1 << 4);
row[1] = sd->i2c_addr;
row[2] = reg;
row[3] = 0;
row[4] = 0;
row[5] = 0;
row[6] = 0;
row[7] = 0x10;
i2c_w(gspca_dev, row);
row[0] = sd->i2c_intf | (2 << 4) | 0x02;
row[2] = 0;
i2c_w(gspca_dev, row);
reg_r(gspca_dev, 0x10c2, 5);
*val = (gspca_dev->usb_buf[3] << 8) | gspca_dev->usb_buf[4];
}
static void ov9650_init_sensor(struct gspca_dev *gspca_dev)
{
u16 id;
struct sd *sd = (struct sd *) gspca_dev;
i2c_r2(gspca_dev, 0x1c, &id);
if (gspca_dev->usb_err < 0)
return;
if (id != 0x7fa2) {
pr_err("sensor id for ov9650 doesn't match (0x%04x)\n", id);
gspca_dev->usb_err = -ENODEV;
return;
}
i2c_w1(gspca_dev, 0x12, 0x80);
msleep(200);
i2c_w1_buf(gspca_dev, ov9650_init, ARRAY_SIZE(ov9650_init));
if (gspca_dev->usb_err < 0)
pr_err("OV9650 sensor initialization failed\n");
sd->hstart = 1;
sd->vstart = 7;
}
static void ov9655_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w1(gspca_dev, 0x12, 0x80);
msleep(200);
i2c_w1_buf(gspca_dev, ov9655_init, ARRAY_SIZE(ov9655_init));
if (gspca_dev->usb_err < 0)
pr_err("OV9655 sensor initialization failed\n");
sd->hstart = 1;
sd->vstart = 2;
}
static void soi968_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w1(gspca_dev, 0x12, 0x80);
msleep(200);
i2c_w1_buf(gspca_dev, soi968_init, ARRAY_SIZE(soi968_init));
if (gspca_dev->usb_err < 0)
pr_err("SOI968 sensor initialization failed\n");
sd->hstart = 60;
sd->vstart = 11;
}
static void ov7660_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w1(gspca_dev, 0x12, 0x80);
msleep(200);
i2c_w1_buf(gspca_dev, ov7660_init, ARRAY_SIZE(ov7660_init));
if (gspca_dev->usb_err < 0)
pr_err("OV7660 sensor initialization failed\n");
sd->hstart = 3;
sd->vstart = 3;
}
static void ov7670_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w1(gspca_dev, 0x12, 0x80);
msleep(200);
i2c_w1_buf(gspca_dev, ov7670_init, ARRAY_SIZE(ov7670_init));
if (gspca_dev->usb_err < 0)
pr_err("OV7670 sensor initialization failed\n");
sd->hstart = 0;
sd->vstart = 1;
}
static void mt9v_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 value;
sd->i2c_addr = 0x5d;
i2c_r2(gspca_dev, 0xff, &value);
if (gspca_dev->usb_err >= 0
&& value == 0x8243) {
i2c_w2_buf(gspca_dev, mt9v011_init, ARRAY_SIZE(mt9v011_init));
if (gspca_dev->usb_err < 0) {
pr_err("MT9V011 sensor initialization failed\n");
return;
}
sd->hstart = 2;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V011;
pr_info("MT9V011 sensor detected\n");
return;
}
gspca_dev->usb_err = 0;
sd->i2c_addr = 0x5c;
i2c_w2(gspca_dev, 0x01, 0x0004);
i2c_r2(gspca_dev, 0xff, &value);
if (gspca_dev->usb_err >= 0
&& value == 0x823a) {
i2c_w2_buf(gspca_dev, mt9v111_init, ARRAY_SIZE(mt9v111_init));
if (gspca_dev->usb_err < 0) {
pr_err("MT9V111 sensor initialization failed\n");
return;
}
sd->hstart = 2;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V111;
pr_info("MT9V111 sensor detected\n");
return;
}
gspca_dev->usb_err = 0;
sd->i2c_addr = 0x5d;
i2c_w2(gspca_dev, 0xf0, 0x0000);
if (gspca_dev->usb_err < 0) {
gspca_dev->usb_err = 0;
sd->i2c_addr = 0x48;
i2c_w2(gspca_dev, 0xf0, 0x0000);
}
i2c_r2(gspca_dev, 0x00, &value);
if (gspca_dev->usb_err >= 0
&& value == 0x1229) {
i2c_w2_buf(gspca_dev, mt9v112_init, ARRAY_SIZE(mt9v112_init));
if (gspca_dev->usb_err < 0) {
pr_err("MT9V112 sensor initialization failed\n");
return;
}
sd->hstart = 6;
sd->vstart = 2;
sd->sensor = SENSOR_MT9V112;
pr_info("MT9V112 sensor detected\n");
return;
}
gspca_dev->usb_err = -ENODEV;
}
static void mt9m112_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w2_buf(gspca_dev, mt9m112_init, ARRAY_SIZE(mt9m112_init));
if (gspca_dev->usb_err < 0)
pr_err("MT9M112 sensor initialization failed\n");
sd->hstart = 0;
sd->vstart = 2;
}
static void mt9m111_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w2_buf(gspca_dev, mt9m111_init, ARRAY_SIZE(mt9m111_init));
if (gspca_dev->usb_err < 0)
pr_err("MT9M111 sensor initialization failed\n");
sd->hstart = 0;
sd->vstart = 2;
}
static void mt9m001_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 id;
i2c_r2(gspca_dev, 0x00, &id);
if (gspca_dev->usb_err < 0)
return;
switch (id) {
case 0x8411:
case 0x8421:
pr_info("MT9M001 color sensor detected\n");
break;
case 0x8431:
pr_info("MT9M001 mono sensor detected\n");
break;
default:
pr_err("No MT9M001 chip detected, ID = %x\n\n", id);
gspca_dev->usb_err = -ENODEV;
return;
}
i2c_w2_buf(gspca_dev, mt9m001_init, ARRAY_SIZE(mt9m001_init));
if (gspca_dev->usb_err < 0)
pr_err("MT9M001 sensor initialization failed\n");
sd->hstart = 1;
sd->vstart = 1;
}
static void hv7131r_init_sensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
i2c_w1_buf(gspca_dev, hv7131r_init, ARRAY_SIZE(hv7131r_init));
if (gspca_dev->usb_err < 0)
pr_err("HV7131R Sensor initialization failed\n");
sd->hstart = 0;
sd->vstart = 1;
}
static void set_cmatrix(struct gspca_dev *gspca_dev,
s32 brightness, s32 contrast, s32 satur, s32 hue)
{
s32 hue_coord, hue_index = 180 + hue;
u8 cmatrix[21];
memset(cmatrix, 0, sizeof cmatrix);
cmatrix[2] = (contrast * 0x25 / 0x100) + 0x26;
cmatrix[0] = 0x13 + (cmatrix[2] - 0x26) * 0x13 / 0x25;
cmatrix[4] = 0x07 + (cmatrix[2] - 0x26) * 0x07 / 0x25;
cmatrix[18] = brightness - 0x80;
hue_coord = (hsv_red_x[hue_index] * satur) >> 8;
cmatrix[6] = hue_coord;
cmatrix[7] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_red_y[hue_index] * satur) >> 8;
cmatrix[8] = hue_coord;
cmatrix[9] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_green_x[hue_index] * satur) >> 8;
cmatrix[10] = hue_coord;
cmatrix[11] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_green_y[hue_index] * satur) >> 8;
cmatrix[12] = hue_coord;
cmatrix[13] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_blue_x[hue_index] * satur) >> 8;
cmatrix[14] = hue_coord;
cmatrix[15] = (hue_coord >> 8) & 0x0f;
hue_coord = (hsv_blue_y[hue_index] * satur) >> 8;
cmatrix[16] = hue_coord;
cmatrix[17] = (hue_coord >> 8) & 0x0f;
reg_w(gspca_dev, 0x10e1, cmatrix, 21);
}
static void set_gamma(struct gspca_dev *gspca_dev, s32 val)
{
u8 gamma[17];
u8 gval = val * 0xb8 / 0x100;
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
reg_w(gspca_dev, 0x1190, gamma, 17);
}
static void set_redblue(struct gspca_dev *gspca_dev, s32 blue, s32 red)
{
reg_w1(gspca_dev, 0x118c, red);
reg_w1(gspca_dev, 0x118f, blue);
}
static void set_hvflip(struct gspca_dev *gspca_dev, s32 hflip, s32 vflip)
{
u8 value, tslb;
u16 value2;
struct sd *sd = (struct sd *) gspca_dev;
if ((sd->flags & FLIP_DETECT) && dmi_check_system(flip_dmi_table)) {
hflip = !hflip;
vflip = !vflip;
}
switch (sd->sensor) {
case SENSOR_OV7660:
value = 0x01;
if (hflip)
value |= 0x20;
if (vflip) {
value |= 0x10;
sd->vstart = 2;
} else {
sd->vstart = 3;
}
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
}
static void set_exposure(struct gspca_dev *gspca_dev, s32 expo)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 exp[8] = {sd->i2c_intf, sd->i2c_addr,
0x00, 0x00, 0x00, 0x00, 0x00, 0x10};
int expo2;
if (gspca_dev->streaming)
exp[7] = 0x1e;
switch (sd->sensor) {
case SENSOR_OV7660:
case SENSOR_OV7670:
case SENSOR_OV9655:
case SENSOR_OV9650:
if (expo > 547)
expo2 = 547;
else
expo2 = expo;
exp[0] |= (2 << 4);
exp[2] = 0x10;
exp[3] = expo2 >> 2;
exp[7] = 0x10;
i2c_w(gspca_dev, exp);
exp[2] = 0x04;
exp[3] = expo2 & 0x0003;
exp[7] = 0x10;
i2c_w(gspca_dev, exp);
expo -= expo2;
exp[7] = 0x1e;
exp[0] |= (3 << 4);
exp[2] = 0x2d;
exp[3] = expo;
exp[4] = expo >> 8;
break;
case SENSOR_MT9M001:
case SENSOR_MT9V112:
case SENSOR_MT9V011:
exp[0] |= (3 << 4);
exp[2] = 0x09;
exp[3] = expo >> 8;
exp[4] = expo;
break;
case SENSOR_HV7131R:
exp[0] |= (4 << 4);
exp[2] = 0x25;
exp[3] = expo >> 5;
exp[4] = expo << 3;
exp[5] = 0;
break;
default:
return;
}
i2c_w(gspca_dev, exp);
}
static void set_gain(struct gspca_dev *gspca_dev, s32 g)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gain[8] = {sd->i2c_intf, sd->i2c_addr,
0x00, 0x00, 0x00, 0x00, 0x00, 0x10};
if (gspca_dev->streaming)
gain[7] = 0x15;
switch (sd->sensor) {
case SENSOR_OV7660:
case SENSOR_OV7670:
case SENSOR_SOI968:
case SENSOR_OV9655:
case SENSOR_OV9650:
gain[0] |= (2 << 4);
gain[3] = ov_gain[g];
break;
case SENSOR_MT9V011:
gain[0] |= (3 << 4);
gain[2] = 0x35;
gain[3] = micron1_gain[g] >> 8;
gain[4] = micron1_gain[g];
break;
case SENSOR_MT9V112:
gain[0] |= (3 << 4);
gain[2] = 0x2f;
gain[3] = micron1_gain[g] >> 8;
gain[4] = micron1_gain[g];
break;
case SENSOR_MT9M001:
gain[0] |= (3 << 4);
gain[2] = 0x2f;
gain[3] = micron2_gain[g] >> 8;
gain[4] = micron2_gain[g];
break;
case SENSOR_HV7131R:
gain[0] |= (2 << 4);
gain[2] = 0x30;
gain[3] = hv7131r_gain[g];
break;
default:
return;
}
i2c_w(gspca_dev, gain);
}
static void set_quality(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
jpeg_set_qual(sd->jpeg_hdr, val);
reg_w1(gspca_dev, 0x1061, 0x01);
reg_w1(gspca_dev, 0x10e0, sd->fmt | 0x20);
reg_w(gspca_dev, 0x1100, &sd->jpeg_hdr[JPEG_QT0_OFFSET], 64);
reg_w(gspca_dev, 0x1140, &sd->jpeg_hdr[JPEG_QT1_OFFSET], 64);
reg_w1(gspca_dev, 0x1061, 0x03);
reg_w1(gspca_dev, 0x10e0, sd->fmt);
sd->fmt ^= 0x0c;
reg_w1(gspca_dev, 0x10e0, sd->fmt);
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
reg_r(gspca_dev, reg->reg, 1);
reg->val = gspca_dev->usb_buf[0];
return gspca_dev->usb_err;
case V4L2_CHIP_MATCH_I2C_ADDR:
if (reg->match.addr != sd->i2c_addr)
return -EINVAL;
if (sd->sensor >= SENSOR_MT9V011 &&
sd->sensor <= SENSOR_MT9M112) {
i2c_r2(gspca_dev, reg->reg, (u16 *) &reg->val);
} else {
i2c_r1(gspca_dev, reg->reg, (u8 *) &reg->val);
}
return gspca_dev->usb_err;
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
reg_w1(gspca_dev, reg->reg, reg->val);
return gspca_dev->usb_err;
case V4L2_CHIP_MATCH_I2C_ADDR:
if (reg->match.addr != sd->i2c_addr)
return -EINVAL;
if (sd->sensor >= SENSOR_MT9V011 &&
sd->sensor <= SENSOR_MT9M112) {
i2c_w2(gspca_dev, reg->reg, reg->val);
} else {
i2c_w1(gspca_dev, reg->reg, reg->val);
}
return gspca_dev->usb_err;
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
cam->needs_full_bandwidth = 1;
sd->sensor = id->driver_info >> 8;
sd->i2c_addr = id->driver_info;
sd->flags = id->driver_info >> 16;
sd->i2c_intf = 0x80;
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
case SENSOR_HV7131R:
sd->i2c_intf = 0x81;
default:
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
break;
}
sd->old_step = 0;
sd->older_step = 0;
sd->exposure_step = 16;
INIT_WORK(&sd->work, qual_upd);
return 0;
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
set_cmatrix(gspca_dev, sd->brightness->val,
sd->contrast->val, sd->saturation->val, sd->hue->val);
break;
case V4L2_CID_GAMMA:
set_gamma(gspca_dev, ctrl->val);
break;
case V4L2_CID_BLUE_BALANCE:
set_redblue(gspca_dev, sd->blue->val, sd->red->val);
break;
case V4L2_CID_HFLIP:
set_hvflip(gspca_dev, sd->hflip->val, sd->vflip->val);
break;
case V4L2_CID_EXPOSURE:
set_exposure(gspca_dev, ctrl->val);
break;
case V4L2_CID_GAIN:
set_gain(gspca_dev, ctrl->val);
break;
case V4L2_CID_AUTOGAIN:
if (sd->sensor == SENSOR_SOI968)
set_gain(gspca_dev, sd->gain->val);
else
set_exposure(gspca_dev, sd->exposure->val);
break;
case V4L2_CID_JPEG_COMPRESSION_QUALITY:
set_quality(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 13);
sd->brightness = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 127);
sd->contrast = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 127);
sd->saturation = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 127);
sd->hue = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, -180, 180, 1, 0);
sd->gamma = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAMMA, 0, 255, 1, 0x10);
sd->blue = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 127, 1, 0x28);
sd->red = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 127, 1, 0x28);
if (sd->sensor != SENSOR_OV9655 && sd->sensor != SENSOR_SOI968 &&
sd->sensor != SENSOR_OV7670 && sd->sensor != SENSOR_MT9M001 &&
sd->sensor != SENSOR_MT9VPRB) {
sd->hflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
sd->vflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
}
if (sd->sensor != SENSOR_SOI968 && sd->sensor != SENSOR_MT9VPRB &&
sd->sensor != SENSOR_MT9M112 && sd->sensor != SENSOR_MT9M111 &&
sd->sensor != SENSOR_MT9V111)
sd->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 0x1780, 1, 0x33);
if (sd->sensor != SENSOR_MT9VPRB && sd->sensor != SENSOR_MT9M112 &&
sd->sensor != SENSOR_MT9M111 && sd->sensor != SENSOR_MT9V111) {
sd->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 28, 1, 0);
sd->autogain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
}
sd->jpegqual = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_JPEG_COMPRESSION_QUALITY, 50, 90, 1, 80);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_cluster(4, &sd->brightness);
v4l2_ctrl_cluster(2, &sd->blue);
if (sd->hflip)
v4l2_ctrl_cluster(2, &sd->hflip);
if (sd->autogain) {
if (sd->sensor == SENSOR_SOI968)
v4l2_ctrl_auto_cluster(3, &sd->autogain, 0, false);
else
v4l2_ctrl_auto_cluster(2, &sd->autogain, 0, false);
}
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
reg_w(gspca_dev, bridge_init[i][0], &value, 1);
if (gspca_dev->usb_err < 0) {
pr_err("Device initialization failed\n");
return gspca_dev->usb_err;
}
}
if (sd->flags & LED_REVERSE)
reg_w1(gspca_dev, 0x1006, 0x00);
else
reg_w1(gspca_dev, 0x1006, 0x20);
reg_w(gspca_dev, 0x10c0, i2c_init, 9);
if (gspca_dev->usb_err < 0) {
pr_err("Device initialization failed\n");
return gspca_dev->usb_err;
}
switch (sd->sensor) {
case SENSOR_OV9650:
ov9650_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("OV9650 sensor detected\n");
break;
case SENSOR_OV9655:
ov9655_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("OV9655 sensor detected\n");
break;
case SENSOR_SOI968:
soi968_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("SOI968 sensor detected\n");
break;
case SENSOR_OV7660:
ov7660_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("OV7660 sensor detected\n");
break;
case SENSOR_OV7670:
ov7670_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("OV7670 sensor detected\n");
break;
case SENSOR_MT9VPRB:
mt9v_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("MT9VPRB sensor detected\n");
break;
case SENSOR_MT9M111:
mt9m111_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("MT9M111 sensor detected\n");
break;
case SENSOR_MT9M112:
mt9m112_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("MT9M112 sensor detected\n");
break;
case SENSOR_MT9M001:
mt9m001_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
break;
case SENSOR_HV7131R:
hv7131r_init_sensor(gspca_dev);
if (gspca_dev->usb_err < 0)
break;
pr_info("HV7131R sensor detected\n");
break;
default:
pr_err("Unsupported sensor\n");
gspca_dev->usb_err = -ENODEV;
}
return gspca_dev->usb_err;
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
static int sd_isoc_init(struct gspca_dev *gspca_dev)
{
struct usb_interface *intf;
u32 flags = gspca_dev->cam.cam_mode[(int)gspca_dev->curr_mode].priv;
if (!(flags & (MODE_RAW | MODE_JPEG))) {
intf = usb_ifnum_to_if(gspca_dev->dev, gspca_dev->iface);
if (intf->num_altsetting != 9) {
pr_warn("sn9c20x camera with unknown number of alt "
"settings (%d), please report!\n",
intf->num_altsetting);
gspca_dev->alt = intf->num_altsetting;
return 0;
}
switch (gspca_dev->width) {
case 160:
gspca_dev->alt = 2;
break;
case 320:
gspca_dev->alt = 6;
break;
default:
gspca_dev->alt = 9;
break;
}
}
return 0;
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
jpeg_set_qual(sd->jpeg_hdr, v4l2_ctrl_g_ctrl(sd->jpegqual));
if (mode & MODE_RAW)
fmt = 0x2d;
else if (mode & MODE_JPEG)
fmt = 0x24;
else
fmt = 0x2f;
sd->fmt = fmt;
switch (mode & SCALE_MASK) {
case SCALE_1280x1024:
scale = 0xc0;
pr_info("Set 1280x1024\n");
break;
case SCALE_640x480:
scale = 0x80;
pr_info("Set 640x480\n");
break;
case SCALE_320x240:
scale = 0x90;
pr_info("Set 320x240\n");
break;
case SCALE_160x120:
scale = 0xa0;
pr_info("Set 160x120\n");
break;
}
configure_sensor_output(gspca_dev, mode);
reg_w(gspca_dev, 0x1100, &sd->jpeg_hdr[JPEG_QT0_OFFSET], 64);
reg_w(gspca_dev, 0x1140, &sd->jpeg_hdr[JPEG_QT1_OFFSET], 64);
reg_w(gspca_dev, 0x10fb, CLR_WIN(width, height), 5);
reg_w(gspca_dev, 0x1180, HW_WIN(mode, sd->hstart, sd->vstart), 6);
reg_w1(gspca_dev, 0x1189, scale);
reg_w1(gspca_dev, 0x10e0, fmt);
set_cmatrix(gspca_dev, v4l2_ctrl_g_ctrl(sd->brightness),
v4l2_ctrl_g_ctrl(sd->contrast),
v4l2_ctrl_g_ctrl(sd->saturation),
v4l2_ctrl_g_ctrl(sd->hue));
set_gamma(gspca_dev, v4l2_ctrl_g_ctrl(sd->gamma));
set_redblue(gspca_dev, v4l2_ctrl_g_ctrl(sd->blue),
v4l2_ctrl_g_ctrl(sd->red));
if (sd->gain)
set_gain(gspca_dev, v4l2_ctrl_g_ctrl(sd->gain));
if (sd->exposure)
set_exposure(gspca_dev, v4l2_ctrl_g_ctrl(sd->exposure));
if (sd->hflip)
set_hvflip(gspca_dev, v4l2_ctrl_g_ctrl(sd->hflip),
v4l2_ctrl_g_ctrl(sd->vflip));
reg_w1(gspca_dev, 0x1007, 0x20);
reg_w1(gspca_dev, 0x1061, 0x03);
if (mode & MODE_JPEG) {
sd->pktsz = sd->npkt = 0;
sd->nchg = 0;
sd->work_thread =
create_singlethread_workqueue(KBUILD_MODNAME);
}
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w1(gspca_dev, 0x1007, 0x00);
reg_w1(gspca_dev, 0x1061, 0x01);
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
static void do_autoexposure(struct gspca_dev *gspca_dev, u16 avg_lum)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 cur_exp = v4l2_ctrl_g_ctrl(sd->exposure);
s32 max = sd->exposure->maximum - sd->exposure_step;
s32 min = sd->exposure->minimum + sd->exposure_step;
s16 new_exp;
if (avg_lum < MIN_AVG_LUM) {
if (cur_exp > max)
return;
new_exp = cur_exp + sd->exposure_step;
if (new_exp > max)
new_exp = max;
if (new_exp < min)
new_exp = min;
v4l2_ctrl_s_ctrl(sd->exposure, new_exp);
sd->older_step = sd->old_step;
sd->old_step = 1;
if (sd->old_step ^ sd->older_step)
sd->exposure_step /= 2;
else
sd->exposure_step += 2;
}
if (avg_lum > MAX_AVG_LUM) {
if (cur_exp < min)
return;
new_exp = cur_exp - sd->exposure_step;
if (new_exp > max)
new_exp = max;
if (new_exp < min)
new_exp = min;
v4l2_ctrl_s_ctrl(sd->exposure, new_exp);
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
s32 cur_gain = v4l2_ctrl_g_ctrl(sd->gain);
if (avg_lum < MIN_AVG_LUM && cur_gain < sd->gain->maximum)
v4l2_ctrl_s_ctrl(sd->gain, cur_gain + 1);
if (avg_lum > MAX_AVG_LUM && cur_gain > sd->gain->minimum)
v4l2_ctrl_s_ctrl(sd->gain, cur_gain - 1);
}
static void sd_dqcallback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum;
if (sd->autogain == NULL || !v4l2_ctrl_g_ctrl(sd->autogain))
return;
avg_lum = atomic_read(&sd->avg_lum);
if (sd->sensor == SENSOR_SOI968)
do_autogain(gspca_dev, avg_lum);
else
do_autoexposure(gspca_dev, avg_lum);
}
static void qual_upd(struct work_struct *work)
{
struct sd *sd = container_of(work, struct sd, work);
struct gspca_dev *gspca_dev = &sd->gspca_dev;
s32 qual = v4l2_ctrl_g_ctrl(sd->jpegqual);
mutex_lock(&gspca_dev->usb_lock);
PDEBUG(D_STREAM, "qual_upd %d%%", qual);
set_quality(gspca_dev, qual);
mutex_unlock(&gspca_dev->usb_lock);
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!(sd->flags & HAS_NO_BUTTON) && len == 1) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
return 0;
}
return -EINVAL;
}
static void transfer_check(struct gspca_dev *gspca_dev,
u8 *data)
{
struct sd *sd = (struct sd *) gspca_dev;
int new_qual, r;
new_qual = 0;
if (data[6] & 0x08) {
gspca_dev->last_packet_type = DISCARD_PACKET;
new_qual = -5;
} else {
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
s32 curqual = sd->jpegqual->cur.val;
sd->nchg = 0;
new_qual += curqual;
if (new_qual < sd->jpegqual->minimum)
new_qual = sd->jpegqual->minimum;
else if (new_qual > sd->jpegqual->maximum)
new_qual = sd->jpegqual->maximum;
if (new_qual != curqual) {
sd->jpegqual->cur.val = new_qual;
queue_work(sd->work_thread, &sd->work);
}
}
} else {
sd->nchg = 0;
}
sd->pktsz = sd->npkt = 0;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum, is_jpeg;
static const u8 frame_header[] =
{0xff, 0xff, 0x00, 0xc4, 0xc4, 0x96};
is_jpeg = (sd->fmt & 0x03) == 0;
if (len >= 64 && memcmp(data, frame_header, 6) == 0) {
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
if (is_jpeg)
transfer_check(gspca_dev, data);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
len -= 64;
if (len == 0)
return;
data += 64;
}
if (gspca_dev->last_packet_type == LAST_PACKET) {
if (is_jpeg) {
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
gspca_frame_add(gspca_dev, INTER_PACKET,
data, len);
} else {
gspca_frame_add(gspca_dev, FIRST_PACKET,
data, len);
}
} else {
if (is_jpeg) {
sd->npkt++;
sd->pktsz += len;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
