int
gt200_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)
{
return nv50_disp_new_(&gt200_disp, device, index, 2, pdisp);
}
