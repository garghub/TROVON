static void meson_fb_output_poll_changed(struct drm_device *dev)
{
struct meson_drm *priv = dev->dev_private;
drm_fbdev_cma_hotplug_event(priv->fbdev);
}
static int meson_enable_vblank(struct drm_device *dev, unsigned int crtc)
{
struct meson_drm *priv = dev->dev_private;
meson_venc_enable_vsync(priv);
return 0;
}
static void meson_disable_vblank(struct drm_device *dev, unsigned int crtc)
{
struct meson_drm *priv = dev->dev_private;
meson_venc_disable_vsync(priv);
}
static irqreturn_t meson_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct meson_drm *priv = dev->dev_private;
(void)readl_relaxed(priv->io_base + _REG(VENC_INTFLAG));
meson_crtc_irq(priv);
return IRQ_HANDLED;
}
static bool meson_vpu_has_available_connectors(struct device *dev)
{
struct device_node *ep, *remote;
for_each_endpoint_of_node(dev->of_node, ep) {
remote = of_graph_get_remote_port(ep);
if (remote)
return true;
}
return false;
}
static int meson_drv_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct meson_drm *priv;
struct drm_device *drm;
struct resource *res;
void __iomem *regs;
int ret;
if (!meson_vpu_has_available_connectors(dev)) {
dev_err(dev, "No output connector available\n");
return -ENODEV;
}
drm = drm_dev_alloc(&meson_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto free_drm;
}
drm->dev_private = priv;
priv->drm = drm;
priv->dev = dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "vpu");
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
priv->io_base = regs;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "hhi");
regs = devm_ioremap(dev, res->start, resource_size(res));
if (!regs)
return -EADDRNOTAVAIL;
priv->hhi = devm_regmap_init_mmio(dev, regs,
&meson_regmap_config);
if (IS_ERR(priv->hhi)) {
dev_err(&pdev->dev, "Couldn't create the HHI regmap\n");
return PTR_ERR(priv->hhi);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dmc");
regs = devm_ioremap(dev, res->start, resource_size(res));
if (!regs)
return -EADDRNOTAVAIL;
priv->dmc = devm_regmap_init_mmio(dev, regs,
&meson_regmap_config);
if (IS_ERR(priv->dmc)) {
dev_err(&pdev->dev, "Couldn't create the DMC regmap\n");
return PTR_ERR(priv->dmc);
}
priv->vsync_irq = platform_get_irq(pdev, 0);
drm_vblank_init(drm, 1);
drm_mode_config_init(drm);
ret = meson_venc_cvbs_create(priv);
if (ret)
goto free_drm;
meson_venc_init(priv);
meson_vpp_init(priv);
meson_viu_init(priv);
ret = meson_plane_create(priv);
if (ret)
goto free_drm;
ret = meson_crtc_create(priv);
if (ret)
goto free_drm;
ret = drm_irq_install(drm, priv->vsync_irq);
if (ret)
goto free_drm;
drm_mode_config_reset(drm);
drm->mode_config.max_width = 8192;
drm->mode_config.max_height = 8192;
drm->mode_config.funcs = &meson_mode_config_funcs;
priv->fbdev = drm_fbdev_cma_init(drm, 32,
drm->mode_config.num_crtc,
drm->mode_config.num_connector);
if (IS_ERR(priv->fbdev)) {
ret = PTR_ERR(priv->fbdev);
goto free_drm;
}
drm_kms_helper_poll_init(drm);
platform_set_drvdata(pdev, priv);
ret = drm_dev_register(drm, 0);
if (ret)
goto free_drm;
return 0;
free_drm:
drm_dev_unref(drm);
return ret;
}
static int meson_drv_remove(struct platform_device *pdev)
{
struct drm_device *drm = dev_get_drvdata(&pdev->dev);
struct meson_drm *priv = drm->dev_private;
drm_dev_unregister(drm);
drm_kms_helper_poll_fini(drm);
drm_fbdev_cma_fini(priv->fbdev);
drm_mode_config_cleanup(drm);
drm_vblank_cleanup(drm);
drm_dev_unref(drm);
return 0;
}
