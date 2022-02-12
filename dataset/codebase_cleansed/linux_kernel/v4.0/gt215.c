static int
gt215_disp_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nv50_disp_priv *priv;
int ret;
ret = nvkm_disp_create(parent, engine, oclass, 2, "PDISP",
"display", &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
ret = nvkm_event_init(&nv50_disp_chan_uevent, 1, 9, &priv->uevent);
if (ret)
return ret;
nv_engine(priv)->sclass = gt215_disp_main_oclass;
nv_engine(priv)->cclass = &nv50_disp_cclass;
nv_subdev(priv)->intr = nv50_disp_intr;
INIT_WORK(&priv->supervisor, nv50_disp_intr_supervisor);
priv->sclass = gt215_disp_sclass;
priv->head.nr = 2;
priv->dac.nr = 3;
priv->sor.nr = 4;
priv->pior.nr = 3;
priv->dac.power = nv50_dac_power;
priv->dac.sense = nv50_dac_sense;
priv->sor.power = nv50_sor_power;
priv->sor.hda_eld = gt215_hda_eld;
priv->sor.hdmi = gt215_hdmi_ctrl;
priv->pior.power = nv50_pior_power;
return 0;
}
