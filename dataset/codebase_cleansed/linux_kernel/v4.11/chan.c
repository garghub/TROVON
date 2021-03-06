static int
nvkm_fifo_chan_child_fini(struct nvkm_oproxy *base, bool suspend)
{
struct nvkm_fifo_chan_object *object =
container_of(base, typeof(*object), oproxy);
struct nvkm_engine *engine = object->oproxy.object->engine;
struct nvkm_fifo_chan *chan = object->chan;
struct nvkm_fifo_engn *engn = &chan->engn[engine->subdev.index];
const char *name = nvkm_subdev_name[engine->subdev.index];
int ret = 0;
if (--engn->usecount)
return 0;
if (chan->func->engine_fini) {
ret = chan->func->engine_fini(chan, engine, suspend);
if (ret) {
nvif_error(&chan->object,
"detach %s failed, %d\n", name, ret);
return ret;
}
}
if (engn->object) {
ret = nvkm_object_fini(engn->object, suspend);
if (ret && suspend)
return ret;
}
nvif_trace(&chan->object, "detached %s\n", name);
return ret;
}
static int
nvkm_fifo_chan_child_init(struct nvkm_oproxy *base)
{
struct nvkm_fifo_chan_object *object =
container_of(base, typeof(*object), oproxy);
struct nvkm_engine *engine = object->oproxy.object->engine;
struct nvkm_fifo_chan *chan = object->chan;
struct nvkm_fifo_engn *engn = &chan->engn[engine->subdev.index];
const char *name = nvkm_subdev_name[engine->subdev.index];
int ret;
if (engn->usecount++)
return 0;
if (engn->object) {
ret = nvkm_object_init(engn->object);
if (ret)
return ret;
}
if (chan->func->engine_init) {
ret = chan->func->engine_init(chan, engine);
if (ret) {
nvif_error(&chan->object,
"attach %s failed, %d\n", name, ret);
return ret;
}
}
nvif_trace(&chan->object, "attached %s\n", name);
return 0;
}
static void
nvkm_fifo_chan_child_del(struct nvkm_oproxy *base)
{
struct nvkm_fifo_chan_object *object =
container_of(base, typeof(*object), oproxy);
struct nvkm_engine *engine = object->oproxy.base.engine;
struct nvkm_fifo_chan *chan = object->chan;
struct nvkm_fifo_engn *engn = &chan->engn[engine->subdev.index];
if (chan->func->object_dtor)
chan->func->object_dtor(chan, object->hash);
if (!--engn->refcount) {
if (chan->func->engine_dtor)
chan->func->engine_dtor(chan, engine);
nvkm_object_del(&engn->object);
if (chan->vm)
atomic_dec(&chan->vm->engref[engine->subdev.index]);
}
}
static int
nvkm_fifo_chan_child_new(const struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_engine *engine = oclass->engine;
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(oclass->parent);
struct nvkm_fifo_engn *engn = &chan->engn[engine->subdev.index];
struct nvkm_fifo_chan_object *object;
int ret = 0;
if (!(object = kzalloc(sizeof(*object), GFP_KERNEL)))
return -ENOMEM;
nvkm_oproxy_ctor(&nvkm_fifo_chan_child_func, oclass, &object->oproxy);
object->chan = chan;
*pobject = &object->oproxy.base;
if (!engn->refcount++) {
struct nvkm_oclass cclass = {
.client = oclass->client,
.engine = oclass->engine,
};
if (chan->vm)
atomic_inc(&chan->vm->engref[engine->subdev.index]);
if (engine->func->fifo.cclass) {
ret = engine->func->fifo.cclass(chan, &cclass,
&engn->object);
} else
if (engine->func->cclass) {
ret = nvkm_object_new_(engine->func->cclass, &cclass,
NULL, 0, &engn->object);
}
if (ret)
return ret;
if (chan->func->engine_ctor) {
ret = chan->func->engine_ctor(chan, oclass->engine,
engn->object);
if (ret)
return ret;
}
}
ret = oclass->base.ctor(&(const struct nvkm_oclass) {
.base = oclass->base,
.engn = oclass->engn,
.handle = oclass->handle,
.object = oclass->object,
.client = oclass->client,
.parent = engn->object ?
engn->object :
oclass->parent,
.engine = engine,
}, data, size, &object->oproxy.object);
if (ret)
return ret;
if (chan->func->object_ctor) {
object->hash =
chan->func->object_ctor(chan, object->oproxy.object);
if (object->hash < 0)
return object->hash;
}
return 0;
}
static int
nvkm_fifo_chan_child_get(struct nvkm_object *object, int index,
struct nvkm_oclass *oclass)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
struct nvkm_fifo *fifo = chan->fifo;
struct nvkm_device *device = fifo->engine.subdev.device;
struct nvkm_engine *engine;
u64 mask = chan->engines;
int ret, i, c;
for (; c = 0, i = __ffs64(mask), mask; mask &= ~(1ULL << i)) {
if (!(engine = nvkm_device_engine(device, i)))
continue;
oclass->engine = engine;
oclass->base.oclass = 0;
if (engine->func->fifo.sclass) {
ret = engine->func->fifo.sclass(oclass, index);
if (oclass->base.oclass) {
if (!oclass->base.ctor)
oclass->base.ctor = nvkm_object_new;
oclass->ctor = nvkm_fifo_chan_child_new;
return 0;
}
index -= ret;
continue;
}
while (engine->func->sclass[c].oclass) {
if (c++ == index) {
oclass->base = engine->func->sclass[index];
if (!oclass->base.ctor)
oclass->base.ctor = nvkm_object_new;
oclass->ctor = nvkm_fifo_chan_child_new;
return 0;
}
}
index -= c;
}
return -EINVAL;
}
static int
nvkm_fifo_chan_ntfy(struct nvkm_object *object, u32 type,
struct nvkm_event **pevent)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
if (chan->func->ntfy)
return chan->func->ntfy(chan, type, pevent);
return -ENODEV;
}
static int
nvkm_fifo_chan_map(struct nvkm_object *object, u64 *addr, u32 *size)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
*addr = chan->addr;
*size = chan->size;
return 0;
}
static int
nvkm_fifo_chan_rd32(struct nvkm_object *object, u64 addr, u32 *data)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
if (unlikely(!chan->user)) {
chan->user = ioremap(chan->addr, chan->size);
if (!chan->user)
return -ENOMEM;
}
if (unlikely(addr + 4 > chan->size))
return -EINVAL;
*data = ioread32_native(chan->user + addr);
return 0;
}
static int
nvkm_fifo_chan_wr32(struct nvkm_object *object, u64 addr, u32 data)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
if (unlikely(!chan->user)) {
chan->user = ioremap(chan->addr, chan->size);
if (!chan->user)
return -ENOMEM;
}
if (unlikely(addr + 4 > chan->size))
return -EINVAL;
iowrite32_native(data, chan->user + addr);
return 0;
}
static int
nvkm_fifo_chan_fini(struct nvkm_object *object, bool suspend)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
chan->func->fini(chan);
return 0;
}
static int
nvkm_fifo_chan_init(struct nvkm_object *object)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
chan->func->init(chan);
return 0;
}
static void *
nvkm_fifo_chan_dtor(struct nvkm_object *object)
{
struct nvkm_fifo_chan *chan = nvkm_fifo_chan(object);
struct nvkm_fifo *fifo = chan->fifo;
void *data = chan->func->dtor(chan);
unsigned long flags;
spin_lock_irqsave(&fifo->lock, flags);
if (!list_empty(&chan->head)) {
__clear_bit(chan->chid, fifo->mask);
list_del(&chan->head);
}
spin_unlock_irqrestore(&fifo->lock, flags);
if (chan->user)
iounmap(chan->user);
nvkm_vm_ref(NULL, &chan->vm, NULL);
nvkm_gpuobj_del(&chan->push);
nvkm_gpuobj_del(&chan->inst);
return data;
}
int
nvkm_fifo_chan_ctor(const struct nvkm_fifo_chan_func *func,
struct nvkm_fifo *fifo, u32 size, u32 align, bool zero,
u64 vm, u64 push, u64 engines, int bar, u32 base, u32 user,
const struct nvkm_oclass *oclass,
struct nvkm_fifo_chan *chan)
{
struct nvkm_client *client = oclass->client;
struct nvkm_device *device = fifo->engine.subdev.device;
struct nvkm_mmu *mmu = device->mmu;
struct nvkm_dmaobj *dmaobj;
unsigned long flags;
int ret;
nvkm_object_ctor(&nvkm_fifo_chan_func, oclass, &chan->object);
chan->func = func;
chan->fifo = fifo;
chan->engines = engines;
INIT_LIST_HEAD(&chan->head);
ret = nvkm_gpuobj_new(device, size, align, zero, NULL, &chan->inst);
if (ret)
return ret;
if (push) {
dmaobj = nvkm_dmaobj_search(client, push);
if (IS_ERR(dmaobj))
return PTR_ERR(dmaobj);
ret = nvkm_object_bind(&dmaobj->object, chan->inst, -16,
&chan->push);
if (ret)
return ret;
}
if (!vm && mmu) {
if (!client->vm || client->vm->mmu == mmu) {
ret = nvkm_vm_ref(client->vm, &chan->vm, NULL);
if (ret)
return ret;
} else {
return -EINVAL;
}
} else {
return -ENOENT;
}
spin_lock_irqsave(&fifo->lock, flags);
chan->chid = find_first_zero_bit(fifo->mask, NVKM_FIFO_CHID_NR);
if (chan->chid >= NVKM_FIFO_CHID_NR) {
spin_unlock_irqrestore(&fifo->lock, flags);
return -ENOSPC;
}
list_add(&chan->head, &fifo->chan);
__set_bit(chan->chid, fifo->mask);
spin_unlock_irqrestore(&fifo->lock, flags);
chan->addr = device->func->resource_addr(device, bar) +
base + user * chan->chid;
chan->size = user;
nvkm_fifo_cevent(fifo);
return 0;
}
