static void
nv50_disp_pioc_fini(struct nv50_disp_chan *chan)
{
struct nv50_disp *disp = chan->root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int ctrl = chan->chid.ctrl;
int user = chan->chid.user;
nvkm_mask(device, 0x610200 + (ctrl * 0x10), 0x00000001, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x00030000))
break;
) < 0) {
nvkm_error(subdev, "ch %d timeout: %08x\n", user,
nvkm_rd32(device, 0x610200 + (ctrl * 0x10)));
}
}
static int
nv50_disp_pioc_init(struct nv50_disp_chan *chan)
{
struct nv50_disp *disp = chan->root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
int ctrl = chan->chid.ctrl;
int user = chan->chid.user;
nvkm_wr32(device, 0x610200 + (ctrl * 0x10), 0x00002000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x00030000))
break;
) < 0) {
nvkm_error(subdev, "ch %d timeout0: %08x\n", user,
nvkm_rd32(device, 0x610200 + (ctrl * 0x10)));
return -EBUSY;
}
nvkm_wr32(device, 0x610200 + (ctrl * 0x10), 0x00000001);
if (nvkm_msec(device, 2000,
u32 tmp = nvkm_rd32(device, 0x610200 + (ctrl * 0x10));
if ((tmp & 0x00030000) == 0x00010000)
break;
) < 0) {
nvkm_error(subdev, "ch %d timeout1: %08x\n", user,
nvkm_rd32(device, 0x610200 + (ctrl * 0x10)));
return -EBUSY;
}
return 0;
}
