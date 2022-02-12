static inline void coda_write(struct coda_dev *dev, u32 data, u32 reg)
{
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: data=0x%x, reg=0x%x\n", __func__, data, reg);
writel(data, dev->regs_base + reg);
}
static inline unsigned int coda_read(struct coda_dev *dev, u32 reg)
{
u32 data;
data = readl(dev->regs_base + reg);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: data=0x%x, reg=0x%x\n", __func__, data, reg);
return data;
}
static inline unsigned long coda_isbusy(struct coda_dev *dev)
{
return coda_read(dev, CODA_REG_BIT_BUSY);
}
static inline int coda_is_initialized(struct coda_dev *dev)
{
return (coda_read(dev, CODA_REG_BIT_CUR_PC) != 0);
}
static int coda_wait_timeout(struct coda_dev *dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
while (coda_isbusy(dev)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
}
return 0;
}
static void coda_command_async(struct coda_ctx *ctx, int cmd)
{
struct coda_dev *dev = ctx->dev;
coda_write(dev, CODA_REG_BIT_BUSY_FLAG, CODA_REG_BIT_BUSY);
coda_write(dev, ctx->idx, CODA_REG_BIT_RUN_INDEX);
coda_write(dev, ctx->params.codec_mode, CODA_REG_BIT_RUN_COD_STD);
coda_write(dev, cmd, CODA_REG_BIT_RUN_COMMAND);
}
static int coda_command_sync(struct coda_ctx *ctx, int cmd)
{
struct coda_dev *dev = ctx->dev;
coda_command_async(ctx, cmd);
return coda_wait_timeout(dev);
}
static struct coda_q_data *get_q_data(struct coda_ctx *ctx,
enum v4l2_buf_type type)
{
switch (type) {
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
return &(ctx->q_data[V4L2_M2M_SRC]);
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return &(ctx->q_data[V4L2_M2M_DST]);
default:
BUG();
}
return NULL;
}
static struct coda_fmt *find_format(struct coda_dev *dev, struct v4l2_format *f)
{
struct coda_fmt *formats = dev->devtype->formats;
int num_formats = dev->devtype->num_formats;
unsigned int k;
for (k = 0; k < num_formats; k++) {
if (formats[k].fourcc == f->fmt.pix.pixelformat)
break;
}
if (k == num_formats)
return NULL;
return &formats[k];
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strlcpy(cap->driver, CODA_NAME, sizeof(cap->driver));
strlcpy(cap->card, CODA_NAME, sizeof(cap->card));
strlcpy(cap->bus_info, CODA_NAME, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_VIDEO_M2M | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int enum_fmt(void *priv, struct v4l2_fmtdesc *f,
enum coda_fmt_type type)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
struct coda_dev *dev = ctx->dev;
struct coda_fmt *formats = dev->devtype->formats;
struct coda_fmt *fmt;
int num_formats = dev->devtype->num_formats;
int i, num = 0;
for (i = 0; i < num_formats; i++) {
if (formats[i].type == type) {
if (num == f->index)
break;
++num;
}
}
if (i < num_formats) {
fmt = &formats[i];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
return 0;
}
return -EINVAL;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(priv, f, CODA_FMT_ENC);
}
static int vidioc_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(priv, f, CODA_FMT_RAW);
}
static int vidioc_g_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct coda_q_data *q_data;
struct coda_ctx *ctx = fh_to_ctx(priv);
vq = v4l2_m2m_get_vq(ctx->m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.pixelformat = q_data->fmt->fourcc;
f->fmt.pix.width = q_data->width;
f->fmt.pix.height = q_data->height;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420)
f->fmt.pix.bytesperline = round_up(f->fmt.pix.width, 2);
else
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = q_data->sizeimage;
f->fmt.pix.colorspace = ctx->colorspace;
return 0;
}
static int vidioc_try_fmt(struct coda_dev *dev, struct v4l2_format *f)
{
enum v4l2_field field;
field = f->fmt.pix.field;
if (field == V4L2_FIELD_ANY)
field = V4L2_FIELD_NONE;
else if (V4L2_FIELD_NONE != field)
return -EINVAL;
f->fmt.pix.field = field;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) {
v4l_bound_align_image(&f->fmt.pix.width, MIN_W, MAX_W,
W_ALIGN, &f->fmt.pix.height,
MIN_H, MAX_H, H_ALIGN, S_ALIGN);
f->fmt.pix.bytesperline = round_up(f->fmt.pix.width, 2);
f->fmt.pix.sizeimage = f->fmt.pix.width *
f->fmt.pix.height * 3 / 2;
} else {
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = CODA_MAX_FRAME_SIZE;
}
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
struct coda_fmt *fmt;
struct coda_ctx *ctx = fh_to_ctx(priv);
fmt = find_format(ctx->dev, f);
if (!fmt || !(fmt->type == CODA_FMT_ENC))
f->fmt.pix.pixelformat = V4L2_PIX_FMT_H264;
f->fmt.pix.colorspace = ctx->colorspace;
ret = vidioc_try_fmt(ctx->dev, f);
if (ret < 0)
return ret;
return 0;
}
static int vidioc_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
struct coda_fmt *fmt;
int ret;
fmt = find_format(ctx->dev, f);
if (!fmt || !(fmt->type == CODA_FMT_RAW))
f->fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
if (!f->fmt.pix.colorspace)
f->fmt.pix.colorspace = V4L2_COLORSPACE_REC709;
ret = vidioc_try_fmt(ctx->dev, f);
if (ret < 0)
return ret;
return 0;
}
static int vidioc_s_fmt(struct coda_ctx *ctx, struct v4l2_format *f)
{
struct coda_q_data *q_data;
struct vb2_queue *vq;
int ret;
vq = v4l2_m2m_get_vq(ctx->m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
if (!q_data)
return -EINVAL;
if (vb2_is_busy(vq)) {
v4l2_err(&ctx->dev->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
ret = vidioc_try_fmt(ctx->dev, f);
if (ret)
return ret;
q_data->fmt = find_format(ctx->dev, f);
q_data->width = f->fmt.pix.width;
q_data->height = f->fmt.pix.height;
q_data->sizeimage = f->fmt.pix.sizeimage;
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
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
return vidioc_s_fmt(fh_to_ctx(priv), f);
}
static int vidioc_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
int ret;
ret = vidioc_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
ret = vidioc_s_fmt(ctx, f);
if (ret)
ctx->colorspace = f->fmt.pix.colorspace;
return ret;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbufs)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_reqbufs(file, ctx->m2m_ctx, reqbufs);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_querybuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_qbuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_dqbuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_create_bufs(struct file *file, void *priv,
struct v4l2_create_buffers *create)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_create_bufs(file, ctx->m2m_ctx, create);
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_streamon(file, ctx->m2m_ctx, type);
}
static int vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_streamoff(file, ctx->m2m_ctx, type);
}
static void coda_device_run(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
struct coda_q_data *q_data_src, *q_data_dst;
struct vb2_buffer *src_buf, *dst_buf;
struct coda_dev *dev = ctx->dev;
int force_ipicture;
int quant_param = 0;
u32 picture_y, picture_cb, picture_cr;
u32 pic_stream_buffer_addr, pic_stream_buffer_size;
u32 dst_fourcc;
src_buf = v4l2_m2m_next_src_buf(ctx->m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->m2m_ctx);
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
dst_fourcc = q_data_dst->fmt->fourcc;
src_buf->v4l2_buf.sequence = ctx->isequence;
dst_buf->v4l2_buf.sequence = ctx->isequence;
ctx->isequence++;
if (src_buf->v4l2_buf.sequence % ctx->params.gop_size) {
src_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_PFRAME;
src_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_KEYFRAME;
} else {
src_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_KEYFRAME;
src_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_PFRAME;
}
if (src_buf->v4l2_buf.sequence == 0) {
pic_stream_buffer_addr =
vb2_dma_contig_plane_dma_addr(dst_buf, 0) +
ctx->vpu_header_size[0] +
ctx->vpu_header_size[1] +
ctx->vpu_header_size[2];
pic_stream_buffer_size = CODA_MAX_FRAME_SIZE -
ctx->vpu_header_size[0] -
ctx->vpu_header_size[1] -
ctx->vpu_header_size[2];
memcpy(vb2_plane_vaddr(dst_buf, 0),
&ctx->vpu_header[0][0], ctx->vpu_header_size[0]);
memcpy(vb2_plane_vaddr(dst_buf, 0) + ctx->vpu_header_size[0],
&ctx->vpu_header[1][0], ctx->vpu_header_size[1]);
memcpy(vb2_plane_vaddr(dst_buf, 0) + ctx->vpu_header_size[0] +
ctx->vpu_header_size[1], &ctx->vpu_header[2][0],
ctx->vpu_header_size[2]);
} else {
pic_stream_buffer_addr =
vb2_dma_contig_plane_dma_addr(dst_buf, 0);
pic_stream_buffer_size = CODA_MAX_FRAME_SIZE;
}
if (src_buf->v4l2_buf.flags & V4L2_BUF_FLAG_KEYFRAME) {
force_ipicture = 1;
switch (dst_fourcc) {
case V4L2_PIX_FMT_H264:
quant_param = ctx->params.h264_intra_qp;
break;
case V4L2_PIX_FMT_MPEG4:
quant_param = ctx->params.mpeg4_intra_qp;
break;
default:
v4l2_warn(&ctx->dev->v4l2_dev,
"cannot set intra qp, fmt not supported\n");
break;
}
} else {
force_ipicture = 0;
switch (dst_fourcc) {
case V4L2_PIX_FMT_H264:
quant_param = ctx->params.h264_inter_qp;
break;
case V4L2_PIX_FMT_MPEG4:
quant_param = ctx->params.mpeg4_inter_qp;
break;
default:
v4l2_warn(&ctx->dev->v4l2_dev,
"cannot set inter qp, fmt not supported\n");
break;
}
}
coda_write(dev, CODA_ROT_MIR_ENABLE | ctx->params.rot_mode, CODA_CMD_ENC_PIC_ROT_MODE);
coda_write(dev, quant_param, CODA_CMD_ENC_PIC_QS);
picture_y = vb2_dma_contig_plane_dma_addr(src_buf, 0);
picture_cb = picture_y + q_data_src->width * q_data_src->height;
picture_cr = picture_cb + q_data_src->width / 2 *
q_data_src->height / 2;
coda_write(dev, picture_y, CODA_CMD_ENC_PIC_SRC_ADDR_Y);
coda_write(dev, picture_cb, CODA_CMD_ENC_PIC_SRC_ADDR_CB);
coda_write(dev, picture_cr, CODA_CMD_ENC_PIC_SRC_ADDR_CR);
coda_write(dev, force_ipicture << 1 & 0x2,
CODA_CMD_ENC_PIC_OPTION);
coda_write(dev, pic_stream_buffer_addr, CODA_CMD_ENC_PIC_BB_START);
coda_write(dev, pic_stream_buffer_size / 1024,
CODA_CMD_ENC_PIC_BB_SIZE);
if (dev->devtype->product == CODA_7541) {
coda_write(dev, CODA7_USE_BIT_ENABLE | CODA7_USE_HOST_BIT_ENABLE |
CODA7_USE_ME_ENABLE | CODA7_USE_HOST_ME_ENABLE,
CODA7_REG_BIT_AXI_SRAM_USE);
}
schedule_delayed_work(&dev->timeout, HZ);
INIT_COMPLETION(dev->done);
coda_command_async(ctx, CODA_COMMAND_PIC_RUN);
}
static int coda_job_ready(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
if (!v4l2_m2m_num_src_bufs_ready(ctx->m2m_ctx) ||
!v4l2_m2m_num_dst_bufs_ready(ctx->m2m_ctx)) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"not ready: not enough video buffers.\n");
return 0;
}
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"job ready\n");
return 1;
}
static void coda_job_abort(void *priv)
{
struct coda_ctx *ctx = priv;
struct coda_dev *dev = ctx->dev;
ctx->aborting = 1;
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"Aborting task\n");
v4l2_m2m_job_finish(dev->m2m_dev, ctx->m2m_ctx);
}
static void coda_lock(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
struct coda_dev *pcdev = ctx->dev;
mutex_lock(&pcdev->dev_mutex);
}
static void coda_unlock(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
struct coda_dev *pcdev = ctx->dev;
mutex_unlock(&pcdev->dev_mutex);
}
static void set_default_params(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
ctx->params.codec_mode = CODA_MODE_INVALID;
ctx->colorspace = V4L2_COLORSPACE_REC709;
ctx->params.framerate = 30;
ctx->aborting = 0;
ctx->q_data[V4L2_M2M_SRC].fmt = &dev->devtype->formats[0];
ctx->q_data[V4L2_M2M_DST].fmt = &dev->devtype->formats[1];
ctx->q_data[V4L2_M2M_SRC].width = MAX_W;
ctx->q_data[V4L2_M2M_SRC].height = MAX_H;
ctx->q_data[V4L2_M2M_SRC].sizeimage = (MAX_W * MAX_H * 3) / 2;
ctx->q_data[V4L2_M2M_DST].width = MAX_W;
ctx->q_data[V4L2_M2M_DST].height = MAX_H;
ctx->q_data[V4L2_M2M_DST].sizeimage = CODA_MAX_FRAME_SIZE;
}
static int coda_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct coda_ctx *ctx = vb2_get_drv_priv(vq);
struct coda_q_data *q_data;
unsigned int size;
q_data = get_q_data(ctx, vq->type);
size = q_data->sizeimage;
*nplanes = 1;
sizes[0] = size;
alloc_ctxs[0] = ctx->dev->alloc_ctx;
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"get %d buffer(s) of size %d each.\n", *nbuffers, size);
return 0;
}
static int coda_buf_prepare(struct vb2_buffer *vb)
{
struct coda_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct coda_q_data *q_data;
q_data = get_q_data(ctx, vb->vb2_queue->type);
if (vb2_plane_size(vb, 0) < q_data->sizeimage) {
v4l2_warn(&ctx->dev->v4l2_dev,
"%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0),
(long)q_data->sizeimage);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, q_data->sizeimage);
return 0;
}
static void coda_buf_queue(struct vb2_buffer *vb)
{
struct coda_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
v4l2_m2m_buf_queue(ctx->m2m_ctx, vb);
}
static void coda_wait_prepare(struct vb2_queue *q)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
coda_unlock(ctx);
}
static void coda_wait_finish(struct vb2_queue *q)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
coda_lock(ctx);
}
static void coda_free_framebuffers(struct coda_ctx *ctx)
{
int i;
for (i = 0; i < CODA_MAX_FRAMEBUFFERS; i++) {
if (ctx->internal_frames[i].vaddr) {
dma_free_coherent(&ctx->dev->plat_dev->dev,
ctx->internal_frames[i].size,
ctx->internal_frames[i].vaddr,
ctx->internal_frames[i].paddr);
ctx->internal_frames[i].vaddr = NULL;
}
}
}
static int coda_alloc_framebuffers(struct coda_ctx *ctx, struct coda_q_data *q_data, u32 fourcc)
{
struct coda_dev *dev = ctx->dev;
int height = q_data->height;
int width = q_data->width;
u32 *p;
int i;
ctx->num_internal_frames = CODA_MAX_FRAMEBUFFERS;
for (i = 0; i < ctx->num_internal_frames; i++) {
ctx->internal_frames[i].size = q_data->sizeimage;
if (fourcc == V4L2_PIX_FMT_H264 && dev->devtype->product != CODA_DX6)
ctx->internal_frames[i].size += width / 2 * height / 2;
ctx->internal_frames[i].vaddr = dma_alloc_coherent(
&dev->plat_dev->dev, ctx->internal_frames[i].size,
&ctx->internal_frames[i].paddr, GFP_KERNEL);
if (!ctx->internal_frames[i].vaddr) {
coda_free_framebuffers(ctx);
return -ENOMEM;
}
}
p = ctx->parabuf.vaddr;
if (dev->devtype->product == CODA_DX6) {
for (i = 0; i < ctx->num_internal_frames; i++) {
p[i * 3] = ctx->internal_frames[i].paddr;
p[i * 3 + 1] = p[i * 3] + width * height;
p[i * 3 + 2] = p[i * 3 + 1] + width / 2 * height / 2;
}
} else {
for (i = 0; i < ctx->num_internal_frames; i += 2) {
p[i * 3 + 1] = ctx->internal_frames[i].paddr;
p[i * 3] = p[i * 3 + 1] + width * height;
p[i * 3 + 3] = p[i * 3] + (width / 2) * (height / 2);
if (fourcc == V4L2_PIX_FMT_H264)
p[96 + i + 1] = p[i * 3 + 3] + (width / 2) * (height / 2);
if (i + 1 < ctx->num_internal_frames) {
p[i * 3 + 2] = ctx->internal_frames[i+1].paddr;
p[i * 3 + 5] = p[i * 3 + 2] + width * height ;
p[i * 3 + 4] = p[i * 3 + 5] + (width / 2) * (height / 2);
if (fourcc == V4L2_PIX_FMT_H264)
p[96 + i] = p[i * 3 + 4] + (width / 2) * (height / 2);
}
}
}
return 0;
}
static int coda_h264_padding(int size, char *p)
{
int nal_size;
int diff;
diff = size - (size & ~0x7);
if (diff == 0)
return 0;
nal_size = coda_filler_size[diff];
memcpy(p, coda_filler_nal, nal_size);
*(p + nal_size - 1) = 0x80;
return nal_size;
}
static int coda_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct v4l2_device *v4l2_dev = &ctx->dev->v4l2_dev;
u32 bitstream_buf, bitstream_size;
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data_src, *q_data_dst;
struct vb2_buffer *buf;
u32 dst_fourcc;
u32 value;
int ret;
if (count < 1)
return -EINVAL;
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
ctx->rawstreamon = 1;
else
ctx->compstreamon = 1;
if (!(ctx->rawstreamon & ctx->compstreamon))
return 0;
if (coda_isbusy(dev))
if (wait_for_completion_interruptible_timeout(&dev->done, HZ) <= 0)
return -EBUSY;
ctx->gopcounter = ctx->params.gop_size - 1;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
buf = v4l2_m2m_next_dst_buf(ctx->m2m_ctx);
bitstream_buf = vb2_dma_contig_plane_dma_addr(buf, 0);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
bitstream_size = q_data_dst->sizeimage;
dst_fourcc = q_data_dst->fmt->fourcc;
if (q_data_src->fmt->type == CODA_FMT_RAW &&
q_data_dst->fmt->type == CODA_FMT_ENC) {
ctx->inst_type = CODA_INST_ENCODER;
} else if (q_data_src->fmt->type == CODA_FMT_ENC &&
q_data_dst->fmt->type == CODA_FMT_RAW) {
ctx->inst_type = CODA_INST_DECODER;
v4l2_err(v4l2_dev, "decoding not supported.\n");
return -EINVAL;
} else {
v4l2_err(v4l2_dev, "couldn't tell instance type.\n");
return -EINVAL;
}
if (!coda_is_initialized(dev)) {
v4l2_err(v4l2_dev, "coda is not initialized.\n");
return -EFAULT;
}
coda_write(dev, ctx->parabuf.paddr, CODA_REG_BIT_PARA_BUF_ADDR);
coda_write(dev, bitstream_buf, CODA_REG_BIT_RD_PTR(ctx->idx));
coda_write(dev, bitstream_buf, CODA_REG_BIT_WR_PTR(ctx->idx));
switch (dev->devtype->product) {
case CODA_DX6:
coda_write(dev, CODADX6_STREAM_BUF_DYNALLOC_EN |
CODADX6_STREAM_BUF_PIC_RESET, CODA_REG_BIT_STREAM_CTRL);
break;
default:
coda_write(dev, CODA7_STREAM_BUF_DYNALLOC_EN |
CODA7_STREAM_BUF_PIC_RESET, CODA_REG_BIT_STREAM_CTRL);
}
if (dev->devtype->product == CODA_DX6) {
coda_write(dev, dev->iram_paddr, CODADX6_REG_BIT_SEARCH_RAM_BASE_ADDR);
}
switch (dev->devtype->product) {
case CODA_DX6:
value = (q_data_src->width & CODADX6_PICWIDTH_MASK) << CODADX6_PICWIDTH_OFFSET;
break;
default:
value = (q_data_src->width & CODA7_PICWIDTH_MASK) << CODA7_PICWIDTH_OFFSET;
}
value |= (q_data_src->height & CODA_PICHEIGHT_MASK) << CODA_PICHEIGHT_OFFSET;
coda_write(dev, value, CODA_CMD_ENC_SEQ_SRC_SIZE);
coda_write(dev, ctx->params.framerate,
CODA_CMD_ENC_SEQ_SRC_F_RATE);
switch (dst_fourcc) {
case V4L2_PIX_FMT_MPEG4:
if (dev->devtype->product == CODA_DX6)
ctx->params.codec_mode = CODADX6_MODE_ENCODE_MP4;
else
ctx->params.codec_mode = CODA7_MODE_ENCODE_MP4;
coda_write(dev, CODA_STD_MPEG4, CODA_CMD_ENC_SEQ_COD_STD);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_MP4_PARA);
break;
case V4L2_PIX_FMT_H264:
if (dev->devtype->product == CODA_DX6)
ctx->params.codec_mode = CODADX6_MODE_ENCODE_H264;
else
ctx->params.codec_mode = CODA7_MODE_ENCODE_H264;
coda_write(dev, CODA_STD_H264, CODA_CMD_ENC_SEQ_COD_STD);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_264_PARA);
break;
default:
v4l2_err(v4l2_dev,
"dst format (0x%08x) invalid.\n", dst_fourcc);
return -EINVAL;
}
switch (ctx->params.slice_mode) {
case V4L2_MPEG_VIDEO_MULTI_SLICE_MODE_SINGLE:
value = 0;
break;
case V4L2_MPEG_VIDEO_MULTI_SICE_MODE_MAX_MB:
value = (ctx->params.slice_max_mb & CODA_SLICING_SIZE_MASK) << CODA_SLICING_SIZE_OFFSET;
value |= (1 & CODA_SLICING_UNIT_MASK) << CODA_SLICING_UNIT_OFFSET;
value |= 1 & CODA_SLICING_MODE_MASK;
break;
case V4L2_MPEG_VIDEO_MULTI_SICE_MODE_MAX_BYTES:
value = (ctx->params.slice_max_bits & CODA_SLICING_SIZE_MASK) << CODA_SLICING_SIZE_OFFSET;
value |= (0 & CODA_SLICING_UNIT_MASK) << CODA_SLICING_UNIT_OFFSET;
value |= 1 & CODA_SLICING_MODE_MASK;
break;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_SLICE_MODE);
value = ctx->params.gop_size & CODA_GOP_SIZE_MASK;
coda_write(dev, value, CODA_CMD_ENC_SEQ_GOP_SIZE);
if (ctx->params.bitrate) {
value = (ctx->params.bitrate & CODA_RATECONTROL_BITRATE_MASK) << CODA_RATECONTROL_BITRATE_OFFSET;
value |= 1 & CODA_RATECONTROL_ENABLE_MASK;
} else {
value = 0;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_RC_PARA);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_RC_BUF_SIZE);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_INTRA_REFRESH);
coda_write(dev, bitstream_buf, CODA_CMD_ENC_SEQ_BB_START);
coda_write(dev, bitstream_size / 1024, CODA_CMD_ENC_SEQ_BB_SIZE);
value = (CODA_DEFAULT_GAMMA & CODA_GAMMA_MASK) << CODA_GAMMA_OFFSET;
coda_write(dev, value, CODA_CMD_ENC_SEQ_RC_GAMMA);
value = (CODA_DEFAULT_GAMMA > 0) << CODA_OPTION_GAMMA_OFFSET;
value |= (0 & CODA_OPTION_SLICEREPORT_MASK) << CODA_OPTION_SLICEREPORT_OFFSET;
coda_write(dev, value, CODA_CMD_ENC_SEQ_OPTION);
if (dst_fourcc == V4L2_PIX_FMT_H264) {
value = (FMO_SLICE_SAVE_BUF_SIZE << 7);
value |= (0 & CODA_FMOPARAM_TYPE_MASK) << CODA_FMOPARAM_TYPE_OFFSET;
value |= 0 & CODA_FMOPARAM_SLICENUM_MASK;
if (dev->devtype->product == CODA_DX6) {
coda_write(dev, value, CODADX6_CMD_ENC_SEQ_FMO);
} else {
coda_write(dev, dev->iram_paddr, CODA7_CMD_ENC_SEQ_SEARCH_BASE);
coda_write(dev, 48 * 1024, CODA7_CMD_ENC_SEQ_SEARCH_SIZE);
}
}
if (coda_command_sync(ctx, CODA_COMMAND_SEQ_INIT)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_SEQ_INIT timeout\n");
return -ETIMEDOUT;
}
if (coda_read(dev, CODA_RET_ENC_SEQ_SUCCESS) == 0)
return -EFAULT;
ret = coda_alloc_framebuffers(ctx, q_data_src, dst_fourcc);
if (ret < 0)
return ret;
coda_write(dev, ctx->num_internal_frames, CODA_CMD_SET_FRAME_BUF_NUM);
coda_write(dev, round_up(q_data_src->width, 8), CODA_CMD_SET_FRAME_BUF_STRIDE);
if (dev->devtype->product != CODA_DX6) {
coda_write(dev, round_up(q_data_src->width, 8), CODA7_CMD_SET_FRAME_SOURCE_BUF_STRIDE);
coda_write(dev, dev->iram_paddr + 48 * 1024, CODA7_CMD_SET_FRAME_AXI_DBKY_ADDR);
coda_write(dev, dev->iram_paddr + 53 * 1024, CODA7_CMD_SET_FRAME_AXI_DBKC_ADDR);
coda_write(dev, dev->iram_paddr + 58 * 1024, CODA7_CMD_SET_FRAME_AXI_BIT_ADDR);
coda_write(dev, dev->iram_paddr + 68 * 1024, CODA7_CMD_SET_FRAME_AXI_IPACDC_ADDR);
coda_write(dev, 0x0, CODA7_CMD_SET_FRAME_AXI_OVL_ADDR);
}
if (coda_command_sync(ctx, CODA_COMMAND_SET_FRAME_BUF)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_SET_FRAME_BUF timeout\n");
return -ETIMEDOUT;
}
buf = v4l2_m2m_next_dst_buf(ctx->m2m_ctx);
switch (dst_fourcc) {
case V4L2_PIX_FMT_H264:
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0), CODA_CMD_ENC_HEADER_BB_START);
coda_write(dev, bitstream_size, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, CODA_HEADER_H264_SPS, CODA_CMD_ENC_HEADER_CODE);
if (coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_ENCODE_HEADER timeout\n");
return -ETIMEDOUT;
}
ctx->vpu_header_size[0] = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
memcpy(&ctx->vpu_header[0][0], vb2_plane_vaddr(buf, 0),
ctx->vpu_header_size[0]);
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0), CODA_CMD_ENC_HEADER_BB_START);
coda_write(dev, bitstream_size, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, CODA_HEADER_H264_PPS, CODA_CMD_ENC_HEADER_CODE);
if (coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_ENCODE_HEADER timeout\n");
return -ETIMEDOUT;
}
ctx->vpu_header_size[1] = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
memcpy(&ctx->vpu_header[1][0], vb2_plane_vaddr(buf, 0),
ctx->vpu_header_size[1]);
ctx->vpu_header_size[2] = coda_h264_padding(
(ctx->vpu_header_size[0] +
ctx->vpu_header_size[1]),
ctx->vpu_header[2]);
break;
case V4L2_PIX_FMT_MPEG4:
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0), CODA_CMD_ENC_HEADER_BB_START);
coda_write(dev, bitstream_size, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, CODA_HEADER_MP4V_VOS, CODA_CMD_ENC_HEADER_CODE);
if (coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_ENCODE_HEADER timeout\n");
return -ETIMEDOUT;
}
ctx->vpu_header_size[0] = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
memcpy(&ctx->vpu_header[0][0], vb2_plane_vaddr(buf, 0),
ctx->vpu_header_size[0]);
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0), CODA_CMD_ENC_HEADER_BB_START);
coda_write(dev, bitstream_size, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, CODA_HEADER_MP4V_VIS, CODA_CMD_ENC_HEADER_CODE);
if (coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_ENCODE_HEADER failed\n");
return -ETIMEDOUT;
}
ctx->vpu_header_size[1] = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
memcpy(&ctx->vpu_header[1][0], vb2_plane_vaddr(buf, 0),
ctx->vpu_header_size[1]);
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0), CODA_CMD_ENC_HEADER_BB_START);
coda_write(dev, bitstream_size, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, CODA_HEADER_MP4V_VOL, CODA_CMD_ENC_HEADER_CODE);
if (coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER)) {
v4l2_err(v4l2_dev, "CODA_COMMAND_ENCODE_HEADER failed\n");
return -ETIMEDOUT;
}
ctx->vpu_header_size[2] = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
memcpy(&ctx->vpu_header[2][0], vb2_plane_vaddr(buf, 0),
ctx->vpu_header_size[2]);
break;
default:
break;
}
return 0;
}
static int coda_stop_streaming(struct vb2_queue *q)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct coda_dev *dev = ctx->dev;
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"%s: output\n", __func__);
ctx->rawstreamon = 0;
} else {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"%s: capture\n", __func__);
ctx->compstreamon = 0;
}
if (ctx->rawstreamon || ctx->compstreamon)
return 0;
if (coda_isbusy(dev)) {
if (wait_for_completion_interruptible_timeout(&dev->done, HZ) <= 0) {
v4l2_warn(&dev->v4l2_dev,
"%s: timeout, sending SEQ_END anyway\n", __func__);
}
}
cancel_delayed_work(&dev->timeout);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: sent command 'SEQ_END' to coda\n", __func__);
if (coda_command_sync(ctx, CODA_COMMAND_SEQ_END)) {
v4l2_err(&dev->v4l2_dev,
"CODA_COMMAND_SEQ_END failed\n");
return -ETIMEDOUT;
}
coda_free_framebuffers(ctx);
return 0;
}
static int coda_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct coda_ctx *ctx =
container_of(ctrl->handler, struct coda_ctx, ctrls);
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"s_ctrl: id = %d, val = %d\n", ctrl->id, ctrl->val);
switch (ctrl->id) {
case V4L2_CID_HFLIP:
if (ctrl->val)
ctx->params.rot_mode |= CODA_MIR_HOR;
else
ctx->params.rot_mode &= ~CODA_MIR_HOR;
break;
case V4L2_CID_VFLIP:
if (ctrl->val)
ctx->params.rot_mode |= CODA_MIR_VER;
else
ctx->params.rot_mode &= ~CODA_MIR_VER;
break;
case V4L2_CID_MPEG_VIDEO_BITRATE:
ctx->params.bitrate = ctrl->val / 1000;
break;
case V4L2_CID_MPEG_VIDEO_GOP_SIZE:
ctx->params.gop_size = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_I_FRAME_QP:
ctx->params.h264_intra_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_P_FRAME_QP:
ctx->params.h264_inter_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_MPEG4_I_FRAME_QP:
ctx->params.mpeg4_intra_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_MPEG4_P_FRAME_QP:
ctx->params.mpeg4_inter_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MODE:
ctx->params.slice_mode = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_MB:
ctx->params.slice_max_mb = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_BYTES:
ctx->params.slice_max_bits = ctrl->val * 8;
break;
case V4L2_CID_MPEG_VIDEO_HEADER_MODE:
break;
default:
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"Invalid control, id=%d, val=%d\n",
ctrl->id, ctrl->val);
return -EINVAL;
}
return 0;
}
static int coda_ctrls_setup(struct coda_ctx *ctx)
{
v4l2_ctrl_handler_init(&ctx->ctrls, 9);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_BITRATE, 0, 32767000, 1, 0);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_GOP_SIZE, 1, 60, 1, 16);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_I_FRAME_QP, 1, 51, 1, 25);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_P_FRAME_QP, 1, 51, 1, 25);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_MPEG4_I_FRAME_QP, 1, 31, 1, 2);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_MPEG4_P_FRAME_QP, 1, 31, 1, 2);
v4l2_ctrl_new_std_menu(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MODE,
V4L2_MPEG_VIDEO_MULTI_SICE_MODE_MAX_BYTES, 0x0,
V4L2_MPEG_VIDEO_MULTI_SLICE_MODE_SINGLE);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_MB, 1, 0x3fffffff, 1, 1);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_BYTES, 1, 0x3fffffff, 1, 500);
v4l2_ctrl_new_std_menu(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_HEADER_MODE,
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME,
(1 << V4L2_MPEG_VIDEO_HEADER_MODE_SEPARATE),
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME);
if (ctx->ctrls.error) {
v4l2_err(&ctx->dev->v4l2_dev, "control initialization error (%d)",
ctx->ctrls.error);
return -EINVAL;
}
return v4l2_ctrl_handler_setup(&ctx->ctrls);
}
static int coda_queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct coda_ctx *ctx = priv;
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
src_vq->ops = &coda_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->timestamp_type = V4L2_BUF_FLAG_TIMESTAMP_COPY;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
dst_vq->ops = &coda_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->timestamp_type = V4L2_BUF_FLAG_TIMESTAMP_COPY;
return vb2_queue_init(dst_vq);
}
static int coda_next_free_instance(struct coda_dev *dev)
{
return ffz(dev->instance_mask);
}
static int coda_open(struct file *file)
{
struct coda_dev *dev = video_drvdata(file);
struct coda_ctx *ctx = NULL;
int ret = 0;
int idx;
idx = coda_next_free_instance(dev);
if (idx >= CODA_MAX_INSTANCES)
return -EBUSY;
set_bit(idx, &dev->instance_mask);
ctx = kzalloc(sizeof *ctx, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
v4l2_fh_init(&ctx->fh, video_devdata(file));
file->private_data = &ctx->fh;
v4l2_fh_add(&ctx->fh);
ctx->dev = dev;
ctx->idx = idx;
set_default_params(ctx);
ctx->m2m_ctx = v4l2_m2m_ctx_init(dev->m2m_dev, ctx,
&coda_queue_init);
if (IS_ERR(ctx->m2m_ctx)) {
int ret = PTR_ERR(ctx->m2m_ctx);
v4l2_err(&dev->v4l2_dev, "%s return error (%d)\n",
__func__, ret);
goto err;
}
ret = coda_ctrls_setup(ctx);
if (ret) {
v4l2_err(&dev->v4l2_dev, "failed to setup coda controls\n");
goto err;
}
ctx->fh.ctrl_handler = &ctx->ctrls;
ctx->parabuf.vaddr = dma_alloc_coherent(&dev->plat_dev->dev,
CODA_PARA_BUF_SIZE, &ctx->parabuf.paddr, GFP_KERNEL);
if (!ctx->parabuf.vaddr) {
v4l2_err(&dev->v4l2_dev, "failed to allocate parabuf");
ret = -ENOMEM;
goto err;
}
coda_lock(ctx);
list_add(&ctx->list, &dev->instances);
coda_unlock(ctx);
clk_prepare_enable(dev->clk_per);
clk_prepare_enable(dev->clk_ahb);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev, "Created instance %d (%p)\n",
ctx->idx, ctx);
return 0;
err:
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
kfree(ctx);
return ret;
}
static int coda_release(struct file *file)
{
struct coda_dev *dev = video_drvdata(file);
struct coda_ctx *ctx = fh_to_ctx(file->private_data);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev, "Releasing instance %p\n",
ctx);
coda_lock(ctx);
list_del(&ctx->list);
coda_unlock(ctx);
dma_free_coherent(&dev->plat_dev->dev, CODA_PARA_BUF_SIZE,
ctx->parabuf.vaddr, ctx->parabuf.paddr);
v4l2_m2m_ctx_release(ctx->m2m_ctx);
v4l2_ctrl_handler_free(&ctx->ctrls);
clk_disable_unprepare(dev->clk_per);
clk_disable_unprepare(dev->clk_ahb);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
clear_bit(ctx->idx, &dev->instance_mask);
kfree(ctx);
return 0;
}
static unsigned int coda_poll(struct file *file,
struct poll_table_struct *wait)
{
struct coda_ctx *ctx = fh_to_ctx(file->private_data);
int ret;
coda_lock(ctx);
ret = v4l2_m2m_poll(file, ctx->m2m_ctx, wait);
coda_unlock(ctx);
return ret;
}
static int coda_mmap(struct file *file, struct vm_area_struct *vma)
{
struct coda_ctx *ctx = fh_to_ctx(file->private_data);
return v4l2_m2m_mmap(file, ctx->m2m_ctx, vma);
}
static irqreturn_t coda_irq_handler(int irq, void *data)
{
struct vb2_buffer *src_buf, *dst_buf;
struct coda_dev *dev = data;
u32 wr_ptr, start_ptr;
struct coda_ctx *ctx;
cancel_delayed_work(&dev->timeout);
coda_read(dev, CODA_REG_BIT_INT_STATUS);
coda_write(dev, CODA_REG_BIT_INT_CLEAR_SET,
CODA_REG_BIT_INT_CLEAR);
ctx = v4l2_m2m_get_curr_priv(dev->m2m_dev);
if (ctx == NULL) {
v4l2_err(&dev->v4l2_dev, "Instance released before the end of transaction\n");
return IRQ_HANDLED;
}
if (ctx->aborting) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"task has been aborted\n");
return IRQ_HANDLED;
}
if (coda_isbusy(ctx->dev)) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"coda is still busy!!!!\n");
return IRQ_NONE;
}
complete(&dev->done);
src_buf = v4l2_m2m_src_buf_remove(ctx->m2m_ctx);
dst_buf = v4l2_m2m_dst_buf_remove(ctx->m2m_ctx);
coda_read(dev, CODA_RET_ENC_PIC_TYPE);
start_ptr = coda_read(dev, CODA_CMD_ENC_PIC_BB_START);
wr_ptr = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->idx));
if (dst_buf->v4l2_buf.sequence == 0) {
dst_buf->v4l2_planes[0].bytesused = (wr_ptr - start_ptr) +
ctx->vpu_header_size[0] +
ctx->vpu_header_size[1] +
ctx->vpu_header_size[2];
} else {
dst_buf->v4l2_planes[0].bytesused = (wr_ptr - start_ptr);
}
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev, "frame size = %u\n",
wr_ptr - start_ptr);
coda_read(dev, CODA_RET_ENC_PIC_SLICE_NUM);
coda_read(dev, CODA_RET_ENC_PIC_FLAG);
if (src_buf->v4l2_buf.flags & V4L2_BUF_FLAG_KEYFRAME) {
dst_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_KEYFRAME;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_PFRAME;
} else {
dst_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_PFRAME;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_KEYFRAME;
}
dst_buf->v4l2_buf.timestamp = src_buf->v4l2_buf.timestamp;
dst_buf->v4l2_buf.timecode = src_buf->v4l2_buf.timecode;
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_DONE);
v4l2_m2m_buf_done(dst_buf, VB2_BUF_STATE_DONE);
ctx->gopcounter--;
if (ctx->gopcounter < 0)
ctx->gopcounter = ctx->params.gop_size - 1;
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"job finished: encoding frame (%d) (%s)\n",
dst_buf->v4l2_buf.sequence,
(dst_buf->v4l2_buf.flags & V4L2_BUF_FLAG_KEYFRAME) ?
"KEYFRAME" : "PFRAME");
v4l2_m2m_job_finish(ctx->dev->m2m_dev, ctx->m2m_ctx);
return IRQ_HANDLED;
}
static void coda_timeout(struct work_struct *work)
{
struct coda_ctx *ctx;
struct coda_dev *dev = container_of(to_delayed_work(work),
struct coda_dev, timeout);
if (completion_done(&dev->done))
return;
complete(&dev->done);
v4l2_err(&dev->v4l2_dev, "CODA PIC_RUN timeout, stopping all streams\n");
mutex_lock(&dev->dev_mutex);
list_for_each_entry(ctx, &dev->instances, list) {
v4l2_m2m_streamoff(NULL, ctx->m2m_ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
v4l2_m2m_streamoff(NULL, ctx->m2m_ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
}
mutex_unlock(&dev->dev_mutex);
}
static bool coda_firmware_supported(u32 vernum)
{
int i;
for (i = 0; i < ARRAY_SIZE(coda_supported_firmwares); i++)
if (vernum == coda_supported_firmwares[i])
return true;
return false;
}
static char *coda_product_name(int product)
{
static char buf[9];
switch (product) {
case CODA_DX6:
return "CodaDx6";
case CODA_7541:
return "CODA7541";
default:
snprintf(buf, sizeof(buf), "(0x%04x)", product);
return buf;
}
}
static int coda_hw_init(struct coda_dev *dev)
{
u16 product, major, minor, release;
u32 data;
u16 *p;
int i;
clk_prepare_enable(dev->clk_per);
clk_prepare_enable(dev->clk_ahb);
p = (u16 *)dev->codebuf.vaddr;
if (dev->devtype->product == CODA_DX6) {
for (i = 0; i < (CODA_ISRAM_SIZE / 2); i++) {
data = CODA_DOWN_ADDRESS_SET(i) |
CODA_DOWN_DATA_SET(p[i ^ 1]);
coda_write(dev, data, CODA_REG_BIT_CODE_DOWN);
}
} else {
for (i = 0; i < (CODA_ISRAM_SIZE / 2); i++) {
data = CODA_DOWN_ADDRESS_SET(i) |
CODA_DOWN_DATA_SET(p[round_down(i, 4) +
3 - (i % 4)]);
coda_write(dev, data, CODA_REG_BIT_CODE_DOWN);
}
}
coda_write(dev, dev->workbuf.paddr,
CODA_REG_BIT_WORK_BUF_ADDR);
coda_write(dev, dev->codebuf.paddr,
CODA_REG_BIT_CODE_BUF_ADDR);
coda_write(dev, 0, CODA_REG_BIT_CODE_RUN);
switch (dev->devtype->product) {
case CODA_DX6:
coda_write(dev, CODADX6_STREAM_BUF_PIC_FLUSH, CODA_REG_BIT_STREAM_CTRL);
break;
default:
coda_write(dev, CODA7_STREAM_BUF_PIC_FLUSH, CODA_REG_BIT_STREAM_CTRL);
}
coda_write(dev, 0, CODA_REG_BIT_FRAME_MEM_CTRL);
if (dev->devtype->product != CODA_DX6)
coda_write(dev, 0, CODA7_REG_BIT_AXI_SRAM_USE);
coda_write(dev, CODA_INT_INTERRUPT_ENABLE,
CODA_REG_BIT_INT_ENABLE);
data = coda_read(dev, CODA_REG_BIT_CODE_RESET);
data |= CODA_REG_RESET_ENABLE;
coda_write(dev, data, CODA_REG_BIT_CODE_RESET);
udelay(10);
data &= ~CODA_REG_RESET_ENABLE;
coda_write(dev, data, CODA_REG_BIT_CODE_RESET);
coda_write(dev, CODA_REG_RUN_ENABLE, CODA_REG_BIT_CODE_RUN);
coda_write(dev, 0, CODA_CMD_FIRMWARE_VERNUM);
coda_write(dev, CODA_REG_BIT_BUSY_FLAG, CODA_REG_BIT_BUSY);
coda_write(dev, 0, CODA_REG_BIT_RUN_INDEX);
coda_write(dev, 0, CODA_REG_BIT_RUN_COD_STD);
coda_write(dev, CODA_COMMAND_FIRMWARE_GET, CODA_REG_BIT_RUN_COMMAND);
if (coda_wait_timeout(dev)) {
clk_disable_unprepare(dev->clk_per);
clk_disable_unprepare(dev->clk_ahb);
v4l2_err(&dev->v4l2_dev, "firmware get command error\n");
return -EIO;
}
data = coda_read(dev, CODA_CMD_FIRMWARE_VERNUM);
product = CODA_FIRMWARE_PRODUCT(data);
major = CODA_FIRMWARE_MAJOR(data);
minor = CODA_FIRMWARE_MINOR(data);
release = CODA_FIRMWARE_RELEASE(data);
clk_disable_unprepare(dev->clk_per);
clk_disable_unprepare(dev->clk_ahb);
if (product != dev->devtype->product) {
v4l2_err(&dev->v4l2_dev, "Wrong firmware. Hw: %s, Fw: %s,"
" Version: %u.%u.%u\n",
coda_product_name(dev->devtype->product),
coda_product_name(product), major, minor, release);
return -EINVAL;
}
v4l2_info(&dev->v4l2_dev, "Initialized %s.\n",
coda_product_name(product));
if (coda_firmware_supported(data)) {
v4l2_info(&dev->v4l2_dev, "Firmware version: %u.%u.%u\n",
major, minor, release);
} else {
v4l2_warn(&dev->v4l2_dev, "Unsupported firmware version: "
"%u.%u.%u\n", major, minor, release);
}
return 0;
}
static void coda_fw_callback(const struct firmware *fw, void *context)
{
struct coda_dev *dev = context;
struct platform_device *pdev = dev->plat_dev;
int ret;
if (!fw) {
v4l2_err(&dev->v4l2_dev, "firmware request failed\n");
return;
}
dev->codebuf.size = fw->size;
dev->codebuf.vaddr = dma_alloc_coherent(&pdev->dev, fw->size,
&dev->codebuf.paddr,
GFP_KERNEL);
if (!dev->codebuf.vaddr) {
dev_err(&pdev->dev, "failed to allocate code buffer\n");
return;
}
memcpy(dev->codebuf.vaddr, fw->data, fw->size);
release_firmware(fw);
ret = coda_hw_init(dev);
if (ret) {
v4l2_err(&dev->v4l2_dev, "HW initialization failed\n");
return;
}
dev->vfd.fops = &coda_fops,
dev->vfd.ioctl_ops = &coda_ioctl_ops;
dev->vfd.release = video_device_release_empty,
dev->vfd.lock = &dev->dev_mutex;
dev->vfd.v4l2_dev = &dev->v4l2_dev;
dev->vfd.vfl_dir = VFL_DIR_M2M;
snprintf(dev->vfd.name, sizeof(dev->vfd.name), "%s", CODA_NAME);
video_set_drvdata(&dev->vfd, dev);
dev->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(dev->alloc_ctx)) {
v4l2_err(&dev->v4l2_dev, "Failed to alloc vb2 context\n");
return;
}
dev->m2m_dev = v4l2_m2m_init(&coda_m2m_ops);
if (IS_ERR(dev->m2m_dev)) {
v4l2_err(&dev->v4l2_dev, "Failed to init mem2mem device\n");
goto rel_ctx;
}
ret = video_register_device(&dev->vfd, VFL_TYPE_GRABBER, 0);
if (ret) {
v4l2_err(&dev->v4l2_dev, "Failed to register video device\n");
goto rel_m2m;
}
v4l2_info(&dev->v4l2_dev, "codec registered as /dev/video%d\n",
dev->vfd.num);
return;
rel_m2m:
v4l2_m2m_release(dev->m2m_dev);
rel_ctx:
vb2_dma_contig_cleanup_ctx(dev->alloc_ctx);
}
static int coda_firmware_request(struct coda_dev *dev)
{
char *fw = dev->devtype->firmware;
dev_dbg(&dev->plat_dev->dev, "requesting firmware '%s' for %s\n", fw,
coda_product_name(dev->devtype->product));
return request_firmware_nowait(THIS_MODULE, true,
fw, &dev->plat_dev->dev, GFP_KERNEL, dev, coda_fw_callback);
}
static int coda_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(of_match_ptr(coda_dt_ids), &pdev->dev);
const struct platform_device_id *pdev_id;
struct coda_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
struct gen_pool *pool;
struct coda_dev *dev;
struct resource *res;
int ret, irq;
dev = devm_kzalloc(&pdev->dev, sizeof *dev, GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev, "Not enough memory for %s\n",
CODA_NAME);
return -ENOMEM;
}
spin_lock_init(&dev->irqlock);
INIT_LIST_HEAD(&dev->instances);
INIT_DELAYED_WORK(&dev->timeout, coda_timeout);
init_completion(&dev->done);
complete(&dev->done);
dev->plat_dev = pdev;
dev->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(dev->clk_per)) {
dev_err(&pdev->dev, "Could not get per clock\n");
return PTR_ERR(dev->clk_per);
}
dev->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(dev->clk_ahb)) {
dev_err(&pdev->dev, "Could not get ahb clock\n");
return PTR_ERR(dev->clk_ahb);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "failed to get memory region resource\n");
return -ENOENT;
}
if (devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), CODA_NAME) == NULL) {
dev_err(&pdev->dev, "failed to request memory region\n");
return -ENOENT;
}
dev->regs_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!dev->regs_base) {
dev_err(&pdev->dev, "failed to ioremap address region\n");
return -ENOENT;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq resource\n");
return -ENOENT;
}
if (devm_request_irq(&pdev->dev, irq, coda_irq_handler,
0, CODA_NAME, dev) < 0) {
dev_err(&pdev->dev, "failed to request irq\n");
return -ENOENT;
}
pool = of_get_named_gen_pool(np, "iram", 0);
if (!pool && pdata)
pool = dev_get_gen_pool(pdata->iram_dev);
if (!pool) {
dev_err(&pdev->dev, "iram pool not available\n");
return -ENOMEM;
}
dev->iram_pool = pool;
ret = v4l2_device_register(&pdev->dev, &dev->v4l2_dev);
if (ret)
return ret;
mutex_init(&dev->dev_mutex);
pdev_id = of_id ? of_id->data : platform_get_device_id(pdev);
if (of_id) {
dev->devtype = of_id->data;
} else if (pdev_id) {
dev->devtype = &coda_devdata[pdev_id->driver_data];
} else {
v4l2_device_unregister(&dev->v4l2_dev);
return -EINVAL;
}
switch (dev->devtype->product) {
case CODA_DX6:
dev->workbuf.size = CODADX6_WORK_BUF_SIZE;
break;
default:
dev->workbuf.size = CODA7_WORK_BUF_SIZE;
}
dev->workbuf.vaddr = dma_alloc_coherent(&pdev->dev, dev->workbuf.size,
&dev->workbuf.paddr,
GFP_KERNEL);
if (!dev->workbuf.vaddr) {
dev_err(&pdev->dev, "failed to allocate work buffer\n");
v4l2_device_unregister(&dev->v4l2_dev);
return -ENOMEM;
}
if (dev->devtype->product == CODA_DX6)
dev->iram_size = CODADX6_IRAM_SIZE;
else
dev->iram_size = CODA7_IRAM_SIZE;
dev->iram_vaddr = gen_pool_alloc(dev->iram_pool, dev->iram_size);
if (!dev->iram_vaddr) {
dev_err(&pdev->dev, "unable to alloc iram\n");
return -ENOMEM;
}
dev->iram_paddr = gen_pool_virt_to_phys(dev->iram_pool,
dev->iram_vaddr);
platform_set_drvdata(pdev, dev);
return coda_firmware_request(dev);
}
static int coda_remove(struct platform_device *pdev)
{
struct coda_dev *dev = platform_get_drvdata(pdev);
video_unregister_device(&dev->vfd);
if (dev->m2m_dev)
v4l2_m2m_release(dev->m2m_dev);
if (dev->alloc_ctx)
vb2_dma_contig_cleanup_ctx(dev->alloc_ctx);
v4l2_device_unregister(&dev->v4l2_dev);
if (dev->iram_vaddr)
gen_pool_free(dev->iram_pool, dev->iram_vaddr, dev->iram_size);
if (dev->codebuf.vaddr)
dma_free_coherent(&pdev->dev, dev->codebuf.size,
&dev->codebuf.vaddr, dev->codebuf.paddr);
if (dev->workbuf.vaddr)
dma_free_coherent(&pdev->dev, dev->workbuf.size, &dev->workbuf.vaddr,
dev->workbuf.paddr);
return 0;
}
