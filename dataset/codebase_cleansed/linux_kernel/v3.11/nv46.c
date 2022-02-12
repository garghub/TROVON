void
nv46_fb_tile_init(struct nouveau_fb *pfb, int i, u32 addr, u32 size, u32 pitch,
u32 flags, struct nouveau_fb_tile *tile)
{
if (!(flags & 4)) tile->addr = (0 << 3);
else tile->addr = (1 << 3);
tile->addr |= 0x00000001;
tile->addr |= addr;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
static int
nv46_fb_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv46_fb_priv *priv;
int ret;
ret = nouveau_fb_create(parent, engine, oclass, &nv44_ram_oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
priv->base.memtype_valid = nv04_fb_memtype_valid;
priv->base.tile.regions = 15;
priv->base.tile.init = nv46_fb_tile_init;
priv->base.tile.fini = nv20_fb_tile_fini;
priv->base.tile.prog = nv44_fb_tile_prog;
return 0;
}
