void
nvkm_subdev_intr(struct nvkm_subdev *subdev)
{
if (subdev->func->intr)
subdev->func->intr(subdev);
}
int
nvkm_subdev_fini(struct nvkm_subdev *subdev, bool suspend)
{
struct nvkm_device *device = subdev->device;
const char *action = suspend ? "suspend" : "fini";
s64 time;
nvkm_trace(subdev, "%s running...\n", action);
time = ktime_to_us(ktime_get());
if (subdev->func->fini) {
int ret = subdev->func->fini(subdev, suspend);
if (ret) {
nvkm_error(subdev, "%s failed, %d\n", action, ret);
if (suspend)
return ret;
}
}
nvkm_mc_reset(device->mc, subdev->index);
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "%s completed in %lldus\n", action, time);
return 0;
}
int
nvkm_subdev_preinit(struct nvkm_subdev *subdev)
{
s64 time;
nvkm_trace(subdev, "preinit running...\n");
time = ktime_to_us(ktime_get());
if (subdev->func->preinit) {
int ret = subdev->func->preinit(subdev);
if (ret) {
nvkm_error(subdev, "preinit failed, %d\n", ret);
return ret;
}
}
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "preinit completed in %lldus\n", time);
return 0;
}
int
nvkm_subdev_init(struct nvkm_subdev *subdev)
{
s64 time;
int ret;
nvkm_trace(subdev, "init running...\n");
time = ktime_to_us(ktime_get());
if (subdev->func->oneinit && !subdev->oneinit) {
s64 time;
nvkm_trace(subdev, "one-time init running...\n");
time = ktime_to_us(ktime_get());
ret = subdev->func->oneinit(subdev);
if (ret) {
nvkm_error(subdev, "one-time init failed, %d\n", ret);
return ret;
}
subdev->oneinit = true;
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "one-time init completed in %lldus\n", time);
}
if (subdev->func->init) {
ret = subdev->func->init(subdev);
if (ret) {
nvkm_error(subdev, "init failed, %d\n", ret);
return ret;
}
}
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "init completed in %lldus\n", time);
return 0;
}
void
nvkm_subdev_del(struct nvkm_subdev **psubdev)
{
struct nvkm_subdev *subdev = *psubdev;
s64 time;
if (subdev && !WARN_ON(!subdev->func)) {
nvkm_trace(subdev, "destroy running...\n");
time = ktime_to_us(ktime_get());
if (subdev->func->dtor)
*psubdev = subdev->func->dtor(subdev);
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "destroy completed in %lldus\n", time);
kfree(*psubdev);
*psubdev = NULL;
}
}
void
nvkm_subdev_ctor(const struct nvkm_subdev_func *func,
struct nvkm_device *device, int index,
struct nvkm_subdev *subdev)
{
const char *name = nvkm_subdev_name[index];
subdev->func = func;
subdev->device = device;
subdev->index = index;
__mutex_init(&subdev->mutex, name, &nvkm_subdev_lock_class[index]);
subdev->debug = nvkm_dbgopt(device->dbgopt, name);
}
