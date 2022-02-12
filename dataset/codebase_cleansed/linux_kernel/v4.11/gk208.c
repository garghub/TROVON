int\r\ngk208_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)\r\n{\r\nreturn nvkm_pmu_new_(&gk208_pmu, device, index, ppmu);\r\n}
