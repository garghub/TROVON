static int _send_control_msg(struct pwc_device *pdev,
u8 request, u16 value, int index, void *buf, int buflen, int timeout)
{
int rc;
void *kbuf = NULL;
if (buflen) {
kbuf = kmalloc(buflen, GFP_KERNEL);
if (kbuf == NULL)
return -ENOMEM;
memcpy(kbuf, buf, buflen);
}
rc = usb_control_msg(pdev->udev, usb_sndctrlpipe(pdev->udev, 0),
request,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
kbuf, buflen, timeout);
kfree(kbuf);
return rc;
}
static int recv_control_msg(struct pwc_device *pdev,
u8 request, u16 value, void *buf, int buflen)
{
int rc;
void *kbuf = kmalloc(buflen, GFP_KERNEL);
if (kbuf == NULL)
return -ENOMEM;
rc = usb_control_msg(pdev->udev, usb_rcvctrlpipe(pdev->udev, 0),
request,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
pdev->vcinterface,
kbuf, buflen, 500);
memcpy(buf, kbuf, buflen);
kfree(kbuf);
return rc;
}
static inline int send_video_command(struct pwc_device *pdev,
int index, void *buf, int buflen)
{
return _send_control_msg(pdev,
SET_EP_STREAM_CTL,
VIDEO_OUTPUT_CONTROL_FORMATTER,
index,
buf, buflen, 1000);
}
static inline int send_control_msg(struct pwc_device *pdev,
u8 request, u16 value, void *buf, int buflen)
{
return _send_control_msg(pdev,
request, value, pdev->vcinterface, buf, buflen, 500);
}
static int set_video_mode_Nala(struct pwc_device *pdev, int size, int frames)
{
unsigned char buf[3];
int ret, fps;
struct Nala_table_entry *pEntry;
int frames2frames[31] =
{
0, 0, 0, 0, 4,
5, 5, 7, 7, 10,
10, 10, 12, 12, 15,
15, 15, 15, 20, 20,
20, 20, 20, 24, 24,
24, 24, 24, 24, 24,
24
};
int frames2table[31] =
{ 0, 0, 0, 0, 0,
1, 1, 1, 2, 2,
3, 3, 4, 4, 4,
5, 5, 5, 5, 5,
6, 6, 6, 6, 7,
7, 7, 7, 7, 7,
7
};
if (size < 0 || size > PSZ_CIF || frames < 4 || frames > 25)
return -EINVAL;
frames = frames2frames[frames];
fps = frames2table[frames];
pEntry = &Nala_table[size][fps];
if (pEntry->alternate == 0)
return -EINVAL;
memcpy(buf, pEntry->mode, 3);
ret = send_video_command(pdev, pdev->vendpoint, buf, 3);
if (ret < 0) {
PWC_DEBUG_MODULE("Failed to send video command... %d\n", ret);
return ret;
}
if (pEntry->compressed && pdev->pixfmt == V4L2_PIX_FMT_YUV420)
pwc_dec1_init(pdev->type, pdev->release, buf, pdev->decompress_data);
pdev->cmd_len = 3;
memcpy(pdev->cmd_buf, buf, 3);
pdev->vframes = frames;
pdev->vsize = size;
pdev->valternate = pEntry->alternate;
pdev->image = pwc_image_sizes[size];
pdev->frame_size = (pdev->image.x * pdev->image.y * 3) / 2;
if (pEntry->compressed) {
if (pdev->release < 5) {
pdev->vbandlength = 528;
pdev->frame_size /= 4;
}
else {
pdev->vbandlength = 704;
pdev->frame_size /= 3;
}
}
else
pdev->vbandlength = 0;
return 0;
}
static int set_video_mode_Timon(struct pwc_device *pdev, int size, int frames, int compression, int snapshot)
{
unsigned char buf[13];
const struct Timon_table_entry *pChoose;
int ret, fps;
if (size >= PSZ_MAX || frames < 5 || frames > 30 || compression < 0 || compression > 3)
return -EINVAL;
if (size == PSZ_VGA && frames > 15)
return -EINVAL;
fps = (frames / 5) - 1;
pChoose = NULL;
while (compression <= 3) {
pChoose = &Timon_table[size][fps][compression];
if (pChoose->alternate != 0)
break;
compression++;
}
if (pChoose == NULL || pChoose->alternate == 0)
return -ENOENT;
memcpy(buf, pChoose->mode, 13);
if (snapshot)
buf[0] |= 0x80;
ret = send_video_command(pdev, pdev->vendpoint, buf, 13);
if (ret < 0)
return ret;
if (pChoose->bandlength > 0 && pdev->pixfmt == V4L2_PIX_FMT_YUV420)
pwc_dec23_init(pdev, pdev->type, buf);
pdev->cmd_len = 13;
memcpy(pdev->cmd_buf, buf, 13);
pdev->vframes = frames;
pdev->vsize = size;
pdev->vsnapshot = snapshot;
pdev->valternate = pChoose->alternate;
pdev->image = pwc_image_sizes[size];
pdev->vbandlength = pChoose->bandlength;
if (pChoose->bandlength > 0)
pdev->frame_size = (pChoose->bandlength * pdev->image.y) / 4;
else
pdev->frame_size = (pdev->image.x * pdev->image.y * 12) / 8;
return 0;
}
static int set_video_mode_Kiara(struct pwc_device *pdev, int size, int frames, int compression, int snapshot)
{
const struct Kiara_table_entry *pChoose = NULL;
int fps, ret;
unsigned char buf[12];
struct Kiara_table_entry RawEntry = {6, 773, 1272, {0xAD, 0xF4, 0x10, 0x27, 0xB6, 0x24, 0x96, 0x02, 0x30, 0x05, 0x03, 0x80}};
if (size >= PSZ_MAX || frames < 5 || frames > 30 || compression < 0 || compression > 3)
return -EINVAL;
if (size == PSZ_VGA && frames > 15)
return -EINVAL;
fps = (frames / 5) - 1;
if (size == PSZ_VGA && frames == 5 && snapshot && pdev->pixfmt != V4L2_PIX_FMT_YUV420)
{
PWC_DEBUG_SIZE("Choosing VGA/5 BAYER mode.\n");
pChoose = &RawEntry;
}
else
{
snapshot = 0;
while (compression <= 3) {
pChoose = &Kiara_table[size][fps][compression];
if (pChoose->alternate != 0)
break;
compression++;
}
}
if (pChoose == NULL || pChoose->alternate == 0)
return -ENOENT;
PWC_TRACE("Using alternate setting %d.\n", pChoose->alternate);
memcpy(buf, pChoose->mode, 12);
if (snapshot)
buf[0] |= 0x80;
ret = send_video_command(pdev, 4 , buf, 12);
if (ret < 0)
return ret;
if (pChoose->bandlength > 0 && pdev->pixfmt == V4L2_PIX_FMT_YUV420)
pwc_dec23_init(pdev, pdev->type, buf);
pdev->cmd_len = 12;
memcpy(pdev->cmd_buf, buf, 12);
pdev->vframes = frames;
pdev->vsize = size;
pdev->vsnapshot = snapshot;
pdev->valternate = pChoose->alternate;
pdev->image = pwc_image_sizes[size];
pdev->vbandlength = pChoose->bandlength;
if (pdev->vbandlength > 0)
pdev->frame_size = (pdev->vbandlength * pdev->image.y) / 4;
else
pdev->frame_size = (pdev->image.x * pdev->image.y * 12) / 8;
PWC_TRACE("frame_size=%d, vframes=%d, vsize=%d, vsnapshot=%d, vbandlength=%d\n",
pdev->frame_size,pdev->vframes,pdev->vsize,pdev->vsnapshot,pdev->vbandlength);
return 0;
}
int pwc_set_video_mode(struct pwc_device *pdev, int width, int height, int frames, int compression, int snapshot)
{
int ret, size;
PWC_DEBUG_FLOW("set_video_mode(%dx%d @ %d, pixfmt %08x).\n", width, height, frames, pdev->pixfmt);
size = pwc_decode_size(pdev, width, height);
if (size < 0) {
PWC_DEBUG_MODULE("Could not find suitable size.\n");
return -ERANGE;
}
PWC_TRACE("decode_size = %d.\n", size);
if (DEVICE_USE_CODEC1(pdev->type)) {
ret = set_video_mode_Nala(pdev, size, frames);
} else if (DEVICE_USE_CODEC3(pdev->type)) {
ret = set_video_mode_Kiara(pdev, size, frames, compression, snapshot);
} else {
ret = set_video_mode_Timon(pdev, size, frames, compression, snapshot);
}
if (ret < 0) {
PWC_ERROR("Failed to set video mode %s@%d fps; return code = %d\n", size2name[size], frames, ret);
return ret;
}
pdev->view.x = width;
pdev->view.y = height;
pdev->frame_total_size = pdev->frame_size + pdev->frame_header_size + pdev->frame_trailer_size;
pwc_set_image_buffer_size(pdev);
PWC_DEBUG_SIZE("Set viewport to %dx%d, image size is %dx%d.\n", width, height, pwc_image_sizes[size].x, pwc_image_sizes[size].y);
return 0;
}
static unsigned int pwc_get_fps_Nala(struct pwc_device *pdev, unsigned int index, unsigned int size)
{
unsigned int i;
for (i = 0; i < PWC_FPS_MAX_NALA; i++) {
if (Nala_table[size][i].alternate) {
if (index--==0) return Nala_fps_vector[i];
}
}
return 0;
}
static unsigned int pwc_get_fps_Kiara(struct pwc_device *pdev, unsigned int index, unsigned int size)
{
unsigned int i;
for (i = 0; i < PWC_FPS_MAX_KIARA; i++) {
if (Kiara_table[size][i][3].alternate) {
if (index--==0) return Kiara_fps_vector[i];
}
}
return 0;
}
static unsigned int pwc_get_fps_Timon(struct pwc_device *pdev, unsigned int index, unsigned int size)
{
unsigned int i;
for (i=0; i < PWC_FPS_MAX_TIMON; i++) {
if (Timon_table[size][i][3].alternate) {
if (index--==0) return Timon_fps_vector[i];
}
}
return 0;
}
unsigned int pwc_get_fps(struct pwc_device *pdev, unsigned int index, unsigned int size)
{
unsigned int ret;
if (DEVICE_USE_CODEC1(pdev->type)) {
ret = pwc_get_fps_Nala(pdev, index, size);
} else if (DEVICE_USE_CODEC3(pdev->type)) {
ret = pwc_get_fps_Kiara(pdev, index, size);
} else {
ret = pwc_get_fps_Timon(pdev, index, size);
}
return ret;
}
static void pwc_set_image_buffer_size(struct pwc_device *pdev)
{
int i, factor = 0;
switch (pdev->pixfmt) {
case V4L2_PIX_FMT_YUV420:
factor = 6;
break;
case V4L2_PIX_FMT_PWC1:
case V4L2_PIX_FMT_PWC2:
factor = 6;
break;
}
pdev->image.size = pdev->image.x * pdev->image.y * factor / 4;
pdev->view.size = pdev->view.x * pdev->view.y * factor / 4;
pdev->offset.x = ((pdev->view.x - pdev->image.x) / 2) & 0xFFFC;
pdev->offset.y = ((pdev->view.y - pdev->image.y) / 2) & 0xFFFE;
for (i = 0; i < pwc_mbufs; i++) {
unsigned char *p = pdev->image_data + pdev->images[i].offset;
memset(p, BLACK_Y, pdev->view.x * pdev->view.y);
p += pdev->view.x * pdev->view.y;
memset(p, BLACK_U, pdev->view.x * pdev->view.y/4);
p += pdev->view.x * pdev->view.y/4;
memset(p, BLACK_V, pdev->view.x * pdev->view.y/4);
}
}
int pwc_get_brightness(struct pwc_device *pdev)
{
char buf;
int ret;
ret = recv_control_msg(pdev,
GET_LUM_CTL, BRIGHTNESS_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return buf;
}
int pwc_set_brightness(struct pwc_device *pdev, int value)
{
char buf;
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = (value >> 9) & 0x7f;
return send_control_msg(pdev,
SET_LUM_CTL, BRIGHTNESS_FORMATTER, &buf, sizeof(buf));
}
int pwc_get_contrast(struct pwc_device *pdev)
{
char buf;
int ret;
ret = recv_control_msg(pdev,
GET_LUM_CTL, CONTRAST_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return buf;
}
int pwc_set_contrast(struct pwc_device *pdev, int value)
{
char buf;
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = (value >> 10) & 0x3f;
return send_control_msg(pdev,
SET_LUM_CTL, CONTRAST_FORMATTER, &buf, sizeof(buf));
}
int pwc_get_gamma(struct pwc_device *pdev)
{
char buf;
int ret;
ret = recv_control_msg(pdev,
GET_LUM_CTL, GAMMA_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return buf;
}
int pwc_set_gamma(struct pwc_device *pdev, int value)
{
char buf;
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = (value >> 11) & 0x1f;
return send_control_msg(pdev,
SET_LUM_CTL, GAMMA_FORMATTER, &buf, sizeof(buf));
}
int pwc_get_saturation(struct pwc_device *pdev, int *value)
{
char buf;
int ret, saturation_register;
if (pdev->type < 675)
return -EINVAL;
if (pdev->type < 730)
saturation_register = SATURATION_MODE_FORMATTER2;
else
saturation_register = SATURATION_MODE_FORMATTER1;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, saturation_register, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = (signed)buf;
return 0;
}
int pwc_set_saturation(struct pwc_device *pdev, int value)
{
char buf;
int saturation_register;
if (pdev->type < 675)
return -EINVAL;
if (value < -100)
value = -100;
if (value > 100)
value = 100;
if (pdev->type < 730)
saturation_register = SATURATION_MODE_FORMATTER2;
else
saturation_register = SATURATION_MODE_FORMATTER1;
return send_control_msg(pdev,
SET_CHROM_CTL, saturation_register, &buf, sizeof(buf));
}
int pwc_set_agc(struct pwc_device *pdev, int mode, int value)
{
char buf;
int ret;
if (mode)
buf = 0x0;
else
buf = 0xff;
ret = send_control_msg(pdev,
SET_LUM_CTL, AGC_MODE_FORMATTER, &buf, sizeof(buf));
if (!mode && ret >= 0) {
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = (value >> 10) & 0x3F;
ret = send_control_msg(pdev,
SET_LUM_CTL, PRESET_AGC_FORMATTER, &buf, sizeof(buf));
}
if (ret < 0)
return ret;
return 0;
}
int pwc_get_agc(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_LUM_CTL, AGC_MODE_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (buf != 0) {
ret = recv_control_msg(pdev,
GET_LUM_CTL, PRESET_AGC_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (buf > 0x3F)
buf = 0x3F;
*value = (buf << 10);
}
else {
ret = recv_control_msg(pdev,
GET_STATUS_CTL, READ_AGC_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (buf > 0x9F)
buf = 0x9F;
*value = -(48 + buf * 409);
}
return 0;
}
int pwc_set_shutter_speed(struct pwc_device *pdev, int mode, int value)
{
char buf[2];
int speed, ret;
if (mode)
buf[0] = 0x0;
else
buf[0] = 0xff;
ret = send_control_msg(pdev,
SET_LUM_CTL, SHUTTER_MODE_FORMATTER, &buf, 1);
if (!mode && ret >= 0) {
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
if (DEVICE_USE_CODEC2(pdev->type)) {
speed = (value / 100);
buf[1] = speed >> 8;
buf[0] = speed & 0xff;
} else if (DEVICE_USE_CODEC3(pdev->type)) {
buf[1] = 0;
buf[0] = value >> 8;
}
ret = send_control_msg(pdev,
SET_LUM_CTL, PRESET_SHUTTER_FORMATTER,
&buf, sizeof(buf));
}
return ret;
}
int pwc_get_shutter_speed(struct pwc_device *pdev, int *value)
{
unsigned char buf[2];
int ret;
ret = recv_control_msg(pdev,
GET_STATUS_CTL, READ_SHUTTER_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf[0] + (buf[1] << 8);
if (DEVICE_USE_CODEC2(pdev->type)) {
*value *= 256/656;
} else if (DEVICE_USE_CODEC3(pdev->type)) {
}
return 0;
}
int pwc_camera_power(struct pwc_device *pdev, int power)
{
char buf;
if (pdev->type < 675 || (pdev->type < 730 && pdev->release < 6))
return 0;
if (power)
buf = 0x00;
else
buf = 0xFF;
return send_control_msg(pdev,
SET_STATUS_CTL, SET_POWER_SAVE_MODE_FORMATTER,
&buf, sizeof(buf));
}
int pwc_restore_user(struct pwc_device *pdev)
{
return send_control_msg(pdev,
SET_STATUS_CTL, RESTORE_USER_DEFAULTS_FORMATTER, NULL, 0);
}
int pwc_save_user(struct pwc_device *pdev)
{
return send_control_msg(pdev,
SET_STATUS_CTL, SAVE_USER_DEFAULTS_FORMATTER, NULL, 0);
}
int pwc_restore_factory(struct pwc_device *pdev)
{
return send_control_msg(pdev,
SET_STATUS_CTL, RESTORE_FACTORY_DEFAULTS_FORMATTER, NULL, 0);
}
int pwc_set_awb(struct pwc_device *pdev, int mode)
{
char buf;
int ret;
if (mode < 0)
mode = 0;
if (mode > 4)
mode = 4;
buf = mode & 0x07;
ret = send_control_msg(pdev,
SET_CHROM_CTL, WB_MODE_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return 0;
}
int pwc_get_awb(struct pwc_device *pdev)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, WB_MODE_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return buf;
}
int pwc_set_red_gain(struct pwc_device *pdev, int value)
{
unsigned char buf;
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = value >> 8;
return send_control_msg(pdev,
SET_CHROM_CTL, PRESET_MANUAL_RED_GAIN_FORMATTER,
&buf, sizeof(buf));
}
int pwc_get_red_gain(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, PRESET_MANUAL_RED_GAIN_FORMATTER,
&buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf << 8;
return 0;
}
int pwc_set_blue_gain(struct pwc_device *pdev, int value)
{
unsigned char buf;
if (value < 0)
value = 0;
if (value > 0xffff)
value = 0xffff;
buf = value >> 8;
return send_control_msg(pdev,
SET_CHROM_CTL, PRESET_MANUAL_BLUE_GAIN_FORMATTER,
&buf, sizeof(buf));
}
int pwc_get_blue_gain(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, PRESET_MANUAL_BLUE_GAIN_FORMATTER,
&buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf << 8;
return 0;
}
static int pwc_read_red_gain(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_STATUS_CTL, READ_RED_GAIN_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf << 8;
return 0;
}
static int pwc_read_blue_gain(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_STATUS_CTL, READ_BLUE_GAIN_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf << 8;
return 0;
}
static int pwc_set_wb_speed(struct pwc_device *pdev, int speed)
{
unsigned char buf;
buf = speed / 0x7f0;
return send_control_msg(pdev,
SET_CHROM_CTL, AWB_CONTROL_SPEED_FORMATTER, &buf, sizeof(buf));
}
static int pwc_get_wb_speed(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, AWB_CONTROL_SPEED_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf * 0x7f0;
return 0;
}
static int pwc_set_wb_delay(struct pwc_device *pdev, int delay)
{
unsigned char buf;
buf = (delay >> 10);
return send_control_msg(pdev,
SET_CHROM_CTL, AWB_CONTROL_DELAY_FORMATTER, &buf, sizeof(buf));
}
static int pwc_get_wb_delay(struct pwc_device *pdev, int *value)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, AWB_CONTROL_DELAY_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*value = buf << 10;
return 0;
}
int pwc_set_leds(struct pwc_device *pdev, int on_value, int off_value)
{
unsigned char buf[2];
if (pdev->type < 730)
return 0;
on_value /= 100;
off_value /= 100;
if (on_value < 0)
on_value = 0;
if (on_value > 0xff)
on_value = 0xff;
if (off_value < 0)
off_value = 0;
if (off_value > 0xff)
off_value = 0xff;
buf[0] = on_value;
buf[1] = off_value;
return send_control_msg(pdev,
SET_STATUS_CTL, LED_FORMATTER, &buf, sizeof(buf));
}
static int pwc_get_leds(struct pwc_device *pdev, int *on_value, int *off_value)
{
unsigned char buf[2];
int ret;
if (pdev->type < 730) {
*on_value = -1;
*off_value = -1;
return 0;
}
ret = recv_control_msg(pdev,
GET_STATUS_CTL, LED_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*on_value = buf[0] * 100;
*off_value = buf[1] * 100;
return 0;
}
int pwc_set_contour(struct pwc_device *pdev, int contour)
{
unsigned char buf;
int ret;
if (contour < 0)
buf = 0xff;
else
buf = 0x0;
ret = send_control_msg(pdev,
SET_LUM_CTL, AUTO_CONTOUR_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (contour < 0)
return 0;
if (contour > 0xffff)
contour = 0xffff;
buf = (contour >> 10);
ret = send_control_msg(pdev,
SET_LUM_CTL, PRESET_CONTOUR_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
return 0;
}
int pwc_get_contour(struct pwc_device *pdev, int *contour)
{
unsigned char buf;
int ret;
ret = recv_control_msg(pdev,
GET_LUM_CTL, AUTO_CONTOUR_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (buf == 0) {
ret = recv_control_msg(pdev,
GET_LUM_CTL, PRESET_CONTOUR_FORMATTER,
&buf, sizeof(buf));
if (ret < 0)
return ret;
*contour = buf << 10;
}
else
*contour = -1;
return 0;
}
int pwc_set_backlight(struct pwc_device *pdev, int backlight)
{
unsigned char buf;
if (backlight)
buf = 0xff;
else
buf = 0x0;
return send_control_msg(pdev,
SET_LUM_CTL, BACK_LIGHT_COMPENSATION_FORMATTER,
&buf, sizeof(buf));
}
int pwc_get_backlight(struct pwc_device *pdev, int *backlight)
{
int ret;
unsigned char buf;
ret = recv_control_msg(pdev,
GET_LUM_CTL, BACK_LIGHT_COMPENSATION_FORMATTER,
&buf, sizeof(buf));
if (ret < 0)
return ret;
*backlight = !!buf;
return 0;
}
int pwc_set_colour_mode(struct pwc_device *pdev, int colour)
{
unsigned char buf;
if (colour)
buf = 0xff;
else
buf = 0x0;
return send_control_msg(pdev,
SET_CHROM_CTL, COLOUR_MODE_FORMATTER, &buf, sizeof(buf));
}
int pwc_get_colour_mode(struct pwc_device *pdev, int *colour)
{
int ret;
unsigned char buf;
ret = recv_control_msg(pdev,
GET_CHROM_CTL, COLOUR_MODE_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*colour = !!buf;
return 0;
}
int pwc_set_flicker(struct pwc_device *pdev, int flicker)
{
unsigned char buf;
if (flicker)
buf = 0xff;
else
buf = 0x0;
return send_control_msg(pdev,
SET_LUM_CTL, FLICKERLESS_MODE_FORMATTER, &buf, sizeof(buf));
}
int pwc_get_flicker(struct pwc_device *pdev, int *flicker)
{
int ret;
unsigned char buf;
ret = recv_control_msg(pdev,
GET_LUM_CTL, FLICKERLESS_MODE_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
*flicker = !!buf;
return 0;
}
int pwc_set_dynamic_noise(struct pwc_device *pdev, int noise)
{
unsigned char buf;
if (noise < 0)
noise = 0;
if (noise > 3)
noise = 3;
buf = noise;
return send_control_msg(pdev,
SET_LUM_CTL, DYNAMIC_NOISE_CONTROL_FORMATTER,
&buf, sizeof(buf));
}
int pwc_get_dynamic_noise(struct pwc_device *pdev, int *noise)
{
int ret;
unsigned char buf;
ret = recv_control_msg(pdev,
GET_LUM_CTL, DYNAMIC_NOISE_CONTROL_FORMATTER,
&buf, sizeof(buf));
if (ret < 0)
return ret;
*noise = buf;
return 0;
}
static int _pwc_mpt_reset(struct pwc_device *pdev, int flags)
{
unsigned char buf;
buf = flags & 0x03;
return send_control_msg(pdev,
SET_MPT_CTL, PT_RESET_CONTROL_FORMATTER, &buf, sizeof(buf));
}
int pwc_mpt_reset(struct pwc_device *pdev, int flags)
{
int ret;
ret = _pwc_mpt_reset(pdev, flags);
if (ret >= 0) {
pdev->pan_angle = 0;
pdev->tilt_angle = 0;
}
return ret;
}
static int _pwc_mpt_set_angle(struct pwc_device *pdev, int pan, int tilt)
{
unsigned char buf[4];
pan = 64 * pan / 100;
tilt = -64 * tilt / 100;
buf[0] = pan & 0xFF;
buf[1] = (pan >> 8) & 0xFF;
buf[2] = tilt & 0xFF;
buf[3] = (tilt >> 8) & 0xFF;
return send_control_msg(pdev,
SET_MPT_CTL, PT_RELATIVE_CONTROL_FORMATTER, &buf, sizeof(buf));
}
int pwc_mpt_set_angle(struct pwc_device *pdev, int pan, int tilt)
{
int ret;
if (pan < pdev->angle_range.pan_min ||
pan > pdev->angle_range.pan_max ||
tilt < pdev->angle_range.tilt_min ||
tilt > pdev->angle_range.tilt_max)
return -ERANGE;
pan -= pdev->pan_angle;
tilt -= pdev->tilt_angle;
if (pan < -36000 || pan > 36000 || tilt < -36000 || tilt > 36000)
return -ERANGE;
ret = _pwc_mpt_set_angle(pdev, pan, tilt);
if (ret >= 0) {
pdev->pan_angle += pan;
pdev->tilt_angle += tilt;
}
if (ret == -EPIPE)
ret = -ERANGE;
return ret;
}
static int pwc_mpt_get_status(struct pwc_device *pdev, struct pwc_mpt_status *status)
{
int ret;
unsigned char buf[5];
ret = recv_control_msg(pdev,
GET_MPT_CTL, PT_STATUS_FORMATTER, &buf, sizeof(buf));
if (ret < 0)
return ret;
status->status = buf[0] & 0x7;
status->time_pan = (buf[1] << 8) + buf[2];
status->time_tilt = (buf[3] << 8) + buf[4];
return 0;
}
int pwc_get_cmos_sensor(struct pwc_device *pdev, int *sensor)
{
unsigned char buf;
int ret = -1, request;
if (pdev->type < 675)
request = SENSOR_TYPE_FORMATTER1;
else if (pdev->type < 730)
return -1;
else
request = SENSOR_TYPE_FORMATTER2;
ret = recv_control_msg(pdev,
GET_STATUS_CTL, request, &buf, sizeof(buf));
if (ret < 0)
return ret;
if (pdev->type < 675)
*sensor = buf | 0x100;
else
*sensor = buf;
return 0;
}
long pwc_ioctl(struct pwc_device *pdev, unsigned int cmd, void *arg)
{
long ret = 0;
switch(cmd) {
case VIDIOCPWCRUSER:
{
if (pwc_restore_user(pdev))
ret = -EINVAL;
break;
}
case VIDIOCPWCSUSER:
{
if (pwc_save_user(pdev))
ret = -EINVAL;
break;
}
case VIDIOCPWCFACTORY:
{
if (pwc_restore_factory(pdev))
ret = -EINVAL;
break;
}
case VIDIOCPWCSCQUAL:
{
ARG_DEF(int, qual)
if (pdev->iso_init) {
ret = -EBUSY;
break;
}
ARG_IN(qual)
if (ARGR(qual) < 0 || ARGR(qual) > 3)
ret = -EINVAL;
else
ret = pwc_set_video_mode(pdev, pdev->view.x, pdev->view.y, pdev->vframes, ARGR(qual), pdev->vsnapshot);
if (ret >= 0)
pdev->vcompression = ARGR(qual);
break;
}
case VIDIOCPWCGCQUAL:
{
ARG_DEF(int, qual)
ARGR(qual) = pdev->vcompression;
ARG_OUT(qual)
break;
}
case VIDIOCPWCPROBE:
{
ARG_DEF(struct pwc_probe, probe)
strcpy(ARGR(probe).name, pdev->vdev.name);
ARGR(probe).type = pdev->type;
ARG_OUT(probe)
break;
}
case VIDIOCPWCGSERIAL:
{
ARG_DEF(struct pwc_serial, serial)
strcpy(ARGR(serial).serial, pdev->serial);
ARG_OUT(serial)
break;
}
case VIDIOCPWCSAGC:
{
ARG_DEF(int, agc)
ARG_IN(agc)
if (pwc_set_agc(pdev, ARGR(agc) < 0 ? 1 : 0, ARGR(agc)))
ret = -EINVAL;
break;
}
case VIDIOCPWCGAGC:
{
ARG_DEF(int, agc)
if (pwc_get_agc(pdev, ARGA(agc)))
ret = -EINVAL;
ARG_OUT(agc)
break;
}
case VIDIOCPWCSSHUTTER:
{
ARG_DEF(int, shutter_speed)
ARG_IN(shutter_speed)
ret = pwc_set_shutter_speed(pdev, ARGR(shutter_speed) < 0 ? 1 : 0, ARGR(shutter_speed));
break;
}
case VIDIOCPWCSAWB:
{
ARG_DEF(struct pwc_whitebalance, wb)
ARG_IN(wb)
ret = pwc_set_awb(pdev, ARGR(wb).mode);
if (ret >= 0 && ARGR(wb).mode == PWC_WB_MANUAL) {
pwc_set_red_gain(pdev, ARGR(wb).manual_red);
pwc_set_blue_gain(pdev, ARGR(wb).manual_blue);
}
break;
}
case VIDIOCPWCGAWB:
{
ARG_DEF(struct pwc_whitebalance, wb)
memset(ARGA(wb), 0, sizeof(struct pwc_whitebalance));
ARGR(wb).mode = pwc_get_awb(pdev);
if (ARGR(wb).mode < 0)
ret = -EINVAL;
else {
if (ARGR(wb).mode == PWC_WB_MANUAL) {
ret = pwc_get_red_gain(pdev, &ARGR(wb).manual_red);
if (ret < 0)
break;
ret = pwc_get_blue_gain(pdev, &ARGR(wb).manual_blue);
if (ret < 0)
break;
}
if (ARGR(wb).mode == PWC_WB_AUTO) {
ret = pwc_read_red_gain(pdev, &ARGR(wb).read_red);
if (ret < 0)
break;
ret = pwc_read_blue_gain(pdev, &ARGR(wb).read_blue);
if (ret < 0)
break;
}
}
ARG_OUT(wb)
break;
}
case VIDIOCPWCSAWBSPEED:
{
ARG_DEF(struct pwc_wb_speed, wbs)
if (ARGR(wbs).control_speed > 0) {
ret = pwc_set_wb_speed(pdev, ARGR(wbs).control_speed);
}
if (ARGR(wbs).control_delay > 0) {
ret = pwc_set_wb_delay(pdev, ARGR(wbs).control_delay);
}
break;
}
case VIDIOCPWCGAWBSPEED:
{
ARG_DEF(struct pwc_wb_speed, wbs)
ret = pwc_get_wb_speed(pdev, &ARGR(wbs).control_speed);
if (ret < 0)
break;
ret = pwc_get_wb_delay(pdev, &ARGR(wbs).control_delay);
if (ret < 0)
break;
ARG_OUT(wbs)
break;
}
case VIDIOCPWCSLED:
{
ARG_DEF(struct pwc_leds, leds)
ARG_IN(leds)
ret = pwc_set_leds(pdev, ARGR(leds).led_on, ARGR(leds).led_off);
break;
}
case VIDIOCPWCGLED:
{
ARG_DEF(struct pwc_leds, leds)
ret = pwc_get_leds(pdev, &ARGR(leds).led_on, &ARGR(leds).led_off);
ARG_OUT(leds)
break;
}
case VIDIOCPWCSCONTOUR:
{
ARG_DEF(int, contour)
ARG_IN(contour)
ret = pwc_set_contour(pdev, ARGR(contour));
break;
}
case VIDIOCPWCGCONTOUR:
{
ARG_DEF(int, contour)
ret = pwc_get_contour(pdev, ARGA(contour));
ARG_OUT(contour)
break;
}
case VIDIOCPWCSBACKLIGHT:
{
ARG_DEF(int, backlight)
ARG_IN(backlight)
ret = pwc_set_backlight(pdev, ARGR(backlight));
break;
}
case VIDIOCPWCGBACKLIGHT:
{
ARG_DEF(int, backlight)
ret = pwc_get_backlight(pdev, ARGA(backlight));
ARG_OUT(backlight)
break;
}
case VIDIOCPWCSFLICKER:
{
ARG_DEF(int, flicker)
ARG_IN(flicker)
ret = pwc_set_flicker(pdev, ARGR(flicker));
break;
}
case VIDIOCPWCGFLICKER:
{
ARG_DEF(int, flicker)
ret = pwc_get_flicker(pdev, ARGA(flicker));
ARG_OUT(flicker)
break;
}
case VIDIOCPWCSDYNNOISE:
{
ARG_DEF(int, dynnoise)
ARG_IN(dynnoise)
ret = pwc_set_dynamic_noise(pdev, ARGR(dynnoise));
break;
}
case VIDIOCPWCGDYNNOISE:
{
ARG_DEF(int, dynnoise)
ret = pwc_get_dynamic_noise(pdev, ARGA(dynnoise));
ARG_OUT(dynnoise);
break;
}
case VIDIOCPWCGREALSIZE:
{
ARG_DEF(struct pwc_imagesize, size)
ARGR(size).width = pdev->image.x;
ARGR(size).height = pdev->image.y;
ARG_OUT(size)
break;
}
case VIDIOCPWCMPTRESET:
{
if (pdev->features & FEATURE_MOTOR_PANTILT)
{
ARG_DEF(int, flags)
ARG_IN(flags)
ret = pwc_mpt_reset(pdev, ARGR(flags));
}
else
{
ret = -ENXIO;
}
break;
}
case VIDIOCPWCMPTGRANGE:
{
if (pdev->features & FEATURE_MOTOR_PANTILT)
{
ARG_DEF(struct pwc_mpt_range, range)
ARGR(range) = pdev->angle_range;
ARG_OUT(range)
}
else
{
ret = -ENXIO;
}
break;
}
case VIDIOCPWCMPTSANGLE:
{
int new_pan, new_tilt;
if (pdev->features & FEATURE_MOTOR_PANTILT)
{
ARG_DEF(struct pwc_mpt_angles, angles)
ARG_IN(angles)
if (ARGR(angles).absolute)
{
new_pan = ARGR(angles).pan;
new_tilt = ARGR(angles).tilt;
}
else
{
new_pan = pdev->pan_angle + ARGR(angles).pan;
new_tilt = pdev->tilt_angle + ARGR(angles).tilt;
}
ret = pwc_mpt_set_angle(pdev, new_pan, new_tilt);
}
else
{
ret = -ENXIO;
}
break;
}
case VIDIOCPWCMPTGANGLE:
{
if (pdev->features & FEATURE_MOTOR_PANTILT)
{
ARG_DEF(struct pwc_mpt_angles, angles)
ARGR(angles).absolute = 1;
ARGR(angles).pan = pdev->pan_angle;
ARGR(angles).tilt = pdev->tilt_angle;
ARG_OUT(angles)
}
else
{
ret = -ENXIO;
}
break;
}
case VIDIOCPWCMPTSTATUS:
{
if (pdev->features & FEATURE_MOTOR_PANTILT)
{
ARG_DEF(struct pwc_mpt_status, status)
ret = pwc_mpt_get_status(pdev, ARGA(status));
ARG_OUT(status)
}
else
{
ret = -ENXIO;
}
break;
}
case VIDIOCPWCGVIDCMD:
{
ARG_DEF(struct pwc_video_command, vcmd);
ARGR(vcmd).type = pdev->type;
ARGR(vcmd).release = pdev->release;
ARGR(vcmd).command_len = pdev->cmd_len;
memcpy(&ARGR(vcmd).command_buf, pdev->cmd_buf, pdev->cmd_len);
ARGR(vcmd).bandlength = pdev->vbandlength;
ARGR(vcmd).frame_size = pdev->frame_size;
ARG_OUT(vcmd)
break;
}
default:
ret = -ENOIOCTLCMD;
break;
}
if (ret > 0)
return 0;
return ret;
}
