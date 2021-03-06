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
dev_err(dev->dev,
"URB status %d [%s].\n", status, errmsg);
} else {
dev_err(dev->dev,
"URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline int cx231xx_isoc_vbi_copy(struct cx231xx *dev, struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
int rc = 1;
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
p_buffer = urb->transfer_buffer;
buffer_size = urb->actual_length;
if (buffer_size > 0) {
bytes_parsed = 0;
if (dma_q->is_partial_line) {
sav_eav = dma_q->last_sav;
} else {
sav_eav = cx231xx_find_boundary_SAV_EAV(p_buffer,
dma_q->partial_buf,
&bytes_parsed);
}
sav_eav &= 0xF0;
if (sav_eav) {
bytes_parsed += cx231xx_get_vbi_line(dev, dma_q,
sav_eav,
p_buffer + bytes_parsed,
buffer_size - bytes_parsed);
}
dma_q->is_partial_line = 0;
while (bytes_parsed < buffer_size) {
u32 bytes_used = 0;
sav_eav = cx231xx_find_next_SAV_EAV(
p_buffer + bytes_parsed,
buffer_size - bytes_parsed,
&bytes_used);
bytes_parsed += bytes_used;
sav_eav &= 0xF0;
if (sav_eav && (bytes_parsed < buffer_size)) {
bytes_parsed += cx231xx_get_vbi_line(dev,
dma_q, sav_eav,
p_buffer+bytes_parsed,
buffer_size-bytes_parsed);
}
}
memcpy(dma_q->partial_buf, p_buffer + buffer_size - 4, 4);
bytes_parsed = 0;
}
return rc;
}
static int
vbi_buffer_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
u32 height = 0;
height = ((dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES);
*size = (dev->width * height * 2 * 2);
if (0 == *count)
*count = CX231XX_DEF_VBI_BUF;
if (*count < CX231XX_MIN_BUF)
*count = CX231XX_MIN_BUF;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct cx231xx_buffer *buf)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->vbi_mode.slock, flags);
if (dev->vbi_mode.bulk_ctl.buf == buf)
dev->vbi_mode.bulk_ctl.buf = NULL;
spin_unlock_irqrestore(&dev->vbi_mode.slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
vbi_buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx *dev = fh->dev;
int rc = 0, urb_init = 0;
u32 height = 0;
height = ((dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES);
buf->vb.size = ((dev->width << 1) * height * 2);
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
buf->vb.width = dev->width;
buf->vb.height = height;
buf->vb.field = field;
buf->vb.field = V4L2_FIELD_SEQ_TB;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
rc = videobuf_iolock(vq, &buf->vb, NULL);
if (rc < 0)
goto fail;
}
if (!dev->vbi_mode.bulk_ctl.num_bufs)
urb_init = 1;
if (urb_init) {
rc = cx231xx_init_vbi_isoc(dev, CX231XX_NUM_VBI_PACKETS,
CX231XX_NUM_VBI_BUFS,
dev->vbi_mode.alt_max_pkt_size[0],
cx231xx_isoc_vbi_copy);
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
vbi_buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
struct cx231xx_fh *fh = vq->priv_data;
struct cx231xx *dev = fh->dev;
struct cx231xx_dmaqueue *vidq = &dev->vbi_mode.vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void vbi_buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct cx231xx_buffer *buf =
container_of(vb, struct cx231xx_buffer, vb);
free_buffer(vq, buf);
}
static void cx231xx_irq_vbi_callback(struct urb *urb)
{
struct cx231xx_dmaqueue *dma_q = urb->context;
struct cx231xx_video_mode *vmode =
container_of(dma_q, struct cx231xx_video_mode, vidq);
struct cx231xx *dev = container_of(vmode, struct cx231xx, vbi_mode);
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_err(dev->dev,
"urb completition error %d.\n", urb->status);
break;
}
spin_lock(&dev->vbi_mode.slock);
dev->vbi_mode.bulk_ctl.bulk_copy(dev, urb);
spin_unlock(&dev->vbi_mode.slock);
urb->status = 0;
urb->status = usb_submit_urb(urb, GFP_ATOMIC);
if (urb->status) {
dev_err(dev->dev, "urb resubmit failed (error=%i)\n",
urb->status);
}
}
void cx231xx_uninit_vbi_isoc(struct cx231xx *dev)
{
struct urb *urb;
int i;
dev_dbg(dev->dev, "called cx231xx_uninit_vbi_isoc\n");
dev->vbi_mode.bulk_ctl.nfields = -1;
for (i = 0; i < dev->vbi_mode.bulk_ctl.num_bufs; i++) {
urb = dev->vbi_mode.bulk_ctl.urb[i];
if (urb) {
if (!irqs_disabled())
usb_kill_urb(urb);
else
usb_unlink_urb(urb);
if (dev->vbi_mode.bulk_ctl.transfer_buffer[i]) {
kfree(dev->vbi_mode.bulk_ctl.
transfer_buffer[i]);
dev->vbi_mode.bulk_ctl.transfer_buffer[i] =
NULL;
}
usb_free_urb(urb);
dev->vbi_mode.bulk_ctl.urb[i] = NULL;
}
dev->vbi_mode.bulk_ctl.transfer_buffer[i] = NULL;
}
kfree(dev->vbi_mode.bulk_ctl.urb);
kfree(dev->vbi_mode.bulk_ctl.transfer_buffer);
dev->vbi_mode.bulk_ctl.urb = NULL;
dev->vbi_mode.bulk_ctl.transfer_buffer = NULL;
dev->vbi_mode.bulk_ctl.num_bufs = 0;
cx231xx_capture_start(dev, 0, Vbi);
}
int cx231xx_init_vbi_isoc(struct cx231xx *dev, int max_packets,
int num_bufs, int max_pkt_size,
int (*bulk_copy) (struct cx231xx *dev,
struct urb *urb))
{
struct cx231xx_dmaqueue *dma_q = &dev->vbi_mode.vidq;
int i;
int sb_size, pipe;
struct urb *urb;
int rc;
dev_dbg(dev->dev, "called cx231xx_vbi_isoc\n");
cx231xx_uninit_vbi_isoc(dev);
usb_clear_halt(dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->vbi_mode.end_point_addr));
dev->vbi_mode.bulk_ctl.bulk_copy = bulk_copy;
dev->vbi_mode.bulk_ctl.num_bufs = num_bufs;
dma_q->pos = 0;
dma_q->is_partial_line = 0;
dma_q->last_sav = 0;
dma_q->current_field = -1;
dma_q->bytes_left_in_line = dev->width << 1;
dma_q->lines_per_field = ((dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES);
dma_q->lines_completed = 0;
for (i = 0; i < 8; i++)
dma_q->partial_buf[i] = 0;
dev->vbi_mode.bulk_ctl.urb = kzalloc(sizeof(void *) * num_bufs,
GFP_KERNEL);
if (!dev->vbi_mode.bulk_ctl.urb) {
dev_err(dev->dev,
"cannot alloc memory for usb buffers\n");
return -ENOMEM;
}
dev->vbi_mode.bulk_ctl.transfer_buffer =
kzalloc(sizeof(void *) * num_bufs, GFP_KERNEL);
if (!dev->vbi_mode.bulk_ctl.transfer_buffer) {
dev_err(dev->dev,
"cannot allocate memory for usbtransfer\n");
kfree(dev->vbi_mode.bulk_ctl.urb);
return -ENOMEM;
}
dev->vbi_mode.bulk_ctl.max_pkt_size = max_pkt_size;
dev->vbi_mode.bulk_ctl.buf = NULL;
sb_size = max_packets * dev->vbi_mode.bulk_ctl.max_pkt_size;
for (i = 0; i < dev->vbi_mode.bulk_ctl.num_bufs; i++) {
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
dev_err(dev->dev,
"cannot alloc bulk_ctl.urb %i\n", i);
cx231xx_uninit_vbi_isoc(dev);
return -ENOMEM;
}
dev->vbi_mode.bulk_ctl.urb[i] = urb;
urb->transfer_flags = 0;
dev->vbi_mode.bulk_ctl.transfer_buffer[i] =
kzalloc(sb_size, GFP_KERNEL);
if (!dev->vbi_mode.bulk_ctl.transfer_buffer[i]) {
dev_err(dev->dev,
"unable to allocate %i bytes for transfer buffer %i%s\n",
sb_size, i,
in_interrupt() ? " while in int" : "");
cx231xx_uninit_vbi_isoc(dev);
return -ENOMEM;
}
pipe = usb_rcvbulkpipe(dev->udev, dev->vbi_mode.end_point_addr);
usb_fill_bulk_urb(urb, dev->udev, pipe,
dev->vbi_mode.bulk_ctl.transfer_buffer[i],
sb_size, cx231xx_irq_vbi_callback, dma_q);
}
init_waitqueue_head(&dma_q->wq);
for (i = 0; i < dev->vbi_mode.bulk_ctl.num_bufs; i++) {
rc = usb_submit_urb(dev->vbi_mode.bulk_ctl.urb[i], GFP_ATOMIC);
if (rc) {
dev_err(dev->dev,
"submit of urb %i failed (error=%i)\n", i, rc);
cx231xx_uninit_vbi_isoc(dev);
return rc;
}
}
cx231xx_capture_start(dev, 1, Vbi);
return 0;
}
u32 cx231xx_get_vbi_line(struct cx231xx *dev, struct cx231xx_dmaqueue *dma_q,
u8 sav_eav, u8 *p_buffer, u32 buffer_size)
{
u32 bytes_copied = 0;
int current_field = -1;
switch (sav_eav) {
case SAV_VBI_FIELD1:
current_field = 1;
break;
case SAV_VBI_FIELD2:
current_field = 2;
break;
default:
break;
}
if (current_field < 0)
return bytes_copied;
dma_q->last_sav = sav_eav;
bytes_copied =
cx231xx_copy_vbi_line(dev, dma_q, p_buffer, buffer_size,
current_field);
return bytes_copied;
}
static inline void vbi_buffer_filled(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q,
struct cx231xx_buffer *buf)
{
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
dev->vbi_mode.bulk_ctl.buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
u32 cx231xx_copy_vbi_line(struct cx231xx *dev, struct cx231xx_dmaqueue *dma_q,
u8 *p_line, u32 length, int field_number)
{
u32 bytes_to_copy;
struct cx231xx_buffer *buf;
u32 _line_size = dev->width * 2;
if (dma_q->current_field == -1) {
cx231xx_reset_vbi_buffer(dev, dma_q);
}
if (dma_q->current_field != field_number)
dma_q->lines_completed = 0;
buf = dev->vbi_mode.bulk_ctl.buf;
dma_q->current_field = field_number;
bytes_to_copy = dma_q->bytes_left_in_line;
if (bytes_to_copy > length)
bytes_to_copy = length;
if (dma_q->lines_completed >= dma_q->lines_per_field) {
dma_q->bytes_left_in_line -= bytes_to_copy;
dma_q->is_partial_line =
(dma_q->bytes_left_in_line == 0) ? 0 : 1;
return 0;
}
dma_q->is_partial_line = 1;
if (!buf) {
dma_q->bytes_left_in_line -= bytes_to_copy;
dma_q->is_partial_line =
(dma_q->bytes_left_in_line == 0) ? 0 : 1;
return bytes_to_copy;
}
cx231xx_do_vbi_copy(dev, dma_q, p_line, bytes_to_copy);
dma_q->pos += bytes_to_copy;
dma_q->bytes_left_in_line -= bytes_to_copy;
if (dma_q->bytes_left_in_line == 0) {
dma_q->bytes_left_in_line = _line_size;
dma_q->lines_completed++;
dma_q->is_partial_line = 0;
if (cx231xx_is_vbi_buffer_done(dev, dma_q) && buf) {
vbi_buffer_filled(dev, dma_q, buf);
dma_q->pos = 0;
dma_q->lines_completed = 0;
cx231xx_reset_vbi_buffer(dev, dma_q);
}
}
return bytes_to_copy;
}
static inline void get_next_vbi_buf(struct cx231xx_dmaqueue *dma_q,
struct cx231xx_buffer **buf)
{
struct cx231xx_video_mode *vmode =
container_of(dma_q, struct cx231xx_video_mode, vidq);
struct cx231xx *dev = container_of(vmode, struct cx231xx, vbi_mode);
char *outp;
if (list_empty(&dma_q->active)) {
dev_err(dev->dev, "No active queue to serve\n");
dev->vbi_mode.bulk_ctl.buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct cx231xx_buffer, vb.queue);
outp = videobuf_to_vmalloc(&(*buf)->vb);
memset(outp, 0, (*buf)->vb.size);
dev->vbi_mode.bulk_ctl.buf = *buf;
return;
}
void cx231xx_reset_vbi_buffer(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q)
{
struct cx231xx_buffer *buf;
buf = dev->vbi_mode.bulk_ctl.buf;
if (buf == NULL) {
get_next_vbi_buf(dma_q, &buf);
dma_q->pos = 0;
dma_q->current_field = -1;
}
dma_q->bytes_left_in_line = dev->width << 1;
dma_q->lines_completed = 0;
}
int cx231xx_do_vbi_copy(struct cx231xx *dev, struct cx231xx_dmaqueue *dma_q,
u8 *p_buffer, u32 bytes_to_copy)
{
u8 *p_out_buffer = NULL;
u32 current_line_bytes_copied = 0;
struct cx231xx_buffer *buf;
u32 _line_size = dev->width << 1;
void *startwrite;
int offset, lencopy;
buf = dev->vbi_mode.bulk_ctl.buf;
if (buf == NULL)
return -EINVAL;
p_out_buffer = videobuf_to_vmalloc(&buf->vb);
if (dma_q->bytes_left_in_line != _line_size) {
current_line_bytes_copied =
_line_size - dma_q->bytes_left_in_line;
}
offset = (dma_q->lines_completed * _line_size) +
current_line_bytes_copied;
if (dma_q->current_field == 2) {
offset += (dev->width * 2 * dma_q->lines_per_field);
}
startwrite = p_out_buffer + offset;
lencopy = dma_q->bytes_left_in_line > bytes_to_copy ?
bytes_to_copy : dma_q->bytes_left_in_line;
memcpy(startwrite, p_buffer, lencopy);
return 0;
}
u8 cx231xx_is_vbi_buffer_done(struct cx231xx *dev,
struct cx231xx_dmaqueue *dma_q)
{
u32 height = 0;
height = ((dev->norm & V4L2_STD_625_50) ?
PAL_VBI_LINES : NTSC_VBI_LINES);
if (dma_q->lines_completed == height && dma_q->current_field == 2)
return 1;
else
return 0;
}
