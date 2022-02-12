static int
gf100_mspdec_init(struct nvkm_object *object)
{
struct gf100_mspdec_priv *priv = (void *)object;
int ret;
ret = nvkm_falcon_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x085010, 0x0000fff2);
nv_wr32(priv, 0x08501c, 0x0000fff2);
return 0;
}
static int
gf100_mspdec_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct gf100_mspdec_priv *priv;
int ret;
ret = nvkm_falcon_create(parent, engine, oclass, 0x085000, true,
"PMSPDEC", "mspdec", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00020000;
nv_subdev(priv)->intr = nvkm_falcon_intr;
nv_engine(priv)->cclass = &gf100_mspdec_cclass;
nv_engine(priv)->sclass = gf100_mspdec_sclass;
return 0;
}
