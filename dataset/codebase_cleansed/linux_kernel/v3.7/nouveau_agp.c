static unsigned long
get_agp_mode(struct nouveau_drm *drm, unsigned long mode)
{
struct nouveau_device *device = nv_device(drm->device);
if (device->chipset == 0x18)
mode &= ~PCI_AGP_COMMAND_FW;
if (nouveau_agpmode > 0) {
bool agpv3 = mode & 0x8;
int rate = agpv3 ? nouveau_agpmode / 4 : nouveau_agpmode;
mode = (mode & ~0x7) | (rate & 0x7);
}
return mode;
}
static bool
nouveau_agp_enabled(struct nouveau_drm *drm)
{
struct drm_device *dev = drm->dev;
if (!drm_pci_device_is_agp(dev) || !dev->agp)
return false;
if (drm->agp.stat == UNKNOWN) {
if (!nouveau_agpmode)
return false;
return true;
}
return (drm->agp.stat == ENABLED);
}
void
nouveau_agp_reset(struct nouveau_drm *drm)
{
#if __OS_HAS_AGP
struct nouveau_device *device = nv_device(drm->device);
struct drm_device *dev = drm->dev;
u32 save[2];
int ret;
if (!nouveau_agp_enabled(drm))
return;
if ((nv_rd32(device, NV04_PBUS_PCI_NV_19) |
dev->agp->mode) & PCI_AGP_COMMAND_FW) {
struct drm_agp_info info;
struct drm_agp_mode mode;
ret = drm_agp_info(dev, &info);
if (ret)
return;
mode.mode = get_agp_mode(drm, info.mode);
mode.mode &= ~PCI_AGP_COMMAND_FW;
ret = drm_agp_enable(dev, mode);
if (ret)
return;
}
save[0] = nv_mask(device, NV04_PBUS_PCI_NV_1, 0x00000004, 0x00000000);
nv_wr32(device, NV04_PBUS_PCI_NV_19, 0);
save[1] = nv_mask(device, 0x000200, 0x00011100, 0x00000000);
nv_mask(device, 0x000200, 0x00011100, save[1]);
nv_wr32(device, NV04_PBUS_PCI_NV_1, save[0]);
#endif
}
void
nouveau_agp_init(struct nouveau_drm *drm)
{
#if __OS_HAS_AGP
struct nouveau_device *device = nv_device(drm->device);
struct drm_device *dev = drm->dev;
struct drm_agp_info info;
struct drm_agp_mode mode;
int ret;
if (!nouveau_agp_enabled(drm))
return;
drm->agp.stat = DISABLE;
ret = drm_agp_acquire(dev);
if (ret) {
nv_error(device, "unable to acquire AGP: %d\n", ret);
return;
}
ret = drm_agp_info(dev, &info);
if (ret) {
nv_error(device, "unable to get AGP info: %d\n", ret);
return;
}
mode.mode = get_agp_mode(drm, info.mode);
ret = drm_agp_enable(dev, mode);
if (ret) {
nv_error(device, "unable to enable AGP: %d\n", ret);
return;
}
drm->agp.stat = ENABLED;
drm->agp.base = info.aperture_base;
drm->agp.size = info.aperture_size;
#endif
}
void
nouveau_agp_fini(struct nouveau_drm *drm)
{
#if __OS_HAS_AGP
struct drm_device *dev = drm->dev;
if (dev->agp && dev->agp->acquired)
drm_agp_release(dev);
#endif
}
