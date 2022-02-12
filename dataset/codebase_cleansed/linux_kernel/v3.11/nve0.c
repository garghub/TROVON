static int
nve0_vp_init(struct nouveau_object *object)
{
struct nve0_vp_priv *priv = (void *)object;
int ret;
ret = nouveau_falcon_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x085010, 0x0000fff2);
nv_wr32(priv, 0x08501c, 0x0000fff2);
return 0;
}
static int
nve0_vp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nve0_vp_priv *priv;
int ret;
ret = nouveau_falcon_create(parent, engine, oclass, 0x085000, true,
"PVP", "vp", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00020000;
nv_subdev(priv)->intr = nouveau_falcon_intr;
nv_engine(priv)->cclass = &nve0_vp_cclass;
nv_engine(priv)->sclass = nve0_vp_sclass;
return 0;
}
