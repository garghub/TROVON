static struct platform_device *
cpu8815_add_gpio(int id, resource_size_t addr, int irq,
struct nmk_gpio_platform_data *pdata)
{
struct resource resources[] = {
{
.start = addr,
.end = addr + 127,
.flags = IORESOURCE_MEM,
},
{
.start = irq,
.end = irq,
.flags = IORESOURCE_IRQ,
}
};
return platform_device_register_resndata(NULL, "gpio", id,
resources, ARRAY_SIZE(resources),
pdata, sizeof(*pdata));
}
void cpu8815_add_gpios(resource_size_t *base, int num, int irq,
struct nmk_gpio_platform_data *pdata)
{
int first = 0;
int i;
for (i = 0; i < num; i++, first += 32, irq++) {
pdata->first_gpio = first;
pdata->first_irq = NOMADIK_GPIO_TO_IRQ(first);
pdata->num_gpio = 32;
cpu8815_add_gpio(i, base[i], irq, pdata);
}
}
static inline void
cpu8815_add_pinctrl(struct device *parent, const char *name)
{
struct platform_device_info pdevinfo = {
.parent = parent,
.name = name,
.id = -1,
};
platform_device_register_full(&pdevinfo);
}
static int __init cpu8815_init(void)
{
struct nmk_gpio_platform_data pdata = {
};
cpu8815_add_gpios(cpu8815_gpio_base, ARRAY_SIZE(cpu8815_gpio_base),
IRQ_GPIO0, &pdata);
cpu8815_add_pinctrl(NULL, "pinctrl-stn8815");
amba_apb_device_add(NULL, "rng", NOMADIK_RNG_BASE, SZ_4K, 0, 0, NULL, 0);
amba_apb_device_add(NULL, "rtc-pl031", NOMADIK_RTC_BASE, SZ_4K, IRQ_RTC_RTT, 0, NULL, 0);
return 0;
}
void __init cpu8815_map_io(void)
{
iotable_init(nomadik_io_desc, ARRAY_SIZE(nomadik_io_desc));
}
void __init cpu8815_init_irq(void)
{
vic_init(io_p2v(NOMADIK_IC_BASE + 0x00), IRQ_VIC_START + 0, ~0, 0);
vic_init(io_p2v(NOMADIK_IC_BASE + 0x20), IRQ_VIC_START + 32, ~0, 0);
nomadik_clk_init();
}
void __init cpu8815_platform_init(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(io_p2v(NOMADIK_L2CC_BASE), 0x00730249, 0xfe000fff);
#endif
return;
}
void cpu8815_restart(char mode, const char *cmd)
{
void __iomem *src_rstsr = io_p2v(NOMADIK_SRC_BASE + 0x18);
writel(1, src_rstsr);
}
