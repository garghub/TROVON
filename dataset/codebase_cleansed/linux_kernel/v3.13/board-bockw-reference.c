static void __init bockw_init(void)
{
static void __iomem *fpga;
r8a7778_clock_init();
r8a7778_init_irq_extpin_dt(1);
pinctrl_register_mappings(bockw_pinctrl_map,
ARRAY_SIZE(bockw_pinctrl_map));
r8a7778_pinmux_init();
r8a7778_add_dt_devices();
fpga = ioremap_nocache(FPGA, SZ_1M);
if (fpga) {
u16 val = ioread16(fpga + IRQ0MR);
val &= ~(1 << 4);
iowrite16(val, fpga + IRQ0MR);
}
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
