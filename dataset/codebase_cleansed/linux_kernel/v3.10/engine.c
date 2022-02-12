int
nouveau_engine_create_(struct nouveau_object *parent,
struct nouveau_object *engobj,
struct nouveau_oclass *oclass, bool enable,
const char *iname, const char *fname,
int length, void **pobject)
{
struct nouveau_engine *engine;
int ret;
ret = nouveau_subdev_create_(parent, engobj, oclass, NV_ENGINE_CLASS,
iname, fname, length, pobject);
engine = *pobject;
if (ret)
return ret;
if ( parent &&
!nouveau_boolopt(nv_device(parent)->cfgopt, iname, enable)) {
if (!enable)
nv_warn(engine, "disabled, %s=1 to enable\n", iname);
return -ENODEV;
}
INIT_LIST_HEAD(&engine->contexts);
spin_lock_init(&engine->lock);
return 0;
}
