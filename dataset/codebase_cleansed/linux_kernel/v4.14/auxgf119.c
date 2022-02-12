int\r\ngf119_i2c_aux_new(struct nvkm_i2c_pad *pad, int index, u8 drive,\r\nstruct nvkm_i2c_aux **paux)\r\n{\r\nreturn g94_i2c_aux_new_(&gf119_i2c_aux, pad, index, drive, paux);\r\n}
