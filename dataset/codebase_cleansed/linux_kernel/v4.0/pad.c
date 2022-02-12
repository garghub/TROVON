int
_nvkm_i2c_pad_fini(struct nvkm_object *object, bool suspend)
{
struct nvkm_i2c_pad *pad = (void *)object;
DBG("-> NULL\n");
pad->port = NULL;
return nvkm_object_fini(&pad->base, suspend);
}
int
_nvkm_i2c_pad_init(struct nvkm_object *object)
{
struct nvkm_i2c_pad *pad = (void *)object;
DBG("-> PORT:%02x\n", pad->next->index);
pad->port = pad->next;
return nvkm_object_init(&pad->base);
}
int
nvkm_i2c_pad_create_(struct nvkm_object *parent,
struct nvkm_object *engine,
struct nvkm_oclass *oclass, int index,
int size, void **pobject)
{
struct nvkm_i2c *i2c = nvkm_i2c(parent);
struct nvkm_i2c_port *port;
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
ret = nvkm_object_create_(parent, engine, oclass, 0, size, pobject);
pad = *pobject;
if (ret)
return ret;
pad->index = index;
return 0;
}
int
_nvkm_i2c_pad_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 index,
struct nvkm_object **pobject)
{
struct nvkm_i2c_pad *pad;
int ret;
ret = nvkm_i2c_pad_create(parent, engine, oclass, index, &pad);
*pobject = nv_object(pad);
return ret;
}
