static int
nv98_ppp_fini(struct drm_device *dev, int engine, bool suspend)
{
if (!(nv_rd32(dev, 0x000200) & 0x00000002))
return 0;
nv_mask(dev, 0x000200, 0x00000002, 0x00000000);
return 0;
}
static int
nv98_ppp_init(struct drm_device *dev, int engine)
{
nv_mask(dev, 0x000200, 0x00000002, 0x00000000);
nv_mask(dev, 0x000200, 0x00000002, 0x00000002);
return 0;
}
static void
nv98_ppp_destroy(struct drm_device *dev, int engine)
{
struct nv98_ppp_engine *pppp = nv_engine(dev, engine);
NVOBJ_ENGINE_DEL(dev, PPP);
kfree(pppp);
}
int
nv98_ppp_create(struct drm_device *dev)
{
struct nv98_ppp_engine *pppp;
pppp = kzalloc(sizeof(*pppp), GFP_KERNEL);
if (!pppp)
return -ENOMEM;
pppp->base.destroy = nv98_ppp_destroy;
pppp->base.init = nv98_ppp_init;
pppp->base.fini = nv98_ppp_fini;
NVOBJ_ENGINE_ADD(dev, PPP, &pppp->base);
return 0;
}
