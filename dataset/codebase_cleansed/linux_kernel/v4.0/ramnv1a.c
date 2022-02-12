static int
nv1a_ram_create(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_fb *pfb = nvkm_fb(parent);
struct nvkm_ram *ram;
struct pci_dev *bridge;
u32 mem, mib;
int ret;
bridge = pci_get_bus_and_slot(0, PCI_DEVFN(0, 1));
if (!bridge) {
nv_fatal(pfb, "no bridge device\n");
return -ENODEV;
}
ret = nvkm_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
if (nv_device(pfb)->chipset == 0x1a) {
pci_read_config_dword(bridge, 0x7c, &mem);
mib = ((mem >> 6) & 31) + 1;
} else {
pci_read_config_dword(bridge, 0x84, &mem);
mib = ((mem >> 4) & 127) + 1;
}
ram->type = NV_MEM_TYPE_STOLEN;
ram->size = mib * 1024 * 1024;
return 0;
}
