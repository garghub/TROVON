int\r\nnv1a_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)\r\n{\r\nreturn nvkm_fb_new_(&nv1a_fb, device, index, pfb);\r\n}
