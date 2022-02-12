static void
gm107_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
mmio_data(0x003000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x008000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x200000, 0x1000, NV_MEM_ACCESS_RW);
mmio_list(0x40800c, 0x00000000, 8, 1);
mmio_list(0x408010, 0x80000000, 0, 0);
mmio_list(0x419004, 0x00000000, 8, 1);
mmio_list(0x419008, 0x00000000, 0, 0);
mmio_list(0x4064cc, 0x80000000, 0, 0);
mmio_list(0x418e30, 0x80000000, 0, 0);
mmio_list(0x408004, 0x00000000, 8, 0);
mmio_list(0x408008, 0x80000030, 0, 0);
mmio_list(0x418e24, 0x00000000, 8, 0);
mmio_list(0x418e28, 0x80000030, 0, 0);
mmio_list(0x4064c8, 0x018002c0, 0, 0);
mmio_list(0x418810, 0x80000000, 12, 2);
mmio_list(0x419848, 0x10000000, 12, 2);
mmio_list(0x419c2c, 0x10000000, 12, 2);
mmio_list(0x405830, 0x0aa01000, 0, 0);
mmio_list(0x4064c4, 0x0400ffff, 0, 0);
mmio_list(0x5030c0, 0x00001540, 0, 0);
mmio_list(0x5030f4, 0x00000000, 0, 0);
mmio_list(0x5030e4, 0x00002000, 0, 0);
mmio_list(0x5030f8, 0x00003fc0, 0, 0);
mmio_list(0x418ea0, 0x07151540, 0, 0);
mmio_list(0x5032c0, 0x00001540, 0, 0);
mmio_list(0x5032f4, 0x00001fe0, 0, 0);
mmio_list(0x5032e4, 0x00002000, 0, 0);
mmio_list(0x5032f8, 0x00006fc0, 0, 0);
mmio_list(0x418ea4, 0x07151540, 0, 0);
}
static void
gm107_grctx_generate_tpcid(struct nvc0_graph_priv *priv)
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
gm107_grctx_generate_main(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
struct nvc0_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
int i;
nvc0_graph_mmio(priv, oclass->hub);
nvc0_graph_mmio(priv, oclass->gpc);
nvc0_graph_mmio(priv, oclass->zcull);
nvc0_graph_mmio(priv, oclass->tpc);
nvc0_graph_mmio(priv, oclass->ppc);
nv_wr32(priv, 0x404154, 0x00000000);
oclass->mods(priv, info);
oclass->unkn(priv);
gm107_grctx_generate_tpcid(priv);
nvc0_grctx_generate_r406028(priv);
nve4_grctx_generate_r418bb8(priv);
nvc0_grctx_generate_r406800(priv);
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
nvc0_graph_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
nvc0_graph_mthd(priv, oclass->mthd);
nv_mask(priv, 0x419e00, 0x00808080, 0x00808080);
nv_mask(priv, 0x419ccc, 0x80000000, 0x80000000);
nv_mask(priv, 0x419f80, 0x80000000, 0x80000000);
nv_mask(priv, 0x419f88, 0x80000000, 0x80000000);
}
