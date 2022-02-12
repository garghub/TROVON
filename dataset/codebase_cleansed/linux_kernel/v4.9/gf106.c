int\r\ngf106_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)\r\n{\r\nreturn nvkm_pci_new_(&gf106_pci_func, device, index, ppci);\r\n}
