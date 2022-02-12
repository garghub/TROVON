static void __init
nautilus_init_irq(void)
{
if (alpha_using_srm) {
alpha_mv.device_interrupt = srm_device_interrupt;
}
init_i8259a_irqs();
common_init_isa_dma();
}
static int __init
nautilus_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
u8 irq;
if (slot == 1 && pin == 2 &&
dev->bus->self && dev->bus->self->device == 0x700f)
return 5;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &irq);
return irq;
}
void
nautilus_kill_arch(int mode)
{
struct pci_bus *bus = pci_isa_hose->bus;
u32 pmuport;
int off;
switch (mode) {
case LINUX_REBOOT_CMD_RESTART:
if (! alpha_using_srm) {
u8 t8;
pci_bus_read_config_byte(bus, 0x38, 0x43, &t8);
pci_bus_write_config_byte(bus, 0x38, 0x43, t8 | 0x80);
outb(1, 0x92);
outb(0, 0x92);
}
break;
case LINUX_REBOOT_CMD_POWER_OFF:
off = 0x2000;
pci_bus_read_config_dword(bus, 0x88, 0x10, &pmuport);
if (!pmuport) {
off = 0x3400;
pci_bus_read_config_dword(bus, 0x88, 0xe0, &pmuport);
}
pmuport &= 0xfffe;
outw(0xffff, pmuport);
outw(off, pmuport + 4);
break;
}
}
static void
naut_sys_machine_check(unsigned long vector, unsigned long la_ptr,
struct pt_regs *regs)
{
printk("PC %lx RA %lx\n", regs->pc, regs->r26);
irongate_pci_clr_err();
}
void
nautilus_machine_check(unsigned long vector, unsigned long la_ptr)
{
char *mchk_class;
if (vector == SCB_Q_SYSMCHK
&& ((IRONGATE0->dramms & 0x300) == 0x300)) {
unsigned long nmi_ctl;
nmi_ctl = inb(0x61);
nmi_ctl |= 0x0c;
outb(nmi_ctl, 0x61);
nmi_ctl &= ~0x0c;
outb(nmi_ctl, 0x61);
IRONGATE0->stat_cmd = IRONGATE0->stat_cmd & ~0x100;
mb();
IRONGATE0->stat_cmd;
IRONGATE0->dramms = IRONGATE0->dramms;
mb();
IRONGATE0->dramms;
draina();
wrmces(0x7);
mb();
return;
}
if (vector == SCB_Q_SYSERR)
mchk_class = "Correctable";
else if (vector == SCB_Q_SYSMCHK)
mchk_class = "Fatal";
else {
ev6_machine_check(vector, la_ptr);
return;
}
printk(KERN_CRIT "NAUTILUS Machine check 0x%lx "
"[%s System Machine Check (NMI)]\n",
vector, mchk_class);
naut_sys_machine_check(vector, la_ptr, get_irq_regs());
draina();
wrmces(0x7);
mb();
}
void __init
nautilus_init_pci(void)
{
struct pci_controller *hose = hose_head;
struct pci_bus *bus;
struct pci_dev *irongate;
unsigned long bus_align, bus_size, pci_mem;
unsigned long memtop = max_low_pfn << PAGE_SHIFT;
bus = pci_scan_bus(0, alpha_mv.pci_ops, hose);
hose->bus = bus;
pcibios_claim_one_bus(bus);
irongate = pci_get_bus_and_slot(0, 0);
bus->self = irongate;
bus->resource[1] = &irongate_mem;
pci_bus_size_bridges(bus);
bus->resource[0]->start = 0;
bus->resource[0]->end = 0xffff;
bus_align = bus->resource[1]->start;
bus_size = bus->resource[1]->end + 1 - bus_align;
if (bus_align < 0x1000000UL)
bus_align = 0x1000000UL;
pci_mem = (0x100000000UL - bus_size) & -bus_align;
bus->resource[1]->start = pci_mem;
bus->resource[1]->end = 0xffffffffUL;
if (request_resource(&iomem_resource, bus->resource[1]) < 0)
printk(KERN_ERR "Failed to request MEM on hose 0\n");
if (pci_mem < memtop)
memtop = pci_mem;
if (memtop > alpha_mv.min_mem_address) {
free_reserved_mem(__va(alpha_mv.min_mem_address),
__va(memtop));
printk("nautilus_init_pci: %ldk freed\n",
(memtop - alpha_mv.min_mem_address) >> 10);
}
if ((IRONGATE0->dev_vendor >> 16) > 0x7006)
IRONGATE0->pci_mem = pci_mem;
pci_bus_assign_resources(bus);
bus->self = NULL;
pci_fixup_irqs(alpha_mv.pci_swizzle, alpha_mv.pci_map_irq);
}
