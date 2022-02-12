int
nv44_fb_vram_init(struct nouveau_fb *pfb)
{
u32 pfb474 = nv_rd32(pfb, 0x100474);
if (pfb474 & 0x00000004)
pfb->ram.type = NV_MEM_TYPE_GDDR3;
if (pfb474 & 0x00000002)
pfb->ram.type = NV_MEM_TYPE_DDR2;
if (pfb474 & 0x00000001)
pfb->ram.type = NV_MEM_TYPE_DDR1;
pfb->ram.size = nv_rd32(pfb, 0x10020c) & 0xff000000;
return 0;
}
static void
nv44_fb_tile_init(struct nouveau_fb *pfb, int i, u32 addr, u32 size, u32 pitch,
u32 flags, struct nouveau_fb_tile *tile)
{
tile->addr = 0x00000001;
tile->addr |= addr;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
void
nv44_fb_tile_prog(struct nouveau_fb *pfb, int i, struct nouveau_fb_tile *tile)
{
nv_wr32(pfb, 0x100604 + (i * 0x10), tile->limit);
nv_wr32(pfb, 0x100608 + (i * 0x10), tile->pitch);
nv_wr32(pfb, 0x100600 + (i * 0x10), tile->addr);
nv_rd32(pfb, 0x100600 + (i * 0x10));
}
int
nv44_fb_init(struct nouveau_object *object)
{
struct nv44_fb_priv *priv = (void *)object;
int ret;
ret = nouveau_fb_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x100850, 0x80000000);
nv_wr32(priv, 0x100800, 0x00000001);
return 0;
}
static int
nv44_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv44_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.ram.init = nv44_fb_vram_init;
priv->base.tile.regions = 12;
priv->base.tile.init = nv44_fb_tile_init;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv44_fb_tile_prog;
return nouveau_fb_preinit(&priv->base);
}
