static int
nvf0_disp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_disp_priv *priv;
int heads = nv_rd32(parent, 0x022448);
int ret;
ret = nouveau_disp_create(parent, engine, oclass, heads,
"PDISP", "display", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_engine(priv)->sclass = nvf0_disp_base_oclass;
nv_engine(priv)->cclass = &nv50_disp_cclass;
nv_subdev(priv)->intr = nvd0_disp_intr;
INIT_WORK(&priv->supervisor, nvd0_disp_intr_supervisor);
priv->sclass = nvf0_disp_sclass;
priv->head.nr = heads;
priv->dac.nr = 3;
priv->sor.nr = 4;
priv->dac.power = nv50_dac_power;
priv->dac.sense = nv50_dac_sense;
priv->sor.power = nv50_sor_power;
priv->sor.hda_eld = nvd0_hda_eld;
priv->sor.hdmi = nvd0_hdmi_ctrl;
priv->sor.dp = &nvd0_sor_dp_func;
return 0;
}
