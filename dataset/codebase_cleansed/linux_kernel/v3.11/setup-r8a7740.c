void __init r8a7740_map_io(void)
{
iotable_init(r8a7740_io_desc, ARRAY_SIZE(r8a7740_io_desc));
}
void __init r8a7740_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a7740", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
}
void r8a7740_meram_workaround(void)
{
void __iomem *reg;
reg = ioremap_nocache(MEBUFCNTR, 4);
if (reg) {
iowrite32(0x01600164, reg);
iounmap(reg);
}
}
static void r8a7740_i2c_workaround(struct platform_device *pdev)
{
struct resource *res;
void __iomem *reg;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res)) {
pr_err("r8a7740 i2c workaround fail (cannot find resource)\n");
return;
}
reg = ioremap(res->start, resource_size(res));
if (unlikely(!reg)) {
pr_err("r8a7740 i2c workaround fail (cannot map IO)\n");
return;
}
i2c_write(reg, ICCR, i2c_read(reg, ICCR) | 0x80);
i2c_read(reg, ICCR);
i2c_write(reg, ICSTART, i2c_read(reg, ICSTART) | 0x10);
i2c_read(reg, ICSTART);
udelay(10);
i2c_write(reg, ICCR, 0x01);
i2c_write(reg, ICSTART, 0x00);
udelay(10);
i2c_write(reg, ICCR, 0x10);
udelay(10);
i2c_write(reg, ICCR, 0x00);
udelay(10);
i2c_write(reg, ICCR, 0x10);
udelay(10);
iounmap(reg);
}
void __init r8a7740_add_standard_devices(void)
{
r8a7740_i2c_workaround(&i2c0_device);
r8a7740_i2c_workaround(&i2c1_device);
r8a7740_init_pm_domains();
platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
platform_add_devices(r8a7740_devices_dt,
ARRAY_SIZE(r8a7740_devices_dt));
platform_add_devices(r8a7740_late_devices,
ARRAY_SIZE(r8a7740_late_devices));
rmobile_add_device_to_domain("A3SP", &scif0_device);
rmobile_add_device_to_domain("A3SP", &scif1_device);
rmobile_add_device_to_domain("A3SP", &scif2_device);
rmobile_add_device_to_domain("A3SP", &scif3_device);
rmobile_add_device_to_domain("A3SP", &scif4_device);
rmobile_add_device_to_domain("A3SP", &scif5_device);
rmobile_add_device_to_domain("A3SP", &scif6_device);
rmobile_add_device_to_domain("A3SP", &scif7_device);
rmobile_add_device_to_domain("A3SP", &scifb_device);
rmobile_add_device_to_domain("A3SP", &i2c1_device);
}
void __init r8a7740_add_early_devices(void)
{
early_platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
early_platform_add_devices(r8a7740_devices_dt,
ARRAY_SIZE(r8a7740_devices_dt));
shmobile_setup_console();
}
void __init r8a7740_add_standard_devices_dt(void)
{
platform_add_devices(r8a7740_devices_dt,
ARRAY_SIZE(r8a7740_devices_dt));
of_platform_populate(NULL, of_default_bus_match_table,
r8a7740_auxdata_lookup, NULL);
}
void __init r8a7740_init_delay(void)
{
shmobile_setup_delay(800, 1, 3);
}
static void __init r8a7740_generic_init(void)
{
r8a7740_clock_init(0);
r8a7740_add_standard_devices_dt();
}
