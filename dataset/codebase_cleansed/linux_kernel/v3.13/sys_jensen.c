static void
jensen_local_enable(struct irq_data *d)
{
if (d->irq == 7)
i8259a_enable_irq(d);
}
static void
jensen_local_disable(struct irq_data *d)
{
if (d->irq == 7)
i8259a_disable_irq(d);
}
static void
jensen_local_mask_ack(struct irq_data *d)
{
if (d->irq == 7)
i8259a_mask_and_ack_irq(d);
}
static void
jensen_device_interrupt(unsigned long vector)
{
int irq;
switch (vector) {
case 0x660:
printk("Whee.. NMI received. Probable hardware error\n");
printk("61=%02x, 461=%02x\n", inb(0x61), inb(0x461));
return;
case 0x900: irq = 4; break;
case 0x920: irq = 3; break;
case 0x980: irq = 1; break;
case 0x990: irq = 9; break;
default:
if (vector > 0x900) {
printk("Unknown local interrupt %lx\n", vector);
return;
}
irq = (vector - 0x800) >> 4;
if (irq == 1)
irq = 7;
break;
}
if (!irq_has_action(irq)) {
if (vector >= 0x900)
{
inb(0x64);
inb(0x60);
inb(0x3fa);
inb(0x2fa);
outb(0x0c, 0x3fc);
outb(0x0c, 0x2fc);
outb(0,0x61);
outb(0,0x461);
}
}
#if 0
{
static unsigned int last_msg = 0, last_cc = 0;
static int last_irq = -1, count = 0;
unsigned int cc;
__asm __volatile("rpcc %0" : "=r"(cc));
++count;
#define JENSEN_CYCLES_PER_SEC (150000000)
if (cc - last_msg > ((JENSEN_CYCLES_PER_SEC) * 3) ||
irq != last_irq) {
printk(KERN_CRIT " irq %d count %d cc %u @ %lx\n",
irq, count, cc-last_cc, get_irq_regs()->pc);
count = 0;
last_msg = cc;
last_irq = irq;
}
last_cc = cc;
}
#endif
handle_irq(irq);
}
static void __init
jensen_init_irq(void)
{
init_i8259a_irqs();
irq_set_chip_and_handler(1, &jensen_local_irq_type, handle_level_irq);
irq_set_chip_and_handler(4, &jensen_local_irq_type, handle_level_irq);
irq_set_chip_and_handler(3, &jensen_local_irq_type, handle_level_irq);
irq_set_chip_and_handler(7, &jensen_local_irq_type, handle_level_irq);
irq_set_chip_and_handler(9, &jensen_local_irq_type, handle_level_irq);
common_init_isa_dma();
}
static void __init
jensen_init_arch(void)
{
struct pci_controller *hose;
#ifdef CONFIG_PCI
static struct pci_dev fake_isa_bridge = { .dma_mask = 0xffffffffUL, };
isa_bridge = &fake_isa_bridge;
#endif
pci_isa_hose = hose = alloc_pci_controller();
hose->io_space = &ioport_resource;
hose->mem_space = &iomem_resource;
hose->index = 0;
hose->sparse_mem_base = EISA_MEM - IDENT_ADDR;
hose->dense_mem_base = 0;
hose->sparse_io_base = EISA_IO - IDENT_ADDR;
hose->dense_io_base = 0;
hose->sg_isa = hose->sg_pci = NULL;
__direct_map_base = 0;
__direct_map_size = 0xffffffff;
}
static void
jensen_machine_check(unsigned long vector, unsigned long la)
{
printk(KERN_CRIT "Machine check\n");
}
