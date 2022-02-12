void
nv50_sor_clock(struct nvkm_ior *sor)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const int div = sor->asy.link == 3;
const u32 soff = nv50_ior_base(sor);
nvkm_mask(device, 0x614300 + soff, 0x00000707, (div << 8) | div);
}
static void
nv50_sor_power_wait(struct nvkm_device *device, u32 soff)
{
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
);
}
void
nv50_sor_power(struct nvkm_ior *sor, bool normal, bool pu,
bool data, bool vsync, bool hsync)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 soff = nv50_ior_base(sor);
const u32 shift = normal ? 0 : 16;
const u32 state = 0x80000000 | (0x00000001 * !!pu) << shift;
const u32 field = 0x80000000 | (0x00000001 << shift);
nv50_sor_power_wait(device, soff);
nvkm_mask(device, 0x61c004 + soff, field, state);
nv50_sor_power_wait(device, soff);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
);
}
void
nv50_sor_state(struct nvkm_ior *sor, struct nvkm_ior_state *state)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 coff = sor->id * 8 + (state == &sor->arm) * 4;
u32 ctrl = nvkm_rd32(device, 0x610b70 + coff);
state->proto_evo = (ctrl & 0x00000f00) >> 8;
switch (state->proto_evo) {
case 0: state->proto = LVDS; state->link = 1; break;
case 1: state->proto = TMDS; state->link = 1; break;
case 2: state->proto = TMDS; state->link = 2; break;
case 5: state->proto = TMDS; state->link = 3; break;
default:
state->proto = UNKNOWN;
break;
}
state->head = ctrl & 0x00000003;
}
int
nv50_sor_new_(const struct nvkm_ior_func *func, struct nvkm_disp *disp, int id)
{
struct nvkm_device *device = disp->engine.subdev.device;
if (!(nvkm_rd32(device, 0x610184) & (0x01000000 << id)))
return 0;
return nvkm_ior_new_(func, disp, SOR, id);
}
int
nv50_sor_new(struct nvkm_disp *disp, int id)
{
return nv50_sor_new_(&nv50_sor, disp, id);
}
