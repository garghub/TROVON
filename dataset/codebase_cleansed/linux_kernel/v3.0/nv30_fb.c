void
nv30_fb_init_tile_region(struct drm_device *dev, int i, uint32_t addr,
uint32_t size, uint32_t pitch, uint32_t flags)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_tile_reg *tile = &dev_priv->tile.reg[i];
tile->addr = addr | 1;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
void
nv30_fb_free_tile_region(struct drm_device *dev, int i)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_tile_reg *tile = &dev_priv->tile.reg[i];
tile->addr = tile->limit = tile->pitch = 0;
}
static int
calc_bias(struct drm_device *dev, int k, int i, int j)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
int b = (dev_priv->chipset > 0x30 ?
nv_rd32(dev, 0x122c + 0x10 * k + 0x4 * j) >> (4 * (i ^ 1)) :
0) & 0xf;
return 2 * (b & 0x8 ? b - 0x10 : b);
}
static int
calc_ref(struct drm_device *dev, int l, int k, int i)
{
int j, x = 0;
for (j = 0; j < 4; j++) {
int m = (l >> (8 * i) & 0xff) + calc_bias(dev, k, i, j);
x |= (0x80 | clamp(m, 0, 0x1f)) << (8 * j);
}
return x;
}
int
nv30_fb_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
int i, j;
pfb->num_tiles = NV10_PFB_TILE__SIZE;
for (i = 0; i < pfb->num_tiles; i++)
pfb->set_tile_region(dev, i);
if (dev_priv->chipset == 0x30 ||
dev_priv->chipset == 0x31 ||
dev_priv->chipset == 0x35) {
int n = (dev_priv->chipset == 0x31 ? 2 : 4);
int l = nv_rd32(dev, 0x1003d0);
for (i = 0; i < n; i++) {
for (j = 0; j < 3; j++)
nv_wr32(dev, 0x10037c + 0xc * i + 0x4 * j,
calc_ref(dev, l, 0, j));
for (j = 0; j < 2; j++)
nv_wr32(dev, 0x1003ac + 0x8 * i + 0x4 * j,
calc_ref(dev, l, 1, j));
}
}
return 0;
}
void
nv30_fb_takedown(struct drm_device *dev)
{
}
