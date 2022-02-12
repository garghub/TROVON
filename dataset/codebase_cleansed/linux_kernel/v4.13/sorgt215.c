void
gt215_sor_dp_audio(struct nvkm_ior *sor, int head, bool enable)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 soff = nv50_ior_base(sor);
const u32 data = 0x80000000 | (0x00000001 * enable);
const u32 mask = 0x8000000d;
nvkm_mask(device, 0x61c1e0 + soff, mask, data);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c1e0 + soff) & 0x80000000))
break;
);
}
int
gt215_sor_new(struct nvkm_disp *disp, int id)
{
return nv50_sor_new_(&gt215_sor, disp, id);
}
