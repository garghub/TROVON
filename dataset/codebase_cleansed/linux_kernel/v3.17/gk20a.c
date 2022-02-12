int
gk20a_bar_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_bar *bar;
int ret;
ret = nvc0_bar_ctor(parent, engine, oclass, data, size, pobject);
if (ret)
return ret;
bar = (struct nouveau_bar *)*pobject;
bar->iomap_uncached = true;
return 0;
}
