static void
gm20b_pmu_recv(struct nvkm_pmu *pmu)
{
if (!pmu->queue) {
nvkm_warn(&pmu->subdev,
"recv function called while no firmware set!\n");
return;
}
nvkm_msgqueue_recv(pmu->queue);
}
int
gm20b_pmu_new(struct nvkm_device *device, int index, struct nvkm_pmu **ppmu)
{
int ret;
ret = nvkm_pmu_new_(&gm20b_pmu, device, index, ppmu);
if (ret)
return ret;
return 0;
}
