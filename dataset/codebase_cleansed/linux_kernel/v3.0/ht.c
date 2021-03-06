static __inline__ int check_titan_htlink(void)
{
u32 val;
val = *(volatile uint32_t *)(RM9000x2_HTLINK_REG);
if (val & 0x00000020)
return 1;
else
return 0;
}
static int titan_ht_config_read_dword(struct pci_dev *device,
int offset, u32* val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
RM9K_WRITE(address_reg, address);
RM9K_READ(data_reg, val);
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_read_word(struct pci_dev *device,
int offset, u16* val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
if ((offset & 0x3) == 0)
offset = 0x2;
else
offset = 0x0;
RM9K_WRITE(address_reg, address);
RM9K_READ_16(data_reg + offset, val);
return PCIBIOS_SUCCESSFUL;
}
u32 longswap(unsigned long l)
{
unsigned char b1, b2, b3, b4;
b1 = l&255;
b2 = (l>>8)&255;
b3 = (l>>16)&255;
b4 = (l>>24)&255;
return ((b1<<24) + (b2<<16) + (b3<<8) + b4);
}
static int titan_ht_config_read_byte(struct pci_dev *device,
int offset, u8* val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
int offset1;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
RM9K_WRITE(address_reg, address);
if ((offset & 0x3) == 0) {
offset1 = 0x3;
}
if ((offset & 0x3) == 1) {
offset1 = 0x2;
}
if ((offset & 0x3) == 2) {
offset1 = 0x1;
}
if ((offset & 0x3) == 3) {
offset1 = 0x0;
}
RM9K_READ_8(data_reg + offset1, val);
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_write_dword(struct pci_dev *device,
int offset, u8 val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
RM9K_WRITE(address_reg, address);
RM9K_WRITE(data_reg, val);
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_write_word(struct pci_dev *device,
int offset, u8 val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
if ((offset & 0x3) == 0)
offset = 0x2;
else
offset = 0x0;
RM9K_WRITE(address_reg, address);
RM9K_WRITE_16(data_reg + offset, val);
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_write_byte(struct pci_dev *device,
int offset, u8 val)
{
int dev, bus, func;
uint32_t address_reg, data_reg;
uint32_t address;
int offset1;
bus = device->bus->number;
dev = PCI_SLOT(device->devfn);
func = PCI_FUNC(device->devfn);
if (bus > 2)
address = (bus << 16) | (dev << 11) | (func << 8) | (offset & 0xfc) |
0x80000000 | 0x1;
else
address = (dev << 11) | (func << 8) | (offset & 0xfc) | 0x80000000;
address_reg = RM9000x2_OCD_HTCFGA;
data_reg = RM9000x2_OCD_HTCFGD;
RM9K_WRITE(address_reg, address);
if ((offset & 0x3) == 0) {
offset1 = 0x3;
}
if ((offset & 0x3) == 1) {
offset1 = 0x2;
}
if ((offset & 0x3) == 2) {
offset1 = 0x1;
}
if ((offset & 0x3) == 3) {
offset1 = 0x0;
}
RM9K_WRITE_8(data_reg + offset1, val);
return PCIBIOS_SUCCESSFUL;
}
static void titan_pcibios_set_master(struct pci_dev *dev)
{
u16 cmd;
int bus = dev->bus->number;
if (check_titan_htlink())
titan_ht_config_read_word(dev, PCI_COMMAND, &cmd);
cmd |= PCI_COMMAND_MASTER;
if (check_titan_htlink())
titan_ht_config_write_word(dev, PCI_COMMAND, cmd);
}
int pcibios_enable_resources(struct pci_dev *dev)
{
u16 cmd, old_cmd;
u8 tmp1;
int idx;
struct resource *r;
int bus = dev->bus->number;
if (check_titan_htlink())
titan_ht_config_read_word(dev, PCI_COMMAND, &cmd);
old_cmd = cmd;
for (idx = 0; idx < 6; idx++) {
r = &dev->resource[idx];
if (!r->start && r->end) {
printk(KERN_ERR
"PCI: Device %s not available because of "
"resource collisions\n", pci_name(dev));
return -EINVAL;
}
if (r->flags & IORESOURCE_IO)
cmd |= PCI_COMMAND_IO;
if (r->flags & IORESOURCE_MEM)
cmd |= PCI_COMMAND_MEMORY;
}
if (cmd != old_cmd) {
if (check_titan_htlink())
titan_ht_config_write_word(dev, PCI_COMMAND, cmd);
}
if (check_titan_htlink())
titan_ht_config_read_byte(dev, PCI_CACHE_LINE_SIZE, &tmp1);
if (tmp1 != 8) {
printk(KERN_WARNING "PCI setting cache line size to 8 from "
"%d\n", tmp1);
}
if (check_titan_htlink())
titan_ht_config_write_byte(dev, PCI_CACHE_LINE_SIZE, 8);
if (check_titan_htlink())
titan_ht_config_read_byte(dev, PCI_LATENCY_TIMER, &tmp1);
if (tmp1 < 32 || tmp1 == 0xff) {
printk(KERN_WARNING "PCI setting latency timer to 32 from %d\n",
tmp1);
}
if (check_titan_htlink())
titan_ht_config_write_byte(dev, PCI_LATENCY_TIMER, 32);
return 0;
}
int pcibios_enable_device(struct pci_dev *dev, int mask)
{
return pcibios_enable_resources(dev);
}
resource_size_t pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
struct pci_dev *dev = data;
resource_size_t start = res->start;
if (res->flags & IORESOURCE_IO) {
if (size > 0x100) {
printk(KERN_ERR "PCI: I/O Region %s/%d too large"
" (%ld bytes)\n", pci_name(dev),
dev->resource - res, size);
}
start = (start + 1024 - 1) & ~(1024 - 1);
}
return start;
}
void __init pcibios_fixup_bus(struct pci_bus *c)
{
titan_ht_pcibios_fixup_bus(c);
}
void __init pcibios_init(void)
{
ioport_resource.start = 0xe0000000;
ioport_resource.end = 0xe0000000 + 0x20000000 - 1;
iomem_resource.start = 0xc0000000;
iomem_resource.end = 0xc0000000 + 0x20000000 - 1;
pci_scan_bus(2, &titan_pci_ops, NULL);
pci_scan_bus(3, &titan_pci_ops, NULL);
}
char *pcibios_setup(char *str)
{
printk(KERN_INFO "rr: pcibios_setup\n");
return str;
}
unsigned __init int pcibios_assign_all_busses(void)
{
return 0;
}
