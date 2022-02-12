int\r\nnv4e_i2c_pad_new(struct nvkm_i2c *i2c, int id, struct nvkm_i2c_pad **ppad)\r\n{\r\nreturn nvkm_i2c_pad_new_(&nv4e_i2c_pad_func, i2c, id, ppad);\r\n}
