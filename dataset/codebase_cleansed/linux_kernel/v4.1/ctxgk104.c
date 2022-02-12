void
gk104_grctx_generate_bundle(struct gf100_grctx *info)
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
mmio_refn(info, 0x418808, 0x00000000, s, b);
mmio_wr32(info, 0x41880c, 0x80000000 | (impl->bundle_size >> s));
mmio_wr32(info, 0x4064c8, (state_limit << 16) | token_limit);
}
void
gk104_grctx_generate_pagepool(struct gf100_grctx *info)
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
}
void
gk104_grctx_generate_unkn(struct gf100_gr_priv *priv)
{
nv_mask(priv, 0x418c6c, 0x00000001, 0x00000001);
nv_mask(priv, 0x41980c, 0x00000010, 0x00000010);
nv_mask(priv, 0x41be08, 0x00000004, 0x00000004);
nv_mask(priv, 0x4064c0, 0x80000000, 0x80000000);
nv_mask(priv, 0x405800, 0x08000000, 0x08000000);
nv_mask(priv, 0x419c00, 0x00000008, 0x00000008);
}
void
gk104_grctx_generate_r418bb8(struct gf100_gr_priv *priv)
{
u32 data[6] = {}, data2[2] = {};
u8 tpcnr[GPC_MAX];
u8 shift, ntpcv;
int gpc, tpc, i;
memcpy(tpcnr, priv->tpc_nr, sizeof(priv->tpc_nr));
gpc = -1;
for (tpc = 0; tpc < priv->tpc_total; tpc++) {
do {
gpc = (gpc + 1) % priv->gpc_nr;
} while (!tpcnr[gpc]);
tpcnr[gpc]--;
data[tpc / 6] |= gpc << ((tpc % 6) * 5);
}
for (; tpc < 32; tpc++)
data[tpc / 6] |= 7 << ((tpc % 6) * 5);
shift = 0;
ntpcv = priv->tpc_total;
while (!(ntpcv & (1 << 4))) {
ntpcv <<= 1;
shift++;
}
data2[0] = (ntpcv << 16);
data2[0] |= (shift << 21);
data2[0] |= (((1 << (0 + 5)) % ntpcv) << 24);
for (i = 1; i < 7; i++)
data2[1] |= ((1 << (i + 5)) % ntpcv) << ((i - 1) * 5);
nv_wr32(priv, 0x418bb8, (priv->tpc_total << 8) |
priv->magic_not_rop_nr);
for (i = 0; i < 6; i++)
nv_wr32(priv, 0x418b08 + (i * 4), data[i]);
nv_wr32(priv, 0x41bfd0, (priv->tpc_total << 8) |
priv->magic_not_rop_nr | data2[0]);
nv_wr32(priv, 0x41bfe4, data2[1]);
for (i = 0; i < 6; i++)
nv_wr32(priv, 0x41bf00 + (i * 4), data[i]);
nv_wr32(priv, 0x4078bc, (priv->tpc_total << 8) |
priv->magic_not_rop_nr);
for (i = 0; i < 6; i++)
nv_wr32(priv, 0x40780c + (i * 4), data[i]);
}
void
gk104_grctx_generate_rop_active_fbps(struct gf100_gr_priv *priv)
{
const u32 fbp_count = nv_rd32(priv, 0x120074);
nv_mask(priv, 0x408850, 0x0000000f, fbp_count);
nv_mask(priv, 0x408958, 0x0000000f, fbp_count);
}
void
gk104_grctx_generate_main(struct gf100_gr_priv *priv, struct gf100_grctx *info)
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
gk104_grctx_generate_r418bb8(priv);
gf100_grctx_generate_r406800(priv);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
nv_wr32(priv, 0x405b00, (priv->tpc_total << 8) | priv->gpc_nr);
gk104_grctx_generate_rop_active_fbps(priv);
nv_mask(priv, 0x419f78, 0x00000001, 0x00000000);
gf100_gr_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
gf100_gr_mthd(priv, oclass->mthd);
nvkm_mc(priv)->unk260(nvkm_mc(priv), 1);
nv_mask(priv, 0x418800, 0x00200000, 0x00200000);
nv_mask(priv, 0x41be10, 0x00800000, 0x00800000);
}
