void __init prom_init(void)
{
#ifdef CONFIG_CPU_SUPPORTS_ADDRWINCFG
_loongson_addrwincfg_base = (unsigned long)
ioremap(LOONGSON_ADDRWINCFG_BASE, LOONGSON_ADDRWINCFG_SIZE);
#endif
prom_init_cmdline();
prom_init_env();
set_io_port_base((unsigned long)
ioremap(LOONGSON_PCIIO_BASE, LOONGSON_PCIIO_SIZE));
prom_init_memory();
prom_init_uart_base();
register_smp_ops(&loongson3_smp_ops);
}
void __init prom_free_prom_memory(void)
{
}
