int pci_enable_rom(struct pci_dev *pdev)
{
struct resource *res = &pdev->resource[PCI_ROM_RESOURCE];
struct pci_bus_region region;
u32 rom_addr;
if (!res->flags)
return -1;
if (res->flags & IORESOURCE_ROM_SHADOW)
return 0;
pcibios_resource_to_bus(pdev->bus, &region, res);
pci_read_config_dword(pdev, pdev->rom_base_reg, &rom_addr);
rom_addr &= ~PCI_ROM_ADDRESS_MASK;
rom_addr |= region.start | PCI_ROM_ADDRESS_ENABLE;
pci_write_config_dword(pdev, pdev->rom_base_reg, rom_addr);
return 0;
}
void pci_disable_rom(struct pci_dev *pdev)
{
struct resource *res = &pdev->resource[PCI_ROM_RESOURCE];
u32 rom_addr;
if (res->flags & IORESOURCE_ROM_SHADOW)
return;
pci_read_config_dword(pdev, pdev->rom_base_reg, &rom_addr);
rom_addr &= ~PCI_ROM_ADDRESS_ENABLE;
pci_write_config_dword(pdev, pdev->rom_base_reg, rom_addr);
}
size_t pci_get_rom_size(struct pci_dev *pdev, void __iomem *rom, size_t size)
{
void __iomem *image;
int last_image;
unsigned length;
image = rom;
do {
void __iomem *pds;
if (readw(image) != 0xAA55) {
dev_err(&pdev->dev, "Invalid PCI ROM header signature: expecting 0xaa55, got %#06x\n",
readw(image));
break;
}
pds = image + readw(image + 24);
if (readl(pds) != 0x52494350) {
dev_err(&pdev->dev, "Invalid PCI ROM data signature: expecting 0x52494350, got %#010x\n",
readl(pds));
break;
}
last_image = readb(pds + 21) & 0x80;
length = readw(pds + 16);
image += length * 512;
if (image > rom + size)
break;
} while (length && !last_image);
return min((size_t)(image - rom), size);
}
void __iomem *pci_map_rom(struct pci_dev *pdev, size_t *size)
{
struct resource *res = &pdev->resource[PCI_ROM_RESOURCE];
loff_t start;
void __iomem *rom;
if (res->parent == NULL && pci_assign_resource(pdev, PCI_ROM_RESOURCE))
return NULL;
start = pci_resource_start(pdev, PCI_ROM_RESOURCE);
*size = pci_resource_len(pdev, PCI_ROM_RESOURCE);
if (*size == 0)
return NULL;
if (pci_enable_rom(pdev))
return NULL;
rom = ioremap(start, *size);
if (!rom) {
if (!(res->flags & IORESOURCE_ROM_ENABLE))
pci_disable_rom(pdev);
return NULL;
}
*size = pci_get_rom_size(pdev, rom, *size);
return rom;
}
void pci_unmap_rom(struct pci_dev *pdev, void __iomem *rom)
{
struct resource *res = &pdev->resource[PCI_ROM_RESOURCE];
iounmap(rom);
if (!(res->flags & IORESOURCE_ROM_ENABLE))
pci_disable_rom(pdev);
}
void __iomem *pci_platform_rom(struct pci_dev *pdev, size_t *size)
{
if (pdev->rom && pdev->romlen) {
*size = pdev->romlen;
return phys_to_virt((phys_addr_t)pdev->rom);
}
return NULL;
}
