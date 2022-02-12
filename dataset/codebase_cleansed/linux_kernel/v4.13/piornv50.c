static void
nv50_pior_clock(struct nvkm_ior *pior)
{
struct nvkm_device *device = pior->disp->engine.subdev.device;
const u32 poff = nv50_ior_base(pior);
nvkm_mask(device, 0x614380 + poff, 0x00000707, 0x00000001);
}
static int
nv50_pior_dp_links(struct nvkm_ior *pior, struct nvkm_i2c_aux *aux)
{
int ret = nvkm_i2c_aux_lnk_ctl(aux, pior->dp.nr, pior->dp.bw,
pior->dp.ef);
if (ret)
return ret;
return 1;
}
static void
nv50_pior_power_wait(struct nvkm_device *device, u32 poff)
{
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61e004 + poff) & 0x80000000))
break;
);
}
static void
nv50_pior_power(struct nvkm_ior *pior, bool normal, bool pu,
bool data, bool vsync, bool hsync)
{
struct nvkm_device *device = pior->disp->engine.subdev.device;
const u32 poff = nv50_ior_base(pior);
const u32 shift = normal ? 0 : 16;
const u32 state = 0x80000000 | (0x00000001 * !!pu) << shift;
const u32 field = 0x80000000 | (0x00000101 << shift);
nv50_pior_power_wait(device, poff);
nvkm_mask(device, 0x61e004 + poff, field, state);
nv50_pior_power_wait(device, poff);
}
void
nv50_pior_depth(struct nvkm_ior *ior, struct nvkm_ior_state *state, u32 ctrl)
{
if (state->head && state == &ior->asy) {
struct nvkm_head *head =
nvkm_head_find(ior->disp, __ffs(state->head));
if (!WARN_ON(!head)) {
struct nvkm_head_state *state = &head->asy;
switch ((ctrl & 0x000f0000) >> 16) {
case 6: state->or.depth = 30; break;
case 5: state->or.depth = 24; break;
case 2: state->or.depth = 18; break;
case 0: state->or.depth = 18; break;
default:
state->or.depth = 18;
WARN_ON(1);
break;
}
}
}
}
static void
nv50_pior_state(struct nvkm_ior *pior, struct nvkm_ior_state *state)
{
struct nvkm_device *device = pior->disp->engine.subdev.device;
const u32 coff = pior->id * 8 + (state == &pior->arm) * 4;
u32 ctrl = nvkm_rd32(device, 0x610b80 + coff);
state->proto_evo = (ctrl & 0x00000f00) >> 8;
state->rgdiv = 1;
switch (state->proto_evo) {
case 0: state->proto = TMDS; break;
default:
state->proto = UNKNOWN;
break;
}
state->head = ctrl & 0x00000003;
nv50_pior_depth(pior, state, ctrl);
}
int
nv50_pior_new(struct nvkm_disp *disp, int id)
{
struct nvkm_device *device = disp->engine.subdev.device;
if (!(nvkm_rd32(device, 0x610184) & (0x10000000 << id)))
return 0;
return nvkm_ior_new_(&nv50_pior, disp, PIOR, id);
}
