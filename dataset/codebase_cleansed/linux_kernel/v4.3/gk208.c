int
gk208_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
return nvkm_pmu_new_(&gk208_pmu, device, index, ppmu);
}
