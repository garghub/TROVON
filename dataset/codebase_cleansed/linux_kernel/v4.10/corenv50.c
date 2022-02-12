int
nv50_disp_core_new(const struct nv50_disp_dmac_func *func,
const struct nv50_disp_chan_mthd *mthd,
struct nv50_disp_root *root, int chid,
const struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
union {
struct nv50_disp_core_channel_dma_v0 v0;
} *args = data;
struct nvkm_object *parent = oclass->parent;
u64 push;
int ret = -ENOSYS;
nvif_ioctl(parent, "create disp core channel dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent, "create disp core channel dma vers %d "
"pushbuf %016llx\n",
args->v0.version, args->v0.pushbuf);
push = args->v0.pushbuf;
} else
return ret;
return nv50_disp_dmac_new_(func, mthd, root, chid, 0,
push, oclass, pobject);
}
static void
nv50_disp_core_fini(struct nv50_disp_dmac *chan)
{
struct nv50_disp *disp = chan->base.root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
nvkm_mask(device, 0x610200, 0x00000010, 0x00000000);
nvkm_mask(device, 0x610200, 0x00000003, 0x00000000);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610200) & 0x001e0000))
break;
) < 0) {
nvkm_error(subdev, "core fini: %08x\n",
nvkm_rd32(device, 0x610200));
}
nvkm_mask(device, 0x610028, 0x00010001, 0x00000000);
}
static int
nv50_disp_core_init(struct nv50_disp_dmac *chan)
{
struct nv50_disp *disp = chan->base.root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
nvkm_mask(device, 0x610028, 0x00010000, 0x00010000);
if ((nvkm_rd32(device, 0x610200) & 0x009f0000) == 0x00020000)
nvkm_mask(device, 0x610200, 0x00800000, 0x00800000);
if ((nvkm_rd32(device, 0x610200) & 0x003f0000) == 0x00030000)
nvkm_mask(device, 0x610200, 0x00600000, 0x00600000);
nvkm_wr32(device, 0x610204, chan->push);
nvkm_wr32(device, 0x610208, 0x00010000);
nvkm_wr32(device, 0x61020c, 0x00000000);
nvkm_mask(device, 0x610200, 0x00000010, 0x00000010);
nvkm_wr32(device, 0x640000, 0x00000000);
nvkm_wr32(device, 0x610200, 0x01000013);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610200) & 0x80000000))
break;
) < 0) {
nvkm_error(subdev, "core init: %08x\n",
nvkm_rd32(device, 0x610200));
return -EBUSY;
}
return 0;
}
