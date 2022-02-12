static void reg_w(struct gspca_dev *gspca_dev,
u16 index,
const u8 *data,
int len)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
if (len == 1)
PDEBUG(D_USBO, "SET 00 0000 %04x %02x", index, *data);
else
PDEBUG(D_USBO, "SET 00 0000 %04x %02x %02x ...",
index, *data, data[1]);
memcpy(gspca_dev->usb_buf, data, len);
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x00,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00,
index,
gspca_dev->usb_buf,
len,
500);
if (ret < 0) {
pr_err("reg_w err %d\n", ret);
gspca_dev->usb_err = ret;
}
}
static void reg_r(struct gspca_dev *gspca_dev,
u16 index,
int len)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00, index,
gspca_dev->usb_buf, len, 500);
if (ret < 0) {
pr_err("reg_r err %d\n", ret);
gspca_dev->usb_err = ret;
return;
}
if (len == 1)
PDEBUG(D_USBI, "GET 00 0000 %04x %02x",
index, gspca_dev->usb_buf[0]);
else
PDEBUG(D_USBI, "GET 00 0000 %04x %02x %02x ..",
index, gspca_dev->usb_buf[0],
gspca_dev->usb_buf[1]);
}
static void i2c_w(struct gspca_dev *gspca_dev,
u8 i2c_addr,
const u8 *data,
int len)
{
u8 val[2];
int i;
reg_w(gspca_dev, 0x0600, data + 1, len - 1);
reg_w(gspca_dev, 0x0600, data, len);
val[0] = len;
val[1] = i2c_addr;
reg_w(gspca_dev, 0x0502, val, 2);
val[0] = 0x01;
reg_w(gspca_dev, 0x0501, val, 1);
for (i = 5; --i >= 0; ) {
msleep(4);
reg_r(gspca_dev, 0x0505, 1);
if (gspca_dev->usb_err < 0)
return;
if (gspca_dev->usb_buf[0] == 0)
return;
}
gspca_dev->usb_err = -ETIME;
}
static void reg_w_buf(struct gspca_dev *gspca_dev,
const u8 *cmd)
{
u16 reg;
int len;
for (;;) {
reg = *cmd++ << 8;
reg += *cmd++;
len = *cmd++;
if (len == 0)
break;
if (cmd[-3] != I2C0)
reg_w(gspca_dev, reg, cmd, len);
else
i2c_w(gspca_dev, reg, cmd, len);
cmd += len;
}
}
static int swap_bits(int v)
{
int r, i;
r = 0;
for (i = 0; i < 8; i++) {
r <<= 1;
if (v & 1)
r++;
v >>= 1;
}
return r;
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val, v[2];
val = sd->ctrls[GAIN].val;
switch (sd->webcam) {
case P35u:
val >>= 1;
reg_w(gspca_dev, 0x1026, &val, 1);
break;
case Kr651us:
val = swap_bits(val);
v[0] = val << 3;
v[1] = val >> 5;
reg_w(gspca_dev, 0x101d, v, 2);
break;
}
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
s16 val;
u8 v[2];
val = sd->ctrls[EXPOSURE].val;
switch (sd->webcam) {
case P35u:
v[0] = ((9 - val) << 3) | 0x01;
reg_w(gspca_dev, 0x1019, v, 1);
break;
case Cvideopro:
case DvcV6:
case Kritter:
case Kr651us:
v[0] = val;
v[1] = val >> 8;
reg_w(gspca_dev, 0x101b, v, 2);
break;
}
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int w, h;
if (gspca_dev->ctrl_dis & (1 << AUTOGAIN))
return;
if (!sd->ctrls[AUTOGAIN].val) {
sd->ag_cnt = -1;
return;
}
sd->ag_cnt = AG_CNT_START;
reg_r(gspca_dev, 0x1004, 1);
if (gspca_dev->usb_buf[0] & 0x04) {
sd->ae_res = gspca_dev->width * gspca_dev->height;
} else {
reg_r(gspca_dev, 0x1011, 8);
w = (gspca_dev->usb_buf[1] << 8) + gspca_dev->usb_buf[0]
- (gspca_dev->usb_buf[3] << 8) - gspca_dev->usb_buf[2];
h = (gspca_dev->usb_buf[5] << 8) + gspca_dev->usb_buf[4]
- (gspca_dev->usb_buf[7] << 8) - gspca_dev->usb_buf[6];
sd->ae_res = h * w;
if (sd->ae_res == 0)
sd->ae_res = gspca_dev->width * gspca_dev->height;
}
}
static int nw802_test_reg(struct gspca_dev *gspca_dev,
u16 index,
u8 value)
{
reg_w(gspca_dev, index, &value, 1);
reg_r(gspca_dev, index, 1);
return gspca_dev->usb_buf[0] == value;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
if ((unsigned) webcam >= NWEBCAMS)
webcam = 0;
sd->webcam = webcam;
gspca_dev->cam.reverse_alts = 1;
gspca_dev->cam.ctrls = sd->ctrls;
sd->ag_cnt = -1;
if (!nw802_test_reg(gspca_dev, 0x0500, 0x55)) {
sd->bridge = BRIDGE_NW802;
if (sd->webcam == Generic800)
sd->webcam = Generic802;
} else if (!nw802_test_reg(gspca_dev, 0x109b, 0xaa)) {
sd->bridge = BRIDGE_NW801;
if (sd->webcam == Generic800)
sd->webcam = P35u;
} else if (id->idVendor == 0x06a5 && id->idProduct == 0xd800) {
reg_r(gspca_dev, 0x0403, 1);
PDEBUG(D_PROBE, "et31x110 sensor type %02x",
gspca_dev->usb_buf[0]);
switch (gspca_dev->usb_buf[0] >> 1) {
case 0x00:
if (sd->webcam == Generic800)
sd->webcam = SpaceCam;
break;
case 0x01:
if (sd->webcam == Generic800)
sd->webcam = Twinkle;
break;
case 0x0a:
if (sd->webcam == Generic800)
sd->webcam = SpaceCam2;
break;
}
}
if (webcam_chip[sd->webcam] != sd->bridge) {
pr_err("Bad webcam type %d for NW80%d\n",
sd->webcam, sd->bridge);
gspca_dev->usb_err = -ENODEV;
return gspca_dev->usb_err;
}
PDEBUG(D_PROBE, "Bridge nw80%d - type: %d", sd->bridge, sd->webcam);
if (sd->bridge == BRIDGE_NW800) {
switch (sd->webcam) {
case DS3303u:
gspca_dev->cam.cam_mode = cif_mode;
break;
default:
gspca_dev->cam.cam_mode = &cif_mode[1];
break;
}
gspca_dev->cam.nmodes = 1;
} else {
gspca_dev->cam.cam_mode = vga_mode;
switch (sd->webcam) {
case Kr651us:
case Proscope:
case P35u:
gspca_dev->cam.nmodes = ARRAY_SIZE(vga_mode);
break;
default:
gspca_dev->cam.nmodes = 1;
break;
}
}
switch (sd->webcam) {
case P35u:
sd->ctrls[GAIN].def = 255 / 5 * 2;
break;
case Cvideopro:
case DvcV6:
case Kritter:
gspca_dev->ctrl_dis = (1 << GAIN) | (1 << AUTOGAIN);
case Kr651us:
sd->ctrls[EXPOSURE].max = 315;
sd->ctrls[EXPOSURE].def = 150;
break;
default:
gspca_dev->ctrl_dis = (1 << GAIN) | (1 << EXPOSURE)
| (1 << AUTOGAIN);
break;
}
#if AUTOGAIN_DEF
if (!(gspca_dev->ctrl_dis & (1 << AUTOGAIN)))
gspca_dev->ctrl_inac = (1 << GAIN) | (1 << EXPOSURE);
#endif
return gspca_dev->usb_err;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->bridge) {
case BRIDGE_NW800:
switch (sd->webcam) {
case SpaceCam:
reg_w_buf(gspca_dev, spacecam_init);
break;
default:
reg_w_buf(gspca_dev, nw800_init);
break;
}
break;
default:
switch (sd->webcam) {
case Mustek300:
case P35u:
case Proscope:
reg_w_buf(gspca_dev, proscope_init);
break;
}
break;
}
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
const u8 *cmd;
cmd = webcam_start[sd->webcam];
reg_w_buf(gspca_dev, cmd);
switch (sd->webcam) {
case P35u:
if (gspca_dev->width == 320)
reg_w_buf(gspca_dev, nw801_start_qvga);
else
reg_w_buf(gspca_dev, nw801_start_vga);
reg_w_buf(gspca_dev, nw801_start_2);
break;
case Kr651us:
if (gspca_dev->width == 320)
reg_w_buf(gspca_dev, kr651_start_qvga);
else
reg_w_buf(gspca_dev, kr651_start_vga);
reg_w_buf(gspca_dev, kr651_start_2);
break;
case Proscope:
if (gspca_dev->width == 320)
reg_w_buf(gspca_dev, proscope_start_qvga);
else
reg_w_buf(gspca_dev, proscope_start_vga);
reg_w_buf(gspca_dev, proscope_start_2);
break;
}
setgain(gspca_dev);
setexposure(gspca_dev);
setautogain(gspca_dev);
sd->exp_too_high_cnt = 0;
sd->exp_too_low_cnt = 0;
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 value;
if (sd->bridge != BRIDGE_NW801) {
value = 0x02;
reg_w(gspca_dev, 0x0406, &value, 1);
}
switch (sd->webcam) {
case Cvideopro:
case Kr651us:
case DvcV6:
case Kritter:
value = 0xff;
break;
case Dlink350c:
value = 0x21;
break;
case SpaceCam:
case SpaceCam2:
case Proscope:
case Twinkle:
value = 0x01;
break;
default:
return;
}
reg_w(gspca_dev, 0x0404, &value, 1);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
if (data[0] == 0x00 && data[1] == 0x00
&& data[6] == 0xff && data[7] == 0xff) {
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
gspca_frame_add(gspca_dev, FIRST_PACKET, data + 8, len - 8);
} else {
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
}
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->ctrls[AUTOGAIN].val = val;
if (val)
gspca_dev->ctrl_inac = (1 << GAIN) | (1 << EXPOSURE);
else
gspca_dev->ctrl_inac = 0;
if (gspca_dev->streaming)
setautogain(gspca_dev);
return gspca_dev->usb_err;
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int luma;
if (sd->ag_cnt < 0)
return;
if (--sd->ag_cnt >= 0)
return;
sd->ag_cnt = AG_CNT_START;
reg_r(gspca_dev, sd->bridge == BRIDGE_NW801 ? 0x080d : 0x080c, 4);
luma = (gspca_dev->usb_buf[3] << 24) + (gspca_dev->usb_buf[2] << 16)
+ (gspca_dev->usb_buf[1] << 8) + gspca_dev->usb_buf[0];
luma /= sd->ae_res;
switch (sd->webcam) {
case P35u:
coarse_grained_expo_autogain(gspca_dev, luma, 100, 5);
break;
default:
auto_gain_n_exposure(gspca_dev, luma, 100, 5, 230, 0);
break;
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
