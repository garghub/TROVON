static void
nv36_fb_tile_comp(struct nouveau_fb *pfb, int i, u32 size, u32 flags,
struct nouveau_fb_tile *tile)
{
u32 tiles = DIV_ROUND_UP(size, 0x40);
u32 tags = round_up(tiles / pfb->ram.parts, 0x40);
if (!nouveau_mm_head(&pfb->tags, 1, tags, tags, 1, &tile->tag)) {
if (flags & 2) tile->zcomp |= 0x10000000;
else tile->zcomp |= 0x20000000;
tile->zcomp |= ((tile->tag->offset ) >> 6);
tile->zcomp |= ((tile->tag->offset + tags - 1) >> 6) << 14;
#ifdef __BIG_ENDIAN
tile->zcomp |= 0x80000000;
#endif
}
}
static int
nv36_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv36_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.ram.init = nv20_fb_vram_init;
priv->base.tile.regions = 8;
priv->base.tile.init = nv30_fb_tile_init;
priv->base.tile.comp = nv36_fb_tile_comp;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv20_fb_tile_prog;
return nouveau_fb_preinit(&priv->base);
}
