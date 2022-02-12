static inline bool
nouveau_acpi_rom_supported(struct pci_dev *pdev)
{
return false;
}
static inline int
nouveau_acpi_get_bios_chunk(uint8_t *bios, int offset, int len)
{
return -EINVAL;
}
static u32
acpi_read_fast(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
u32 limit = (offset + length + 0xfff) & ~0xfff;
u32 start = offset & ~0x00000fff;
u32 fetch = limit - start;
if (nvbios_extend(bios, limit) > 0) {
int ret = nouveau_acpi_get_bios_chunk(bios->data, start, fetch);
if (ret == fetch)
return fetch;
}
return 0;
}
static u32
acpi_read_slow(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
u32 limit = (offset + length + 0xfff) & ~0xfff;
u32 start = offset & ~0xfff;
u32 fetch = 0;
if (nvbios_extend(bios, limit) > 0) {
while (start + fetch < limit) {
int ret = nouveau_acpi_get_bios_chunk(bios->data,
start + fetch,
0x1000);
if (ret != 0x1000)
break;
fetch += 0x1000;
}
}
return fetch;
}
static void *
acpi_init(struct nvkm_bios *bios, const char *name)
{
if (!nouveau_acpi_rom_supported(nv_device(bios)->pdev))
return ERR_PTR(-ENODEV);
return NULL;
}
