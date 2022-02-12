static void __init init_shmin_irq(void)
{
__raw_writew(0x2a00, PFC_PHCR);
__raw_writew(0x0aaa, INTC_ICR1);
plat_irq_setup_pins(IRQ_MODE_IRQ);
}
static void __init shmin_setup(char **cmdline_p)
{
__set_io_port_base(SHMIN_IO_BASE);
}
