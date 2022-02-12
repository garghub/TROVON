static u32
prom_read(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
struct nvkm_device *device = data;
u32 i;
if (offset + length <= 0x00100000) {
for (i = offset; i < offset + length; i += 4)
*(u32 *)&bios->data[i] = nvkm_rd32(device, 0x300000 + i);
return length;
}
return 0;
}
static void
prom_fini(void *data)
{
struct nvkm_device *device = data;
nvkm_pci_rom_shadow(device->pci, true);
}
static void *
prom_init(struct nvkm_bios *bios, const char *name)
{
struct nvkm_device *device = bios->subdev.device;
if (device->card_type == NV_40 && device->chipset >= 0x4c)
return ERR_PTR(-ENODEV);
nvkm_pci_rom_shadow(device->pci, false);
return device;
}
