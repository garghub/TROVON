int\r\ngm20b_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)\r\n{\r\nreturn gf100_fb_new_(&gm20b_fb, device, index, pfb);\r\n}
