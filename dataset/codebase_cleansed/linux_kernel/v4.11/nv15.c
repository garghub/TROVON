int\r\nnv15_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)\r\n{\r\nreturn nv10_gr_new_(&nv15_gr, device, index, pgr);\r\n}
