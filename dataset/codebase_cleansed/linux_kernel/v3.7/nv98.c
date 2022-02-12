static int
nv98_ppp_context_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv98_ppp_chan *priv;
int ret;
ret = nouveau_ppp_context_create(parent, engine, oclass, NULL,
0, 0, 0, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
return 0;
}
static void
nv98_ppp_context_dtor(struct nouveau_object *object)
{
struct nv98_ppp_chan *priv = (void *)object;
nouveau_ppp_context_destroy(&priv->base);
}
static int
nv98_ppp_context_init(struct nouveau_object *object)
{
struct nv98_ppp_chan *priv = (void *)object;
int ret;
ret = nouveau_ppp_context_init(&priv->base);
if (ret)
return ret;
return 0;
}
static int
nv98_ppp_context_fini(struct nouveau_object *object, bool suspend)
{
struct nv98_ppp_chan *priv = (void *)object;
return nouveau_ppp_context_fini(&priv->base, suspend);
}
static void
nv98_ppp_intr(struct nouveau_subdev *subdev)
{
}
static int
nv98_ppp_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv98_ppp_priv *priv;
int ret;
ret = nouveau_ppp_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00400002;
nv_subdev(priv)->intr = nv98_ppp_intr;
nv_engine(priv)->cclass = &nv98_ppp_cclass;
nv_engine(priv)->sclass = nv98_ppp_sclass;
return 0;
}
static void
nv98_ppp_dtor(struct nouveau_object *object)
{
struct nv98_ppp_priv *priv = (void *)object;
nouveau_ppp_destroy(&priv->base);
}
static int
nv98_ppp_init(struct nouveau_object *object)
{
struct nv98_ppp_priv *priv = (void *)object;
int ret;
ret = nouveau_ppp_init(&priv->base);
if (ret)
return ret;
return 0;
}
static int
nv98_ppp_fini(struct nouveau_object *object, bool suspend)
{
struct nv98_ppp_priv *priv = (void *)object;
return nouveau_ppp_fini(&priv->base, suspend);
}
