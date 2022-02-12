int
_nvkm_i2c_pad_fini(struct nouveau_object *object, bool suspend)
{
struct nvkm_i2c_pad *pad = (void *)object;
DBG("-> NULL\n");
pad->port = NULL;
return nouveau_object_fini(&pad->base, suspend);
}
int
_nvkm_i2c_pad_init(struct nouveau_object *object)
{
struct nvkm_i2c_pad *pad = (void *)object;
DBG("-> PORT:%02x\n", pad->next->index);
pad->port = pad->next;
return nouveau_object_init(&pad->base);
}
int
nvkm_i2c_pad_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, int index,
int size, void **pobject)
{
struct nouveau_i2c *i2c = (void *)engine;
struct nouveau_i2c_port *port;
struct nvkm_i2c_pad *pad;
int ret;
list_for_each_entry(port, &i2c->ports, head) {
pad = nvkm_i2c_pad(port);
if (pad->index == index) {
atomic_inc(&nv_object(pad)->refcount);
*pobject = pad;
return 1;
}
}
ret = nouveau_object_create_(parent, engine, oclass, 0, size, pobject);
pad = *pobject;
if (ret)
return ret;
pad->index = index;
return 0;
}
int
_nvkm_i2c_pad_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 index,
struct nouveau_object **pobject)
{
struct nvkm_i2c_pad *pad;
int ret;
ret = nvkm_i2c_pad_create(parent, engine, oclass, index, &pad);
*pobject = nv_object(pad);
return ret;
}
