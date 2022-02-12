int
gf117_pm_new(struct nvkm_device *device, int index, struct nvkm_pm **ppm)
{
return gf100_pm_new_(&gf117_pm, device, index, ppm);
}
