void __init prom_init(void)
{
set_io_port_base((unsigned long)
ioremap(LOONGSON_PCIIO_BASE, LOONGSON_PCIIO_SIZE));
#ifdef CONFIG_CPU_SUPPORTS_ADDRWINCFG
_loongson_addrwincfg_base = (unsigned long)
ioremap(LOONGSON_ADDRWINCFG_BASE, LOONGSON_ADDRWINCFG_SIZE);
#endif
prom_init_cmdline();
prom_init_env();
prom_init_memory();
prom_init_uart_base();
}
void __init prom_free_prom_memory(void)
{
}
