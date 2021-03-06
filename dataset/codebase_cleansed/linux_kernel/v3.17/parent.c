int
nouveau_parent_sclass(struct nouveau_object *parent, u16 handle,
struct nouveau_object **pengine,
struct nouveau_oclass **poclass)
{
struct nouveau_sclass *sclass;
struct nouveau_engine *engine;
struct nouveau_oclass *oclass;
u64 mask;
sclass = nv_parent(parent)->sclass;
while (sclass) {
if ((sclass->oclass->handle & 0xffff) == handle) {
*pengine = parent->engine;
*poclass = sclass->oclass;
return 0;
}
sclass = sclass->sclass;
}
mask = nv_parent(parent)->engine;
while (mask) {
int i = __ffs64(mask);
if (nv_iclass(parent, NV_CLIENT_CLASS))
engine = nv_engine(nv_client(parent)->device);
else
engine = nouveau_engine(parent, i);
if (engine) {
oclass = engine->sclass;
while (oclass->ofuncs) {
if ((oclass->handle & 0xffff) == handle) {
*pengine = nv_object(engine);
*poclass = oclass;
return 0;
}
oclass++;
}
}
mask &= ~(1ULL << i);
}
return -EINVAL;
}
int
nouveau_parent_lclass(struct nouveau_object *parent, u32 *lclass, int size)
{
struct nouveau_sclass *sclass;
struct nouveau_engine *engine;
struct nouveau_oclass *oclass;
int nr = -1, i;
u64 mask;
sclass = nv_parent(parent)->sclass;
while (sclass) {
if (++nr < size)
lclass[nr] = sclass->oclass->handle & 0xffff;
sclass = sclass->sclass;
}
mask = nv_parent(parent)->engine;
while (i = __ffs64(mask), mask) {
engine = nouveau_engine(parent, i);
if (engine && (oclass = engine->sclass)) {
while (oclass->ofuncs) {
if (++nr < size)
lclass[nr] = oclass->handle & 0xffff;
oclass++;
}
}
mask &= ~(1ULL << i);
}
return nr + 1;
}
int
nouveau_parent_create_(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, u32 pclass,
struct nouveau_oclass *sclass, u64 engcls,
int size, void **pobject)
{
struct nouveau_parent *object;
struct nouveau_sclass *nclass;
int ret;
ret = nouveau_object_create_(parent, engine, oclass, pclass |
NV_PARENT_CLASS, size, pobject);
object = *pobject;
if (ret)
return ret;
while (sclass && sclass->ofuncs) {
nclass = kzalloc(sizeof(*nclass), GFP_KERNEL);
if (!nclass)
return -ENOMEM;
nclass->sclass = object->sclass;
object->sclass = nclass;
nclass->engine = engine ? nv_engine(engine) : NULL;
nclass->oclass = sclass;
sclass++;
}
object->engine = engcls;
return 0;
}
void
nouveau_parent_destroy(struct nouveau_parent *parent)
{
struct nouveau_sclass *sclass;
while ((sclass = parent->sclass)) {
parent->sclass = sclass->sclass;
kfree(sclass);
}
nouveau_object_destroy(&parent->base);
}
void
_nouveau_parent_dtor(struct nouveau_object *object)
{
nouveau_parent_destroy(nv_parent(object));
}
