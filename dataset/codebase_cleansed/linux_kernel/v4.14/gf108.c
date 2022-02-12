int\r\ngf108_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)\r\n{\r\nreturn gf100_fb_new_(&gf108_fb, device, index, pfb);\r\n}
