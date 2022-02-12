int
mcp77_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)
{
return nv50_disp_new_(&mcp77_disp, device, index, 2, pdisp);
}
