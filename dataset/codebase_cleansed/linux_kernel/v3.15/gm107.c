static void
gm107_ltcg_lts_isr(struct gf100_ltcg_priv *priv, int ltc, int lts)
{
u32 base = 0x140000 + (ltc * 0x2000) + (lts * 0x400);
u32 stat = nv_rd32(priv, base + 0x00c);
if (stat) {
nv_info(priv, "LTC%d_LTS%d: 0x%08x\n", ltc, lts, stat);
nv_wr32(priv, base + 0x00c, stat);
}
}
static void
gm107_ltcg_intr(struct nouveau_subdev *subdev)
{
struct gf100_ltcg_priv *priv = (void *)subdev;
u32 mask;
mask = nv_rd32(priv, 0x00017c);
while (mask) {
u32 lts, ltc = __ffs(mask);
for (lts = 0; lts < priv->lts_nr; lts++)
gm107_ltcg_lts_isr(priv, ltc, lts);
mask &= ~(1 << ltc);
}
nv_mask(priv, 0x000640, 0x02000000, 0x00000000);
}
static void
gm107_ltcg_tags_clear(struct nouveau_ltcg *ltcg, u32 first, u32 count)
{
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
u32 last = first + count - 1;
int p, i;
BUG_ON((first > last) || (last >= priv->num_tags));
nv_wr32(priv, 0x17e270, first);
nv_wr32(priv, 0x17e274, last);
nv_wr32(priv, 0x17e26c, 0x4);
for (p = 0; p < priv->ltc_nr; ++p) {
for (i = 0; i < priv->lts_nr; ++i)
nv_wait(priv, 0x14046c + p * 0x2000 + i * 0x200, ~0, 0);
}
}
static int
gm107_ltcg_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
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
mask = nv_rd32(priv, 0x021c14);
for (i = 0; i < parts; i++) {
if (!(mask & (1 << i)))
priv->ltc_nr++;
}
priv->lts_nr = nv_rd32(priv, 0x17e280) >> 28;
ret = gf100_ltcg_init_tag_ram(pfb, priv);
if (ret)
return ret;
priv->base.tags_alloc = gf100_ltcg_tags_alloc;
priv->base.tags_free = gf100_ltcg_tags_free;
priv->base.tags_clear = gm107_ltcg_tags_clear;
nv_subdev(priv)->intr = gm107_ltcg_intr;
return 0;
}
static int
gm107_ltcg_init(struct nouveau_object *object)
{
struct nouveau_ltcg *ltcg = (struct nouveau_ltcg *)object;
struct gf100_ltcg_priv *priv = (struct gf100_ltcg_priv *)ltcg;
int ret;
ret = nouveau_ltcg_init(ltcg);
if (ret)
return ret;
nv_wr32(priv, 0x17e27c, priv->ltc_nr);
nv_wr32(priv, 0x17e278, priv->tag_base);
return 0;
}
