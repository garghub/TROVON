static int gsc_sw_reset(struct gsc_context *ctx)
{
u32 cfg;
int count = GSC_RESET_TIMEOUT;
cfg = (GSC_SW_RESET_SRESET);
gsc_write(cfg, GSC_SW_RESET);
while (count--) {
cfg = gsc_read(GSC_SW_RESET);
if (!cfg)
break;
usleep_range(1000, 2000);
}
if (cfg) {
DRM_ERROR("failed to reset gsc h/w.\n");
return -EBUSY;
}
cfg = gsc_read(GSC_IN_BASE_ADDR_Y_MASK);
cfg |= (GSC_IN_BASE_ADDR_MASK |
GSC_IN_BASE_ADDR_PINGPONG(0));
gsc_write(cfg, GSC_IN_BASE_ADDR_Y_MASK);
gsc_write(cfg, GSC_IN_BASE_ADDR_CB_MASK);
gsc_write(cfg, GSC_IN_BASE_ADDR_CR_MASK);
cfg = gsc_read(GSC_OUT_BASE_ADDR_Y_MASK);
cfg |= (GSC_OUT_BASE_ADDR_MASK |
GSC_OUT_BASE_ADDR_PINGPONG(0));
gsc_write(cfg, GSC_OUT_BASE_ADDR_Y_MASK);
gsc_write(cfg, GSC_OUT_BASE_ADDR_CB_MASK);
gsc_write(cfg, GSC_OUT_BASE_ADDR_CR_MASK);
return 0;
}
static void gsc_set_gscblk_fimd_wb(struct gsc_context *ctx, bool enable)
{
u32 gscblk_cfg;
gscblk_cfg = readl(SYSREG_GSCBLK_CFG1);
if (enable)
gscblk_cfg |= GSC_BLK_DISP1WB_DEST(ctx->id) |
GSC_BLK_GSCL_WB_IN_SRC_SEL(ctx->id) |
GSC_BLK_SW_RESET_WB_DEST(ctx->id);
else
gscblk_cfg |= GSC_BLK_PXLASYNC_LO_MASK_WB(ctx->id);
writel(gscblk_cfg, SYSREG_GSCBLK_CFG1);
}
static void gsc_handle_irq(struct gsc_context *ctx, bool enable,
bool overflow, bool done)
{
u32 cfg;
DRM_DEBUG_KMS("enable[%d]overflow[%d]level[%d]\n",
enable, overflow, done);
cfg = gsc_read(GSC_IRQ);
cfg |= (GSC_IRQ_OR_MASK | GSC_IRQ_FRMDONE_MASK);
if (enable)
cfg |= GSC_IRQ_ENABLE;
else
cfg &= ~GSC_IRQ_ENABLE;
if (overflow)
cfg &= ~GSC_IRQ_OR_MASK;
else
cfg |= GSC_IRQ_OR_MASK;
if (done)
cfg &= ~GSC_IRQ_FRMDONE_MASK;
else
cfg |= GSC_IRQ_FRMDONE_MASK;
gsc_write(cfg, GSC_IRQ);
}
static int gsc_src_set_fmt(struct device *dev, u32 fmt)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~(GSC_IN_RGB_TYPE_MASK | GSC_IN_YUV422_1P_ORDER_MASK |
GSC_IN_CHROMA_ORDER_MASK | GSC_IN_FORMAT_MASK |
GSC_IN_TILE_TYPE_MASK | GSC_IN_TILE_MODE |
GSC_IN_CHROM_STRIDE_SEL_MASK | GSC_IN_RB_SWAP_MASK);
switch (fmt) {
case DRM_FORMAT_RGB565:
cfg |= GSC_IN_RGB565;
break;
case DRM_FORMAT_XRGB8888:
cfg |= GSC_IN_XRGB8888;
break;
case DRM_FORMAT_BGRX8888:
cfg |= (GSC_IN_XRGB8888 | GSC_IN_RB_SWAP);
break;
case DRM_FORMAT_YUYV:
cfg |= (GSC_IN_YUV422_1P |
GSC_IN_YUV422_1P_ORDER_LSB_Y |
GSC_IN_CHROMA_ORDER_CBCR);
break;
case DRM_FORMAT_YVYU:
cfg |= (GSC_IN_YUV422_1P |
GSC_IN_YUV422_1P_ORDER_LSB_Y |
GSC_IN_CHROMA_ORDER_CRCB);
break;
case DRM_FORMAT_UYVY:
cfg |= (GSC_IN_YUV422_1P |
GSC_IN_YUV422_1P_OEDER_LSB_C |
GSC_IN_CHROMA_ORDER_CBCR);
break;
case DRM_FORMAT_VYUY:
cfg |= (GSC_IN_YUV422_1P |
GSC_IN_YUV422_1P_OEDER_LSB_C |
GSC_IN_CHROMA_ORDER_CRCB);
break;
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV61:
cfg |= (GSC_IN_CHROMA_ORDER_CRCB |
GSC_IN_YUV420_2P);
break;
case DRM_FORMAT_YUV422:
cfg |= GSC_IN_YUV422_3P;
break;
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
cfg |= GSC_IN_YUV420_3P;
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV16:
cfg |= (GSC_IN_CHROMA_ORDER_CBCR |
GSC_IN_YUV420_2P);
break;
case DRM_FORMAT_NV12MT:
cfg |= (GSC_IN_TILE_C_16x8 | GSC_IN_TILE_MODE);
break;
default:
dev_err(ippdrv->dev, "inavlid target yuv order 0x%x.\n", fmt);
return -EINVAL;
}
gsc_write(cfg, GSC_IN_CON);
return 0;
}
static int gsc_src_set_transf(struct device *dev,
enum drm_exynos_degree degree,
enum drm_exynos_flip flip, bool *swap)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("degree[%d]flip[0x%x]\n", degree, flip);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~GSC_IN_ROT_MASK;
switch (degree) {
case EXYNOS_DRM_DEGREE_0:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= GSC_IN_ROT_XFLIP;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= GSC_IN_ROT_YFLIP;
break;
case EXYNOS_DRM_DEGREE_90:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= GSC_IN_ROT_90_XFLIP;
else if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= GSC_IN_ROT_90_YFLIP;
else
cfg |= GSC_IN_ROT_90;
break;
case EXYNOS_DRM_DEGREE_180:
cfg |= GSC_IN_ROT_180;
break;
case EXYNOS_DRM_DEGREE_270:
cfg |= GSC_IN_ROT_270;
break;
default:
dev_err(ippdrv->dev, "inavlid degree value %d.\n", degree);
return -EINVAL;
}
gsc_write(cfg, GSC_IN_CON);
ctx->rotation = cfg &
(GSC_IN_ROT_90 | GSC_IN_ROT_270) ? 1 : 0;
*swap = ctx->rotation;
return 0;
}
static int gsc_src_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos, struct drm_exynos_sz *sz)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct drm_exynos_pos img_pos = *pos;
struct gsc_scaler *sc = &ctx->sc;
u32 cfg;
DRM_DEBUG_KMS("swap[%d]x[%d]y[%d]w[%d]h[%d]\n",
swap, pos->x, pos->y, pos->w, pos->h);
if (swap) {
img_pos.w = pos->h;
img_pos.h = pos->w;
}
cfg = (GSC_SRCIMG_OFFSET_X(img_pos.x) |
GSC_SRCIMG_OFFSET_Y(img_pos.y));
gsc_write(cfg, GSC_SRCIMG_OFFSET);
cfg = (GSC_CROPPED_WIDTH(img_pos.w) |
GSC_CROPPED_HEIGHT(img_pos.h));
gsc_write(cfg, GSC_CROPPED_SIZE);
DRM_DEBUG_KMS("hsize[%d]vsize[%d]\n", sz->hsize, sz->vsize);
cfg = gsc_read(GSC_SRCIMG_SIZE);
cfg &= ~(GSC_SRCIMG_HEIGHT_MASK |
GSC_SRCIMG_WIDTH_MASK);
cfg |= (GSC_SRCIMG_WIDTH(sz->hsize) |
GSC_SRCIMG_HEIGHT(sz->vsize));
gsc_write(cfg, GSC_SRCIMG_SIZE);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~GSC_IN_RGB_TYPE_MASK;
DRM_DEBUG_KMS("width[%d]range[%d]\n", pos->w, sc->range);
if (pos->w >= GSC_WIDTH_ITU_709)
if (sc->range)
cfg |= GSC_IN_RGB_HD_WIDE;
else
cfg |= GSC_IN_RGB_HD_NARROW;
else
if (sc->range)
cfg |= GSC_IN_RGB_SD_WIDE;
else
cfg |= GSC_IN_RGB_SD_NARROW;
gsc_write(cfg, GSC_IN_CON);
return 0;
}
static int gsc_src_set_buf_seq(struct gsc_context *ctx, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
bool masked;
u32 cfg;
u32 mask = 0x00000001 << buf_id;
DRM_DEBUG_KMS("buf_id[%d]buf_type[%d]\n", buf_id, buf_type);
cfg = gsc_read(GSC_IN_BASE_ADDR_Y_MASK);
switch (buf_type) {
case IPP_BUF_ENQUEUE:
masked = false;
break;
case IPP_BUF_DEQUEUE:
masked = true;
break;
default:
dev_err(ippdrv->dev, "invalid buf ctrl parameter.\n");
return -EINVAL;
}
cfg &= ~mask;
cfg |= masked << buf_id;
gsc_write(cfg, GSC_IN_BASE_ADDR_Y_MASK);
gsc_write(cfg, GSC_IN_BASE_ADDR_CB_MASK);
gsc_write(cfg, GSC_IN_BASE_ADDR_CR_MASK);
return 0;
}
static int gsc_src_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EFAULT;
}
property = &c_node->property;
DRM_DEBUG_KMS("prop_id[%d]buf_id[%d]buf_type[%d]\n",
property->prop_id, buf_id, buf_type);
if (buf_id > GSC_MAX_SRC) {
dev_info(ippdrv->dev, "inavlid buf_id %d.\n", buf_id);
return -EINVAL;
}
switch (buf_type) {
case IPP_BUF_ENQUEUE:
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_Y],
GSC_IN_BASE_ADDR_Y(buf_id));
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_CB],
GSC_IN_BASE_ADDR_CB(buf_id));
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_CR],
GSC_IN_BASE_ADDR_CR(buf_id));
break;
case IPP_BUF_DEQUEUE:
gsc_write(0x0, GSC_IN_BASE_ADDR_Y(buf_id));
gsc_write(0x0, GSC_IN_BASE_ADDR_CB(buf_id));
gsc_write(0x0, GSC_IN_BASE_ADDR_CR(buf_id));
break;
default:
break;
}
return gsc_src_set_buf_seq(ctx, buf_id, buf_type);
}
static int gsc_dst_set_fmt(struct device *dev, u32 fmt)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("fmt[0x%x]\n", fmt);
cfg = gsc_read(GSC_OUT_CON);
cfg &= ~(GSC_OUT_RGB_TYPE_MASK | GSC_OUT_YUV422_1P_ORDER_MASK |
GSC_OUT_CHROMA_ORDER_MASK | GSC_OUT_FORMAT_MASK |
GSC_OUT_CHROM_STRIDE_SEL_MASK | GSC_OUT_RB_SWAP_MASK |
GSC_OUT_GLOBAL_ALPHA_MASK);
switch (fmt) {
case DRM_FORMAT_RGB565:
cfg |= GSC_OUT_RGB565;
break;
case DRM_FORMAT_XRGB8888:
cfg |= GSC_OUT_XRGB8888;
break;
case DRM_FORMAT_BGRX8888:
cfg |= (GSC_OUT_XRGB8888 | GSC_OUT_RB_SWAP);
break;
case DRM_FORMAT_YUYV:
cfg |= (GSC_OUT_YUV422_1P |
GSC_OUT_YUV422_1P_ORDER_LSB_Y |
GSC_OUT_CHROMA_ORDER_CBCR);
break;
case DRM_FORMAT_YVYU:
cfg |= (GSC_OUT_YUV422_1P |
GSC_OUT_YUV422_1P_ORDER_LSB_Y |
GSC_OUT_CHROMA_ORDER_CRCB);
break;
case DRM_FORMAT_UYVY:
cfg |= (GSC_OUT_YUV422_1P |
GSC_OUT_YUV422_1P_OEDER_LSB_C |
GSC_OUT_CHROMA_ORDER_CBCR);
break;
case DRM_FORMAT_VYUY:
cfg |= (GSC_OUT_YUV422_1P |
GSC_OUT_YUV422_1P_OEDER_LSB_C |
GSC_OUT_CHROMA_ORDER_CRCB);
break;
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV61:
cfg |= (GSC_OUT_CHROMA_ORDER_CRCB | GSC_OUT_YUV420_2P);
break;
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
cfg |= GSC_OUT_YUV420_3P;
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV16:
cfg |= (GSC_OUT_CHROMA_ORDER_CBCR |
GSC_OUT_YUV420_2P);
break;
case DRM_FORMAT_NV12MT:
cfg |= (GSC_OUT_TILE_C_16x8 | GSC_OUT_TILE_MODE);
break;
default:
dev_err(ippdrv->dev, "inavlid target yuv order 0x%x.\n", fmt);
return -EINVAL;
}
gsc_write(cfg, GSC_OUT_CON);
return 0;
}
static int gsc_dst_set_transf(struct device *dev,
enum drm_exynos_degree degree,
enum drm_exynos_flip flip, bool *swap)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
DRM_DEBUG_KMS("degree[%d]flip[0x%x]\n", degree, flip);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~GSC_IN_ROT_MASK;
switch (degree) {
case EXYNOS_DRM_DEGREE_0:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= GSC_IN_ROT_XFLIP;
if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= GSC_IN_ROT_YFLIP;
break;
case EXYNOS_DRM_DEGREE_90:
if (flip & EXYNOS_DRM_FLIP_VERTICAL)
cfg |= GSC_IN_ROT_90_XFLIP;
else if (flip & EXYNOS_DRM_FLIP_HORIZONTAL)
cfg |= GSC_IN_ROT_90_YFLIP;
else
cfg |= GSC_IN_ROT_90;
break;
case EXYNOS_DRM_DEGREE_180:
cfg |= GSC_IN_ROT_180;
break;
case EXYNOS_DRM_DEGREE_270:
cfg |= GSC_IN_ROT_270;
break;
default:
dev_err(ippdrv->dev, "inavlid degree value %d.\n", degree);
return -EINVAL;
}
gsc_write(cfg, GSC_IN_CON);
ctx->rotation = cfg &
(GSC_IN_ROT_90 | GSC_IN_ROT_270) ? 1 : 0;
*swap = ctx->rotation;
return 0;
}
static int gsc_get_ratio_shift(u32 src, u32 dst, u32 *ratio)
{
DRM_DEBUG_KMS("src[%d]dst[%d]\n", src, dst);
if (src >= dst * 8) {
DRM_ERROR("failed to make ratio and shift.\n");
return -EINVAL;
} else if (src >= dst * 4)
*ratio = 4;
else if (src >= dst * 2)
*ratio = 2;
else
*ratio = 1;
return 0;
}
static void gsc_get_prescaler_shfactor(u32 hratio, u32 vratio, u32 *shfactor)
{
if (hratio == 4 && vratio == 4)
*shfactor = 4;
else if ((hratio == 4 && vratio == 2) ||
(hratio == 2 && vratio == 4))
*shfactor = 3;
else if ((hratio == 4 && vratio == 1) ||
(hratio == 1 && vratio == 4) ||
(hratio == 2 && vratio == 2))
*shfactor = 2;
else if (hratio == 1 && vratio == 1)
*shfactor = 0;
else
*shfactor = 1;
}
static int gsc_set_prescaler(struct gsc_context *ctx, struct gsc_scaler *sc,
struct drm_exynos_pos *src, struct drm_exynos_pos *dst)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
u32 cfg;
u32 src_w, src_h, dst_w, dst_h;
int ret = 0;
src_w = src->w;
src_h = src->h;
if (ctx->rotation) {
dst_w = dst->h;
dst_h = dst->w;
} else {
dst_w = dst->w;
dst_h = dst->h;
}
ret = gsc_get_ratio_shift(src_w, dst_w, &sc->pre_hratio);
if (ret) {
dev_err(ippdrv->dev, "failed to get ratio horizontal.\n");
return ret;
}
ret = gsc_get_ratio_shift(src_h, dst_h, &sc->pre_vratio);
if (ret) {
dev_err(ippdrv->dev, "failed to get ratio vertical.\n");
return ret;
}
DRM_DEBUG_KMS("pre_hratio[%d]pre_vratio[%d]\n",
sc->pre_hratio, sc->pre_vratio);
sc->main_hratio = (src_w << 16) / dst_w;
sc->main_vratio = (src_h << 16) / dst_h;
DRM_DEBUG_KMS("main_hratio[%ld]main_vratio[%ld]\n",
sc->main_hratio, sc->main_vratio);
gsc_get_prescaler_shfactor(sc->pre_hratio, sc->pre_vratio,
&sc->pre_shfactor);
DRM_DEBUG_KMS("pre_shfactor[%d]\n", sc->pre_shfactor);
cfg = (GSC_PRESC_SHFACTOR(sc->pre_shfactor) |
GSC_PRESC_H_RATIO(sc->pre_hratio) |
GSC_PRESC_V_RATIO(sc->pre_vratio));
gsc_write(cfg, GSC_PRE_SCALE_RATIO);
return ret;
}
static void gsc_set_h_coef(struct gsc_context *ctx, unsigned long main_hratio)
{
int i, j, k, sc_ratio;
if (main_hratio <= GSC_SC_UP_MAX_RATIO)
sc_ratio = 0;
else if (main_hratio <= GSC_SC_DOWN_RATIO_7_8)
sc_ratio = 1;
else if (main_hratio <= GSC_SC_DOWN_RATIO_6_8)
sc_ratio = 2;
else if (main_hratio <= GSC_SC_DOWN_RATIO_5_8)
sc_ratio = 3;
else if (main_hratio <= GSC_SC_DOWN_RATIO_4_8)
sc_ratio = 4;
else if (main_hratio <= GSC_SC_DOWN_RATIO_3_8)
sc_ratio = 5;
else
sc_ratio = 6;
for (i = 0; i < GSC_COEF_PHASE; i++)
for (j = 0; j < GSC_COEF_H_8T; j++)
for (k = 0; k < GSC_COEF_DEPTH; k++)
gsc_write(h_coef_8t[sc_ratio][i][j],
GSC_HCOEF(i, j, k));
}
static void gsc_set_v_coef(struct gsc_context *ctx, unsigned long main_vratio)
{
int i, j, k, sc_ratio;
if (main_vratio <= GSC_SC_UP_MAX_RATIO)
sc_ratio = 0;
else if (main_vratio <= GSC_SC_DOWN_RATIO_7_8)
sc_ratio = 1;
else if (main_vratio <= GSC_SC_DOWN_RATIO_6_8)
sc_ratio = 2;
else if (main_vratio <= GSC_SC_DOWN_RATIO_5_8)
sc_ratio = 3;
else if (main_vratio <= GSC_SC_DOWN_RATIO_4_8)
sc_ratio = 4;
else if (main_vratio <= GSC_SC_DOWN_RATIO_3_8)
sc_ratio = 5;
else
sc_ratio = 6;
for (i = 0; i < GSC_COEF_PHASE; i++)
for (j = 0; j < GSC_COEF_V_4T; j++)
for (k = 0; k < GSC_COEF_DEPTH; k++)
gsc_write(v_coef_4t[sc_ratio][i][j],
GSC_VCOEF(i, j, k));
}
static void gsc_set_scaler(struct gsc_context *ctx, struct gsc_scaler *sc)
{
u32 cfg;
DRM_DEBUG_KMS("main_hratio[%ld]main_vratio[%ld]\n",
sc->main_hratio, sc->main_vratio);
gsc_set_h_coef(ctx, sc->main_hratio);
cfg = GSC_MAIN_H_RATIO_VALUE(sc->main_hratio);
gsc_write(cfg, GSC_MAIN_H_RATIO);
gsc_set_v_coef(ctx, sc->main_vratio);
cfg = GSC_MAIN_V_RATIO_VALUE(sc->main_vratio);
gsc_write(cfg, GSC_MAIN_V_RATIO);
}
static int gsc_dst_set_size(struct device *dev, int swap,
struct drm_exynos_pos *pos, struct drm_exynos_sz *sz)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct drm_exynos_pos img_pos = *pos;
struct gsc_scaler *sc = &ctx->sc;
u32 cfg;
DRM_DEBUG_KMS("swap[%d]x[%d]y[%d]w[%d]h[%d]\n",
swap, pos->x, pos->y, pos->w, pos->h);
if (swap) {
img_pos.w = pos->h;
img_pos.h = pos->w;
}
cfg = (GSC_DSTIMG_OFFSET_X(pos->x) |
GSC_DSTIMG_OFFSET_Y(pos->y));
gsc_write(cfg, GSC_DSTIMG_OFFSET);
cfg = (GSC_SCALED_WIDTH(img_pos.w) | GSC_SCALED_HEIGHT(img_pos.h));
gsc_write(cfg, GSC_SCALED_SIZE);
DRM_DEBUG_KMS("hsize[%d]vsize[%d]\n", sz->hsize, sz->vsize);
cfg = gsc_read(GSC_DSTIMG_SIZE);
cfg &= ~(GSC_DSTIMG_HEIGHT_MASK |
GSC_DSTIMG_WIDTH_MASK);
cfg |= (GSC_DSTIMG_WIDTH(sz->hsize) |
GSC_DSTIMG_HEIGHT(sz->vsize));
gsc_write(cfg, GSC_DSTIMG_SIZE);
cfg = gsc_read(GSC_OUT_CON);
cfg &= ~GSC_OUT_RGB_TYPE_MASK;
DRM_DEBUG_KMS("width[%d]range[%d]\n", pos->w, sc->range);
if (pos->w >= GSC_WIDTH_ITU_709)
if (sc->range)
cfg |= GSC_OUT_RGB_HD_WIDE;
else
cfg |= GSC_OUT_RGB_HD_NARROW;
else
if (sc->range)
cfg |= GSC_OUT_RGB_SD_WIDE;
else
cfg |= GSC_OUT_RGB_SD_NARROW;
gsc_write(cfg, GSC_OUT_CON);
return 0;
}
static int gsc_dst_get_buf_seq(struct gsc_context *ctx)
{
u32 cfg, i, buf_num = GSC_REG_SZ;
u32 mask = 0x00000001;
cfg = gsc_read(GSC_OUT_BASE_ADDR_Y_MASK);
for (i = 0; i < GSC_REG_SZ; i++)
if (cfg & (mask << i))
buf_num--;
DRM_DEBUG_KMS("buf_num[%d]\n", buf_num);
return buf_num;
}
static int gsc_dst_set_buf_seq(struct gsc_context *ctx, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
bool masked;
u32 cfg;
u32 mask = 0x00000001 << buf_id;
int ret = 0;
DRM_DEBUG_KMS("buf_id[%d]buf_type[%d]\n", buf_id, buf_type);
mutex_lock(&ctx->lock);
cfg = gsc_read(GSC_OUT_BASE_ADDR_Y_MASK);
switch (buf_type) {
case IPP_BUF_ENQUEUE:
masked = false;
break;
case IPP_BUF_DEQUEUE:
masked = true;
break;
default:
dev_err(ippdrv->dev, "invalid buf ctrl parameter.\n");
ret = -EINVAL;
goto err_unlock;
}
cfg &= ~mask;
cfg |= masked << buf_id;
gsc_write(cfg, GSC_OUT_BASE_ADDR_Y_MASK);
gsc_write(cfg, GSC_OUT_BASE_ADDR_CB_MASK);
gsc_write(cfg, GSC_OUT_BASE_ADDR_CR_MASK);
if (buf_type == IPP_BUF_ENQUEUE &&
gsc_dst_get_buf_seq(ctx) >= GSC_BUF_START)
gsc_handle_irq(ctx, true, false, true);
if (buf_type == IPP_BUF_DEQUEUE &&
gsc_dst_get_buf_seq(ctx) <= GSC_BUF_STOP)
gsc_handle_irq(ctx, false, false, true);
err_unlock:
mutex_unlock(&ctx->lock);
return ret;
}
static int gsc_dst_set_addr(struct device *dev,
struct drm_exynos_ipp_buf_info *buf_info, u32 buf_id,
enum drm_exynos_ipp_buf_type buf_type)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EFAULT;
}
property = &c_node->property;
DRM_DEBUG_KMS("prop_id[%d]buf_id[%d]buf_type[%d]\n",
property->prop_id, buf_id, buf_type);
if (buf_id > GSC_MAX_DST) {
dev_info(ippdrv->dev, "inavlid buf_id %d.\n", buf_id);
return -EINVAL;
}
switch (buf_type) {
case IPP_BUF_ENQUEUE:
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_Y],
GSC_OUT_BASE_ADDR_Y(buf_id));
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_CB],
GSC_OUT_BASE_ADDR_CB(buf_id));
gsc_write(buf_info->base[EXYNOS_DRM_PLANAR_CR],
GSC_OUT_BASE_ADDR_CR(buf_id));
break;
case IPP_BUF_DEQUEUE:
gsc_write(0x0, GSC_OUT_BASE_ADDR_Y(buf_id));
gsc_write(0x0, GSC_OUT_BASE_ADDR_CB(buf_id));
gsc_write(0x0, GSC_OUT_BASE_ADDR_CR(buf_id));
break;
default:
break;
}
return gsc_dst_set_buf_seq(ctx, buf_id, buf_type);
}
static int gsc_clk_ctrl(struct gsc_context *ctx, bool enable)
{
DRM_DEBUG_KMS("enable[%d]\n", enable);
if (enable) {
clk_enable(ctx->gsc_clk);
ctx->suspended = false;
} else {
clk_disable(ctx->gsc_clk);
ctx->suspended = true;
}
return 0;
}
static int gsc_get_src_buf_index(struct gsc_context *ctx)
{
u32 cfg, curr_index, i;
u32 buf_id = GSC_MAX_SRC;
int ret;
DRM_DEBUG_KMS("gsc id[%d]\n", ctx->id);
cfg = gsc_read(GSC_IN_BASE_ADDR_Y_MASK);
curr_index = GSC_IN_CURR_GET_INDEX(cfg);
for (i = curr_index; i < GSC_MAX_SRC; i++) {
if (!((cfg >> i) & 0x1)) {
buf_id = i;
break;
}
}
if (buf_id == GSC_MAX_SRC) {
DRM_ERROR("failed to get in buffer index.\n");
return -EINVAL;
}
ret = gsc_src_set_buf_seq(ctx, buf_id, IPP_BUF_DEQUEUE);
if (ret < 0) {
DRM_ERROR("failed to dequeue.\n");
return ret;
}
DRM_DEBUG_KMS("cfg[0x%x]curr_index[%d]buf_id[%d]\n", cfg,
curr_index, buf_id);
return buf_id;
}
static int gsc_get_dst_buf_index(struct gsc_context *ctx)
{
u32 cfg, curr_index, i;
u32 buf_id = GSC_MAX_DST;
int ret;
DRM_DEBUG_KMS("gsc id[%d]\n", ctx->id);
cfg = gsc_read(GSC_OUT_BASE_ADDR_Y_MASK);
curr_index = GSC_OUT_CURR_GET_INDEX(cfg);
for (i = curr_index; i < GSC_MAX_DST; i++) {
if (!((cfg >> i) & 0x1)) {
buf_id = i;
break;
}
}
if (buf_id == GSC_MAX_DST) {
DRM_ERROR("failed to get out buffer index.\n");
return -EINVAL;
}
ret = gsc_dst_set_buf_seq(ctx, buf_id, IPP_BUF_DEQUEUE);
if (ret < 0) {
DRM_ERROR("failed to dequeue.\n");
return ret;
}
DRM_DEBUG_KMS("cfg[0x%x]curr_index[%d]buf_id[%d]\n", cfg,
curr_index, buf_id);
return buf_id;
}
static irqreturn_t gsc_irq_handler(int irq, void *dev_id)
{
struct gsc_context *ctx = dev_id;
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_event_work *event_work =
c_node->event_work;
u32 status;
int buf_id[EXYNOS_DRM_OPS_MAX];
DRM_DEBUG_KMS("gsc id[%d]\n", ctx->id);
status = gsc_read(GSC_IRQ);
if (status & GSC_IRQ_STATUS_OR_IRQ) {
dev_err(ippdrv->dev, "occurred overflow at %d, status 0x%x.\n",
ctx->id, status);
return IRQ_NONE;
}
if (status & GSC_IRQ_STATUS_OR_FRM_DONE) {
dev_dbg(ippdrv->dev, "occurred frame done at %d, status 0x%x.\n",
ctx->id, status);
buf_id[EXYNOS_DRM_OPS_SRC] = gsc_get_src_buf_index(ctx);
if (buf_id[EXYNOS_DRM_OPS_SRC] < 0)
return IRQ_HANDLED;
buf_id[EXYNOS_DRM_OPS_DST] = gsc_get_dst_buf_index(ctx);
if (buf_id[EXYNOS_DRM_OPS_DST] < 0)
return IRQ_HANDLED;
DRM_DEBUG_KMS("buf_id_src[%d]buf_id_dst[%d]\n",
buf_id[EXYNOS_DRM_OPS_SRC], buf_id[EXYNOS_DRM_OPS_DST]);
event_work->ippdrv = ippdrv;
event_work->buf_id[EXYNOS_DRM_OPS_SRC] =
buf_id[EXYNOS_DRM_OPS_SRC];
event_work->buf_id[EXYNOS_DRM_OPS_DST] =
buf_id[EXYNOS_DRM_OPS_DST];
queue_work(ippdrv->event_workq,
(struct work_struct *)event_work);
}
return IRQ_HANDLED;
}
static int gsc_init_prop_list(struct exynos_drm_ippdrv *ippdrv)
{
struct drm_exynos_ipp_prop_list *prop_list = &ippdrv->prop_list;
prop_list->version = 1;
prop_list->writeback = 1;
prop_list->refresh_min = GSC_REFRESH_MIN;
prop_list->refresh_max = GSC_REFRESH_MAX;
prop_list->flip = (1 << EXYNOS_DRM_FLIP_VERTICAL) |
(1 << EXYNOS_DRM_FLIP_HORIZONTAL);
prop_list->degree = (1 << EXYNOS_DRM_DEGREE_0) |
(1 << EXYNOS_DRM_DEGREE_90) |
(1 << EXYNOS_DRM_DEGREE_180) |
(1 << EXYNOS_DRM_DEGREE_270);
prop_list->csc = 1;
prop_list->crop = 1;
prop_list->crop_max.hsize = GSC_CROP_MAX;
prop_list->crop_max.vsize = GSC_CROP_MAX;
prop_list->crop_min.hsize = GSC_CROP_MIN;
prop_list->crop_min.vsize = GSC_CROP_MIN;
prop_list->scale = 1;
prop_list->scale_max.hsize = GSC_SCALE_MAX;
prop_list->scale_max.vsize = GSC_SCALE_MAX;
prop_list->scale_min.hsize = GSC_SCALE_MIN;
prop_list->scale_min.vsize = GSC_SCALE_MIN;
return 0;
}
static inline bool gsc_check_drm_flip(enum drm_exynos_flip flip)
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
static int gsc_ippdrv_check_property(struct device *dev,
struct drm_exynos_ipp_property *property)
{
struct gsc_context *ctx = get_gsc_context(dev);
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
if (!gsc_check_drm_flip(config->flip)) {
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
static int gsc_ippdrv_reset(struct device *dev)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct gsc_scaler *sc = &ctx->sc;
int ret;
ret = gsc_sw_reset(ctx);
if (ret < 0) {
dev_err(dev, "failed to reset hardware.\n");
return ret;
}
memset(&ctx->sc, 0x0, sizeof(ctx->sc));
sc->range = true;
return 0;
}
static int gsc_ippdrv_start(struct device *dev, enum drm_exynos_ipp_cmd cmd)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
struct drm_exynos_ipp_cmd_node *c_node = ippdrv->c_node;
struct drm_exynos_ipp_property *property;
struct drm_exynos_ipp_config *config;
struct drm_exynos_pos img_pos[EXYNOS_DRM_OPS_MAX];
struct drm_exynos_ipp_set_wb set_wb;
u32 cfg;
int ret, i;
DRM_DEBUG_KMS("cmd[%d]\n", cmd);
if (!c_node) {
DRM_ERROR("failed to get c_node.\n");
return -EINVAL;
}
property = &c_node->property;
gsc_handle_irq(ctx, true, false, true);
for_each_ipp_ops(i) {
config = &property->config[i];
img_pos[i] = config->pos;
}
switch (cmd) {
case IPP_CMD_M2M:
cfg = gsc_read(GSC_ENABLE);
cfg &= ~(GSC_ENABLE_ON_CLEAR_MASK |
GSC_ENABLE_CLK_GATE_MODE_MASK);
cfg |= GSC_ENABLE_ON_CLEAR_ONESHOT;
gsc_write(cfg, GSC_ENABLE);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~(GSC_IN_PATH_MASK | GSC_IN_LOCAL_SEL_MASK);
cfg |= GSC_IN_PATH_MEMORY;
gsc_write(cfg, GSC_IN_CON);
cfg = gsc_read(GSC_OUT_CON);
cfg |= GSC_OUT_PATH_MEMORY;
gsc_write(cfg, GSC_OUT_CON);
break;
case IPP_CMD_WB:
set_wb.enable = 1;
set_wb.refresh = property->refresh_rate;
gsc_set_gscblk_fimd_wb(ctx, set_wb.enable);
exynos_drm_ippnb_send_event(IPP_SET_WRITEBACK, (void *)&set_wb);
cfg = gsc_read(GSC_IN_CON);
cfg &= ~(GSC_IN_PATH_MASK | GSC_IN_LOCAL_SEL_MASK);
cfg |= (GSC_IN_PATH_LOCAL | GSC_IN_LOCAL_FIMD_WB);
gsc_write(cfg, GSC_IN_CON);
cfg = gsc_read(GSC_OUT_CON);
cfg |= GSC_OUT_PATH_MEMORY;
gsc_write(cfg, GSC_OUT_CON);
break;
case IPP_CMD_OUTPUT:
cfg = gsc_read(GSC_IN_CON);
cfg &= ~(GSC_IN_PATH_MASK | GSC_IN_LOCAL_SEL_MASK);
cfg |= GSC_IN_PATH_MEMORY;
gsc_write(cfg, GSC_IN_CON);
cfg = gsc_read(GSC_OUT_CON);
cfg |= GSC_OUT_PATH_MEMORY;
gsc_write(cfg, GSC_OUT_CON);
break;
default:
ret = -EINVAL;
dev_err(dev, "invalid operations.\n");
return ret;
}
ret = gsc_set_prescaler(ctx, &ctx->sc,
&img_pos[EXYNOS_DRM_OPS_SRC],
&img_pos[EXYNOS_DRM_OPS_DST]);
if (ret) {
dev_err(dev, "failed to set precalser.\n");
return ret;
}
gsc_set_scaler(ctx, &ctx->sc);
cfg = gsc_read(GSC_ENABLE);
cfg |= GSC_ENABLE_ON;
gsc_write(cfg, GSC_ENABLE);
return 0;
}
static void gsc_ippdrv_stop(struct device *dev, enum drm_exynos_ipp_cmd cmd)
{
struct gsc_context *ctx = get_gsc_context(dev);
struct drm_exynos_ipp_set_wb set_wb = {0, 0};
u32 cfg;
DRM_DEBUG_KMS("cmd[%d]\n", cmd);
switch (cmd) {
case IPP_CMD_M2M:
break;
case IPP_CMD_WB:
gsc_set_gscblk_fimd_wb(ctx, set_wb.enable);
exynos_drm_ippnb_send_event(IPP_SET_WRITEBACK, (void *)&set_wb);
break;
case IPP_CMD_OUTPUT:
default:
dev_err(dev, "invalid operations.\n");
break;
}
gsc_handle_irq(ctx, false, false, true);
gsc_write(0xff, GSC_OUT_BASE_ADDR_Y_MASK);
gsc_write(0xff, GSC_OUT_BASE_ADDR_CB_MASK);
gsc_write(0xff, GSC_OUT_BASE_ADDR_CR_MASK);
cfg = gsc_read(GSC_ENABLE);
cfg &= ~GSC_ENABLE_ON;
gsc_write(cfg, GSC_ENABLE);
}
static int gsc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct gsc_context *ctx;
struct resource *res;
struct exynos_drm_ippdrv *ippdrv;
int ret;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->gsc_clk = devm_clk_get(dev, "gscl");
if (IS_ERR(ctx->gsc_clk)) {
dev_err(dev, "failed to get gsc clock.\n");
return PTR_ERR(ctx->gsc_clk);
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
ret = devm_request_threaded_irq(dev, ctx->irq, NULL, gsc_irq_handler,
IRQF_ONESHOT, "drm_gsc", ctx);
if (ret < 0) {
dev_err(dev, "failed to request irq.\n");
return ret;
}
ctx->id = pdev->id;
ippdrv = &ctx->ippdrv;
ippdrv->dev = dev;
ippdrv->ops[EXYNOS_DRM_OPS_SRC] = &gsc_src_ops;
ippdrv->ops[EXYNOS_DRM_OPS_DST] = &gsc_dst_ops;
ippdrv->check_property = gsc_ippdrv_check_property;
ippdrv->reset = gsc_ippdrv_reset;
ippdrv->start = gsc_ippdrv_start;
ippdrv->stop = gsc_ippdrv_stop;
ret = gsc_init_prop_list(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to init property list.\n");
return ret;
}
DRM_DEBUG_KMS("id[%d]ippdrv[0x%x]\n", ctx->id, (int)ippdrv);
mutex_init(&ctx->lock);
platform_set_drvdata(pdev, ctx);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
ret = exynos_drm_ippdrv_register(ippdrv);
if (ret < 0) {
dev_err(dev, "failed to register drm gsc device.\n");
goto err_ippdrv_register;
}
dev_info(dev, "drm gsc registered successfully.\n");
return 0;
err_ippdrv_register:
pm_runtime_disable(dev);
return ret;
}
static int gsc_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct gsc_context *ctx = get_gsc_context(dev);
struct exynos_drm_ippdrv *ippdrv = &ctx->ippdrv;
exynos_drm_ippdrv_unregister(ippdrv);
mutex_destroy(&ctx->lock);
pm_runtime_set_suspended(dev);
pm_runtime_disable(dev);
return 0;
}
static int gsc_suspend(struct device *dev)
{
struct gsc_context *ctx = get_gsc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
if (pm_runtime_suspended(dev))
return 0;
return gsc_clk_ctrl(ctx, false);
}
static int gsc_resume(struct device *dev)
{
struct gsc_context *ctx = get_gsc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
if (!pm_runtime_suspended(dev))
return gsc_clk_ctrl(ctx, true);
return 0;
}
static int gsc_runtime_suspend(struct device *dev)
{
struct gsc_context *ctx = get_gsc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
return gsc_clk_ctrl(ctx, false);
}
static int gsc_runtime_resume(struct device *dev)
{
struct gsc_context *ctx = get_gsc_context(dev);
DRM_DEBUG_KMS("id[%d]\n", ctx->id);
return gsc_clk_ctrl(ctx, true);
}
