static void __init sni_pcit_resource_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(pcit_io_resources); i++)
request_resource(&sni_io_resource, pcit_io_resources + i);
}
static void enable_pcit_irq(struct irq_data *d)
{
u32 mask = 1 << (d->irq - SNI_PCIT_INT_START + 24);
*(volatile u32 *)SNI_PCIT_INT_REG |= mask;
}
void disable_pcit_irq(struct irq_data *d)
{
u32 mask = 1 << (d->irq - SNI_PCIT_INT_START + 24);
*(volatile u32 *)SNI_PCIT_INT_REG &= ~mask;
}
static void pcit_hwint1(void)
{
u32 pending = *(volatile u32 *)SNI_PCIT_INT_REG;
int irq;
clear_c0_status(IE_IRQ1);
irq = ffs((pending >> 16) & 0x7f);
if (likely(irq > 0))
do_IRQ(irq + SNI_PCIT_INT_START - 1);
set_c0_status(IE_IRQ1);
}
static void pcit_hwint0(void)
{
u32 pending = *(volatile u32 *)SNI_PCIT_INT_REG;
int irq;
clear_c0_status(IE_IRQ0);
irq = ffs((pending >> 16) & 0x3f);
if (likely(irq > 0))
do_IRQ(irq + SNI_PCIT_INT_START - 1);
set_c0_status(IE_IRQ0);
}
static void sni_pcit_hwint(void)
{
u32 pending = read_c0_cause() & read_c0_status();
if (pending & C_IRQ1)
pcit_hwint1();
else if (pending & C_IRQ2)
do_IRQ(MIPS_CPU_IRQ_BASE + 4);
else if (pending & C_IRQ3)
do_IRQ(MIPS_CPU_IRQ_BASE + 5);
else if (pending & C_IRQ5)
do_IRQ(MIPS_CPU_IRQ_BASE + 7);
}
static void sni_pcit_hwint_cplus(void)
{
u32 pending = read_c0_cause() & read_c0_status();
if (pending & C_IRQ0)
pcit_hwint0();
else if (pending & C_IRQ1)
do_IRQ(MIPS_CPU_IRQ_BASE + 3);
else if (pending & C_IRQ2)
do_IRQ(MIPS_CPU_IRQ_BASE + 4);
else if (pending & C_IRQ3)
do_IRQ(MIPS_CPU_IRQ_BASE + 5);
else if (pending & C_IRQ5)
do_IRQ(MIPS_CPU_IRQ_BASE + 7);
}
void __init sni_pcit_irq_init(void)
{
int i;
mips_cpu_irq_init();
for (i = SNI_PCIT_INT_START; i <= SNI_PCIT_INT_END; i++)
irq_set_chip_and_handler(i, &pcit_irq_type, handle_level_irq);
*(volatile u32 *)SNI_PCIT_INT_REG = 0;
sni_hwint = sni_pcit_hwint;
change_c0_status(ST0_IM, IE_IRQ1);
setup_irq(SNI_PCIT_INT_START + 6, &sni_isa_irq);
}
void __init sni_pcit_cplus_irq_init(void)
{
int i;
mips_cpu_irq_init();
for (i = SNI_PCIT_INT_START; i <= SNI_PCIT_INT_END; i++)
irq_set_chip_and_handler(i, &pcit_irq_type, handle_level_irq);
*(volatile u32 *)SNI_PCIT_INT_REG = 0x40000000;
sni_hwint = sni_pcit_hwint_cplus;
change_c0_status(ST0_IM, IE_IRQ0);
setup_irq(MIPS_CPU_IRQ_BASE + 3, &sni_isa_irq);
}
void __init sni_pcit_init(void)
{
ioport_resource.end = sni_io_resource.end;
#ifdef CONFIG_PCI
PCIBIOS_MIN_IO = 0x9000;
register_pci_controller(&sni_pcit_controller);
#endif
sni_pcit_resource_init();
}
static int __init snirm_pcit_setup_devinit(void)
{
switch (sni_brd_type) {
case SNI_BRD_PCI_TOWER:
platform_device_register(&pcit_serial8250_device);
platform_device_register(&pcit_cmos_device);
platform_device_register(&pcit_pcspeaker_pdev);
break;
case SNI_BRD_PCI_TOWER_CPLUS:
platform_device_register(&pcit_cplus_serial8250_device);
platform_device_register(&pcit_cmos_device);
platform_device_register(&pcit_pcspeaker_pdev);
break;
}
return 0;
}
