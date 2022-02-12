static void
nv04_head_vblank_put(struct nvkm_head *head)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
nvkm_wr32(device, 0x600140 + (head->id * 0x2000) , 0x00000000);
}
static void
nv04_head_vblank_get(struct nvkm_head *head)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
nvkm_wr32(device, 0x600140 + (head->id * 0x2000) , 0x00000001);
}
static void
nv04_head_rgpos(struct nvkm_head *head, u16 *hline, u16 *vline)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
u32 data = nvkm_rd32(device, 0x600868 + (head->id * 0x2000));
*hline = (data & 0xffff0000) >> 16;
*vline = (data & 0x0000ffff);
}
static void
nv04_head_state(struct nvkm_head *head, struct nvkm_head_state *state)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
const u32 hoff = head->id * 0x0200;
state->vblanks = nvkm_rd32(device, 0x680800 + hoff) & 0x0000ffff;
state->vtotal = nvkm_rd32(device, 0x680804 + hoff) & 0x0000ffff;
state->vblanke = state->vtotal - 1;
state->hblanks = nvkm_rd32(device, 0x680820 + hoff) & 0x0000ffff;
state->htotal = nvkm_rd32(device, 0x680824 + hoff) & 0x0000ffff;
state->hblanke = state->htotal - 1;
}
int
nv04_head_new(struct nvkm_disp *disp, int id)
{
return nvkm_head_new_(&nv04_head, disp, id);
}
