int
gt200_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return nv50_gr_new_(&gt200_gr, device, index, pgr);
}
