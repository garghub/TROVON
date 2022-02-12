static int
nv98_ppp_init(struct nouveau_object *object)
{
struct nv98_ppp_priv *priv = (void *)object;
int ret;
ret = nouveau_falcon_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x086010, 0x0000ffd2);
nv_wr32(priv, 0x08601c, 0x0000fff2);
return 0;
}
static int
nv98_ppp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv98_ppp_priv *priv;
int ret;
ret = nouveau_falcon_create(parent, engine, oclass, 0x086000, true,
"PPPP", "ppp", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00400002;
nv_engine(priv)->cclass = &nv98_ppp_cclass;
nv_engine(priv)->sclass = nv98_ppp_sclass;
return 0;
}
