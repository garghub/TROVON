int\r\ngm107_ce_new(struct nvkm_device *device, int index,\r\nstruct nvkm_engine **pengine)\r\n{\r\nreturn nvkm_engine_new_(&gm107_ce, device, index, true, pengine);\r\n}
