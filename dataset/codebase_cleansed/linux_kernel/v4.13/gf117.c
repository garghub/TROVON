int
gf117_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return gf100_gr_new_(&gf117_gr, device, index, pgr);
}
