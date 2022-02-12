void
gm107_sor_dp_pattern(struct nvkm_ior *sor, int pattern)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 soff = nv50_ior_base(sor);
const u32 data = 0x01010101 * pattern;
if (sor->asy.link & 1)
nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, data);
else
nvkm_mask(device, 0x61c12c + soff, 0x0f0f0f0f, data);
}
int
gm107_sor_new(struct nvkm_disp *disp, int id)
{
return gf119_sor_new_(&gm107_sor, disp, id);
}
