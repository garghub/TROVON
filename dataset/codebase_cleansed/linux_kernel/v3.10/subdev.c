void
nouveau_subdev_reset(struct nouveau_object *subdev)
{
nv_trace(subdev, "resetting...\n");
nv_ofuncs(subdev)->fini(subdev, false);
nv_debug(subdev, "reset\n");
}
int
nouveau_subdev_init(struct nouveau_subdev *subdev)
{
int ret = nouveau_object_init(&subdev->base);
if (ret)
return ret;
nouveau_subdev_reset(&subdev->base);
return 0;
}
int
_nouveau_subdev_init(struct nouveau_object *object)
{
return nouveau_subdev_init(nv_subdev(object));
}
int
nouveau_subdev_fini(struct nouveau_subdev *subdev, bool suspend)
{
if (subdev->unit) {
nv_mask(subdev, 0x000200, subdev->unit, 0x00000000);
nv_mask(subdev, 0x000200, subdev->unit, subdev->unit);
}
return nouveau_object_fini(&subdev->base, suspend);
}
int
_nouveau_subdev_fini(struct nouveau_object *object, bool suspend)
{
return nouveau_subdev_fini(nv_subdev(object), suspend);
}
void
nouveau_subdev_destroy(struct nouveau_subdev *subdev)
{
int subidx = nv_hclass(subdev) & 0xff;
nv_device(subdev)->subdev[subidx] = NULL;
nouveau_object_destroy(&subdev->base);
}
void
_nouveau_subdev_dtor(struct nouveau_object *object)
{
nouveau_subdev_destroy(nv_subdev(object));
}
int
nouveau_subdev_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, u32 pclass,
const char *subname, const char *sysname,
int size, void **pobject)
{
struct nouveau_subdev *subdev;
int ret;
ret = nouveau_object_create_(parent, engine, oclass, pclass |
NV_SUBDEV_CLASS, size, pobject);
subdev = *pobject;
if (ret)
return ret;
__mutex_init(&subdev->mutex, subname, &oclass->lock_class_key);
subdev->name = subname;
if (parent) {
struct nouveau_device *device = nv_device(parent);
int subidx = nv_hclass(subdev) & 0xff;
subdev->debug = nouveau_dbgopt(device->dbgopt, subname);
subdev->mmio = nv_subdev(device)->mmio;
device->subdev[subidx] = *pobject;
}
return 0;
}
