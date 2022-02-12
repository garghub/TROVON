int\r\ngt200_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)\r\n{\r\nreturn nv50_disp_new_(&gt200_disp, device, index, 2, pdisp);\r\n}
