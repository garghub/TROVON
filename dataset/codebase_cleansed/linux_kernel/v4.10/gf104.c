int
gf104_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return gf100_gr_new_(&gf104_gr, device, index, pgr);
}
