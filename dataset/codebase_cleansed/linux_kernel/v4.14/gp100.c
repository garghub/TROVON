int
gp100_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
return nvkm_pmu_new_(&gp100_pmu, device, index, ppmu);
}
