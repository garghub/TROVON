int
nv17_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
return nvkm_mc_new_(&nv17_mc, device, index, pmc);
}
