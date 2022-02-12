static void
gf119_head_vblank_put(struct nvkm_head *head)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
const u32 hoff = head->id * 0x800;
nvkm_mask(device, 0x6100c0 + hoff, 0x00000001, 0x00000000);
}
static void
gf119_head_vblank_get(struct nvkm_head *head)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
const u32 hoff = head->id * 0x800;
nvkm_mask(device, 0x6100c0 + hoff, 0x00000001, 0x00000001);
}
static void
gf119_head_rgclk(struct nvkm_head *head, int div)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
nvkm_mask(device, 0x612200 + (head->id * 0x800), 0x0000000f, div);
}
static void
gf119_head_state(struct nvkm_head *head, struct nvkm_head_state *state)
{
struct nvkm_device *device = head->disp->engine.subdev.device;
const u32 hoff = (state == &head->asy) * 0x20000 + head->id * 0x300;
u32 data;
data = nvkm_rd32(device, 0x640414 + hoff);
state->vtotal = (data & 0xffff0000) >> 16;
state->htotal = (data & 0x0000ffff);
data = nvkm_rd32(device, 0x640418 + hoff);
state->vsynce = (data & 0xffff0000) >> 16;
state->hsynce = (data & 0x0000ffff);
data = nvkm_rd32(device, 0x64041c + hoff);
state->vblanke = (data & 0xffff0000) >> 16;
state->hblanke = (data & 0x0000ffff);
data = nvkm_rd32(device, 0x640420 + hoff);
state->vblanks = (data & 0xffff0000) >> 16;
state->hblanks = (data & 0x0000ffff);
state->hz = nvkm_rd32(device, 0x640450 + hoff);
data = nvkm_rd32(device, 0x640404 + hoff);
switch ((data & 0x000003c0) >> 6) {
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
int
gf119_head_new(struct nvkm_disp *disp, int id)
{
return nvkm_head_new_(&gf119_head, disp, id);
}
