static int
nv94_disp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_disp_priv *priv;
int ret;
ret = nouveau_disp_create(parent, engine, oclass, "PDISP",
"display", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_engine(priv)->sclass = nv94_disp_base_oclass;
nv_engine(priv)->cclass = &nv50_disp_cclass;
nv_subdev(priv)->intr = nv50_disp_intr;
priv->sclass = nv94_disp_sclass;
priv->head.nr = 2;
priv->dac.nr = 3;
priv->sor.nr = 4;
priv->dac.power = nv50_dac_power;
priv->dac.sense = nv50_dac_sense;
priv->sor.power = nv50_sor_power;
priv->sor.hdmi = nv84_hdmi_ctrl;
priv->sor.dp_train = nv94_sor_dp_train;
priv->sor.dp_train_init = nv94_sor_dp_train_init;
priv->sor.dp_train_fini = nv94_sor_dp_train_fini;
priv->sor.dp_lnkctl = nv94_sor_dp_lnkctl;
priv->sor.dp_drvctl = nv94_sor_dp_drvctl;
INIT_LIST_HEAD(&priv->base.vblank.list);
spin_lock_init(&priv->base.vblank.lock);
return 0;
}
