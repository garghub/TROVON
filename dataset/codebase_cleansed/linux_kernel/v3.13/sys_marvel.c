static void
io7_device_interrupt(unsigned long vector)
{
unsigned int pid;
unsigned int irq;
pid = vector >> 16;
irq = ((vector & 0xffff) - 0x800) >> 4;
irq += 16;
irq &= MARVEL_IRQ_VEC_IRQ_MASK;
irq |= pid << MARVEL_IRQ_VEC_PE_SHIFT;
handle_irq(irq);
}
static volatile unsigned long *
io7_get_irq_ctl(unsigned int irq, struct io7 **pio7)
{
volatile unsigned long *ctl;
unsigned int pid;
struct io7 *io7;
pid = irq >> MARVEL_IRQ_VEC_PE_SHIFT;
if (!(io7 = marvel_find_io7(pid))) {
printk(KERN_ERR
"%s for nonexistent io7 -- vec %x, pid %d\n",
__func__, irq, pid);
return NULL;
}
irq &= MARVEL_IRQ_VEC_IRQ_MASK;
irq -= 16;
if (irq >= 0x180) {
printk(KERN_ERR
"%s for invalid irq -- pid %d adjusted irq %x\n",
__func__, pid, irq);
return NULL;
}
ctl = &io7->csrs->PO7_LSI_CTL[irq & 0xff].csr;
if (irq >= 0x80)
ctl = &io7->csrs->PO7_MSI_CTL[((irq - 0x80) >> 5) & 0x0f].csr;
if (pio7) *pio7 = io7;
return ctl;
}
static void
io7_enable_irq(struct irq_data *d)
{
volatile unsigned long *ctl;
unsigned int irq = d->irq;
struct io7 *io7;
ctl = io7_get_irq_ctl(irq, &io7);
if (!ctl || !io7) {
printk(KERN_ERR "%s: get_ctl failed for irq %x\n",
__func__, irq);
return;
}
spin_lock(&io7->irq_lock);
*ctl |= 1UL << 24;
mb();
*ctl;
spin_unlock(&io7->irq_lock);
}
static void
io7_disable_irq(struct irq_data *d)
{
volatile unsigned long *ctl;
unsigned int irq = d->irq;
struct io7 *io7;
ctl = io7_get_irq_ctl(irq, &io7);
if (!ctl || !io7) {
printk(KERN_ERR "%s: get_ctl failed for irq %x\n",
__func__, irq);
return;
}
spin_lock(&io7->irq_lock);
*ctl &= ~(1UL << 24);
mb();
*ctl;
spin_unlock(&io7->irq_lock);
}
static void
marvel_irq_noop(struct irq_data *d)
{
return;
}
static void
io7_redirect_irq(struct io7 *io7,
volatile unsigned long *csr,
unsigned int where)
{
unsigned long val;
val = *csr;
val &= ~(0x1ffUL << 24);
val |= ((unsigned long)where << 24);
*csr = val;
mb();
*csr;
}
static void
io7_redirect_one_lsi(struct io7 *io7, unsigned int which, unsigned int where)
{
unsigned long val;
val = io7->csrs->PO7_LSI_CTL[which].csr;
val &= ~(0x1ffUL << 14);
val |= ((unsigned long)where << 14);
io7->csrs->PO7_LSI_CTL[which].csr = val;
mb();
io7->csrs->PO7_LSI_CTL[which].csr;
}
static void
io7_redirect_one_msi(struct io7 *io7, unsigned int which, unsigned int where)
{
unsigned long val;
val = io7->csrs->PO7_MSI_CTL[which].csr;
val &= ~(0x1ffUL << 14);
val |= ((unsigned long)where << 14);
io7->csrs->PO7_MSI_CTL[which].csr = val;
mb();
io7->csrs->PO7_MSI_CTL[which].csr;
}
static void __init
init_one_io7_lsi(struct io7 *io7, unsigned int which, unsigned int where)
{
io7->csrs->PO7_LSI_CTL[which].csr = ((unsigned long)where << 14);
mb();
io7->csrs->PO7_LSI_CTL[which].csr;
}
static void __init
init_one_io7_msi(struct io7 *io7, unsigned int which, unsigned int where)
{
io7->csrs->PO7_MSI_CTL[which].csr = ((unsigned long)where << 14);
mb();
io7->csrs->PO7_MSI_CTL[which].csr;
}
static void __init
init_io7_irqs(struct io7 *io7,
struct irq_chip *lsi_ops,
struct irq_chip *msi_ops)
{
long base = (io7->pe << MARVEL_IRQ_VEC_PE_SHIFT) + 16;
long i;
printk("Initializing interrupts for IO7 at PE %u - base %lx\n",
io7->pe, base);
printk(" Interrupts reported to CPU at PE %u\n", boot_cpuid);
spin_lock(&io7->irq_lock);
io7_redirect_irq(io7, &io7->csrs->HLT_CTL.csr, boot_cpuid);
io7_redirect_irq(io7, &io7->csrs->HPI_CTL.csr, boot_cpuid);
io7_redirect_irq(io7, &io7->csrs->CRD_CTL.csr, boot_cpuid);
io7_redirect_irq(io7, &io7->csrs->STV_CTL.csr, boot_cpuid);
io7_redirect_irq(io7, &io7->csrs->HEI_CTL.csr, boot_cpuid);
for (i = 0; i < 128; ++i) {
irq_set_chip_and_handler(base + i, lsi_ops, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
for (i = 0; i < 0x60; ++i)
init_one_io7_lsi(io7, i, boot_cpuid);
init_one_io7_lsi(io7, 0x74, boot_cpuid);
init_one_io7_lsi(io7, 0x75, boot_cpuid);
for (i = 128; i < (128 + 512); ++i) {
irq_set_chip_and_handler(base + i, msi_ops, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
for (i = 0; i < 16; ++i)
init_one_io7_msi(io7, i, boot_cpuid);
spin_unlock(&io7->irq_lock);
}
static void __init
marvel_init_irq(void)
{
int i;
struct io7 *io7 = NULL;
for (i = 0; i < 16; ++i) {
irq_set_chip_and_handler(i, &marvel_legacy_irq_type,
handle_level_irq);
}
for (io7 = NULL; (io7 = marvel_next_io7(io7)) != NULL; )
init_io7_irqs(io7, &io7_lsi_irq_type, &io7_msi_irq_type);
}
static int
marvel_map_irq(const struct pci_dev *cdev, u8 slot, u8 pin)
{
struct pci_dev *dev = (struct pci_dev *)cdev;
struct pci_controller *hose = dev->sysdata;
struct io7_port *io7_port = hose->sysdata;
struct io7 *io7 = io7_port->io7;
int msi_loc, msi_data_off;
u16 msg_ctl;
u16 msg_dat;
u8 intline;
int irq;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &intline);
irq = intline;
msi_loc = pci_find_capability(dev, PCI_CAP_ID_MSI);
msg_ctl = 0;
if (msi_loc)
pci_read_config_word(dev, msi_loc + PCI_MSI_FLAGS, &msg_ctl);
if (msg_ctl & PCI_MSI_FLAGS_ENABLE) {
msi_data_off = PCI_MSI_DATA_32;
if (msg_ctl & PCI_MSI_FLAGS_64BIT)
msi_data_off = PCI_MSI_DATA_64;
pci_read_config_word(dev, msi_loc + msi_data_off, &msg_dat);
irq = msg_dat & 0x1ff;
irq += 0x80;
#if 1
printk("PCI:%d:%d:%d (hose %d) is using MSI\n",
dev->bus->number,
PCI_SLOT(dev->devfn),
PCI_FUNC(dev->devfn),
hose->index);
printk(" %d message(s) from 0x%04x\n",
1 << ((msg_ctl & PCI_MSI_FLAGS_QSIZE) >> 4),
msg_dat);
printk(" reporting on %d IRQ(s) from %d (0x%x)\n",
1 << ((msg_ctl & PCI_MSI_FLAGS_QSIZE) >> 4),
(irq + 16) | (io7->pe << MARVEL_IRQ_VEC_PE_SHIFT),
(irq + 16) | (io7->pe << MARVEL_IRQ_VEC_PE_SHIFT));
#endif
#if 0
pci_write_config_word(dev, msi_loc + PCI_MSI_FLAGS,
msg_ctl & ~PCI_MSI_FLAGS_ENABLE);
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &intline);
irq = intline;
printk(" forcing LSI interrupt on irq %d [0x%x]\n", irq, irq);
#endif
}
irq += 16;
irq |= io7->pe << MARVEL_IRQ_VEC_PE_SHIFT;
return irq;
}
static void __init
marvel_init_pci(void)
{
struct io7 *io7;
marvel_register_error_handlers();
pci_set_flags(PCI_PROBE_ONLY);
common_init_pci();
locate_and_init_vga(NULL);
for (io7 = NULL; (io7 = marvel_next_io7(io7)) != NULL; )
io7_clear_errors(io7);
}
static void __init
marvel_init_rtc(void)
{
init_rtc_irq();
}
static void
marvel_smp_callin(void)
{
int cpuid = hard_smp_processor_id();
struct io7 *io7 = marvel_find_io7(cpuid);
unsigned int i;
if (!io7)
return;
printk("Redirecting IO7 interrupts to local CPU at PE %u\n", cpuid);
io7_redirect_irq(io7, &io7->csrs->HLT_CTL.csr, cpuid);
io7_redirect_irq(io7, &io7->csrs->HPI_CTL.csr, cpuid);
io7_redirect_irq(io7, &io7->csrs->CRD_CTL.csr, cpuid);
io7_redirect_irq(io7, &io7->csrs->STV_CTL.csr, cpuid);
io7_redirect_irq(io7, &io7->csrs->HEI_CTL.csr, cpuid);
for (i = 0; i < 0x60; ++i)
io7_redirect_one_lsi(io7, i, cpuid);
io7_redirect_one_lsi(io7, 0x74, cpuid);
io7_redirect_one_lsi(io7, 0x75, cpuid);
for (i = 0; i < 16; ++i)
io7_redirect_one_msi(io7, i, cpuid);
}
