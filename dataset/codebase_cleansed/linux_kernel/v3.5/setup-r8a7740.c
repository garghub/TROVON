void __init r8a7740_map_io(void)
{
iotable_init(r8a7740_io_desc, ARRAY_SIZE(r8a7740_io_desc));
init_consistent_dma_size(12 << 20);
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
platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
platform_add_devices(r8a7740_late_devices,
ARRAY_SIZE(r8a7740_late_devices));
}
static void __init r8a7740_earlytimer_init(void)
{
r8a7740_clock_init(0);
shmobile_earlytimer_init();
}
void __init r8a7740_add_early_devices(void)
{
early_platform_add_devices(r8a7740_early_devices,
ARRAY_SIZE(r8a7740_early_devices));
shmobile_setup_console();
shmobile_timer.init = r8a7740_earlytimer_init;
}
