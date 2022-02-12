static int __devinit
nouveau_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
return drm_get_pci_dev(pdev, ent, &driver);
}
static void
nouveau_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
int
nouveau_pci_suspend(struct pci_dev *pdev, pm_message_t pm_state)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_instmem_engine *pinstmem = &dev_priv->engine.instmem;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
struct nouveau_channel *chan;
struct drm_crtc *crtc;
int ret, i, e;
if (pm_state.event == PM_EVENT_PRETHAW)
return 0;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
NV_INFO(dev, "Disabling display...\n");
nouveau_display_fini(dev);
NV_INFO(dev, "Disabling fbcon...\n");
nouveau_fbcon_set_suspend(dev, 1);
NV_INFO(dev, "Unpinning framebuffer(s)...\n");
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_framebuffer *nouveau_fb;
nouveau_fb = nouveau_framebuffer(crtc->fb);
if (!nouveau_fb || !nouveau_fb->nvbo)
continue;
nouveau_bo_unpin(nouveau_fb->nvbo);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
nouveau_bo_unmap(nv_crtc->cursor.nvbo);
nouveau_bo_unpin(nv_crtc->cursor.nvbo);
}
NV_INFO(dev, "Evicting buffers...\n");
ttm_bo_evict_mm(&dev_priv->ttm.bdev, TTM_PL_VRAM);
NV_INFO(dev, "Idling channels...\n");
for (i = 0; i < pfifo->channels; i++) {
chan = dev_priv->channels.ptr[i];
if (chan && chan->pushbuf_bo)
nouveau_channel_idle(chan);
}
pfifo->reassign(dev, false);
pfifo->disable(dev);
pfifo->unload_context(dev);
for (e = NVOBJ_ENGINE_NR - 1; e >= 0; e--) {
if (!dev_priv->eng[e])
continue;
ret = dev_priv->eng[e]->fini(dev, e, true);
if (ret) {
NV_ERROR(dev, "... engine %d failed: %d\n", e, ret);
goto out_abort;
}
}
ret = pinstmem->suspend(dev);
if (ret) {
NV_ERROR(dev, "... failed: %d\n", ret);
goto out_abort;
}
NV_INFO(dev, "Suspending GPU objects...\n");
ret = nouveau_gpuobj_suspend(dev);
if (ret) {
NV_ERROR(dev, "... failed: %d\n", ret);
pinstmem->resume(dev);
goto out_abort;
}
NV_INFO(dev, "And we're gone!\n");
pci_save_state(pdev);
if (pm_state.event == PM_EVENT_SUSPEND) {
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
}
return 0;
out_abort:
NV_INFO(dev, "Re-enabling acceleration..\n");
for (e = e + 1; e < NVOBJ_ENGINE_NR; e++) {
if (dev_priv->eng[e])
dev_priv->eng[e]->init(dev, e);
}
pfifo->enable(dev);
pfifo->reassign(dev, true);
return ret;
}
int
nouveau_pci_resume(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_engine *engine = &dev_priv->engine;
struct drm_crtc *crtc;
int ret, i;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
NV_INFO(dev, "We're back, enabling device...\n");
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (pci_enable_device(pdev))
return -1;
pci_set_master(dev->pdev);
if (dev_priv->gart_info.type == NOUVEAU_GART_AGP)
nouveau_mem_reset_agp(dev);
engine->display.early_init(dev);
NV_INFO(dev, "POSTing device...\n");
ret = nouveau_run_vbios_init(dev);
if (ret)
return ret;
if (dev_priv->gart_info.type == NOUVEAU_GART_AGP) {
ret = nouveau_mem_init_agp(dev);
if (ret) {
NV_ERROR(dev, "error reinitialising AGP: %d\n", ret);
return ret;
}
}
NV_INFO(dev, "Restoring GPU objects...\n");
nouveau_gpuobj_resume(dev);
NV_INFO(dev, "Reinitialising engines...\n");
engine->instmem.resume(dev);
engine->mc.init(dev);
engine->timer.init(dev);
engine->fb.init(dev);
for (i = 0; i < NVOBJ_ENGINE_NR; i++) {
if (dev_priv->eng[i])
dev_priv->eng[i]->init(dev, i);
}
engine->fifo.init(dev);
nouveau_irq_postinstall(dev);
if (nouveau_vram_pushbuf) {
struct nouveau_channel *chan;
int j;
for (i = 0; i < dev_priv->engine.fifo.channels; i++) {
chan = dev_priv->channels.ptr[i];
if (!chan || !chan->pushbuf_bo)
continue;
for (j = 0; j < NOUVEAU_DMA_SKIPS; j++)
nouveau_bo_wr32(chan->pushbuf_bo, i, 0);
}
}
nouveau_pm_resume(dev);
NV_INFO(dev, "Restoring mode...\n");
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_framebuffer *nouveau_fb;
nouveau_fb = nouveau_framebuffer(crtc->fb);
if (!nouveau_fb || !nouveau_fb->nvbo)
continue;
nouveau_bo_pin(nouveau_fb->nvbo, TTM_PL_FLAG_VRAM);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
ret = nouveau_bo_pin(nv_crtc->cursor.nvbo, TTM_PL_FLAG_VRAM);
if (!ret)
ret = nouveau_bo_map(nv_crtc->cursor.nvbo);
if (ret)
NV_ERROR(dev, "Could not pin/map cursor.\n");
}
nouveau_fbcon_set_suspend(dev, 0);
nouveau_fbcon_zfill_all(dev);
nouveau_display_init(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
nv_crtc->lut.depth = 0;
}
drm_helper_resume_force_mode(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
u32 offset = nv_crtc->cursor.nvbo->bo.offset;
nv_crtc->cursor.set_offset(nv_crtc, offset);
nv_crtc->cursor.set_pos(nv_crtc, nv_crtc->cursor_saved_x,
nv_crtc->cursor_saved_y);
}
return 0;
}
static int __init nouveau_init(void)
{
driver.num_ioctls = nouveau_max_ioctl;
if (nouveau_modeset == -1) {
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force())
nouveau_modeset = 0;
else
#endif
nouveau_modeset = 1;
}
if (!nouveau_modeset)
return 0;
nouveau_register_dsm_handler();
return drm_pci_init(&driver, &nouveau_pci_driver);
}
static void __exit nouveau_exit(void)
{
if (!nouveau_modeset)
return;
drm_pci_exit(&driver, &nouveau_pci_driver);
nouveau_unregister_dsm_handler();
}
