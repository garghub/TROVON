static int
nouveau_fannil_get(struct nouveau_therm *therm)
{
return -ENODEV;
}
static int
nouveau_fannil_set(struct nouveau_therm *therm, int percent)
{
return -ENODEV;
}
int
nouveau_fannil_create(struct nouveau_therm *therm)
{
struct nouveau_therm_priv *tpriv = (void *)therm;
struct nouveau_fan *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
tpriv->fan = priv;
if (!priv)
return -ENOMEM;
priv->type = "none / external";
priv->get = nouveau_fannil_get;
priv->set = nouveau_fannil_set;
return 0;
}
