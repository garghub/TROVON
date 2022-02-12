static void reg_r(struct gspca_dev *gspca_dev,
__u16 index,
__u16 length)
{
usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, length, 500);
}
static int reg_w(struct gspca_dev *gspca_dev,
__u16 req, __u16 index, __u16 value)
{
int ret;
PDEBUG(D_USBO, "reg write: [0x%02x] = 0x%02x", index, value);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
return ret;
}
static int reg_r_12(struct gspca_dev *gspca_dev,
__u16 req,
__u16 index,
__u16 length)
{
int ret;
gspca_dev->usb_buf[1] = 0;
ret = usb_control_msg(gspca_dev->dev,
usb_rcvctrlpipe(gspca_dev->dev, 0),
req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index,
gspca_dev->usb_buf, length,
500);
if (ret < 0) {
pr_err("reg_r_12 err %d\n", ret);
return ret;
}
return (gspca_dev->usb_buf[1] << 8) + gspca_dev->usb_buf[0];
}
static int reg_r_wait(struct gspca_dev *gspca_dev,
__u16 reg, __u16 index, __u16 value)
{
int ret, cnt = 20;
while (--cnt > 0) {
ret = reg_r_12(gspca_dev, reg, index, 1);
if (ret == value)
return 0;
msleep(50);
}
return -EIO;
}
static int write_vector(struct gspca_dev *gspca_dev,
const __u16 data[][3])
{
int ret, i = 0;
while (data[i][0] != 0 || data[i][1] != 0 || data[i][2] != 0) {
ret = reg_w(gspca_dev, data[i][0], data[i][2], data[i][1]);
if (ret < 0)
return ret;
i++;
}
return 0;
}
static int spca50x_setup_qtable(struct gspca_dev *gspca_dev,
unsigned int request,
unsigned int ybase,
unsigned int cbase,
const __u8 qtable[2][64])
{
int i, err;
for (i = 0; i < 64; i++) {
err = reg_w(gspca_dev, request, ybase + i, qtable[0][i]);
if (err < 0)
return err;
}
for (i = 0; i < 64; i++) {
err = reg_w(gspca_dev, request, cbase + i, qtable[1][i]);
if (err < 0)
return err;
}
return 0;
}
static void spca500_ping310(struct gspca_dev *gspca_dev)
{
reg_r(gspca_dev, 0x0d04, 2);
PDEBUG(D_STREAM, "ClickSmart310 ping 0x0d04 0x%02x 0x%02x",
gspca_dev->usb_buf[0], gspca_dev->usb_buf[1]);
}
static void spca500_clksmart310_init(struct gspca_dev *gspca_dev)
{
reg_r(gspca_dev, 0x0d05, 2);
PDEBUG(D_STREAM, "ClickSmart310 init 0x0d05 0x%02x 0x%02x",
gspca_dev->usb_buf[0], gspca_dev->usb_buf[1]);
reg_w(gspca_dev, 0x00, 0x8167, 0x5a);
spca500_ping310(gspca_dev);
reg_w(gspca_dev, 0x00, 0x8168, 0x22);
reg_w(gspca_dev, 0x00, 0x816a, 0xc0);
reg_w(gspca_dev, 0x00, 0x816b, 0x0b);
reg_w(gspca_dev, 0x00, 0x8169, 0x25);
reg_w(gspca_dev, 0x00, 0x8157, 0x5b);
reg_w(gspca_dev, 0x00, 0x8158, 0x5b);
reg_w(gspca_dev, 0x00, 0x813f, 0x03);
reg_w(gspca_dev, 0x00, 0x8151, 0x4a);
reg_w(gspca_dev, 0x00, 0x8153, 0x78);
reg_w(gspca_dev, 0x00, 0x0d01, 0x04);
reg_w(gspca_dev, 0x00, 0x0d02, 0x01);
reg_w(gspca_dev, 0x00, 0x8169, 0x25);
reg_w(gspca_dev, 0x00, 0x0d01, 0x02);
}
static void spca500_setmode(struct gspca_dev *gspca_dev,
__u8 xmult, __u8 ymult)
{
int mode;
reg_w(gspca_dev, 0, 0x8001, xmult);
reg_w(gspca_dev, 0, 0x8002, ymult);
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
reg_w(gspca_dev, 0, 0x8003, mode << 4);
}
static int spca500_full_reset(struct gspca_dev *gspca_dev)
{
int err;
err = reg_w(gspca_dev, 0xe0, 0x0001, 0x0000);
if (err < 0)
return err;
err = reg_r_wait(gspca_dev, 0x06, 0x0000, 0x0000);
if (err < 0)
return err;
err = reg_w(gspca_dev, 0xe0, 0x0000, 0x0000);
if (err < 0)
return err;
err = reg_r_wait(gspca_dev, 0x06, 0, 0);
if (err < 0) {
PDEBUG(D_ERR, "reg_r_wait() failed");
return err;
}
return 0;
}
static int spca500_synch310(struct gspca_dev *gspca_dev)
{
if (usb_set_interface(gspca_dev->dev, gspca_dev->iface, 0) < 0) {
PDEBUG(D_ERR, "Set packet size: set interface error");
goto error;
}
spca500_ping310(gspca_dev);
reg_r(gspca_dev, 0x0d00, 1);
PDEBUG(D_PACK, "ClickSmart310 sync alt: %d", gspca_dev->alt);
if (usb_set_interface(gspca_dev->dev,
gspca_dev->iface,
gspca_dev->alt) < 0) {
PDEBUG(D_ERR, "Set packet size: set interface error");
goto error;
}
return 0;
error:
return -EBUSY;
}
static void spca500_reinit(struct gspca_dev *gspca_dev)
{
int err;
__u8 Data;
reg_w(gspca_dev, 0x00, 0x0d01, 0x01);
reg_w(gspca_dev, 0x00, 0x0d03, 0x00);
reg_w(gspca_dev, 0x00, 0x0d02, 0x01);
reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
err = spca50x_setup_qtable(gspca_dev, 0x00, 0x8800, 0x8840,
qtable_pocketdv);
if (err < 0)
PDEBUG(D_ERR|D_STREAM, "spca50x_setup_qtable failed on init");
reg_w(gspca_dev, 0x00, 0x8880, 2);
reg_w(gspca_dev, 0x00, 0x800a, 0x00);
reg_w(gspca_dev, 0x00, 0x820f, 0x01);
reg_w(gspca_dev, 0x00, 0x870a, 0x04);
reg_w(gspca_dev, 0, 0x8003, 0x00);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
msleep(2000);
if (reg_r_wait(gspca_dev, 0, 0x8000, 0x44) != 0) {
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
sd->subtype = id->driver_info;
if (sd->subtype != LogitechClickSmart310) {
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
} else {
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
}
sd->brightness = BRIGHTNESS_DEF;
sd->contrast = CONTRAST_DEF;
sd->colors = COLOR_DEF;
sd->quality = QUALITY_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
PDEBUG(D_STREAM, "SPCA500 init");
if (sd->subtype == LogitechClickSmart310)
spca500_clksmart310_init(gspca_dev);
PDEBUG(D_STREAM, "SPCA500 init done");
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int err;
__u8 Data;
__u8 xmult, ymult;
jpeg_define(sd->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x22);
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
if (sd->subtype == LogitechClickSmart310) {
xmult = 0x16;
ymult = 0x12;
} else {
xmult = 0x28;
ymult = 0x1e;
}
reg_r(gspca_dev, 0x8a04, 1);
PDEBUG(D_STREAM, "Spca500 Sensor Address 0x%02x",
gspca_dev->usb_buf[0]);
PDEBUG(D_STREAM, "Spca500 curr_mode: %d Xmult: 0x%02x, Ymult: 0x%02x",
gspca_dev->curr_mode, xmult, ymult);
switch (sd->subtype) {
case LogitechClickSmart310:
spca500_setmode(gspca_dev, xmult, ymult);
reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
reg_w(gspca_dev, 0x00, 0x8880, 3);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800, 0x8840,
qtable_creative_pccam);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
reg_w(gspca_dev, 0x00, 0x870a, 0x04);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
msleep(500);
if (reg_r_wait(gspca_dev, 0, 0x8000, 0x44) != 0)
PDEBUG(D_ERR, "reg_r_wait() failed");
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
spca500_synch310(gspca_dev);
write_vector(gspca_dev, spca500_visual_defaults);
spca500_setmode(gspca_dev, xmult, ymult);
err = reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
if (err < 0)
PDEBUG(D_ERR, "failed to enable drop packet");
reg_w(gspca_dev, 0x00, 0x8880, 3);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800, 0x8840,
qtable_creative_pccam);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
reg_w(gspca_dev, 0x00, 0x870a, 0x04);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
if (reg_r_wait(gspca_dev, 0, 0x8000, 0x44) != 0)
PDEBUG(D_ERR, "reg_r_wait() failed");
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
break;
case CreativePCCam300:
case IntelPocketPCCamera:
err = spca500_full_reset(gspca_dev);
if (err < 0)
PDEBUG(D_ERR, "spca500_full_reset failed");
err = reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
if (err < 0)
PDEBUG(D_ERR, "failed to enable drop packet");
reg_w(gspca_dev, 0x00, 0x8880, 3);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800, 0x8840,
qtable_creative_pccam);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
spca500_setmode(gspca_dev, xmult, ymult);
reg_w(gspca_dev, 0x20, 0x0001, 0x0004);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
if (reg_r_wait(gspca_dev, 0, 0x8000, 0x44) != 0)
PDEBUG(D_ERR, "reg_r_wait() failed");
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
break;
case KodakEZ200:
err = spca500_full_reset(gspca_dev);
if (err < 0)
PDEBUG(D_ERR, "spca500_full_reset failed");
reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
reg_w(gspca_dev, 0x00, 0x8880, 0);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800, 0x8840,
qtable_kodak_ez200);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
spca500_setmode(gspca_dev, xmult, ymult);
reg_w(gspca_dev, 0x20, 0x0001, 0x0004);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
if (reg_r_wait(gspca_dev, 0, 0x8000, 0x44) != 0)
PDEBUG(D_ERR, "reg_r_wait() failed");
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
break;
case BenqDC1016:
case DLinkDSC350:
case AiptekPocketDV:
case Gsmartmini:
case MustekGsmart300:
case PalmPixDC85:
case Optimedia:
case ToptroIndus:
case AgfaCl20:
spca500_reinit(gspca_dev);
reg_w(gspca_dev, 0x00, 0x0d01, 0x01);
reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800, 0x8840, qtable_pocketdv);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
reg_w(gspca_dev, 0x00, 0x8880, 2);
reg_w(gspca_dev, 0x00, 0x800a, 0x00);
reg_w(gspca_dev, 0x00, 0x820f, 0x01);
reg_w(gspca_dev, 0x00, 0x870a, 0x04);
spca500_setmode(gspca_dev, xmult, ymult);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
reg_r_wait(gspca_dev, 0, 0x8000, 0x44);
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
break;
case LogitechTraveler:
case LogitechClickSmart510:
reg_w(gspca_dev, 0x02, 0x00, 0x00);
reg_w(gspca_dev, 0x00, 0x850a, 0x0001);
err = spca50x_setup_qtable(gspca_dev,
0x00, 0x8800,
0x8840, qtable_creative_pccam);
if (err < 0)
PDEBUG(D_ERR, "spca50x_setup_qtable failed");
reg_w(gspca_dev, 0x00, 0x8880, 3);
reg_w(gspca_dev, 0x00, 0x800a, 0x00);
reg_w(gspca_dev, 0x00, 0x870a, 0x04);
spca500_setmode(gspca_dev, xmult, ymult);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
reg_r_wait(gspca_dev, 0, 0x8000, 0x44);
reg_r(gspca_dev, 0x816b, 1);
Data = gspca_dev->usb_buf[0];
reg_w(gspca_dev, 0x00, 0x816b, Data);
write_vector(gspca_dev, Clicksmart510_defaults);
break;
}
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0, 0x8003, 0x00);
reg_w(gspca_dev, 0x00, 0x8000, 0x0004);
reg_r(gspca_dev, 0x8000, 1);
PDEBUG(D_STREAM, "stop SPCA500 done reg8000: 0x%2x",
gspca_dev->usb_buf[0]);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
static __u8 ffd9[] = {0xff, 0xd9};
if (data[0] == 0xff) {
if (data[1] != 0x01) {
return;
}
gspca_frame_add(gspca_dev, LAST_PACKET,
ffd9, 2);
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
data += SPCA500_OFFSET_DATA;
len -= SPCA500_OFFSET_DATA;
} else {
data += 1;
len -= 1;
}
i = 0;
do {
if (data[i] == 0xff) {
gspca_frame_add(gspca_dev, INTER_PACKET,
data, i + 1);
len -= i;
data += i;
*data = 0x00;
i = 0;
}
i++;
} while (i < len);
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0x00, 0x8167,
(__u8) (sd->brightness - 128));
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0x00, 0x8168, sd->contrast);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0x00, 0x8169, sd->colors);
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
return 0;
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
return 0;
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
static int sd_set_jcomp(struct gspca_dev *gspca_dev,
struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
if (jcomp->quality < QUALITY_MIN)
sd->quality = QUALITY_MIN;
else if (jcomp->quality > QUALITY_MAX)
sd->quality = QUALITY_MAX;
else
sd->quality = jcomp->quality;
if (gspca_dev->streaming)
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
return 0;
}
static int sd_get_jcomp(struct gspca_dev *gspca_dev,
struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
memset(jcomp, 0, sizeof *jcomp);
jcomp->quality = sd->quality;
jcomp->jpeg_markers = V4L2_JPEG_MARKER_DHT
| V4L2_JPEG_MARKER_DQT;
return 0;
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
