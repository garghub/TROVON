void
nvkm_agp_fini(struct nvkm_pci *pci)
{
if (pci->agp.acquired) {
agp_backend_release(pci->agp.bridge);
pci->agp.acquired = false;
}
}
void
nvkm_agp_preinit(struct nvkm_pci *pci)
{
struct nvkm_device *device = pci->subdev.device;
u32 mode = nvkm_pci_rd32(pci, 0x004c);
u32 save[2];
if ((mode | pci->agp.mode) & PCI_AGP_COMMAND_FW) {
mode = pci->agp.mode & ~PCI_AGP_COMMAND_FW;
agp_enable(pci->agp.bridge, mode);
}
save[0] = nvkm_pci_rd32(pci, 0x0004);
nvkm_pci_wr32(pci, 0x0004, save[0] & ~0x00000004);
nvkm_pci_wr32(pci, 0x004c, 0x00000000);
save[1] = nvkm_mask(device, 0x000200, 0x00011100, 0x00000000);
nvkm_mask(device, 0x000200, 0x00011100, save[1]);
nvkm_pci_wr32(pci, 0x0004, save[0]);
}
int
nvkm_agp_init(struct nvkm_pci *pci)
{
if (!agp_backend_acquire(pci->pdev)) {
nvkm_error(&pci->subdev, "failed to acquire agp\n");
return -ENODEV;
}
agp_enable(pci->agp.bridge, pci->agp.mode);
pci->agp.acquired = true;
return 0;
}
void
nvkm_agp_dtor(struct nvkm_pci *pci)
{
arch_phys_wc_del(pci->agp.mtrr);
}
void
nvkm_agp_ctor(struct nvkm_pci *pci)
{
const struct nvkm_device_agp_quirk *quirk = nvkm_device_agp_quirks;
struct nvkm_subdev *subdev = &pci->subdev;
struct nvkm_device *device = subdev->device;
struct agp_kern_info info;
int mode = -1;
#ifdef __powerpc__
mode = 0;
#endif
mode = nvkm_longopt(device->cfgopt, "NvAGP", mode);
if (!(pci->agp.bridge = agp_backend_acquire(pci->pdev))) {
nvkm_warn(subdev, "failed to acquire agp\n");
return;
}
agp_copy_info(pci->agp.bridge, &info);
agp_backend_release(pci->agp.bridge);
pci->agp.mode = info.mode;
pci->agp.base = info.aper_base;
pci->agp.size = info.aper_size * 1024 * 1024;
pci->agp.cma = info.cant_use_aperture;
pci->agp.mtrr = -1;
while (quirk->hostbridge_vendor) {
if (info.device->vendor == quirk->hostbridge_vendor &&
info.device->device == quirk->hostbridge_device &&
(quirk->chip_vendor == (u16)PCI_ANY_ID ||
pci->pdev->vendor == quirk->chip_vendor) &&
(quirk->chip_device == (u16)PCI_ANY_ID ||
pci->pdev->device == quirk->chip_device)) {
nvkm_info(subdev, "forcing default agp mode to %dX, "
"use NvAGP=<mode> to override\n",
quirk->mode);
mode = quirk->mode;
break;
}
quirk++;
}
if (mode >= 1) {
if (pci->agp.mode & 0x00000008)
mode /= 4;
pci->agp.mode &= ~0x00000007;
pci->agp.mode |= (mode & 0x7);
} else
if (mode == 0) {
pci->agp.bridge = NULL;
return;
}
if (device->chipset == 0x18)
pci->agp.mode &= ~PCI_AGP_COMMAND_FW;
pci->agp.mtrr = arch_phys_wc_add(pci->agp.base, pci->agp.size);
}
