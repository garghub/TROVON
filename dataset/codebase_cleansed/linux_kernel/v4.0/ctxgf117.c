void
gf117_grctx_generate_attrib(struct gf100_grctx *info)
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
int gpc, ppc;
mmio_refn(info, 0x418810, 0x80000000, s, b);
mmio_refn(info, 0x419848, 0x10000000, s, b);
mmio_wr32(info, 0x405830, (beta << 16) | alpha);
mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
for (ppc = 0; ppc < priv->ppc_nr[gpc]; ppc++) {
const u32 a = alpha * priv->ppc_tpc_nr[gpc][ppc];
const u32 b = beta * priv->ppc_tpc_nr[gpc][ppc];
const u32 t = timeslice_mode;
const u32 o = PPC_UNIT(gpc, ppc, 0);
mmio_skip(info, o + 0xc0, (t << 28) | (b << 16) | ++bo);
mmio_wr32(info, o + 0xc0, (t << 28) | (b << 16) | --bo);
bo += impl->attrib_nr_max * priv->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, o + 0xe4, (a << 16) | ao);
ao += impl->alpha_nr_max * priv->ppc_tpc_nr[gpc][ppc];
}
}
}
void
gf117_grctx_generate_main(struct gf100_gr_priv *priv, struct gf100_grctx *info)
{
struct gf100_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
int i;
nvkm_mc(priv)->unk260(nvkm_mc(priv), 0);
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
gf100_grctx_generate_tpcid(priv);
gf100_grctx_generate_r406028(priv);
gf100_grctx_generate_r4060a8(priv);
gk104_grctx_generate_r418bb8(priv);
gf100_grctx_generate_r406800(priv);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
gf100_gr_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
gf100_gr_mthd(priv, oclass->mthd);
nvkm_mc(priv)->unk260(nvkm_mc(priv), 1);
}
