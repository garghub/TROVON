int
gm107_sor_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
struct nvkm_device *device = outp->base.disp->engine.subdev.device;
const u32 soff = outp->base.or * 0x800;
const u32 data = 0x01010101 * pattern;
if (outp->base.info.sorconf.link & 1)
nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, data);
else
nvkm_mask(device, 0x61c12c + soff, 0x0f0f0f0f, data);
return 0;
}
int
gm107_sor_dp_new(struct nvkm_disp *disp, int index,
struct dcb_output *dcbE, struct nvkm_output **poutp)
{
return nvkm_output_dp_new_(&gm107_sor_dp_func, disp, index, dcbE, poutp);
}
