static int
nv04_disp_scanoutpos(struct nv04_disp_root *root,
void *data, u32 size, int head)
{
struct nvkm_device *device = root->disp->engine.subdev.device;
struct nvkm_object *object = &root->object;
const u32 hoff = head * 0x2000;
union {
struct nv04_disp_scanoutpos_v0 v0;
} *args = data;
u32 line;
int ret = -ENOSYS;
nvif_ioctl(object, "disp scanoutpos size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp scanoutpos vers %d\n",
args->v0.version);
args->v0.vblanks = nvkm_rd32(device, 0x680800 + hoff) & 0xffff;
args->v0.vtotal = nvkm_rd32(device, 0x680804 + hoff) & 0xffff;
args->v0.vblanke = args->v0.vtotal - 1;
args->v0.hblanks = nvkm_rd32(device, 0x680820 + hoff) & 0xffff;
args->v0.htotal = nvkm_rd32(device, 0x680824 + hoff) & 0xffff;
args->v0.hblanke = args->v0.htotal - 1;
if (!args->v0.vtotal || !args->v0.htotal)
return -ENOTSUPP;
args->v0.time[0] = ktime_to_ns(ktime_get());
line = nvkm_rd32(device, 0x600868 + hoff);
args->v0.time[1] = ktime_to_ns(ktime_get());
args->v0.hline = (line & 0xffff0000) >> 16;
args->v0.vline = (line & 0x0000ffff);
} else
return ret;
return 0;
}
static int
nv04_disp_mthd(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
struct nv04_disp_root *root = nv04_disp_root(object);
union {
struct nv04_disp_mthd_v0 v0;
} *args = data;
int head, ret = -ENOSYS;
nvif_ioctl(object, "disp mthd size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, true))) {
nvif_ioctl(object, "disp mthd vers %d mthd %02x head %d\n",
args->v0.version, args->v0.method, args->v0.head);
mthd = args->v0.method;
head = args->v0.head;
} else
return ret;
if (head < 0 || head >= 2)
return -ENXIO;
switch (mthd) {
case NV04_DISP_SCANOUTPOS:
return nv04_disp_scanoutpos(root, data, size, head);
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
