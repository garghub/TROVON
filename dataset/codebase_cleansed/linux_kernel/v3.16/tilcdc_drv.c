void tilcdc_module_init(struct tilcdc_module *mod, const char *name,
const struct tilcdc_module_ops *funcs)
{
mod->name = name;
mod->funcs = funcs;
INIT_LIST_HEAD(&mod->list);
list_add(&mod->list, &module_list);
}
void tilcdc_module_cleanup(struct tilcdc_module *mod)
{
list_del(&mod->list);
}
void tilcdc_slave_probedefer(bool defered)
{
slave_probing = defered;
}
static struct drm_framebuffer *tilcdc_fb_create(struct drm_device *dev,
struct drm_file *file_priv, struct drm_mode_fb_cmd2 *mode_cmd)
{
return drm_fb_cma_create(dev, file_priv, mode_cmd);
}
static void tilcdc_fb_output_poll_changed(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
if (priv->fbdev)
drm_fbdev_cma_hotplug_event(priv->fbdev);
}
static int modeset_init(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
struct tilcdc_module *mod;
drm_mode_config_init(dev);
priv->crtc = tilcdc_crtc_create(dev);
list_for_each_entry(mod, &module_list, list) {
DBG("loading module: %s", mod->name);
mod->funcs->modeset_init(mod, dev);
}
if ((priv->num_encoders == 0) || (priv->num_connectors == 0)) {
dev_err(dev->dev, "no encoders/connectors found\n");
return -ENXIO;
}
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = tilcdc_crtc_max_width(priv->crtc);
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &mode_config_funcs;
return 0;
}
static int cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
struct tilcdc_drm_private *priv = container_of(nb,
struct tilcdc_drm_private, freq_transition);
if (val == CPUFREQ_POSTCHANGE) {
if (priv->lcd_fck_rate != clk_get_rate(priv->clk)) {
priv->lcd_fck_rate = clk_get_rate(priv->clk);
tilcdc_crtc_update_clk(priv->crtc);
}
}
return 0;
}
static int tilcdc_unload(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
struct tilcdc_module *mod, *cur;
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
pm_runtime_get_sync(dev->dev);
drm_irq_uninstall(dev);
pm_runtime_put_sync(dev->dev);
#ifdef CONFIG_CPU_FREQ
cpufreq_unregister_notifier(&priv->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
#endif
if (priv->clk)
clk_put(priv->clk);
if (priv->mmio)
iounmap(priv->mmio);
flush_workqueue(priv->wq);
destroy_workqueue(priv->wq);
dev->dev_private = NULL;
pm_runtime_disable(dev->dev);
list_for_each_entry_safe(mod, cur, &module_list, list) {
DBG("destroying module: %s", mod->name);
mod->funcs->destroy(mod);
}
kfree(priv);
return 0;
}
static int tilcdc_load(struct drm_device *dev, unsigned long flags)
{
struct platform_device *pdev = dev->platformdev;
struct device_node *node = pdev->dev.of_node;
struct tilcdc_drm_private *priv;
struct tilcdc_module *mod;
struct resource *res;
u32 bpp = 0;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev->dev, "failed to allocate private data\n");
return -ENOMEM;
}
dev->dev_private = priv;
priv->wq = alloc_ordered_workqueue("tilcdc", 0);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev->dev, "failed to get memory resource\n");
ret = -EINVAL;
goto fail;
}
priv->mmio = ioremap_nocache(res->start, resource_size(res));
if (!priv->mmio) {
dev_err(dev->dev, "failed to ioremap\n");
ret = -ENOMEM;
goto fail;
}
priv->clk = clk_get(dev->dev, "fck");
if (IS_ERR(priv->clk)) {
dev_err(dev->dev, "failed to get functional clock\n");
ret = -ENODEV;
goto fail;
}
priv->disp_clk = clk_get(dev->dev, "dpll_disp_ck");
if (IS_ERR(priv->clk)) {
dev_err(dev->dev, "failed to get display clock\n");
ret = -ENODEV;
goto fail;
}
#ifdef CONFIG_CPU_FREQ
priv->lcd_fck_rate = clk_get_rate(priv->clk);
priv->freq_transition.notifier_call = cpufreq_transition;
ret = cpufreq_register_notifier(&priv->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
if (ret) {
dev_err(dev->dev, "failed to register cpufreq notifier\n");
goto fail;
}
#endif
if (of_property_read_u32(node, "max-bandwidth", &priv->max_bandwidth))
priv->max_bandwidth = TILCDC_DEFAULT_MAX_BANDWIDTH;
DBG("Maximum Bandwidth Value %d", priv->max_bandwidth);
if (of_property_read_u32(node, "ti,max-width", &priv->max_width))
priv->max_width = TILCDC_DEFAULT_MAX_WIDTH;
DBG("Maximum Horizontal Pixel Width Value %dpixels", priv->max_width);
if (of_property_read_u32(node, "ti,max-pixelclock",
&priv->max_pixelclock))
priv->max_pixelclock = TILCDC_DEFAULT_MAX_PIXELCLOCK;
DBG("Maximum Pixel Clock Value %dKHz", priv->max_pixelclock);
pm_runtime_enable(dev->dev);
pm_runtime_get_sync(dev->dev);
switch (tilcdc_read(dev, LCDC_PID_REG)) {
case 0x4c100102:
priv->rev = 1;
break;
case 0x4f200800:
case 0x4f201000:
priv->rev = 2;
break;
default:
dev_warn(dev->dev, "Unknown PID Reg value 0x%08x, "
"defaulting to LCD revision 1\n",
tilcdc_read(dev, LCDC_PID_REG));
priv->rev = 1;
break;
}
pm_runtime_put_sync(dev->dev);
ret = modeset_init(dev);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize mode setting\n");
goto fail;
}
ret = drm_vblank_init(dev, 1);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize vblank\n");
goto fail;
}
pm_runtime_get_sync(dev->dev);
ret = drm_irq_install(dev, platform_get_irq(dev->platformdev, 0));
pm_runtime_put_sync(dev->dev);
if (ret < 0) {
dev_err(dev->dev, "failed to install IRQ handler\n");
goto fail;
}
platform_set_drvdata(pdev, dev);
list_for_each_entry(mod, &module_list, list) {
DBG("%s: preferred_bpp: %d", mod->name, mod->preferred_bpp);
bpp = mod->preferred_bpp;
if (bpp > 0)
break;
}
priv->fbdev = drm_fbdev_cma_init(dev, bpp,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
drm_kms_helper_poll_init(dev);
return 0;
fail:
tilcdc_unload(dev);
return ret;
}
static void tilcdc_preclose(struct drm_device *dev, struct drm_file *file)
{
struct tilcdc_drm_private *priv = dev->dev_private;
tilcdc_crtc_cancel_page_flip(priv->crtc, file);
}
static void tilcdc_lastclose(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
drm_fbdev_cma_restore_mode(priv->fbdev);
}
static irqreturn_t tilcdc_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct tilcdc_drm_private *priv = dev->dev_private;
return tilcdc_crtc_irq(priv->crtc);
}
static void tilcdc_irq_preinstall(struct drm_device *dev)
{
tilcdc_clear_irqstatus(dev, 0xffffffff);
}
static int tilcdc_irq_postinstall(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
if (priv->rev == 1)
tilcdc_set(dev, LCDC_RASTER_CTRL_REG, LCDC_V1_UNDERFLOW_INT_ENA);
else
tilcdc_set(dev, LCDC_INT_ENABLE_SET_REG, LCDC_V2_UNDERFLOW_INT_ENA);
return 0;
}
static void tilcdc_irq_uninstall(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
if (priv->rev == 1) {
tilcdc_clear(dev, LCDC_RASTER_CTRL_REG,
LCDC_V1_UNDERFLOW_INT_ENA | LCDC_V1_PL_INT_ENA);
tilcdc_clear(dev, LCDC_DMA_CTRL_REG, LCDC_V1_END_OF_FRAME_INT_ENA);
} else {
tilcdc_clear(dev, LCDC_INT_ENABLE_SET_REG,
LCDC_V2_UNDERFLOW_INT_ENA | LCDC_V2_PL_INT_ENA |
LCDC_V2_END_OF_FRAME0_INT_ENA | LCDC_V2_END_OF_FRAME1_INT_ENA |
LCDC_FRAME_DONE);
}
}
static void enable_vblank(struct drm_device *dev, bool enable)
{
struct tilcdc_drm_private *priv = dev->dev_private;
u32 reg, mask;
if (priv->rev == 1) {
reg = LCDC_DMA_CTRL_REG;
mask = LCDC_V1_END_OF_FRAME_INT_ENA;
} else {
reg = LCDC_INT_ENABLE_SET_REG;
mask = LCDC_V2_END_OF_FRAME0_INT_ENA |
LCDC_V2_END_OF_FRAME1_INT_ENA | LCDC_FRAME_DONE;
}
if (enable)
tilcdc_set(dev, reg, mask);
else
tilcdc_clear(dev, reg, mask);
}
static int tilcdc_enable_vblank(struct drm_device *dev, int crtc)
{
enable_vblank(dev, true);
return 0;
}
static void tilcdc_disable_vblank(struct drm_device *dev, int crtc)
{
enable_vblank(dev, false);
}
static int tilcdc_regs_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
unsigned i;
pm_runtime_get_sync(dev->dev);
seq_printf(m, "revision: %d\n", priv->rev);
for (i = 0; i < ARRAY_SIZE(registers); i++)
if (priv->rev >= registers[i].rev)
seq_printf(m, "%s:\t %08x\n", registers[i].name,
tilcdc_read(dev, registers[i].reg));
pm_runtime_put_sync(dev->dev);
return 0;
}
static int tilcdc_mm_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
return drm_mm_dump_table(m, &dev->vma_offset_manager->vm_addr_space_mm);
}
static int tilcdc_debugfs_init(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct tilcdc_module *mod;
int ret;
ret = drm_debugfs_create_files(tilcdc_debugfs_list,
ARRAY_SIZE(tilcdc_debugfs_list),
minor->debugfs_root, minor);
list_for_each_entry(mod, &module_list, list)
if (mod->funcs->debugfs_init)
mod->funcs->debugfs_init(mod, minor);
if (ret) {
dev_err(dev->dev, "could not install tilcdc_debugfs_list\n");
return ret;
}
return ret;
}
static void tilcdc_debugfs_cleanup(struct drm_minor *minor)
{
struct tilcdc_module *mod;
drm_debugfs_remove_files(tilcdc_debugfs_list,
ARRAY_SIZE(tilcdc_debugfs_list), minor);
list_for_each_entry(mod, &module_list, list)
if (mod->funcs->debugfs_cleanup)
mod->funcs->debugfs_cleanup(mod, minor);
}
static int tilcdc_pm_suspend(struct device *dev)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct tilcdc_drm_private *priv = ddev->dev_private;
unsigned i, n = 0;
drm_kms_helper_poll_disable(ddev);
for (i = 0; i < ARRAY_SIZE(registers); i++)
if (registers[i].save && (priv->rev >= registers[i].rev))
priv->saved_register[n++] = tilcdc_read(ddev, registers[i].reg);
return 0;
}
static int tilcdc_pm_resume(struct device *dev)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct tilcdc_drm_private *priv = ddev->dev_private;
unsigned i, n = 0;
for (i = 0; i < ARRAY_SIZE(registers); i++)
if (registers[i].save && (priv->rev >= registers[i].rev))
tilcdc_write(ddev, registers[i].reg, priv->saved_register[n++]);
drm_kms_helper_poll_enable(ddev);
return 0;
}
static int tilcdc_pdev_probe(struct platform_device *pdev)
{
if (!pdev->dev.of_node) {
dev_err(&pdev->dev, "device-tree data is missing\n");
return -ENXIO;
}
if (slave_probing == true)
return -EPROBE_DEFER;
return drm_platform_init(&tilcdc_driver, pdev);
}
static int tilcdc_pdev_remove(struct platform_device *pdev)
{
drm_put_dev(platform_get_drvdata(pdev));
return 0;
}
static int __init tilcdc_drm_init(void)
{
DBG("init");
tilcdc_tfp410_init();
tilcdc_slave_init();
tilcdc_panel_init();
return platform_driver_register(&tilcdc_platform_driver);
}
static void __exit tilcdc_drm_fini(void)
{
DBG("fini");
tilcdc_tfp410_fini();
tilcdc_slave_fini();
tilcdc_panel_fini();
platform_driver_unregister(&tilcdc_platform_driver);
}
