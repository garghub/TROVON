static int ce4100_i8042_detect(void)
{
return 0;
}
static void ce4100_power_off(void)
{
outb(0x4, 0xcf9);
}
static unsigned int mem_serial_in(struct uart_port *p, int offset)
{
offset = offset << p->regshift;
return readl(p->membase + offset);
}
static unsigned int ce4100_mem_serial_in(struct uart_port *p, int offset)
{
unsigned int ret, ier, lsr;
if (offset == UART_IIR) {
offset = offset << p->regshift;
ret = readl(p->membase + offset);
if (ret & UART_IIR_NO_INT) {
ier = mem_serial_in(p, UART_IER);
if (ier & UART_IER_THRI) {
lsr = mem_serial_in(p, UART_LSR);
if (lsr & (UART_LSR_THRE | UART_LSR_TEMT))
ret &= ~UART_IIR_NO_INT;
}
}
} else
ret = mem_serial_in(p, offset);
return ret;
}
static void ce4100_mem_serial_out(struct uart_port *p, int offset, int value)
{
offset = offset << p->regshift;
writel(value, p->membase + offset);
}
static void ce4100_serial_fixup(int port, struct uart_port *up,
unsigned short *capabilites)
{
#ifdef CONFIG_EARLY_PRINTK
if (up->iotype != UPIO_MEM32) {
up->uartclk = 14745600;
up->mapbase = 0xdffe0200;
set_fixmap_nocache(FIX_EARLYCON_MEM_BASE,
up->mapbase & PAGE_MASK);
up->membase =
(void __iomem *)__fix_to_virt(FIX_EARLYCON_MEM_BASE);
up->membase += up->mapbase & ~PAGE_MASK;
up->mapbase += port * 0x100;
up->membase += port * 0x100;
up->iotype = UPIO_MEM32;
up->regshift = 2;
up->irq = 4;
}
#endif
up->iobase = 0;
up->serial_in = ce4100_mem_serial_in;
up->serial_out = ce4100_mem_serial_out;
*capabilites |= (1 << 12);
}
static __init void sdv_serial_fixup(void)
{
serial8250_set_isa_configurator(ce4100_serial_fixup);
}
static inline void sdv_serial_fixup(void) {}
static void __init sdv_arch_setup(void)
{
sdv_serial_fixup();
}
static void sdv_pci_init(void)
{
x86_of_pci_init();
}
void __init x86_ce4100_early_setup(void)
{
x86_init.oem.arch_setup = sdv_arch_setup;
x86_platform.i8042_detect = ce4100_i8042_detect;
x86_init.resources.probe_roms = x86_init_noop;
x86_init.mpparse.get_smp_config = x86_init_uint_noop;
x86_init.mpparse.find_smp_config = x86_init_noop;
x86_init.mpparse.setup_ioapic_ids = setup_ioapic_ids_from_mpc_nocheck;
x86_init.pci.init = ce4100_pci_init;
x86_init.pci.init_irq = sdv_pci_init;
reboot_type = BOOT_KBD;
pm_power_off = ce4100_power_off;
}
