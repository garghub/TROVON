static int gl860_build_control_table(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct ctrl *sd_ctrls;
int nCtrls = 0;
if (_MI1320_)
sd_ctrls = sd_ctrls_mi1320;
else if (_MI2020_)
sd_ctrls = sd_ctrls_mi2020;
else if (_OV2640_)
sd_ctrls = sd_ctrls_ov2640;
else if (_OV9655_)
sd_ctrls = sd_ctrls_ov9655;
else
return 0;
memset(sd_ctrls, 0, GL860_NCTRLS * sizeof(struct ctrl));
SET_MY_CTRL(V4L2_CID_BRIGHTNESS,
V4L2_CTRL_TYPE_INTEGER, "Brightness", brightness)
SET_MY_CTRL(V4L2_CID_SHARPNESS,
V4L2_CTRL_TYPE_INTEGER, "Sharpness", sharpness)
SET_MY_CTRL(V4L2_CID_CONTRAST,
V4L2_CTRL_TYPE_INTEGER, "Contrast", contrast)
SET_MY_CTRL(V4L2_CID_GAMMA,
V4L2_CTRL_TYPE_INTEGER, "Gamma", gamma)
SET_MY_CTRL(V4L2_CID_HUE,
V4L2_CTRL_TYPE_INTEGER, "Palette", hue)
SET_MY_CTRL(V4L2_CID_SATURATION,
V4L2_CTRL_TYPE_INTEGER, "Saturation", saturation)
SET_MY_CTRL(V4L2_CID_WHITE_BALANCE_TEMPERATURE,
V4L2_CTRL_TYPE_INTEGER, "White Bal.", whitebal)
SET_MY_CTRL(V4L2_CID_BACKLIGHT_COMPENSATION,
V4L2_CTRL_TYPE_INTEGER, "Backlight" , backlight)
SET_MY_CTRL(V4L2_CID_HFLIP,
V4L2_CTRL_TYPE_BOOLEAN, "Mirror", mirror)
SET_MY_CTRL(V4L2_CID_VFLIP,
V4L2_CTRL_TYPE_BOOLEAN, "Flip", flip)
SET_MY_CTRL(V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CTRL_TYPE_BOOLEAN, "AC power 50Hz", AC50Hz)
return nCtrls;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
u16 vendor_id, product_id;
vendor_id = id->idVendor;
product_id = id->idProduct;
sd->nbRightUp = 1;
sd->nbIm = -1;
sd->sensor = 0xff;
if (strcmp(sensor, "MI1320") == 0)
sd->sensor = ID_MI1320;
else if (strcmp(sensor, "OV2640") == 0)
sd->sensor = ID_OV2640;
else if (strcmp(sensor, "OV9655") == 0)
sd->sensor = ID_OV9655;
else if (strcmp(sensor, "MI2020") == 0)
sd->sensor = ID_MI2020;
if (gl860_guess_sensor(gspca_dev, vendor_id, product_id) == -1)
return -1;
cam = &gspca_dev->cam;
gspca_dev->nbalt = 4;
switch (sd->sensor) {
case ID_MI1320:
gspca_dev->sd_desc = &sd_desc_mi1320;
cam->cam_mode = mi1320_mode;
cam->nmodes = ARRAY_SIZE(mi1320_mode);
dev_init_settings = mi1320_init_settings;
break;
case ID_MI2020:
gspca_dev->sd_desc = &sd_desc_mi2020;
cam->cam_mode = mi2020_mode;
cam->nmodes = ARRAY_SIZE(mi2020_mode);
dev_init_settings = mi2020_init_settings;
break;
case ID_OV2640:
gspca_dev->sd_desc = &sd_desc_ov2640;
cam->cam_mode = ov2640_mode;
cam->nmodes = ARRAY_SIZE(ov2640_mode);
dev_init_settings = ov2640_init_settings;
break;
case ID_OV9655:
gspca_dev->sd_desc = &sd_desc_ov9655;
cam->cam_mode = ov9655_mode;
cam->nmodes = ARRAY_SIZE(ov9655_mode);
dev_init_settings = ov9655_init_settings;
break;
}
dev_init_settings(gspca_dev);
if (AC50Hz != 0xff)
((struct sd *) gspca_dev)->vcur.AC50Hz = AC50Hz;
gl860_build_control_table(gspca_dev);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return sd->dev_init_at_startup(gspca_dev);
}
static int sd_isoc_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return sd->dev_configure_alt(gspca_dev);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return sd->dev_init_pre_alt(gspca_dev);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
return sd->dev_post_unset_alt(gspca_dev);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
static s32 nSkipped;
s32 mode = (s32) gspca_dev->curr_mode;
s32 nToSkip =
sd->swapRB * (gspca_dev->cam.cam_mode[mode].bytesperline + 1);
switch (*(s16 *) data) {
case 0x0202:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
nSkipped = 0;
if (sd->nbIm >= 0 && sd->nbIm < 10)
sd->nbIm++;
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
break;
default:
data += 2;
len -= 2;
if (nSkipped + len <= nToSkip)
nSkipped += len;
else {
if (nSkipped < nToSkip && nSkipped + len > nToSkip) {
data += nToSkip - nSkipped;
len -= nToSkip - nSkipped;
nSkipped = nToSkip + 1;
}
gspca_frame_add(gspca_dev,
INTER_PACKET, data, len);
}
break;
}
}
static void sd_callback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!_OV9655_) {
u8 state;
u8 upsideDown;
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0000, 1, (void *)&state);
upsideDown = (state == 0xc8 || state == 0x40);
if (upsideDown && sd->nbRightUp > -4) {
if (sd->nbRightUp > 0)
sd->nbRightUp = 0;
if (sd->nbRightUp == -3) {
sd->mirrorMask = 1;
sd->waitSet = 1;
}
sd->nbRightUp--;
}
if (!upsideDown && sd->nbRightUp < 4) {
if (sd->nbRightUp < 0)
sd->nbRightUp = 0;
if (sd->nbRightUp == 3) {
sd->mirrorMask = 0;
sd->waitSet = 1;
}
sd->nbRightUp++;
}
}
if (sd->waitSet)
sd->dev_camera_settings(gspca_dev);
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
&sd_desc_mi1320, sizeof(struct sd), THIS_MODULE);
}
static void sd_disconnect(struct usb_interface *intf)
{
gspca_disconnect(intf);
}
static int __init sd_mod_init(void)
{
PDEBUG(D_PROBE, "driver startup - version %s", DRIVER_VERSION);
if (usb_register(&sd_driver) < 0)
return -1;
return 0;
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
int gl860_RTx(struct gspca_dev *gspca_dev,
unsigned char pref, u32 req, u16 val, u16 index,
s32 len, void *pdata)
{
struct usb_device *udev = gspca_dev->dev;
s32 r = 0;
if (pref == 0x40) {
if (len > 0) {
memcpy(gspca_dev->usb_buf, pdata, len);
r = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
req, pref, val, index,
gspca_dev->usb_buf,
len, 400 + 200 * (len > 1));
} else {
r = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
req, pref, val, index, NULL, len, 400);
}
} else {
if (len > 0) {
r = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
req, pref, val, index,
gspca_dev->usb_buf,
len, 400 + 200 * (len > 1));
memcpy(pdata, gspca_dev->usb_buf, len);
} else {
r = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
req, pref, val, index, NULL, len, 400);
}
}
if (r < 0)
pr_err("ctrl transfer failed %4d [p%02x r%d v%04x i%04x len%d]\n",
r, pref, req, val, index, len);
else if (len > 1 && r < len)
PDEBUG(D_ERR, "short ctrl transfer %d/%d", r, len);
msleep(1);
return r;
}
int fetch_validx(struct gspca_dev *gspca_dev, struct validx *tbl, int len)
{
int n;
for (n = 0; n < len; n++) {
if (tbl[n].idx != 0xffff)
ctrl_out(gspca_dev, 0x40, 1, tbl[n].val,
tbl[n].idx, 0, NULL);
else if (tbl[n].val == 0xffff)
break;
else
msleep(tbl[n].val);
}
return n;
}
int keep_on_fetching_validx(struct gspca_dev *gspca_dev, struct validx *tbl,
int len, int n)
{
while (++n < len) {
if (tbl[n].idx != 0xffff)
ctrl_out(gspca_dev, 0x40, 1, tbl[n].val, tbl[n].idx,
0, NULL);
else if (tbl[n].val == 0xffff)
break;
else
msleep(tbl[n].val);
}
return n;
}
void fetch_idxdata(struct gspca_dev *gspca_dev, struct idxdata *tbl, int len)
{
int n;
for (n = 0; n < len; n++) {
if (memcmp(tbl[n].data, "\xff\xff\xff", 3) != 0)
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, tbl[n].idx,
3, tbl[n].data);
else
msleep(tbl[n].idx);
}
}
static int gl860_guess_sensor(struct gspca_dev *gspca_dev,
u16 vendor_id, u16 product_id)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 probe, nb26, nb96, nOV, ntry;
if (product_id == 0xf191)
sd->sensor = ID_MI1320;
if (sd->sensor == 0xff) {
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0004, 1, &probe);
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0004, 1, &probe);
ctrl_out(gspca_dev, 0x40, 1, 0x0000, 0x0000, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0010, 0x0010, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0008, 0x00c0, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0001, 0x00c1, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0001, 0x00c2, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0020, 0x0006, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x006a, 0x000d, 0, NULL);
msleep(56);
PDEBUG(D_PROBE, "probing for sensor MI2020 or OVXXXX");
nOV = 0;
for (ntry = 0; ntry < 4; ntry++) {
ctrl_out(gspca_dev, 0x40, 1, 0x0040, 0x0000, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x0063, 0x0006, 0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x7a00, 0x8030, 0, NULL);
msleep(10);
ctrl_in(gspca_dev, 0xc0, 2, 0x7a00, 0x8030, 1, &probe);
PDEBUG(D_PROBE, "probe=0x%02x", probe);
if (probe == 0xff)
nOV++;
}
if (nOV) {
PDEBUG(D_PROBE, "0xff -> OVXXXX");
PDEBUG(D_PROBE, "probing for sensor OV2640 or OV9655");
nb26 = nb96 = 0;
for (ntry = 0; ntry < 4; ntry++) {
ctrl_out(gspca_dev, 0x40, 1, 0x0040, 0x0000,
0, NULL);
msleep(3);
ctrl_out(gspca_dev, 0x40, 1, 0x6000, 0x800a,
0, NULL);
msleep(10);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x800a,
1, &probe);
if (probe == 0x26 || probe == 0x40) {
PDEBUG(D_PROBE,
"probe=0x%02x -> OV2640",
probe);
sd->sensor = ID_OV2640;
nb26 += 4;
break;
}
if (probe == 0x96 || probe == 0x55) {
PDEBUG(D_PROBE,
"probe=0x%02x -> OV9655",
probe);
sd->sensor = ID_OV9655;
nb96 += 4;
break;
}
PDEBUG(D_PROBE, "probe=0x%02x", probe);
if (probe == 0x00)
nb26++;
if (probe == 0xff)
nb96++;
msleep(3);
}
if (nb26 < 4 && nb96 < 4)
return -1;
} else {
PDEBUG(D_PROBE, "Not any 0xff -> MI2020");
sd->sensor = ID_MI2020;
}
}
if (_MI1320_) {
PDEBUG(D_PROBE, "05e3:f191 sensor MI1320 (1.3M)");
} else if (_MI2020_) {
PDEBUG(D_PROBE, "05e3:0503 sensor MI2020 (2.0M)");
} else if (_OV9655_) {
PDEBUG(D_PROBE, "05e3:0503 sensor OV9655 (1.3M)");
} else if (_OV2640_) {
PDEBUG(D_PROBE, "05e3:0503 sensor OV2640 (2.0M)");
} else {
PDEBUG(D_PROBE, "***** Unknown sensor *****");
return -1;
}
return 0;
}
