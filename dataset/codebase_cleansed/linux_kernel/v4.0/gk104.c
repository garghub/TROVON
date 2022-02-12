static int
gk104_msvld_init(struct nvkm_object *object)
{
struct gk104_msvld_priv *priv = (void *)object;
int ret;
ret = nvkm_falcon_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x084010, 0x0000fff2);
nv_wr32(priv, 0x08401c, 0x0000fff2);
return 0;
}
static int
gk104_msvld_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct gk104_msvld_priv *priv;
int ret;
ret = nvkm_falcon_create(parent, engine, oclass, 0x084000, true,
"PMSVLD", "msvld", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00008000;
nv_subdev(priv)->intr = nvkm_falcon_intr;
nv_engine(priv)->cclass = &gk104_msvld_cclass;
nv_engine(priv)->sclass = gk104_msvld_sclass;
return 0;
}
