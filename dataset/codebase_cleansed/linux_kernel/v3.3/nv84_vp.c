static int
nv84_vp_fini(struct drm_device *dev, int engine, bool suspend)
{
if (!(nv_rd32(dev, 0x000200) & 0x00020000))
return 0;
nv_mask(dev, 0x000200, 0x00020000, 0x00000000);
return 0;
}
static int
nv84_vp_init(struct drm_device *dev, int engine)
{
nv_mask(dev, 0x000200, 0x00020000, 0x00000000);
nv_mask(dev, 0x000200, 0x00020000, 0x00020000);
return 0;
}
static void
nv84_vp_destroy(struct drm_device *dev, int engine)
{
struct nv84_vp_engine *pvp = nv_engine(dev, engine);
NVOBJ_ENGINE_DEL(dev, VP);
kfree(pvp);
}
int
nv84_vp_create(struct drm_device *dev)
{
struct nv84_vp_engine *pvp;
pvp = kzalloc(sizeof(*pvp), GFP_KERNEL);
if (!pvp)
return -ENOMEM;
pvp->base.destroy = nv84_vp_destroy;
pvp->base.init = nv84_vp_init;
pvp->base.fini = nv84_vp_fini;
NVOBJ_ENGINE_ADD(dev, VP, &pvp->base);
return 0;
}
