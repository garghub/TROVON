static struct jpu_buffer *vb2_to_jpu_buffer(struct vb2_v4l2_buffer *vb)
{
struct v4l2_m2m_buffer *b =
container_of(vb, struct v4l2_m2m_buffer, vb);
return container_of(b, struct jpu_buffer, buf);
}
static u32 jpu_read(struct jpu *jpu, unsigned int reg)
{
return ioread32(jpu->regs + reg);
}
static void jpu_write(struct jpu *jpu, u32 val, unsigned int reg)
{
iowrite32(val, jpu->regs + reg);
}
static struct jpu_ctx *ctrl_to_ctx(struct v4l2_ctrl *c)
{
return container_of(c->handler, struct jpu_ctx, ctrl_handler);
}
static struct jpu_ctx *fh_to_ctx(struct v4l2_fh *fh)
{
return container_of(fh, struct jpu_ctx, fh);
}
static void jpu_set_tbl(struct jpu *jpu, u32 reg, const unsigned int *tbl,
unsigned int len) {
unsigned int i;
for (i = 0; i < len; i++)
jpu_write(jpu, tbl[i], reg + (i << 2));
}
static void jpu_set_qtbl(struct jpu *jpu, unsigned short quality)
{
jpu_set_tbl(jpu, JCQTBL(0), qtbl_lum[quality], QTBL_SIZE);
jpu_set_tbl(jpu, JCQTBL(1), qtbl_chr[quality], QTBL_SIZE);
}
static void jpu_set_htbl(struct jpu *jpu)
{
jpu_set_tbl(jpu, JCHTBD(0), hdctbl_lum, HDCTBL_SIZE);
jpu_set_tbl(jpu, JCHTBA(0), hactbl_lum, HACTBL_SIZE);
jpu_set_tbl(jpu, JCHTBD(1), hdctbl_chr, HDCTBL_SIZE);
jpu_set_tbl(jpu, JCHTBA(1), hactbl_chr, HACTBL_SIZE);
}
static int jpu_wait_reset(struct jpu *jpu)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(JPU_RESET_TIMEOUT);
while (jpu_read(jpu, JCCMD) & JCCMD_SRST) {
if (time_after(jiffies, timeout)) {
dev_err(jpu->dev, "timed out in reset\n");
return -ETIMEDOUT;
}
schedule();
}
return 0;
}
static int jpu_reset(struct jpu *jpu)
{
jpu_write(jpu, JCCMD_SRST, JCCMD);
return jpu_wait_reset(jpu);
}
static void put_qtbl(u8 *p, const u8 *qtbl)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(zigzag); i++)
p[i] = *(qtbl + zigzag[i]);
}
static void put_htbl(u8 *p, const u8 *htbl, unsigned int len)
{
unsigned int i, j;
for (i = 0; i < len; i += 4)
for (j = 0; j < 4 && (i + j) < len; ++j)
p[i + j] = htbl[i + 3 - j];
}
static void jpu_generate_hdr(unsigned short quality, unsigned char *p)
{
put_qtbl(p + JPU_JPEG_QTBL_LUM_OFFSET, (const u8 *)qtbl_lum[quality]);
put_qtbl(p + JPU_JPEG_QTBL_CHR_OFFSET, (const u8 *)qtbl_chr[quality]);
put_htbl(p + JPU_JPEG_HDCTBL_LUM_OFFSET, (const u8 *)hdctbl_lum,
JPU_JPEG_HDCTBL_SIZE);
put_htbl(p + JPU_JPEG_HACTBL_LUM_OFFSET, (const u8 *)hactbl_lum,
JPU_JPEG_HACTBL_SIZE);
put_htbl(p + JPU_JPEG_HDCTBL_CHR_OFFSET, (const u8 *)hdctbl_chr,
JPU_JPEG_HDCTBL_SIZE);
put_htbl(p + JPU_JPEG_HACTBL_CHR_OFFSET, (const u8 *)hactbl_chr,
JPU_JPEG_HACTBL_SIZE);
}
static int get_byte(struct jpeg_buffer *buf)
{
if (buf->curr >= buf->end)
return -1;
return *(u8 *)buf->curr++;
}
static int get_word_be(struct jpeg_buffer *buf, unsigned int *word)
{
if (buf->end - buf->curr < 2)
return -1;
*word = get_unaligned_be16(buf->curr);
buf->curr += 2;
return 0;
}
static void skip(struct jpeg_buffer *buf, unsigned long len)
{
buf->curr += min((unsigned long)(buf->end - buf->curr), len);
}
static u8 jpu_parse_hdr(void *buffer, unsigned long size, unsigned int *width,
unsigned int *height)
{
struct jpeg_buffer jpeg_buffer;
unsigned int word;
bool soi = false;
jpeg_buffer.end = buffer + size;
jpeg_buffer.curr = buffer;
if (size < JPU_JPEG_MIN_SIZE || *(u8 *)(buffer + size - 1) != EOI)
return 0;
for (;;) {
int c;
do
c = get_byte(&jpeg_buffer);
while (c == 0xff || c == 0);
if (!soi && c == SOI) {
soi = true;
continue;
} else if (soi != (c != SOI))
return 0;
switch (c) {
case SOF0:
skip(&jpeg_buffer, 3);
if (get_word_be(&jpeg_buffer, height) ||
get_word_be(&jpeg_buffer, width) ||
get_byte(&jpeg_buffer) != 3)
return 0;
skip(&jpeg_buffer, 1);
return get_byte(&jpeg_buffer);
case DHT:
case DQT:
case COM:
case DRI:
case APP0 ... APP0 + 0x0f:
if (get_word_be(&jpeg_buffer, &word))
return 0;
skip(&jpeg_buffer, (long)word - 2);
case 0:
break;
default:
return 0;
}
}
return 0;
}
static int jpu_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct jpu_ctx *ctx = fh_to_ctx(priv);
if (ctx->encoder)
strlcpy(cap->card, DRV_NAME " encoder", sizeof(cap->card));
else
strlcpy(cap->card, DRV_NAME " decoder", sizeof(cap->card));
strlcpy(cap->driver, DRV_NAME, sizeof(cap->driver));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(ctx->jpu->dev));
cap->device_caps |= V4L2_CAP_STREAMING | V4L2_CAP_VIDEO_M2M_MPLANE;
cap->capabilities = V4L2_CAP_DEVICE_CAPS | cap->device_caps;
memset(cap->reserved, 0, sizeof(cap->reserved));
return 0;
}
static struct jpu_fmt *jpu_find_format(bool encoder, u32 pixelformat,
unsigned int fmt_type)
{
unsigned int i, fmt_flag;
if (encoder)
fmt_flag = fmt_type == JPU_FMT_TYPE_OUTPUT ? JPU_ENC_OUTPUT :
JPU_ENC_CAPTURE;
else
fmt_flag = fmt_type == JPU_FMT_TYPE_OUTPUT ? JPU_DEC_OUTPUT :
JPU_DEC_CAPTURE;
for (i = 0; i < ARRAY_SIZE(jpu_formats); i++) {
struct jpu_fmt *fmt = &jpu_formats[i];
if (fmt->fourcc == pixelformat && fmt->types & fmt_flag)
return fmt;
}
return NULL;
}
static int jpu_enum_fmt(struct v4l2_fmtdesc *f, u32 type)
{
unsigned int i, num = 0;
for (i = 0; i < ARRAY_SIZE(jpu_formats); ++i) {
if (jpu_formats[i].types & type) {
if (num == f->index)
break;
++num;
}
}
if (i >= ARRAY_SIZE(jpu_formats))
return -EINVAL;
f->pixelformat = jpu_formats[i].fourcc;
return 0;
}
static int jpu_enum_fmt_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct jpu_ctx *ctx = fh_to_ctx(priv);
return jpu_enum_fmt(f, ctx->encoder ? JPU_ENC_CAPTURE :
JPU_DEC_CAPTURE);
}
static int jpu_enum_fmt_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct jpu_ctx *ctx = fh_to_ctx(priv);
return jpu_enum_fmt(f, ctx->encoder ? JPU_ENC_OUTPUT : JPU_DEC_OUTPUT);
}
static struct jpu_q_data *jpu_get_q_data(struct jpu_ctx *ctx,
enum v4l2_buf_type type)
{
if (V4L2_TYPE_IS_OUTPUT(type))
return &ctx->out_q;
else
return &ctx->cap_q;
}
static void jpu_bound_align_image(u32 *w, unsigned int w_min,
unsigned int w_max, unsigned int w_align,
u32 *h, unsigned int h_min,
unsigned int h_max, unsigned int h_align)
{
unsigned int width, height, w_step, h_step;
width = *w;
height = *h;
w_step = 1U << w_align;
h_step = 1U << h_align;
v4l_bound_align_image(w, w_min, w_max, w_align, h, h_min, h_max,
h_align, 3);
if (*w < width && *w + w_step < w_max)
*w += w_step;
if (*h < height && *h + h_step < h_max)
*h += h_step;
}
static int __jpu_try_fmt(struct jpu_ctx *ctx, struct jpu_fmt **fmtinfo,
struct v4l2_pix_format_mplane *pix,
enum v4l2_buf_type type)
{
struct jpu_fmt *fmt;
unsigned int f_type, w, h;
f_type = V4L2_TYPE_IS_OUTPUT(type) ? JPU_FMT_TYPE_OUTPUT :
JPU_FMT_TYPE_CAPTURE;
fmt = jpu_find_format(ctx->encoder, pix->pixelformat, f_type);
if (!fmt) {
unsigned int pixelformat;
dev_dbg(ctx->jpu->dev, "unknown format; set default format\n");
if (ctx->encoder)
pixelformat = f_type == JPU_FMT_TYPE_OUTPUT ?
V4L2_PIX_FMT_NV16M : V4L2_PIX_FMT_JPEG;
else
pixelformat = f_type == JPU_FMT_TYPE_CAPTURE ?
V4L2_PIX_FMT_NV16M : V4L2_PIX_FMT_JPEG;
fmt = jpu_find_format(ctx->encoder, pixelformat, f_type);
}
pix->pixelformat = fmt->fourcc;
pix->colorspace = fmt->colorspace;
pix->field = V4L2_FIELD_NONE;
pix->num_planes = fmt->num_planes;
memset(pix->reserved, 0, sizeof(pix->reserved));
jpu_bound_align_image(&pix->width, JPU_WIDTH_MIN, JPU_WIDTH_MAX,
fmt->h_align, &pix->height, JPU_HEIGHT_MIN,
JPU_HEIGHT_MAX, fmt->v_align);
w = pix->width;
h = pix->height;
if (fmt->fourcc == V4L2_PIX_FMT_JPEG) {
if (pix->plane_fmt[0].sizeimage <= 0 || ctx->encoder)
pix->plane_fmt[0].sizeimage = JPU_JPEG_HDR_SIZE +
(JPU_JPEG_MAX_BYTES_PER_PIXEL * w * h);
pix->plane_fmt[0].bytesperline = 0;
memset(pix->plane_fmt[0].reserved, 0,
sizeof(pix->plane_fmt[0].reserved));
} else {
unsigned int i, bpl = 0;
for (i = 0; i < pix->num_planes; ++i)
bpl = max(bpl, pix->plane_fmt[i].bytesperline);
bpl = clamp_t(unsigned int, bpl, w, JPU_WIDTH_MAX);
bpl = round_up(bpl, JPU_MEMALIGN);
for (i = 0; i < pix->num_planes; ++i) {
pix->plane_fmt[i].bytesperline = bpl;
pix->plane_fmt[i].sizeimage = bpl * h * fmt->bpp[i] / 8;
memset(pix->plane_fmt[i].reserved, 0,
sizeof(pix->plane_fmt[i].reserved));
}
}
if (fmtinfo)
*fmtinfo = fmt;
return 0;
}
static int jpu_try_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct jpu_ctx *ctx = fh_to_ctx(priv);
if (!v4l2_m2m_get_vq(ctx->fh.m2m_ctx, f->type))
return -EINVAL;
return __jpu_try_fmt(ctx, NULL, &f->fmt.pix_mp, f->type);
}
static int jpu_s_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct jpu_ctx *ctx = fh_to_ctx(priv);
struct v4l2_m2m_ctx *m2m_ctx = ctx->fh.m2m_ctx;
struct jpu_fmt *fmtinfo;
struct jpu_q_data *q_data;
int ret;
vq = v4l2_m2m_get_vq(m2m_ctx, f->type);
if (!vq)
return -EINVAL;
if (vb2_is_busy(vq)) {
v4l2_err(&ctx->jpu->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
ret = __jpu_try_fmt(ctx, &fmtinfo, &f->fmt.pix_mp, f->type);
if (ret < 0)
return ret;
q_data = jpu_get_q_data(ctx, f->type);
q_data->format = f->fmt.pix_mp;
q_data->fmtinfo = fmtinfo;
return 0;
}
static int jpu_g_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct jpu_q_data *q_data;
struct jpu_ctx *ctx = fh_to_ctx(priv);
if (!v4l2_m2m_get_vq(ctx->fh.m2m_ctx, f->type))
return -EINVAL;
q_data = jpu_get_q_data(ctx, f->type);
f->fmt.pix_mp = q_data->format;
return 0;
}
static int jpu_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct jpu_ctx *ctx = ctrl_to_ctx(ctrl);
unsigned long flags;
spin_lock_irqsave(&ctx->jpu->lock, flags);
if (ctrl->id == V4L2_CID_JPEG_COMPRESSION_QUALITY)
ctx->compr_quality = ctrl->val;
spin_unlock_irqrestore(&ctx->jpu->lock, flags);
return 0;
}
static int jpu_streamon(struct file *file, void *priv, enum v4l2_buf_type type)
{
struct jpu_ctx *ctx = fh_to_ctx(priv);
struct jpu_q_data *src_q_data, *dst_q_data, *orig, adj, *ref;
enum v4l2_buf_type adj_type;
src_q_data = jpu_get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE);
dst_q_data = jpu_get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE);
if (ctx->encoder) {
adj = *src_q_data;
orig = src_q_data;
ref = dst_q_data;
adj_type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
} else {
adj = *dst_q_data;
orig = dst_q_data;
ref = src_q_data;
adj_type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
}
adj.format.width = ref->format.width;
adj.format.height = ref->format.height;
__jpu_try_fmt(ctx, NULL, &adj.format, adj_type);
if (adj.format.width != orig->format.width ||
adj.format.height != orig->format.height) {
dev_err(ctx->jpu->dev, "src and dst formats do not match.\n");
return -EINVAL;
}
return v4l2_m2m_streamon(file, ctx->fh.m2m_ctx, type);
}
static int jpu_controls_create(struct jpu_ctx *ctx)
{
struct v4l2_ctrl *ctrl;
int ret;
v4l2_ctrl_handler_init(&ctx->ctrl_handler, 1);
ctrl = v4l2_ctrl_new_std(&ctx->ctrl_handler, &jpu_ctrl_ops,
V4L2_CID_JPEG_COMPRESSION_QUALITY,
0, JPU_MAX_QUALITY - 1, 1, 0);
if (ctx->ctrl_handler.error) {
ret = ctx->ctrl_handler.error;
goto error_free;
}
if (!ctx->encoder)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY;
ret = v4l2_ctrl_handler_setup(&ctx->ctrl_handler);
if (ret < 0)
goto error_free;
return 0;
error_free:
v4l2_ctrl_handler_free(&ctx->ctrl_handler);
return ret;
}
static int jpu_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct jpu_ctx *ctx = vb2_get_drv_priv(vq);
struct jpu_q_data *q_data;
unsigned int i;
q_data = jpu_get_q_data(ctx, vq->type);
if (*nplanes) {
if (*nplanes != q_data->format.num_planes)
return -EINVAL;
for (i = 0; i < *nplanes; i++) {
unsigned int q_size = q_data->format.plane_fmt[i].sizeimage;
if (sizes[i] < q_size)
return -EINVAL;
alloc_ctxs[i] = ctx->jpu->alloc_ctx;
}
return 0;
}
*nplanes = q_data->format.num_planes;
for (i = 0; i < *nplanes; i++) {
sizes[i] = q_data->format.plane_fmt[i].sizeimage;
alloc_ctxs[i] = ctx->jpu->alloc_ctx;
}
return 0;
}
static int jpu_buf_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct jpu_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct jpu_q_data *q_data;
unsigned int i;
q_data = jpu_get_q_data(ctx, vb->vb2_queue->type);
if (V4L2_TYPE_IS_OUTPUT(vb->vb2_queue->type)) {
if (vbuf->field == V4L2_FIELD_ANY)
vbuf->field = V4L2_FIELD_NONE;
if (vbuf->field != V4L2_FIELD_NONE) {
dev_err(ctx->jpu->dev, "%s field isn't supported\n",
__func__);
return -EINVAL;
}
}
for (i = 0; i < q_data->format.num_planes; i++) {
unsigned long size = q_data->format.plane_fmt[i].sizeimage;
if (vb2_plane_size(vb, i) < size) {
dev_err(ctx->jpu->dev,
"%s: data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, i), size);
return -EINVAL;
}
if (!ctx->encoder && !V4L2_TYPE_IS_OUTPUT(vb->vb2_queue->type))
vb2_set_plane_payload(vb, i, size);
}
return 0;
}
static void jpu_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct jpu_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
if (!ctx->encoder && V4L2_TYPE_IS_OUTPUT(vb->vb2_queue->type)) {
struct jpu_buffer *jpu_buf = vb2_to_jpu_buffer(vbuf);
struct jpu_q_data *q_data, adjust;
void *buffer = vb2_plane_vaddr(vb, 0);
unsigned long buf_size = vb2_get_plane_payload(vb, 0);
unsigned int width, height;
u8 subsampling = jpu_parse_hdr(buffer, buf_size, &width,
&height);
if (subsampling != JPU_JPEG_422 && subsampling != JPU_JPEG_420)
goto format_error;
q_data = &ctx->out_q;
adjust = *q_data;
adjust.format.width = width;
adjust.format.height = height;
__jpu_try_fmt(ctx, &adjust.fmtinfo, &adjust.format,
V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE);
if (adjust.format.width != q_data->format.width ||
adjust.format.height != q_data->format.height)
goto format_error;
jpu_buf->subsampling = subsampling;
}
if (ctx->fh.m2m_ctx)
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vbuf);
return;
format_error:
dev_err(ctx->jpu->dev, "incompatible or corrupted JPEG data\n");
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
static void jpu_buf_finish(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct jpu_buffer *jpu_buf = vb2_to_jpu_buffer(vbuf);
struct jpu_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct jpu_q_data *q_data = &ctx->out_q;
enum v4l2_buf_type type = vb->vb2_queue->type;
u8 *buffer;
if (vb->state == VB2_BUF_STATE_DONE)
vbuf->sequence = jpu_get_q_data(ctx, type)->sequence++;
if (!ctx->encoder || vb->state != VB2_BUF_STATE_DONE ||
V4L2_TYPE_IS_OUTPUT(type))
return;
buffer = vb2_plane_vaddr(vb, 0);
memcpy(buffer, jpeg_hdrs[jpu_buf->compr_quality], JPU_JPEG_HDR_SIZE);
*(__be16 *)(buffer + JPU_JPEG_HEIGHT_OFFSET) =
cpu_to_be16(q_data->format.height);
*(__be16 *)(buffer + JPU_JPEG_WIDTH_OFFSET) =
cpu_to_be16(q_data->format.width);
*(buffer + JPU_JPEG_SUBS_OFFSET) = q_data->fmtinfo->subsampling;
}
static int jpu_start_streaming(struct vb2_queue *vq, unsigned count)
{
struct jpu_ctx *ctx = vb2_get_drv_priv(vq);
struct jpu_q_data *q_data = jpu_get_q_data(ctx, vq->type);
q_data->sequence = 0;
return 0;
}
static void jpu_stop_streaming(struct vb2_queue *vq)
{
struct jpu_ctx *ctx = vb2_get_drv_priv(vq);
struct vb2_v4l2_buffer *vb;
unsigned long flags;
for (;;) {
if (V4L2_TYPE_IS_OUTPUT(vq->type))
vb = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
else
vb = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
if (vb == NULL)
return;
spin_lock_irqsave(&ctx->jpu->lock, flags);
v4l2_m2m_buf_done(vb, VB2_BUF_STATE_ERROR);
spin_unlock_irqrestore(&ctx->jpu->lock, flags);
}
}
static int jpu_queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct jpu_ctx *ctx = priv;
int ret;
memset(src_vq, 0, sizeof(*src_vq));
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
src_vq->io_modes = VB2_MMAP | VB2_DMABUF;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct jpu_buffer);
src_vq->ops = &jpu_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
src_vq->lock = &ctx->jpu->mutex;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
memset(dst_vq, 0, sizeof(*dst_vq));
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
dst_vq->io_modes = VB2_MMAP | VB2_DMABUF;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct jpu_buffer);
dst_vq->ops = &jpu_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
dst_vq->lock = &ctx->jpu->mutex;
return vb2_queue_init(dst_vq);
}
static int jpu_open(struct file *file)
{
struct jpu *jpu = video_drvdata(file);
struct video_device *vfd = video_devdata(file);
struct jpu_ctx *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
v4l2_fh_init(&ctx->fh, vfd);
ctx->fh.ctrl_handler = &ctx->ctrl_handler;
file->private_data = &ctx->fh;
v4l2_fh_add(&ctx->fh);
ctx->jpu = jpu;
ctx->encoder = vfd == &jpu->vfd_encoder;
__jpu_try_fmt(ctx, &ctx->out_q.fmtinfo, &ctx->out_q.format,
V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE);
__jpu_try_fmt(ctx, &ctx->cap_q.fmtinfo, &ctx->cap_q.format,
V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE);
ctx->fh.m2m_ctx = v4l2_m2m_ctx_init(jpu->m2m_dev, ctx, jpu_queue_init);
if (IS_ERR(ctx->fh.m2m_ctx)) {
ret = PTR_ERR(ctx->fh.m2m_ctx);
goto v4l_prepare_rollback;
}
ret = jpu_controls_create(ctx);
if (ret < 0)
goto v4l_prepare_rollback;
if (mutex_lock_interruptible(&jpu->mutex)) {
ret = -ERESTARTSYS;
goto v4l_prepare_rollback;
}
if (jpu->ref_count == 0) {
ret = clk_prepare_enable(jpu->clk);
if (ret < 0)
goto device_prepare_rollback;
ret = jpu_reset(jpu);
if (ret)
goto device_prepare_rollback;
}
jpu->ref_count++;
mutex_unlock(&jpu->mutex);
return 0;
device_prepare_rollback:
mutex_unlock(&jpu->mutex);
v4l_prepare_rollback:
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
kfree(ctx);
return ret;
}
static int jpu_release(struct file *file)
{
struct jpu *jpu = video_drvdata(file);
struct jpu_ctx *ctx = fh_to_ctx(file->private_data);
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
v4l2_ctrl_handler_free(&ctx->ctrl_handler);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
kfree(ctx);
mutex_lock(&jpu->mutex);
if (--jpu->ref_count == 0)
clk_disable_unprepare(jpu->clk);
mutex_unlock(&jpu->mutex);
return 0;
}
static void jpu_cleanup(struct jpu_ctx *ctx, bool reset)
{
struct vb2_v4l2_buffer *src_buf, *dst_buf;
unsigned long flags;
spin_lock_irqsave(&ctx->jpu->lock, flags);
src_buf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_ERROR);
v4l2_m2m_buf_done(dst_buf, VB2_BUF_STATE_ERROR);
if (reset)
jpu_write(ctx->jpu, JCCMD_SRST, JCCMD);
spin_unlock_irqrestore(&ctx->jpu->lock, flags);
v4l2_m2m_job_finish(ctx->jpu->m2m_dev, ctx->fh.m2m_ctx);
}
static void jpu_device_run(void *priv)
{
struct jpu_ctx *ctx = priv;
struct jpu *jpu = ctx->jpu;
struct jpu_buffer *jpu_buf;
struct jpu_q_data *q_data;
struct vb2_v4l2_buffer *src_buf, *dst_buf;
unsigned int w, h, bpl;
unsigned char num_planes, subsampling;
unsigned long flags;
if (jpu_wait_reset(jpu)) {
jpu_cleanup(ctx, true);
return;
}
spin_lock_irqsave(&ctx->jpu->lock, flags);
jpu->curr = ctx;
src_buf = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
if (ctx->encoder) {
jpu_buf = vb2_to_jpu_buffer(dst_buf);
q_data = &ctx->out_q;
} else {
jpu_buf = vb2_to_jpu_buffer(src_buf);
q_data = &ctx->cap_q;
}
w = q_data->format.width;
h = q_data->format.height;
bpl = q_data->format.plane_fmt[0].bytesperline;
num_planes = q_data->fmtinfo->num_planes;
subsampling = q_data->fmtinfo->subsampling;
if (ctx->encoder) {
unsigned long src_1_addr, src_2_addr, dst_addr;
unsigned int redu, inft;
dst_addr = vb2_dma_contig_plane_dma_addr(&dst_buf->vb2_buf, 0);
src_1_addr =
vb2_dma_contig_plane_dma_addr(&src_buf->vb2_buf, 0);
if (num_planes > 1)
src_2_addr = vb2_dma_contig_plane_dma_addr(
&src_buf->vb2_buf, 1);
else
src_2_addr = src_1_addr + w * h;
jpu_buf->compr_quality = ctx->compr_quality;
if (subsampling == JPU_JPEG_420) {
redu = JCMOD_REDU_420;
inft = JIFECNT_INFT_420;
} else {
redu = JCMOD_REDU_422;
inft = JIFECNT_INFT_422;
}
jpu_write(jpu, JCMOD_DSP_ENC | JCMOD_PCTR | redu |
JCMOD_MSKIP_ENABLE, JCMOD);
jpu_write(jpu, JIFECNT_SWAP_WB | inft, JIFECNT);
jpu_write(jpu, JIFDCNT_SWAP_WB, JIFDCNT);
jpu_write(jpu, JINTE_TRANSF_COMPL, JINTE);
jpu_write(jpu, src_1_addr, JIFESYA1);
jpu_write(jpu, src_2_addr, JIFESCA1);
jpu_write(jpu, bpl, JIFESMW);
jpu_write(jpu, (w >> 8) & JCSZ_MASK, JCHSZU);
jpu_write(jpu, w & JCSZ_MASK, JCHSZD);
jpu_write(jpu, (h >> 8) & JCSZ_MASK, JCVSZU);
jpu_write(jpu, h & JCSZ_MASK, JCVSZD);
jpu_write(jpu, w, JIFESHSZ);
jpu_write(jpu, h, JIFESVSZ);
jpu_write(jpu, dst_addr + JPU_JPEG_HDR_SIZE, JIFEDA1);
jpu_write(jpu, 0 << JCQTN_SHIFT(1) | 1 << JCQTN_SHIFT(2) |
1 << JCQTN_SHIFT(3), JCQTN);
jpu_write(jpu, 0 << JCHTN_AC_SHIFT(1) | 0 << JCHTN_DC_SHIFT(1) |
1 << JCHTN_AC_SHIFT(2) | 1 << JCHTN_DC_SHIFT(2) |
1 << JCHTN_AC_SHIFT(3) | 1 << JCHTN_DC_SHIFT(3),
JCHTN);
jpu_set_qtbl(jpu, ctx->compr_quality);
jpu_set_htbl(jpu);
} else {
unsigned long src_addr, dst_1_addr, dst_2_addr;
if (jpu_buf->subsampling != subsampling) {
dev_err(ctx->jpu->dev,
"src and dst formats do not match.\n");
spin_unlock_irqrestore(&ctx->jpu->lock, flags);
jpu_cleanup(ctx, false);
return;
}
src_addr = vb2_dma_contig_plane_dma_addr(&src_buf->vb2_buf, 0);
dst_1_addr =
vb2_dma_contig_plane_dma_addr(&dst_buf->vb2_buf, 0);
if (q_data->fmtinfo->num_planes > 1)
dst_2_addr = vb2_dma_contig_plane_dma_addr(
&dst_buf->vb2_buf, 1);
else
dst_2_addr = dst_1_addr + w * h;
jpu_write(jpu, JCMOD_DSP_DEC | JCMOD_PCTR, JCMOD);
jpu_write(jpu, JIFECNT_SWAP_WB, JIFECNT);
jpu_write(jpu, JIFDCNT_SWAP_WB, JIFDCNT);
jpu_write(jpu, JINTE_TRANSF_COMPL | JINTE_ERR, JINTE);
jpu_write(jpu, src_addr, JIFDSA1);
jpu_write(jpu, dst_1_addr, JIFDDYA1);
jpu_write(jpu, dst_2_addr, JIFDDCA1);
jpu_write(jpu, bpl, JIFDDMW);
}
jpu_write(jpu, JCCMD_JSRT, JCCMD);
spin_unlock_irqrestore(&ctx->jpu->lock, flags);
}
static int jpu_job_ready(void *priv)
{
return 1;
}
static void jpu_job_abort(void *priv)
{
struct jpu_ctx *ctx = priv;
if (!wait_event_timeout(ctx->jpu->irq_queue, !ctx->jpu->curr,
msecs_to_jiffies(JPU_JOB_TIMEOUT)))
jpu_cleanup(ctx, true);
}
static irqreturn_t jpu_irq_handler(int irq, void *dev_id)
{
struct jpu *jpu = dev_id;
struct jpu_ctx *curr_ctx;
struct vb2_v4l2_buffer *src_buf, *dst_buf;
unsigned int int_status;
int_status = jpu_read(jpu, JINTS);
if (!((JINTS_TRANSF_COMPL | JINTS_PROCESS_COMPL | JINTS_ERR) &
int_status))
return IRQ_NONE;
jpu_write(jpu, ~(int_status & JINTS_MASK), JINTS);
if (int_status & (JINTS_ERR | JINTS_PROCESS_COMPL))
jpu_write(jpu, JCCMD_JEND, JCCMD);
spin_lock(&jpu->lock);
if ((int_status & JINTS_PROCESS_COMPL) &&
!(int_status & JINTS_TRANSF_COMPL))
goto handled;
curr_ctx = v4l2_m2m_get_curr_priv(jpu->m2m_dev);
if (!curr_ctx) {
dev_err(jpu->dev, "no active context for m2m\n");
goto handled;
}
src_buf = v4l2_m2m_src_buf_remove(curr_ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_dst_buf_remove(curr_ctx->fh.m2m_ctx);
if (int_status & JINTS_TRANSF_COMPL) {
if (curr_ctx->encoder) {
unsigned long payload_size = jpu_read(jpu, JCDTCU) << 16
| jpu_read(jpu, JCDTCM) << 8
| jpu_read(jpu, JCDTCD);
vb2_set_plane_payload(&dst_buf->vb2_buf, 0,
payload_size + JPU_JPEG_HDR_SIZE);
}
dst_buf->field = src_buf->field;
dst_buf->vb2_buf.timestamp = src_buf->vb2_buf.timestamp;
if (src_buf->flags & V4L2_BUF_FLAG_TIMECODE)
dst_buf->timecode = src_buf->timecode;
dst_buf->flags = src_buf->flags &
(V4L2_BUF_FLAG_TIMECODE | V4L2_BUF_FLAG_KEYFRAME |
V4L2_BUF_FLAG_PFRAME | V4L2_BUF_FLAG_BFRAME |
V4L2_BUF_FLAG_TSTAMP_SRC_MASK);
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_DONE);
v4l2_m2m_buf_done(dst_buf, VB2_BUF_STATE_DONE);
} else if (int_status & JINTS_ERR) {
unsigned char error = jpu_read(jpu, JCDERR) & JCDERR_MASK;
dev_dbg(jpu->dev, "processing error: %#X: %s\n", error,
error_to_text[error]);
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_ERROR);
v4l2_m2m_buf_done(dst_buf, VB2_BUF_STATE_ERROR);
}
jpu->curr = NULL;
jpu_write(jpu, JCCMD_SRST, JCCMD);
spin_unlock(&jpu->lock);
v4l2_m2m_job_finish(jpu->m2m_dev, curr_ctx->fh.m2m_ctx);
wake_up(&jpu->irq_queue);
return IRQ_HANDLED;
handled:
spin_unlock(&jpu->lock);
return IRQ_HANDLED;
}
static int jpu_probe(struct platform_device *pdev)
{
struct jpu *jpu;
struct resource *res;
int ret;
unsigned int i;
jpu = devm_kzalloc(&pdev->dev, sizeof(*jpu), GFP_KERNEL);
if (!jpu)
return -ENOMEM;
init_waitqueue_head(&jpu->irq_queue);
mutex_init(&jpu->mutex);
spin_lock_init(&jpu->lock);
jpu->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
jpu->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(jpu->regs))
return PTR_ERR(jpu->regs);
jpu->irq = ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "cannot find IRQ\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, jpu->irq, jpu_irq_handler, 0,
dev_name(&pdev->dev), jpu);
if (ret) {
dev_err(&pdev->dev, "cannot claim IRQ %d\n", jpu->irq);
return ret;
}
jpu->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(jpu->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(jpu->clk);
}
ret = v4l2_device_register(&pdev->dev, &jpu->v4l2_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to register v4l2 device\n");
return ret;
}
jpu->m2m_dev = v4l2_m2m_init(&jpu_m2m_ops);
if (IS_ERR(jpu->m2m_dev)) {
v4l2_err(&jpu->v4l2_dev, "Failed to init mem2mem device\n");
ret = PTR_ERR(jpu->m2m_dev);
goto device_register_rollback;
}
jpu->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(jpu->alloc_ctx)) {
v4l2_err(&jpu->v4l2_dev, "Failed to init memory allocator\n");
ret = PTR_ERR(jpu->alloc_ctx);
goto m2m_init_rollback;
}
for (i = 0; i < JPU_MAX_QUALITY; i++)
jpu_generate_hdr(i, (unsigned char *)jpeg_hdrs[i]);
strlcpy(jpu->vfd_encoder.name, DRV_NAME, sizeof(jpu->vfd_encoder.name));
jpu->vfd_encoder.fops = &jpu_fops;
jpu->vfd_encoder.ioctl_ops = &jpu_ioctl_ops;
jpu->vfd_encoder.minor = -1;
jpu->vfd_encoder.release = video_device_release_empty;
jpu->vfd_encoder.lock = &jpu->mutex;
jpu->vfd_encoder.v4l2_dev = &jpu->v4l2_dev;
jpu->vfd_encoder.vfl_dir = VFL_DIR_M2M;
ret = video_register_device(&jpu->vfd_encoder, VFL_TYPE_GRABBER, -1);
if (ret) {
v4l2_err(&jpu->v4l2_dev, "Failed to register video device\n");
goto vb2_allocator_rollback;
}
video_set_drvdata(&jpu->vfd_encoder, jpu);
strlcpy(jpu->vfd_decoder.name, DRV_NAME, sizeof(jpu->vfd_decoder.name));
jpu->vfd_decoder.fops = &jpu_fops;
jpu->vfd_decoder.ioctl_ops = &jpu_ioctl_ops;
jpu->vfd_decoder.minor = -1;
jpu->vfd_decoder.release = video_device_release_empty;
jpu->vfd_decoder.lock = &jpu->mutex;
jpu->vfd_decoder.v4l2_dev = &jpu->v4l2_dev;
jpu->vfd_decoder.vfl_dir = VFL_DIR_M2M;
ret = video_register_device(&jpu->vfd_decoder, VFL_TYPE_GRABBER, -1);
if (ret) {
v4l2_err(&jpu->v4l2_dev, "Failed to register video device\n");
goto enc_vdev_register_rollback;
}
video_set_drvdata(&jpu->vfd_decoder, jpu);
platform_set_drvdata(pdev, jpu);
v4l2_info(&jpu->v4l2_dev, "encoder device registered as /dev/video%d\n",
jpu->vfd_encoder.num);
v4l2_info(&jpu->v4l2_dev, "decoder device registered as /dev/video%d\n",
jpu->vfd_decoder.num);
return 0;
enc_vdev_register_rollback:
video_unregister_device(&jpu->vfd_encoder);
vb2_allocator_rollback:
vb2_dma_contig_cleanup_ctx(jpu->alloc_ctx);
m2m_init_rollback:
v4l2_m2m_release(jpu->m2m_dev);
device_register_rollback:
v4l2_device_unregister(&jpu->v4l2_dev);
return ret;
}
static int jpu_remove(struct platform_device *pdev)
{
struct jpu *jpu = platform_get_drvdata(pdev);
video_unregister_device(&jpu->vfd_decoder);
video_unregister_device(&jpu->vfd_encoder);
vb2_dma_contig_cleanup_ctx(jpu->alloc_ctx);
v4l2_m2m_release(jpu->m2m_dev);
v4l2_device_unregister(&jpu->v4l2_dev);
return 0;
}
static int jpu_suspend(struct device *dev)
{
struct jpu *jpu = dev_get_drvdata(dev);
if (jpu->ref_count == 0)
return 0;
clk_disable_unprepare(jpu->clk);
return 0;
}
static int jpu_resume(struct device *dev)
{
struct jpu *jpu = dev_get_drvdata(dev);
if (jpu->ref_count == 0)
return 0;
clk_prepare_enable(jpu->clk);
return 0;
}
