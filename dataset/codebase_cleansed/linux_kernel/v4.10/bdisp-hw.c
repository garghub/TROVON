int bdisp_hw_reset(struct bdisp_dev *bdisp)
{
unsigned int i;
dev_dbg(bdisp->dev, "%s\n", __func__);
writel(0, bdisp->regs + BLT_ITM0);
writel(readl(bdisp->regs + BLT_CTL) | BLT_CTL_RESET,
bdisp->regs + BLT_CTL);
writel(0, bdisp->regs + BLT_CTL);
for (i = 0; i < POLL_RST_MAX; i++) {
if (readl(bdisp->regs + BLT_STA1) & BLT_STA1_IDLE)
break;
msleep(POLL_RST_DELAY_MS);
}
if (i == POLL_RST_MAX)
dev_err(bdisp->dev, "Reset timeout\n");
return (i == POLL_RST_MAX) ? -EAGAIN : 0;
}
int bdisp_hw_get_and_clear_irq(struct bdisp_dev *bdisp)
{
u32 its;
its = readl(bdisp->regs + BLT_ITS);
if (!(its & BLT_ITS_AQ1_LNA)) {
dev_dbg(bdisp->dev, "Unexpected IT status: 0x%08X\n", its);
writel(its, bdisp->regs + BLT_ITS);
return -1;
}
writel(its, bdisp->regs + BLT_ITS);
writel(0, bdisp->regs + BLT_ITM0);
return 0;
}
void bdisp_hw_free_nodes(struct bdisp_ctx *ctx)
{
if (ctx && ctx->node[0])
dma_free_attrs(ctx->bdisp_dev->dev,
sizeof(struct bdisp_node) * MAX_NB_NODE,
ctx->node[0], ctx->node_paddr[0],
DMA_ATTR_WRITE_COMBINE);
}
int bdisp_hw_alloc_nodes(struct bdisp_ctx *ctx)
{
struct device *dev = ctx->bdisp_dev->dev;
unsigned int i, node_size = sizeof(struct bdisp_node);
void *base;
dma_addr_t paddr;
base = dma_alloc_attrs(dev, node_size * MAX_NB_NODE, &paddr,
GFP_KERNEL | GFP_DMA, DMA_ATTR_WRITE_COMBINE);
if (!base) {
dev_err(dev, "%s no mem\n", __func__);
return -ENOMEM;
}
memset(base, 0, node_size * MAX_NB_NODE);
for (i = 0; i < MAX_NB_NODE; i++) {
ctx->node[i] = base;
ctx->node_paddr[i] = paddr;
dev_dbg(dev, "node[%d]=0x%p (paddr=%pad)\n", i, ctx->node[i],
&paddr);
base += node_size;
paddr += node_size;
}
return 0;
}
void bdisp_hw_free_filters(struct device *dev)
{
int size = (BDISP_HF_NB * NB_H_FILTER) + (BDISP_VF_NB * NB_V_FILTER);
if (bdisp_h_filter[0].virt)
dma_free_attrs(dev, size, bdisp_h_filter[0].virt,
bdisp_h_filter[0].paddr, DMA_ATTR_WRITE_COMBINE);
}
int bdisp_hw_alloc_filters(struct device *dev)
{
unsigned int i, size;
void *base;
dma_addr_t paddr;
size = (BDISP_HF_NB * NB_H_FILTER) + (BDISP_VF_NB * NB_V_FILTER);
base = dma_alloc_attrs(dev, size, &paddr, GFP_KERNEL | GFP_DMA,
DMA_ATTR_WRITE_COMBINE);
if (!base)
return -ENOMEM;
for (i = 0; i < NB_H_FILTER; i++) {
bdisp_h_filter[i].min = bdisp_h_spec[i].min;
bdisp_h_filter[i].max = bdisp_h_spec[i].max;
memcpy(base, bdisp_h_spec[i].coef, BDISP_HF_NB);
bdisp_h_filter[i].virt = base;
bdisp_h_filter[i].paddr = paddr;
base += BDISP_HF_NB;
paddr += BDISP_HF_NB;
}
for (i = 0; i < NB_V_FILTER; i++) {
bdisp_v_filter[i].min = bdisp_v_spec[i].min;
bdisp_v_filter[i].max = bdisp_v_spec[i].max;
memcpy(base, bdisp_v_spec[i].coef, BDISP_VF_NB);
bdisp_v_filter[i].virt = base;
bdisp_v_filter[i].paddr = paddr;
base += BDISP_VF_NB;
paddr += BDISP_VF_NB;
}
return 0;
}
static dma_addr_t bdisp_hw_get_hf_addr(u16 inc)
{
unsigned int i;
for (i = NB_H_FILTER - 1; i > 0; i--)
if ((bdisp_h_filter[i].min < inc) &&
(inc <= bdisp_h_filter[i].max))
break;
return bdisp_h_filter[i].paddr;
}
static dma_addr_t bdisp_hw_get_vf_addr(u16 inc)
{
unsigned int i;
for (i = NB_V_FILTER - 1; i > 0; i--)
if ((bdisp_v_filter[i].min < inc) &&
(inc <= bdisp_v_filter[i].max))
break;
return bdisp_v_filter[i].paddr;
}
static int bdisp_hw_get_inc(u32 from, u32 to, u16 *inc)
{
u32 tmp;
if (!to)
return -EINVAL;
if (to == from) {
*inc = 1 << 10;
return 0;
}
tmp = (from << 10) / to;
if ((tmp > 0xFFFF) || (!tmp))
return -EINVAL;
*inc = (u16)tmp;
return 0;
}
static int bdisp_hw_get_hv_inc(struct bdisp_ctx *ctx, u16 *h_inc, u16 *v_inc)
{
u32 src_w, src_h, dst_w, dst_h;
src_w = ctx->src.crop.width;
src_h = ctx->src.crop.height;
dst_w = ctx->dst.crop.width;
dst_h = ctx->dst.crop.height;
if (bdisp_hw_get_inc(src_w, dst_w, h_inc) ||
bdisp_hw_get_inc(src_h, dst_h, v_inc)) {
dev_err(ctx->bdisp_dev->dev,
"scale factors failed (%dx%d)->(%dx%d)\n",
src_w, src_h, dst_w, dst_h);
return -EINVAL;
}
return 0;
}
static int bdisp_hw_get_op_cfg(struct bdisp_ctx *ctx, struct bdisp_op_cfg *c)
{
struct device *dev = ctx->bdisp_dev->dev;
struct bdisp_frame *src = &ctx->src;
struct bdisp_frame *dst = &ctx->dst;
if (src->width > MAX_SRC_WIDTH * MAX_VERTICAL_STRIDES) {
dev_err(dev, "Image width out of HW caps\n");
return -EINVAL;
}
c->wide = src->width > MAX_SRC_WIDTH;
c->hflip = ctx->hflip;
c->vflip = ctx->vflip;
c->src_interlaced = (src->field == V4L2_FIELD_INTERLACED);
c->src_nbp = src->fmt->nb_planes;
c->src_yuv = (src->fmt->pixelformat == V4L2_PIX_FMT_NV12) ||
(src->fmt->pixelformat == V4L2_PIX_FMT_YUV420);
c->src_420 = c->src_yuv;
c->dst_nbp = dst->fmt->nb_planes;
c->dst_yuv = (dst->fmt->pixelformat == V4L2_PIX_FMT_NV12) ||
(dst->fmt->pixelformat == V4L2_PIX_FMT_YUV420);
c->dst_420 = c->dst_yuv;
c->cconv = (c->src_yuv != c->dst_yuv);
if (bdisp_hw_get_hv_inc(ctx, &c->h_inc, &c->v_inc)) {
dev_err(dev, "Scale factor out of HW caps\n");
return -EINVAL;
}
if (c->src_interlaced)
c->v_inc /= 2;
if ((c->h_inc != (1 << 10)) || (c->v_inc != (1 << 10)))
c->scale = true;
else
c->scale = false;
return 0;
}
static u32 bdisp_hw_color_format(u32 pixelformat)
{
u32 ret;
switch (pixelformat) {
case V4L2_PIX_FMT_YUV420:
ret = (BDISP_YUV_3B << BLT_TTY_COL_SHIFT);
break;
case V4L2_PIX_FMT_NV12:
ret = (BDISP_NV12 << BLT_TTY_COL_SHIFT) | BLT_TTY_BIG_END;
break;
case V4L2_PIX_FMT_RGB565:
ret = (BDISP_RGB565 << BLT_TTY_COL_SHIFT);
break;
case V4L2_PIX_FMT_XBGR32:
ret = (BDISP_XRGB8888 << BLT_TTY_COL_SHIFT);
break;
case V4L2_PIX_FMT_RGB24:
ret = (BDISP_RGB888 << BLT_TTY_COL_SHIFT) | BLT_TTY_BIG_END;
break;
case V4L2_PIX_FMT_ABGR32:
default:
ret = (BDISP_ARGB8888 << BLT_TTY_COL_SHIFT) | BLT_TTY_ALPHA_R;
break;
}
return ret;
}
static void bdisp_hw_build_node(struct bdisp_ctx *ctx,
struct bdisp_op_cfg *cfg,
struct bdisp_node *node,
enum bdisp_target_plan t_plan, int src_x_offset)
{
struct bdisp_frame *src = &ctx->src;
struct bdisp_frame *dst = &ctx->dst;
u16 h_inc, v_inc, yh_inc, yv_inc;
struct v4l2_rect src_rect = src->crop;
struct v4l2_rect dst_rect = dst->crop;
int dst_x_offset;
s32 dst_width = dst->crop.width;
u32 src_fmt, dst_fmt;
const u32 *ivmx;
dev_dbg(ctx->bdisp_dev->dev, "%s\n", __func__);
memset(node, 0, sizeof(*node));
src_rect.left += src_x_offset;
src_rect.width -= src_x_offset;
src_rect.width = min_t(__s32, MAX_SRC_WIDTH, src_rect.width);
dst_x_offset = (src_x_offset * dst_width) / ctx->src.crop.width;
dst_rect.left += dst_x_offset;
dst_rect.width = (src_rect.width * dst_width) / ctx->src.crop.width;
src_fmt = src->fmt->pixelformat;
dst_fmt = dst->fmt->pixelformat;
node->nip = 0;
node->cic = BLT_CIC_ALL_GRP;
node->ack = BLT_ACK_BYPASS_S2S3;
switch (cfg->src_nbp) {
case 1:
node->ins = BLT_INS_S1_OFF | BLT_INS_S2_MEM | BLT_INS_S3_OFF;
break;
case 2:
node->ins = BLT_INS_S1_OFF | BLT_INS_S3_MEM;
if (t_plan == BDISP_Y)
node->ins |= BLT_INS_S2_CF;
else
node->ins |= BLT_INS_S2_MEM;
break;
case 3:
default:
node->ins = BLT_INS_S3_MEM;
if (t_plan == BDISP_Y)
node->ins |= BLT_INS_S2_CF | BLT_INS_S1_CF;
else
node->ins |= BLT_INS_S2_MEM | BLT_INS_S1_MEM;
break;
}
node->ins |= cfg->cconv ? BLT_INS_IVMX : 0;
node->ins |= (cfg->scale || cfg->src_420 || cfg->dst_420) ?
BLT_INS_SCALE : 0;
node->tba = (t_plan == BDISP_CBCR) ? dst->paddr[1] : dst->paddr[0];
node->tty = dst->bytesperline;
node->tty |= bdisp_hw_color_format(dst_fmt);
node->tty |= BLT_TTY_DITHER;
node->tty |= (t_plan == BDISP_CBCR) ? BLT_TTY_CHROMA : 0;
node->tty |= cfg->hflip ? BLT_TTY_HSO : 0;
node->tty |= cfg->vflip ? BLT_TTY_VSO : 0;
if (cfg->dst_420 && (t_plan == BDISP_CBCR)) {
dst_rect.height /= 2;
dst_rect.width /= 2;
dst_rect.left /= 2;
dst_rect.top /= 2;
dst_x_offset /= 2;
dst_width /= 2;
}
node->txy = cfg->vflip ? (dst_rect.height - 1) : dst_rect.top;
node->txy <<= 16;
node->txy |= cfg->hflip ? (dst_width - dst_x_offset - 1) :
dst_rect.left;
node->tsz = dst_rect.height << 16 | dst_rect.width;
if (cfg->src_interlaced) {
src_rect.top /= 2;
src_rect.height /= 2;
}
if (cfg->src_nbp == 1) {
node->s2ba = src->paddr[0];
node->s2ty = src->bytesperline;
if (cfg->src_interlaced)
node->s2ty *= 2;
node->s2ty |= bdisp_hw_color_format(src_fmt);
node->s2xy = src_rect.top << 16 | src_rect.left;
node->s2sz = src_rect.height << 16 | src_rect.width;
} else {
if (cfg->src_420) {
src_rect.top /= 2;
src_rect.left /= 2;
src_rect.width /= 2;
src_rect.height /= 2;
}
node->s2ba = src->paddr[1];
node->s2ty = src->bytesperline;
if (cfg->src_nbp == 3)
node->s2ty /= 2;
if (cfg->src_interlaced)
node->s2ty *= 2;
node->s2ty |= bdisp_hw_color_format(src_fmt);
node->s2xy = src_rect.top << 16 | src_rect.left;
node->s2sz = src_rect.height << 16 | src_rect.width;
if (cfg->src_nbp == 3) {
node->s1ba = src->paddr[2];
node->s1ty = node->s2ty;
node->s1xy = node->s2xy;
}
node->s3ba = src->paddr[0];
node->s3ty = src->bytesperline;
if (cfg->src_interlaced)
node->s3ty *= 2;
node->s3ty |= bdisp_hw_color_format(src_fmt);
if ((t_plan != BDISP_CBCR) && cfg->src_420) {
node->s3xy = node->s2xy * 2;
node->s3sz = node->s2sz * 2;
} else {
node->s3ty |= BLT_S3TY_BLANK_ACC;
node->s3xy = node->s2xy;
node->s3sz = node->s2sz;
}
}
if (node->ins & BLT_INS_SCALE) {
bool skip_y = (t_plan == BDISP_CBCR) && !cfg->src_yuv;
if (cfg->scale) {
node->fctl = BLT_FCTL_HV_SCALE;
if (!skip_y)
node->fctl |= BLT_FCTL_Y_HV_SCALE;
} else {
node->fctl = BLT_FCTL_HV_SAMPLE;
if (!skip_y)
node->fctl |= BLT_FCTL_Y_HV_SAMPLE;
}
h_inc = cfg->h_inc;
v_inc = cfg->v_inc;
if (!cfg->src_420 && cfg->dst_420 && (t_plan == BDISP_CBCR)) {
h_inc *= 2;
v_inc *= 2;
} else if (cfg->src_420 && !cfg->dst_420) {
h_inc /= 2;
v_inc /= 2;
}
node->rsf = v_inc << 16 | h_inc;
node->rzi = BLT_RZI_DEFAULT;
node->hfp = bdisp_hw_get_hf_addr(h_inc);
node->vfp = bdisp_hw_get_vf_addr(v_inc);
if (!skip_y) {
yh_inc = cfg->h_inc;
yv_inc = cfg->v_inc;
node->y_rsf = yv_inc << 16 | yh_inc;
node->y_rzi = BLT_RZI_DEFAULT;
node->y_hfp = bdisp_hw_get_hf_addr(yh_inc);
node->y_vfp = bdisp_hw_get_vf_addr(yv_inc);
}
}
if (cfg->cconv) {
ivmx = cfg->src_yuv ? bdisp_yuv_to_rgb : bdisp_rgb_to_yuv;
node->ivmx0 = ivmx[0];
node->ivmx1 = ivmx[1];
node->ivmx2 = ivmx[2];
node->ivmx3 = ivmx[3];
}
}
static int bdisp_hw_build_all_nodes(struct bdisp_ctx *ctx)
{
struct bdisp_op_cfg cfg;
unsigned int i, nid = 0;
int src_x_offset = 0;
for (i = 0; i < MAX_NB_NODE; i++)
if (!ctx->node[i]) {
dev_err(ctx->bdisp_dev->dev, "node %d is null\n", i);
return -EINVAL;
}
if (bdisp_hw_get_op_cfg(ctx, &cfg))
return -EINVAL;
for (i = 0; i < MAX_VERTICAL_STRIDES; i++) {
bdisp_hw_build_node(ctx, &cfg, ctx->node[nid],
cfg.dst_nbp == 1 ? BDISP_RGB : BDISP_Y,
src_x_offset);
if (nid)
ctx->node[nid - 1]->nip = ctx->node_paddr[nid];
nid++;
if (cfg.dst_nbp > 1) {
bdisp_hw_build_node(ctx, &cfg, ctx->node[nid],
BDISP_CBCR, src_x_offset);
ctx->node[nid - 1]->nip = ctx->node_paddr[nid];
nid++;
}
src_x_offset += MAX_SRC_WIDTH;
if (src_x_offset >= ctx->src.crop.width)
break;
}
ctx->node[nid - 1]->nip = 0;
return 0;
}
static void bdisp_hw_save_request(struct bdisp_ctx *ctx)
{
struct bdisp_node **copy_node = ctx->bdisp_dev->dbg.copy_node;
struct bdisp_request *request = &ctx->bdisp_dev->dbg.copy_request;
struct bdisp_node **node = ctx->node;
int i;
request->src = ctx->src;
request->dst = ctx->dst;
request->hflip = ctx->hflip;
request->vflip = ctx->vflip;
request->nb_req++;
for (i = 0; i < MAX_NB_NODE; i++) {
if (!copy_node[i]) {
copy_node[i] = devm_kzalloc(ctx->bdisp_dev->dev,
sizeof(*copy_node[i]),
GFP_KERNEL);
if (!copy_node[i])
return;
}
*copy_node[i] = *node[i];
}
}
int bdisp_hw_update(struct bdisp_ctx *ctx)
{
int ret;
struct bdisp_dev *bdisp = ctx->bdisp_dev;
struct device *dev = bdisp->dev;
unsigned int node_id;
dev_dbg(dev, "%s\n", __func__);
ret = bdisp_hw_build_all_nodes(ctx);
if (ret) {
dev_err(dev, "cannot build nodes (%d)\n", ret);
return ret;
}
bdisp_hw_save_request(ctx);
writel(BLT_AQ1_CTL_CFG, bdisp->regs + BLT_AQ1_CTL);
writel(BLT_ITS_AQ1_LNA, bdisp->regs + BLT_ITM0);
writel(ctx->node_paddr[0], bdisp->regs + BLT_AQ1_IP);
for (node_id = 0; node_id < MAX_NB_NODE - 1; node_id++) {
if (!ctx->node[node_id]->nip)
break;
}
writel(ctx->node_paddr[node_id], bdisp->regs + BLT_AQ1_LNA);
return 0;
}
