static void set_val(u32 v, int where, int size, u32 *val)
{
int shift = (where & 3) * 8;
pr_debug("set_val %04x: %08x\n", (unsigned)(where & ~3), v);
v >>= shift;
if (size == 1)
v &= 0xff;
else if (size == 2)
v &= 0xffff;
*val = v;
}
static int handle_ea_bar(u32 e0, int bar, struct pci_bus *bus,
unsigned int devfn, int where, int size, u32 *val)
{
void __iomem *addr;
u32 v;
int where_a = where & 0xc;
if (where_a == 0) {
set_val(e0, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0x4) {
addr = bus->ops->map_bus(bus, devfn, bar);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
v &= ~0xf;
v |= 2;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0x8) {
u32 barl_orig;
u32 barl_rb;
addr = bus->ops->map_bus(bus, devfn, bar);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
barl_orig = readl(addr + 0);
writel(0xffffffff, addr + 0);
barl_rb = readl(addr + 0);
writel(barl_orig, addr + 0);
v = ~barl_rb & ~3;
v |= 0xc;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xc) {
addr = bus->ops->map_bus(bus, devfn, bar + 4);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
return PCIBIOS_DEVICE_NOT_FOUND;
}
static int thunder_ecam_p2_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct pci_config_window *cfg = bus->sysdata;
int where_a = where & ~3;
void __iomem *addr;
u32 node_bits;
u32 v;
switch (where_a) {
case 0xa8:
case 0xbc:
case 0xd0:
case 0xe4:
break;
default:
return pci_generic_config_read(bus, devfn, where, size, val);
}
addr = bus->ops->map_bus(bus, devfn, where_a);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
node_bits = (cfg->res.start >> 32) & (1 << 12);
v |= node_bits;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
static int thunder_ecam_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u32 v;
u32 vendor_device;
u32 class_rev;
void __iomem *addr;
int cfg_type;
int where_a = where & ~3;
addr = bus->ops->map_bus(bus, devfn, 0xc);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
cfg_type = (v >> 16) & 0x7f;
addr = bus->ops->map_bus(bus, devfn, 8);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
class_rev = readl(addr);
if (class_rev == 0xffffffff)
goto no_emulation;
if ((class_rev & 0xff) >= 8) {
if (cfg_type)
goto no_emulation;
return thunder_ecam_p2_config_read(bus, devfn, where,
size, val);
}
if (cfg_type == 0 &&
((where >= 0x10 && where < 0x2c) ||
(where >= 0x1a4 && where < 0x1bc))) {
*val = 0;
return PCIBIOS_SUCCESSFUL;
}
addr = bus->ops->map_bus(bus, devfn, 0);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
vendor_device = readl(addr);
if (vendor_device == 0xffffffff)
goto no_emulation;
pr_debug("%04x:%04x - Fix pass#: %08x, where: %03x, devfn: %03x\n",
vendor_device & 0xffff, vendor_device >> 16, class_rev,
(unsigned) where, devfn);
if (cfg_type == 0) {
bool has_msix;
bool is_nic = (vendor_device == 0xa01e177d);
bool is_tns = (vendor_device == 0xa01f177d);
addr = bus->ops->map_bus(bus, devfn, 0x70);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
has_msix = (v & 0xff00) != 0;
if (!has_msix && where_a == 0x70) {
v |= 0xbc00;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xb0) {
addr = bus->ops->map_bus(bus, devfn, where_a);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
if (v & 0xff00)
pr_err("Bad MSIX cap header: %08x\n", v);
v |= 0xbc00;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xbc) {
if (is_nic)
v = 0x40014;
else if (is_tns)
v = 0x30014;
else if (has_msix)
v = 0x20014;
else
v = 0x10014;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a >= 0xc0 && where_a < 0xd0)
return handle_ea_bar(0x80ff0003,
0x10, bus, devfn, where,
size, val);
if (where_a >= 0xd0 && where_a < 0xe0 && has_msix)
return handle_ea_bar(0x80ff0043,
0x20, bus, devfn, where,
size, val);
if (where_a >= 0xe0 && where_a < 0xf0 && is_tns)
return handle_ea_bar(0x80ff0023,
0x18, bus, devfn, where,
size, val);
if (where_a >= 0xe0 && where_a < 0xf0 && is_nic)
return handle_ea_bar(0x80ff0493,
0x1a4, bus, devfn, where,
size, val);
if (where_a >= 0xf0 && where_a < 0x100 && is_nic)
return handle_ea_bar(0x80ff04d3,
0x1b4, bus, devfn, where,
size, val);
} else if (cfg_type == 1) {
bool is_rsl_bridge = devfn == 0x08;
bool is_rad_bridge = devfn == 0xa0;
bool is_zip_bridge = devfn == 0xa8;
bool is_dfa_bridge = devfn == 0xb0;
bool is_nic_bridge = devfn == 0x10;
if (where_a == 0x70) {
addr = bus->ops->map_bus(bus, devfn, where_a);
if (!addr) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
v = readl(addr);
if (v & 0xff00)
pr_err("Bad PCIe cap header: %08x\n", v);
v |= 0xbc00;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xbc) {
if (is_nic_bridge)
v = 0x10014;
else
v = 0x00014;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xc0) {
if (is_rsl_bridge || is_nic_bridge)
v = 0x0101;
else if (is_rad_bridge)
v = 0x0202;
else if (is_zip_bridge)
v = 0x0303;
else if (is_dfa_bridge)
v = 0x0404;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xc4 && is_nic_bridge) {
v = 0x80ff0564;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xc8 && is_nic_bridge) {
v = 0x00000002;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xcc && is_nic_bridge) {
v = 0xfffffffe;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xd0 && is_nic_bridge) {
v = 0x00008430;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
if (where_a == 0xd4 && is_nic_bridge) {
v = 0x0000000f;
set_val(v, where, size, val);
return PCIBIOS_SUCCESSFUL;
}
}
no_emulation:
return pci_generic_config_read(bus, devfn, where, size, val);
}
static int thunder_ecam_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
if ((where >= 0x10 && where < 0x2c) ||
(where >= 0x1a4 && where < 0x1bc))
return PCIBIOS_SUCCESSFUL;
return pci_generic_config_write(bus, devfn, where, size, val);
}
static int thunder_ecam_probe(struct platform_device *pdev)
{
return pci_host_common_probe(pdev, &pci_thunder_ecam_ops);
}
