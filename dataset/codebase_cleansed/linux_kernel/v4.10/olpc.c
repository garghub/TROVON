static int is_simulated(unsigned int bus, unsigned int devfn)
{
return (!bus && ((PCI_SLOT(devfn) == NB_SLOT) ||
(PCI_SLOT(devfn) == SB_SLOT)));
}
static uint32_t *hdr_addr(const uint32_t *hdr, int reg)
{
uint32_t addr;
addr = (uint32_t)hdr + reg + (bar_probing ? -0x10 : 0x20);
bar_probing = 0;
return (uint32_t *)addr;
}
static int pci_olpc_read(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, uint32_t *value)
{
uint32_t *addr;
WARN_ON(seg);
if (!is_simulated(bus, devfn))
return pci_direct_conf1.read(seg, bus, devfn, reg, len, value);
if (reg >= 0x70)
addr = &zero_loc;
else {
switch (devfn) {
case 0x8:
addr = hdr_addr(is_lx ? lxnb_hdr : gxnb_hdr, reg);
break;
case 0x9:
addr = hdr_addr(is_lx ? lxfb_hdr : gxfb_hdr, reg);
break;
case 0xa:
addr = is_lx ? hdr_addr(aes_hdr, reg) : &ff_loc;
break;
case 0x78:
addr = hdr_addr(isa_hdr, reg);
break;
case 0x7b:
addr = hdr_addr(ac97_hdr, reg);
break;
case 0x7c:
addr = hdr_addr(ohci_hdr, reg);
break;
case 0x7d:
addr = hdr_addr(ehci_hdr, reg);
break;
default:
addr = &ff_loc;
break;
}
}
switch (len) {
case 1:
*value = *(uint8_t *)addr;
break;
case 2:
*value = *(uint16_t *)addr;
break;
case 4:
*value = *addr;
break;
default:
BUG();
}
return 0;
}
static int pci_olpc_write(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, uint32_t value)
{
WARN_ON(seg);
if (!is_simulated(bus, devfn))
return pci_direct_conf1.write(seg, bus, devfn, reg, len, value);
if ((reg >= 0x10) && (reg < 0x2c)) {
if (value == ~0)
bar_probing = 1;
} else {
if ((reg != PCI_ROM_ADDRESS) && (reg != PCI_COMMAND_MASTER) &&
(reg != PCI_LATENCY_TIMER) &&
(reg != PCI_CACHE_LINE_SIZE) && (reg != 0x44))
printk(KERN_WARNING "OLPC PCI: Config write to devfn"
" %x reg %x value %x\n", devfn, reg, value);
}
return 0;
}
int __init pci_olpc_init(void)
{
printk(KERN_INFO "PCI: Using configuration type OLPC XO-1\n");
raw_pci_ops = &pci_olpc_conf;
is_lx = is_geode_lx();
return 0;
}
