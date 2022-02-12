int
mcp79_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return nv50_gr_new_(&mcp79_gr, device, index, pgr);
}
