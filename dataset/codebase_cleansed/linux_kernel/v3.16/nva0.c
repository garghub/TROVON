static int
nva0_disp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_disp_priv *priv;
int ret;
ret = nouveau_disp_create(parent, engine, oclass, 2, "PDISP",
"display", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_engine(priv)->sclass = nva0_disp_base_oclass;
nv_engine(priv)->cclass = &nv50_disp_cclass;
nv_subdev(priv)->intr = nv50_disp_intr;
INIT_WORK(&priv->supervisor, nv50_disp_intr_supervisor);
priv->sclass = nva0_disp_sclass;
priv->head.nr = 2;
priv->dac.nr = 3;
priv->sor.nr = 2;
priv->pior.nr = 3;
priv->dac.power = nv50_dac_power;
priv->dac.sense = nv50_dac_sense;
priv->sor.power = nv50_sor_power;
priv->sor.hdmi = nv84_hdmi_ctrl;
priv->pior.power = nv50_pior_power;
return 0;
}
