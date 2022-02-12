static u32 fimc_read(struct fimc_context *ctx, u32 reg)
{
return readl(ctx->regs + reg);
}
static void fimc_write(struct fimc_context *ctx, u32 val, u32 reg)
{
writel(val, ctx->regs + reg);
}
static void fimc_set_bits(struct fimc_context *ctx, u32 reg, u32 bits)
{
void __iomem *r = ctx->regs + reg;
writel(readl(r) | bits, r);
}
static void fimc_clear_bits(struct fimc_context *ctx, u32 reg, u32 bits)
{
void __iomem *r = ctx->regs + reg;
writel(readl(r) & ~bits, r);
}
static void fimc_sw_reset(struct fimc_context *ctx)
{
u32 cfg;
cfg = fimc_read(ctx, EXYNOS_CISTATUS);
if (EXYNOS_CISTATUS_GET_ENVID_STATUS(cfg))
fimc_clear_bits(ctx, EXYNOS_MSCTRL, EXYNOS_MSCTRL_ENVID);
fimc_set_bits(ctx, EXYNOS_CISRCFMT, EXYNOS_CISRCFMT_ITU601_8BIT);
fimc_clear_bits(ctx, EXYNOS_CIIMGCPT,
EXYNOS_CIIMGCPT_IMGCPTEN_SC | EXYNOS_CIIMGCPT_IMGCPTEN);
fimc_set_bits(ctx, EXYNOS_CIGCTRL, EXYNOS_CIGCTRL_SWRST);
fimc_clear_bits(ctx, EXYNOS_CIGCTRL, EXYNOS_CIGCTRL_SWRST);
fimc_write(ctx, 0x0, EXYNOS_CIFCNTSEQ);
}
static int fimc_set_camblk_fimd0_wb(struct fimc_context *ctx)
{
return regmap_update_bits(ctx->sysreg, SYSREG_CAMERA_BLK,
SYSREG_FIMD0WB_DEST_MASK,
ctx->id << SYSREG_FIMD0WB_DEST_SHIFT);
}
static void fimc_set_type_ctrl(struct fimc_context *ctx, enum fimc_wb wb)
{
u32 cfg;
DRM_DEBUG_KMS("wb[%d]\n", wb);
cfg = fimc_read(ctx, EXYNOS_CIGCTRL);
cfg &= ~(EXYNOS_CIGCTRL_TESTPATTERN_MASK |
EXYNOS_CIGCTRL_SELCAM_ITU_MASK |
EXYNOS_CIGCTRL_SELCAM_MIPI_MASK |
EXYNOS_CIGCTRL_SELCAM_FIMC_MASK |
EXYNOS_CIGCTRL_SELWB_CAMIF_MASK |
EXYNOS_CIGCTRL_SELWRITEBACK_MASK);
switch (wb) {
case FIMC_WB_A:
cfg |= (EXYNOS_CIGCTRL_SELWRITEBACK_A |
EXYNOS_CIGCTRL_SELWB_CAMIF_WRITEBACK);
break;
case FIMC_WB_B:
cfg |= (EXYNOS_CIGCTRL_SELWRITEBACK_B |
EXYNOS_CIGCTRL_SELWB_CAMIF_WRITEBACK);
break;
case FIMC_WB_NONE:
default:
cfg |= (EXYNOS_CIGCTRL_SELCAM_ITU_A |
EXYNOS_CIGCTRL_SELWRITEBACK_A |
EXYNOS_CIGCTRL_SELCAM_MIPI_A |
EXYNOS_CIGCTRL_SELCAM_FIMC_ITU);
break;
}
fimc_write(ctx, cfg, EXYNOS_CIGCTRL);
}
static void fimc_set_polarity(struct fimc_context *ctx,
struct exynos_drm_ipp_pol *pol)
{
u32 cfg;
DRM_DEBUG_KMS("inv_pclk[%d]inv_vsync[%d]\n",
pol->inv_pclk, pol->inv_vsync);
DRM_DEBUG_KMS("inv_href[%d]inv_hsync[%d]\n",
pol->inv_href, pol->inv_hsync);
cfg = fimc_read(ctx, EXYNOS_CIGCTRL);
cfg &= ~(EXYNOS_CIGCTRL_INVPOLPCLK | EXYNOS_CIGCTRL_INVPOLVSYNC |
EXYNOS_CIGCTRL_INVPOLHREF | EXYNOS_CIGCTRL_INVPOLHSYNC);
if (pol->inv_pclk)
cfg |= EXYNOS_CIGCTRL_INVPOLPCLK;
if (pol->inv_vsync)
cfg |= EXYNOS_CIGCTRL_INVPOLVSYNC;
if (pol->inv_href)
cfg |= EXYNOS_CIGCTRL_INVPOLHREF;
if (pol->inv_hsync)
cfg |= EXYNOS_CIGCTRL_INVPOLHSYNC;
fimc_write(ctx, cfg, EXYNOS_CIGCTRL);
}
static void fimc_handle_jpeg(struct fimc_context *ctx, bool enable)
{
u32 cfg;
DRM_DEBUG_KMS("enable[%d]\n", enable);
cfg = fimc_read(ctx, EXYNOS_CIGCTRL);
if (enable)
cfg |= EXYNOS_CIGCTRL_CAM_JPEG;
else
cfg &= ~EXYNOS_CIGCTRL_CAM_JPEG;
fimc_write(ctx, cfg, EXYNOS_CIGCTRL);
}
static void fimc_mask_irq(struct fimc_context *ctx, bool enable)
{
u32 cfg;
DRM_DEBUG_KMS("enable[%d]\n", enable);
cfg = fimc_read(ctx, EXYNOS_CIGCTRL);
if (enable) {
cfg &= ~EXYNOS_CIGCTRL_IRQ_OVFEN;
cfg |= EXYNOS_CIGCTRL_IRQ_ENABLE | EXYNOS_CIGCTRL_IRQ_LEVEL;
} else
cfg &= ~EXYNOS_CIGCTRL_IRQ_ENABLE;
fimc_write(ctx, cfg, EXYNOS_CIGCTRL);
}
static void fimc_clear_irq(struct fimc_context *ctx)
{
fimc_set_bits(ctx, EXYNOS_CIGCTRL, EXYNOS_CIGCTRL_IRQ_CLR);
}
static bool fimc_check_ovf(struct fimc_context *ctx)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 status, flag;
status = fimc_read(ctx, EXYNOS_CISTATUS);
flag = EXYNOS_CISTATUS_OVFIY | EXYNOS_CISTATUS_OVFICB |
EXYNOS_CISTATUS_OVFICR;
DRM_DEBUG_KMS("flag[0x%x]\n", flag);
if (status & flag) {
fimc_set_bits(ctx, EXYNOS_CIWDOFST,
EXYNOS_CIWDOFST_CLROVFIY | EXYNOS_CIWDOFST_CLROVFICB |
EXYNOS_CIWDOFST_CLROVFICR);
fimc_clear_bits(ctx, EXYNOS_CIWDOFST,
EXYNOS_CIWDOFST_CLROVFIY | EXYNOS_CIWDOFST_CLROVFICB |
EXYNOS_CIWDOFST_CLROVFICR);
dev_err(ippdrv->dev, "occurred overflow at %d, status 0x%x.\n",
ctx->id, status);
return true;
}
return false;
}
static bool fimc_check_frame_end(struct fimc_context *ctx)
{
u32 cfg;
cfg = fimc_read(ctx, EXYNOS_CISTATUS);
DRM_DEBUG_KMS("cfg[0x%x]\n", cfg);
if (!(cfg & EXYNOS_CISTATUS_FRAMEEND))
return false;
cfg &= ~(EXYNOS_CISTATUS_FRAMEEND);
fimc_write(ctx, cfg, EXYNOS_CISTATUS);
return true;
}
static int fimc_get_buf_id(struct fimc_context *ctx)
{
u32 cfg;
int frame_cnt, buf_id;
cfg = fimc_read(ctx, EXYNOS_CISTATUS2);
frame_cnt = EXYNOS_CISTATUS2_GET_FRAMECOUNT_BEFORE(cfg);
if (frame_cnt == 0)
frame_cnt = EXYNOS_CISTATUS2_GET_FRAMECOUNT_PRESENT(cfg);
DRM_DEBUG_KMS("present[%d]before[%d]\n",
EXYNOS_CISTATUS2_GET_FRAMECOUNT_PRESENT(cfg),
EXYNOS_CISTATUS2_GET_FRAMECOUNT_BEFORE(cfg));
if (frame_cnt == 0) {
DRM_ERROR("failed to get frame count.\n");
return -EIO;
}
buf_id = frame_cnt - 1;
DRM_DEBUG_KMS("buf_id[%d]\n", buf_id);
return buf_id;
}
static void fimc_handle_lastend(struct fimc_context *ctx, bool enable)
{
u32 cfg;
DRM_DEBUG_KMS("enable[%d]\n", enable);
cfg = fimc_read(ctx, EXYNOS_CIOCTRL);
if (enable)
cfg |= EXYNOS_CIOCTRL_LASTENDEN;
else
cfg &= ~EXYNOS_CIOCTRL_LASTENDEN;
fimc_write(ctx, cfg, EXYNOS_CIOCTRL);
}
static int fimc_src_set_fmt_order(struct fimc_context *ctx, u32 fmt)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = fimc_read(ctx, EXYNOS_CISCCTRL);
cfg &= ~EXYNOS_CISCCTRL_INRGB_FMT_RGB_MASK;
switch (fmt) {
case DRM_FORMAT_RGB565:
cfg |= EXYNOS_CISCCTRL_INRGB_FMT_RGB565;
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
return 0;
case DRM_FORMAT_RGB888:
case DRM_FORMAT_XRGB8888:
cfg |= EXYNOS_CISCCTRL_INRGB_FMT_RGB888;
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
return 0;
default:
break;
}
cfg = fimc_read(ctx, EXYNOS_MSCTRL);
cfg &= ~(EXYNOS_MSCTRL_ORDER2P_SHIFT_MASK |
EXYNOS_MSCTRL_C_INT_IN_2PLANE |
EXYNOS_MSCTRL_ORDER422_YCBYCR);
switch (fmt) {
case DRM_FORMAT_YUYV:
cfg |= EXYNOS_MSCTRL_ORDER422_YCBYCR;
break;
case DRM_FORMAT_YVYU:
cfg |= EXYNOS_MSCTRL_ORDER422_YCRYCB;
break;
case DRM_FORMAT_UYVY:
cfg |= EXYNOS_MSCTRL_ORDER422_CBYCRY;
break;
case DRM_FORMAT_VYUY:
case DRM_FORMAT_YUV444:
cfg |= EXYNOS_MSCTRL_ORDER422_CRYCBY;
break;
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV61:
cfg |= (EXYNOS_MSCTRL_ORDER2P_LSB_CRCB |
EXYNOS_MSCTRL_C_INT_IN_2PLANE);
break;
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
cfg |= EXYNOS_MSCTRL_C_INT_IN_3PLANE;
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV12MT:
case DRM_FORMAT_NV16:
cfg |= (EXYNOS_MSCTRL_ORDER2P_LSB_CBCR |
EXYNOS_MSCTRL_C_INT_IN_2PLANE);
break;
default:
dev_err(ippdrv->dev, "inavlid source yuv order 0x%x.\n", fmt);
return -EINVAL;
}
fimc_write(ctx, cfg, EXYNOS_MSCTRL);
return 0;
}
static int fimc_src_set_fmt(struct device *dev, u32 fmt)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = fimc_read(ctx, EXYNOS_MSCTRL);
cfg &= ~EXYNOS_MSCTRL_INFORMAT_RGB;
switch (fmt) {
case DRM_FORMAT_RGB565:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_XRGB8888:
cfg |= EXYNOS_MSCTRL_INFORMAT_RGB;
break;
case DRM_FORMAT_YUV444:
cfg |= EXYNOS_MSCTRL_INFORMAT_YCBCR420;
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
cfg |= EXYNOS_MSCTRL_INFORMAT_YCBCR422_1PLANE;
break;
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_YUV422:
cfg |= EXYNOS_MSCTRL_INFORMAT_YCBCR422;
break;
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV12MT:
cfg |= EXYNOS_MSCTRL_INFORMAT_YCBCR420;
break;
default:
dev_err(ippdrv->dev, "inavlid source format 0x%x.\n", fmt);
return -EINVAL;
}
fimc_write(ctx, cfg, EXYNOS_MSCTRL);
cfg = fimc_read(ctx, EXYNOS_CIDMAPARAM);
cfg &= ~EXYNOS_CIDMAPARAM_R_MODE_MASK;
if (fmt == DRM_FORMAT_NV12MT)
cfg |= EXYNOS_CIDMAPARAM_R_MODE_64X32;
else
cfg |= EXYNOS_CIDMAPARAM_R_MODE_LINEAR;
fimc_write(ctx, cfg, EXYNOS_CIDMAPARAM);
return fimc_src_set_fmt_order(ctx, fmt);
}
static int fimc_src_set_transf(struct device *dev,
enum drm_exynos_degree degree,
enum drm_exynos_flip flip, bool *swap)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg1, cfg2;
DRM_DEBUG_KMS("degree[%d]flip[0x%x]\n", degree, flip);
cfg1 = fimc_read(ctx, EXYNOS_MSCTRL);
cfg1 &= ~(EXYNOS_MSCTRL_FLIP_X_MIRROR |
EXYNOS_MSCTRL_FLIP_Y_MIRROR);
cfg2 = fimc_read(ctx, EXYNOS_CITRGFMT);
cfg2 &= ~EXYNOS_CITRGFMT_INROT90_CLOCKWISE;
switch (degree) {
case EXYNOS_DRM_DEGREE_0:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg1 |= EXYNOS_MSCTRL_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg1 |= EXYNOS_MSCTRL_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_90:
cfg2 |= EXYNOS_CITRGFMT_INROT90_CLOCKWISE;
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg1 |= EXYNOS_MSCTRL_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg1 |= EXYNOS_MSCTRL_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_180:
cfg1 |= (EXYNOS_MSCTRL_FLIP_X_MIRROR |
EXYNOS_MSCTRL_FLIP_Y_MIRROR);
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg1 &= ~EXYNOS_MSCTRL_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg1 &= ~EXYNOS_MSCTRL_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_270:
cfg1 |= (EXYNOS_MSCTRL_FLIP_X_MIRROR |
EXYNOS_MSCTRL_FLIP_Y_MIRROR);
cfg2 |= EXYNOS_CITRGFMT_INROT90_CLOCKWISE;
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg1 &= ~EXYNOS_MSCTRL_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg1 &= ~EXYNOS_MSCTRL_FLIP_Y_MIRROR;
break;
default:
dev_err(ippdrv->dev, "inavlid degree value %d.\n", degree);
return -EINVAL;
}
fimc_write(ctx, cfg1, EXYNOS_MSCTRL);
fimc_write(ctx, cfg2, EXYNOS_CITRGFMT);
*swap = (cfg2 & EXYNOS_CITRGFMT_INROT90_CLOCKWISE) ? 1 : 0;
return 0;
}
static int fimc_set_window(struct fimc_context *ctx,
struct drm_exynos_pos *pos, struct drm_exynos_sz *sz)
{
u32 cfg, h1, h2, v1, v2;
h1 = pos->x;
h2 = sz->hsize - pos->w - pos->x;
v1 = pos->y;
v2 = sz->vsize - pos->h - pos->y;
DRM_DEBUG_KMS("x[%d]y[%d]w[%d]h[%d]hsize[%d]vsize[%d]\n",
pos->x, pos->y, pos->w, pos->h, sz->hsize, sz->vsize);
DRM_DEBUG_KMS("h1[%d]h2[%d]v1[%d]v2[%d]\n", h1, h2, v1, v2);
cfg = fimc_read(ctx, EXYNOS_CIWDOFST);
cfg &= ~(EXYNOS_CIWDOFST_WINHOROFST_MASK |
EXYNOS_CIWDOFST_WINVEROFST_MASK);
cfg |= (EXYNOS_CIWDOFST_WINHOROFST(h1) |
EXYNOS_CIWDOFST_WINVEROFST(v1));
cfg |= EXYNOS_CIWDOFST_WINOFSEN;
fimc_write(ctx, cfg, EXYNOS_CIWDOFST);
cfg = (EXYNOS_CIWDOFST2_WINHOROFST2(h2) |
EXYNOS_CIWDOFST2_WINVEROFST2(v2));
fimc_write(ctx, cfg, EXYNOS_CIWDOFST2);
return 0;
}
static int fimc_src_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos, struct drm_exynos_sz *sz)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct drm_exynos_pos img_pos = *pos;
struct drm_exynos_sz img_sz = *sz;
u32 cfg;
DRM_DEBUG_KMS("swap[%d]hsize[%d]vsize[%d]\n",
swap, sz->hsize, sz->vsize);
cfg = (EXYNOS_ORGISIZE_HORIZONTAL(img_sz.hsize) |
EXYNOS_ORGISIZE_VERTICAL(img_sz.vsize));
fimc_write(ctx, cfg, EXYNOS_ORGISIZE);
DRM_DEBUG_KMS("x[%d]y[%d]w[%d]h[%d]\n", pos->x, pos->y, pos->w, pos->h);
if (swap) {
img_pos.w = pos->h;
img_pos.h = pos->w;
img_sz.hsize = sz->vsize;
img_sz.vsize = sz->hsize;
}
cfg = fimc_read(ctx, EXYNOS_CIREAL_ISIZE);
cfg &= ~(EXYNOS_CIREAL_ISIZE_HEIGHT_MASK |
EXYNOS_CIREAL_ISIZE_WIDTH_MASK);
cfg |= (EXYNOS_CIREAL_ISIZE_WIDTH(img_pos.w) |
EXYNOS_CIREAL_ISIZE_HEIGHT(img_pos.h));
fimc_write(ctx, cfg, EXYNOS_CIREAL_ISIZE);
cfg = (EXYNOS_CISRCFMT_ITU601_8BIT |
EXYNOS_CISRCFMT_SOURCEHSIZE(img_sz.hsize) |
EXYNOS_CISRCFMT_SOURCEVSIZE(img_sz.vsize));
fimc_write(ctx, cfg, EXYNOS_CISRCFMT);
cfg = (EXYNOS_CIIYOFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIIYOFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIIYOFF);
cfg = (EXYNOS_CIICBOFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIICBOFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIICBOFF);
cfg = (EXYNOS_CIICROFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIICROFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIICROFF);
return fimc_set_window(ctx, &img_pos, &img_sz);
}
static int fimc_src_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
struct drm_exynos_ipp_config *config;
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EINVAL;
}
property = &c_node->property;
DRM_DEBUG_KMS("prop_id[%d]buf_id[%d]buf_type[%d]\n",
property->prop_id, buf_id, buf_type);
if (buf_id > FIMC_MAX_SRC) {
dev_info(ippdrv->dev, "inavlid buf_id %d.\n", buf_id);
return -ENOMEM;
}
switch (buf_type) {
case IPP_BUF_ENQUEUE:
config = &property->config[EXYNOS_DRM_OPS_SRC];
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_Y],
EXYNOS_CIIYSA(buf_id));
if (config->fmt == DRM_FORMAT_YVU420) {
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CR],
EXYNOS_CIICBSA(buf_id));
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CB],
EXYNOS_CIICRSA(buf_id));
} else {
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CB],
EXYNOS_CIICBSA(buf_id));
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CR],
EXYNOS_CIICRSA(buf_id));
}
break;
case IPP_BUF_DEQUEUE:
fimc_write(ctx, 0x0, EXYNOS_CIIYSA(buf_id));
fimc_write(ctx, 0x0, EXYNOS_CIICBSA(buf_id));
fimc_write(ctx, 0x0, EXYNOS_CIICRSA(buf_id));
break;
default:
break;
}
return 0;
}
static int fimc_dst_set_fmt_order(struct fimc_context *ctx, u32 fmt)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = fimc_read(ctx, EXYNOS_CISCCTRL);
cfg &= ~EXYNOS_CISCCTRL_OUTRGB_FMT_RGB_MASK;
switch (fmt) {
case DRM_FORMAT_RGB565:
cfg |= EXYNOS_CISCCTRL_OUTRGB_FMT_RGB565;
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
return 0;
case DRM_FORMAT_RGB888:
cfg |= EXYNOS_CISCCTRL_OUTRGB_FMT_RGB888;
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
return 0;
case DRM_FORMAT_XRGB8888:
cfg |= (EXYNOS_CISCCTRL_OUTRGB_FMT_RGB888 |
EXYNOS_CISCCTRL_EXTRGB_EXTENSION);
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
break;
default:
break;
}
cfg = fimc_read(ctx, EXYNOS_CIOCTRL);
cfg &= ~(EXYNOS_CIOCTRL_ORDER2P_MASK |
EXYNOS_CIOCTRL_ORDER422_MASK |
EXYNOS_CIOCTRL_YCBCR_PLANE_MASK);
switch (fmt) {
case DRM_FORMAT_XRGB8888:
cfg |= EXYNOS_CIOCTRL_ALPHA_OUT;
break;
case DRM_FORMAT_YUYV:
cfg |= EXYNOS_CIOCTRL_ORDER422_YCBYCR;
break;
case DRM_FORMAT_YVYU:
cfg |= EXYNOS_CIOCTRL_ORDER422_YCRYCB;
break;
case DRM_FORMAT_UYVY:
cfg |= EXYNOS_CIOCTRL_ORDER422_CBYCRY;
break;
case DRM_FORMAT_VYUY:
cfg |= EXYNOS_CIOCTRL_ORDER422_CRYCBY;
break;
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV61:
cfg |= EXYNOS_CIOCTRL_ORDER2P_LSB_CRCB;
cfg |= EXYNOS_CIOCTRL_YCBCR_2PLANE;
break;
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
cfg |= EXYNOS_CIOCTRL_YCBCR_3PLANE;
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV12MT:
case DRM_FORMAT_NV16:
cfg |= EXYNOS_CIOCTRL_ORDER2P_LSB_CBCR;
cfg |= EXYNOS_CIOCTRL_YCBCR_2PLANE;
break;
default:
dev_err(ippdrv->dev, "inavlid target yuv order 0x%x.\n", fmt);
return -EINVAL;
}
fimc_write(ctx, cfg, EXYNOS_CIOCTRL);
return 0;
}
static int fimc_dst_set_fmt(struct device *dev, u32 fmt)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = fimc_read(ctx, EXYNOS_CIEXTEN);
if (fmt == DRM_FORMAT_AYUV) {
cfg |= EXYNOS_CIEXTEN_YUV444_OUT;
fimc_write(ctx, cfg, EXYNOS_CIEXTEN);
} else {
cfg &= ~EXYNOS_CIEXTEN_YUV444_OUT;
fimc_write(ctx, cfg, EXYNOS_CIEXTEN);
cfg = fimc_read(ctx, EXYNOS_CITRGFMT);
cfg &= ~EXYNOS_CITRGFMT_OUTFORMAT_MASK;
switch (fmt) {
case DRM_FORMAT_RGB565:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_XRGB8888:
cfg |= EXYNOS_CITRGFMT_OUTFORMAT_RGB;
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
cfg |= EXYNOS_CITRGFMT_OUTFORMAT_YCBCR422_1PLANE;
break;
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_YUV422:
cfg |= EXYNOS_CITRGFMT_OUTFORMAT_YCBCR422;
break;
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV12MT:
case DRM_FORMAT_NV21:
cfg |= EXYNOS_CITRGFMT_OUTFORMAT_YCBCR420;
break;
default:
dev_err(ippdrv->dev, "inavlid target format 0x%x.\n",
fmt);
return -EINVAL;
}
fimc_write(ctx, cfg, EXYNOS_CITRGFMT);
}
cfg = fimc_read(ctx, EXYNOS_CIDMAPARAM);
cfg &= ~EXYNOS_CIDMAPARAM_W_MODE_MASK;
if (fmt == DRM_FORMAT_NV12MT)
cfg |= EXYNOS_CIDMAPARAM_W_MODE_64X32;
else
cfg |= EXYNOS_CIDMAPARAM_W_MODE_LINEAR;
fimc_write(ctx, cfg, EXYNOS_CIDMAPARAM);
return fimc_dst_set_fmt_order(ctx, fmt);
}
static int fimc_dst_set_transf(struct device *dev,
enum drm_exynos_degree degree,
enum drm_exynos_flip flip, bool *swap)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("degree[%d]flip[0x%x]\n", degree, flip);
cfg = fimc_read(ctx, EXYNOS_CITRGFMT);
cfg &= ~EXYNOS_CITRGFMT_FLIP_MASK;
cfg &= ~EXYNOS_CITRGFMT_OUTROT90_CLOCKWISE;
switch (degree) {
case EXYNOS_DRM_DEGREE_0:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= EXYNOS_CITRGFMT_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= EXYNOS_CITRGFMT_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_90:
cfg |= EXYNOS_CITRGFMT_OUTROT90_CLOCKWISE;
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= EXYNOS_CITRGFMT_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= EXYNOS_CITRGFMT_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_180:
cfg |= (EXYNOS_CITRGFMT_FLIP_X_MIRROR |
EXYNOS_CITRGFMT_FLIP_Y_MIRROR);
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg &= ~EXYNOS_CITRGFMT_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg &= ~EXYNOS_CITRGFMT_FLIP_Y_MIRROR;
break;
case EXYNOS_DRM_DEGREE_270:
cfg |= (EXYNOS_CITRGFMT_OUTROT90_CLOCKWISE |
EXYNOS_CITRGFMT_FLIP_X_MIRROR |
EXYNOS_CITRGFMT_FLIP_Y_MIRROR);
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg &= ~EXYNOS_CITRGFMT_FLIP_X_MIRROR;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg &= ~EXYNOS_CITRGFMT_FLIP_Y_MIRROR;
break;
default:
dev_err(ippdrv->dev, "inavlid degree value %d.\n", degree);
return -EINVAL;
}
fimc_write(ctx, cfg, EXYNOS_CITRGFMT);
*swap = (cfg & EXYNOS_CITRGFMT_OUTROT90_CLOCKWISE) ? 1 : 0;
return 0;
}
static int fimc_set_prescaler(struct fimc_context *ctx, struct fimc_scaler *sc,
struct drm_exynos_pos *src, struct drm_exynos_pos *dst)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg, cfg_ext, shfactor;
u32 pre_dst_width, pre_dst_height;
u32 hfactor, vfactor;
int ret = 0;
u32 src_w, src_h, dst_w, dst_h;
cfg_ext = fimc_read(ctx, EXYNOS_CITRGFMT);
if (cfg_ext & EXYNOS_CITRGFMT_INROT90_CLOCKWISE) {
src_w = src->h;
src_h = src->w;
} else {
src_w = src->w;
src_h = src->h;
}
if (cfg_ext & EXYNOS_CITRGFMT_OUTROT90_CLOCKWISE) {
dst_w = dst->h;
dst_h = dst->w;
} else {
dst_w = dst->w;
dst_h = dst->h;
}
hfactor = fls(src_w / dst_w / 2);
if (hfactor > FIMC_SHFACTOR / 2) {
dev_err(ippdrv->dev, "failed to get ratio horizontal.\n");
return -EINVAL;
}
vfactor = fls(src_h / dst_h / 2);
if (vfactor > FIMC_SHFACTOR / 2) {
dev_err(ippdrv->dev, "failed to get ratio vertical.\n");
return -EINVAL;
}
pre_dst_width = src_w >> hfactor;
pre_dst_height = src_h >> vfactor;
DRM_DEBUG_KMS("pre_dst_width[%d]pre_dst_height[%d]\n",
pre_dst_width, pre_dst_height);
DRM_DEBUG_KMS("hfactor[%d]vfactor[%d]\n", hfactor, vfactor);
sc->hratio = (src_w << 14) / (dst_w << hfactor);
sc->vratio = (src_h << 14) / (dst_h << vfactor);
sc->up_h = (dst_w >= src_w) ? true : false;
sc->up_v = (dst_h >= src_h) ? true : false;
DRM_DEBUG_KMS("hratio[%d]vratio[%d]up_h[%d]up_v[%d]\n",
sc->hratio, sc->vratio, sc->up_h, sc->up_v);
shfactor = FIMC_SHFACTOR - (hfactor + vfactor);
DRM_DEBUG_KMS("shfactor[%d]\n", shfactor);
cfg = (EXYNOS_CISCPRERATIO_SHFACTOR(shfactor) |
EXYNOS_CISCPRERATIO_PREHORRATIO(1 << hfactor) |
EXYNOS_CISCPRERATIO_PREVERRATIO(1 << vfactor));
fimc_write(ctx, cfg, EXYNOS_CISCPRERATIO);
cfg = (EXYNOS_CISCPREDST_PREDSTWIDTH(pre_dst_width) |
EXYNOS_CISCPREDST_PREDSTHEIGHT(pre_dst_height));
fimc_write(ctx, cfg, EXYNOS_CISCPREDST);
return ret;
}
static void fimc_set_scaler(struct fimc_context *ctx, struct fimc_scaler *sc)
{
u32 cfg, cfg_ext;
DRM_DEBUG_KMS("range[%d]bypass[%d]up_h[%d]up_v[%d]\n",
sc->range, sc->bypass, sc->up_h, sc->up_v);
DRM_DEBUG_KMS("hratio[%d]vratio[%d]\n",
sc->hratio, sc->vratio);
cfg = fimc_read(ctx, EXYNOS_CISCCTRL);
cfg &= ~(EXYNOS_CISCCTRL_SCALERBYPASS |
EXYNOS_CISCCTRL_SCALEUP_H | EXYNOS_CISCCTRL_SCALEUP_V |
EXYNOS_CISCCTRL_MAIN_V_RATIO_MASK |
EXYNOS_CISCCTRL_MAIN_H_RATIO_MASK |
EXYNOS_CISCCTRL_CSCR2Y_WIDE |
EXYNOS_CISCCTRL_CSCY2R_WIDE);
if (sc->range)
cfg |= (EXYNOS_CISCCTRL_CSCR2Y_WIDE |
EXYNOS_CISCCTRL_CSCY2R_WIDE);
if (sc->bypass)
cfg |= EXYNOS_CISCCTRL_SCALERBYPASS;
if (sc->up_h)
cfg |= EXYNOS_CISCCTRL_SCALEUP_H;
if (sc->up_v)
cfg |= EXYNOS_CISCCTRL_SCALEUP_V;
cfg |= (EXYNOS_CISCCTRL_MAINHORRATIO((sc->hratio >> 6)) |
EXYNOS_CISCCTRL_MAINVERRATIO((sc->vratio >> 6)));
fimc_write(ctx, cfg, EXYNOS_CISCCTRL);
cfg_ext = fimc_read(ctx, EXYNOS_CIEXTEN);
cfg_ext &= ~EXYNOS_CIEXTEN_MAINHORRATIO_EXT_MASK;
cfg_ext &= ~EXYNOS_CIEXTEN_MAINVERRATIO_EXT_MASK;
cfg_ext |= (EXYNOS_CIEXTEN_MAINHORRATIO_EXT(sc->hratio) |
EXYNOS_CIEXTEN_MAINVERRATIO_EXT(sc->vratio));
fimc_write(ctx, cfg_ext, EXYNOS_CIEXTEN);
}
static int fimc_dst_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos, struct drm_exynos_sz *sz)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct drm_exynos_pos img_pos = *pos;
struct drm_exynos_sz img_sz = *sz;
u32 cfg;
DRM_DEBUG_KMS("swap[%d]hsize[%d]vsize[%d]\n",
swap, sz->hsize, sz->vsize);
cfg = (EXYNOS_ORGOSIZE_HORIZONTAL(img_sz.hsize) |
EXYNOS_ORGOSIZE_VERTICAL(img_sz.vsize));
fimc_write(ctx, cfg, EXYNOS_ORGOSIZE);
DRM_DEBUG_KMS("x[%d]y[%d]w[%d]h[%d]\n", pos->x, pos->y, pos->w, pos->h);
cfg = fimc_read(ctx, EXYNOS_CIGCTRL);
cfg &= ~EXYNOS_CIGCTRL_CSC_MASK;
if (sz->hsize >= FIMC_WIDTH_ITU_709)
cfg |= EXYNOS_CIGCTRL_CSC_ITU709;
else
cfg |= EXYNOS_CIGCTRL_CSC_ITU601;
fimc_write(ctx, cfg, EXYNOS_CIGCTRL);
if (swap) {
img_pos.w = pos->h;
img_pos.h = pos->w;
img_sz.hsize = sz->vsize;
img_sz.vsize = sz->hsize;
}
cfg = fimc_read(ctx, EXYNOS_CITRGFMT);
cfg &= ~(EXYNOS_CITRGFMT_TARGETH_MASK |
EXYNOS_CITRGFMT_TARGETV_MASK);
cfg |= (EXYNOS_CITRGFMT_TARGETHSIZE(img_pos.w) |
EXYNOS_CITRGFMT_TARGETVSIZE(img_pos.h));
fimc_write(ctx, cfg, EXYNOS_CITRGFMT);
cfg = EXYNOS_CITAREA_TARGET_AREA(img_pos.w * img_pos.h);
fimc_write(ctx, cfg, EXYNOS_CITAREA);
cfg = (EXYNOS_CIOYOFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIOYOFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIOYOFF);
cfg = (EXYNOS_CIOCBOFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIOCBOFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIOCBOFF);
cfg = (EXYNOS_CIOCROFF_HORIZONTAL(img_pos.x) |
EXYNOS_CIOCROFF_VERTICAL(img_pos.y));
fimc_write(ctx, cfg, EXYNOS_CIOCROFF);
return 0;
}
static int fimc_dst_get_buf_count(struct fimc_context *ctx)
{
u32 cfg, buf_num;
cfg = fimc_read(ctx, EXYNOS_CIFCNTSEQ);
buf_num = hweight32(cfg);
DRM_DEBUG_KMS("buf_num[%d]\n", buf_num);
return buf_num;
}
static int fimc_dst_set_buf_seq(struct fimc_context *ctx, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
bool enable;
u32 cfg;
u32 mask = 0x00000001 << buf_id;
int ret = 0;
unsigned long flags;
DRM_DEBUG_KMS("buf_id[%d]buf_type[%d]\n", buf_id, buf_type);
spin_lock_irqsave(&ctx->lock, flags);
cfg = fimc_read(ctx, EXYNOS_CIFCNTSEQ);
switch (buf_type) {
case IPP_BUF_ENQUEUE:
enable = true;
break;
case IPP_BUF_DEQUEUE:
enable = false;
break;
default:
dev_err(ippdrv->dev, "invalid buf ctrl parameter.\n");
ret = -EINVAL;
goto err_unlock;
}
cfg &= ~mask;
cfg |= (enable << buf_id);
fimc_write(ctx, cfg, EXYNOS_CIFCNTSEQ);
if (buf_type == IPP_BUF_ENQUEUE &&
fimc_dst_get_buf_count(ctx) >= FIMC_BUF_START)
fimc_mask_irq(ctx, true);
if (buf_type == IPP_BUF_DEQUEUE &&
fimc_dst_get_buf_count(ctx) <= FIMC_BUF_STOP)
fimc_mask_irq(ctx, false);
err_unlock:
spin_unlock_irqrestore(&ctx->lock, flags);
return ret;
}
static int fimc_dst_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
struct drm_exynos_ipp_config *config;
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EINVAL;
}
property = &c_node->property;
DRM_DEBUG_KMS("prop_id[%d]buf_id[%d]buf_type[%d]\n",
property->prop_id, buf_id, buf_type);
if (buf_id > FIMC_MAX_DST) {
dev_info(ippdrv->dev, "inavlid buf_id %d.\n", buf_id);
return -ENOMEM;
}
switch (buf_type) {
case IPP_BUF_ENQUEUE:
config = &property->config[EXYNOS_DRM_OPS_DST];
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_Y],
EXYNOS_CIOYSA(buf_id));
if (config->fmt == DRM_FORMAT_YVU420) {
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CR],
EXYNOS_CIOCBSA(buf_id));
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CB],
EXYNOS_CIOCRSA(buf_id));
} else {
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CB],
EXYNOS_CIOCBSA(buf_id));
fimc_write(ctx, buf_info->base[EXYNOS_DRM_PLANAR_CR],
EXYNOS_CIOCRSA(buf_id));
}
break;
case IPP_BUF_DEQUEUE:
fimc_write(ctx, 0x0, EXYNOS_CIOYSA(buf_id));
fimc_write(ctx, 0x0, EXYNOS_CIOCBSA(buf_id));
fimc_write(ctx, 0x0, EXYNOS_CIOCRSA(buf_id));
break;
default:
break;
}
return fimc_dst_set_buf_seq(ctx, buf_id, buf_type);
}
static int fimc_clk_ctrl(struct fimc_context *ctx, bool enable)
{
DRM_DEBUG_KMS("enable[%d]\n", enable);
if (enable) {
clk_prepare_enable(ctx->clocks[FIMC_CLK_GATE]);
clk_prepare_enable(ctx->clocks[FIMC_CLK_WB_A]);
ctx->suspended = false;
} else {
clk_disable_unprepare(ctx->clocks[FIMC_CLK_GATE]);
clk_disable_unprepare(ctx->clocks[FIMC_CLK_WB_A]);
ctx->suspended = true;
}
return 0;
}
static irqreturn_t fimc_irq_handler(int irq, void *dev_id)
{
struct fimc_context *ctx = dev_id;
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_event_work *event_work =
c_node->event_work;
int buf_id;
DRM_DEBUG_KMS("fimc id[%d]\n", ctx->id);
fimc_clear_irq(ctx);
if (fimc_check_ovf(ctx))
return IRQ_NONE;
if (!fimc_check_frame_end(ctx))
return IRQ_NONE;
buf_id = fimc_get_buf_id(ctx);
if (buf_id < 0)
return IRQ_HANDLED;
DRM_DEBUG_KMS("buf_id[%d]\n", buf_id);
if (fimc_dst_set_buf_seq(ctx, buf_id, IPP_BUF_DEQUEUE) < 0) {
DRM_ERROR("failed to dequeue.\n");
return IRQ_HANDLED;
}
event_work->ippdrv = ippdrv;
event_work->buf_id[EXYNOS_DRM_OPS_DST] = buf_id;
queue_work(ippdrv->event_workq, (struct work_struct *)event_work);
return IRQ_HANDLED;
}
static int fimc_init_prop_list(struct exynos_drm_ippdrv *ippdrv)
{
struct drm_exynos_ipp_prop_list *prop_list = &ippdrv->prop_list;
prop_list->version = 1;
prop_list->writeback = 1;
prop_list->refresh_min = FIMC_REFRESH_MIN;
prop_list->refresh_max = FIMC_REFRESH_MAX;
prop_list->flip = (1 << EXYNOS_DRM_FLIP_NONE) |
(1 << EXYNOS_DRM_FLIP_VERTICAL) |
(1 << EXYNOS_DRM_FLIP_HORIZONTAL);
prop_list->degree = (1 << EXYNOS_DRM_DEGREE_0) |
(1 << EXYNOS_DRM_DEGREE_90) |
(1 << EXYNOS_DRM_DEGREE_180) |
(1 << EXYNOS_DRM_DEGREE_270);
prop_list->csc = 1;
prop_list->crop = 1;
prop_list->crop_max.hsize = FIMC_CROP_MAX;
prop_list->crop_max.vsize = FIMC_CROP_MAX;
prop_list->crop_min.hsize = FIMC_CROP_MIN;
prop_list->crop_min.vsize = FIMC_CROP_MIN;
prop_list->scale = 1;
prop_list->scale_max.hsize = FIMC_SCALE_MAX;
prop_list->scale_max.vsize = FIMC_SCALE_MAX;
prop_list->scale_min.hsize = FIMC_SCALE_MIN;
prop_list->scale_min.vsize = FIMC_SCALE_MIN;
return 0;
}
static inline bool fimc_check_drm_flip(enum drm_exynos_flip flip)
{
switch (flip) {
case EXYNOS_DRM_FLIP_NONE:
case EXYNOS_DRM_FLIP_VERTICAL:
case EXYNOS_DRM_FLIP_HORIZONTAL:
case EXYNOS_DRM_FLIP_BOTH:
return true;
default:
DRM_DEBUG_KMS("invalid flip\n");
return false;
}
}
static int fimc_ippdrv_check_property(struct device *dev,
struct drm_exynos_ipp_property *property)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_prop_list *pp = &ippdrv->prop_list;
struct drm_exynos_ipp_config *config;
struct drm_exynos_pos *pos;
struct drm_exynos_sz *sz;
bool swap;
int i;
for_each_ipp_ops(i) {
if ((i == EXYNOS_DRM_OPS_SRC) &&
(property->cmd == IPP_CMD_WB))
continue;
config = &property->config[i];
pos = &config->pos;
sz = &config->sz;
if (!fimc_check_drm_flip(config->flip)) {
DRM_ERROR("invalid flip.\n");
goto err_property;
}
switch (config->degree) {
case EXYNOS_DRM_DEGREE_90:
case EXYNOS_DRM_DEGREE_270:
swap = true;
break;
case EXYNOS_DRM_DEGREE_0:
case EXYNOS_DRM_DEGREE_180:
swap = false;
break;
default:
DRM_ERROR("invalid degree.\n");
goto err_property;
}
if ((pos->x + pos->w > sz->hsize) ||
(pos->y + pos->h > sz->vsize)) {
DRM_ERROR("out of buf bound.\n");
goto err_property;
}
if ((i == EXYNOS_DRM_OPS_SRC) && (pp->crop)) {
if (swap) {
if ((pos->h < pp->crop_min.hsize) ||
(sz->vsize > pp->crop_max.hsize) ||
(pos->w < pp->crop_min.vsize) ||
(sz->hsize > pp->crop_max.vsize)) {
DRM_ERROR("out of crop size.\n");
goto err_property;
}
} else {
if ((pos->w < pp->crop_min.hsize) ||
(sz->hsize > pp->crop_max.hsize) ||
(pos->h < pp->crop_min.vsize) ||
(sz->vsize > pp->crop_max.vsize)) {
DRM_ERROR("out of crop size.\n");
goto err_property;
}
}
}
if ((i == EXYNOS_DRM_OPS_DST) && (pp->scale)) {
if (swap) {
if ((pos->h < pp->scale_min.hsize) ||
(sz->vsize > pp->scale_max.hsize) ||
(pos->w < pp->scale_min.vsize) ||
(sz->hsize > pp->scale_max.vsize)) {
DRM_ERROR("out of scale size.\n");
goto err_property;
}
} else {
if ((pos->w < pp->scale_min.hsize) ||
(sz->hsize > pp->scale_max.hsize) ||
(pos->h < pp->scale_min.vsize) ||
(sz->vsize > pp->scale_max.vsize)) {
DRM_ERROR("out of scale size.\n");
goto err_property;
}
}
}
}
return 0;
err_property:
for_each_ipp_ops(i) {
if ((i == EXYNOS_DRM_OPS_SRC) &&
(property->cmd == IPP_CMD_WB))
continue;
config = &property->config[i];
pos = &config->pos;
sz = &config->sz;
DRM_ERROR("[%s]f[%d]r[%d]pos[%d %d %d %d]sz[%d %d]\n",
i ? "dst" : "src", config->flip, config->degree,
pos->x, pos->y, pos->w, pos->h,
sz->hsize, sz->vsize);
}
return -EINVAL;
}
static void fimc_clear_addr(struct fimc_context *ctx)
{
int i;
for (i = 0; i < FIMC_MAX_SRC; i++) {
fimc_write(ctx, 0, EXYNOS_CIIYSA(i));
fimc_write(ctx, 0, EXYNOS_CIICBSA(i));
fimc_write(ctx, 0, EXYNOS_CIICRSA(i));
}
for (i = 0; i < FIMC_MAX_DST; i++) {
fimc_write(ctx, 0, EXYNOS_CIOYSA(i));
fimc_write(ctx, 0, EXYNOS_CIOCBSA(i));
fimc_write(ctx, 0, EXYNOS_CIOCRSA(i));
}
}
static int fimc_ippdrv_reset(struct device *dev)
{
struct fimc_context *ctx = get_fimc_context(dev);
fimc_sw_reset(ctx);
memset(&ctx->sc, 0x0, sizeof(ctx->sc));
fimc_clear_addr(ctx);
return 0;
}
static int fimc_ippdrv_start(struct device *dev, enum drm_exynos_ipp_cmd cmd)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
struct drm_exynos_ipp_config *config;
struct drm_exynos_pos img_pos[EXYNOS_DRM_OPS_MAX];
struct drm_exynos_ipp_set_wb set_wb;
int ret, i;
u32 cfg0, cfg1;
DRM_DEBUG_KMS("cmd[%d]\n", cmd);
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EINVAL;
}
property = &c_node->property;
fimc_mask_irq(ctx, true);
for_each_ipp_ops(i) {
config = &property->config[i];
img_pos[i] = config->pos;
}
ret = fimc_set_prescaler(ctx, &ctx->sc,
&img_pos[EXYNOS_DRM_OPS_SRC],
&img_pos[EXYNOS_DRM_OPS_DST]);
if (ret) {
dev_err(dev, "failed to set precalser.\n");
return ret;
}
fimc_handle_jpeg(ctx, false);
fimc_set_scaler(ctx, &ctx->sc);
fimc_set_polarity(ctx, &ctx->pol);
switch (cmd) {
case IPP_CMD_M2M:
fimc_set_type_ctrl(ctx, FIMC_WB_NONE);
fimc_handle_lastend(ctx, false);
cfg0 = fimc_read(ctx, EXYNOS_MSCTRL);
cfg0 &= ~EXYNOS_MSCTRL_INPUT_MASK;
cfg0 |= EXYNOS_MSCTRL_INPUT_MEMORY;
fimc_write(ctx, cfg0, EXYNOS_MSCTRL);
break;
case IPP_CMD_WB:
fimc_set_type_ctrl(ctx, FIMC_WB_A);
fimc_handle_lastend(ctx, true);
ret = fimc_set_camblk_fimd0_wb(ctx);
if (ret < 0) {
dev_err(dev, "camblk setup failed.\n");
return ret;
}
set_wb.enable = 1;
set_wb.refresh = property->refresh_rate;
exynos_drm_ippnb_send_event(IPP_SET_WRITEBACK, (void *)&set_wb);
break;
case IPP_CMD_OUTPUT:
default:
ret = -EINVAL;
dev_err(dev, "invalid operations.\n");
return ret;
}
fimc_write(ctx, 0x0, EXYNOS_CISTATUS);
cfg0 = fimc_read(ctx, EXYNOS_CIIMGCPT);
cfg0 &= ~EXYNOS_CIIMGCPT_IMGCPTEN_SC;
cfg0 |= EXYNOS_CIIMGCPT_IMGCPTEN_SC;
cfg1 = fimc_read(ctx, EXYNOS_CISCCTRL);
cfg1 &= ~EXYNOS_CISCCTRL_SCAN_MASK;
cfg1 |= (EXYNOS_CISCCTRL_PROGRESSIVE |
EXYNOS_CISCCTRL_SCALERSTART);
fimc_write(ctx, cfg1, EXYNOS_CISCCTRL);
cfg0 |= EXYNOS_CIIMGCPT_IMGCPTEN;
fimc_write(ctx, cfg0, EXYNOS_CIIMGCPT);
fimc_clear_bits(ctx, EXYNOS_CIGCTRL, EXYNOS_CIGCTRL_IRQ_END_DISABLE);
fimc_clear_bits(ctx, EXYNOS_CIOCTRL, EXYNOS_CIOCTRL_WEAVE_MASK);
if (cmd == IPP_CMD_M2M) {
fimc_set_bits(ctx, EXYNOS_MSCTRL, EXYNOS_MSCTRL_ENVID);
fimc_set_bits(ctx, EXYNOS_MSCTRL, EXYNOS_MSCTRL_ENVID);
}
return 0;
}
static void fimc_ippdrv_stop(struct device *dev, enum drm_exynos_ipp_cmd cmd)
{
struct fimc_context *ctx = get_fimc_context(dev);
struct drm_exynos_ipp_set_wb set_wb = {0, 0};
u32 cfg;
DRM_DEBUG_KMS("cmd[%d]\n", cmd);
switch (cmd) {
case IPP_CMD_M2M:
cfg = fimc_read(ctx, EXYNOS_MSCTRL);
cfg &= ~EXYNOS_MSCTRL_INPUT_MASK;
cfg &= ~EXYNOS_MSCTRL_ENVID;
fimc_write(ctx, cfg, EXYNOS_MSCTRL);
break;
case IPP_CMD_WB:
exynos_drm_ippnb_send_event(IPP_SET_WRITEBACK, (void *)&set_wb);
break;
case IPP_CMD_OUTPUT:
default:
dev_err(dev, "invalid operations.\n");
break;
}
fimc_mask_irq(ctx, false);
fimc_write(ctx, 0x0, EXYNOS_CIFCNTSEQ);
fimc_clear_bits(ctx, EXYNOS_CISCCTRL, EXYNOS_CISCCTRL_SCALERSTART);
fimc_clear_bits(ctx, EXYNOS_CIIMGCPT,
EXYNOS_CIIMGCPT_IMGCPTEN_SC | EXYNOS_CIIMGCPT_IMGCPTEN);
fimc_set_bits(ctx, EXYNOS_CIGCTRL, EXYNOS_CIGCTRL_IRQ_END_DISABLE);
}
static void fimc_put_clocks(struct fimc_context *ctx)
{
int i;
for (i = 0; i < FIMC_CLKS_MAX; i++) {
if (IS_ERR(ctx->clocks[i]))
continue;
clk_put(ctx->clocks[i]);
ctx->clocks[i] = ERR_PTR(-EINVAL);
}
}
static int fimc_setup_clocks(struct fimc_context *ctx)
{
struct device *fimc_dev = ctx->ippdrv.dev;
struct device *dev;
int ret, i;
for (i = 0; i < FIMC_CLKS_MAX; i++)
ctx->clocks[i] = ERR_PTR(-EINVAL);
for (i = 0; i < FIMC_CLKS_MAX; i++) {
if (i == FIMC_CLK_WB_A || i == FIMC_CLK_WB_B)
dev = fimc_dev->parent;
else
dev = fimc_dev;
ctx->clocks[i] = clk_get(dev, fimc_clock_names[i]);
if (IS_ERR(ctx->clocks[i])) {
if (i >= FIMC_CLK_MUX)
break;
ret = PTR_ERR(ctx->clocks[i]);
dev_err(fimc_dev, "failed to get clock: %s\n",
fimc_clock_names[i]);
goto e_clk_free;
}
}
if (!IS_ERR(ctx->clocks[FIMC_CLK_PARENT])) {
ret = clk_set_parent(ctx->clocks[FIMC_CLK_MUX],
ctx->clocks[FIMC_CLK_PARENT]);
if (ret < 0) {
dev_err(fimc_dev, "failed to set parent.\n");
goto e_clk_free;
}
}
ret = clk_set_rate(ctx->clocks[FIMC_CLK_LCLK], ctx->clk_frequency);
if (ret < 0)
goto e_clk_free;
ret = clk_prepare_enable(ctx->clocks[FIMC_CLK_LCLK]);
if (!ret)
return ret;
e_clk_free:
fimc_put_clocks(ctx);
return ret;
}
static int fimc_parse_dt(struct fimc_context *ctx)
{
struct device_node *node = ctx->ippdrv.dev->of_node;
if (!of_property_read_bool(node, "samsung,lcd-wb"))
return -ENODEV;
if (of_property_read_u32(node, "clock-frequency",
&ctx->clk_frequency))
ctx->clk_frequency = FIMC_DEFAULT_LCLK_FREQUENCY;
ctx->id = of_alias_get_id(node, "fimc");
if (ctx->id < 0) {
dev_err(ctx->ippdrv.dev, "failed to get node alias id.\n");
return -EINVAL;
}
return 0;
}
static int fimc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimc_context *ctx;
struct resource *res;
struct exynos_drm_ippdrv *ippdrv;
int ret;
if (!dev->of_node) {
dev_err(dev, "device tree node not found.\n");
return -ENODEV;
}
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->ippdrv.dev = dev;
ret = fimc_parse_dt(ctx);
if (ret < 0)
return ret;
ctx->sysreg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,sysreg");
if (IS_ERR(ctx->sysreg)) {
dev_err(dev, "syscon regmap lookup failed.\n");
return PTR_ERR(ctx->sysreg);
}
ctx->regs_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->regs = devm_ioremap_resource(dev, ctx->regs_res);
if (IS_ERR(ctx->regs))
return PTR_ERR(ctx->regs);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "failed to request irq resource.\n");
return -ENOENT;
}
ctx->irq = res->start;
ret = devm_request_threaded_irq(dev, ctx->irq, NULL, fimc_irq_handler,
IRQF_ONESHOT, "drm_fimc", ctx);
if (ret < 0) {
dev_err(dev, "failed to request irq.\n");
return ret;
}
ret = fimc_setup_clocks(ctx);
if (ret < 0)
return ret;
ippdrv = &ctx->ippdrv;
ippdrv->ops[EXYNOS_DRM_OPS_SRC] = &fimc_src_ops;
ippdrv->ops[EXYNOS_DRM_OPS_DST] = &fimc_dst_ops;
ippdrv->check_property = fimc_ippdrv_check_property;
ippdrv->reset = fimc_ippdrv_reset;
ippdrv->start = fimc_ippdrv_start;
ippdrv->stop = fimc_ippdrv_stop;
ret = fimc_init_prop_list(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to init property list.\n");
goto err_put_clk;
}
DRM_DEBUG_KMS("id[%d]ippdrv[0x%x]\n", ctx->id, (int)ippdrv);
spin_lock_init(&ctx->lock);
platform_set_drvdata(pdev, ctx);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
ret = exynos_drm_ippdrv_register(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to register drm fimc device.\n");
goto err_pm_dis;
}
dev_info(dev, "drm fimc registered successfully.\n");
return 0;
err_pm_dis:
pm_runtime_disable(dev);
err_put_clk:
fimc_put_clocks(ctx);
return ret;
}
static int fimc_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimc_context *ctx = get_fimc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
exynos_drm_ippdrv_unregister(ippdrv);
fimc_put_clocks(ctx);
pm_runtime_set_suspended(dev);
pm_runtime_disable(dev);
return 0;
}
static int fimc_suspend(struct device *dev)
{
struct fimc_context *ctx = get_fimc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
if (pm_runtime_suspended(dev))
return 0;
return fimc_clk_ctrl(ctx, false);
}
static int fimc_resume(struct device *dev)
{
struct fimc_context *ctx = get_fimc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
if (!pm_runtime_suspended(dev))
return fimc_clk_ctrl(ctx, true);
return 0;
}
static int fimc_runtime_suspend(struct device *dev)
{
struct fimc_context *ctx = get_fimc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
return fimc_clk_ctrl(ctx, false);
}
static int fimc_runtime_resume(struct device *dev)
{
struct fimc_context *ctx = get_fimc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
return fimc_clk_ctrl(ctx, true);
}
