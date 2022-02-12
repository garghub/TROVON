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
struct nv04_fb_priv *priv = (void *)object;
int ret;
ret = nouveau_fb_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, 0x100850, 0x80000000);
nv_wr32(priv, 0x100800, 0x00000001);
return 0;
}
