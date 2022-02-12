void
gf119_sor_dp_watermark(struct nvkm_ior *sor, int head, u8 watermark)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 hoff = head * 0x800;
nvkm_mask(device, 0x616610 + hoff, 0x0800003f, 0x08000000 | watermark);
}
void
gf119_sor_dp_audio_sym(struct nvkm_ior *sor, int head, u16 h, u32 v)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 hoff = head * 0x800;
nvkm_mask(device, 0x616620 + hoff, 0x0000ffff, h);
nvkm_mask(device, 0x616624 + hoff, 0x00ffffff, v);
}
void
gf119_sor_dp_audio(struct nvkm_ior *sor, int head, bool enable)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 hoff = 0x800 * head;
const u32 data = 0x80000000 | (0x00000001 * enable);
const u32 mask = 0x8000000d;
nvkm_mask(device, 0x616618 + hoff, mask, data);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x616618 + hoff) & 0x80000000))
break;
);
}
void
gf119_sor_dp_vcpi(struct nvkm_ior *sor, int head,
u8 slot, u8 slot_nr, u16 pbn, u16 aligned)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 hoff = head * 0x800;
nvkm_mask(device, 0x616588 + hoff, 0x00003f3f, (slot_nr << 8) | slot);
nvkm_mask(device, 0x61658c + hoff, 0xffffffff, (aligned << 16) | pbn);
}
void
gf119_sor_dp_drive(struct nvkm_ior *sor, int ln, int pc, int dc, int pe, int pu)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 loff = nv50_sor_link(sor);
const u32 shift = sor->func->dp.lanes[ln] * 8;
u32 data[4];
data[0] = nvkm_rd32(device, 0x61c118 + loff) & ~(0x000000ff << shift);
data[1] = nvkm_rd32(device, 0x61c120 + loff) & ~(0x000000ff << shift);
data[2] = nvkm_rd32(device, 0x61c130 + loff);
if ((data[2] & 0x0000ff00) < (pu << 8) || ln == 0)
data[2] = (data[2] & ~0x0000ff00) | (pu << 8);
nvkm_wr32(device, 0x61c118 + loff, data[0] | (dc << shift));
nvkm_wr32(device, 0x61c120 + loff, data[1] | (pe << shift));
nvkm_wr32(device, 0x61c130 + loff, data[2]);
data[3] = nvkm_rd32(device, 0x61c13c + loff) & ~(0x000000ff << shift);
nvkm_wr32(device, 0x61c13c + loff, data[3] | (pc << shift));
}
void
gf119_sor_dp_pattern(struct nvkm_ior *sor, int pattern)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 soff = nv50_ior_base(sor);
nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, 0x01010101 * pattern);
}
int
gf119_sor_dp_links(struct nvkm_ior *sor, struct nvkm_i2c_aux *aux)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 soff = nv50_ior_base(sor);
const u32 loff = nv50_sor_link(sor);
u32 dpctrl = 0x00000000;
u32 clksor = 0x00000000;
clksor |= sor->dp.bw << 18;
dpctrl |= ((1 << sor->dp.nr) - 1) << 16;
if (sor->dp.mst)
dpctrl |= 0x40000000;
if (sor->dp.ef)
dpctrl |= 0x00004000;
nvkm_mask(device, 0x612300 + soff, 0x007c0000, clksor);
nvkm_mask(device, 0x61c10c + loff, 0x401f4000, dpctrl);
return 0;
}
void
gf119_sor_clock(struct nvkm_ior *sor)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const int div = sor->asy.link == 3;
const u32 soff = nv50_ior_base(sor);
if (sor->asy.proto == TMDS) {
nvkm_mask(device, 0x612300 + soff, 0x007c0000, 0x0a << 18);
}
nvkm_mask(device, 0x612300 + soff, 0x00000707, (div << 8) | div);
}
void
gf119_sor_state(struct nvkm_ior *sor, struct nvkm_ior_state *state)
{
struct nvkm_device *device = sor->disp->engine.subdev.device;
const u32 coff = (state == &sor->asy) * 0x20000 + sor->id * 0x20;
u32 ctrl = nvkm_rd32(device, 0x640200 + coff);
state->proto_evo = (ctrl & 0x00000f00) >> 8;
switch (state->proto_evo) {
case 0: state->proto = LVDS; state->link = 1; break;
case 1: state->proto = TMDS; state->link = 1; break;
case 2: state->proto = TMDS; state->link = 2; break;
case 5: state->proto = TMDS; state->link = 3; break;
case 8: state->proto = DP; state->link = 1; break;
case 9: state->proto = DP; state->link = 2; break;
default:
state->proto = UNKNOWN;
break;
}
state->head = ctrl & 0x0000000f;
}
int
gf119_sor_new_(const struct nvkm_ior_func *func, struct nvkm_disp *disp, int id)
{
struct nvkm_device *device = disp->engine.subdev.device;
if (!(nvkm_rd32(device, 0x612004) & (0x00000100 << id)))
return 0;
return nvkm_ior_new_(func, disp, SOR, id);
}
int
gf119_sor_new(struct nvkm_disp *disp, int id)
{
return gf119_sor_new_(&gf119_sor, disp, id);
}
