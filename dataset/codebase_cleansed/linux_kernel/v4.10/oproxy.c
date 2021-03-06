static int
nvkm_oproxy_mthd(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
return nvkm_object_mthd(nvkm_oproxy(object)->object, mthd, data, size);
}
static int
nvkm_oproxy_ntfy(struct nvkm_object *object, u32 mthd,
struct nvkm_event **pevent)
{
return nvkm_object_ntfy(nvkm_oproxy(object)->object, mthd, pevent);
}
static int
nvkm_oproxy_map(struct nvkm_object *object, u64 *addr, u32 *size)
{
return nvkm_object_map(nvkm_oproxy(object)->object, addr, size);
}
static int
nvkm_oproxy_rd08(struct nvkm_object *object, u64 addr, u8 *data)
{
return nvkm_object_rd08(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_rd16(struct nvkm_object *object, u64 addr, u16 *data)
{
return nvkm_object_rd16(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_rd32(struct nvkm_object *object, u64 addr, u32 *data)
{
return nvkm_object_rd32(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_wr08(struct nvkm_object *object, u64 addr, u8 data)
{
return nvkm_object_wr08(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_wr16(struct nvkm_object *object, u64 addr, u16 data)
{
return nvkm_object_wr16(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_wr32(struct nvkm_object *object, u64 addr, u32 data)
{
return nvkm_object_wr32(nvkm_oproxy(object)->object, addr, data);
}
static int
nvkm_oproxy_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
return nvkm_object_bind(nvkm_oproxy(object)->object,
parent, align, pgpuobj);
}
static int
nvkm_oproxy_sclass(struct nvkm_object *object, int index,
struct nvkm_oclass *oclass)
{
struct nvkm_oproxy *oproxy = nvkm_oproxy(object);
oclass->parent = oproxy->object;
if (!oproxy->object->func->sclass)
return -ENODEV;
return oproxy->object->func->sclass(oproxy->object, index, oclass);
}
static int
nvkm_oproxy_fini(struct nvkm_object *object, bool suspend)
{
struct nvkm_oproxy *oproxy = nvkm_oproxy(object);
int ret;
if (oproxy->func->fini[0]) {
ret = oproxy->func->fini[0](oproxy, suspend);
if (ret && suspend)
return ret;
}
if (oproxy->object->func->fini) {
ret = oproxy->object->func->fini(oproxy->object, suspend);
if (ret && suspend)
return ret;
}
if (oproxy->func->fini[1]) {
ret = oproxy->func->fini[1](oproxy, suspend);
if (ret && suspend)
return ret;
}
return 0;
}
static int
nvkm_oproxy_init(struct nvkm_object *object)
{
struct nvkm_oproxy *oproxy = nvkm_oproxy(object);
int ret;
if (oproxy->func->init[0]) {
ret = oproxy->func->init[0](oproxy);
if (ret)
return ret;
}
if (oproxy->object->func->init) {
ret = oproxy->object->func->init(oproxy->object);
if (ret)
return ret;
}
if (oproxy->func->init[1]) {
ret = oproxy->func->init[1](oproxy);
if (ret)
return ret;
}
return 0;
}
static void *
nvkm_oproxy_dtor(struct nvkm_object *object)
{
struct nvkm_oproxy *oproxy = nvkm_oproxy(object);
if (oproxy->func->dtor[0])
oproxy->func->dtor[0](oproxy);
nvkm_object_del(&oproxy->object);
if (oproxy->func->dtor[1])
oproxy->func->dtor[1](oproxy);
return oproxy;
}
void
nvkm_oproxy_ctor(const struct nvkm_oproxy_func *func,
const struct nvkm_oclass *oclass, struct nvkm_oproxy *oproxy)
{
nvkm_object_ctor(&nvkm_oproxy_func, oclass, &oproxy->base);
oproxy->func = func;
}
int
nvkm_oproxy_new_(const struct nvkm_oproxy_func *func,
const struct nvkm_oclass *oclass, struct nvkm_oproxy **poproxy)
{
if (!(*poproxy = kzalloc(sizeof(**poproxy), GFP_KERNEL)))
return -ENOMEM;
nvkm_oproxy_ctor(func, oclass, *poproxy);
return 0;
}
