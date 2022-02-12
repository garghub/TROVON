void
nouveau_irq_preinstall(struct drm_device *dev)
{
nv_wr32(nouveau_dev(dev), 0x000140, 0x00000000);
}
int
nouveau_irq_postinstall(struct drm_device *dev)
{
nv_wr32(nouveau_dev(dev), 0x000140, 0x00000001);
return 0;
}
void
nouveau_irq_uninstall(struct drm_device *dev)
{
nv_wr32(nouveau_dev(dev), 0x000140, 0x00000000);
}
irqreturn_t
nouveau_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = arg;
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_mc *pmc = nouveau_mc(device);
u32 stat;
stat = nv_rd32(device, 0x000100);
if (stat == 0 || stat == ~0)
return IRQ_NONE;
nv_subdev(pmc)->intr(nv_subdev(pmc));
if (dev->mode_config.num_crtc) {
if (device->card_type >= NV_D0) {
if (nv_rd32(device, 0x000100) & 0x04000000)
nvd0_display_intr(dev);
} else
if (device->card_type >= NV_50) {
if (nv_rd32(device, 0x000100) & 0x04000000)
nv50_display_intr(dev);
}
}
return IRQ_HANDLED;
}
int
nouveau_irq_init(struct drm_device *dev)
{
return drm_irq_install(dev);
}
void
nouveau_irq_fini(struct drm_device *dev)
{
drm_irq_uninstall(dev);
}
