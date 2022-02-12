static int pl111_modeset_init(struct drm_device *dev)
{
struct drm_mode_config *mode_config;
struct pl111_drm_dev_private *priv = dev->dev_private;
int ret = 0;
drm_mode_config_init(dev);
mode_config = &dev->mode_config;
mode_config->funcs = &mode_config_funcs;
mode_config->min_width = 1;
mode_config->max_width = 1024;
mode_config->min_height = 1;
mode_config->max_height = 768;
ret = pl111_connector_init(dev);
if (ret) {
dev_err(dev->dev, "Failed to create pl111_drm_connector\n");
goto out_config;
}
if (!priv->connector.panel) {
dev_info(dev->dev,
"Disabling due to lack of DRM panel device.\n");
ret = -ENODEV;
goto out_config;
}
ret = pl111_display_init(dev);
if (ret != 0) {
dev_err(dev->dev, "Failed to init display\n");
goto out_config;
}
ret = drm_vblank_init(dev, 1);
if (ret != 0) {
dev_err(dev->dev, "Failed to init vblank\n");
goto out_config;
}
drm_mode_config_reset(dev);
priv->fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_connector);
drm_kms_helper_poll_init(dev);
goto finish;
out_config:
drm_mode_config_cleanup(dev);
finish:
return ret;
}
static void pl111_lastclose(struct drm_device *dev)
{
struct pl111_drm_dev_private *priv = dev->dev_private;
drm_fbdev_cma_restore_mode(priv->fbdev);
}
static int pl111_amba_probe(struct amba_device *amba_dev,
const struct amba_id *id)
{
struct device *dev = &amba_dev->dev;
struct pl111_drm_dev_private *priv;
struct drm_device *drm;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
drm = drm_dev_alloc(&pl111_drm_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
amba_set_drvdata(amba_dev, drm);
priv->drm = drm;
drm->dev_private = priv;
priv->regs = devm_ioremap_resource(dev, &amba_dev->res);
if (IS_ERR(priv->regs)) {
dev_err(dev, "%s failed mmio\n", __func__);
return PTR_ERR(priv->regs);
}
writel(0, priv->regs + CLCD_PL111_IENB);
ret = devm_request_irq(dev, amba_dev->irq[0], pl111_irq, 0,
"pl111", priv);
if (ret != 0) {
dev_err(dev, "%s failed irq %d\n", __func__, ret);
return ret;
}
ret = pl111_modeset_init(drm);
if (ret != 0)
goto dev_unref;
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto dev_unref;
return 0;
dev_unref:
drm_dev_unref(drm);
return ret;
}
static int pl111_amba_remove(struct amba_device *amba_dev)
{
struct drm_device *drm = amba_get_drvdata(amba_dev);
struct pl111_drm_dev_private *priv = drm->dev_private;
drm_dev_unregister(drm);
if (priv->fbdev)
drm_fbdev_cma_fini(priv->fbdev);
drm_mode_config_cleanup(drm);
drm_dev_unref(drm);
return 0;
}
