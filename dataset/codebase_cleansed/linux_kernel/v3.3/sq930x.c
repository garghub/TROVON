static void reg_r(struct gspca_dev *gspca_dev,
u16 value, int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0x0c,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, 0, gspca_dev->usb_buf, len,
500);
if (ret < 0) {
pr_err("reg_r %04x failed %d\n", value, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev, u16 value, u16 index)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "reg_w v: %04x i: %04x", value, index);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x0c,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0,
500);
msleep(30);
if (ret < 0) {
pr_err("reg_w %04x %04x failed %d\n", value, index, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_wb(struct gspca_dev *gspca_dev, u16 value, u16 index,
const u8 *data, int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
PDEBUG(D_USBO, "reg_wb v: %04x i: %04x %02x...%02x",
value, index, *data, data[len - 1]);
memcpy(gspca_dev->usb_buf, data, len);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x0c,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, gspca_dev->usb_buf, len,
1000);
msleep(30);
if (ret < 0) {
pr_err("reg_wb %04x %04x failed %d\n", value, index, ret);
gspca_dev->usb_err = ret;
}
}
static void i2c_write(struct sd *sd,
const struct i2c_write_cmd *cmd,
int ncmds)
{
struct gspca_dev *gspca_dev = &sd->gspca_dev;
const struct sensor_s *sensor;
u16 val, idx;
u8 *buf;
int ret;
if (gspca_dev->usb_err < 0)
return;
sensor = &sensor_tb[sd->sensor];
val = (sensor->i2c_addr << 8) | SQ930_CTRL_I2C_IO;
idx = (cmd->val & 0xff00) | cmd->reg;
buf = gspca_dev->usb_buf;
*buf++ = sensor->i2c_dum;
*buf++ = cmd->val;
while (--ncmds > 0) {
cmd++;
*buf++ = cmd->reg;
*buf++ = cmd->val >> 8;
*buf++ = sensor->i2c_dum;
*buf++ = cmd->val;
}
PDEBUG(D_USBO, "i2c_w v: %04x i: %04x %02x...%02x",
val, idx, gspca_dev->usb_buf[0], buf[-1]);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x0c,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
val, idx,
gspca_dev->usb_buf, buf - gspca_dev->usb_buf,
500);
if (ret < 0) {
pr_err("i2c_write failed %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void ucbus_write(struct gspca_dev *gspca_dev,
const struct ucbus_write_cmd *cmd,
int ncmds,
int batchsize)
{
u8 *buf;
u16 val, idx;
int len, ret;
if (gspca_dev->usb_err < 0)
return;
#ifdef GSPCA_DEBUG
if ((batchsize - 1) * 3 > USB_BUF_SZ) {
pr_err("Bug: usb_buf overflow\n");
gspca_dev->usb_err = -ENOMEM;
return;
}
#endif
for (;;) {
len = ncmds;
if (len > batchsize)
len = batchsize;
ncmds -= len;
val = (cmd->bw_addr << 8) | SQ930_CTRL_UCBUS_IO;
idx = (cmd->bw_data << 8) | (cmd->bw_addr >> 8);
buf = gspca_dev->usb_buf;
while (--len > 0) {
cmd++;
*buf++ = cmd->bw_addr;
*buf++ = cmd->bw_addr >> 8;
*buf++ = cmd->bw_data;
}
if (buf != gspca_dev->usb_buf)
PDEBUG(D_USBO, "ucbus v: %04x i: %04x %02x...%02x",
val, idx,
gspca_dev->usb_buf[0], buf[-1]);
else
PDEBUG(D_USBO, "ucbus v: %04x i: %04x",
val, idx);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x0c,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
val, idx,
gspca_dev->usb_buf, buf - gspca_dev->usb_buf,
500);
if (ret < 0) {
pr_err("ucbus_write failed %d\n", ret);
gspca_dev->usb_err = ret;
return;
}
msleep(30);
if (ncmds <= 0)
break;
cmd++;
}
}
static void gpio_set(struct sd *sd, u16 val, u16 mask)
{
struct gspca_dev *gspca_dev = &sd->gspca_dev;
if (mask & 0x00ff) {
sd->gpio[0] &= ~mask;
sd->gpio[0] |= val;
reg_w(gspca_dev, 0x0100 | SQ930_CTRL_GPIO,
~sd->gpio[0] << 8);
}
mask >>= 8;
val >>= 8;
if (mask) {
sd->gpio[1] &= ~mask;
sd->gpio[1] |= val;
reg_w(gspca_dev, 0x0300 | SQ930_CTRL_GPIO,
~sd->gpio[1] << 8);
}
}
static void gpio_init(struct sd *sd,
const u8 *gpio)
{
gpio_set(sd, *gpio++, 0x000f);
gpio_set(sd, *gpio++, 0x000f);
gpio_set(sd, *gpio++, 0x000f);
gpio_set(sd, *gpio++, 0x000f);
gpio_set(sd, *gpio, 0x000f);
}
static void bridge_init(struct sd *sd)
{
static const struct ucbus_write_cmd clkfreq_cmd = {
0xf031, 0
};
ucbus_write(&sd->gspca_dev, &clkfreq_cmd, 1, 1);
gpio_set(sd, SQ930_GPIO_POWER, 0xff00);
}
static void cmos_probe(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
const struct sensor_s *sensor;
static const u8 probe_order[] = {
SENSOR_OV9630,
SENSOR_MI0360,
SENSOR_OV7660,
SENSOR_MT9V111,
};
for (i = 0; i < ARRAY_SIZE(probe_order); i++) {
sensor = &sensor_tb[probe_order[i]];
ucbus_write(&sd->gspca_dev, sensor->cmd, sensor->cmd_len, 8);
gpio_init(sd, sensor->gpio);
msleep(100);
reg_r(gspca_dev, (sensor->i2c_addr << 8) | 0x001c, 1);
msleep(100);
if (gspca_dev->usb_buf[0] != 0)
break;
}
if (i >= ARRAY_SIZE(probe_order)) {
pr_err("Unknown sensor\n");
gspca_dev->usb_err = -EINVAL;
return;
}
sd->sensor = probe_order[i];
switch (sd->sensor) {
case SENSOR_OV7660:
case SENSOR_OV9630:
pr_err("Sensor %s not yet treated\n",
sensor_tb[sd->sensor].name);
gspca_dev->usb_err = -EINVAL;
break;
}
}
static void mt9v111_init(struct gspca_dev *gspca_dev)
{
int i, nwait;
static const u8 cmd_001b[] = {
0x00, 0x3b, 0xf6, 0x01, 0x03, 0x02, 0x00, 0x00,
0x00, 0x00, 0x00
};
static const u8 cmd_011b[][7] = {
{0x10, 0x01, 0x66, 0x08, 0x00, 0x00, 0x00},
{0x01, 0x00, 0x1a, 0x04, 0x00, 0x00, 0x00},
{0x20, 0x00, 0x10, 0x04, 0x00, 0x00, 0x00},
{0x02, 0x01, 0xae, 0x01, 0x00, 0x00, 0x00},
};
reg_wb(gspca_dev, 0x001b, 0x0000, cmd_001b, sizeof cmd_001b);
for (i = 0; i < ARRAY_SIZE(cmd_011b); i++) {
reg_wb(gspca_dev, 0x001b, 0x0000, cmd_011b[i],
ARRAY_SIZE(cmd_011b[0]));
msleep(400);
nwait = 20;
for (;;) {
reg_r(gspca_dev, 0x031b, 1);
if (gspca_dev->usb_buf[0] == 0
|| gspca_dev->usb_err != 0)
break;
if (--nwait < 0) {
PDEBUG(D_PROBE, "mt9v111_init timeout");
gspca_dev->usb_err = -ETIME;
return;
}
msleep(50);
}
}
}
static void global_init(struct sd *sd, int first_time)
{
switch (sd->sensor) {
case SENSOR_ICX098BQ:
if (first_time)
ucbus_write(&sd->gspca_dev,
icx098bq_start_0,
8, 8);
gpio_init(sd, sensor_tb[sd->sensor].gpio);
break;
case SENSOR_LZ24BP:
if (sd->type != Creative_live_motion)
gpio_set(sd, SQ930_GPIO_EXTRA1, 0x00ff);
else
gpio_set(sd, 0, 0x00ff);
msleep(50);
if (first_time)
ucbus_write(&sd->gspca_dev,
lz24bp_start_0,
8, 8);
gpio_init(sd, sensor_tb[sd->sensor].gpio);
break;
case SENSOR_MI0360:
if (first_time)
ucbus_write(&sd->gspca_dev,
mi0360_start_0,
ARRAY_SIZE(mi0360_start_0),
8);
gpio_init(sd, sensor_tb[sd->sensor].gpio);
gpio_set(sd, SQ930_GPIO_EXTRA2, SQ930_GPIO_EXTRA2);
break;
default:
if (first_time)
mt9v111_init(&sd->gspca_dev);
else
gpio_init(sd, sensor_tb[sd->sensor].gpio);
break;
}
}
static void lz24bp_ppl(struct sd *sd, u16 ppl)
{
struct ucbus_write_cmd cmds[2] = {
{0xf810, ppl >> 8},
{0xf811, ppl}
};
ucbus_write(&sd->gspca_dev, cmds, ARRAY_SIZE(cmds), 2);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, integclks, intstartclk, frameclks, min_frclk;
const struct sensor_s *sensor;
u16 cmd;
u8 buf[15];
integclks = sd->expo;
i = 0;
cmd = SQ930_CTRL_SET_EXPOSURE;
switch (sd->sensor) {
case SENSOR_ICX098BQ:
case SENSOR_LZ24BP:
min_frclk = sd->sensor == SENSOR_ICX098BQ ? 0x210 : 0x26f;
if (integclks >= min_frclk) {
intstartclk = 0;
frameclks = integclks;
} else {
intstartclk = min_frclk - integclks;
frameclks = min_frclk;
}
buf[i++] = intstartclk >> 8;
buf[i++] = intstartclk;
buf[i++] = frameclks >> 8;
buf[i++] = frameclks;
buf[i++] = sd->gain;
break;
default:
cmd |= 0x0100;
sensor = &sensor_tb[sd->sensor];
buf[i++] = sensor->i2c_addr;
buf[i++] = 0x08;
buf[i++] = 0x09;
buf[i++] = integclks >> 8;
buf[i++] = sensor->i2c_dum;
buf[i++] = integclks;
buf[i++] = 0x35;
buf[i++] = 0x00;
buf[i++] = sensor->i2c_dum;
buf[i++] = 0x80 + sd->gain / 2;
buf[i++] = 0x00;
buf[i++] = 0x00;
buf[i++] = 0x00;
buf[i++] = 0x00;
buf[i++] = 0x83;
break;
}
reg_wb(gspca_dev, cmd, 0, buf, i);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam = &gspca_dev->cam;
sd->sensor = id->driver_info >> 8;
sd->type = id->driver_info;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
cam->bulk = 1;
sd->gain = GAIN_DEF;
sd->expo = EXPO_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gpio[0] = sd->gpio[1] = 0xff;
reg_r(gspca_dev, SQ930_CTRL_GET_DEV_INFO, 8);
if (gspca_dev->usb_err < 0)
return gspca_dev->usb_err;
PDEBUG(D_PROBE, "info: %02x %02x %02x %02x %02x %02x %02x %02x",
gspca_dev->usb_buf[0],
gspca_dev->usb_buf[1],
gspca_dev->usb_buf[2],
gspca_dev->usb_buf[3],
gspca_dev->usb_buf[4],
gspca_dev->usb_buf[5],
gspca_dev->usb_buf[6],
gspca_dev->usb_buf[7]);
bridge_init(sd);
if (sd->sensor == SENSOR_MI0360) {
if (gspca_dev->usb_buf[5] == 0xf6)
sd->sensor = SENSOR_ICX098BQ;
else
cmos_probe(gspca_dev);
}
if (gspca_dev->usb_err >= 0) {
PDEBUG(D_PROBE, "Sensor %s", sensor_tb[sd->sensor].name);
global_init(sd, 1);
}
return gspca_dev->usb_err;
}
static void send_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const struct cap_s *cap;
int mode;
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
cap = &capconfig[sd->sensor][mode];
reg_wb(gspca_dev, 0x0900 | SQ930_CTRL_CAP_START,
0x0a00 | cap->cc_sizeid,
cap->cc_bytes, 32);
}
static void send_stop(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, SQ930_CTRL_CAP_STOP, 0);
}
static int sd_isoc_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->cam.bulk_nurbs = 1;
sd->do_ctrl = 0;
gspca_dev->cam.bulk_size = gspca_dev->width * gspca_dev->height + 8;
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int mode;
bridge_init(sd);
global_init(sd, 0);
msleep(100);
switch (sd->sensor) {
case SENSOR_ICX098BQ:
ucbus_write(gspca_dev, icx098bq_start_0,
ARRAY_SIZE(icx098bq_start_0),
8);
ucbus_write(gspca_dev, icx098bq_start_1,
ARRAY_SIZE(icx098bq_start_1),
5);
ucbus_write(gspca_dev, icx098bq_start_2,
ARRAY_SIZE(icx098bq_start_2),
6);
msleep(50);
send_start(gspca_dev);
gpio_set(sd, SQ930_GPIO_EXTRA2 | SQ930_GPIO_RSTBAR, 0x00ff);
msleep(70);
reg_w(gspca_dev, SQ930_CTRL_CAP_STOP, 0x0000);
gpio_set(sd, 0x7f, 0x00ff);
send_start(gspca_dev);
gpio_set(sd, SQ930_GPIO_EXTRA2 | SQ930_GPIO_RSTBAR, 0x00ff);
goto out;
case SENSOR_LZ24BP:
ucbus_write(gspca_dev, lz24bp_start_0,
ARRAY_SIZE(lz24bp_start_0),
8);
if (sd->type != Creative_live_motion)
ucbus_write(gspca_dev, lz24bp_start_1_gen,
ARRAY_SIZE(lz24bp_start_1_gen),
5);
else
ucbus_write(gspca_dev, lz24bp_start_1_clm,
ARRAY_SIZE(lz24bp_start_1_clm),
5);
ucbus_write(gspca_dev, lz24bp_start_2,
ARRAY_SIZE(lz24bp_start_2),
6);
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
lz24bp_ppl(sd, mode == 1 ? 0x0564 : 0x0310);
msleep(10);
break;
case SENSOR_MI0360:
ucbus_write(gspca_dev, mi0360_start_0,
ARRAY_SIZE(mi0360_start_0),
8);
i2c_write(sd, mi0360_init_23,
ARRAY_SIZE(mi0360_init_23));
i2c_write(sd, mi0360_init_24,
ARRAY_SIZE(mi0360_init_24));
i2c_write(sd, mi0360_init_25,
ARRAY_SIZE(mi0360_init_25));
ucbus_write(gspca_dev, mi0360_start_1,
ARRAY_SIZE(mi0360_start_1),
5);
i2c_write(sd, mi0360_start_2,
ARRAY_SIZE(mi0360_start_2));
i2c_write(sd, mi0360_start_3,
ARRAY_SIZE(mi0360_start_3));
send_start(gspca_dev);
msleep(60);
send_stop(gspca_dev);
i2c_write(sd,
mi0360_start_4, ARRAY_SIZE(mi0360_start_4));
break;
default:
ucbus_write(gspca_dev, mi0360_start_0,
ARRAY_SIZE(mi0360_start_0),
8);
i2c_write(sd, mt9v111_init_0,
ARRAY_SIZE(mt9v111_init_0));
i2c_write(sd, mt9v111_init_1,
ARRAY_SIZE(mt9v111_init_1));
i2c_write(sd, mt9v111_init_2,
ARRAY_SIZE(mt9v111_init_2));
ucbus_write(gspca_dev, mt9v111_start_1,
ARRAY_SIZE(mt9v111_start_1),
5);
i2c_write(sd, mt9v111_init_3,
ARRAY_SIZE(mt9v111_init_3));
i2c_write(sd, mt9v111_init_4,
ARRAY_SIZE(mt9v111_init_4));
break;
}
send_start(gspca_dev);
out:
msleep(1000);
if (sd->sensor == SENSOR_MT9V111)
gpio_set(sd, SQ930_GPIO_DFL_LED, SQ930_GPIO_DFL_LED);
sd->do_ctrl = 1;
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor == SENSOR_MT9V111)
gpio_set(sd, 0, SQ930_GPIO_DFL_LED);
send_stop(gspca_dev);
}
static void sd_dq_callback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret;
if (!sd->do_ctrl || gspca_dev->cam.bulk_nurbs != 0)
return;
sd->do_ctrl = 0;
setexposure(gspca_dev);
gspca_dev->cam.bulk_nurbs = 1;
ret = usb_submit_urb(gspca_dev->urb[0], GFP_ATOMIC);
if (ret < 0)
pr_err("sd_dq_callback() err %d\n", ret);
msleep(100);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->do_ctrl)
gspca_dev->cam.bulk_nurbs = 0;
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len - 8);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
sd->do_ctrl = 1;
return 0;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setexpo(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->expo = val;
if (gspca_dev->streaming)
sd->do_ctrl = 1;
return 0;
}
static int sd_getexpo(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->expo;
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
