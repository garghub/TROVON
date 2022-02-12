static void
pwr_perfctr_init(struct nvkm_pm *ppm, struct nvkm_perfdom *dom,
struct nvkm_perfctr *ctr)
{
u32 mask = 0x00000000;
u32 ctrl = 0x00000001;
int i;
for (i = 0; i < ARRAY_SIZE(ctr->signal) && ctr->signal[i]; i++)
mask |= 1 << (ctr->signal[i] - dom->signal);
nv_wr32(ppm, 0x10a504 + (ctr->slot * 0x10), mask);
nv_wr32(ppm, 0x10a50c + (ctr->slot * 0x10), ctrl);
nv_wr32(ppm, 0x10a50c + (ppm->last * 0x10), 0x00000003);
}
static void
pwr_perfctr_read(struct nvkm_pm *ppm, struct nvkm_perfdom *dom,
struct nvkm_perfctr *ctr)
{
ctr->ctr = ppm->pwr[ctr->slot];
ctr->clk = ppm->pwr[ppm->last];
}
static void
pwr_perfctr_next(struct nvkm_pm *ppm, struct nvkm_perfdom *dom)
{
int i;
for (i = 0; i <= ppm->last; i++) {
ppm->pwr[i] = nv_rd32(ppm, 0x10a508 + (i * 0x10));
nv_wr32(ppm, 0x10a508 + (i * 0x10), 0x80000000);
}
}
