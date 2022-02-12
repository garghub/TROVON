int\r\ngp107_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)\r\n{\r\nreturn gm200_gr_new_(&gp107_gr, device, index, pgr);\r\n}
