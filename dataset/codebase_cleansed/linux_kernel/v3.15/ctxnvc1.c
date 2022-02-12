void
nvc1_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
{
int gpc, tpc;
u32 offset;
mmio_data(0x002000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x008000, 0x0100, NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS);
mmio_data(0x060000, 0x1000, NV_MEM_ACCESS_RW);
mmio_list(0x408004, 0x00000000, 8, 0);
mmio_list(0x408008, 0x80000018, 0, 0);
mmio_list(0x40800c, 0x00000000, 8, 1);
mmio_list(0x408010, 0x80000000, 0, 0);
mmio_list(0x418810, 0x80000000, 12, 2);
mmio_list(0x419848, 0x10000000, 12, 2);
mmio_list(0x419004, 0x00000000, 8, 1);
mmio_list(0x419008, 0x00000000, 0, 0);
mmio_list(0x418808, 0x00000000, 8, 0);
mmio_list(0x41880c, 0x80000018, 0, 0);
mmio_list(0x405830, 0x02180218, 0, 0);
mmio_list(0x4064c4, 0x0086ffff, 0, 0);
for (gpc = 0, offset = 0; gpc < priv->gpc_nr; gpc++) {
for (tpc = 0; tpc < priv->tpc_nr[gpc]; tpc++) {
u32 addr = TPC_UNIT(gpc, tpc, 0x0520);
mmio_list(addr, 0x12180000 | offset, 0, 0);
offset += 0x0324;
}
for (tpc = 0; tpc < priv->tpc_nr[gpc]; tpc++) {
u32 addr = TPC_UNIT(gpc, tpc, 0x0544);
mmio_list(addr, 0x02180000 | offset, 0, 0);
offset += 0x0324;
}
}
}
void
nvc1_grctx_generate_unkn(struct nvc0_graph_priv *priv)
{
nv_mask(priv, 0x418c6c, 0x00000001, 0x00000001);
nv_mask(priv, 0x41980c, 0x00000010, 0x00000010);
nv_mask(priv, 0x419814, 0x00000004, 0x00000004);
nv_mask(priv, 0x4064c0, 0x80000000, 0x80000000);
nv_mask(priv, 0x405800, 0x08000000, 0x08000000);
nv_mask(priv, 0x419c00, 0x00000008, 0x00000008);
}
