void __init r8a7740_map_io(void)
{
debug_ll_io_init();
iotable_init(r8a7740_io_desc, ARRAY_SIZE(r8a7740_io_desc));
}
void __init r8a7740_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a7740", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
}
void __init r8a7740_meram_workaround(void)
{
void __iomem *reg;
reg = ioremap_nocache(MEBUFCNTR, 4);
if (reg) {
iowrite32(0x01600164, reg);
iounmap(reg);
}
}
void __init r8a7740_add_standard_devices(void)
{
static struct pm_domain_device domain_devices[] __initdata = {
{ "A4R", &tmu0_device },
{ "A4R", &i2c0_device },
{ "A4S", &irqpin0_device },
{ "A4S", &irqpin1_device },
{ "A4S", &irqpin2_device },
{ "A4S", &irqpin3_device },
{ "A3SP", &scif0_device },
{ "A3SP", &scif1_device },
{ "A3SP", &scif2_device },
{ "A3SP", &scif3_device },
{ "A3SP", &scif4_device },
{ "A3SP", &scif5_device },
{ "A3SP", &scif6_device },
{ "A3SP", &scif7_device },
{ "A3SP", &scif8_device },
{ "A3SP", &i2c1_device },
{ "A3SP", &ipmmu_device },
{ "A3SP", &dma0_device },
{ "A3SP", &dma1_device },
{ "A3SP", &dma2_device },
{ "A3SP", &usb_dma_device },
};
r8a7740_init_pm_domains();
platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
platform_add_devices(r8a7740_late_devices,
ARRAY_SIZE(r8a7740_late_devices));
rmobile_add_devices_to_domains(domain_devices,
ARRAY_SIZE(domain_devices));
}
void __init r8a7740_add_early_devices(void)
{
early_platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
shmobile_setup_console();
}
void __init r8a7740_init_irq_of(void)
{
void __iomem *intc_prio_base = ioremap_nocache(0xe6900010, 0x10);
void __iomem *intc_msk_base = ioremap_nocache(0xe6900040, 0x10);
void __iomem *pfc_inta_ctrl = ioremap_nocache(0xe605807c, 0x4);
#ifdef CONFIG_ARCH_SHMOBILE_LEGACY
void __iomem *gic_dist_base = ioremap_nocache(0xc2800000, 0x1000);
void __iomem *gic_cpu_base = ioremap_nocache(0xc2000000, 0x1000);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
#else
irqchip_init();
#endif
iowrite32(0x0, pfc_inta_ctrl);
iowrite32(0x0, intc_prio_base + 0x0);
iowrite32(0x0, intc_prio_base + 0x4);
iowrite32(0x0, intc_prio_base + 0x8);
iowrite32(0x0, intc_prio_base + 0xc);
iowrite8(0xff, intc_msk_base + 0x0);
iowrite8(0xff, intc_msk_base + 0x4);
iowrite8(0xff, intc_msk_base + 0x8);
iowrite8(0xff, intc_msk_base + 0xc);
iounmap(intc_prio_base);
iounmap(intc_msk_base);
iounmap(pfc_inta_ctrl);
}
static void __init r8a7740_generic_init(void)
{
r8a7740_meram_workaround();
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0002000), 0x00400000, 0xc20f0fff);
#endif
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
