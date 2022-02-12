static int
nvc0_clock_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nvc0_clock_priv *priv;
int ret;
ret = nouveau_clock_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.pll_calc = nva3_clock_pll_calc;
return 0;
}
