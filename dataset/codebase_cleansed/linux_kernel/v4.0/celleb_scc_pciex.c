static void scc_pciex_io_flush(struct iowa_bus *bus)
{
(void)PEX_IN(bus->phb->cfg_addr, PEXDMRDEN0);
}
static void scc_pciex_memcpy_fromio(void *dest, const PCI_IO_ADDR src,
unsigned long n)
{
__do_memcpy_fromio(dest, src, n);
scc_pciex_io_flush(iowa_mem_find_bus(src));
}
static inline unsigned long get_bus_address(struct pci_controller *phb,
unsigned long port)
{
return port - ((unsigned long)(phb->io_base_virt) - _IO_BASE);
}
static u32 scc_pciex_read_port(struct pci_controller *phb,
unsigned long port, int size)
{
unsigned int byte_enable;
unsigned int cmd, shift;
unsigned long addr;
u32 data, ret;
BUG_ON(((port & 0x3ul) + size) > 4);
addr = get_bus_address(phb, port);
shift = addr & 0x3ul;
byte_enable = ((1 << size) - 1) << shift;
cmd = PEXDCMND_IO_READ | (byte_enable << PEXDCMND_BYTE_EN_SHIFT);
PEX_OUT(phb->cfg_addr, PEXDADRS, (addr & ~0x3ul));
PEX_OUT(phb->cfg_addr, PEXDCMND, cmd);
data = PEX_IN(phb->cfg_addr, PEXDRDATA);
ret = (data >> (shift * 8)) & (0xFFFFFFFF >> ((4 - size) * 8));
pr_debug("PCIEX:PIO READ:port=0x%lx, addr=0x%lx, size=%d, be=%x,"
" cmd=%x, data=%x, ret=%x\n", port, addr, size, byte_enable,
cmd, data, ret);
return ret;
}
static void scc_pciex_write_port(struct pci_controller *phb,
unsigned long port, int size, u32 val)
{
unsigned int byte_enable;
unsigned int cmd, shift;
unsigned long addr;
u32 data;
BUG_ON(((port & 0x3ul) + size) > 4);
addr = get_bus_address(phb, port);
shift = addr & 0x3ul;
byte_enable = ((1 << size) - 1) << shift;
cmd = PEXDCMND_IO_WRITE | (byte_enable << PEXDCMND_BYTE_EN_SHIFT);
data = (val & (0xFFFFFFFF >> (4 - size) * 8)) << (shift * 8);
PEX_OUT(phb->cfg_addr, PEXDADRS, (addr & ~0x3ul));
PEX_OUT(phb->cfg_addr, PEXDCMND, cmd);
PEX_OUT(phb->cfg_addr, PEXDWDATA, data);
pr_debug("PCIEX:PIO WRITE:port=0x%lx, addr=%lx, size=%d, val=%x,"
" be=%x, cmd=%x, data=%x\n", port, addr, size, val,
byte_enable, cmd, data);
}
static u8 __scc_pciex_inb(struct pci_controller *phb, unsigned long port)
{
return (u8)scc_pciex_read_port(phb, port, 1);
}
static u16 __scc_pciex_inw(struct pci_controller *phb, unsigned long port)
{
u32 data;
if ((port & 0x3ul) < 3)
data = scc_pciex_read_port(phb, port, 2);
else {
u32 d1 = scc_pciex_read_port(phb, port, 1);
u32 d2 = scc_pciex_read_port(phb, port + 1, 1);
data = d1 | (d2 << 8);
}
return (u16)data;
}
static u32 __scc_pciex_inl(struct pci_controller *phb, unsigned long port)
{
unsigned int mod = port & 0x3ul;
u32 data;
if (mod == 0)
data = scc_pciex_read_port(phb, port, 4);
else {
u32 d1 = scc_pciex_read_port(phb, port, 4 - mod);
u32 d2 = scc_pciex_read_port(phb, port + 1, mod);
data = d1 | (d2 << (mod * 8));
}
return data;
}
static void __scc_pciex_outb(struct pci_controller *phb,
u8 val, unsigned long port)
{
scc_pciex_write_port(phb, port, 1, (u32)val);
}
static void __scc_pciex_outw(struct pci_controller *phb,
u16 val, unsigned long port)
{
if ((port & 0x3ul) < 3)
scc_pciex_write_port(phb, port, 2, (u32)val);
else {
u32 d1 = val & 0x000000FF;
u32 d2 = (val & 0x0000FF00) >> 8;
scc_pciex_write_port(phb, port, 1, d1);
scc_pciex_write_port(phb, port + 1, 1, d2);
}
}
static void __scc_pciex_outl(struct pci_controller *phb,
u32 val, unsigned long port)
{
unsigned int mod = port & 0x3ul;
if (mod == 0)
scc_pciex_write_port(phb, port, 4, val);
else {
u32 d1 = val & (0xFFFFFFFFul >> (mod * 8));
u32 d2 = val >> ((4 - mod) * 8);
scc_pciex_write_port(phb, port, 4 - mod, d1);
scc_pciex_write_port(phb, port + 1, mod, d2);
}
}
static int __init scc_pciex_iowa_init(struct iowa_bus *bus, void *data)
{
dma_addr_t dummy_page_da;
void *dummy_page_va;
dummy_page_va = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!dummy_page_va) {
pr_err("PCIEX:Alloc dummy_page_va failed\n");
return -1;
}
dummy_page_da = dma_map_single(bus->phb->parent, dummy_page_va,
PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(bus->phb->parent, dummy_page_da)) {
pr_err("PCIEX:Map dummy page failed.\n");
kfree(dummy_page_va);
return -1;
}
PEX_OUT(bus->phb->cfg_addr, PEXDMRDADR0, dummy_page_da);
return 0;
}
static uint32_t config_read_pciex_dev(unsigned int __iomem *base,
uint64_t bus_no, uint64_t dev_no, uint64_t func_no,
uint64_t off, uint64_t size)
{
uint32_t ret;
uint32_t addr, cmd;
addr = MK_PEXDADRS(bus_no, dev_no, func_no, off);
cmd = MK_PEXDCMND(PEXDCMND_CONFIG_READ, off, size);
PEX_OUT(base, PEXDADRS, addr);
PEX_OUT(base, PEXDCMND, cmd);
ret = (PEX_IN(base, PEXDRDATA)
>> ((off & (4-size)) * 8)) & ((0x1 << (size * 8)) - 1);
return ret;
}
static void config_write_pciex_dev(unsigned int __iomem *base, uint64_t bus_no,
uint64_t dev_no, uint64_t func_no, uint64_t off, uint64_t size,
uint32_t data)
{
uint32_t addr, cmd;
addr = MK_PEXDADRS(bus_no, dev_no, func_no, off);
cmd = MK_PEXDCMND(PEXDCMND_CONFIG_WRITE, off, size);
PEX_OUT(base, PEXDADRS, addr);
PEX_OUT(base, PEXDCMND, cmd);
PEX_OUT(base, PEXDWDATA,
(data & ((0x1 << (size * 8)) - 1)) << ((off & (4-size)) * 8));
}
static uint32_t config_read_pciex_rc(unsigned int __iomem *base,
uint32_t where, uint32_t size)
{
PEX_OUT(base, PEXCADRS, MK_PEXCADRS(PEXCADRS_CMD_READ, where, size));
return (PEX_IN(base, PEXCRDATA)
>> ((where & (4 - size)) * 8)) & ((0x1 << (size * 8)) - 1);
}
static void config_write_pciex_rc(unsigned int __iomem *base, uint32_t where,
uint32_t size, uint32_t val)
{
uint32_t data;
data = (val & ((0x1 << (size * 8)) - 1)) << ((where & (4 - size)) * 8);
PEX_OUT(base, PEXCADRS, MK_PEXCADRS(PEXCADRS_CMD_WRITE, where, size));
PEX_OUT(base, PEXCWDATA, data);
}
static int scc_pciex_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, unsigned int *val)
{
struct pci_controller *phb = pci_bus_to_host(bus);
if (bus->number == phb->first_busno && PCI_SLOT(devfn) != 1) {
*val = ~0;
return PCIBIOS_DEVICE_NOT_FOUND;
}
if (bus->number == 0 && PCI_SLOT(devfn) == 0)
*val = config_read_pciex_rc(phb->cfg_addr, where, size);
else
*val = config_read_pciex_dev(phb->cfg_addr, bus->number,
PCI_SLOT(devfn), PCI_FUNC(devfn), where, size);
return PCIBIOS_SUCCESSFUL;
}
static int scc_pciex_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, unsigned int val)
{
struct pci_controller *phb = pci_bus_to_host(bus);
if (bus->number == phb->first_busno && PCI_SLOT(devfn) != 1)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == 0 && PCI_SLOT(devfn) == 0)
config_write_pciex_rc(phb->cfg_addr, where, size, val);
else
config_write_pciex_dev(phb->cfg_addr, bus->number,
PCI_SLOT(devfn), PCI_FUNC(devfn), where, size, val);
return PCIBIOS_SUCCESSFUL;
}
static void pciex_clear_intr_all(unsigned int __iomem *base)
{
PEX_OUT(base, PEXAERRSTS, 0xffffffff);
PEX_OUT(base, PEXPRERRSTS, 0xffffffff);
PEX_OUT(base, PEXINTSTS, 0xffffffff);
}
static void pciex_enable_intr_all(unsigned int __iomem *base)
{
PEX_OUT(base, PEXINTMASK, 0x0000e7f1);
PEX_OUT(base, PEXAERRMASK, 0x03ff01ff);
PEX_OUT(base, PEXPRERRMASK, 0x0001010f);
PEX_OUT(base, PEXVDMASK, 0x00000001);
}
static void pciex_check_status(unsigned int __iomem *base)
{
uint32_t err = 0;
uint32_t intsts, aerr, prerr, rcvcp, lenerr;
uint32_t maea, maec;
intsts = PEX_IN(base, PEXINTSTS);
aerr = PEX_IN(base, PEXAERRSTS);
prerr = PEX_IN(base, PEXPRERRSTS);
rcvcp = PEX_IN(base, PEXRCVCPLIDA);
lenerr = PEX_IN(base, PEXLENERRIDA);
if (intsts || aerr || prerr || rcvcp || lenerr)
err = 1;
pr_info("PCEXC interrupt!!\n");
pr_info("PEXINTSTS :0x%08x\n", intsts);
pr_info("PEXAERRSTS :0x%08x\n", aerr);
pr_info("PEXPRERRSTS :0x%08x\n", prerr);
pr_info("PEXRCVCPLIDA :0x%08x\n", rcvcp);
pr_info("PEXLENERRIDA :0x%08x\n", lenerr);
if (intsts & 0x00004000) {
uint32_t i, n;
for (i = 0; i < 4; i++) {
n = 1 << i;
if (prerr & n) {
maea = PEX_IN(base, PEXMAEA(i));
maec = PEX_IN(base, PEXMAEC(i));
pr_info("PEXMAEC%d :0x%08x\n", i, maec);
pr_info("PEXMAEA%d :0x%08x\n", i, maea);
}
}
}
if (err)
pciex_clear_intr_all(base);
}
static irqreturn_t pciex_handle_internal_irq(int irq, void *dev_id)
{
struct pci_controller *phb = dev_id;
pr_debug("PCIEX:pciex_handle_internal_irq(irq=%d)\n", irq);
BUG_ON(phb->cfg_addr == NULL);
pciex_check_status(phb->cfg_addr);
return IRQ_HANDLED;
}
static __init int celleb_setup_pciex(struct device_node *node,
struct pci_controller *phb)
{
struct resource r;
int virq;
if (of_address_to_resource(node, 0, &r)) {
pr_err("PCIEXC:Failed to get config resource.\n");
return 1;
}
phb->cfg_addr = ioremap(r.start, resource_size(&r));
if (!phb->cfg_addr) {
pr_err("PCIEXC:Failed to remap SMMIO region.\n");
return 1;
}
phb->cfg_data = NULL;
phb->ops = &scc_pciex_pci_ops;
virq = irq_of_parse_and_map(node, 1);
if (!virq) {
pr_err("PCIEXC:Failed to map irq\n");
goto error;
}
if (request_irq(virq, pciex_handle_internal_irq,
0, "pciex", (void *)phb)) {
pr_err("PCIEXC:Failed to request irq\n");
goto error;
}
pciex_clear_intr_all(phb->cfg_addr);
pciex_enable_intr_all(phb->cfg_addr);
return 0;
error:
phb->cfg_data = NULL;
if (phb->cfg_addr)
iounmap(phb->cfg_addr);
phb->cfg_addr = NULL;
return 1;
}
