static void
gp102_pmu_reset(struct nvkm_pmu *pmu)
{
struct nvkm_device *device = pmu->subdev.device;
nvkm_mask(device, 0x10a3c0, 0x00000001, 0x00000001);
nvkm_mask(device, 0x10a3c0, 0x00000001, 0x00000000);
}
int
gp102_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
return nvkm_pmu_new_(&gp102_pmu, device, index, ppmu);
}
