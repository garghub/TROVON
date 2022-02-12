static int
nv98_ppp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv98_ppp_priv *priv;
int ret;
ret = nouveau_engine_create(parent, engine, oclass, true,
"PPPP", "ppp", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00400002;
nv_engine(priv)->cclass = &nv98_ppp_cclass;
nv_engine(priv)->sclass = nv98_ppp_sclass;
return 0;
}
