void
gk110_pmu_pgob(struct nvkm_pmu *pmu, bool enable)
{
struct nvkm_device *device = pmu->subdev.device;
static const struct {
u32 addr;
u32 data;
} magic[] = {
{ 0x020520, 0xfffffffc },
{ 0x020524, 0xfffffffe },
{ 0x020524, 0xfffffffc },
{ 0x020524, 0xfffffff8 },
{ 0x020524, 0xffffffe0 },
{ 0x020530, 0xfffffffe },
{ 0x02052c, 0xfffffffa },
{ 0x02052c, 0xfffffff0 },
{ 0x02052c, 0xffffffc0 },
{ 0x02052c, 0xffffff00 },
{ 0x02052c, 0xfffffc00 },
{ 0x02052c, 0xfffcfc00 },
{ 0x02052c, 0xfff0fc00 },
{ 0x02052c, 0xff80fc00 },
{ 0x020528, 0xfffffffe },
{ 0x020528, 0xfffffffc },
};
int i;
nvkm_mask(device, 0x000200, 0x00001000, 0x00000000);
nvkm_rd32(device, 0x000200);
nvkm_mask(device, 0x000200, 0x08000000, 0x08000000);
msleep(50);
nvkm_mask(device, 0x10a78c, 0x00000002, 0x00000002);
nvkm_mask(device, 0x10a78c, 0x00000001, 0x00000001);
nvkm_mask(device, 0x10a78c, 0x00000001, 0x00000000);
nvkm_mask(device, 0x0206b4, 0x00000000, 0x00000000);
for (i = 0; i < ARRAY_SIZE(magic); i++) {
nvkm_wr32(device, magic[i].addr, magic[i].data);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, magic[i].addr) & 0x80000000))
break;
);
}
nvkm_mask(device, 0x10a78c, 0x00000002, 0x00000000);
nvkm_mask(device, 0x10a78c, 0x00000001, 0x00000001);
nvkm_mask(device, 0x10a78c, 0x00000001, 0x00000000);
nvkm_mask(device, 0x000200, 0x08000000, 0x00000000);
nvkm_mask(device, 0x000200, 0x00001000, 0x00001000);
nvkm_rd32(device, 0x000200);
}
int
gk110_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
return nvkm_pmu_new_(&gk110_pmu, device, index, ppmu);
}
