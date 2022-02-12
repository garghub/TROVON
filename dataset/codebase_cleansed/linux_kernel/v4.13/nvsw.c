static int
nvkm_nvsw_mthd_(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
struct nvkm_nvsw *nvsw = nvkm_nvsw(object);
if (nvsw->func->mthd)
return nvsw->func->mthd(nvsw, mthd, data, size);
return -ENODEV;
}
static int
nvkm_nvsw_ntfy_(struct nvkm_object *object, u32 mthd,
struct nvkm_event **pevent)
{
struct nvkm_nvsw *nvsw = nvkm_nvsw(object);
switch (mthd) {
case NV04_NVSW_NTFY_UEVENT:
*pevent = &nvsw->chan->event;
return 0;
default:
break;
}
return -EINVAL;
}
int
nvkm_nvsw_new_(const struct nvkm_nvsw_func *func, struct nvkm_sw_chan *chan,
const struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_nvsw *nvsw;
if (!(nvsw = kzalloc(sizeof(*nvsw), GFP_KERNEL)))
return -ENOMEM;
*pobject = &nvsw->object;
nvkm_object_ctor(&nvkm_nvsw_, oclass, &nvsw->object);
nvsw->func = func;
nvsw->chan = chan;
return 0;
}
int
nvkm_nvsw_new(struct nvkm_sw_chan *chan, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
return nvkm_nvsw_new_(&nvkm_nvsw, chan, oclass, data, size, pobject);
}
