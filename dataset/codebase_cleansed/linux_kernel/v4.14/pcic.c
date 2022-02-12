static int pcic_read_config_dword(unsigned int busno, unsigned int devfn,
int where, u32 *value)
{
struct linux_pcic *pcic;
unsigned long flags;
pcic = &pcic0;
local_irq_save(flags);
#if 0
pcic_speculative = 1;
pcic_trapped = 0;
#endif
writel(CONFIG_CMD(busno, devfn, where), pcic->pcic_config_space_addr);
#if 0
nop();
if (pcic_trapped) {
local_irq_restore(flags);
*value = ~0;
return 0;
}
#endif
pcic_speculative = 2;
pcic_trapped = 0;
*value = readl(pcic->pcic_config_space_data + (where&4));
nop();
if (pcic_trapped) {
pcic_speculative = 0;
local_irq_restore(flags);
*value = ~0;
return 0;
}
pcic_speculative = 0;
local_irq_restore(flags);
return 0;
}
static int pcic_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
unsigned int v;
if (bus->number != 0) return -EINVAL;
switch (size) {
case 1:
pcic_read_config_dword(bus->number, devfn, where&~3, &v);
*val = 0xff & (v >> (8*(where & 3)));
return 0;
case 2:
if (where&1) return -EINVAL;
pcic_read_config_dword(bus->number, devfn, where&~3, &v);
*val = 0xffff & (v >> (8*(where & 3)));
return 0;
case 4:
if (where&3) return -EINVAL;
pcic_read_config_dword(bus->number, devfn, where&~3, val);
return 0;
}
return -EINVAL;
}
static int pcic_write_config_dword(unsigned int busno, unsigned int devfn,
int where, u32 value)
{
struct linux_pcic *pcic;
unsigned long flags;
pcic = &pcic0;
local_irq_save(flags);
writel(CONFIG_CMD(busno, devfn, where), pcic->pcic_config_space_addr);
writel(value, pcic->pcic_config_space_data + (where&4));
local_irq_restore(flags);
return 0;
}
static int pcic_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
unsigned int v;
if (bus->number != 0) return -EINVAL;
switch (size) {
case 1:
pcic_read_config_dword(bus->number, devfn, where&~3, &v);
v = (v & ~(0xff << (8*(where&3)))) |
((0xff&val) << (8*(where&3)));
return pcic_write_config_dword(bus->number, devfn, where&~3, v);
case 2:
if (where&1) return -EINVAL;
pcic_read_config_dword(bus->number, devfn, where&~3, &v);
v = (v & ~(0xffff << (8*(where&3)))) |
((0xffff&val) << (8*(where&3)));
return pcic_write_config_dword(bus->number, devfn, where&~3, v);
case 4:
if (where&3) return -EINVAL;
return pcic_write_config_dword(bus->number, devfn, where, val);
}
return -EINVAL;
}
int __init pcic_probe(void)
{
struct linux_pcic *pcic;
struct linux_prom_registers regs[PROMREG_MAX];
struct linux_pbm_info* pbm;
char namebuf[64];
phandle node;
int err;
if (pcic0_up) {
prom_printf("PCIC: called twice!\n");
prom_halt();
}
pcic = &pcic0;
node = prom_getchild (prom_root_node);
node = prom_searchsiblings (node, "pci");
if (node == 0)
return -ENODEV;
err = prom_getproperty(node, "reg", (char*)regs, sizeof(regs));
if (err == 0 || err == -1) {
prom_printf("PCIC: Error, cannot get PCIC registers "
"from PROM.\n");
prom_halt();
}
pcic0_up = 1;
pcic->pcic_res_regs.name = "pcic_registers";
pcic->pcic_regs = ioremap(regs[0].phys_addr, regs[0].reg_size);
if (!pcic->pcic_regs) {
prom_printf("PCIC: Error, cannot map PCIC registers.\n");
prom_halt();
}
pcic->pcic_res_io.name = "pcic_io";
if ((pcic->pcic_io = (unsigned long)
ioremap(regs[1].phys_addr, 0x10000)) == 0) {
prom_printf("PCIC: Error, cannot map PCIC IO Base.\n");
prom_halt();
}
pcic->pcic_res_cfg_addr.name = "pcic_cfg_addr";
if ((pcic->pcic_config_space_addr =
ioremap(regs[2].phys_addr, regs[2].reg_size * 2)) == NULL) {
prom_printf("PCIC: Error, cannot map "
"PCI Configuration Space Address.\n");
prom_halt();
}
pcic->pcic_res_cfg_data.name = "pcic_cfg_data";
if ((pcic->pcic_config_space_data =
ioremap(regs[3].phys_addr, regs[3].reg_size * 2)) == NULL) {
prom_printf("PCIC: Error, cannot map "
"PCI Configuration Space Data.\n");
prom_halt();
}
pbm = &pcic->pbm;
pbm->prom_node = node;
prom_getstring(node, "name", namebuf, 63); namebuf[63] = 0;
strcpy(pbm->prom_name, namebuf);
{
extern int pcic_nmi_trap_patch[4];
t_nmi[0] = pcic_nmi_trap_patch[0];
t_nmi[1] = pcic_nmi_trap_patch[1];
t_nmi[2] = pcic_nmi_trap_patch[2];
t_nmi[3] = pcic_nmi_trap_patch[3];
swift_flush_dcache();
pcic_regs = pcic->pcic_regs;
}
prom_getstring(prom_root_node, "name", namebuf, 63); namebuf[63] = 0;
{
struct pcic_sn2list *p;
for (p = pcic_known_sysnames; p->sysname != NULL; p++) {
if (strcmp(namebuf, p->sysname) == 0)
break;
}
pcic->pcic_imap = p->intmap;
pcic->pcic_imdim = p->mapdim;
}
if (pcic->pcic_imap == NULL) {
printk("PCIC: System %s is unknown, cannot route interrupts\n",
namebuf);
}
return 0;
}
static void __init pcic_pbm_scan_bus(struct linux_pcic *pcic)
{
struct linux_pbm_info *pbm = &pcic->pbm;
pbm->pci_bus = pci_scan_bus(pbm->pci_first_busno, &pcic_ops, pbm);
if (!pbm->pci_bus)
return;
#if 0
pci_fill_in_pbm_cookies(pbm->pci_bus, pbm, pbm->prom_node);
pci_record_assignments(pbm, pbm->pci_bus);
pci_assign_unassigned(pbm, pbm->pci_bus);
pci_fixup_irq(pbm, pbm->pci_bus);
#endif
pci_bus_add_devices(pbm->pci_bus);
}
static int __init pcic_init(void)
{
struct linux_pcic *pcic;
if(!pcic0_up)
return 0;
pcic = &pcic0;
writeb(PCI_DVMA_CONTROL_IOTLB_DISABLE,
pcic->pcic_regs+PCI_DVMA_CONTROL);
writel(0xF0000000UL, pcic->pcic_regs+PCI_SIZE_0);
writel(0+PCI_BASE_ADDRESS_SPACE_MEMORY,
pcic->pcic_regs+PCI_BASE_ADDRESS_0);
pcic_pbm_scan_bus(pcic);
return 0;
}
int pcic_present(void)
{
return pcic0_up;
}
static int pdev_to_pnode(struct linux_pbm_info *pbm, struct pci_dev *pdev)
{
struct linux_prom_pci_registers regs[PROMREG_MAX];
int err;
phandle node = prom_getchild(pbm->prom_node);
while(node) {
err = prom_getproperty(node, "reg",
(char *)&regs[0], sizeof(regs));
if(err != 0 && err != -1) {
unsigned long devfn = (regs[0].which_io >> 8) & 0xff;
if(devfn == pdev->devfn)
return node;
}
node = prom_getsibling(node);
}
return 0;
}
static inline struct pcidev_cookie *pci_devcookie_alloc(void)
{
return kmalloc(sizeof(struct pcidev_cookie), GFP_ATOMIC);
}
static void pcic_map_pci_device(struct linux_pcic *pcic,
struct pci_dev *dev, int node)
{
char namebuf[64];
unsigned long address;
unsigned long flags;
int j;
if (node == 0 || node == -1) {
strcpy(namebuf, "???");
} else {
prom_getstring(node, "name", namebuf, 63); namebuf[63] = 0;
}
for (j = 0; j < 6; j++) {
address = dev->resource[j].start;
if (address == 0) break;
flags = dev->resource[j].flags;
if ((flags & IORESOURCE_IO) != 0) {
if (address < 0x10000) {
dev->resource[j].start =
pcic->pcic_io + address;
dev->resource[j].end = 1;
dev->resource[j].flags =
(flags & ~IORESOURCE_IO) | IORESOURCE_MEM;
} else {
printk("PCIC: Skipping I/O space at 0x%lx, "
"this will Oops if a driver attaches "
"device '%s' at %02x:%02x)\n", address,
namebuf, dev->bus->number, dev->devfn);
}
}
}
}
static void
pcic_fill_irq(struct linux_pcic *pcic, struct pci_dev *dev, int node)
{
struct pcic_ca2irq *p;
unsigned int real_irq;
int i, ivec;
char namebuf[64];
if (node == 0 || node == -1) {
strcpy(namebuf, "???");
} else {
prom_getstring(node, "name", namebuf, sizeof(namebuf));
}
if ((p = pcic->pcic_imap) == NULL) {
dev->irq = 0;
return;
}
for (i = 0; i < pcic->pcic_imdim; i++) {
if (p->busno == dev->bus->number && p->devfn == dev->devfn)
break;
p++;
}
if (i >= pcic->pcic_imdim) {
printk("PCIC: device %s devfn %02x:%02x not found in %d\n",
namebuf, dev->bus->number, dev->devfn, pcic->pcic_imdim);
dev->irq = 0;
return;
}
i = p->pin;
if (i >= 0 && i < 4) {
ivec = readw(pcic->pcic_regs+PCI_INT_SELECT_LO);
real_irq = ivec >> (i << 2) & 0xF;
} else if (i >= 4 && i < 8) {
ivec = readw(pcic->pcic_regs+PCI_INT_SELECT_HI);
real_irq = ivec >> ((i-4) << 2) & 0xF;
} else {
printk("PCIC: BAD PIN %d\n", i); for (;;) {}
}
if (real_irq == 0 || p->force) {
if (p->irq == 0 || p->irq >= 15) {
printk("PCIC: BAD IRQ %d\n", p->irq); for (;;) {}
}
printk("PCIC: setting irq %d at pin %d for device %02x:%02x\n",
p->irq, p->pin, dev->bus->number, dev->devfn);
real_irq = p->irq;
i = p->pin;
if (i >= 4) {
ivec = readw(pcic->pcic_regs+PCI_INT_SELECT_HI);
ivec &= ~(0xF << ((i - 4) << 2));
ivec |= p->irq << ((i - 4) << 2);
writew(ivec, pcic->pcic_regs+PCI_INT_SELECT_HI);
} else {
ivec = readw(pcic->pcic_regs+PCI_INT_SELECT_LO);
ivec &= ~(0xF << (i << 2));
ivec |= p->irq << (i << 2);
writew(ivec, pcic->pcic_regs+PCI_INT_SELECT_LO);
}
}
dev->irq = pcic_build_device_irq(NULL, real_irq);
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
struct pci_dev *dev;
int i, has_io, has_mem;
unsigned int cmd = 0;
struct linux_pcic *pcic;
int node;
struct pcidev_cookie *pcp;
if (!pcic0_up) {
printk("pcibios_fixup_bus: no PCIC\n");
return;
}
pcic = &pcic0;
if (bus->number != 0) {
printk("pcibios_fixup_bus: nonzero bus 0x%x\n", bus->number);
return;
}
list_for_each_entry(dev, &bus->devices, bus_list) {
has_io = has_mem = 0;
for(i=0; i<6; i++) {
unsigned long f = dev->resource[i].flags;
if (f & IORESOURCE_IO) {
has_io = 1;
} else if (f & IORESOURCE_MEM)
has_mem = 1;
}
pcic_read_config(dev->bus, dev->devfn, PCI_COMMAND, 2, &cmd);
if (has_io && !(cmd & PCI_COMMAND_IO)) {
printk("PCIC: Enabling I/O for device %02x:%02x\n",
dev->bus->number, dev->devfn);
cmd |= PCI_COMMAND_IO;
pcic_write_config(dev->bus, dev->devfn,
PCI_COMMAND, 2, cmd);
}
if (has_mem && !(cmd & PCI_COMMAND_MEMORY)) {
printk("PCIC: Enabling memory for device %02x:%02x\n",
dev->bus->number, dev->devfn);
cmd |= PCI_COMMAND_MEMORY;
pcic_write_config(dev->bus, dev->devfn,
PCI_COMMAND, 2, cmd);
}
node = pdev_to_pnode(&pcic->pbm, dev);
if(node == 0)
node = -1;
pcp = pci_devcookie_alloc();
pcp->pbm = &pcic->pbm;
pcp->prom_node = of_find_node_by_phandle(node);
dev->sysdata = pcp;
if ((dev->class>>16) != PCI_BASE_CLASS_BRIDGE)
pcic_map_pci_device(pcic, dev, node);
pcic_fill_irq(pcic, dev, node);
}
}
static void pcic_clear_clock_irq(void)
{
pcic_timer_dummy = readl(pcic0.pcic_regs+PCI_SYS_LIMIT);
}
static unsigned int pcic_cycles_offset(void)
{
u32 value, count;
value = readl(pcic0.pcic_regs + PCI_SYS_COUNTER);
count = value & ~PCI_SYS_COUNTER_OVERFLOW;
if (value & PCI_SYS_COUNTER_OVERFLOW)
count += TICK_TIMER_LIMIT;
count = ((count / HZ) * USECS_PER_JIFFY) / (TICK_TIMER_LIMIT / HZ);
return count * 2;
}
void __init pci_time_init(void)
{
struct linux_pcic *pcic = &pcic0;
unsigned long v;
int timer_irq, irq;
int err;
#ifndef CONFIG_SMP
sparc_config.clock_rate = SBUS_CLOCK_RATE / HZ;
sparc_config.features |= FEAT_L10_CLOCKEVENT;
#endif
sparc_config.features |= FEAT_L10_CLOCKSOURCE;
sparc_config.get_cycles_offset = pcic_cycles_offset;
writel (TICK_TIMER_LIMIT, pcic->pcic_regs+PCI_SYS_LIMIT);
v = readb(pcic->pcic_regs+PCI_COUNTER_IRQ);
timer_irq = PCI_COUNTER_IRQ_SYS(v);
writel (PCI_COUNTER_IRQ_SET(timer_irq, 0),
pcic->pcic_regs+PCI_COUNTER_IRQ);
irq = pcic_build_device_irq(NULL, timer_irq);
err = request_irq(irq, timer_interrupt,
IRQF_TIMER, "timer", NULL);
if (err) {
prom_printf("time_init: unable to attach IRQ%d\n", timer_irq);
prom_halt();
}
local_irq_enable();
}
int pcibios_enable_device(struct pci_dev *pdev, int mask)
{
return 0;
}
void pcic_nmi(unsigned int pend, struct pt_regs *regs)
{
pend = swab32(pend);
if (!pcic_speculative || (pend & PCI_SYS_INT_PENDING_PIO) == 0) {
printk("Aiee, NMI pend 0x%x pc 0x%x spec %d, hanging\n",
pend, (int)regs->pc, pcic_speculative);
for (;;) { }
}
pcic_speculative = 0;
pcic_trapped = 1;
regs->pc = regs->npc;
regs->npc += 4;
}
static inline unsigned long get_irqmask(int irq_nr)
{
return 1 << irq_nr;
}
static void pcic_mask_irq(struct irq_data *data)
{
unsigned long mask, flags;
mask = (unsigned long)data->chip_data;
local_irq_save(flags);
writel(mask, pcic0.pcic_regs+PCI_SYS_INT_TARGET_MASK_SET);
local_irq_restore(flags);
}
static void pcic_unmask_irq(struct irq_data *data)
{
unsigned long mask, flags;
mask = (unsigned long)data->chip_data;
local_irq_save(flags);
writel(mask, pcic0.pcic_regs+PCI_SYS_INT_TARGET_MASK_CLEAR);
local_irq_restore(flags);
}
static unsigned int pcic_startup_irq(struct irq_data *data)
{
irq_link(data->irq);
pcic_unmask_irq(data);
return 0;
}
unsigned int pcic_build_device_irq(struct platform_device *op,
unsigned int real_irq)
{
unsigned int irq;
unsigned long mask;
irq = 0;
mask = get_irqmask(real_irq);
if (mask == 0)
goto out;
irq = irq_alloc(real_irq, real_irq);
if (irq == 0)
goto out;
irq_set_chip_and_handler_name(irq, &pcic_irq,
handle_level_irq, "PCIC");
irq_set_chip_data(irq, (void *)mask);
out:
return irq;
}
static void pcic_load_profile_irq(int cpu, unsigned int limit)
{
printk("PCIC: unimplemented code: FILE=%s LINE=%d", __FILE__, __LINE__);
}
void __init sun4m_pci_init_IRQ(void)
{
sparc_config.build_device_irq = pcic_build_device_irq;
sparc_config.clear_clock_irq = pcic_clear_clock_irq;
sparc_config.load_profile_irq = pcic_load_profile_irq;
}
