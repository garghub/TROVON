void __init r8a7790_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a7790", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
r8a7790_register_gpio(0);
r8a7790_register_gpio(1);
r8a7790_register_gpio(2);
r8a7790_register_gpio(3);
r8a7790_register_gpio(4);
r8a7790_register_gpio(5);
}
static inline void r8a7790_register_scif(int idx)
{
platform_device_register_data(&platform_bus, "sh-sci", idx, &scif[idx],
sizeof(struct plat_sci_port));
}
void __init r8a7790_add_standard_devices(void)
{
r8a7790_register_scif(SCIFA0);
r8a7790_register_scif(SCIFA1);
r8a7790_register_scif(SCIFB0);
r8a7790_register_scif(SCIFB1);
r8a7790_register_scif(SCIFB2);
r8a7790_register_scif(SCIFA2);
r8a7790_register_scif(SCIF0);
r8a7790_register_scif(SCIF1);
r8a7790_register_scif(HSCIF0);
r8a7790_register_scif(HSCIF1);
r8a7790_register_irqc(0);
}
void __init r8a7790_timer_init(void)
{
void __iomem *cntcr;
cntcr = ioremap(0xe6080000, PAGE_SIZE);
iowrite32(1, cntcr);
iounmap(cntcr);
shmobile_timer_init();
}
void __init r8a7790_add_standard_devices_dt(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
