int
gp107_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return gm200_gr_new_(&gp107_gr, device, index, pgr);
}
