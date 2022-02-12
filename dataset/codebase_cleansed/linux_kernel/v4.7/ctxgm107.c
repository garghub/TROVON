void
gm107_grctx_generate_bundle(struct gf100_grctx *info)
{
const struct gf100_grctx_func *grctx = info->gr->func->grctx;
const u32 state_limit = min(grctx->bundle_min_gpm_fifo_depth,
grctx->bundle_size / 0x20);
const u32 token_limit = grctx->bundle_token_limit;
const u32 access = NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS;
const int s = 8;
const int b = mmio_vram(info, grctx->bundle_size, (1 << s), access);
mmio_refn(info, 0x408004, 0x00000000, s, b);
mmio_wr32(info, 0x408008, 0x80000000 | (grctx->bundle_size >> s));
mmio_refn(info, 0x418e24, 0x00000000, s, b);
mmio_wr32(info, 0x418e28, 0x80000000 | (grctx->bundle_size >> s));
mmio_wr32(info, 0x4064c8, (state_limit << 16) | token_limit);
}
void
gm107_grctx_generate_pagepool(struct gf100_grctx *info)
{
const struct gf100_grctx_func *grctx = info->gr->func->grctx;
const u32 access = NV_MEM_ACCESS_RW | NV_MEM_ACCESS_SYS;
const int s = 8;
const int b = mmio_vram(info, grctx->pagepool_size, (1 << s), access);
mmio_refn(info, 0x40800c, 0x00000000, s, b);
mmio_wr32(info, 0x408010, 0x80000000);
mmio_refn(info, 0x419004, 0x00000000, s, b);
mmio_wr32(info, 0x419008, 0x00000000);
mmio_wr32(info, 0x4064cc, 0x80000000);
mmio_wr32(info, 0x418e30, 0x80000000);
}
void
gm107_grctx_generate_attrib(struct gf100_grctx *info)
{
struct gf100_gr *gr = info->gr;
const struct gf100_grctx_func *grctx = gr->func->grctx;
const u32 alpha = grctx->alpha_nr;
const u32 attrib = grctx->attrib_nr;
const u32 size = 0x20 * (grctx->attrib_nr_max + grctx->alpha_nr_max);
const u32 access = NV_MEM_ACCESS_RW;
const int s = 12;
const int b = mmio_vram(info, size * gr->tpc_total, (1 << s), access);
const int max_batches = 0xffff;
u32 bo = 0;
u32 ao = bo + grctx->attrib_nr_max * gr->tpc_total;
int gpc, ppc, n = 0;
mmio_refn(info, 0x418810, 0x80000000, s, b);
mmio_refn(info, 0x419848, 0x10000000, s, b);
mmio_refn(info, 0x419c2c, 0x10000000, s, b);
mmio_wr32(info, 0x405830, (attrib << 16) | alpha);
mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);
for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
for (ppc = 0; ppc < gr->ppc_nr[gpc]; ppc++, n++) {
const u32 as = alpha * gr->ppc_tpc_nr[gpc][ppc];
const u32 bs = attrib * gr->ppc_tpc_nr[gpc][ppc];
const u32 u = 0x418ea0 + (n * 0x04);
const u32 o = PPC_UNIT(gpc, ppc, 0);
if (!(gr->ppc_mask[gpc] & (1 << ppc)))
continue;
mmio_wr32(info, o + 0xc0, bs);
mmio_wr32(info, o + 0xf4, bo);
bo += grctx->attrib_nr_max * gr->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, o + 0xe4, as);
mmio_wr32(info, o + 0xf8, ao);
ao += grctx->alpha_nr_max * gr->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, u, ((bs / 3) << 16) | bs);
}
}
}
void
gm107_grctx_generate_tpcid(struct gf100_gr *gr)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
int gpc, tpc, id;
for (tpc = 0, id = 0; tpc < 4; tpc++) {
for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
if (tpc < gr->tpc_nr[gpc]) {
nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x698), id);
nvkm_wr32(device, GPC_UNIT(gpc, 0x0c10 + tpc * 4), id);
nvkm_wr32(device, TPC_UNIT(gpc, tpc, 0x088), id);
id++;
}
nvkm_wr32(device, GPC_UNIT(gpc, 0x0c08), gr->tpc_nr[gpc]);
nvkm_wr32(device, GPC_UNIT(gpc, 0x0c8c), gr->tpc_nr[gpc]);
}
}
}
static void
gm107_grctx_generate_main(struct gf100_gr *gr, struct gf100_grctx *info)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
const struct gf100_grctx_func *grctx = gr->func->grctx;
u32 idle_timeout;
int i;
gf100_gr_mmio(gr, grctx->hub);
gf100_gr_mmio(gr, grctx->gpc);
gf100_gr_mmio(gr, grctx->zcull);
gf100_gr_mmio(gr, grctx->tpc);
gf100_gr_mmio(gr, grctx->ppc);
idle_timeout = nvkm_mask(device, 0x404154, 0xffffffff, 0x00000000);
grctx->bundle(info);
grctx->pagepool(info);
grctx->attrib(info);
grctx->unkn(gr);
gm107_grctx_generate_tpcid(gr);
gf100_grctx_generate_r406028(gr);
gk104_grctx_generate_r418bb8(gr);
gf100_grctx_generate_r406800(gr);
nvkm_wr32(device, 0x4064d0, 0x00000001);
for (i = 1; i < 8; i++)
nvkm_wr32(device, 0x4064d0 + (i * 0x04), 0x00000000);
nvkm_wr32(device, 0x406500, 0x00000001);
nvkm_wr32(device, 0x405b00, (gr->tpc_total << 8) | gr->gpc_nr);
gf100_gr_icmd(gr, grctx->icmd);
nvkm_wr32(device, 0x404154, idle_timeout);
gf100_gr_mthd(gr, grctx->mthd);
nvkm_mask(device, 0x419e00, 0x00808080, 0x00808080);
nvkm_mask(device, 0x419ccc, 0x80000000, 0x80000000);
nvkm_mask(device, 0x419f80, 0x80000000, 0x80000000);
nvkm_mask(device, 0x419f88, 0x80000000, 0x80000000);
}
