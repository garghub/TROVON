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
if (legacyfb_depth != 16 && legacyfb_depth != 24 &&
legacyfb_depth != 32) {
dev_warn(dev->dev,
"Invalid legacyfb_depth. Defaulting to 24bpp\n");
legacyfb_depth = 24;
}
fsl_dev->fbdev = drm_fbdev_cma_init(dev, legacyfb_depth, 1);
if (IS_ERR(fsl_dev->fbdev)) {
ret = PTR_ERR(fsl_dev->fbdev);
fsl_dev->fbdev = NULL;
goto done;
}
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
static void fsl_dcu_unload(struct drm_device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
drm_crtc_force_disable_all(dev);
drm_kms_helper_poll_fini(dev);
if (fsl_dev->fbdev)
drm_fbdev_cma_fini(fsl_dev->fbdev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
drm_irq_uninstall(dev);
dev->dev_private = NULL;
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
return IRQ_HANDLED;
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
disable_irq(fsl_dev->irq);
drm_kms_helper_poll_disable(fsl_dev->drm);
console_lock();
drm_fbdev_cma_set_suspend(fsl_dev->fbdev, 1);
console_unlock();
fsl_dev->state = drm_atomic_helper_suspend(fsl_dev->drm);
if (IS_ERR(fsl_dev->state)) {
console_lock();
drm_fbdev_cma_set_suspend(fsl_dev->fbdev, 0);
console_unlock();
drm_kms_helper_poll_enable(fsl_dev->drm);
enable_irq(fsl_dev->irq);
return PTR_ERR(fsl_dev->state);
}
clk_disable_unprepare(fsl_dev->pix_clk);
clk_disable_unprepare(fsl_dev->clk);
return 0;
}
static int fsl_dcu_drm_pm_resume(struct device *dev)
{
struct fsl_dcu_drm_device *fsl_dev = dev_get_drvdata(dev);
int ret;
if (!fsl_dev)
return 0;
ret = clk_prepare_enable(fsl_dev->clk);
if (ret < 0) {
dev_err(dev, "failed to enable dcu clk\n");
return ret;
}
if (fsl_dev->tcon)
fsl_tcon_bypass_enable(fsl_dev->tcon);
fsl_dcu_drm_init_planes(fsl_dev->drm);
drm_atomic_helper_resume(fsl_dev->drm, fsl_dev->state);
console_lock();
drm_fbdev_cma_set_suspend(fsl_dev->fbdev, 0);
console_unlock();
drm_kms_helper_poll_enable(fsl_dev->drm);
enable_irq(fsl_dev->irq);
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
u8 div_ratio_shift = 0;
fsl_dev = devm_kzalloc(dev, sizeof(*fsl_dev), GFP_KERNEL);
if (!fsl_dev)
return -ENOMEM;
id = of_match_node(fsl_dcu_of_match, pdev->dev.of_node);
if (!id)
return -ENODEV;
fsl_dev->soc = id->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
return ret;
}
fsl_dev->irq = platform_get_irq(pdev, 0);
if (fsl_dev->irq < 0) {
dev_err(dev, "failed to get irq\n");
return fsl_dev->irq;
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
if (of_property_read_bool(dev->of_node, "big-endian"))
div_ratio_shift = 24;
pix_clk_in_name = __clk_get_name(pix_clk_in);
snprintf(pix_clk_name, sizeof(pix_clk_name), "%s_pix", pix_clk_in_name);
fsl_dev->pix_clk = clk_register_divider(dev, pix_clk_name,
pix_clk_in_name, 0, base + DCU_DIV_RATIO,
div_ratio_shift, 8, CLK_DIVIDER_ROUND_CLOSEST, NULL);
if (IS_ERR(fsl_dev->pix_clk)) {
dev_err(dev, "failed to register pix clk\n");
ret = PTR_ERR(fsl_dev->pix_clk);
goto disable_clk;
}
fsl_dev->tcon = fsl_tcon_init(dev);
drm = drm_dev_alloc(driver, dev);
if (IS_ERR(drm)) {
ret = PTR_ERR(drm);
goto unregister_pix_clk;
}
fsl_dev->dev = dev;
fsl_dev->drm = drm;
fsl_dev->np = dev->of_node;
drm->dev_private = fsl_dev;
dev_set_drvdata(dev, fsl_dev);
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto unref;
return 0;
unref:
drm_dev_unref(drm);
unregister_pix_clk:
clk_unregister(fsl_dev->pix_clk);
disable_clk:
clk_disable_unprepare(fsl_dev->clk);
return ret;
}
static int fsl_dcu_drm_remove(struct platform_device *pdev)
{
struct fsl_dcu_drm_device *fsl_dev = platform_get_drvdata(pdev);
drm_dev_unregister(fsl_dev->drm);
drm_dev_unref(fsl_dev->drm);
clk_disable_unprepare(fsl_dev->clk);
clk_unregister(fsl_dev->pix_clk);
return 0;
}
