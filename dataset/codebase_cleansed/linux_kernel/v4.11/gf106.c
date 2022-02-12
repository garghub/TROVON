int
gf106_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
return nvkm_pci_new_(&gf106_pci_func, device, index, ppci);
}
