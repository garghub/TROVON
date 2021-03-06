struct fimc_fmt *fimc_get_format(unsigned int index)
{
if (index >= ARRAY_SIZE(fimc_formats))
return NULL;
return &fimc_formats[index];
}
int fimc_check_scaler_ratio(struct fimc_ctx *ctx, int sw, int sh,
int dw, int dh, int rotation)
{
if (rotation == 90 || rotation == 270)
swap(dw, dh);
if (!ctx->scaler.enabled)
return (sw == dw && sh == dh) ? 0 : -EINVAL;
if ((sw >= SCALER_MAX_HRATIO * dw) || (sh >= SCALER_MAX_VRATIO * dh))
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
struct fimc_variant *variant = ctx->fimc_dev->variant;
struct device *dev = &ctx->fimc_dev->pdev->dev;
struct fimc_scaler *sc = &ctx->scaler;
struct fimc_frame *s_frame = &ctx->s_frame;
struct fimc_frame *d_frame = &ctx->d_frame;
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
dev_err(dev, "Invalid target size: %dx%d", tx, ty);
return -EINVAL;
}
sx = s_frame->width;
sy = s_frame->height;
if (sx <= 0 || sy <= 0) {
dev_err(dev, "Invalid source size: %dx%d", sx, sy);
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
static irqreturn_t fimc_irq_handler(int irq, void *priv)
{
struct fimc_dev *fimc = priv;
struct fimc_ctx *ctx;
fimc_hw_clear_irq(fimc);
spin_lock(&fimc->slock);
if (test_and_clear_bit(ST_M2M_PEND, &fimc->state)) {
if (test_and_clear_bit(ST_M2M_SUSPENDING, &fimc->state)) {
set_bit(ST_M2M_SUSPENDED, &fimc->state);
wake_up(&fimc->irq_queue);
goto out;
}
ctx = v4l2_m2m_get_curr_priv(fimc->m2m.m2m_dev);
if (ctx != NULL) {
spin_unlock(&fimc->slock);
fimc_m2m_job_finish(ctx, VB2_BUF_STATE_DONE);
if (ctx->state & FIMC_CTX_SHUT) {
ctx->state &= ~FIMC_CTX_SHUT;
wake_up(&fimc->irq_queue);
}
return IRQ_HANDLED;
}
} else if (test_bit(ST_CAPT_PEND, &fimc->state)) {
int last_buf = test_bit(ST_CAPT_JPEG, &fimc->state) &&
fimc->vid_cap.reqbufs_count == 1;
fimc_capture_irq_handler(fimc, !last_buf);
}
out:
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
paddr->y = vb2_dma_contig_plane_dma_addr(vb, 0);
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
if (FIMC_FMT_YCBCR420 == frame->fmt->color)
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
paddr->cb = vb2_dma_contig_plane_dma_addr(vb, 1);
if (frame->fmt->memplanes == 3)
paddr->cr = vb2_dma_contig_plane_dma_addr(vb, 2);
}
dbg("PHYS_ADDR: y= 0x%X cb= 0x%X cr= 0x%X ret= %d",
paddr->y, paddr->cb, paddr->cr, ret);
return ret;
}
void fimc_set_yuv_order(struct fimc_ctx *ctx)
{
ctx->in_order_2p = FIMC_REG_CIOCTRL_ORDER422_2P_LSB_CRCB;
ctx->out_order_2p = FIMC_REG_CIOCTRL_ORDER422_2P_LSB_CRCB;
switch (ctx->s_frame.fmt->color) {
case FIMC_FMT_YCRYCB422:
ctx->in_order_1p = FIMC_REG_MSCTRL_ORDER422_CBYCRY;
break;
case FIMC_FMT_CBYCRY422:
ctx->in_order_1p = FIMC_REG_MSCTRL_ORDER422_YCRYCB;
break;
case FIMC_FMT_CRYCBY422:
ctx->in_order_1p = FIMC_REG_MSCTRL_ORDER422_YCBYCR;
break;
case FIMC_FMT_YCBYCR422:
default:
ctx->in_order_1p = FIMC_REG_MSCTRL_ORDER422_CRYCBY;
break;
}
dbg("ctx->in_order_1p= %d", ctx->in_order_1p);
switch (ctx->d_frame.fmt->color) {
case FIMC_FMT_YCRYCB422:
ctx->out_order_1p = FIMC_REG_CIOCTRL_ORDER422_CBYCRY;
break;
case FIMC_FMT_CBYCRY422:
ctx->out_order_1p = FIMC_REG_CIOCTRL_ORDER422_YCRYCB;
break;
case FIMC_FMT_CRYCBY422:
ctx->out_order_1p = FIMC_REG_CIOCTRL_ORDER422_YCBYCR;
break;
case FIMC_FMT_YCBYCR422:
default:
ctx->out_order_1p = FIMC_REG_CIOCTRL_ORDER422_CRYCBY;
break;
}
dbg("ctx->out_order_1p= %d", ctx->out_order_1p);
}
void fimc_prepare_dma_offset(struct fimc_ctx *ctx, struct fimc_frame *f)
{
struct fimc_variant *variant = ctx->fimc_dev->variant;
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
if (f->fmt->color == FIMC_FMT_YCBCR420) {
f->dma_offset.cb_v >>= 1;
f->dma_offset.cr_v >>= 1;
}
}
dbg("in_offset: color= %d, y_h= %d, y_v= %d",
f->fmt->color, f->dma_offset.y_h, f->dma_offset.y_v);
}
static int fimc_set_color_effect(struct fimc_ctx *ctx, enum v4l2_colorfx colorfx)
{
struct fimc_effect *effect = &ctx->effect;
switch (colorfx) {
case V4L2_COLORFX_NONE:
effect->type = FIMC_REG_CIIMGEFF_FIN_BYPASS;
break;
case V4L2_COLORFX_BW:
effect->type = FIMC_REG_CIIMGEFF_FIN_ARBITRARY;
effect->pat_cb = 128;
effect->pat_cr = 128;
break;
case V4L2_COLORFX_SEPIA:
effect->type = FIMC_REG_CIIMGEFF_FIN_ARBITRARY;
effect->pat_cb = 115;
effect->pat_cr = 145;
break;
case V4L2_COLORFX_NEGATIVE:
effect->type = FIMC_REG_CIIMGEFF_FIN_NEGATIVE;
break;
case V4L2_COLORFX_EMBOSS:
effect->type = FIMC_REG_CIIMGEFF_FIN_EMBOSSING;
break;
case V4L2_COLORFX_ART_FREEZE:
effect->type = FIMC_REG_CIIMGEFF_FIN_ARTFREEZE;
break;
case V4L2_COLORFX_SILHOUETTE:
effect->type = FIMC_REG_CIIMGEFF_FIN_SILHOUETTE;
break;
case V4L2_COLORFX_SET_CBCR:
effect->type = FIMC_REG_CIIMGEFF_FIN_ARBITRARY;
effect->pat_cb = ctx->ctrls.colorfx_cbcr->val >> 8;
effect->pat_cr = ctx->ctrls.colorfx_cbcr->val & 0xff;
break;
default:
return -EINVAL;
}
return 0;
}
static int __fimc_s_ctrl(struct fimc_ctx *ctx, struct v4l2_ctrl *ctrl)
{
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_variant *variant = fimc->variant;
unsigned int flags = FIMC_DST_FMT | FIMC_SRC_FMT;
int ret = 0;
if (ctrl->flags & V4L2_CTRL_FLAG_INACTIVE)
return 0;
switch (ctrl->id) {
case V4L2_CID_HFLIP:
ctx->hflip = ctrl->val;
break;
case V4L2_CID_VFLIP:
ctx->vflip = ctrl->val;
break;
case V4L2_CID_ROTATE:
if (fimc_capture_pending(fimc) ||
(ctx->state & flags) == flags) {
ret = fimc_check_scaler_ratio(ctx, ctx->s_frame.width,
ctx->s_frame.height, ctx->d_frame.width,
ctx->d_frame.height, ctrl->val);
if (ret)
return -EINVAL;
}
if ((ctrl->val == 90 || ctrl->val == 270) &&
!variant->has_out_rot)
return -EINVAL;
ctx->rotation = ctrl->val;
break;
case V4L2_CID_ALPHA_COMPONENT:
ctx->d_frame.alpha = ctrl->val;
break;
case V4L2_CID_COLORFX:
ret = fimc_set_color_effect(ctx, ctrl->val);
if (ret)
return ret;
break;
}
ctx->state |= FIMC_PARAMS;
set_bit(ST_CAPT_APPLY_CFG, &fimc->state);
return 0;
}
static int fimc_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct fimc_ctx *ctx = ctrl_to_ctx(ctrl);
unsigned long flags;
int ret;
spin_lock_irqsave(&ctx->fimc_dev->slock, flags);
ret = __fimc_s_ctrl(ctx, ctrl);
spin_unlock_irqrestore(&ctx->fimc_dev->slock, flags);
return ret;
}
int fimc_ctrls_create(struct fimc_ctx *ctx)
{
struct fimc_variant *variant = ctx->fimc_dev->variant;
unsigned int max_alpha = fimc_get_alpha_mask(ctx->d_frame.fmt);
struct fimc_ctrls *ctrls = &ctx->ctrls;
struct v4l2_ctrl_handler *handler = &ctrls->handler;
if (ctx->ctrls.ready)
return 0;
v4l2_ctrl_handler_init(handler, 6);
ctrls->rotate = v4l2_ctrl_new_std(handler, &fimc_ctrl_ops,
V4L2_CID_ROTATE, 0, 270, 90, 0);
ctrls->hflip = v4l2_ctrl_new_std(handler, &fimc_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
ctrls->vflip = v4l2_ctrl_new_std(handler, &fimc_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
if (variant->has_alpha)
ctrls->alpha = v4l2_ctrl_new_std(handler, &fimc_ctrl_ops,
V4L2_CID_ALPHA_COMPONENT,
0, max_alpha, 1, 0);
else
ctrls->alpha = NULL;
ctrls->colorfx = v4l2_ctrl_new_std_menu(handler, &fimc_ctrl_ops,
V4L2_CID_COLORFX, V4L2_COLORFX_SET_CBCR,
~0x983f, V4L2_COLORFX_NONE);
ctrls->colorfx_cbcr = v4l2_ctrl_new_std(handler, &fimc_ctrl_ops,
V4L2_CID_COLORFX_CBCR, 0, 0xffff, 1, 0);
ctx->effect.type = FIMC_REG_CIIMGEFF_FIN_BYPASS;
if (!handler->error) {
v4l2_ctrl_cluster(2, &ctrls->colorfx);
ctrls->ready = true;
}
return handler->error;
}
void fimc_ctrls_delete(struct fimc_ctx *ctx)
{
struct fimc_ctrls *ctrls = &ctx->ctrls;
if (ctrls->ready) {
v4l2_ctrl_handler_free(&ctrls->handler);
ctrls->ready = false;
ctrls->alpha = NULL;
}
}
void fimc_ctrls_activate(struct fimc_ctx *ctx, bool active)
{
unsigned int has_alpha = ctx->d_frame.fmt->flags & FMT_HAS_ALPHA;
struct fimc_ctrls *ctrls = &ctx->ctrls;
if (!ctrls->ready)
return;
mutex_lock(ctrls->handler.lock);
v4l2_ctrl_activate(ctrls->rotate, active);
v4l2_ctrl_activate(ctrls->hflip, active);
v4l2_ctrl_activate(ctrls->vflip, active);
v4l2_ctrl_activate(ctrls->colorfx, active);
if (ctrls->alpha)
v4l2_ctrl_activate(ctrls->alpha, active && has_alpha);
if (active) {
fimc_set_color_effect(ctx, ctrls->colorfx->cur.val);
ctx->rotation = ctrls->rotate->val;
ctx->hflip = ctrls->hflip->val;
ctx->vflip = ctrls->vflip->val;
} else {
ctx->effect.type = FIMC_REG_CIIMGEFF_FIN_BYPASS;
ctx->rotation = 0;
ctx->hflip = 0;
ctx->vflip = 0;
}
mutex_unlock(ctrls->handler.lock);
}
void fimc_alpha_ctrl_update(struct fimc_ctx *ctx)
{
struct fimc_dev *fimc = ctx->fimc_dev;
struct v4l2_ctrl *ctrl = ctx->ctrls.alpha;
if (ctrl == NULL || !fimc->variant->has_alpha)
return;
v4l2_ctrl_lock(ctrl);
ctrl->maximum = fimc_get_alpha_mask(ctx->d_frame.fmt);
if (ctrl->cur.val > ctrl->maximum)
ctrl->cur.val = ctrl->maximum;
v4l2_ctrl_unlock(ctrl);
}
int fimc_fill_format(struct fimc_frame *frame, struct v4l2_format *f)
{
struct v4l2_pix_format_mplane *pixm = &f->fmt.pix_mp;
int i;
pixm->width = frame->o_width;
pixm->height = frame->o_height;
pixm->field = V4L2_FIELD_NONE;
pixm->pixelformat = frame->fmt->fourcc;
pixm->colorspace = V4L2_COLORSPACE_JPEG;
pixm->num_planes = frame->fmt->memplanes;
for (i = 0; i < pixm->num_planes; ++i) {
int bpl = frame->f_width;
if (frame->fmt->colplanes == 1)
bpl = (bpl * frame->fmt->depth[0]) / 8;
pixm->plane_fmt[i].bytesperline = bpl;
pixm->plane_fmt[i].sizeimage = (frame->o_width *
frame->o_height * frame->fmt->depth[i]) / 8;
}
return 0;
}
void fimc_fill_frame(struct fimc_frame *frame, struct v4l2_format *f)
{
struct v4l2_pix_format_mplane *pixm = &f->fmt.pix_mp;
frame->f_width = pixm->plane_fmt[0].bytesperline;
if (frame->fmt->colplanes == 1)
frame->f_width = (frame->f_width * 8) / frame->fmt->depth[0];
frame->f_height = pixm->height;
frame->width = pixm->width;
frame->height = pixm->height;
frame->o_width = pixm->width;
frame->o_height = pixm->height;
frame->offs_h = 0;
frame->offs_v = 0;
}
void fimc_adjust_mplane_format(struct fimc_fmt *fmt, u32 width, u32 height,
struct v4l2_pix_format_mplane *pix)
{
u32 bytesperline = 0;
int i;
pix->colorspace = V4L2_COLORSPACE_JPEG;
pix->field = V4L2_FIELD_NONE;
pix->num_planes = fmt->memplanes;
pix->pixelformat = fmt->fourcc;
pix->height = height;
pix->width = width;
for (i = 0; i < pix->num_planes; ++i) {
struct v4l2_plane_pix_format *plane_fmt = &pix->plane_fmt[i];
u32 bpl = plane_fmt->bytesperline;
if (fmt->colplanes > 1 && (bpl == 0 || bpl < pix->width))
bpl = pix->width;
if (fmt->colplanes == 1 &&
(bpl == 0 || ((bpl * 8) / fmt->depth[i]) < pix->width))
bpl = (pix->width * fmt->depth[0]) / 8;
if (i == 0)
bytesperline = bpl;
plane_fmt->bytesperline = bytesperline;
plane_fmt->sizeimage = max((pix->width * pix->height *
fmt->depth[i]) / 8, plane_fmt->sizeimage);
}
}
struct fimc_fmt *fimc_find_format(const u32 *pixelformat, const u32 *mbus_code,
unsigned int mask, int index)
{
struct fimc_fmt *fmt, *def_fmt = NULL;
unsigned int i;
int id = 0;
if (index >= (int)ARRAY_SIZE(fimc_formats))
return NULL;
for (i = 0; i < ARRAY_SIZE(fimc_formats); ++i) {
fmt = &fimc_formats[i];
if (!(fmt->flags & mask))
continue;
if (pixelformat && fmt->fourcc == *pixelformat)
return fmt;
if (mbus_code && fmt->mbus_code == *mbus_code)
return fmt;
if (index == id)
def_fmt = fmt;
id++;
}
return def_fmt;
}
static void fimc_clk_put(struct fimc_dev *fimc)
{
int i;
for (i = 0; i < MAX_FIMC_CLOCKS; i++) {
if (IS_ERR_OR_NULL(fimc->clock[i]))
continue;
clk_unprepare(fimc->clock[i]);
clk_put(fimc->clock[i]);
fimc->clock[i] = NULL;
}
}
static int fimc_clk_get(struct fimc_dev *fimc)
{
int i, ret;
for (i = 0; i < MAX_FIMC_CLOCKS; i++) {
fimc->clock[i] = clk_get(&fimc->pdev->dev, fimc_clocks[i]);
if (IS_ERR(fimc->clock[i]))
goto err;
ret = clk_prepare(fimc->clock[i]);
if (ret < 0) {
clk_put(fimc->clock[i]);
fimc->clock[i] = NULL;
goto err;
}
}
return 0;
err:
fimc_clk_put(fimc);
dev_err(&fimc->pdev->dev, "failed to get clock: %s\n",
fimc_clocks[i]);
return -ENXIO;
}
static int fimc_m2m_suspend(struct fimc_dev *fimc)
{
unsigned long flags;
int timeout;
spin_lock_irqsave(&fimc->slock, flags);
if (!fimc_m2m_pending(fimc)) {
spin_unlock_irqrestore(&fimc->slock, flags);
return 0;
}
clear_bit(ST_M2M_SUSPENDED, &fimc->state);
set_bit(ST_M2M_SUSPENDING, &fimc->state);
spin_unlock_irqrestore(&fimc->slock, flags);
timeout = wait_event_timeout(fimc->irq_queue,
test_bit(ST_M2M_SUSPENDED, &fimc->state),
FIMC_SHUTDOWN_TIMEOUT);
clear_bit(ST_M2M_SUSPENDING, &fimc->state);
return timeout == 0 ? -EAGAIN : 0;
}
static int fimc_m2m_resume(struct fimc_dev *fimc)
{
unsigned long flags;
spin_lock_irqsave(&fimc->slock, flags);
fimc->m2m.ctx = NULL;
spin_unlock_irqrestore(&fimc->slock, flags);
if (test_and_clear_bit(ST_M2M_SUSPENDED, &fimc->state))
fimc_m2m_job_finish(fimc->m2m.ctx,
VB2_BUF_STATE_ERROR);
return 0;
}
static int fimc_probe(struct platform_device *pdev)
{
struct fimc_drvdata *drv_data = fimc_get_drvdata(pdev);
struct s5p_platform_fimc *pdata;
struct fimc_dev *fimc;
struct resource *res;
int ret = 0;
if (pdev->id >= drv_data->num_entities) {
dev_err(&pdev->dev, "Invalid platform device id: %d\n",
pdev->id);
return -EINVAL;
}
fimc = devm_kzalloc(&pdev->dev, sizeof(*fimc), GFP_KERNEL);
if (!fimc)
return -ENOMEM;
fimc->id = pdev->id;
fimc->variant = drv_data->variant[fimc->id];
fimc->pdev = pdev;
pdata = pdev->dev.platform_data;
fimc->pdata = pdata;
init_waitqueue_head(&fimc->irq_queue);
spin_lock_init(&fimc->slock);
mutex_init(&fimc->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fimc->regs = devm_request_and_ioremap(&pdev->dev, res);
if (fimc->regs == NULL) {
dev_err(&pdev->dev, "Failed to obtain io memory\n");
return -ENOENT;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(&pdev->dev, "Failed to get IRQ resource\n");
return -ENXIO;
}
ret = fimc_clk_get(fimc);
if (ret)
return ret;
clk_set_rate(fimc->clock[CLK_BUS], drv_data->lclk_frequency);
clk_enable(fimc->clock[CLK_BUS]);
ret = devm_request_irq(&pdev->dev, res->start, fimc_irq_handler,
0, dev_name(&pdev->dev), fimc);
if (ret) {
dev_err(&pdev->dev, "failed to install irq (%d)\n", ret);
goto err_clk;
}
ret = fimc_initialize_capture_subdev(fimc);
if (ret)
goto err_clk;
platform_set_drvdata(pdev, fimc);
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0)
goto err_sd;
fimc->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(fimc->alloc_ctx)) {
ret = PTR_ERR(fimc->alloc_ctx);
goto err_pm;
}
dev_dbg(&pdev->dev, "FIMC.%d registered successfully\n", fimc->id);
pm_runtime_put(&pdev->dev);
return 0;
err_pm:
pm_runtime_put(&pdev->dev);
err_sd:
fimc_unregister_capture_subdev(fimc);
err_clk:
fimc_clk_put(fimc);
return ret;
}
static int fimc_runtime_resume(struct device *dev)
{
struct fimc_dev *fimc = dev_get_drvdata(dev);
dbg("fimc%d: state: 0x%lx", fimc->id, fimc->state);
clk_enable(fimc->clock[CLK_GATE]);
fimc_hw_reset(fimc);
if (fimc_capture_busy(fimc))
return fimc_capture_resume(fimc);
return fimc_m2m_resume(fimc);
}
static int fimc_runtime_suspend(struct device *dev)
{
struct fimc_dev *fimc = dev_get_drvdata(dev);
int ret = 0;
if (fimc_capture_busy(fimc))
ret = fimc_capture_suspend(fimc);
else
ret = fimc_m2m_suspend(fimc);
if (!ret)
clk_disable(fimc->clock[CLK_GATE]);
dbg("fimc%d: state: 0x%lx", fimc->id, fimc->state);
return ret;
}
static int fimc_resume(struct device *dev)
{
struct fimc_dev *fimc = dev_get_drvdata(dev);
unsigned long flags;
dbg("fimc%d: state: 0x%lx", fimc->id, fimc->state);
spin_lock_irqsave(&fimc->slock, flags);
if (!test_and_clear_bit(ST_LPM, &fimc->state) ||
(!fimc_m2m_active(fimc) && !fimc_capture_busy(fimc))) {
spin_unlock_irqrestore(&fimc->slock, flags);
return 0;
}
fimc_hw_reset(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
if (fimc_capture_busy(fimc))
return fimc_capture_resume(fimc);
return fimc_m2m_resume(fimc);
}
static int fimc_suspend(struct device *dev)
{
struct fimc_dev *fimc = dev_get_drvdata(dev);
dbg("fimc%d: state: 0x%lx", fimc->id, fimc->state);
if (test_and_set_bit(ST_LPM, &fimc->state))
return 0;
if (fimc_capture_busy(fimc))
return fimc_capture_suspend(fimc);
return fimc_m2m_suspend(fimc);
}
static int __devexit fimc_remove(struct platform_device *pdev)
{
struct fimc_dev *fimc = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
fimc_unregister_capture_subdev(fimc);
vb2_dma_contig_cleanup_ctx(fimc->alloc_ctx);
clk_disable(fimc->clock[CLK_BUS]);
fimc_clk_put(fimc);
dev_info(&pdev->dev, "driver unloaded\n");
return 0;
}
int __init fimc_register_driver(void)
{
return platform_driver_register(&fimc_driver);
}
void __exit fimc_unregister_driver(void)
{
platform_driver_unregister(&fimc_driver);
}
