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
if (dev->devtype->product == CODA_960 ||
dev->devtype->product == CODA_7541) {
coda_write(dev, ctx->bit_stream_param,
CODA_REG_BIT_BIT_STREAM_PARAM);
coda_write(dev, ctx->frm_dis_flg,
CODA_REG_BIT_FRM_DIS_FLG(ctx->reg_idx));
coda_write(dev, ctx->frame_mem_ctrl,
CODA_REG_BIT_FRAME_MEM_CTRL);
coda_write(dev, ctx->workbuf.paddr, CODA_REG_BIT_WORK_BUF_ADDR);
}
if (dev->devtype->product == CODA_960) {
coda_write(dev, 1, CODA9_GDI_WPROT_ERR_CLR);
coda_write(dev, 0, CODA9_GDI_WPROT_RGN_EN);
}
coda_write(dev, CODA_REG_BIT_BUSY_FLAG, CODA_REG_BIT_BUSY);
coda_write(dev, ctx->idx, CODA_REG_BIT_RUN_INDEX);
coda_write(dev, ctx->params.codec_mode, CODA_REG_BIT_RUN_COD_STD);
coda_write(dev, ctx->params.codec_mode_aux, CODA7_REG_BIT_RUN_AUX_STD);
coda_write(dev, cmd, CODA_REG_BIT_RUN_COMMAND);
}
static int coda_command_sync(struct coda_ctx *ctx, int cmd)
{
struct coda_dev *dev = ctx->dev;
coda_command_async(ctx, cmd);
return coda_wait_timeout(dev);
}
static int coda_hw_reset(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
unsigned long timeout;
unsigned int idx;
int ret;
if (!dev->rstc)
return -ENOENT;
idx = coda_read(dev, CODA_REG_BIT_RUN_INDEX);
timeout = jiffies + msecs_to_jiffies(100);
coda_write(dev, 0x11, CODA9_GDI_BUS_CTRL);
while (coda_read(dev, CODA9_GDI_BUS_STATUS) != 0x77) {
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
ret = reset_control_reset(dev->rstc);
if (ret < 0)
return ret;
coda_write(dev, 0x00, CODA9_GDI_BUS_CTRL);
coda_write(dev, CODA_REG_BIT_BUSY_FLAG, CODA_REG_BIT_BUSY);
coda_write(dev, CODA_REG_RUN_ENABLE, CODA_REG_BIT_CODE_RUN);
ret = coda_wait_timeout(dev);
coda_write(dev, idx, CODA_REG_BIT_RUN_INDEX);
return ret;
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
return NULL;
}
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
static struct coda_codec *coda_find_codec(struct coda_dev *dev, int src_fourcc,
int dst_fourcc)
{
struct coda_codec *codecs = dev->devtype->codecs;
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
struct coda_codec *codec,
int *max_w, int *max_h)
{
struct coda_codec *codecs = dev->devtype->codecs;
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
static char *coda_product_name(int product)
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
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_VIDEO_M2M | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int enum_fmt(void *priv, struct v4l2_fmtdesc *f,
enum v4l2_buf_type type, int src_fourcc)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
struct coda_codec *codecs = ctx->dev->devtype->codecs;
struct coda_fmt *formats = coda_formats;
struct coda_fmt *fmt;
int num_codecs = ctx->dev->devtype->num_codecs;
int num_formats = ARRAY_SIZE(coda_formats);
int i, k, num = 0;
for (i = 0; i < num_formats; i++) {
if (coda_format_is_yuv(formats[i].fourcc) &&
!coda_format_is_yuv(src_fourcc)) {
if (num == f->index)
break;
++num;
continue;
}
for (k = 0; k < num_codecs; k++) {
if (type == V4L2_BUF_TYPE_VIDEO_CAPTURE &&
formats[i].fourcc == codecs[k].dst_fourcc &&
(!src_fourcc || src_fourcc == codecs[k].src_fourcc))
break;
if (type == V4L2_BUF_TYPE_VIDEO_OUTPUT &&
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
if (!coda_format_is_yuv(fmt->fourcc))
f->flags |= V4L2_FMT_FLAG_COMPRESSED;
return 0;
}
return -EINVAL;
}
static int coda_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct coda_ctx *ctx = fh_to_ctx(priv);
struct vb2_queue *src_vq;
struct coda_q_data *q_data_src;
src_vq = v4l2_m2m_get_vq(ctx->fh.m2m_ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
if (vb2_is_streaming(src_vq)) {
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
return enum_fmt(priv, f, V4L2_BUF_TYPE_VIDEO_CAPTURE,
q_data_src->fourcc);
}
return enum_fmt(priv, f, V4L2_BUF_TYPE_VIDEO_CAPTURE, 0);
}
static int coda_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(priv, f, V4L2_BUF_TYPE_VIDEO_OUTPUT, 0);
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
static int coda_try_fmt(struct coda_ctx *ctx, struct coda_codec *codec,
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
struct coda_codec *codec;
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
struct coda_codec *codec;
codec = coda_find_codec(ctx->dev, f->fmt.pix.pixelformat,
V4L2_PIX_FMT_YUV420);
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
int ret;
ret = coda_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
ret = coda_s_fmt(ctx, f);
if (ret)
ctx->colorspace = f->fmt.pix.colorspace;
return ret;
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
struct coda_dev *dev = ctx->dev;
int ret;
ret = coda_try_decoder_cmd(file, fh, dc);
if (ret < 0)
return ret;
if (ctx->inst_type != CODA_INST_DECODER)
return 0;
ctx->bit_stream_param |= CODA_BIT_STREAM_END_FLAG;
if ((dev->devtype->product == CODA_960) &&
coda_isbusy(dev) &&
(ctx->idx == coda_read(dev, CODA_REG_BIT_RUN_INDEX))) {
coda_write(dev, ctx->bit_stream_param, CODA_REG_BIT_BIT_STREAM_PARAM);
}
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
static inline int coda_get_bitstream_payload(struct coda_ctx *ctx)
{
return kfifo_len(&ctx->bitstream_fifo);
}
static void coda_kfifo_sync_from_device(struct coda_ctx *ctx)
{
struct __kfifo *kfifo = &ctx->bitstream_fifo.kfifo;
struct coda_dev *dev = ctx->dev;
u32 rd_ptr;
rd_ptr = coda_read(dev, CODA_REG_BIT_RD_PTR(ctx->reg_idx));
kfifo->out = (kfifo->in & ~kfifo->mask) |
(rd_ptr - ctx->bitstream.paddr);
if (kfifo->out > kfifo->in)
kfifo->out -= kfifo->mask + 1;
}
static void coda_kfifo_sync_to_device_full(struct coda_ctx *ctx)
{
struct __kfifo *kfifo = &ctx->bitstream_fifo.kfifo;
struct coda_dev *dev = ctx->dev;
u32 rd_ptr, wr_ptr;
rd_ptr = ctx->bitstream.paddr + (kfifo->out & kfifo->mask);
coda_write(dev, rd_ptr, CODA_REG_BIT_RD_PTR(ctx->reg_idx));
wr_ptr = ctx->bitstream.paddr + (kfifo->in & kfifo->mask);
coda_write(dev, wr_ptr, CODA_REG_BIT_WR_PTR(ctx->reg_idx));
}
static void coda_kfifo_sync_to_device_write(struct coda_ctx *ctx)
{
struct __kfifo *kfifo = &ctx->bitstream_fifo.kfifo;
struct coda_dev *dev = ctx->dev;
u32 wr_ptr;
wr_ptr = ctx->bitstream.paddr + (kfifo->in & kfifo->mask);
coda_write(dev, wr_ptr, CODA_REG_BIT_WR_PTR(ctx->reg_idx));
}
static int coda_bitstream_queue(struct coda_ctx *ctx, struct vb2_buffer *src_buf)
{
u32 src_size = vb2_get_plane_payload(src_buf, 0);
u32 n;
n = kfifo_in(&ctx->bitstream_fifo, vb2_plane_vaddr(src_buf, 0), src_size);
if (n < src_size)
return -ENOSPC;
dma_sync_single_for_device(&ctx->dev->plat_dev->dev, ctx->bitstream.paddr,
ctx->bitstream.size, DMA_TO_DEVICE);
src_buf->v4l2_buf.sequence = ctx->qsequence++;
return 0;
}
static bool coda_bitstream_try_queue(struct coda_ctx *ctx,
struct vb2_buffer *src_buf)
{
int ret;
if (coda_get_bitstream_payload(ctx) +
vb2_get_plane_payload(src_buf, 0) + 512 >= ctx->bitstream.size)
return false;
if (vb2_plane_vaddr(src_buf, 0) == NULL) {
v4l2_err(&ctx->dev->v4l2_dev, "trying to queue empty buffer\n");
return true;
}
ret = coda_bitstream_queue(ctx, src_buf);
if (ret < 0) {
v4l2_err(&ctx->dev->v4l2_dev, "bitstream buffer overflow\n");
return false;
}
if (ctx == v4l2_m2m_get_curr_priv(ctx->dev->m2m_dev))
coda_kfifo_sync_to_device_write(ctx);
ctx->hold = false;
return true;
}
static void coda_fill_bitstream(struct coda_ctx *ctx)
{
struct vb2_buffer *src_buf;
struct coda_timestamp *ts;
while (v4l2_m2m_num_src_bufs_ready(ctx->fh.m2m_ctx) > 0) {
src_buf = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
if (coda_bitstream_try_queue(ctx, src_buf)) {
src_buf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
ts = kmalloc(sizeof(*ts), GFP_KERNEL);
if (ts) {
ts->sequence = src_buf->v4l2_buf.sequence;
ts->timecode = src_buf->v4l2_buf.timecode;
ts->timestamp = src_buf->v4l2_buf.timestamp;
list_add_tail(&ts->list, &ctx->timestamp_list);
}
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_DONE);
} else {
break;
}
}
}
static void coda_set_gdi_regs(struct coda_ctx *ctx)
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
static int coda_prepare_decode(struct coda_ctx *ctx)
{
struct vb2_buffer *dst_buf;
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data_dst;
u32 stridey, height;
u32 picture_y, picture_cb, picture_cr;
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
if (ctx->params.rot_mode & CODA_ROT_90) {
stridey = q_data_dst->height;
height = q_data_dst->width;
} else {
stridey = q_data_dst->width;
height = q_data_dst->height;
}
mutex_lock(&ctx->bitstream_mutex);
coda_fill_bitstream(ctx);
mutex_unlock(&ctx->bitstream_mutex);
if (coda_get_bitstream_payload(ctx) < 512 &&
(!(ctx->bit_stream_param & CODA_BIT_STREAM_END_FLAG))) {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"bitstream payload: %d, skipping\n",
coda_get_bitstream_payload(ctx));
v4l2_m2m_job_finish(ctx->dev->m2m_dev, ctx->fh.m2m_ctx);
return -EAGAIN;
}
if (!ctx->initialized) {
int ret = coda_start_decoding(ctx);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to start decoding\n");
v4l2_m2m_job_finish(ctx->dev->m2m_dev, ctx->fh.m2m_ctx);
return -EAGAIN;
} else {
ctx->initialized = 1;
}
}
if (dev->devtype->product == CODA_960)
coda_set_gdi_regs(ctx);
picture_y = vb2_dma_contig_plane_dma_addr(dst_buf, 0);
if (q_data_dst->fourcc == V4L2_PIX_FMT_YVU420) {
picture_cr = picture_y + stridey * height;
picture_cb = picture_cr + stridey / 2 * height / 2;
} else {
picture_cb = picture_y + stridey * height;
picture_cr = picture_cb + stridey / 2 * height / 2;
}
if (dev->devtype->product == CODA_960) {
coda_write(dev, CODA_MAX_FRAMEBUFFERS + dst_buf->v4l2_buf.index,
CODA9_CMD_DEC_PIC_ROT_INDEX);
coda_write(dev, picture_y, CODA9_CMD_DEC_PIC_ROT_ADDR_Y);
coda_write(dev, picture_cb, CODA9_CMD_DEC_PIC_ROT_ADDR_CB);
coda_write(dev, picture_cr, CODA9_CMD_DEC_PIC_ROT_ADDR_CR);
coda_write(dev, stridey, CODA9_CMD_DEC_PIC_ROT_STRIDE);
} else {
coda_write(dev, picture_y, CODA_CMD_DEC_PIC_ROT_ADDR_Y);
coda_write(dev, picture_cb, CODA_CMD_DEC_PIC_ROT_ADDR_CB);
coda_write(dev, picture_cr, CODA_CMD_DEC_PIC_ROT_ADDR_CR);
coda_write(dev, stridey, CODA_CMD_DEC_PIC_ROT_STRIDE);
}
coda_write(dev, CODA_ROT_MIR_ENABLE | ctx->params.rot_mode,
CODA_CMD_DEC_PIC_ROT_MODE);
switch (dev->devtype->product) {
case CODA_DX6:
case CODA_7541:
coda_write(dev, CODA_PRE_SCAN_EN, CODA_CMD_DEC_PIC_OPTION);
break;
case CODA_960:
coda_write(dev, (1 << 10), CODA_CMD_DEC_PIC_OPTION);
break;
}
coda_write(dev, 0, CODA_CMD_DEC_PIC_SKIP_NUM);
coda_write(dev, 0, CODA_CMD_DEC_PIC_BB_START);
coda_write(dev, 0, CODA_CMD_DEC_PIC_START_BYTE);
return 0;
}
static void coda_prepare_encode(struct coda_ctx *ctx)
{
struct coda_q_data *q_data_src, *q_data_dst;
struct vb2_buffer *src_buf, *dst_buf;
struct coda_dev *dev = ctx->dev;
int force_ipicture;
int quant_param = 0;
u32 picture_y, picture_cb, picture_cr;
u32 pic_stream_buffer_addr, pic_stream_buffer_size;
u32 dst_fourcc;
src_buf = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
dst_fourcc = q_data_dst->fourcc;
src_buf->v4l2_buf.sequence = ctx->osequence;
dst_buf->v4l2_buf.sequence = ctx->osequence;
ctx->osequence++;
if (src_buf->v4l2_buf.sequence % ctx->params.gop_size) {
src_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_PFRAME;
src_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_KEYFRAME;
} else {
src_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_KEYFRAME;
src_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_PFRAME;
}
if (dev->devtype->product == CODA_960)
coda_set_gdi_regs(ctx);
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
switch (q_data_src->fourcc) {
case V4L2_PIX_FMT_YVU420:
picture_cr = picture_y + q_data_src->bytesperline *
q_data_src->height;
picture_cb = picture_cr + q_data_src->bytesperline / 2 *
q_data_src->height / 2;
break;
case V4L2_PIX_FMT_YUV420:
default:
picture_cb = picture_y + q_data_src->bytesperline *
q_data_src->height;
picture_cr = picture_cb + q_data_src->bytesperline / 2 *
q_data_src->height / 2;
break;
}
if (dev->devtype->product == CODA_960) {
coda_write(dev, 4, CODA9_CMD_ENC_PIC_SRC_INDEX);
coda_write(dev, q_data_src->width, CODA9_CMD_ENC_PIC_SRC_STRIDE);
coda_write(dev, 0, CODA9_CMD_ENC_PIC_SUB_FRAME_SYNC);
coda_write(dev, picture_y, CODA9_CMD_ENC_PIC_SRC_ADDR_Y);
coda_write(dev, picture_cb, CODA9_CMD_ENC_PIC_SRC_ADDR_CB);
coda_write(dev, picture_cr, CODA9_CMD_ENC_PIC_SRC_ADDR_CR);
} else {
coda_write(dev, picture_y, CODA_CMD_ENC_PIC_SRC_ADDR_Y);
coda_write(dev, picture_cb, CODA_CMD_ENC_PIC_SRC_ADDR_CB);
coda_write(dev, picture_cr, CODA_CMD_ENC_PIC_SRC_ADDR_CR);
}
coda_write(dev, force_ipicture << 1 & 0x2,
CODA_CMD_ENC_PIC_OPTION);
coda_write(dev, pic_stream_buffer_addr, CODA_CMD_ENC_PIC_BB_START);
coda_write(dev, pic_stream_buffer_size / 1024,
CODA_CMD_ENC_PIC_BB_SIZE);
if (!ctx->streamon_out) {
ctx->bit_stream_param |= CODA_BIT_STREAM_END_FLAG;
coda_write(dev, ctx->bit_stream_param, CODA_REG_BIT_BIT_STREAM_PARAM);
}
}
static void coda_device_run(void *m2m_priv)
{
struct coda_ctx *ctx = m2m_priv;
struct coda_dev *dev = ctx->dev;
queue_work(dev->workqueue, &ctx->pic_run_work);
}
static void coda_seq_end_work(struct work_struct *work)
{
struct coda_ctx *ctx = container_of(work, struct coda_ctx, seq_end_work);
struct coda_dev *dev = ctx->dev;
mutex_lock(&ctx->buffer_mutex);
mutex_lock(&dev->coda_mutex);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%d: %s: sent command 'SEQ_END' to coda\n", ctx->idx, __func__);
if (coda_command_sync(ctx, CODA_COMMAND_SEQ_END)) {
v4l2_err(&dev->v4l2_dev,
"CODA_COMMAND_SEQ_END failed\n");
}
kfifo_init(&ctx->bitstream_fifo,
ctx->bitstream.vaddr, ctx->bitstream.size);
coda_free_framebuffers(ctx);
coda_free_context_buffers(ctx);
mutex_unlock(&dev->coda_mutex);
mutex_unlock(&ctx->buffer_mutex);
}
static void coda_pic_run_work(struct work_struct *work)
{
struct coda_ctx *ctx = container_of(work, struct coda_ctx, pic_run_work);
struct coda_dev *dev = ctx->dev;
int ret;
mutex_lock(&ctx->buffer_mutex);
mutex_lock(&dev->coda_mutex);
if (ctx->inst_type == CODA_INST_DECODER) {
ret = coda_prepare_decode(ctx);
if (ret < 0) {
mutex_unlock(&dev->coda_mutex);
mutex_unlock(&ctx->buffer_mutex);
return;
}
} else {
coda_prepare_encode(ctx);
}
if (dev->devtype->product != CODA_DX6)
coda_write(dev, ctx->iram_info.axi_sram_use,
CODA7_REG_BIT_AXI_SRAM_USE);
if (ctx->inst_type == CODA_INST_DECODER)
coda_kfifo_sync_to_device_full(ctx);
coda_command_async(ctx, CODA_COMMAND_PIC_RUN);
if (!wait_for_completion_timeout(&ctx->completion, msecs_to_jiffies(1000))) {
dev_err(&dev->plat_dev->dev, "CODA PIC_RUN timeout\n");
ctx->hold = true;
coda_hw_reset(ctx);
} else if (!ctx->aborting) {
if (ctx->inst_type == CODA_INST_DECODER)
coda_finish_decode(ctx);
else
coda_finish_encode(ctx);
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
int max_w;
int max_h;
ctx->codec = &ctx->dev->devtype->codecs[0];
max_w = ctx->codec->max_w;
max_h = ctx->codec->max_h;
ctx->params.codec_mode = CODA_MODE_INVALID;
ctx->colorspace = V4L2_COLORSPACE_REC709;
ctx->params.framerate = 30;
ctx->aborting = 0;
ctx->q_data[V4L2_M2M_SRC].fourcc = ctx->codec->src_fourcc;
ctx->q_data[V4L2_M2M_DST].fourcc = ctx->codec->dst_fourcc;
ctx->q_data[V4L2_M2M_SRC].width = max_w;
ctx->q_data[V4L2_M2M_SRC].height = max_h;
ctx->q_data[V4L2_M2M_SRC].bytesperline = max_w;
ctx->q_data[V4L2_M2M_SRC].sizeimage = (max_w * max_h * 3) / 2;
ctx->q_data[V4L2_M2M_DST].width = max_w;
ctx->q_data[V4L2_M2M_DST].height = max_h;
ctx->q_data[V4L2_M2M_DST].bytesperline = 0;
ctx->q_data[V4L2_M2M_DST].sizeimage = CODA_MAX_FRAME_SIZE;
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
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data;
q_data = get_q_data(ctx, vb->vb2_queue->type);
if (q_data->fourcc == V4L2_PIX_FMT_H264 &&
vb->vb2_queue->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (vb2_get_plane_payload(vb, 0) == 0) {
ctx->bit_stream_param |= CODA_BIT_STREAM_END_FLAG;
if ((dev->devtype->product == CODA_960) &&
coda_isbusy(dev) &&
(ctx->idx == coda_read(dev, CODA_REG_BIT_RUN_INDEX))) {
coda_write(dev, ctx->bit_stream_param, CODA_REG_BIT_BIT_STREAM_PARAM);
}
}
mutex_lock(&ctx->bitstream_mutex);
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
coda_fill_bitstream(ctx);
mutex_unlock(&ctx->bitstream_mutex);
} else {
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
}
}
static void coda_parabuf_write(struct coda_ctx *ctx, int index, u32 value)
{
struct coda_dev *dev = ctx->dev;
u32 *p = ctx->parabuf.vaddr;
if (dev->devtype->product == CODA_DX6)
p[index] = value;
else
p[index ^ 1] = value;
}
static int coda_alloc_aux_buf(struct coda_dev *dev,
struct coda_aux_buf *buf, size_t size,
const char *name, struct dentry *parent)
{
buf->vaddr = dma_alloc_coherent(&dev->plat_dev->dev, size, &buf->paddr,
GFP_KERNEL);
if (!buf->vaddr)
return -ENOMEM;
buf->size = size;
if (name && parent) {
buf->blob.data = buf->vaddr;
buf->blob.size = size;
buf->dentry = debugfs_create_blob(name, 0644, parent, &buf->blob);
if (!buf->dentry)
dev_warn(&dev->plat_dev->dev,
"failed to create debugfs entry %s\n", name);
}
return 0;
}
static inline int coda_alloc_context_buf(struct coda_ctx *ctx,
struct coda_aux_buf *buf, size_t size,
const char *name)
{
return coda_alloc_aux_buf(ctx->dev, buf, size, name, ctx->debugfs_entry);
}
static void coda_free_aux_buf(struct coda_dev *dev,
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
static void coda_free_framebuffers(struct coda_ctx *ctx)
{
int i;
for (i = 0; i < CODA_MAX_FRAMEBUFFERS; i++)
coda_free_aux_buf(ctx->dev, &ctx->internal_frames[i]);
}
static int coda_alloc_framebuffers(struct coda_ctx *ctx, struct coda_q_data *q_data, u32 fourcc)
{
struct coda_dev *dev = ctx->dev;
int width, height;
dma_addr_t paddr;
int ysize;
int ret;
int i;
if (ctx->codec && (ctx->codec->src_fourcc == V4L2_PIX_FMT_H264 ||
ctx->codec->dst_fourcc == V4L2_PIX_FMT_H264)) {
width = round_up(q_data->width, 16);
height = round_up(q_data->height, 16);
} else {
width = round_up(q_data->width, 8);
height = q_data->height;
}
ysize = width * height;
for (i = 0; i < ctx->num_internal_frames; i++) {
size_t size;
char *name;
size = ysize + ysize / 2;
if (ctx->codec->src_fourcc == V4L2_PIX_FMT_H264 &&
dev->devtype->product != CODA_DX6)
size += ysize / 4;
name = kasprintf(GFP_KERNEL, "fb%d", i);
ret = coda_alloc_context_buf(ctx, &ctx->internal_frames[i],
size, name);
kfree(name);
if (ret < 0) {
coda_free_framebuffers(ctx);
return ret;
}
}
for (i = 0; i < ctx->num_internal_frames; i++) {
paddr = ctx->internal_frames[i].paddr;
coda_parabuf_write(ctx, i * 3 + 0, paddr);
coda_parabuf_write(ctx, i * 3 + 1, paddr + ysize);
coda_parabuf_write(ctx, i * 3 + 2, paddr + ysize + ysize/4);
if (ctx->codec->src_fourcc == V4L2_PIX_FMT_H264 &&
dev->devtype->product != CODA_DX6)
coda_parabuf_write(ctx, 96 + i,
ctx->internal_frames[i].paddr +
ysize + ysize/4 + ysize/4);
}
if ((dev->devtype->product != CODA_DX6) &&
(ctx->codec->src_fourcc == V4L2_PIX_FMT_MPEG4))
coda_parabuf_write(ctx, 97, ctx->internal_frames[i].paddr +
ysize + ysize/4 + ysize/4);
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
static phys_addr_t coda_iram_alloc(struct coda_iram_info *iram, size_t size)
{
phys_addr_t ret;
size = round_up(size, 1024);
if (size > iram->remaining)
return 0;
iram->remaining -= size;
ret = iram->next_paddr;
iram->next_paddr += size;
return ret;
}
static void coda_setup_iram(struct coda_ctx *ctx)
{
struct coda_iram_info *iram_info = &ctx->iram_info;
struct coda_dev *dev = ctx->dev;
int mb_width;
int dbk_bits;
int bit_bits;
int ip_bits;
memset(iram_info, 0, sizeof(*iram_info));
iram_info->next_paddr = dev->iram.paddr;
iram_info->remaining = dev->iram.size;
switch (dev->devtype->product) {
case CODA_7541:
dbk_bits = CODA7_USE_HOST_DBK_ENABLE | CODA7_USE_DBK_ENABLE;
bit_bits = CODA7_USE_HOST_BIT_ENABLE | CODA7_USE_BIT_ENABLE;
ip_bits = CODA7_USE_HOST_IP_ENABLE | CODA7_USE_IP_ENABLE;
break;
case CODA_960:
dbk_bits = CODA9_USE_HOST_DBK_ENABLE | CODA9_USE_DBK_ENABLE;
bit_bits = CODA9_USE_HOST_BIT_ENABLE | CODA7_USE_BIT_ENABLE;
ip_bits = CODA9_USE_HOST_IP_ENABLE | CODA7_USE_IP_ENABLE;
break;
default:
return;
}
if (ctx->inst_type == CODA_INST_ENCODER) {
struct coda_q_data *q_data_src;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
mb_width = DIV_ROUND_UP(q_data_src->width, 16);
if (dev->devtype->product == CODA_7541) {
iram_info->search_ram_size = round_up(mb_width * 16 *
36 + 2048, 1024);
iram_info->search_ram_paddr = coda_iram_alloc(iram_info,
iram_info->search_ram_size);
if (!iram_info->search_ram_paddr) {
pr_err("IRAM is smaller than the search ram size\n");
goto out;
}
iram_info->axi_sram_use |= CODA7_USE_HOST_ME_ENABLE |
CODA7_USE_ME_ENABLE;
}
iram_info->buf_dbk_y_use = coda_iram_alloc(iram_info, 64 * mb_width);
iram_info->buf_dbk_c_use = coda_iram_alloc(iram_info, 64 * mb_width);
if (!iram_info->buf_dbk_c_use)
goto out;
iram_info->axi_sram_use |= dbk_bits;
iram_info->buf_bit_use = coda_iram_alloc(iram_info, 128 * mb_width);
if (!iram_info->buf_bit_use)
goto out;
iram_info->axi_sram_use |= bit_bits;
iram_info->buf_ip_ac_dc_use = coda_iram_alloc(iram_info, 128 * mb_width);
if (!iram_info->buf_ip_ac_dc_use)
goto out;
iram_info->axi_sram_use |= ip_bits;
} else if (ctx->inst_type == CODA_INST_DECODER) {
struct coda_q_data *q_data_dst;
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
mb_width = DIV_ROUND_UP(q_data_dst->width, 16);
iram_info->buf_dbk_y_use = coda_iram_alloc(iram_info, 128 * mb_width);
iram_info->buf_dbk_c_use = coda_iram_alloc(iram_info, 128 * mb_width);
if (!iram_info->buf_dbk_c_use)
goto out;
iram_info->axi_sram_use |= dbk_bits;
iram_info->buf_bit_use = coda_iram_alloc(iram_info, 128 * mb_width);
if (!iram_info->buf_bit_use)
goto out;
iram_info->axi_sram_use |= bit_bits;
iram_info->buf_ip_ac_dc_use = coda_iram_alloc(iram_info, 128 * mb_width);
if (!iram_info->buf_ip_ac_dc_use)
goto out;
iram_info->axi_sram_use |= ip_bits;
}
out:
if (!(iram_info->axi_sram_use & CODA7_USE_HOST_IP_ENABLE))
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"IRAM smaller than needed\n");
if (dev->devtype->product == CODA_7541) {
if (ctx->inst_type == CODA_INST_DECODER) {
iram_info->axi_sram_use &= ~(CODA7_USE_HOST_IP_ENABLE |
CODA7_USE_IP_ENABLE);
} else {
iram_info->axi_sram_use &= ~(CODA7_USE_HOST_IP_ENABLE |
CODA7_USE_HOST_DBK_ENABLE |
CODA7_USE_IP_ENABLE |
CODA7_USE_DBK_ENABLE);
}
}
}
static void coda_free_context_buffers(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
coda_free_aux_buf(dev, &ctx->slicebuf);
coda_free_aux_buf(dev, &ctx->psbuf);
if (dev->devtype->product != CODA_DX6)
coda_free_aux_buf(dev, &ctx->workbuf);
}
static int coda_alloc_context_buffers(struct coda_ctx *ctx,
struct coda_q_data *q_data)
{
struct coda_dev *dev = ctx->dev;
size_t size;
int ret;
if (dev->devtype->product == CODA_DX6)
return 0;
if (ctx->psbuf.vaddr) {
v4l2_err(&dev->v4l2_dev, "psmembuf still allocated\n");
return -EBUSY;
}
if (ctx->slicebuf.vaddr) {
v4l2_err(&dev->v4l2_dev, "slicebuf still allocated\n");
return -EBUSY;
}
if (ctx->workbuf.vaddr) {
v4l2_err(&dev->v4l2_dev, "context buffer still allocated\n");
ret = -EBUSY;
return -ENOMEM;
}
if (q_data->fourcc == V4L2_PIX_FMT_H264) {
size = (DIV_ROUND_UP(q_data->width, 16) *
DIV_ROUND_UP(q_data->height, 16)) * 3200 / 8 + 512;
ret = coda_alloc_context_buf(ctx, &ctx->slicebuf, size, "slicebuf");
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to allocate %d byte slice buffer",
ctx->slicebuf.size);
return ret;
}
}
if (dev->devtype->product == CODA_7541) {
ret = coda_alloc_context_buf(ctx, &ctx->psbuf, CODA7_PS_BUF_SIZE, "psbuf");
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to allocate psmem buffer");
goto err;
}
}
size = dev->devtype->workbuf_size;
if (dev->devtype->product == CODA_960 &&
q_data->fourcc == V4L2_PIX_FMT_H264)
size += CODA9_PS_SAVE_SIZE;
ret = coda_alloc_context_buf(ctx, &ctx->workbuf, size, "workbuf");
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to allocate %d byte context buffer",
ctx->workbuf.size);
goto err;
}
return 0;
err:
coda_free_context_buffers(ctx);
return ret;
}
static int coda_start_decoding(struct coda_ctx *ctx)
{
struct coda_q_data *q_data_src, *q_data_dst;
u32 bitstream_buf, bitstream_size;
struct coda_dev *dev = ctx->dev;
int width, height;
u32 src_fourcc;
u32 val;
int ret;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
bitstream_buf = ctx->bitstream.paddr;
bitstream_size = ctx->bitstream.size;
src_fourcc = q_data_src->fourcc;
coda_write(dev, ctx->parabuf.paddr, CODA_REG_BIT_PARA_BUF_ADDR);
coda_kfifo_sync_to_device_full(ctx);
ctx->display_idx = -1;
ctx->frm_dis_flg = 0;
coda_write(dev, 0, CODA_REG_BIT_FRM_DIS_FLG(ctx->reg_idx));
coda_write(dev, CODA_BIT_DEC_SEQ_INIT_ESCAPE,
CODA_REG_BIT_BIT_STREAM_PARAM);
coda_write(dev, bitstream_buf, CODA_CMD_DEC_SEQ_BB_START);
coda_write(dev, bitstream_size / 1024, CODA_CMD_DEC_SEQ_BB_SIZE);
val = 0;
if ((dev->devtype->product == CODA_7541) ||
(dev->devtype->product == CODA_960))
val |= CODA_REORDER_ENABLE;
coda_write(dev, val, CODA_CMD_DEC_SEQ_OPTION);
ctx->params.codec_mode = ctx->codec->mode;
if (dev->devtype->product == CODA_960 &&
src_fourcc == V4L2_PIX_FMT_MPEG4)
ctx->params.codec_mode_aux = CODA_MP4_AUX_MPEG4;
else
ctx->params.codec_mode_aux = 0;
if (src_fourcc == V4L2_PIX_FMT_H264) {
if (dev->devtype->product == CODA_7541) {
coda_write(dev, ctx->psbuf.paddr,
CODA_CMD_DEC_SEQ_PS_BB_START);
coda_write(dev, (CODA7_PS_BUF_SIZE / 1024),
CODA_CMD_DEC_SEQ_PS_BB_SIZE);
}
if (dev->devtype->product == CODA_960) {
coda_write(dev, 0, CODA_CMD_DEC_SEQ_X264_MV_EN);
coda_write(dev, 512, CODA_CMD_DEC_SEQ_SPP_CHUNK_SIZE);
}
}
if (dev->devtype->product != CODA_960) {
coda_write(dev, 0, CODA_CMD_DEC_SEQ_SRC_SIZE);
}
if (coda_command_sync(ctx, CODA_COMMAND_SEQ_INIT)) {
v4l2_err(&dev->v4l2_dev, "CODA_COMMAND_SEQ_INIT timeout\n");
coda_write(dev, 0, CODA_REG_BIT_BIT_STREAM_PARAM);
return -ETIMEDOUT;
}
coda_kfifo_sync_from_device(ctx);
coda_write(dev, 0, CODA_REG_BIT_BIT_STREAM_PARAM);
if (coda_read(dev, CODA_RET_DEC_SEQ_SUCCESS) == 0) {
v4l2_err(&dev->v4l2_dev,
"CODA_COMMAND_SEQ_INIT failed, error code = %d\n",
coda_read(dev, CODA_RET_DEC_SEQ_ERR_REASON));
return -EAGAIN;
}
val = coda_read(dev, CODA_RET_DEC_SEQ_SRC_SIZE);
if (dev->devtype->product == CODA_DX6) {
width = (val >> CODADX6_PICWIDTH_OFFSET) & CODADX6_PICWIDTH_MASK;
height = val & CODADX6_PICHEIGHT_MASK;
} else {
width = (val >> CODA7_PICWIDTH_OFFSET) & CODA7_PICWIDTH_MASK;
height = val & CODA7_PICHEIGHT_MASK;
}
if (width > q_data_dst->width || height > q_data_dst->height) {
v4l2_err(&dev->v4l2_dev, "stream is %dx%d, not %dx%d\n",
width, height, q_data_dst->width, q_data_dst->height);
return -EINVAL;
}
width = round_up(width, 16);
height = round_up(height, 16);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev, "%s instance %d now: %dx%d\n",
__func__, ctx->idx, width, height);
ctx->num_internal_frames = coda_read(dev, CODA_RET_DEC_SEQ_FRAME_NEED);
if (ctx->num_internal_frames > CODA_MAX_FRAMEBUFFERS) {
v4l2_err(&dev->v4l2_dev,
"not enough framebuffers to decode (%d < %d)\n",
CODA_MAX_FRAMEBUFFERS, ctx->num_internal_frames);
return -EINVAL;
}
if (src_fourcc == V4L2_PIX_FMT_H264) {
u32 left_right;
u32 top_bottom;
left_right = coda_read(dev, CODA_RET_DEC_SEQ_CROP_LEFT_RIGHT);
top_bottom = coda_read(dev, CODA_RET_DEC_SEQ_CROP_TOP_BOTTOM);
q_data_dst->rect.left = (left_right >> 10) & 0x3ff;
q_data_dst->rect.top = (top_bottom >> 10) & 0x3ff;
q_data_dst->rect.width = width - q_data_dst->rect.left -
(left_right & 0x3ff);
q_data_dst->rect.height = height - q_data_dst->rect.top -
(top_bottom & 0x3ff);
}
ret = coda_alloc_framebuffers(ctx, q_data_dst, src_fourcc);
if (ret < 0)
return ret;
coda_write(dev, ctx->num_internal_frames, CODA_CMD_SET_FRAME_BUF_NUM);
coda_write(dev, width, CODA_CMD_SET_FRAME_BUF_STRIDE);
if (dev->devtype->product != CODA_DX6) {
coda_setup_iram(ctx);
coda_write(dev, ctx->iram_info.buf_bit_use,
CODA7_CMD_SET_FRAME_AXI_BIT_ADDR);
coda_write(dev, ctx->iram_info.buf_ip_ac_dc_use,
CODA7_CMD_SET_FRAME_AXI_IPACDC_ADDR);
coda_write(dev, ctx->iram_info.buf_dbk_y_use,
CODA7_CMD_SET_FRAME_AXI_DBKY_ADDR);
coda_write(dev, ctx->iram_info.buf_dbk_c_use,
CODA7_CMD_SET_FRAME_AXI_DBKC_ADDR);
coda_write(dev, ctx->iram_info.buf_ovl_use,
CODA7_CMD_SET_FRAME_AXI_OVL_ADDR);
if (dev->devtype->product == CODA_960)
coda_write(dev, ctx->iram_info.buf_btp_use,
CODA9_CMD_SET_FRAME_AXI_BTP_ADDR);
}
if (dev->devtype->product == CODA_960) {
coda_write(dev, -1, CODA9_CMD_SET_FRAME_DELAY);
coda_write(dev, 0x20262024, CODA9_CMD_SET_FRAME_CACHE_SIZE);
coda_write(dev, 2 << CODA9_CACHE_PAGEMERGE_OFFSET |
32 << CODA9_CACHE_LUMA_BUFFER_SIZE_OFFSET |
8 << CODA9_CACHE_CB_BUFFER_SIZE_OFFSET |
8 << CODA9_CACHE_CR_BUFFER_SIZE_OFFSET,
CODA9_CMD_SET_FRAME_CACHE_CONFIG);
}
if (src_fourcc == V4L2_PIX_FMT_H264) {
coda_write(dev, ctx->slicebuf.paddr,
CODA_CMD_SET_FRAME_SLICE_BB_START);
coda_write(dev, ctx->slicebuf.size / 1024,
CODA_CMD_SET_FRAME_SLICE_BB_SIZE);
}
if (dev->devtype->product == CODA_7541) {
int max_mb_x = 1920 / 16;
int max_mb_y = 1088 / 16;
int max_mb_num = max_mb_x * max_mb_y;
coda_write(dev, max_mb_num << 16 | max_mb_x << 8 | max_mb_y,
CODA7_CMD_SET_FRAME_MAX_DEC_SIZE);
} else if (dev->devtype->product == CODA_960) {
int max_mb_x = 1920 / 16;
int max_mb_y = 1088 / 16;
int max_mb_num = max_mb_x * max_mb_y;
coda_write(dev, max_mb_num << 16 | max_mb_x << 8 | max_mb_y,
CODA9_CMD_SET_FRAME_MAX_DEC_SIZE);
}
if (coda_command_sync(ctx, CODA_COMMAND_SET_FRAME_BUF)) {
v4l2_err(&ctx->dev->v4l2_dev,
"CODA_COMMAND_SET_FRAME_BUF timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int coda_encode_header(struct coda_ctx *ctx, struct vb2_buffer *buf,
int header_code, u8 *header, int *size)
{
struct coda_dev *dev = ctx->dev;
size_t bufsize;
int ret;
int i;
if (dev->devtype->product == CODA_960)
memset(vb2_plane_vaddr(buf, 0), 0, 64);
coda_write(dev, vb2_dma_contig_plane_dma_addr(buf, 0),
CODA_CMD_ENC_HEADER_BB_START);
bufsize = vb2_plane_size(buf, 0);
if (dev->devtype->product == CODA_960)
bufsize /= 1024;
coda_write(dev, bufsize, CODA_CMD_ENC_HEADER_BB_SIZE);
coda_write(dev, header_code, CODA_CMD_ENC_HEADER_CODE);
ret = coda_command_sync(ctx, CODA_COMMAND_ENCODE_HEADER);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "CODA_COMMAND_ENCODE_HEADER timeout\n");
return ret;
}
if (dev->devtype->product == CODA_960) {
for (i = 63; i > 0; i--)
if (((char *)vb2_plane_vaddr(buf, 0))[i] != 0)
break;
*size = i + 1;
} else {
*size = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->reg_idx)) -
coda_read(dev, CODA_CMD_ENC_HEADER_BB_START);
}
memcpy(header, vb2_plane_vaddr(buf, 0), *size);
return 0;
}
static int coda_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct v4l2_device *v4l2_dev = &ctx->dev->v4l2_dev;
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data_src, *q_data_dst;
u32 dst_fourcc;
int ret = 0;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (q_data_src->fourcc == V4L2_PIX_FMT_H264) {
if (coda_get_bitstream_payload(ctx) < 512)
return -EINVAL;
} else {
if (count < 1)
return -EINVAL;
}
ctx->streamon_out = 1;
if (coda_format_is_yuv(q_data_src->fourcc))
ctx->inst_type = CODA_INST_ENCODER;
else
ctx->inst_type = CODA_INST_DECODER;
} else {
if (count < 1)
return -EINVAL;
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
return -EINVAL;
}
ret = coda_alloc_context_buffers(ctx, q_data_src);
if (ret < 0)
return ret;
if (ctx->inst_type == CODA_INST_DECODER) {
mutex_lock(&dev->coda_mutex);
ret = coda_start_decoding(ctx);
mutex_unlock(&dev->coda_mutex);
if (ret == -EAGAIN)
return 0;
else if (ret < 0)
return ret;
} else {
ret = coda_start_encoding(ctx);
}
ctx->initialized = 1;
return ret;
}
static int coda_start_encoding(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
struct v4l2_device *v4l2_dev = &dev->v4l2_dev;
struct coda_q_data *q_data_src, *q_data_dst;
u32 bitstream_buf, bitstream_size;
struct vb2_buffer *buf;
int gamma, ret, value;
u32 dst_fourcc;
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
dst_fourcc = q_data_dst->fourcc;
buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
bitstream_buf = vb2_dma_contig_plane_dma_addr(buf, 0);
bitstream_size = q_data_dst->sizeimage;
if (!coda_is_initialized(dev)) {
v4l2_err(v4l2_dev, "coda is not initialized.\n");
return -EFAULT;
}
mutex_lock(&dev->coda_mutex);
coda_write(dev, ctx->parabuf.paddr, CODA_REG_BIT_PARA_BUF_ADDR);
coda_write(dev, bitstream_buf, CODA_REG_BIT_RD_PTR(ctx->reg_idx));
coda_write(dev, bitstream_buf, CODA_REG_BIT_WR_PTR(ctx->reg_idx));
switch (dev->devtype->product) {
case CODA_DX6:
coda_write(dev, CODADX6_STREAM_BUF_DYNALLOC_EN |
CODADX6_STREAM_BUF_PIC_RESET, CODA_REG_BIT_STREAM_CTRL);
break;
case CODA_960:
coda_write(dev, 0, CODA9_GDI_WPROT_RGN_EN);
case CODA_7541:
coda_write(dev, CODA7_STREAM_BUF_DYNALLOC_EN |
CODA7_STREAM_BUF_PIC_RESET, CODA_REG_BIT_STREAM_CTRL);
break;
}
value = coda_read(dev, CODA_REG_BIT_FRAME_MEM_CTRL);
value &= ~(1 << 2 | 0x7 << 9);
ctx->frame_mem_ctrl = value;
coda_write(dev, value, CODA_REG_BIT_FRAME_MEM_CTRL);
if (dev->devtype->product == CODA_DX6) {
coda_write(dev, dev->iram.paddr, CODADX6_REG_BIT_SEARCH_RAM_BASE_ADDR);
}
switch (dev->devtype->product) {
case CODA_DX6:
value = (q_data_src->width & CODADX6_PICWIDTH_MASK) << CODADX6_PICWIDTH_OFFSET;
value |= (q_data_src->height & CODADX6_PICHEIGHT_MASK) << CODA_PICHEIGHT_OFFSET;
break;
case CODA_7541:
if (dst_fourcc == V4L2_PIX_FMT_H264) {
value = (round_up(q_data_src->width, 16) &
CODA7_PICWIDTH_MASK) << CODA7_PICWIDTH_OFFSET;
value |= (round_up(q_data_src->height, 16) &
CODA7_PICHEIGHT_MASK) << CODA_PICHEIGHT_OFFSET;
break;
}
case CODA_960:
value = (q_data_src->width & CODA7_PICWIDTH_MASK) << CODA7_PICWIDTH_OFFSET;
value |= (q_data_src->height & CODA7_PICHEIGHT_MASK) << CODA_PICHEIGHT_OFFSET;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_SRC_SIZE);
coda_write(dev, ctx->params.framerate,
CODA_CMD_ENC_SEQ_SRC_F_RATE);
ctx->params.codec_mode = ctx->codec->mode;
switch (dst_fourcc) {
case V4L2_PIX_FMT_MPEG4:
if (dev->devtype->product == CODA_960)
coda_write(dev, CODA9_STD_MPEG4, CODA_CMD_ENC_SEQ_COD_STD);
else
coda_write(dev, CODA_STD_MPEG4, CODA_CMD_ENC_SEQ_COD_STD);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_MP4_PARA);
break;
case V4L2_PIX_FMT_H264:
if (dev->devtype->product == CODA_960)
coda_write(dev, CODA9_STD_H264, CODA_CMD_ENC_SEQ_COD_STD);
else
coda_write(dev, CODA_STD_H264, CODA_CMD_ENC_SEQ_COD_STD);
if (ctx->params.h264_deblk_enabled) {
value = ((ctx->params.h264_deblk_alpha &
CODA_264PARAM_DEBLKFILTEROFFSETALPHA_MASK) <<
CODA_264PARAM_DEBLKFILTEROFFSETALPHA_OFFSET) |
((ctx->params.h264_deblk_beta &
CODA_264PARAM_DEBLKFILTEROFFSETBETA_MASK) <<
CODA_264PARAM_DEBLKFILTEROFFSETBETA_OFFSET);
} else {
value = 1 << CODA_264PARAM_DISABLEDEBLK_OFFSET;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_264_PARA);
break;
default:
v4l2_err(v4l2_dev,
"dst format (0x%08x) invalid.\n", dst_fourcc);
ret = -EINVAL;
goto out;
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
if (dev->devtype->product == CODA_960)
value |= BIT(31);
} else {
value = 0;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_RC_PARA);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_RC_BUF_SIZE);
coda_write(dev, ctx->params.intra_refresh,
CODA_CMD_ENC_SEQ_INTRA_REFRESH);
coda_write(dev, bitstream_buf, CODA_CMD_ENC_SEQ_BB_START);
coda_write(dev, bitstream_size / 1024, CODA_CMD_ENC_SEQ_BB_SIZE);
value = 0;
if (dev->devtype->product == CODA_960)
gamma = CODA9_DEFAULT_GAMMA;
else
gamma = CODA_DEFAULT_GAMMA;
if (gamma > 0) {
coda_write(dev, (gamma & CODA_GAMMA_MASK) << CODA_GAMMA_OFFSET,
CODA_CMD_ENC_SEQ_RC_GAMMA);
}
if (ctx->params.h264_min_qp || ctx->params.h264_max_qp) {
coda_write(dev,
ctx->params.h264_min_qp << CODA_QPMIN_OFFSET |
ctx->params.h264_max_qp << CODA_QPMAX_OFFSET,
CODA_CMD_ENC_SEQ_RC_QP_MIN_MAX);
}
if (dev->devtype->product == CODA_960) {
if (ctx->params.h264_max_qp)
value |= 1 << CODA9_OPTION_RCQPMAX_OFFSET;
if (CODA_DEFAULT_GAMMA > 0)
value |= 1 << CODA9_OPTION_GAMMA_OFFSET;
} else {
if (CODA_DEFAULT_GAMMA > 0) {
if (dev->devtype->product == CODA_DX6)
value |= 1 << CODADX6_OPTION_GAMMA_OFFSET;
else
value |= 1 << CODA7_OPTION_GAMMA_OFFSET;
}
if (ctx->params.h264_min_qp)
value |= 1 << CODA7_OPTION_RCQPMIN_OFFSET;
if (ctx->params.h264_max_qp)
value |= 1 << CODA7_OPTION_RCQPMAX_OFFSET;
}
coda_write(dev, value, CODA_CMD_ENC_SEQ_OPTION);
coda_write(dev, 0, CODA_CMD_ENC_SEQ_RC_INTERVAL_MODE);
coda_setup_iram(ctx);
if (dst_fourcc == V4L2_PIX_FMT_H264) {
switch (dev->devtype->product) {
case CODA_DX6:
value = FMO_SLICE_SAVE_BUF_SIZE << 7;
coda_write(dev, value, CODADX6_CMD_ENC_SEQ_FMO);
break;
case CODA_7541:
coda_write(dev, ctx->iram_info.search_ram_paddr,
CODA7_CMD_ENC_SEQ_SEARCH_BASE);
coda_write(dev, ctx->iram_info.search_ram_size,
CODA7_CMD_ENC_SEQ_SEARCH_SIZE);
break;
case CODA_960:
coda_write(dev, 0, CODA9_CMD_ENC_SEQ_ME_OPTION);
coda_write(dev, 0, CODA9_CMD_ENC_SEQ_INTRA_WEIGHT);
}
}
ret = coda_command_sync(ctx, CODA_COMMAND_SEQ_INIT);
if (ret < 0) {
v4l2_err(v4l2_dev, "CODA_COMMAND_SEQ_INIT timeout\n");
goto out;
}
if (coda_read(dev, CODA_RET_ENC_SEQ_SUCCESS) == 0) {
v4l2_err(v4l2_dev, "CODA_COMMAND_SEQ_INIT failed\n");
ret = -EFAULT;
goto out;
}
if (dev->devtype->product == CODA_960)
ctx->num_internal_frames = 4;
else
ctx->num_internal_frames = 2;
ret = coda_alloc_framebuffers(ctx, q_data_src, dst_fourcc);
if (ret < 0) {
v4l2_err(v4l2_dev, "failed to allocate framebuffers\n");
goto out;
}
coda_write(dev, ctx->num_internal_frames, CODA_CMD_SET_FRAME_BUF_NUM);
coda_write(dev, q_data_src->bytesperline,
CODA_CMD_SET_FRAME_BUF_STRIDE);
if (dev->devtype->product == CODA_7541) {
coda_write(dev, q_data_src->bytesperline,
CODA7_CMD_SET_FRAME_SOURCE_BUF_STRIDE);
}
if (dev->devtype->product != CODA_DX6) {
coda_write(dev, ctx->iram_info.buf_bit_use,
CODA7_CMD_SET_FRAME_AXI_BIT_ADDR);
coda_write(dev, ctx->iram_info.buf_ip_ac_dc_use,
CODA7_CMD_SET_FRAME_AXI_IPACDC_ADDR);
coda_write(dev, ctx->iram_info.buf_dbk_y_use,
CODA7_CMD_SET_FRAME_AXI_DBKY_ADDR);
coda_write(dev, ctx->iram_info.buf_dbk_c_use,
CODA7_CMD_SET_FRAME_AXI_DBKC_ADDR);
coda_write(dev, ctx->iram_info.buf_ovl_use,
CODA7_CMD_SET_FRAME_AXI_OVL_ADDR);
if (dev->devtype->product == CODA_960) {
coda_write(dev, ctx->iram_info.buf_btp_use,
CODA9_CMD_SET_FRAME_AXI_BTP_ADDR);
coda_write(dev, ctx->internal_frames[2].paddr, CODA9_CMD_SET_FRAME_SUBSAMP_A);
coda_write(dev, ctx->internal_frames[3].paddr, CODA9_CMD_SET_FRAME_SUBSAMP_B);
}
}
ret = coda_command_sync(ctx, CODA_COMMAND_SET_FRAME_BUF);
if (ret < 0) {
v4l2_err(v4l2_dev, "CODA_COMMAND_SET_FRAME_BUF timeout\n");
goto out;
}
buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
switch (dst_fourcc) {
case V4L2_PIX_FMT_H264:
ret = coda_encode_header(ctx, buf, CODA_HEADER_H264_SPS,
&ctx->vpu_header[0][0],
&ctx->vpu_header_size[0]);
if (ret < 0)
goto out;
ret = coda_encode_header(ctx, buf, CODA_HEADER_H264_PPS,
&ctx->vpu_header[1][0],
&ctx->vpu_header_size[1]);
if (ret < 0)
goto out;
ctx->vpu_header_size[2] = coda_h264_padding(
(ctx->vpu_header_size[0] +
ctx->vpu_header_size[1]),
ctx->vpu_header[2]);
break;
case V4L2_PIX_FMT_MPEG4:
ret = coda_encode_header(ctx, buf, CODA_HEADER_MP4V_VOS,
&ctx->vpu_header[0][0],
&ctx->vpu_header_size[0]);
if (ret < 0)
goto out;
ret = coda_encode_header(ctx, buf, CODA_HEADER_MP4V_VIS,
&ctx->vpu_header[1][0],
&ctx->vpu_header_size[1]);
if (ret < 0)
goto out;
ret = coda_encode_header(ctx, buf, CODA_HEADER_MP4V_VOL,
&ctx->vpu_header[2][0],
&ctx->vpu_header_size[2]);
if (ret < 0)
goto out;
break;
default:
break;
}
out:
mutex_unlock(&dev->coda_mutex);
return ret;
}
static void coda_stop_streaming(struct vb2_queue *q)
{
struct coda_ctx *ctx = vb2_get_drv_priv(q);
struct coda_dev *dev = ctx->dev;
if (q->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: output\n", __func__);
ctx->streamon_out = 0;
if (ctx->inst_type == CODA_INST_DECODER &&
coda_isbusy(dev) && ctx->idx == coda_read(dev, CODA_REG_BIT_RUN_INDEX)) {
if (dev->devtype->product == CODA_960) {
u32 val = coda_read(dev, CODA_REG_BIT_BIT_STREAM_PARAM);
val |= CODA_BIT_STREAM_END_FLAG;
coda_write(dev, val, CODA_REG_BIT_BIT_STREAM_PARAM);
ctx->bit_stream_param = val;
}
}
ctx->bit_stream_param |= CODA_BIT_STREAM_END_FLAG;
ctx->isequence = 0;
} else {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"%s: capture\n", __func__);
ctx->streamon_cap = 0;
ctx->osequence = 0;
ctx->sequence_offset = 0;
}
if (!ctx->streamon_out && !ctx->streamon_cap) {
struct coda_timestamp *ts;
while (!list_empty(&ctx->timestamp_list)) {
ts = list_first_entry(&ctx->timestamp_list,
struct coda_timestamp, list);
list_del(&ts->list);
kfree(ts);
}
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
V4L2_CID_MPEG_VIDEO_MULTI_SLICE_MAX_BYTES, 1, 0x3fffffff, 1, 500);
v4l2_ctrl_new_std_menu(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_HEADER_MODE,
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME,
(1 << V4L2_MPEG_VIDEO_HEADER_MODE_SEPARATE),
V4L2_MPEG_VIDEO_HEADER_MODE_JOINED_WITH_1ST_FRAME);
v4l2_ctrl_new_std(&ctx->ctrls, &coda_ctrl_ops,
V4L2_CID_MPEG_VIDEO_CYCLIC_INTRA_REFRESH_MB, 0, 1920 * 1088 / 256, 1, 0);
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
src_vq->io_modes = VB2_DMABUF | VB2_MMAP | VB2_USERPTR;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
src_vq->ops = &coda_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
src_vq->lock = &ctx->dev->dev_mutex;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_DMABUF | VB2_MMAP | VB2_USERPTR;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
dst_vq->ops = &coda_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
dst_vq->lock = &ctx->dev->dev_mutex;
return vb2_queue_init(dst_vq);
}
static int coda_next_free_instance(struct coda_dev *dev)
{
int idx = ffz(dev->instance_mask);
if ((idx < 0) ||
(dev->devtype->product == CODA_DX6 && idx > CODADX6_MAX_INSTANCES))
return -EBUSY;
return idx;
}
static int coda_open(struct file *file)
{
struct coda_dev *dev = video_drvdata(file);
struct coda_ctx *ctx = NULL;
char *name;
int ret;
int idx;
ctx = kzalloc(sizeof *ctx, GFP_KERNEL);
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
init_completion(&ctx->completion);
INIT_WORK(&ctx->pic_run_work, coda_pic_run_work);
INIT_WORK(&ctx->seq_end_work, coda_seq_end_work);
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
&coda_queue_init);
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
v4l2_err(&dev->v4l2_dev, "failed to allocate bitstream ringbuffer");
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
coda_free_context_buffers(ctx);
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
coda_free_framebuffers(ctx);
coda_lock(ctx);
list_del(&ctx->list);
coda_unlock(ctx);
dma_free_writecombine(&dev->plat_dev->dev, ctx->bitstream.size,
ctx->bitstream.vaddr, ctx->bitstream.paddr);
coda_free_context_buffers(ctx);
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
kfree(ctx);
return 0;
}
static void coda_finish_decode(struct coda_ctx *ctx)
{
struct coda_dev *dev = ctx->dev;
struct coda_q_data *q_data_src;
struct coda_q_data *q_data_dst;
struct vb2_buffer *dst_buf;
struct coda_timestamp *ts;
int width, height;
int decoded_idx;
int display_idx;
u32 src_fourcc;
int success;
u32 err_mb;
u32 val;
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
coda_kfifo_sync_from_device(ctx);
if (ctx->bit_stream_param & CODA_BIT_STREAM_END_FLAG) {
if (coda_get_bitstream_payload(ctx) >= 0x100000 - 512)
kfifo_init(&ctx->bitstream_fifo,
ctx->bitstream.vaddr, ctx->bitstream.size);
}
q_data_src = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
src_fourcc = q_data_src->fourcc;
val = coda_read(dev, CODA_RET_DEC_PIC_SUCCESS);
if (val != 1)
pr_err("DEC_PIC_SUCCESS = %d\n", val);
success = val & 0x1;
if (!success)
v4l2_err(&dev->v4l2_dev, "decode failed\n");
if (src_fourcc == V4L2_PIX_FMT_H264) {
if (val & (1 << 3))
v4l2_err(&dev->v4l2_dev,
"insufficient PS buffer space (%d bytes)\n",
ctx->psbuf.size);
if (val & (1 << 2))
v4l2_err(&dev->v4l2_dev,
"insufficient slice buffer space (%d bytes)\n",
ctx->slicebuf.size);
}
val = coda_read(dev, CODA_RET_DEC_PIC_SIZE);
width = (val >> 16) & 0xffff;
height = val & 0xffff;
q_data_dst = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
if (src_fourcc == V4L2_PIX_FMT_H264) {
u32 left_right;
u32 top_bottom;
left_right = coda_read(dev, CODA_RET_DEC_PIC_CROP_LEFT_RIGHT);
top_bottom = coda_read(dev, CODA_RET_DEC_PIC_CROP_TOP_BOTTOM);
if (left_right == 0xffffffff && top_bottom == 0xffffffff) {
} else {
struct v4l2_rect *rect = &q_data_dst->rect;
rect->left = left_right >> 16 & 0xffff;
rect->top = top_bottom >> 16 & 0xffff;
rect->width = width - rect->left -
(left_right & 0xffff);
rect->height = height - rect->top -
(top_bottom & 0xffff);
}
} else {
}
err_mb = coda_read(dev, CODA_RET_DEC_PIC_ERR_MB);
if (err_mb > 0)
v4l2_err(&dev->v4l2_dev,
"errors in %d macroblocks\n", err_mb);
if (dev->devtype->product == CODA_7541) {
val = coda_read(dev, CODA_RET_DEC_PIC_OPTION);
if (val == 0) {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"prescan failed: %d\n", val);
ctx->hold = true;
return;
}
}
ctx->frm_dis_flg = coda_read(dev, CODA_REG_BIT_FRM_DIS_FLG(ctx->reg_idx));
if (ctx->display_idx >= 0 &&
ctx->display_idx < ctx->num_internal_frames) {
ctx->frm_dis_flg &= ~(1 << ctx->display_idx);
coda_write(dev, ctx->frm_dis_flg,
CODA_REG_BIT_FRM_DIS_FLG(ctx->reg_idx));
}
decoded_idx = coda_read(dev, CODA_RET_DEC_PIC_CUR_IDX);
display_idx = coda_read(dev, CODA_RET_DEC_PIC_FRAME_IDX);
if (decoded_idx == -1) {
if (display_idx >= 0 && display_idx < ctx->num_internal_frames)
ctx->sequence_offset++;
else if (ctx->display_idx < 0)
ctx->hold = true;
} else if (decoded_idx == -2) {
} else if (decoded_idx < 0 || decoded_idx >= ctx->num_internal_frames) {
v4l2_err(&dev->v4l2_dev,
"decoded frame index out of range: %d\n", decoded_idx);
} else {
ts = list_first_entry(&ctx->timestamp_list,
struct coda_timestamp, list);
list_del(&ts->list);
val = coda_read(dev, CODA_RET_DEC_PIC_FRAME_NUM) - 1;
val -= ctx->sequence_offset;
if (val != (ts->sequence & 0xffff)) {
v4l2_err(&dev->v4l2_dev,
"sequence number mismatch (%d(%d) != %d)\n",
val, ctx->sequence_offset, ts->sequence);
}
ctx->frame_timestamps[decoded_idx] = *ts;
kfree(ts);
val = coda_read(dev, CODA_RET_DEC_PIC_TYPE) & 0x7;
if (val == 0)
ctx->frame_types[decoded_idx] = V4L2_BUF_FLAG_KEYFRAME;
else if (val == 1)
ctx->frame_types[decoded_idx] = V4L2_BUF_FLAG_PFRAME;
else
ctx->frame_types[decoded_idx] = V4L2_BUF_FLAG_BFRAME;
ctx->frame_errors[decoded_idx] = err_mb;
}
if (display_idx == -1) {
ctx->hold = true;
} else if (display_idx == -3) {
} else if (display_idx < 0 || display_idx >= ctx->num_internal_frames) {
v4l2_err(&dev->v4l2_dev,
"presentation frame index out of range: %d\n",
display_idx);
}
if (ctx->display_idx >= 0 &&
ctx->display_idx < ctx->num_internal_frames) {
dst_buf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
dst_buf->v4l2_buf.sequence = ctx->osequence++;
dst_buf->v4l2_buf.flags &= ~(V4L2_BUF_FLAG_KEYFRAME |
V4L2_BUF_FLAG_PFRAME |
V4L2_BUF_FLAG_BFRAME);
dst_buf->v4l2_buf.flags |= ctx->frame_types[ctx->display_idx];
ts = &ctx->frame_timestamps[ctx->display_idx];
dst_buf->v4l2_buf.timecode = ts->timecode;
dst_buf->v4l2_buf.timestamp = ts->timestamp;
vb2_set_plane_payload(dst_buf, 0, width * height * 3 / 2);
v4l2_m2m_buf_done(dst_buf, ctx->frame_errors[display_idx] ?
VB2_BUF_STATE_ERROR : VB2_BUF_STATE_DONE);
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"job finished: decoding frame (%d) (%s)\n",
dst_buf->v4l2_buf.sequence,
(dst_buf->v4l2_buf.flags & V4L2_BUF_FLAG_KEYFRAME) ?
"KEYFRAME" : "PFRAME");
} else {
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"job finished: no frame decoded\n");
}
ctx->display_idx = display_idx;
}
static void coda_finish_encode(struct coda_ctx *ctx)
{
struct vb2_buffer *src_buf, *dst_buf;
struct coda_dev *dev = ctx->dev;
u32 wr_ptr, start_ptr;
src_buf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
start_ptr = coda_read(dev, CODA_CMD_ENC_PIC_BB_START);
wr_ptr = coda_read(dev, CODA_REG_BIT_WR_PTR(ctx->reg_idx));
if (dst_buf->v4l2_buf.sequence == 0) {
vb2_set_plane_payload(dst_buf, 0, wr_ptr - start_ptr +
ctx->vpu_header_size[0] +
ctx->vpu_header_size[1] +
ctx->vpu_header_size[2]);
} else {
vb2_set_plane_payload(dst_buf, 0, wr_ptr - start_ptr);
}
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev, "frame size = %u\n",
wr_ptr - start_ptr);
coda_read(dev, CODA_RET_ENC_PIC_SLICE_NUM);
coda_read(dev, CODA_RET_ENC_PIC_FLAG);
if (coda_read(dev, CODA_RET_ENC_PIC_TYPE) == 0) {
dst_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_KEYFRAME;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_PFRAME;
} else {
dst_buf->v4l2_buf.flags |= V4L2_BUF_FLAG_PFRAME;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_KEYFRAME;
}
dst_buf->v4l2_buf.timestamp = src_buf->v4l2_buf.timestamp;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
dst_buf->v4l2_buf.flags |=
src_buf->v4l2_buf.flags & V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
dst_buf->v4l2_buf.timecode = src_buf->v4l2_buf.timecode;
v4l2_m2m_buf_done(src_buf, VB2_BUF_STATE_DONE);
dst_buf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
v4l2_m2m_buf_done(dst_buf, VB2_BUF_STATE_DONE);
ctx->gopcounter--;
if (ctx->gopcounter < 0)
ctx->gopcounter = ctx->params.gop_size - 1;
v4l2_dbg(1, coda_debug, &dev->v4l2_dev,
"job finished: encoding frame (%d) (%s)\n",
dst_buf->v4l2_buf.sequence,
(dst_buf->v4l2_buf.flags & V4L2_BUF_FLAG_KEYFRAME) ?
"KEYFRAME" : "PFRAME");
}
static irqreturn_t coda_irq_handler(int irq, void *data)
{
struct coda_dev *dev = data;
struct coda_ctx *ctx;
coda_read(dev, CODA_REG_BIT_INT_STATUS);
coda_write(dev, CODA_REG_BIT_INT_CLEAR_SET,
CODA_REG_BIT_INT_CLEAR);
ctx = v4l2_m2m_get_curr_priv(dev->m2m_dev);
if (ctx == NULL) {
v4l2_err(&dev->v4l2_dev, "Instance released before the end of transaction\n");
mutex_unlock(&dev->coda_mutex);
return IRQ_HANDLED;
}
if (ctx->aborting) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"task has been aborted\n");
}
if (coda_isbusy(ctx->dev)) {
v4l2_dbg(1, coda_debug, &ctx->dev->v4l2_dev,
"coda is still busy!!!!\n");
return IRQ_NONE;
}
complete(&ctx->completion);
return IRQ_HANDLED;
}
static bool coda_firmware_supported(u32 vernum)
{
int i;
for (i = 0; i < ARRAY_SIZE(coda_supported_firmwares); i++)
if (vernum == coda_supported_firmwares[i])
return true;
return false;
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
coda_write(dev, CODADX6_STREAM_BUF_PIC_FLUSH, CODA_REG_BIT_STREAM_CTRL);
break;
default:
coda_write(dev, CODA7_STREAM_BUF_PIC_FLUSH, CODA_REG_BIT_STREAM_CTRL);
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
static int coda_check_firmware(struct coda_dev *dev)
{
u16 product, major, minor, release;
u32 data;
int ret;
ret = clk_prepare_enable(dev->clk_per);
if (ret)
goto err_clk_per;
ret = clk_prepare_enable(dev->clk_ahb);
if (ret)
goto err_clk_ahb;
coda_write(dev, 0, CODA_CMD_FIRMWARE_VERNUM);
coda_write(dev, CODA_REG_BIT_BUSY_FLAG, CODA_REG_BIT_BUSY);
coda_write(dev, 0, CODA_REG_BIT_RUN_INDEX);
coda_write(dev, 0, CODA_REG_BIT_RUN_COD_STD);
coda_write(dev, CODA_COMMAND_FIRMWARE_GET, CODA_REG_BIT_RUN_COMMAND);
if (coda_wait_timeout(dev)) {
v4l2_err(&dev->v4l2_dev, "firmware get command error\n");
ret = -EIO;
goto err_run_cmd;
}
if (dev->devtype->product == CODA_960) {
data = coda_read(dev, CODA9_CMD_FIRMWARE_CODE_REV);
v4l2_info(&dev->v4l2_dev, "Firmware code revision: %d\n",
data);
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
err_run_cmd:
clk_disable_unprepare(dev->clk_ahb);
err_clk_ahb:
clk_disable_unprepare(dev->clk_per);
err_clk_per:
return ret;
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
ret = coda_alloc_aux_buf(dev, &dev->codebuf, fw->size, "codebuf",
dev->debugfs_root);
if (ret < 0) {
dev_err(&pdev->dev, "failed to allocate code buffer\n");
return;
}
memcpy(dev->codebuf.vaddr, fw->data, fw->size);
release_firmware(fw);
if (pm_runtime_enabled(&pdev->dev) && pdev->dev.pm_domain) {
ret = pm_runtime_get_sync(&dev->plat_dev->dev);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "failed to power on: %d\n",
ret);
return;
}
ret = coda_check_firmware(dev);
if (ret < 0)
return;
pm_runtime_put_sync(&dev->plat_dev->dev);
} else {
ret = coda_hw_init(dev);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev, "HW initialization failed\n");
return;
}
ret = coda_check_firmware(dev);
if (ret < 0)
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
dev_err(&pdev->dev, "failed get reset control: %d\n", ret);
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
dev_err(&pdev->dev, "unable to alloc iram\n");
return -ENOMEM;
}
dev->iram.blob.data = dev->iram.vaddr;
dev->iram.blob.size = dev->iram.size;
dev->iram.dentry = debugfs_create_blob("iram", 0644, dev->debugfs_root,
&dev->iram.blob);
dev->workqueue = alloc_workqueue("coda", WQ_UNBOUND | WQ_MEM_RECLAIM, 1);
if (!dev->workqueue) {
dev_err(&pdev->dev, "unable to alloc workqueue\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, dev);
pm_runtime_enable(&pdev->dev);
return coda_firmware_request(dev);
}
static int coda_remove(struct platform_device *pdev)
{
struct coda_dev *dev = platform_get_drvdata(pdev);
video_unregister_device(&dev->vfd);
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
if (dev->pm_domain) {
ret = coda_hw_init(cdev);
if (ret)
v4l2_err(&cdev->v4l2_dev, "HW initialization failed\n");
}
return ret;
}
