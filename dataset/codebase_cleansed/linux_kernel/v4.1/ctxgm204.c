static void
gm204_grctx_generate_tpcid(struct gf100_gr_priv *priv)
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
}
}
}
static void
gm204_grctx_generate_rop_active_fbps(struct gf100_gr_priv *priv)
{
const u32 fbp_count = nv_rd32(priv, 0x12006c);
nv_mask(priv, 0x408850, 0x0000000f, fbp_count);
nv_mask(priv, 0x408958, 0x0000000f, fbp_count);
}
static void
gm204_grctx_generate_405b60(struct gf100_gr_priv *priv)
{
const u32 dist_nr = DIV_ROUND_UP(priv->tpc_total, 4);
u32 dist[TPC_MAX] = {};
u32 gpcs[GPC_MAX] = {};
u8 tpcnr[GPC_MAX];
int tpc, gpc, i;
memcpy(tpcnr, priv->tpc_nr, sizeof(priv->tpc_nr));
for (gpc = -1, i = 0; i < priv->tpc_total; i++) {
do {
gpc = (gpc + 1) % priv->gpc_nr;
} while(!tpcnr[gpc]);
tpc = priv->tpc_nr[gpc] - tpcnr[gpc]--;
dist[i / 4] |= ((gpc << 4) | tpc) << ((i % 4) * 8);
gpcs[gpc] |= i << (tpc * 8);
}
for (i = 0; i < dist_nr; i++)
nv_wr32(priv, 0x405b60 + (i * 4), dist[i]);
for (i = 0; i < priv->gpc_nr; i++)
nv_wr32(priv, 0x405ba0 + (i * 4), gpcs[i]);
}
void
gm204_grctx_generate_main(struct gf100_gr_priv *priv, struct gf100_grctx *info)
{
struct gf100_grctx_oclass *oclass = (void *)nv_engine(priv)->cclass;
u32 tmp;
int i;
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
gm204_grctx_generate_tpcid(priv);
gf100_grctx_generate_r406028(priv);
gk104_grctx_generate_r418bb8(priv);
for (i = 0; i < 8; i++)
nv_wr32(priv, 0x4064d0 + (i * 0x04), 0x00000000);
nv_wr32(priv, 0x406500, 0x00000000);
nv_wr32(priv, 0x405b00, (priv->tpc_total << 8) | priv->gpc_nr);
gm204_grctx_generate_rop_active_fbps(priv);
for (tmp = 0, i = 0; i < priv->gpc_nr; i++)
tmp |= ((1 << priv->tpc_nr[i]) - 1) << (i * 4);
nv_wr32(priv, 0x4041c4, tmp);
gm204_grctx_generate_405b60(priv);
gf100_gr_icmd(priv, oclass->icmd);
nv_wr32(priv, 0x404154, 0x00000800);
gf100_gr_mthd(priv, oclass->mthd);
nv_mask(priv, 0x418e94, 0xffffffff, 0xc4230000);
nv_mask(priv, 0x418e4c, 0xffffffff, 0x70000000);
}
