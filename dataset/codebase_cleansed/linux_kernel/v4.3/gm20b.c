static void
gm20b_gr_init_gpc_mmu(struct gf100_gr *gr)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
u32 val;
if (1) {
nvkm_wr32(device, 0x100ce4, 0xffffffff);
}
val = nvkm_rd32(device, 0x100c80);
val &= 0xf000087f;
nvkm_wr32(device, 0x418880, val);
nvkm_wr32(device, 0x418890, 0);
nvkm_wr32(device, 0x418894, 0);
nvkm_wr32(device, 0x4188b0, nvkm_rd32(device, 0x100cc4));
nvkm_wr32(device, 0x4188b4, nvkm_rd32(device, 0x100cc8));
nvkm_wr32(device, 0x4188b8, nvkm_rd32(device, 0x100ccc));
nvkm_wr32(device, 0x4188ac, nvkm_rd32(device, 0x100800));
}
static void
gm20b_gr_set_hww_esr_report_mask(struct gf100_gr *gr)
{
struct nvkm_device *device = gr->base.engine.subdev.device;
nvkm_wr32(device, 0x419e44, 0xdffffe);
nvkm_wr32(device, 0x419e4c, 0x5);
}
int
gm20b_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return gk20a_gr_new_(&gm20b_gr, device, index, pgr);
}
