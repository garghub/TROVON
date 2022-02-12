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
err("Out of memory");
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
err("Out of memory");
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
err("Bad sensor reset %02x", byte);
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
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode_t16;
cam->nmodes = ARRAY_SIZE(vga_mode_t16);
sd->brightness = BRIGHTNESS_DEF;
sd->contrast = CONTRAST_DEF;
sd->colors = COLORS_DEF;
sd->gamma = GAMMA_DEF;
sd->autogain = AUTOGAIN_DEF;
sd->mirror = MIRROR_DEF;
sd->freq = FREQ_DEF;
sd->awb = AWB_DEF;
sd->sharpness = SHARPNESS_DEF;
sd->effect = EFFECTS_DEF;
sd->red_gain = RED_GAIN_DEF;
sd->blue_gain = BLUE_GAIN_DEF;
sd->green_gain = GAIN_DEF * 3 - RED_GAIN_DEF - BLUE_GAIN_DEF;
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned int brightness;
u8 set6[4] = { 0x8f, 0x24, 0xc3, 0x00 };
brightness = sd->brightness;
if (brightness < 7) {
set6[1] = 0x26;
set6[3] = 0x70 - brightness * 0x10;
} else {
set6[3] = 0x00 + ((brightness - 7) * 0x10);
}
reg_w_buf(gspca_dev, set6, sizeof set6);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned int contrast = sd->contrast;
u16 reg_to_write;
if (contrast < 7)
reg_to_write = 0x8ea9 - contrast * 0x200;
else
reg_to_write = 0x00a9 + (contrast - 7) * 0x200;
reg_w(gspca_dev, reg_to_write);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg_to_write;
reg_to_write = 0x80bb + sd->colors * 0x100;
reg_w(gspca_dev, reg_to_write);
}
static void setgamma(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
PDEBUG(D_CONF, "Gamma: %d", sd->gamma);
reg_w_ixbuf(gspca_dev, 0x90,
gamma_table[sd->gamma], sizeof gamma_table[0]);
}
static void setRGB(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 all_gain_reg[6] =
{0x87, 0x00, 0x88, 0x00, 0x89, 0x00};
all_gain_reg[1] = sd->red_gain;
all_gain_reg[3] = sd->blue_gain;
all_gain_reg[5] = sd->green_gain;
reg_w_buf(gspca_dev, all_gain_reg, sizeof all_gain_reg);
}
static void setawb(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg80;
reg80 = (sensor_data[sd->sensor].reg80 << 8) | 0x80;
if (!sd->awb) {
sd->red_gain = reg_r(gspca_dev, 0x0087);
sd->blue_gain = reg_r(gspca_dev, 0x0088);
sd->green_gain = reg_r(gspca_dev, 0x0089);
reg80 &= ~0x0400;
}
reg_w(gspca_dev, reg80);
reg_w(gspca_dev, reg80);
}
static void init_gains(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg80;
u8 all_gain_reg[8] =
{0x87, 0x00, 0x88, 0x00, 0x89, 0x00, 0x80, 0x00};
all_gain_reg[1] = sd->red_gain;
all_gain_reg[3] = sd->blue_gain;
all_gain_reg[5] = sd->green_gain;
reg80 = sensor_data[sd->sensor].reg80;
if (!sd->awb)
reg80 &= ~0x04;
all_gain_reg[7] = reg80;
reg_w_buf(gspca_dev, all_gain_reg, sizeof all_gain_reg);
reg_w(gspca_dev, (sd->red_gain << 8) + 0x87);
reg_w(gspca_dev, (sd->blue_gain << 8) + 0x88);
reg_w(gspca_dev, (sd->green_gain << 8) + 0x89);
}
static void setsharpness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 reg_to_write;
reg_to_write = 0x0aa6 + 0x1000 * sd->sharpness;
reg_w(gspca_dev, reg_to_write);
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 reg66;
u8 freq[4] = { 0x66, 0x00, 0xa8, 0xe8 };
switch (sd->sensor) {
case SENSOR_LT168G:
if (sd->freq != 0)
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
switch (sd->freq) {
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
err("unknown sensor %04x", sensor_id);
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
err("Bad sensor reset %02x", test_byte);
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
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setgamma(gspca_dev);
setcolors(gspca_dev);
setsharpness(gspca_dev);
init_gains(gspca_dev);
setfreq(gspca_dev);
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
static void setmirror(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 hflipcmd[8] =
{0x62, 0x07, 0x63, 0x03, 0x64, 0x00, 0x60, 0x09};
if (sd->mirror)
hflipcmd[3] = 0x01;
reg_w_buf(gspca_dev, hflipcmd, sizeof hflipcmd);
}
static void seteffect(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w_buf(gspca_dev, effects_table[sd->effect],
sizeof effects_table[0]);
if (sd->effect == 1 || sd->effect == 5) {
PDEBUG(D_CONF,
"This effect have been disabled for webcam \"safety\"");
return;
}
if (sd->effect == 1 || sd->effect == 4)
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
setfreq(gspca_dev);
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
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int pkt_type;
if (data[0] == 0x5a) {
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
static int sd_setblue_gain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->blue_gain = val;
if (gspca_dev->streaming)
reg_w(gspca_dev, (val << 8) + 0x88);
return 0;
}
static int sd_getblue_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->blue_gain;
return 0;
}
static int sd_setred_gain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->red_gain = val;
if (gspca_dev->streaming)
reg_w(gspca_dev, (val << 8) + 0x87);
return 0;
}
static int sd_getred_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->red_gain;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 psg, nsg;
psg = sd->red_gain + sd->blue_gain + sd->green_gain;
nsg = val * 3;
sd->red_gain = sd->red_gain * nsg / psg;
if (sd->red_gain > 0x40)
sd->red_gain = 0x40;
else if (sd->red_gain < 0x10)
sd->red_gain = 0x10;
sd->blue_gain = sd->blue_gain * nsg / psg;
if (sd->blue_gain > 0x40)
sd->blue_gain = 0x40;
else if (sd->blue_gain < 0x10)
sd->blue_gain = 0x10;
sd->green_gain = sd->green_gain * nsg / psg;
if (sd->green_gain > 0x40)
sd->green_gain = 0x40;
else if (sd->green_gain < 0x10)
sd->green_gain = 0x10;
if (gspca_dev->streaming)
setRGB(gspca_dev);
return 0;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = (sd->red_gain + sd->blue_gain + sd->green_gain) / 3;
return 0;
}
static int sd_setbrightness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->brightness = val;
if (gspca_dev->streaming)
setbrightness(gspca_dev);
return 0;
}
static int sd_getbrightness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->brightness;
return *val;
}
static int sd_setawb(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->awb = val;
if (gspca_dev->streaming)
setawb(gspca_dev);
return 0;
}
static int sd_getawb(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->awb;
return *val;
}
static int sd_setmirror(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->mirror = val;
if (gspca_dev->streaming)
setmirror(gspca_dev);
return 0;
}
static int sd_getmirror(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->mirror;
return *val;
}
static int sd_seteffect(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->effect = val;
if (gspca_dev->streaming)
seteffect(gspca_dev);
return 0;
}
static int sd_geteffect(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->effect;
return *val;
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
setcontrast(gspca_dev);
return 0;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return *val;
}
static int sd_setcolors(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->colors = val;
if (gspca_dev->streaming)
setcolors(gspca_dev);
return 0;
}
static int sd_getcolors(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->colors;
return 0;
}
static int sd_setgamma(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gamma = val;
if (gspca_dev->streaming)
setgamma(gspca_dev);
return 0;
}
static int sd_getgamma(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gamma;
return 0;
}
static int sd_setfreq(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->freq = val;
if (gspca_dev->streaming)
setfreq(gspca_dev);
return 0;
}
static int sd_getfreq(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->freq;
return 0;
}
static int sd_setsharpness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->sharpness = val;
if (gspca_dev->streaming)
setsharpness(gspca_dev);
return 0;
}
static int sd_getsharpness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->sharpness;
return 0;
}
static int sd_setlowlight(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->autogain = val;
if (val != 0)
reg_w(gspca_dev, 0xf48e);
else
reg_w(gspca_dev, 0xb48e);
return 0;
}
static int sd_getlowlight(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->autogain;
return 0;
}
static int sd_querymenu(struct gspca_dev *gspca_dev,
struct v4l2_querymenu *menu)
{
static const char *freq_nm[3] = {"NoFliker", "50 Hz", "60 Hz"};
switch (menu->id) {
case V4L2_CID_POWER_LINE_FREQUENCY:
if ((unsigned) menu->index >= ARRAY_SIZE(freq_nm))
break;
strcpy((char *) menu->name, freq_nm[menu->index]);
return 0;
case V4L2_CID_EFFECTS:
if ((unsigned) menu->index < ARRAY_SIZE(effects_control)) {
strncpy((char *) menu->name,
effects_control[menu->index],
sizeof menu->name);
return 0;
}
break;
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
