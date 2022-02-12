static int pac207_write_regs(struct gspca_dev *gspca_dev, u16 index,
const u8 *buffer, u16 length)
{
struct usb_device *udev = gspca_dev->dev;
int err;
memcpy(gspca_dev->usb_buf, buffer, length);
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x00, index,
gspca_dev->usb_buf, length, PAC207_CTRL_TIMEOUT);
if (err < 0)
pr_err("Failed to write registers to index 0x%04X, error %d\n",
index, err);
return err;
}
static int pac207_write_reg(struct gspca_dev *gspca_dev, u16 index, u16 value)
{
struct usb_device *udev = gspca_dev->dev;
int err;
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x00,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, index, NULL, 0, PAC207_CTRL_TIMEOUT);
if (err)
pr_err("Failed to write a register (index 0x%04X, value 0x%02X, error %d)\n",
index, value, err);
return err;
}
static int pac207_read_reg(struct gspca_dev *gspca_dev, u16 index)
{
struct usb_device *udev = gspca_dev->dev;
int res;
res = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
0x00, index,
gspca_dev->usb_buf, 1, PAC207_CTRL_TIMEOUT);
if (res < 0) {
pr_err("Failed to read a register (index 0x%04X, error %d)\n",
index, res);
return res;
}
return gspca_dev->usb_buf[0];
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
u8 idreg[2];
idreg[0] = pac207_read_reg(gspca_dev, 0x0000);
idreg[1] = pac207_read_reg(gspca_dev, 0x0001);
idreg[0] = ((idreg[0] & 0x0f) << 4) | ((idreg[1] & 0xf0) >> 4);
idreg[1] = idreg[1] & 0x0f;
PDEBUG(D_PROBE, "Pixart Sensor ID 0x%02X Chips ID 0x%02X",
idreg[0], idreg[1]);
if (idreg[0] != 0x27) {
PDEBUG(D_PROBE, "Error invalid sensor ID!");
return -ENODEV;
}
PDEBUG(D_PROBE,
"Pixart PAC207BCA Image Processor and Control Chip detected"
" (vid/pid 0x%04X:0x%04X)", id->idVendor, id->idProduct);
cam = &gspca_dev->cam;
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
sd->brightness = PAC207_BRIGHTNESS_DEFAULT;
sd->exposure = PAC207_EXPOSURE_DEFAULT;
sd->gain = PAC207_GAIN_DEFAULT;
sd->autogain = AUTOGAIN_DEF;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
pac207_write_reg(gspca_dev, 0x41, 0x00);
pac207_write_reg(gspca_dev, 0x0f, 0x00);
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 mode;
pac207_write_reg(gspca_dev, 0x0f, 0x10);
pac207_write_regs(gspca_dev, 0x0002, pac207_sensor_init[0], 8);
pac207_write_regs(gspca_dev, 0x000a, pac207_sensor_init[1], 8);
pac207_write_regs(gspca_dev, 0x0012, pac207_sensor_init[2], 8);
pac207_write_regs(gspca_dev, 0x0042, pac207_sensor_init[3], 8);
if (gspca_dev->width == 176)
pac207_write_reg(gspca_dev, 0x4a, 0xff);
else
pac207_write_reg(gspca_dev, 0x4a, 0x30);
pac207_write_reg(gspca_dev, 0x4b, 0x00);
pac207_write_reg(gspca_dev, 0x08, sd->brightness);
pac207_write_reg(gspca_dev, 0x0e, sd->gain);
pac207_write_reg(gspca_dev, 0x02, sd->exposure);
mode = 0x02;
if (gspca_dev->width == 176) {
mode |= 0x01;
PDEBUG(D_STREAM, "pac207_start mode 176x144");
} else {
PDEBUG(D_STREAM, "pac207_start mode 352x288");
}
pac207_write_reg(gspca_dev, 0x41, mode);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
msleep(10);
pac207_write_reg(gspca_dev, 0x40, 0x01);
sd->sof_read = 0;
sd->autogain_ignore_frames = 0;
atomic_set(&sd->avg_lum, -1);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
pac207_write_reg(gspca_dev, 0x40, 0x00);
pac207_write_reg(gspca_dev, 0x41, 0x00);
pac207_write_reg(gspca_dev, 0x0f, 0x00);
}
static void pac207_do_auto_gain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum = atomic_read(&sd->avg_lum);
if (avg_lum == -1)
return;
if (sd->autogain_ignore_frames > 0)
sd->autogain_ignore_frames--;
else if (gspca_auto_gain_n_exposure(gspca_dev, avg_lum,
100, PAC207_AUTOGAIN_DEADZONE,
PAC207_GAIN_KNEE, PAC207_EXPOSURE_KNEE))
sd->autogain_ignore_frames = PAC_AUTOGAIN_IGNORE_FRAMES;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned char *sof;
sof = pac_find_sof(&sd->sof_read, data, len);
if (sof) {
int n;
n = sof - data;
if (n > sizeof pac_sof_marker)
n -= sizeof pac_sof_marker;
else
n = 0;
gspca_frame_add(gspca_dev, LAST_PACKET,
data, n);
sd->header_read = 0;
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
len -= sof - data;
data = sof;
}
if (sd->header_read < 11) {
int needed;
if (sd->header_read < 5) {
needed = 5 - sd->header_read;
if (len >= needed)
atomic_set(&sd->avg_lum, data[needed - 1]);
}
needed = 11 - sd->header_read;
if (len <= needed) {
sd->header_read += len;
return;
}
data += needed;
len -= needed;
sd->header_read = 11;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
pac207_write_reg(gspca_dev, 0x08, sd->brightness);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
pac207_write_reg(gspca_dev, 0x02, sd->exposure);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
pac207_write_reg(gspca_dev, 0x0e, sd->gain);
pac207_write_reg(gspca_dev, 0x13, 0x01);
pac207_write_reg(gspca_dev, 0x1c, 0x01);
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
static int sd_setexposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return 0;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
setgain(gspca_dev);
return 0;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->autogain = val;
if (sd->autogain) {
sd->exposure = PAC207_EXPOSURE_DEFAULT;
sd->gain = PAC207_GAIN_DEFAULT;
if (gspca_dev->streaming) {
sd->autogain_ignore_frames =
PAC_AUTOGAIN_IGNORE_FRAMES;
setexposure(gspca_dev);
setgain(gspca_dev);
}
}
return 0;
}
static int sd_getautogain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->autogain;
return 0;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
if (len == 2 && data[0] == 0x5a && data[1] == 0x5a) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
return ret;
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
