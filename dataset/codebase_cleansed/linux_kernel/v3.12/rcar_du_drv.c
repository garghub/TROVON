static int rcar_du_unload(struct drm_device *dev)
{
struct rcar_du_device *rcdu = dev->dev_private;
if (rcdu->fbdev)
drm_fbdev_cma_fini(rcdu->fbdev);
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
dev->irq_enabled = 0;
dev->dev_private = NULL;
return 0;
}
static int rcar_du_load(struct drm_device *dev, unsigned long flags)
{
struct platform_device *pdev = dev->platformdev;
struct rcar_du_platform_data *pdata = pdev->dev.platform_data;
struct rcar_du_device *rcdu;
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
rcdu->info = (struct rcar_du_device_info *)pdev->id_entry->driver_data;
rcdu->ddev = dev;
dev->dev_private = rcdu;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rcdu->mmio = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rcdu->mmio))
return PTR_ERR(rcdu->mmio);
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
dev->irq_enabled = 1;
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
for (i = 0; i < rcdu->num_crtcs; ++i)
rcar_du_crtc_cancel_page_flip(&rcdu->crtcs[i], file);
}
static void rcar_du_lastclose(struct drm_device *dev)
{
struct rcar_du_device *rcdu = dev->dev_private;
drm_fbdev_cma_restore_mode(rcdu->fbdev);
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
