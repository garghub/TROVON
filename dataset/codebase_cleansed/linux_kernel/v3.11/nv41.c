void
nv41_fb_tile_prog(struct nouveau_fb *pfb, int i, struct nouveau_fb_tile *tile)
{
nv_wr32(pfb, 0x100604 + (i * 0x10), tile->limit);
nv_wr32(pfb, 0x100608 + (i * 0x10), tile->pitch);
nv_wr32(pfb, 0x100600 + (i * 0x10), tile->addr);
nv_rd32(pfb, 0x100600 + (i * 0x10));
nv_wr32(pfb, 0x100700 + (i * 0x04), tile->zcomp);
}
int
nv41_fb_init(struct nouveau_object *object)
{
struct nv41_fb_priv *priv = (void *)object;
int ret;
ret = nouveau_fb_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x100800, 0x00000001);
return 0;
}
static int
nv41_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv41_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &nv41_ram_oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.tile.regions = 12;
priv->base.tile.init = nv30_fb_tile_init;
priv->base.tile.comp = nv40_fb_tile_comp;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv41_fb_tile_prog;
return 0;
}
