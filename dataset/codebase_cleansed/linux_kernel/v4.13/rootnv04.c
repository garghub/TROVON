static int
nv04_disp_mthd(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
struct nv04_disp_root *root = nv04_disp_root(object);
union {
struct nv04_disp_mthd_v0 v0;
} *args = data;
struct nvkm_head *head;
int id, ret = -ENOSYS;
nvif_ioctl(object, "disp mthd size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, true))) {
nvif_ioctl(object, "disp mthd vers %d mthd %02x head %d\n",
args->v0.version, args->v0.method, args->v0.head);
mthd = args->v0.method;
id = args->v0.head;
} else
return ret;
if (!(head = nvkm_head_find(root->disp, id)))
return -ENXIO;
switch (mthd) {
case NV04_DISP_SCANOUTPOS:
return nvkm_head_mthd_scanoutpos(object, head, data, size);
default:
break;
}
return -EINVAL;
}
static int
nv04_disp_root_new(struct nvkm_disp *disp, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
struct nv04_disp_root *root;
if (!(root = kzalloc(sizeof(*root), GFP_KERNEL)))
return -ENOMEM;
root->disp = disp;
*pobject = &root->object;
nvkm_object_ctor(&nv04_disp_root, oclass, &root->object);
return 0;
}
