int
nv50_disp_oimm_new(const struct nv50_disp_chan_func *func,
const struct nv50_disp_chan_mthd *mthd,
struct nv50_disp_root *root, int ctrl, int user,
const struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
union {
struct nv50_disp_overlay_v0 v0;
} *args = data;
struct nvkm_object *parent = oclass->parent;
struct nv50_disp *disp = root->disp;
int head, ret = -ENOSYS;
nvif_ioctl(parent, "create disp overlay size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent, "create disp overlay vers %d head %d\n",
args->v0.version, args->v0.head);
if (!nvkm_head_find(&disp->base, args->v0.head))
return -EINVAL;
head = args->v0.head;
} else
return ret;
return nv50_disp_chan_new_(func, mthd, root, ctrl + head, user + head,
head, oclass, pobject);
}
