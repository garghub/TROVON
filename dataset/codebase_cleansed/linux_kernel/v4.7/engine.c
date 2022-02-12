void
nvkm_engine_unref(struct nvkm_engine **pengine)
{
struct nvkm_engine *engine = *pengine;
if (engine) {
mutex_lock(&engine->subdev.mutex);
if (--engine->usecount == 0)
nvkm_subdev_fini(&engine->subdev, false);
mutex_unlock(&engine->subdev.mutex);
*pengine = NULL;
}
}
struct nvkm_engine *
nvkm_engine_ref(struct nvkm_engine *engine)
{
if (engine) {
mutex_lock(&engine->subdev.mutex);
if (++engine->usecount == 1) {
int ret = nvkm_subdev_init(&engine->subdev);
if (ret) {
engine->usecount--;
mutex_unlock(&engine->subdev.mutex);
return ERR_PTR(ret);
}
}
mutex_unlock(&engine->subdev.mutex);
}
return engine;
}
void
nvkm_engine_tile(struct nvkm_engine *engine, int region)
{
struct nvkm_fb *fb = engine->subdev.device->fb;
if (engine->func->tile)
engine->func->tile(engine, region, &fb->tile.region[region]);
}
static void
nvkm_engine_intr(struct nvkm_subdev *subdev)
{
struct nvkm_engine *engine = nvkm_engine(subdev);
if (engine->func->intr)
engine->func->intr(engine);
}
static int
nvkm_engine_fini(struct nvkm_subdev *subdev, bool suspend)
{
struct nvkm_engine *engine = nvkm_engine(subdev);
if (engine->func->fini)
return engine->func->fini(engine, suspend);
return 0;
}
static int
nvkm_engine_init(struct nvkm_subdev *subdev)
{
struct nvkm_engine *engine = nvkm_engine(subdev);
struct nvkm_fb *fb = subdev->device->fb;
int ret = 0, i;
s64 time;
if (!engine->usecount) {
nvkm_trace(subdev, "init skipped, engine has no users\n");
return ret;
}
if (engine->func->oneinit && !engine->subdev.oneinit) {
nvkm_trace(subdev, "one-time init running...\n");
time = ktime_to_us(ktime_get());
ret = engine->func->oneinit(engine);
if (ret) {
nvkm_trace(subdev, "one-time init failed, %d\n", ret);
return ret;
}
engine->subdev.oneinit = true;
time = ktime_to_us(ktime_get()) - time;
nvkm_trace(subdev, "one-time init completed in %lldus\n", time);
}
if (engine->func->init)
ret = engine->func->init(engine);
for (i = 0; fb && i < fb->tile.regions; i++)
nvkm_engine_tile(engine, i);
return ret;
}
static void *
nvkm_engine_dtor(struct nvkm_subdev *subdev)
{
struct nvkm_engine *engine = nvkm_engine(subdev);
if (engine->func->dtor)
return engine->func->dtor(engine);
return engine;
}
int
nvkm_engine_ctor(const struct nvkm_engine_func *func,
struct nvkm_device *device, int index, bool enable,
struct nvkm_engine *engine)
{
nvkm_subdev_ctor(&nvkm_engine_func, device, index, &engine->subdev);
engine->func = func;
if (!nvkm_boolopt(device->cfgopt, nvkm_subdev_name[index], enable)) {
nvkm_debug(&engine->subdev, "disabled\n");
return -ENODEV;
}
spin_lock_init(&engine->lock);
return 0;
}
int
nvkm_engine_new_(const struct nvkm_engine_func *func,
struct nvkm_device *device, int index, bool enable,
struct nvkm_engine **pengine)
{
if (!(*pengine = kzalloc(sizeof(**pengine), GFP_KERNEL)))
return -ENOMEM;
return nvkm_engine_ctor(func, device, index, enable, *pengine);
}
