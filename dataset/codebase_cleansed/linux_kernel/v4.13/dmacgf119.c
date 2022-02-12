int
gf119_disp_dmac_bind(struct nv50_disp_dmac *chan,
struct nvkm_object *object, u32 handle)
{
return nvkm_ramht_insert(chan->base.root->ramht, object,
chan->base.chid.user, -9, handle,
chan->base.chid.user << 27 | 0x00000001);
}
void
gf119_disp_dmac_fini(struct nv50_disp_dmac *chan)
{
struct nv50_disp *disp = chan->base.root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int ctrl = chan->base.chid.ctrl;
int user = chan->base.chid.user;
nvkm_mask(device, 0x610490 + (ctrl * 0x0010), 0x00001010, 0x00001000);
nvkm_mask(device, 0x610490 + (ctrl * 0x0010), 0x00000003, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610490 + (ctrl * 0x10)) & 0x001e0000))
break;
) < 0) {
nvkm_error(subdev, "ch %d fini: %08x\n", user,
nvkm_rd32(device, 0x610490 + (ctrl * 0x10)));
}
nvkm_mask(device, 0x610090, 0x00000001 << user, 0x00000000);
nvkm_mask(device, 0x6100a0, 0x00000001 << user, 0x00000000);
}
static int
gf119_disp_dmac_init(struct nv50_disp_dmac *chan)
{
struct nv50_disp *disp = chan->base.root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int ctrl = chan->base.chid.ctrl;
int user = chan->base.chid.user;
nvkm_mask(device, 0x6100a0, 0x00000001 << user, 0x00000001 << user);
nvkm_wr32(device, 0x610494 + (ctrl * 0x0010), chan->push);
nvkm_wr32(device, 0x610498 + (ctrl * 0x0010), 0x00010000);
nvkm_wr32(device, 0x61049c + (ctrl * 0x0010), 0x00000001);
nvkm_mask(device, 0x610490 + (ctrl * 0x0010), 0x00000010, 0x00000010);
nvkm_wr32(device, 0x640000 + (ctrl * 0x1000), 0x00000000);
nvkm_wr32(device, 0x610490 + (ctrl * 0x0010), 0x00000013);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610490 + (ctrl * 0x10)) & 0x80000000))
break;
) < 0) {
nvkm_error(subdev, "ch %d init: %08x\n", user,
nvkm_rd32(device, 0x610490 + (ctrl * 0x10)));
return -EBUSY;
}
return 0;
}
