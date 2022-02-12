int
nv15_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return nv10_gr_new_(&nv15_gr, device, index, pgr);
}
