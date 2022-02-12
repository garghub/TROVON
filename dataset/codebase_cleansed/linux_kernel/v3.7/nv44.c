static int
nv44_mc_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv44_mc_priv *priv;
int ret;
ret = nouveau_mc_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->intr = nouveau_mc_intr;
priv->base.intr_map = nv04_mc_intr;
return 0;
}
static int
nv44_mc_init(struct nouveau_object *object)
{
struct nv44_mc_priv *priv = (void *)object;
u32 tmp = nv_rd32(priv, 0x10020c);
nv_wr32(priv, 0x000200, 0xffffffff);
nv_wr32(priv, 0x001700, tmp);
nv_wr32(priv, 0x001704, 0);
nv_wr32(priv, 0x001708, 0);
nv_wr32(priv, 0x00170c, tmp);
return nouveau_mc_init(&priv->base);
}
