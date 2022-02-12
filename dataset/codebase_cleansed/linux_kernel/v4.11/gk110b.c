int\r\ngk110b_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)\r\n{\r\nreturn gf100_gr_new_(&gk110b_gr, device, index, pgr);\r\n}
