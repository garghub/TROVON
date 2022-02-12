static inline void finish_buffer(struct em28xx *dev,
struct em28xx_buffer *buf)
{
em28xx_isocdbg("[%p/%d] wakeup\n", buf, buf->top_field);
buf->vb.v4l2_buf.sequence = dev->field_count++;
buf->vb.v4l2_buf.field = V4L2_FIELD_INTERLACED;
v4l2_get_timestamp(&buf->vb.v4l2_buf.timestamp);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_DONE);
}
static void em28xx_copy_video(struct em28xx *dev,
struct em28xx_buffer *buf,
unsigned char *usb_buf,
unsigned long len)
{
void *fieldstart, *startwrite, *startread;
int linesdone, currlinedone, offset, lencopy, remain;
int bytesperline = dev->width << 1;
if (buf->pos + len > buf->length)
len = buf->length - buf->pos;
startread = usb_buf;
remain = len;
if (dev->progressive || buf->top_field)
fieldstart = buf->vb_buf;
else
fieldstart = buf->vb_buf + bytesperline;
linesdone = buf->pos / bytesperline;
currlinedone = buf->pos % bytesperline;
if (dev->progressive)
offset = linesdone * bytesperline + currlinedone;
else
offset = linesdone * bytesperline * 2 + currlinedone;
startwrite = fieldstart + offset;
lencopy = bytesperline - currlinedone;
lencopy = lencopy > remain ? remain : lencopy;
if ((char *)startwrite + lencopy > (char *)buf->vb_buf + buf->length) {
em28xx_isocdbg("Overflow of %zi bytes past buffer end (1)\n",
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
if (dev->progressive)
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
em28xx_isocdbg("Overflow of %zi bytes past buffer end"
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
offset += dev->vbi_width * dev->vbi_height;
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
if (dev->progressive || dev->top_field) {
if (buf != NULL)
finish_buffer(dev, buf);
buf = get_next_buf(dev, dma_q);
}
if (buf != NULL) {
buf->top_field = dev->top_field;
buf->pos = 0;
}
return buf;
}
static inline void process_frame_data_em28xx(struct em28xx *dev,
unsigned char *data_pkt,
unsigned int data_len)
{
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
dev->capture_type = 0;
dev->vbi_read = 0;
em28xx_isocdbg("VBI START HEADER !!!\n");
dev->top_field = !(data_pkt[2] & 1);
data_pkt += 4;
data_len -= 4;
} else if (data_pkt[0] == 0x22 && data_pkt[1] == 0x5a) {
dev->capture_type = 2;
em28xx_isocdbg("VIDEO START HEADER !!!\n");
dev->top_field = !(data_pkt[2] & 1);
data_pkt += 4;
data_len -= 4;
}
}
if (dev->capture_type == 0) {
vbi_buf = finish_field_prepare_next(dev, vbi_buf, vbi_dma_q);
dev->usb_ctl.vbi_buf = vbi_buf;
dev->capture_type = 1;
}
if (dev->capture_type == 1) {
int vbi_size = dev->vbi_width * dev->vbi_height;
int vbi_data_len = ((dev->vbi_read + data_len) > vbi_size) ?
(vbi_size - dev->vbi_read) : data_len;
if (vbi_buf != NULL)
em28xx_copy_vbi(dev, vbi_buf, data_pkt, vbi_data_len);
dev->vbi_read += vbi_data_len;
if (vbi_data_len < data_len) {
dev->capture_type = 2;
data_pkt += vbi_data_len;
data_len -= vbi_data_len;
}
}
if (dev->capture_type == 2) {
buf = finish_field_prepare_next(dev, buf, dma_q);
dev->usb_ctl.vid_buf = buf;
dev->capture_type = 3;
}
if (dev->capture_type == 3 && buf != NULL && data_len > 0)
em28xx_copy_video(dev, buf, data_pkt, data_len);
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
process_frame_data_em28xx(dev, usb_data_pkt, usb_data_len);
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
unsigned long size;
if (fmt)
size = fmt->fmt.pix.sizeimage;
else
size = (dev->width * dev->height * dev->format->depth + 7) >> 3;
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
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
unsigned long size;
em28xx_videodbg("%s, field=%d\n", __func__, vb->v4l2_buf.field);
size = (dev->width * dev->height * dev->format->depth + 7) >> 3;
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
struct v4l2_frequency f;
int rc = 0;
em28xx_videodbg("%s\n", __func__);
rc = res_get(dev, vq->type);
if (rc)
return rc;
if (dev->streaming_users++ == 0) {
em28xx_set_alternate(dev);
em28xx_wake_i2c(dev);
dev->capture_type = -1;
rc = em28xx_init_usb_xfer(dev, EM28XX_ANALOG_MODE,
dev->analog_xfer_bulk,
EM28XX_NUM_BUFS,
dev->max_pkt_size,
dev->packet_multiplier,
em28xx_urb_data_copy);
if (rc < 0)
goto fail;
memset(&f, 0, sizeof(f));
f.frequency = dev->ctl_freq;
if (vq->owner && vq->owner->vdev->vfl_type == VFL_TYPE_RADIO)
f.type = V4L2_TUNER_RADIO;
else
f.type = V4L2_TUNER_ANALOG_TV;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, &f);
}
fail:
return rc;
}
static int em28xx_stop_streaming(struct vb2_queue *vq)
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_dmaqueue *vidq = &dev->vidq;
unsigned long flags = 0;
em28xx_videodbg("%s\n", __func__);
res_free(dev, vq->type);
if (dev->streaming_users-- == 1) {
em28xx_uninit_usb_xfer(dev, EM28XX_ANALOG_MODE);
}
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&vidq->active)) {
struct em28xx_buffer *buf;
buf = list_entry(vidq->active.next, struct em28xx_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
dev->usb_ctl.vid_buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
int em28xx_stop_vbi_streaming(struct vb2_queue *vq)
{
struct em28xx *dev = vb2_get_drv_priv(vq);
struct em28xx_dmaqueue *vbiq = &dev->vbiq;
unsigned long flags = 0;
em28xx_videodbg("%s\n", __func__);
res_free(dev, vq->type);
if (dev->streaming_users-- == 1) {
em28xx_uninit_usb_xfer(dev, EM28XX_ANALOG_MODE);
}
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&vbiq->active)) {
struct em28xx_buffer *buf;
buf = list_entry(vbiq->active.next, struct em28xx_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
dev->usb_ctl.vbi_buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
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
int em28xx_vb2_setup(struct em28xx *dev)
{
int rc;
struct vb2_queue *q;
q = &dev->vb_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_READ | VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct em28xx_buffer);
q->ops = &em28xx_video_qops;
q->mem_ops = &vb2_vmalloc_memops;
rc = vb2_queue_init(q);
if (rc < 0)
return rc;
q = &dev->vb_vbiq;
q->type = V4L2_BUF_TYPE_VBI_CAPTURE;
q->io_modes = VB2_READ | VB2_MMAP | VB2_USERPTR;
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
dev->ctl_input = index;
dev->ctl_ainput = INPUT(index)->amux;
dev->ctl_aoutput = INPUT(index)->aout;
if (!dev->ctl_aoutput)
dev->ctl_aoutput = EM28XX_AOUT_MASTER;
v4l2_device_call_all(&dev->v4l2_dev, 0, video, s_routing,
INPUT(index)->vmux, 0, 0);
if (dev->board.has_msp34xx) {
if (dev->i2s_speed) {
v4l2_device_call_all(&dev->v4l2_dev, 0, audio,
s_i2s_clock_freq, dev->i2s_speed);
}
v4l2_device_call_all(&dev->v4l2_dev, 0, audio, s_routing,
dev->ctl_ainput, MSP_OUTPUT(MSP_SC_IN_DSP_SCART1), 0);
}
if (dev->board.adecoder != EM28XX_NOADECODER) {
v4l2_device_call_all(&dev->v4l2_dev, 0, audio, s_routing,
dev->ctl_ainput, dev->ctl_aoutput, 0);
}
em28xx_audio_analog_set(dev);
}
void em28xx_ctrl_notify(struct v4l2_ctrl *ctrl, void *priv)
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
struct em28xx *dev = container_of(ctrl->handler, struct em28xx, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
dev->mute = ctrl->val;
break;
case V4L2_CID_AUDIO_VOLUME:
dev->volume = ctrl->val;
break;
}
return em28xx_audio_analog_set(dev);
}
static int check_dev(struct em28xx *dev)
{
if (dev->disconnected) {
em28xx_errdev("v4l2 ioctl: device not present\n");
return -ENODEV;
}
return 0;
}
static void get_scale(struct em28xx *dev,
unsigned int width, unsigned int height,
unsigned int *hscale, unsigned int *vscale)
{
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
*hscale = (((unsigned long)maxw) << 12) / width - 4096L;
if (*hscale >= 0x4000)
*hscale = 0x3fff;
*vscale = (((unsigned long)maxh) << 12) / height - 4096L;
if (*vscale >= 0x4000)
*vscale = 0x3fff;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.pixelformat = dev->format->fourcc;
f->fmt.pix.bytesperline = (dev->width * dev->format->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * dev->height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
if (dev->progressive)
f->fmt.pix.field = V4L2_FIELD_NONE;
else
f->fmt.pix.field = dev->interlaced ?
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
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
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
get_scale(dev, width, height, &hscale, &vscale);
width = (((unsigned long)maxw) << 12) / (hscale + 4096L);
height = (((unsigned long)maxh) << 12) / (vscale + 4096L);
f->fmt.pix.width = width;
f->fmt.pix.height = height;
f->fmt.pix.pixelformat = fmt->fourcc;
f->fmt.pix.bytesperline = (width * fmt->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
if (dev->progressive)
f->fmt.pix.field = V4L2_FIELD_NONE;
else
f->fmt.pix.field = dev->interlaced ?
V4L2_FIELD_INTERLACED : V4L2_FIELD_TOP;
return 0;
}
static int em28xx_set_video_format(struct em28xx *dev, unsigned int fourcc,
unsigned width, unsigned height)
{
struct em28xx_fmt *fmt;
fmt = format_by_fourcc(fourcc);
if (!fmt)
return -EINVAL;
dev->format = fmt;
dev->width = width;
dev->height = height;
get_scale(dev, dev->width, dev->height, &dev->hscale, &dev->vscale);
em28xx_resolution_set(dev);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx *dev = video_drvdata(file);
if (dev->streaming_users > 0)
return -EBUSY;
vidioc_try_fmt_vid_cap(file, priv, f);
return em28xx_set_video_format(dev, f->fmt.pix.pixelformat,
f->fmt.pix.width, f->fmt.pix.height);
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
if (dev->board.is_webcam)
return -ENOTTY;
rc = check_dev(dev);
if (rc < 0)
return rc;
*norm = dev->norm;
return 0;
}
static int vidioc_querystd(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
if (dev->board.is_webcam)
return -ENOTTY;
rc = check_dev(dev);
if (rc < 0)
return rc;
v4l2_device_call_all(&dev->v4l2_dev, 0, video, querystd, norm);
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
struct v4l2_format f;
int rc;
if (dev->board.is_webcam)
return -ENOTTY;
if (*norm == dev->norm)
return 0;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (dev->streaming_users > 0)
return -EBUSY;
dev->norm = *norm;
f.fmt.pix.width = 720;
f.fmt.pix.height = (*norm & V4L2_STD_525_60) ? 480 : 576;
vidioc_try_fmt_vid_cap(file, priv, &f);
dev->width = f.fmt.pix.width;
dev->height = f.fmt.pix.height;
get_scale(dev, dev->width, dev->height, &dev->hscale, &dev->vscale);
em28xx_resolution_set(dev);
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std, dev->norm);
return 0;
}
static int vidioc_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *p)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc = 0;
if (p->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
p->parm.capture.readbuffers = EM28XX_MIN_BUF;
if (dev->board.is_webcam)
rc = v4l2_device_call_until_err(&dev->v4l2_dev, 0,
video, g_parm, p);
else
v4l2_video_std_frame_period(dev->norm,
&p->parm.capture.timeperframe);
return rc;
}
static int vidioc_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *p)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
if (!dev->board.is_webcam)
return -ENOTTY;
if (p->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
p->parm.capture.readbuffers = EM28XX_MIN_BUF;
return v4l2_device_call_until_err(&dev->v4l2_dev, 0, video, s_parm, p);
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
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
i->std = dev->vdev->tvnorms;
if (dev->board.is_webcam)
i->capabilities = 0;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
*i = dev->ctl_input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (i >= MAX_EM28XX_INPUT)
return -EINVAL;
if (0 == INPUT(i)->type)
return -EINVAL;
video_mux(dev, i);
return 0;
}
static int vidioc_g_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
if (!dev->audio_mode.has_audio)
return -EINVAL;
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
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
if (!dev->audio_mode.has_audio)
return -EINVAL;
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
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Tuner");
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != t->index)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
if (0 != f->tuner)
return -EINVAL;
f->frequency = dev->ctl_freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != f->tuner)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, f);
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_frequency, f);
dev->ctl_freq = f->frequency;
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
static int vidioc_g_chip_ident(struct file *file, void *priv,
struct v4l2_dbg_chip_ident *chip)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
if (chip->match.type == V4L2_CHIP_MATCH_HOST) {
if (v4l2_chip_match_host(&chip->match))
chip->ident = V4L2_IDENT_NONE;
return 0;
}
if (chip->match.type != V4L2_CHIP_MATCH_I2C_DRIVER &&
chip->match.type != V4L2_CHIP_MATCH_I2C_ADDR)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_chip_ident, chip);
return 0;
}
static int vidioc_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int ret;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_AC97:
ret = em28xx_read_ac97(dev, reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
reg->size = 1;
return 0;
case V4L2_CHIP_MATCH_I2C_DRIVER:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_register, reg);
return 0;
case V4L2_CHIP_MATCH_I2C_ADDR:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_register, reg);
return 0;
default:
if (!v4l2_chip_match_host(&reg->match))
return -EINVAL;
}
reg->size = em28xx_reg_len(reg->reg);
if (reg->size == 1) {
ret = em28xx_read_reg(dev, reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
} else {
__le16 val = 0;
ret = em28xx_read_reg_req_len(dev, USB_REQ_GET_STATUS,
reg->reg, (char *)&val, 2);
if (ret < 0)
return ret;
reg->val = le16_to_cpu(val);
}
return 0;
}
static int vidioc_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
__le16 buf;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_AC97:
return em28xx_write_ac97(dev, reg->reg, reg->val);
case V4L2_CHIP_MATCH_I2C_DRIVER:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_register, reg);
return 0;
case V4L2_CHIP_MATCH_I2C_ADDR:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_register, reg);
return 0;
default:
if (!v4l2_chip_match_host(&reg->match))
return -EINVAL;
}
buf = cpu_to_le16(reg->val);
return em28xx_write_regs(dev, reg->reg, (char *)&buf,
em28xx_reg_len(reg->reg));
}
static int vidioc_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *cc)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
if (cc->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
cc->bounds.left = 0;
cc->bounds.top = 0;
cc->bounds.width = dev->width;
cc->bounds.height = dev->height;
cc->defrect = cc->bounds;
cc->pixelaspect.numerator = 54;
cc->pixelaspect.denominator = 59;
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
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
if (dev->audio_mode.has_audio)
cap->device_caps |= V4L2_CAP_AUDIO;
if (dev->tuner_type != TUNER_ABSENT)
cap->device_caps |= V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS |
V4L2_CAP_READWRITE | V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
if (dev->vbi_dev)
cap->capabilities |= V4L2_CAP_VBI_CAPTURE;
if (dev->radio_dev)
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
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
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
fsize->stepwise.min_width = 48;
fsize->stepwise.min_height = 32;
fsize->stepwise.max_width = maxw;
fsize->stepwise.max_height = maxh;
fsize->stepwise.step_width = 1;
fsize->stepwise.step_height = 1;
return 0;
}
static int vidioc_g_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *format)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
format->fmt.vbi.samples_per_line = dev->vbi_width;
format->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
format->fmt.vbi.offset = 0;
format->fmt.vbi.flags = 0;
format->fmt.vbi.sampling_rate = 6750000 * 4 / 2;
format->fmt.vbi.count[0] = dev->vbi_height;
format->fmt.vbi.count[1] = dev->vbi_height;
memset(format->fmt.vbi.reserved, 0, sizeof(format->fmt.vbi.reserved));
if (dev->norm & V4L2_STD_525_60) {
format->fmt.vbi.start[0] = 10;
format->fmt.vbi.start[1] = 273;
} else if (dev->norm & V4L2_STD_625_50) {
format->fmt.vbi.start[0] = 6;
format->fmt.vbi.start[1] = 318;
}
return 0;
}
static int vidioc_s_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *format)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
format->fmt.vbi.samples_per_line = dev->vbi_width;
format->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
format->fmt.vbi.offset = 0;
format->fmt.vbi.flags = 0;
format->fmt.vbi.sampling_rate = 6750000 * 4 / 2;
format->fmt.vbi.count[0] = dev->vbi_height;
format->fmt.vbi.count[1] = dev->vbi_height;
memset(format->fmt.vbi.reserved, 0, sizeof(format->fmt.vbi.reserved));
if (dev->norm & V4L2_STD_525_60) {
format->fmt.vbi.start[0] = 10;
format->fmt.vbi.start[1] = 273;
} else if (dev->norm & V4L2_STD_625_50) {
format->fmt.vbi.start[0] = 6;
format->fmt.vbi.start[1] = 318;
}
return 0;
}
static int radio_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct em28xx *dev = ((struct em28xx_fh *)priv)->dev;
if (unlikely(t->index > 0))
return -EINVAL;
strcpy(t->name, "Radio");
t->type = V4L2_TUNER_RADIO;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int radio_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct em28xx *dev = ((struct em28xx_fh *)priv)->dev;
if (0 != t->index)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static int em28xx_v4l2_open(struct file *filp)
{
struct video_device *vdev = video_devdata(filp);
struct em28xx *dev = video_drvdata(filp);
enum v4l2_buf_type fh_type = 0;
struct em28xx_fh *fh;
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
fh_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
fh_type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
}
em28xx_videodbg("open dev=%s type=%s users=%d\n",
video_device_node_name(vdev), v4l2_type_names[fh_type],
dev->users);
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
fh = kzalloc(sizeof(struct em28xx_fh), GFP_KERNEL);
if (!fh) {
em28xx_errdev("em28xx-video.c: Out of memory?!\n");
mutex_unlock(&dev->lock);
return -ENOMEM;
}
v4l2_fh_init(&fh->fh, vdev);
fh->dev = dev;
fh->type = fh_type;
filp->private_data = fh;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE && dev->users == 0) {
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
em28xx_resolution_set(dev);
em28xx_wake_i2c(dev);
}
if (vdev->vfl_type == VFL_TYPE_RADIO) {
em28xx_videodbg("video_open: setting radio device\n");
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_radio);
}
dev->users++;
mutex_unlock(&dev->lock);
v4l2_fh_add(&fh->fh);
return 0;
}
void em28xx_release_analog_resources(struct em28xx *dev)
{
if (dev->radio_dev) {
if (video_is_registered(dev->radio_dev))
video_unregister_device(dev->radio_dev);
else
video_device_release(dev->radio_dev);
dev->radio_dev = NULL;
}
if (dev->vbi_dev) {
em28xx_info("V4L2 device %s deregistered\n",
video_device_node_name(dev->vbi_dev));
if (video_is_registered(dev->vbi_dev))
video_unregister_device(dev->vbi_dev);
else
video_device_release(dev->vbi_dev);
dev->vbi_dev = NULL;
}
if (dev->vdev) {
em28xx_info("V4L2 device %s deregistered\n",
video_device_node_name(dev->vdev));
if (video_is_registered(dev->vdev))
video_unregister_device(dev->vdev);
else
video_device_release(dev->vdev);
dev->vdev = NULL;
}
}
static int em28xx_v4l2_close(struct file *filp)
{
struct em28xx_fh *fh = filp->private_data;
struct em28xx *dev = fh->dev;
int errCode;
em28xx_videodbg("users=%d\n", dev->users);
mutex_lock(&dev->lock);
vb2_fop_release(filp);
if (dev->users == 1) {
if (dev->disconnected) {
em28xx_release_resources(dev);
kfree(dev->alt_max_pkt_size_isoc);
mutex_unlock(&dev->lock);
kfree(dev);
return 0;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_power, 0);
em28xx_set_mode(dev, EM28XX_SUSPEND);
dev->alt = 0;
em28xx_videodbg("setting alternate 0\n");
errCode = usb_set_interface(dev->udev, 0, 0);
if (errCode < 0) {
em28xx_errdev("cannot change alternate number to "
"0 (error=%i)\n", errCode);
}
}
dev->users--;
mutex_unlock(&dev->lock);
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
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->debug = video_debug;
vfd->lock = &dev->lock;
set_bit(V4L2_FL_USE_FH_PRIO, &vfd->flags);
if (dev->board.is_webcam)
vfd->tvnorms = 0;
snprintf(vfd->name, sizeof(vfd->name), "%s %s",
dev->name, type_name);
video_set_drvdata(vfd, dev);
return vfd;
}
int em28xx_register_analog_devices(struct em28xx *dev)
{
u8 val;
int ret;
unsigned int maxw;
printk(KERN_INFO "%s: v4l2 driver version %s\n",
dev->name, EM28XX_VERSION);
dev->norm = V4L2_STD_PAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std, dev->norm);
dev->interlaced = EM28XX_INTERLACED_DEFAULT;
dev->format = &format[0];
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
em28xx_colorlevels_set_default(dev);
em28xx_compression_disable(dev);
dev->vdev = em28xx_vdev_init(dev, &em28xx_video_template, "video");
if (!dev->vdev) {
em28xx_errdev("cannot allocate video_device.\n");
return -ENODEV;
}
dev->vdev->queue = &dev->vb_vidq;
dev->vdev->queue->lock = &dev->vb_queue_lock;
ret = video_register_device(dev->vdev, VFL_TYPE_GRABBER,
video_nr[dev->devno]);
if (ret) {
em28xx_errdev("unable to register video device (error=%i).\n",
ret);
return ret;
}
if (em28xx_vbi_supported(dev) == 1) {
dev->vbi_dev = em28xx_vdev_init(dev, &em28xx_video_template,
"vbi");
dev->vbi_dev->queue = &dev->vb_vbiq;
dev->vbi_dev->queue->lock = &dev->vb_vbi_queue_lock;
ret = video_register_device(dev->vbi_dev, VFL_TYPE_VBI,
vbi_nr[dev->devno]);
if (ret < 0) {
em28xx_errdev("unable to register vbi device\n");
return ret;
}
}
if (em28xx_boards[dev->model].radio.type == EM28XX_RADIO) {
dev->radio_dev = em28xx_vdev_init(dev, &em28xx_radio_template,
"radio");
if (!dev->radio_dev) {
em28xx_errdev("cannot allocate video_device.\n");
return -ENODEV;
}
ret = video_register_device(dev->radio_dev, VFL_TYPE_RADIO,
radio_nr[dev->devno]);
if (ret < 0) {
em28xx_errdev("can't register radio device\n");
return ret;
}
em28xx_info("Registered radio device as %s\n",
video_device_node_name(dev->radio_dev));
}
em28xx_info("V4L2 video device registered as %s\n",
video_device_node_name(dev->vdev));
if (dev->vbi_dev)
em28xx_info("V4L2 VBI device registered as %s\n",
video_device_node_name(dev->vbi_dev));
return 0;
}
