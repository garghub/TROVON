static inline unsigned int norm_maxw(struct em28xx *dev)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (dev->board.is_webcam)
return v4l2->sensor_xres;
if (dev->board.max_range_640_480)
return 640;
return 720;
}
static inline unsigned int norm_maxh(struct em28xx *dev)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (dev->board.is_webcam)
return v4l2->sensor_yres;
if (dev->board.max_range_640_480)
return 480;
return (v4l2->norm & V4L2_STD_625_50) ? 576 : 480;
}
static int em28xx_vbi_supported(struct em28xx *dev)
{
if (disable_vbi == 1)
return 0;
if (dev->board.is_webcam)
return 0;
if (dev->chip_id == CHIP_ID_EM2860 ||
dev->chip_id == CHIP_ID_EM2883)
return 1;
return 0;
}
static void em28xx_wake_i2c(struct em28xx *dev)
{
struct v4l2_device *v4l2_dev = &dev->v4l2->v4l2_dev;
v4l2_device_call_all(v4l2_dev, 0, core, reset, 0);
v4l2_device_call_all(v4l2_dev, 0, video, s_routing,
INPUT(dev->ctl_input)->vmux, 0, 0);
v4l2_device_call_all(v4l2_dev, 0, video, s_stream, 0);
}
static int em28xx_colorlevels_set_default(struct em28xx *dev)
{
em28xx_write_reg(dev, EM28XX_R20_YGAIN, CONTRAST_DEFAULT);
em28xx_write_reg(dev, EM28XX_R21_YOFFSET, BRIGHTNESS_DEFAULT);
em28xx_write_reg(dev, EM28XX_R22_UVGAIN, SATURATION_DEFAULT);
em28xx_write_reg(dev, EM28XX_R23_UOFFSET, BLUE_BALANCE_DEFAULT);
em28xx_write_reg(dev, EM28XX_R24_VOFFSET, RED_BALANCE_DEFAULT);
em28xx_write_reg(dev, EM28XX_R25_SHARPNESS, SHARPNESS_DEFAULT);
em28xx_write_reg(dev, EM28XX_R14_GAMMA, 0x20);
em28xx_write_reg(dev, EM28XX_R15_RGAIN, 0x20);
em28xx_write_reg(dev, EM28XX_R16_GGAIN, 0x20);
em28xx_write_reg(dev, EM28XX_R17_BGAIN, 0x20);
em28xx_write_reg(dev, EM28XX_R18_ROFFSET, 0x00);
em28xx_write_reg(dev, EM28XX_R19_GOFFSET, 0x00);
return em28xx_write_reg(dev, EM28XX_R1A_BOFFSET, 0x00);
}
static int em28xx_set_outfmt(struct em28xx *dev)
{
int ret;
u8 fmt, vinctrl;
struct em28xx_v4l2 *v4l2 = dev->v4l2;
fmt = v4l2->format->reg;
if (!dev->is_em25xx)
fmt |= 0x20;
ret = em28xx_write_reg(dev, EM28XX_R27_OUTFMT, fmt);
if (ret < 0)
return ret;
ret = em28xx_write_reg(dev, EM28XX_R10_VINMODE, v4l2->vinmode);
if (ret < 0)
return ret;
vinctrl = v4l2->vinctl;
if (em28xx_vbi_supported(dev) == 1) {
vinctrl |= EM28XX_VINCTRL_VBI_RAW;
em28xx_write_reg(dev, EM28XX_R34_VBI_START_H, 0x00);
em28xx_write_reg(dev, EM28XX_R36_VBI_WIDTH, v4l2->vbi_width/4);
em28xx_write_reg(dev, EM28XX_R37_VBI_HEIGHT, v4l2->vbi_height);
if (v4l2->norm & V4L2_STD_525_60) {
em28xx_write_reg(dev, EM28XX_R35_VBI_START_V, 0x09);
} else if (v4l2->norm & V4L2_STD_625_50) {
em28xx_write_reg(dev, EM28XX_R35_VBI_START_V, 0x07);
}
}
return em28xx_write_reg(dev, EM28XX_R11_VINCTRL, vinctrl);
}
static int em28xx_accumulator_set(struct em28xx *dev, u8 xmin, u8 xmax,
u8 ymin, u8 ymax)
{
em28xx_videodbg("em28xx Scale: (%d,%d)-(%d,%d)\n",
xmin, ymin, xmax, ymax);
em28xx_write_regs(dev, EM28XX_R28_XMIN, &xmin, 1);
em28xx_write_regs(dev, EM28XX_R29_XMAX, &xmax, 1);
em28xx_write_regs(dev, EM28XX_R2A_YMIN, &ymin, 1);
return em28xx_write_regs(dev, EM28XX_R2B_YMAX, &ymax, 1);
}
static void em28xx_capture_area_set(struct em28xx *dev, u8 hstart, u8 vstart,
u16 width, u16 height)
{
u8 cwidth = width >> 2;
u8 cheight = height >> 2;
u8 overflow = (height >> 9 & 0x02) | (width >> 10 & 0x01);
em28xx_videodbg("capture area set to (%d,%d): %dx%d\n",
hstart, vstart,
((overflow & 2) << 9 | cwidth << 2),
((overflow & 1) << 10 | cheight << 2));
em28xx_write_regs(dev, EM28XX_R1C_HSTART, &hstart, 1);
em28xx_write_regs(dev, EM28XX_R1D_VSTART, &vstart, 1);
em28xx_write_regs(dev, EM28XX_R1E_CWIDTH, &cwidth, 1);
em28xx_write_regs(dev, EM28XX_R1F_CHEIGHT, &cheight, 1);
em28xx_write_regs(dev, EM28XX_R1B_OFLOW, &overflow, 1);
if (dev->is_em25xx) {
em28xx_write_reg(dev, 0x34, width >> 4);
em28xx_write_reg(dev, 0x35, height >> 4);
}
}
static int em28xx_scaler_set(struct em28xx *dev, u16 h, u16 v)
{
u8 mode = 0x00;
if (dev->board.is_em2800) {
mode = (v ? 0x20 : 0x00) | (h ? 0x10 : 0x00);
} else {
u8 buf[2];
buf[0] = h;
buf[1] = h >> 8;
em28xx_write_regs(dev, EM28XX_R30_HSCALELOW, (char *)buf, 2);
buf[0] = v;
buf[1] = v >> 8;
em28xx_write_regs(dev, EM28XX_R32_VSCALELOW, (char *)buf, 2);
mode = (h || v) ? 0x30 : 0x00;
}
return em28xx_write_reg(dev, EM28XX_R26_COMPR, mode);
}
static int em28xx_resolution_set(struct em28xx *dev)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
int width = norm_maxw(dev);
int height = norm_maxh(dev);
v4l2->vbi_width = 720;
if (v4l2->norm & V4L2_STD_525_60)
v4l2->vbi_height = 12;
else
v4l2->vbi_height = 18;
em28xx_set_outfmt(dev);
em28xx_accumulator_set(dev, 1, (width - 4) >> 2, 1, (height - 4) >> 2);
if (em28xx_vbi_supported(dev) == 1)
em28xx_capture_area_set(dev, 0, 2, width, height);
else
em28xx_capture_area_set(dev, 0, 0, width, height);
return em28xx_scaler_set(dev, v4l2->hscale, v4l2->vscale);
}
static int em28xx_set_alternate(struct em28xx *dev)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
int errCode;
int i;
unsigned int min_pkt_size = v4l2->width * 2 + 4;
dev->alt = 0;
if ((alt > 0) && (alt < dev->num_alt)) {
em28xx_videodbg("alternate forced to %d\n", dev->alt);
dev->alt = alt;
goto set_alt;
}
if (dev->analog_xfer_bulk)
goto set_alt;
if (v4l2->width * 2 * v4l2->height > 720 * 240 * 2)
min_pkt_size *= 2;
for (i = 0; i < dev->num_alt; i++) {
if (dev->alt_max_pkt_size_isoc[i] >= min_pkt_size) {
dev->alt = i;
break;
} else if (dev->alt_max_pkt_size_isoc[i] >
dev->alt_max_pkt_size_isoc[dev->alt])
dev->alt = i;
}
set_alt:
if (dev->analog_xfer_bulk) {
dev->max_pkt_size = 512;
dev->packet_multiplier = EM28XX_BULK_PACKET_MULTIPLIER;
} else {
em28xx_videodbg("minimum isoc packet size: %u (alt=%d)\n",
min_pkt_size, dev->alt);
dev->max_pkt_size =
dev->alt_max_pkt_size_isoc[dev->alt];
dev->packet_multiplier = EM28XX_NUM_ISOC_PACKETS;
}
em28xx_videodbg("setting alternate %d with wMaxPacketSize=%u\n",
dev->alt, dev->max_pkt_size);
errCode = usb_set_interface(dev->udev, dev->ifnum, dev->alt);
if (errCode < 0) {
em28xx_errdev("cannot change alternate number to %d (error=%i)\n",
dev->alt, errCode);
return errCode;
}
return 0;
}
static inline void finish_buffer(struct em28xx *dev,
struct em28xx_buffer *buf)
{
em28xx_isocdbg("[%p/%d] wakeup\n", buf, buf->top_field);
buf->vb.v4l2_buf.sequence = dev->v4l2->field_count++;
if (dev->v4l2->progressive)
buf->vb.v4l2_buf.field = V4L2_FIELD_NONE;
else
buf->vb.v4l2_buf.field = V4L2_FIELD_INTERLACED;
v4l2_get_timestamp(&buf->vb.v4l2_buf.timestamp);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_DONE);
}
static void em28xx_copy_video(struct em28xx *dev,
struct em28xx_buffer *buf,
unsigned char *usb_buf,
unsigned long len)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
void *fieldstart, *startwrite, *startread;
int linesdone, currlinedone, offset, lencopy, remain;
int bytesperline = v4l2->width << 1;
if (buf->pos + len > buf->length)
len = buf->length - buf->pos;
startread = usb_buf;
remain = len;
if (v4l2->progressive || buf->top_field)
fieldstart = buf->vb_buf;
else
fieldstart = buf->vb_buf + bytesperline;
linesdone = buf->pos / bytesperline;
currlinedone = buf->pos % bytesperline;
if (v4l2->progressive)
offset = linesdone * bytesperline + currlinedone;
else
offset = linesdone * bytesperline * 2 + currlinedone;
startwrite = fieldstart + offset;
lencopy = bytesperline - currlinedone;
lencopy = lencopy > remain ? remain : lencopy;
if ((char *)startwrite + lencopy > (char *)buf->vb_buf + buf->length) {
em28xx_isocdbg("Overflow of %zu bytes past buffer end (1)\n",
((char *)startwrite + lencopy) -
((char *)buf->vb_buf + buf->length));
remain = (char *)buf->vb_buf + buf->length -
(char *)startwrite;
lencopy = remain;
}
if (lencopy <= 0)
return;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
while (remain > 0) {
if (v4l2->progressive)
startwrite += lencopy;
else
startwrite += lencopy + bytesperline;
startread += lencopy;
if (bytesperline > remain)
lencopy = remain;
else
lencopy = bytesperline;
if ((char *)startwrite + lencopy > (char *)buf->vb_buf +
buf->length) {
em28xx_isocdbg("Overflow of %zu bytes past buffer end"
"(2)\n",
((char *)startwrite + lencopy) -
((char *)buf->vb_buf + buf->length));
lencopy = remain = (char *)buf->vb_buf + buf->length -
(char *)startwrite;
}
if (lencopy <= 0)
break;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
}
buf->pos += len;
}
static void em28xx_copy_vbi(struct em28xx *dev,
struct em28xx_buffer *buf,
unsigned char *usb_buf,
unsigned long len)
{
unsigned int offset;
if (buf->pos + len > buf->length)
len = buf->length - buf->pos;
offset = buf->pos;
if (buf->top_field == 0)
offset += dev->v4l2->vbi_width * dev->v4l2->vbi_height;
memcpy(buf->vb_buf + offset, usb_buf, len);
buf->pos += len;
}
static inline void print_err_status(struct em28xx *dev,
int packet, int status)
{
char *errmsg = "Unknown";
switch (status) {
case -ENOENT:
errmsg = "unlinked synchronuously";
break;
case -ECONNRESET:
errmsg = "unlinked asynchronuously";
break;
case -ENOSR:
errmsg = "Buffer error (overrun)";
break;
case -EPIPE:
errmsg = "Stalled (device not responding)";
break;
case -EOVERFLOW:
errmsg = "Babble (bad cable?)";
break;
case -EPROTO:
errmsg = "Bit-stuff error (bad cable?)";
break;
case -EILSEQ:
errmsg = "CRC/Timeout (could be anything)";
break;
case -ETIME:
errmsg = "Device does not respond";
break;
}
if (packet < 0) {
em28xx_isocdbg("URB status %d [%s].\n", status, errmsg);
} else {
em28xx_isocdbg("URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline struct em28xx_buffer *get_next_buf(struct em28xx *dev,
struct em28xx_dmaqueue *dma_q)
{
struct em28xx_buffer *buf;
if (list_empty(&dma_q->active)) {
em28xx_isocdbg("No active queue to serve\n");
return NULL;
}
buf = list_entry(dma_q->active.next, struct em28xx_buffer, list);
list_del(&buf->list);
buf->pos = 0;
buf->vb_buf = buf->mem;
return buf;
}
static struct em28xx_buffer *
finish_field_prepare_next(struct em28xx *dev,
struct em28xx_buffer *buf,
struct em28xx_dmaqueue *dma_q)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (v4l2->progressive || v4l2->top_field) {
if (buf != NULL)
finish_buffer(dev, buf);
buf = get_next_buf(dev, dma_q);
}
if (buf != NULL) {
buf->top_field = v4l2->top_field;
buf->pos = 0;
}
return buf;
}
static inline void process_frame_data_em28xx(struct em28xx *dev,
unsigned char *data_pkt,
unsigned int data_len)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct em28xx_buffer *buf = dev->usb_ctl.vid_buf;
struct em28xx_buffer *vbi_buf = dev->usb_ctl.vbi_buf;
struct em28xx_dmaqueue *dma_q = &dev->vidq;
struct em28xx_dmaqueue *vbi_dma_q = &dev->vbiq;
if (data_len >= 4) {
if (data_pkt[0] == 0x88 && data_pkt[1] == 0x88 &&
data_pkt[2] == 0x88 && data_pkt[3] == 0x88) {
data_pkt += 4;
data_len -= 4;
} else if (data_pkt[0] == 0x33 && data_pkt[1] == 0x95) {
v4l2->capture_type = 0;
v4l2->vbi_read = 0;
em28xx_isocdbg("VBI START HEADER !!!\n");
v4l2->top_field = !(data_pkt[2] & 1);
data_pkt += 4;
data_len -= 4;
} else if (data_pkt[0] == 0x22 && data_pkt[1] == 0x5a) {
v4l2->capture_type = 2;
em28xx_isocdbg("VIDEO START HEADER !!!\n");
v4l2->top_field = !(data_pkt[2] & 1);
data_pkt += 4;
data_len -= 4;
}
}
if (v4l2->capture_type == 0) {
vbi_buf = finish_field_prepare_next(dev, vbi_buf, vbi_dma_q);
dev->usb_ctl.vbi_buf = vbi_buf;
v4l2->capture_type = 1;
}
if (v4l2->capture_type == 1) {
int vbi_size = v4l2->vbi_width * v4l2->vbi_height;
int vbi_data_len = ((v4l2->vbi_read + data_len) > vbi_size) ?
(vbi_size - v4l2->vbi_read) : data_len;
if (vbi_buf != NULL)
em28xx_copy_vbi(dev, vbi_buf, data_pkt, vbi_data_len);
v4l2->vbi_read += vbi_data_len;
if (vbi_data_len < data_len) {
v4l2->capture_type = 2;
data_pkt += vbi_data_len;
data_len -= vbi_data_len;
}
}
if (v4l2->capture_type == 2) {
buf = finish_field_prepare_next(dev, buf, dma_q);
dev->usb_ctl.vid_buf = buf;
v4l2->capture_type = 3;
}
if (v4l2->capture_type == 3 && buf != NULL && data_len > 0)
em28xx_copy_video(dev, buf, data_pkt, data_len);
}
static inline void process_frame_data_em25xx(struct em28xx *dev,
unsigned char *data_pkt,
unsigned int data_len)
{
struct em28xx_buffer *buf = dev->usb_ctl.vid_buf;
struct em28xx_dmaqueue *dmaq = &dev->vidq;
struct em28xx_v4l2 *v4l2 = dev->v4l2;
bool frame_end = false;
if (data_len >= 2) {
if ((data_pkt[0] == EM25XX_FRMDATAHDR_BYTE1) &&
((data_pkt[1] & ~EM25XX_FRMDATAHDR_BYTE2_MASK) == 0x00)) {
v4l2->top_field = !(data_pkt[1] &
EM25XX_FRMDATAHDR_BYTE2_FRAME_ID);
frame_end = data_pkt[1] &
EM25XX_FRMDATAHDR_BYTE2_FRAME_END;
data_pkt += 2;
data_len -= 2;
}
if (dev->analog_xfer_bulk && frame_end) {
buf = finish_field_prepare_next(dev, buf, dmaq);
dev->usb_ctl.vid_buf = buf;
}
}
if (buf != NULL && data_len > 0)
em28xx_copy_video(dev, buf, data_pkt, data_len);
if (!dev->analog_xfer_bulk && frame_end) {
buf = finish_field_prepare_next(dev, buf, dmaq);
dev->usb_ctl.vid_buf = buf;
}
}
static inline int em28xx_urb_data_copy(struct em28xx *dev, struct urb *urb)
{
int xfer_bulk, num_packets, i;
unsigned char *usb_data_pkt;
unsigned int usb_data_len;
if (!dev)
return 0;
if (dev->disconnected)
return 0;
if (urb->status < 0)
print_err_status(dev, -1, urb->status);
xfer_bulk = usb_pipebulk(urb->pipe);
if (xfer_bulk)
num_packets = 1;
else
num_packets = urb->number_of_packets;
for (i = 0; i < num_packets; i++) {
if (xfer_bulk) {
usb_data_len = urb->actual_length;
usb_data_pkt = urb->transfer_buffer;
} else {
if (urb->iso_frame_desc[i].status < 0) {
print_err_status(dev, i,
urb->iso_frame_desc[i].status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
usb_data_len = urb->iso_frame_desc[i].actual_length;
if (usb_data_len > dev->max_pkt_size) {
em28xx_isocdbg("packet bigger than packet size");
continue;
}
usb_data_pkt = urb->transfer_buffer +
urb->iso_frame_desc[i].offset;
}
if (usb_data_len == 0) {
continue;
}
if (dev->is_em25xx)
process_frame_data_em25xx(dev,
usb_data_pkt, usb_data_len);
else
process_frame_data_em28xx(dev,
usb_data_pkt, usb_data_len);
}
return 1;
}
static int get_ressource(enum v4l2_buf_type f_type)
{
switch (f_type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return EM28XX_RESOURCE_VIDEO;
case V4L2_BUF_TYPE_VBI_CAPTURE:
return EM28XX_RESOURCE_VBI;
default:
BUG();
return 0;
}
}
static int res_get(struct em28xx *dev, enum v4l2_buf_type f_type)
{
int res_type = get_ressource(f_type);
if (dev->resources & res_type) {
return -EBUSY;
}
dev->resources |= res_type;
em28xx_videodbg("res: get %d\n", res_type);
return 0;
}
static void res_free(struct em28xx *dev, enum v4l2_buf_type f_type)
{
int res_type = get_ressource(f_type);
dev->resources &= ~res_type;
em28xx_videodbg("res: put %d\n", res_type);
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
unsigned long size;
if (fmt)
size = fmt->fmt.pix.sizeimage;
else
size =
(v4l2->width * v4l2->height * v4l2->format->depth + 7) >> 3;
if (size == 0)
return -EINVAL;
if (0 == *nbuffers)
*nbuffers = 32;
*nplanes = 1;
sizes[0] = size;
return 0;
}
static int
buffer_prepare(struct vb2_buffer *vb)
{
struct em28xx *dev = vb2_get_drv_priv(vb->vb2_queue);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
unsigned long size;
em28xx_videodbg("%s, field=%d\n", __func__, vb->v4l2_buf.field);
size = (v4l2->width * v4l2->height * v4l2->format->depth + 7) >> 3;
if (vb2_plane_size(vb, 0) < size) {
em28xx_videodbg("%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(&buf->vb, 0, size);
return 0;
}
int em28xx_start_analog_streaming(struct vb2_queue *vq, unsigned int count)
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct v4l2_frequency f;
int rc = 0;
em28xx_videodbg("%s\n", __func__);
rc = res_get(dev, vq->type);
if (rc)
return rc;
if (v4l2->streaming_users == 0) {
em28xx_set_alternate(dev);
em28xx_wake_i2c(dev);
v4l2->capture_type = -1;
rc = em28xx_init_usb_xfer(dev, EM28XX_ANALOG_MODE,
dev->analog_xfer_bulk,
EM28XX_NUM_BUFS,
dev->max_pkt_size,
dev->packet_multiplier,
em28xx_urb_data_copy);
if (rc < 0)
return rc;
memset(&f, 0, sizeof(f));
f.frequency = v4l2->frequency;
if (vq->owner && vq->owner->vdev->vfl_type == VFL_TYPE_RADIO)
f.type = V4L2_TUNER_RADIO;
else
f.type = V4L2_TUNER_ANALOG_TV;
v4l2_device_call_all(&v4l2->v4l2_dev,
0, tuner, s_frequency, &f);
}
v4l2->streaming_users++;
return rc;
}
static void em28xx_stop_streaming(struct vb2_queue *vq)
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct em28xx_dmaqueue *vidq = &dev->vidq;
unsigned long flags = 0;
em28xx_videodbg("%s\n", __func__);
res_free(dev, vq->type);
if (v4l2->streaming_users-- == 1) {
em28xx_uninit_usb_xfer(dev, EM28XX_ANALOG_MODE);
}
spin_lock_irqsave(&dev->slock, flags);
if (dev->usb_ctl.vid_buf != NULL) {
vb2_buffer_done(&dev->usb_ctl.vid_buf->vb, VB2_BUF_STATE_ERROR);
dev->usb_ctl.vid_buf = NULL;
}
while (!list_empty(&vidq->active)) {
struct em28xx_buffer *buf;
buf = list_entry(vidq->active.next, struct em28xx_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
void em28xx_stop_vbi_streaming(struct vb2_queue *vq)
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct em28xx_dmaqueue *vbiq = &dev->vbiq;
unsigned long flags = 0;
em28xx_videodbg("%s\n", __func__);
res_free(dev, vq->type);
if (v4l2->streaming_users-- == 1) {
em28xx_uninit_usb_xfer(dev, EM28XX_ANALOG_MODE);
}
spin_lock_irqsave(&dev->slock, flags);
if (dev->usb_ctl.vbi_buf != NULL) {
vb2_buffer_done(&dev->usb_ctl.vbi_buf->vb, VB2_BUF_STATE_ERROR);
dev->usb_ctl.vbi_buf = NULL;
}
while (!list_empty(&vbiq->active)) {
struct em28xx_buffer *buf;
buf = list_entry(vbiq->active.next, struct em28xx_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static void
buffer_queue(struct vb2_buffer *vb)
{
struct em28xx *dev = vb2_get_drv_priv(vb->vb2_queue);
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
struct em28xx_dmaqueue *vidq = &dev->vidq;
unsigned long flags = 0;
em28xx_videodbg("%s\n", __func__);
buf->mem = vb2_plane_vaddr(vb, 0);
buf->length = vb2_plane_size(vb, 0);
spin_lock_irqsave(&dev->slock, flags);
list_add_tail(&buf->list, &vidq->active);
spin_unlock_irqrestore(&dev->slock, flags);
}
static int em28xx_vb2_setup(struct em28xx *dev)
{
int rc;
struct vb2_queue *q;
struct em28xx_v4l2 *v4l2 = dev->v4l2;
q = &v4l2->vb_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_READ | VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct em28xx_buffer);
q->ops = &em28xx_video_qops;
q->mem_ops = &vb2_vmalloc_memops;
rc = vb2_queue_init(q);
if (rc < 0)
return rc;
q = &v4l2->vb_vbiq;
q->type = V4L2_BUF_TYPE_VBI_CAPTURE;
q->io_modes = VB2_READ | VB2_MMAP | VB2_USERPTR;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct em28xx_buffer);
q->ops = &em28xx_vbi_qops;
q->mem_ops = &vb2_vmalloc_memops;
rc = vb2_queue_init(q);
if (rc < 0)
return rc;
return 0;
}
static void video_mux(struct em28xx *dev, int index)
{
struct v4l2_device *v4l2_dev = &dev->v4l2->v4l2_dev;
dev->ctl_input = index;
dev->ctl_ainput = INPUT(index)->amux;
dev->ctl_aoutput = INPUT(index)->aout;
if (!dev->ctl_aoutput)
dev->ctl_aoutput = EM28XX_AOUT_MASTER;
v4l2_device_call_all(v4l2_dev, 0, video, s_routing,
INPUT(index)->vmux, 0, 0);
if (dev->board.has_msp34xx) {
if (dev->i2s_speed) {
v4l2_device_call_all(v4l2_dev, 0, audio,
s_i2s_clock_freq, dev->i2s_speed);
}
v4l2_device_call_all(v4l2_dev, 0, audio, s_routing,
dev->ctl_ainput, MSP_OUTPUT(MSP_SC_IN_DSP_SCART1), 0);
}
if (dev->board.adecoder != EM28XX_NOADECODER) {
v4l2_device_call_all(v4l2_dev, 0, audio, s_routing,
dev->ctl_ainput, dev->ctl_aoutput, 0);
}
em28xx_audio_analog_set(dev);
}
static void em28xx_ctrl_notify(struct v4l2_ctrl *ctrl, void *priv)
{
struct em28xx *dev = priv;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
dev->mute = ctrl->val;
em28xx_audio_analog_set(dev);
break;
case V4L2_CID_AUDIO_VOLUME:
dev->volume = ctrl->val;
em28xx_audio_analog_set(dev);
break;
}
}
static int em28xx_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct em28xx_v4l2 *v4l2 =
container_of(ctrl->handler, struct em28xx_v4l2, ctrl_handler);
struct em28xx *dev = v4l2->dev;
int ret = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
dev->mute = ctrl->val;
ret = em28xx_audio_analog_set(dev);
break;
case V4L2_CID_AUDIO_VOLUME:
dev->volume = ctrl->val;
ret = em28xx_audio_analog_set(dev);
break;
case V4L2_CID_CONTRAST:
ret = em28xx_write_reg(dev, EM28XX_R20_YGAIN, ctrl->val);
break;
case V4L2_CID_BRIGHTNESS:
ret = em28xx_write_reg(dev, EM28XX_R21_YOFFSET, ctrl->val);
break;
case V4L2_CID_SATURATION:
ret = em28xx_write_reg(dev, EM28XX_R22_UVGAIN, ctrl->val);
break;
case V4L2_CID_BLUE_BALANCE:
ret = em28xx_write_reg(dev, EM28XX_R23_UOFFSET, ctrl->val);
break;
case V4L2_CID_RED_BALANCE:
ret = em28xx_write_reg(dev, EM28XX_R24_VOFFSET, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
ret = em28xx_write_reg(dev, EM28XX_R25_SHARPNESS, ctrl->val);
break;
}
return (ret < 0) ? ret : 0;
}
static void size_to_scale(struct em28xx *dev,
unsigned int width, unsigned int height,
unsigned int *hscale, unsigned int *vscale)
{
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
*hscale = (((unsigned long)maxw) << 12) / width - 4096L;
if (*hscale > EM28XX_HVSCALE_MAX)
*hscale = EM28XX_HVSCALE_MAX;
*vscale = (((unsigned long)maxh) << 12) / height - 4096L;
if (*vscale > EM28XX_HVSCALE_MAX)
*vscale = EM28XX_HVSCALE_MAX;
}
static void scale_to_size(struct em28xx *dev,
unsigned int hscale, unsigned int vscale,
unsigned int *width, unsigned int *height)
{
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
*width = (((unsigned long)maxw) << 12) / (hscale + 4096L);
*height = (((unsigned long)maxh) << 12) / (vscale + 4096L);
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
f->fmt.pix.width = v4l2->width;
f->fmt.pix.height = v4l2->height;
f->fmt.pix.pixelformat = v4l2->format->fourcc;
f->fmt.pix.bytesperline = (v4l2->width * v4l2->format->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * v4l2->height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
if (v4l2->progressive)
f->fmt.pix.field = V4L2_FIELD_NONE;
else
f->fmt.pix.field = v4l2->interlaced_fieldmode ?
V4L2_FIELD_INTERLACED : V4L2_FIELD_TOP;
return 0;
}
static struct em28xx_fmt *format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(format); i++)
if (format[i].fourcc == fourcc)
return &format[i];
return NULL;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
unsigned int width = f->fmt.pix.width;
unsigned int height = f->fmt.pix.height;
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
unsigned int hscale, vscale;
struct em28xx_fmt *fmt;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (!fmt) {
em28xx_videodbg("Fourcc format (%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
if (dev->board.is_em2800) {
height = height > (3 * maxh / 4) ? maxh : maxh / 2;
width = width > (3 * maxw / 4) ? maxw : maxw / 2;
if (width == maxw && height == maxh)
width /= 2;
} else {
v4l_bound_align_image(&width, 48, maxw, 1, &height, 32, maxh,
1, 0);
}
size_to_scale(dev, width, height, &hscale, &vscale);
scale_to_size(dev, hscale, vscale, &width, &height);
f->fmt.pix.width = width;
f->fmt.pix.height = height;
f->fmt.pix.pixelformat = fmt->fourcc;
f->fmt.pix.bytesperline = (width * fmt->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
if (v4l2->progressive)
f->fmt.pix.field = V4L2_FIELD_NONE;
else
f->fmt.pix.field = v4l2->interlaced_fieldmode ?
V4L2_FIELD_INTERLACED : V4L2_FIELD_TOP;
f->fmt.pix.priv = 0;
return 0;
}
static int em28xx_set_video_format(struct em28xx *dev, unsigned int fourcc,
unsigned width, unsigned height)
{
struct em28xx_fmt *fmt;
struct em28xx_v4l2 *v4l2 = dev->v4l2;
fmt = format_by_fourcc(fourcc);
if (!fmt)
return -EINVAL;
v4l2->format = fmt;
v4l2->width = width;
v4l2->height = height;
size_to_scale(dev, v4l2->width, v4l2->height,
&v4l2->hscale, &v4l2->vscale);
em28xx_resolution_set(dev);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (vb2_is_busy(&v4l2->vb_vidq))
return -EBUSY;
vidioc_try_fmt_vid_cap(file, priv, f);
return em28xx_set_video_format(dev, f->fmt.pix.pixelformat,
f->fmt.pix.width, f->fmt.pix.height);
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx *dev = video_drvdata(file);
*norm = dev->v4l2->norm;
return 0;
}
static int vidioc_querystd(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx *dev = video_drvdata(file);
v4l2_device_call_all(&dev->v4l2->v4l2_dev, 0, video, querystd, norm);
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id norm)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct v4l2_format f;
if (norm == v4l2->norm)
return 0;
if (v4l2->streaming_users > 0)
return -EBUSY;
v4l2->norm = norm;
f.fmt.pix.width = 720;
f.fmt.pix.height = (norm & V4L2_STD_525_60) ? 480 : 576;
vidioc_try_fmt_vid_cap(file, priv, &f);
v4l2->width = f.fmt.pix.width;
v4l2->height = f.fmt.pix.height;
size_to_scale(dev, v4l2->width, v4l2->height,
&v4l2->hscale, &v4l2->vscale);
em28xx_resolution_set(dev);
v4l2_device_call_all(&v4l2->v4l2_dev, 0, video, s_std, v4l2->norm);
return 0;
}
static int vidioc_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *p)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
int rc = 0;
p->parm.capture.readbuffers = EM28XX_MIN_BUF;
if (dev->board.is_webcam)
rc = v4l2_device_call_until_err(&v4l2->v4l2_dev, 0,
video, g_parm, p);
else
v4l2_video_std_frame_period(v4l2->norm,
&p->parm.capture.timeperframe);
return rc;
}
static int vidioc_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *p)
{
struct em28xx *dev = video_drvdata(file);
p->parm.capture.readbuffers = EM28XX_MIN_BUF;
return v4l2_device_call_until_err(&dev->v4l2->v4l2_dev,
0, video, s_parm, p);
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct em28xx *dev = video_drvdata(file);
unsigned int n;
n = i->index;
if (n >= MAX_EM28XX_INPUT)
return -EINVAL;
if (0 == INPUT(n)->type)
return -EINVAL;
i->index = n;
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name, iname[INPUT(n)->type]);
if ((EM28XX_VMUX_TELEVISION == INPUT(n)->type) ||
(EM28XX_VMUX_CABLE == INPUT(n)->type))
i->type = V4L2_INPUT_TYPE_TUNER;
i->std = dev->v4l2->vdev->tvnorms;
if (dev->board.is_webcam)
i->capabilities = 0;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct em28xx *dev = video_drvdata(file);
*i = dev->ctl_input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct em28xx *dev = video_drvdata(file);
if (i >= MAX_EM28XX_INPUT)
return -EINVAL;
if (0 == INPUT(i)->type)
return -EINVAL;
video_mux(dev, i);
return 0;
}
static int vidioc_g_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
struct em28xx *dev = video_drvdata(file);
switch (a->index) {
case EM28XX_AMUX_VIDEO:
strcpy(a->name, "Television");
break;
case EM28XX_AMUX_LINE_IN:
strcpy(a->name, "Line In");
break;
case EM28XX_AMUX_VIDEO2:
strcpy(a->name, "Television alt");
break;
case EM28XX_AMUX_PHONE:
strcpy(a->name, "Phone");
break;
case EM28XX_AMUX_MIC:
strcpy(a->name, "Mic");
break;
case EM28XX_AMUX_CD:
strcpy(a->name, "CD");
break;
case EM28XX_AMUX_AUX:
strcpy(a->name, "Aux");
break;
case EM28XX_AMUX_PCM_OUT:
strcpy(a->name, "PCM");
break;
default:
return -EINVAL;
}
a->index = dev->ctl_ainput;
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv, const struct v4l2_audio *a)
{
struct em28xx *dev = video_drvdata(file);
if (a->index >= MAX_EM28XX_INPUT)
return -EINVAL;
if (0 == INPUT(a->index)->type)
return -EINVAL;
dev->ctl_ainput = INPUT(a->index)->amux;
dev->ctl_aoutput = INPUT(a->index)->aout;
if (!dev->ctl_aoutput)
dev->ctl_aoutput = EM28XX_AOUT_MASTER;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct em28xx *dev = video_drvdata(file);
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Tuner");
v4l2_device_call_all(&dev->v4l2->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct em28xx *dev = video_drvdata(file);
if (0 != t->index)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (0 != f->tuner)
return -EINVAL;
f->frequency = v4l2->frequency;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct v4l2_frequency new_freq = *f;
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (0 != f->tuner)
return -EINVAL;
v4l2_device_call_all(&v4l2->v4l2_dev, 0, tuner, s_frequency, f);
v4l2_device_call_all(&v4l2->v4l2_dev, 0, tuner, g_frequency, &new_freq);
v4l2->frequency = new_freq.frequency;
return 0;
}
static int vidioc_g_chip_info(struct file *file, void *priv,
struct v4l2_dbg_chip_info *chip)
{
struct em28xx *dev = video_drvdata(file);
if (chip->match.addr > 1)
return -EINVAL;
if (chip->match.addr == 1)
strlcpy(chip->name, "ac97", sizeof(chip->name));
else
strlcpy(chip->name,
dev->v4l2->v4l2_dev.name, sizeof(chip->name));
return 0;
}
static int em28xx_reg_len(int reg)
{
switch (reg) {
case EM28XX_R40_AC97LSB:
case EM28XX_R30_HSCALELOW:
case EM28XX_R32_VSCALELOW:
return 2;
default:
return 1;
}
}
static int vidioc_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct em28xx *dev = video_drvdata(file);
int ret;
if (reg->match.addr > 1)
return -EINVAL;
if (reg->match.addr) {
ret = em28xx_read_ac97(dev, reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
reg->size = 1;
return 0;
}
reg->size = em28xx_reg_len(reg->reg);
if (reg->size == 1) {
ret = em28xx_read_reg(dev, reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
} else {
__le16 val = 0;
ret = dev->em28xx_read_reg_req_len(dev, USB_REQ_GET_STATUS,
reg->reg, (char *)&val, 2);
if (ret < 0)
return ret;
reg->val = le16_to_cpu(val);
}
return 0;
}
static int vidioc_s_register(struct file *file, void *priv,
const struct v4l2_dbg_register *reg)
{
struct em28xx *dev = video_drvdata(file);
__le16 buf;
if (reg->match.addr > 1)
return -EINVAL;
if (reg->match.addr)
return em28xx_write_ac97(dev, reg->reg, reg->val);
buf = cpu_to_le16(reg->val);
return em28xx_write_regs(dev, reg->reg, (char *)&buf,
em28xx_reg_len(reg->reg));
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
strlcpy(cap->driver, "em28xx", sizeof(cap->driver));
strlcpy(cap->card, em28xx_boards[dev->model].name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
if (vdev->vfl_type == VFL_TYPE_GRABBER)
cap->device_caps = V4L2_CAP_READWRITE |
V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
else if (vdev->vfl_type == VFL_TYPE_RADIO)
cap->device_caps = V4L2_CAP_RADIO;
else
cap->device_caps = V4L2_CAP_READWRITE | V4L2_CAP_VBI_CAPTURE;
if (dev->int_audio_type != EM28XX_INT_AUDIO_NONE)
cap->device_caps |= V4L2_CAP_AUDIO;
if (dev->tuner_type != TUNER_ABSENT)
cap->device_caps |= V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS |
V4L2_CAP_READWRITE | V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
if (v4l2->vbi_dev)
cap->capabilities |= V4L2_CAP_VBI_CAPTURE;
if (v4l2->radio_dev)
cap->capabilities |= V4L2_CAP_RADIO;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (unlikely(f->index >= ARRAY_SIZE(format)))
return -EINVAL;
strlcpy(f->description, format[f->index].name, sizeof(f->description));
f->pixelformat = format[f->index].fourcc;
return 0;
}
static int vidioc_enum_framesizes(struct file *file, void *priv,
struct v4l2_frmsizeenum *fsize)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_fmt *fmt;
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
fmt = format_by_fourcc(fsize->pixel_format);
if (!fmt) {
em28xx_videodbg("Fourcc format (%08x) invalid.\n",
fsize->pixel_format);
return -EINVAL;
}
if (dev->board.is_em2800) {
if (fsize->index > 1)
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = maxw / (1 + fsize->index);
fsize->discrete.height = maxh / (1 + fsize->index);
return 0;
}
if (fsize->index != 0)
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_STEPWISE;
scale_to_size(dev, EM28XX_HVSCALE_MAX, EM28XX_HVSCALE_MAX,
&fsize->stepwise.min_width, &fsize->stepwise.min_height);
if (fsize->stepwise.min_width < 48)
fsize->stepwise.min_width = 48;
if (fsize->stepwise.min_height < 38)
fsize->stepwise.min_height = 38;
fsize->stepwise.max_width = maxw;
fsize->stepwise.max_height = maxh;
fsize->stepwise.step_width = 1;
fsize->stepwise.step_height = 1;
return 0;
}
static int vidioc_g_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *format)
{
struct em28xx *dev = video_drvdata(file);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
format->fmt.vbi.samples_per_line = v4l2->vbi_width;
format->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
format->fmt.vbi.offset = 0;
format->fmt.vbi.flags = 0;
format->fmt.vbi.sampling_rate = 6750000 * 4 / 2;
format->fmt.vbi.count[0] = v4l2->vbi_height;
format->fmt.vbi.count[1] = v4l2->vbi_height;
memset(format->fmt.vbi.reserved, 0, sizeof(format->fmt.vbi.reserved));
if (v4l2->norm & V4L2_STD_525_60) {
format->fmt.vbi.start[0] = 10;
format->fmt.vbi.start[1] = 273;
} else if (v4l2->norm & V4L2_STD_625_50) {
format->fmt.vbi.start[0] = 6;
format->fmt.vbi.start[1] = 318;
}
return 0;
}
static int radio_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct em28xx *dev = video_drvdata(file);
if (unlikely(t->index > 0))
return -EINVAL;
strcpy(t->name, "Radio");
v4l2_device_call_all(&dev->v4l2->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int radio_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct em28xx *dev = video_drvdata(file);
if (0 != t->index)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static void em28xx_free_v4l2(struct kref *ref)
{
struct em28xx_v4l2 *v4l2 = container_of(ref, struct em28xx_v4l2, ref);
v4l2->dev->v4l2 = NULL;
kfree(v4l2);
}
static int em28xx_v4l2_open(struct file *filp)
{
struct video_device *vdev = video_devdata(filp);
struct em28xx *dev = video_drvdata(filp);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
enum v4l2_buf_type fh_type = 0;
int ret;
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
fh_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
fh_type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
case VFL_TYPE_RADIO:
break;
default:
return -EINVAL;
}
em28xx_videodbg("open dev=%s type=%s users=%d\n",
video_device_node_name(vdev), v4l2_type_names[fh_type],
v4l2->users);
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
ret = v4l2_fh_open(filp);
if (ret) {
em28xx_errdev("%s: v4l2_fh_open() returned error %d\n",
__func__, ret);
mutex_unlock(&dev->lock);
return ret;
}
if (v4l2->users == 0) {
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
if (vdev->vfl_type != VFL_TYPE_RADIO)
em28xx_resolution_set(dev);
em28xx_wake_i2c(dev);
}
if (vdev->vfl_type == VFL_TYPE_RADIO) {
em28xx_videodbg("video_open: setting radio device\n");
v4l2_device_call_all(&v4l2->v4l2_dev, 0, tuner, s_radio);
}
kref_get(&dev->ref);
kref_get(&v4l2->ref);
v4l2->users++;
mutex_unlock(&dev->lock);
return 0;
}
static int em28xx_v4l2_fini(struct em28xx *dev)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
if (dev->is_audio_only) {
return 0;
}
if (!dev->has_video) {
return 0;
}
if (v4l2 == NULL)
return 0;
em28xx_info("Closing video extension");
mutex_lock(&dev->lock);
v4l2_device_disconnect(&v4l2->v4l2_dev);
em28xx_uninit_usb_xfer(dev, EM28XX_ANALOG_MODE);
if (v4l2->radio_dev) {
em28xx_info("V4L2 device %s deregistered\n",
video_device_node_name(v4l2->radio_dev));
video_unregister_device(v4l2->radio_dev);
}
if (v4l2->vbi_dev) {
em28xx_info("V4L2 device %s deregistered\n",
video_device_node_name(v4l2->vbi_dev));
video_unregister_device(v4l2->vbi_dev);
}
if (v4l2->vdev) {
em28xx_info("V4L2 device %s deregistered\n",
video_device_node_name(v4l2->vdev));
video_unregister_device(v4l2->vdev);
}
v4l2_ctrl_handler_free(&v4l2->ctrl_handler);
v4l2_device_unregister(&v4l2->v4l2_dev);
if (v4l2->clk) {
v4l2_clk_unregister_fixed(v4l2->clk);
v4l2->clk = NULL;
}
kref_put(&v4l2->ref, em28xx_free_v4l2);
mutex_unlock(&dev->lock);
kref_put(&dev->ref, em28xx_free_device);
return 0;
}
static int em28xx_v4l2_suspend(struct em28xx *dev)
{
if (dev->is_audio_only)
return 0;
if (!dev->has_video)
return 0;
em28xx_info("Suspending video extension");
em28xx_stop_urbs(dev);
return 0;
}
static int em28xx_v4l2_resume(struct em28xx *dev)
{
if (dev->is_audio_only)
return 0;
if (!dev->has_video)
return 0;
em28xx_info("Resuming video extension");
return 0;
}
static int em28xx_v4l2_close(struct file *filp)
{
struct em28xx *dev = video_drvdata(filp);
struct em28xx_v4l2 *v4l2 = dev->v4l2;
int errCode;
em28xx_videodbg("users=%d\n", v4l2->users);
vb2_fop_release(filp);
mutex_lock(&dev->lock);
if (v4l2->users == 1) {
if (dev->disconnected)
goto exit;
v4l2_device_call_all(&v4l2->v4l2_dev, 0, core, s_power, 0);
em28xx_set_mode(dev, EM28XX_SUSPEND);
dev->alt = 0;
em28xx_videodbg("setting alternate 0\n");
errCode = usb_set_interface(dev->udev, 0, 0);
if (errCode < 0) {
em28xx_errdev("cannot change alternate number to "
"0 (error=%i)\n", errCode);
}
}
exit:
v4l2->users--;
kref_put(&v4l2->ref, em28xx_free_v4l2);
mutex_unlock(&dev->lock);
kref_put(&dev->ref, em28xx_free_device);
return 0;
}
static struct video_device *em28xx_vdev_init(struct em28xx *dev,
const struct video_device *template,
const char *type_name)
{
struct video_device *vfd;
vfd = video_device_alloc();
if (NULL == vfd)
return NULL;
*vfd = *template;
vfd->v4l2_dev = &dev->v4l2->v4l2_dev;
vfd->debug = video_debug;
vfd->lock = &dev->lock;
if (dev->board.is_webcam)
vfd->tvnorms = 0;
snprintf(vfd->name, sizeof(vfd->name), "%s %s",
dev->name, type_name);
video_set_drvdata(vfd, dev);
return vfd;
}
static void em28xx_tuner_setup(struct em28xx *dev, unsigned short tuner_addr)
{
struct em28xx_v4l2 *v4l2 = dev->v4l2;
struct v4l2_device *v4l2_dev = &v4l2->v4l2_dev;
struct tuner_setup tun_setup;
struct v4l2_frequency f;
memset(&tun_setup, 0, sizeof(tun_setup));
tun_setup.mode_mask = T_ANALOG_TV | T_RADIO;
tun_setup.tuner_callback = em28xx_tuner_callback;
if (dev->board.radio.type) {
tun_setup.type = dev->board.radio.type;
tun_setup.addr = dev->board.radio_addr;
v4l2_device_call_all(v4l2_dev,
0, tuner, s_type_addr, &tun_setup);
}
if ((dev->tuner_type != TUNER_ABSENT) && (dev->tuner_type)) {
tun_setup.type = dev->tuner_type;
tun_setup.addr = tuner_addr;
v4l2_device_call_all(v4l2_dev,
0, tuner, s_type_addr, &tun_setup);
}
if (dev->board.tda9887_conf) {
struct v4l2_priv_tun_config tda9887_cfg;
tda9887_cfg.tuner = TUNER_TDA9887;
tda9887_cfg.priv = &dev->board.tda9887_conf;
v4l2_device_call_all(v4l2_dev,
0, tuner, s_config, &tda9887_cfg);
}
if (dev->tuner_type == TUNER_XC2028) {
struct v4l2_priv_tun_config xc2028_cfg;
struct xc2028_ctrl ctl;
memset(&xc2028_cfg, 0, sizeof(xc2028_cfg));
memset(&ctl, 0, sizeof(ctl));
em28xx_setup_xc3028(dev, &ctl);
xc2028_cfg.tuner = TUNER_XC2028;
xc2028_cfg.priv = &ctl;
v4l2_device_call_all(v4l2_dev, 0, tuner, s_config, &xc2028_cfg);
}
f.tuner = 0;
f.type = V4L2_TUNER_ANALOG_TV;
f.frequency = 9076;
v4l2->frequency = f.frequency;
v4l2_device_call_all(v4l2_dev, 0, tuner, s_frequency, &f);
}
static int em28xx_v4l2_init(struct em28xx *dev)
{
u8 val;
int ret;
unsigned int maxw;
struct v4l2_ctrl_handler *hdl;
struct em28xx_v4l2 *v4l2;
if (dev->is_audio_only) {
return 0;
}
if (!dev->has_video) {
return 0;
}
em28xx_info("Registering V4L2 extension\n");
mutex_lock(&dev->lock);
v4l2 = kzalloc(sizeof(struct em28xx_v4l2), GFP_KERNEL);
if (v4l2 == NULL) {
em28xx_info("em28xx_v4l: memory allocation failed\n");
mutex_unlock(&dev->lock);
return -ENOMEM;
}
kref_init(&v4l2->ref);
v4l2->dev = dev;
dev->v4l2 = v4l2;
ret = v4l2_device_register(&dev->udev->dev, &v4l2->v4l2_dev);
if (ret < 0) {
em28xx_errdev("Call to v4l2_device_register() failed!\n");
goto err;
}
hdl = &v4l2->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 8);
v4l2->v4l2_dev.ctrl_handler = hdl;
if (dev->board.is_webcam)
v4l2->progressive = true;
v4l2->vinmode = 0x10;
v4l2->vinctl = EM28XX_VINCTRL_INTERLACED |
EM28XX_VINCTRL_CCIR656_ENABLE;
if (dev->board.has_msp34xx)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"msp3400", 0, msp3400_addrs);
if (dev->board.decoder == EM28XX_SAA711X)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"saa7115_auto", 0, saa711x_addrs);
if (dev->board.decoder == EM28XX_TVP5150)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"tvp5150", 0, tvp5150_addrs);
if (dev->board.adecoder == EM28XX_TVAUDIO)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"tvaudio", dev->board.tvaudio_addr, NULL);
if (dev->board.tuner_type != TUNER_ABSENT) {
unsigned short tuner_addr = dev->board.tuner_addr;
int has_demod = (dev->board.tda9887_conf & TDA9887_PRESENT);
if (dev->board.radio.type)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"tuner", dev->board.radio_addr, NULL);
if (has_demod)
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus], "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
if (tuner_addr == 0) {
enum v4l2_i2c_tuner_type type =
has_demod ? ADDRS_TV_WITH_DEMOD : ADDRS_TV;
struct v4l2_subdev *sd;
sd = v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus], "tuner",
0, v4l2_i2c_tuner_addrs(type));
if (sd)
tuner_addr = v4l2_i2c_subdev_addr(sd);
} else {
v4l2_i2c_new_subdev(&v4l2->v4l2_dev,
&dev->i2c_adap[dev->def_i2c_bus],
"tuner", tuner_addr, NULL);
}
em28xx_tuner_setup(dev, tuner_addr);
}
if (dev->em28xx_sensor != EM28XX_NOSENSOR)
em28xx_init_camera(dev);
ret = em28xx_audio_setup(dev);
if (ret < 0) {
em28xx_errdev("%s: Error while setting audio - error [%d]!\n",
__func__, ret);
goto unregister_dev;
}
if (dev->audio_mode.ac97 != EM28XX_NO_AC97) {
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 0x1f, 1, 0x1f);
} else {
v4l2_ctrl_notify(v4l2_ctrl_find(hdl, V4L2_CID_AUDIO_MUTE),
em28xx_ctrl_notify, dev);
v4l2_ctrl_notify(v4l2_ctrl_find(hdl, V4L2_CID_AUDIO_VOLUME),
em28xx_ctrl_notify, dev);
}
em28xx_wake_i2c(dev);
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vbiq.active);
if (dev->board.has_msp34xx) {
ret = em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xf7);
if (ret < 0) {
em28xx_errdev("%s: em28xx_write_reg - msp34xx(1) failed! error [%d]\n",
__func__, ret);
goto unregister_dev;
}
msleep(3);
ret = em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xff);
if (ret < 0) {
em28xx_errdev("%s: em28xx_write_reg - msp34xx(2) failed! error [%d]\n",
__func__, ret);
goto unregister_dev;
}
msleep(3);
}
v4l2->norm = V4L2_STD_PAL;
v4l2_device_call_all(&v4l2->v4l2_dev, 0, video, s_std, v4l2->norm);
v4l2->interlaced_fieldmode = EM28XX_INTERLACED_DEFAULT;
v4l2->format = &format[0];
maxw = norm_maxw(dev);
if (dev->board.is_em2800)
maxw /= 2;
em28xx_set_video_format(dev, format[0].fourcc,
maxw, norm_maxh(dev));
video_mux(dev, 0);
dev->mute = 1;
dev->volume = 0x1f;
val = (u8)em28xx_read_reg(dev, EM28XX_R0F_XCLK);
em28xx_write_reg(dev, EM28XX_R0F_XCLK,
(EM28XX_XCLK_AUDIO_UNMUTE | val));
em28xx_set_outfmt(dev);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_CONTRAST))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_CONTRAST,
0, 0x1f, 1, CONTRAST_DEFAULT);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_BRIGHTNESS))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_BRIGHTNESS,
-0x80, 0x7f, 1, BRIGHTNESS_DEFAULT);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_SATURATION))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_SATURATION,
0, 0x1f, 1, SATURATION_DEFAULT);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_BLUE_BALANCE))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_BLUE_BALANCE,
-0x30, 0x30, 1, BLUE_BALANCE_DEFAULT);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_RED_BALANCE))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_RED_BALANCE,
-0x30, 0x30, 1, RED_BALANCE_DEFAULT);
if (NULL == v4l2_ctrl_find(hdl, V4L2_CID_SHARPNESS))
v4l2_ctrl_new_std(hdl, &em28xx_ctrl_ops,
V4L2_CID_SHARPNESS,
0, 0x0f, 1, SHARPNESS_DEFAULT);
em28xx_colorlevels_set_default(dev);
v4l2_ctrl_handler_setup(hdl);
ret = hdl->error;
if (ret)
goto unregister_dev;
v4l2->vdev = em28xx_vdev_init(dev, &em28xx_video_template, "video");
if (!v4l2->vdev) {
em28xx_errdev("cannot allocate video_device.\n");
ret = -ENODEV;
goto unregister_dev;
}
mutex_init(&v4l2->vb_queue_lock);
mutex_init(&v4l2->vb_vbi_queue_lock);
v4l2->vdev->queue = &v4l2->vb_vidq;
v4l2->vdev->queue->lock = &v4l2->vb_queue_lock;
if (dev->board.is_webcam) {
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_QUERYSTD);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_G_STD);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_S_STD);
} else {
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_S_PARM);
}
if (dev->tuner_type == TUNER_ABSENT) {
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_G_TUNER);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_S_TUNER);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_S_FREQUENCY);
}
if (dev->int_audio_type == EM28XX_INT_AUDIO_NONE) {
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_G_AUDIO);
v4l2_disable_ioctl(v4l2->vdev, VIDIOC_S_AUDIO);
}
ret = video_register_device(v4l2->vdev, VFL_TYPE_GRABBER,
video_nr[dev->devno]);
if (ret) {
em28xx_errdev("unable to register video device (error=%i).\n",
ret);
goto unregister_dev;
}
if (em28xx_vbi_supported(dev) == 1) {
v4l2->vbi_dev = em28xx_vdev_init(dev, &em28xx_video_template,
"vbi");
v4l2->vbi_dev->queue = &v4l2->vb_vbiq;
v4l2->vbi_dev->queue->lock = &v4l2->vb_vbi_queue_lock;
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_S_PARM);
if (dev->tuner_type == TUNER_ABSENT) {
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_G_TUNER);
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_S_TUNER);
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_S_FREQUENCY);
}
if (dev->int_audio_type == EM28XX_INT_AUDIO_NONE) {
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_G_AUDIO);
v4l2_disable_ioctl(v4l2->vbi_dev, VIDIOC_S_AUDIO);
}
ret = video_register_device(v4l2->vbi_dev, VFL_TYPE_VBI,
vbi_nr[dev->devno]);
if (ret < 0) {
em28xx_errdev("unable to register vbi device\n");
goto unregister_dev;
}
}
if (em28xx_boards[dev->model].radio.type == EM28XX_RADIO) {
v4l2->radio_dev = em28xx_vdev_init(dev, &em28xx_radio_template,
"radio");
if (!v4l2->radio_dev) {
em28xx_errdev("cannot allocate video_device.\n");
ret = -ENODEV;
goto unregister_dev;
}
ret = video_register_device(v4l2->radio_dev, VFL_TYPE_RADIO,
radio_nr[dev->devno]);
if (ret < 0) {
em28xx_errdev("can't register radio device\n");
goto unregister_dev;
}
em28xx_info("Registered radio device as %s\n",
video_device_node_name(v4l2->radio_dev));
}
em28xx_info("V4L2 video device registered as %s\n",
video_device_node_name(v4l2->vdev));
if (v4l2->vbi_dev)
em28xx_info("V4L2 VBI device registered as %s\n",
video_device_node_name(v4l2->vbi_dev));
v4l2_device_call_all(&v4l2->v4l2_dev, 0, core, s_power, 0);
em28xx_vb2_setup(dev);
em28xx_info("V4L2 extension successfully initialized\n");
kref_get(&dev->ref);
mutex_unlock(&dev->lock);
return 0;
unregister_dev:
v4l2_ctrl_handler_free(&v4l2->ctrl_handler);
v4l2_device_unregister(&v4l2->v4l2_dev);
err:
dev->v4l2 = NULL;
kref_put(&v4l2->ref, em28xx_free_v4l2);
mutex_unlock(&dev->lock);
return ret;
}
static int __init em28xx_video_register(void)
{
return em28xx_register_extension(&v4l2_ops);
}
static void __exit em28xx_video_unregister(void)
{
em28xx_unregister_extension(&v4l2_ops);
}
