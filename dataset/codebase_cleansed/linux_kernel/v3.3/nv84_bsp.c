static int
nv84_bsp_fini(struct drm_device *dev, int engine, bool suspend)
{
if (!(nv_rd32(dev, 0x000200) & 0x00008000))
return 0;
nv_mask(dev, 0x000200, 0x00008000, 0x00000000);
return 0;
}
static int
nv84_bsp_init(struct drm_device *dev, int engine)
{
nv_mask(dev, 0x000200, 0x00008000, 0x00000000);
nv_mask(dev, 0x000200, 0x00008000, 0x00008000);
return 0;
}
static void
nv84_bsp_destroy(struct drm_device *dev, int engine)
{
struct nv84_bsp_engine *pbsp = nv_engine(dev, engine);
NVOBJ_ENGINE_DEL(dev, BSP);
kfree(pbsp);
}
int
nv84_bsp_create(struct drm_device *dev)
{
struct nv84_bsp_engine *pbsp;
pbsp = kzalloc(sizeof(*pbsp), GFP_KERNEL);
if (!pbsp)
return -ENOMEM;
pbsp->base.destroy = nv84_bsp_destroy;
pbsp->base.init = nv84_bsp_init;
pbsp->base.fini = nv84_bsp_fini;
NVOBJ_ENGINE_ADD(dev, BSP, &pbsp->base);
return 0;
}
