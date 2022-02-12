static u8 reg_r(struct gspca_dev *gspca_dev,
__u16 index)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return 0;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00,
index,
gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
err("reg_r err %d", ret);
gspca_dev->usb_err = ret;
return 0;
}
return gspca_dev->usb_buf[0];
}
static void reg_w(struct gspca_dev *gspca_dev,
__u16 index, __u16 value)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
NULL,
0,
500);
if (ret < 0) {
err("reg_w err %d", ret);
gspca_dev->usb_err = ret;
}
}
static void rcv_val(struct gspca_dev *gspca_dev,
int ads)
{
struct usb_device *dev = gspca_dev->dev;
int alen, ret;
reg_w(gspca_dev, 0x634, (ads >> 16) & 0xff);
reg_w(gspca_dev, 0x635, (ads >> 8) & 0xff);
reg_w(gspca_dev, 0x636, ads & 0xff);
reg_w(gspca_dev, 0x637, 0);
reg_w(gspca_dev, 0x638, 4);
reg_w(gspca_dev, 0x639, 0);
reg_w(gspca_dev, 0x63a, 0);
reg_w(gspca_dev, 0x63b, 0);
reg_w(gspca_dev, 0x630, 5);
if (gspca_dev->usb_err < 0)
return;
ret = usb_bulk_msg(dev,
usb_rcvbulkpipe(dev, 0x05),
gspca_dev->usb_buf,
4,
&alen,
500);
if (ret < 0) {
err("rcv_val err %d", ret);
gspca_dev->usb_err = ret;
}
}
static void snd_val(struct gspca_dev *gspca_dev,
int ads,
unsigned int val)
{
struct usb_device *dev = gspca_dev->dev;
int alen, ret;
__u8 seq = 0;
if (ads == 0x003f08) {
reg_r(gspca_dev, 0x0704);
seq = reg_r(gspca_dev, 0x0705);
reg_r(gspca_dev, 0x0650);
reg_w(gspca_dev, 0x654, seq);
} else {
reg_w(gspca_dev, 0x654, (ads >> 16) & 0xff);
}
reg_w(gspca_dev, 0x655, (ads >> 8) & 0xff);
reg_w(gspca_dev, 0x656, ads & 0xff);
reg_w(gspca_dev, 0x657, 0);
reg_w(gspca_dev, 0x658, 0x04);
reg_w(gspca_dev, 0x659, 0);
reg_w(gspca_dev, 0x65a, 0);
reg_w(gspca_dev, 0x65b, 0);
reg_w(gspca_dev, 0x650, 5);
if (gspca_dev->usb_err < 0)
return;
gspca_dev->usb_buf[0] = val >> 24;
gspca_dev->usb_buf[1] = val >> 16;
gspca_dev->usb_buf[2] = val >> 8;
gspca_dev->usb_buf[3] = val;
ret = usb_bulk_msg(dev,
usb_sndbulkpipe(dev, 6),
gspca_dev->usb_buf,
4,
&alen,
500);
if (ret < 0) {
err("snd_val err %d", ret);
gspca_dev->usb_err = ret;
} else {
if (ads == 0x003f08) {
seq += 4;
seq &= 0x3f;
reg_w(gspca_dev, 0x705, seq);
}
}
}
static void set_par(struct gspca_dev *gspca_dev,
int parval)
{
snd_val(gspca_dev, 0x003f08, parval);
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int parval;
parval = 0x06000000
+ (sd->ctrls[BRIGHTNESS].val << 16);
set_par(gspca_dev, parval);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int parval;
parval = 0x07000000
+ (sd->ctrls[CONTRAST].val << 16);
set_par(gspca_dev, parval);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int parval;
parval = 0x08000000
+ (sd->ctrls[COLORS].val << 16);
set_par(gspca_dev, parval);
}
static void setlightfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
set_par(gspca_dev, sd->ctrls[LIGHTFREQ].val == 1
? 0x33640000
: 0x33780000);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->cam.cam_mode = vga_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(vga_mode);
gspca_dev->cam.ctrls = sd->ctrls;
sd->quality = QUALITY_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
u8 ret;
usb_set_interface(gspca_dev->dev, gspca_dev->iface, 1);
ret = reg_r(gspca_dev, 0x0740);
if (gspca_dev->usb_err >= 0) {
if (ret != 0xff) {
err("init reg: 0x%02x", ret);
gspca_dev->usb_err = -EIO;
}
}
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int ret, value;
jpeg_define(sd->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x22);
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
usb_set_interface(gspca_dev->dev, gspca_dev->iface, 1);
set_par(gspca_dev, 0x10000000);
set_par(gspca_dev, 0x00000000);
set_par(gspca_dev, 0x8002e001);
set_par(gspca_dev, 0x14000000);
if (gspca_dev->width > 320)
value = 0x8002e001;
else
value = 0x4001f000;
set_par(gspca_dev, value);
ret = usb_set_interface(gspca_dev->dev,
gspca_dev->iface,
gspca_dev->alt);
if (ret < 0) {
err("set intf %d %d failed",
gspca_dev->iface, gspca_dev->alt);
gspca_dev->usb_err = ret;
goto out;
}
reg_r(gspca_dev, 0x0630);
rcv_val(gspca_dev, 0x000020);
reg_r(gspca_dev, 0x0650);
snd_val(gspca_dev, 0x000020, 0xffffffff);
reg_w(gspca_dev, 0x0620, 0);
reg_w(gspca_dev, 0x0630, 0);
reg_w(gspca_dev, 0x0640, 0);
reg_w(gspca_dev, 0x0650, 0);
reg_w(gspca_dev, 0x0660, 0);
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setcolors(gspca_dev);
set_par(gspca_dev, 0x09800000);
set_par(gspca_dev, 0x0a800000);
set_par(gspca_dev, 0x0b800000);
set_par(gspca_dev, 0x0d030000);
setlightfreq(gspca_dev);
set_par(gspca_dev, 0x01000000);
set_par(gspca_dev, 0x01000000);
if (gspca_dev->usb_err >= 0)
PDEBUG(D_STREAM, "camera started alt: 0x%02x",
gspca_dev->alt);
out:
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
set_par(gspca_dev, 0x02000000);
set_par(gspca_dev, 0x02000000);
usb_set_interface(dev, gspca_dev->iface, 1);
reg_r(gspca_dev, 0x0630);
rcv_val(gspca_dev, 0x000020);
reg_r(gspca_dev, 0x0650);
snd_val(gspca_dev, 0x000020, 0xffffffff);
reg_w(gspca_dev, 0x0620, 0);
reg_w(gspca_dev, 0x0630, 0);
reg_w(gspca_dev, 0x0640, 0);
reg_w(gspca_dev, 0x0650, 0);
reg_w(gspca_dev, 0x0660, 0);
PDEBUG(D_STREAM, "camera stopped");
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
static unsigned char ffd9[] = {0xff, 0xd9};
if (data[0] == 0xff && data[1] == 0xfe) {
gspca_frame_add(gspca_dev, LAST_PACKET,
ffd9, 2);
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
#define STKHDRSZ 12
data += STKHDRSZ;
len -= STKHDRSZ;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
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
}
return -EINVAL;
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
return gspca_dev->usb_err;
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
