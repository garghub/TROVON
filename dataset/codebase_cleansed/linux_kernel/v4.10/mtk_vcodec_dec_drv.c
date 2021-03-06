static void wake_up_ctx(struct mtk_vcodec_ctx *ctx)
{
ctx->int_cond = 1;
wake_up_interruptible(&ctx->queue);
}
static irqreturn_t mtk_vcodec_dec_irq_handler(int irq, void *priv)
{
struct mtk_vcodec_dev *dev = priv;
struct mtk_vcodec_ctx *ctx;
u32 cg_status = 0;
unsigned int dec_done_status = 0;
void __iomem *vdec_misc_addr = dev->reg_base[VDEC_MISC] +
VDEC_IRQ_CFG_REG;
ctx = mtk_vcodec_get_curr_ctx(dev);
cg_status = readl(dev->reg_base[0]);
if ((cg_status & VDEC_HW_ACTIVE) != 0) {
mtk_v4l2_err("DEC ISR, VDEC active is not 0x0 (0x%08x)",
cg_status);
return IRQ_HANDLED;
}
dec_done_status = readl(vdec_misc_addr);
ctx->irq_status = dec_done_status;
if ((dec_done_status & MTK_VDEC_IRQ_STATUS_DEC_SUCCESS) !=
MTK_VDEC_IRQ_STATUS_DEC_SUCCESS)
return IRQ_HANDLED;
writel((readl(vdec_misc_addr) | VDEC_IRQ_CFG),
dev->reg_base[VDEC_MISC] + VDEC_IRQ_CFG_REG);
writel((readl(vdec_misc_addr) & ~VDEC_IRQ_CLR),
dev->reg_base[VDEC_MISC] + VDEC_IRQ_CFG_REG);
wake_up_ctx(ctx);
mtk_v4l2_debug(3,
"mtk_vcodec_dec_irq_handler :wake up ctx %d, dec_done_status=%x",
ctx->id, dec_done_status);
return IRQ_HANDLED;
}
static void mtk_vcodec_dec_reset_handler(void *priv)
{
struct mtk_vcodec_dev *dev = priv;
struct mtk_vcodec_ctx *ctx;
mtk_v4l2_err("Watchdog timeout!!");
mutex_lock(&dev->dev_mutex);
list_for_each_entry(ctx, &dev->ctx_list, list) {
ctx->state = MTK_STATE_ABORT;
mtk_v4l2_debug(0, "[%d] Change to state MTK_STATE_ERROR",
ctx->id);
}
mutex_unlock(&dev->dev_mutex);
}
static int fops_vcodec_open(struct file *file)
{
struct mtk_vcodec_dev *dev = video_drvdata(file);
struct mtk_vcodec_ctx *ctx = NULL;
int ret = 0;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mutex_lock(&dev->dev_mutex);
ctx->id = dev->id_counter++;
v4l2_fh_init(&ctx->fh, video_devdata(file));
file->private_data = &ctx->fh;
v4l2_fh_add(&ctx->fh);
INIT_LIST_HEAD(&ctx->list);
ctx->dev = dev;
init_waitqueue_head(&ctx->queue);
mutex_init(&ctx->lock);
ctx->type = MTK_INST_DECODER;
ret = mtk_vcodec_dec_ctrls_setup(ctx);
if (ret) {
mtk_v4l2_err("Failed to setup mt vcodec controls");
goto err_ctrls_setup;
}
ctx->m2m_ctx = v4l2_m2m_ctx_init(dev->m2m_dev_dec, ctx,
&mtk_vcodec_dec_queue_init);
if (IS_ERR((__force void *)ctx->m2m_ctx)) {
ret = PTR_ERR((__force void *)ctx->m2m_ctx);
mtk_v4l2_err("Failed to v4l2_m2m_ctx_init() (%d)",
ret);
goto err_m2m_ctx_init;
}
mtk_vcodec_dec_set_default_params(ctx);
if (v4l2_fh_is_singular(&ctx->fh)) {
mtk_vcodec_dec_pw_on(&dev->pm);
ret = vpu_load_firmware(dev->vpu_plat_dev);
if (ret < 0) {
mtk_v4l2_err("vpu_load_firmware failed!");
goto err_load_fw;
}
dev->dec_capability =
vpu_get_vdec_hw_capa(dev->vpu_plat_dev);
mtk_v4l2_debug(0, "decoder capability %x", dev->dec_capability);
}
list_add(&ctx->list, &dev->ctx_list);
mutex_unlock(&dev->dev_mutex);
mtk_v4l2_debug(0, "%s decoder [%d]", dev_name(&dev->plat_dev->dev),
ctx->id);
return ret;
err_load_fw:
v4l2_m2m_ctx_release(ctx->m2m_ctx);
err_m2m_ctx_init:
v4l2_ctrl_handler_free(&ctx->ctrl_hdl);
err_ctrls_setup:
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
kfree(ctx);
mutex_unlock(&dev->dev_mutex);
return ret;
}
static int fops_vcodec_release(struct file *file)
{
struct mtk_vcodec_dev *dev = video_drvdata(file);
struct mtk_vcodec_ctx *ctx = fh_to_ctx(file->private_data);
mtk_v4l2_debug(0, "[%d] decoder", ctx->id);
mutex_lock(&dev->dev_mutex);
v4l2_m2m_ctx_release(ctx->m2m_ctx);
mtk_vcodec_dec_release(ctx);
if (v4l2_fh_is_singular(&ctx->fh))
mtk_vcodec_dec_pw_off(&dev->pm);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
v4l2_ctrl_handler_free(&ctx->ctrl_hdl);
list_del_init(&ctx->list);
kfree(ctx);
mutex_unlock(&dev->dev_mutex);
return 0;
}
static int mtk_vcodec_probe(struct platform_device *pdev)
{
struct mtk_vcodec_dev *dev;
struct video_device *vfd_dec;
struct resource *res;
int i, ret;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
INIT_LIST_HEAD(&dev->ctx_list);
dev->plat_dev = pdev;
dev->vpu_plat_dev = vpu_get_plat_device(dev->plat_dev);
if (dev->vpu_plat_dev == NULL) {
mtk_v4l2_err("[VPU] vpu device in not ready");
return -EPROBE_DEFER;
}
vpu_wdt_reg_handler(dev->vpu_plat_dev, mtk_vcodec_dec_reset_handler,
dev, VPU_RST_DEC);
ret = mtk_vcodec_init_dec_pm(dev);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to get mt vcodec clock source");
return ret;
}
for (i = 0; i < NUM_MAX_VDEC_REG_BASE; i++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (res == NULL) {
dev_err(&pdev->dev, "get memory resource failed.");
ret = -ENXIO;
goto err_res;
}
dev->reg_base[i] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR((__force void *)dev->reg_base[i])) {
ret = PTR_ERR((__force void *)dev->reg_base[i]);
goto err_res;
}
mtk_v4l2_debug(2, "reg[%d] base=%p", i, dev->reg_base[i]);
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(&pdev->dev, "failed to get irq resource");
ret = -ENOENT;
goto err_res;
}
dev->dec_irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(&pdev->dev, dev->dec_irq,
mtk_vcodec_dec_irq_handler, 0, pdev->name, dev);
if (ret) {
dev_err(&pdev->dev, "Failed to install dev->dec_irq %d (%d)",
dev->dec_irq,
ret);
goto err_res;
}
disable_irq(dev->dec_irq);
mutex_init(&dev->dec_mutex);
mutex_init(&dev->dev_mutex);
spin_lock_init(&dev->irqlock);
snprintf(dev->v4l2_dev.name, sizeof(dev->v4l2_dev.name), "%s",
"[/MTK_V4L2_VDEC]");
ret = v4l2_device_register(&pdev->dev, &dev->v4l2_dev);
if (ret) {
mtk_v4l2_err("v4l2_device_register err=%d", ret);
goto err_res;
}
init_waitqueue_head(&dev->queue);
vfd_dec = video_device_alloc();
if (!vfd_dec) {
mtk_v4l2_err("Failed to allocate video device");
ret = -ENOMEM;
goto err_dec_alloc;
}
vfd_dec->fops = &mtk_vcodec_fops;
vfd_dec->ioctl_ops = &mtk_vdec_ioctl_ops;
vfd_dec->release = video_device_release;
vfd_dec->lock = &dev->dev_mutex;
vfd_dec->v4l2_dev = &dev->v4l2_dev;
vfd_dec->vfl_dir = VFL_DIR_M2M;
vfd_dec->device_caps = V4L2_CAP_VIDEO_M2M_MPLANE |
V4L2_CAP_STREAMING;
snprintf(vfd_dec->name, sizeof(vfd_dec->name), "%s",
MTK_VCODEC_DEC_NAME);
video_set_drvdata(vfd_dec, dev);
dev->vfd_dec = vfd_dec;
platform_set_drvdata(pdev, dev);
dev->m2m_dev_dec = v4l2_m2m_init(&mtk_vdec_m2m_ops);
if (IS_ERR((__force void *)dev->m2m_dev_dec)) {
mtk_v4l2_err("Failed to init mem2mem dec device");
ret = PTR_ERR((__force void *)dev->m2m_dev_dec);
goto err_dec_mem_init;
}
dev->decode_workqueue =
alloc_ordered_workqueue(MTK_VCODEC_DEC_NAME,
WQ_MEM_RECLAIM | WQ_FREEZABLE);
if (!dev->decode_workqueue) {
mtk_v4l2_err("Failed to create decode workqueue");
ret = -EINVAL;
goto err_event_workq;
}
ret = video_register_device(vfd_dec, VFL_TYPE_GRABBER, 0);
if (ret) {
mtk_v4l2_err("Failed to register video device");
goto err_dec_reg;
}
mtk_v4l2_debug(0, "decoder registered as /dev/video%d",
vfd_dec->num);
return 0;
err_dec_reg:
destroy_workqueue(dev->decode_workqueue);
err_event_workq:
v4l2_m2m_release(dev->m2m_dev_dec);
err_dec_mem_init:
video_unregister_device(vfd_dec);
err_dec_alloc:
v4l2_device_unregister(&dev->v4l2_dev);
err_res:
mtk_vcodec_release_dec_pm(dev);
return ret;
}
static int mtk_vcodec_dec_remove(struct platform_device *pdev)
{
struct mtk_vcodec_dev *dev = platform_get_drvdata(pdev);
flush_workqueue(dev->decode_workqueue);
destroy_workqueue(dev->decode_workqueue);
if (dev->m2m_dev_dec)
v4l2_m2m_release(dev->m2m_dev_dec);
if (dev->vfd_dec)
video_unregister_device(dev->vfd_dec);
v4l2_device_unregister(&dev->v4l2_dev);
mtk_vcodec_release_dec_pm(dev);
return 0;
}
