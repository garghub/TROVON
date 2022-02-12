void
gf100_ltc_cbc_clear(struct nvkm_ltc_priv *priv, u32 start, u32 limit)
{
nv_wr32(priv, 0x17e8cc, start);
nv_wr32(priv, 0x17e8d0, limit);
nv_wr32(priv, 0x17e8c8, 0x00000004);
}
void
gf100_ltc_cbc_wait(struct nvkm_ltc_priv *priv)
{
int c, s;
for (c = 0; c < priv->ltc_nr; c++) {
for (s = 0; s < priv->lts_nr; s++)
nv_wait(priv, 0x1410c8 + c * 0x2000 + s * 0x400, ~0, 0);
}
}
void
gf100_ltc_zbc_clear_color(struct nvkm_ltc_priv *priv, int i, const u32 color[4])
{
nv_mask(priv, 0x17ea44, 0x0000000f, i);
nv_wr32(priv, 0x17ea48, color[0]);
nv_wr32(priv, 0x17ea4c, color[1]);
nv_wr32(priv, 0x17ea50, color[2]);
nv_wr32(priv, 0x17ea54, color[3]);
}
void
gf100_ltc_zbc_clear_depth(struct nvkm_ltc_priv *priv, int i, const u32 depth)
{
nv_mask(priv, 0x17ea44, 0x0000000f, i);
nv_wr32(priv, 0x17ea58, depth);
}
static void
gf100_ltc_lts_isr(struct nvkm_ltc_priv *priv, int ltc, int lts)
{
u32 base = 0x141000 + (ltc * 0x2000) + (lts * 0x400);
u32 stat = nv_rd32(priv, base + 0x020);
if (stat) {
nv_info(priv, "LTC%d_LTS%d: 0x%08x\n", ltc, lts, stat);
nv_wr32(priv, base + 0x020, stat);
}
}
void
gf100_ltc_intr(struct nouveau_subdev *subdev)
{
struct nvkm_ltc_priv *priv = (void *)subdev;
u32 mask;
mask = nv_rd32(priv, 0x00017c);
while (mask) {
u32 lts, ltc = __ffs(mask);
for (lts = 0; lts < priv->lts_nr; lts++)
gf100_ltc_lts_isr(priv, ltc, lts);
mask &= ~(1 << ltc);
}
nv_mask(priv, 0x000640, 0x02000000, 0x00000000);
}
static int
gf100_ltc_init(struct nouveau_object *object)
{
struct nvkm_ltc_priv *priv = (void *)object;
u32 lpg128 = !(nv_rd32(priv, 0x100c80) & 0x00000001);
int ret;
ret = nvkm_ltc_init(priv);
if (ret)
return ret;
nv_mask(priv, 0x17e820, 0x00100000, 0x00000000);
nv_wr32(priv, 0x17e8d8, priv->ltc_nr);
nv_wr32(priv, 0x17e8d4, priv->tag_base);
nv_mask(priv, 0x17e8c0, 0x00000002, lpg128 ? 0x00000002 : 0x00000000);
return 0;
}
void
gf100_ltc_dtor(struct nouveau_object *object)
{
struct nouveau_fb *pfb = nouveau_fb(object);
struct nvkm_ltc_priv *priv = (void *)object;
nouveau_mm_fini(&priv->tags);
nouveau_mm_free(&pfb->vram, &priv->tag_ram);
nvkm_ltc_destroy(priv);
}
int
gf100_ltc_init_tag_ram(struct nouveau_fb *pfb, struct nvkm_ltc_priv *priv)
{
u32 tag_size, tag_margin, tag_align;
int ret;
priv->num_tags = (pfb->ram->size >> 17) / 4;
if (priv->num_tags > (1 << 17))
priv->num_tags = 1 << 17;
priv->num_tags = (priv->num_tags + 63) & ~63;
tag_align = priv->ltc_nr * 0x800;
tag_margin = (tag_align < 0x6000) ? 0x6000 : tag_align;
tag_size = (priv->num_tags / 64) * 0x6000 + tag_margin;
tag_size += tag_align;
tag_size = (tag_size + 0xfff) >> 12;
ret = nouveau_mm_tail(&pfb->vram, 1, tag_size, tag_size, 1,
&priv->tag_ram);
if (ret) {
priv->num_tags = 0;
} else {
u64 tag_base = ((u64)priv->tag_ram->offset << 12) + tag_margin;
tag_base += tag_align - 1;
ret = do_div(tag_base, tag_align);
priv->tag_base = tag_base;
}
ret = nouveau_mm_init(&priv->tags, 0, priv->num_tags, 1);
return ret;
}
int
gf100_ltc_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nvkm_ltc_priv *priv;
u32 parts, mask;
int ret, i;
ret = nvkm_ltc_create(parent, engine, oclass, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
parts = nv_rd32(priv, 0x022438);
mask = nv_rd32(priv, 0x022554);
for (i = 0; i < parts; i++) {
if (!(mask & (1 << i)))
priv->ltc_nr++;
}
priv->lts_nr = nv_rd32(priv, 0x17e8dc) >> 28;
ret = gf100_ltc_init_tag_ram(pfb, priv);
if (ret)
return ret;
nv_subdev(priv)->intr = gf100_ltc_intr;
return 0;
}
