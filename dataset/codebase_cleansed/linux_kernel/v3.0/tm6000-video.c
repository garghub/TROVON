static const struct v4l2_queryctrl *ctrl_by_id(unsigned int id)
{
unsigned int i;
for (i = 0; i < CTRLS; i++)
if (tm6000_qctrl[i].id == id)
return tm6000_qctrl+i;
return NULL;
}
static inline void get_next_buf(struct tm6000_dmaqueue *dma_q,
struct tm6000_buffer **buf)
{
struct tm6000_core *dev = container_of(dma_q, struct tm6000_core, vidq);
char *outp;
if (list_empty(&dma_q->active)) {
dprintk(dev, V4L2_DEBUG_QUEUE, "No active queue to serve\n");
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next,
struct tm6000_buffer, vb.queue);
if (!buf)
return;
outp = videobuf_to_vmalloc(&(*buf)->vb);
return;
}
static inline void buffer_filled(struct tm6000_core *dev,
struct tm6000_dmaqueue *dma_q,
struct tm6000_buffer *buf)
{
dprintk(dev, V4L2_DEBUG_ISOC, "[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
do_gettimeofday(&buf->vb.ts);
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static int copy_streams(u8 *data, unsigned long len,
struct urb *urb)
{
struct tm6000_dmaqueue *dma_q = urb->context;
struct tm6000_core *dev = container_of(dma_q, struct tm6000_core, vidq);
u8 *ptr = data, *endp = data+len, c;
unsigned long header = 0;
int rc = 0;
unsigned int cmd, cpysize, pktsize, size, field, block, line, pos = 0;
struct tm6000_buffer *vbuf = NULL;
char *voutp = NULL;
unsigned int linewidth;
if (!dev->radio) {
get_next_buf(dma_q, &vbuf);
if (!vbuf)
return rc;
voutp = videobuf_to_vmalloc(&vbuf->vb);
if (!voutp)
return 0;
}
for (ptr = data; ptr < endp;) {
if (!dev->isoc_ctl.cmd) {
if (dev->isoc_ctl.tmp_buf_len > 0) {
header = dev->isoc_ctl.tmp_buf;
if (4 - dev->isoc_ctl.tmp_buf_len > 0) {
memcpy((u8 *)&header +
dev->isoc_ctl.tmp_buf_len,
ptr,
4 - dev->isoc_ctl.tmp_buf_len);
ptr += 4 - dev->isoc_ctl.tmp_buf_len;
}
dev->isoc_ctl.tmp_buf_len = 0;
} else {
if (ptr + 3 >= endp) {
dev->isoc_ctl.tmp_buf_len = endp - ptr;
memcpy(&dev->isoc_ctl.tmp_buf, ptr,
dev->isoc_ctl.tmp_buf_len);
return rc;
}
for (; ptr < endp - 3; ptr++) {
if (*(ptr + 3) == 0x47)
break;
}
header = *(unsigned long *)ptr;
ptr += 4;
}
c = (header >> 24) & 0xff;
size = ((header & 0x7e) << 1);
if (size > 0)
size -= 4;
block = (header >> 7) & 0xf;
field = (header >> 11) & 0x1;
line = (header >> 12) & 0x1ff;
cmd = (header >> 21) & 0x7;
if (size > TM6000_URB_MSG_LEN)
size = TM6000_URB_MSG_LEN;
pktsize = TM6000_URB_MSG_LEN;
switch (cmd) {
case TM6000_URB_MSG_VIDEO:
if (!dev->radio) {
if ((dev->isoc_ctl.vfield != field) &&
(field == 1)) {
buffer_filled(dev, dma_q, vbuf);
dprintk(dev, V4L2_DEBUG_ISOC,
"new buffer filled\n");
get_next_buf(dma_q, &vbuf);
if (!vbuf)
return rc;
voutp = videobuf_to_vmalloc(&vbuf->vb);
if (!voutp)
return rc;
memset(voutp, 0, vbuf->vb.size);
}
linewidth = vbuf->vb.width << 1;
pos = ((line << 1) - field - 1) *
linewidth + block * TM6000_URB_MSG_LEN;
if (pos + size > vbuf->vb.size)
cmd = TM6000_URB_MSG_ERR;
dev->isoc_ctl.vfield = field;
}
break;
case TM6000_URB_MSG_VBI:
break;
case TM6000_URB_MSG_AUDIO:
case TM6000_URB_MSG_PTS:
size = pktsize;
break;
}
} else {
cmd = dev->isoc_ctl.cmd;
size = dev->isoc_ctl.size;
pos = dev->isoc_ctl.pos;
pktsize = dev->isoc_ctl.pktsize;
field = dev->isoc_ctl.field;
}
cpysize = (endp - ptr > size) ? size : endp - ptr;
if (cpysize) {
switch (cmd) {
case TM6000_URB_MSG_VIDEO:
if (vbuf)
memcpy(&voutp[pos], ptr, cpysize);
break;
case TM6000_URB_MSG_AUDIO: {
int i;
for (i = 0; i < cpysize; i += 2)
swab16s((u16 *)(ptr + i));
tm6000_call_fillbuf(dev, TM6000_AUDIO, ptr, cpysize);
break;
}
case TM6000_URB_MSG_VBI:
break;
case TM6000_URB_MSG_PTS: {
u32 pts;
pts = *(u32 *)ptr;
dprintk(dev, V4L2_DEBUG_ISOC, "field %d, PTS %x",
field, pts);
break;
}
}
}
if (ptr + pktsize > endp) {
dev->isoc_ctl.pos = pos + cpysize;
dev->isoc_ctl.size = size - cpysize;
dev->isoc_ctl.cmd = cmd;
dev->isoc_ctl.field = field;
dev->isoc_ctl.pktsize = pktsize - (endp - ptr);
ptr += endp - ptr;
} else {
dev->isoc_ctl.cmd = 0;
ptr += pktsize;
}
}
return 0;
}
static int copy_multiplexed(u8 *ptr, unsigned long len,
struct urb *urb)
{
struct tm6000_dmaqueue *dma_q = urb->context;
struct tm6000_core *dev = container_of(dma_q, struct tm6000_core, vidq);
unsigned int pos = dev->isoc_ctl.pos, cpysize;
int rc = 1;
struct tm6000_buffer *buf;
char *outp = NULL;
get_next_buf(dma_q, &buf);
if (buf)
outp = videobuf_to_vmalloc(&buf->vb);
if (!outp)
return 0;
while (len > 0) {
cpysize = min(len, buf->vb.size-pos);
memcpy(&outp[pos], ptr, cpysize);
pos += cpysize;
ptr += cpysize;
len -= cpysize;
if (pos >= buf->vb.size) {
pos = 0;
buffer_filled(dev, dma_q, buf);
dprintk(dev, V4L2_DEBUG_ISOC, "new buffer filled\n");
get_next_buf(dma_q, &buf);
if (!buf)
break;
outp = videobuf_to_vmalloc(&(buf->vb));
if (!outp)
return rc;
pos = 0;
}
}
dev->isoc_ctl.pos = pos;
return rc;
}
static inline void print_err_status(struct tm6000_core *dev,
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
dprintk(dev, V4L2_DEBUG_QUEUE, "URB status %d [%s].\n",
status, errmsg);
} else {
dprintk(dev, V4L2_DEBUG_QUEUE, "URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline int tm6000_isoc_copy(struct urb *urb)
{
struct tm6000_dmaqueue *dma_q = urb->context;
struct tm6000_core *dev = container_of(dma_q, struct tm6000_core, vidq);
int i, len = 0, rc = 1, status;
char *p;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
return 0;
}
for (i = 0; i < urb->number_of_packets; i++) {
status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
continue;
}
len = urb->iso_frame_desc[i].actual_length;
if (len > 0) {
p = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (!urb->iso_frame_desc[i].status) {
if ((dev->fourcc) == V4L2_PIX_FMT_TM6000) {
rc = copy_multiplexed(p, len, urb);
if (rc <= 0)
return rc;
} else {
copy_streams(p, len, urb);
}
}
}
}
return rc;
}
static void tm6000_irq_callback(struct urb *urb)
{
struct tm6000_dmaqueue *dma_q = urb->context;
struct tm6000_core *dev = container_of(dma_q, struct tm6000_core, vidq);
int i;
if (!dev)
return;
spin_lock(&dev->slock);
tm6000_isoc_copy(urb);
spin_unlock(&dev->slock);
for (i = 0; i < urb->number_of_packets; i++) {
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length = 0;
}
urb->status = usb_submit_urb(urb, GFP_ATOMIC);
if (urb->status)
tm6000_err("urb resubmit failed (error=%i)\n",
urb->status);
}
static void tm6000_uninit_isoc(struct tm6000_core *dev)
{
struct urb *urb;
int i;
dev->isoc_ctl.buf = NULL;
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
urb = dev->isoc_ctl.urb[i];
if (urb) {
usb_kill_urb(urb);
usb_unlink_urb(urb);
if (dev->isoc_ctl.transfer_buffer[i]) {
usb_free_coherent(dev->udev,
urb->transfer_buffer_length,
dev->isoc_ctl.transfer_buffer[i],
urb->transfer_dma);
}
usb_free_urb(urb);
dev->isoc_ctl.urb[i] = NULL;
}
dev->isoc_ctl.transfer_buffer[i] = NULL;
}
kfree(dev->isoc_ctl.urb);
kfree(dev->isoc_ctl.transfer_buffer);
dev->isoc_ctl.urb = NULL;
dev->isoc_ctl.transfer_buffer = NULL;
dev->isoc_ctl.num_bufs = 0;
}
static int tm6000_prepare_isoc(struct tm6000_core *dev)
{
struct tm6000_dmaqueue *dma_q = &dev->vidq;
int i, j, sb_size, pipe, size, max_packets, num_bufs = 8;
struct urb *urb;
tm6000_uninit_isoc(dev);
tm6000_ir_int_stop(dev);
usb_set_interface(dev->udev,
dev->isoc_in.bInterfaceNumber,
dev->isoc_in.bAlternateSetting);
tm6000_ir_int_start(dev);
pipe = usb_rcvisocpipe(dev->udev,
dev->isoc_in.endp->desc.bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK);
size = usb_maxpacket(dev->udev, pipe, usb_pipeout(pipe));
if (size > dev->isoc_in.maxsize)
size = dev->isoc_in.maxsize;
dev->isoc_ctl.max_pkt_size = size;
max_packets = TM6000_MAX_ISO_PACKETS;
sb_size = max_packets * size;
dev->isoc_ctl.num_bufs = num_bufs;
dev->isoc_ctl.urb = kmalloc(sizeof(void *)*num_bufs, GFP_KERNEL);
if (!dev->isoc_ctl.urb) {
tm6000_err("cannot alloc memory for usb buffers\n");
return -ENOMEM;
}
dev->isoc_ctl.transfer_buffer = kmalloc(sizeof(void *)*num_bufs,
GFP_KERNEL);
if (!dev->isoc_ctl.transfer_buffer) {
tm6000_err("cannot allocate memory for usbtransfer\n");
kfree(dev->isoc_ctl.urb);
return -ENOMEM;
}
dprintk(dev, V4L2_DEBUG_QUEUE, "Allocating %d x %d packets"
" (%d bytes) of %d bytes each to handle %u size\n",
max_packets, num_bufs, sb_size,
dev->isoc_in.maxsize, size);
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
urb = usb_alloc_urb(max_packets, GFP_KERNEL);
if (!urb) {
tm6000_err("cannot alloc isoc_ctl.urb %i\n", i);
tm6000_uninit_isoc(dev);
usb_free_urb(urb);
return -ENOMEM;
}
dev->isoc_ctl.urb[i] = urb;
dev->isoc_ctl.transfer_buffer[i] = usb_alloc_coherent(dev->udev,
sb_size, GFP_KERNEL, &urb->transfer_dma);
if (!dev->isoc_ctl.transfer_buffer[i]) {
tm6000_err("unable to allocate %i bytes for transfer"
" buffer %i%s\n",
sb_size, i,
in_interrupt() ? " while in int" : "");
tm6000_uninit_isoc(dev);
return -ENOMEM;
}
memset(dev->isoc_ctl.transfer_buffer[i], 0, sb_size);
usb_fill_bulk_urb(urb, dev->udev, pipe,
dev->isoc_ctl.transfer_buffer[i], sb_size,
tm6000_irq_callback, dma_q);
urb->interval = dev->isoc_in.endp->desc.bInterval;
urb->number_of_packets = max_packets;
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
for (j = 0; j < max_packets; j++) {
urb->iso_frame_desc[j].offset = size * j;
urb->iso_frame_desc[j].length = size;
}
}
return 0;
}
static int tm6000_start_thread(struct tm6000_core *dev)
{
struct tm6000_dmaqueue *dma_q = &dev->vidq;
int i;
dma_q->frame = 0;
dma_q->ini_jiffies = jiffies;
init_waitqueue_head(&dma_q->wq);
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
int rc = usb_submit_urb(dev->isoc_ctl.urb[i], GFP_ATOMIC);
if (rc) {
tm6000_err("submit of urb %i failed (error=%i)\n", i,
rc);
tm6000_uninit_isoc(dev);
return rc;
}
}
return 0;
}
static int
buffer_setup(struct videobuf_queue *vq, unsigned int *count, unsigned int *size)
{
struct tm6000_fh *fh = vq->priv_data;
*size = fh->fmt->depth * fh->width * fh->height >> 3;
if (0 == *count)
*count = TM6000_DEF_BUF;
if (*count < TM6000_MIN_BUF)
*count = TM6000_MIN_BUF;
while (*size * *count > vid_limit * 1024 * 1024)
(*count)--;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct tm6000_buffer *buf)
{
struct tm6000_fh *fh = vq->priv_data;
struct tm6000_core *dev = fh->dev;
unsigned long flags;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->slock, flags);
if (dev->isoc_ctl.buf == buf)
dev->isoc_ctl.buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct tm6000_fh *fh = vq->priv_data;
struct tm6000_buffer *buf = container_of(vb, struct tm6000_buffer, vb);
struct tm6000_core *dev = fh->dev;
int rc = 0, urb_init = 0;
BUG_ON(NULL == fh->fmt);
buf->vb.size = fh->fmt->depth*fh->width*fh->height >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
if (buf->fmt != fh->fmt ||
buf->vb.width != fh->width ||
buf->vb.height != fh->height ||
buf->vb.field != field) {
buf->fmt = fh->fmt;
buf->vb.width = fh->width;
buf->vb.height = fh->height;
buf->vb.field = field;
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
if (0 != (rc = videobuf_iolock(vq, &buf->vb, NULL)))
goto fail;
urb_init = 1;
}
if (!dev->isoc_ctl.num_bufs)
urb_init = 1;
if (urb_init) {
rc = tm6000_prepare_isoc(dev);
if (rc < 0)
goto fail;
rc = tm6000_start_thread(dev);
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
struct tm6000_buffer *buf = container_of(vb, struct tm6000_buffer, vb);
struct tm6000_fh *fh = vq->priv_data;
struct tm6000_core *dev = fh->dev;
struct tm6000_dmaqueue *vidq = &dev->vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void buffer_release(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct tm6000_buffer *buf = container_of(vb, struct tm6000_buffer, vb);
free_buffer(vq, buf);
}
static bool is_res_read(struct tm6000_core *dev, struct tm6000_fh *fh)
{
if (dev->resources == fh && dev->is_res_read)
return true;
return false;
}
static bool is_res_streaming(struct tm6000_core *dev, struct tm6000_fh *fh)
{
if (dev->resources == fh)
return true;
return false;
}
static bool res_get(struct tm6000_core *dev, struct tm6000_fh *fh,
bool is_res_read)
{
if (dev->resources == fh && dev->is_res_read == is_res_read)
return true;
if (dev->resources)
return false;
dev->resources = fh;
dev->is_res_read = is_res_read;
dprintk(dev, V4L2_DEBUG_RES_LOCK, "res: get\n");
return true;
}
static void res_free(struct tm6000_core *dev, struct tm6000_fh *fh)
{
if (dev->resources != fh)
return;
dev->resources = NULL;
dprintk(dev, V4L2_DEBUG_RES_LOCK, "res: put\n");
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct tm6000_core *dev = ((struct tm6000_fh *)priv)->dev;
strlcpy(cap->driver, "tm6000", sizeof(cap->driver));
strlcpy(cap->card, "Trident TVMaster TM5600/6000/6010", sizeof(cap->card));
cap->version = TM6000_VERSION;
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING |
V4L2_CAP_AUDIO |
V4L2_CAP_READWRITE;
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
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct tm6000_fh *fh = priv;
f->fmt.pix.width = fh->width;
f->fmt.pix.height = fh->height;
f->fmt.pix.field = fh->vb_vidq.field;
f->fmt.pix.pixelformat = fh->fmt->fourcc;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fh->fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
return 0;
}
static struct tm6000_fmt *format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(format); i++)
if (format[i].fourcc == fourcc)
return format+i;
return NULL;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct tm6000_core *dev = ((struct tm6000_fh *)priv)->dev;
struct tm6000_fmt *fmt;
enum v4l2_field field;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt) {
dprintk(dev, V4L2_DEBUG_IOCTL_ARG, "Fourcc format (0x%08x)"
" invalid.\n", f->fmt.pix.pixelformat);
return -EINVAL;
}
field = f->fmt.pix.field;
if (field == V4L2_FIELD_ANY)
field = V4L2_FIELD_SEQ_TB;
else if (V4L2_FIELD_INTERLACED != field) {
dprintk(dev, V4L2_DEBUG_IOCTL_ARG, "Field type invalid.\n");
return -EINVAL;
}
tm6000_get_std_res(dev);
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.width &= ~0x01;
f->fmt.pix.field = field;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
int ret = vidioc_try_fmt_vid_cap(file, fh, f);
if (ret < 0)
return ret;
fh->fmt = format_by_fourcc(f->fmt.pix.pixelformat);
fh->width = f->fmt.pix.width;
fh->height = f->fmt.pix.height;
fh->vb_vidq.field = f->fmt.pix.field;
fh->type = f->type;
dev->fourcc = f->fmt.pix.pixelformat;
tm6000_set_fourcc_format(dev);
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct tm6000_fh *fh = priv;
return videobuf_reqbufs(&fh->vb_vidq, p);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct tm6000_fh *fh = priv;
return videobuf_querybuf(&fh->vb_vidq, p);
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct tm6000_fh *fh = priv;
return videobuf_qbuf(&fh->vb_vidq, p);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct tm6000_fh *fh = priv;
return videobuf_dqbuf(&fh->vb_vidq, p,
file->f_flags & O_NONBLOCK);
}
static int vidioc_streamon(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (i != fh->type)
return -EINVAL;
if (!res_get(dev, fh, false))
return -EBUSY;
return (videobuf_streamon(&fh->vb_vidq));
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct tm6000_fh *fh=priv;
struct tm6000_core *dev = fh->dev;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (i != fh->type)
return -EINVAL;
videobuf_streamoff(&fh->vb_vidq);
res_free(dev,fh);
return (0);
}
static int vidioc_s_std (struct file *file, void *priv, v4l2_std_id *norm)
{
int rc=0;
struct tm6000_fh *fh=priv;
struct tm6000_core *dev = fh->dev;
dev->norm = *norm;
rc = tm6000_init_analog_mode(dev);
fh->width = dev->width;
fh->height = dev->height;
if (rc<0)
return rc;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std, dev->norm);
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
unsigned int n;
n = i->index;
if (n >= 3)
return -EINVAL;
if (!dev->vinput[n].type)
return -EINVAL;
i->index = n;
if (dev->vinput[n].type == TM6000_INPUT_TV)
i->type = V4L2_INPUT_TYPE_TUNER;
else
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name, iname[dev->vinput[n].type]);
i->std = TM6000_STD;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
*i = dev->input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
int rc = 0;
if (i >= 3)
return -EINVAL;
if (!dev->vinput[i].type)
return -EINVAL;
dev->input = i;
rc = vidioc_s_std(file, priv, &dev->vfd->current_norm);
return rc;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(tm6000_qctrl); i++)
if (qc->id && qc->id == tm6000_qctrl[i].id) {
memcpy(qc, &(tm6000_qctrl[i]),
sizeof(*qc));
return 0;
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
int val;
switch (ctrl->id) {
case V4L2_CID_CONTRAST:
val = tm6000_get_reg(dev, TM6010_REQ07_R08_LUMA_CONTRAST_ADJ, 0);
break;
case V4L2_CID_BRIGHTNESS:
val = tm6000_get_reg(dev, TM6010_REQ07_R09_LUMA_BRIGHTNESS_ADJ, 0);
return 0;
case V4L2_CID_SATURATION:
val = tm6000_get_reg(dev, TM6010_REQ07_R0A_CHROMA_SATURATION_ADJ, 0);
return 0;
case V4L2_CID_HUE:
val = tm6000_get_reg(dev, TM6010_REQ07_R0B_CHROMA_HUE_PHASE_ADJ, 0);
return 0;
case V4L2_CID_AUDIO_MUTE:
val = dev->ctl_mute;
return 0;
case V4L2_CID_AUDIO_VOLUME:
val = dev->ctl_volume;
return 0;
default:
return -EINVAL;
}
if (val < 0)
return val;
ctrl->value = val;
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
u8 val = ctrl->value;
switch (ctrl->id) {
case V4L2_CID_CONTRAST:
tm6000_set_reg(dev, TM6010_REQ07_R08_LUMA_CONTRAST_ADJ, val);
return 0;
case V4L2_CID_BRIGHTNESS:
tm6000_set_reg(dev, TM6010_REQ07_R09_LUMA_BRIGHTNESS_ADJ, val);
return 0;
case V4L2_CID_SATURATION:
tm6000_set_reg(dev, TM6010_REQ07_R0A_CHROMA_SATURATION_ADJ, val);
return 0;
case V4L2_CID_HUE:
tm6000_set_reg(dev, TM6010_REQ07_R0B_CHROMA_HUE_PHASE_ADJ, val);
return 0;
case V4L2_CID_AUDIO_MUTE:
dev->ctl_mute = val;
tm6000_tvaudio_set_mute(dev, val);
return 0;
case V4L2_CID_AUDIO_VOLUME:
dev->ctl_volume = val;
tm6000_set_volume(dev, val);
return 0;
}
return -EINVAL;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Television");
t->type = V4L2_TUNER_ANALOG_TV;
t->capability = V4L2_TUNER_CAP_NORM;
t->rangehigh = 0xffffffffUL;
t->rxsubchans = V4L2_TUNER_SUB_STEREO;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_tuner, t);
t->audmode = dev->amode;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (UNSET == dev->tuner_type)
return -EINVAL;
if (0 != t->index)
return -EINVAL;
dev->amode = t->audmode;
dprintk(dev, 3, "audio mode: %x\n", t->audmode);
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
f->type = fh->radio ? V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
f->frequency = dev->freq;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_frequency, f);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
if (0 == fh->radio && V4L2_TUNER_ANALOG_TV != f->type)
return -EINVAL;
if (1 == fh->radio && V4L2_TUNER_RADIO != f->type)
return -EINVAL;
dev->freq = f->frequency;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, f);
return 0;
}
static int radio_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct tm6000_fh *fh = file->private_data;
struct tm6000_core *dev = fh->dev;
strcpy(cap->driver, "tm6000");
strlcpy(cap->card, dev->name, sizeof(dev->name));
sprintf(cap->bus_info, "USB%04x:%04x",
le16_to_cpu(dev->udev->descriptor.idVendor),
le16_to_cpu(dev->udev->descriptor.idProduct));
cap->version = dev->dev_type;
cap->capabilities = V4L2_CAP_TUNER |
V4L2_CAP_AUDIO |
V4L2_CAP_RADIO |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
return 0;
}
static int radio_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct tm6000_fh *fh = file->private_data;
struct tm6000_core *dev = fh->dev;
if (0 != t->index)
return -EINVAL;
memset(t, 0, sizeof(*t));
strcpy(t->name, "Radio");
t->type = V4L2_TUNER_RADIO;
t->rxsubchans = V4L2_TUNER_SUB_STEREO;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int radio_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct tm6000_fh *fh = file->private_data;
struct tm6000_core *dev = fh->dev;
if (0 != t->index)
return -EINVAL;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_tuner, t);
return 0;
}
static int radio_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (i->index != 0)
return -EINVAL;
if (!dev->rinput.type)
return -EINVAL;
strcpy(i->name, "Radio");
i->type = V4L2_INPUT_TYPE_TUNER;
return 0;
}
static int radio_g_input(struct file *filp, void *priv, unsigned int *i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (dev->input !=5)
return -EINVAL;
*i = dev->input -5;
return 0;
}
static int radio_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
memset(a, 0, sizeof(*a));
strcpy(a->name, "Radio");
return 0;
}
static int radio_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
return 0;
}
static int radio_s_input(struct file *filp, void *priv, unsigned int i)
{
struct tm6000_fh *fh = priv;
struct tm6000_core *dev = fh->dev;
if (i)
return -EINVAL;
if (!dev->rinput.type)
return -EINVAL;
dev->input = i + 5;
return 0;
}
static int radio_s_std(struct file *file, void *fh, v4l2_std_id *norm)
{
return 0;
}
static int radio_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *c)
{
const struct v4l2_queryctrl *ctrl;
if (c->id < V4L2_CID_BASE ||
c->id >= V4L2_CID_LASTP1)
return -EINVAL;
if (c->id == V4L2_CID_AUDIO_MUTE) {
ctrl = ctrl_by_id(c->id);
*c = *ctrl;
} else
*c = no_ctrl;
return 0;
}
static int tm6000_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct tm6000_core *dev = video_drvdata(file);
struct tm6000_fh *fh;
enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
int i, rc;
int radio = 0;
printk(KERN_INFO "tm6000: open called (dev=%s)\n",
video_device_node_name(vdev));
dprintk(dev, V4L2_DEBUG_OPEN, "tm6000: open called (dev=%s)\n",
video_device_node_name(vdev));
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
case VFL_TYPE_RADIO:
radio = 1;
break;
}
dev->users++;
dprintk(dev, V4L2_DEBUG_OPEN, "open dev=%s type=%s users=%d\n",
video_device_node_name(vdev), v4l2_type_names[type],
dev->users);
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (NULL == fh) {
dev->users--;
return -ENOMEM;
}
file->private_data = fh;
fh->dev = dev;
fh->radio = radio;
dev->radio = radio;
fh->type = type;
dev->fourcc = format[0].fourcc;
fh->fmt = format_by_fourcc(dev->fourcc);
tm6000_get_std_res (dev);
fh->width = dev->width;
fh->height = dev->height;
dprintk(dev, V4L2_DEBUG_OPEN, "Open: fh=0x%08lx, dev=0x%08lx, "
"dev->vidq=0x%08lx\n",
(unsigned long)fh,(unsigned long)dev,(unsigned long)&dev->vidq);
dprintk(dev, V4L2_DEBUG_OPEN, "Open: list_empty "
"queued=%d\n",list_empty(&dev->vidq.queued));
dprintk(dev, V4L2_DEBUG_OPEN, "Open: list_empty "
"active=%d\n",list_empty(&dev->vidq.active));
rc = tm6000_init_analog_mode(dev);
if (rc < 0)
return rc;
if (dev->mode != TM6000_MODE_ANALOG) {
for (i = 0; i < ARRAY_SIZE(tm6000_qctrl); i++)
qctl_regs[i] = tm6000_qctrl[i].default_value;
dev->mode = TM6000_MODE_ANALOG;
}
videobuf_queue_vmalloc_init(&fh->vb_vidq, &tm6000_video_qops,
NULL, &dev->slock,
fh->type,
V4L2_FIELD_INTERLACED,
sizeof(struct tm6000_buffer), fh, &dev->lock);
if (fh->radio) {
dprintk(dev, V4L2_DEBUG_OPEN, "video_open: setting radio device\n");
dev->input = 5;
tm6000_set_audio_rinput(dev);
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_radio);
tm6000_prepare_isoc(dev);
tm6000_start_thread(dev);
}
return 0;
}
static ssize_t
tm6000_read(struct file *file, char __user *data, size_t count, loff_t *pos)
{
struct tm6000_fh *fh = file->private_data;
if (fh->type==V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (!res_get(fh->dev, fh, true))
return -EBUSY;
return videobuf_read_stream(&fh->vb_vidq, data, count, pos, 0,
file->f_flags & O_NONBLOCK);
}
return 0;
}
static unsigned int
tm6000_poll(struct file *file, struct poll_table_struct *wait)
{
struct tm6000_fh *fh = file->private_data;
struct tm6000_buffer *buf;
if (V4L2_BUF_TYPE_VIDEO_CAPTURE != fh->type)
return POLLERR;
if (!!is_res_streaming(fh->dev, fh))
return POLLERR;
if (!is_res_read(fh->dev, fh)) {
if (list_empty(&fh->vb_vidq.stream))
return POLLERR;
buf = list_entry(fh->vb_vidq.stream.next,struct tm6000_buffer,vb.stream);
} else {
return videobuf_poll_stream(file, &fh->vb_vidq,
wait);
}
poll_wait(file, &buf->vb.done, wait);
if (buf->vb.state == VIDEOBUF_DONE ||
buf->vb.state == VIDEOBUF_ERROR)
return POLLIN | POLLRDNORM;
return 0;
}
static int tm6000_release(struct file *file)
{
struct tm6000_fh *fh = file->private_data;
struct tm6000_core *dev = fh->dev;
struct video_device *vdev = video_devdata(file);
dprintk(dev, V4L2_DEBUG_OPEN, "tm6000: close called (dev=%s, users=%d)\n",
video_device_node_name(vdev), dev->users);
dev->users--;
res_free(dev, fh);
if (!dev->users) {
tm6000_uninit_isoc(dev);
videobuf_mmap_free(&fh->vb_vidq);
}
kfree(fh);
return 0;
}
static int tm6000_mmap(struct file *file, struct vm_area_struct * vma)
{
struct tm6000_fh *fh = file->private_data;
int ret;
ret = videobuf_mmap_mapper(&fh->vb_vidq, vma);
return ret;
}
static struct video_device *vdev_init(struct tm6000_core *dev,
const struct video_device
*template, const char *type_name)
{
struct video_device *vfd;
vfd = video_device_alloc();
if (NULL == vfd)
return NULL;
*vfd = *template;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->release = video_device_release;
vfd->debug = tm6000_debug;
vfd->lock = &dev->lock;
snprintf(vfd->name, sizeof(vfd->name), "%s %s", dev->name, type_name);
video_set_drvdata(vfd, dev);
return vfd;
}
int tm6000_v4l2_register(struct tm6000_core *dev)
{
int ret = -1;
dev->vfd = vdev_init(dev, &tm6000_template, "video");
if (!dev->vfd) {
printk(KERN_INFO "%s: can't register video device\n",
dev->name);
return -ENOMEM;
}
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vidq.queued);
ret = video_register_device(dev->vfd, VFL_TYPE_GRABBER, video_nr);
if (ret < 0) {
printk(KERN_INFO "%s: can't register video device\n",
dev->name);
return ret;
}
printk(KERN_INFO "%s: registered device %s\n",
dev->name, video_device_node_name(dev->vfd));
if (dev->caps.has_radio) {
dev->radio_dev = vdev_init(dev, &tm6000_radio_template,
"radio");
if (!dev->radio_dev) {
printk(KERN_INFO "%s: can't register radio device\n",
dev->name);
return ret;
}
ret = video_register_device(dev->radio_dev, VFL_TYPE_RADIO,
radio_nr);
if (ret < 0) {
printk(KERN_INFO "%s: can't register radio device\n",
dev->name);
return ret;
}
printk(KERN_INFO "%s: registered device %s\n",
dev->name, video_device_node_name(dev->radio_dev));
}
printk(KERN_INFO "Trident TVMaster TM5600/TM6000/TM6010 USB2 board (Load status: %d)\n", ret);
return ret;
}
int tm6000_v4l2_unregister(struct tm6000_core *dev)
{
video_unregister_device(dev->vfd);
if (dev->radio_dev) {
if (video_is_registered(dev->radio_dev))
video_unregister_device(dev->radio_dev);
else
video_device_release(dev->radio_dev);
dev->radio_dev = NULL;
}
return 0;
}
int tm6000_v4l2_exit(void)
{
return 0;
}
