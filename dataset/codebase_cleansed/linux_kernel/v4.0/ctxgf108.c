void
gf108_grctx_generate_attrib(struct gf100_grctx *info)
{
struct gf100_gr_priv *priv = info->priv;
const struct gf100_grctx_oclass *impl = gf100_grctx_impl(priv);
const u32 alpha = impl->alpha_nr;
const u32 beta = impl->attrib_nr;
const u32 size = 0x20 * (impl->attrib_nr_max + impl->alpha_nr_max);
const u32 access = NV_MEM_ACCESS_RW;
const int s = 12;
const int b = mmio_vram(info, size * priv->tpc_total, (1 << s), access);
const int timeslice_mode = 1;
const int max_batches = 0xffff;
u32 bo = 0;
u32 ao = bo + impl->attrib_nr_max * priv->tpc_total;
int gpc, tpc;
mmio_refn(info, 0x418810, 0x80000000, s, b);
mmio_refn(info, 0x419848, 0x10000000, s, b);
mmio_wr32(info, 0x405830, (beta << 16) | alpha);
mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
for (tpc = 0; tpc < priv->tpc_nr[gpc]; tpc++) {
const u32 a = alpha;
const u32 b = beta;
const u32 t = timeslice_mode;
const u32 o = TPC_UNIT(gpc, tpc, 0x500);
mmio_skip(info, o + 0x20, (t << 28) | (b << 16) | ++bo);
mmio_wr32(info, o + 0x20, (t << 28) | (b << 16) | --bo);
bo += impl->attrib_nr_max;
mmio_wr32(info, o + 0x44, (a << 16) | ao);
ao += impl->alpha_nr_max;
}
}
}
void
gf108_grctx_generate_unkn(struct gf100_gr_priv *priv)
{
nv_mask(priv, 0x418c6c, 0x00000001, 0x00000001);
nv_mask(priv, 0x41980c, 0x00000010, 0x00000010);
nv_mask(priv, 0x419814, 0x00000004, 0x00000004);
nv_mask(priv, 0x4064c0, 0x80000000, 0x80000000);
nv_mask(priv, 0x405800, 0x08000000, 0x08000000);
nv_mask(priv, 0x419c00, 0x00000008, 0x00000008);
}
