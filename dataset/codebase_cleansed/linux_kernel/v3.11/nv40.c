void
nv40_fb_tile_comp(struct nouveau_fb *pfb, int i, u32 size, u32 flags,
struct nouveau_fb_tile *tile)
{
u32 tiles = DIV_ROUND_UP(size, 0x80);
u32 tags = round_up(tiles / pfb->ram->parts, 0x100);
if ( (flags & 2) &&
!nouveau_mm_head(&pfb->tags, 1, tags, tags, 1, &tile->tag)) {
tile->zcomp = 0x28000000;
tile->zcomp |= ((tile->tag->offset ) >> 8);
tile->zcomp |= ((tile->tag->offset + tags - 1) >> 8) << 13;
#ifdef __BIG_ENDIAN
tile->zcomp |= 0x40000000;
#endif
}
}
static int
nv40_fb_init(struct nouveau_object *object)
{
struct nv40_fb_priv *priv = (void *)object;
int ret;
ret = nouveau_fb_init(&priv->base);
if (ret)
return ret;
nv_mask(priv, 0x10033c, 0x00008000, 0x00000000);
return 0;
}
static int
nv40_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv40_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &nv40_ram_oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.tile.regions = 8;
priv->base.tile.init = nv30_fb_tile_init;
priv->base.tile.comp = nv40_fb_tile_comp;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv20_fb_tile_prog;
return 0;
}
