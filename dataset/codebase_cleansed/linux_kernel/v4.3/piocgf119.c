static void
gf119_disp_pioc_fini(struct nv50_disp_chan *chan)
{
struct nv50_disp *disp = chan->root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int chid = chan->chid;
nvkm_mask(device, 0x610490 + (chid * 0x10), 0x00000001, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610490 + (chid * 0x10)) & 0x00030000))
break;
) < 0) {
nvkm_error(subdev, "ch %d fini: %08x\n", chid,
nvkm_rd32(device, 0x610490 + (chid * 0x10)));
}
nvkm_mask(device, 0x610090, 0x00000001 << chid, 0x00000000);
nvkm_mask(device, 0x6100a0, 0x00000001 << chid, 0x00000000);
}
static int
gf119_disp_pioc_init(struct nv50_disp_chan *chan)
{
struct nv50_disp *disp = chan->root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int chid = chan->chid;
nvkm_mask(device, 0x6100a0, 0x00000001 << chid, 0x00000001 << chid);
nvkm_wr32(device, 0x610490 + (chid * 0x10), 0x00000001);
if (nvkm_msec(device, 2000,
u32 tmp = nvkm_rd32(device, 0x610490 + (chid * 0x10));
if ((tmp & 0x00030000) == 0x00010000)
break;
) < 0) {
nvkm_error(subdev, "ch %d init: %08x\n", chid,
nvkm_rd32(device, 0x610490 + (chid * 0x10)));
return -EBUSY;
}
return 0;
}
