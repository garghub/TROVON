void
gf117_grctx_generate_attrib(struct gf100_grctx *info)
{
struct gf100_gr *gr = info->gr;
const struct gf100_grctx_func *grctx = gr->func->grctx;
const u32 alpha = grctx->alpha_nr;
const u32 beta = grctx->attrib_nr;
const u32 size = 0x20 * (grctx->attrib_nr_max + grctx->alpha_nr_max);
const u32 access = NV_MEM_ACCESS_RW;
const int s = 12;
const int b = mmio_vram(info, size * gr->tpc_total, (1 << s), access);
const int timeslice_mode = 1;
const int max_batches = 0xffff;
u32 bo = 0;
u32 ao = bo + grctx->attrib_nr_max * gr->tpc_total;
int gpc, ppc;
mmio_refn(info, 0x418810, 0x80000000, s, b);
mmio_refn(info, 0x419848, 0x10000000, s, b);
mmio_wr32(info, 0x405830, (beta << 16) | alpha);
mmio_wr32(info, 0x4064c4, ((alpha / 4) << 16) | max_batches);
for (gpc = 0; gpc < gr->gpc_nr; gpc++) {
for (ppc = 0; ppc < gr->ppc_nr[gpc]; ppc++) {
const u32 a = alpha * gr->ppc_tpc_nr[gpc][ppc];
const u32 b = beta * gr->ppc_tpc_nr[gpc][ppc];
const u32 t = timeslice_mode;
const u32 o = PPC_UNIT(gpc, ppc, 0);
mmio_skip(info, o + 0xc0, (t << 28) | (b << 16) | ++bo);
mmio_wr32(info, o + 0xc0, (t << 28) | (b << 16) | --bo);
bo += grctx->attrib_nr_max * gr->ppc_tpc_nr[gpc][ppc];
mmio_wr32(info, o + 0xe4, (a << 16) | ao);
ao += grctx->alpha_nr_max * gr->ppc_tpc_nr[gpc][ppc];
}
}
}
void
gf117_grctx_generate_main(struct gf100_gr *gr, struct gf100_grctx *info)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
const struct gf100_grctx_func *grctx = gr->func->grctx;
int i;
nvkm_mc_unk260(device->mc, 0);
gf100_gr_mmio(gr, grctx->hub);
gf100_gr_mmio(gr, grctx->gpc);
gf100_gr_mmio(gr, grctx->zcull);
gf100_gr_mmio(gr, grctx->tpc);
gf100_gr_mmio(gr, grctx->ppc);
nvkm_wr32(device, 0x404154, 0x00000000);
grctx->bundle(info);
grctx->pagepool(info);
grctx->attrib(info);
grctx->unkn(gr);
gf100_grctx_generate_tpcid(gr);
gf100_grctx_generate_r406028(gr);
gf100_grctx_generate_r4060a8(gr);
gk104_grctx_generate_r418bb8(gr);
gf100_grctx_generate_r406800(gr);
for (i = 0; i < 8; i++)
nvkm_wr32(device, 0x4064d0 + (i * 0x04), 0x00000000);
gf100_gr_icmd(gr, grctx->icmd);
nvkm_wr32(device, 0x404154, 0x00000400);
gf100_gr_mthd(gr, grctx->mthd);
nvkm_mc_unk260(device->mc, 1);
}
