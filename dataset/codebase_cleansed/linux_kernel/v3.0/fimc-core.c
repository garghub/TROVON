static struct v4l2_queryctrl *get_ctrl(int id)
{
int i;
for (i = 0; i < ARRAY_SIZE(fimc_ctrls); ++i)
if (id == fimc_ctrls[i].id)
return &fimc_ctrls[i];
return NULL;
}
int fimc_check_scaler_ratio(int sw, int sh, int dw, int dh, int rot)
{
int tx, ty;
if (rot == 90 || rot == 270) {
ty = dw;
tx = dh;
} else {
tx = dw;
ty = dh;
}
if ((sw >= SCALER_MAX_HRATIO * tx) || (sh >= SCALER_MAX_VRATIO * ty))
return -EINVAL;
return 0;
}
static int fimc_get_scaler_factor(u32 src, u32 tar, u32 *ratio, u32 *shift)
{
u32 sh = 6;
if (src >= 64 * tar)
return -EINVAL;
while (sh--) {
u32 tmp = 1 << sh;
if (src >= tar * tmp) {
*shift = sh, *ratio = tmp;
return 0;
}
}
*shift = 0, *ratio = 1;
return 0;
}
int fimc_set_scaler_info(struct fimc_ctx *ctx)
{
struct fimc_scaler *sc = &ctx->scaler;
struct fimc_frame *s_frame = &ctx->s_frame;
struct fimc_frame *d_frame = &ctx->d_frame;
struct samsung_fimc_variant *variant = ctx->fimc_dev->variant;
int tx, ty, sx, sy;
int ret;
if (ctx->rotation == 90 || ctx->rotation == 270) {
ty = d_frame->width;
tx = d_frame->height;
} else {
tx = d_frame->width;
ty = d_frame->height;
}
if (tx <= 0 || ty <= 0) {
v4l2_err(&ctx->fimc_dev->m2m.v4l2_dev,
"invalid target size: %d x %d", tx, ty);
return -EINVAL;
}
sx = s_frame->width;
sy = s_frame->height;
if (sx <= 0 || sy <= 0) {
err("invalid source size: %d x %d", sx, sy);
return -EINVAL;
}
sc->real_width = sx;
sc->real_height = sy;
ret = fimc_get_scaler_factor(sx, tx, &sc->pre_hratio, &sc->hfactor);
if (ret)
return ret;
ret = fimc_get_scaler_factor(sy, ty, &sc->pre_vratio, &sc->vfactor);
if (ret)
return ret;
sc->pre_dst_width = sx / sc->pre_hratio;
sc->pre_dst_height = sy / sc->pre_vratio;
if (variant->has_mainscaler_ext) {
sc->main_hratio = (sx << 14) / (tx << sc->hfactor);
sc->main_vratio = (sy << 14) / (ty << sc->vfactor);
} else {
sc->main_hratio = (sx << 8) / (tx << sc->hfactor);
sc->main_vratio = (sy << 8) / (ty << sc->vfactor);
}
sc->scaleup_h = (tx >= sx) ? 1 : 0;
sc->scaleup_v = (ty >= sy) ? 1 : 0;
if (s_frame->fmt->color == d_frame->fmt->color
&& s_frame->width == d_frame->width
&& s_frame->height == d_frame->height)
sc->copy_mode = 1;
else
sc->copy_mode = 0;
return 0;
}
static void fimc_m2m_job_finish(struct fimc_ctx *ctx, int vb_state)
{
struct vb2_buffer *src_vb, *dst_vb;
struct fimc_dev *fimc = ctx->fimc_dev;
if (!ctx || !ctx->m2m_ctx)
return;
src_vb = v4l2_m2m_src_buf_remove(ctx->m2m_ctx);
dst_vb = v4l2_m2m_dst_buf_remove(ctx->m2m_ctx);
if (src_vb && dst_vb) {
v4l2_m2m_buf_done(src_vb, vb_state);
v4l2_m2m_buf_done(dst_vb, vb_state);
v4l2_m2m_job_finish(fimc->m2m.m2m_dev, ctx->m2m_ctx);
}
}
static void fimc_m2m_shutdown(struct fimc_ctx *ctx)
{
struct fimc_dev *fimc = ctx->fimc_dev;
int ret;
if (!fimc_m2m_pending(fimc))
return;
fimc_ctx_state_lock_set(FIMC_CTX_SHUT, ctx);
ret = wait_event_timeout(fimc->irq_queue,
!fimc_ctx_state_is_set(FIMC_CTX_SHUT, ctx),
FIMC_SHUTDOWN_TIMEOUT);
if (ret == 0)
fimc_m2m_job_finish(ctx, VB2_BUF_STATE_ERROR);
}
static int stop_streaming(struct vb2_queue *q)
{
struct fimc_ctx *ctx = q->drv_priv;
fimc_m2m_shutdown(ctx);
return 0;
}
static void fimc_capture_irq_handler(struct fimc_dev *fimc)
{
struct fimc_vid_cap *cap = &fimc->vid_cap;
struct fimc_vid_buffer *v_buf;
struct timeval *tv;
struct timespec ts;
if (!list_empty(&cap->active_buf_q) &&
test_bit(ST_CAPT_RUN, &fimc->state)) {
ktime_get_real_ts(&ts);
v_buf = active_queue_pop(cap);
tv = &v_buf->vb.v4l2_buf.timestamp;
tv->tv_sec = ts.tv_sec;
tv->tv_usec = ts.tv_nsec / NSEC_PER_USEC;
v_buf->vb.v4l2_buf.sequence = cap->frame_count++;
vb2_buffer_done(&v_buf->vb, VB2_BUF_STATE_DONE);
}
if (test_and_clear_bit(ST_CAPT_SHUT, &fimc->state)) {
wake_up(&fimc->irq_queue);
return;
}
if (!list_empty(&cap->pending_buf_q)) {
v_buf = pending_queue_pop(cap);
fimc_hw_set_output_addr(fimc, &v_buf->paddr, cap->buf_index);
v_buf->index = cap->buf_index;
active_queue_add(cap, v_buf);
dbg("next frame: %d, done frame: %d",
fimc_hw_get_frame_index(fimc), v_buf->index);
if (++cap->buf_index >= FIMC_MAX_OUT_BUFS)
cap->buf_index = 0;
}
if (cap->active_buf_cnt == 0) {
clear_bit(ST_CAPT_RUN, &fimc->state);
if (++cap->buf_index >= FIMC_MAX_OUT_BUFS)
cap->buf_index = 0;
} else {
set_bit(ST_CAPT_RUN, &fimc->state);
}
dbg("frame: %d, active_buf_cnt: %d",
fimc_hw_get_frame_index(fimc), cap->active_buf_cnt);
}
static irqreturn_t fimc_isr(int irq, void *priv)
{
struct fimc_dev *fimc = priv;
struct fimc_vid_cap *cap = &fimc->vid_cap;
struct fimc_ctx *ctx;
fimc_hw_clear_irq(fimc);
if (test_and_clear_bit(ST_M2M_PEND, &fimc->state)) {
ctx = v4l2_m2m_get_curr_priv(fimc->m2m.m2m_dev);
if (ctx != NULL) {
fimc_m2m_job_finish(ctx, VB2_BUF_STATE_DONE);
spin_lock(&ctx->slock);
if (ctx->state & FIMC_CTX_SHUT) {
ctx->state &= ~FIMC_CTX_SHUT;
wake_up(&fimc->irq_queue);
}
spin_unlock(&ctx->slock);
}
return IRQ_HANDLED;
}
spin_lock(&fimc->slock);
if (test_bit(ST_CAPT_PEND, &fimc->state)) {
fimc_capture_irq_handler(fimc);
if (cap->active_buf_cnt == 1) {
fimc_deactivate_capture(fimc);
clear_bit(ST_CAPT_STREAM, &fimc->state);
}
}
spin_unlock(&fimc->slock);
return IRQ_HANDLED;
}
int fimc_prepare_addr(struct fimc_ctx *ctx, struct vb2_buffer *vb,
struct fimc_frame *frame, struct fimc_addr *paddr)
{
int ret = 0;
u32 pix_size;
if (vb == NULL || frame == NULL)
return -EINVAL;
pix_size = frame->width * frame->height;
dbg("memplanes= %d, colplanes= %d, pix_size= %d",
frame->fmt->memplanes, frame->fmt->colplanes, pix_size);
paddr->y = vb2_dma_contig_plane_paddr(vb, 0);
if (frame->fmt->memplanes == 1) {
switch (frame->fmt->colplanes) {
case 1:
paddr->cb = 0;
paddr->cr = 0;
break;
case 2:
paddr->cb = (u32)(paddr->y + pix_size);
paddr->cr = 0;
break;
case 3:
paddr->cb = (u32)(paddr->y + pix_size);
if (S5P_FIMC_YCBCR420 == frame->fmt->color)
paddr->cr = (u32)(paddr->cb
+ (pix_size >> 2));
else
paddr->cr = (u32)(paddr->cb
+ (pix_size >> 1));
break;
default:
return -EINVAL;
}
} else {
if (frame->fmt->memplanes >= 2)
paddr->cb = vb2_dma_contig_plane_paddr(vb, 1);
if (frame->fmt->memplanes == 3)
paddr->cr = vb2_dma_contig_plane_paddr(vb, 2);
}
dbg("PHYS_ADDR: y= 0x%X cb= 0x%X cr= 0x%X ret= %d",
paddr->y, paddr->cb, paddr->cr, ret);
return ret;
}
static void fimc_set_yuv_order(struct fimc_ctx *ctx)
{
ctx->in_order_2p = S5P_FIMC_LSB_CRCB;
ctx->out_order_2p = S5P_FIMC_LSB_CRCB;
switch (ctx->s_frame.fmt->color) {
case S5P_FIMC_YCRYCB422:
ctx->in_order_1p = S5P_MSCTRL_ORDER422_CBYCRY;
break;
case S5P_FIMC_CBYCRY422:
ctx->in_order_1p = S5P_MSCTRL_ORDER422_YCRYCB;
break;
case S5P_FIMC_CRYCBY422:
ctx->in_order_1p = S5P_MSCTRL_ORDER422_YCBYCR;
break;
case S5P_FIMC_YCBYCR422:
default:
ctx->in_order_1p = S5P_MSCTRL_ORDER422_CRYCBY;
break;
}
dbg("ctx->in_order_1p= %d", ctx->in_order_1p);
switch (ctx->d_frame.fmt->color) {
case S5P_FIMC_YCRYCB422:
ctx->out_order_1p = S5P_CIOCTRL_ORDER422_CBYCRY;
break;
case S5P_FIMC_CBYCRY422:
ctx->out_order_1p = S5P_CIOCTRL_ORDER422_YCRYCB;
break;
case S5P_FIMC_CRYCBY422:
ctx->out_order_1p = S5P_CIOCTRL_ORDER422_YCBYCR;
break;
case S5P_FIMC_YCBYCR422:
default:
ctx->out_order_1p = S5P_CIOCTRL_ORDER422_CRYCBY;
break;
}
dbg("ctx->out_order_1p= %d", ctx->out_order_1p);
}
static void fimc_prepare_dma_offset(struct fimc_ctx *ctx, struct fimc_frame *f)
{
struct samsung_fimc_variant *variant = ctx->fimc_dev->variant;
u32 i, depth = 0;
for (i = 0; i < f->fmt->colplanes; i++)
depth += f->fmt->depth[i];
f->dma_offset.y_h = f->offs_h;
if (!variant->pix_hoff)
f->dma_offset.y_h *= (depth >> 3);
f->dma_offset.y_v = f->offs_v;
f->dma_offset.cb_h = f->offs_h;
f->dma_offset.cb_v = f->offs_v;
f->dma_offset.cr_h = f->offs_h;
f->dma_offset.cr_v = f->offs_v;
if (!variant->pix_hoff) {
if (f->fmt->colplanes == 3) {
f->dma_offset.cb_h >>= 1;
f->dma_offset.cr_h >>= 1;
}
if (f->fmt->color == S5P_FIMC_YCBCR420) {
f->dma_offset.cb_v >>= 1;
f->dma_offset.cr_v >>= 1;
}
}
dbg("in_offset: color= %d, y_h= %d, y_v= %d",
f->fmt->color, f->dma_offset.y_h, f->dma_offset.y_v);
}
int fimc_prepare_config(struct fimc_ctx *ctx, u32 flags)
{
struct fimc_frame *s_frame, *d_frame;
struct vb2_buffer *vb = NULL;
int ret = 0;
s_frame = &ctx->s_frame;
d_frame = &ctx->d_frame;
if (flags & FIMC_PARAMS) {
fimc_prepare_dma_offset(ctx, &ctx->s_frame);
fimc_prepare_dma_offset(ctx, &ctx->d_frame);
if (s_frame->height > (SCALER_MAX_VRATIO * d_frame->height) ||
s_frame->width > (SCALER_MAX_HRATIO * d_frame->width)) {
err("out of scaler range");
return -EINVAL;
}
fimc_set_yuv_order(ctx);
}
ctx->scaler.enabled = 1;
if (flags & FIMC_SRC_ADDR) {
vb = v4l2_m2m_next_src_buf(ctx->m2m_ctx);
ret = fimc_prepare_addr(ctx, vb, s_frame, &s_frame->paddr);
if (ret)
return ret;
}
if (flags & FIMC_DST_ADDR) {
vb = v4l2_m2m_next_dst_buf(ctx->m2m_ctx);
ret = fimc_prepare_addr(ctx, vb, d_frame, &d_frame->paddr);
}
return ret;
}
static void fimc_dma_run(void *priv)
{
struct fimc_ctx *ctx = priv;
struct fimc_dev *fimc;
unsigned long flags;
u32 ret;
if (WARN(!ctx, "null hardware context\n"))
return;
fimc = ctx->fimc_dev;
spin_lock_irqsave(&ctx->slock, flags);
set_bit(ST_M2M_PEND, &fimc->state);
ctx->state |= (FIMC_SRC_ADDR | FIMC_DST_ADDR);
ret = fimc_prepare_config(ctx, ctx->state);
if (ret)
goto dma_unlock;
if (fimc->m2m.ctx != ctx) {
ctx->state |= FIMC_PARAMS;
fimc->m2m.ctx = ctx;
}
spin_lock(&fimc->slock);
fimc_hw_set_input_addr(fimc, &ctx->s_frame.paddr);
if (ctx->state & FIMC_PARAMS) {
fimc_hw_set_input_path(ctx);
fimc_hw_set_in_dma(ctx);
ret = fimc_set_scaler_info(ctx);
if (ret) {
spin_unlock(&fimc->slock);
goto dma_unlock;
}
fimc_hw_set_prescaler(ctx);
fimc_hw_set_mainscaler(ctx);
fimc_hw_set_target_format(ctx);
fimc_hw_set_rotation(ctx);
fimc_hw_set_effect(ctx);
}
fimc_hw_set_output_path(ctx);
if (ctx->state & (FIMC_DST_ADDR | FIMC_PARAMS))
fimc_hw_set_output_addr(fimc, &ctx->d_frame.paddr, -1);
if (ctx->state & FIMC_PARAMS)
fimc_hw_set_out_dma(ctx);
fimc_activate_capture(ctx);
ctx->state &= (FIMC_CTX_M2M | FIMC_CTX_CAP |
FIMC_SRC_FMT | FIMC_DST_FMT);
fimc_hw_activate_input_dma(fimc, true);
spin_unlock(&fimc->slock);
dma_unlock:
spin_unlock_irqrestore(&ctx->slock, flags);
}
static void fimc_job_abort(void *priv)
{
fimc_m2m_shutdown(priv);
}
static int fimc_queue_setup(struct vb2_queue *vq, unsigned int *num_buffers,
unsigned int *num_planes, unsigned long sizes[],
void *allocators[])
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vq);
struct fimc_frame *f;
int i;
f = ctx_get_frame(ctx, vq->type);
if (IS_ERR(f))
return PTR_ERR(f);
if (!f->fmt)
return -EINVAL;
*num_planes = f->fmt->memplanes;
for (i = 0; i < f->fmt->memplanes; i++) {
sizes[i] = (f->f_width * f->f_height * f->fmt->depth[i]) / 8;
allocators[i] = ctx->fimc_dev->alloc_ctx;
}
return 0;
}
static int fimc_buf_prepare(struct vb2_buffer *vb)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct fimc_frame *frame;
int i;
frame = ctx_get_frame(ctx, vb->vb2_queue->type);
if (IS_ERR(frame))
return PTR_ERR(frame);
for (i = 0; i < frame->fmt->memplanes; i++)
vb2_set_plane_payload(vb, i, frame->payload[i]);
return 0;
}
static void fimc_buf_queue(struct vb2_buffer *vb)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
dbg("ctx: %p, ctx->state: 0x%x", ctx, ctx->state);
if (ctx->m2m_ctx)
v4l2_m2m_buf_queue(ctx->m2m_ctx, vb);
}
static void fimc_lock(struct vb2_queue *vq)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vq);
mutex_lock(&ctx->fimc_dev->lock);
}
static void fimc_unlock(struct vb2_queue *vq)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vq);
mutex_unlock(&ctx->fimc_dev->lock);
}
static int fimc_m2m_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct fimc_ctx *ctx = file->private_data;
struct fimc_dev *fimc = ctx->fimc_dev;
strncpy(cap->driver, fimc->pdev->name, sizeof(cap->driver) - 1);
strncpy(cap->card, fimc->pdev->name, sizeof(cap->card) - 1);
cap->bus_info[0] = 0;
cap->version = KERNEL_VERSION(1, 0, 0);
cap->capabilities = V4L2_CAP_STREAMING |
V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_VIDEO_CAPTURE_MPLANE | V4L2_CAP_VIDEO_OUTPUT_MPLANE;
return 0;
}
int fimc_vidioc_enum_fmt_mplane(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct fimc_fmt *fmt;
if (f->index >= ARRAY_SIZE(fimc_formats))
return -EINVAL;
fmt = &fimc_formats[f->index];
strncpy(f->description, fmt->name, sizeof(f->description) - 1);
f->pixelformat = fmt->fourcc;
return 0;
}
int fimc_vidioc_g_fmt_mplane(struct file *file, void *priv,
struct v4l2_format *f)
{
struct fimc_ctx *ctx = priv;
struct fimc_frame *frame;
struct v4l2_pix_format_mplane *pixm;
int i;
frame = ctx_get_frame(ctx, f->type);
if (IS_ERR(frame))
return PTR_ERR(frame);
pixm = &f->fmt.pix_mp;
pixm->width = frame->width;
pixm->height = frame->height;
pixm->field = V4L2_FIELD_NONE;
pixm->pixelformat = frame->fmt->fourcc;
pixm->colorspace = V4L2_COLORSPACE_JPEG;
pixm->num_planes = frame->fmt->memplanes;
for (i = 0; i < pixm->num_planes; ++i) {
int bpl = frame->o_width;
if (frame->fmt->colplanes == 1)
bpl = (bpl * frame->fmt->depth[0]) / 8;
pixm->plane_fmt[i].bytesperline = bpl;
pixm->plane_fmt[i].sizeimage = (frame->o_width *
frame->o_height * frame->fmt->depth[i]) / 8;
}
return 0;
}
struct fimc_fmt *find_format(struct v4l2_format *f, unsigned int mask)
{
struct fimc_fmt *fmt;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fimc_formats); ++i) {
fmt = &fimc_formats[i];
if (fmt->fourcc == f->fmt.pix_mp.pixelformat &&
(fmt->flags & mask))
break;
}
return (i == ARRAY_SIZE(fimc_formats)) ? NULL : fmt;
}
struct fimc_fmt *find_mbus_format(struct v4l2_mbus_framefmt *f,
unsigned int mask)
{
struct fimc_fmt *fmt;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fimc_formats); ++i) {
fmt = &fimc_formats[i];
if (fmt->mbus_code == f->code && (fmt->flags & mask))
break;
}
return (i == ARRAY_SIZE(fimc_formats)) ? NULL : fmt;
}
int fimc_vidioc_try_fmt_mplane(struct file *file, void *priv,
struct v4l2_format *f)
{
struct fimc_ctx *ctx = priv;
struct fimc_dev *fimc = ctx->fimc_dev;
struct samsung_fimc_variant *variant = fimc->variant;
struct v4l2_pix_format_mplane *pix = &f->fmt.pix_mp;
struct fimc_fmt *fmt;
u32 max_width, mod_x, mod_y, mask;
int i, is_output = 0;
if (f->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE) {
if (fimc_ctx_state_is_set(FIMC_CTX_CAP, ctx))
return -EINVAL;
is_output = 1;
} else if (f->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE) {
return -EINVAL;
}
dbg("w: %d, h: %d", pix->width, pix->height);
mask = is_output ? FMT_FLAGS_M2M : FMT_FLAGS_M2M | FMT_FLAGS_CAM;
fmt = find_format(f, mask);
if (!fmt) {
v4l2_err(&fimc->m2m.v4l2_dev, "Fourcc format (0x%X) invalid.\n",
pix->pixelformat);
return -EINVAL;
}
if (pix->field == V4L2_FIELD_ANY)
pix->field = V4L2_FIELD_NONE;
else if (V4L2_FIELD_NONE != pix->field)
return -EINVAL;
if (is_output) {
max_width = variant->pix_limit->scaler_dis_w;
mod_x = ffs(variant->min_inp_pixsize) - 1;
} else {
max_width = variant->pix_limit->out_rot_dis_w;
mod_x = ffs(variant->min_out_pixsize) - 1;
}
if (tiled_fmt(fmt)) {
mod_x = 6;
mod_y = 5;
} else {
if (fimc->id == 1 && variant->pix_hoff)
mod_y = fimc_fmt_is_rgb(fmt->color) ? 0 : 1;
else
mod_y = mod_x;
}
dbg("mod_x: %d, mod_y: %d, max_w: %d", mod_x, mod_y, max_width);
v4l_bound_align_image(&pix->width, 16, max_width, mod_x,
&pix->height, 8, variant->pix_limit->scaler_dis_w, mod_y, 0);
pix->num_planes = fmt->memplanes;
pix->colorspace = V4L2_COLORSPACE_JPEG;
for (i = 0; i < pix->num_planes; ++i) {
u32 bpl = pix->plane_fmt[i].bytesperline;
u32 *sizeimage = &pix->plane_fmt[i].sizeimage;
if (fmt->colplanes > 1 && (bpl == 0 || bpl < pix->width))
bpl = pix->width;
if (fmt->colplanes == 1 &&
(bpl == 0 || ((bpl * 8) / fmt->depth[i]) < pix->width))
bpl = (pix->width * fmt->depth[0]) / 8;
if (i == 0)
mod_x = bpl;
pix->plane_fmt[i].bytesperline = mod_x;
*sizeimage = (pix->width * pix->height * fmt->depth[i]) / 8;
}
return 0;
}
static int fimc_m2m_s_fmt_mplane(struct file *file, void *priv,
struct v4l2_format *f)
{
struct fimc_ctx *ctx = priv;
struct fimc_dev *fimc = ctx->fimc_dev;
struct vb2_queue *vq;
struct fimc_frame *frame;
struct v4l2_pix_format_mplane *pix;
int i, ret = 0;
ret = fimc_vidioc_try_fmt_mplane(file, priv, f);
if (ret)
return ret;
vq = v4l2_m2m_get_vq(ctx->m2m_ctx, f->type);
if (vb2_is_busy(vq)) {
v4l2_err(&fimc->m2m.v4l2_dev, "queue (%d) busy\n", f->type);
return -EBUSY;
}
if (f->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE) {
frame = &ctx->s_frame;
} else if (f->type == V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE) {
frame = &ctx->d_frame;
} else {
v4l2_err(&fimc->m2m.v4l2_dev,
"Wrong buffer/video queue type (%d)\n", f->type);
return -EINVAL;
}
pix = &f->fmt.pix_mp;
frame->fmt = find_format(f, FMT_FLAGS_M2M);
if (!frame->fmt)
return -EINVAL;
for (i = 0; i < frame->fmt->colplanes; i++) {
frame->payload[i] =
(pix->width * pix->height * frame->fmt->depth[i]) / 8;
}
frame->f_width = pix->plane_fmt[0].bytesperline * 8 /
frame->fmt->depth[0];
frame->f_height = pix->height;
frame->width = pix->width;
frame->height = pix->height;
frame->o_width = pix->width;
frame->o_height = pix->height;
frame->offs_h = 0;
frame->offs_v = 0;
if (f->type == V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
fimc_ctx_state_lock_set(FIMC_PARAMS | FIMC_DST_FMT, ctx);
else
fimc_ctx_state_lock_set(FIMC_PARAMS | FIMC_SRC_FMT, ctx);
dbg("f_w: %d, f_h: %d", frame->f_width, frame->f_height);
return 0;
}
static int fimc_m2m_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbufs)
{
struct fimc_ctx *ctx = priv;
return v4l2_m2m_reqbufs(file, ctx->m2m_ctx, reqbufs);
}
static int fimc_m2m_querybuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_ctx *ctx = priv;
return v4l2_m2m_querybuf(file, ctx->m2m_ctx, buf);
}
static int fimc_m2m_qbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_ctx *ctx = priv;
return v4l2_m2m_qbuf(file, ctx->m2m_ctx, buf);
}
static int fimc_m2m_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_ctx *ctx = priv;
return v4l2_m2m_dqbuf(file, ctx->m2m_ctx, buf);
}
static int fimc_m2m_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_ctx *ctx = priv;
if (V4L2_TYPE_IS_OUTPUT(type)) {
if (!fimc_ctx_state_is_set(FIMC_SRC_FMT, ctx))
return -EINVAL;
} else if (!fimc_ctx_state_is_set(FIMC_DST_FMT, ctx)) {
return -EINVAL;
}
return v4l2_m2m_streamon(file, ctx->m2m_ctx, type);
}
static int fimc_m2m_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_ctx *ctx = priv;
return v4l2_m2m_streamoff(file, ctx->m2m_ctx, type);
}
int fimc_vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
struct fimc_ctx *ctx = priv;
struct v4l2_queryctrl *c;
int ret = -EINVAL;
c = get_ctrl(qc->id);
if (c) {
*qc = *c;
return 0;
}
if (fimc_ctx_state_is_set(FIMC_CTX_CAP, ctx)) {
return v4l2_subdev_call(ctx->fimc_dev->vid_cap.sd,
core, queryctrl, qc);
}
return ret;
}
int fimc_vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct fimc_ctx *ctx = priv;
struct fimc_dev *fimc = ctx->fimc_dev;
switch (ctrl->id) {
case V4L2_CID_HFLIP:
ctrl->value = (FLIP_X_AXIS & ctx->flip) ? 1 : 0;
break;
case V4L2_CID_VFLIP:
ctrl->value = (FLIP_Y_AXIS & ctx->flip) ? 1 : 0;
break;
case V4L2_CID_ROTATE:
ctrl->value = ctx->rotation;
break;
default:
if (fimc_ctx_state_is_set(FIMC_CTX_CAP, ctx)) {
return v4l2_subdev_call(fimc->vid_cap.sd, core,
g_ctrl, ctrl);
} else {
v4l2_err(&fimc->m2m.v4l2_dev, "Invalid control\n");
return -EINVAL;
}
}
dbg("ctrl->value= %d", ctrl->value);
return 0;
}
int check_ctrl_val(struct fimc_ctx *ctx, struct v4l2_control *ctrl)
{
struct v4l2_queryctrl *c;
c = get_ctrl(ctrl->id);
if (!c)
return -EINVAL;
if (ctrl->value < c->minimum || ctrl->value > c->maximum
|| (c->step != 0 && ctrl->value % c->step != 0)) {
v4l2_err(&ctx->fimc_dev->m2m.v4l2_dev,
"Invalid control value\n");
return -ERANGE;
}
return 0;
}
int fimc_s_ctrl(struct fimc_ctx *ctx, struct v4l2_control *ctrl)
{
struct samsung_fimc_variant *variant = ctx->fimc_dev->variant;
struct fimc_dev *fimc = ctx->fimc_dev;
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_HFLIP:
if (ctrl->value)
ctx->flip |= FLIP_X_AXIS;
else
ctx->flip &= ~FLIP_X_AXIS;
break;
case V4L2_CID_VFLIP:
if (ctrl->value)
ctx->flip |= FLIP_Y_AXIS;
else
ctx->flip &= ~FLIP_Y_AXIS;
break;
case V4L2_CID_ROTATE:
if (fimc_ctx_state_is_set(FIMC_DST_FMT | FIMC_SRC_FMT, ctx)) {
ret = fimc_check_scaler_ratio(ctx->s_frame.width,
ctx->s_frame.height, ctx->d_frame.width,
ctx->d_frame.height, ctrl->value);
}
if (ret) {
v4l2_err(&fimc->m2m.v4l2_dev, "Out of scaler range\n");
return -EINVAL;
}
if ((ctrl->value == 90 || ctrl->value == 270) &&
(ctx->in_path == FIMC_DMA && !variant->has_out_rot))
return -EINVAL;
ctx->rotation = ctrl->value;
break;
default:
v4l2_err(&fimc->m2m.v4l2_dev, "Invalid control\n");
return -EINVAL;
}
fimc_ctx_state_lock_set(FIMC_PARAMS, ctx);
return 0;
}
static int fimc_m2m_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct fimc_ctx *ctx = priv;
int ret = 0;
ret = check_ctrl_val(ctx, ctrl);
if (ret)
return ret;
ret = fimc_s_ctrl(ctx, ctrl);
return 0;
}
static int fimc_m2m_cropcap(struct file *file, void *fh,
struct v4l2_cropcap *cr)
{
struct fimc_frame *frame;
struct fimc_ctx *ctx = fh;
frame = ctx_get_frame(ctx, cr->type);
if (IS_ERR(frame))
return PTR_ERR(frame);
cr->bounds.left = 0;
cr->bounds.top = 0;
cr->bounds.width = frame->f_width;
cr->bounds.height = frame->f_height;
cr->defrect = cr->bounds;
return 0;
}
static int fimc_m2m_g_crop(struct file *file, void *fh, struct v4l2_crop *cr)
{
struct fimc_frame *frame;
struct fimc_ctx *ctx = file->private_data;
frame = ctx_get_frame(ctx, cr->type);
if (IS_ERR(frame))
return PTR_ERR(frame);
cr->c.left = frame->offs_h;
cr->c.top = frame->offs_v;
cr->c.width = frame->width;
cr->c.height = frame->height;
return 0;
}
int fimc_try_crop(struct fimc_ctx *ctx, struct v4l2_crop *cr)
{
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_frame *f;
u32 min_size, halign, depth = 0;
bool is_capture_ctx;
int i;
if (cr->c.top < 0 || cr->c.left < 0) {
v4l2_err(&fimc->m2m.v4l2_dev,
"doesn't support negative values for top & left\n");
return -EINVAL;
}
is_capture_ctx = fimc_ctx_state_is_set(FIMC_CTX_CAP, ctx);
if (cr->type == V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
f = is_capture_ctx ? &ctx->s_frame : &ctx->d_frame;
else if (cr->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE &&
!is_capture_ctx)
f = &ctx->s_frame;
else
return -EINVAL;
min_size = (f == &ctx->s_frame) ?
fimc->variant->min_inp_pixsize : fimc->variant->min_out_pixsize;
if (is_capture_ctx) {
min_size = 16;
halign = 4;
} else {
if (fimc->id == 1 && fimc->variant->pix_hoff)
halign = fimc_fmt_is_rgb(f->fmt->color) ? 0 : 1;
else
halign = ffs(min_size) - 1;
}
for (i = 0; i < f->fmt->colplanes; i++)
depth += f->fmt->depth[i];
v4l_bound_align_image(&cr->c.width, min_size, f->o_width,
ffs(min_size) - 1,
&cr->c.height, min_size, f->o_height,
halign, 64/(ALIGN(depth, 8)));
if (cr->c.left + cr->c.width > f->o_width)
cr->c.left = f->o_width - cr->c.width;
if (cr->c.top + cr->c.height > f->o_height)
cr->c.top = f->o_height - cr->c.height;
cr->c.left = round_down(cr->c.left, min_size);
cr->c.top = round_down(cr->c.top, is_capture_ctx ? 16 : 8);
dbg("l:%d, t:%d, w:%d, h:%d, f_w: %d, f_h: %d",
cr->c.left, cr->c.top, cr->c.width, cr->c.height,
f->f_width, f->f_height);
return 0;
}
static int fimc_m2m_s_crop(struct file *file, void *fh, struct v4l2_crop *cr)
{
struct fimc_ctx *ctx = file->private_data;
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_frame *f;
int ret;
ret = fimc_try_crop(ctx, cr);
if (ret)
return ret;
f = (cr->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE) ?
&ctx->s_frame : &ctx->d_frame;
if (fimc_ctx_state_is_set(FIMC_DST_FMT | FIMC_SRC_FMT, ctx)) {
if (cr->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE) {
ret = fimc_check_scaler_ratio(cr->c.width, cr->c.height,
ctx->d_frame.width,
ctx->d_frame.height,
ctx->rotation);
} else {
ret = fimc_check_scaler_ratio(ctx->s_frame.width,
ctx->s_frame.height,
cr->c.width, cr->c.height,
ctx->rotation);
}
if (ret) {
v4l2_err(&fimc->m2m.v4l2_dev, "Out of scaler range\n");
return -EINVAL;
}
}
f->offs_h = cr->c.left;
f->offs_v = cr->c.top;
f->width = cr->c.width;
f->height = cr->c.height;
fimc_ctx_state_lock_set(FIMC_PARAMS, ctx);
return 0;
}
static int queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct fimc_ctx *ctx = priv;
int ret;
memset(src_vq, 0, sizeof(*src_vq));
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR;
src_vq->drv_priv = ctx;
src_vq->ops = &fimc_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
memset(dst_vq, 0, sizeof(*dst_vq));
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR;
dst_vq->drv_priv = ctx;
dst_vq->ops = &fimc_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
return vb2_queue_init(dst_vq);
}
static int fimc_m2m_open(struct file *file)
{
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_ctx *ctx = NULL;
dbg("pid: %d, state: 0x%lx, refcnt: %d",
task_pid_nr(current), fimc->state, fimc->vid_cap.refcnt);
if (fimc->vid_cap.refcnt > 0)
return -EBUSY;
fimc->m2m.refcnt++;
set_bit(ST_OUTDMA_RUN, &fimc->state);
ctx = kzalloc(sizeof *ctx, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
file->private_data = ctx;
ctx->fimc_dev = fimc;
ctx->s_frame.fmt = &fimc_formats[0];
ctx->d_frame.fmt = &fimc_formats[0];
ctx->state = FIMC_CTX_M2M;
ctx->flags = 0;
ctx->in_path = FIMC_DMA;
ctx->out_path = FIMC_DMA;
spin_lock_init(&ctx->slock);
ctx->m2m_ctx = v4l2_m2m_ctx_init(fimc->m2m.m2m_dev, ctx, queue_init);
if (IS_ERR(ctx->m2m_ctx)) {
int err = PTR_ERR(ctx->m2m_ctx);
kfree(ctx);
return err;
}
return 0;
}
static int fimc_m2m_release(struct file *file)
{
struct fimc_ctx *ctx = file->private_data;
struct fimc_dev *fimc = ctx->fimc_dev;
dbg("pid: %d, state: 0x%lx, refcnt= %d",
task_pid_nr(current), fimc->state, fimc->m2m.refcnt);
v4l2_m2m_ctx_release(ctx->m2m_ctx);
kfree(ctx);
if (--fimc->m2m.refcnt <= 0)
clear_bit(ST_OUTDMA_RUN, &fimc->state);
return 0;
}
static unsigned int fimc_m2m_poll(struct file *file,
struct poll_table_struct *wait)
{
struct fimc_ctx *ctx = file->private_data;
return v4l2_m2m_poll(file, ctx->m2m_ctx, wait);
}
static int fimc_m2m_mmap(struct file *file, struct vm_area_struct *vma)
{
struct fimc_ctx *ctx = file->private_data;
return v4l2_m2m_mmap(file, ctx->m2m_ctx, vma);
}
static int fimc_register_m2m_device(struct fimc_dev *fimc)
{
struct video_device *vfd;
struct platform_device *pdev;
struct v4l2_device *v4l2_dev;
int ret = 0;
if (!fimc)
return -ENODEV;
pdev = fimc->pdev;
v4l2_dev = &fimc->m2m.v4l2_dev;
if (!v4l2_dev->name[0])
snprintf(v4l2_dev->name, sizeof(v4l2_dev->name),
"%s.m2m", dev_name(&pdev->dev));
ret = v4l2_device_register(&pdev->dev, v4l2_dev);
if (ret)
goto err_m2m_r1;
vfd = video_device_alloc();
if (!vfd) {
v4l2_err(v4l2_dev, "Failed to allocate video device\n");
goto err_m2m_r1;
}
vfd->fops = &fimc_m2m_fops;
vfd->ioctl_ops = &fimc_m2m_ioctl_ops;
vfd->minor = -1;
vfd->release = video_device_release;
vfd->lock = &fimc->lock;
snprintf(vfd->name, sizeof(vfd->name), "%s:m2m", dev_name(&pdev->dev));
video_set_drvdata(vfd, fimc);
platform_set_drvdata(pdev, fimc);
fimc->m2m.vfd = vfd;
fimc->m2m.m2m_dev = v4l2_m2m_init(&m2m_ops);
if (IS_ERR(fimc->m2m.m2m_dev)) {
v4l2_err(v4l2_dev, "failed to initialize v4l2-m2m device\n");
ret = PTR_ERR(fimc->m2m.m2m_dev);
goto err_m2m_r2;
}
ret = video_register_device(vfd, VFL_TYPE_GRABBER, -1);
if (ret) {
v4l2_err(v4l2_dev,
"%s(): failed to register video device\n", __func__);
goto err_m2m_r3;
}
v4l2_info(v4l2_dev,
"FIMC m2m driver registered as /dev/video%d\n", vfd->num);
return 0;
err_m2m_r3:
v4l2_m2m_release(fimc->m2m.m2m_dev);
err_m2m_r2:
video_device_release(fimc->m2m.vfd);
err_m2m_r1:
v4l2_device_unregister(v4l2_dev);
return ret;
}
static void fimc_unregister_m2m_device(struct fimc_dev *fimc)
{
if (fimc) {
v4l2_m2m_release(fimc->m2m.m2m_dev);
video_unregister_device(fimc->m2m.vfd);
v4l2_device_unregister(&fimc->m2m.v4l2_dev);
}
}
static void fimc_clk_release(struct fimc_dev *fimc)
{
int i;
for (i = 0; i < fimc->num_clocks; i++) {
if (fimc->clock[i]) {
clk_disable(fimc->clock[i]);
clk_put(fimc->clock[i]);
}
}
}
static int fimc_clk_get(struct fimc_dev *fimc)
{
int i;
for (i = 0; i < fimc->num_clocks; i++) {
fimc->clock[i] = clk_get(&fimc->pdev->dev, fimc_clocks[i]);
if (!IS_ERR_OR_NULL(fimc->clock[i])) {
clk_enable(fimc->clock[i]);
continue;
}
dev_err(&fimc->pdev->dev, "failed to get fimc clock: %s\n",
fimc_clocks[i]);
return -ENXIO;
}
return 0;
}
static int fimc_probe(struct platform_device *pdev)
{
struct fimc_dev *fimc;
struct resource *res;
struct samsung_fimc_driverdata *drv_data;
struct s5p_platform_fimc *pdata;
int ret = 0;
int cap_input_index = -1;
dev_dbg(&pdev->dev, "%s():\n", __func__);
drv_data = (struct samsung_fimc_driverdata *)
platform_get_device_id(pdev)->driver_data;
if (pdev->id >= drv_data->num_entities) {
dev_err(&pdev->dev, "Invalid platform device id: %d\n",
pdev->id);
return -EINVAL;
}
fimc = kzalloc(sizeof(struct fimc_dev), GFP_KERNEL);
if (!fimc)
return -ENOMEM;
fimc->id = pdev->id;
fimc->variant = drv_data->variant[fimc->id];
fimc->pdev = pdev;
pdata = pdev->dev.platform_data;
fimc->pdata = pdata;
fimc->state = ST_IDLE;
init_waitqueue_head(&fimc->irq_queue);
spin_lock_init(&fimc->slock);
mutex_init(&fimc->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to find the registers\n");
ret = -ENOENT;
goto err_info;
}
fimc->regs_res = request_mem_region(res->start, resource_size(res),
dev_name(&pdev->dev));
if (!fimc->regs_res) {
dev_err(&pdev->dev, "failed to obtain register region\n");
ret = -ENOENT;
goto err_info;
}
fimc->regs = ioremap(res->start, resource_size(res));
if (!fimc->regs) {
dev_err(&pdev->dev, "failed to map registers\n");
ret = -ENXIO;
goto err_req_region;
}
fimc->num_clocks = MAX_FIMC_CLOCKS - 1;
if (pdata && pdata->num_clients > 0) {
cap_input_index = 0;
fimc->num_clocks++;
}
ret = fimc_clk_get(fimc);
if (ret)
goto err_regs_unmap;
clk_set_rate(fimc->clock[CLK_BUS], drv_data->lclk_frequency);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get IRQ resource\n");
ret = -ENXIO;
goto err_clk;
}
fimc->irq = res->start;
fimc_hw_reset(fimc);
ret = request_irq(fimc->irq, fimc_isr, 0, pdev->name, fimc);
if (ret) {
dev_err(&pdev->dev, "failed to install irq (%d)\n", ret);
goto err_clk;
}
fimc->alloc_ctx = vb2_dma_contig_init_ctx(&fimc->pdev->dev);
if (IS_ERR(fimc->alloc_ctx)) {
ret = PTR_ERR(fimc->alloc_ctx);
goto err_irq;
}
ret = fimc_register_m2m_device(fimc);
if (ret)
goto err_irq;
if (cap_input_index >= 0) {
ret = fimc_register_capture_device(fimc);
if (ret)
goto err_m2m;
clk_disable(fimc->clock[CLK_CAM]);
}
if (fimc->variant->out_buf_count > 4)
fimc_hw_set_dma_seq(fimc, 0xF);
dev_dbg(&pdev->dev, "%s(): fimc-%d registered successfully\n",
__func__, fimc->id);
return 0;
err_m2m:
fimc_unregister_m2m_device(fimc);
err_irq:
free_irq(fimc->irq, fimc);
err_clk:
fimc_clk_release(fimc);
err_regs_unmap:
iounmap(fimc->regs);
err_req_region:
release_resource(fimc->regs_res);
kfree(fimc->regs_res);
err_info:
kfree(fimc);
return ret;
}
static int __devexit fimc_remove(struct platform_device *pdev)
{
struct fimc_dev *fimc =
(struct fimc_dev *)platform_get_drvdata(pdev);
free_irq(fimc->irq, fimc);
fimc_hw_reset(fimc);
fimc_unregister_m2m_device(fimc);
fimc_unregister_capture_device(fimc);
fimc_clk_release(fimc);
vb2_dma_contig_cleanup_ctx(fimc->alloc_ctx);
iounmap(fimc->regs);
release_resource(fimc->regs_res);
kfree(fimc->regs_res);
kfree(fimc);
dev_info(&pdev->dev, "%s driver unloaded\n", pdev->name);
return 0;
}
static int __init fimc_init(void)
{
int ret = platform_driver_register(&fimc_driver);
if (ret)
err("platform_driver_register failed: %d\n", ret);
return ret;
}
static void __exit fimc_exit(void)
{
platform_driver_unregister(&fimc_driver);
}
