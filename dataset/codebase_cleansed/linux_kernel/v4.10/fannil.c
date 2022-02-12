static int
nvkm_fannil_get(struct nvkm_therm *therm)
{
return -ENODEV;
}
static int
nvkm_fannil_set(struct nvkm_therm *therm, int percent)
{
return -ENODEV;
}
int
nvkm_fannil_create(struct nvkm_therm *therm)
{
struct nvkm_fan *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
therm->fan = priv;
if (!priv)
return -ENOMEM;
priv->type = "none / external";
priv->get = nvkm_fannil_get;
priv->set = nvkm_fannil_set;
return 0;
}
