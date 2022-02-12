static int s5p_jpeg_get_dwngrd_sch_id_by_fourcc(u32 fourcc)
{
int i;
for (i = 0; i < ARRAY_SIZE(fourcc_to_dwngrd_schema_id); ++i) {
if (fourcc_to_dwngrd_schema_id[i] == fourcc)
return i;
}
return -EINVAL;
}
static int s5p_jpeg_adjust_fourcc_to_subsampling(
enum v4l2_jpeg_chroma_subsampling subs,
u32 in_fourcc,
u32 *out_fourcc,
struct s5p_jpeg_ctx *ctx)
{
int dwngrd_sch_id;
if (ctx->subsampling != V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY) {
dwngrd_sch_id =
s5p_jpeg_get_dwngrd_sch_id_by_fourcc(in_fourcc);
if (dwngrd_sch_id < 0)
return -EINVAL;
}
switch (ctx->subsampling) {
case V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY:
*out_fourcc = V4L2_PIX_FMT_GREY;
break;
case V4L2_JPEG_CHROMA_SUBSAMPLING_420:
if (dwngrd_sch_id >
ARRAY_SIZE(subs420_fourcc_dwngrd_schema) - 1)
return -EINVAL;
*out_fourcc = subs420_fourcc_dwngrd_schema[dwngrd_sch_id];
break;
case V4L2_JPEG_CHROMA_SUBSAMPLING_422:
if (dwngrd_sch_id >
ARRAY_SIZE(subs422_fourcc_dwngrd_schema) - 1)
return -EINVAL;
*out_fourcc = subs422_fourcc_dwngrd_schema[dwngrd_sch_id];
break;
default:
*out_fourcc = V4L2_PIX_FMT_GREY;
break;
}
return 0;
}
static inline struct s5p_jpeg_ctx *ctrl_to_ctx(struct v4l2_ctrl *c)
{
return container_of(c->handler, struct s5p_jpeg_ctx, ctrl_handler);
}
static inline struct s5p_jpeg_ctx *fh_to_ctx(struct v4l2_fh *fh)
{
return container_of(fh, struct s5p_jpeg_ctx, fh);
}
static int s5p_jpeg_to_user_subsampling(struct s5p_jpeg_ctx *ctx)
{
WARN_ON(ctx->subsampling > 3);
switch (ctx->jpeg->variant->version) {
case SJPEG_S5P:
if (ctx->subsampling > 2)
return V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY;
return ctx->subsampling;
case SJPEG_EXYNOS3250:
if (ctx->subsampling > 3)
return V4L2_JPEG_CHROMA_SUBSAMPLING_411;
return exynos3250_decoded_subsampling[ctx->subsampling];
case SJPEG_EXYNOS4:
if (ctx->subsampling > 2)
return V4L2_JPEG_CHROMA_SUBSAMPLING_420;
return exynos4x12_decoded_subsampling[ctx->subsampling];
default:
return V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY;
}
}
static inline void s5p_jpeg_set_qtbl(void __iomem *regs,
const unsigned char *qtbl,
unsigned long tab, int len)
{
int i;
for (i = 0; i < len; i++)
writel((unsigned int)qtbl[i], regs + tab + (i * 0x04));
}
static inline void s5p_jpeg_set_qtbl_lum(void __iomem *regs, int quality)
{
s5p_jpeg_set_qtbl(regs, qtbl_luminance[quality],
S5P_JPG_QTBL_CONTENT(0),
ARRAY_SIZE(qtbl_luminance[quality]));
}
static inline void s5p_jpeg_set_qtbl_chr(void __iomem *regs, int quality)
{
s5p_jpeg_set_qtbl(regs, qtbl_chrominance[quality],
S5P_JPG_QTBL_CONTENT(1),
ARRAY_SIZE(qtbl_chrominance[quality]));
}
static inline void s5p_jpeg_set_htbl(void __iomem *regs,
const unsigned char *htbl,
unsigned long tab, int len)
{
int i;
for (i = 0; i < len; i++)
writel((unsigned int)htbl[i], regs + tab + (i * 0x04));
}
static inline void s5p_jpeg_set_hdctbl(void __iomem *regs)
{
s5p_jpeg_set_htbl(regs, hdctbl0, S5P_JPG_HDCTBL(0),
ARRAY_SIZE(hdctbl0));
}
static inline void s5p_jpeg_set_hdctblg(void __iomem *regs)
{
s5p_jpeg_set_htbl(regs, hdctblg0, S5P_JPG_HDCTBLG(0),
ARRAY_SIZE(hdctblg0));
}
static inline void s5p_jpeg_set_hactbl(void __iomem *regs)
{
s5p_jpeg_set_htbl(regs, hactbl0, S5P_JPG_HACTBL(0),
ARRAY_SIZE(hactbl0));
}
static inline void s5p_jpeg_set_hactblg(void __iomem *regs)
{
s5p_jpeg_set_htbl(regs, hactblg0, S5P_JPG_HACTBLG(0),
ARRAY_SIZE(hactblg0));
}
static inline void exynos4_jpeg_set_tbl(void __iomem *regs,
const unsigned char *tbl,
unsigned long tab, int len)
{
int i;
unsigned int dword;
for (i = 0; i < len; i += 4) {
dword = tbl[i] |
(tbl[i + 1] << 8) |
(tbl[i + 2] << 16) |
(tbl[i + 3] << 24);
writel(dword, regs + tab + i);
}
}
static inline void exynos4_jpeg_set_qtbl_lum(void __iomem *regs, int quality)
{
exynos4_jpeg_set_tbl(regs, qtbl_luminance[quality],
EXYNOS4_QTBL_CONTENT(0),
ARRAY_SIZE(qtbl_luminance[quality]));
}
static inline void exynos4_jpeg_set_qtbl_chr(void __iomem *regs, int quality)
{
exynos4_jpeg_set_tbl(regs, qtbl_chrominance[quality],
EXYNOS4_QTBL_CONTENT(1),
ARRAY_SIZE(qtbl_chrominance[quality]));
}
void exynos4_jpeg_set_huff_tbl(void __iomem *base)
{
exynos4_jpeg_set_tbl(base, hdctbl0, EXYNOS4_HUFF_TBL_HDCLL,
ARRAY_SIZE(hdctbl0));
exynos4_jpeg_set_tbl(base, hdctbl0, EXYNOS4_HUFF_TBL_HDCCL,
ARRAY_SIZE(hdctbl0));
exynos4_jpeg_set_tbl(base, hdctblg0, EXYNOS4_HUFF_TBL_HDCLV,
ARRAY_SIZE(hdctblg0));
exynos4_jpeg_set_tbl(base, hdctblg0, EXYNOS4_HUFF_TBL_HDCCV,
ARRAY_SIZE(hdctblg0));
exynos4_jpeg_set_tbl(base, hactbl0, EXYNOS4_HUFF_TBL_HACLL,
ARRAY_SIZE(hactbl0));
exynos4_jpeg_set_tbl(base, hactbl0, EXYNOS4_HUFF_TBL_HACCL,
ARRAY_SIZE(hactbl0));
exynos4_jpeg_set_tbl(base, hactblg0, EXYNOS4_HUFF_TBL_HACLV,
ARRAY_SIZE(hactblg0));
exynos4_jpeg_set_tbl(base, hactblg0, EXYNOS4_HUFF_TBL_HACCV,
ARRAY_SIZE(hactblg0));
}
static int s5p_jpeg_open(struct file *file)
{
struct s5p_jpeg *jpeg = video_drvdata(file);
struct video_device *vfd = video_devdata(file);
struct s5p_jpeg_ctx *ctx;
struct s5p_jpeg_fmt *out_fmt, *cap_fmt;
int ret = 0;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
if (mutex_lock_interruptible(&jpeg->lock)) {
ret = -ERESTARTSYS;
goto free;
}
v4l2_fh_init(&ctx->fh, vfd);
ctx->fh.ctrl_handler = &ctx->ctrl_handler;
file->private_data = &ctx->fh;
v4l2_fh_add(&ctx->fh);
ctx->jpeg = jpeg;
if (vfd == jpeg->vfd_encoder) {
ctx->mode = S5P_JPEG_ENCODE;
out_fmt = s5p_jpeg_find_format(ctx, V4L2_PIX_FMT_RGB565,
FMT_TYPE_OUTPUT);
cap_fmt = s5p_jpeg_find_format(ctx, V4L2_PIX_FMT_JPEG,
FMT_TYPE_CAPTURE);
} else {
ctx->mode = S5P_JPEG_DECODE;
out_fmt = s5p_jpeg_find_format(ctx, V4L2_PIX_FMT_JPEG,
FMT_TYPE_OUTPUT);
cap_fmt = s5p_jpeg_find_format(ctx, V4L2_PIX_FMT_YUYV,
FMT_TYPE_CAPTURE);
ctx->scale_factor = EXYNOS3250_DEC_SCALE_FACTOR_8_8;
}
ctx->fh.m2m_ctx = v4l2_m2m_ctx_init(jpeg->m2m_dev, ctx, queue_init);
if (IS_ERR(ctx->fh.m2m_ctx)) {
ret = PTR_ERR(ctx->fh.m2m_ctx);
goto error;
}
ctx->out_q.fmt = out_fmt;
ctx->cap_q.fmt = cap_fmt;
ret = s5p_jpeg_controls_create(ctx);
if (ret < 0)
goto error;
mutex_unlock(&jpeg->lock);
return 0;
error:
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
mutex_unlock(&jpeg->lock);
free:
kfree(ctx);
return ret;
}
static int s5p_jpeg_release(struct file *file)
{
struct s5p_jpeg *jpeg = video_drvdata(file);
struct s5p_jpeg_ctx *ctx = fh_to_ctx(file->private_data);
mutex_lock(&jpeg->lock);
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
v4l2_ctrl_handler_free(&ctx->ctrl_handler);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
kfree(ctx);
mutex_unlock(&jpeg->lock);
return 0;
}
static int get_byte(struct s5p_jpeg_buffer *buf)
{
if (buf->curr >= buf->size)
return -1;
return ((unsigned char *)buf->data)[buf->curr++];
}
static int get_word_be(struct s5p_jpeg_buffer *buf, unsigned int *word)
{
unsigned int temp;
int byte;
byte = get_byte(buf);
if (byte == -1)
return -1;
temp = byte << 8;
byte = get_byte(buf);
if (byte == -1)
return -1;
*word = (unsigned int)byte | temp;
return 0;
}
static void skip(struct s5p_jpeg_buffer *buf, long len)
{
if (len <= 0)
return;
while (len--)
get_byte(buf);
}
static bool s5p_jpeg_parse_hdr(struct s5p_jpeg_q_data *result,
unsigned long buffer, unsigned long size,
struct s5p_jpeg_ctx *ctx)
{
int c, components, notfound;
unsigned int height, width, word, subsampling = 0;
long length;
struct s5p_jpeg_buffer jpeg_buffer;
jpeg_buffer.size = size;
jpeg_buffer.data = buffer;
jpeg_buffer.curr = 0;
notfound = 1;
while (notfound) {
c = get_byte(&jpeg_buffer);
if (c == -1)
return false;
if (c != 0xff)
continue;
do
c = get_byte(&jpeg_buffer);
while (c == 0xff);
if (c == -1)
return false;
if (c == 0)
continue;
length = 0;
switch (c) {
case SOF0:
if (get_word_be(&jpeg_buffer, &word))
break;
if (get_byte(&jpeg_buffer) == -1)
break;
if (get_word_be(&jpeg_buffer, &height))
break;
if (get_word_be(&jpeg_buffer, &width))
break;
components = get_byte(&jpeg_buffer);
if (components == -1)
break;
notfound = 0;
if (components == 1) {
subsampling = 0x33;
} else {
skip(&jpeg_buffer, 1);
subsampling = get_byte(&jpeg_buffer);
skip(&jpeg_buffer, 1);
}
skip(&jpeg_buffer, components * 2);
break;
case RST ... RST + 7:
case SOI:
case EOI:
case TEM:
break;
default:
if (get_word_be(&jpeg_buffer, &word))
break;
length = (long)word - 2;
skip(&jpeg_buffer, length);
break;
}
}
result->w = width;
result->h = height;
result->size = components;
switch (subsampling) {
case 0x11:
ctx->subsampling = V4L2_JPEG_CHROMA_SUBSAMPLING_444;
break;
case 0x21:
ctx->subsampling = V4L2_JPEG_CHROMA_SUBSAMPLING_422;
break;
case 0x22:
ctx->subsampling = V4L2_JPEG_CHROMA_SUBSAMPLING_420;
break;
case 0x33:
ctx->subsampling = V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY;
break;
default:
return false;
}
return !notfound;
}
static int s5p_jpeg_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
if (ctx->mode == S5P_JPEG_ENCODE) {
strlcpy(cap->driver, S5P_JPEG_M2M_NAME " encoder",
sizeof(cap->driver));
strlcpy(cap->card, S5P_JPEG_M2M_NAME " encoder",
sizeof(cap->card));
} else {
strlcpy(cap->driver, S5P_JPEG_M2M_NAME " decoder",
sizeof(cap->driver));
strlcpy(cap->card, S5P_JPEG_M2M_NAME " decoder",
sizeof(cap->card));
}
cap->bus_info[0] = 0;
cap->capabilities = V4L2_CAP_STREAMING | V4L2_CAP_VIDEO_M2M |
V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT;
return 0;
}
static int enum_fmt(struct s5p_jpeg_fmt *sjpeg_formats, int n,
struct v4l2_fmtdesc *f, u32 type)
{
int i, num = 0;
for (i = 0; i < n; ++i) {
if (sjpeg_formats[i].flags & type) {
if (num == f->index)
break;
++num;
}
}
if (i >= n)
return -EINVAL;
strlcpy(f->description, sjpeg_formats[i].name, sizeof(f->description));
f->pixelformat = sjpeg_formats[i].fourcc;
return 0;
}
static int s5p_jpeg_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
if (ctx->mode == S5P_JPEG_ENCODE)
return enum_fmt(sjpeg_formats, SJPEG_NUM_FORMATS, f,
SJPEG_FMT_FLAG_ENC_CAPTURE);
return enum_fmt(sjpeg_formats, SJPEG_NUM_FORMATS, f,
SJPEG_FMT_FLAG_DEC_CAPTURE);
}
static int s5p_jpeg_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
if (ctx->mode == S5P_JPEG_ENCODE)
return enum_fmt(sjpeg_formats, SJPEG_NUM_FORMATS, f,
SJPEG_FMT_FLAG_ENC_OUTPUT);
return enum_fmt(sjpeg_formats, SJPEG_NUM_FORMATS, f,
SJPEG_FMT_FLAG_DEC_OUTPUT);
}
static struct s5p_jpeg_q_data *get_q_data(struct s5p_jpeg_ctx *ctx,
enum v4l2_buf_type type)
{
if (type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
return &ctx->out_q;
if (type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
return &ctx->cap_q;
return NULL;
}
static int s5p_jpeg_g_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct s5p_jpeg_q_data *q_data = NULL;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct s5p_jpeg_ctx *ct = fh_to_ctx(priv);
vq = v4l2_m2m_get_vq(ct->fh.m2m_ctx, f->type);
if (!vq)
return -EINVAL;
if (f->type == V4L2_BUF_TYPE_VIDEO_CAPTURE &&
ct->mode == S5P_JPEG_DECODE && !ct->hdr_parsed)
return -EINVAL;
q_data = get_q_data(ct, f->type);
BUG_ON(q_data == NULL);
pix->width = q_data->w;
pix->height = q_data->h;
pix->field = V4L2_FIELD_NONE;
pix->pixelformat = q_data->fmt->fourcc;
pix->bytesperline = 0;
if (q_data->fmt->fourcc != V4L2_PIX_FMT_JPEG) {
u32 bpl = q_data->w;
if (q_data->fmt->colplanes == 1)
bpl = (bpl * q_data->fmt->depth) >> 3;
pix->bytesperline = bpl;
}
pix->sizeimage = q_data->size;
return 0;
}
static struct s5p_jpeg_fmt *s5p_jpeg_find_format(struct s5p_jpeg_ctx *ctx,
u32 pixelformat, unsigned int fmt_type)
{
unsigned int k, fmt_flag;
if (ctx->mode == S5P_JPEG_ENCODE)
fmt_flag = (fmt_type == FMT_TYPE_OUTPUT) ?
SJPEG_FMT_FLAG_ENC_OUTPUT :
SJPEG_FMT_FLAG_ENC_CAPTURE;
else
fmt_flag = (fmt_type == FMT_TYPE_OUTPUT) ?
SJPEG_FMT_FLAG_DEC_OUTPUT :
SJPEG_FMT_FLAG_DEC_CAPTURE;
for (k = 0; k < ARRAY_SIZE(sjpeg_formats); k++) {
struct s5p_jpeg_fmt *fmt = &sjpeg_formats[k];
if (fmt->fourcc == pixelformat &&
fmt->flags & fmt_flag &&
fmt->flags & ctx->jpeg->variant->fmt_ver_flag) {
return fmt;
}
}
return NULL;
}
static void jpeg_bound_align_image(struct s5p_jpeg_ctx *ctx,
u32 *w, unsigned int wmin, unsigned int wmax,
unsigned int walign,
u32 *h, unsigned int hmin, unsigned int hmax,
unsigned int halign)
{
int width, height, w_step, h_step;
width = *w;
height = *h;
w_step = 1 << walign;
h_step = 1 << halign;
if (ctx->jpeg->variant->version == SJPEG_EXYNOS3250) {
if (w_step == 4 && ((width & 3) == 1)) {
wmax = width;
hmax = height;
}
}
v4l_bound_align_image(w, wmin, wmax, walign, h, hmin, hmax, halign, 0);
if (*w < width && (*w + w_step) < wmax)
*w += w_step;
if (*h < height && (*h + h_step) < hmax)
*h += h_step;
}
static int vidioc_try_fmt(struct v4l2_format *f, struct s5p_jpeg_fmt *fmt,
struct s5p_jpeg_ctx *ctx, int q_type)
{
struct v4l2_pix_format *pix = &f->fmt.pix;
if (pix->field == V4L2_FIELD_ANY)
pix->field = V4L2_FIELD_NONE;
else if (pix->field != V4L2_FIELD_NONE)
return -EINVAL;
if (q_type == FMT_TYPE_OUTPUT)
jpeg_bound_align_image(ctx, &pix->width, S5P_JPEG_MIN_WIDTH,
S5P_JPEG_MAX_WIDTH, 0,
&pix->height, S5P_JPEG_MIN_HEIGHT,
S5P_JPEG_MAX_HEIGHT, 0);
else
jpeg_bound_align_image(ctx, &pix->width, S5P_JPEG_MIN_WIDTH,
S5P_JPEG_MAX_WIDTH, fmt->h_align,
&pix->height, S5P_JPEG_MIN_HEIGHT,
S5P_JPEG_MAX_HEIGHT, fmt->v_align);
if (fmt->fourcc == V4L2_PIX_FMT_JPEG) {
if (pix->sizeimage <= 0)
pix->sizeimage = PAGE_SIZE;
pix->bytesperline = 0;
} else {
u32 bpl = pix->bytesperline;
if (fmt->colplanes > 1 && bpl < pix->width)
bpl = pix->width;
if (fmt->colplanes == 1 &&
(bpl << 3) / fmt->depth < pix->width)
bpl = (pix->width * fmt->depth) >> 3;
pix->bytesperline = bpl;
pix->sizeimage = (pix->width * pix->height * fmt->depth) >> 3;
}
return 0;
}
static int s5p_jpeg_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
struct v4l2_pix_format *pix = &f->fmt.pix;
struct s5p_jpeg_fmt *fmt;
int ret;
fmt = s5p_jpeg_find_format(ctx, f->fmt.pix.pixelformat,
FMT_TYPE_CAPTURE);
if (!fmt) {
v4l2_err(&ctx->jpeg->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
if ((ctx->jpeg->variant->version != SJPEG_EXYNOS4) ||
(ctx->mode != S5P_JPEG_DECODE))
goto exit;
if ((fmt->flags & SJPEG_FMT_NON_RGB) &&
(fmt->subsampling < ctx->subsampling)) {
ret = s5p_jpeg_adjust_fourcc_to_subsampling(ctx->subsampling,
fmt->fourcc,
&pix->pixelformat,
ctx);
if (ret < 0)
pix->pixelformat = V4L2_PIX_FMT_GREY;
fmt = s5p_jpeg_find_format(ctx, pix->pixelformat,
FMT_TYPE_CAPTURE);
}
if (ctx->subsampling == V4L2_JPEG_CHROMA_SUBSAMPLING_420 &&
(ctx->out_q.w & 1) &&
(pix->pixelformat == V4L2_PIX_FMT_NV12 ||
pix->pixelformat == V4L2_PIX_FMT_NV21 ||
pix->pixelformat == V4L2_PIX_FMT_YUV420)) {
pix->pixelformat = V4L2_PIX_FMT_RGB565;
fmt = s5p_jpeg_find_format(ctx, pix->pixelformat,
FMT_TYPE_CAPTURE);
}
exit:
return vidioc_try_fmt(f, fmt, ctx, FMT_TYPE_CAPTURE);
}
static int s5p_jpeg_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
struct s5p_jpeg_fmt *fmt;
fmt = s5p_jpeg_find_format(ctx, f->fmt.pix.pixelformat,
FMT_TYPE_OUTPUT);
if (!fmt) {
v4l2_err(&ctx->jpeg->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
return vidioc_try_fmt(f, fmt, ctx, FMT_TYPE_OUTPUT);
}
static int exynos4_jpeg_get_output_buffer_size(struct s5p_jpeg_ctx *ctx,
struct v4l2_format *f,
int fmt_depth)
{
struct v4l2_pix_format *pix = &f->fmt.pix;
u32 pix_fmt = f->fmt.pix.pixelformat;
int w = pix->width, h = pix->height, wh_align;
if (pix_fmt == V4L2_PIX_FMT_RGB32 ||
pix_fmt == V4L2_PIX_FMT_NV24 ||
pix_fmt == V4L2_PIX_FMT_NV42 ||
pix_fmt == V4L2_PIX_FMT_NV12 ||
pix_fmt == V4L2_PIX_FMT_NV21 ||
pix_fmt == V4L2_PIX_FMT_YUV420)
wh_align = 4;
else
wh_align = 1;
jpeg_bound_align_image(ctx, &w, S5P_JPEG_MIN_WIDTH,
S5P_JPEG_MAX_WIDTH, wh_align,
&h, S5P_JPEG_MIN_HEIGHT,
S5P_JPEG_MAX_HEIGHT, wh_align);
return w * h * fmt_depth >> 3;
}
static int s5p_jpeg_s_fmt(struct s5p_jpeg_ctx *ct, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct s5p_jpeg_q_data *q_data = NULL;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_ctrl *ctrl_subs;
struct v4l2_rect scale_rect;
unsigned int f_type;
vq = v4l2_m2m_get_vq(ct->fh.m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ct, f->type);
BUG_ON(q_data == NULL);
if (vb2_is_busy(vq)) {
v4l2_err(&ct->jpeg->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
f_type = V4L2_TYPE_IS_OUTPUT(f->type) ?
FMT_TYPE_OUTPUT : FMT_TYPE_CAPTURE;
q_data->fmt = s5p_jpeg_find_format(ct, pix->pixelformat, f_type);
q_data->w = pix->width;
q_data->h = pix->height;
if (q_data->fmt->fourcc != V4L2_PIX_FMT_JPEG) {
if (ct->jpeg->variant->version == SJPEG_EXYNOS4 &&
f_type == FMT_TYPE_OUTPUT && ct->mode == S5P_JPEG_ENCODE)
q_data->size = exynos4_jpeg_get_output_buffer_size(ct,
f,
q_data->fmt->depth);
else
q_data->size = q_data->w * q_data->h *
q_data->fmt->depth >> 3;
} else {
q_data->size = pix->sizeimage;
}
if (f_type == FMT_TYPE_OUTPUT) {
ctrl_subs = v4l2_ctrl_find(&ct->ctrl_handler,
V4L2_CID_JPEG_CHROMA_SUBSAMPLING);
if (ctrl_subs)
v4l2_ctrl_s_ctrl(ctrl_subs, q_data->fmt->subsampling);
ct->crop_altered = false;
}
if (!ct->crop_altered &&
((ct->mode == S5P_JPEG_DECODE && f_type == FMT_TYPE_CAPTURE) ||
(ct->mode == S5P_JPEG_ENCODE && f_type == FMT_TYPE_OUTPUT))) {
ct->crop_rect.width = pix->width;
ct->crop_rect.height = pix->height;
}
if (ct->mode == S5P_JPEG_DECODE &&
f_type == FMT_TYPE_CAPTURE &&
ct->jpeg->variant->version == SJPEG_EXYNOS3250 &&
pix->pixelformat == V4L2_PIX_FMT_YUV420 &&
ct->scale_factor > 2) {
scale_rect.width = ct->out_q.w / 2;
scale_rect.height = ct->out_q.h / 2;
exynos3250_jpeg_try_downscale(ct, &scale_rect);
}
return 0;
}
static int s5p_jpeg_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
ret = s5p_jpeg_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
return s5p_jpeg_s_fmt(fh_to_ctx(priv), f);
}
static int s5p_jpeg_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
ret = s5p_jpeg_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
return s5p_jpeg_s_fmt(fh_to_ctx(priv), f);
}
static int exynos3250_jpeg_try_downscale(struct s5p_jpeg_ctx *ctx,
struct v4l2_rect *r)
{
int w_ratio, h_ratio, scale_factor, cur_ratio, i;
w_ratio = ctx->out_q.w / r->width;
h_ratio = ctx->out_q.h / r->height;
scale_factor = w_ratio > h_ratio ? w_ratio : h_ratio;
scale_factor = clamp_val(scale_factor, 1, 8);
for (i = 0; i <= 3; ++i) {
cur_ratio = 1 << i;
if (scale_factor <= cur_ratio) {
ctx->scale_factor = cur_ratio;
break;
}
}
r->width = round_down(ctx->out_q.w / ctx->scale_factor, 2);
r->height = round_down(ctx->out_q.h / ctx->scale_factor, 2);
ctx->crop_rect.width = r->width;
ctx->crop_rect.height = r->height;
ctx->crop_rect.left = 0;
ctx->crop_rect.top = 0;
ctx->crop_altered = true;
return 0;
}
static int enclosed_rectangle(struct v4l2_rect *a, struct v4l2_rect *b)
{
if (a->left < b->left || a->top < b->top)
return 0;
if (a->left + a->width > b->left + b->width)
return 0;
if (a->top + a->height > b->top + b->height)
return 0;
return 1;
}
static int exynos3250_jpeg_try_crop(struct s5p_jpeg_ctx *ctx,
struct v4l2_rect *r)
{
struct v4l2_rect base_rect;
int w_step, h_step;
switch (ctx->cap_q.fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
w_step = 1;
h_step = 2;
break;
case V4L2_PIX_FMT_YUV420:
w_step = 2;
h_step = 2;
break;
default:
w_step = 1;
h_step = 1;
break;
}
base_rect.top = 0;
base_rect.left = 0;
base_rect.width = ctx->out_q.w;
base_rect.height = ctx->out_q.h;
r->width = round_down(r->width, w_step);
r->height = round_down(r->height, h_step);
r->left = round_down(r->left, 2);
r->top = round_down(r->top, 2);
if (!enclosed_rectangle(r, &base_rect))
return -EINVAL;
ctx->crop_rect.left = r->left;
ctx->crop_rect.top = r->top;
ctx->crop_rect.width = r->width;
ctx->crop_rect.height = r->height;
ctx->crop_altered = true;
return 0;
}
static int s5p_jpeg_g_selection(struct file *file, void *priv,
struct v4l2_selection *s)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(priv);
if (s->type != V4L2_BUF_TYPE_VIDEO_OUTPUT &&
s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
switch (s->target) {
case V4L2_SEL_TGT_CROP:
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_COMPOSE_DEFAULT:
s->r.width = ctx->out_q.w;
s->r.height = ctx->out_q.h;
s->r.left = 0;
s->r.top = 0;
break;
case V4L2_SEL_TGT_COMPOSE:
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
case V4L2_SEL_TGT_COMPOSE_PADDED:
s->r.width = ctx->crop_rect.width;
s->r.height = ctx->crop_rect.height;
s->r.left = ctx->crop_rect.left;
s->r.top = ctx->crop_rect.top;
break;
default:
return -EINVAL;
}
return 0;
}
static int s5p_jpeg_s_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct s5p_jpeg_ctx *ctx = fh_to_ctx(file->private_data);
struct v4l2_rect *rect = &s->r;
int ret = -EINVAL;
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (s->target == V4L2_SEL_TGT_COMPOSE) {
if (ctx->mode != S5P_JPEG_DECODE)
return -EINVAL;
if (ctx->jpeg->variant->version == SJPEG_EXYNOS3250)
ret = exynos3250_jpeg_try_downscale(ctx, rect);
} else if (s->target == V4L2_SEL_TGT_CROP) {
if (ctx->mode != S5P_JPEG_ENCODE)
return -EINVAL;
if (ctx->jpeg->variant->version == SJPEG_EXYNOS3250)
ret = exynos3250_jpeg_try_crop(ctx, rect);
}
return ret;
}
static int s5p_jpeg_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct s5p_jpeg_ctx *ctx = ctrl_to_ctx(ctrl);
struct s5p_jpeg *jpeg = ctx->jpeg;
unsigned long flags;
switch (ctrl->id) {
case V4L2_CID_JPEG_CHROMA_SUBSAMPLING:
spin_lock_irqsave(&jpeg->slock, flags);
ctrl->val = s5p_jpeg_to_user_subsampling(ctx);
spin_unlock_irqrestore(&jpeg->slock, flags);
break;
}
return 0;
}
static int s5p_jpeg_adjust_subs_ctrl(struct s5p_jpeg_ctx *ctx, int *ctrl_val)
{
switch (ctx->jpeg->variant->version) {
case SJPEG_S5P:
return 0;
case SJPEG_EXYNOS3250:
if (ctx->out_q.fmt->fourcc == V4L2_PIX_FMT_RGB32)
*ctrl_val = 0;
break;
case SJPEG_EXYNOS4:
if (ctx->out_q.fmt->fourcc != V4L2_PIX_FMT_GREY &&
*ctrl_val == V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY)
return -EINVAL;
break;
}
if (ctx->out_q.fmt->subsampling > *ctrl_val)
*ctrl_val = ctx->out_q.fmt->subsampling;
return 0;
}
static int s5p_jpeg_try_ctrl(struct v4l2_ctrl *ctrl)
{
struct s5p_jpeg_ctx *ctx = ctrl_to_ctx(ctrl);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&ctx->jpeg->slock, flags);
if (ctrl->id == V4L2_CID_JPEG_CHROMA_SUBSAMPLING)
ret = s5p_jpeg_adjust_subs_ctrl(ctx, &ctrl->val);
spin_unlock_irqrestore(&ctx->jpeg->slock, flags);
return ret;
}
static int s5p_jpeg_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct s5p_jpeg_ctx *ctx = ctrl_to_ctx(ctrl);
unsigned long flags;
spin_lock_irqsave(&ctx->jpeg->slock, flags);
switch (ctrl->id) {
case V4L2_CID_JPEG_COMPRESSION_QUALITY:
ctx->compr_quality = ctrl->val;
break;
case V4L2_CID_JPEG_RESTART_INTERVAL:
ctx->restart_interval = ctrl->val;
break;
case V4L2_CID_JPEG_CHROMA_SUBSAMPLING:
ctx->subsampling = ctrl->val;
break;
}
spin_unlock_irqrestore(&ctx->jpeg->slock, flags);
return 0;
}
static int s5p_jpeg_controls_create(struct s5p_jpeg_ctx *ctx)
{
unsigned int mask = ~0x27;
struct v4l2_ctrl *ctrl;
int ret;
v4l2_ctrl_handler_init(&ctx->ctrl_handler, 3);
if (ctx->mode == S5P_JPEG_ENCODE) {
v4l2_ctrl_new_std(&ctx->ctrl_handler, &s5p_jpeg_ctrl_ops,
V4L2_CID_JPEG_COMPRESSION_QUALITY,
0, 3, 1, S5P_JPEG_COMPR_QUAL_WORST);
v4l2_ctrl_new_std(&ctx->ctrl_handler, &s5p_jpeg_ctrl_ops,
V4L2_CID_JPEG_RESTART_INTERVAL,
0, 3, 0xffff, 0);
if (ctx->jpeg->variant->version == SJPEG_S5P)
mask = ~0x06;
}
ctrl = v4l2_ctrl_new_std_menu(&ctx->ctrl_handler, &s5p_jpeg_ctrl_ops,
V4L2_CID_JPEG_CHROMA_SUBSAMPLING,
V4L2_JPEG_CHROMA_SUBSAMPLING_GRAY, mask,
V4L2_JPEG_CHROMA_SUBSAMPLING_422);
if (ctx->ctrl_handler.error) {
ret = ctx->ctrl_handler.error;
goto error_free;
}
if (ctx->mode == S5P_JPEG_DECODE)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY;
ret = v4l2_ctrl_handler_setup(&ctx->ctrl_handler);
if (ret < 0)
goto error_free;
return ret;
error_free:
v4l2_ctrl_handler_free(&ctx->ctrl_handler);
return ret;
}
static void s5p_jpeg_device_run(void *priv)
{
struct s5p_jpeg_ctx *ctx = priv;
struct s5p_jpeg *jpeg = ctx->jpeg;
struct vb2_buffer *src_buf, *dst_buf;
unsigned long src_addr, dst_addr, flags;
spin_lock_irqsave(&ctx->jpeg->slock, flags);
src_buf = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
src_addr = vb2_dma_contig_plane_dma_addr(src_buf, 0);
dst_addr = vb2_dma_contig_plane_dma_addr(dst_buf, 0);
s5p_jpeg_reset(jpeg->regs);
s5p_jpeg_poweron(jpeg->regs);
s5p_jpeg_proc_mode(jpeg->regs, ctx->mode);
if (ctx->mode == S5P_JPEG_ENCODE) {
if (ctx->out_q.fmt->fourcc == V4L2_PIX_FMT_RGB565)
s5p_jpeg_input_raw_mode(jpeg->regs,
S5P_JPEG_RAW_IN_565);
else
s5p_jpeg_input_raw_mode(jpeg->regs,
S5P_JPEG_RAW_IN_422);
s5p_jpeg_subsampling_mode(jpeg->regs, ctx->subsampling);
s5p_jpeg_dri(jpeg->regs, ctx->restart_interval);
s5p_jpeg_x(jpeg->regs, ctx->out_q.w);
s5p_jpeg_y(jpeg->regs, ctx->out_q.h);
s5p_jpeg_imgadr(jpeg->regs, src_addr);
s5p_jpeg_jpgadr(jpeg->regs, dst_addr);
s5p_jpeg_enc_stream_int(jpeg->regs, ctx->cap_q.size);
s5p_jpeg_coef(jpeg->regs, 1, 1, S5P_JPEG_COEF11);
s5p_jpeg_coef(jpeg->regs, 1, 2, S5P_JPEG_COEF12);
s5p_jpeg_coef(jpeg->regs, 1, 3, S5P_JPEG_COEF13);
s5p_jpeg_coef(jpeg->regs, 2, 1, S5P_JPEG_COEF21);
s5p_jpeg_coef(jpeg->regs, 2, 2, S5P_JPEG_COEF22);
s5p_jpeg_coef(jpeg->regs, 2, 3, S5P_JPEG_COEF23);
s5p_jpeg_coef(jpeg->regs, 3, 1, S5P_JPEG_COEF31);
s5p_jpeg_coef(jpeg->regs, 3, 2, S5P_JPEG_COEF32);
s5p_jpeg_coef(jpeg->regs, 3, 3, S5P_JPEG_COEF33);
s5p_jpeg_set_qtbl_lum(jpeg->regs, ctx->compr_quality);
s5p_jpeg_set_qtbl_chr(jpeg->regs, ctx->compr_quality);
s5p_jpeg_qtbl(jpeg->regs, 1, 0);
s5p_jpeg_qtbl(jpeg->regs, 2, 1);
s5p_jpeg_qtbl(jpeg->regs, 3, 1);
s5p_jpeg_htbl_ac(jpeg->regs, 1);
s5p_jpeg_htbl_dc(jpeg->regs, 1);
s5p_jpeg_htbl_ac(jpeg->regs, 2);
s5p_jpeg_htbl_dc(jpeg->regs, 2);
s5p_jpeg_htbl_ac(jpeg->regs, 3);
s5p_jpeg_htbl_dc(jpeg->regs, 3);
} else {
s5p_jpeg_rst_int_enable(jpeg->regs, true);
s5p_jpeg_data_num_int_enable(jpeg->regs, true);
s5p_jpeg_final_mcu_num_int_enable(jpeg->regs, true);
if (ctx->cap_q.fmt->fourcc == V4L2_PIX_FMT_YUYV)
s5p_jpeg_outform_raw(jpeg->regs, S5P_JPEG_RAW_OUT_422);
else
s5p_jpeg_outform_raw(jpeg->regs, S5P_JPEG_RAW_OUT_420);
s5p_jpeg_jpgadr(jpeg->regs, src_addr);
s5p_jpeg_imgadr(jpeg->regs, dst_addr);
}
s5p_jpeg_start(jpeg->regs);
spin_unlock_irqrestore(&ctx->jpeg->slock, flags);
}
static void exynos4_jpeg_set_img_addr(struct s5p_jpeg_ctx *ctx)
{
struct s5p_jpeg *jpeg = ctx->jpeg;
struct s5p_jpeg_fmt *fmt;
struct vb2_buffer *vb;
struct s5p_jpeg_addr jpeg_addr;
u32 pix_size, padding_bytes = 0;
pix_size = ctx->cap_q.w * ctx->cap_q.h;
if (ctx->mode == S5P_JPEG_ENCODE) {
vb = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
fmt = ctx->out_q.fmt;
if (ctx->out_q.w % 2 && fmt->h_align > 0)
padding_bytes = ctx->out_q.h;
} else {
fmt = ctx->cap_q.fmt;
vb = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
}
jpeg_addr.y = vb2_dma_contig_plane_dma_addr(vb, 0);
if (fmt->colplanes == 2) {
jpeg_addr.cb = jpeg_addr.y + pix_size - padding_bytes;
} else if (fmt->colplanes == 3) {
jpeg_addr.cb = jpeg_addr.y + pix_size;
if (fmt->fourcc == V4L2_PIX_FMT_YUV420)
jpeg_addr.cr = jpeg_addr.cb + pix_size / 4;
else
jpeg_addr.cr = jpeg_addr.cb + pix_size / 2;
}
exynos4_jpeg_set_frame_buf_address(jpeg->regs, &jpeg_addr);
}
static void exynos4_jpeg_set_jpeg_addr(struct s5p_jpeg_ctx *ctx)
{
struct s5p_jpeg *jpeg = ctx->jpeg;
struct vb2_buffer *vb;
unsigned int jpeg_addr = 0;
if (ctx->mode == S5P_JPEG_ENCODE)
vb = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
else
vb = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
jpeg_addr = vb2_dma_contig_plane_dma_addr(vb, 0);
exynos4_jpeg_set_stream_buf_address(jpeg->regs, jpeg_addr);
}
static void exynos4_jpeg_device_run(void *priv)
{
struct s5p_jpeg_ctx *ctx = priv;
struct s5p_jpeg *jpeg = ctx->jpeg;
unsigned int bitstream_size;
unsigned long flags;
spin_lock_irqsave(&ctx->jpeg->slock, flags);
if (ctx->mode == S5P_JPEG_ENCODE) {
exynos4_jpeg_sw_reset(jpeg->regs);
exynos4_jpeg_set_interrupt(jpeg->regs);
exynos4_jpeg_set_huf_table_enable(jpeg->regs, 1);
exynos4_jpeg_set_huff_tbl(jpeg->regs);
exynos4_jpeg_set_qtbl_lum(jpeg->regs, ctx->compr_quality);
exynos4_jpeg_set_qtbl_chr(jpeg->regs, ctx->compr_quality);
exynos4_jpeg_set_encode_tbl_select(jpeg->regs,
ctx->compr_quality);
exynos4_jpeg_set_stream_size(jpeg->regs, ctx->cap_q.w,
ctx->cap_q.h);
exynos4_jpeg_set_enc_out_fmt(jpeg->regs, ctx->subsampling);
exynos4_jpeg_set_img_fmt(jpeg->regs, ctx->out_q.fmt->fourcc);
exynos4_jpeg_set_img_addr(ctx);
exynos4_jpeg_set_jpeg_addr(ctx);
exynos4_jpeg_set_encode_hoff_cnt(jpeg->regs,
ctx->out_q.fmt->fourcc);
} else {
exynos4_jpeg_sw_reset(jpeg->regs);
exynos4_jpeg_set_interrupt(jpeg->regs);
exynos4_jpeg_set_img_addr(ctx);
exynos4_jpeg_set_jpeg_addr(ctx);
exynos4_jpeg_set_img_fmt(jpeg->regs, ctx->cap_q.fmt->fourcc);
bitstream_size = DIV_ROUND_UP(ctx->out_q.size, 32);
exynos4_jpeg_set_dec_bitstream_size(jpeg->regs, bitstream_size);
}
exynos4_jpeg_set_enc_dec_mode(jpeg->regs, ctx->mode);
spin_unlock_irqrestore(&ctx->jpeg->slock, flags);
}
static void exynos3250_jpeg_set_img_addr(struct s5p_jpeg_ctx *ctx)
{
struct s5p_jpeg *jpeg = ctx->jpeg;
struct s5p_jpeg_fmt *fmt;
struct vb2_buffer *vb;
struct s5p_jpeg_addr jpeg_addr;
u32 pix_size;
pix_size = ctx->cap_q.w * ctx->cap_q.h;
if (ctx->mode == S5P_JPEG_ENCODE) {
vb = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
fmt = ctx->out_q.fmt;
} else {
vb = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
fmt = ctx->cap_q.fmt;
}
jpeg_addr.y = vb2_dma_contig_plane_dma_addr(vb, 0);
if (fmt->colplanes == 2) {
jpeg_addr.cb = jpeg_addr.y + pix_size;
} else if (fmt->colplanes == 3) {
jpeg_addr.cb = jpeg_addr.y + pix_size;
if (fmt->fourcc == V4L2_PIX_FMT_YUV420)
jpeg_addr.cr = jpeg_addr.cb + pix_size / 4;
else
jpeg_addr.cr = jpeg_addr.cb + pix_size / 2;
}
exynos3250_jpeg_imgadr(jpeg->regs, &jpeg_addr);
}
static void exynos3250_jpeg_set_jpeg_addr(struct s5p_jpeg_ctx *ctx)
{
struct s5p_jpeg *jpeg = ctx->jpeg;
struct vb2_buffer *vb;
unsigned int jpeg_addr = 0;
if (ctx->mode == S5P_JPEG_ENCODE)
vb = v4l2_m2m_next_dst_buf(ctx->fh.m2m_ctx);
else
vb = v4l2_m2m_next_src_buf(ctx->fh.m2m_ctx);
jpeg_addr = vb2_dma_contig_plane_dma_addr(vb, 0);
exynos3250_jpeg_jpgadr(jpeg->regs, jpeg_addr);
}
static void exynos3250_jpeg_device_run(void *priv)
{
struct s5p_jpeg_ctx *ctx = priv;
struct s5p_jpeg *jpeg = ctx->jpeg;
unsigned long flags;
spin_lock_irqsave(&ctx->jpeg->slock, flags);
exynos3250_jpeg_reset(jpeg->regs);
exynos3250_jpeg_set_dma_num(jpeg->regs);
exynos3250_jpeg_poweron(jpeg->regs);
exynos3250_jpeg_clk_set(jpeg->regs);
exynos3250_jpeg_proc_mode(jpeg->regs, ctx->mode);
if (ctx->mode == S5P_JPEG_ENCODE) {
exynos3250_jpeg_input_raw_fmt(jpeg->regs,
ctx->out_q.fmt->fourcc);
exynos3250_jpeg_dri(jpeg->regs, ctx->restart_interval);
s5p_jpeg_set_qtbl_lum(jpeg->regs, ctx->compr_quality);
s5p_jpeg_set_qtbl_chr(jpeg->regs, ctx->compr_quality);
exynos3250_jpeg_qtbl(jpeg->regs, 1, 0);
exynos3250_jpeg_qtbl(jpeg->regs, 2, 1);
exynos3250_jpeg_qtbl(jpeg->regs, 3, 1);
exynos3250_jpeg_htbl_ac(jpeg->regs, 1);
exynos3250_jpeg_htbl_dc(jpeg->regs, 1);
exynos3250_jpeg_htbl_ac(jpeg->regs, 2);
exynos3250_jpeg_htbl_dc(jpeg->regs, 2);
exynos3250_jpeg_htbl_ac(jpeg->regs, 3);
exynos3250_jpeg_htbl_dc(jpeg->regs, 3);
exynos3250_jpeg_set_x(jpeg->regs, ctx->crop_rect.width);
exynos3250_jpeg_set_y(jpeg->regs, ctx->crop_rect.height);
exynos3250_jpeg_stride(jpeg->regs, ctx->out_q.fmt->fourcc,
ctx->out_q.w);
exynos3250_jpeg_offset(jpeg->regs, ctx->crop_rect.left,
ctx->crop_rect.top);
exynos3250_jpeg_set_img_addr(ctx);
exynos3250_jpeg_set_jpeg_addr(ctx);
exynos3250_jpeg_subsampling_mode(jpeg->regs, ctx->subsampling);
exynos3250_jpeg_enc_stream_bound(jpeg->regs, ctx->cap_q.size);
if (ctx->out_q.fmt->fourcc == V4L2_PIX_FMT_RGB565 ||
ctx->out_q.fmt->fourcc == V4L2_PIX_FMT_RGB565X ||
ctx->out_q.fmt->fourcc == V4L2_PIX_FMT_RGB32)
exynos3250_jpeg_set_y16(jpeg->regs, true);
} else {
exynos3250_jpeg_set_img_addr(ctx);
exynos3250_jpeg_set_jpeg_addr(ctx);
exynos3250_jpeg_stride(jpeg->regs, ctx->cap_q.fmt->fourcc,
ctx->cap_q.w);
exynos3250_jpeg_offset(jpeg->regs, 0, 0);
exynos3250_jpeg_dec_scaling_ratio(jpeg->regs,
ctx->scale_factor);
exynos3250_jpeg_dec_stream_size(jpeg->regs, ctx->out_q.size);
exynos3250_jpeg_output_raw_fmt(jpeg->regs,
ctx->cap_q.fmt->fourcc);
}
exynos3250_jpeg_interrupts_enable(jpeg->regs);
exynos3250_jpeg_coef(jpeg->regs, ctx->mode);
exynos3250_jpeg_set_timer(jpeg->regs, EXYNOS3250_IRQ_TIMEOUT);
jpeg->irq_status = 0;
exynos3250_jpeg_start(jpeg->regs);
spin_unlock_irqrestore(&ctx->jpeg->slock, flags);
}
static int s5p_jpeg_job_ready(void *priv)
{
struct s5p_jpeg_ctx *ctx = priv;
if (ctx->mode == S5P_JPEG_DECODE)
return ctx->hdr_parsed;
return 1;
}
static void s5p_jpeg_job_abort(void *priv)
{
}
static int s5p_jpeg_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct s5p_jpeg_ctx *ctx = vb2_get_drv_priv(vq);
struct s5p_jpeg_q_data *q_data = NULL;
unsigned int size, count = *nbuffers;
q_data = get_q_data(ctx, vq->type);
BUG_ON(q_data == NULL);
size = q_data->size;
if (ctx->mode == S5P_JPEG_DECODE)
count = 1;
*nbuffers = count;
*nplanes = 1;
sizes[0] = size;
alloc_ctxs[0] = ctx->jpeg->alloc_ctx;
return 0;
}
static int s5p_jpeg_buf_prepare(struct vb2_buffer *vb)
{
struct s5p_jpeg_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct s5p_jpeg_q_data *q_data = NULL;
q_data = get_q_data(ctx, vb->vb2_queue->type);
BUG_ON(q_data == NULL);
if (vb2_plane_size(vb, 0) < q_data->size) {
pr_err("%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0),
(long)q_data->size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, q_data->size);
return 0;
}
static void s5p_jpeg_buf_queue(struct vb2_buffer *vb)
{
struct s5p_jpeg_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
if (ctx->mode == S5P_JPEG_DECODE &&
vb->vb2_queue->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
struct s5p_jpeg_q_data tmp, *q_data;
ctx->hdr_parsed = s5p_jpeg_parse_hdr(&tmp,
(unsigned long)vb2_plane_vaddr(vb, 0),
min((unsigned long)ctx->out_q.size,
vb2_get_plane_payload(vb, 0)), ctx);
if (!ctx->hdr_parsed) {
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
return;
}
q_data = &ctx->out_q;
q_data->w = tmp.w;
q_data->h = tmp.h;
q_data = &ctx->cap_q;
q_data->w = tmp.w;
q_data->h = tmp.h;
}
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vb);
}
static int s5p_jpeg_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct s5p_jpeg_ctx *ctx = vb2_get_drv_priv(q);
int ret;
ret = pm_runtime_get_sync(ctx->jpeg->dev);
return ret > 0 ? 0 : ret;
}
static void s5p_jpeg_stop_streaming(struct vb2_queue *q)
{
struct s5p_jpeg_ctx *ctx = vb2_get_drv_priv(q);
pm_runtime_put(ctx->jpeg->dev);
}
static int queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct s5p_jpeg_ctx *ctx = priv;
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
src_vq->ops = &s5p_jpeg_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
src_vq->lock = &ctx->jpeg->lock;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
dst_vq->ops = &s5p_jpeg_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
dst_vq->lock = &ctx->jpeg->lock;
return vb2_queue_init(dst_vq);
}
static irqreturn_t s5p_jpeg_irq(int irq, void *dev_id)
{
struct s5p_jpeg *jpeg = dev_id;
struct s5p_jpeg_ctx *curr_ctx;
struct vb2_buffer *src_buf, *dst_buf;
unsigned long payload_size = 0;
enum vb2_buffer_state state = VB2_BUF_STATE_DONE;
bool enc_jpeg_too_large = false;
bool timer_elapsed = false;
bool op_completed = false;
spin_lock(&jpeg->slock);
curr_ctx = v4l2_m2m_get_curr_priv(jpeg->m2m_dev);
src_buf = v4l2_m2m_src_buf_remove(curr_ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_dst_buf_remove(curr_ctx->fh.m2m_ctx);
if (curr_ctx->mode == S5P_JPEG_ENCODE)
enc_jpeg_too_large = s5p_jpeg_enc_stream_stat(jpeg->regs);
timer_elapsed = s5p_jpeg_timer_stat(jpeg->regs);
op_completed = s5p_jpeg_result_stat_ok(jpeg->regs);
if (curr_ctx->mode == S5P_JPEG_DECODE)
op_completed = op_completed &&
s5p_jpeg_stream_stat_ok(jpeg->regs);
if (enc_jpeg_too_large) {
state = VB2_BUF_STATE_ERROR;
s5p_jpeg_clear_enc_stream_stat(jpeg->regs);
} else if (timer_elapsed) {
state = VB2_BUF_STATE_ERROR;
s5p_jpeg_clear_timer_stat(jpeg->regs);
} else if (!op_completed) {
state = VB2_BUF_STATE_ERROR;
} else {
payload_size = s5p_jpeg_compressed_size(jpeg->regs);
}
dst_buf->v4l2_buf.timecode = src_buf->v4l2_buf.timecode;
dst_buf->v4l2_buf.timestamp = src_buf->v4l2_buf.timestamp;
dst_buf->v4l2_buf.flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
dst_buf->v4l2_buf.flags |=
src_buf->v4l2_buf.flags & V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
v4l2_m2m_buf_done(src_buf, state);
if (curr_ctx->mode == S5P_JPEG_ENCODE)
vb2_set_plane_payload(dst_buf, 0, payload_size);
v4l2_m2m_buf_done(dst_buf, state);
v4l2_m2m_job_finish(jpeg->m2m_dev, curr_ctx->fh.m2m_ctx);
curr_ctx->subsampling = s5p_jpeg_get_subsampling_mode(jpeg->regs);
spin_unlock(&jpeg->slock);
s5p_jpeg_clear_int(jpeg->regs);
return IRQ_HANDLED;
}
static irqreturn_t exynos4_jpeg_irq(int irq, void *priv)
{
unsigned int int_status;
struct vb2_buffer *src_vb, *dst_vb;
struct s5p_jpeg *jpeg = priv;
struct s5p_jpeg_ctx *curr_ctx;
unsigned long payload_size = 0;
spin_lock(&jpeg->slock);
curr_ctx = v4l2_m2m_get_curr_priv(jpeg->m2m_dev);
src_vb = v4l2_m2m_src_buf_remove(curr_ctx->fh.m2m_ctx);
dst_vb = v4l2_m2m_dst_buf_remove(curr_ctx->fh.m2m_ctx);
int_status = exynos4_jpeg_get_int_status(jpeg->regs);
if (int_status) {
switch (int_status & 0x1f) {
case 0x1:
jpeg->irq_ret = ERR_PROT;
break;
case 0x2:
jpeg->irq_ret = OK_ENC_OR_DEC;
break;
case 0x4:
jpeg->irq_ret = ERR_DEC_INVALID_FORMAT;
break;
case 0x8:
jpeg->irq_ret = ERR_MULTI_SCAN;
break;
case 0x10:
jpeg->irq_ret = ERR_FRAME;
break;
default:
jpeg->irq_ret = ERR_UNKNOWN;
break;
}
} else {
jpeg->irq_ret = ERR_UNKNOWN;
}
if (jpeg->irq_ret == OK_ENC_OR_DEC) {
if (curr_ctx->mode == S5P_JPEG_ENCODE) {
payload_size = exynos4_jpeg_get_stream_size(jpeg->regs);
vb2_set_plane_payload(dst_vb, 0, payload_size);
}
v4l2_m2m_buf_done(src_vb, VB2_BUF_STATE_DONE);
v4l2_m2m_buf_done(dst_vb, VB2_BUF_STATE_DONE);
} else {
v4l2_m2m_buf_done(src_vb, VB2_BUF_STATE_ERROR);
v4l2_m2m_buf_done(dst_vb, VB2_BUF_STATE_ERROR);
}
v4l2_m2m_job_finish(jpeg->m2m_dev, curr_ctx->fh.m2m_ctx);
curr_ctx->subsampling = exynos4_jpeg_get_frame_fmt(jpeg->regs);
spin_unlock(&jpeg->slock);
return IRQ_HANDLED;
}
static irqreturn_t exynos3250_jpeg_irq(int irq, void *dev_id)
{
struct s5p_jpeg *jpeg = dev_id;
struct s5p_jpeg_ctx *curr_ctx;
struct vb2_buffer *src_buf, *dst_buf;
unsigned long payload_size = 0;
enum vb2_buffer_state state = VB2_BUF_STATE_DONE;
bool interrupt_timeout = false;
u32 irq_status;
spin_lock(&jpeg->slock);
irq_status = exynos3250_jpeg_get_timer_status(jpeg->regs);
if (irq_status & EXYNOS3250_TIMER_INT_STAT) {
exynos3250_jpeg_clear_timer_status(jpeg->regs);
interrupt_timeout = true;
dev_err(jpeg->dev, "Interrupt timeout occurred.\n");
}
irq_status = exynos3250_jpeg_get_int_status(jpeg->regs);
exynos3250_jpeg_clear_int_status(jpeg->regs, irq_status);
jpeg->irq_status |= irq_status;
curr_ctx = v4l2_m2m_get_curr_priv(jpeg->m2m_dev);
if (!curr_ctx)
goto exit_unlock;
if ((irq_status & EXYNOS3250_HEADER_STAT) &&
(curr_ctx->mode == S5P_JPEG_DECODE)) {
exynos3250_jpeg_rstart(jpeg->regs);
goto exit_unlock;
}
if (jpeg->irq_status & (EXYNOS3250_JPEG_DONE |
EXYNOS3250_WDMA_DONE |
EXYNOS3250_RDMA_DONE |
EXYNOS3250_RESULT_STAT))
payload_size = exynos3250_jpeg_compressed_size(jpeg->regs);
else if (interrupt_timeout)
state = VB2_BUF_STATE_ERROR;
else
goto exit_unlock;
src_buf = v4l2_m2m_src_buf_remove(curr_ctx->fh.m2m_ctx);
dst_buf = v4l2_m2m_dst_buf_remove(curr_ctx->fh.m2m_ctx);
dst_buf->v4l2_buf.timecode = src_buf->v4l2_buf.timecode;
dst_buf->v4l2_buf.timestamp = src_buf->v4l2_buf.timestamp;
v4l2_m2m_buf_done(src_buf, state);
if (curr_ctx->mode == S5P_JPEG_ENCODE)
vb2_set_plane_payload(dst_buf, 0, payload_size);
v4l2_m2m_buf_done(dst_buf, state);
v4l2_m2m_job_finish(jpeg->m2m_dev, curr_ctx->fh.m2m_ctx);
curr_ctx->subsampling =
exynos3250_jpeg_get_subsampling_mode(jpeg->regs);
exit_unlock:
spin_unlock(&jpeg->slock);
return IRQ_HANDLED;
}
static int s5p_jpeg_probe(struct platform_device *pdev)
{
struct s5p_jpeg *jpeg;
struct resource *res;
int ret;
jpeg = devm_kzalloc(&pdev->dev, sizeof(struct s5p_jpeg), GFP_KERNEL);
if (!jpeg)
return -ENOMEM;
jpeg->variant = jpeg_get_drv_data(&pdev->dev);
mutex_init(&jpeg->lock);
spin_lock_init(&jpeg->slock);
jpeg->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
jpeg->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(jpeg->regs))
return PTR_ERR(jpeg->regs);
jpeg->irq = ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "cannot find IRQ\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, jpeg->irq, jpeg->variant->jpeg_irq,
0, dev_name(&pdev->dev), jpeg);
if (ret) {
dev_err(&pdev->dev, "cannot claim IRQ %d\n", jpeg->irq);
return ret;
}
jpeg->clk = clk_get(&pdev->dev, "jpeg");
if (IS_ERR(jpeg->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
ret = PTR_ERR(jpeg->clk);
return ret;
}
dev_dbg(&pdev->dev, "clock source %p\n", jpeg->clk);
jpeg->sclk = clk_get(&pdev->dev, "sclk");
if (IS_ERR(jpeg->sclk))
dev_info(&pdev->dev, "sclk clock not available\n");
ret = v4l2_device_register(&pdev->dev, &jpeg->v4l2_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to register v4l2 device\n");
goto clk_get_rollback;
}
jpeg->m2m_dev = v4l2_m2m_init(jpeg->variant->m2m_ops);
if (IS_ERR(jpeg->m2m_dev)) {
v4l2_err(&jpeg->v4l2_dev, "Failed to init mem2mem device\n");
ret = PTR_ERR(jpeg->m2m_dev);
goto device_register_rollback;
}
jpeg->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(jpeg->alloc_ctx)) {
v4l2_err(&jpeg->v4l2_dev, "Failed to init memory allocator\n");
ret = PTR_ERR(jpeg->alloc_ctx);
goto m2m_init_rollback;
}
jpeg->vfd_encoder = video_device_alloc();
if (!jpeg->vfd_encoder) {
v4l2_err(&jpeg->v4l2_dev, "Failed to allocate video device\n");
ret = -ENOMEM;
goto vb2_allocator_rollback;
}
snprintf(jpeg->vfd_encoder->name, sizeof(jpeg->vfd_encoder->name),
"%s-enc", S5P_JPEG_M2M_NAME);
jpeg->vfd_encoder->fops = &s5p_jpeg_fops;
jpeg->vfd_encoder->ioctl_ops = &s5p_jpeg_ioctl_ops;
jpeg->vfd_encoder->minor = -1;
jpeg->vfd_encoder->release = video_device_release;
jpeg->vfd_encoder->lock = &jpeg->lock;
jpeg->vfd_encoder->v4l2_dev = &jpeg->v4l2_dev;
jpeg->vfd_encoder->vfl_dir = VFL_DIR_M2M;
ret = video_register_device(jpeg->vfd_encoder, VFL_TYPE_GRABBER, -1);
if (ret) {
v4l2_err(&jpeg->v4l2_dev, "Failed to register video device\n");
goto enc_vdev_alloc_rollback;
}
video_set_drvdata(jpeg->vfd_encoder, jpeg);
v4l2_info(&jpeg->v4l2_dev,
"encoder device registered as /dev/video%d\n",
jpeg->vfd_encoder->num);
jpeg->vfd_decoder = video_device_alloc();
if (!jpeg->vfd_decoder) {
v4l2_err(&jpeg->v4l2_dev, "Failed to allocate video device\n");
ret = -ENOMEM;
goto enc_vdev_register_rollback;
}
snprintf(jpeg->vfd_decoder->name, sizeof(jpeg->vfd_decoder->name),
"%s-dec", S5P_JPEG_M2M_NAME);
jpeg->vfd_decoder->fops = &s5p_jpeg_fops;
jpeg->vfd_decoder->ioctl_ops = &s5p_jpeg_ioctl_ops;
jpeg->vfd_decoder->minor = -1;
jpeg->vfd_decoder->release = video_device_release;
jpeg->vfd_decoder->lock = &jpeg->lock;
jpeg->vfd_decoder->v4l2_dev = &jpeg->v4l2_dev;
jpeg->vfd_decoder->vfl_dir = VFL_DIR_M2M;
ret = video_register_device(jpeg->vfd_decoder, VFL_TYPE_GRABBER, -1);
if (ret) {
v4l2_err(&jpeg->v4l2_dev, "Failed to register video device\n");
goto dec_vdev_alloc_rollback;
}
video_set_drvdata(jpeg->vfd_decoder, jpeg);
v4l2_info(&jpeg->v4l2_dev,
"decoder device registered as /dev/video%d\n",
jpeg->vfd_decoder->num);
platform_set_drvdata(pdev, jpeg);
pm_runtime_enable(&pdev->dev);
v4l2_info(&jpeg->v4l2_dev, "Samsung S5P JPEG codec\n");
return 0;
dec_vdev_alloc_rollback:
video_device_release(jpeg->vfd_decoder);
enc_vdev_register_rollback:
video_unregister_device(jpeg->vfd_encoder);
enc_vdev_alloc_rollback:
video_device_release(jpeg->vfd_encoder);
vb2_allocator_rollback:
vb2_dma_contig_cleanup_ctx(jpeg->alloc_ctx);
m2m_init_rollback:
v4l2_m2m_release(jpeg->m2m_dev);
device_register_rollback:
v4l2_device_unregister(&jpeg->v4l2_dev);
clk_get_rollback:
clk_put(jpeg->clk);
if (!IS_ERR(jpeg->sclk))
clk_put(jpeg->sclk);
return ret;
}
static int s5p_jpeg_remove(struct platform_device *pdev)
{
struct s5p_jpeg *jpeg = platform_get_drvdata(pdev);
pm_runtime_disable(jpeg->dev);
video_unregister_device(jpeg->vfd_decoder);
video_device_release(jpeg->vfd_decoder);
video_unregister_device(jpeg->vfd_encoder);
video_device_release(jpeg->vfd_encoder);
vb2_dma_contig_cleanup_ctx(jpeg->alloc_ctx);
v4l2_m2m_release(jpeg->m2m_dev);
v4l2_device_unregister(&jpeg->v4l2_dev);
if (!pm_runtime_status_suspended(&pdev->dev)) {
clk_disable_unprepare(jpeg->clk);
if (!IS_ERR(jpeg->sclk))
clk_disable_unprepare(jpeg->sclk);
}
clk_put(jpeg->clk);
if (!IS_ERR(jpeg->sclk))
clk_put(jpeg->sclk);
return 0;
}
static int s5p_jpeg_runtime_suspend(struct device *dev)
{
struct s5p_jpeg *jpeg = dev_get_drvdata(dev);
clk_disable_unprepare(jpeg->clk);
if (!IS_ERR(jpeg->sclk))
clk_disable_unprepare(jpeg->sclk);
return 0;
}
static int s5p_jpeg_runtime_resume(struct device *dev)
{
struct s5p_jpeg *jpeg = dev_get_drvdata(dev);
unsigned long flags;
int ret;
ret = clk_prepare_enable(jpeg->clk);
if (ret < 0)
return ret;
if (!IS_ERR(jpeg->sclk)) {
ret = clk_prepare_enable(jpeg->sclk);
if (ret < 0)
return ret;
}
spin_lock_irqsave(&jpeg->slock, flags);
if (jpeg->variant->version == SJPEG_S5P ||
jpeg->variant->version == SJPEG_EXYNOS3250) {
s5p_jpeg_set_hdctbl(jpeg->regs);
s5p_jpeg_set_hdctblg(jpeg->regs);
s5p_jpeg_set_hactbl(jpeg->regs);
s5p_jpeg_set_hactblg(jpeg->regs);
}
spin_unlock_irqrestore(&jpeg->slock, flags);
return 0;
}
static int s5p_jpeg_suspend(struct device *dev)
{
if (pm_runtime_suspended(dev))
return 0;
return s5p_jpeg_runtime_suspend(dev);
}
static int s5p_jpeg_resume(struct device *dev)
{
if (pm_runtime_suspended(dev))
return 0;
return s5p_jpeg_runtime_resume(dev);
}
static void *jpeg_get_drv_data(struct device *dev)
{
struct s5p_jpeg_variant *driver_data = NULL;
const struct of_device_id *match;
if (!IS_ENABLED(CONFIG_OF) || !dev->of_node)
return &s5p_jpeg_drvdata;
match = of_match_node(samsung_jpeg_match, dev->of_node);
if (match)
driver_data = (struct s5p_jpeg_variant *)match->data;
return driver_data;
}
