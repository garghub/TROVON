static void
gf119_dac_clock(struct nvkm_ior *dac)
{
struct nvkm_device *device = dac->disp->engine.subdev.device;
const u32 doff = nv50_ior_base(dac);
nvkm_mask(device, 0x612280 + doff, 0x07070707, 0x00000000);
}
static void
gf119_dac_state(struct nvkm_ior *dac, struct nvkm_ior_state *state)
{
struct nvkm_device *device = dac->disp->engine.subdev.device;
const u32 coff = (state == &dac->asy) * 0x20000 + dac->id * 0x20;
u32 ctrl = nvkm_rd32(device, 0x640180 + coff);
state->proto_evo = (ctrl & 0x00000f00) >> 8;
switch (state->proto_evo) {
case 0: state->proto = CRT; break;
default:
state->proto = UNKNOWN;
break;
}
state->head = ctrl & 0x0000000f;
}
int
gf119_dac_new(struct nvkm_disp *disp, int id)
{
struct nvkm_device *device = disp->engine.subdev.device;
if (!(nvkm_rd32(device, 0x612004) & (0x00000010 << id)))
return 0;
return nvkm_ior_new_(&gf119_dac, disp, DAC, id);
}
