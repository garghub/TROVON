static void rcar_du_lastclose(struct drm_device *dev)
{
struct rcar_du_device *rcdu = dev->dev_private;
drm_fbdev_cma_restore_mode(rcdu->fbdev);
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
static int rcar_du_remove(struct platform_device *pdev)
{
struct rcar_du_device *rcdu = platform_get_drvdata(pdev);
struct drm_device *ddev = rcdu->ddev;
drm_dev_unregister(ddev);
if (rcdu->fbdev)
drm_fbdev_cma_fini(rcdu->fbdev);
drm_kms_helper_poll_fini(ddev);
drm_mode_config_cleanup(ddev);
drm_dev_unref(ddev);
return 0;
}
static int rcar_du_probe(struct platform_device *pdev)
{
struct rcar_du_device *rcdu;
struct drm_device *ddev;
struct resource *mem;
int ret;
rcdu = devm_kzalloc(&pdev->dev, sizeof(*rcdu), GFP_KERNEL);
if (rcdu == NULL)
return -ENOMEM;
rcdu->dev = &pdev->dev;
rcdu->info = of_device_get_match_data(rcdu->dev);
platform_set_drvdata(pdev, rcdu);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rcdu->mmio = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rcdu->mmio))
return PTR_ERR(rcdu->mmio);
ddev = drm_dev_alloc(&rcar_du_driver, &pdev->dev);
if (IS_ERR(ddev))
return PTR_ERR(ddev);
rcdu->ddev = ddev;
ddev->dev_private = rcdu;
ret = rcar_du_modeset_init(rcdu);
if (ret < 0) {
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev,
"failed to initialize DRM/KMS (%d)\n", ret);
goto error;
}
ddev->irq_enabled = 1;
ret = drm_dev_register(ddev, 0);
if (ret)
goto error;
DRM_INFO("Device %s probed\n", dev_name(&pdev->dev));
return 0;
error:
rcar_du_remove(pdev);
return ret;
}
