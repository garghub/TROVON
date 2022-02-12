static void
nve4_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
u32 magic[GPC_MAX][2];
u32 offset;
int gpc;
mmio_data(0x003000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x008000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x060000, 0x1000, NV_MEM_ACCESS_RW);
mmio_list(0x40800c, 0x00000000, 8, 1);
mmio_list(0x408010, 0x80000000, 0, 0);
mmio_list(0x419004, 0x00000000, 8, 1);
mmio_list(0x419008, 0x00000000, 0, 0);
mmio_list(0x4064cc, 0x80000000, 0, 0);
mmio_list(0x408004, 0x00000000, 8, 0);
mmio_list(0x408008, 0x80000030, 0, 0);
mmio_list(0x418808, 0x00000000, 8, 0);
mmio_list(0x41880c, 0x80000030, 0, 0);
mmio_list(0x4064c8, 0x01800600, 0, 0);
mmio_list(0x418810, 0x80000000, 12, 2);
mmio_list(0x419848, 0x10000000, 12, 2);
mmio_list(0x405830, 0x02180648, 0, 0);
mmio_list(0x4064c4, 0x0192ffff, 0, 0);
for (gpc = 0, offset = 0; gpc < priv->gpc_nr; gpc++) {
u16 magic0 = 0x0218 * priv->tpc_nr[gpc];
u16 magic1 = 0x0648 * priv->tpc_nr[gpc];
magic[gpc][0] = 0x10000000 | (magic0 << 16) | offset;
magic[gpc][1] = 0x00000000 | (magic1 << 16);
offset += 0x0324 * priv->tpc_nr[gpc];
}
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
mmio_list(GPC_UNIT(gpc, 0x30c0), magic[gpc][0], 0, 0);
mmio_list(GPC_UNIT(gpc, 0x30e4), magic[gpc][1] | offset, 0, 0);
offset += 0x07ff * priv->tpc_nr[gpc];
}
mmio_list(0x17e91c, 0x06060609, 0, 0);
mmio_list(0x17e920, 0x00090a05, 0, 0);
}
void
nve4_grctx_generate_unkn(struct nvc0_graph_priv *priv)
{
nv_mask(priv, 0x418c6c, 0x00000001, 0x00000001);
nv_mask(priv, 0x41980c, 0x00000010, 0x00000010);
nv_mask(priv, 0x41be08, 0x00000004, 0x00000004);
nv_mask(priv, 0x4064c0, 0x80000000, 0x80000000);
nv_mask(priv, 0x405800, 0x08000000, 0x08000000);
nv_mask(priv, 0x419c00, 0x00000008, 0x00000008);
}
void
nve4_grctx_generate_r418bb8(struct nvc0_graph_priv *priv)
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
nve4_grctx_generate_main(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
struct nvc0_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
int i;
nv_mask(priv, 0x000260, 0x00000001, 0x00000000);
nvc0_graph_mmio(priv, oclass->hub);
nvc0_graph_mmio(priv, oclass->gpc);
nvc0_graph_mmio(priv, oclass->zcull);
nvc0_graph_mmio(priv, oclass->tpc);
nvc0_graph_mmio(priv, oclass->ppc);
nv_wr32(priv, 0x404154, 0x00000000);
oclass->mods(priv, info);
oclass->unkn(priv);
nvc0_grctx_generate_tpcid(priv);
nvc0_grctx_generate_r406028(priv);
nve4_grctx_generate_r418bb8(priv);
nvc0_grctx_generate_r406800(priv);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
nv_wr32(priv, 0x405b00, (priv->tpc_total << 8) | priv->gpc_nr);
if (priv->gpc_nr == 1) {
nv_mask(priv, 0x408850, 0x0000000f, priv->tpc_nr[0]);
nv_mask(priv, 0x408958, 0x0000000f, priv->tpc_nr[0]);
} else {
nv_mask(priv, 0x408850, 0x0000000f, priv->gpc_nr);
nv_mask(priv, 0x408958, 0x0000000f, priv->gpc_nr);
}
nv_mask(priv, 0x419f78, 0x00000001, 0x00000000);
nvc0_graph_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
nvc0_graph_mthd(priv, oclass->mthd);
nv_mask(priv, 0x000260, 0x00000001, 0x00000001);
nv_mask(priv, 0x418800, 0x00200000, 0x00200000);
nv_mask(priv, 0x41be10, 0x00800000, 0x00800000);
}
