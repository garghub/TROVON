void
gf119_disp_root_fini(struct nv50_disp_root *root)
{
struct nvkm_device *device = root->disp->base.engine.subdev.device;
nvkm_wr32(device, 0x6100b0, 0x00000000);
}
int
gf119_disp_root_init(struct nv50_disp_root *root)
{
struct nv50_disp *disp = root->disp;
struct nvkm_head *head;
struct nvkm_device *device = disp->base.engine.subdev.device;
u32 tmp;
int i;
list_for_each_entry(head, &disp->base.head, head) {
const u32 hoff = head->id * 0x800;
tmp = nvkm_rd32(device, 0x616104 + hoff);
nvkm_wr32(device, 0x6101b4 + hoff, tmp);
tmp = nvkm_rd32(device, 0x616108 + hoff);
nvkm_wr32(device, 0x6101b8 + hoff, tmp);
tmp = nvkm_rd32(device, 0x61610c + hoff);
nvkm_wr32(device, 0x6101bc + hoff, tmp);
}
for (i = 0; i < disp->func->dac.nr; i++) {
tmp = nvkm_rd32(device, 0x61a000 + (i * 0x800));
nvkm_wr32(device, 0x6101c0 + (i * 0x800), tmp);
}
for (i = 0; i < disp->func->sor.nr; i++) {
tmp = nvkm_rd32(device, 0x61c000 + (i * 0x800));
nvkm_wr32(device, 0x6301c4 + (i * 0x800), tmp);
}
if (nvkm_rd32(device, 0x6100ac) & 0x00000100) {
nvkm_wr32(device, 0x6100ac, 0x00000100);
nvkm_mask(device, 0x6194e8, 0x00000001, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0)
return -EBUSY;
}
nvkm_wr32(device, 0x610010, (root->instmem->addr >> 8) | 9);
nvkm_wr32(device, 0x610090, 0x00000000);
nvkm_wr32(device, 0x6100a0, 0x00000000);
nvkm_wr32(device, 0x6100b0, 0x00000307);
list_for_each_entry(head, &disp->base.head, head) {
const u32 hoff = head->id * 0x800;
nvkm_mask(device, 0x616308 + hoff, 0x00000111, 0x00000010);
}
return 0;
}
static int
gf119_disp_root_new(struct nvkm_disp *disp, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
return nv50_disp_root_new_(&gf119_disp_root, disp, oclass,
data, size, pobject);
}
