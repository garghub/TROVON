static int
nva3_perfmon_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **object)
{
int ret = nv40_perfmon_ctor(parent, engine, oclass, data, size, object);
if (ret == 0) {
struct nv40_perfmon_priv *priv = (void *)*object;
ret = nouveau_perfdom_new(&priv->base, "pwr", 0, 0, 0, 0,
nva3_perfmon_pwr);
if (ret)
return ret;
priv->base.last = 3;
}
return ret;
}
