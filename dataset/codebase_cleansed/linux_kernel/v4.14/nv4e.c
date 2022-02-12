int\r\nnv4e_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)\r\n{\r\nreturn nvkm_fb_new_(&nv4e_fb, device, index, pfb);\r\n}
