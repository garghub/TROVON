static void arcpgu_fb_output_poll_changed(struct drm_device *dev)
{
struct arcpgu_drm_private *arcpgu = dev->dev_private;
if (arcpgu->fbdev)
drm_fbdev_cma_hotplug_event(arcpgu->fbdev);
}
static int arcpgu_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state, bool async)
{
return drm_atomic_helper_commit(dev, state, false);
}
static void arcpgu_setup_mode_config(struct drm_device *drm)
{
drm_mode_config_init(drm);
drm->mode_config.min_width = 0;
drm->mode_config.min_height = 0;
drm->mode_config.max_width = 1920;
drm->mode_config.max_height = 1080;
drm->mode_config.funcs = &arcpgu_drm_modecfg_funcs;
}
int arcpgu_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret)
return ret;
vma->vm_page_prot = pgprot_noncached(vm_get_page_prot(vma->vm_flags));
return 0;
}
static void arcpgu_preclose(struct drm_device *drm, struct drm_file *file)
{
struct arcpgu_drm_private *arcpgu = drm->dev_private;
struct drm_pending_vblank_event *e, *t;
unsigned long flags;
spin_lock_irqsave(&drm->event_lock, flags);
list_for_each_entry_safe(e, t, &arcpgu->event_list, base.link) {
if (e->base.file_priv != file)
continue;
list_del(&e->base.link);
e->base.destroy(&e->base);
}
spin_unlock_irqrestore(&drm->event_lock, flags);
}
static void arcpgu_lastclose(struct drm_device *drm)
{
struct arcpgu_drm_private *arcpgu = drm->dev_private;
drm_fbdev_cma_restore_mode(arcpgu->fbdev);
}
static int arcpgu_load(struct drm_device *drm)
{
struct platform_device *pdev = to_platform_device(drm->dev);
struct arcpgu_drm_private *arcpgu;
struct device_node *encoder_node;
struct resource *res;
int ret;
arcpgu = devm_kzalloc(&pdev->dev, sizeof(*arcpgu), GFP_KERNEL);
if (arcpgu == NULL)
return -ENOMEM;
drm->dev_private = arcpgu;
arcpgu->clk = devm_clk_get(drm->dev, "pxlclk");
if (IS_ERR(arcpgu->clk))
return PTR_ERR(arcpgu->clk);
INIT_LIST_HEAD(&arcpgu->event_list);
arcpgu_setup_mode_config(drm);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
arcpgu->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(arcpgu->regs)) {
dev_err(drm->dev, "Could not remap IO mem\n");
return PTR_ERR(arcpgu->regs);
}
dev_info(drm->dev, "arc_pgu ID: 0x%x\n",
arc_pgu_read(arcpgu, ARCPGU_REG_ID));
ret = of_reserved_mem_device_init(drm->dev);
if (ret && ret != -ENODEV)
return ret;
if (dma_set_mask_and_coherent(drm->dev, DMA_BIT_MASK(32)))
return -ENODEV;
if (arc_pgu_setup_crtc(drm) < 0)
return -ENODEV;
encoder_node = of_parse_phandle(drm->dev->of_node, "encoder-slave", 0);
if (!encoder_node) {
dev_err(drm->dev, "failed to get an encoder slave node\n");
return -ENODEV;
}
ret = arcpgu_drm_hdmi_init(drm, encoder_node);
if (ret < 0)
return ret;
drm_mode_config_reset(drm);
drm_kms_helper_poll_init(drm);
arcpgu->fbdev = drm_fbdev_cma_init(drm, 16,
drm->mode_config.num_crtc,
drm->mode_config.num_connector);
if (IS_ERR(arcpgu->fbdev)) {
ret = PTR_ERR(arcpgu->fbdev);
arcpgu->fbdev = NULL;
return -ENODEV;
}
platform_set_drvdata(pdev, arcpgu);
return 0;
}
int arcpgu_unload(struct drm_device *drm)
{
struct arcpgu_drm_private *arcpgu = drm->dev_private;
if (arcpgu->fbdev) {
drm_fbdev_cma_fini(arcpgu->fbdev);
arcpgu->fbdev = NULL;
}
drm_kms_helper_poll_fini(drm);
drm_vblank_cleanup(drm);
drm_mode_config_cleanup(drm);
return 0;
}
static int arcpgu_probe(struct platform_device *pdev)
{
struct drm_device *drm;
int ret;
drm = drm_dev_alloc(&arcpgu_drm_driver, &pdev->dev);
if (!drm)
return -ENOMEM;
ret = arcpgu_load(drm);
if (ret)
goto err_unref;
ret = drm_dev_register(drm, 0);
if (ret)
goto err_unload;
ret = drm_connector_register_all(drm);
if (ret)
goto err_unregister;
return 0;
err_unregister:
drm_dev_unregister(drm);
err_unload:
arcpgu_unload(drm);
err_unref:
drm_dev_unref(drm);
return ret;
}
static int arcpgu_remove(struct platform_device *pdev)
{
struct drm_device *drm = platform_get_drvdata(pdev);
drm_connector_unregister_all(drm);
drm_dev_unregister(drm);
arcpgu_unload(drm);
drm_dev_unref(drm);
return 0;
}
