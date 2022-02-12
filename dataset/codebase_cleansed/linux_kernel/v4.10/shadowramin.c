static u32
pramin_read(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
struct nvkm_device *device = bios->subdev.device;
u32 i;
if (offset + length <= 0x00100000) {
for (i = offset; i < offset + length; i += 4)
*(u32 *)&bios->data[i] = nvkm_rd32(device, 0x700000 + i);
return length;
}
return 0;
}
static void
pramin_fini(void *data)
{
struct priv *priv = data;
if (priv) {
struct nvkm_device *device = priv->bios->subdev.device;
nvkm_wr32(device, 0x001700, priv->bar0);
kfree(priv);
}
}
static void *
pramin_init(struct nvkm_bios *bios, const char *name)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct nvkm_device *device = subdev->device;
struct priv *priv = NULL;
u64 addr = 0;
if (device->card_type < NV_50)
return NULL;
if (device->card_type >= GM100)
addr = nvkm_rd32(device, 0x021c04);
else
if (device->card_type >= NV_C0)
addr = nvkm_rd32(device, 0x022500);
if (addr & 0x00000001) {
nvkm_debug(subdev, "... display disabled\n");
return ERR_PTR(-ENODEV);
}
addr = nvkm_rd32(device, 0x619f04);
if (!(addr & 0x00000008)) {
nvkm_debug(subdev, "... not enabled\n");
return ERR_PTR(-ENODEV);
}
if ( (addr & 0x00000003) != 1) {
nvkm_debug(subdev, "... not in vram\n");
return ERR_PTR(-ENODEV);
}
addr = (addr & 0xffffff00) << 8;
if (!addr) {
addr = (u64)nvkm_rd32(device, 0x001700) << 16;
addr += 0xf0000;
}
if (!(priv = kmalloc(sizeof(*priv), GFP_KERNEL))) {
nvkm_error(subdev, "... out of memory\n");
return ERR_PTR(-ENOMEM);
}
priv->bios = bios;
priv->bar0 = nvkm_rd32(device, 0x001700);
nvkm_wr32(device, 0x001700, addr >> 16);
return priv;
}
