const char *get_system_type(void)
{
return "MIPSsim";
}
void __init plat_mem_setup(void)
{
set_io_port_base(0xbfd00000);
serial_init();
}
void __init prom_init(void)
{
set_io_port_base(0xbfd00000);
prom_meminit();
if (cpu_has_mipsmt) {
if (!register_vsmp_smp_ops())
return;
#ifdef CONFIG_MIPS_MT_SMTC
register_smp_ops(&ssmtc_smp_ops);
return;
#endif
}
register_up_smp_ops();
}
static void __init serial_init(void)
{
#ifdef CONFIG_SERIAL_8250
struct uart_port s;
memset(&s, 0, sizeof(s));
s.iobase = 0x3f8;
s.irq = 0;
s.uartclk = 1843200;
s.flags = UPF_BOOT_AUTOCONF | UPF_SKIP_TEST;
s.iotype = UPIO_PORT;
s.regshift = 0;
s.timeout = 4;
if (early_serial_setup(&s) != 0) {
printk(KERN_ERR "Serial setup failed!\n");
}
#endif
}
