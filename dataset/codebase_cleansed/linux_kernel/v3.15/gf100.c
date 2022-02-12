static void
gf100_ltcg_lts_isr(struct gf100_ltcg_priv *priv, int ltc, int lts)
{
u32 base = 0x141000 + (ltc * 0x2000) + (lts * 0x400);
u32 stat = nv_rd32(priv, base + 0x020);
if (stat) {
nv_info(priv, "LTC%d_LTS%d: 0x%08x\n", ltc, lts, stat);
nv_wr32(priv, base + 0x020, stat);
}
}
static void
gf100_ltcg_intr(struct nouveau_subdev *subdev)
{
struct gf100_ltcg_priv *priv = (void *)subdev;
u32 mask;
mask = nv_rd32(priv, 0x00017c);
while (mask) {
u32 lts, ltc = __ffs(mask);
for (lts = 0; lts < priv->lts_nr; lts++)
gf100_ltcg_lts_isr(priv, ltc, lts);
mask &= ~(1 << ltc);
}
nv_mask(priv, 0x000640, 0x02000000, 0x00000000);
}
int
gf100_ltcg_tags_alloc(struct nouveau_ltcg *ltcg, u32 n,
struct nouveau_mm_node **pnode)
{
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
int ret;
ret = nouveau_mm_head(&priv->tags, 1, n, n, 1, pnode);
if (ret)
*pnode = NULL;
return ret;
}
void
gf100_ltcg_tags_free(struct nouveau_ltcg *ltcg, struct nouveau_mm_node **pnode)
{
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
nouveau_mm_free(&priv->tags, pnode);
}
static void
gf100_ltcg_tags_clear(struct nouveau_ltcg *ltcg, u32 first, u32 count)
{
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
u32 last = first + count - 1;
int p, i;
BUG_ON((first > last) || (last >= priv->num_tags));
nv_wr32(priv, 0x17e8cc, first);
nv_wr32(priv, 0x17e8d0, last);
nv_wr32(priv, 0x17e8c8, 0x4);
for (p = 0; p < priv->ltc_nr; ++p) {
for (i = 0; i < priv->lts_nr; ++i)
nv_wait(priv, 0x1410c8 + p * 0x2000 + i * 0x400, ~0, 0);
}
}
int
gf100_ltcg_init_tag_ram(struct nouveau_fb *pfb, struct gf100_ltcg_priv *priv)
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
u64 tag_base = (priv->tag_ram->offset << 12) + tag_margin;
tag_base += tag_align - 1;
ret = do_div(tag_base, tag_align);
priv->tag_base = tag_base;
}
ret = nouveau_mm_init(&priv->tags, 0, priv->num_tags, 1);
return ret;
}
static int
gf100_ltcg_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct gf100_ltcg_priv *priv;
struct nouveau_fb *pfb = nouveau_fb(parent);
u32 parts, mask;
int ret, i;
ret = nouveau_ltcg_create(parent, engine, oclass, &priv);
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
ret = gf100_ltcg_init_tag_ram(pfb, priv);
if (ret)
return ret;
priv->base.tags_alloc = gf100_ltcg_tags_alloc;
priv->base.tags_free = gf100_ltcg_tags_free;
priv->base.tags_clear = gf100_ltcg_tags_clear;
nv_subdev(priv)->intr = gf100_ltcg_intr;
return 0;
}
void
gf100_ltcg_dtor(struct nouveau_object *object)
{
struct nouveau_ltcg *ltcg = (struct nouveau_ltcg *)object;
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
struct nouveau_fb *pfb = nouveau_fb(ltcg->base.base.parent);
nouveau_mm_fini(&priv->tags);
nouveau_mm_free(&pfb->vram, &priv->tag_ram);
nouveau_ltcg_destroy(ltcg);
}
static int
gf100_ltcg_init(struct nouveau_object *object)
{
struct nouveau_ltcg *ltcg = (struct nouveau_ltcg *)object;
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
int ret;
ret = nouveau_ltcg_init(ltcg);
if (ret)
return ret;
nv_mask(priv, 0x17e820, 0x00100000, 0x00000000);
nv_wr32(priv, 0x17e8d8, priv->ltc_nr);
if (nv_device(ltcg)->card_type >= NV_E0)
nv_wr32(priv, 0x17e000, priv->ltc_nr);
nv_wr32(priv, 0x17e8d4, priv->tag_base);
return 0;
}
