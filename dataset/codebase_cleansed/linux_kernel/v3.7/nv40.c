static inline int
nv44_graph_class(struct nouveau_device *device)
{
if ((device->chipset & 0xf0) == 0x60)
return 1;
return !(0x0baf & (1 << (device->chipset & 0x0f)));
}
static void
nv40_fb_tile_prog(struct nouveau_fb *pfb, int i, struct nouveau_fb_tile *tile)
{
nv_wr32(pfb, 0x100604 + (i * 0x10), tile->limit);
nv_wr32(pfb, 0x100608 + (i * 0x10), tile->pitch);
nv_wr32(pfb, 0x100600 + (i * 0x10), tile->addr);
}
static void
nv40_fb_init_gart(struct nv40_fb_priv *priv)
{
nv_wr32(priv, 0x100800, 0x00000001);
}
static void
nv44_fb_init_gart(struct nv40_fb_priv *priv)
{
nv_wr32(priv, 0x100850, 0x80000000);
nv_wr32(priv, 0x100800, 0x00000001);
}
static int
nv40_fb_init(struct nouveau_object *object)
{
struct nv40_fb_priv *priv = (void *)object;
int ret;
ret = nouveau_fb_init(&priv->base);
if (ret)
return ret;
switch (nv_device(priv)->chipset) {
case 0x40:
case 0x45:
nv_mask(priv, 0x10033c, 0x00008000, 0x00000000);
break;
default:
if (nv44_graph_class(nv_device(priv)))
nv44_fb_init_gart(priv);
else
nv40_fb_init_gart(priv);
break;
}
return 0;
}
static int
nv40_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_device *device = nv_device(parent);
struct nv40_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
if (device->chipset == 0x40) {
u32 pbus1218 = nv_rd32(priv, 0x001218);
switch (pbus1218 & 0x00000300) {
case 0x00000000: priv->base.ram.type = NV_MEM_TYPE_SDRAM; break;
case 0x00000100: priv->base.ram.type = NV_MEM_TYPE_DDR1; break;
case 0x00000200: priv->base.ram.type = NV_MEM_TYPE_GDDR3; break;
case 0x00000300: priv->base.ram.type = NV_MEM_TYPE_DDR2; break;
}
} else
if (device->chipset == 0x49 || device->chipset == 0x4b) {
u32 pfb914 = nv_rd32(priv, 0x100914);
switch (pfb914 & 0x00000003) {
case 0x00000000: priv->base.ram.type = NV_MEM_TYPE_DDR1; break;
case 0x00000001: priv->base.ram.type = NV_MEM_TYPE_DDR2; break;
case 0x00000002: priv->base.ram.type = NV_MEM_TYPE_GDDR3; break;
case 0x00000003: break;
}
} else
if (device->chipset != 0x4e) {
u32 pfb474 = nv_rd32(priv, 0x100474);
if (pfb474 & 0x00000004)
priv->base.ram.type = NV_MEM_TYPE_GDDR3;
if (pfb474 & 0x00000002)
priv->base.ram.type = NV_MEM_TYPE_DDR2;
if (pfb474 & 0x00000001)
priv->base.ram.type = NV_MEM_TYPE_DDR1;
} else {
priv->base.ram.type = NV_MEM_TYPE_STOLEN;
}
priv->base.ram.size = nv_rd32(priv, 0x10020c) & 0xff000000;
priv->base.memtype_valid = nv04_fb_memtype_valid;
switch (device->chipset) {
case 0x40:
case 0x45:
priv->base.tile.regions = 8;
break;
case 0x46:
case 0x47:
case 0x49:
case 0x4b:
case 0x4c:
priv->base.tile.regions = 15;
break;
default:
priv->base.tile.regions = 12;
break;
}
priv->base.tile.init = nv30_fb_tile_init;
priv->base.tile.fini = nv30_fb_tile_fini;
if (device->chipset == 0x40)
priv->base.tile.prog = nv10_fb_tile_prog;
else
priv->base.tile.prog = nv40_fb_tile_prog;
return nouveau_fb_created(&priv->base);
}
