static void __iomem *v3_open_config_window(struct pci_bus *bus,
unsigned int devfn, int offset)
{
unsigned int address, mapaddress, busnr;
busnr = bus->number;
BUG_ON(offset > 255);
BUG_ON(busnr > 255);
BUG_ON(devfn > 255);
if (busnr == 0) {
int slot = PCI_SLOT(devfn);
address = PCI_FUNC(devfn) << 8;
mapaddress = V3_LB_MAP_TYPE_CONFIG;
if (slot > 12)
mapaddress |= 1 << (slot - 5);
else
address |= 1 << (slot + 11);
} else {
mapaddress = V3_LB_MAP_TYPE_CONFIG | V3_LB_MAP_AD_LOW_EN;
address = (busnr << 16) | (devfn << 8);
}
v3_writel(V3_LB_BASE0, v3_addr_to_lb_base(non_mem.start) |
V3_LB_BASE_ADR_SIZE_512MB | V3_LB_BASE_ENABLE);
v3_writel(V3_LB_BASE1, v3_addr_to_lb_base(conf_mem.start) |
V3_LB_BASE_ADR_SIZE_16MB | V3_LB_BASE_ENABLE);
v3_writew(V3_LB_MAP1, mapaddress);
return PCI_CONFIG_VADDR + address + offset;
}
static void v3_close_config_window(void)
{
v3_writel(V3_LB_BASE1, v3_addr_to_lb_base(pre_mem.start) |
V3_LB_BASE_ADR_SIZE_256MB | V3_LB_BASE_PREFETCH |
V3_LB_BASE_ENABLE);
v3_writew(V3_LB_MAP1, v3_addr_to_lb_map(pre_mem_pci) |
V3_LB_MAP_TYPE_MEM_MULTIPLE);
v3_writel(V3_LB_BASE0, v3_addr_to_lb_base(non_mem.start) |
V3_LB_BASE_ADR_SIZE_256MB | V3_LB_BASE_ENABLE);
}
static int v3_read_config(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 *val)
{
void __iomem *addr;
unsigned long flags;
u32 v;
raw_spin_lock_irqsave(&v3_lock, flags);
addr = v3_open_config_window(bus, devfn, where);
switch (size) {
case 1:
v = __raw_readb(addr);
break;
case 2:
v = __raw_readw(addr);
break;
default:
v = __raw_readl(addr);
break;
}
v3_close_config_window();
raw_spin_unlock_irqrestore(&v3_lock, flags);
*val = v;
return PCIBIOS_SUCCESSFUL;
}
static int v3_write_config(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 val)
{
void __iomem *addr;
unsigned long flags;
raw_spin_lock_irqsave(&v3_lock, flags);
addr = v3_open_config_window(bus, devfn, where);
switch (size) {
case 1:
__raw_writeb((u8)val, addr);
__raw_readb(addr);
break;
case 2:
__raw_writew((u16)val, addr);
__raw_readw(addr);
break;
case 4:
__raw_writel(val, addr);
__raw_readl(addr);
break;
}
v3_close_config_window();
raw_spin_unlock_irqrestore(&v3_lock, flags);
return PCIBIOS_SUCCESSFUL;
}
static int __init pci_v3_setup_resources(struct pci_sys_data *sys)
{
if (request_resource(&iomem_resource, &non_mem)) {
printk(KERN_ERR "PCI: unable to allocate non-prefetchable "
"memory region\n");
return -EBUSY;
}
if (request_resource(&iomem_resource, &pre_mem)) {
release_resource(&non_mem);
printk(KERN_ERR "PCI: unable to allocate prefetchable "
"memory region\n");
return -EBUSY;
}
pci_add_resource_offset(&sys->resources, &non_mem, sys->mem_offset);
pci_add_resource_offset(&sys->resources, &pre_mem, sys->mem_offset);
return 1;
}
static int
v3_pci_fault(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
unsigned long pc = instruction_pointer(regs);
unsigned long instr = *(unsigned long *)pc;
#if 0
char buf[128];
sprintf(buf, "V3 fault: addr 0x%08lx, FSR 0x%03x, PC 0x%08lx [%08lx] LBFADDR=%08x LBFCODE=%02x ISTAT=%02x\n",
addr, fsr, pc, instr, __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFADDR_OFFSET), __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFCODE_OFFSET) & 255,
v3_readb(V3_LB_ISTAT));
printk(KERN_DEBUG "%s", buf);
#endif
v3_writeb(V3_LB_ISTAT, 0);
__raw_writel(3, ap_syscon_base + INTEGRATOR_SC_PCIENABLE_OFFSET);
if ((instr & 0x0c100000) == 0x04100000) {
int reg = (instr >> 12) & 15;
unsigned long val;
if (instr & 0x00400000)
val = 255;
else
val = -1;
regs->uregs[reg] = val;
regs->ARM_pc += 4;
return 0;
}
if ((instr & 0x0e100090) == 0x00100090) {
int reg = (instr >> 12) & 15;
regs->uregs[reg] = -1;
regs->ARM_pc += 4;
return 0;
}
return 1;
}
static irqreturn_t v3_irq(int irq, void *devid)
{
#ifdef CONFIG_DEBUG_LL
struct pt_regs *regs = get_irq_regs();
unsigned long pc = instruction_pointer(regs);
unsigned long instr = *(unsigned long *)pc;
char buf[128];
extern void printascii(const char *);
sprintf(buf, "V3 int %d: pc=0x%08lx [%08lx] LBFADDR=%08x LBFCODE=%02x "
"ISTAT=%02x\n", irq, pc, instr,
__raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFADDR_OFFSET),
__raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFCODE_OFFSET) & 255,
v3_readb(V3_LB_ISTAT));
printascii(buf);
#endif
v3_writew(V3_PCI_STAT, 0xf000);
v3_writeb(V3_LB_ISTAT, 0);
__raw_writel(3, ap_syscon_base + INTEGRATOR_SC_PCIENABLE_OFFSET);
#ifdef CONFIG_DEBUG_LL
if ((instr & 0x0c100000) == 0x04100000) {
int reg = (instr >> 16) & 15;
sprintf(buf, " reg%d = %08lx\n", reg, regs->uregs[reg]);
printascii(buf);
}
#endif
return IRQ_HANDLED;
}
static int __init pci_v3_setup(int nr, struct pci_sys_data *sys)
{
int ret = 0;
if (!ap_syscon_base)
return -EINVAL;
if (nr == 0) {
sys->mem_offset = non_mem.start;
ret = pci_v3_setup_resources(sys);
}
return ret;
}
static void __init pci_v3_preinit(void)
{
unsigned long flags;
unsigned int temp;
phys_addr_t io_address = pci_pio_to_address(io_mem.start);
pcibios_min_mem = 0x00100000;
hook_fault_code(4, v3_pci_fault, SIGBUS, 0, "external abort on linefetch");
hook_fault_code(6, v3_pci_fault, SIGBUS, 0, "external abort on linefetch");
hook_fault_code(8, v3_pci_fault, SIGBUS, 0, "external abort on non-linefetch");
hook_fault_code(10, v3_pci_fault, SIGBUS, 0, "external abort on non-linefetch");
raw_spin_lock_irqsave(&v3_lock, flags);
if (v3_readw(V3_SYSTEM) & V3_SYSTEM_M_LOCK)
v3_writew(V3_SYSTEM, 0xa05f);
v3_writel(V3_LB_BASE0, v3_addr_to_lb_base(non_mem.start) |
V3_LB_BASE_ADR_SIZE_256MB | V3_LB_BASE_ENABLE);
v3_writew(V3_LB_MAP0, v3_addr_to_lb_map(non_mem_pci) |
V3_LB_MAP_TYPE_MEM);
v3_writel(V3_LB_BASE1, v3_addr_to_lb_base(pre_mem.start) |
V3_LB_BASE_ADR_SIZE_256MB | V3_LB_BASE_PREFETCH |
V3_LB_BASE_ENABLE);
v3_writew(V3_LB_MAP1, v3_addr_to_lb_map(pre_mem_pci) |
V3_LB_MAP_TYPE_MEM_MULTIPLE);
v3_writel(V3_LB_BASE2, v3_addr_to_lb_base2(io_address) |
V3_LB_BASE_ENABLE);
v3_writew(V3_LB_MAP2, v3_addr_to_lb_map2(0));
temp = v3_readw(V3_PCI_CFG) & ~V3_PCI_CFG_M_I2O_EN;
temp |= V3_PCI_CFG_M_IO_REG_DIS | V3_PCI_CFG_M_IO_DIS;
v3_writew(V3_PCI_CFG, temp);
printk(KERN_DEBUG "FIFO_CFG: %04x FIFO_PRIO: %04x\n",
v3_readw(V3_FIFO_CFG), v3_readw(V3_FIFO_PRIORITY));
v3_writew(V3_FIFO_PRIORITY, 0x0a0a);
temp = v3_readw(V3_SYSTEM) | V3_SYSTEM_M_LOCK;
v3_writew(V3_SYSTEM, temp);
v3_writeb(V3_LB_ISTAT, 0);
v3_writew(V3_LB_CFG, v3_readw(V3_LB_CFG) | (1 << 10));
v3_writeb(V3_LB_IMASK, 0x28);
__raw_writel(3, ap_syscon_base + INTEGRATOR_SC_PCIENABLE_OFFSET);
raw_spin_unlock_irqrestore(&v3_lock, flags);
}
static void __init pci_v3_postinit(void)
{
unsigned int pci_cmd;
phys_addr_t io_address = pci_pio_to_address(io_mem.start);
pci_cmd = PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE;
v3_writew(V3_PCI_CMD, pci_cmd);
v3_writeb(V3_LB_ISTAT, ~0x40);
v3_writeb(V3_LB_IMASK, 0x68);
#if 0
ret = request_irq(IRQ_AP_LBUSTIMEOUT, lb_timeout, 0, "bus timeout", NULL);
if (ret)
printk(KERN_ERR "PCI: unable to grab local bus timeout "
"interrupt: %d\n", ret);
#endif
register_isa_ports(non_mem.start, io_address, 0);
}
static u8 __init pci_v3_swizzle(struct pci_dev *dev, u8 *pinp)
{
if (*pinp == 0)
*pinp = 1;
return pci_common_swizzle(dev, pinp);
}
static int __init pci_v3_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct of_pci_range_parser parser;
struct of_pci_range range;
struct resource *res;
int irq, ret;
ap_syscon_base = devm_ioremap(&pdev->dev, INTEGRATOR_SC_BASE, 0x100);
if (!ap_syscon_base) {
dev_err(&pdev->dev, "unable to remap the AP syscon for PCIv3\n");
return -ENODEV;
}
if (!np) {
dev_err(&pdev->dev, "no device tree node for PCIv3\n");
return -ENODEV;
}
if (of_pci_range_parser_init(&parser, np))
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "unable to obtain PCIv3 base\n");
return -ENODEV;
}
pci_v3_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pci_v3_base) {
dev_err(&pdev->dev, "unable to remap PCIv3 base\n");
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "unable to obtain PCIv3 error IRQ\n");
return -ENODEV;
}
ret = devm_request_irq(&pdev->dev, irq, v3_irq, 0,
"PCIv3 error", NULL);
if (ret < 0) {
dev_err(&pdev->dev, "unable to request PCIv3 error IRQ %d (%d)\n", irq, ret);
return ret;
}
for_each_of_pci_range(&parser, &range) {
if (!range.flags) {
ret = of_pci_range_to_resource(&range, np, &conf_mem);
conf_mem.name = "PCIv3 config";
}
if (range.flags & IORESOURCE_IO) {
ret = of_pci_range_to_resource(&range, np, &io_mem);
io_mem.name = "PCIv3 I/O";
}
if ((range.flags & IORESOURCE_MEM) &&
!(range.flags & IORESOURCE_PREFETCH)) {
non_mem_pci = range.pci_addr;
non_mem_pci_sz = range.size;
ret = of_pci_range_to_resource(&range, np, &non_mem);
non_mem.name = "PCIv3 non-prefetched mem";
}
if ((range.flags & IORESOURCE_MEM) &&
(range.flags & IORESOURCE_PREFETCH)) {
pre_mem_pci = range.pci_addr;
pre_mem_pci_sz = range.size;
ret = of_pci_range_to_resource(&range, np, &pre_mem);
pre_mem.name = "PCIv3 prefetched mem";
}
if (ret < 0) {
dev_err(&pdev->dev, "missing ranges in device node\n");
return ret;
}
}
pci_v3.map_irq = of_irq_parse_and_map_pci;
pci_common_init_dev(&pdev->dev, &pci_v3);
return 0;
}
static int __init pci_v3_init(void)
{
return platform_driver_probe(&pci_v3_driver, pci_v3_probe);
}
int __init pci_v3_early_init(void)
{
iotable_init(pci_v3_io_desc, ARRAY_SIZE(pci_v3_io_desc));
vga_base = (unsigned long)PCI_MEMORY_VADDR;
pci_map_io_early(__phys_to_pfn(PHYS_PCI_IO_BASE));
return 0;
}
