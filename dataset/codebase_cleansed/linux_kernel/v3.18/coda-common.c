void coda_write(struct coda_dev *dev, u32 data, u32 reg)
{
v4l2_dbg(2, coda_debug, &dev->v4l2_dev,
"%s: data=0x%x, reg=0x%x\n", __func__, data, reg);
writel(data, dev->regs_base + reg);
}
unsigned int coda_read(struct coda_dev *dev, u32 reg)
{
u32 data;
data = readl(dev->regs_base + reg);
v4l2_dbg(2, coda_debug, &dev->v4l2_dev,
"%s: data=0x%x, reg=0x%x\n", __func__, data, reg);
return data;
}
static bool coda_format_is_yuv(u32 fourcc)
{
switch (fourcc) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
return true;
default:
return false;
}
}
static u32 coda_format_normalize_yuv(u32 fourcc)
{
return coda_format_is_yuv(fourcc) ? V4L2_PIX_FMT_YUV420 : fourcc;
}
static const struct coda_codec *coda_find_codec(struct coda_dev *dev,
int src_fourcc, int dst_fourcc)
{
const struct coda_codec *codecs = dev->devtype->codecs;
int num_codecs = dev->devtype->num_codecs;
int k;
src_fourcc = coda_format_normalize_yuv(src_fourcc);
dst_fourcc = coda_format_normalize_yuv(dst_fourcc);
if (src_fourcc == dst_fourcc)
return NULL;
for (k = 0; k < num_codecs; k++) {
if (codecs[k].src_fourcc == src_fourcc &&
codecs[k].dst_fourcc == dst_fourcc)
break;
}
if (k == num_codecs)
return NULL;
return &codecs[k];
}
static void coda_get_max_dimensions(struct coda_dev *dev,
const struct coda_codec *codec,
int *max_w, int *max_h)
{
const struct coda_codec *codecs = dev->devtype->codecs;
int num_codecs = dev->devtype->num_codecs;
unsigned int w, h;
int k;
if (codec) {
w = codec->max_w;
h = codec->max_h;
} else {
for (k = 0, w = 0, h = 0; k < num_codecs; k++) {
w = max(w, codecs[k].max_w);
h = max(h, codecs[k].max_h);
}
}
if (max_w)
*max_w = w;
if (max_h)
*max_h = h;
}
const char *coda_product_name(int product)
{
static char buf[9];
switch (product) {
case CODA_DX6:
return "CodaDx6";
case CODA_7541:
return "CODA7541";
case CODA_960:
return "CODA960";
default:
snprintf(buf, sizeof(buf), "(0x%04x)", product);
return buf;
}
}
static int coda_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
strlcpy(cap->driver, CODA_NAME, sizeof(cap->driver));
strlcpy(cap->card, coda_product_name(ctx->dev->devtype->product),
sizeof(cap->card));
strlcpy(cap->bus_info, "platform:" CODA_NAME, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_VIDEO_M2M | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int coda_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
const struct coda_codec *codecs = ctx->dev->devtype->codecs;
const struct coda_fmt *formats = coda_formats;
const struct coda_fmt *fmt;
int num_codecs = ctx->dev->devtype->num_codecs;
int num_formats = ARRAY_SIZE(coda_formats);
int i, k, num = 0;
bool yuv;
if (ctx->inst_type == CODA_INST_ENCODER)
yuv = (f->type == V4L2_BUF_TYPE_VIDEO_OUTPUT);
else
yuv = (f->type == V4L2_BUF_TYPE_VIDEO_CAPTURE);
for (i = 0; i < num_formats; i++) {
if (yuv != coda_format_is_yuv(formats[i].fourcc))
continue;
if (yuv) {
if (num == f->index)
break;
++num;
continue;
}
for (k = 0; k < num_codecs; k++) {
if (f->type == V4L2_BUF_TYPE_VIDEO_CAPTURE &&
formats[i].fourcc == codecs[k].dst_fourcc)
break;
if (f->type == V4L2_BUF_TYPE_VIDEO_OUTPUT &&
formats[i].fourcc == codecs[k].src_fourcc)
break;
}
if (k < num_codecs) {
if (num == f->index)
break;
++num;
}
}
if (i < num_formats) {
fmt = &formats[i];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
if (!yuv)
f->flags |= V4L2_FMT_FLAG_COMPRESSED;
return 0;
}
return -EINVAL;
}
static int coda_g_fmt(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_q_data *q_data;
struct coda_ctx *ctx = fh_to_ctx(priv);
q_data = get_q_data(ctx, f->type);
if (!q_data)
return -EINVAL;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.pixelformat = q_data->fourcc;
f->fmt.pix.width = q_data->width;
f->fmt.pix.height = q_data->height;
f->fmt.pix.bytesperline = q_data->bytesperline;
f->fmt.pix.sizeimage = q_data->sizeimage;
f->fmt.pix.colorspace = ctx->colorspace;
return 0;
}
static int coda_try_fmt(struct coda_ctx *ctx, const struct coda_codec *codec,
struct v4l2_format *f)
{
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data;
unsigned int max_w, max_h;
enum v4l2_field field;
field = f->fmt.pix.field;
if (field == V4L2_FIELD_ANY)
field = V4L2_FIELD_NONE;
else if (V4L2_FIELD_NONE != field)
return -EINVAL;
f->fmt.pix.field = field;
coda_get_max_dimensions(dev, codec, &max_w, &max_h);
v4l_bound_align_image(&f->fmt.pix.width, MIN_W, max_w, W_ALIGN,
&f->fmt.pix.height, MIN_H, max_h, H_ALIGN,
S_ALIGN);
switch (f->fmt.pix.pixelformat) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
case V4L2_PIX_FMT_H264:
case V4L2_PIX_FMT_MPEG4:
case V4L2_PIX_FMT_JPEG:
break;
default:
q_data = get_q_data(ctx, f->type);
if (!q_data)
return -EINVAL;
f->fmt.pix.pixelformat = q_data->fourcc;
}
switch (f->fmt.pix.pixelformat) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
f->fmt.pix.bytesperline = round_up(f->fmt.pix.width, 16);
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline *
f->fmt.pix.height * 3 / 2;
break;
case V4L2_PIX_FMT_H264:
case V4L2_PIX_FMT_MPEG4:
case V4L2_PIX_FMT_JPEG:
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = CODA_MAX_FRAME_SIZE;
break;
default:
BUG();
}
return 0;
}
static int coda_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
const struct coda_codec *codec = NULL;
struct vb2_queue *src_vq;
int ret;
src_vq = v4l2_m2m_get_vq(ctx->fh.m2m_ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
if (vb2_is_streaming(src_vq)) {
struct coda_q_data *q_data_src;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
codec = coda_find_codec(ctx->dev, q_data_src->fourcc,
f->fmt.pix.pixelformat);
if (!codec)
return -EINVAL;
f->fmt.pix.width = q_data_src->width;
f->fmt.pix.height = q_data_src->height;
} else {
codec = coda_find_codec(ctx->dev, V4L2_PIX_FMT_YUV420,
f->fmt.pix.pixelformat);
}
f->fmt.pix.colorspace = ctx->colorspace;
ret = coda_try_fmt(ctx, codec, f);
if (ret < 0)
return ret;
if (codec && codec->src_fourcc == V4L2_PIX_FMT_H264) {
f->fmt.pix.width = f->fmt.pix.width;
f->fmt.pix.height = round_up(f->fmt.pix.height, 16);
f->fmt.pix.bytesperline = round_up(f->fmt.pix.width, 16);
f->fmt.pix.sizeimage = f->fmt.pix.bytesperline *
f->fmt.pix.height * 3 / 2;
}
return 0;
}
static int coda_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
const struct coda_codec *codec = NULL;
if (ctx->inst_type == CODA_INST_DECODER) {
codec = coda_find_codec(ctx->dev, f->fmt.pix.pixelformat,
V4L2_PIX_FMT_YUV420);
if (!codec)
codec = coda_find_codec(ctx->dev, V4L2_PIX_FMT_H264,
V4L2_PIX_FMT_YUV420);
if (!codec)
return -EINVAL;
}
if (!f->fmt.pix.colorspace)
f->fmt.pix.colorspace = V4L2_COLORSPACE_REC709;
return coda_try_fmt(ctx, codec, f);
}
static int coda_s_fmt(struct coda_ctx *ctx, struct v4l2_format *f)
{
struct coda_q_data *q_data;
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
q_data->fourcc = f->fmt.pix.pixelformat;
q_data->width = f->fmt.pix.width;
q_data->height = f->fmt.pix.height;
q_data->bytesperline = f->fmt.pix.bytesperline;
q_data->sizeimage = f->fmt.pix.sizeimage;
q_data->rect.left = 0;
q_data->rect.top = 0;
q_data->rect.width = f->fmt.pix.width;
q_data->rect.height = f->fmt.pix.height;
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"Setting format for type %d, wxh: %dx%d, fmt: %d\n",
f->type, q_data->width, q_data->height, q_data->fourcc);
return 0;
}
static int coda_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
int ret;
ret = coda_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
return coda_s_fmt(ctx, f);
}
static int coda_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
struct v4l2_format f_cap;
int ret;
ret = coda_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
ret = coda_s_fmt(ctx, f);
if (ret)
return ret;
ctx->colorspace = f->fmt.pix.colorspace;
f_cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
coda_g_fmt(file, priv, &f_cap);
f_cap.fmt.pix.width = f->fmt.pix.width;
f_cap.fmt.pix.height = f->fmt.pix.height;
ret = coda_try_fmt_vid_cap(file, priv, &f_cap);
if (ret)
return ret;
return coda_s_fmt(ctx, &f_cap);
}
static int coda_qbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
return v4l2_m2m_qbuf(file, ctx->fh.m2m_ctx, buf);
}
static bool coda_buf_is_end_of_stream(struct coda_ctx *ctx,
struct v4l2_buffer *buf)
{
struct vb2_queue *src_vq;
src_vq = v4l2_m2m_get_vq(ctx->fh.m2m_ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
return ((ctx->bit_stream_param & CODA_BIT_STREAM_END_FLAG) &&
(buf->sequence == (ctx->qsequence - 1)));
}
static int coda_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
int ret;
ret = v4l2_m2m_dqbuf(file, ctx->fh.m2m_ctx, buf);
if (buf->type == V4L2_BUF_TYPE_VIDEO_CAPTURE &&
coda_buf_is_end_of_stream(ctx, buf)) {
const struct v4l2_event eos_event = {
.type = V4L2_EVENT_EOS
};
v4l2_event_queue_fh(&ctx->fh, &eos_event);
}
return ret;
}
static int coda_g_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct coda_ctx *ctx = fh_to_ctx(fh);
struct coda_q_data *q_data;
struct v4l2_rect r, *rsel;
q_data = get_q_data(ctx, s->type);
if (!q_data)
return -EINVAL;
r.left = 0;
r.top = 0;
r.width = q_data->width;
r.height = q_data->height;
rsel = &q_data->rect;
switch (s->target) {
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_CROP_BOUNDS:
rsel = &r;
case V4L2_SEL_TGT_CROP:
if (s->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
break;
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
case V4L2_SEL_TGT_COMPOSE_PADDED:
rsel = &r;
case V4L2_SEL_TGT_COMPOSE:
case V4L2_SEL_TGT_COMPOSE_DEFAULT:
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
break;
default:
return -EINVAL;
}
s->r = *rsel;
return 0;
}
static int coda_try_decoder_cmd(struct file *file, void *fh,
struct v4l2_decoder_cmd *dc)
{
if (dc->cmd != V4L2_DEC_CMD_STOP)
return -EINVAL;
if (dc->flags & V4L2_DEC_CMD_STOP_TO_BLACK)
return -EINVAL;
if (!(dc->flags & V4L2_DEC_CMD_STOP_IMMEDIATELY) && (dc->stop.pts != 0))
return -EINVAL;
return 0;
}
static int coda_decoder_cmd(struct file *file, void *fh,
struct v4l2_decoder_cmd *dc)
{
struct coda_ctx *ctx = fh_to_ctx(fh);
int ret;
ret = coda_try_decoder_cmd(file, fh, dc);
if (ret < 0)
return ret;
if (ctx->inst_type != CODA_INST_DECODER)
return 0;
coda_bit_stream_end_flag(ctx);
ctx->hold = false;
v4l2_m2m_try_schedule(ctx->fh.m2m_ctx);
return 0;
}
static int coda_subscribe_event(struct v4l2_fh *fh,
const struct v4l2_event_subscription *sub)
{
switch (sub->type) {
case V4L2_EVENT_EOS:
return v4l2_event_subscribe(fh, sub, 0, NULL);
default:
return v4l2_ctrl_subscribe_event(fh, sub);
}
}
void coda_set_gdi_regs(struct coda_ctx *ctx)
{
struct gdi_tiled_map *tiled_map = &ctx->tiled_map;
struct coda_dev *dev = ctx->dev;
int i;
for (i = 0; i < 16; i++)
coda_write(dev, tiled_map->xy2ca_map[i],
CODA9_GDI_XY2_CAS_0 + 4 * i);
for (i = 0; i < 4; i++)
coda_write(dev, tiled_map->xy2ba_map[i],
CODA9_GDI_XY2_BA_0 + 4 * i);
for (i = 0; i < 16; i++)
coda_write(dev, tiled_map->xy2ra_map[i],
CODA9_GDI_XY2_RAS_0 + 4 * i);
coda_write(dev, tiled_map->xy2rbc_config, CODA9_GDI_XY2_RBC_CONFIG);
for (i = 0; i < 32; i++)
coda_write(dev, tiled_map->rbc2axi_map[i],
CODA9_GDI_RBC2_AXI_0 + 4 * i);
}
static void coda_device_run(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
struct coda_dev *dev = ctx->dev;
queue_work(dev->workqueue, &ctx->pic_run_work);
}
static void coda_pic_run_work(struct work_struct *work)
{
struct coda_ctx *ctx = container_of(work, struct coda_ctx, pic_run_work);
struct coda_dev *dev = ctx->dev;
int ret;
mutex_lock(&ctx->buffer_mutex);
mutex_lock(&dev->coda_mutex);
ret = ctx->ops->prepare_run(ctx);
if (ret < 0 && ctx->inst_type == CODA_INST_DECODER) {
mutex_unlock(&dev->coda_mutex);
mutex_unlock(&ctx->buffer_mutex);
return;
}
if (!wait_for_completion_timeout(&ctx->completion,
msecs_to_jiffies(1000))) {
dev_err(&dev->plat_dev->dev, "CODA PIC_RUN timeout\n");
ctx->hold = true;
coda_hw_reset(ctx);
} else if (!ctx->aborting) {
ctx->ops->finish_run(ctx);
}
if (ctx->aborting || (!ctx->streamon_cap && !ctx->streamon_out))
queue_work(dev->workqueue, &ctx->seq_end_work);
mutex_unlock(&dev->coda_mutex);
mutex_unlock(&ctx->buffer_mutex);
v4l2_m2m_job_finish(ctx->dev->m2m_dev, ctx->fh.m2m_ctx);
}
static int coda_job_ready(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
if (!v4l2_m2m_num_src_bufs_ready(ctx->fh.m2m_ctx) &&
ctx->inst_type != CODA_INST_DECODER) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"not ready: not enough video buffers.\n");
return 0;
}
if (!v4l2_m2m_num_dst_bufs_ready(ctx->fh.m2m_ctx)) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"not ready: not enough video capture buffers.\n");
return 0;
}
if (ctx->hold ||
((ctx->inst_type == CODA_INST_DECODER) &&
(coda_get_bitstream_payload(ctx) < 512) &&
!(ctx->bit_stream_param & CODA_BIT_STREAM_END_FLAG))) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"%d: not ready: not enough bitstream data.\n",
ctx->idx);
return 0;
}
if (ctx->aborting) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"not ready: aborting\n");
return 0;
}
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"job ready\n");
return 1;
}
static void coda_job_abort(void *priv)
{
struct coda_ctx *ctx = priv;
ctx->aborting = 1;
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"Aborting task\n");
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
static void coda_set_tiled_map_type(struct coda_ctx *ctx, int tiled_map_type)
{
struct gdi_tiled_map *tiled_map = &ctx->tiled_map;
int luma_map, chro_map, i;
memset(tiled_map, 0, sizeof(*tiled_map));
luma_map = 64;
chro_map = 64;
tiled_map->map_type = tiled_map_type;
for (i = 0; i < 16; i++)
tiled_map->xy2ca_map[i] = luma_map << 8 | chro_map;
for (i = 0; i < 4; i++)
tiled_map->xy2ba_map[i] = luma_map << 8 | chro_map;
for (i = 0; i < 16; i++)
tiled_map->xy2ra_map[i] = luma_map << 8 | chro_map;
if (tiled_map_type == GDI_LINEAR_FRAME_MAP) {
tiled_map->xy2rbc_config = 0;
} else {
dev_err(&ctx->dev->plat_dev->dev, "invalid map type: %d\n",
tiled_map_type);
return;
}
}
static void set_default_params(struct coda_ctx *ctx)
{
u32 src_fourcc, dst_fourcc;
int max_w;
int max_h;
if (ctx->inst_type == CODA_INST_ENCODER) {
src_fourcc = V4L2_PIX_FMT_YUV420;
dst_fourcc = V4L2_PIX_FMT_H264;
} else {
src_fourcc = V4L2_PIX_FMT_H264;
dst_fourcc = V4L2_PIX_FMT_YUV420;
}
ctx->codec = coda_find_codec(ctx->dev, src_fourcc, dst_fourcc);
max_w = ctx->codec->max_w;
max_h = ctx->codec->max_h;
ctx->params.codec_mode = ctx->codec->mode;
ctx->colorspace = V4L2_COLORSPACE_REC709;
ctx->params.framerate = 30;
ctx->aborting = 0;
ctx->q_data[V4L2_M2M_SRC].fourcc = ctx->codec->src_fourcc;
ctx->q_data[V4L2_M2M_DST].fourcc = ctx->codec->dst_fourcc;
ctx->q_data[V4L2_M2M_SRC].width = max_w;
ctx->q_data[V4L2_M2M_SRC].height = max_h;
ctx->q_data[V4L2_M2M_DST].width = max_w;
ctx->q_data[V4L2_M2M_DST].height = max_h;
if (ctx->codec->src_fourcc == V4L2_PIX_FMT_YUV420) {
ctx->q_data[V4L2_M2M_SRC].bytesperline = max_w;
ctx->q_data[V4L2_M2M_SRC].sizeimage = (max_w * max_h * 3) / 2;
ctx->q_data[V4L2_M2M_DST].bytesperline = 0;
ctx->q_data[V4L2_M2M_DST].sizeimage = CODA_MAX_FRAME_SIZE;
} else {
ctx->q_data[V4L2_M2M_SRC].bytesperline = 0;
ctx->q_data[V4L2_M2M_SRC].sizeimage = CODA_MAX_FRAME_SIZE;
ctx->q_data[V4L2_M2M_DST].bytesperline = max_w;
ctx->q_data[V4L2_M2M_DST].sizeimage = (max_w * max_h * 3) / 2;
}
ctx->q_data[V4L2_M2M_SRC].rect.width = max_w;
ctx->q_data[V4L2_M2M_SRC].rect.height = max_h;
ctx->q_data[V4L2_M2M_DST].rect.width = max_w;
ctx->q_data[V4L2_M2M_DST].rect.height = max_h;
if (ctx->dev->devtype->product == CODA_960)
coda_set_tiled_map_type(ctx, GDI_LINEAR_FRAME_MAP);
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
return 0;
}
static void coda_buf_queue(struct vb2_buffer *vb)
{
struct coda_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct coda_q_data *q_data;
q_data = get_q_data(ctx, vb->vb2_queue->type);
if (q_data->fourcc == V4L2_PIX_FMT_H264 &&
vb->vb2_queue->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (vb2_get_plane_payload(vb, 0) == 0)
coda_bit_stream_end_flag(ctx);
mutex_lock(&ctx->bitstream_mutex);
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
if (vb2_is_streaming(vb->vb2_queue))
coda_fill_bitstream(ctx);
mutex_unlock(&ctx->bitstream_mutex);
} else {
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
}
}
int coda_alloc_aux_buf(struct coda_dev *dev, struct coda_aux_buf *buf,
size_t size, const char *name, struct dentry *parent)
{
buf->vaddr = dma_alloc_coherent(&dev->plat_dev->dev, size, &buf->paddr,
GFP_KERNEL);
if (!buf->vaddr) {
v4l2_err(&dev->v4l2_dev,
"Failed to allocate %s buffer of size %u\n",
name, size);
return -ENOMEM;
}
buf->size = size;
if (name && parent) {
buf->blob.data = buf->vaddr;
buf->blob.size = size;
buf->dentry = debugfs_create_blob(name, 0644, parent,
&buf->blob);
if (!buf->dentry)
dev_warn(&dev->plat_dev->dev,
"failed to create debugfs entry %s\n", name);
}
return 0;
}
void coda_free_aux_buf(struct coda_dev *dev,
struct coda_aux_buf *buf)
{
if (buf->vaddr) {
dma_free_coherent(&dev->plat_dev->dev, buf->size,
buf->vaddr, buf->paddr);
buf->vaddr = NULL;
buf->size = 0;
}
debugfs_remove(buf->dentry);
}
static int coda_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct v4l2_device *v4l2_dev = &ctx->dev->v4l2_dev;
struct coda_q_data *q_data_src, *q_data_dst;
struct vb2_buffer *buf;
u32 dst_fourcc;
int ret = 0;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (q_data_src->fourcc == V4L2_PIX_FMT_H264) {
mutex_lock(&ctx->bitstream_mutex);
coda_fill_bitstream(ctx);
mutex_unlock(&ctx->bitstream_mutex);
if (coda_get_bitstream_payload(ctx) < 512) {
ret = -EINVAL;
goto err;
}
} else {
if (count < 1) {
ret = -EINVAL;
goto err;
}
}
ctx->streamon_out = 1;
} else {
if (count < 1) {
ret = -EINVAL;
goto err;
}
ctx->streamon_cap = 1;
}
if (!(ctx->streamon_out & ctx->streamon_cap))
return 0;
if (ctx->inst_type == CODA_INST_DECODER)
v4l2_m2m_set_src_buffered(ctx->fh.m2m_ctx, true);
ctx->gopcounter = ctx->params.gop_size - 1;
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
dst_fourcc = q_data_dst->fourcc;
ctx->codec = coda_find_codec(ctx->dev, q_data_src->fourcc,
q_data_dst->fourcc);
if (!ctx->codec) {
v4l2_err(v4l2_dev, "couldn't tell instance type.\n");
ret = -EINVAL;
goto err;
}
ret = ctx->ops->start_streaming(ctx);
if (ctx->inst_type == CODA_INST_DECODER) {
if (ret == -EAGAIN)
return 0;
else if (ret < 0)
goto err;
}
ctx->initialized = 1;
return ret;
err:
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
while ((buf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx)))
v4l2_m2m_buf_done(buf, VB2_BUF_STATE_DEQUEUED);
} else {
while ((buf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx)))
v4l2_m2m_buf_done(buf, VB2_BUF_STATE_DEQUEUED);
}
return ret;
}
static void coda_stop_streaming(struct vb2_queue *q)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct coda_dev *dev = ctx->dev;
struct vb2_buffer *buf;
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: output\n", __func__);
ctx->streamon_out = 0;
coda_bit_stream_end_flag(ctx);
ctx->isequence = 0;
while ((buf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx)))
v4l2_m2m_buf_done(buf, VB2_BUF_STATE_ERROR);
} else {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: capture\n", __func__);
ctx->streamon_cap = 0;
ctx->osequence = 0;
ctx->sequence_offset = 0;
while ((buf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx)))
v4l2_m2m_buf_done(buf, VB2_BUF_STATE_ERROR);
}
if (!ctx->streamon_out && !ctx->streamon_cap) {
struct coda_timestamp *ts;
mutex_lock(&ctx->bitstream_mutex);
while (!list_empty(&ctx->timestamp_list)) {
ts = list_first_entry(&ctx->timestamp_list,
struct coda_timestamp, list);
list_del(&ts->list);
kfree(ts);
}
mutex_unlock(&ctx->bitstream_mutex);
kfifo_init(&ctx->bitstream_fifo,
ctx->bitstream.vaddr, ctx->bitstream.size);
ctx->runcounter = 0;
}
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
case V4L2_CID_MPEG_VIDEO_H264_MIN_QP:
ctx->params.h264_min_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_MAX_QP:
ctx->params.h264_max_qp = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_ALPHA:
ctx->params.h264_deblk_alpha = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_BETA:
ctx->params.h264_deblk_beta = ctrl->val;
break;
case V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_MODE:
ctx->params.h264_deblk_enabled = (ctrl->val ==
V4L2_MPEG_VIDEO_H264_LOOP_FILTER_MODE_ENABLED);
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
case V4L2_CID_MPEG_VIDEO_CYCLIC_INTRA_REFRESH_MB:
ctx->params.intra_refresh = ctrl->val;
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
V4L2_CID_MPEG_VIDEO_H264_I_FRAME_QP, 0, 51, 1, 25);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_P_FRAME_QP, 0, 51, 1, 25);
if (ctx->dev->devtype->product != CODA_960) {
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_MIN_QP, 0, 51, 1, 12);
}
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_MAX_QP, 0, 51, 1, 51);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_ALPHA, 0, 15, 1, 0);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_BETA, 0, 15, 1, 0);
v4l2_ctrl_new_std_menu(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_LOOP_FILTER_MODE,
V4L2_MPEG_VIDEO_H264_LOOP_FILTER_MODE_DISABLED, 0x0,
V4L2_MPEG_VIDEO_H264_LOOP_FILTER_MODE_ENABLED);
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
V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_BYTES, 1, 0x3fffffff, 1,
500);
v4l2_ctrl_new_std_menu(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_HEADER_MODE,
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME,
(1 << V4L2_MPEG_VIDEO_HEADER_MODE_SEPARATE),
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_CYCLIC_INTRA_REFRESH_MB, 0,
1920 * 1088 / 256, 1, 0);
if (ctx->ctrls.error) {
v4l2_err(&ctx->dev->v4l2_dev,
"control initialization error (%d)",
ctx->ctrls.error);
return -EINVAL;
}
return v4l2_ctrl_handler_setup(&ctx->ctrls);
}
static int coda_queue_init(struct coda_ctx *ctx, struct vb2_queue *vq)
{
vq->drv_priv = ctx;
vq->ops = &coda_qops;
vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
vq->lock = &ctx->dev->dev_mutex;
return vb2_queue_init(vq);
}
int coda_encoder_queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_DMABUF | VB2_MMAP;
src_vq->mem_ops = &vb2_dma_contig_memops;
ret = coda_queue_init(priv, src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_DMABUF | VB2_MMAP;
dst_vq->mem_ops = &vb2_dma_contig_memops;
return coda_queue_init(priv, dst_vq);
}
int coda_decoder_queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_DMABUF | VB2_MMAP;
src_vq->mem_ops = &vb2_dma_contig_memops;
ret = coda_queue_init(priv, src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_DMABUF | VB2_MMAP;
dst_vq->mem_ops = &vb2_dma_contig_memops;
return coda_queue_init(priv, dst_vq);
}
static int coda_next_free_instance(struct coda_dev *dev)
{
int idx = ffz(dev->instance_mask);
if ((idx < 0) ||
(dev->devtype->product == CODA_DX6 && idx > CODADX6_MAX_INSTANCES))
return -EBUSY;
return idx;
}
static int coda_open(struct file *file, enum coda_inst_type inst_type,
const struct coda_context_ops *ctx_ops)
{
struct coda_dev *dev = video_drvdata(file);
struct coda_ctx *ctx = NULL;
char *name;
int ret;
int idx;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
idx = coda_next_free_instance(dev);
if (idx < 0) {
ret = idx;
goto err_coda_max;
}
set_bit(idx, &dev->instance_mask);
name = kasprintf(GFP_KERNEL, "context%d", idx);
ctx->debugfs_entry = debugfs_create_dir(name, dev->debugfs_root);
kfree(name);
ctx->inst_type = inst_type;
ctx->ops = ctx_ops;
init_completion(&ctx->completion);
INIT_WORK(&ctx->pic_run_work, coda_pic_run_work);
INIT_WORK(&ctx->seq_end_work, ctx->ops->seq_end_work);
v4l2_fh_init(&ctx->fh, video_devdata(file));
file->private_data = &ctx->fh;
v4l2_fh_add(&ctx->fh);
ctx->dev = dev;
ctx->idx = idx;
switch (dev->devtype->product) {
case CODA_7541:
case CODA_960:
ctx->reg_idx = 0;
break;
default:
ctx->reg_idx = idx;
}
ret = pm_runtime_get_sync(&dev->plat_dev->dev);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to power up: %d\n", ret);
goto err_pm_get;
}
ret = clk_prepare_enable(dev->clk_per);
if (ret)
goto err_clk_per;
ret = clk_prepare_enable(dev->clk_ahb);
if (ret)
goto err_clk_ahb;
set_default_params(ctx);
ctx->fh.m2m_ctx = v4l2_m2m_ctx_init(dev->m2m_dev, ctx,
ctx->ops->queue_init);
if (IS_ERR(ctx->fh.m2m_ctx)) {
ret = PTR_ERR(ctx->fh.m2m_ctx);
v4l2_err(&dev->v4l2_dev, "%s return error (%d)\n",
__func__, ret);
goto err_ctx_init;
}
ret = coda_ctrls_setup(ctx);
if (ret) {
v4l2_err(&dev->v4l2_dev, "failed to setup coda controls\n");
goto err_ctrls_setup;
}
ctx->fh.ctrl_handler = &ctx->ctrls;
ret = coda_alloc_context_buf(ctx, &ctx->parabuf, CODA_PARA_BUF_SIZE,
"parabuf");
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to allocate parabuf");
goto err_dma_alloc;
}
ctx->bitstream.size = CODA_MAX_FRAME_SIZE;
ctx->bitstream.vaddr = dma_alloc_writecombine(&dev->plat_dev->dev,
ctx->bitstream.size, &ctx->bitstream.paddr, GFP_KERNEL);
if (!ctx->bitstream.vaddr) {
v4l2_err(&dev->v4l2_dev,
"failed to allocate bitstream ringbuffer");
ret = -ENOMEM;
goto err_dma_writecombine;
}
kfifo_init(&ctx->bitstream_fifo,
ctx->bitstream.vaddr, ctx->bitstream.size);
mutex_init(&ctx->bitstream_mutex);
mutex_init(&ctx->buffer_mutex);
INIT_LIST_HEAD(&ctx->timestamp_list);
coda_lock(ctx);
list_add(&ctx->list, &dev->instances);
coda_unlock(ctx);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev, "Created instance %d (%p)\n",
ctx->idx, ctx);
return 0;
err_dma_writecombine:
if (ctx->dev->devtype->product == CODA_DX6)
coda_free_aux_buf(dev, &ctx->workbuf);
coda_free_aux_buf(dev, &ctx->parabuf);
err_dma_alloc:
v4l2_ctrl_handler_free(&ctx->ctrls);
err_ctrls_setup:
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
err_ctx_init:
clk_disable_unprepare(dev->clk_ahb);
err_clk_ahb:
clk_disable_unprepare(dev->clk_per);
err_clk_per:
pm_runtime_put_sync(&dev->plat_dev->dev);
err_pm_get:
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
clear_bit(ctx->idx, &dev->instance_mask);
err_coda_max:
kfree(ctx);
return ret;
}
static int coda_encoder_open(struct file *file)
{
return coda_open(file, CODA_INST_ENCODER, &coda_bit_encode_ops);
}
static int coda_decoder_open(struct file *file)
{
return coda_open(file, CODA_INST_DECODER, &coda_bit_decode_ops);
}
static int coda_release(struct file *file)
{
struct coda_dev *dev = video_drvdata(file);
struct coda_ctx *ctx = fh_to_ctx(file->private_data);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev, "Releasing instance %p\n",
ctx);
debugfs_remove_recursive(ctx->debugfs_entry);
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
if (ctx->initialized) {
queue_work(dev->workqueue, &ctx->seq_end_work);
flush_work(&ctx->seq_end_work);
}
coda_lock(ctx);
list_del(&ctx->list);
coda_unlock(ctx);
dma_free_writecombine(&dev->plat_dev->dev, ctx->bitstream.size,
ctx->bitstream.vaddr, ctx->bitstream.paddr);
if (ctx->dev->devtype->product == CODA_DX6)
coda_free_aux_buf(dev, &ctx->workbuf);
coda_free_aux_buf(dev, &ctx->parabuf);
v4l2_ctrl_handler_free(&ctx->ctrls);
clk_disable_unprepare(dev->clk_ahb);
clk_disable_unprepare(dev->clk_per);
pm_runtime_put_sync(&dev->plat_dev->dev);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
clear_bit(ctx->idx, &dev->instance_mask);
if (ctx->ops->release)
ctx->ops->release(ctx);
kfree(ctx);
return 0;
}
static int coda_hw_init(struct coda_dev *dev)
{
u32 data;
u16 *p;
int i, ret;
ret = clk_prepare_enable(dev->clk_per);
if (ret)
goto err_clk_per;
ret = clk_prepare_enable(dev->clk_ahb);
if (ret)
goto err_clk_ahb;
if (dev->rstc)
reset_control_reset(dev->rstc);
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
for (i = 0; i < 64; i++)
coda_write(dev, 0, CODA_REG_BIT_CODE_BUF_ADDR + i * 4);
if (dev->devtype->product == CODA_960 ||
dev->devtype->product == CODA_7541) {
coda_write(dev, dev->tempbuf.paddr,
CODA_REG_BIT_TEMP_BUF_ADDR);
coda_write(dev, 0, CODA_REG_BIT_BIT_STREAM_PARAM);
} else {
coda_write(dev, dev->workbuf.paddr,
CODA_REG_BIT_WORK_BUF_ADDR);
}
coda_write(dev, dev->codebuf.paddr,
CODA_REG_BIT_CODE_BUF_ADDR);
coda_write(dev, 0, CODA_REG_BIT_CODE_RUN);
switch (dev->devtype->product) {
case CODA_DX6:
coda_write(dev, CODADX6_STREAM_BUF_PIC_FLUSH,
CODA_REG_BIT_STREAM_CTRL);
break;
default:
coda_write(dev, CODA7_STREAM_BUF_PIC_FLUSH,
CODA_REG_BIT_STREAM_CTRL);
}
if (dev->devtype->product == CODA_960)
coda_write(dev, 1 << 12, CODA_REG_BIT_FRAME_MEM_CTRL);
else
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
clk_disable_unprepare(dev->clk_ahb);
clk_disable_unprepare(dev->clk_per);
return 0;
err_clk_ahb:
clk_disable_unprepare(dev->clk_per);
err_clk_per:
return ret;
}
static int coda_register_device(struct coda_dev *dev, struct video_device *vfd)
{
vfd->release = video_device_release_empty,
vfd->lock = &dev->dev_mutex;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->vfl_dir = VFL_DIR_M2M;
video_set_drvdata(vfd, dev);
v4l2_disable_ioctl(vfd, VIDIOC_CROPCAP);
v4l2_disable_ioctl(vfd, VIDIOC_G_CROP);
v4l2_disable_ioctl(vfd, VIDIOC_S_CROP);
return video_register_device(vfd, VFL_TYPE_GRABBER, 0);
}
static void coda_fw_callback(const struct firmware *fw, void *context)
{
struct coda_dev *dev = context;
struct platform_device *pdev = dev->plat_dev;
int ret;
if (!fw) {
v4l2_err(&dev->v4l2_dev, "firmware request failed\n");
goto put_pm;
}
ret = coda_alloc_aux_buf(dev, &dev->codebuf, fw->size, "codebuf",
dev->debugfs_root);
if (ret < 0) {
dev_err(&pdev->dev, "failed to allocate code buffer\n");
goto put_pm;
}
memcpy(dev->codebuf.vaddr, fw->data, fw->size);
release_firmware(fw);
ret = coda_hw_init(dev);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "HW initialization failed\n");
goto put_pm;
}
ret = coda_check_firmware(dev);
if (ret < 0)
goto put_pm;
dev->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(dev->alloc_ctx)) {
v4l2_err(&dev->v4l2_dev, "Failed to alloc vb2 context\n");
goto put_pm;
}
dev->m2m_dev = v4l2_m2m_init(&coda_m2m_ops);
if (IS_ERR(dev->m2m_dev)) {
v4l2_err(&dev->v4l2_dev, "Failed to init mem2mem device\n");
goto rel_ctx;
}
dev->vfd[0].fops = &coda_encoder_fops,
dev->vfd[0].ioctl_ops = &coda_ioctl_ops;
snprintf(dev->vfd[0].name, sizeof(dev->vfd[0].name), "coda-encoder");
ret = coda_register_device(dev, &dev->vfd[0]);
if (ret) {
v4l2_err(&dev->v4l2_dev,
"Failed to register encoder video device\n");
goto rel_m2m;
}
dev->vfd[1].fops = &coda_decoder_fops,
dev->vfd[1].ioctl_ops = &coda_ioctl_ops;
snprintf(dev->vfd[1].name, sizeof(dev->vfd[1].name), "coda-decoder");
ret = coda_register_device(dev, &dev->vfd[1]);
if (ret) {
v4l2_err(&dev->v4l2_dev,
"Failed to register decoder video device\n");
goto rel_m2m;
}
v4l2_info(&dev->v4l2_dev, "codec registered as /dev/video[%d-%d]\n",
dev->vfd[0].num, dev->vfd[1].num);
pm_runtime_put_sync(&pdev->dev);
return;
rel_m2m:
v4l2_m2m_release(dev->m2m_dev);
rel_ctx:
vb2_dma_contig_cleanup_ctx(dev->alloc_ctx);
put_pm:
pm_runtime_put_sync(&pdev->dev);
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
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev, "Not enough memory for %s\n",
CODA_NAME);
return -ENOMEM;
}
spin_lock_init(&dev->irqlock);
INIT_LIST_HEAD(&dev->instances);
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
dev->regs_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dev->regs_base))
return PTR_ERR(dev->regs_base);
irq = platform_get_irq_byname(pdev, "bit");
if (irq < 0)
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq resource\n");
return irq;
}
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL, coda_irq_handler,
IRQF_ONESHOT, dev_name(&pdev->dev), dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request irq: %d\n", ret);
return ret;
}
dev->rstc = devm_reset_control_get_optional(&pdev->dev, NULL);
if (IS_ERR(dev->rstc)) {
ret = PTR_ERR(dev->rstc);
if (ret == -ENOENT || ret == -ENOSYS) {
dev->rstc = NULL;
} else {
dev_err(&pdev->dev, "failed get reset control: %d\n",
ret);
return ret;
}
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
mutex_init(&dev->coda_mutex);
pdev_id = of_id ? of_id->data : platform_get_device_id(pdev);
if (of_id) {
dev->devtype = of_id->data;
} else if (pdev_id) {
dev->devtype = &coda_devdata[pdev_id->driver_data];
} else {
v4l2_device_unregister(&dev->v4l2_dev);
return -EINVAL;
}
dev->debugfs_root = debugfs_create_dir("coda", NULL);
if (!dev->debugfs_root)
dev_warn(&pdev->dev, "failed to create debugfs root\n");
if (dev->devtype->product == CODA_DX6) {
ret = coda_alloc_aux_buf(dev, &dev->workbuf,
dev->devtype->workbuf_size, "workbuf",
dev->debugfs_root);
if (ret < 0) {
dev_err(&pdev->dev, "failed to allocate work buffer\n");
v4l2_device_unregister(&dev->v4l2_dev);
return ret;
}
}
if (dev->devtype->tempbuf_size) {
ret = coda_alloc_aux_buf(dev, &dev->tempbuf,
dev->devtype->tempbuf_size, "tempbuf",
dev->debugfs_root);
if (ret < 0) {
dev_err(&pdev->dev, "failed to allocate temp buffer\n");
v4l2_device_unregister(&dev->v4l2_dev);
return ret;
}
}
dev->iram.size = dev->devtype->iram_size;
dev->iram.vaddr = gen_pool_dma_alloc(dev->iram_pool, dev->iram.size,
&dev->iram.paddr);
if (!dev->iram.vaddr) {
dev_warn(&pdev->dev, "unable to alloc iram\n");
} else {
dev->iram.blob.data = dev->iram.vaddr;
dev->iram.blob.size = dev->iram.size;
dev->iram.dentry = debugfs_create_blob("iram", 0644,
dev->debugfs_root,
&dev->iram.blob);
}
dev->workqueue = alloc_workqueue("coda", WQ_UNBOUND | WQ_MEM_RECLAIM, 1);
if (!dev->workqueue) {
dev_err(&pdev->dev, "unable to alloc workqueue\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, dev);
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return coda_firmware_request(dev);
}
static int coda_remove(struct platform_device *pdev)
{
struct coda_dev *dev = platform_get_drvdata(pdev);
video_unregister_device(&dev->vfd[0]);
video_unregister_device(&dev->vfd[1]);
if (dev->m2m_dev)
v4l2_m2m_release(dev->m2m_dev);
pm_runtime_disable(&pdev->dev);
if (dev->alloc_ctx)
vb2_dma_contig_cleanup_ctx(dev->alloc_ctx);
v4l2_device_unregister(&dev->v4l2_dev);
destroy_workqueue(dev->workqueue);
if (dev->iram.vaddr)
gen_pool_free(dev->iram_pool, (unsigned long)dev->iram.vaddr,
dev->iram.size);
coda_free_aux_buf(dev, &dev->codebuf);
coda_free_aux_buf(dev, &dev->tempbuf);
coda_free_aux_buf(dev, &dev->workbuf);
debugfs_remove_recursive(dev->debugfs_root);
return 0;
}
static int coda_runtime_resume(struct device *dev)
{
struct coda_dev *cdev = dev_get_drvdata(dev);
int ret = 0;
if (dev->pm_domain && cdev->codebuf.vaddr) {
ret = coda_hw_init(cdev);
if (ret)
v4l2_err(&cdev->v4l2_dev, "HW initialization failed\n");
}
return ret;
}
