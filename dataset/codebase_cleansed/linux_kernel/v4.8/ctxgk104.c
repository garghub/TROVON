void
gk104_grctx_generate_bundle(struct gf100_grctx *info)
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
mmio_refn(info, 0x418808, 0x00000000, s, b);
mmio_wr32(info, 0x41880c, 0x80000000 | (grctx->bundle_size >> s));
mmio_wr32(info, 0x4064c8, (state_limit << 16) | token_limit);
}
void
gk104_grctx_generate_pagepool(struct gf100_grctx *info)
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
}
void
gk104_grctx_generate_unkn(struct gf100_gr *gr)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
nvkm_mask(device, 0x418c6c, 0x00000001, 0x00000001);
nvkm_mask(device, 0x41980c, 0x00000010, 0x00000010);
nvkm_mask(device, 0x41be08, 0x00000004, 0x00000004);
nvkm_mask(device, 0x4064c0, 0x80000000, 0x80000000);
nvkm_mask(device, 0x405800, 0x08000000, 0x08000000);
nvkm_mask(device, 0x419c00, 0x00000008, 0x00000008);
}
void
gk104_grctx_generate_r418bb8(struct gf100_gr *gr)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
u32 data[6] = {}, data2[2] = {};
u8 tpcnr[GPC_MAX];
u8 shift, ntpcv;
int gpc, tpc, i;
memcpy(tpcnr, gr->tpc_nr, sizeof(gr->tpc_nr));
gpc = -1;
for (tpc = 0; tpc < gr->tpc_total; tpc++) {
do {
gpc = (gpc + 1) % gr->gpc_nr;
} while (!tpcnr[gpc]);
tpcnr[gpc]--;
data[tpc / 6] |= gpc << ((tpc % 6) * 5);
}
for (; tpc < 32; tpc++)
data[tpc / 6] |= 7 << ((tpc % 6) * 5);
shift = 0;
ntpcv = gr->tpc_total;
while (!(ntpcv & (1 << 4))) {
ntpcv <<= 1;
shift++;
}
data2[0] = (ntpcv << 16);
data2[0] |= (shift << 21);
data2[0] |= (((1 << (0 + 5)) % ntpcv) << 24);
for (i = 1; i < 7; i++)
data2[1] |= ((1 << (i + 5)) % ntpcv) << ((i - 1) * 5);
nvkm_wr32(device, 0x418bb8, (gr->tpc_total << 8) |
gr->screen_tile_row_offset);
for (i = 0; i < 6; i++)
nvkm_wr32(device, 0x418b08 + (i * 4), data[i]);
nvkm_wr32(device, 0x41bfd0, (gr->tpc_total << 8) |
gr->screen_tile_row_offset | data2[0]);
nvkm_wr32(device, 0x41bfe4, data2[1]);
for (i = 0; i < 6; i++)
nvkm_wr32(device, 0x41bf00 + (i * 4), data[i]);
nvkm_wr32(device, 0x4078bc, (gr->tpc_total << 8) |
gr->screen_tile_row_offset);
for (i = 0; i < 6; i++)
nvkm_wr32(device, 0x40780c + (i * 4), data[i]);
}
void
gk104_grctx_generate_main(struct gf100_gr *gr, struct gf100_grctx *info)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
const struct gf100_grctx_func *grctx = gr->func->grctx;
u32 idle_timeout;
int i;
nvkm_mc_unk260(device, 0);
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
gf100_grctx_generate_tpcid(gr);
gf100_grctx_generate_r406028(gr);
gk104_grctx_generate_r418bb8(gr);
gf100_grctx_generate_r406800(gr);
for (i = 0; i < 8; i++)
nvkm_wr32(device, 0x4064d0 + (i * 0x04), 0x00000000);
nvkm_wr32(device, 0x405b00, (gr->tpc_total << 8) | gr->gpc_nr);
nvkm_mask(device, 0x419f78, 0x00000001, 0x00000000);
gf100_gr_icmd(gr, grctx->icmd);
nvkm_wr32(device, 0x404154, idle_timeout);
gf100_gr_mthd(gr, grctx->mthd);
nvkm_mc_unk260(device, 1);
nvkm_mask(device, 0x418800, 0x00200000, 0x00200000);
nvkm_mask(device, 0x41be10, 0x00800000, 0x00800000);
}
