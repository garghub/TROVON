int\r\nnv4c_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)\r\n{\r\nreturn nvkm_pci_new_(&nv4c_pci_func, device, index, ppci);\r\n}
