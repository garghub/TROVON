static bool fsl_dcu_drm_is_volatile_reg(struct device *dev, unsigned int reg)
{
if (reg == DCU_INT_STATUS || reg == DCU_UPDATE_MODE)
return true;
return false;
}
static int fsl_dcu_drm_irq_init(struct drm_device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
int ret;
ret = drm_irq_install(dev, fsl_dev->irq);
if (ret < 0)
dev_err(dev->dev, "failed to install IRQ handler\n");
regmap_write(fsl_dev->regmap, DCU_INT_STATUS, 0);
regmap_write(fsl_dev->regmap, DCU_INT_MASK, ~0);
regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
return ret;
}
static int fsl_dcu_load(struct drm_device *dev, unsigned long flags)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
int ret;
ret = fsl_dcu_drm_modeset_init(fsl_dev);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize mode setting\n");
return ret;
}
ret = drm_vblank_init(dev, dev->mode_config.num_crtc);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize vblank\n");
goto done;
}
ret = fsl_dcu_drm_irq_init(dev);
if (ret < 0)
goto done;
dev->irq_enabled = true;
fsl_dcu_fbdev_init(dev);
return 0;
done:
drm_kms_helper_poll_fini(dev);
if (fsl_dev->fbdev)
drm_fbdev_cma_fini(fsl_dev->fbdev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
drm_irq_uninstall(dev);
dev->dev_private = NULL;
return ret;
}
static int fsl_dcu_unload(struct drm_device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
drm_kms_helper_poll_fini(dev);
if (fsl_dev->fbdev)
drm_fbdev_cma_fini(fsl_dev->fbdev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
drm_irq_uninstall(dev);
dev->dev_private = NULL;
return 0;
}
static irqreturn_t fsl_dcu_drm_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int int_status;
int ret;
ret = regmap_read(fsl_dev->regmap, DCU_INT_STATUS, &int_status);
if (ret) {
dev_err(dev->dev, "read DCU_INT_STATUS failed\n");
return IRQ_NONE;
}
if (int_status & DCU_INT_STATUS_VBLANK)
drm_handle_vblank(dev, 0);
regmap_write(fsl_dev->regmap, DCU_INT_STATUS, int_status);
regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
return IRQ_HANDLED;
}
static int fsl_dcu_drm_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int value;
regmap_read(fsl_dev->regmap, DCU_INT_MASK, &value);
value &= ~DCU_INT_MASK_VBLANK;
regmap_write(fsl_dev->regmap, DCU_INT_MASK, value);
return 0;
}
static void fsl_dcu_drm_disable_vblank(struct drm_device *dev,
unsigned int pipe)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
unsigned int value;
regmap_read(fsl_dev->regmap, DCU_INT_MASK, &value);
value |= DCU_INT_MASK_VBLANK;
regmap_write(fsl_dev->regmap, DCU_INT_MASK, value);
}
static void fsl_dcu_drm_lastclose(struct drm_device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
drm_fbdev_cma_restore_mode(fsl_dev->fbdev);
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
struct clk *pix_clk_in;
char pix_clk_name[32];
const char *pix_clk_in_name;
const struct of_device_id *id;
int ret;
fsl_dev = devm_kzalloc(dev, sizeof(*fsl_dev), GFP_KERNEL);
if (!fsl_dev)
return -ENOMEM;
id = of_match_node(fsl_dcu_of_match, pdev->dev.of_node);
if (!id)
return -ENODEV;
fsl_dev->soc = id->data;
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
fsl_dev->regmap = devm_regmap_init_mmio(dev, base,
&fsl_dcu_regmap_config);
if (IS_ERR(fsl_dev->regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(fsl_dev->regmap);
}
fsl_dev->clk = devm_clk_get(dev, "dcu");
if (IS_ERR(fsl_dev->clk)) {
dev_err(dev, "failed to get dcu clock\n");
return PTR_ERR(fsl_dev->clk);
}
ret = clk_prepare_enable(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to enable dcu clk\n");
return ret;
}
pix_clk_in = devm_clk_get(dev, "pix");
if (IS_ERR(pix_clk_in)) {
pix_clk_in = fsl_dev->clk;
}
pix_clk_in_name = __clk_get_name(pix_clk_in);
snprintf(pix_clk_name, sizeof(pix_clk_name), "%s_pix", pix_clk_in_name);
fsl_dev->pix_clk = clk_register_divider(dev, pix_clk_name,
pix_clk_in_name, 0, base + DCU_DIV_RATIO,
0, 8, CLK_DIVIDER_ROUND_CLOSEST, NULL);
if (IS_ERR(fsl_dev->pix_clk)) {
dev_err(dev, "failed to register pix clk\n");
ret = PTR_ERR(fsl_dev->pix_clk);
goto disable_clk;
}
ret = clk_prepare_enable(fsl_dev->pix_clk);
if (ret < 0) {
dev_err(dev, "failed to enable pix clk\n");
goto unregister_pix_clk;
}
fsl_dev->tcon = fsl_tcon_init(dev);
drm = drm_dev_alloc(driver, dev);
if (!drm) {
ret = -ENOMEM;
goto disable_pix_clk;
}
fsl_dev->dev = dev;
fsl_dev->drm = drm;
fsl_dev->np = dev->of_node;
drm->dev_private = fsl_dev;
dev_set_drvdata(dev, fsl_dev);
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto unref;
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n", driver->name,
driver->major, driver->minor, driver->patchlevel,
driver->date, drm->primary->index);
return 0;
unref:
drm_dev_unref(drm);
disable_pix_clk:
clk_disable_unprepare(fsl_dev->pix_clk);
unregister_pix_clk:
clk_unregister(fsl_dev->pix_clk);
disable_clk:
clk_disable_unprepare(fsl_dev->clk);
return ret;
}
static int fsl_dcu_drm_remove(struct platform_device *pdev)
{
struct fsl_dcu_drm_device *fsl_dev = platform_get_drvdata(pdev);
clk_disable_unprepare(fsl_dev->clk);
clk_disable_unprepare(fsl_dev->pix_clk);
clk_unregister(fsl_dev->pix_clk);
drm_put_dev(fsl_dev->drm);
return 0;
}
