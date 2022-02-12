static void
nv108_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
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
mmio_list(0x4064c8, 0x00c20200, 0, 0);
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
mmio_list(0x17e91c, 0x0b040a0b, 0, 0);
mmio_list(0x17e920, 0x00090d08, 0, 0);
}
