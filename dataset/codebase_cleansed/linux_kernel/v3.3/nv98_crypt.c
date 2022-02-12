static int
nv98_crypt_fini(struct drm_device *dev, int engine, bool suspend)
{
if (!(nv_rd32(dev, 0x000200) & 0x00004000))
return 0;
nv_mask(dev, 0x000200, 0x00004000, 0x00000000);
return 0;
}
static int
nv98_crypt_init(struct drm_device *dev, int engine)
{
nv_mask(dev, 0x000200, 0x00004000, 0x00000000);
nv_mask(dev, 0x000200, 0x00004000, 0x00004000);
return 0;
}
static void
nv98_crypt_destroy(struct drm_device *dev, int engine)
{
struct nv98_crypt_engine *pcrypt = nv_engine(dev, engine);
NVOBJ_ENGINE_DEL(dev, CRYPT);
kfree(pcrypt);
}
int
nv98_crypt_create(struct drm_device *dev)
{
struct nv98_crypt_engine *pcrypt;
pcrypt = kzalloc(sizeof(*pcrypt), GFP_KERNEL);
if (!pcrypt)
return -ENOMEM;
pcrypt->base.destroy = nv98_crypt_destroy;
pcrypt->base.init = nv98_crypt_init;
pcrypt->base.fini = nv98_crypt_fini;
NVOBJ_ENGINE_ADD(dev, CRYPT, &pcrypt->base);
return 0;
}
