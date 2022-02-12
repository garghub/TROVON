static void
gk20a_grctx_generate_main(struct gf100_gr *gr, struct gf100_grctx *info)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
const struct gf100_grctx_func *grctx = gr->func->grctx;
int idle_timeout_save;
int i;
gf100_gr_mmio(gr, gr->fuc_sw_ctx);
gf100_gr_wait_idle(gr);
idle_timeout_save = nvkm_rd32(device, 0x404154);
nvkm_wr32(device, 0x404154, 0x00000000);
grctx->attrib(info);
grctx->unkn(gr);
gf100_grctx_generate_tpcid(gr);
gf100_grctx_generate_r406028(gr);
gk104_grctx_generate_r418bb8(gr);
gf100_grctx_generate_r406800(gr);
for (i = 0; i < 8; i++)
nvkm_wr32(device, 0x4064d0 + (i * 0x04), 0x00000000);
nvkm_wr32(device, 0x405b00, (gr->tpc_total << 8) | gr->gpc_nr);
gk104_grctx_generate_rop_active_fbps(gr);
nvkm_mask(device, 0x5044b0, 0x08000000, 0x08000000);
gf100_gr_wait_idle(gr);
nvkm_wr32(device, 0x404154, idle_timeout_save);
gf100_gr_wait_idle(gr);
gf100_gr_mthd(gr, gr->fuc_method);
gf100_gr_wait_idle(gr);
gf100_gr_icmd(gr, gr->fuc_bundle);
grctx->pagepool(info);
grctx->bundle(info);
}
