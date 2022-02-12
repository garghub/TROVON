static inline void
eiger_update_irq_hw(unsigned long irq, unsigned long mask)
{
int regaddr;
mask = (irq >= 64 ? mask << 16 : mask >> ((irq - 16) & 0x30));
regaddr = 0x510 + (((irq - 16) >> 2) & 0x0c);
outl(mask & 0xffff0000UL, regaddr);
}
static inline void
eiger_enable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
unsigned long mask;
mask = (cached_irq_mask[irq >= 64] &= ~(1UL << (irq & 63)));
eiger_update_irq_hw(irq, mask);
}
static void
eiger_disable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
unsigned long mask;
mask = (cached_irq_mask[irq >= 64] |= 1UL << (irq & 63));
eiger_update_irq_hw(irq, mask);
}
static void
eiger_device_interrupt(unsigned long vector)
{
unsigned intstatus;
intstatus = inw(0x500) & 15;
if (intstatus) {
if (intstatus & 8) handle_irq(16+3);
if (intstatus & 4) handle_irq(16+2);
if (intstatus & 2) handle_irq(16+1);
if (intstatus & 1) handle_irq(16+0);
} else {
isa_device_interrupt(vector);
}
}
static void
eiger_srm_device_interrupt(unsigned long vector)
{
int irq = (vector - 0x800) >> 4;
handle_irq(irq);
}
static void __init
eiger_init_irq(void)
{
long i;
outb(0, DMA1_RESET_REG);
outb(0, DMA2_RESET_REG);
outb(DMA_MODE_CASCADE, DMA2_MODE_REG);
outb(0, DMA2_MASK_REG);
if (alpha_using_srm)
alpha_mv.device_interrupt = eiger_srm_device_interrupt;
for (i = 16; i < 128; i += 16)
eiger_update_irq_hw(i, -1);
init_i8259a_irqs();
for (i = 16; i < 128; ++i) {
irq_set_chip_and_handler(i, &eiger_irq_type, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
}
static int
eiger_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
u8 irq_orig;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &irq_orig);
return irq_orig - 0x80;
}
static u8
eiger_swizzle(struct pci_dev *dev, u8 *pinp)
{
struct pci_controller *hose = dev->sysdata;
int slot, pin = *pinp;
int bridge_count = 0;
int backplane = inw(0x502) & 0x0f;
switch (backplane)
{
case 0x00: bridge_count = 0; break;
case 0x01: bridge_count = 1; break;
case 0x03: bridge_count = 2; break;
case 0x07: bridge_count = 3; break;
case 0x0f: bridge_count = 4; break;
};
slot = PCI_SLOT(dev->devfn);
while (dev->bus->self) {
if (hose->index == 0
&& (PCI_SLOT(dev->bus->self->devfn)
> 20 - bridge_count)) {
slot = PCI_SLOT(dev->devfn);
break;
}
pin = pci_swizzle_interrupt_pin(dev, pin);
dev = dev->bus->self;
}
*pinp = pin;
return slot;
}
