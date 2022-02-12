static int
nv49_fb_vram_init(struct nouveau_fb *pfb)
{
u32 pfb914 = nv_rd32(pfb, 0x100914);
switch (pfb914 & 0x00000003) {
case 0x00000000: pfb->ram.type = NV_MEM_TYPE_DDR1; break;
case 0x00000001: pfb->ram.type = NV_MEM_TYPE_DDR2; break;
case 0x00000002: pfb->ram.type = NV_MEM_TYPE_GDDR3; break;
case 0x00000003: break;
}
pfb->ram.size = nv_rd32(pfb, 0x10020c) & 0xff000000;
pfb->ram.parts = (nv_rd32(pfb, 0x100200) & 0x00000003) + 1;
return nv_rd32(pfb, 0x100320);
}
static int
nv49_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv49_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.ram.init = nv49_fb_vram_init;
priv->base.tile.regions = 15;
priv->base.tile.init = nv30_fb_tile_init;
priv->base.tile.comp = nv40_fb_tile_comp;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv41_fb_tile_prog;
return nouveau_fb_preinit(&priv->base);
}
