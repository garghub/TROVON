static int fsl_dcu_drm_irq_init(struct drm_device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int value;
int ret;
ret = drm_irq_install(dev, fsl_dev->irq);
if (ret < 0)
dev_err(dev->dev, "failed to install IRQ handler\n");
ret = regmap_write(fsl_dev->regmap, DCU_INT_STATUS, 0);
if (ret)
dev_err(dev->dev, "set DCU_INT_STATUS failed\n");
ret = regmap_read(fsl_dev->regmap, DCU_INT_MASK, &value);
if (ret)
dev_err(dev->dev, "read DCU_INT_MASK failed\n");
value &= DCU_INT_MASK_VBLANK;
ret = regmap_write(fsl_dev->regmap, DCU_INT_MASK, value);
if (ret)
dev_err(dev->dev, "set DCU_INT_MASK failed\n");
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
dev_err(dev->dev, "set DCU_UPDATE_MODE failed\n");
return ret;
}
static int fsl_dcu_load(struct drm_device *drm, unsigned long flags)
{
struct device *dev = drm->dev;
struct fsl_dcu_drm_device *fsl_dev = drm->dev_private;
int ret;
ret = fsl_dcu_drm_modeset_init(fsl_dev);
if (ret < 0) {
dev_err(dev, "failed to initialize mode setting\n");
return ret;
}
ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
if (ret < 0) {
dev_err(dev, "failed to initialize vblank\n");
goto done;
}
drm->vblank_disable_allowed = true;
ret = fsl_dcu_drm_irq_init(drm);
if (ret < 0)
goto done;
drm->irq_enabled = true;
fsl_dcu_fbdev_init(drm);
return 0;
done:
if (ret) {
drm_mode_config_cleanup(drm);
drm_vblank_cleanup(drm);
drm_irq_uninstall(drm);
drm->dev_private = NULL;
}
return ret;
}
static int fsl_dcu_unload(struct drm_device *dev)
{
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
drm_irq_uninstall(dev);
dev->dev_private = NULL;
return 0;
}
static void fsl_dcu_drm_preclose(struct drm_device *dev, struct drm_file *file)
{
}
static irqreturn_t fsl_dcu_drm_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int int_status;
int ret;
ret = regmap_read(fsl_dev->regmap, DCU_INT_STATUS, &int_status);
if (ret)
dev_err(dev->dev, "set DCU_INT_STATUS failed\n");
if (int_status & DCU_INT_STATUS_VBLANK)
drm_handle_vblank(dev, 0);
ret = regmap_write(fsl_dev->regmap, DCU_INT_STATUS, 0xffffffff);
if (ret)
dev_err(dev->dev, "set DCU_INT_STATUS failed\n");
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
dev_err(dev->dev, "set DCU_UPDATE_MODE failed\n");
return IRQ_HANDLED;
}
static int fsl_dcu_drm_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int value;
int ret;
ret = regmap_read(fsl_dev->regmap, DCU_INT_MASK, &value);
if (ret)
dev_err(dev->dev, "read DCU_INT_MASK failed\n");
value &= ~DCU_INT_MASK_VBLANK;
ret = regmap_write(fsl_dev->regmap, DCU_INT_MASK, value);
if (ret)
dev_err(dev->dev, "set DCU_INT_MASK failed\n");
return 0;
}
static void fsl_dcu_drm_disable_vblank(struct drm_device *dev,
unsigned int pipe)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int value;
int ret;
ret = regmap_read(fsl_dev->regmap, DCU_INT_MASK, &value);
if (ret)
dev_err(dev->dev, "read DCU_INT_MASK failed\n");
value |= DCU_INT_MASK_VBLANK;
ret = regmap_write(fsl_dev->regmap, DCU_INT_MASK, value);
if (ret)
dev_err(dev->dev, "set DCU_INT_MASK failed\n");
}
static int fsl_dcu_drm_pm_suspend(struct device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev_get_drvdata(dev);
if (!fsl_dev)
return 0;
drm_kms_helper_poll_disable(fsl_dev->drm);
regcache_cache_only(fsl_dev->regmap, true);
regcache_mark_dirty(fsl_dev->regmap);
clk_disable(fsl_dev->clk);
clk_unprepare(fsl_dev->clk);
return 0;
}
static int fsl_dcu_drm_pm_resume(struct device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev_get_drvdata(dev);
int ret;
if (!fsl_dev)
return 0;
ret = clk_enable(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to enable dcu clk\n");
clk_unprepare(fsl_dev->clk);
return ret;
}
ret = clk_prepare(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to prepare dcu clk\n");
return ret;
}
drm_kms_helper_poll_enable(fsl_dev->drm);
regcache_cache_only(fsl_dev->regmap, false);
regcache_sync(fsl_dev->regmap);
return 0;
}
static int fsl_dcu_drm_probe(struct platform_device *pdev)
{
struct fsl_dcu_drm_device *fsl_dev;
struct drm_device *drm;
struct device *dev = &pdev->dev;
struct resource *res;
void __iomem *base;
struct drm_driver *driver = &fsl_dcu_drm_driver;
const struct of_device_id *id;
int ret;
fsl_dev = devm_kzalloc(dev, sizeof(*fsl_dev), GFP_KERNEL);
if (!fsl_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "could not get memory IO resource\n");
return -ENODEV;
}
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
return ret;
}
fsl_dev->irq = platform_get_irq(pdev, 0);
if (fsl_dev->irq < 0) {
dev_err(dev, "failed to get irq\n");
return -ENXIO;
}
fsl_dev->clk = devm_clk_get(dev, "dcu");
if (IS_ERR(fsl_dev->clk)) {
ret = PTR_ERR(fsl_dev->clk);
dev_err(dev, "failed to get dcu clock\n");
return ret;
}
ret = clk_prepare(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to prepare dcu clk\n");
return ret;
}
ret = clk_enable(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to enable dcu clk\n");
clk_unprepare(fsl_dev->clk);
return ret;
}
fsl_dev->regmap = devm_regmap_init_mmio(dev, base,
&fsl_dcu_regmap_config);
if (IS_ERR(fsl_dev->regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(fsl_dev->regmap);
}
id = of_match_node(fsl_dcu_of_match, pdev->dev.of_node);
if (!id)
return -ENODEV;
fsl_dev->soc = id->data;
drm = drm_dev_alloc(driver, dev);
if (!drm)
return -ENOMEM;
fsl_dev->dev = dev;
fsl_dev->drm = drm;
fsl_dev->np = dev->of_node;
drm->dev_private = fsl_dev;
dev_set_drvdata(dev, fsl_dev);
drm_dev_set_unique(drm, dev_name(dev));
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto unref;
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n", driver->name,
driver->major, driver->minor, driver->patchlevel,
driver->date, drm->primary->index);
return 0;
unref:
drm_dev_unref(drm);
return ret;
}
static int fsl_dcu_drm_remove(struct platform_device *pdev)
{
struct fsl_dcu_drm_device *fsl_dev = platform_get_drvdata(pdev);
drm_put_dev(fsl_dev->drm);
return 0;
}
