int
g92_pcie_version_supported(struct nvkm_pci *pci)
{
if ((nvkm_pci_rd32(pci, 0x460) & 0x200) == 0x200)
return 2;
return 1;
}
int
g92_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
return nvkm_pci_new_(&g92_pci_func, device, index, ppci);
}
