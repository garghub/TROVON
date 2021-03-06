static void reg_w_buf(struct gspca_dev *gspca_dev,
__u8 index,
const u8 *buffer, int len)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
memcpy(gspca_dev->usb_buf, buffer, len);
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, len,
500);
if (ret < 0) {
pr_err("reg_w_buf() failed index 0x%02x, error %d\n",
index, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w(struct gspca_dev *gspca_dev,
__u8 index,
__u8 value)
{
int ret;
if (gspca_dev->usb_err < 0)
return;
gspca_dev->usb_buf[0] = value;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, index, gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w() failed index 0x%02x, value 0x%02x, error %d\n",
index, value, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w_seq(struct gspca_dev *gspca_dev,
const __u8 *seq, int len)
{
while (--len >= 0) {
reg_w(gspca_dev, seq[0], seq[1]);
seq += 2;
}
}
static void reg_w_page(struct gspca_dev *gspca_dev,
const __u8 *page, int len)
{
int index;
int ret = 0;
if (gspca_dev->usb_err < 0)
return;
for (index = 0; index < len; index++) {
if (page[index] == SKIP)
continue;
gspca_dev->usb_buf[0] = page[index];
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, index, gspca_dev->usb_buf, 1,
500);
if (ret < 0) {
pr_err("reg_w_page() failed index 0x%02x, value 0x%02x, error %d\n",
index, page[index], ret);
gspca_dev->usb_err = ret;
break;
}
}
}
static void reg_w_var(struct gspca_dev *gspca_dev,
const __u8 *seq,
const __u8 *page4, unsigned int page4_len)
{
int index, len;
for (;;) {
index = *seq++;
len = *seq++;
switch (len) {
case END_OF_SEQUENCE:
return;
case LOAD_PAGE4:
reg_w_page(gspca_dev, page4, page4_len);
break;
default:
if (len > USB_BUF_SZ) {
PDEBUG(D_ERR|D_STREAM,
"Incorrect variable sequence");
return;
}
while (len > 0) {
if (len < 8) {
reg_w_buf(gspca_dev,
index, seq, len);
seq += len;
break;
}
reg_w_buf(gspca_dev, index, seq, 8);
seq += 8;
index += 8;
len -= 8;
}
}
}
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
PDEBUG(D_CONF, "Find Sensor PAC7311");
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
sd->contrast = CONTRAST_DEF;
sd->gain = GAIN_DEF;
sd->exposure = EXPOSURE_DEF;
sd->autogain = AUTOGAIN_DEF;
sd->hflip = HFLIP_DEF;
sd->vflip = VFLIP_DEF;
return 0;
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, 0xff, 0x04);
reg_w(gspca_dev, 0x10, sd->contrast >> 4);
reg_w(gspca_dev, 0x11, 0x01);
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int gain = GAIN_MAX - sd->gain;
if (gain < 1)
gain = 1;
else if (gain > 245)
gain = 245;
reg_w(gspca_dev, 0xff, 0x04);
reg_w(gspca_dev, 0x0e, 0x00);
reg_w(gspca_dev, 0x0f, gain);
reg_w(gspca_dev, 0x11, 0x01);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 reg;
reg = 120 * sd->exposure / 1000;
if (reg < 2)
reg = 2;
else if (reg > 63)
reg = 63;
reg_w(gspca_dev, 0xff, 0x04);
reg_w(gspca_dev, 0x02, reg);
reg_w(gspca_dev, 0xff, 0x01);
if (gspca_dev->cam.cam_mode[(int)gspca_dev->curr_mode].priv &&
reg <= 3) {
reg_w(gspca_dev, 0x08, 0x09);
} else {
reg_w(gspca_dev, 0x08, 0x08);
}
reg_w(gspca_dev, 0x11, 0x01);
}
static void sethvflip(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 data;
reg_w(gspca_dev, 0xff, 0x04);
data = (sd->hflip ? 0x04 : 0x00) | (sd->vflip ? 0x08 : 0x00);
reg_w(gspca_dev, 0x21, data);
reg_w(gspca_dev, 0x11, 0x01);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
reg_w_seq(gspca_dev, init_7311, sizeof(init_7311)/2);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->sof_read = 0;
reg_w_var(gspca_dev, start_7311,
page4_7311, sizeof(page4_7311));
setcontrast(gspca_dev);
setgain(gspca_dev);
setexposure(gspca_dev);
sethvflip(gspca_dev);
switch (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
case 2:
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x17, 0x20);
reg_w(gspca_dev, 0x87, 0x10);
break;
case 1:
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x17, 0x30);
reg_w(gspca_dev, 0x87, 0x11);
break;
case 0:
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x17, 0x00);
reg_w(gspca_dev, 0x87, 0x12);
break;
}
sd->sof_read = 0;
sd->autogain_ignore_frames = 0;
atomic_set(&sd->avg_lum, -1);
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x78, 0x05);
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, 0xff, 0x04);
reg_w(gspca_dev, 0x27, 0x80);
reg_w(gspca_dev, 0x28, 0xca);
reg_w(gspca_dev, 0x29, 0x53);
reg_w(gspca_dev, 0x2a, 0x0e);
reg_w(gspca_dev, 0xff, 0x01);
reg_w(gspca_dev, 0x3e, 0x20);
reg_w(gspca_dev, 0x78, 0x44);
reg_w(gspca_dev, 0x78, 0x44);
reg_w(gspca_dev, 0x78, 0x44);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
}
static void do_autogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int avg_lum = atomic_read(&sd->avg_lum);
int desired_lum, deadzone;
if (avg_lum == -1)
return;
desired_lum = 200;
deadzone = 20;
if (sd->autogain_ignore_frames > 0)
sd->autogain_ignore_frames--;
else if (gspca_auto_gain_n_exposure(gspca_dev, avg_lum, desired_lum,
deadzone, GAIN_KNEE, EXPOSURE_KNEE))
sd->autogain_ignore_frames = PAC_AUTOGAIN_IGNORE_FRAMES;
}
static void pac_start_frame(struct gspca_dev *gspca_dev,
__u16 lines, __u16 samples_per_line)
{
unsigned char tmpbuf[4];
gspca_frame_add(gspca_dev, FIRST_PACKET,
pac_jpeg_header1, sizeof(pac_jpeg_header1));
tmpbuf[0] = lines >> 8;
tmpbuf[1] = lines & 0xff;
tmpbuf[2] = samples_per_line >> 8;
tmpbuf[3] = samples_per_line & 0xff;
gspca_frame_add(gspca_dev, INTER_PACKET,
tmpbuf, sizeof(tmpbuf));
gspca_frame_add(gspca_dev, INTER_PACKET,
pac_jpeg_header2, sizeof(pac_jpeg_header2));
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 *image;
unsigned char *sof;
sof = pac_find_sof(&sd->sof_read, data, len);
if (sof) {
int n, lum_offset, footer_length;
lum_offset = 24 + sizeof pac_sof_marker;
footer_length = 26;
n = (sof - data) - (footer_length + sizeof pac_sof_marker);
if (n < 0) {
gspca_dev->image_len += n;
n = 0;
} else {
gspca_frame_add(gspca_dev, INTER_PACKET, data, n);
}
image = gspca_dev->image;
if (image != NULL
&& image[gspca_dev->image_len - 2] == 0xff
&& image[gspca_dev->image_len - 1] == 0xd9)
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
n = sof - data;
len -= n;
data = sof;
if (gspca_dev->last_packet_type == LAST_PACKET &&
n >= lum_offset)
atomic_set(&sd->avg_lum, data[-lum_offset] +
data[-lum_offset + 1]);
else
atomic_set(&sd->avg_lum, -1);
pac_start_frame(gspca_dev,
gspca_dev->height, gspca_dev->width);
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
setcontrast(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
setgain(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setexposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setautogain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->autogain = val;
if (sd->autogain) {
sd->exposure = EXPOSURE_DEF;
sd->gain = GAIN_DEF;
if (gspca_dev->streaming) {
sd->autogain_ignore_frames =
PAC_AUTOGAIN_IGNORE_FRAMES;
setexposure(gspca_dev);
setgain(gspca_dev);
}
}
return gspca_dev->usb_err;
}
static int sd_getautogain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->autogain;
return 0;
}
static int sd_sethflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->hflip = val;
if (gspca_dev->streaming)
sethvflip(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_gethflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->hflip;
return 0;
}
static int sd_setvflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vflip = val;
if (gspca_dev->streaming)
sethvflip(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_getvflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->vflip;
return 0;
}
static int sd_int_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
int ret = -EINVAL;
u8 data0, data1;
if (len == 2) {
data0 = data[0];
data1 = data[1];
if ((data0 == 0x00 && data1 == 0x11) ||
(data0 == 0x22 && data1 == 0x33) ||
(data0 == 0x44 && data1 == 0x55) ||
(data0 == 0x66 && data1 == 0x77) ||
(data0 == 0x88 && data1 == 0x99) ||
(data0 == 0xaa && data1 == 0xbb) ||
(data0 == 0xcc && data1 == 0xdd) ||
(data0 == 0xee && data1 == 0xff)) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 1);
input_sync(gspca_dev->input_dev);
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
ret = 0;
}
}
return ret;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
