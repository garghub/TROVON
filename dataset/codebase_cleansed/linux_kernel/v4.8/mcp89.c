int\r\nmcp89_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)\r\n{\r\nreturn nv50_fb_new_(&mcp89_fb, device, index, pfb);\r\n}
