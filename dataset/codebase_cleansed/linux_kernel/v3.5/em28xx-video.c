static inline void buffer_filled(struct em28xx *dev,
struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer *buf)
{
em28xx_isocdbg("[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
do_gettimeofday(&buf->vb.ts);
dev->isoc_ctl.vid_buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static inline void vbi_buffer_filled(struct em28xx *dev,
struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer *buf)
{
em28xx_isocdbg("[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
do_gettimeofday(&buf->vb.ts);
dev->isoc_ctl.vbi_buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static void em28xx_copy_video(struct em28xx *dev,
struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer *buf,
unsigned char *p,
unsigned char *outp, unsigned long len)
{
void *fieldstart, *startwrite, *startread;
int linesdone, currlinedone, offset, lencopy, remain;
int bytesperline = dev->width << 1;
if (dma_q->pos + len > buf->vb.size)
len = buf->vb.size - dma_q->pos;
startread = p;
remain = len;
if (dev->progressive)
fieldstart = outp;
else {
if (buf->top_field)
fieldstart = outp;
else
fieldstart = outp + bytesperline;
}
linesdone = dma_q->pos / bytesperline;
currlinedone = dma_q->pos % bytesperline;
if (dev->progressive)
offset = linesdone * bytesperline + currlinedone;
else
offset = linesdone * bytesperline * 2 + currlinedone;
startwrite = fieldstart + offset;
lencopy = bytesperline - currlinedone;
lencopy = lencopy > remain ? remain : lencopy;
if ((char *)startwrite + lencopy > (char *)outp + buf->vb.size) {
em28xx_isocdbg("Overflow of %zi bytes past buffer end (1)\n",
((char *)startwrite + lencopy) -
((char *)outp + buf->vb.size));
remain = (char *)outp + buf->vb.size - (char *)startwrite;
lencopy = remain;
}
if (lencopy <= 0)
return;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
while (remain > 0) {
startwrite += lencopy + bytesperline;
startread += lencopy;
if (bytesperline > remain)
lencopy = remain;
else
lencopy = bytesperline;
if ((char *)startwrite + lencopy > (char *)outp +
buf->vb.size) {
em28xx_isocdbg("Overflow of %zi bytes past buffer end"
"(2)\n",
((char *)startwrite + lencopy) -
((char *)outp + buf->vb.size));
lencopy = remain = (char *)outp + buf->vb.size -
(char *)startwrite;
}
if (lencopy <= 0)
break;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
}
dma_q->pos += len;
}
static void em28xx_copy_vbi(struct em28xx *dev,
struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer *buf,
unsigned char *p,
unsigned char *outp, unsigned long len)
{
void *startwrite, *startread;
int offset;
int bytesperline;
if (dev == NULL) {
em28xx_isocdbg("dev is null\n");
return;
}
bytesperline = dev->vbi_width;
if (dma_q == NULL) {
em28xx_isocdbg("dma_q is null\n");
return;
}
if (buf == NULL) {
return;
}
if (p == NULL) {
em28xx_isocdbg("p is null\n");
return;
}
if (outp == NULL) {
em28xx_isocdbg("outp is null\n");
return;
}
if (dma_q->pos + len > buf->vb.size)
len = buf->vb.size - dma_q->pos;
startread = p;
startwrite = outp + dma_q->pos;
offset = dma_q->pos;
if (buf->top_field == 0) {
startwrite += bytesperline * dev->vbi_height;
offset += bytesperline * dev->vbi_height;
}
memcpy(startwrite, startread, len);
dma_q->pos += len;
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
static inline void get_next_buf(struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer **buf)
{
struct em28xx *dev = container_of(dma_q, struct em28xx, vidq);
char *outp;
if (list_empty(&dma_q->active)) {
em28xx_isocdbg("No active queue to serve\n");
dev->isoc_ctl.vid_buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct em28xx_buffer, vb.queue);
outp = videobuf_to_vmalloc(&(*buf)->vb);
memset(outp, 0, (*buf)->vb.size);
dev->isoc_ctl.vid_buf = *buf;
return;
}
static inline void vbi_get_next_buf(struct em28xx_dmaqueue *dma_q,
struct em28xx_buffer **buf)
{
struct em28xx *dev = container_of(dma_q, struct em28xx, vbiq);
char *outp;
if (list_empty(&dma_q->active)) {
em28xx_isocdbg("No active queue to serve\n");
dev->isoc_ctl.vbi_buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct em28xx_buffer, vb.queue);
outp = videobuf_to_vmalloc(&(*buf)->vb);
memset(outp, 0x00, (*buf)->vb.size);
dev->isoc_ctl.vbi_buf = *buf;
return;
}
static inline int em28xx_isoc_copy(struct em28xx *dev, struct urb *urb)
{
struct em28xx_buffer *buf;
struct em28xx_dmaqueue *dma_q = &dev->vidq;
unsigned char *outp = NULL;
int i, len = 0, rc = 1;
unsigned char *p;
if (!dev)
return 0;
if ((dev->state & DEV_DISCONNECTED) || (dev->state & DEV_MISCONFIGURED))
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
buf = dev->isoc_ctl.vid_buf;
if (buf != NULL)
outp = videobuf_to_vmalloc(&buf->vb);
for (i = 0; i < urb->number_of_packets; i++) {
int status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
len = urb->iso_frame_desc[i].actual_length - 4;
if (urb->iso_frame_desc[i].actual_length <= 0) {
continue;
}
if (urb->iso_frame_desc[i].actual_length >
dev->max_pkt_size) {
em28xx_isocdbg("packet bigger than packet size");
continue;
}
p = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (p[0] == 0x33 && p[1] == 0x95 && p[2] == 0x00) {
em28xx_isocdbg("VBI HEADER!!!\n");
continue;
}
if (p[0] == 0x22 && p[1] == 0x5a) {
em28xx_isocdbg("Video frame %d, length=%i, %s\n", p[2],
len, (p[2] & 1) ? "odd" : "even");
if (dev->progressive || !(p[2] & 1)) {
if (buf != NULL)
buffer_filled(dev, dma_q, buf);
get_next_buf(dma_q, &buf);
if (buf == NULL)
outp = NULL;
else
outp = videobuf_to_vmalloc(&buf->vb);
}
if (buf != NULL) {
if (p[2] & 1)
buf->top_field = 0;
else
buf->top_field = 1;
}
dma_q->pos = 0;
}
if (buf != NULL) {
if (p[0] != 0x88 && p[0] != 0x22) {
em28xx_isocdbg("frame is not complete\n");
len += 4;
} else {
p += 4;
}
em28xx_copy_video(dev, dma_q, buf, p, outp, len);
}
}
return rc;
}
static inline int em28xx_isoc_copy_vbi(struct em28xx *dev, struct urb *urb)
{
struct em28xx_buffer *buf, *vbi_buf;
struct em28xx_dmaqueue *dma_q = &dev->vidq;
struct em28xx_dmaqueue *vbi_dma_q = &dev->vbiq;
unsigned char *outp = NULL;
unsigned char *vbioutp = NULL;
int i, len = 0, rc = 1;
unsigned char *p;
int vbi_size;
if (!dev)
return 0;
if ((dev->state & DEV_DISCONNECTED) || (dev->state & DEV_MISCONFIGURED))
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
buf = dev->isoc_ctl.vid_buf;
if (buf != NULL)
outp = videobuf_to_vmalloc(&buf->vb);
vbi_buf = dev->isoc_ctl.vbi_buf;
if (vbi_buf != NULL)
vbioutp = videobuf_to_vmalloc(&vbi_buf->vb);
for (i = 0; i < urb->number_of_packets; i++) {
int status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
len = urb->iso_frame_desc[i].actual_length;
if (urb->iso_frame_desc[i].actual_length <= 0) {
continue;
}
if (urb->iso_frame_desc[i].actual_length >
dev->max_pkt_size) {
em28xx_isocdbg("packet bigger than packet size");
continue;
}
p = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (p[0] == 0x33 && p[1] == 0x95) {
dev->capture_type = 0;
dev->vbi_read = 0;
em28xx_isocdbg("VBI START HEADER!!!\n");
dev->cur_field = p[2];
p += 4;
len -= 4;
} else if (p[0] == 0x88 && p[1] == 0x88 &&
p[2] == 0x88 && p[3] == 0x88) {
p += 4;
len -= 4;
} else if (p[0] == 0x22 && p[1] == 0x5a) {
p += 4;
len -= 4;
}
vbi_size = dev->vbi_width * dev->vbi_height;
if (dev->capture_type == 0) {
if (dev->vbi_read >= vbi_size) {
em28xx_isocdbg("dev->vbi_read > vbi_size\n");
} else if ((dev->vbi_read + len) < vbi_size) {
if (dev->vbi_read == 0 &&
(!(dev->cur_field & 1))) {
if (vbi_buf != NULL)
vbi_buffer_filled(dev,
vbi_dma_q,
vbi_buf);
vbi_get_next_buf(vbi_dma_q, &vbi_buf);
if (vbi_buf == NULL)
vbioutp = NULL;
else
vbioutp = videobuf_to_vmalloc(
&vbi_buf->vb);
}
if (dev->vbi_read == 0) {
vbi_dma_q->pos = 0;
if (vbi_buf != NULL) {
if (dev->cur_field & 1)
vbi_buf->top_field = 0;
else
vbi_buf->top_field = 1;
}
}
dev->vbi_read += len;
em28xx_copy_vbi(dev, vbi_dma_q, vbi_buf, p,
vbioutp, len);
} else {
int vbi_data_len = vbi_size - dev->vbi_read;
dev->vbi_read += vbi_data_len;
em28xx_copy_vbi(dev, vbi_dma_q, vbi_buf, p,
vbioutp, vbi_data_len);
dev->capture_type = 1;
p += vbi_data_len;
len -= vbi_data_len;
}
}
if (dev->capture_type == 1) {
dev->capture_type = 2;
if (dev->progressive || !(dev->cur_field & 1)) {
if (buf != NULL)
buffer_filled(dev, dma_q, buf);
get_next_buf(dma_q, &buf);
if (buf == NULL)
outp = NULL;
else
outp = videobuf_to_vmalloc(&buf->vb);
}
if (buf != NULL) {
if (dev->cur_field & 1)
buf->top_field = 0;
else
buf->top_field = 1;
}
dma_q->pos = 0;
}
if (buf != NULL && dev->capture_type == 2) {
if (len >= 4 && p[0] == 0x88 && p[1] == 0x88 &&
p[2] == 0x88 && p[3] == 0x88) {
p += 4;
len -= 4;
}
if (len >= 4 && p[0] == 0x22 && p[1] == 0x5a) {
em28xx_isocdbg("Video frame %d, len=%i, %s\n",
p[2], len, (p[2] & 1) ?
"odd" : "even");
p += 4;
len -= 4;
}
if (len > 0)
em28xx_copy_video(dev, dma_q, buf, p, outp,
len);
}
}
return rc;
}
static int
buffer_setup(struct videobuf_queue *vq, unsigned int *count, unsigned int *size)
{
struct em28xx_fh *fh = vq->priv_data;
struct em28xx *dev = fh->dev;
struct v4l2_frequency f;
*size = (fh->dev->width * fh->dev->height * dev->format->depth + 7)
>> 3;
if (0 == *count)
*count = EM28XX_DEF_BUF;
if (*count < EM28XX_MIN_BUF)
*count = EM28XX_MIN_BUF;
memset(&f, 0, sizeof(f));
f.frequency = dev->ctl_freq;
f.type = fh->radio ? V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, &f);
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct em28xx_buffer *buf)
{
struct em28xx_fh *fh = vq->priv_data;
struct em28xx *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->slock, flags);
if (dev->isoc_ctl.vid_buf == buf)
dev->isoc_ctl.vid_buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct em28xx_fh *fh = vq->priv_data;
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
struct em28xx *dev = fh->dev;
int rc = 0, urb_init = 0;
buf->vb.size = (fh->dev->width * fh->dev->height * dev->format->depth
+ 7) >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
buf->vb.width = dev->width;
buf->vb.height = dev->height;
buf->vb.field = field;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
rc = videobuf_iolock(vq, &buf->vb, NULL);
if (rc < 0)
goto fail;
}
if (!dev->isoc_ctl.analog_bufs.num_bufs)
urb_init = 1;
if (urb_init) {
if (em28xx_vbi_supported(dev) == 1)
rc = em28xx_init_isoc(dev, EM28XX_ANALOG_MODE,
EM28XX_NUM_PACKETS,
EM28XX_NUM_BUFS,
dev->max_pkt_size,
em28xx_isoc_copy_vbi);
else
rc = em28xx_init_isoc(dev, EM28XX_ANALOG_MODE,
EM28XX_NUM_PACKETS,
EM28XX_NUM_BUFS,
dev->max_pkt_size,
em28xx_isoc_copy);
if (rc < 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(vq, buf);
return rc;
}
static void
buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct em28xx_buffer *buf = container_of(vb,
struct em28xx_buffer,
vb);
struct em28xx_fh *fh = vq->priv_data;
struct em28xx *dev = fh->dev;
struct em28xx_dmaqueue *vidq = &dev->vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct em28xx_buffer *buf = container_of(vb,
struct em28xx_buffer,
vb);
struct em28xx_fh *fh = vq->priv_data;
struct em28xx *dev = (struct em28xx *)fh->dev;
em28xx_isocdbg("em28xx: called buffer_release\n");
free_buffer(vq, buf);
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
static int res_get(struct em28xx_fh *fh, unsigned int bit)
{
struct em28xx *dev = fh->dev;
if (fh->resources & bit)
return 1;
if (dev->resources & bit) {
return 0;
}
fh->resources |= bit;
dev->resources |= bit;
em28xx_videodbg("res: get %d\n", bit);
return 1;
}
static int res_check(struct em28xx_fh *fh, unsigned int bit)
{
return fh->resources & bit;
}
static int res_locked(struct em28xx *dev, unsigned int bit)
{
return dev->resources & bit;
}
static void res_free(struct em28xx_fh *fh, unsigned int bits)
{
struct em28xx *dev = fh->dev;
BUG_ON((fh->resources & bits) != bits);
fh->resources &= ~bits;
dev->resources &= ~bits;
em28xx_videodbg("res: put %d\n", bits);
}
static int get_ressource(struct em28xx_fh *fh)
{
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return EM28XX_RESOURCE_VIDEO;
case V4L2_BUF_TYPE_VBI_CAPTURE:
return EM28XX_RESOURCE_VBI;
default:
BUG();
return 0;
}
}
static int ac97_queryctrl(struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(ac97_qctrl); i++) {
if (qc->id && qc->id == ac97_qctrl[i].id) {
memcpy(qc, &(ac97_qctrl[i]), sizeof(*qc));
return 0;
}
}
return 1;
}
static int ac97_get_ctrl(struct em28xx *dev, struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = dev->mute;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = dev->volume;
return 0;
default:
return 1;
}
}
static int ac97_set_ctrl(struct em28xx *dev, const struct v4l2_control *ctrl)
{
int i;
for (i = 0; i < ARRAY_SIZE(ac97_qctrl); i++)
if (ctrl->id == ac97_qctrl[i].id)
goto handle;
return 1;
handle:
if (ctrl->value < ac97_qctrl[i].minimum ||
ctrl->value > ac97_qctrl[i].maximum)
return -ERANGE;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
dev->mute = ctrl->value;
break;
case V4L2_CID_AUDIO_VOLUME:
dev->volume = ctrl->value;
break;
}
return em28xx_audio_analog_set(dev);
}
static int check_dev(struct em28xx *dev)
{
if (dev->state & DEV_DISCONNECTED) {
em28xx_errdev("v4l2 ioctl: device not present\n");
return -ENODEV;
}
if (dev->state & DEV_MISCONFIGURED) {
em28xx_errdev("v4l2 ioctl: device is misconfigured; "
"close and open it again\n");
return -EIO;
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
f->fmt.pix.bytesperline = (dev->width * fmt->depth + 7) >> 3;
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
em28xx_set_alternate(dev);
em28xx_resolution_set(dev);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
vidioc_try_fmt_vid_cap(file, priv, f);
if (videobuf_queue_is_busy(&fh->vb_vidq)) {
em28xx_errdev("%s queue busy\n", __func__);
return -EBUSY;
}
return em28xx_set_video_format(dev, f->fmt.pix.pixelformat,
f->fmt.pix.width, f->fmt.pix.height);
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *norm)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
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
rc = check_dev(dev);
if (rc < 0)
return rc;
dev->norm = *norm;
f.fmt.pix.width = dev->width;
f.fmt.pix.height = dev->height;
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
return -EINVAL;
if (p->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
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
static int vidioc_s_audio(struct file *file, void *priv, struct v4l2_audio *a)
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
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int id = qc->id;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
memset(qc, 0, sizeof(*qc));
qc->id = id;
if (dev->audio_mode.ac97 != EM28XX_NO_AC97) {
rc = ac97_queryctrl(qc);
if (!rc)
return 0;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, core, queryctrl, qc);
if (qc->type)
return 0;
else
return -EINVAL;
}
static int check_subdev_ctrl(struct em28xx *dev, int id)
{
struct v4l2_queryctrl qc;
memset(&qc, 0, sizeof(qc));
qc.id = id;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, queryctrl, &qc);
if (qc.type)
return 0;
else
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
rc = 0;
if (dev->audio_mode.ac97 != EM28XX_NO_AC97)
rc = ac97_get_ctrl(dev, ctrl);
else
rc = 1;
if (rc == 1) {
if (check_subdev_ctrl(dev, ctrl->id))
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_ctrl, ctrl);
rc = 0;
}
return rc;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (dev->audio_mode.ac97 != EM28XX_NO_AC97)
rc = ac97_set_ctrl(dev, ctrl);
else
rc = 1;
if (rc == 1) {
rc = check_subdev_ctrl(dev, ctrl->id);
if (!rc)
v4l2_device_call_all(&dev->v4l2_dev, 0,
core, s_ctrl, ctrl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
dev->mute = ctrl->value;
rc = em28xx_audio_analog_set(dev);
break;
case V4L2_CID_AUDIO_VOLUME:
dev->volume = ctrl->value;
rc = em28xx_audio_analog_set(dev);
}
}
return (rc < 0) ? rc : 0;
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
t->type = V4L2_TUNER_ANALOG_TV;
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
f->type = fh->radio ? V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
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
if (unlikely(0 == fh->radio && f->type != V4L2_TUNER_ANALOG_TV))
return -EINVAL;
if (unlikely(1 == fh->radio && f->type != V4L2_TUNER_RADIO))
return -EINVAL;
dev->ctl_freq = f->frequency;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, f);
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
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc = -EINVAL;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (unlikely(type != fh->type))
return -EINVAL;
em28xx_videodbg("vidioc_streamon fh=%p t=%d fh->res=%d dev->res=%d\n",
fh, type, fh->resources, dev->resources);
if (unlikely(!res_get(fh, get_ressource(fh))))
return -EBUSY;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_streamon(&fh->vb_vidq);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_streamon(&fh->vb_vbiq);
return rc;
}
static int vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
fh->type != V4L2_BUF_TYPE_VBI_CAPTURE)
return -EINVAL;
if (type != fh->type)
return -EINVAL;
em28xx_videodbg("vidioc_streamoff fh=%p t=%d fh->res=%d dev->res=%d\n",
fh, type, fh->resources, dev->resources);
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (res_check(fh, EM28XX_RESOURCE_VIDEO)) {
videobuf_streamoff(&fh->vb_vidq);
res_free(fh, EM28XX_RESOURCE_VIDEO);
}
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (res_check(fh, EM28XX_RESOURCE_VBI)) {
videobuf_streamoff(&fh->vb_vbiq);
res_free(fh, EM28XX_RESOURCE_VBI);
}
}
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
strlcpy(cap->driver, "em28xx", sizeof(cap->driver));
strlcpy(cap->card, em28xx_boards[dev->model].name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
cap->capabilities =
V4L2_CAP_SLICED_VBI_CAPTURE |
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
if (dev->vbi_dev)
cap->capabilities |= V4L2_CAP_VBI_CAPTURE;
if (dev->audio_mode.has_audio)
cap->capabilities |= V4L2_CAP_AUDIO;
if (dev->tuner_type != TUNER_ABSENT)
cap->capabilities |= V4L2_CAP_TUNER;
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
static int vidioc_g_fmt_sliced_vbi_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
f->fmt.sliced.service_set = 0;
v4l2_device_call_all(&dev->v4l2_dev, 0, vbi, g_sliced_fmt, &f->fmt.sliced);
if (f->fmt.sliced.service_set == 0)
rc = -EINVAL;
return rc;
}
static int vidioc_try_set_sliced_vbi_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
v4l2_device_call_all(&dev->v4l2_dev, 0, vbi, g_sliced_fmt, &f->fmt.sliced);
if (f->fmt.sliced.service_set == 0)
return -EINVAL;
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
if (dev->norm & V4L2_STD_525_60) {
format->fmt.vbi.start[0] = 10;
format->fmt.vbi.start[1] = 273;
} else if (dev->norm & V4L2_STD_625_50) {
format->fmt.vbi.start[0] = 6;
format->fmt.vbi.start[1] = 318;
}
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *rb)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
return videobuf_reqbufs(&fh->vb_vidq, rb);
else
return videobuf_reqbufs(&fh->vb_vbiq, rb);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
return videobuf_querybuf(&fh->vb_vidq, b);
else {
int result = videobuf_querybuf(&fh->vb_vbiq, b);
b->length = dev->vbi_width * dev->vbi_height * 2;
return result;
}
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
return videobuf_qbuf(&fh->vb_vidq, b);
else
return videobuf_qbuf(&fh->vb_vbiq, b);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct em28xx_fh *fh = priv;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
return videobuf_dqbuf(&fh->vb_vidq, b, file->f_flags &
O_NONBLOCK);
else
return videobuf_dqbuf(&fh->vb_vbiq, b, file->f_flags &
O_NONBLOCK);
}
static int radio_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct em28xx *dev = ((struct em28xx_fh *)priv)->dev;
strlcpy(cap->driver, "em28xx", sizeof(cap->driver));
strlcpy(cap->card, em28xx_boards[dev->model].name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
cap->capabilities = V4L2_CAP_TUNER;
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
static int radio_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
strcpy(i->name, "Radio");
i->type = V4L2_INPUT_TYPE_TUNER;
return 0;
}
static int radio_g_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
if (unlikely(a->index))
return -EINVAL;
strcpy(a->name, "Radio");
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
static int radio_s_audio(struct file *file, void *fh,
struct v4l2_audio *a)
{
return 0;
}
static int radio_s_input(struct file *file, void *fh, unsigned int i)
{
return 0;
}
static int radio_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
int i;
if (qc->id < V4L2_CID_BASE ||
qc->id >= V4L2_CID_LASTP1)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(ac97_qctrl); i++) {
if (qc->id && qc->id == ac97_qctrl[i].id) {
memcpy(qc, &(ac97_qctrl[i]), sizeof(*qc));
return 0;
}
}
return -EINVAL;
}
static int em28xx_v4l2_open(struct file *filp)
{
int errCode = 0, radio = 0;
struct video_device *vdev = video_devdata(filp);
struct em28xx *dev = video_drvdata(filp);
enum v4l2_buf_type fh_type = 0;
struct em28xx_fh *fh;
enum v4l2_field field;
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
fh_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
fh_type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
case VFL_TYPE_RADIO:
radio = 1;
break;
}
em28xx_videodbg("open dev=%s type=%s users=%d\n",
video_device_node_name(vdev), v4l2_type_names[fh_type],
dev->users);
fh = kzalloc(sizeof(struct em28xx_fh), GFP_KERNEL);
if (!fh) {
em28xx_errdev("em28xx-video.c: Out of memory?!\n");
return -ENOMEM;
}
fh->dev = dev;
fh->radio = radio;
fh->type = fh_type;
filp->private_data = fh;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE && dev->users == 0) {
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
em28xx_set_alternate(dev);
em28xx_resolution_set(dev);
em28xx_wake_i2c(dev);
}
if (fh->radio) {
em28xx_videodbg("video_open: setting radio device\n");
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_radio);
}
dev->users++;
if (dev->progressive)
field = V4L2_FIELD_NONE;
else
field = V4L2_FIELD_INTERLACED;
videobuf_queue_vmalloc_init(&fh->vb_vidq, &em28xx_video_qops,
NULL, &dev->slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, field,
sizeof(struct em28xx_buffer), fh, &dev->lock);
videobuf_queue_vmalloc_init(&fh->vb_vbiq, &em28xx_vbi_qops,
NULL, &dev->slock,
V4L2_BUF_TYPE_VBI_CAPTURE,
V4L2_FIELD_SEQ_TB,
sizeof(struct em28xx_buffer), fh, &dev->lock);
return errCode;
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
if (res_check(fh, EM28XX_RESOURCE_VIDEO)) {
videobuf_stop(&fh->vb_vidq);
res_free(fh, EM28XX_RESOURCE_VIDEO);
}
if (res_check(fh, EM28XX_RESOURCE_VBI)) {
videobuf_stop(&fh->vb_vbiq);
res_free(fh, EM28XX_RESOURCE_VBI);
}
if (dev->users == 1) {
if (dev->state & DEV_DISCONNECTED) {
em28xx_release_resources(dev);
kfree(dev->alt_max_pkt_size);
kfree(dev);
kfree(fh);
return 0;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_power, 0);
em28xx_uninit_isoc(dev, EM28XX_ANALOG_MODE);
em28xx_set_mode(dev, EM28XX_SUSPEND);
dev->alt = 0;
em28xx_videodbg("setting alternate 0\n");
errCode = usb_set_interface(dev->udev, 0, 0);
if (errCode < 0) {
em28xx_errdev("cannot change alternate number to "
"0 (error=%i)\n", errCode);
}
}
videobuf_mmap_free(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vbiq);
kfree(fh);
dev->users--;
return 0;
}
static ssize_t
em28xx_v4l2_read(struct file *filp, char __user *buf, size_t count,
loff_t *pos)
{
struct em28xx_fh *fh = filp->private_data;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (res_locked(dev, EM28XX_RESOURCE_VIDEO))
return -EBUSY;
return videobuf_read_stream(&fh->vb_vidq, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
}
if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (!res_get(fh, EM28XX_RESOURCE_VBI))
return -EBUSY;
return videobuf_read_stream(&fh->vb_vbiq, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
}
return 0;
}
static unsigned int em28xx_v4l2_poll(struct file *filp, poll_table *wait)
{
struct em28xx_fh *fh = filp->private_data;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (!res_get(fh, EM28XX_RESOURCE_VIDEO))
return POLLERR;
return videobuf_poll_stream(filp, &fh->vb_vidq, wait);
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (!res_get(fh, EM28XX_RESOURCE_VBI))
return POLLERR;
return videobuf_poll_stream(filp, &fh->vb_vbiq, wait);
} else {
return POLLERR;
}
}
static int em28xx_v4l2_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct em28xx_fh *fh = filp->private_data;
struct em28xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_mmap_mapper(&fh->vb_vidq, vma);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_mmap_mapper(&fh->vb_vbiq, vma);
em28xx_videodbg("vma start=0x%08lx, size=%ld, ret=%d\n",
(unsigned long)vma->vm_start,
(unsigned long)vma->vm_end-(unsigned long)vma->vm_start,
rc);
return rc;
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
vfd->release = video_device_release;
vfd->debug = video_debug;
vfd->lock = &dev->lock;
set_bit(V4L2_FL_LOCK_ALL_FOPS, &vfd->flags);
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
dev->norm = em28xx_video_template.current_norm;
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
