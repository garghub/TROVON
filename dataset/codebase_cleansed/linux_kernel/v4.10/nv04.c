static u32
nv04_pci_rd32(struct nvkm_pci *pci, u16 addr)
{
struct nvkm_device *device = pci->subdev.device;
return nvkm_rd32(device, 0x001800 + addr);
}
static void
nv04_pci_wr08(struct nvkm_pci *pci, u16 addr, u8 data)
{
struct nvkm_device *device = pci->subdev.device;
nvkm_wr08(device, 0x001800 + addr, data);
}
static void
nv04_pci_wr32(struct nvkm_pci *pci, u16 addr, u32 data)
{
struct nvkm_device *device = pci->subdev.device;
nvkm_wr32(device, 0x001800 + addr, data);
}
int
nv04_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
return nvkm_pci_new_(&nv04_pci_func, device, index, ppci);
}
