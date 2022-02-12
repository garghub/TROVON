static void
nvd7_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
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
mmio_list(0x408004, 0x00000000, 8, 0);
mmio_list(0x408008, 0x80000018, 0, 0);
mmio_list(0x418808, 0x00000000, 8, 0);
mmio_list(0x41880c, 0x80000018, 0, 0);
mmio_list(0x418810, 0x80000000, 12, 2);
mmio_list(0x419848, 0x10000000, 12, 2);
mmio_list(0x405830, 0x02180324, 0, 0);
mmio_list(0x4064c4, 0x00c9ffff, 0, 0);
for (gpc = 0, offset = 0; gpc < priv->gpc_nr; gpc++) {
u16 magic0 = 0x0218 * priv->tpc_nr[gpc];
u16 magic1 = 0x0324 * priv->tpc_nr[gpc];
magic[gpc][0] = 0x10000000 | (magic0 << 16) | offset;
magic[gpc][1] = 0x00000000 | (magic1 << 16);
offset += 0x0324 * priv->tpc_nr[gpc];
}
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
mmio_list(GPC_UNIT(gpc, 0x30c0), magic[gpc][0], 0, 0);
mmio_list(GPC_UNIT(gpc, 0x30e4), magic[gpc][1] | offset, 0, 0);
offset += 0x07ff * priv->tpc_nr[gpc];
}
mmio_list(0x17e91c, 0x03060609, 0, 0);
}
void
nvd7_grctx_generate_main(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
struct nvc0_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
int i;
nv_mask(priv, 0x000260, 0x00000001, 0x00000000);
for (i = 0; oclass->hub[i]; i++)
nvc0_graph_mmio(priv, oclass->hub[i]);
for (i = 0; oclass->gpc[i]; i++)
nvc0_graph_mmio(priv, oclass->gpc[i]);
nv_wr32(priv, 0x404154, 0x00000000);
oclass->mods(priv, info);
oclass->unkn(priv);
nvc0_grctx_generate_tpcid(priv);
nvc0_grctx_generate_r406028(priv);
nvc0_grctx_generate_r4060a8(priv);
nve4_grctx_generate_r418bb8(priv);
nvc0_grctx_generate_r406800(priv);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
nvc0_graph_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
nvc0_graph_mthd(priv, oclass->mthd);
nv_mask(priv, 0x000260, 0x00000001, 0x00000001);
}
