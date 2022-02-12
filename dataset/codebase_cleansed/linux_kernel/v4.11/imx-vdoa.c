static irqreturn_t vdoa_irq_handler(int irq, void *data)
{
struct vdoa_data *vdoa = data;
struct vdoa_ctx *curr_ctx;
u32 val;
writel(0, vdoa->regs + VDOAIE);
curr_ctx = vdoa->curr_ctx;
if (!curr_ctx) {
dev_dbg(vdoa->dev,
"Instance released before the end of transaction\n");
return IRQ_HANDLED;
}
val = readl(vdoa->regs + VDOAIST);
writel(val, vdoa->regs + VDOAIST);
if (val & VDOAIST_TERR) {
val = readl(vdoa->regs + VDOASR) & VDOASR_ERRW;
dev_err(vdoa->dev, "AXI %s error\n", val ? "write" : "read");
} else if (!(val & VDOAIST_EOT)) {
dev_warn(vdoa->dev, "Spurious interrupt\n");
}
complete(&curr_ctx->completion);
return IRQ_HANDLED;
}
void vdoa_device_run(struct vdoa_ctx *ctx, dma_addr_t dst, dma_addr_t src)
{
struct vdoa_q_data *src_q_data, *dst_q_data;
struct vdoa_data *vdoa = ctx->vdoa;
u32 val;
vdoa->curr_ctx = ctx;
src_q_data = &ctx->q_data[V4L2_M2M_SRC];
dst_q_data = &ctx->q_data[V4L2_M2M_DST];
if (dst_q_data->pixelformat == V4L2_PIX_FMT_YUYV)
val = VDOAC_PFS;
else
val = 0;
writel(val, vdoa->regs + VDOAC);
writel(dst_q_data->height << 16 | dst_q_data->width,
vdoa->regs + VDOAFP);
val = dst;
writel(val, vdoa->regs + VDOAIEBA00);
writel(src_q_data->bytesperline << 16 | dst_q_data->bytesperline,
vdoa->regs + VDOASL);
if (dst_q_data->pixelformat == V4L2_PIX_FMT_NV12 ||
dst_q_data->pixelformat == V4L2_PIX_FMT_NV21)
val = dst_q_data->bytesperline * dst_q_data->height;
else
val = 0;
writel(val, vdoa->regs + VDOAIUBO);
val = src;
writel(val, vdoa->regs + VDOAVEBA0);
val = round_up(src_q_data->bytesperline * src_q_data->height, 4096);
writel(val, vdoa->regs + VDOAVUBO);
writel(VDOAIE_EITERR | VDOAIE_EIEOT, vdoa->regs + VDOAIE);
writel(VDOASRR_START, vdoa->regs + VDOASRR);
}
int vdoa_wait_for_completion(struct vdoa_ctx *ctx)
{
struct vdoa_data *vdoa = ctx->vdoa;
if (!wait_for_completion_timeout(&ctx->completion,
msecs_to_jiffies(300))) {
dev_err(vdoa->dev,
"Timeout waiting for transfer result\n");
return -ETIMEDOUT;
}
return 0;
}
struct vdoa_ctx *vdoa_context_create(struct vdoa_data *vdoa)
{
struct vdoa_ctx *ctx;
int err;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return NULL;
err = clk_prepare_enable(vdoa->vdoa_clk);
if (err) {
kfree(ctx);
return NULL;
}
init_completion(&ctx->completion);
ctx->vdoa = vdoa;
return ctx;
}
void vdoa_context_destroy(struct vdoa_ctx *ctx)
{
struct vdoa_data *vdoa = ctx->vdoa;
clk_disable_unprepare(vdoa->vdoa_clk);
kfree(ctx);
}
int vdoa_context_configure(struct vdoa_ctx *ctx,
unsigned int width, unsigned int height,
u32 pixelformat)
{
struct vdoa_q_data *src_q_data;
struct vdoa_q_data *dst_q_data;
if (width < 16 || width > 8192 || width % 16 != 0 ||
height < 16 || height > 4096 || height % 16 != 0)
return -EINVAL;
if (pixelformat != V4L2_PIX_FMT_YUYV &&
pixelformat != V4L2_PIX_FMT_NV12)
return -EINVAL;
if (!ctx)
return 0;
src_q_data = &ctx->q_data[V4L2_M2M_SRC];
dst_q_data = &ctx->q_data[V4L2_M2M_DST];
src_q_data->width = width;
src_q_data->height = height;
src_q_data->bytesperline = width;
src_q_data->sizeimage =
round_up(src_q_data->bytesperline * height, 4096) +
src_q_data->bytesperline * height / 2;
dst_q_data->width = width;
dst_q_data->height = height;
dst_q_data->pixelformat = pixelformat;
switch (pixelformat) {
case V4L2_PIX_FMT_YUYV:
dst_q_data->bytesperline = width * 2;
dst_q_data->sizeimage = dst_q_data->bytesperline * height;
break;
case V4L2_PIX_FMT_NV12:
default:
dst_q_data->bytesperline = width;
dst_q_data->sizeimage =
dst_q_data->bytesperline * height * 3 / 2;
break;
}
return 0;
}
static int vdoa_probe(struct platform_device *pdev)
{
struct vdoa_data *vdoa;
struct resource *res;
dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
vdoa = devm_kzalloc(&pdev->dev, sizeof(*vdoa), GFP_KERNEL);
if (!vdoa)
return -ENOMEM;
vdoa->dev = &pdev->dev;
vdoa->vdoa_clk = devm_clk_get(vdoa->dev, NULL);
if (IS_ERR(vdoa->vdoa_clk)) {
dev_err(vdoa->dev, "Failed to get clock\n");
return PTR_ERR(vdoa->vdoa_clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
vdoa->regs = devm_ioremap_resource(vdoa->dev, res);
if (IS_ERR(vdoa->regs))
return PTR_ERR(vdoa->regs);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
vdoa->irq = devm_request_threaded_irq(&pdev->dev, res->start, NULL,
vdoa_irq_handler, IRQF_ONESHOT,
"vdoa", vdoa);
if (vdoa->irq < 0) {
dev_err(vdoa->dev, "Failed to get irq\n");
return vdoa->irq;
}
platform_set_drvdata(pdev, vdoa);
return 0;
}
static int vdoa_remove(struct platform_device *pdev)
{
return 0;
}
