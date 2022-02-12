static u8 reg_r(struct gspca_dev *gspca_dev,
u16 index)
{
int ret;
if (gspca_dev->usb_err < 0)
return 0;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0xa1,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x01,
index, gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
return 0;
}
return gspca_dev->usb_buf[0];
}
static void reg_w(struct gspca_dev *gspca_dev,
u8 value,
u16 index)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0xa0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0,
500);
if (ret < 0) {
pr_err("reg_w_i err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static u16 i2c_read(struct gspca_dev *gspca_dev,
u8 reg)
{
u8 retbyte;
u16 retval;
if (gspca_dev->usb_err < 0)
return 0;
reg_w(gspca_dev, reg, 0x0092);
reg_w(gspca_dev, 0x02, 0x0090);
msleep(20);
retbyte = reg_r(gspca_dev, 0x0091);
if (retbyte != 0x00)
pr_err("i2c_r status error %02x\n", retbyte);
retval = reg_r(gspca_dev, 0x0095);
retval |= reg_r(gspca_dev, 0x0096) << 8;
return retval;
}
static u8 i2c_write(struct gspca_dev *gspca_dev,
u8 reg,
u8 valL,
u8 valH)
{
u8 retbyte;
if (gspca_dev->usb_err < 0)
return 0;
reg_w(gspca_dev, reg, 0x92);
reg_w(gspca_dev, valL, 0x93);
reg_w(gspca_dev, valH, 0x94);
reg_w(gspca_dev, 0x01, 0x90);
msleep(1);
retbyte = reg_r(gspca_dev, 0x0091);
if (retbyte != 0x00)
pr_err("i2c_w status error %02x\n", retbyte);
return retbyte;
}
static void usb_exchange(struct gspca_dev *gspca_dev,
const struct usb_action *action)
{
while (action->req) {
switch (action->req) {
case 0xa0:
reg_w(gspca_dev, action->val, action->idx);
break;
case 0xa1:
reg_r(gspca_dev, action->idx);
break;
case 0xaa:
i2c_write(gspca_dev,
action->val,
action->idx & 0xff,
action->idx >> 8);
break;
case 0xbb:
i2c_write(gspca_dev,
action->idx >> 8,
action->idx & 0xff,
action->val);
break;
default:
msleep(action->idx);
break;
}
action++;
msleep(1);
}
}
static void setmatrix(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
const u8 *matrix;
static const u8 adcm2700_matrix[9] =
{0x74, 0xed, 0xed, 0xed, 0x74, 0xed, 0xed, 0xed, 0x74};
static const u8 gc0305_matrix[9] =
{0x50, 0xf8, 0xf8, 0xf8, 0x50, 0xf8, 0xf8, 0xf8, 0x50};
static const u8 ov7620_matrix[9] =
{0x58, 0xf4, 0xf4, 0xf4, 0x58, 0xf4, 0xf4, 0xf4, 0x58};
static const u8 pas202b_matrix[9] =
{0x4c, 0xf5, 0xff, 0xf9, 0x51, 0xf5, 0xfb, 0xed, 0x5f};
static const u8 po2030_matrix[9] =
{0x60, 0xf0, 0xf0, 0xf0, 0x60, 0xf0, 0xf0, 0xf0, 0x60};
static const u8 tas5130c_matrix[9] =
{0x68, 0xec, 0xec, 0xec, 0x68, 0xec, 0xec, 0xec, 0x68};
static const u8 gc0303_matrix[9] =
{0x6c, 0xea, 0xea, 0xea, 0x6c, 0xea, 0xea, 0xea, 0x6c};
static const u8 *matrix_tb[SENSOR_MAX] = {
[SENSOR_ADCM2700] = adcm2700_matrix,
[SENSOR_CS2102] = ov7620_matrix,
[SENSOR_CS2102K] = NULL,
[SENSOR_GC0303] = gc0303_matrix,
[SENSOR_GC0305] = gc0305_matrix,
[SENSOR_HDCS2020] = NULL,
[SENSOR_HV7131B] = NULL,
[SENSOR_HV7131R] = po2030_matrix,
[SENSOR_ICM105A] = po2030_matrix,
[SENSOR_MC501CB] = NULL,
[SENSOR_MT9V111_1] = gc0305_matrix,
[SENSOR_MT9V111_3] = gc0305_matrix,
[SENSOR_OV7620] = ov7620_matrix,
[SENSOR_OV7630C] = NULL,
[SENSOR_PAS106] = NULL,
[SENSOR_PAS202B] = pas202b_matrix,
[SENSOR_PB0330] = gc0305_matrix,
[SENSOR_PO2030] = po2030_matrix,
[SENSOR_TAS5130C] = tas5130c_matrix,
};
matrix = matrix_tb[sd->sensor];
if (matrix == NULL)
return;
for (i = 0; i < ARRAY_SIZE(ov7620_matrix); i++)
reg_w(gspca_dev, matrix[i], 0x010a + i);
}
static void setsharpness(struct gspca_dev *gspca_dev, s32 val)
{
static const u8 sharpness_tb[][2] = {
{0x02, 0x03},
{0x04, 0x07},
{0x08, 0x0f},
{0x10, 0x1e}
};
reg_w(gspca_dev, sharpness_tb[val][0], 0x01c6);
reg_r(gspca_dev, 0x01c8);
reg_r(gspca_dev, 0x01c9);
reg_r(gspca_dev, 0x01ca);
reg_w(gspca_dev, sharpness_tb[val][1], 0x01cb);
}
static void setcontrast(struct gspca_dev *gspca_dev,
s32 gamma, s32 brightness, s32 contrast)
{
const u8 *Tgamma;
int g, i, adj, gp1, gp2;
u8 gr[16];
static const u8 delta_b[16] =
{0x50, 0x38, 0x2d, 0x28, 0x24, 0x21, 0x1e, 0x1d,
0x1d, 0x1b, 0x1b, 0x1b, 0x19, 0x18, 0x18, 0x18};
static const u8 delta_c[16] =
{0x2c, 0x1a, 0x12, 0x0c, 0x0a, 0x06, 0x06, 0x06,
0x04, 0x06, 0x04, 0x04, 0x03, 0x03, 0x02, 0x02};
static const u8 gamma_tb[6][16] = {
{0x00, 0x00, 0x03, 0x0d, 0x1b, 0x2e, 0x45, 0x5f,
0x79, 0x93, 0xab, 0xc1, 0xd4, 0xe5, 0xf3, 0xff},
{0x01, 0x0c, 0x1f, 0x3a, 0x53, 0x6d, 0x85, 0x9c,
0xb0, 0xc2, 0xd1, 0xde, 0xe9, 0xf2, 0xf9, 0xff},
{0x04, 0x16, 0x30, 0x4e, 0x68, 0x81, 0x98, 0xac,
0xbe, 0xcd, 0xda, 0xe4, 0xed, 0xf5, 0xfb, 0xff},
{0x13, 0x38, 0x59, 0x79, 0x92, 0xa7, 0xb9, 0xc8,
0xd4, 0xdf, 0xe7, 0xee, 0xf4, 0xf9, 0xfc, 0xff},
{0x20, 0x4b, 0x6e, 0x8d, 0xa3, 0xb5, 0xc5, 0xd2,
0xdc, 0xe5, 0xec, 0xf2, 0xf6, 0xfa, 0xfd, 0xff},
{0x24, 0x44, 0x64, 0x84, 0x9d, 0xb2, 0xc4, 0xd3,
0xe0, 0xeb, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff},
};
Tgamma = gamma_tb[gamma - 1];
contrast -= 128;
brightness -= 128;
adj = 0;
gp1 = gp2 = 0;
for (i = 0; i < 16; i++) {
g = Tgamma[i] + delta_b[i] * brightness / 256
- delta_c[i] * contrast / 256 - adj / 2;
if (g > 0xff)
g = 0xff;
else if (g < 0)
g = 0;
reg_w(gspca_dev, g, 0x0120 + i);
if (contrast > 0)
adj--;
else if (contrast < 0)
adj++;
if (i > 1)
gr[i - 1] = (g - gp2) / 2;
else if (i != 0)
gr[0] = gp1 == 0 ? 0 : (g - gp1);
gp2 = gp1;
gp1 = g;
}
gr[15] = (0xff - gp2) / 2;
for (i = 0; i < 16; i++)
reg_w(gspca_dev, gr[i], 0x0130 + i);
}
static s32 getexposure(struct gspca_dev *gspca_dev)
{
return (i2c_read(gspca_dev, 0x25) << 9)
| (i2c_read(gspca_dev, 0x26) << 1)
| (i2c_read(gspca_dev, 0x27) >> 7);
}
static void setexposure(struct gspca_dev *gspca_dev, s32 val)
{
i2c_write(gspca_dev, 0x25, val >> 9, 0x00);
i2c_write(gspca_dev, 0x26, val >> 1, 0x00);
i2c_write(gspca_dev, 0x27, val << 7, 0x00);
}
static void setquality(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
jpeg_set_qual(sd->jpeg_hdr, jpeg_qual[sd->reg08 >> 1]);
reg_w(gspca_dev, sd->reg08, ZC3XX_R008_CLOCKSETTING);
}
static void setlightfreq(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, mode;
const struct usb_action *zc3_freq;
static const struct usb_action *freq_tb[SENSOR_MAX][6] = {
[SENSOR_ADCM2700] =
{adcm2700_NoFliker, adcm2700_NoFliker,
adcm2700_50HZ, adcm2700_50HZ,
adcm2700_60HZ, adcm2700_60HZ},
[SENSOR_CS2102] =
{cs2102_NoFliker, cs2102_NoFlikerScale,
cs2102_50HZ, cs2102_50HZScale,
cs2102_60HZ, cs2102_60HZScale},
[SENSOR_CS2102K] =
{cs2102_NoFliker, cs2102_NoFlikerScale,
NULL, NULL,
NULL, NULL},
[SENSOR_GC0303] =
{gc0303_NoFliker, gc0303_NoFlikerScale,
gc0303_50HZ, gc0303_50HZScale,
gc0303_60HZ, gc0303_60HZScale},
[SENSOR_GC0305] =
{gc0305_NoFliker, gc0305_NoFliker,
gc0305_50HZ, gc0305_50HZ,
gc0305_60HZ, gc0305_60HZ},
[SENSOR_HDCS2020] =
{hdcs2020_NoFliker, hdcs2020_NoFliker,
hdcs2020_50HZ, hdcs2020_50HZ,
hdcs2020_60HZ, hdcs2020_60HZ},
[SENSOR_HV7131B] =
{hv7131b_NoFliker, hv7131b_NoFlikerScale,
hv7131b_50HZ, hv7131b_50HZScale,
hv7131b_60HZ, hv7131b_60HZScale},
[SENSOR_HV7131R] =
{hv7131r_NoFliker, hv7131r_NoFlikerScale,
hv7131r_50HZ, hv7131r_50HZScale,
hv7131r_60HZ, hv7131r_60HZScale},
[SENSOR_ICM105A] =
{icm105a_NoFliker, icm105a_NoFlikerScale,
icm105a_50HZ, icm105a_50HZScale,
icm105a_60HZ, icm105a_60HZScale},
[SENSOR_MC501CB] =
{mc501cb_NoFliker, mc501cb_NoFlikerScale,
mc501cb_50HZ, mc501cb_50HZScale,
mc501cb_60HZ, mc501cb_60HZScale},
[SENSOR_MT9V111_1] =
{mt9v111_1_AENoFliker, mt9v111_1_AENoFlikerScale,
mt9v111_1_AE50HZ, mt9v111_1_AE50HZScale,
mt9v111_1_AE60HZ, mt9v111_1_AE60HZScale},
[SENSOR_MT9V111_3] =
{mt9v111_3_AENoFliker, mt9v111_3_AENoFlikerScale,
mt9v111_3_AE50HZ, mt9v111_3_AE50HZScale,
mt9v111_3_AE60HZ, mt9v111_3_AE60HZScale},
[SENSOR_OV7620] =
{ov7620_NoFliker, ov7620_NoFliker,
ov7620_50HZ, ov7620_50HZ,
ov7620_60HZ, ov7620_60HZ},
[SENSOR_OV7630C] =
{NULL, NULL,
NULL, NULL,
NULL, NULL},
[SENSOR_PAS106] =
{pas106b_NoFliker, pas106b_NoFliker,
pas106b_50HZ, pas106b_50HZ,
pas106b_60HZ, pas106b_60HZ},
[SENSOR_PAS202B] =
{pas202b_NoFliker, pas202b_NoFlikerScale,
pas202b_50HZ, pas202b_50HZScale,
pas202b_60HZ, pas202b_60HZScale},
[SENSOR_PB0330] =
{pb0330_NoFliker, pb0330_NoFlikerScale,
pb0330_50HZ, pb0330_50HZScale,
pb0330_60HZ, pb0330_60HZScale},
[SENSOR_PO2030] =
{po2030_NoFliker, po2030_NoFliker,
po2030_50HZ, po2030_50HZ,
po2030_60HZ, po2030_60HZ},
[SENSOR_TAS5130C] =
{tas5130c_NoFliker, tas5130c_NoFlikerScale,
tas5130c_50HZ, tas5130c_50HZScale,
tas5130c_60HZ, tas5130c_60HZScale},
};
i = val * 2;
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
if (mode)
i++;
zc3_freq = freq_tb[sd->sensor][i];
if (zc3_freq == NULL)
return;
usb_exchange(gspca_dev, zc3_freq);
switch (sd->sensor) {
case SENSOR_GC0305:
if (mode
&& val == 1)
reg_w(gspca_dev, 0x85, 0x018d);
break;
case SENSOR_OV7620:
if (!mode) {
if (val != 0)
reg_w(gspca_dev, 0x40, 0x0002);
else
reg_w(gspca_dev, 0x44, 0x0002);
}
break;
case SENSOR_PAS202B:
reg_w(gspca_dev, 0x00, 0x01a7);
break;
}
}
static void setautogain(struct gspca_dev *gspca_dev, s32 val)
{
reg_w(gspca_dev, val ? 0x42 : 0x02, 0x0180);
}
static void transfer_update(struct work_struct *work)
{
struct sd *sd = container_of(work, struct sd, work);
struct gspca_dev *gspca_dev = &sd->gspca_dev;
int change, good;
u8 reg07, reg11;
reg07 = 0;
good = 0;
while (1) {
msleep(100);
mutex_lock(&gspca_dev->usb_lock);
#ifdef CONFIG_PM
if (gspca_dev->frozen)
break;
#endif
if (!gspca_dev->present || !gspca_dev->streaming)
break;
gspca_dev->usb_err = 0;
reg11 = reg_r(gspca_dev, 0x0011);
if (gspca_dev->usb_err)
break;
change = reg11 & 0x01;
if (change) {
good = 0;
if (reg07 == 0)
reg07 = 0x32;
else if (reg07 > 2)
reg07 -= 2;
else
change = 0;
} else {
good++;
if (good >= 10) {
good = 0;
if (reg07) {
change = 1;
if (reg07 < 0x32)
reg07 += 2;
else
reg07 = 0;
}
}
}
if (change) {
gspca_dev->usb_err = 0;
reg_w(gspca_dev, reg07, 0x0007);
if (gspca_dev->usb_err)
break;
}
mutex_unlock(&gspca_dev->usb_lock);
}
mutex_unlock(&gspca_dev->usb_lock);
}
static void send_unknown(struct gspca_dev *gspca_dev, int sensor)
{
reg_w(gspca_dev, 0x01, 0x0000);
switch (sensor) {
case SENSOR_PAS106:
reg_w(gspca_dev, 0x03, 0x003a);
reg_w(gspca_dev, 0x0c, 0x003b);
reg_w(gspca_dev, 0x08, 0x0038);
break;
case SENSOR_ADCM2700:
case SENSOR_GC0305:
case SENSOR_OV7620:
case SENSOR_MT9V111_1:
case SENSOR_MT9V111_3:
case SENSOR_PB0330:
case SENSOR_PO2030:
reg_w(gspca_dev, 0x0d, 0x003a);
reg_w(gspca_dev, 0x02, 0x003b);
reg_w(gspca_dev, 0x00, 0x0038);
break;
case SENSOR_HV7131R:
case SENSOR_PAS202B:
reg_w(gspca_dev, 0x03, 0x003b);
reg_w(gspca_dev, 0x0c, 0x003a);
reg_w(gspca_dev, 0x0b, 0x0039);
if (sensor == SENSOR_PAS202B)
reg_w(gspca_dev, 0x0b, 0x0038);
break;
}
}
static void start_2wr_probe(struct gspca_dev *gspca_dev, int sensor)
{
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, sensor, 0x0010);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0x03, 0x0012);
reg_w(gspca_dev, 0x01, 0x0012);
}
static int sif_probe(struct gspca_dev *gspca_dev)
{
u16 checkword;
start_2wr_probe(gspca_dev, 0x0f);
reg_w(gspca_dev, 0x08, 0x008d);
msleep(150);
checkword = ((i2c_read(gspca_dev, 0x00) & 0x0f) << 4)
| ((i2c_read(gspca_dev, 0x01) & 0xf0) >> 4);
PDEBUG(D_PROBE, "probe sif 0x%04x", checkword);
if (checkword == 0x0007) {
send_unknown(gspca_dev, SENSOR_PAS106);
return 0x0f;
}
return -1;
}
static int vga_2wr_probe(struct gspca_dev *gspca_dev)
{
u16 retword;
start_2wr_probe(gspca_dev, 0x00);
i2c_write(gspca_dev, 0x01, 0xaa, 0x00);
retword = i2c_read(gspca_dev, 0x01);
if (retword != 0)
return 0x00;
start_2wr_probe(gspca_dev, 0x04);
i2c_write(gspca_dev, 0x01, 0xaa, 0x00);
retword = i2c_read(gspca_dev, 0x01);
if (retword != 0)
return 0x04;
start_2wr_probe(gspca_dev, 0x06);
reg_w(gspca_dev, 0x08, 0x008d);
i2c_write(gspca_dev, 0x11, 0xaa, 0x00);
retword = i2c_read(gspca_dev, 0x11);
if (retword != 0) {
goto ov_check;
}
start_2wr_probe(gspca_dev, 0x08);
i2c_write(gspca_dev, 0x1c, 0x00, 0x00);
i2c_write(gspca_dev, 0x15, 0xaa, 0x00);
retword = i2c_read(gspca_dev, 0x15);
if (retword != 0)
return 0x08;
start_2wr_probe(gspca_dev, 0x0a);
i2c_write(gspca_dev, 0x07, 0xaa, 0xaa);
retword = i2c_read(gspca_dev, 0x07);
if (retword != 0)
return 0x0a;
retword = i2c_read(gspca_dev, 0x03);
if (retword != 0)
return 0x0a;
retword = i2c_read(gspca_dev, 0x04);
if (retword != 0)
return 0x0a;
start_2wr_probe(gspca_dev, 0x0c);
i2c_write(gspca_dev, 0x01, 0x11, 0x00);
retword = i2c_read(gspca_dev, 0x01);
if (retword != 0)
return 0x0c;
start_2wr_probe(gspca_dev, 0x0e);
reg_w(gspca_dev, 0x08, 0x008d);
i2c_write(gspca_dev, 0x03, 0xaa, 0x00);
msleep(50);
retword = i2c_read(gspca_dev, 0x03);
if (retword != 0) {
send_unknown(gspca_dev, SENSOR_PAS202B);
return 0x0e;
}
start_2wr_probe(gspca_dev, 0x02);
i2c_write(gspca_dev, 0x01, 0xaa, 0x00);
retword = i2c_read(gspca_dev, 0x01);
if (retword != 0)
return 0x02;
ov_check:
reg_r(gspca_dev, 0x0010);
reg_r(gspca_dev, 0x0010);
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0x06, 0x0010);
reg_w(gspca_dev, 0xa1, 0x008b);
reg_w(gspca_dev, 0x08, 0x008d);
msleep(500);
reg_w(gspca_dev, 0x01, 0x0012);
i2c_write(gspca_dev, 0x12, 0x80, 0x00);
retword = i2c_read(gspca_dev, 0x0a) << 8;
retword |= i2c_read(gspca_dev, 0x0b);
PDEBUG(D_PROBE, "probe 2wr ov vga 0x%04x", retword);
switch (retword) {
case 0x7631:
reg_w(gspca_dev, 0x06, 0x0010);
break;
case 0x7620:
case 0x7648:
break;
default:
return -1;
}
return retword;
}
static int vga_3wr_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
u16 retword;
reg_w(gspca_dev, 0x02, 0x0010);
reg_r(gspca_dev, 0x0010);
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x00, 0x0010);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0x91, 0x008b);
reg_w(gspca_dev, 0x03, 0x0012);
reg_w(gspca_dev, 0x01, 0x0012);
reg_w(gspca_dev, 0x05, 0x0012);
retword = i2c_read(gspca_dev, 0x14);
if (retword != 0)
return 0x11;
retword = i2c_read(gspca_dev, 0x15);
if (retword != 0)
return 0x11;
retword = i2c_read(gspca_dev, 0x16);
if (retword != 0)
return 0x11;
reg_w(gspca_dev, 0x02, 0x0010);
retword = reg_r(gspca_dev, 0x000b) << 8;
retword |= reg_r(gspca_dev, 0x000a);
PDEBUG(D_PROBE, "probe 3wr vga 1 0x%04x", retword);
reg_r(gspca_dev, 0x0010);
if ((retword & 0xff00) == 0x6400)
return 0x02;
for (i = 0; i < ARRAY_SIZE(chipset_revision_sensor); i++) {
if (chipset_revision_sensor[i].revision == retword) {
sd->chip_revision = retword;
send_unknown(gspca_dev, SENSOR_PB0330);
return chipset_revision_sensor[i].internal_sensor_id;
}
}
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0xdd, 0x008b);
reg_w(gspca_dev, 0x0a, 0x0010);
reg_w(gspca_dev, 0x03, 0x0012);
reg_w(gspca_dev, 0x01, 0x0012);
retword = i2c_read(gspca_dev, 0x00);
if (retword != 0) {
PDEBUG(D_PROBE, "probe 3wr vga type 0a");
return 0x0a;
}
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0x98, 0x008b);
reg_w(gspca_dev, 0x01, 0x0010);
reg_w(gspca_dev, 0x03, 0x0012);
msleep(2);
reg_w(gspca_dev, 0x01, 0x0012);
retword = i2c_read(gspca_dev, 0x00);
if (retword != 0) {
PDEBUG(D_PROBE, "probe 3wr vga type %02x", retword);
if (retword == 0x0011)
return 0x0303;
if (retword == 0x0029)
send_unknown(gspca_dev, SENSOR_GC0305);
return retword;
}
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0xa1, 0x008b);
reg_w(gspca_dev, 0x08, 0x008d);
reg_w(gspca_dev, 0x06, 0x0010);
reg_w(gspca_dev, 0x01, 0x0012);
reg_w(gspca_dev, 0x05, 0x0012);
if (i2c_read(gspca_dev, 0x1c) == 0x007f
&& i2c_read(gspca_dev, 0x1d) == 0x00a2) {
send_unknown(gspca_dev, SENSOR_OV7620);
return 0x06;
}
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x00, 0x0002);
reg_w(gspca_dev, 0x01, 0x0010);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0xee, 0x008b);
reg_w(gspca_dev, 0x03, 0x0012);
reg_w(gspca_dev, 0x01, 0x0012);
reg_w(gspca_dev, 0x05, 0x0012);
retword = i2c_read(gspca_dev, 0x00) << 8;
retword |= i2c_read(gspca_dev, 0x01);
PDEBUG(D_PROBE, "probe 3wr vga 2 0x%04x", retword);
if (retword == 0x2030) {
u8 retbyte;
retbyte = i2c_read(gspca_dev, 0x02);
PDEBUG(D_PROBE, "sensor PO2030 rev 0x%02x", retbyte);
send_unknown(gspca_dev, SENSOR_PO2030);
return retword;
}
reg_w(gspca_dev, 0x01, 0x0000);
reg_w(gspca_dev, 0x0a, 0x0010);
reg_w(gspca_dev, 0xd3, 0x008b);
reg_w(gspca_dev, 0x01, 0x0001);
reg_w(gspca_dev, 0x03, 0x0012);
reg_w(gspca_dev, 0x01, 0x0012);
reg_w(gspca_dev, 0x05, 0x0012);
reg_w(gspca_dev, 0xd3, 0x008b);
retword = i2c_read(gspca_dev, 0x01);
if (retword != 0) {
PDEBUG(D_PROBE, "probe 3wr vga type 0a ? ret: %04x", retword);
return 0x16;
}
return -1;
}
static int zcxx_probeSensor(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int sensor;
switch (sd->sensor) {
case SENSOR_MC501CB:
return -1;
case SENSOR_GC0303:
return -1;
case SENSOR_PAS106:
sensor = sif_probe(gspca_dev);
if (sensor >= 0)
return sensor;
break;
}
sensor = vga_2wr_probe(gspca_dev);
if (sensor >= 0)
return sensor;
return vga_3wr_probe(gspca_dev);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
if (id->idProduct == 0x301b)
sd->bridge = BRIDGE_ZC301;
else
sd->bridge = BRIDGE_ZC303;
sd->sensor = id->driver_info;
sd->reg08 = REG08_DEF;
INIT_WORK(&sd->work, transfer_update);
return 0;
}
static int zcxx_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
gspca_dev->usb_err = 0;
if (ctrl->val && sd->exposure && gspca_dev->streaming)
sd->exposure->val = getexposure(gspca_dev);
return gspca_dev->usb_err;
}
return -EINVAL;
}
static int zcxx_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
int i, qual;
gspca_dev->usb_err = 0;
if (ctrl->id == V4L2_CID_JPEG_COMPRESSION_QUALITY) {
qual = sd->reg08 >> 1;
for (i = 0; i < ARRAY_SIZE(jpeg_qual); i++) {
if (ctrl->val <= jpeg_qual[i])
break;
}
if (i == ARRAY_SIZE(jpeg_qual) || (i > 0 && i == qual && ctrl->val < jpeg_qual[i]))
i--;
if (i >= 2 && gspca_dev->streaming &&
!gspca_dev->cam.needs_full_bandwidth)
return -EBUSY;
sd->reg08 = (i << 1) | 1;
ctrl->val = jpeg_qual[i];
}
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_GAMMA:
setcontrast(gspca_dev, sd->gamma->val,
sd->brightness->val, sd->contrast->val);
break;
case V4L2_CID_AUTOGAIN:
setautogain(gspca_dev, ctrl->val);
if (!gspca_dev->usb_err && !ctrl->val && sd->exposure)
setexposure(gspca_dev, sd->exposure->val);
break;
case V4L2_CID_POWER_LINE_FREQUENCY:
setlightfreq(gspca_dev, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
setsharpness(gspca_dev, ctrl->val);
break;
case V4L2_CID_JPEG_COMPRESSION_QUALITY:
setquality(gspca_dev);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
static const u8 gamma[SENSOR_MAX] = {
[SENSOR_ADCM2700] = 4,
[SENSOR_CS2102] = 4,
[SENSOR_CS2102K] = 5,
[SENSOR_GC0303] = 3,
[SENSOR_GC0305] = 4,
[SENSOR_HDCS2020] = 4,
[SENSOR_HV7131B] = 4,
[SENSOR_HV7131R] = 4,
[SENSOR_ICM105A] = 4,
[SENSOR_MC501CB] = 4,
[SENSOR_MT9V111_1] = 4,
[SENSOR_MT9V111_3] = 4,
[SENSOR_OV7620] = 3,
[SENSOR_OV7630C] = 4,
[SENSOR_PAS106] = 4,
[SENSOR_PAS202B] = 4,
[SENSOR_PB0330] = 4,
[SENSOR_PO2030] = 4,
[SENSOR_TAS5130C] = 3,
};
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 8);
sd->brightness = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
sd->contrast = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 128);
sd->gamma = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_GAMMA, 1, 6, 1, gamma[sd->sensor]);
if (sd->sensor == SENSOR_HV7131R)
sd->exposure = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_EXPOSURE, 0x30d, 0x493e, 1, 0x927);
sd->autogain = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
if (sd->sensor != SENSOR_OV7630C)
sd->plfreq = v4l2_ctrl_new_std_menu(hdl, &zcxx_ctrl_ops,
V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CID_POWER_LINE_FREQUENCY_60HZ, 0,
V4L2_CID_POWER_LINE_FREQUENCY_DISABLED);
sd->sharpness = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 3, 1,
sd->sensor == SENSOR_PO2030 ? 0 : 2);
sd->jpegqual = v4l2_ctrl_new_std(hdl, &zcxx_ctrl_ops,
V4L2_CID_JPEG_COMPRESSION_QUALITY,
jpeg_qual[0], jpeg_qual[ARRAY_SIZE(jpeg_qual) - 1], 1,
jpeg_qual[REG08_DEF >> 1]);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
v4l2_ctrl_cluster(3, &sd->gamma);
if (sd->sensor == SENSOR_HV7131R)
v4l2_ctrl_auto_cluster(2, &sd->autogain, 0, true);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
int sensor;
static const u8 mode_tb[SENSOR_MAX] = {
[SENSOR_ADCM2700] = 2,
[SENSOR_CS2102] = 1,
[SENSOR_CS2102K] = 1,
[SENSOR_GC0303] = 1,
[SENSOR_GC0305] = 1,
[SENSOR_HDCS2020] = 1,
[SENSOR_HV7131B] = 1,
[SENSOR_HV7131R] = 1,
[SENSOR_ICM105A] = 1,
[SENSOR_MC501CB] = 2,
[SENSOR_MT9V111_1] = 1,
[SENSOR_MT9V111_3] = 1,
[SENSOR_OV7620] = 2,
[SENSOR_OV7630C] = 1,
[SENSOR_PAS106] = 0,
[SENSOR_PAS202B] = 1,
[SENSOR_PB0330] = 1,
[SENSOR_PO2030] = 1,
[SENSOR_TAS5130C] = 1,
};
sensor = zcxx_probeSensor(gspca_dev);
if (sensor >= 0)
PDEBUG(D_PROBE, "probe sensor -> %04x", sensor);
if ((unsigned) force_sensor < SENSOR_MAX) {
sd->sensor = force_sensor;
PDEBUG(D_PROBE, "sensor forced to %d", force_sensor);
} else {
switch (sensor) {
case -1:
switch (sd->sensor) {
case SENSOR_MC501CB:
PDEBUG(D_PROBE, "Sensor MC501CB");
break;
case SENSOR_GC0303:
PDEBUG(D_PROBE, "Sensor GC0303");
break;
default:
pr_warn("Unknown sensor - set to TAS5130C\n");
sd->sensor = SENSOR_TAS5130C;
}
break;
case 0:
sensor = i2c_read(gspca_dev, 0x00);
PDEBUG(D_PROBE, "Sensor hv7131 type %d", sensor);
switch (sensor) {
case 0:
case 1:
PDEBUG(D_PROBE, "Find Sensor HV7131B");
sd->sensor = SENSOR_HV7131B;
break;
default:
PDEBUG(D_PROBE, "Find Sensor HV7131R");
sd->sensor = SENSOR_HV7131R;
break;
}
break;
case 0x02:
PDEBUG(D_PROBE, "Sensor TAS5130C");
sd->sensor = SENSOR_TAS5130C;
break;
case 0x04:
PDEBUG(D_PROBE, "Find Sensor CS2102");
sd->sensor = SENSOR_CS2102;
break;
case 0x08:
PDEBUG(D_PROBE, "Find Sensor HDCS2020");
sd->sensor = SENSOR_HDCS2020;
break;
case 0x0a:
PDEBUG(D_PROBE,
"Find Sensor PB0330. Chip revision %x",
sd->chip_revision);
sd->sensor = SENSOR_PB0330;
break;
case 0x0c:
PDEBUG(D_PROBE, "Find Sensor ICM105A");
sd->sensor = SENSOR_ICM105A;
break;
case 0x0e:
PDEBUG(D_PROBE, "Find Sensor PAS202B");
sd->sensor = SENSOR_PAS202B;
break;
case 0x0f:
PDEBUG(D_PROBE, "Find Sensor PAS106");
sd->sensor = SENSOR_PAS106;
break;
case 0x10:
case 0x12:
PDEBUG(D_PROBE, "Find Sensor TAS5130C");
sd->sensor = SENSOR_TAS5130C;
break;
case 0x11:
PDEBUG(D_PROBE, "Find Sensor HV7131R");
sd->sensor = SENSOR_HV7131R;
break;
case 0x13:
case 0x15:
PDEBUG(D_PROBE,
"Sensor MT9V111. Chip revision %04x",
sd->chip_revision);
sd->sensor = sd->bridge == BRIDGE_ZC301
? SENSOR_MT9V111_1
: SENSOR_MT9V111_3;
break;
case 0x14:
PDEBUG(D_PROBE,
"Find Sensor CS2102K?. Chip revision %x",
sd->chip_revision);
sd->sensor = SENSOR_CS2102K;
break;
case 0x16:
PDEBUG(D_PROBE, "Find Sensor ADCM2700");
sd->sensor = SENSOR_ADCM2700;
break;
case 0x29:
PDEBUG(D_PROBE, "Find Sensor GC0305");
sd->sensor = SENSOR_GC0305;
break;
case 0x0303:
PDEBUG(D_PROBE, "Sensor GC0303");
sd->sensor = SENSOR_GC0303;
break;
case 0x2030:
PDEBUG(D_PROBE, "Find Sensor PO2030");
sd->sensor = SENSOR_PO2030;
break;
case 0x7620:
PDEBUG(D_PROBE, "Find Sensor OV7620");
sd->sensor = SENSOR_OV7620;
break;
case 0x7631:
PDEBUG(D_PROBE, "Find Sensor OV7630C");
sd->sensor = SENSOR_OV7630C;
break;
case 0x7648:
PDEBUG(D_PROBE, "Find Sensor OV7648");
sd->sensor = SENSOR_OV7620;
break;
default:
pr_err("Unknown sensor %04x\n", sensor);
return -EINVAL;
}
}
if (sensor < 0x20) {
if (sensor == -1 || sensor == 0x10 || sensor == 0x12)
reg_w(gspca_dev, 0x02, 0x0010);
reg_r(gspca_dev, 0x0010);
}
cam = &gspca_dev->cam;
switch (mode_tb[sd->sensor]) {
case 0:
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
break;
case 1:
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
break;
default:
cam->cam_mode = broken_vga_mode;
cam->nmodes = ARRAY_SIZE(broken_vga_mode);
break;
}
reg_w(gspca_dev, 0x01, 0x0000);
return gspca_dev->usb_err;
}
static int sd_pre_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->cam.needs_full_bandwidth = (sd->reg08 >= 4) ? 1 : 0;
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int mode;
static const struct usb_action *init_tb[SENSOR_MAX][2] = {
[SENSOR_ADCM2700] =
{adcm2700_Initial, adcm2700_InitialScale},
[SENSOR_CS2102] =
{cs2102_Initial, cs2102_InitialScale},
[SENSOR_CS2102K] =
{cs2102K_Initial, cs2102K_InitialScale},
[SENSOR_GC0303] =
{gc0303_Initial, gc0303_InitialScale},
[SENSOR_GC0305] =
{gc0305_Initial, gc0305_InitialScale},
[SENSOR_HDCS2020] =
{hdcs2020_Initial, hdcs2020_InitialScale},
[SENSOR_HV7131B] =
{hv7131b_Initial, hv7131b_InitialScale},
[SENSOR_HV7131R] =
{hv7131r_Initial, hv7131r_InitialScale},
[SENSOR_ICM105A] =
{icm105a_Initial, icm105a_InitialScale},
[SENSOR_MC501CB] =
{mc501cb_Initial, mc501cb_InitialScale},
[SENSOR_MT9V111_1] =
{mt9v111_1_Initial, mt9v111_1_InitialScale},
[SENSOR_MT9V111_3] =
{mt9v111_3_Initial, mt9v111_3_InitialScale},
[SENSOR_OV7620] =
{ov7620_Initial, ov7620_InitialScale},
[SENSOR_OV7630C] =
{ov7630c_Initial, ov7630c_InitialScale},
[SENSOR_PAS106] =
{pas106b_Initial, pas106b_InitialScale},
[SENSOR_PAS202B] =
{pas202b_Initial, pas202b_InitialScale},
[SENSOR_PB0330] =
{pb0330_Initial, pb0330_InitialScale},
[SENSOR_PO2030] =
{po2030_Initial, po2030_InitialScale},
[SENSOR_TAS5130C] =
{tas5130c_Initial, tas5130c_InitialScale},
};
jpeg_define(sd->jpeg_hdr, gspca_dev->pixfmt.height,
gspca_dev->pixfmt.width,
0x21);
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
switch (sd->sensor) {
case SENSOR_HV7131R:
zcxx_probeSensor(gspca_dev);
break;
case SENSOR_PAS106:
usb_exchange(gspca_dev, pas106b_Initial_com);
break;
}
usb_exchange(gspca_dev, init_tb[sd->sensor][mode]);
switch (sd->sensor) {
case SENSOR_ADCM2700:
case SENSOR_GC0305:
case SENSOR_OV7620:
case SENSOR_PO2030:
case SENSOR_TAS5130C:
case SENSOR_GC0303:
reg_r(gspca_dev, 0x0002);
reg_w(gspca_dev, 0x09, 0x01ad);
reg_w(gspca_dev, 0x15, 0x01ae);
if (sd->sensor == SENSOR_TAS5130C)
break;
reg_w(gspca_dev, 0x0d, 0x003a);
reg_w(gspca_dev, 0x02, 0x003b);
reg_w(gspca_dev, 0x00, 0x0038);
break;
case SENSOR_HV7131R:
case SENSOR_PAS202B:
reg_w(gspca_dev, 0x03, 0x003b);
reg_w(gspca_dev, 0x0c, 0x003a);
reg_w(gspca_dev, 0x0b, 0x0039);
if (sd->sensor == SENSOR_HV7131R)
reg_w(gspca_dev, 0x50, ZC3XX_R11D_GLOBALGAIN);
break;
}
setmatrix(gspca_dev);
switch (sd->sensor) {
case SENSOR_ADCM2700:
case SENSOR_OV7620:
reg_r(gspca_dev, 0x0008);
reg_w(gspca_dev, 0x00, 0x0008);
break;
case SENSOR_PAS202B:
case SENSOR_GC0305:
case SENSOR_HV7131R:
case SENSOR_TAS5130C:
reg_r(gspca_dev, 0x0008);
case SENSOR_PO2030:
reg_w(gspca_dev, 0x03, 0x0008);
break;
}
setsharpness(gspca_dev, v4l2_ctrl_g_ctrl(sd->sharpness));
switch (sd->sensor) {
case SENSOR_CS2102K:
case SENSOR_HDCS2020:
case SENSOR_OV7630C:
break;
default:
setcontrast(gspca_dev, v4l2_ctrl_g_ctrl(sd->gamma),
v4l2_ctrl_g_ctrl(sd->brightness),
v4l2_ctrl_g_ctrl(sd->contrast));
break;
}
setmatrix(gspca_dev);
switch (sd->sensor) {
case SENSOR_OV7620:
case SENSOR_PAS202B:
reg_r(gspca_dev, 0x0180);
reg_w(gspca_dev, 0x00, 0x0180);
break;
}
setquality(gspca_dev);
reg_w(gspca_dev, 0x00, 0x0007);
if (sd->plfreq)
setlightfreq(gspca_dev, v4l2_ctrl_g_ctrl(sd->plfreq));
switch (sd->sensor) {
case SENSOR_ADCM2700:
reg_w(gspca_dev, 0x09, 0x01ad);
reg_w(gspca_dev, 0x15, 0x01ae);
reg_w(gspca_dev, 0x02, 0x0180);
reg_w(gspca_dev, 0x40, 0x0117);
break;
case SENSOR_HV7131R:
setexposure(gspca_dev, v4l2_ctrl_g_ctrl(sd->exposure));
reg_w(gspca_dev, 0x00, ZC3XX_R1A7_CALCGLOBALMEAN);
break;
case SENSOR_GC0305:
case SENSOR_TAS5130C:
reg_w(gspca_dev, 0x09, 0x01ad);
reg_w(gspca_dev, 0x15, 0x01ae);
case SENSOR_PAS202B:
case SENSOR_PO2030:
reg_r(gspca_dev, 0x0180);
break;
case SENSOR_OV7620:
reg_w(gspca_dev, 0x09, 0x01ad);
reg_w(gspca_dev, 0x15, 0x01ae);
i2c_read(gspca_dev, 0x13);
i2c_write(gspca_dev, 0x13, 0xa3, 0x00);
reg_w(gspca_dev, 0x40, 0x0117);
reg_r(gspca_dev, 0x0180);
break;
}
setautogain(gspca_dev, v4l2_ctrl_g_ctrl(sd->autogain));
if (gspca_dev->usb_err < 0)
return gspca_dev->usb_err;
sd->work_thread = create_singlethread_workqueue(KBUILD_MODNAME);
queue_work(sd->work_thread, &sd->work);
return 0;
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
if (!gspca_dev->present)
return;
send_unknown(gspca_dev, sd->sensor);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (len >= 3
&& data[len - 3] == 0xff && data[len - 2] == 0xd9) {
gspca_frame_add(gspca_dev, LAST_PACKET,
data, len - 1);
return;
}
if (data[0] == 0xff && data[1] == 0xd8) {
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
data += 18;
len -= 18;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_set_jcomp(struct gspca_dev *gspca_dev,
const struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
return v4l2_ctrl_s_ctrl(sd->jpegqual, jcomp->quality);
}
static int sd_get_jcomp(struct gspca_dev *gspca_dev,
struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
memset(jcomp, 0, sizeof *jcomp);
jcomp->quality = v4l2_ctrl_g_ctrl(sd->jpegqual);
jcomp->jpeg_markers = V4L2_JPEG_MARKER_DHT
| V4L2_JPEG_MARKER_DQT;
return 0;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
if (len == 8 && data[4] == 1) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
