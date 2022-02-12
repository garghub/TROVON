static void __iomem *thunder_pem_map_bus(struct pci_bus *bus,
unsigned int devfn, int where)
{
struct gen_pci *pci = bus->sysdata;
resource_size_t idx = bus->number - pci->cfg.bus_range->start;
return pci->cfg.win[idx] + ((devfn << 16) | where);
}
static int thunder_pem_bridge_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u64 read_val;
struct thunder_pem_pci *pem_pci;
struct gen_pci *pci = bus->sysdata;
pem_pci = container_of(pci, struct thunder_pem_pci, gen_pci);
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
struct gen_pci *pci = bus->sysdata;
if (bus->number < pci->cfg.bus_range->start ||
bus->number > pci->cfg.bus_range->end)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == pci->cfg.bus_range->start)
return thunder_pem_bridge_read(bus, devfn, where, size, val);
return pci_generic_config_read(bus, devfn, where, size, val);
}
static u32 thunder_pem_bridge_w1c_bits(int where)
{
u32 w1c_bits = 0;
switch (where & ~3) {
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
static int thunder_pem_bridge_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct gen_pci *pci = bus->sysdata;
struct thunder_pem_pci *pem_pci;
u64 write_val, read_val;
u32 mask = 0;
pem_pci = container_of(pci, struct thunder_pem_pci, gen_pci);
if (devfn != 0 || where >= 2048)
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1:
read_val = where & ~3ull;
writeq(read_val, pem_pci->pem_reg_base + PEM_CFG_RD);
read_val = readq(pem_pci->pem_reg_base + PEM_CFG_RD);
read_val >>= 32;
mask = ~(0xff << (8 * (where & 3)));
read_val &= mask;
val = (val & 0xff) << (8 * (where & 3));
val |= (u32)read_val;
break;
case 2:
read_val = where & ~3ull;
writeq(read_val, pem_pci->pem_reg_base + PEM_CFG_RD);
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
write_val = where & ~3ull;
write_val |= (((u64)val) << 32);
writeq(write_val, pem_pci->pem_reg_base + PEM_CFG_WR);
return PCIBIOS_SUCCESSFUL;
}
static int thunder_pem_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct gen_pci *pci = bus->sysdata;
if (bus->number < pci->cfg.bus_range->start ||
bus->number > pci->cfg.bus_range->end)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == pci->cfg.bus_range->start)
return thunder_pem_bridge_write(bus, devfn, where, size, val);
return pci_generic_config_write(bus, devfn, where, size, val);
}
static int thunder_pem_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
resource_size_t bar4_start;
struct resource *res_pem;
struct thunder_pem_pci *pem_pci;
pem_pci = devm_kzalloc(dev, sizeof(*pem_pci), GFP_KERNEL);
if (!pem_pci)
return -ENOMEM;
of_id = of_match_node(thunder_pem_of_match, dev->of_node);
pem_pci->gen_pci.cfg.ops = (struct gen_pci_cfg_bus_ops *)of_id->data;
res_pem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res_pem) {
dev_err(dev, "missing \"reg[1]\"property\n");
return -EINVAL;
}
pem_pci->pem_reg_base = devm_ioremap(dev, res_pem->start, 0x10000);
if (!pem_pci->pem_reg_base)
return -ENOMEM;
bar4_start = res_pem->start + 0xf00000;
pem_pci->ea_entry[0] = (u32)bar4_start | 2;
pem_pci->ea_entry[1] = (u32)(res_pem->end - bar4_start) & ~3u;
pem_pci->ea_entry[2] = (u32)(bar4_start >> 32);
return pci_host_common_probe(pdev, &pem_pci->gen_pci);
}
