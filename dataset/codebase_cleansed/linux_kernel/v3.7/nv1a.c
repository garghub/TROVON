static int
nv1a_devinit_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv1a_devinit_priv *priv;
int ret;
ret = nouveau_devinit_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
return 0;
}
