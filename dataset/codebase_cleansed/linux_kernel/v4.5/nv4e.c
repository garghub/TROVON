int\r\nnv4e_i2c_new(struct nvkm_device *device, int index, struct nvkm_i2c **pi2c)\r\n{\r\nreturn nvkm_i2c_new_(&nv4e_i2c, device, index, pi2c);\r\n}
