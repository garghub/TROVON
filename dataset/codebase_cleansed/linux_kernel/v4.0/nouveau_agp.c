static unsigned long
get_agp_mode(struct nouveau_drm *drm, const struct drm_agp_info *info)
{
struct nvif_device *device = &drm->device;
struct nouveau_agpmode_quirk *quirk = nouveau_agpmode_quirk_list;
int agpmode = nouveau_agpmode;
unsigned long mode = info->mode;
if (device->info.chipset == 0x18)
mode &= ~PCI_AGP_COMMAND_FW;
while (agpmode == -1 && quirk->hostbridge_vendor) {
if (info->id_vendor == quirk->hostbridge_vendor &&
info->id_device == quirk->hostbridge_device &&
nvxx_device(device)->pdev->vendor == quirk->chip_vendor &&
nvxx_device(device)->pdev->device == quirk->chip_device) {
agpmode = quirk->mode;
NV_INFO(drm, "Forcing agp mode to %dX. Use agpmode to override.\n",
agpmode);
break;
}
++quirk;
}
if (agpmode > 0) {
bool agpv3 = mode & 0x8;
int rate = agpv3 ? agpmode / 4 : agpmode;
mode = (mode & ~0x7) | (rate & 0x7);
}
return mode;
}
static bool
nouveau_agp_enabled(struct nouveau_drm *drm)
{
struct drm_device *dev = drm->dev;
if (!dev->pdev || !drm_pci_device_is_agp(dev) || !dev->agp)
return false;
if (drm->agp.stat == UNKNOWN) {
if (!nouveau_agpmode)
return false;
#ifdef __powerpc__
if (nouveau_agpmode == -1)
return false;
#endif
return true;
}
return (drm->agp.stat == ENABLED);
}
void
nouveau_agp_reset(struct nouveau_drm *drm)
{
#if __OS_HAS_AGP
struct nvif_device *device = &drm->device;
struct drm_device *dev = drm->dev;
u32 save[2];
int ret;
if (!nouveau_agp_enabled(drm))
return;
if ((nvif_rd32(device, NV04_PBUS_PCI_NV_19) |
dev->agp->mode) & PCI_AGP_COMMAND_FW) {
struct drm_agp_info info;
struct drm_agp_mode mode;
ret = drm_agp_info(dev, &info);
if (ret)
return;
mode.mode = get_agp_mode(drm, &info);
mode.mode &= ~PCI_AGP_COMMAND_FW;
ret = drm_agp_enable(dev, mode);
if (ret)
return;
}
save[0] = nvif_mask(device, NV04_PBUS_PCI_NV_1, 0x00000004, 0x00000000);
nvif_wr32(device, NV04_PBUS_PCI_NV_19, 0);
save[1] = nvif_mask(device, 0x000200, 0x00011100, 0x00000000);
nvif_mask(device, 0x000200, 0x00011100, save[1]);
nvif_wr32(device, NV04_PBUS_PCI_NV_1, save[0]);
#endif
}
void
nouveau_agp_init(struct nouveau_drm *drm)
{
#if __OS_HAS_AGP
struct drm_device *dev = drm->dev;
struct drm_agp_info info;
struct drm_agp_mode mode;
int ret;
if (!nouveau_agp_enabled(drm))
return;
drm->agp.stat = DISABLE;
ret = drm_agp_acquire(dev);
if (ret) {
NV_ERROR(drm, "unable to acquire AGP: %d\n", ret);
return;
}
ret = drm_agp_info(dev, &info);
if (ret) {
NV_ERROR(drm, "unable to get AGP info: %d\n", ret);
return;
}
mode.mode = get_agp_mode(drm, &info);
ret = drm_agp_enable(dev, mode);
if (ret) {
NV_ERROR(drm, "unable to enable AGP: %d\n", ret);
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
