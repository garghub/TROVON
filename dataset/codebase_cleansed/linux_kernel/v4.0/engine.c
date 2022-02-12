struct nvkm_engine *
nvkm_engine(void *obj, int idx)
{
obj = nvkm_subdev(obj, idx);
if (obj && nv_iclass(obj, NV_ENGINE_CLASS))
return nv_engine(obj);
return NULL;
}
int
nvkm_engine_create_(struct nvkm_object *parent, struct nvkm_object *engobj,
struct nvkm_oclass *oclass, bool enable,
const char *iname, const char *fname,
int length, void **pobject)
{
struct nvkm_engine *engine;
int ret;
ret = nvkm_subdev_create_(parent, engobj, oclass, NV_ENGINE_CLASS,
iname, fname, length, pobject);
engine = *pobject;
if (ret)
return ret;
if (parent) {
struct nvkm_device *device = nv_device(parent);
int engidx = nv_engidx(engine);
if (device->disable_mask & (1ULL << engidx)) {
if (!nvkm_boolopt(device->cfgopt, iname, false)) {
nv_debug(engine, "engine disabled by hw/fw\n");
return -ENODEV;
}
nv_warn(engine, "ignoring hw/fw engine disable\n");
}
if (!nvkm_boolopt(device->cfgopt, iname, enable)) {
if (!enable)
nv_warn(engine, "disabled, %s=1 to enable\n", iname);
return -ENODEV;
}
}
INIT_LIST_HEAD(&engine->contexts);
spin_lock_init(&engine->lock);
return 0;
}
