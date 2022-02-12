int
nv4c_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
return nvkm_pci_new_(&nv4c_pci_func, device, index, ppci);
}
