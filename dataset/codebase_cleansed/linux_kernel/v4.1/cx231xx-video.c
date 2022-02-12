static int cx231xx_enable_analog_tuner(struct cx231xx *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
struct media_device *mdev = dev->media_dev;
struct media_entity *entity, *decoder = NULL, *source;
struct media_link *link, *found_link = NULL;
int i, ret, active_links = 0;
if (!mdev)
return 0;
media_device_for_each_entity(entity, mdev) {
if (entity->type == MEDIA_ENT_T_V4L2_SUBDEV_DECODER) {
decoder = entity;
break;
}
}
if (!decoder)
return 0;
for (i = 0; i < decoder->num_links; i++) {
link = &decoder->links[i];
if (link->sink->entity == decoder) {
found_link = link;
if (link->flags & MEDIA_LNK_FL_ENABLED)
active_links++;
break;
}
}
if (active_links == 1 || !found_link)
return 0;
source = found_link->source->entity;
for (i = 0; i < source->num_links; i++) {
struct media_entity *sink;
int flags = 0;
link = &source->links[i];
sink = link->sink->entity;
if (sink == entity)
flags = MEDIA_LNK_FL_ENABLED;
ret = media_entity_setup_link(link, flags);
if (ret) {
dev_err(dev->dev,
"Couldn't change link %s->%s to %s. Error %d\n",
source->name, sink->name,
flags ? "enabled" : "disabled",
ret);
return ret;
} else
dev_dbg(dev->dev,
"link %s->%s was %s\n",
source->name, sink->name,
flags ? "ENABLED" : "disabled");
}
#endif
return 0;
}
static inline void buffer_filled(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q,
struct cx231xx_buffer *buf)
{
cx231xx_isocdbg("[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
if (dev->USE_ISO)
dev->video_mode.isoc_ctl.buf = NULL;
else
dev->video_mode.bulk_ctl.buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static inline void print_err_status(struct cx231xx *dev, int packet, int status)
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
cx231xx_isocdbg("URB status %d [%s].\n", status, errmsg);
} else {
cx231xx_isocdbg("URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline void get_next_buf(struct cx231xx_dmaqueue *dma_q,
struct cx231xx_buffer **buf)
{
struct cx231xx_video_mode *vmode =
container_of(dma_q, struct cx231xx_video_mode, vidq);
struct cx231xx *dev = container_of(vmode, struct cx231xx, video_mode);
char *outp;
if (list_empty(&dma_q->active)) {
cx231xx_isocdbg("No active queue to serve\n");
if (dev->USE_ISO)
dev->video_mode.isoc_ctl.buf = NULL;
else
dev->video_mode.bulk_ctl.buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct cx231xx_buffer, vb.queue);
outp = videobuf_to_vmalloc(&(*buf)->vb);
memset(outp, 0, (*buf)->vb.size);
if (dev->USE_ISO)
dev->video_mode.isoc_ctl.buf = *buf;
else
dev->video_mode.bulk_ctl.buf = *buf;
return;
}
static inline int cx231xx_isoc_copy(struct cx231xx *dev, struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
int i;
unsigned char *p_buffer;
u32 bytes_parsed = 0, buffer_size = 0;
u8 sav_eav = 0;
if (!dev)
return 0;
if (dev->state & DEV_DISCONNECTED)
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
for (i = 0; i < urb->number_of_packets; i++) {
int status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
if (urb->iso_frame_desc[i].actual_length <= 0) {
continue;
}
if (urb->iso_frame_desc[i].actual_length >
dev->video_mode.max_pkt_size) {
cx231xx_isocdbg("packet bigger than packet size");
continue;
}
p_buffer = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
buffer_size = urb->iso_frame_desc[i].actual_length;
bytes_parsed = 0;
if (dma_q->is_partial_line) {
sav_eav = dma_q->last_sav;
} else {
sav_eav =
cx231xx_find_boundary_SAV_EAV(p_buffer,
dma_q->partial_buf,
&bytes_parsed);
}
sav_eav &= 0xF0;
if (sav_eav) {
bytes_parsed += cx231xx_get_video_line(dev, dma_q,
sav_eav,
p_buffer + bytes_parsed,
buffer_size - bytes_parsed);
}
while (bytes_parsed < buffer_size) {
u32 bytes_used = 0;
sav_eav = cx231xx_find_next_SAV_EAV(
p_buffer + bytes_parsed,
buffer_size - bytes_parsed,
&bytes_used);
bytes_parsed += bytes_used;
sav_eav &= 0xF0;
if (sav_eav && (bytes_parsed < buffer_size)) {
bytes_parsed += cx231xx_get_video_line(dev,
dma_q, sav_eav,
p_buffer + bytes_parsed,
buffer_size - bytes_parsed);
}
}
memcpy(dma_q->partial_buf, p_buffer + buffer_size - 4, 4);
bytes_parsed = 0;
}
return 1;
}
static inline int cx231xx_bulk_copy(struct cx231xx *dev, struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
unsigned char *p_buffer;
u32 bytes_parsed = 0, buffer_size = 0;
u8 sav_eav = 0;
if (!dev)
return 0;
if (dev->state & DEV_DISCONNECTED)
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
if (1) {
p_buffer = urb->transfer_buffer;
buffer_size = urb->actual_length;
bytes_parsed = 0;
if (dma_q->is_partial_line) {
sav_eav = dma_q->last_sav;
} else {
sav_eav =
cx231xx_find_boundary_SAV_EAV(p_buffer,
dma_q->partial_buf,
&bytes_parsed);
}
sav_eav &= 0xF0;
if (sav_eav) {
bytes_parsed += cx231xx_get_video_line(dev, dma_q,
sav_eav,
p_buffer + bytes_parsed,
buffer_size - bytes_parsed);
}
while (bytes_parsed < buffer_size) {
u32 bytes_used = 0;
sav_eav = cx231xx_find_next_SAV_EAV(
p_buffer + bytes_parsed,
buffer_size - bytes_parsed,
&bytes_used);
bytes_parsed += bytes_used;
sav_eav &= 0xF0;
if (sav_eav && (bytes_parsed < buffer_size)) {
bytes_parsed += cx231xx_get_video_line(dev,
dma_q, sav_eav,
p_buffer + bytes_parsed,
buffer_size - bytes_parsed);
}
}
memcpy(dma_q->partial_buf, p_buffer + buffer_size - 4, 4);
bytes_parsed = 0;
}
return 1;
}
u8 cx231xx_find_boundary_SAV_EAV(u8 *p_buffer, u8 *partial_buf,
u32 *p_bytes_used)
{
u32 bytes_used;
u8 boundary_bytes[8];
u8 sav_eav = 0;
*p_bytes_used = 0;
memcpy(boundary_bytes, partial_buf, 4);
memcpy(boundary_bytes + 4, p_buffer, 4);
sav_eav = cx231xx_find_next_SAV_EAV((u8 *)&boundary_bytes, 8,
&bytes_used);
if (sav_eav) {
*p_bytes_used = bytes_used - 4;
}
return sav_eav;
}
u8 cx231xx_find_next_SAV_EAV(u8 *p_buffer, u32 buffer_size, u32 *p_bytes_used)
{
u32 i;
u8 sav_eav = 0;
if (buffer_size < 4) {
*p_bytes_used = buffer_size;
return 0;
}
for (i = 0; i < (buffer_size - 3); i++) {
if ((p_buffer[i] == 0xFF) &&
(p_buffer[i + 1] == 0x00) && (p_buffer[i + 2] == 0x00)) {
*p_bytes_used = i + 4;
sav_eav = p_buffer[i + 3];
return sav_eav;
}
}
*p_bytes_used = buffer_size;
return 0;
}
u32 cx231xx_get_video_line(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q, u8 sav_eav,
u8 *p_buffer, u32 buffer_size)
{
u32 bytes_copied = 0;
int current_field = -1;
switch (sav_eav) {
case SAV_ACTIVE_VIDEO_FIELD1:
if ((buffer_size > 3) && (p_buffer[0] == 0xFF) &&
(p_buffer[1] == 0x00) && (p_buffer[2] == 0x00) &&
((p_buffer[3] == EAV_ACTIVE_VIDEO_FIELD1) ||
(p_buffer[3] == EAV_ACTIVE_VIDEO_FIELD2) ||
(p_buffer[3] == EAV_VBLANK_FIELD1) ||
(p_buffer[3] == EAV_VBLANK_FIELD2)))
return bytes_copied;
current_field = 1;
break;
case SAV_ACTIVE_VIDEO_FIELD2:
if ((buffer_size > 3) && (p_buffer[0] == 0xFF) &&
(p_buffer[1] == 0x00) && (p_buffer[2] == 0x00) &&
((p_buffer[3] == EAV_ACTIVE_VIDEO_FIELD1) ||
(p_buffer[3] == EAV_ACTIVE_VIDEO_FIELD2) ||
(p_buffer[3] == EAV_VBLANK_FIELD1) ||
(p_buffer[3] == EAV_VBLANK_FIELD2)))
return bytes_copied;
current_field = 2;
break;
}
dma_q->last_sav = sav_eav;
bytes_copied = cx231xx_copy_video_line(dev, dma_q, p_buffer,
buffer_size, current_field);
return bytes_copied;
}
u32 cx231xx_copy_video_line(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q, u8 *p_line,
u32 length, int field_number)
{
u32 bytes_to_copy;
struct cx231xx_buffer *buf;
u32 _line_size = dev->width * 2;
if (dma_q->current_field != field_number)
cx231xx_reset_video_buffer(dev, dma_q);
if (dev->USE_ISO)
buf = dev->video_mode.isoc_ctl.buf;
else
buf = dev->video_mode.bulk_ctl.buf;
dma_q->current_field = field_number;
bytes_to_copy = dma_q->bytes_left_in_line;
if (bytes_to_copy > length)
bytes_to_copy = length;
if (dma_q->lines_completed >= dma_q->lines_per_field) {
dma_q->bytes_left_in_line -= bytes_to_copy;
dma_q->is_partial_line = (dma_q->bytes_left_in_line == 0) ?
0 : 1;
return 0;
}
dma_q->is_partial_line = 1;
if (!buf) {
dma_q->bytes_left_in_line -= bytes_to_copy;
dma_q->is_partial_line = (dma_q->bytes_left_in_line == 0)
? 0 : 1;
return bytes_to_copy;
}
cx231xx_do_copy(dev, dma_q, p_line, bytes_to_copy);
dma_q->pos += bytes_to_copy;
dma_q->bytes_left_in_line -= bytes_to_copy;
if (dma_q->bytes_left_in_line == 0) {
dma_q->bytes_left_in_line = _line_size;
dma_q->lines_completed++;
dma_q->is_partial_line = 0;
if (cx231xx_is_buffer_done(dev, dma_q) && buf) {
buffer_filled(dev, dma_q, buf);
dma_q->pos = 0;
buf = NULL;
dma_q->lines_completed = 0;
}
}
return bytes_to_copy;
}
void cx231xx_reset_video_buffer(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q)
{
struct cx231xx_buffer *buf;
if (dma_q->current_field == 1) {
if (dma_q->lines_completed >= dma_q->lines_per_field)
dma_q->field1_done = 1;
else
dma_q->field1_done = 0;
}
if (dev->USE_ISO)
buf = dev->video_mode.isoc_ctl.buf;
else
buf = dev->video_mode.bulk_ctl.buf;
if (buf == NULL) {
get_next_buf(dma_q, &buf);
dma_q->pos = 0;
dma_q->field1_done = 0;
dma_q->current_field = -1;
}
dma_q->bytes_left_in_line = dev->width << 1;
dma_q->lines_completed = 0;
}
int cx231xx_do_copy(struct cx231xx *dev, struct cx231xx_dmaqueue *dma_q,
u8 *p_buffer, u32 bytes_to_copy)
{
u8 *p_out_buffer = NULL;
u32 current_line_bytes_copied = 0;
struct cx231xx_buffer *buf;
u32 _line_size = dev->width << 1;
void *startwrite;
int offset, lencopy;
if (dev->USE_ISO)
buf = dev->video_mode.isoc_ctl.buf;
else
buf = dev->video_mode.bulk_ctl.buf;
if (buf == NULL)
return -1;
p_out_buffer = videobuf_to_vmalloc(&buf->vb);
current_line_bytes_copied = _line_size - dma_q->bytes_left_in_line;
offset = (dma_q->current_field == 1) ? 0 : _line_size;
startwrite = p_out_buffer + offset;
startwrite += (dma_q->lines_completed * _line_size * 2);
startwrite += current_line_bytes_copied;
lencopy = dma_q->bytes_left_in_line > bytes_to_copy ?
bytes_to_copy : dma_q->bytes_left_in_line;
if ((u8 *)(startwrite + lencopy) > (u8 *)(p_out_buffer + buf->vb.size))
return 0;
cx231xx_swab((u16 *) p_buffer, (u16 *) startwrite, (u16) lencopy);
return 0;
}
void cx231xx_swab(u16 *from, u16 *to, u16 len)
{
u16 i;
if (len <= 0)
return;
for (i = 0; i < len / 2; i++)
to[i] = (from[i] << 8) | (from[i] >> 8);
}
u8 cx231xx_is_buffer_done(struct cx231xx *dev, struct cx231xx_dmaqueue *dma_q)
{
u8 buffer_complete = 0;
buffer_complete = ((dma_q->current_field == 2) &&
(dma_q->lines_completed >= dma_q->lines_per_field) &&
dma_q->field1_done);
return buffer_complete;
}
static int
buffer_setup(struct videobuf_queue *vq, unsigned int *count, unsigned int *size)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
*size = (fh->dev->width * fh->dev->height * dev->format->depth + 7)>>3;
if (0 == *count)
*count = CX231XX_DEF_BUF;
if (*count < CX231XX_MIN_BUF)
*count = CX231XX_MIN_BUF;
cx231xx_enable_analog_tuner(dev);
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct cx231xx_buffer *buf)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->video_mode.slock, flags);
if (dev->USE_ISO) {
if (dev->video_mode.isoc_ctl.buf == buf)
dev->video_mode.isoc_ctl.buf = NULL;
} else {
if (dev->video_mode.bulk_ctl.buf == buf)
dev->video_mode.bulk_ctl.buf = NULL;
}
spin_unlock_irqrestore(&dev->video_mode.slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx *dev = fh->dev;
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
if (dev->USE_ISO) {
if (!dev->video_mode.isoc_ctl.num_bufs)
urb_init = 1;
} else {
if (!dev->video_mode.bulk_ctl.num_bufs)
urb_init = 1;
}
dev_dbg(dev->dev,
"urb_init=%d dev->video_mode.max_pkt_size=%d\n",
urb_init, dev->video_mode.max_pkt_size);
if (urb_init) {
dev->mode_tv = 0;
if (dev->USE_ISO)
rc = cx231xx_init_isoc(dev, CX231XX_NUM_PACKETS,
CX231XX_NUM_BUFS,
dev->video_mode.max_pkt_size,
cx231xx_isoc_copy);
else
rc = cx231xx_init_bulk(dev, CX231XX_NUM_PACKETS,
CX231XX_NUM_BUFS,
dev->video_mode.max_pkt_size,
cx231xx_bulk_copy);
if (rc < 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(vq, buf);
return rc;
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
struct cx231xx_dmaqueue *vidq = &dev->video_mode.vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = (struct cx231xx *)fh->dev;
cx231xx_isocdbg("cx231xx: called buffer_release\n");
free_buffer(vq, buf);
}
void video_mux(struct cx231xx *dev, int index)
{
dev->video_input = index;
dev->ctl_ainput = INPUT(index)->amux;
cx231xx_set_video_input_mux(dev, index);
cx25840_call(dev, video, s_routing, INPUT(index)->vmux, 0, 0);
cx231xx_set_audio_input(dev, dev->ctl_ainput);
dev_dbg(dev->dev, "video_mux : %d\n", index);
cx231xx_do_mode_ctrl_overrides(dev);
}
static int res_get(struct cx231xx_fh *fh)
{
struct cx231xx *dev = fh->dev;
int rc = 0;
if (fh->stream_on)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (dev->stream_on)
return -EBUSY;
dev->stream_on = 1;
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (dev->vbi_stream_on)
return -EBUSY;
dev->vbi_stream_on = 1;
} else
return -EINVAL;
fh->stream_on = 1;
return rc;
}
static int res_check(struct cx231xx_fh *fh)
{
return fh->stream_on;
}
static void res_free(struct cx231xx_fh *fh)
{
struct cx231xx *dev = fh->dev;
fh->stream_on = 0;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
dev->stream_on = 0;
if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
dev->vbi_stream_on = 0;
}
static int check_dev(struct cx231xx *dev)
{
if (dev->state & DEV_DISCONNECTED) {
dev_err(dev->dev, "v4l2 ioctl: device not present\n");
return -ENODEV;
}
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.pixelformat = dev->format->fourcc;
f->fmt.pix.bytesperline = (dev->width * dev->format->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * dev->height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
return 0;
}
static struct cx231xx_fmt *format_by_fourcc(unsigned int fourcc)
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
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
unsigned int width = f->fmt.pix.width;
unsigned int height = f->fmt.pix.height;
unsigned int maxw = norm_maxw(dev);
unsigned int maxh = norm_maxh(dev);
struct cx231xx_fmt *fmt;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (!fmt) {
cx231xx_videodbg("Fourcc format (%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
v4l_bound_align_image(&width, 48, maxw, 1, &height, 32, maxh, 1, 0);
f->fmt.pix.width = width;
f->fmt.pix.height = height;
f->fmt.pix.pixelformat = fmt->fourcc;
f->fmt.pix.bytesperline = (width * fmt->depth + 7) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline * height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
struct cx231xx_fmt *fmt;
struct v4l2_mbus_framefmt mbus_fmt;
rc = check_dev(dev);
if (rc < 0)
return rc;
vidioc_try_fmt_vid_cap(file, priv, f);
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (!fmt)
return -EINVAL;
if (videobuf_queue_is_busy(&fh->vb_vidq)) {
dev_err(dev->dev, "%s: queue busy\n", __func__);
return -EBUSY;
}
if (dev->stream_on && !fh->stream_on) {
dev_err(dev->dev,
"%s: device in use by another fh\n", __func__);
return -EBUSY;
}
dev->width = f->fmt.pix.width;
dev->height = f->fmt.pix.height;
dev->format = fmt;
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, MEDIA_BUS_FMT_FIXED);
call_all(dev, video, s_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
return rc;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
*id = dev->norm;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id norm)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
struct v4l2_mbus_framefmt mbus_fmt;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (dev->norm == norm)
return 0;
if (videobuf_queue_is_busy(&fh->vb_vidq))
return -EBUSY;
dev->norm = norm;
dev->width = 720;
dev->height = (dev->norm & V4L2_STD_625_50) ? 576 : 480;
call_all(dev, video, s_std, dev->norm);
memset(&mbus_fmt, 0, sizeof(mbus_fmt));
mbus_fmt.code = MEDIA_BUS_FMT_FIXED;
mbus_fmt.width = dev->width;
mbus_fmt.height = dev->height;
call_all(dev, video, s_mbus_fmt, &mbus_fmt);
cx231xx_do_mode_ctrl_overrides(dev);
return 0;
}
int cx231xx_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
u32 gen_stat;
unsigned int ret, n;
n = i->index;
if (n >= MAX_CX231XX_INPUT)
return -EINVAL;
if (0 == INPUT(n)->type)
return -EINVAL;
i->index = n;
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name, iname[INPUT(n)->type]);
if ((CX231XX_VMUX_TELEVISION == INPUT(n)->type) ||
(CX231XX_VMUX_CABLE == INPUT(n)->type))
i->type = V4L2_INPUT_TYPE_TUNER;
i->std = dev->vdev.tvnorms;
if (n == dev->video_input) {
ret = cx231xx_read_i2c_data(dev, VID_BLK_I2C_ADDRESS,
GEN_STAT, 2, &gen_stat, 4);
if (ret > 0) {
if ((gen_stat & FLD_VPRES) == 0x00)
i->status |= V4L2_IN_ST_NO_SIGNAL;
if ((gen_stat & FLD_HLOCK) == 0x00)
i->status |= V4L2_IN_ST_NO_H_LOCK;
}
}
return 0;
}
int cx231xx_g_input(struct file *file, void *priv, unsigned int *i)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
*i = dev->video_input;
return 0;
}
int cx231xx_s_input(struct file *file, void *priv, unsigned int i)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
dev->mode_tv = 0;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (i >= MAX_CX231XX_INPUT)
return -EINVAL;
if (0 == INPUT(i)->type)
return -EINVAL;
video_mux(dev, i);
if (INPUT(i)->type == CX231XX_VMUX_TELEVISION ||
INPUT(i)->type == CX231XX_VMUX_CABLE) {
call_all(dev, video, s_std, dev->norm);
}
return 0;
}
int cx231xx_g_tuner(struct file *file, void *priv, struct v4l2_tuner *t)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Tuner");
t->type = V4L2_TUNER_ANALOG_TV;
t->capability = V4L2_TUNER_CAP_NORM;
t->rangehigh = 0xffffffffUL;
t->signal = 0xffff;
call_all(dev, tuner, g_tuner, t);
return 0;
}
int cx231xx_s_tuner(struct file *file, void *priv, const struct v4l2_tuner *t)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != t->index)
return -EINVAL;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0;
}
int cx231xx_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
if (f->tuner)
return -EINVAL;
f->frequency = dev->ctl_freq;
return 0;
}
int cx231xx_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
struct v4l2_frequency new_freq = *f;
int rc;
u32 if_frequency = 5400000;
dev_dbg(dev->dev,
"Enter vidioc_s_frequency()f->frequency=%d;f->type=%d\n",
f->frequency, f->type);
rc = check_dev(dev);
if (rc < 0)
return rc;
if (0 != f->tuner)
return -EINVAL;
rc = cx231xx_tuner_pre_channel_change(dev);
call_all(dev, tuner, s_frequency, f);
call_all(dev, tuner, g_frequency, &new_freq);
dev->ctl_freq = new_freq.frequency;
rc = cx231xx_tuner_post_channel_change(dev);
if (dev->tuner_type == TUNER_NXP_TDA18271) {
if (dev->norm & (V4L2_STD_MN | V4L2_STD_NTSC_443))
if_frequency = 5400000;
else if (dev->norm & V4L2_STD_B)
if_frequency = 6000000;
else if (dev->norm & (V4L2_STD_PAL_DK | V4L2_STD_SECAM_DK))
if_frequency = 6900000;
else if (dev->norm & V4L2_STD_GH)
if_frequency = 7100000;
else if (dev->norm & V4L2_STD_PAL_I)
if_frequency = 7250000;
else if (dev->norm & V4L2_STD_SECAM_L)
if_frequency = 6900000;
else if (dev->norm & V4L2_STD_SECAM_LC)
if_frequency = 1250000;
dev_dbg(dev->dev,
"if_frequency is set to %d\n", if_frequency);
cx231xx_set_Colibri_For_LowIF(dev, if_frequency, 1, 1);
update_HH_register_after_set_DIF(dev);
}
dev_dbg(dev->dev, "Set New FREQUENCY to %d\n", f->frequency);
return rc;
}
int cx231xx_g_chip_info(struct file *file, void *fh,
struct v4l2_dbg_chip_info *chip)
{
switch (chip->match.addr) {
case 0:
return 0;
case 1:
strlcpy(chip->name, "AFE (byte)", sizeof(chip->name));
return 0;
case 2:
strlcpy(chip->name, "Video (byte)", sizeof(chip->name));
return 0;
case 3:
strlcpy(chip->name, "I2S (byte)", sizeof(chip->name));
return 0;
case 4:
strlcpy(chip->name, "AFE (dword)", sizeof(chip->name));
return 0;
case 5:
strlcpy(chip->name, "Video (dword)", sizeof(chip->name));
return 0;
case 6:
strlcpy(chip->name, "I2S (dword)", sizeof(chip->name));
return 0;
}
return -EINVAL;
}
int cx231xx_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int ret;
u8 value[4] = { 0, 0, 0, 0 };
u32 data = 0;
switch (reg->match.addr) {
case 0:
ret = cx231xx_read_ctrl_reg(dev, VRT_GET_REGISTER,
(u16)reg->reg, value, 4);
reg->val = value[0] | value[1] << 8 |
value[2] << 16 | value[3] << 24;
reg->size = 4;
break;
case 1:
ret = cx231xx_read_i2c_data(dev, AFE_DEVICE_ADDRESS,
(u16)reg->reg, 2, &data, 1);
reg->val = data;
reg->size = 1;
break;
case 2:
ret = cx231xx_read_i2c_data(dev, VID_BLK_I2C_ADDRESS,
(u16)reg->reg, 2, &data, 1);
reg->val = data;
reg->size = 1;
break;
case 3:
ret = cx231xx_read_i2c_data(dev, I2S_BLK_DEVICE_ADDRESS,
(u16)reg->reg, 1, &data, 1);
reg->val = data;
reg->size = 1;
break;
case 4:
ret = cx231xx_read_i2c_data(dev, AFE_DEVICE_ADDRESS,
(u16)reg->reg, 2, &data, 4);
reg->val = data;
reg->size = 4;
break;
case 5:
ret = cx231xx_read_i2c_data(dev, VID_BLK_I2C_ADDRESS,
(u16)reg->reg, 2, &data, 4);
reg->val = data;
reg->size = 4;
break;
case 6:
ret = cx231xx_read_i2c_data(dev, I2S_BLK_DEVICE_ADDRESS,
(u16)reg->reg, 1, &data, 4);
reg->val = data;
reg->size = 4;
break;
default:
return -EINVAL;
}
return ret < 0 ? ret : 0;
}
int cx231xx_s_register(struct file *file, void *priv,
const struct v4l2_dbg_register *reg)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int ret;
u8 data[4] = { 0, 0, 0, 0 };
switch (reg->match.addr) {
case 0:
data[0] = (u8) reg->val;
data[1] = (u8) (reg->val >> 8);
data[2] = (u8) (reg->val >> 16);
data[3] = (u8) (reg->val >> 24);
ret = cx231xx_write_ctrl_reg(dev, VRT_SET_REGISTER,
(u16)reg->reg, data, 4);
break;
case 1:
ret = cx231xx_write_i2c_data(dev, AFE_DEVICE_ADDRESS,
(u16)reg->reg, 2, reg->val, 1);
break;
case 2:
ret = cx231xx_write_i2c_data(dev, VID_BLK_I2C_ADDRESS,
(u16)reg->reg, 2, reg->val, 1);
break;
case 3:
ret = cx231xx_write_i2c_data(dev, I2S_BLK_DEVICE_ADDRESS,
(u16)reg->reg, 1, reg->val, 1);
break;
case 4:
ret = cx231xx_write_i2c_data(dev, AFE_DEVICE_ADDRESS,
(u16)reg->reg, 2, reg->val, 4);
break;
case 5:
ret = cx231xx_write_i2c_data(dev, VID_BLK_I2C_ADDRESS,
(u16)reg->reg, 2, reg->val, 4);
break;
case 6:
ret = cx231xx_write_i2c_data(dev, I2S_BLK_DEVICE_ADDRESS,
(u16)reg->reg, 1, reg->val, 4);
break;
default:
return -EINVAL;
}
return ret < 0 ? ret : 0;
}
static int vidioc_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *cc)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
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
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
rc = res_get(fh);
if (likely(rc >= 0))
rc = videobuf_streamon(&fh->vb_vidq);
call_all(dev, video, s_stream, 1);
return rc;
}
static int vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (type != fh->type)
return -EINVAL;
cx25840_call(dev, video, s_stream, 0);
videobuf_streamoff(&fh->vb_vidq);
res_free(fh);
return 0;
}
int cx231xx_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
strlcpy(cap->driver, "cx231xx", sizeof(cap->driver));
strlcpy(cap->card, cx231xx_boards[dev->model].name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
if (vdev->vfl_type == VFL_TYPE_RADIO)
cap->device_caps = V4L2_CAP_RADIO;
else {
cap->device_caps = V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
if (vdev->vfl_type == VFL_TYPE_VBI)
cap->device_caps |= V4L2_CAP_VBI_CAPTURE;
else
cap->device_caps |= V4L2_CAP_VIDEO_CAPTURE;
}
if (dev->tuner_type != TUNER_ABSENT)
cap->device_caps |= V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_READWRITE |
V4L2_CAP_VBI_CAPTURE | V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING | V4L2_CAP_DEVICE_CAPS;
if (video_is_registered(&dev->radio_dev))
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
static int vidioc_g_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
f->fmt.vbi.sampling_rate = 6750000 * 4;
f->fmt.vbi.samples_per_line = VBI_LINE_LENGTH;
f->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
f->fmt.vbi.offset = 0;
f->fmt.vbi.start[0] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_START_LINE : NTSC_VBI_START_LINE;
f->fmt.vbi.count[0] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES;
f->fmt.vbi.start[1] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_START_LINE + 312 : NTSC_VBI_START_LINE + 263;
f->fmt.vbi.count[1] = f->fmt.vbi.count[0];
memset(f->fmt.vbi.reserved, 0, sizeof(f->fmt.vbi.reserved));
return 0;
}
static int vidioc_try_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
f->fmt.vbi.sampling_rate = 6750000 * 4;
f->fmt.vbi.samples_per_line = VBI_LINE_LENGTH;
f->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
f->fmt.vbi.offset = 0;
f->fmt.vbi.flags = 0;
f->fmt.vbi.start[0] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_START_LINE : NTSC_VBI_START_LINE;
f->fmt.vbi.count[0] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES;
f->fmt.vbi.start[1] = (dev->norm & V4L2_STD_625_50) ?
PAL_VBI_START_LINE + 312 : NTSC_VBI_START_LINE + 263;
f->fmt.vbi.count[1] = f->fmt.vbi.count[0];
memset(f->fmt.vbi.reserved, 0, sizeof(f->fmt.vbi.reserved));
return 0;
}
static int vidioc_s_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
if (dev->vbi_stream_on && !fh->stream_on) {
dev_err(dev->dev,
"%s device in use by another fh\n", __func__);
return -EBUSY;
}
return vidioc_try_fmt_vbi_cap(file, priv, f);
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *rb)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
return videobuf_reqbufs(&fh->vb_vidq, rb);
}
static int vidioc_querybuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
return videobuf_querybuf(&fh->vb_vidq, b);
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
return videobuf_qbuf(&fh->vb_vidq, b);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct cx231xx_fh *fh = priv;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
return videobuf_dqbuf(&fh->vb_vidq, b, file->f_flags & O_NONBLOCK);
}
static int radio_g_tuner(struct file *file, void *priv, struct v4l2_tuner *t)
{
struct cx231xx *dev = ((struct cx231xx_fh *)priv)->dev;
if (t->index)
return -EINVAL;
strcpy(t->name, "Radio");
call_all(dev, tuner, g_tuner, t);
return 0;
}
static int radio_s_tuner(struct file *file, void *priv, const struct v4l2_tuner *t)
{
struct cx231xx *dev = ((struct cx231xx_fh *)priv)->dev;
if (t->index)
return -EINVAL;
call_all(dev, tuner, s_tuner, t);
return 0;
}
static int cx231xx_v4l2_open(struct file *filp)
{
int radio = 0;
struct video_device *vdev = video_devdata(filp);
struct cx231xx *dev = video_drvdata(filp);
struct cx231xx_fh *fh;
enum v4l2_buf_type fh_type = 0;
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
cx231xx_videodbg("open dev=%s type=%s users=%d\n",
video_device_node_name(vdev), v4l2_type_names[fh_type],
dev->users);
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
dev_err(dev->dev,
"Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
fh = kzalloc(sizeof(struct cx231xx_fh), GFP_KERNEL);
if (!fh)
return -ENOMEM;
if (mutex_lock_interruptible(&dev->lock)) {
kfree(fh);
return -ERESTARTSYS;
}
fh->dev = dev;
fh->type = fh_type;
filp->private_data = fh;
v4l2_fh_init(&fh->fh, vdev);
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE && dev->users == 0) {
if (dev->board.external_av)
cx231xx_set_power_mode(dev,
POLARIS_AVMODE_ENXTERNAL_AV);
else
cx231xx_set_power_mode(dev, POLARIS_AVMODE_ANALOGT_TV);
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
cx231xx_set_video_alternate(dev);
cx231xx_config_i2c(dev);
dev->video_input = dev->video_input > 2 ? 2 : dev->video_input;
}
if (radio) {
cx231xx_videodbg("video_open: setting radio device\n");
call_all(dev, tuner, s_radio);
}
dev->users++;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
videobuf_queue_vmalloc_init(&fh->vb_vidq, &cx231xx_video_qops,
NULL, &dev->video_mode.slock,
fh->type, V4L2_FIELD_INTERLACED,
sizeof(struct cx231xx_buffer),
fh, &dev->lock);
if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
cx231xx_set_alt_setting(dev, INDEX_VANC, 0);
videobuf_queue_vmalloc_init(&fh->vb_vidq, &cx231xx_vbi_qops,
NULL, &dev->vbi_mode.slock,
fh->type, V4L2_FIELD_SEQ_TB,
sizeof(struct cx231xx_buffer),
fh, &dev->lock);
}
mutex_unlock(&dev->lock);
v4l2_fh_add(&fh->fh);
return 0;
}
void cx231xx_release_analog_resources(struct cx231xx *dev)
{
if (video_is_registered(&dev->radio_dev))
video_unregister_device(&dev->radio_dev);
if (video_is_registered(&dev->vbi_dev)) {
dev_info(dev->dev, "V4L2 device %s deregistered\n",
video_device_node_name(&dev->vbi_dev));
video_unregister_device(&dev->vbi_dev);
}
if (video_is_registered(&dev->vdev)) {
dev_info(dev->dev, "V4L2 device %s deregistered\n",
video_device_node_name(&dev->vdev));
if (dev->board.has_417)
cx231xx_417_unregister(dev);
video_unregister_device(&dev->vdev);
}
v4l2_ctrl_handler_free(&dev->ctrl_handler);
v4l2_ctrl_handler_free(&dev->radio_ctrl_handler);
}
static int cx231xx_close(struct file *filp)
{
struct cx231xx_fh *fh = filp->private_data;
struct cx231xx *dev = fh->dev;
cx231xx_videodbg("users=%d\n", dev->users);
cx231xx_videodbg("users=%d\n", dev->users);
if (res_check(fh))
res_free(fh);
if (!dev->board.no_alt_vanc)
if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
videobuf_stop(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vidq);
if (dev->state & DEV_DISCONNECTED) {
if (atomic_read(&dev->devlist_count) > 0) {
cx231xx_release_resources(dev);
fh->dev = NULL;
return 0;
}
return 0;
}
cx231xx_uninit_vbi_isoc(dev);
if (!dev->vbi_or_sliced_cc_mode)
cx231xx_set_alt_setting(dev, INDEX_VANC, 0);
else
cx231xx_set_alt_setting(dev, INDEX_HANC, 0);
v4l2_fh_del(&fh->fh);
v4l2_fh_exit(&fh->fh);
kfree(fh);
dev->users--;
wake_up_interruptible_nr(&dev->open, 1);
return 0;
}
v4l2_fh_del(&fh->fh);
dev->users--;
if (!dev->users) {
videobuf_stop(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vidq);
if (dev->state & DEV_DISCONNECTED) {
cx231xx_release_resources(dev);
fh->dev = NULL;
return 0;
}
call_all(dev, core, s_power, 0);
if (dev->USE_ISO)
cx231xx_uninit_isoc(dev);
else
cx231xx_uninit_bulk(dev);
cx231xx_set_mode(dev, CX231XX_SUSPEND);
cx231xx_set_alt_setting(dev, INDEX_VIDEO, 0);
}
v4l2_fh_exit(&fh->fh);
kfree(fh);
wake_up_interruptible_nr(&dev->open, 1);
return 0;
}
static int cx231xx_v4l2_close(struct file *filp)
{
struct cx231xx_fh *fh = filp->private_data;
struct cx231xx *dev = fh->dev;
int rc;
mutex_lock(&dev->lock);
rc = cx231xx_close(filp);
mutex_unlock(&dev->lock);
return rc;
}
static ssize_t
cx231xx_v4l2_read(struct file *filp, char __user *buf, size_t count,
loff_t *pos)
{
struct cx231xx_fh *fh = filp->private_data;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if ((fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) ||
(fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)) {
rc = res_get(fh);
if (unlikely(rc < 0))
return rc;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
rc = videobuf_read_stream(&fh->vb_vidq, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
mutex_unlock(&dev->lock);
return rc;
}
return 0;
}
static unsigned int cx231xx_v4l2_poll(struct file *filp, poll_table *wait)
{
unsigned long req_events = poll_requested_events(wait);
struct cx231xx_fh *fh = filp->private_data;
struct cx231xx *dev = fh->dev;
unsigned res = 0;
int rc;
rc = check_dev(dev);
if (rc < 0)
return POLLERR;
rc = res_get(fh);
if (unlikely(rc < 0))
return POLLERR;
if (v4l2_event_pending(&fh->fh))
res |= POLLPRI;
else
poll_wait(filp, &fh->fh.wait, wait);
if (!(req_events & (POLLIN | POLLRDNORM)))
return res;
if ((V4L2_BUF_TYPE_VIDEO_CAPTURE == fh->type) ||
(V4L2_BUF_TYPE_VBI_CAPTURE == fh->type)) {
mutex_lock(&dev->lock);
res |= videobuf_poll_stream(filp, &fh->vb_vidq, wait);
mutex_unlock(&dev->lock);
return res;
}
return res | POLLERR;
}
static int cx231xx_v4l2_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct cx231xx_fh *fh = filp->private_data;
struct cx231xx *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
rc = res_get(fh);
if (unlikely(rc < 0))
return rc;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
rc = videobuf_mmap_mapper(&fh->vb_vidq, vma);
mutex_unlock(&dev->lock);
cx231xx_videodbg("vma start=0x%08lx, size=%ld, ret=%d\n",
(unsigned long)vma->vm_start,
(unsigned long)vma->vm_end -
(unsigned long)vma->vm_start, rc);
return rc;
}
static void cx231xx_vdev_init(struct cx231xx *dev,
struct video_device *vfd,
const struct video_device *template,
const char *type_name)
{
*vfd = *template;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->release = video_device_release_empty;
vfd->lock = &dev->lock;
snprintf(vfd->name, sizeof(vfd->name), "%s %s", dev->name, type_name);
video_set_drvdata(vfd, dev);
if (dev->tuner_type == TUNER_ABSENT) {
v4l2_disable_ioctl(vfd, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(vfd, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(vfd, VIDIOC_G_TUNER);
v4l2_disable_ioctl(vfd, VIDIOC_S_TUNER);
}
}
int cx231xx_register_analog_devices(struct cx231xx *dev)
{
int ret;
dev_info(dev->dev, "v4l2 driver version %s\n", CX231XX_VERSION);
dev->norm = V4L2_STD_PAL;
dev->width = norm_maxw(dev);
dev->height = norm_maxh(dev);
dev->interlaced = 0;
dev->format = &format[0];
video_mux(dev, dev->video_input);
call_all(dev, video, s_std, dev->norm);
v4l2_ctrl_handler_init(&dev->ctrl_handler, 10);
v4l2_ctrl_handler_init(&dev->radio_ctrl_handler, 5);
if (dev->sd_cx25840) {
v4l2_ctrl_add_handler(&dev->ctrl_handler,
dev->sd_cx25840->ctrl_handler, NULL);
v4l2_ctrl_add_handler(&dev->radio_ctrl_handler,
dev->sd_cx25840->ctrl_handler,
v4l2_ctrl_radio_filter);
}
if (dev->ctrl_handler.error)
return dev->ctrl_handler.error;
if (dev->radio_ctrl_handler.error)
return dev->radio_ctrl_handler.error;
cx231xx_vdev_init(dev, &dev->vdev, &cx231xx_video_template, "video");
#if defined(CONFIG_MEDIA_CONTROLLER)
dev->video_pad.flags = MEDIA_PAD_FL_SINK;
ret = media_entity_init(&dev->vdev.entity, 1, &dev->video_pad, 0);
if (ret < 0)
dev_err(dev->dev, "failed to initialize video media entity!\n");
#endif
dev->vdev.ctrl_handler = &dev->ctrl_handler;
ret = video_register_device(&dev->vdev, VFL_TYPE_GRABBER,
video_nr[dev->devno]);
if (ret) {
dev_err(dev->dev,
"unable to register video device (error=%i).\n",
ret);
return ret;
}
dev_info(dev->dev, "Registered video device %s [v4l2]\n",
video_device_node_name(&dev->vdev));
cx231xx_vbi_template = cx231xx_video_template;
strcpy(cx231xx_vbi_template.name, "cx231xx-vbi");
cx231xx_vdev_init(dev, &dev->vbi_dev, &cx231xx_vbi_template, "vbi");
#if defined(CONFIG_MEDIA_CONTROLLER)
dev->vbi_pad.flags = MEDIA_PAD_FL_SINK;
ret = media_entity_init(&dev->vbi_dev.entity, 1, &dev->vbi_pad, 0);
if (ret < 0)
dev_err(dev->dev, "failed to initialize vbi media entity!\n");
#endif
dev->vbi_dev.ctrl_handler = &dev->ctrl_handler;
ret = video_register_device(&dev->vbi_dev, VFL_TYPE_VBI,
vbi_nr[dev->devno]);
if (ret < 0) {
dev_err(dev->dev, "unable to register vbi device\n");
return ret;
}
dev_info(dev->dev, "Registered VBI device %s\n",
video_device_node_name(&dev->vbi_dev));
if (cx231xx_boards[dev->model].radio.type == CX231XX_RADIO) {
cx231xx_vdev_init(dev, &dev->radio_dev,
&cx231xx_radio_template, "radio");
dev->radio_dev.ctrl_handler = &dev->radio_ctrl_handler;
ret = video_register_device(&dev->radio_dev, VFL_TYPE_RADIO,
radio_nr[dev->devno]);
if (ret < 0) {
dev_err(dev->dev,
"can't register radio device\n");
return ret;
}
dev_info(dev->dev, "Registered radio device as %s\n",
video_device_node_name(&dev->radio_dev));
}
return 0;
}
