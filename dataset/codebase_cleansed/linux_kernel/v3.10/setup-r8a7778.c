void __init r8a7778_add_standard_devices(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
void __iomem *base = ioremap_nocache(0xf0100000, 0x1000);
if (base) {
l2x0_init(base, 0x40470000, 0x82000fff);
}
#endif
for (i = 0; i < ARRAY_SIZE(scif_platform_data); i++)
platform_device_register_data(&platform_bus, "sh-sci", i,
&scif_platform_data[i],
sizeof(struct plat_sci_port));
r8a7778_register_tmu(0);
r8a7778_register_tmu(1);
}
void __init r8a7778_add_ether_device(struct sh_eth_plat_data *pdata)
{
platform_device_register_resndata(&platform_bus, "sh_eth", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
pdata, sizeof(*pdata));
}
void __init r8a7778_init_irq_extpin(int irlm)
{
void __iomem *icr0 = ioremap_nocache(0xfe780000, PAGE_SIZE);
unsigned long tmp;
if (!icr0) {
pr_warn("r8a7778: unable to setup external irq pin mode\n");
return;
}
tmp = ioread32(icr0);
if (irlm)
tmp |= 1 << 23;
else
tmp &= ~(1 << 23);
tmp |= (1 << 21);
iowrite32(tmp, icr0);
iounmap(icr0);
if (irlm)
platform_device_register_resndata(
&platform_bus, "renesas_intc_irqpin", -1,
irqpin_resources, ARRAY_SIZE(irqpin_resources),
&irqpin_platform_data, sizeof(irqpin_platform_data));
}
static void __init r8a7778_init_irq_common(void)
{
void __iomem *base = ioremap_nocache(0xfe700000, 0x00100000);
BUG_ON(!base);
__raw_writel(0x73ffffff, base + INT2NTSR0);
__raw_writel(0xffffffff, base + INT2NTSR1);
__raw_writel(0x08330773, base + INT2SMSKCR0);
__raw_writel(0x00311110, base + INT2SMSKCR1);
iounmap(base);
}
void __init r8a7778_init_irq(void)
{
void __iomem *gic_dist_base;
void __iomem *gic_cpu_base;
gic_dist_base = ioremap_nocache(0xfe438000, PAGE_SIZE);
gic_cpu_base = ioremap_nocache(0xfe430000, PAGE_SIZE);
BUG_ON(!gic_dist_base || !gic_cpu_base);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
r8a7778_init_irq_common();
}
void __init r8a7778_init_delay(void)
{
shmobile_setup_delay(800, 1, 3);
}
void __init r8a7778_init_irq_dt(void)
{
irqchip_init();
r8a7778_init_irq_common();
}
void __init r8a7778_add_standard_devices_dt(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
r8a7778_auxdata_lookup, NULL);
}
