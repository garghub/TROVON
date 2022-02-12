int\r\nmcp77_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)\r\n{\r\nreturn nv50_disp_new_(&mcp77_disp, device, index, 2, pdisp);\r\n}
