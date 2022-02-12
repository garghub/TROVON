int
nv11_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
return nvkm_mc_new_(&nv11_mc, device, index, pmc);
}
