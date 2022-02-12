static void vim2m_dev_release(struct device *dev)
{}
static struct vim2m_fmt *find_format(struct v4l2_format *f)
{
struct vim2m_fmt *fmt;
unsigned int k;
for (k = 0; k < NUM_FORMATS; k++) {
fmt = &formats[k];
if (fmt->fourcc == f->fmt.pix.pixelformat)
break;
}
if (k == NUM_FORMATS)
return NULL;
return &formats[k];
}
static inline struct vim2m_ctx *file2ctx(struct file *file)
{
return container_of(file->private_data, struct vim2m_ctx, fh);
}
static struct vim2m_q_data *get_q_data(struct vim2m_ctx *ctx,
enum v4l2_buf_type type)
{
switch (type) {
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
return &ctx->q_data[V4L2_M2M_SRC];
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return &ctx->q_data[V4L2_M2M_DST];
default:
BUG();
}
return NULL;
}
static int device_process(struct vim2m_ctx *ctx,
struct vb2_buffer *in_vb,
struct vb2_buffer *out_vb)
{
struct vim2m_dev *dev = ctx->dev;
struct vim2m_q_data *q_data;
u8 *p_in, *p_out;
int x, y, t, w;
int tile_w, bytes_left;
int width, height, bytesperline;
q_data = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
width = q_data->width;
height = q_data->height;
bytesperline = (q_data->width * q_data->fmt->depth) >> 3;
p_in = vb2_plane_vaddr(in_vb, 0);
p_out = vb2_plane_vaddr(out_vb, 0);
if (!p_in || !p_out) {
v4l2_err(&dev->v4l2_dev,
"Acquiring kernel pointers to buffers failed\n");
return -EFAULT;
}
if (vb2_plane_size(in_vb, 0) > vb2_plane_size(out_vb, 0)) {
v4l2_err(&dev->v4l2_dev, "Output buffer is too small\n");
return -EINVAL;
}
tile_w = (width * (q_data[V4L2_M2M_DST].fmt->depth >> 3))
/ MEM2MEM_NUM_TILES;
bytes_left = bytesperline - tile_w * MEM2MEM_NUM_TILES;
w = 0;
out_vb->v4l2_buf.sequence = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE)->sequence++;
in_vb->v4l2_buf.sequence = q_data->sequence++;
memcpy(&out_vb->v4l2_buf.timestamp,
&in_vb->v4l2_buf.timestamp,
sizeof(struct timeval));
if (in_vb->v4l2_buf.flags & V4L2_BUF_FLAG_TIMECODE)
memcpy(&out_vb->v4l2_buf.timecode, &in_vb->v4l2_buf.timecode,
sizeof(struct v4l2_timecode));
out_vb->v4l2_buf.field = in_vb->v4l2_buf.field;
out_vb->v4l2_buf.flags = in_vb->v4l2_buf.flags &
(V4L2_BUF_FLAG_TIMECODE |
V4L2_BUF_FLAG_KEYFRAME |
V4L2_BUF_FLAG_PFRAME |
V4L2_BUF_FLAG_BFRAME |
V4L2_BUF_FLAG_TSTAMP_SRC_MASK);
switch (ctx->mode) {
case MEM2MEM_HFLIP | MEM2MEM_VFLIP:
p_out += bytesperline * height - bytes_left;
for (y = 0; y < height; ++y) {
for (t = 0; t < MEM2MEM_NUM_TILES; ++t) {
if (w & 0x1) {
for (x = 0; x < tile_w; ++x)
*--p_out = *p_in++ +
MEM2MEM_COLOR_STEP;
} else {
for (x = 0; x < tile_w; ++x)
*--p_out = *p_in++ -
MEM2MEM_COLOR_STEP;
}
++w;
}
p_in += bytes_left;
p_out -= bytes_left;
}
break;
case MEM2MEM_HFLIP:
for (y = 0; y < height; ++y) {
p_out += MEM2MEM_NUM_TILES * tile_w;
for (t = 0; t < MEM2MEM_NUM_TILES; ++t) {
if (w & 0x01) {
for (x = 0; x < tile_w; ++x)
*--p_out = *p_in++ +
MEM2MEM_COLOR_STEP;
} else {
for (x = 0; x < tile_w; ++x)
*--p_out = *p_in++ -
MEM2MEM_COLOR_STEP;
}
++w;
}
p_in += bytes_left;
p_out += bytesperline;
}
break;
case MEM2MEM_VFLIP:
p_out += bytesperline * (height - 1);
for (y = 0; y < height; ++y) {
for (t = 0; t < MEM2MEM_NUM_TILES; ++t) {
if (w & 0x1) {
for (x = 0; x < tile_w; ++x)
*p_out++ = *p_in++ +
MEM2MEM_COLOR_STEP;
} else {
for (x = 0; x < tile_w; ++x)
*p_out++ = *p_in++ -
MEM2MEM_COLOR_STEP;
}
++w;
}
p_in += bytes_left;
p_out += bytes_left - 2 * bytesperline;
}
break;
default:
for (y = 0; y < height; ++y) {
for (t = 0; t < MEM2MEM_NUM_TILES; ++t) {
if (w & 0x1) {
for (x = 0; x < tile_w; ++x)
*p_out++ = *p_in++ +
MEM2MEM_COLOR_STEP;
} else {
for (x = 0; x < tile_w; ++x)
*p_out++ = *p_in++ -
MEM2MEM_COLOR_STEP;
}
++w;
}
p_in += bytes_left;
p_out += bytes_left;
}
}
return 0;
}
static void schedule_irq(struct vim2m_dev *dev, int msec_timeout)
{
dprintk(dev, "Scheduling a simulated irq\n");
mod_timer(&dev->timer, jiffies + msecs_to_jiffies(msec_timeout));
}
static int job_ready(void *priv)
{
struct vim2m_ctx *ctx = priv;
if (v4l2_m2m_num_src_bufs_ready(ctx->fh.m2m_ctx) < ctx->translen
|| v4l2_m2m_num_dst_bufs_ready(ctx->fh.m2m_ctx) < ctx->translen) {
dprintk(ctx->dev, "Not enough buffers available\n");
return 0;
}
return 1;
}
static void job_abort(void *priv)
{
struct vim2m_ctx *ctx = priv;
ctx->aborting = 1;
}
static void device_run(void *priv)
{
struct vim2m_ctx *ctx = priv;
struct vim2m_dev *dev = ctx->dev;
struct vb2_buffer *src_buf, *dst_buf;
src_buf = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
device_process(ctx, src_buf, dst_buf);
schedule_irq(dev, ctx->transtime);
}
static void device_isr(unsigned long priv)
{
struct vim2m_dev *vim2m_dev = (struct vim2m_dev *)priv;
struct vim2m_ctx *curr_ctx;
struct vb2_buffer *src_vb, *dst_vb;
unsigned long flags;
curr_ctx = v4l2_m2m_get_curr_priv(vim2m_dev->m2m_dev);
if (NULL == curr_ctx) {
pr_err("Instance released before the end of transaction\n");
return;
}
src_vb = v4l2_m2m_src_buf_remove(curr_ctx->fh.m2m_ctx);
dst_vb = v4l2_m2m_dst_buf_remove(curr_ctx->fh.m2m_ctx);
curr_ctx->num_processed++;
spin_lock_irqsave(&vim2m_dev->irqlock, flags);
v4l2_m2m_buf_done(src_vb, VB2_BUF_STATE_DONE);
v4l2_m2m_buf_done(dst_vb, VB2_BUF_STATE_DONE);
spin_unlock_irqrestore(&vim2m_dev->irqlock, flags);
if (curr_ctx->num_processed == curr_ctx->translen
|| curr_ctx->aborting) {
dprintk(curr_ctx->dev, "Finishing transaction\n");
curr_ctx->num_processed = 0;
v4l2_m2m_job_finish(vim2m_dev->m2m_dev, curr_ctx->fh.m2m_ctx);
} else {
device_run(curr_ctx);
}
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strncpy(cap->driver, MEM2MEM_NAME, sizeof(cap->driver) - 1);
strncpy(cap->card, MEM2MEM_NAME, sizeof(cap->card) - 1);
snprintf(cap->bus_info, sizeof(cap->bus_info),
"platform:%s", MEM2MEM_NAME);
cap->device_caps = V4L2_CAP_VIDEO_M2M | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int enum_fmt(struct v4l2_fmtdesc *f, u32 type)
{
int i, num;
struct vim2m_fmt *fmt;
num = 0;
for (i = 0; i < NUM_FORMATS; ++i) {
if (formats[i].types & type) {
if (num == f->index)
break;
++num;
}
}
if (i < NUM_FORMATS) {
fmt = &formats[i];
strncpy(f->description, fmt->name, sizeof(f->description) - 1);
f->pixelformat = fmt->fourcc;
return 0;
}
return -EINVAL;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(f, MEM2MEM_CAPTURE);
}
static int vidioc_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(f, MEM2MEM_OUTPUT);
}
static int vidioc_g_fmt(struct vim2m_ctx *ctx, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct vim2m_q_data *q_data;
vq = v4l2_m2m_get_vq(ctx->fh.m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
f->fmt.pix.width = q_data->width;
f->fmt.pix.height = q_data->height;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.pixelformat = q_data->fmt->fourcc;
f->fmt.pix.bytesperline = (q_data->width * q_data->fmt->depth) >> 3;
f->fmt.pix.sizeimage = q_data->sizeimage;
f->fmt.pix.colorspace = ctx->colorspace;
return 0;
}
static int vidioc_g_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
return vidioc_g_fmt(file2ctx(file), f);
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
return vidioc_g_fmt(file2ctx(file), f);
}
static int vidioc_try_fmt(struct v4l2_format *f, struct vim2m_fmt *fmt)
{
if (f->fmt.pix.height < MIN_H)
f->fmt.pix.height = MIN_H;
else if (f->fmt.pix.height > MAX_H)
f->fmt.pix.height = MAX_H;
if (f->fmt.pix.width < MIN_W)
f->fmt.pix.width = MIN_W;
else if (f->fmt.pix.width > MAX_W)
f->fmt.pix.width = MAX_W;
f->fmt.pix.width &= ~DIM_ALIGN_MASK;
f->fmt.pix.bytesperline = (f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.field = V4L2_FIELD_NONE;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vim2m_fmt *fmt;
struct vim2m_ctx *ctx = file2ctx(file);
fmt = find_format(f);
if (!fmt) {
f->fmt.pix.pixelformat = formats[0].fourcc;
fmt = find_format(f);
}
if (!(fmt->types & MEM2MEM_CAPTURE)) {
v4l2_err(&ctx->dev->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
f->fmt.pix.colorspace = ctx->colorspace;
return vidioc_try_fmt(f, fmt);
}
static int vidioc_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vim2m_fmt *fmt;
struct vim2m_ctx *ctx = file2ctx(file);
fmt = find_format(f);
if (!fmt) {
f->fmt.pix.pixelformat = formats[0].fourcc;
fmt = find_format(f);
}
if (!(fmt->types & MEM2MEM_OUTPUT)) {
v4l2_err(&ctx->dev->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
if (!f->fmt.pix.colorspace)
f->fmt.pix.colorspace = V4L2_COLORSPACE_REC709;
return vidioc_try_fmt(f, fmt);
}
static int vidioc_s_fmt(struct vim2m_ctx *ctx, struct v4l2_format *f)
{
struct vim2m_q_data *q_data;
struct vb2_queue *vq;
vq = v4l2_m2m_get_vq(ctx->fh.m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
if (!q_data)
return -EINVAL;
if (vb2_is_busy(vq)) {
v4l2_err(&ctx->dev->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
q_data->fmt = find_format(f);
q_data->width = f->fmt.pix.width;
q_data->height = f->fmt.pix.height;
q_data->sizeimage = q_data->width * q_data->height
* q_data->fmt->depth >> 3;
dprintk(ctx->dev,
"Setting format for type %d, wxh: %dx%d, fmt: %d\n",
f->type, q_data->width, q_data->height, q_data->fmt->fourcc);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
ret = vidioc_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
return vidioc_s_fmt(file2ctx(file), f);
}
static int vidioc_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct vim2m_ctx *ctx = file2ctx(file);
int ret;
ret = vidioc_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
ret = vidioc_s_fmt(file2ctx(file), f);
if (!ret)
ctx->colorspace = f->fmt.pix.colorspace;
return ret;
}
static int vim2m_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vim2m_ctx *ctx =
container_of(ctrl->handler, struct vim2m_ctx, hdl);
switch (ctrl->id) {
case V4L2_CID_HFLIP:
if (ctrl->val)
ctx->mode |= MEM2MEM_HFLIP;
else
ctx->mode &= ~MEM2MEM_HFLIP;
break;
case V4L2_CID_VFLIP:
if (ctrl->val)
ctx->mode |= MEM2MEM_VFLIP;
else
ctx->mode &= ~MEM2MEM_VFLIP;
break;
case V4L2_CID_TRANS_TIME_MSEC:
ctx->transtime = ctrl->val;
break;
case V4L2_CID_TRANS_NUM_BUFS:
ctx->translen = ctrl->val;
break;
default:
v4l2_err(&ctx->dev->v4l2_dev, "Invalid control\n");
return -EINVAL;
}
return 0;
}
static int vim2m_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct vim2m_ctx *ctx = vb2_get_drv_priv(vq);
struct vim2m_q_data *q_data;
unsigned int size, count = *nbuffers;
q_data = get_q_data(ctx, vq->type);
size = q_data->width * q_data->height * q_data->fmt->depth >> 3;
while (size * count > MEM2MEM_VID_MEM_LIMIT)
(count)--;
*nplanes = 1;
*nbuffers = count;
sizes[0] = size;
dprintk(ctx->dev, "get %d buffer(s) of size %d each.\n", count, size);
return 0;
}
static int vim2m_buf_prepare(struct vb2_buffer *vb)
{
struct vim2m_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct vim2m_q_data *q_data;
dprintk(ctx->dev, "type: %d\n", vb->vb2_queue->type);
q_data = get_q_data(ctx, vb->vb2_queue->type);
if (V4L2_TYPE_IS_OUTPUT(vb->vb2_queue->type)) {
if (vb->v4l2_buf.field == V4L2_FIELD_ANY)
vb->v4l2_buf.field = V4L2_FIELD_NONE;
if (vb->v4l2_buf.field != V4L2_FIELD_NONE) {
dprintk(ctx->dev, "%s field isn't supported\n",
__func__);
return -EINVAL;
}
}
if (vb2_plane_size(vb, 0) < q_data->sizeimage) {
dprintk(ctx->dev, "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), (long)q_data->sizeimage);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, q_data->sizeimage);
return 0;
}
static void vim2m_buf_queue(struct vb2_buffer *vb)
{
struct vim2m_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
}
static int vim2m_start_streaming(struct vb2_queue *q, unsigned count)
{
struct vim2m_ctx *ctx = vb2_get_drv_priv(q);
struct vim2m_q_data *q_data = get_q_data(ctx, q->type);
q_data->sequence = 0;
return 0;
}
static void vim2m_stop_streaming(struct vb2_queue *q)
{
struct vim2m_ctx *ctx = vb2_get_drv_priv(q);
struct vb2_buffer *vb;
unsigned long flags;
for (;;) {
if (V4L2_TYPE_IS_OUTPUT(q->type))
vb = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
else
vb = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
if (vb == NULL)
return;
spin_lock_irqsave(&ctx->dev->irqlock, flags);
v4l2_m2m_buf_done(vb, VB2_BUF_STATE_ERROR);
spin_unlock_irqrestore(&ctx->dev->irqlock, flags);
}
}
static int queue_init(void *priv, struct vb2_queue *src_vq, struct vb2_queue *dst_vq)
{
struct vim2m_ctx *ctx = priv;
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
src_vq->ops = &vim2m_qops;
src_vq->mem_ops = &vb2_vmalloc_memops;
src_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
src_vq->lock = &ctx->dev->dev_mutex;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
dst_vq->ops = &vim2m_qops;
dst_vq->mem_ops = &vb2_vmalloc_memops;
dst_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
dst_vq->lock = &ctx->dev->dev_mutex;
return vb2_queue_init(dst_vq);
}
static int vim2m_open(struct file *file)
{
struct vim2m_dev *dev = video_drvdata(file);
struct vim2m_ctx *ctx = NULL;
struct v4l2_ctrl_handler *hdl;
int rc = 0;
if (mutex_lock_interruptible(&dev->dev_mutex))
return -ERESTARTSYS;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
rc = -ENOMEM;
goto open_unlock;
}
v4l2_fh_init(&ctx->fh, video_devdata(file));
file->private_data = &ctx->fh;
ctx->dev = dev;
hdl = &ctx->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &vim2m_ctrl_ops, V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(hdl, &vim2m_ctrl_ops, V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_custom(hdl, &vim2m_ctrl_trans_time_msec, NULL);
v4l2_ctrl_new_custom(hdl, &vim2m_ctrl_trans_num_bufs, NULL);
if (hdl->error) {
rc = hdl->error;
v4l2_ctrl_handler_free(hdl);
goto open_unlock;
}
ctx->fh.ctrl_handler = hdl;
v4l2_ctrl_handler_setup(hdl);
ctx->q_data[V4L2_M2M_SRC].fmt = &formats[0];
ctx->q_data[V4L2_M2M_SRC].width = 640;
ctx->q_data[V4L2_M2M_SRC].height = 480;
ctx->q_data[V4L2_M2M_SRC].sizeimage =
ctx->q_data[V4L2_M2M_SRC].width *
ctx->q_data[V4L2_M2M_SRC].height *
(ctx->q_data[V4L2_M2M_SRC].fmt->depth >> 3);
ctx->q_data[V4L2_M2M_DST] = ctx->q_data[V4L2_M2M_SRC];
ctx->colorspace = V4L2_COLORSPACE_REC709;
ctx->fh.m2m_ctx = v4l2_m2m_ctx_init(dev->m2m_dev, ctx, &queue_init);
if (IS_ERR(ctx->fh.m2m_ctx)) {
rc = PTR_ERR(ctx->fh.m2m_ctx);
v4l2_ctrl_handler_free(hdl);
kfree(ctx);
goto open_unlock;
}
v4l2_fh_add(&ctx->fh);
atomic_inc(&dev->num_inst);
dprintk(dev, "Created instance: %p, m2m_ctx: %p\n",
ctx, ctx->fh.m2m_ctx);
open_unlock:
mutex_unlock(&dev->dev_mutex);
return rc;
}
static int vim2m_release(struct file *file)
{
struct vim2m_dev *dev = video_drvdata(file);
struct vim2m_ctx *ctx = file2ctx(file);
dprintk(dev, "Releasing instance %p\n", ctx);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
v4l2_ctrl_handler_free(&ctx->hdl);
mutex_lock(&dev->dev_mutex);
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
mutex_unlock(&dev->dev_mutex);
kfree(ctx);
atomic_dec(&dev->num_inst);
return 0;
}
static int vim2m_probe(struct platform_device *pdev)
{
struct vim2m_dev *dev;
struct video_device *vfd;
int ret;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
spin_lock_init(&dev->irqlock);
ret = v4l2_device_register(&pdev->dev, &dev->v4l2_dev);
if (ret)
return ret;
atomic_set(&dev->num_inst, 0);
mutex_init(&dev->dev_mutex);
dev->vfd = vim2m_videodev;
vfd = &dev->vfd;
vfd->lock = &dev->dev_mutex;
vfd->v4l2_dev = &dev->v4l2_dev;
ret = video_register_device(vfd, VFL_TYPE_GRABBER, 0);
if (ret) {
v4l2_err(&dev->v4l2_dev, "Failed to register video device\n");
goto unreg_dev;
}
video_set_drvdata(vfd, dev);
snprintf(vfd->name, sizeof(vfd->name), "%s", vim2m_videodev.name);
v4l2_info(&dev->v4l2_dev,
"Device registered as /dev/video%d\n", vfd->num);
setup_timer(&dev->timer, device_isr, (long)dev);
platform_set_drvdata(pdev, dev);
dev->m2m_dev = v4l2_m2m_init(&m2m_ops);
if (IS_ERR(dev->m2m_dev)) {
v4l2_err(&dev->v4l2_dev, "Failed to init mem2mem device\n");
ret = PTR_ERR(dev->m2m_dev);
goto err_m2m;
}
return 0;
err_m2m:
v4l2_m2m_release(dev->m2m_dev);
video_unregister_device(&dev->vfd);
unreg_dev:
v4l2_device_unregister(&dev->v4l2_dev);
return ret;
}
static int vim2m_remove(struct platform_device *pdev)
{
struct vim2m_dev *dev = platform_get_drvdata(pdev);
v4l2_info(&dev->v4l2_dev, "Removing " MEM2MEM_NAME);
v4l2_m2m_release(dev->m2m_dev);
del_timer_sync(&dev->timer);
video_unregister_device(&dev->vfd);
v4l2_device_unregister(&dev->v4l2_dev);
return 0;
}
static void __exit vim2m_exit(void)
{
platform_driver_unregister(&vim2m_pdrv);
platform_device_unregister(&vim2m_pdev);
}
static int __init vim2m_init(void)
{
int ret;
ret = platform_device_register(&vim2m_pdev);
if (ret)
return ret;
ret = platform_driver_register(&vim2m_pdrv);
if (ret)
platform_device_unregister(&vim2m_pdev);
return 0;
}
