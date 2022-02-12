int rcar_du_get(struct rcar_du_device *rcdu)
{
int ret;
if (rcdu->use_count)
goto done;
ret = clk_prepare_enable(rcdu->clock);
if (ret < 0)
return ret;
rcar_du_write(rcdu, DEFR, DEFR_CODE | DEFR_DEFE);
rcar_du_write(rcdu, DEFR2, DEFR2_CODE | DEFR2_DEFE2G);
rcar_du_write(rcdu, DEFR3, DEFR3_CODE | DEFR3_DEFE3);
rcar_du_write(rcdu, DEFR4, DEFR4_CODE);
rcar_du_write(rcdu, DEFR5, DEFR5_CODE | DEFR5_DEFE5);
rcar_du_write(rcdu, DORCR, DORCR_PG1D_DS1 | DORCR_DPRS);
done:
rcdu->use_count++;
return 0;
}
void rcar_du_put(struct rcar_du_device *rcdu)
{
if (--rcdu->use_count)
return;
clk_disable_unprepare(rcdu->clock);
}
static int rcar_du_unload(struct drm_device *dev)
{
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
drm_irq_uninstall(dev);
dev->dev_private = NULL;
return 0;
}
static int rcar_du_load(struct drm_device *dev, unsigned long flags)
{
struct platform_device *pdev = dev->platformdev;
struct rcar_du_platform_data *pdata = pdev->dev.platform_data;
struct rcar_du_device *rcdu;
struct resource *ioarea;
struct resource *mem;
int ret;
if (pdata == NULL) {
dev_err(dev->dev, "no platform data\n");
return -ENODEV;
}
rcdu = devm_kzalloc(&pdev->dev, sizeof(*rcdu), GFP_KERNEL);
if (rcdu == NULL) {
dev_err(dev->dev, "failed to allocate private data\n");
return -ENOMEM;
}
rcdu->dev = &pdev->dev;
rcdu->pdata = pdata;
rcdu->ddev = dev;
dev->dev_private = rcdu;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem == NULL) {
dev_err(&pdev->dev, "failed to get memory resource\n");
return -EINVAL;
}
ioarea = devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem), pdev->name);
if (ioarea == NULL) {
dev_err(&pdev->dev, "failed to request memory region\n");
return -EBUSY;
}
rcdu->mmio = devm_ioremap_nocache(&pdev->dev, ioarea->start,
resource_size(ioarea));
if (rcdu->mmio == NULL) {
dev_err(&pdev->dev, "failed to remap memory resource\n");
return -ENOMEM;
}
rcdu->clock = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rcdu->clock)) {
dev_err(&pdev->dev, "failed to get clock\n");
return -ENOENT;
}
ret = rcar_du_modeset_init(rcdu);
if (ret < 0) {
dev_err(&pdev->dev, "failed to initialize DRM/KMS\n");
goto done;
}
ret = drm_vblank_init(dev, (1 << rcdu->num_crtcs) - 1);
if (ret < 0) {
dev_err(&pdev->dev, "failed to initialize vblank\n");
goto done;
}
ret = drm_irq_install(dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to install IRQ handler\n");
goto done;
}
platform_set_drvdata(pdev, rcdu);
done:
if (ret)
rcar_du_unload(dev);
return ret;
}
static void rcar_du_preclose(struct drm_device *dev, struct drm_file *file)
{
struct rcar_du_device *rcdu = dev->dev_private;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rcdu->crtcs); ++i)
rcar_du_crtc_cancel_page_flip(&rcdu->crtcs[i], file);
}
static irqreturn_t rcar_du_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct rcar_du_device *rcdu = dev->dev_private;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rcdu->crtcs); ++i)
rcar_du_crtc_irq(&rcdu->crtcs[i]);
return IRQ_HANDLED;
}
static int rcar_du_enable_vblank(struct drm_device *dev, int crtc)
{
struct rcar_du_device *rcdu = dev->dev_private;
rcar_du_crtc_enable_vblank(&rcdu->crtcs[crtc], true);
return 0;
}
static void rcar_du_disable_vblank(struct drm_device *dev, int crtc)
{
struct rcar_du_device *rcdu = dev->dev_private;
rcar_du_crtc_enable_vblank(&rcdu->crtcs[crtc], false);
}
static int rcar_du_pm_suspend(struct device *dev)
{
struct rcar_du_device *rcdu = dev_get_drvdata(dev);
drm_kms_helper_poll_disable(rcdu->ddev);
return 0;
}
static int rcar_du_pm_resume(struct device *dev)
{
struct rcar_du_device *rcdu = dev_get_drvdata(dev);
drm_kms_helper_poll_enable(rcdu->ddev);
return 0;
}
static int rcar_du_probe(struct platform_device *pdev)
{
return drm_platform_init(&rcar_du_driver, pdev);
}
static int rcar_du_remove(struct platform_device *pdev)
{
drm_platform_exit(&rcar_du_driver, pdev);
return 0;
}
