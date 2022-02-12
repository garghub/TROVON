int\r\ngk104_msvld_new(struct nvkm_device *device, int index,\r\nstruct nvkm_engine **pengine)\r\n{\r\nreturn nvkm_msvld_new_(&gk104_msvld, device, index, pengine);\r\n}
