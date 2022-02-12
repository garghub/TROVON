static int
nv108_pwr_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv108_pwr_priv *priv;
int ret;
ret = nouveau_pwr_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.code.data = nv108_pwr_code;
priv->base.code.size = sizeof(nv108_pwr_code);
priv->base.data.data = nv108_pwr_data;
priv->base.data.size = sizeof(nv108_pwr_data);
return 0;
}
