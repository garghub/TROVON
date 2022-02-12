void
gt215_hda_eld(struct nvkm_ior *ior, u8 *data, u8 size)
{
struct nvkm_device *device = ior->disp->engine.subdev.device;
const u32 soff = ior->id * 0x800;
int i;
for (i = 0; i < size; i++)
nvkm_wr32(device, 0x61c440 + soff, (i << 8) | data[i]);
for (; i < 0x60; i++)
nvkm_wr32(device, 0x61c440 + soff, (i << 8));
nvkm_mask(device, 0x61c448 + soff, 0x80000002, 0x80000002);
}
void
gt215_hda_hpd(struct nvkm_ior *ior, int head, bool present)
{
struct nvkm_device *device = ior->disp->engine.subdev.device;
u32 data = 0x80000000;
u32 mask = 0x80000001;
if (present)
data |= 0x00000001;
else
mask |= 0x00000002;
nvkm_mask(device, 0x61c448 + ior->id * 0x800, mask, data);
}
