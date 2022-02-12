static const struct vivi_fmt *__get_format(u32 pixelformat)
{
const struct vivi_fmt *fmt;
unsigned int k;
for (k = 0; k < ARRAY_SIZE(formats); k++) {
fmt = &formats[k];
if (fmt->fourcc == pixelformat)
break;
}
if (k == ARRAY_SIZE(formats))
return NULL;
return &formats[k];
}
static const struct vivi_fmt *get_format(struct v4l2_format *f)
{
return __get_format(f->fmt.pix.pixelformat);
}
static void precalculate_bars(struct vivi_dev *dev)
{
u8 r, g, b;
int k, is_yuv;
for (k = 0; k < 9; k++) {
r = bars[dev->input].bar[k][0];
g = bars[dev->input].bar[k][1];
b = bars[dev->input].bar[k][2];
is_yuv = dev->fmt->is_yuv;
switch (dev->fmt->fourcc) {
case V4L2_PIX_FMT_RGB565:
case V4L2_PIX_FMT_RGB565X:
r >>= 3;
g >>= 2;
b >>= 3;
break;
case V4L2_PIX_FMT_RGB555:
case V4L2_PIX_FMT_RGB555X:
r >>= 3;
g >>= 3;
b >>= 3;
break;
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YVYU:
case V4L2_PIX_FMT_VYUY:
case V4L2_PIX_FMT_RGB24:
case V4L2_PIX_FMT_BGR24:
case V4L2_PIX_FMT_RGB32:
case V4L2_PIX_FMT_BGR32:
break;
}
if (is_yuv) {
dev->bars[k][0] = TO_Y(r, g, b);
dev->bars[k][1] = TO_U(r, g, b);
dev->bars[k][2] = TO_V(r, g, b);
} else {
dev->bars[k][0] = r;
dev->bars[k][1] = g;
dev->bars[k][2] = b;
}
}
}
static void gen_twopix(struct vivi_dev *dev, u8 *buf, int colorpos, bool odd)
{
u8 r_y, g_u, b_v;
u8 alpha = dev->alpha_component;
int color;
u8 *p;
r_y = dev->bars[colorpos][0];
g_u = dev->bars[colorpos][1];
b_v = dev->bars[colorpos][2];
for (color = 0; color < dev->pixelsize; color++) {
p = buf + color;
switch (dev->fmt->fourcc) {
case V4L2_PIX_FMT_YUYV:
switch (color) {
case 0:
*p = r_y;
break;
case 1:
*p = odd ? b_v : g_u;
break;
}
break;
case V4L2_PIX_FMT_UYVY:
switch (color) {
case 0:
*p = odd ? b_v : g_u;
break;
case 1:
*p = r_y;
break;
}
break;
case V4L2_PIX_FMT_YVYU:
switch (color) {
case 0:
*p = r_y;
break;
case 1:
*p = odd ? g_u : b_v;
break;
}
break;
case V4L2_PIX_FMT_VYUY:
switch (color) {
case 0:
*p = odd ? g_u : b_v;
break;
case 1:
*p = r_y;
break;
}
break;
case V4L2_PIX_FMT_RGB565:
switch (color) {
case 0:
*p = (g_u << 5) | b_v;
break;
case 1:
*p = (r_y << 3) | (g_u >> 3);
break;
}
break;
case V4L2_PIX_FMT_RGB565X:
switch (color) {
case 0:
*p = (r_y << 3) | (g_u >> 3);
break;
case 1:
*p = (g_u << 5) | b_v;
break;
}
break;
case V4L2_PIX_FMT_RGB555:
switch (color) {
case 0:
*p = (g_u << 5) | b_v;
break;
case 1:
*p = (alpha & 0x80) | (r_y << 2) | (g_u >> 3);
break;
}
break;
case V4L2_PIX_FMT_RGB555X:
switch (color) {
case 0:
*p = (alpha & 0x80) | (r_y << 2) | (g_u >> 3);
break;
case 1:
*p = (g_u << 5) | b_v;
break;
}
break;
case V4L2_PIX_FMT_RGB24:
switch (color) {
case 0:
*p = r_y;
break;
case 1:
*p = g_u;
break;
case 2:
*p = b_v;
break;
}
break;
case V4L2_PIX_FMT_BGR24:
switch (color) {
case 0:
*p = b_v;
break;
case 1:
*p = g_u;
break;
case 2:
*p = r_y;
break;
}
break;
case V4L2_PIX_FMT_RGB32:
switch (color) {
case 0:
*p = alpha;
break;
case 1:
*p = r_y;
break;
case 2:
*p = g_u;
break;
case 3:
*p = b_v;
break;
}
break;
case V4L2_PIX_FMT_BGR32:
switch (color) {
case 0:
*p = b_v;
break;
case 1:
*p = g_u;
break;
case 2:
*p = r_y;
break;
case 3:
*p = alpha;
break;
}
break;
}
}
}
static void precalculate_line(struct vivi_dev *dev)
{
unsigned pixsize = dev->pixelsize;
unsigned pixsize2 = 2*pixsize;
int colorpos;
u8 *pos;
for (colorpos = 0; colorpos < 16; ++colorpos) {
u8 pix[8];
int wstart = colorpos * dev->width / 8;
int wend = (colorpos+1) * dev->width / 8;
int w;
gen_twopix(dev, &pix[0], colorpos % 8, 0);
gen_twopix(dev, &pix[pixsize], colorpos % 8, 1);
for (w = wstart/2*2, pos = dev->line + w*pixsize; w < wend; w += 2, pos += pixsize2)
memcpy(pos, pix, pixsize2);
}
}
static void gen_text(struct vivi_dev *dev, char *basep,
int y, int x, char *text)
{
int line;
unsigned int width = dev->width;
if (y + 16 >= dev->height || x + strlen(text) * 8 >= width)
return;
#define PRINTSTR(PIXTYPE) do { \
PIXTYPE fg; \
PIXTYPE bg; \
memcpy(&fg, &dev->textfg, sizeof(PIXTYPE)); \
memcpy(&bg, &dev->textbg, sizeof(PIXTYPE)); \
\
for (line = 0; line < 16; line++) { \
PIXTYPE *pos = (PIXTYPE *)( basep + ((y + line) * width + x) * sizeof(PIXTYPE) ); \
u8 *s; \
\
for (s = text; *s; s++) { \
u8 chr = font8x16[*s * 16 + line]; \
\
pos[0] = (chr & (0x01 << 7) ? fg : bg); \
pos[1] = (chr & (0x01 << 6) ? fg : bg); \
pos[2] = (chr & (0x01 << 5) ? fg : bg); \
pos[3] = (chr & (0x01 << 4) ? fg : bg); \
pos[4] = (chr & (0x01 << 3) ? fg : bg); \
pos[5] = (chr & (0x01 << 2) ? fg : bg); \
pos[6] = (chr & (0x01 << 1) ? fg : bg); \
pos[7] = (chr & (0x01 << 0) ? fg : bg); \
\
pos += 8; \
} \
} \
} while (0)
switch (dev->pixelsize) {
case 2:
PRINTSTR(u16); break;
case 4:
PRINTSTR(u32); break;
case 3:
PRINTSTR(x24); break;
}
}
static void vivi_fillbuff(struct vivi_dev *dev, struct vivi_buffer *buf)
{
int stride = dev->width * dev->pixelsize;
int hmax = dev->height;
void *vbuf = vb2_plane_vaddr(&buf->vb, 0);
unsigned ms;
char str[100];
int h, line = 1;
u8 *linestart;
s32 gain;
if (!vbuf)
return;
linestart = dev->line + (dev->mv_count % dev->width) * dev->pixelsize;
for (h = 0; h < hmax; h++)
memcpy(vbuf + h * stride, linestart, stride);
gen_twopix(dev, (u8 *)&dev->textbg, TEXT_BLACK, 0);
gen_twopix(dev, (u8 *)&dev->textfg, WHITE, 0);
dev->ms += jiffies_to_msecs(jiffies - dev->jiffies);
dev->jiffies = jiffies;
ms = dev->ms;
snprintf(str, sizeof(str), " %02d:%02d:%02d:%03d ",
(ms / (60 * 60 * 1000)) % 24,
(ms / (60 * 1000)) % 60,
(ms / 1000) % 60,
ms % 1000);
gen_text(dev, vbuf, line++ * 16, 16, str);
snprintf(str, sizeof(str), " %dx%d, input %d ",
dev->width, dev->height, dev->input);
gen_text(dev, vbuf, line++ * 16, 16, str);
gain = v4l2_ctrl_g_ctrl(dev->gain);
mutex_lock(dev->ctrl_handler.lock);
snprintf(str, sizeof(str), " brightness %3d, contrast %3d, saturation %3d, hue %d ",
dev->brightness->cur.val,
dev->contrast->cur.val,
dev->saturation->cur.val,
dev->hue->cur.val);
gen_text(dev, vbuf, line++ * 16, 16, str);
snprintf(str, sizeof(str), " autogain %d, gain %3d, volume %3d, alpha 0x%02x ",
dev->autogain->cur.val, gain, dev->volume->cur.val,
dev->alpha->cur.val);
gen_text(dev, vbuf, line++ * 16, 16, str);
snprintf(str, sizeof(str), " int32 %d, int64 %lld, bitmask %08x ",
dev->int32->cur.val,
dev->int64->cur.val64,
dev->bitmask->cur.val);
gen_text(dev, vbuf, line++ * 16, 16, str);
snprintf(str, sizeof(str), " boolean %d, menu %s, string \"%s\" ",
dev->boolean->cur.val,
dev->menu->qmenu[dev->menu->cur.val],
dev->string->cur.string);
gen_text(dev, vbuf, line++ * 16, 16, str);
snprintf(str, sizeof(str), " integer_menu %lld, value %d ",
dev->int_menu->qmenu_int[dev->int_menu->cur.val],
dev->int_menu->cur.val);
gen_text(dev, vbuf, line++ * 16, 16, str);
mutex_unlock(dev->ctrl_handler.lock);
if (dev->button_pressed) {
dev->button_pressed--;
snprintf(str, sizeof(str), " button pressed!");
gen_text(dev, vbuf, line++ * 16, 16, str);
}
dev->mv_count += 2;
buf->vb.v4l2_buf.field = V4L2_FIELD_INTERLACED;
buf->vb.v4l2_buf.sequence = dev->seq_count++;
v4l2_get_timestamp(&buf->vb.v4l2_buf.timestamp);
}
static void vivi_thread_tick(struct vivi_dev *dev)
{
struct vivi_dmaqueue *dma_q = &dev->vidq;
struct vivi_buffer *buf;
unsigned long flags = 0;
dprintk(dev, 1, "Thread tick\n");
spin_lock_irqsave(&dev->slock, flags);
if (list_empty(&dma_q->active)) {
dprintk(dev, 1, "No active queue to serve\n");
spin_unlock_irqrestore(&dev->slock, flags);
return;
}
buf = list_entry(dma_q->active.next, struct vivi_buffer, list);
list_del(&buf->list);
spin_unlock_irqrestore(&dev->slock, flags);
v4l2_get_timestamp(&buf->vb.v4l2_buf.timestamp);
vivi_fillbuff(dev, buf);
dprintk(dev, 1, "filled buffer %p\n", buf);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_DONE);
dprintk(dev, 2, "[%p/%d] done\n", buf, buf->vb.v4l2_buf.index);
}
static void vivi_sleep(struct vivi_dev *dev)
{
struct vivi_dmaqueue *dma_q = &dev->vidq;
int timeout;
DECLARE_WAITQUEUE(wait, current);
dprintk(dev, 1, "%s dma_q=0x%08lx\n", __func__,
(unsigned long)dma_q);
add_wait_queue(&dma_q->wq, &wait);
if (kthread_should_stop())
goto stop_task;
timeout = msecs_to_jiffies(frames_to_ms(dev, 1));
vivi_thread_tick(dev);
schedule_timeout_interruptible(timeout);
stop_task:
remove_wait_queue(&dma_q->wq, &wait);
try_to_freeze();
}
static int vivi_thread(void *data)
{
struct vivi_dev *dev = data;
dprintk(dev, 1, "thread started\n");
set_freezable();
for (;;) {
vivi_sleep(dev);
if (kthread_should_stop())
break;
}
dprintk(dev, 1, "thread: exit\n");
return 0;
}
static int vivi_start_generating(struct vivi_dev *dev)
{
struct vivi_dmaqueue *dma_q = &dev->vidq;
dprintk(dev, 1, "%s\n", __func__);
dev->ms = 0;
dev->mv_count = 0;
dev->jiffies = jiffies;
dma_q->frame = 0;
dma_q->ini_jiffies = jiffies;
dma_q->kthread = kthread_run(vivi_thread, dev, "%s",
dev->v4l2_dev.name);
if (IS_ERR(dma_q->kthread)) {
v4l2_err(&dev->v4l2_dev, "kernel_thread() failed\n");
return PTR_ERR(dma_q->kthread);
}
wake_up_interruptible(&dma_q->wq);
dprintk(dev, 1, "returning from %s\n", __func__);
return 0;
}
static void vivi_stop_generating(struct vivi_dev *dev)
{
struct vivi_dmaqueue *dma_q = &dev->vidq;
dprintk(dev, 1, "%s\n", __func__);
if (dma_q->kthread) {
kthread_stop(dma_q->kthread);
dma_q->kthread = NULL;
}
while (!list_empty(&dma_q->active)) {
struct vivi_buffer *buf;
buf = list_entry(dma_q->active.next, struct vivi_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
dprintk(dev, 2, "[%p/%d] done\n", buf, buf->vb.v4l2_buf.index);
}
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct vivi_dev *dev = vb2_get_drv_priv(vq);
unsigned long size;
size = dev->width * dev->height * dev->pixelsize;
if (fmt) {
if (fmt->fmt.pix.sizeimage < size)
return -EINVAL;
size = fmt->fmt.pix.sizeimage;
if (size > 7680 * 4320 * dev->pixelsize)
return -EINVAL;
}
*nplanes = 1;
sizes[0] = size;
dprintk(dev, 1, "%s, count=%d, size=%ld\n", __func__,
*nbuffers, size);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vivi_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
struct vivi_buffer *buf = container_of(vb, struct vivi_buffer, vb);
unsigned long size;
dprintk(dev, 1, "%s, field=%d\n", __func__, vb->v4l2_buf.field);
BUG_ON(NULL == dev->fmt);
if (dev->width < 48 || dev->width > MAX_WIDTH ||
dev->height < 32 || dev->height > MAX_HEIGHT)
return -EINVAL;
size = dev->width * dev->height * dev->pixelsize;
if (vb2_plane_size(vb, 0) < size) {
dprintk(dev, 1, "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(&buf->vb, 0, size);
precalculate_bars(dev);
precalculate_line(dev);
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vivi_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
struct vivi_buffer *buf = container_of(vb, struct vivi_buffer, vb);
struct vivi_dmaqueue *vidq = &dev->vidq;
unsigned long flags = 0;
dprintk(dev, 1, "%s\n", __func__);
spin_lock_irqsave(&dev->slock, flags);
list_add_tail(&buf->list, &vidq->active);
spin_unlock_irqrestore(&dev->slock, flags);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vivi_dev *dev = vb2_get_drv_priv(vq);
int err;
dprintk(dev, 1, "%s\n", __func__);
dev->seq_count = 0;
err = vivi_start_generating(dev);
if (err) {
struct vivi_buffer *buf, *tmp;
list_for_each_entry_safe(buf, tmp, &dev->vidq.active, list) {
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_QUEUED);
}
}
return err;
}
static void stop_streaming(struct vb2_queue *vq)
{
struct vivi_dev *dev = vb2_get_drv_priv(vq);
dprintk(dev, 1, "%s\n", __func__);
vivi_stop_generating(dev);
}
static void vivi_lock(struct vb2_queue *vq)
{
struct vivi_dev *dev = vb2_get_drv_priv(vq);
mutex_lock(&dev->mutex);
}
static void vivi_unlock(struct vb2_queue *vq)
{
struct vivi_dev *dev = vb2_get_drv_priv(vq);
mutex_unlock(&dev->mutex);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vivi_dev *dev = video_drvdata(file);
strcpy(cap->driver, "vivi");
strcpy(cap->card, "vivi");
snprintf(cap->bus_info, sizeof(cap->bus_info),
"platform:%s", dev->v4l2_dev.name);
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
const struct vivi_fmt *fmt;
if (f->index >= ARRAY_SIZE(formats))
return -EINVAL;
fmt = &formats[f->index];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vivi_dev *dev = video_drvdata(file);
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
f->fmt.pix.pixelformat = dev->fmt->fourcc;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * dev->fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
if (dev->fmt->is_yuv)
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
else
f->fmt.pix.colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vivi_dev *dev = video_drvdata(file);
const struct vivi_fmt *fmt;
fmt = get_format(f);
if (!fmt) {
dprintk(dev, 1, "Fourcc format (0x%08x) unknown.\n",
f->fmt.pix.pixelformat);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
fmt = get_format(f);
}
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
v4l_bound_align_image(&f->fmt.pix.width, 48, MAX_WIDTH, 2,
&f->fmt.pix.height, 32, MAX_HEIGHT, 0, 0);
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
if (fmt->is_yuv)
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
else
f->fmt.pix.colorspace = V4L2_COLORSPACE_SRGB;
f->fmt.pix.priv = 0;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vivi_dev *dev = video_drvdata(file);
struct vb2_queue *q = &dev->vb_vidq;
int ret = vidioc_try_fmt_vid_cap(file, priv, f);
if (ret < 0)
return ret;
if (vb2_is_busy(q)) {
dprintk(dev, 1, "%s device busy\n", __func__);
return -EBUSY;
}
dev->fmt = get_format(f);
dev->pixelsize = dev->fmt->depth / 8;
dev->width = f->fmt.pix.width;
dev->height = f->fmt.pix.height;
return 0;
}
static int vidioc_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
static const struct v4l2_frmsize_stepwise sizes = {
48, MAX_WIDTH, 4,
32, MAX_HEIGHT, 1
};
int i;
if (fsize->index)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fsize->pixel_format)
break;
if (i == ARRAY_SIZE(formats))
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_STEPWISE;
fsize->stepwise = sizes;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
if (inp->index >= NUM_INPUTS)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
sprintf(inp->name, "Camera %u", inp->index);
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct vivi_dev *dev = video_drvdata(file);
*i = dev->input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct vivi_dev *dev = video_drvdata(file);
if (i >= NUM_INPUTS)
return -EINVAL;
if (i == dev->input)
return 0;
dev->input = i;
v4l2_ctrl_modify_range(dev->brightness,
128 * i, 255 + 128 * i, 1, 127 + 128 * i);
precalculate_bars(dev);
precalculate_line(dev);
return 0;
}
static int vidioc_enum_frameintervals(struct file *file, void *priv,
struct v4l2_frmivalenum *fival)
{
const struct vivi_fmt *fmt;
if (fival->index)
return -EINVAL;
fmt = __get_format(fival->pixel_format);
if (!fmt)
return -EINVAL;
if (fival->width < 48 || fival->width > MAX_WIDTH || (fival->width & 3))
return -EINVAL;
if (fival->height < 32 || fival->height > MAX_HEIGHT)
return -EINVAL;
fival->type = V4L2_FRMIVAL_TYPE_CONTINUOUS;
fival->stepwise.min = tpf_min;
fival->stepwise.max = tpf_max;
fival->stepwise.step = (struct v4l2_fract) {1, 1};
return 0;
}
static int vidioc_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *parm)
{
struct vivi_dev *dev = video_drvdata(file);
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
parm->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
parm->parm.capture.timeperframe = dev->timeperframe;
parm->parm.capture.readbuffers = 1;
return 0;
}
static int vidioc_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *parm)
{
struct vivi_dev *dev = video_drvdata(file);
struct v4l2_fract tpf;
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
tpf = parm->parm.capture.timeperframe;
tpf = tpf.denominator ? tpf : tpf_default;
tpf = FRACT_CMP(tpf, <, tpf_min) ? tpf_min : tpf;
tpf = FRACT_CMP(tpf, >, tpf_max) ? tpf_max : tpf;
dev->timeperframe = tpf;
parm->parm.capture.timeperframe = tpf;
parm->parm.capture.readbuffers = 1;
return 0;
}
static int vivi_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivi_dev *dev = container_of(ctrl->handler, struct vivi_dev, ctrl_handler);
if (ctrl == dev->autogain)
dev->gain->val = jiffies & 0xff;
return 0;
}
static int vivi_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivi_dev *dev = container_of(ctrl->handler, struct vivi_dev, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_ALPHA_COMPONENT:
dev->alpha_component = ctrl->val;
break;
default:
if (ctrl == dev->button)
dev->button_pressed = 30;
break;
}
return 0;
}
static int vivi_release(void)
{
struct vivi_dev *dev;
struct list_head *list;
while (!list_empty(&vivi_devlist)) {
list = vivi_devlist.next;
list_del(list);
dev = list_entry(list, struct vivi_dev, vivi_devlist);
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vdev));
video_unregister_device(&dev->vdev);
v4l2_device_unregister(&dev->v4l2_dev);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
kfree(dev);
}
return 0;
}
static int __init vivi_create_instance(int inst)
{
struct vivi_dev *dev;
struct video_device *vfd;
struct v4l2_ctrl_handler *hdl;
struct vb2_queue *q;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
snprintf(dev->v4l2_dev.name, sizeof(dev->v4l2_dev.name),
"%s-%03d", VIVI_MODULE_NAME, inst);
ret = v4l2_device_register(NULL, &dev->v4l2_dev);
if (ret)
goto free_dev;
dev->fmt = &formats[0];
dev->timeperframe = tpf_default;
dev->width = 640;
dev->height = 480;
dev->pixelsize = dev->fmt->depth / 8;
hdl = &dev->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 11);
dev->volume = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 255, 1, 200);
dev->brightness = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 127);
dev->contrast = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 16);
dev->saturation = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 127);
dev->hue = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
dev->autogain = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
dev->gain = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 100);
dev->alpha = v4l2_ctrl_new_std(hdl, &vivi_ctrl_ops,
V4L2_CID_ALPHA_COMPONENT, 0, 255, 1, 0);
dev->button = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_button, NULL);
dev->int32 = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_int32, NULL);
dev->int64 = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_int64, NULL);
dev->boolean = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_boolean, NULL);
dev->menu = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_menu, NULL);
dev->string = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_string, NULL);
dev->bitmask = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_bitmask, NULL);
dev->int_menu = v4l2_ctrl_new_custom(hdl, &vivi_ctrl_int_menu, NULL);
if (hdl->error) {
ret = hdl->error;
goto unreg_dev;
}
v4l2_ctrl_auto_cluster(2, &dev->autogain, 0, true);
dev->v4l2_dev.ctrl_handler = hdl;
spin_lock_init(&dev->slock);
q = &dev->vb_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivi_buffer);
q->ops = &vivi_video_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
mutex_init(&dev->mutex);
INIT_LIST_HEAD(&dev->vidq.active);
init_waitqueue_head(&dev->vidq.wq);
vfd = &dev->vdev;
*vfd = vivi_template;
vfd->debug = debug;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = q;
set_bit(V4L2_FL_USE_FH_PRIO, &vfd->flags);
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_GRABBER, video_nr);
if (ret < 0)
goto unreg_dev;
list_add_tail(&dev->vivi_devlist, &vivi_devlist);
v4l2_info(&dev->v4l2_dev, "V4L2 device registered as %s\n",
video_device_node_name(vfd));
return 0;
unreg_dev:
v4l2_ctrl_handler_free(hdl);
v4l2_device_unregister(&dev->v4l2_dev);
free_dev:
kfree(dev);
return ret;
}
static int __init vivi_init(void)
{
const struct font_desc *font = find_font("VGA8x16");
int ret = 0, i;
if (font == NULL) {
printk(KERN_ERR "vivi: could not find font\n");
return -ENODEV;
}
font8x16 = font->data;
if (n_devs <= 0)
n_devs = 1;
for (i = 0; i < n_devs; i++) {
ret = vivi_create_instance(i);
if (ret) {
if (i)
ret = 0;
break;
}
}
if (ret < 0) {
printk(KERN_ERR "vivi: error %d while loading driver\n", ret);
return ret;
}
printk(KERN_INFO "Video Technology Magazine Virtual Video "
"Capture Board ver %s successfully loaded.\n",
VIVI_VERSION);
n_devs = i;
return ret;
}
static void __exit vivi_exit(void)
{
vivi_release();
}
