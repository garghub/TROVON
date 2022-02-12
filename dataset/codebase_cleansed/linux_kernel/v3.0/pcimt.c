static void __init sni_pcimt_sc_init(void)
{
unsigned int scsiz, sc_size;
scsiz = cacheconf & 7;
if (scsiz == 0) {
printk("Second level cache is deactived.\n");
return;
}
if (scsiz >= 6) {
printk("Invalid second level cache size configured, "
"deactivating second level cache.\n");
cacheconf = 0;
return;
}
sc_size = 128 << scsiz;
printk("%dkb second level cache detected, deactivating.\n", sc_size);
cacheconf = 0;
}
static inline void sni_pcimt_detect(void)
{
char boardtype[80];
unsigned char csmsr;
char *p = boardtype;
unsigned int asic;
csmsr = *(volatile unsigned char *)PCIMT_CSMSR;
p += sprintf(p, "%s PCI", (csmsr & 0x80) ? "RM200" : "RM300");
if ((csmsr & 0x80) == 0)
p += sprintf(p, ", board revision %s",
(csmsr & 0x20) ? "D" : "C");
asic = csmsr & 0x80;
asic = (csmsr & 0x08) ? asic : !asic;
p += sprintf(p, ", ASIC PCI Rev %s", asic ? "1.0" : "1.1");
printk("%s.\n", boardtype);
}
static void __init sni_pcimt_resource_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(pcimt_io_resources); i++)
request_resource(&sni_io_resource, pcimt_io_resources + i);
for (i = 0; i < ARRAY_SIZE(pcimt_mem_resources); i++)
request_resource(&sni_mem_resource, pcimt_mem_resources + i);
}
static void enable_pcimt_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq - PCIMT_IRQ_INT2);
*(volatile u8 *) PCIMT_IRQSEL |= mask;
}
void disable_pcimt_irq(struct irq_data *d)
{
unsigned int mask = ~(1 << (d->irq - PCIMT_IRQ_INT2));
*(volatile u8 *) PCIMT_IRQSEL &= mask;
}
static void pcimt_hwint0(void)
{
panic("Received int0 but no handler yet ...");
}
static void pcimt_hwint1(void)
{
u8 pend = *(volatile char *)PCIMT_CSITPEND;
unsigned long flags;
if (pend & IT_EISA) {
int irq;
irq = i8259_irq();
if (unlikely(irq < 0))
return;
do_IRQ(irq);
}
if (!(pend & IT_SCSI)) {
flags = read_c0_status();
clear_c0_status(ST0_IM);
do_IRQ(PCIMT_IRQ_SCSI);
write_c0_status(flags);
}
}
static void pcimt_hwint3(void)
{
u8 pend = *(volatile char *)PCIMT_CSITPEND;
int irq;
pend &= (IT_INTA | IT_INTB | IT_INTC | IT_INTD);
pend ^= (IT_INTA | IT_INTB | IT_INTC | IT_INTD);
clear_c0_status(IE_IRQ3);
irq = PCIMT_IRQ_INT2 + ffs(pend) - 1;
do_IRQ(irq);
set_c0_status(IE_IRQ3);
}
static void sni_pcimt_hwint(void)
{
u32 pending = read_c0_cause() & read_c0_status();
if (pending & C_IRQ5)
do_IRQ(MIPS_CPU_IRQ_BASE + 7);
else if (pending & C_IRQ4)
do_IRQ(MIPS_CPU_IRQ_BASE + 6);
else if (pending & C_IRQ3)
pcimt_hwint3();
else if (pending & C_IRQ1)
pcimt_hwint1();
else if (pending & C_IRQ0) {
pcimt_hwint0();
}
}
void __init sni_pcimt_irq_init(void)
{
int i;
*(volatile u8 *) PCIMT_IRQSEL = IT_ETH | IT_EISA;
mips_cpu_irq_init();
for (i = PCIMT_IRQ_INT2; i <= PCIMT_IRQ_SCSI; i++)
irq_set_chip_and_handler(i, &pcimt_irq_type, handle_level_irq);
sni_hwint = sni_pcimt_hwint;
change_c0_status(ST0_IM, IE_IRQ1|IE_IRQ3);
}
void __init sni_pcimt_init(void)
{
sni_pcimt_detect();
sni_pcimt_sc_init();
ioport_resource.end = sni_io_resource.end;
#ifdef CONFIG_PCI
PCIBIOS_MIN_IO = 0x9000;
register_pci_controller(&sni_controller);
#endif
sni_pcimt_resource_init();
}
static int __init snirm_pcimt_setup_devinit(void)
{
switch (sni_brd_type) {
case SNI_BRD_PCI_MTOWER:
case SNI_BRD_PCI_DESKTOP:
case SNI_BRD_PCI_MTOWER_CPLUS:
platform_device_register(&pcimt_serial8250_device);
platform_device_register(&pcimt_cmos_device);
break;
}
return 0;
}
