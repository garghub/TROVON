static void
gm107_graph_init_bios(struct nvc0_graph_priv *priv)
{
static const struct {
u32 ctrl;
u32 data;
} regs[] = {
{ 0x419ed8, 0x419ee0 },
{ 0x419ad0, 0x419ad4 },
{ 0x419ae0, 0x419ae4 },
{ 0x419af0, 0x419af4 },
{ 0x419af8, 0x419afc },
};
struct nouveau_bios *bios = nouveau_bios(priv);
struct nvbios_P0260E infoE;
struct nvbios_P0260X infoX;
int E = -1, X;
u8 ver, hdr;
while (nvbios_P0260Ep(bios, ++E, &ver, &hdr, &infoE)) {
if (X = -1, E < ARRAY_SIZE(regs)) {
nv_wr32(priv, regs[E].ctrl, infoE.data);
while (nvbios_P0260Xp(bios, ++X, &ver, &hdr, &infoX))
nv_wr32(priv, regs[E].data, infoX.data);
}
}
}
int
gm107_graph_init(struct nouveau_object *object)
{
struct nvc0_graph_oclass *oclass = (void *)object->oclass;
struct nvc0_graph_priv *priv = (void *)object;
const u32 magicgpc918 = DIV_ROUND_UP(0x00800000, priv->tpc_total);
u32 data[TPC_MAX / 8] = {};
u8 tpcnr[GPC_MAX];
int gpc, tpc, ppc, rop;
int ret, i;
ret = nouveau_graph_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, GPC_BCAST(0x0880), 0x00000000);
nv_wr32(priv, GPC_BCAST(0x0890), 0x00000000);
nv_wr32(priv, GPC_BCAST(0x0894), 0x00000000);
nv_wr32(priv, GPC_BCAST(0x08b4), priv->unk4188b4->addr >> 8);
nv_wr32(priv, GPC_BCAST(0x08b8), priv->unk4188b8->addr >> 8);
nvc0_graph_mmio(priv, oclass->mmio);
gm107_graph_init_bios(priv);
nv_wr32(priv, GPC_UNIT(0, 0x3018), 0x00000001);
memset(data, 0x00, sizeof(data));
memcpy(tpcnr, priv->tpc_nr, sizeof(priv->tpc_nr));
for (i = 0, gpc = -1; i < priv->tpc_total; i++) {
do {
gpc = (gpc + 1) % priv->gpc_nr;
} while (!tpcnr[gpc]);
tpc = priv->tpc_nr[gpc] - tpcnr[gpc]--;
data[i / 8] |= tpc << ((i % 8) * 4);
}
nv_wr32(priv, GPC_BCAST(0x0980), data[0]);
nv_wr32(priv, GPC_BCAST(0x0984), data[1]);
nv_wr32(priv, GPC_BCAST(0x0988), data[2]);
nv_wr32(priv, GPC_BCAST(0x098c), data[3]);
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
nv_wr32(priv, GPC_UNIT(gpc, 0x0914),
priv->magic_not_rop_nr << 8 | priv->tpc_nr[gpc]);
nv_wr32(priv, GPC_UNIT(gpc, 0x0910), 0x00040000 |
priv->tpc_total);
nv_wr32(priv, GPC_UNIT(gpc, 0x0918), magicgpc918);
}
nv_wr32(priv, GPC_BCAST(0x3fd4), magicgpc918);
nv_wr32(priv, GPC_BCAST(0x08ac), nv_rd32(priv, 0x100800));
nv_wr32(priv, 0x400500, 0x00010001);
nv_wr32(priv, 0x400100, 0xffffffff);
nv_wr32(priv, 0x40013c, 0xffffffff);
nv_wr32(priv, 0x400124, 0x00000002);
nv_wr32(priv, 0x409c24, 0x000e0000);
nv_wr32(priv, 0x404000, 0xc0000000);
nv_wr32(priv, 0x404600, 0xc0000000);
nv_wr32(priv, 0x408030, 0xc0000000);
nv_wr32(priv, 0x404490, 0xc0000000);
nv_wr32(priv, 0x406018, 0xc0000000);
nv_wr32(priv, 0x407020, 0x40000000);
nv_wr32(priv, 0x405840, 0xc0000000);
nv_wr32(priv, 0x405844, 0x00ffffff);
nv_mask(priv, 0x419cc0, 0x00000008, 0x00000008);
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
for (ppc = 0; ppc < 2 ; ppc++)
nv_wr32(priv, PPC_UNIT(gpc, ppc, 0x038), 0xc0000000);
nv_wr32(priv, GPC_UNIT(gpc, 0x0420), 0xc0000000);
nv_wr32(priv, GPC_UNIT(gpc, 0x0900), 0xc0000000);
nv_wr32(priv, GPC_UNIT(gpc, 0x1028), 0xc0000000);
nv_wr32(priv, GPC_UNIT(gpc, 0x0824), 0xc0000000);
for (tpc = 0; tpc < priv->tpc_nr[gpc]; tpc++) {
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x508), 0xffffffff);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x50c), 0xffffffff);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x224), 0xc0000000);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x48c), 0xc0000000);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x084), 0xc0000000);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x430), 0xc0000000);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x644), 0x00dffffe);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x64c), 0x00000005);
}
nv_wr32(priv, GPC_UNIT(gpc, 0x2c90), 0xffffffff);
nv_wr32(priv, GPC_UNIT(gpc, 0x2c94), 0xffffffff);
}
for (rop = 0; rop < priv->rop_nr; rop++) {
nv_wr32(priv, ROP_UNIT(rop, 0x144), 0x40000000);
nv_wr32(priv, ROP_UNIT(rop, 0x070), 0x40000000);
nv_wr32(priv, ROP_UNIT(rop, 0x204), 0xffffffff);
nv_wr32(priv, ROP_UNIT(rop, 0x208), 0xffffffff);
}
nv_wr32(priv, 0x400108, 0xffffffff);
nv_wr32(priv, 0x400138, 0xffffffff);
nv_wr32(priv, 0x400118, 0xffffffff);
nv_wr32(priv, 0x400130, 0xffffffff);
nv_wr32(priv, 0x40011c, 0xffffffff);
nv_wr32(priv, 0x400134, 0xffffffff);
nv_wr32(priv, 0x400054, 0x2c350f63);
nvc0_graph_zbc_init(priv);
return nvc0_graph_init_ctxctl(priv);
}
