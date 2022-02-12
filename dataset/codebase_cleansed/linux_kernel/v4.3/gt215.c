int
gt215_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)
{
return nv50_disp_new_(&gt215_disp, device, index, 2, pdisp);
}
