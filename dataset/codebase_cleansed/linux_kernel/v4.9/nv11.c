int\r\nnv11_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)\r\n{\r\nreturn nvkm_mc_new_(&nv11_mc, device, index, pmc);\r\n}
