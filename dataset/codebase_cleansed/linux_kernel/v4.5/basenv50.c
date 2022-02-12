int
nv50_disp_base_new(const struct nv50_disp_dmac_func *func,
const struct nv50_disp_chan_mthd *mthd,
struct nv50_disp_root *root, int chid,
const struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
union {
struct nv50_disp_base_channel_dma_v0 v0;
} *args = data;
struct nvkm_object *parent = oclass->parent;
struct nv50_disp *disp = root->disp;
int head, ret = -ENOSYS;
u64 push;
nvif_ioctl(parent, "create disp base channel dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent, "create disp base channel dma vers %d "
"pushbuf %016llx head %d\n",
args->v0.version, args->v0.pushbuf, args->v0.head);
if (args->v0.head > disp->base.head.nr)
return -EINVAL;
push = args->v0.pushbuf;
head = args->v0.head;
} else
return ret;
return nv50_disp_dmac_new_(func, mthd, root, chid + head,
head, push, oclass, pobject);
}
