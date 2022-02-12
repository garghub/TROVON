static int thunder_pem_bridge_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u64 read_val;
struct pci_config_window *cfg = bus->sysdata;
struct thunder_pem_pci *pem_pci = (struct thunder_pem_pci *)cfg->priv;
if (devfn != 0 || where >= 2048) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
read_val = where & ~3ull;
writeq(read_val, pem_pci->pem_reg_base + PEM_CFG_RD);
read_val = readq(pem_pci->pem_reg_base + PEM_CFG_RD);
read_val >>= 32;
switch (where & ~3) {
case 0x40:
read_val &= 0xffff00ff;
read_val |= 0x00007000;
break;
case 0x70:
read_val |= (2u << 25);
break;
case 0xb0:
read_val &= 0xc00000ff;
read_val |= 0x0003bc00;
break;
case 0xb4:
read_val = 0x00000000;
break;
case 0xb8:
read_val = 0x000f0000;
break;
case 0xbc:
read_val = 0x00010014;
break;
case 0xc0:
read_val = 0x00000000;
break;
case 0xc4:
read_val = 0x80ff0003;
break;
case 0xc8:
read_val = pem_pci->ea_entry[0];
break;
case 0xcc:
read_val = pem_pci->ea_entry[1];
break;
case 0xd0:
read_val = pem_pci->ea_entry[2];
break;
default:
break;
}
read_val >>= (8 * (where & 3));
switch (size) {
case 1:
read_val &= 0xff;
break;
case 2:
read_val &= 0xffff;
break;
default:
break;
}
*val = read_val;
return PCIBIOS_SUCCESSFUL;
}
static int thunder_pem_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct pci_config_window *cfg = bus->sysdata;
if (bus->number < cfg->busr.start ||
bus->number > cfg->busr.end)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == cfg->busr.start)
return thunder_pem_bridge_read(bus, devfn, where, size, val);
return pci_generic_config_read(bus, devfn, where, size, val);
}
static u32 thunder_pem_bridge_w1c_bits(u64 where_aligned)
{
u32 w1c_bits = 0;
switch (where_aligned) {
case 0x04:
case 0x1c:
w1c_bits = 0xff000000;
break;
case 0x44:
w1c_bits = 0xfffffe00;
break;
case 0x78:
case 0x80:
case 0x88:
case 0x90:
case 0xa0:
w1c_bits = 0xffff0000;
break;
case 0x104:
case 0x110:
case 0x130:
case 0x160:
w1c_bits = 0xffffffff;
break;
default:
break;
}
return w1c_bits;
}
static u32 thunder_pem_bridge_w1_bits(u64 where_aligned)
{
u32 w1_bits;
switch (where_aligned) {
case 0x1c:
w1_bits = 0x0101;
break;
case 0x24:
w1_bits = 0x00010001;
break;
default:
w1_bits = 0;
break;
}
return w1_bits;
}
static int thunder_pem_bridge_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct pci_config_window *cfg = bus->sysdata;
struct thunder_pem_pci *pem_pci = (struct thunder_pem_pci *)cfg->priv;
u64 write_val, read_val;
u64 where_aligned = where & ~3ull;
u32 mask = 0;
if (devfn != 0 || where >= 2048)
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1:
writeq(where_aligned, pem_pci->pem_reg_base + PEM_CFG_RD);
read_val = readq(pem_pci->pem_reg_base + PEM_CFG_RD);
read_val >>= 32;
mask = ~(0xff << (8 * (where & 3)));
read_val &= mask;
val = (val & 0xff) << (8 * (where & 3));
val |= (u32)read_val;
break;
case 2:
writeq(where_aligned, pem_pci->pem_reg_base + PEM_CFG_RD);
read_val = readq(pem_pci->pem_reg_base + PEM_CFG_RD);
read_val >>= 32;
mask = ~(0xffff << (8 * (where & 3)));
read_val &= mask;
val = (val & 0xffff) << (8 * (where & 3));
val |= (u32)read_val;
break;
default:
break;
}
if (mask) {
u32 w1c_bits = thunder_pem_bridge_w1c_bits(where);
if (w1c_bits) {
mask &= w1c_bits;
val &= ~mask;
}
}
val |= thunder_pem_bridge_w1_bits(where_aligned);
write_val = (((u64)val) << 32) | where_aligned;
writeq(write_val, pem_pci->pem_reg_base + PEM_CFG_WR);
return PCIBIOS_SUCCESSFUL;
}
static int thunder_pem_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct pci_config_window *cfg = bus->sysdata;
if (bus->number < cfg->busr.start ||
bus->number > cfg->busr.end)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == cfg->busr.start)
return thunder_pem_bridge_write(bus, devfn, where, size, val);
return pci_generic_config_write(bus, devfn, where, size, val);
}
static int thunder_pem_init(struct device *dev, struct pci_config_window *cfg,
struct resource *res_pem)
{
struct thunder_pem_pci *pem_pci;
resource_size_t bar4_start;
pem_pci = devm_kzalloc(dev, sizeof(*pem_pci), GFP_KERNEL);
if (!pem_pci)
return -ENOMEM;
pem_pci->pem_reg_base = devm_ioremap(dev, res_pem->start, 0x10000);
if (!pem_pci->pem_reg_base)
return -ENOMEM;
bar4_start = res_pem->start + 0xf00000;
pem_pci->ea_entry[0] = (u32)bar4_start | 2;
pem_pci->ea_entry[1] = (u32)(res_pem->end - bar4_start) & ~3u;
pem_pci->ea_entry[2] = (u32)(bar4_start >> 32);
cfg->priv = pem_pci;
return 0;
}
static int thunder_pem_acpi_init(struct pci_config_window *cfg)
{
struct device *dev = cfg->parent;
struct acpi_device *adev = to_acpi_device(dev);
struct acpi_pci_root *root = acpi_driver_data(adev);
struct resource *res_pem;
int ret;
res_pem = devm_kzalloc(&adev->dev, sizeof(*res_pem), GFP_KERNEL);
if (!res_pem)
return -ENOMEM;
ret = acpi_get_rc_resources(dev, "THRX0002", root->segment, res_pem);
if (ret) {
dev_err(dev, "can't get rc base address\n");
return ret;
}
return thunder_pem_init(dev, cfg, res_pem);
}
static int thunder_pem_platform_init(struct pci_config_window *cfg)
{
struct device *dev = cfg->parent;
struct platform_device *pdev = to_platform_device(dev);
struct resource *res_pem;
if (!dev->of_node)
return -EINVAL;
res_pem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res_pem) {
dev_err(dev, "missing \"reg[1]\"property\n");
return -EINVAL;
}
return thunder_pem_init(dev, cfg, res_pem);
}
static int thunder_pem_probe(struct platform_device *pdev)
{
return pci_host_common_probe(pdev, &pci_thunder_pem_ops);
}
