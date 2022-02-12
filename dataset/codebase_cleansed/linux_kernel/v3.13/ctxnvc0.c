void
nvc0_grctx_generate_mods(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
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
mmio_list(0x405830, 0x02180000, 0, 0);
for (gpc = 0, offset = 0; gpc < priv->gpc_nr; gpc++) {
for (tpc = 0; tpc < priv->tpc_nr[gpc]; tpc++) {
u32 addr = TPC_UNIT(gpc, tpc, 0x0520);
mmio_list(addr, 0x02180000 | offset, 0, 0);
offset += 0x0324;
}
}
}
void
nvc0_grctx_generate_unkn(struct nvc0_graph_priv *priv)
{
}
void
nvc0_grctx_generate_tpcid(struct nvc0_graph_priv *priv)
{
int gpc, tpc, id;
for (tpc = 0, id = 0; tpc < 4; tpc++) {
for (gpc = 0; gpc < priv->gpc_nr; gpc++) {
if (tpc < priv->tpc_nr[gpc]) {
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x698), id);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x4e8), id);
nv_wr32(priv, GPC_UNIT(gpc, 0x0c10 + tpc * 4), id);
nv_wr32(priv, TPC_UNIT(gpc, tpc, 0x088), id);
id++;
}
nv_wr32(priv, GPC_UNIT(gpc, 0x0c08), priv->tpc_nr[gpc]);
nv_wr32(priv, GPC_UNIT(gpc, 0x0c8c), priv->tpc_nr[gpc]);
}
}
}
void
nvc0_grctx_generate_r406028(struct nvc0_graph_priv *priv)
{
u32 tmp[GPC_MAX / 8] = {}, i = 0;
for (i = 0; i < priv->gpc_nr; i++)
tmp[i / 8] |= priv->tpc_nr[i] << ((i % 8) * 4);
for (i = 0; i < 4; i++) {
nv_wr32(priv, 0x406028 + (i * 4), tmp[i]);
nv_wr32(priv, 0x405870 + (i * 4), tmp[i]);
}
}
void
nvc0_grctx_generate_r4060a8(struct nvc0_graph_priv *priv)
{
u8 tpcnr[GPC_MAX], data[TPC_MAX];
int gpc, tpc, i;
memcpy(tpcnr, priv->tpc_nr, sizeof(priv->tpc_nr));
memset(data, 0x1f, sizeof(data));
gpc = -1;
for (tpc = 0; tpc < priv->tpc_total; tpc++) {
do {
gpc = (gpc + 1) % priv->gpc_nr;
} while (!tpcnr[gpc]);
tpcnr[gpc]--;
data[tpc] = gpc;
}
for (i = 0; i < 4; i++)
nv_wr32(priv, 0x4060a8 + (i * 4), ((u32 *)data)[i]);
}
void
nvc0_grctx_generate_r418bb8(struct nvc0_graph_priv *priv)
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
nv_wr32(priv, 0x419bd0, (priv->tpc_total << 8) |
priv->magic_not_rop_nr | data2[0]);
nv_wr32(priv, 0x419be4, data2[1]);
for (i = 0; i < 6; i++)
nv_wr32(priv, 0x419b00 + (i * 4), data[i]);
nv_wr32(priv, 0x4078bc, (priv->tpc_total << 8) |
priv->magic_not_rop_nr);
for (i = 0; i < 6; i++)
nv_wr32(priv, 0x40780c + (i * 4), data[i]);
}
void
nvc0_grctx_generate_r406800(struct nvc0_graph_priv *priv)
{
u64 tpc_mask = 0, tpc_set = 0;
u8 tpcnr[GPC_MAX];
int gpc, tpc;
int i, a, b;
memcpy(tpcnr, priv->tpc_nr, sizeof(priv->tpc_nr));
for (gpc = 0; gpc < priv->gpc_nr; gpc++)
tpc_mask |= ((1ULL << priv->tpc_nr[gpc]) - 1) << (gpc * 8);
for (i = 0, gpc = -1, b = -1; i < 32; i++) {
a = (i * (priv->tpc_total - 1)) / 32;
if (a != b) {
b = a;
do {
gpc = (gpc + 1) % priv->gpc_nr;
} while (!tpcnr[gpc]);
tpc = priv->tpc_nr[gpc] - tpcnr[gpc]--;
tpc_set |= 1ULL << ((gpc * 8) + tpc);
}
nv_wr32(priv, 0x406800 + (i * 0x20), lower_32_bits(tpc_set));
nv_wr32(priv, 0x406c00 + (i * 0x20), lower_32_bits(tpc_set ^ tpc_mask));
if (priv->gpc_nr > 4) {
nv_wr32(priv, 0x406804 + (i * 0x20), upper_32_bits(tpc_set));
nv_wr32(priv, 0x406c04 + (i * 0x20), upper_32_bits(tpc_set ^ tpc_mask));
}
}
}
void
nvc0_grctx_generate_main(struct nvc0_graph_priv *priv, struct nvc0_grctx *info)
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
nvc0_grctx_generate_r418bb8(priv);
nvc0_grctx_generate_r406800(priv);
nvc0_graph_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000400);
nvc0_graph_mthd(priv, oclass->mthd);
nv_mask(priv, 0x000260, 0x00000001, 0x00000001);
}
int
nvc0_grctx_generate(struct nvc0_graph_priv *priv)
{
struct nvc0_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
struct nouveau_bar *bar = nouveau_bar(priv);
struct nouveau_gpuobj *chan;
struct nvc0_grctx info;
int ret, i;
ret = nouveau_gpuobj_new(nv_object(priv), NULL, 0x80000 + priv->size,
0x1000, NVOBJ_FLAG_ZERO_ALLOC, &chan);
if (ret) {
nv_error(priv, "failed to allocate channel memory, %d\n", ret);
return ret;
}
nv_wo32(chan, 0x0200, lower_32_bits(chan->addr + 0x1000));
nv_wo32(chan, 0x0204, upper_32_bits(chan->addr + 0x1000));
nv_wo32(chan, 0x0208, 0xffffffff);
nv_wo32(chan, 0x020c, 0x000000ff);
nv_wo32(chan, 0x1000, 0x00000000);
nv_wo32(chan, 0x1004, 0x00000001 | (chan->addr + 0x2000) >> 8);
for (i = 0; i < chan->size / 4096; i++) {
u64 addr = ((chan->addr + (i * 4096)) >> 8) | 1;
nv_wo32(chan, 0x2000 + (i * 8), lower_32_bits(addr));
nv_wo32(chan, 0x2004 + (i * 8), upper_32_bits(addr));
}
nv_wo32(chan, 0x0210, 0x00080004);
nv_wo32(chan, 0x0214, 0x00000000);
bar->flush(bar);
nv_wr32(priv, 0x100cb8, (chan->addr + 0x1000) >> 8);
nv_wr32(priv, 0x100cbc, 0x80000001);
nv_wait(priv, 0x100c80, 0x00008000, 0x00008000);
info.priv = priv;
info.data = priv->mmio_data;
info.mmio = priv->mmio_list;
info.addr = 0x2000 + (i * 8);
info.buffer_nr = 0;
if (priv->firmware) {
nv_wr32(priv, 0x409840, 0x00000030);
nv_wr32(priv, 0x409500, 0x80000000 | chan->addr >> 12);
nv_wr32(priv, 0x409504, 0x00000003);
if (!nv_wait(priv, 0x409800, 0x00000010, 0x00000010))
nv_error(priv, "load_ctx timeout\n");
nv_wo32(chan, 0x8001c, 1);
nv_wo32(chan, 0x80020, 0);
nv_wo32(chan, 0x80028, 0);
nv_wo32(chan, 0x8002c, 0);
bar->flush(bar);
} else {
nv_wr32(priv, 0x409840, 0x80000000);
nv_wr32(priv, 0x409500, 0x80000000 | chan->addr >> 12);
nv_wr32(priv, 0x409504, 0x00000001);
if (!nv_wait(priv, 0x409800, 0x80000000, 0x80000000))
nv_error(priv, "HUB_SET_CHAN timeout\n");
}
oclass->main(priv, &info);
nv_mask(priv, 0x409b04, 0x80000000, 0x00000000);
nv_wr32(priv, 0x409000, 0x00000100);
if (!nv_wait(priv, 0x409b00, 0x80000000, 0x00000000)) {
nv_error(priv, "grctx template channel unload timeout\n");
ret = -EBUSY;
goto done;
}
priv->data = kmalloc(priv->size, GFP_KERNEL);
if (priv->data) {
for (i = 0; i < priv->size; i += 4)
priv->data[i / 4] = nv_ro32(chan, 0x80000 + i);
ret = 0;
} else {
ret = -ENOMEM;
}
done:
nouveau_gpuobj_ref(NULL, &chan);
return ret;
}
