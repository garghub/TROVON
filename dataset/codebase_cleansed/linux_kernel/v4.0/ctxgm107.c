static void
gm107_grctx_generate_bundle(struct gf100_grctx *info)
{
const struct gf100_grctx_oclass *impl = gf100_grctx_impl(info->priv);
const u32 state_limit = min(impl->bundle_min_gpm_fifo_depth,
impl->bundle_size / 0x20);
const u32 token_limit = impl->bundle_token_limit;
const u32 access = NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS;
const int s = 8;
const int b = mmio_vram(info, impl->bundle_size, (1 << s), access);
mmio_refn(info, 0x408004, 0x00000000, s, b);
mmio_wr32(info, 0x408008, 0x80000000 | (impl->bundle_size >> s));
mmio_refn(info, 0x418e24, 0x00000000, s, b);
mmio_wr32(info, 0x418e28, 0x80000000 | (impl->bundle_size >> s));
mmio_wr32(info, 0x4064c8, (state_limit << 16) | token_limit);
}
static void
gm107_grctx_generate_pagepool(struct gf100_grctx *info)
{
const struct gf100_grctx_oclass *impl = gf100_grctx_impl(info->priv);
const u32 access = NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS;
const int s = 8;
const int b = mmio_vram(info, impl->pagepool_size, (1 << s), access);
mmio_refn(info, 0x40800c, 0x00000000, s, b);
mmio_wr32(info, 0x408010, 0x80000000);
mmio_refn(info, 0x419004, 0x00000000, s, b);
mmio_wr32(info, 0x419008, 0x00000000);
mmio_wr32(info, 0x4064cc, 0x80000000);
mmio_wr32(info, 0x418e30, 0x80000000);
}
static void
gm107_grctx_generate_attrib(struct gf100_grctx *info)
{
struct gf100_gr_priv *priv = info->priv;
const struct gf100_grctx_oclass *impl = (void *)gf100_grctx_impl(priv);
const u32 alpha = impl->alpha_nr;
const u32 attrib = impl->attrib_nr;
const u32 size = 0x20 * (impl->attrib_nr_max + impl->alpha_nr_max);
const u32 access = NV_MEM_ACCESS_RW;
const int s = 12;
const int b = mmio_vram(info, size * priv->tpc_total, (1 << s), access);
const int max_batches = 0xffff;
u32 bo = 0;
u32 ao = bo + impl->attrib_nr_max * priv->tpc_total;
int gpc, ppc, n = 0;
mmio_refn(info, 0x418810, 0x80000000, s, b);
mmio_refn(info, 0x419848, 0x10000000, s, b);
mmio_refn(info, 0x419c2c, 0x10000000, s, b);
mmio_wr32(info, 0x405830, (attrib << 16) | alpha);
mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
for (ppc = 0; ppc < priv->ppc_nr[gpc]; ppc++, n++) {
const u32 as = alpha * priv->ppc_tpc_nr[gpc][ppc];
const u32 bs = attrib * priv->ppc_tpc_nr[gpc][ppc];
const u32 u = 0x418ea0 + (n * 0x04);
const u32 o = PPC_UNIT(gpc, ppc, 0);
mmio_wr32(info, o + 0xc0, bs);
mmio_wr32(info, o + 0xf4, bo);
bo += impl->attrib_nr_max * priv->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, o + 0xe4, as);
mmio_wr32(info, o + 0xf8, ao);
ao += impl->alpha_nr_max * priv->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, u, (0x715 << 16) | bs);
}
}
}
static void
gm107_grctx_generate_tpcid(struct gf100_gr_priv *priv)
{
int gpc, tpc, id;
for (tpc = 0, id = 0; tpc < 4; tpc++) {
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
if (tpc < priv->tpc_nr[gpc]) {
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x698), id);
nv_wr32(priv, GPC_UNIT(gpc, 0x0c10 + tpc * 4), id);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x088), id);
id++;
}
nv_wr32(priv, GPC_UNIT(gpc, 0x0c08), priv->tpc_nr[gpc]);
nv_wr32(priv, GPC_UNIT(gpc, 0x0c8c), priv->tpc_nr[gpc]);
}
}
}
static void
gm107_grctx_generate_main(struct gf100_gr_priv *priv, struct gf100_grctx *info)
{
struct gf100_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
int i;
gf100_gr_mmio(priv, oclass->hub);
gf100_gr_mmio(priv, oclass->gpc);
gf100_gr_mmio(priv, oclass->zcull);
gf100_gr_mmio(priv, oclass->tpc);
gf100_gr_mmio(priv, oclass->ppc);
nv_wr32(priv, 0x404154, 0x00000000);
oclass->bundle(info);
oclass->pagepool(info);
oclass->attrib(info);
oclass->unkn(priv);
gm107_grctx_generate_tpcid(priv);
gf100_grctx_generate_r406028(priv);
gk104_grctx_generate_r418bb8(priv);
gf100_grctx_generate_r406800(priv);
nv_wr32(priv, 0x4064d0, 0x00000001);
for (i = 1; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
nv_wr32(priv, 0x406500, 0x00000001);
nv_wr32(priv, 0x405b00, (priv->tpc_total << 8) | priv->gpc_nr);
if (priv->gpc_nr == 1) {
nv_mask(priv, 0x408850, 0x0000000f, priv->tpc_nr[0]);
nv_mask(priv, 0x408958, 0x0000000f, priv->tpc_nr[0]);
} else {
nv_mask(priv, 0x408850, 0x0000000f, priv->gpc_nr);
nv_mask(priv, 0x408958, 0x0000000f, priv->gpc_nr);
}
gf100_gr_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
gf100_gr_mthd(priv, oclass->mthd);
nv_mask(priv, 0x419e00, 0x00808080, 0x00808080);
nv_mask(priv, 0x419ccc, 0x80000000, 0x80000000);
nv_mask(priv, 0x419f80, 0x80000000, 0x80000000);
nv_mask(priv, 0x419f88, 0x80000000, 0x80000000);
}
