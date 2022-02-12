int
gf108_pm_new(struct nvkm_device *device, int index, struct nvkm_pm **ppm)
{
return gf100_pm_new_(&gf108_pm, device, index, ppm);
}
