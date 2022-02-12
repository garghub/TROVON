static u32
prom_read(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
u32 i;
if (offset + length <= 0x00100000) {
for (i = offset; i < offset + length; i += 4)
*(u32 *)&bios->data[i] = nv_rd32(bios, 0x300000 + i);
return length;
}
return 0;
}
static void
prom_fini(void *data)
{
struct nvkm_bios *bios = data;
if (nv_device(bios)->card_type < NV_50)
nv_mask(bios, 0x001850, 0x00000001, 0x00000001);
else
nv_mask(bios, 0x088050, 0x00000001, 0x00000001);
}
static void *
prom_init(struct nvkm_bios *bios, const char *name)
{
if (nv_device(bios)->card_type < NV_50) {
if (nv_device(bios)->card_type == NV_40 &&
nv_device(bios)->chipset >= 0x4c)
return ERR_PTR(-ENODEV);
nv_mask(bios, 0x001850, 0x00000001, 0x00000000);
} else {
nv_mask(bios, 0x088050, 0x00000001, 0x00000000);
}
return bios;
}
