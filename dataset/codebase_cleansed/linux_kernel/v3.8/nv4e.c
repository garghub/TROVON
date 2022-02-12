static int
nv4e_fb_vram_init(struct nouveau_fb *pfb)
{
pfb->ram.size = nv_rd32(pfb, 0x10020c) & 0xff000000;
pfb->ram.type = NV_MEM_TYPE_STOLEN;
return 0;
}
static int
nv4e_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv4e_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.ram.init = nv4e_fb_vram_init;
priv->base.tile.regions = 12;
priv->base.tile.init = nv46_fb_tile_init;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv44_fb_tile_prog;
return nouveau_fb_preinit(&priv->base);
}
